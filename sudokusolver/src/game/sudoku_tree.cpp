//
// sudoku_tree.cpp
// sudoku
//

#include <sstream>

#include "sudoku_tree.h"
#include "sudoku_log.h"
#include "sudoku_cell.h"

namespace sudoku {
namespace game {

Tree::operator const std::ostringstream() const {

  Node *node(static_cast<Node*>(0));

  std::shared_ptr < Node > result = _result.lock();

  if (result && result.get()) {
    node = result.get();
  } else {
    node = dynamic_cast<game::Node*>(const_cast<game::Tree*>(this));
  }

  std::ostringstream os;

  os << (node->operator const std::ostringstream()).str();

  return os;
}

bool Tree::solve(std::deque<game::Move> &loaded,
    const std::shared_ptr<Zones> &zones) {

  LOGGER_INFO("start solve");

  std::shared_ptr < Node > root(this->shared_from_this());

  std::tuple<bool, std::shared_ptr<Node>> result(
      this->search(zones, root, loaded));

  _result = std::get < 1 > (result);

  if (std::get < 0 > (result)) {
    LOGGER_DEBUG("finished search");

    if (this->solved(zones)) {
      LOGGER_DEBUG("solved")
    }

    return true;
  }

  if (this->solved(zones)) {
    LOGGER_WARN("solved despite error")
  }

  LOGGER_ERROR("search error");

  return false;
}

std::tuple<bool, std::shared_ptr<Node>> Tree::apply(
    const std::shared_ptr<Zones> &zones, std::shared_ptr<Node> &parent,
    std::deque<game::Move> &moves) {
  
  game::Move move(moves.front());

  moves.pop_front();

  LOGGER_DEBUG("apply move ", move);

  std::shared_ptr < Node > child(new Node(parent, move));

  if (child->failed()) {
    LOGGER_ERROR("child is failed");

    return std::make_tuple<>(false, child);
  }

  if (moves.empty()) {
    static bool first(true);

    if (first) {
      if (sudoku::util::Logger < sudoku::util::LogInfo > ::isLevelOn()) {
        std::ostringstream os;
        os << std::endl << std::endl
            << (child->operator const std::ostringstream()).str();
        LOGGER_INFO("position", os);
      }
    } else if (sudoku::util::Logger < sudoku::util::LogTrace > ::isLevelOn()) {
      std::ostringstream os;
      os << std::endl << std::endl
          << (child->operator const std::ostringstream()).str();
      LOGGER_TRACE("position", os);
    }

    first = false;
  } else {
    if (sudoku::util::Logger < sudoku::util::LogTrace > ::isLevelOn()) {
      std::ostringstream os;
      os << std::endl << std::endl
          << (child->operator const std::ostringstream()).str();
      LOGGER_TRACE(os);
    }
  }

  std::tuple<bool, std::shared_ptr<Node>> found(
      this->search(zones, child, moves));

  if (!std::get < 0 > (found)) {
    LOGGER_TRACE("search didn't find valid sub-tree at depth ", parent->depth(),
        " using move ", move);

    return std::make_tuple<>(false, child);
  }

  LOGGER_TRACE("search found valid sub-tree at depth ", parent->depth(),
      " attached child ", child->id(), " with depth ", child->depth(),
      " using move ", move);

  parent->child(child);

  return found;
}

std::tuple<bool, std::shared_ptr<Node>> Tree::search(
    const std::shared_ptr<Zones> &zones, std::shared_ptr<Node> &parent,
    std::deque<game::Move> &loaded) {
  if (parent->deadend()) {
    LOGGER_TRACE("deadend");

    return std::make_tuple<>(false, parent);
  }

  if (!loaded.empty()) {
    LOGGER_TRACE("loaded");

    return this->apply(zones, parent, loaded);
  }

  std::vector < game::Move > moves;

  if (parent->schedule(zones, moves)) {
    LOGGER_TRACE("search planned schedule at depth ", parent->depth(),
        " with #moves ", moves.size(), " ", moves);

    for (size_t i(0); i < moves.size(); i++) {
      game::Move move(moves[i]);

      LOGGER_TRACE("search start at depth ", parent->depth(), " with move #",
          (i + 1), " out of #", moves.size(), " using move ", move);

      std::tuple<bool, std::shared_ptr<Node>> found(
          this->apply(zones, parent, move));

      if (!std::get < 0 > (found)) {
        LOGGER_TRACE("search terminated and disposed at depth ",
            parent->depth(), " with move #", (i + 1), " out of #", moves.size(),
            " using move ", move);

        continue;
      }

      LOGGER_TRACE("search terminated and returned at depth ", parent->depth(),
          " with move #", (i + 1), " out of #", moves.size(), " using move ",
          move);

      return found;
    }

    LOGGER_TRACE("processed all options at depth ", parent->depth());

    return std::make_tuple<>(false, parent);
  }

  LOGGER_TRACE("no more options at depth ", parent->depth());

  return std::make_tuple<>(true, parent); // terminate by sending back true/parent ..
}

} // ns game
} // bs sudoku


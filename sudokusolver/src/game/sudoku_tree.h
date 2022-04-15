//
// sudoku_tree.h
// sudoku
//

#ifndef SUDOKU_TREE_H
#define SUDOKU_TREE_H

#include <deque>
#include <cassert>

#include "sudoku_defn.h"
#include "sudoku_board.h"
#include "sudoku_node.h"
#include "sudoku_zones.h"

namespace sudoku {
namespace game {

class Tree: public Node, public std::enable_shared_from_this<Tree> {

public:  
  Tree(const std::shared_ptr<Cells> &cells) :
      Node(cells), _result() {
  }

  virtual ~Tree() {
  }

  operator const std::ostringstream() const;

  bool solve(std::deque<game::Move> &moves,
      const std::shared_ptr<Zones> &zones);

  inline bool solved(const std::shared_ptr<Zones> &zones) const {
    if (_result.use_count()) {
      if (std::shared_ptr < Node > result = _result.lock()) {
        if (!std::all_of(result->board()->cells().begin(),
            result->board()->cells().end(), [](auto &cell) {
              return cell->value() && !cell->option_count();
            }))
        {
          return false;
        }

        if (!std::all_of(result->board()->cells().begin(),
            result->board()->cells().end(), [&zones, &result](auto &cell) {
              return cell->solved(zones, result->board()->cells());
            }))
        {
          return false;
        }

        return true;
      }
    }

    LOGGER_ERROR("cannot lock solution board.");

    return false;
  }

  inline bool failed() const {
    if (_result.use_count()) {
      if (std::shared_ptr < Node > result = _result.lock()) {
        return result->board()->failed();
      }
    }

    LOGGER_FATAL("cannot lock solution board.");

    assert(!"should not get here. node was deleted before finished.");

    return true;
  }

private:
  std::tuple<bool, std::shared_ptr<Node>> search(
      const std::shared_ptr<Zones> &zones, std::shared_ptr<Node> &parent,
      std::deque<game::Move> &loaded);

  std::tuple<bool, std::shared_ptr<Node>> apply(
      const std::shared_ptr<Zones> &zones, std::shared_ptr<Node> &parent,
      std::deque<game::Move> &move);

  inline std::tuple<bool, std::shared_ptr<Node>> apply(
      const std::shared_ptr<Zones> &zones, std::shared_ptr<Node> &parent,
      const game::Move &move) {
    std::deque < game::Move > single { move };

    return this->apply(zones, parent, single);
  }

  std::weak_ptr<Node> _result;

private:
  Tree(const Tree&) = delete;
  Tree& operator=(const Tree&) = delete;
};

} // ns game
} // bs sudoku

#endif /* SUDOKU_TREE_H */

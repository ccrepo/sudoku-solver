//
// sudoku_node.h
// sudoku
//

#ifndef SUDOKU_NODE_H
#define SUDOKU_NODE_H

#include "sudoku_defn.h"
#include "sudoku_board.h"
#include "sudoku_log.h"

namespace sudoku {
namespace game {

class Tree;

class Node {

public:
  Node(const std::shared_ptr<Cells> &cells) :
      _parent(), _board(
          new Board(cells, util::Const::_CONST_TREESEARCH_INITIALDEPTH)), _child(), _id(
          _nodescreated++), _depth(util::Const::_CONST_TREESEARCH_INITIALDEPTH) {
    Node::_nodesalive++;
  }

  Node(const std::shared_ptr<Node> &parent, const game::Move &move) :
      _parent(parent), _board(parent->branch(move)), _child(), _id(
          _nodescreated++), _depth(_board->depth()) {
    Node::_nodesalive++;
  }

  virtual ~Node() {
    --Node::_nodesalive;
  }

  inline const std::shared_ptr<Board>& board() {
    return _board;
  }

  inline operator const std::ostringstream() const {
    if (sudoku::util::Logger < sudoku::util::LogDebug > ::isLevelOn()) {
      std::ostringstream os;

      if (std::shared_ptr<game::Node> parent = this->_parent.lock()) {
        os << "parent:  " << parent->_id << " [" << parent << "]" << std::endl;
      } else {
        os << "parent:  -" << std::endl;
      }

      os << "node:    " << this->_id << " [" << (this) << "]" << std::endl
          << "depth:   " << this->_depth << std::endl << "count:   "
          << (Node::_nodesalive - 1) << " [" << (Node::_nodescreated - 1) << "]"
          << std::endl
          << this->_board->operator const std::ostringstream().str();

      return os;
    } else {
      return this->_board->operator const std::ostringstream();
    }
  }

  inline const bool failed() const {
    return this->_board->failed();
  }

  inline bool deadend() const {
    return this->_board->deadend();
  }

  inline unsigned int depth() const {
    return _depth;
  }

  inline int id() const {
    return _id;
  }

  inline bool schedule(const std::shared_ptr<Zones>& zones, OUT std::vector<game::Move>& moves) const
  {
    return _board->schedule(zones, moves);
  }

  inline void child(const std::shared_ptr<Node> &child) {
    this->_child = child;
  }

  inline int nodescreated() const {
    return Node::_nodescreated - 1;
  }

protected:
  inline std::shared_ptr<Board> branch(const game::Move &move) {
    std::shared_ptr < Board > board(this->_board->clone());

    if (!board->play(move)) {
      LOGGER_FATAL("board failed on move ", move);
    }

    return board;
  }

private:
  std::weak_ptr<Node> _parent;
  std::shared_ptr<Board> _board;
  std::shared_ptr<Node> _child;

  const int _id;
  const unsigned int _depth;

private:
  static int _nodesalive;
  static int _nodescreated;

private:
  Node(const Node&) = delete;
  Node& operator=(const Node&) = delete;

};

} // ns game
} // bs sudoku

#endif /* SUDOKU_NODE_H */

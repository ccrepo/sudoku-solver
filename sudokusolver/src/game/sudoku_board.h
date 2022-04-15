//
// sudoku_board.h
// sudoku
//

#ifndef SUDOKU_BOARD_H
#define SUDOKU_BOARD_H

#include <cassert>
#include <sstream>
#include <array>
#include <vector>
#include <string>
#include <deque>
#include <list>

#include "sudoku_defn.h"
#include "sudoku_const.h"
#include "sudoku_move.h"
#include "sudoku_collection.h"
#include "sudoku_cell.h"
#include "sudoku_cells.h"

namespace sudoku {
namespace game {

class Cells;
class Zones;

class Board {
  
public:
  operator const std::ostringstream() const;

  virtual ~Board() {
    --Board::_boardsalive;
  }

  Board(const std::shared_ptr<game::Cells> &cells, unsigned int depth) :
      _cells(new game::Cells(*cells)), _move(game::Move::empty()), _inited(
          false), _id(Board::_boardscreated++), _failed(false), _depth(depth), _moves() {
    _inited = true;
    Board::_boardsalive++;
  }

  Board(const Board &board, unsigned int depth) :
      _cells(new game::Cells(*board._cells)), _move(board._move), _inited(
          board._inited), _id(Board::_boardscreated++), _failed(board._failed), _depth(
          depth), _moves(board._moves) {
    if (this->_cells->size() != board._cells->size()
        || board._cells->size() != util::Const::_CONST_TOTAL_CELLS) {
      assert(!"should not reach here. should always be the same size. serious");
    }

    Board::_boardsalive++;
    _inited = true;
  }

  Board& operator=(const Board &board) {
    
    std::shared_ptr<game::Cells> cells(new game::Cells());

    std::copy(board.cells().begin(), board.cells().end(),
        cells->cells().begin());

    this->_cells = cells;
    this->_move = board._move;
    this->_inited = board._inited;
    this->_id = board._id;
    this->_failed = board._failed;
    this->_depth = board._depth;
    this->_moves = board._moves;

    return (*this);
  }

  inline std::shared_ptr<Board> clone() const {
    return std::shared_ptr < Board > (new game::Board(*this, this->_depth + 1));
  }

  inline bool failed() const {
    return _failed;
  }

  bool schedule(const std::shared_ptr<Zones>& zones, OUT std::vector<game::Move>& moves) const;

  inline bool deadend() const {
    return !std::all_of(this->cells().begin(), this->cells().end(),
        [](auto &cell) {
          return cell->option_count() > 0 || cell->value() > 0;
        });
  }

  bool play(const game::Move &move);

  inline unsigned int depth() const {
    return _depth;
  }

  inline util::all_cells_array& cells() {
    static util::all_cells_array constant;

    if (this->_cells) {
      return this->_cells->cells();
    }

    assert(!"should not get here");

    return constant;
  }

  inline const util::all_cells_array& cells() const {
    static util::all_cells_array constant;

    if (this->_cells) {
      return this->_cells->cells();
    }

    assert(!"should not get here");

    return constant;
  }

private:
  inline bool prune(int id, int blockNo, int rowNo, int columnNo, int rankNo,
      int stackNo, int value) {
    const auto size(this->cells().size());

    for (size_t i(0); i < size; i++) {
      std::shared_ptr < game::Cell > cell(this->cells()[i]);

      if (cell->id().id() == id) {
        continue;
      }

      if (cell->blockNo() == blockNo || cell->rowNo() == rowNo
          || cell->columnNo() == columnNo) {
        this->cells()[cell->id().id()] = std::shared_ptr < game::Cell
            > (new Cell(cell->id().id(), cell->value(), cell->option_count(),
                cell->options(), value));
      }
    }

    return true;
  }

  void weigh(const std::shared_ptr<Zones> &zones,
      std::vector<game::Move> &buffer) const;

  //

  bool impliedforce(const std::shared_ptr<Zones> &zones,
      const game::Move &move) const;

  bool impliedrank(const std::shared_ptr<Zones> &zones,
      const game::Move &move) const;

  bool impliedstack(const std::shared_ptr<Zones> &zones,
      const game::Move &move) const;

  bool impliedblock(const std::shared_ptr<Zones> &zones,
      const game::Move &move) const;

  bool impliedpointpair(const std::shared_ptr<Zones> &zones,
      const game::Move &move) const;

  bool impliedN(const std::shared_ptr<Zones> &zones,
      const game::Move &move) const;

  //

  std::shared_ptr<game::Cells> _cells;
  game::Move _move;
  bool _inited;
  int _id;
  bool _failed;
  unsigned int _depth;
  std::vector<game::Move> _moves;

private:
  static int _boardsalive;
  static int _boardscreated;

private:
  Board(const Board&) = delete;
  
};

} // ns game
} // ns sudoku

#endif /* SUDOKU_BOARD_H */

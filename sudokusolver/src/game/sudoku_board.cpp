//
// sudoku_board.cpp
// sudoku
//

#include <sstream>
#include <memory>
#include <iostream>
#include <array>

#include "sudoku_const.h"
#include "sudoku_value.h"
#include "sudoku_log.h"
#include "sudoku_board.h"
#include "sudoku_zones.h"
#include "sudoku_block.h"
#include "sudoku_row.h"
#include "sudoku_column.h"
#include "sudoku_rank.h"
#include "sudoku_stack.h"

namespace sudoku {
namespace game {

int Board::_boardsalive(0);
int Board::_boardscreated(0);

Board::operator const std::ostringstream() const {
  
  std::ostringstream os;

  int row = 1;
  int rank = 1;
  int stack = 0;

  if (sudoku::util::Logger < sudoku::util::LogDebug > ::isLevelOn()) {
    os << "board:   " << this->_id << " ["
        << (reinterpret_cast<const void*>(this)) << "] " << std::endl
        << "depth:   " << this->_depth << std::endl << "count:   "
        << (Board::_boardsalive - 1) << " [" << (Board::_boardscreated - 1)
        << "]" << std::endl << "move:    " << _moves.size() << " "
        << this->_move << std::endl << std::endl;
  }

  for (const auto &cell : this->_cells->cells()) {
    if (cell->rowNo() != row && (row = cell->rowNo())) {
      os << std::endl;
    }

    if (cell->stackNo() != stack && (stack = cell->stackNo())) {
      if (cell->rankNo() != rank && (rank = cell->rankNo())) {
        os << std::endl << std::endl;
      }

      os << "   ";
    } else {
      if (cell->rankNo() != rank && (rank = cell->rankNo())) {
        os << std::endl; // << std::endl;
      }
    }

    if (cell->rankNo() != rank && (rank = cell->rankNo())) {
      os << std::endl << std::endl;
    }

    os << "" << (cell->operator const std::string()) << " ";
  }

  os << std::endl << std::endl;

  if (sudoku::util::Logger < sudoku::util::LogDebug > ::isLevelOn()) {
    for (size_t i(0); i < _moves.size(); i++) {
      os << (i + 1) << ". " << _moves[i] << " " << std::endl;
    }
  }

  return os;
}

bool Board::play(const game::Move &move) {
  
  LOGGER_DEBUG("play ", move);

  int id(cell::Id::fromXY(move.row(), move.column()));

  const std::shared_ptr<game::Cell> before(this->cells()[id]);

  if (before->value()) {
    LOGGER_ERROR("cell already played in ", move);
    _failed = true;
    return !_failed;
  }

  this->_move = move;

  _moves.push_back(this->_move);

  this->cells()[id] = std::shared_ptr < game::Cell
      > (new Cell(before->id().id(), move.value(), before->option_count(),
          before->options()));

  if (!this->prune(id, this->cells()[id]->blockNo(), this->cells()[id]->rowNo(),
      this->cells()[id]->columnNo(), this->cells()[id]->rankNo(),
      this->cells()[id]->stackNo(), move.value())) {
    LOGGER_ERROR("cell prune failed on move ", move);
    _failed = true;
    return !_failed;
  }

  return !_failed;
}

bool Board::impliedblock(const std::shared_ptr<Zones> &zones,
    const game::Move &move) const {
  // TODO - implement. Here we need to check block and spot any implied moves based on other cells.
  return false;
}

bool Board::impliedpointpair(const std::shared_ptr<Zones> &zones,
    const game::Move &move) const {
  // TODO - implement. check block point
  return false;
}

bool Board::impliedN(const std::shared_ptr<Zones> &zones,
    const game::Move &move) const {
  // TODO - implement. Here we need to check pairs and other N-tuples with common content and promote in schedule
  return false;
}

bool Board::impliedforce(const std::shared_ptr<Zones> &zones,
    const game::Move &move) const {
  
  int id { game::cell::Id::fromXY(move.row(), move.column()) };

  const auto &cell(this->cells()[id]);

  return cell->option_count() == 1;
}

bool Board::impliedrank(const std::shared_ptr<Zones> &zones,
    const game::Move &move) const // TODO - simplify
    {
  cell::Id ids(cell::Id::fromXY(move.row(), move.column()));

  int rankid(ids.rankNo());

  const std::shared_ptr<util::single_rank_array> rank(
      (zones->ranks())->operator[](rankid)->cells());

  int incidence(0);

  std::shared_ptr < game::Cells > cells { _cells };

  int value(move.value());

  std::for_each(rank->begin(), rank->end(),
      [&incidence, &cells, &value](int rankid) {
        if (cells->cells()[rankid]->value() == value)
          incidence++;
      });

  if (incidence != 2) {
    return false;
  }

  std::array<bool, util::Const::_CONST_ROWS_IN_RANK> flags { };

  std::fill_n(flags.begin(), flags.size(), false);

  std::shared_ptr < util::single_row_array > matchedrow;

  for (int rowid(0); rowid < util::Const::_CONST_ROWS_IN_RANK; rowid++) // IMPORTANT!!! relies ... not hard coded BUT relies of strict multiples. TODO static check in consts for this.
      {
    int rIdx((rankid * util::Const::_CONST_ROWS_IN_RANK) + rowid);

    std::shared_ptr < util::single_row_array
        > row((zones->rows())->operator[](rIdx)->cells());

    flags[rowid] = std::all_of(row->begin(), row->end(),
        [&cells, value](int i) {
          return cells->cells()[i]->value() != value;
        });

    if (flags[rowid] && move.row() == rIdx) {
      matchedrow = row;
    }
  }

  if (std::count_if(flags.begin(), flags.end(), [](bool b) {
    return b;
  }) == 1 && matchedrow) // one possible row "matchedrow" only
      {
    // check if singular cell permits the play of value.
    int count(0);

    for (int cIdx(0); cIdx < util::Const::_CONST_CELLS_IN_ROW; cIdx++) {
      std::shared_ptr < game::Cell
          > cell(cells->cells()[matchedrow->operator[](cIdx)]);

      if (cell->options()[value - 1]) {
        count++;
      }
    }

    if (count == 1) {
      return true;
    }
  }

  return false;
}

void Board::weigh(const std::shared_ptr<Zones> &zones,
    std::vector<game::Move> &moves) const {
  
  bool deterministic(false);

  for (auto &move : moves) {
    if (impliedforce(zones, move)) {
      move.weight(util::Const::_CONST_MOVEWEIGHT_IMPLIEDFORCE);

      deterministic = true;
    } else if (impliedrank(zones, move)) {
      move.weight(util::Const::_CONST_MOVEWEIGHT_IMPLIEDRANK);

      deterministic = true;
    } else if (impliedstack(zones, move)) {
      move.weight(util::Const::_CONST_MOVEWEIGHT_IMPLIEDSTACK);

      deterministic = true;
    }

    // TODO - implement
    //else if (impliedblock(zones, move))
    //{
    //  move.weight(util::Const::_CONST_MOVEWEIGHT_IMPLIEDBLOCK);
    //}

    // TODO - implement
    //else if (impliedpointpair(zones, move))
    //{
    //  move.weight(util::Const::_CONST_MOVEWEIGHT_IMPLIEDPOINTPAIR);
    //}

    // TODO - implement
    //else if (impliedN(zones, move))
    //{
    //  move.weight(util::Const::_CONST_MOVEWEIGHT_IMPLIEDN);
    //}

    // non-deterministic !!
    else {
      move.weight(util::Const::_CONST_MOVEWEIGHT_MAXWEIGHT);
    }
  }

  if (!deterministic) {
    std::array<int, util::Const::_CONST_TOTAL_CELLS> totals { };

    std::for_each(moves.begin(), moves.end(), [&totals](const auto &move) {
      if (move.weight() == util::Const::_CONST_MOVEWEIGHT_MAXWEIGHT)
        totals[game::cell::Id::fromXY(move.row(), move.column())]++;
    });

    // reduce non-deterministic by the number of them .. better "chance" to get it right with guess in cells with lower options
    std::for_each(moves.begin(), moves.end(),
        [&totals](auto &move) {
          if (move.weight() == util::Const::_CONST_MOVEWEIGHT_MAXWEIGHT)
            move.weight(
                util::Const::_CONST_MOVEWEIGHT_MIN_NONDETERMINISTIC
                    + totals[game::cell::Id::fromXY(move.row(), move.column())]);
        });
  }
}

bool Board::schedule(const std::shared_ptr<Zones>& zones, OUT std::vector<game::Move>& moves) const {
  
  std::vector<game::Move> options;

  options.reserve(this->cells().size());

  for (const auto& cell : cells())
  {
    if (cell->option_count())
    {
      for (size_t i(0); i<cell->options().size(); i++)
      {
        if (cell->options()[i])
        {
          options.push_back(Move(cell->rowNo(), cell->columnNo(), i+1));
        }
      }
    }
  }

  if (!options.empty())
  {
    this->weigh(zones, options);

    std::sort(options.begin(), options.end());

    game::Move best(options.front());

    std::copy_if(options.begin(), options.end(), std::back_inserter(moves), [&best](const auto& move) {return best.row() == move.row() && best.column() == move.column();});
  }

  return !moves.empty();
}

bool Board::impliedstack(const std::shared_ptr<Zones> &zones,
    const game::Move &move) const  { // TODO - simplify
  
  cell::Id id(cell::Id::fromXY(move.row(), move.column()));

  int stackid(id.stackNo());

  const std::shared_ptr<util::single_stack_array> stack(
      (zones->stacks())->operator[](stackid)->cells());

  int incidence(0);

  std::shared_ptr < game::Cells > cells { _cells };

  int value(move.value());

  std::for_each(stack->begin(), stack->end(),
      [&incidence, &cells, &value](int stackid) {
        if (cells->cells()[stackid]->value() == value)
          incidence++;
      });

  if (incidence != 2) {
    return false;
  }

  std::array<bool, util::Const::_CONST_COLUMNS_IN_STACK> flags { };

  std::fill_n(flags.begin(), flags.size(), false);

  std::shared_ptr < util::single_column_array > matchedcolumn;

  for (int columnid(0); columnid < util::Const::_CONST_COLUMNS_IN_STACK;
      columnid++) // IMPORTANT!!! relies ... not hard coded BUT relies of strict multiples. TODO static check in consts for this.
      {
    int cIdx((stackid * util::Const::_CONST_COLUMNS_IN_STACK) + columnid);

    std::shared_ptr < util::single_column_array
        > column((zones->columns())->operator[](cIdx)->cells());

    flags[columnid] = std::all_of(column->begin(), column->end(),
        [&cells, value](int i) {
          return cells->cells()[i]->value() != value;
        });

    if (flags[columnid] && move.column() == cIdx) {
      matchedcolumn = column;
    }
  }

  if (std::count_if(flags.begin(), flags.end(), [](bool b) {
    return b;
  }) == 1 && matchedcolumn) // one possible row "matchedrow" only
      {
    // check if singular cell permits the play of value.
    int count(0);

    for (int rIdx(0); rIdx < util::Const::_CONST_CELLS_IN_COLUMN; rIdx++) {
      std::shared_ptr < game::Cell
          > cell(cells->cells()[matchedcolumn->operator[](rIdx)]);

      if (cell->options()[value - 1]) {
        count++;
      }
    }

    if (count == 1) {
      return true;
    }
  }

  return false;
}

} // ns game
} // ns sudoku

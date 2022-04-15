//
// sudoku_const.h
// sudoku
//

#ifndef SUDOKU_CONST_H
#define SUDOKU_CONST_H

#include <array>
#include <tuple>
#include <map>

namespace sudoku {
namespace util {

class Const {
  
public:
  static constexpr const char *_CONST_ENVVAR_BOARDDISPLAY_VERBOSE {
      "SUDOKUSOLVER_BOARDDISPLAY_VERBOSE" };

  static constexpr const char *_CONST_ENVVAR_LOGLEVEL { "SUDOKUSOLVER_LOGLEVEL" };
  static constexpr const char *_CONST_ENVVAR_LOGLEVEL_TRACE { "trace" };
  static constexpr const char *_CONST_ENVVAR_LOGLEVEL_DEBUG { "debug" };
  static constexpr const char *_CONST_ENVVAR_LOGLEVEL_INFO { "info" };
  static constexpr const char *_CONST_ENVVAR_LOGLEVEL_WARN { "warn" };
  static constexpr const char *_CONST_ENVVAR_LOGLEVEL_ERROR { "error" };
  static constexpr const char *_CONST_ENVVAR_LOGLEVEL_FATAL { "fatal" };

  static constexpr int _CONST_ID_WIDTH { 2 };
  static constexpr int _CONST_NUMDIGITS_PLAY { 9 };
  static constexpr int _CONST_NUMDIGITS_INIT { 10 };

  static constexpr int _CONST_BOARD_SIZE { 9 };
  static constexpr int _CONST_BLOCK_SIZE { 3 };

  static constexpr int _CONST_LEGALSYMBOLS_SIZE { 10 };

  static constexpr int _CONST_BLOCKS_IN_ROW { 3 };
  static constexpr int _CONST_BLOCKS_IN_COL { 3 };

  static constexpr int _CONST_CELLS_IN_ROW { 9 };
  static constexpr int _CONST_CELLS_IN_COLUMN { 9 };
  static constexpr int _CONST_CELLS_IN_BLOCK { 9 };
  static constexpr int _CONST_CELLS_IN_BLOCK_ROW { 3 };
  static constexpr int _CONST_CELLS_IN_RANK { 27 };
  static constexpr int _CONST_CELLS_IN_STACK { 27 };

  static constexpr int _CONST_ROWS_IN_BLOCK { 3 };
  static constexpr int _CONST_ROWS_IN_RANK { 3 };
  static constexpr int _CONST_COLUMNS_IN_STACK { 3 };
  static constexpr int _CONST_STACKS_IN_RANK { 3 };
  static constexpr int _CONST_STACKS_IN_ROW { 3 };

  static constexpr int _CONST_TOTAL_CELLS { 81 };
  static constexpr int _CONST_TOTAL_ROWS { 9 };
  static constexpr int _CONST_TOTAL_COLUMNS { 9 };
  static constexpr int _CONST_TOTAL_BLOCKS { 9 };
  static constexpr int _CONST_TOTAL_RANKS { 3 };
  static constexpr int _CONST_TOTAL_STACKS { 3 };

  static constexpr char _CONST_SUDOKU_MINNO { '0' };
  static constexpr char _CONST_SUDOKU_MAXNO { '9' };

  static constexpr char _CONST_SUDOKU_MINPLAY_ASCHAR { '1' };
  static constexpr char _CONST_SUDOKU_MAXPLAY_ASCHAR { '9' };

  static constexpr char _CONST_SUDOKU_MININIT_ASCHAR { '0' };
  static constexpr char _CONST_SUDOKU_MAXINIT_ASCHAR { '9' };

  static constexpr char _CONST_SUDOKU_MINPLAY_ASINT { 1 };
  static constexpr char _CONST_SUDOKU_MAXPLAY_ASINT { 9 };

  static constexpr int _CONST_STRATEGYLIMIT_INNER { 2 };
  static constexpr int _CONST_STRATEGYLIMIT_OUTER { 100 };

  static constexpr int _CONST_MOVEWEIGHT_MAXWEIGHT { 100 };
  static constexpr int _CONST_MOVEWEIGHT_MIN_NONDETERMINISTIC { 10 };
  static constexpr int _CONST_MOVEWEIGHT_MINWEIGHT { 0 };

  static constexpr int _CONST_MOVEWEIGHT_LOADED { 0 };
  static constexpr int _CONST_MOVEWEIGHT_IMPLIEDFORCE { 1 };
  static constexpr int _CONST_MOVEWEIGHT_IMPLIEDRANK { 2 };
  static constexpr int _CONST_MOVEWEIGHT_IMPLIEDSTACK { 2 };
  static constexpr int _CONST_MOVEWEIGHT_IMPLIEDBLOCK { 2 };
  static constexpr int _CONST_MOVEWEIGHT_IMPLIEDPOINTPAIR { 2 };
  static constexpr int _CONST_MOVEWEIGHT_IMPLIEDN { 2 };

  static constexpr int _CONST_TREESEARCH_INITIALDEPTH { 0 };

  static constexpr int _CONST_THREADING_SHORTSLEEP { 50 };
  static constexpr int _CONST_THREADING_LONGSLEEP { 100 };

private:
  Const() = delete;

};

} // ns util
} // ns sudoku

#endif /* SUDOKU_CONST_H */

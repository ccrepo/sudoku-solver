//
// sudoku_game.h
// sudoku
//

#ifndef SUDOKU_GAME_H
#define SUDOKU_GAME_H

#include <sstream>
#include <deque>

#include "sudoku_tree.h"
#include "sudoku_board.h"
#include "sudoku_log.h"
#include "sudoku_zones.h"
#include "sudoku_cells.h"
#include "sudoku_move.h"

namespace sudoku {
namespace game {

class Game {
  
public:
  Game(const std::string &filename) :
      _cells(new Cells()), _zones(new Zones(_cells->shared_from_this())), _tree(
          new Tree(_cells)), _filename(filename), _inited(false) {
    _inited = _cells->inited() && _zones->inited();
  }

  virtual ~Game() {
  }

  inline bool inited() const {
    return _inited;
  }

  bool solve();

  inline bool solved() const {
    return this->_tree->solved(this->_zones);
  }

  inline operator const std::ostringstream() const {
    std::ostringstream os;
    os << std::endl << std::endl
        << (_tree->operator const std::ostringstream().str());
    return os;
  }

  inline int nodescreated() const {
    return _tree->nodescreated();
  }

private:
  std::shared_ptr<Cells> _cells;
  std::shared_ptr<Zones> _zones;
  std::shared_ptr<Tree> _tree;
  
  const std::string _filename;
  
  bool _inited;
  bool load(OUT std::deque<game::Move>& loaded);

private:
  Game(const Game&) = delete;
  Game& operator=(const Game&) = delete;
};

} // ns game
} // bs sudoku

#endif /* SUDOKU_GAME_H */

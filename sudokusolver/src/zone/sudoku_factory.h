//
// sudoku_factory.h
// sudoku
//

#ifndef SUDOKU_FACTORY_H
#define SUDOKU_FACTORY_H

#include <memory>

namespace sudoku
{
namespace game
{
class Cells;
}

namespace zone
{

template<typename T, typename U>
class Factory
{
public:
  static bool init(const std::shared_ptr<game::Cells>& cells, std::shared_ptr<T>& zones);
  
private:
  Factory()  = delete;

};

} // ns game
} // ns sudoku

#endif /* SUDOKU_FACTORY_H */

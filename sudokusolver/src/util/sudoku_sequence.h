//
// sudoku_sequence.h
// sudoku
//

#ifndef SUDOKU_COUNTED_H
#define SUDOKU_COUNTED_H

namespace sudoku {
namespace util {

class Sequence {

public:
  Sequence() :
      _value(0) {
  }

  virtual ~Sequence() {
  }

  int operator++() {
    return _value++;
  }

  inline int value() const {
    return _value;
  }

  operator int() const {
    return _value++; // TODO - not happy with this !
  }

private:
  mutable int _value;

private:
  Sequence(const Sequence&) = delete;
  Sequence& operator=(const Sequence&) = delete;
};

} // ns util
} // ns sudoku

#endif // ns SUDOKU_COUNTED_H

//
// sudoku_argument.h
// sudoku
//

#ifndef SUDOKU_ARGUMENT_H
#define SUDOKU_ARGUMENT_H

#include <iostream>
#include <vector>
#include <atomic>
#include <memory>

namespace sudoku {
namespace util {

// This class is just enough for working/placeholder. Plenty of room left to improve.

class Argument {

public:
  inline bool terminate() const {
    return _terminate;
  }

  inline bool result() const {
    return _result;
  }

  inline std::string filename() const {
    return _arguments.at(0);
  }

  static bool init(int argc, const char *argv[]); 

  static const Argument* const argument() {
    return _argument.get();
  }

  static void help() {
    constexpr const char *helpText = ""
        "sudokusolver:"
        "\nprogram to solve sudoku "
        "\nusage: arguments "
        "\nsudokusolver -h           # to display this information"
        "\nsudokusolver <filename>   # file containing a sudoku position"
        "\n"
        "\nset environment variable SUDOKUSOLVER_LOGLEVEL to one of "
        "\n'fatal', 'error', 'warn', 'info', 'debug', 'trace' "
        "\ndefaults to 'info'"
        "\n";

    std::cerr << helpText << std::endl;
  }

  virtual ~Argument() {
  }

private:
  Argument(bool terminate, int result,
      const std::vector<std::string> &arguments) :
      _terminate(terminate), _result(result), _arguments(arguments.begin(),
          arguments.end()) {
  }

private:
  const bool _terminate;
  const int _result;
  static std::unique_ptr<Argument> _argument;
  std::vector<std::string> _arguments;

private:
  Argument(const Argument&) = delete;
  Argument& operator=(const Argument&) = delete;

};

} // ns util
} // ns sudoku

#endif /* SUDOKU_ARGUMENT_H */

#include <iostream>
#include "textdisplay.h"
#include "info.h"
#include "subject.h"
using namespace std;

std::ostream &operator<<(std::ostream &out, const TextDisplay &td) {
  for (size_t i = 0; i < td.gridSize; ++i) {
    for (size_t j = 0; j < td.gridSize; ++j) {
      out << td.theDisplay[i][j];
    }
    out << '\n';
  }
  return out;
}

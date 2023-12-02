#include <iostream>
#include "textdisplay.h"
#include "info.h"
#include "subject.h"
#include "cell.h"
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

void TextDisplay::notify(Subject<Info, State> &whoFrom) {
  Cell * cell = static_cast<Cell *>(&whoFrom);
  Info cellInfo = cell->getInfo();
  StateType cellState = cell->getState().type;

  // Change the display, only if the sender is a pressed cell
  if (cellState == StateType::Pressed) {
    theDisplay.at(cellInfo.row).at(cellInfo.col) = cellInfo.neighboursWithMines + '0';
    ++numPressed;
  }
}

int TextDisplay::getNumPressed() const { return numPressed; }

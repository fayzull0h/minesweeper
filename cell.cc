#include <cstddef>
#include <iostream>
#include "cell.h"
#include "info.h"

using namespace std;

Cell::Cell(size_t r, size_t c): r{r}, c{c} {}

void Cell::setNumNeighbours(int n) { numNeighbours = n; }

int Cell::setCell(bool m) {
  if (mine == m) return 0;
  mine = m;
  return m ? 1 : -1;
}

Info Cell::getInfo() const {
  return Info{r, c};
}

void Cell::print(std::ostream &out) const {
  mine ? (out << 'X') : (out << neighboursWithMines);
}

void Cell::notify(Subject<Info, State> &whoFrom) {
  // do smth
}

void Cell::press() {
  // do smth
}
#include <iostream>
#include <cstddef>
#include "grid.h"
#include "info.h"
#include "textdisplay.h"
#include "observer.h"
using namespace std;


void Grid::init(size_t n) {
  theGrid = vector<vector<Cell>>();
  theGrid.reserve(n);
  dimensions = n;
  td = new TextDisplay(n);

  for (size_t i = 0; i < n; ++i) {
    theGrid.emplace_back();
    theGrid.back().reserve(n);

    for (size_t j = 0; j < n; ++j) {
      theGrid[i].emplace_back(i, j);
    }
  }

  size_t r = 0;
  for (auto &row : theGrid) {
    size_t c = 0;
    for (auto &cell : row) {
      size_t nbrs = 0;
      if (c > 0 && r > 0) { cell.attach(&theGrid[r-1][c-1]); ++nbrs; }
      if (c > 0) { cell.attach(&theGrid[r][c-1]); ++nbrs; }
      if (r > 0) { cell.attach(&theGrid[r-1][c]); ++nbrs; }
      if (c > 0 && r < n-1) { cell.attach(&theGrid[r+1][c-1]); ++nbrs; }
      if (c < n-1 && r > 0) { cell.attach(&theGrid[r-1][c+1]); ++nbrs; }
      if (c < n-1) { cell.attach(&theGrid[r][c+1]); ++nbrs; }
      if (r < n-1) { cell.attach(&theGrid[r+1][c]); ++nbrs; }
      if (c < n-1 && r < n-1) { cell.attach(&theGrid[r+1][c+1]); ++nbrs; }
      cell.setNumNeighbours(nbrs);
      cell.attach(td);
      ++c;
    }
    ++r;
  }
}

void Grid::setMine(size_t r, size_t c) {  // Place a mine at r, c
  numMines += theGrid[r][c].setCell(true);
}

std::ostream &operator<<(std::ostream &out, const Grid &g) {
  return (out << *(g.td));
}

int Grid::getNumMines() const { return numMines; }

bool Grid::press(size_t r, size_t c) {
  theGrid[r][c].press();
  Info cellInfo = theGrid[r][c].getInfo();
  return cellInfo.mine;
}

Grid::~Grid() {
  delete td;
}

int Grid::getNumPressed() const {
  return td->getNumPressed();
}

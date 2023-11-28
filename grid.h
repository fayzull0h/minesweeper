#ifndef GRID_H
#define GRID_H
#include <iostream>
#include <vector>
#include <cstddef>
#include "cell.h"
#include "state.h"
#include "info.h"

class TextDisplay;
template <typename InfoType, typename StateType> class Observer;
class InvalidMove{};

class Grid {
  std::vector<std::vector<Cell>> theGrid;  // The actual grid. 
  int dimensions;
  int numMines = 0;
  // Add private members, if necessary.

 public:
  ~Grid();
  
  void init(size_t n); // Sets up an n x n grid.  Clears old grid, if necessary.
  void setMine(size_t r, size_t c);  // Place a mine at r, c
  void press(size_t r, size_t c);  // Bress button at r, c
  int getNumMines() const;
  int getNumPressed() const;

  friend std::ostream &operator<<(std::ostream &out, const Grid &g);
};

#endif

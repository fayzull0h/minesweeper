#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <iostream>
#include <vector>
#include "observer.h"
#include "state.h"
#include "info.h"
class Cell;

class TextDisplay: public Observer<Info, State> {
  std::vector<std::vector<char>> theDisplay;
  const size_t gridSize;
  int numPressed = 0;
 public:
  TextDisplay(size_t n): theDisplay(n, std::vector<char>(n, '-')), gridSize(n) {}

  void notify(Subject<Info, State> &whoFrom) override;

  // Returns the number of cells that were pressed
  int getNumPressed() const;

  friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};
#endif

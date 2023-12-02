#ifndef CELL_H
#define CELL_H
#include <cstddef>
#include "state.h"
#include "subject.h"
#include "observer.h"
#include "info.h"

class Cell : public Subject<Info, State>, public Observer<Info, State> {
  const size_t r, c;
  int neighboursWithMines = 0;
  int numNeighbours = 0;
  bool mine = false;
  
 public:
  Cell(size_t r, size_t c);
  void setNumNeighbours(int n);

  int setCell(bool m);  // Set cell to mine (true) or no mine (False)
           // Returns 1 if mine went from false to true
           // -1 if mine went from true to false
           // 0 if mine stayed the same
           // So the return value tells you the change in total # of mines

  void press();  // Press this button.  If it's a mine, you lose.
  void notify(Subject<Info, State> &whoFrom) override;// My neighbours will call this
                                                // when they've changed state
  Info getInfo() const override;
};
#endif

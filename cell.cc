#include <cstddef>
#include <iostream>
#include "cell.h"
#include "info.h"

using namespace std;

Cell::Cell(size_t r, size_t c): r{r}, c{c} { setState(State{StateType::Initial}); }

void Cell::setNumNeighbours(int n) { numNeighbours = n; }

int Cell::setCell(bool m) {
  if (mine == m) return 0;
  mine = m;
  return m ? 1 : -1;
}

Info Cell::getInfo() const {
  return Info{r, c, mine, neighboursWithMines};
}

void Cell::print(std::ostream &out) const {
  mine ? (out << 'X') : (out << neighboursWithMines);
}

void Cell::notify(Subject<Info, State> &whoFrom) {
  Cell * sender = static_cast<Cell *>(&whoFrom);
  StateType senderState = sender->getState().type;
  StateType myState = this->getState().type;

  switch(senderState) {
    /* if another cell is pressed, send a reply for whether im a mine */
    case StateType::Pressed:
      setState(State{StateType::Reply});
      notifyObservers();
      setState(State{StateType::Initial});
      break;

    /* if i'm pressed and i receive a reply, check if sender is a mine */
    case StateType::Reply:
      if (myState == StateType::Pressed) {
        Info senderInfo = sender->getInfo();
        if (senderInfo.mine) ++neighboursWithMines;
      }
      break;

    /* if i'm in an initial state, and sender wants to propogate, press myself 
    case StateType::Propagate:
      if (myState == StateType::Initial) {
        press();
      }
      break;
    */

    default:
      break;
  }
}

void Cell::press() {
  setState(State{StateType::Pressed});
  notifyObservers();
}
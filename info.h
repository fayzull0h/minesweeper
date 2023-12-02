#ifndef __INFO_H__
#define __INFO_H__
#include <cstddef>
#include "state.h"

struct Info {
  size_t row, col;
  bool mine;
  int neighboursWithMines;
  // Other things as you deem appropriate
};

#endif

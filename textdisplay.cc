#include <iostream>
#include "textdisplay.h"
#include "info.h"
#include "subject.h"
using namespace std;

TextDisplay::TextDisplay(int n): theDisplay(n, vector<char>(n, '-')), gridSize(n) {}



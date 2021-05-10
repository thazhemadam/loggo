#ifndef STATE_H
#define STATE_H

#ifdef LIBRARY
#include <string>
using state = std::string;
// #ifdef GEOMETRY
#else
#include "examples/point.h"
using state = Point;
#endif

#endif

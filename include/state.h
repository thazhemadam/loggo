#ifndef STATE_H
#define STATE_H

#ifdef LIBRARY
using state = std::string;
#endif

// #ifdef GEOMETRY
#else
#include "examples/geometry/point.h"
using state = Point;
// #endif

#endif

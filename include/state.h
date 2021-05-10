#ifndef STATE_H
#define STATE_H

#ifdef LIBRARY
using state = std::string;
#endif

#ifdef GEOMETRY
#include "examples/geometry/point.h"
using state = Point;
#endif

#endif

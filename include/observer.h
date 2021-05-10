#ifndef OBSERVER_H
#define OBSERVER_H

#include <iostream>
#include <vector>
#include "state.h"

class Subject;
class Coordinates;
/*
 * Observer
 * defines an updating interface for objects that should be notified
 * of changes in a subject
 */
class Observer
{
	public:
	virtual ~Observer() {}

	virtual std::tuple<state,state> get_state() const = 0;
	virtual void update(Subject *subject) = 0;
	//virtual void update(Coordinates *subject) = 0;
	virtual void disp() const = 0;
};

#endif

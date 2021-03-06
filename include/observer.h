#ifndef OBSERVER_H
#define OBSERVER_H

#include <iostream>
#include <vector>
#include "state.h"

class Subject;

/*
 * Observer
 * defines an updating interface for objects that should be notified
 * of changes in a subject
 */
class Observer
{
	public:
	virtual ~Observer() {}

	virtual void update(Subject *subject) = 0;
};

#endif

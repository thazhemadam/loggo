#ifndef OBSERVER_H
#define OBSERVER_H

#include <iostream>
#include <vector>

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

	virtual int getState() = 0;
	virtual void update(Subject *subject) = 0;
};

/*
 * Concrete Observer
 * stores state of interest to ConcreteObserver objects and
 * sends a notification to its observers when its state changes
 */
class ConcreteObserver : public Observer
{

	private:
	int observer_state;

	public:
	ConcreteObserver(const int state);
	
	~ConcreteObserver();
	
	int getState();
	void update(Subject *subject);
};

#endif

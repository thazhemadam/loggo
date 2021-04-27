#ifndef CONCRETE_OBSERVER_H
#define CONCRETE_OBSERVER_H

#include "../observer.h"

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

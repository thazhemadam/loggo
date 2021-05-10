#ifndef CONCRETE_OBSERVER_H
#define CONCRETE_OBSERVER_H

#include "../observer.h"
#include "../state.h"

/*
 * Concrete Observer
 * stores state of interest to ConcreteObserver objects and
 * sends a notification to its observers when its state changes
 */
class ConcreteObserver : public Observer
{

	private:
	state observer_state_;

	public:
	ConcreteObserver() = default;
	ConcreteObserver(const state state);

	virtual ~ConcreteObserver();

	state get_state() const;
	virtual void update(Subject *subject);
	virtual void disp() const;
};

#endif

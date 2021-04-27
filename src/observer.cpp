#include "observer.h"
#include "subject.h"

ConcreteObserver::ConcreteObserver(const int state)
: observer_state(state)
{}

ConcreteObserver::~ConcreteObserver()
{}

int ConcreteObserver::getState()
{
	return observer_state;
}

void ConcreteObserver::update(Subject *subject)
{
	observer_state = subject->getState();
	std::cout << "Observer state updated." << std::endl;
}

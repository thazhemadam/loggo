#include "concretes/observer.h"
#include "concretes/subject.h"

ConcreteObserver::ConcreteObserver(const std::string state)
: observer_state(state)
{}

ConcreteObserver::~ConcreteObserver()
{}

std::string ConcreteObserver::getState()
{
	return observer_state;
}

void ConcreteObserver::update(Subject *subject)
{
	observer_state = subject->getState();
	std::cout << "Observer state updated." << std::endl;
}

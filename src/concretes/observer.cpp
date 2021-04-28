#include "concretes/observer.h"
#include "concretes/subject.h"
#include "state.h"

ConcreteObserver::ConcreteObserver(const state state)
: observer_state(state)
{}

ConcreteObserver::~ConcreteObserver()
{}

state ConcreteObserver::getState()
{
	return observer_state;
}

void ConcreteObserver::update(Subject *subject)
{
	observer_state = subject->getState();
	std::cout << "Observer state updated." << std::endl;
}

void ConcreteObserver::disp() const
{
	std::cout << "Observer state " << observer_state << "\n";
}
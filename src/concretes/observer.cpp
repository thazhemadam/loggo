#include "concretes/observer.h"
#include "concretes/subject.h"
#include "state.h"

ConcreteObserver::ConcreteObserver(const state state)
: observer_state_(state)
{}

ConcreteObserver::~ConcreteObserver()
{}

state ConcreteObserver::get_state() const
{
	return observer_state_;
}

void ConcreteObserver::update(Subject *subject)
{
	observer_state_ = subject->get_state();
	std::cout << "Observer state updated." << std::endl;
}

void ConcreteObserver::disp() const
{
	std::cout << "Observer state " << observer_state_ << "\n";
}
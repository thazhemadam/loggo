#include "concretes/observer.h"
#include "concretes/subject.h"
#include "state.h"

ConcreteSubject::~ConcreteSubject()
{}

state ConcreteSubject::get_state() const
{
	return subject_state_;
}

void ConcreteSubject::set_state(const state s, bool auto_notify)
{
	subject_state_ = s;

	if(auto_notify)
		notify();
}

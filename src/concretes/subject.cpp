#include "concretes/observer.h"
#include "concretes/subject.h"
#include "state.h"

state ConcreteSubject::get_state() const
{
	return subject_state_;
}

void ConcreteSubject::set_state(const state s)
{
	subject_state_ = s;
}

#include "concretes/observer.h"
#include "concretes/subject.h"
#include "state.h"

state ConcreteSubject::getState()
{
	return subject_state_;
}

void ConcreteSubject::setState(const state s)
{
	subject_state_ = s;
}

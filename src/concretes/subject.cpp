#include "concretes/observer.h"
#include "concretes/subject.h"

int ConcreteSubject::getState()
{
	return subject_state;
}

void ConcreteSubject::setState(const int s)
{
	subject_state = s;
}

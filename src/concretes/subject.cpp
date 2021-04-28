#include "concretes/observer.h"
#include "concretes/subject.h"

std::string ConcreteSubject::getState()
{
	return subject_state;
}

void ConcreteSubject::setState(const std::string s)
{
	subject_state = s;
}

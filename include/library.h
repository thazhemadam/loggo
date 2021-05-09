#ifndef LIBRARY_H
#define LIBRARY_H

#include "concretes/observer.h"
#include "concretes/subject.h"

class Library : public ConcreteObserver, public ConcreteSubject
{
private:

public:

	Library() : ConcreteObserver(), ConcreteSubject()  {};

	Library(const state state)
	: ConcreteObserver(state)
	{}

};

#endif

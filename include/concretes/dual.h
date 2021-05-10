#ifndef DUAL_H
#define DUAL_H

#include "observer.h"
#include "subject.h"

// Acts as an Observer and a Subject
class Dual : public ConcreteObserver, public ConcreteSubject
{
private:
public:

	Dual() : ConcreteObserver(), ConcreteSubject()  {};

	Dual(const state state)
	: ConcreteObserver(state)
	{}

	virtual ~Dual() {};
};

#endif

#ifndef SUBJECT_H
#define SUBJECT_H

#include <iostream>
#include <vector>
#include "state.h"

class Observer;

/*
 * Subject
 * knows its observers and provides an interface for attaching
 * and detaching observers
 */
class Subject
{

	private:
	std::vector<Observer*> observers;

	public:
	virtual ~Subject() {}
	
	void attach(Observer *observer);
	void detach(const int index);

	void notify();
	
	virtual state getState() = 0;
	virtual void setState(const state s) = 0;
};

#endif

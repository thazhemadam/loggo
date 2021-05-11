#ifndef SUBJECT_H
#define SUBJECT_H

#include <iostream>
#include <vector>
#include "state.h"
#include "change_manager.h"

class Observer;

/*
 * Subject
 * knows its observers and provides an interface for attaching
 * and detaching observers
 */
class Subject
{

	private:
	std::vector<Observer*> observers_;

	public:
	virtual ~Subject() {}

	virtual void attach(Observer *observer);
	virtual void detach(Observer *observer);
	virtual void notify();

	virtual state get_state() const = 0;
	virtual void set_state(const state &s, bool auto_notify = false) = 0;
};

#endif

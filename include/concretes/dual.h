#ifndef DUAL_H
#define DUAL_H

#include "../observer.h"
#include "../subject.h"

// Acts as an Observer and a Subject
class Dual : public Observer, public Subject
{
private:
	state subject_state_;
	state observer_state_;

public:

	Dual() : Observer(), Subject()  {};

	Dual(const state state)
	: observer_state_(state), subject_state_(state)
	{
		void *temp = this;
		ChangeManager::get()->initialize_(this, temp);
	}

	virtual ~Dual() {};

	virtual state get_state() const
	{
		return subject_state_;
	}

	virtual void update(Subject *subject)
	{
		observer_state_ = subject->get_state();
		set_state(observer_state_, true);
	}

	virtual void set_state(const state s, bool auto_notify = false)
	{

		subject_state_ = s;

		if(auto_notify)
			notify();
	}

	virtual void disp()
	{
		std::cout << "State : " << observer_state_ << "\n";
	}

};

#endif

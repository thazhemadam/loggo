#ifndef CONCRETE_SUBJECT_H
#define CONCRETE_SUBJECT_H

#include "../subject.h"
#include "../state.h"

/*
 * Concrete Subject
 * stores state that should stay consistent with the subject's
 *
class ConcreteSubject : public Subject
{
	private:
	state subject_state_;

	public:
	ConcreteSubject() = default;
	virtual ~ConcreteSubject();

	virtual std::tuple<state,state> get_state() const;
	virtual void set_state(const state s, bool auto_notify = false);
};*/

#endif

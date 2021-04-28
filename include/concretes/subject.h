#ifndef CONCRETE_SUBJECT_H
#define CONCRETE_SUBJECT_H

#include "../subject.h"
#include "../state.h"

/*
 * Concrete Subject
 * stores state that should stay consistent with the subject's
 */
class ConcreteSubject : public Subject
{
	private:
	state subject_state_;

	public:
	state getState();
	void setState(const state s);
};

#endif

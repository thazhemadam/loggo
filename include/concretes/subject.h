#ifndef CONCRETE_SUBJECT_H
#define CONCRETE_SUBJECT_H

#include "../subject.h"

/*
 * Concrete Subject
 * stores state that should stay consistent with the subject's
 */
class ConcreteSubject : public Subject
{
	private:
	int subject_state;

	public:
	int getState();
	void setState(const int s);
};

#endif

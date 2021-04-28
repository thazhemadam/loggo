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
	std::string subject_state;

	public:
	std::string getState();
	void setState(const std::string s);
};

#endif

#ifndef COORDINATES_H
#define COORDINATES_H

#include "../subject.h"
#include "../state.h"

/*
 * Concrete Subject
 * stores state that should stay consistent with the subject's
 */
class Coordinates : public Subject
{
	protected:
	state x_coord;
    state y_coord;

	public:

	Coordinates(const state x, const state y);
	virtual ~Coordinates();

	virtual state get_state() const;
	virtual void set_state(const state s,const state y, bool auto_notify = false);
};

#endif

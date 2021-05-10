#ifndef ANGLE_H
#define ANGLE_H

#include "../observer.h"
#include "../state.h"

/*
Angle class is not complete, Requires many changes
*/
class Angle : public Observer
{

	private:
	state angle=0;
    state slope_=0;//Temporary, will be removed after fixing implementation !

	public:
	Angle() = default;
	Angle(const state m)
    : slope_(m) // taking in the slope for now!
    {}

	virtual ~Angle();

	virtual std::tuple<state,state> get_state() const;
	virtual void update(Subject *subject);
	virtual void disp() const;
};

#endif

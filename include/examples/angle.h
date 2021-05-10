#ifndef ANGLE_H
#define ANGLE_H

#include "../concretes/observer.h"
#include "../state.h"
#include "../observer.h"

class Angle : public Observer
{
public:
    // to make into a line
    Line l_1_;
    Line l_2_;

    Angle() = default;
    Angle(Line l1, Line l2, bool auto_attach = false) : l_1_(l1), l_2_(l2)
    {
        if(auto_attach) {
            l_1_.attach(this);
            l_2_.attach(this);
        }
    }

    // virtual - to be or not to be.
	void update(Subject *subject);

};

#endif

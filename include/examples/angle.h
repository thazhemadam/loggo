#ifndef ANGLE_H
#define ANGLE_H

#include "../concretes/observer.h"
#include "../state.h"

class Angle
{
public:
    // to make into a line
    double slope_1_;
    double slope_2_;

    Angle() = default;
    Angle(double s1, double s2) : slope_1_(s1), slope_2_(s2) {}

    // virtual - to be or not to be.
	virtual void update(Subject *subject);
	virtual void disp() const;
};

#endif

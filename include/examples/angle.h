#ifndef ANGLE_H
#define ANGLE_H

#include "../concretes/observer.h"
#include "../state.h"
#include "../observer.h"
#include <math.h>

class Angle : public Observer
{
private:
    state observer_state_[2];
    double angle_;
public:
    // to make into a line
    Line l_1_;
    Line l_2_;

    Angle() = default;
    Angle(Line l1, Line l2, bool auto_attach = true) : l_1_(l1), l_2_(l2)
    {
        if(auto_attach) {
            l_1_.attach(this);
            l_2_.attach(this);
        }

        double m1 = l_1_.slope_;
        double m2 = l_2_.slope_;
        angle_ = abs((m2 - m1)/(1 + (m1 * m2)));
    }

    friend std::ostream& operator<<(std::ostream &os, const Angle& angle)
    {
        os << "\nAngle: " << angle.angle_ << " degrees.\n";
        return os;
    }

    // virtual - to be or not to be.
	void update(Subject *subject)
    {
        std::cout << "\nIn angle's update\n";

        for(int i = 0; i < 2; ++i)
            observer_state_[i] = subject->get_state();
    }

};

#endif

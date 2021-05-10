#ifndef LINE_H
#define LINE_H

#include "../concretes/dual.h"
#include "../state.h"
#include "coordinates.h"
#include <math.h>

class Line : public Dual
{

private:
    state observer_state_[2];
	double distance_;
    double slope_;


public:
    Coordinates p_1_;
    Coordinates p_2_;

	Line() = default;
	Line(Coordinates x, Coordinates y, bool auto_attach = false)
    : p_1_(x), p_2_(y)
    {
        distance_ = manhattan_distance(x, y); 
        slope_ = slope(x, y);

        if(auto_attach) {
            p_1_.attach(this);
            p_2_.attach(this);
        }
    }

	~Line() {}

    double manhattan_distance(Coordinates p_1, Coordinates p_2)
    {
        return (abs(p_2.point_.x_ - p_1.point_.x_) + abs(p_2.point_.y_ - p_1.point_.y_));
    }


    double slope(Coordinates p_1, Coordinates p_2)
    {
        return ((p_2.point_.y_ - p_1.point_.y_)/((p_2.point_.x_ - p_1.point_.x_)) );
    }


    void update_distance()
    {
        distance_ = manhattan_distance(p_1_, p_2_);
    }

    void update_slope()
    {
        slope_ = slope(p_1_, p_2_);
    }

	state get_state(int index) const
    {
        return observer_state_[index];
    }

    void update(Subject *subject)
    {
        if(subject == &p_1_) {
            p_1_ = subject->get_state();
            observer_state_[0] = subject->get_state();
        }
        else {
            observer_state_[1] = subject->get_state();
            p_2_ = subject->get_state();
        }

        update_distance();
        update_slope();
        notify();       // Notify all Observers of this line that this line has changed.
    }

    void disp() const
    {
        std::cout << *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Line& line)
    {
        os << "\nCoordinates 1:\n" << line.p_1_;
        os << "\nCoordinates 2:\n" << line.p_2_;
        os << "\nDistance: \t" << line.distance_;
        os << "\nSlope: \t" << line.slope_ << "\n";
        return os;
    }
};

#endif

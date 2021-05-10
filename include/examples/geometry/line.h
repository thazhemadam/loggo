#ifndef LINE_H
#define LINE_H

#include "../../concretes/observer.h"
#include "../../state.h"
#include "coordinates.h"
#include <math.h>

class Line : public ConcreteObserver
{

private:
	double distance_;
    double slope_;


public:
    Coordinates p_1_;
    Coordinates p_2_;

	Line() = default;
	Line(Coordinates x, Coordinates y, bool auto_attach = true)
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

    void update(Subject *subject)
    {
        update_distance();
        update_slope();
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

#ifndef COORDINATES_H
#define COORDINATES_H

#include "point.h"
#include "../subject.h"
#include <sstream>

class Coordinates : public Subject
{
private:
    Point point_;
    state subject_state_;

    Coordinates& operator=(const Coordinates &rhs)
    {
        if(this != &rhs) {
            point_ = rhs.point_;
        }

        return *this;
    }


public:
    Coordinates() = default;
    Coordinates(Point z) : point_(z) {}
    Coordinates(double x, double y) : point_(Point(x, y)) {}
    virtual ~Coordinates() {}

    friend std::ostream& operator<<(std::ostream& os, const Coordinates& point)
    {
        os << point.point_;
        return os;
    }

	state get_state() const
    {
        return subject_state_;
    }

	void set_state(const state s, bool auto_notify = false)
    {
        std::cout << "\nIn coordinates' set_state\n";
        subject_state_ = s;

        if(auto_notify)
            notify();

        return;
    }

    friend class Line;
};

#endif

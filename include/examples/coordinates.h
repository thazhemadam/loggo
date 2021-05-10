#ifndef COORDINATES_H
#define COORDINATES_H

#include "point.h"
#include "../concretes/subject.h"

class Coordinates : public ConcreteSubject
{
private:
    Point point_;
    state subject_state_;

public:
    Coordinates() = default;
    Coordinates(Point z) : point_(z) {}
    Coordinates(double x, double y) : point_(Point(x, y)) {}
    ~Coordinates() {}

    Coordinates& operator=(const Coordinates &rhs)
    {
        if(this != &rhs) {
            point_ = rhs.point_;
            notify();
        }

        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Coordinates& point)
    {
        os << point.point_;
        return os;
    }

    friend class Line;

};

#endif

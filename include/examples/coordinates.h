#ifndef COORDINATES_H
#define COORDINATES_H

#include "point.h"
#include "../concretes/subject.h"
#include <sstream>

class Coordinates : public ConcreteSubject
{
private:
    Point point_;
    state subject_state_;

	void set_state(const state s, bool auto_notify = false)
    {
        subject_state_ = s;

        if(auto_notify)
            notify();

        return;
    }

	state updated_state()
    {
        std::stringstream ss;
        ss << *this;
        std::cout << ss.str();

        return state(ss.str());
    }


public:
    Coordinates() = default;
    Coordinates(Point z) : point_(z) {}
    Coordinates(double x, double y) : point_(Point(x, y)) {}
    virtual ~Coordinates() {}

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

	state get_state() const
    {
        return subject_state_;
    }

    void set_state(const Point new_point, bool autonotify = false)
    {
        point_ = new_point;
        set_state(updated_state(), autonotify);
    }

    friend class Line;
};

#endif

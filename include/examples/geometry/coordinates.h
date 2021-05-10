#ifndef COORDINATES_H
#define COORDINATES_H

#include "point.h"
#include "../../concretes/subject.h"
#include <sstream>

class Coordinates : public ConcreteSubject
{
private:
    Point point_;

public:

    Coordinates() = delete;
    Coordinates(Point z) : point_(z)
    {
        void *temp = this;
		ChangeManager::get()->initialize_(this, temp);
    }

    Coordinates(double x, double y) : point_(Point(x, y)) {
        void *temp = this;
		ChangeManager::get()->initialize_(this, temp);
    }

    ~Coordinates() {}

    Coordinates& operator=(const Coordinates &rhs)
    {
        if(this != &rhs) {
            point_ = rhs.point_;
            set_state(point_, true);
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Coordinates& point)
    {
        os << point.point_;
        return os;
    }

    void set_state(state s, bool autonotify = false)
    {
        point_ = s;
        ConcreteSubject::set_state(s, autonotify);
    }

    friend class Line;
};

#endif

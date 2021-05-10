#ifndef POINT_H
#define POINT_H

typedef struct Point 
{
    double x_;
    double y_;
    Point(double x, double y) : x_(x), y_(y) {}

    Point& operator=(const Point &rhs)
    {
        if(this != &rhs) {
            x_ = rhs.x_;
            y_ = rhs.y_;
        }

        return *this;
    }


    friend std::ostream& operator<<(std::ostream& os, const Point& point)
    {
        os << "x_ : " << point.x_ << "\ny_ : " << point.y_ << "\n";
        return os;
    }

} Point;

#endif

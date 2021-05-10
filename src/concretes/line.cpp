#include "concretes/coordinates.h"
#include "state.h"
#include "concretes/line.h"
#include <cmath>

Line::~Line()
{}

std::tuple<state,state> Line::get_state() const
{
	return std::make_tuple(x_coord_2,y_coord_2);
}

void Line::update(Subject *subject)
{
	state x_coord_1,y_coord_1;
	std::tie(x_coord_1, y_coord_1) = subject->get_state();
	distance = sqrt((x_coord_2 - y_coord_1)*(x_coord_2 - y_coord_1) + (y_coord_2-y_coord_1)*(y_coord_2-y_coord_1));
	slope = (y_coord_2 - y_coord_1)/(x_coord_2 - x_coord_1);
	std:: cout << x_coord_1 << ":" << y_coord_1 << "," << x_coord_2 << ":" << y_coord_2 << std::endl;
	std::cout << "Observer state updated." << std::endl;
}

void Line::disp() const
{
	std::cout << "Observer state " << x_coord_2 << ":" << y_coord_2 << "\n";
	std::cout << "Distance " << distance << ", Slope " << slope << "\n";
}

#include "concretes/coordinates.h"
#include "state.h"
#include "concretes/line.h"

Line::~Line()
{}

state Line::get_state() const
{
	return y_coord_2;
}

void Line::update(Subject *subject)
{
	state y_coord_1 = subject->get_state();
	distance = y_coord_1 + 0;
	y_coord_2 = y_coord_1;
	slope = (x_coord_2 + 0)/(distance);
	std::cout << "Observer state updated." << std::endl;
}

void Line::disp() const
{
	std::cout << "Observer state " << x_coord_2 << ":" << y_coord_2 << "\n";
	std::cout << "Distance " << distance << ", Slope " << slope << "\n";
}

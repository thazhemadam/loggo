#include "concretes/coordinates.h"
#include "state.h"
#include "concretes/angle.h"
#include <cmath>

Angle::~Angle()
{}

std::tuple<state,state> Angle::get_state() const
{
	return std::make_tuple(angle,slope_);
}

void Angle::update(Subject *subject)
{
	state distance_,slope;
	std::tie(distance_, slope) = subject->get_state();
	angle = distance_;
    std::cout << "Observer state updated for angle." <<distance_ << std::endl;
}

void Angle::disp() const
{
	//std::cout << "Observer state " << x_coord_2 << ":" << y_coord_2 << "\n";
	std::cout << "Angle " << angle << ", Slope " << slope_ << "\n";
}

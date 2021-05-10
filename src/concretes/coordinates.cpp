#include "concretes/observer.h"
#include "concretes/coordinates.h"
#include "state.h"

Coordinates::Coordinates(const state x, const state y)
:x_coord(x),y_coord(y)
{
    
}

Coordinates::~Coordinates()
{}

std::tuple<state,state> Coordinates::get_state() const
{
	return std::make_tuple(x_coord,y_coord);
}

void Coordinates::set_state(const state x,const state y, bool auto_notify)
{
	x_coord = x;
    y_coord=y;

	if(auto_notify)
		notify();
}

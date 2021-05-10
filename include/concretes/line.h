#ifndef LINE_H
#define LINE_H

#include "../observer.h"
#include "../state.h"

/*
 * Concrete Observer
 * stores state of interest to ConcreteObserver objects and
 * sends a notification to its observers when its state changes
 */
class Line : public Observer
{

	private:
	state distance =0;
    state slope=0;
    state x_coord_2;
    state y_coord_2;

	public:
	Line() = default;
	Line(const state x,const state y)
    : x_coord_2(x),y_coord_2(y)
    {
    }

	virtual ~Line();

	virtual state get_state() const;
	virtual void update(Subject *subject);
	virtual void disp() const;
};

#endif

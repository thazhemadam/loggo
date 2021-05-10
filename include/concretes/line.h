#ifndef LINE_H
#define LINE_H

#include "../observer.h"
#include "../state.h"

/*
 * Concrete Observer
 * stores state of interest to ConcreteObserver objects and
 * sends a notification to its observers when its state changes
 */
class Line : public Observer,public Subject
{

	protected:
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
    //Subject
    virtual std::tuple<state,state> get_state() const;
	virtual void set_state(const state x,const state y, bool auto_notify = false);
    //Observer
	//virtual std::tuple<state,state> get_state() const;
	virtual void update(Subject *subject);
	virtual void disp() const;
};

#endif

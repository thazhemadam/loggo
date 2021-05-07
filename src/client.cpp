#include "logga.h"

int main()
{
	ConcreteObserver observer1("STATE - 1");
	ConcreteObserver observer2("STATE - 2");

	observer1.disp();
	observer2.disp();

	Subject *subject = new ConcreteSubject();
	subject->attach(&observer1);
	subject->attach(&observer2);

	subject->set_state("STATE - LIQUID");
	subject->notify();

	observer1.disp();
	observer2.disp();
	

	subject->detach(&observer1);

	subject->set_state("STATE - Karnataka");
	subject->notify();

	observer1.disp();
	observer2.disp();

	delete subject;
	return 0;
}

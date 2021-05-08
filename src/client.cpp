#include "logga.h"

int main()
{
	ConcreteObserver observer1("STATE - 1");
	ConcreteObserver observer2("STATE - 2");
	ConcreteObserver observer3("STATE - 3");


	observer1.disp();
	observer2.disp();
	observer3.disp();

	Subject *subject = new ConcreteSubject();
	Subject *subject2 = new ConcreteSubject();

	subject->attach(&observer1);
	subject->attach(&observer3);
	subject2->attach(&observer3);


	
	//subject2->set_state("STATE - LI");
	//subject->set_state("STATE - LIQUID");
	subject2->set_state("from sub 2");
	subject->notify();

	observer1.disp();
	observer2.disp();
	observer3.disp();
	

	subject->detach(&observer1);

	subject->set_state("STATE - Karnataka");
	subject->notify();

	observer1.disp();
	observer2.disp();

	delete subject;
	return 0;
}

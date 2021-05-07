#include "logga.h"

int main()
{
	
	ConcreteObserver observer1("STATE - 1");
	ConcreteObserver observer2("STATE - 2");
	ChangeManager CM;

	observer1.disp();
	observer2.disp();

	ConcreteSubject *subject = new ConcreteSubject();
	//subject->attach(&observer1);
	//subject->attach(&observer2);

	subject->setState("STATE - LIQUID");
	//subject->notify();

	CM.Subscribe(subject,observer1);
	CM.Subscribe(subject,observer2);

	CM.Notify(subject);



	observer1.disp();
	observer2.disp();
	

	delete subject;
	return 0;
}

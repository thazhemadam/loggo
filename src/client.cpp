#include "logga.h"

int main()
{
	ConcreteObserver observer1("STATE - 1");
	ConcreteObserver observer2("STATE - 1");

	std::cout << "Observer 1 state: " << observer1.getState() << std::endl;
	std::cout << "Observer 2 state: " << observer2.getState() << std::endl;

	Subject *subject = new ConcreteSubject();
	subject->attach(&observer1);
	subject->attach(&observer2);

	subject->setState("STATE - LIQUID");
	subject->notify();

	std::cout << "Observer 1 state: " << observer1.getState() << std::endl;
	std::cout << "Observer 2 state: " << observer2.getState() << std::endl;

	delete subject;
	return 0;
}
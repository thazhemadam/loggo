#include "logga.h"

int main()
{
	Library observer1("STATE - 1");
	Library observer2("STATE - 2");

	observer1.disp();
	observer2.disp();

	Library subject;
	subject.attach(&observer1);
	subject.attach(&observer2);

	subject.set_state("STATE - LIQUID");
	subject.notify();

	observer1.disp();
	observer2.disp();
	

	subject.detach(&observer1);

	subject.set_state("STATE - Karnataka");
	subject.notify();

	observer1.disp();
	observer2.disp();

	return 0;
}

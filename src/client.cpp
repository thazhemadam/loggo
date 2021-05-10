#include "logga.h"

int main()
{
	Coordinates coord(1,2);
	//std::cout << coord.get_state() << std::endl;

	Line line1(2,3);
	//line1.disp();

	coord.attach(&line1);
	line1.disp();
	coord.set_state(6,7,true);
	line1.disp();

	#if 0
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
	#endif
	return 0;
}

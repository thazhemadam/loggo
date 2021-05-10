#include "logga.h"

int main()
{
	Coordinates coord1(1,2);
	Coordinates coord2(9,2);
	//std::cout << coord.get_state() << std::endl;

	Line line1(2,3);
	//line1.disp();

	coord1.attach(&line1);
	line1.disp();
	std::cout << "----detach----\n";
	coord1.detach(&line1);
	line1.disp();
	std::cout << "----attach----\n";
	coord2.attach(&line1);
	//coord2.set_state(6,7,true);
	line1.disp();

	#if 1
// For now angle takes a slope i.e 4 and it does nothing !!
	Angle angle_1_2(4);
	line1.attach(&angle_1_2);//should be made to attach to only 2 lines !!
	angle_1_2.disp(); // should display the angle bw them !!
	std::cout << "-------Change------" << "\n";
	coord2.set_state(5,9,true);//change in coordinates
	line1.disp();	//changes line
	angle_1_2.disp(); // changes angle also
	#endif

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

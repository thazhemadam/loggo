#include "logga.h"
using namespace std;

int main()
{
	
	#if 1
	Dual library_1("LIB - 1");
	Dual library_2("LIB - 2");
	Dual library_3("LIB - 3");
	Dual library_4("LIB - 4");
	Dual library_5("LIB - 5");
	Dual library_6("LIB - 6");

	library_1.attach(&library_4);
	library_2.attach(&library_4);
	library_2.attach(&library_5);
	library_3.attach(&library_5);
	library_4.attach(&library_5);
	library_5.attach(&library_6);
	
	cout << "-------------------------------------\n";
	library_2.set_state("STATE - LIQUID", true);
	cout << "-------------------------------------\n";
	library_1.disp();
	library_2.disp();
	library_3.disp();
	library_4.disp();
	library_5.disp();
	library_6.disp();
	cout << "-------------------------------------\n\n\n";
	#endif

	Coordinates z1 = Coordinates(5, 2);
	Coordinates z2 = Coordinates(4, 1);
	Line l1 = Line(z1, z2);
	cout << l1;

	Line l2 = Line(z1, z2, true);
	cout << l2;
	l2.p_2_ = z1;

	return 0;
}

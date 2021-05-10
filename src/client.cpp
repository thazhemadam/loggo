#include "logga.h"
using namespace std;

int main()
{
	
	#ifdef LIBRARY
	Library library_1("LIB - 1");
	Library library_2("LIB - 2");
	Library library_3("LIB - 3");
	Library library_4("LIB - 4");
	Library library_5("LIB - 5");
	Library library_6("LIB - 6");

	// cout << "LIBRARY 1 : " << &library_1 << "\n";
	// cout << "LIBRARY 2 : " << &library_2 << "\n";
	// cout << "LIBRARY 3 : " << &library_3 << "\n";
	// cout << "LIBRARY 4 : " << &library_4 << "\n";
	// cout << "LIBRARY 5 : " << &library_5 << "\n";
	// cout << "LIBRARY 6 : " << &library_6 << "\n";

	// cout << "-------------------------------------\n";
	// cout << "Registering 1 ";
	 library_1.attach(&library_4);
	 library_1.attach(&library_3);
	 library_1.attach(&library_2);
	 library_1.attach(&library_1);

	// cout << "Registering 2 ";
	 library_2.attach(&library_4);
	// cout << "Registering 2 ";
	 library_2.attach(&library_5);
	// cout << "Registering 3 ";
	 library_3.attach(&library_5);
	// cout << "Registering 4 ";
	 library_4.attach(&library_5);
	// cout << "Registering 5 ";
	 library_5.attach(&library_6);

	// ChangeManager::get()->disp();
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
	library_1.set_state("STATE - Sleep", true);
	cout << "-------------------------------------\n\n\n";
	library_1.disp();
	library_2.disp();
	library_3.disp();
	library_4.disp();
	library_5.disp();
	library_6.disp();

	#elif GEOMETRY
	Coordinates z1 = Coordinates(5, 2);
	Coordinates z2 = Coordinates(2, 1);
	Coordinates z3 = Coordinates(2, 5);
	Coordinates z4 = Coordinates(3, 1);
	

	Line l1 = Line(z1, z2, true);
	Line l2 = Line(z1, z3, true);

	cout << "\n\nlllllllllllllllllllllllll\n";
	cout << "L1\t\t" << &l1 << "\n";
	cout << "L1.p_1_ \t " << &l1.p_1_ << "\n";
	cout << "L1.p_2_ \t" << &l1.p_2_ << "\n";
	cout << "L2 \t\t" << &l2 << "\n";
	cout << "L2.p_1_ \t " << &l2.p_1_ << "\n";
	cout << "L2.p_2_ \t" << &l2.p_2_ << "\n";
	cout << "lllllllllllllllllllllllll\n";

	cout <<"\n---------------- \n BEFORE \n";
	cout << l1;
	// Angle angle(l1, l2);
	// cout << &angle;

	l1.p_1_.set_state(Point(5,4), true);
	cout <<"\n---------------- \n AFTER \n";
	cout << l1;
	// line has 2 coordinates	-> an object itself changes state depending upon the state of its own members
	// -> subjects & the line is an observer
	// Angle has 2 lines
	// -> lines are subjects and angle is the obserer



	#endif
	return 0;
}
/*
	1, 2, 3
	2 -> 1
	3 -> 2
	1 changes.
*/
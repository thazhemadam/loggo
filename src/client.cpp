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
	std::cout << "\n\nLine Stats:";

	std::cout << &l1 << "\n\t";
	std::cout << &z1 << "\t" << &z2 << "\n";
	// std::cout << "\n\n";

	// ChangeManager::get()->disp();

	// std::cout << "\n\n";

	
	// Line l2 = Line(z1, z3, true);

	// cout <<"\n---------------- \n BEFORE \n";
	// cout << l1;



	// Point *new_point = new Point(5, 23);
	// l1.p_1_.set_state(new_point, true);
	// cout <<"\n---------------- \n AFTER \n";
	// cout << l1;

	#endif
	return 0;
}

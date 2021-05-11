#include "logga.h"
using namespace std;

int main()
{
	#if 0

	#ifdef LIBRARY
	Library library_1("Imported Library", "LIB - 1", "1.3.8");
	Library library_2("Imported Library", "LIB - 2", "3.3.7");
	Library library_3("Imported Library", "LIB - 3", "4.6.9");
	Library library_4("Imported Library", "LIB - 4", "1.1.3");
	Library library_5("Imported Library", "LIB - 5", "0.3.2");
	Library library_6("Imported Library", "LIB - 6", "1.7.8");

	#ifdef DEBUG_DUAL
	cout << "LIBRARY 1 : " << &library_1 << "\n";
	cout << "LIBRARY 2 : " << &library_2 << "\n";
	cout << "LIBRARY 3 : " << &library_3 << "\n";
	cout << "LIBRARY 4 : " << &library_4 << "\n";
	cout << "LIBRARY 5 : " << &library_5 << "\n";
	cout << "LIBRARY 6 : " << &library_6 << "\n";
	#endif

	// lib1 , lib2 - Subjects with components, and Observers have
	// part of a library
	library_1.attach(&library_4);
	library_1.attach(&library_3);
	library_1.attach(&library_2);
	library_1.attach(&library_1);	// self
	library_2.attach(&library_4);
	library_2.attach(&library_5);
	library_3.attach(&library_5);
	library_4.attach(&library_5);
	library_5.attach(&library_6);

	#ifdef DEBUG_DUAL
	ChangeManager::get()->disp();
	#endif
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

	cout <<"\n---------------- \n BEFORE \n";
	cout << l1;

	
	l1.p_2_ = z3;


	cout <<"\n---------------- \n AFTER \n";
	cout << l1;

	#endif
	#endif

	Library library_1("Imported Library", "LIB - 1", "1.3.8");
	Module new_mod("Module 1");
	Module new_mod2("Module 2");

	library_1.add_module(new_mod);
	library_1.add_module(new_mod2);

	Library library_2("Imported Library", "LIB - 2", "4.3.8");
	Library library_3("Imported Library", "LIB - 3", "2.1.4");

	std::cout << &library_1 <<"\n";
	std::cout << &library_2 <<"\n";
	std::cout << &library_3 <<"\n";
	std::cout << &new_mod <<"\n";
	std::cout << &new_mod2 <<"\n";

	ChangeManager::get()->disp();


	library_2.attach(new_mod);
	library_3.attach(new_mod2);

	ChangeManager::get()->disp();


	std::cout <<" \n========================================\n";
	new_mod.set_state("Module 1 Updated!", true);
	std::cout << new_mod.get_state() << "\n";

	std::cout <<" \n========================================\n";

	ChangeManager::get()->disp();

	std::cout <<" \n========================================\n";

	new_mod2.set_state("Module 2 Updated!", true);
	std::cout << new_mod2.get_state() << "\n";

	std::cout <<" \n========================================\n";

	library_1.disp();
	library_2.disp();
	library_3.disp();


	return 0;
}

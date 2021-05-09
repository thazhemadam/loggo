#include "logga.h"
using namespace std;

int main()
{
	Library library_1("LIB - 1");
	Library library_2("LIB - 2");
	Library library_3("LIB - 3");
	Library library_4("LIB - 4");
	Library library_5("LIB - 5");
	Library library_6("LIB - 6");

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
	cout << "-------------------------------------\n";

	return 0;
}

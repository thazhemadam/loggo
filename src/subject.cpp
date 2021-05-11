#include "observer.h"
#include "subject.h"

void Subject::attach(Observer *observer)
{
	#if DEBUG_DUAL
		std::cout << "In Subject::Attach -\t" << this <<"\n";
	#endif
	ChangeManager::get()->register_((this), observer);
}


void Subject::attach(Observer *observer, Aspect &aspect)
{
	#if DEBUG_DUAL
		std::cout << "In Subject::Attach -\t" << this <<"\n";
	#endif
	ChangeManager::get()->register_((this), observer);
}



void Subject::detach(Observer *observer)
{
	ChangeManager::get()->unregister_(this, observer);
}
	
void Subject::notify()
{
	ChangeManager::get()->notify_(this);
}

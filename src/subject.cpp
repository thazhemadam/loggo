#include "observer.h"
#include "subject.h"


void Subject::attach(Observer *observer)
{
	
	ChangeManager::get()->register_(this, observer);
	observer->update(this); //Imp
}

void Subject::detach(Observer *observer)
{
	ChangeManager::get()->unregister_(this, observer);
}
	
void Subject::notify()
{
	ChangeManager::get()->notify_(this);
}

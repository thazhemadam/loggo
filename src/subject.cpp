#include "observer.h"
#include "subject.h"

void Subject::attach(Observer *observer)
{
	std::cout << this << "\n";
	// std::cout << &this;
	std::cout << &(*this) << "\n";

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

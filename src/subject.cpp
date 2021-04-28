#include "observer.h"
#include "subject.h"

void Subject::attach(Observer *observer)
{
	observers_.push_back(observer);
}
	
void Subject::detach(const int index)
{
	observers_.erase(observers_.begin() + index);
}
	
void Subject::notify()
{
	for (unsigned int i = 0; i < observers_.size(); i++)
		observers_.at(i)->update(this);
}

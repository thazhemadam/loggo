#include "change_manager.h"

ChangeManager* ChangeManager::instance_ = nullptr;

ChangeManager* ChangeManager::get()
{
	if (!instance_)
		instance_ = new ChangeManager();

	return instance_;
}


void ChangeManager::remove()
{
	if (instance_)
		delete instance_;

}


void ChangeManager::register_(Subject* s, Observer* o)
{
	subject_observer.insert(std::pair<Subject *, Observer*>(s, o));
	o->update(s);//updates the observer as soon as its attached
}


void ChangeManager::unregister_(Subject* s, Observer* o)
{
	std::pair<iterator, iterator> iterpair = subject_observer.equal_range(s);
	iterator it = iterpair.first;

	for (; it != iterpair.second; ++it) {
		if (it->second == o) { 
			subject_observer.erase(it);
			break;
		}
	}
}


void ChangeManager::notify_(Subject* subject)
{
	std::pair<iterator, iterator> iterpair = subject_observer.equal_range(subject);

	iterator observer = iterpair.first;
	for (; observer != iterpair.second; ++observer) {
		observer->second->update(subject);	// "observer->second" is an observer of the Subject s
	}
}

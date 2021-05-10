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


void ChangeManager::initialize_(Subject* s, void *test)
{
	lookup.insert(std::pair<void*, Subject *>(test, s));
}



void ChangeManager::register_(Subject* s, Observer* o)
{
	if(s == lookup_convert(o))	// ensure that the Subject and Observer aren't same
		return;

	subject_observer.insert(std::pair<Subject *, Observer*>(s, o));
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

// display the Lookup table and Subject-Observer Table
void ChangeManager::disp()
{
	std::cout << "================================\n";

	for(auto itr = subject_observer.begin(); itr != subject_observer.end(); ++itr) {
		std::cout << "\t" << itr->first << "\t" << itr->second << "\n";
	}

	std::cout << "================================\n";
	
	for(auto itr = lookup.begin(); itr != lookup.end(); ++itr) {
		std::cout << "\t" << itr->first << "\t" << itr->second << "\n";
	}

	std::cout << "================================\n";

}

Subject *ChangeManager::lookup_convert(void* observer)
{
	auto iterpair = lookup.equal_range(observer);
	return iterpair.first->second;
}


void ChangeManager::notify_(Subject* subject)
{
	std::pair<iterator, iterator> iterpair = subject_observer.equal_range(subject);

	iterator observer = iterpair.first;

	for (; observer != iterpair.second; ++observer) {
		observer->second->update(subject);	// "observer->second" is an observer of the Subject sa reference
		// In case Dual isn't being used, this can be used.
		// Subject *next_update = lookup_convert(observer->second);
		// notify_(next_update);
	}
}

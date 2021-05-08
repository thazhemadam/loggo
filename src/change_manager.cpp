#include "change_manager.h"
#include <algorithm>
#include <set>

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


void ChangeManager::notify_(Subject* s)
{
	std::pair<iterator, iterator> iterpair = subject_observer.equal_range(s);
	iterator it = iterpair.first;
	std::set<Subject*> v;

	for(; it != iterpair.second; ++it) {
		for (auto& it2: subject_observer)
		//for (iterator it2=subject_observer.begin();it2!=subject_observer.end();++it2)
	{
		if(it2.second==it->second)
		{
			v.insert(it2.first);
			it->second->update(it2.first);
		}
	}
	}
	//for(auto it:)
	//for (; it != iterpair.second; ++it) {
	//	it->second->update(s);
	//}
}

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

void  ChangeManager::Subscribe(ConcreteSubject* sub, ConcreteObserver obs)
{
	subs.push_back(sub);
	sub->attach(&obs);
}


void ChangeManager::Unsubscribe(ConcreteSubject* sub, ConcreteObserver obs)
{
	//subscriptions[sub].remove(obs);
}

void ChangeManager::Notify(ConcreteSubject* sub)
{
	sub->notify();
}
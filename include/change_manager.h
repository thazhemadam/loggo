#ifndef CHANGE_MANAGER_H
#define CHANGE_MANAGER_H
#include "concretes/observer.h"
#include "concretes/subject.h"
#include <iostream>
#include<vector>
using namespace std;

/*
 * ChangeManager
 * has private static variable to hold one instance_ of the class
 * and method which gives us a way to instantiate the class
 */
class ChangeManager
{
private:
	static ChangeManager *instance_;
	vector<ConcreteSubject*> subs;

protected:

public:
	ChangeManager() {}

	ChangeManager(ChangeManager const&) = delete;
	ChangeManager& operator=(ChangeManager const&) = delete;
	void Subscribe( ConcreteSubject* sub, ConcreteObserver obs);
	void Unsubscribe( ConcreteSubject* sub, ConcreteObserver obs);
	void Notify(ConcreteSubject* sub);
	static ChangeManager* get();
	static void remove();
};

#endif

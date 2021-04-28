#ifndef CHANGE_MANAGER_H
#define CHANGE_MANAGER_H

#include <iostream>

/*
 * ChangeManager
 * has private static variable to hold one instance_ of the class
 * and method which gives us a way to instantiate the class
 */
class ChangeManager
{
private:
	static ChangeManager *instance_;

protected:
	ChangeManager() {}

public:
	ChangeManager(ChangeManager const&) = delete;
	ChangeManager& operator=(ChangeManager const&) = delete;

	static ChangeManager* get();
	static void remove();
};

#endif

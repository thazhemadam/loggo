#ifndef CHANGE_MANAGER_H
#define CHANGE_MANAGER_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include "observer.h"
#include "subject.h"


typedef std::unordered_multimap<Subject *, Observer *>::iterator iterator;


/*
 * ChangeManager
 * -> is a singleton
 * -> is a mediator
 * 
 * 3 "responsibilities":
 * 		1. maps a subject to its observers. provide an interface to maintain this mapping.
 *		2. define a particular update strategy
 * 		3. update all dependent observers at the request of a subject
 */

class ChangeManager
{
private:
	static ChangeManager *instance_;
	std::unordered_multimap<void *, Subject *> lookup;
	std::unordered_multimap<Subject *, Observer *> subject_observer;

protected:
	ChangeManager() {}

public:
	static void remove();

	void initialize_(Subject* s, void *test);

	ChangeManager(ChangeManager const&) = delete;
	ChangeManager& operator=(ChangeManager const&) = delete;

	static ChangeManager* get();

	// use register_ and unregister_ since "register" is a keyword
	Subject* lookup_convert(void *o);
	void register_(Subject* s, Observer* o);
	void unregister_(Subject* s, Observer* o);
	void notify_(Subject* s);
	void disp();
};

#endif

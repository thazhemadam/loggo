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
 * 			=> NO NEED FOR SUBJECTS TO MAINTAIN REFERENCES TO OBSERVERS AND VICE-VERSE
 *		2. define a particular update strategy
 * 		3. update all dependent observers at the request of a subject
 */

class ChangeManager
{
private:
	static ChangeManager *instance_;
	std::unordered_multimap<Subject *, Observer *> subject_observer;

public:
	ChangeManager() {}
	ChangeManager(ChangeManager const&) = delete;
	ChangeManager& operator=(ChangeManager const&) = delete;

	static ChangeManager* get();
	static void remove();

	// use register_ and unregister_ since "register" is a keyword
	void register_(Subject* s, Observer* o);
	void unregister_(Subject* s, Observer* o);
	void notify_(Subject* s);
};

#endif

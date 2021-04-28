#include "change_manager.h"

ChangeManager* ChangeManager::instance = nullptr;

ChangeManager* ChangeManager::get()
{
	if (!instance)
		instance = new ChangeManager();

	return instance;
}

void ChangeManager::remove()
{
	if (instance)
		delete instance;

}

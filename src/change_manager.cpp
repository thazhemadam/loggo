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

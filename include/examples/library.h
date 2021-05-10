#ifndef LIBRARY_H
#define LIBRARY_H

#include "../concretes/dual.h"

class Library : public Dual
{
private:
    std::string name_;
    std::string version_;
public:

	Library() : Dual()  {};

	Library(const state state, std::string name = "", std::string version = "0.0.0")
	: Dual(state), name_(name), version_(version)
	{}


    void update(Subject *subject)
    {
        Library * temp = (Library *)reinterpret_cast<void*>(subject);
    
        std::cout << "\nWarning:\nThe state of dependency for "<< this->name_ << "v" << this->version_ <<" has changed. \n";
        std::cout << "\t" <<subject->get_state() << "\n";
        Dual::update(subject);
    }

    void disp() const
    {
        std::cout << "\nName:\t" << name_ << "\n";
        std::cout << "Version:\t" << version_ << "\n";
        std::cout << "State:\t" << Dual::get_state() << "\n";     
    }

};

#endif
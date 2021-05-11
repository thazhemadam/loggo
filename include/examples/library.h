#ifndef LIBRARY_H
#define LIBRARY_H

#include "../concretes/dual.h"
#include "module.h"
#include <vector>

class Module;
class Library : public Dual
{
private:
    std::string name_;
    std::string version_;
    std::vector<Module *> modules_;

public:

	Library() = default;

	Library(const state &state, std::string name = "", std::string version = "0.0.0")
	: Dual(state), name_(name), version_(version)
	{}

    void add_module(Module &module)
    {
        std::cout << "\b here!";
        modules_.push_back(&(module));
        module.module_library_ = this;
    }

    void attach(Module &module)
    {
        module.attach(this);
    }

    void update(Subject *subject)
    {
        std::cout << "\nUpdate time! \t" << this;
    
        // std::cout << "\nWarning:\nThe state of dependency for "<< this->name_ << " v" << this->version_ <<" has changed. \n";
        // std::cout << "\t" <<subject->get_state() << "\n";
        Dual::update(subject);
    }

    void disp() const
    {
        std::cout << "\nName:\t" << name_ << "\n";
        std::cout << "Version:\t" << version_ << "\n";
        std::cout << "State:\t" << Dual::get_state() << "\n";     
    }

    friend std::ostream& operator << (std::ostream & os, const Library &library)
    {
        os << "\nName:\t" << library.name_ << "\n";
        os << "Version:\t" <<  library.version_ << "\n";
        os << "State:\t" <<  library.Dual::get_state() << "\n";
        os << "\nModules: ";
        for(auto it = library.modules_.begin(); it != library.modules_.end(); ++it) {
            os << **it << "\n";
        }
        return os;
    }

};

#endif

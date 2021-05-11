#ifndef MODULE_H
#define MODULE_H

#include "../concretes/subject.h"

class Library;

class Module : public ConcreteSubject, public virtual Aspect
{
private:
    std::string name_;
    Library *module_library_;

public:

    Module() = default;

    Module(std::string name) : name_ (name) , module_library_(nullptr) {}

    ~Module() {};

    friend class Library;

    friend std::ostream& operator << (std::ostream & os, const Module &module)
    {
        os << "\n\tModule Name: " << module.name_;
        return os;
    }
};

#endif

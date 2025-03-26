#ifndef SELECTOR_H
#define SELECTOR_H

#include <array>
#include <iostream>
#include "../Manager/Manager.h"
#include "../Interfaces/ISelectable.h"
namespace Program {
    class Components {


    public:
        static Program::ISelectable* listSelector(Program::ISelectable* items, int size, std::string message);
    
    
    
    
    };
}

#endif
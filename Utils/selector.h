#ifndef SELECTOR_H
#define SELECTOR_H

#include <vector>
#include <iostream>
#include "../Interfaces/ISelectable.h"
namespace Program {
    class Components {


    public:
        static Program::ISelectable* listSelector(std::vector<Program::ISelectable*>&, int size, std::string message);
    
    
    
    
    };
}

#endif
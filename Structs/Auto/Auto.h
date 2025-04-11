#ifndef AUTO_H
#define AUTO_H
#include <array>
#include <string>
#include <vector>
#include "../../Components/Selector/selector.h" 
namespace Program {
    struct Auto : public ISelectable {
        int id;
        std::string nazwa;
        long int przebieg;
        int getID() const override;
        std::string getName() const override;
        static int countNonEmpty(std::array<Program::Auto, 16> carArray);
        static Program::Auto* carPicker(std::array<Program::Auto, 16>* carArray);
    };
}

#endif
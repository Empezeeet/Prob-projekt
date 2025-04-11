#ifndef WPIS_H
#define WPIS_H

#include <array>
#include <string>
#include <vector>
#include <ctime>
#include "../../Components/Selector/selector.h" 

namespace Program {
    struct Wpis : public ISelectable {
        int id;
        int auto_id;
        long int previousPrzebieg;
        long int przebieg;
        float cena;
        float ilosc;
        std::time_t timestamp;
        
        int getID() const override;
        std::string getName() const override;
        static int countNonEmpty(std::array<Program::Wpis, 64> logArray);
        static Program::Wpis* logPicker(std::array<Program::Wpis, 64>* logArray);
        
    };
}
#endif
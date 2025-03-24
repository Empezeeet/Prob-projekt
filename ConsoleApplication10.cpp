#include <iostream>
#include <string>
#include "Manager.h"

void addCarOpt(Program::Manager* manager) {
    Program::Auto newCar;
    std::cout << "Podaj nazwe auta: ";
    std::cin >> newCar.nazwa;
    std::cout << "Podaj przebieg w kilometrach: ";
    std::cin >> newCar.przebieg;
    newCar.id = 5;


    manager->addCar(newCar);
}
void removeCarOpt(Program::Manager* manager) {

}
void addLogOpt(Program::Manager* manager) {

}

int main()
{
    Program::Manager* manager = new Program::Manager();
    
    
    char opt;
    
    do  {
        // TODO: finish menu;
        std::cout << "[-------MENU-------]\n";
        std::cout << "[ 1 Dodaj Auto     ]\n";
        std::cout << "[ 2 Usun Auto      ]\n";
        std::cout << "[ 3 Dodaj Wpis     ]\n";
        std::cout << "[ 4 Wyswietl Auta  ]\n";
        std::cout << "[ 5 Wyswietl Wpisy ]\n";
        std::cout << "[ (Z) Cofnij       ]\n";
        std::cout << "[ (E) Exit         ]\n";
        std::cout << "[------------------]\n";
        std::cin >> opt;
        switch (opt) {
        case '1': {
            addCarOpt(manager);
            break;
        }
        case '2': {
            removeCarOpt(manager);
            break;
        }
        case '3': {
            addLogOpt(manager);
            break;
        }
        case '4': {
            manager->printCars();
            break;
        }
        case '5': {
            manager->printLogs();
            break;
        }
        case 'Z': {
            // ctrl-z
            break;
        }
        case 'E': {
            break;
        }
        }



    } while (opt != 'E');
    delete manager;
        
    return 0;
}

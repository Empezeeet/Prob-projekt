#include <iostream>
#include <string>
#include "Manager.h"
#if _WIN32
#define CLEAR system("cls")
#else
#define CLEAR system("clear")
#endif


void addCarOpt(Program::Manager* manager) {
    CLEAR;
    Program::Auto newCar;
    std::cout << "Podaj nazwe auta: ";
    std::cin.ignore(1000, '\n');
    std::cin >> newCar.nazwa; // TODO: it's not working with spaces;
    std::cout << "Podaj przebieg w kilometrach: ";
    std::cin >> newCar.przebieg;
    newCar.id = 0;


    manager->addCar(newCar);
}
void removeCarOpt(Program::Manager* manager) {
    CLEAR;
}
void addLogOpt(Program::Manager* manager) {
    CLEAR;
}
void loadOpt(Program::Manager* manager) {
    CLEAR;
    std::cout << "Czy na pewno chcesz wczytac? (Y/N)\n";
    char c;
    std::cin >> c;
    if (c == 'Y') {
        manager->load();
    }
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
        std::cout << "[ 6 Wczytaj        ]\n";
        std::cout << "[ 7 Zapisz         ]\n";
        std::cout << "[ 8 Autosave       ]\n";
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
            CLEAR;
            manager->printCars();
            break;
        }
        case '5': {
            CLEAR;
            manager->printLogs();
            break;
        }
        case '6': {
            // load
            loadOpt(manager);
            break;
        }
        case '7': {
            CLEAR;
            // save;
            break;
        }
        case '8': {
            CLEAR;
            // toggle autosave;
            manager->toggleAutosave();
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

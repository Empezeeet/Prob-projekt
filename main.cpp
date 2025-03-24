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
    std::getline(std::cin, newCar.nazwa);
    std::cout << "Podaj przebieg w kilometrach: ";
    do {
        std::cin >> newCar.przebieg;
    } while (newCar.przebieg < 0);
    newCar.id = 0;


    manager->addCar(newCar);
}
void removeCarOpt(Program::Manager* manager) {
    CLEAR; // TODO: finish
}
void addLogOpt(Program::Manager* manager) {
    CLEAR; // TODO: finish
}
void loadOpt(Program::Manager* manager) {
    CLEAR;
    std::cout << "Czy na pewno chcesz wczytac zapis? Nadpisze on obecne dane. (Y/N)\n";
    char c;
    std::cin >> c;
    if (c == 'Y') {
        manager->load();
    }
}
void saveOpt(Program::Manager* manager) {
    CLEAR;
    manager->save();
    std::cout << "Zapisano dane.\n";
}
void exitOpt(char* opt) {
    CLEAR;
    std::cout << "Czy na pewno chcesz wyjsc? (Y/N)\n";
    char c;
    std::cin >> c;
    if (c == 'Y') {
        *opt = 'E';
    } else {
        *opt = 'A';
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
        case '1': { // add car
            addCarOpt(manager);
            break;
        }
        case '2': { // remove car
            removeCarOpt(manager);
            break;
        }
        case '3': { // add new log to car;
            addLogOpt(manager);
            break;
        }
        case '4': { // print all cars
            CLEAR;
            manager->printCars();
            break;
        }
        case '5': { // print all fuel logs
            CLEAR;
            manager->printLogs();
            break;
        }
        case '6': { // load
            loadOpt(manager);
            break;
        }
        case '7': { // save
            saveOpt(manager);
            break;
        }
        case '8': { // toggle autosave;
            CLEAR;
            manager->toggleAutosave();
        }
        case 'Z': { // revert last change.
            break;
        }
        case 'E': { // exit
            exitOpt(&opt);
            break;
        }
        }



    } while (opt != 'E');
    delete manager;
        
    return 0;
}

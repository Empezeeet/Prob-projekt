#include "AppManager.h"
#if _WIN32
#define CLEAR system("cls")
#else
#define CLEAR system("clear")
#endif
Program::AppManager::AppManager() {
    this->manager = new Program::Manager();
}
Program::AppManager::~AppManager() {
    delete this->manager;
}

void Program::AppManager::displayMenu() {
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
}
void Program::AppManager::addCarOption() {
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

    this->manager->addCar(newCar);
}
void Program::AppManager::removeCarOption() {
    // TODO: finish
}
void Program::AppManager::addLogOption() {
    // TODO: finish
}
void Program::AppManager::loadOption() {
    CLEAR;
    std::cout << "Czy na pewno chcesz wczytac zapis? Nadpisze on obecne dane. (Y/N)\n";
    char c;
    std::cin >> c;
    if (c == 'Y') {
        this->manager->load();
    }
}
void Program::AppManager::saveOption() {
    CLEAR;
    manager->save();
    std::cout << "Zapisano dane.\n";
}
void Program::AppManager::exitOption(char* opt) {
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
void Program::AppManager::toggleAutosave() {
    CLEAR;
    this->manager->toggleAutosave();
}
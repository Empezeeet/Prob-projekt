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
    std::cout << "[ 9 Statystyki     ]\n";
    std::cout << "[ (Z) Cofnij       ]\n";
    std::cout << "[ (E) Exit         ]\n";
    std::cout << "[------------------]\n";
}
void Program::AppManager::showAllStats() {

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
    CLEAR;
    Program::Auto* selectedCar = Program::Components::listSelector(this->manager->getAllCars());
    std::cout << "Czy na pewno chcesz usunac: " << selectedCar->nazwa << "? (Y/N)";
    char c;
    std::cin >> c;
    if (c == 'Y') {
        int res = this->manager->removeCar(selectedCar->id);
        CLEAR;
        std::cout << (res == -1 ? "Blad.\n" : "OK\n");
        return;
    } else {
        CLEAR;
        std::cout << "Anulowano usuwanie auta.";
        return;
    }


}
void Program::AppManager::addLogOption() {
    CLEAR;
    Program::Wpis newLog;
    newLog.id = 0;
    Program::Auto* pickedCar = Program::Components::listSelector(this->manager->getAllCars());
    if (pickedCar == nullptr) {
        std::cout << "HWDPJP100%\n";
    } else {
        CLEAR;
    }
    
    std::cout << "Wybrano auto: " << pickedCar->nazwa << "\n";
    newLog.auto_id = pickedCar->id;
    // przebieg
    do {
        std::cout << "Podaj aktualny przebieg w kilometrach: ";
        std::cin >> newLog.przebieg;
    } while (newLog.przebieg < pickedCar->przebieg);
   
    // ilosc
    do {
        std::cout << "Podaj ilosc paliwa: ";
        std::cin >> newLog.ilosc;
    } while (newLog.ilosc < 0);
    // cena
    do {
        std::cout << "Podaj cene tankowania: ";
        std::cin >> newLog.cena;
    } while (newLog.cena < 0);
    newLog.timestamp = std::time(NULL);
    // TODO: test.
    this->manager->addLog(newLog);
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
void Program::AppManager::showAllLogs() {
    CLEAR;
    this->manager->printLogs();
}
void Program::AppManager::showAllCars() {
    CLEAR;
    this->manager->printCars();
}
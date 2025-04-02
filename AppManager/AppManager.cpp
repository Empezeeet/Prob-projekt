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
    std::cout << "[ (E) Edytuj wpis  ]\n";
    std::cout << "[ (Z) Cofnij       ]\n";
    std::cout << "[ (X) Exit         ]\n";
    std::cout << "[------------------]\n";
}
void Program::AppManager::showAllStats() {

}
void Program::AppManager::editLog() {
    CLEAR;
    Program::Wpis* pickedLog = Program::Wpis::logPicker(this->manager->getAllLogs());
    if (pickedLog == nullptr || !pickedLog) {
        CLEAR;
        std::cout << "Nie znaleziono wpisu! Kod błędu: EL-1";
        return;
    }
    CLEAR;
    char opt;
    std::cout << "[ (P) Przebieg]\n";
    std::cout << "[ (C) Cena    ]\n";
    std::cout << "[ (I) Ilosc   ]\n";
    do {
        std::cout << "Co chcesz edytowac? ";
        std::cin >> opt;
    } while (opt != 'P' && opt != 'C' && opt != 'I');

    switch (opt) {
        case 'P': {
            std::cout << "Podaj nowy przebieg: ";
            long int newPrzebieg;
            std::cin >> newPrzebieg;
            pickedLog->przebieg = newPrzebieg;
            break;
        }
        case 'C': {
            std::cout << "Podaj nową cenę: ";
            float newCena;
            std::cin >> newCena;
            pickedLog->cena = newCena;
            break;
        }
        case 'I': {
            std::cout << "Podaj nową ilość: ";
            float newIlosc;
            std::cin >> newIlosc;
            pickedLog->ilosc = newIlosc;
            break;
        }
    }
    this->manager->save();
}
void Program::AppManager::showStatsOption() {
    CLEAR;
    // fixed segfault???
    Program::Auto* pickedCar = Program::Auto::carPicker(this->manager->getAllCars());

 
    if (pickedCar == nullptr || !pickedCar) {
        // error;
        CLEAR;
        std::cout << "Brak aut do obliczania statystyk.\nKod błędu: SSO-1\n";
        return;
    }
    CLEAR;
    std::cout << "Wybrano auto: " << pickedCar->getName() << '\n';
    Program::LogArray* logs = this->manager->getAllLogs();
    std::cout << "Ogolne wydatki: " << StatsCalculator::calculateAllTimeExpenses(logs) <<'\n';
    //std::cout << "Miesieczne wydatki: " << StatsCalculator::calculateMonthlyExpenses(logs) << '\n'; 
    std::cout << "Spalanie: " << StatsCalculator::fuelUsage(logs, pickedCar) << "L/100km\n";

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

    int res = this->manager->addCar(newCar);
    if (res == -2 ) {
        CLEAR;
        std::cout << "Brak wolnych miejsc na auto!\n";
        return; 
    }
}
void Program::AppManager::removeCarOption() {
    CLEAR;

     // fixed segfault???
     Program::Auto* pickedCar = Program::Auto::carPicker(this->manager->getAllCars());

 
    if (pickedCar == nullptr || !pickedCar) {
        CLEAR;
        std::cout << "Nie znaleziono auta! Kod błędu: RCO-1";
        return;
    } 
    std::cout << "Czy na pewno chcesz usunac: " << pickedCar->getName() << "? (Y/N)";
    char c;
    std::cin >> c;
    if (c == 'Y') {
        int res = this->manager->removeCar(pickedCar->getID());
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
    // fixed segfault???
    Program::Auto* pickedCar = Program::Auto::carPicker(this->manager->getAllCars());

    if (pickedCar == nullptr || !pickedCar) {
        CLEAR;
        std::cout << "Nie znaleziono auta! Kod błędu: ALO-1\n";
        return;
    } 
    CLEAR;
    
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
        *opt = 'X';
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
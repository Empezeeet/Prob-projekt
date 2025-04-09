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
    std::cout << "[ (S) Szukaj       ]\n";
    std::cout << "[ (V) Sortuj wpisy ]\n";
    std::cout << "[ (U) Usuń wpis    ]\n";
    std::cout << "[ (E) Edytuj wpis  ]\n";
    std::cout << "[ (Z) Cofnij       ]\n";
    std::cout << "[ (X) Exit         ]\n";
    std::cout << "[------------------]\n";
}

void Program::AppManager::showAllStats() {

}
void Program::AppManager::preSave() {
    this->manager->save("saves/preCars.txt", "saves/preLogs.txt");
}
void Program::AppManager::preLoad() {
    CLEAR;
    std::cout << "Cofnieto zmiane!\n";
    this->manager->load("saves/preCars.txt", "saves/preLogs.txt");
}

void Program::AppManager::removeLogOption() {
    CLEAR;
    Program::Wpis* pickedLog = Program::Wpis::logPicker(this->manager->getAllLogs());
    if (pickedLog == nullptr || !pickedLog) {
        CLEAR;
        std::cout << "Nie znaleziono wpisu! Kod błędu: RLO-1\n";
        return;
    }
    CLEAR;
    char opt;
    std::cout << "Czy na pewno chcesz usunac wpis z dnia " << std::ctime(&pickedLog->timestamp) << "? (Y/N)";
    std::cin >> opt;
    if (opt != 'Y') {
        std::cout << "Anulowanie.\n";
        return;
    }
    this->manager->removeLog(pickedLog->id);
}
void Program::AppManager::editLog() {
    CLEAR;
    Program::Wpis* pickedLog = Program::Wpis::logPicker(this->manager->getAllLogs());
    if (pickedLog == nullptr || !pickedLog) {
        CLEAR;
        std::cout << "Nie znaleziono wpisu! Kod błędu: EL-1\n";
        return;
    }
    CLEAR;
    char opt;
    std::cout << "[=== OPCJE ===]\n";
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
            this->manager->findCar(pickedLog->auto_id)->przebieg = newPrzebieg;
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
    this->manager->autoSave();
}
void Program::AppManager::showStatsOption() {
    CLEAR;
    Program::Auto* pickedCar = Program::Auto::carPicker(this->manager->getAllCars());

 
    if (pickedCar == nullptr || !pickedCar) {
        // error;
        CLEAR;
        std::cout << "Brak aut do obliczania statystyk.\nKod błędu: SSO-1\n";
        return;
    }
    CLEAR;
    std::cout << "Wybrano auto: " << pickedCar->getName() << '\n';
    Program::LogArray logs = this->manager->getAllLogsCopy();
    std::cout << "Ogolne wydatki: " << StatsCalculator::calculateAllTimeExpenses(&logs) <<'\n';
    std::cout << "Miesieczne wydatki: " << StatsCalculator::calculateMonthlyExpenses(logs) << '\n'; 
    std::cout << "Spalanie: " << StatsCalculator::fuelUsage(&logs, pickedCar) << "L/100km\n";
    std::cout << "Średnia cena paliwa: " << StatsCalculator::averageFuelPrice(&logs) << "/Litr\n";
    std::cout << "Koszt na kilometr: " << StatsCalculator::pricePerKilometer(&logs) << "\n";
}
void Program::AppManager::selectSortingOption() {
    // TODO: sorting    
    CLEAR;
    std::cout << "[ ---- SORTOWANIE --- ]\n";
    std::cout << "[ 1. Po cenie         ]\n";
    std::cout << "[ 2. Po dacie         ]\n";
    std::cout << "[ 3. Po ilości        ]\n";
    int opt;
    do {
        std::cout << "Wybierz: ";
        std::cin >> opt;
    } while (opt < 1 || opt > 3);
    Program::LogArray logs = this->manager->getAllLogsCopy();
    CLEAR;
    // rosnąco.
    switch (opt) {
        case 1: {// cena
            for (int i=0; i<63; i++) {
                for (int j=0; j<63-i; j++) {
                    if (logs.at(j).id == 0 || logs.at(j+1).id == 0) continue; 
                    if (logs.at(j).cena > logs.at(j+1).cena) {
                        std::swap(logs.at(j), logs.at(j+1));
                    }
                }
            }
            break;
        } 
        case 2: {// data
            for (int i=0; i<63; i++) {
                for (int j=0; j<63-i; j++) {
                    if (logs.at(j).id == 0 || logs.at(j+1).id == 0) continue; 
                    if (logs.at(j).timestamp > logs.at(j+1).timestamp) {
                        std::swap(logs.at(j), logs.at(j+1));
                    }
                }
            }
            break;
        }
        case 3: {// ilość
            for (int i=0; i<63; i++) {
                for (int j=0; j<63-i; j++) {
                    if (logs.at(j).id == 0 || logs.at(j+1).id == 0) continue; 
                    if (logs.at(j).ilosc > logs.at(j+1).ilosc) {
                        std::swap(logs.at(j), logs.at(j+1));
                    }
                }
            }
            break;
        }
    }
    // TODO: display all logs.
    std::cout << "|-------------\n";

    for (Program::Wpis log : logs) {
        if (log.id == 0) continue;
        std::cout << "[ DATA WPISU: " << std::ctime(&log.timestamp) << ""; // FIXME: time is off by 3h
        std::cout << "[ NAZWA AUTA: " << this->manager->findCar(log.auto_id)->nazwa << "\n";
        std::cout << "[ Ilosc: " << log.ilosc << "\n";
        std::cout << "[ Cena: " << log.cena << "\n";
        std::cout << "[ PRZEBIEG: " << log.przebieg << "\n";
        std::cout << "|-------------\n";
    }

    
}
void Program::AppManager::search() {
    CLEAR;
    std::cout << "[ ---- WYSZUKIWANIE ---- ]\n";
    std::cout << "[ 1. Auta po nazwie      ]\n";
    std::cout << "[ 2. Wpisu po dacie      ]\n";
    std::cout << "[ 3. Wróć                ]\n";

    int opt;
    do {
        std::cout << "Wybierz: ";
        std::cin >> opt;
    } while (opt < 1 || opt > 3);
    std::string carName;
    struct tm datetime;
    std::time_t timestamp;
    switch (opt) {
        case 1: {
            std::cout << "Podaj nazwę auta: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, carName);
            Program::Auto* car = this->manager->findCar(carName);
            if (car == nullptr) {
                std::cout << "Nie znaleziono auta!\n";
                return;
            }
            std::cout << "[ AUTO: " << car->nazwa << "\n";
            std::cout << "[ PRZEBIEG: " << car->przebieg << "km\n";
            std::cout << "[ ID: " << car->id << "\t\n";
            std::cout << "[ ------------------]\n";
            break;
        }
        case 2: {
            std::cout << "Podaj rok: "; 
                std::cin >> datetime.tm_year;
            std::cout << "Podaj miesiac: "; 
                std::cin >> datetime.tm_mon;
            std::cout << "Podaj dzien: "; 
                std::cin >> datetime.tm_mday;
            // set hour minute and second to 0
            datetime.tm_hour = 0; datetime.tm_min = 0; datetime.tm_sec = 0;
            // 
            datetime.tm_year -= 1900;
            datetime.tm_mon -= 1;
            datetime.tm_isdst = -1;
            timestamp = std::mktime(&datetime);
            CLEAR;
            Program::Wpis* log = this->manager->findLog(timestamp);
            if (log == nullptr) {
                std::cout << "Brak takiego wpisu!\n";
                return;
            }
            std::cout << "|-------------\n";
            std::cout << "[ DATA WPISU: " << std::ctime(&log->timestamp) << "";
            std::cout << "[ NAZWA AUTA: " << this->manager->findCar(log->auto_id)->nazwa << "\n"; // FIXME: time is off by 3h
            std::cout << "[ Ilosc: " << log->ilosc << "\n";
            std::cout << "[ Cena: " << log->cena << "\n";
            std::cout << "[ PRZEBIEG: " << log->przebieg << "\n";
            std::cout << "|-------------\n";


            break;
        }
    }

    
}
void Program::AppManager::addCarOption() {
    CLEAR;
    Program::Auto newCar;
    std::cout << "Podaj nazwe auta: ";
    std::cin.ignore(1000, '\n');
    std::getline(std::cin, newCar.nazwa);
    do {
        std::cout << "Podaj przebieg w kilometrach: ";
        std::cin >> newCar.przebieg;
    } while (newCar.przebieg < 0);
    newCar.id = 0;

    int res = this->manager->addCar(newCar);
    if (res == -2) {
        CLEAR;
        std::cout << "Brak wolnych miejsc na auto!\n";
        return; 
    }
}
void Program::AppManager::removeCarOption() {
    CLEAR;

     // fixed segfault
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
    Program::Auto* pickedCar = Program::Auto::carPicker(this->manager->getAllCars());

    if (pickedCar == nullptr || !pickedCar) {
        CLEAR;
        std::cout << "Nie znaleziono auta! Kod błędu: ALO-1\n";
        return;
    } 
    CLEAR;
    
    std::cout << "Wybrano auto: " << pickedCar->nazwa << "\n";
    newLog.auto_id = pickedCar->id;
    std::cout << "Ostatni przebieg: " << pickedCar->przebieg << "\n";
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
    } else {
        std::cout << "Nie wczytano danych.\n";
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
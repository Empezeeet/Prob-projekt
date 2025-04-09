
#include "Manager.h"

#define PRECHANGE_CAR_FILE "saves/preChangeCar.txt"
#define PRECHANGE_LOG_FILE "saves/preChangeLog.txt"




void Program::Manager::autoSave() {
	if (!this->_autosave) return;
    this->save();
}
Program::Manager::Manager(std::string filePath, std::string logsPath) {
	this->carsFile = filePath;
    this->logsFile = logsPath;
    std::srand(time(nullptr));

}
Program::Manager::~Manager()
{
}
Program::CarArray Program::Manager::getAllCarsCopy() {
    return this->_cars;
}
int Program::Manager::generateID(Program::Auto* car) {
    do {
        car->id = car->przebieg + ((std::rand()%9999)+1000);
    } while (this->findCar(car->id) != nullptr);
    
    return 0;
}
int Program::Manager::generateID(Program::Wpis* log) {
    do {
        log->id = log->przebieg + ((std::rand()%9999)+1000);
    } while (this->findLog(log->id) != nullptr);
    
    return 0;
}
int Program::Manager::addCar(Program::Auto car) {
    if (car.id != 0) return -1; // id is auto-generated;
    // auto-gen car.id;
    this->generateID(&car);
    
    if (++this->_carCount >= 16) {
        --this->_carCount;
        return -2; // no space left
    }
    // add to array;
    this->_cars[this->_carCount] = car;

    this->defragmentation();
    this->autoSave();
    return car.id;
}
int Program::Manager::removeCar(int carID)
{
    for (Auto& car : this->_cars) {
        if (car.id == carID) {
            // delete this car
            car = {};
            this->defragmentation();
            this->autoSave();
            return 0;
        }
    }
    return -1; // id not found;
}
int Program::Manager::removeCar(std::string name)
{
    for (Auto& car : this->_cars) {
        if (car.nazwa == name) {
            // delete this car
            car = {};
            this->defragmentation();
            this->autoSave();
            return 0;
        }
    }
    return -1; // id not found;

}
int Program::Manager::addLog(Wpis log)
{
    if (log.id != 0) return -1;
    this->generateID(&log);
    if (this->_logCount == 0) log.previousPrzebieg = 0;

    this->_logs[this->_logCount++] = log;
    log.previousPrzebieg = this->findCar(log.auto_id)->przebieg;
    this->findCar(log.auto_id)->przebieg = log.przebieg;
    this->defragmentation();
    this->autoSave();
    return 0;
}
int Program::Manager::removeLog(int logID) {
    Program::Wpis* log = this->findLog(logID);
    this->findCar(log->auto_id)->przebieg = log->previousPrzebieg;
    *log = {};
    this->defragmentation();
    this->autoSave();
    return 0;
}
void Program::Manager::toggleAutosave() {
    this->_autosave = !this->_autosave;
    std::cout << "Autosave: " << (this->_autosave == true ? "ON" : "OFF") << "\n";
}
void Program::Manager::printCars()
{
    if (this->_carCount == 0) {
        std::cout << "Brak aut w bazie\n";
        return;
    }
    std::cout << "[ ------------------]\n";
    for (const Program::Auto& car : this->_cars) {
        if (car.id == 0) {
            continue;
        }
        std::cout << "[ AUTO: " << car.nazwa << "\n";
        std::cout << "[ PRZEBIEG: " << car.przebieg << "km\n";
        std::cout << "[ ID: " << car.id << "\t\n";
        std::cout << "[ ------------------]\n";
    }
}
Program::Wpis* Program::Manager::findLog(std::time_t timestamp) {
    struct tm* datetime;
    for (Program::Wpis log : this->_logs) {
        datetime = std::localtime(&log.timestamp);
        if (datetime == nullptr) continue;
        datetime->tm_hour = 0;
        datetime->tm_min = 0;
        datetime->tm_sec = 0;
        if (mktime(datetime) == timestamp) {
            return this->findLog(log.id);
        }

    }
    return nullptr;
}
void Program::Manager::printLogs()
{
    
    if (this->_logCount == 0) {
        std::cout << "Brak wpisów!\n";
        return;
    }
    std::cout << "|-------------\n";
    for (const Program::Wpis& log : this->_logs) {
        if (log.id == 0 ) continue;
        std::cout << "[ DATA WPISU: " << std::ctime(&log.timestamp) << ""; // FIXME: time is off by 3h
        std::cout << "[ NAZWA AUTA: " << this->findCar(log.auto_id)->nazwa << "\n";
        std::cout << "[ Ilosc: " << log.ilosc << "\n";
        std::cout << "[ Cena: " << log.cena << "\n";
        std::cout << "[ PRZEBIEG: " << log.przebieg << "\n";
        std::cout << "|-------------\n";
    }
}
void Program::Manager::defragmentation() {
    CarArray defragmentedCars = {};
    int count = 0;
    for (int i=0; i<15; i++) {
        if (this->_cars[i].nazwa == "") continue;
        defragmentedCars[count] = this->_cars[i];
        count++;
    }
    this->_cars = defragmentedCars;
    count = 0;
    Program::LogArray defragmentedLogs = {};
    for (int i=0; i<64; i++) {
        if (this->_logs[i].id == 0) continue;
        defragmentedLogs[count] = this->_logs[i];
        count++;
    }
}
Program::Wpis* Program::Manager::findLog(int logID) {
    for (int i=0; i<64; i++) {
        if (this->_logs.at(i).id != logID) continue;
        return &this->_logs.at(i);
    }
    return nullptr;
}



Program::Auto* Program::Manager::findCar(int carID)
{
    for (int i = 0; i < 16; i++) {
        if (this->_cars[i].id != carID) continue;
        return &this->_cars[i];
    }
    return nullptr;
}
Program::Auto* Program::Manager::findCar(std::string name)
{
    for (int i = 0; i < 16; i++) {
        if (this->_cars[i].nazwa != name) continue;
        return &this->_cars[i];
    }    
    return nullptr;
}
Program::LogArray* Program::Manager::getAllLogs() {
    return &this->_logs;
}
Program::LogArray Program::Manager::getAllLogsCopy() {
    return this->_logs;
}

void Program::Manager::test() {
   
}
Program::CarArray* Program::Manager::getAllCars() {
    return &this->_cars;
}
int Program::Manager::save(std::string pathCar, std::string pathLog) {
    this->defragmentation();
    // car
    std::ofstream file(pathCar);
    if (!file) {
        std::cout << "Nie można zapisać do pliku aut!. Kod błędu SAV-1\n";
        return -1;
    }

    for (const Auto& car : this->_cars) {
        file << car.id << " " << replaceString(car.nazwa, ' ', '_') << " " << car.przebieg << '\n';
    }
    file.close();
    // log
    std::ofstream file2(pathLog);
    if (!file2) {
        std::cout << "Nie można zapisać do pliku wpisów!. Kod błędu: SAV-2\n";
        return -2;
    }
    for (const Wpis& log : this->_logs) {
     
        file2 << log.id 
            << " " << log.auto_id 
            << " " << log.cena 
            << " " << log.ilosc 
            << " " << log.przebieg 
            << " " << (long long)log.timestamp 
            << " " << log.previousPrzebieg << "\n";
    }
    file2.close();
    return 0;
}
int Program::Manager::load(std::string pathCar, std::string pathLog)
{
    // car
    std::ifstream file(pathCar);
    if (!file) {
        std::cout << "Nie można otworzyć pliku aut!. Kod błędu: PML-1\n";
        return -1;
    }
    this->_cars.fill({});
    Program::Auto car;
    int count = 0;
    while (file >> car.id) {
        file >> car.nazwa;
        file >> car.przebieg;
        car.nazwa = replaceString(car.nazwa, '_', ' ');
        this->_cars[count] = car;
        count++;
    }
    this->_carCount = count;
    file.close();
    // load logs from file
    std::ifstream logFile(pathLog);
    if (!logFile) {
        std::cout << "Nie można otowrzyć pliku wpisów! Kod błędu: PML-2\n";
        return -2;
    }
    this->_logs.fill({});
    Program::Wpis log;
    count = 0;
    while (!logFile.eof()) {
        logFile >> log.id;
        logFile >> log.auto_id;
        logFile >> log.cena;
        logFile >> log.ilosc;
        logFile >> log.przebieg;
        logFile >> log.timestamp;
        logFile >> log.previousPrzebieg;
        this->_logs[count] = log;
        count++;
    } 
    this->_logCount = count;
    return 0;
}
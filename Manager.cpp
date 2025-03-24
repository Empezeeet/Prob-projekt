
#include "Manager.h"

void Program::Manager::autoSave() {
	if (!this->_autosave) return;
    this->save();
}
Program::Manager::Manager(std::string filePath, std::string logsPath) {
	this->carsFile = filePath;
    this->logsFile = logsPath;

}
Program::Manager::~Manager()
{
}
int Program::Manager::addCar(Program::Auto car) {
    if (car.id != 0) return -1; // id is auto-generated;
    // auto-gen car.id;
    int id = car.przebieg + this->_carCount + 1;
    // TODO: check is id valid;
    car.id = id;

    // add to array;
    this->_cars[this->_carCount] = car;
    this->_carCount++;

    this->defragmentation();
    this->autoSave();
    return id;
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
    // TODO: add log
    return 0;
}
int Program::Manager::removeLog(int logID)
{
    // TODO: remove log
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
    std::cout << "|-------------\n";
    for (const auto& car : this->_cars) {
        if (car.id == 0) {
            continue;
        }
        std::cout << "| AUTO: " << car.nazwa << "\t\n";
        std::cout << "| PRZEBIEG: " << car.przebieg << "km\t\n";
        std::cout << "| ID: " << car.id << "\t\n";
        std::cout << "|-------------\n";
    }
}
void Program::Manager::printLogs()
{
    std::cout << "|-------------\n";
    for (const auto& log : this->_logs) {
        std::cout << "[ DATA WPISU: " << log.timestamp << "\t\n";
        std::cout << "[ NAZWA AUTA: " << this->findCar(log.auto_id)->nazwa << "\t\n";
        std::cout << "[ Ilosc: " << log.ilosc << "\t\n";
        std::cout << "[ Cena: " << log.cena << "\t\n";
        std::cout << "[ PRZEBIEG: " << log.przebieg << "\t\n";
        std::cout << "|-------------\n";
    }
}
void Program::Manager::defragmentation() {
    std::array<Program::Auto, 16> defragmentedCars = {};
    int count = 0;
    for (int i=0; i<15; i++) {
        if (this->_cars[i].nazwa == "") continue;
        defragmentedCars[count] = this->_cars[i];
        count++;
    }
    this->_cars = defragmentedCars;
    count = 0;
    std::array<Program::Wpis, 64> defragmentedLogs = {};
    for (int i=0; i<64; i++) {
        if (this->_logs[i].id == 0) continue;
        defragmentedLogs[count] = this->_logs[i];
        count++;
    }
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
void Program::Manager::test() {
    for (auto i : this->_cars) {
        std::cout << "ID: " << i.id << "\n";
    }
	this->defragmentation();
    for (auto i : this->_cars) {
        std::cout << "ID: " << i.id << "\n";
    }
}
int Program::Manager::save() {
    this->defragmentation();
    std::ofstream file(this->carsFile);
    if (!file) return -1;
    for (const Auto& car : this->_cars) {
        file << car.id << " " << car.nazwa << " " << car.przebieg << '\n';
    }
    file.close();
    std::ofstream file2(this->logsFile);
    if (!file2) return -2;
    for (const Wpis& log : this->_logs) {
        file2 << log.auto_id << " " << log.cena << " " << log.ilosc << " " << log.przebieg << "\n";
    }
    file2.close();
    return 0;
}

int Program::Manager::load()
{
    //TODO: load from file
    std::ifstream file(this->carsFile);
    if (!file) return -1;
    Program::Auto car;
    while (file >> car.id) {
        file >> car.nazwa;
        file >> car.przebieg;
        
        
    }
    return 0;
}

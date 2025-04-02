#ifndef MANAGER_H
#define MANAGER_H

#if _WIN32
#define carSaveFilePath "C:\\cars.txt"
#define logSaveFilePath "C:\\logs.txt"
#else
#define carSaveFilePath "saves/carsSave.txt"
#define logSaveFilePath "saves/logsSave.txt"
#endif



#include <string>
#include <array>
#include <algorithm>
#include <vector>
#include <fstream>
#include <iostream>
#include <typeinfo>
#include <ctime>
#include "../Utils/replace.h"
#include "../Interfaces/ISelectable.h"
#include "../Utils/selector.h"



namespace Program {
    
    struct Auto : public ISelectable {
        int id;
        std::string nazwa;
        long int przebieg;
        int getID() const override {
            return this->id;
        }
        std::string getName() const override {
            return this->nazwa;
        }
        static int countNonEmpty(std::array<Program::Auto, 16> carArray) {
            int count=0;
            for (Program::Auto& car : carArray) {
                if (car.id!=0) count++;
            }
            return count;
        }
        static Program::Auto* carPicker(std::array<Program::Auto, 16>* carArray) {
            std::vector<Program::ISelectable*> carVector;
            for (int i=0; i<16; i++) {
                Program::Auto* car = &carArray->at(i);
                if (car->getID() == 0 || car == nullptr) continue;
                carVector.push_back(car);
            }
            return (Program::Auto*)Components::listSelector(carVector, carVector.size(), "Wybierz auto z listy: ");
        }
    };
    struct Wpis : public ISelectable {
        int id;
        int auto_id;
        long int przebieg;
        float cena;
        float ilosc;
        std::time_t timestamp;
        
        int getID() const override {
            return this->id;
        }
        std::string getName() const override {
            return "Wpis " + std::to_string(this->timestamp);
        }
        static int countNonEmpty(std::array<Program::Wpis, 64> logArray) {
            int count=0;
            for (Program::Wpis& log : logArray) {
                if (log.id!=0) count++;
            }
            return count;
        }
        static Program::Wpis* logPicker(std::array<Program::Wpis, 64>* logArray) {
            std::vector<Program::ISelectable*> logVector;
            for (int i=0; i<16; i++) {
                Program::Wpis* log = &logArray->at(i);
                if (log->getID() == 0 || log == nullptr) continue;
                logVector.push_back(log);
            }
            return (Program::Wpis*)Components::listSelector(logVector, logVector.size(), "Wybierz wpis z listy: ");
        }
        
    };
    
    typedef std::array<Program::Wpis, 64> LogArray;
    typedef std::array<Program::Auto, 16> CarArray;
    class Manager
    {
    private:
        
        CarArray _cars = {};
        int _carCount = 0;
        
        LogArray _logs = {};
        int _logCount = 0;
        bool _autosave = true;
        std::string carsFile = carSaveFilePath;
        std::string logsFile = logSaveFilePath;





        void autoSave();
        
        void defragmentation();
        Auto* findCar(int carID);
        Auto* findCar(std::string name);




    public:
        Manager(std::string filePath = carSaveFilePath, std::string logsPath = logSaveFilePath);
        ~Manager();
        int addCar(Auto car);
        int removeCar(int carID);
        int removeCar(std::string name);
        int addLog(Wpis log);
        int removeLog(int logID);
        void printCars();
        void printLogs();
        int save();
        int load();
        void test();
        void calculateStats();
        void toggleAutosave();
        Program::CarArray* getAllCars();
        Program::CarArray getAllCarsCopy();
        Program::LogArray* getAllLogs();
    };
}
#endif

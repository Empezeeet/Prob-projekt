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
#include <fstream>
#include <iostream>
#include <typeinfo>
#include <ctime>
#include "../Utils/replace.h"




namespace Program {
    struct Auto {
        int id;
        std::string nazwa;
        long int przebieg;
    };
    struct Wpis {
        int id;
        int auto_id;
        long int przebieg;
        float cena;
        float ilosc;
        std::time_t timestamp;
    };
    struct Stats {
        int car_id;
        std::string name;
        float value; 
        char unit[6];
    };
    class Manager
    {
    private:
        
        std::array<Auto, 16> _cars = {};
        int _carCount = 0;
        
        std::array<Wpis, 64> _logs = {};
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
        std::array<Program::Auto, 16>* getAllCars();
    };
}
#endif

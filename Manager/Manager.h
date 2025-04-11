#ifndef MANAGER_H
#define MANAGER_H

#if _WIN32
#define carSaveFilePath "C:\\cars.txt"
#define logSaveFilePath "C:\\logs.txt"
#define carPreSaveFilePath "C:\\carsPre.txt"
#define logPreSaveFilePath "C:\\logsPre.txt"
#else
#define carSaveFilePath "saves/carsSave.txt"
#define logSaveFilePath "saves/logsSave.txt"
#define carPreSaveFilePath "saves/carsPre.txt"
#define logPreSaveFilePath "saves/logsPre.txt"
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
#include "../Structs/Auto/Auto.h"
#include "../Structs/Wpis/Wpis.h"
#include "../Utils/time.h"


namespace Program {
    
    
    
    
    typedef std::array<Program::Wpis, 64> LogArray;
    typedef std::array<Program::Auto, 16> CarArray;


    class Manager
    {
    private:
        
        CarArray _cars = {};
        LogArray _logs = {};
        int _carCount = 0;
        int _logCount = 0;

        bool _autosave = true;

        std::string carsFile = carSaveFilePath;
        std::string logsFile = logSaveFilePath;

        void defragmentation();

    public:
        Manager(std::string filePath = carSaveFilePath, std::string logsPath = logSaveFilePath);
        ~Manager();
        void autoSave();
        Program::Auto* findCar(int carID);
        Program::Auto* findCar(std::string name);
        Program::Wpis* findLog(int logID);
        Program::Wpis* findLog(std::time_t timestamp);
        int addCar(Auto car);
        int removeCar(int carID);
        int removeCar(std::string name);
        int addLog(Wpis log);
        int removeLog(int logID);
        void printCars();
        void printLogs();
        int save(std::string pathCar = carSaveFilePath, std::string pathLog = logSaveFilePath);
        int load(std::string pathCar = carSaveFilePath, std::string pathLog = logSaveFilePath);
        int generateID(Program::Auto* car);
        int generateID(Program::Wpis* log);
        

        void test();
        void calculateStats();
        void toggleAutosave();
        Program::CarArray* getAllCars();
        Program::CarArray getAllCarsCopy();
        Program::LogArray* getAllLogs();
        Program::LogArray getAllLogsCopy();
    };
}
#endif

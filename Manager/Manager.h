#ifndef MANAGER_H
#define MANAGER_H

#if _WIN32
#define carSaveFilePath "C:\\cars.txt"
#define logSaveFilePath "C:\\logs.txt"
#else
#define carSaveFilePath "build/save/cars.txt"
#define logSaveFilePath "build/save/logs.txt"
#endif



#include <string>
#include <array>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <typeinfo>
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
        long int timestamp;
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
        Manager(std::string filePath = "C:\\auta.txt", std::string logsPath = "C:\\logs.txt");
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
        void toggleAutosave();
    };
}
#endif

#ifndef APPMANAGER_H
#define APPMANAGER_H
#include "../Manager/Manager.h"
#include "../Utils/selector.h"
#include "../StatsCalculator/StatsCalculator.h"
#include <iostream>
#include <ctime>
#include <vector>
namespace Program {
    class AppManager {
      
        
        private:
            Program::Manager* manager;
        public:
            AppManager();
            ~AppManager();
            void displayMenu();
            void addCarOption();
            void removeCarOption();
            void addLogOption();
            void removeLogOption();
            void loadOption();
            void saveOption();
            void exitOption(char* opt);
            void showAllCars();
            void showAllLogs();
            void toggleAutosave();
            void showAllStats();
            void showStatsOption();
            void editLog();




    };
}
#endif
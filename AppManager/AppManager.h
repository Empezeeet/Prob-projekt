#ifndef APPMANAGER_H
#define APPMANAGER_H
#include "../Manager/Manager.h"
#include "../Components/Selector/selector.h"
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
            void selectSortingOption();
            void loadOption();
            void saveOption();
            void search();
            void exitOption(char* opt);
            void showAllCars();
            void showAllLogs();
            void toggleAutosave();
            void showAllStats();
            void showStatsOption();
            void editLog();
            void preSave();
            void preLoad();
            void csvExportOption();



    };
}
#endif
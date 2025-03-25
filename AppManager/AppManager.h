#ifndef APPMANAGER_H
#define APPMANAGER_H
#include "../Manager/Manager.h"
#include <iostream>
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




    };
}
#endif
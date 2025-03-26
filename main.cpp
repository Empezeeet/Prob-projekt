#include "AppManager/AppManager.h"

int main()
{

    Program::AppManager* app = new Program::AppManager();
    char opt;
    
    
    do  {
        app->displayMenu();
        std::cin >> opt;


        switch (opt) {
        case '1': { // add car
            app->addCarOption();
            break;
        }
        case '2': { // remove car
            app->removeCarOption();
            break;
        }
        case '3': { // add new log to car;
            app->addLogOption();
            break;
        }
        case '4': { // print all cars
            app->showAllCars();
            break;
        }
        case '5': { // print all fuel logs
            app->showAllLogs();
            break;
        }
        case '6': { // load
            app->loadOption();
            break;
        }
        case '7': { // save
            app->saveOption();
            break;
        }
        case '8': { // toggle autosave;
            app->toggleAutosave();
        }
        case '9': { // show stats;
            app->showStatsOption();
        }
        case 'Z': { // revert last change.
            // TODO: add CTRL-Z option;
            break;
        }
        case 'E': { // exit
            app->exitOption(&opt);
            break;
        }
        }



    } while (opt != 'E');



    delete app;    
    return 0;
}

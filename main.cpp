#include "AppManager/AppManager.h"

int main()
{

    Program::AppManager* app = new Program::AppManager();
    char opt;
    
    
    do  {
        app->displayMenu();
        std::cin >> opt;


        switch (opt) {
        case '1':
            app->addCarOption();
            break;
        case '2':
            app->removeCarOption();
            break;
        case '3': 
            app->addLogOption();
            break;
        case '4': 
            app->showAllCars();
            break;
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
            break;
        }
        case 'E': {
            app->editLog();
            break;
        }
        case 'Z': { // revert last change.
            // TODO: add CTRL-Z option;
            break;
        }
        case 'X': { // exit
            app->exitOption(&opt);
        }
        }



    } while (opt != 'X');



    delete app;    
    return 0;
}

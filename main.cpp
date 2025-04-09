#include "AppManager/AppManager.h"

int main()
{
    Program::AppManager* app = new Program::AppManager();
    char opt;
    
    do  {
        app->displayMenu();
        std::cin >> opt;

        switch (opt) {
        case '1': // add car
            app->preSave();
            app->addCarOption();
            break;
        case '2': // remove car
            app->preSave();
            app->removeCarOption();
            break;
        case '3': // add log
            app->preSave();
            app->addLogOption();
            break;
        case '4': // print all cars.
            app->showAllCars();
            break;
        case '5': // print all fuel logs
            app->showAllLogs();
            break;
        case '6': // load
            app->preSave();
            app->loadOption();
            break;
        case '7': // save
            app->saveOption();
            break;
        case '8': // toggle autosave;
            app->toggleAutosave();
            break;
        case '9': // show stats;
            app->showStatsOption();
            break;
        case 'U': // remove log
            app->preSave();
            app->removeLogOption();
            break;
        case 'E': // edit log 
            app->preSave();
            app->editLog();
            break;
        case 'Z': // revert last change.
            app->preLoad();
            break;
        case 'X': // exit
            app->exitOption(&opt);
        }

    } while (opt != 'X');

    delete app;    
    return 0;
}

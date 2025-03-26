#include "selector.h"
#if _WIN32
#define CLEAR system("cls")
#else
#define CLEAR system("clear")
#endif
Program::Auto* Program::Components::listSelector(Program::CarArray* items) {
    
    int count = 0;
    // count = 1, opt = 2, 
    std::cout << "Wybierz auto z listy:\n";
    for (int i=0; i<items->max_size(); i++) {
        if (items->at(i).id == 0) continue;
        std::cout << "[" << i+1 << "] " << items->at(i).nazwa << '\n';
        count++;
    }
    if (count == 0) {
        std::cout << "Brak opcji.\n";
        return nullptr;
    }
    int opt;
    do {
        std::cin >> opt;
        opt--;
        if (opt > count-1 || opt < 0) {
            std::cout << "Opcja " << opt+1 << " jest niepoprawna! Wybierz inna!\n";
            continue;
        }
    } while (opt > count-1 || opt < 0);
    return &items->at(opt);
}
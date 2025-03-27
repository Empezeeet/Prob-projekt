#include "selector.h"
#if _WIN32
#define CLEAR system("cls")
#else
#define CLEAR system("clear")
#endif
Program::ISelectable* Program::Components::listSelector(std::vector<Program::ISelectable*> items, int size, std::string message) {
    int count = 0;
    std::cout << "size: " << size << "\n";
    // fixme: not showing all...
    std::cout << message << '\n';
    for (int i=0; i<size; i++) {
        if (items.at(i) == nullptr) continue; 
        std::cout << "[" << i+1 << "] " << items.at(i)->getName() << '\n';
        count++;
    }
    if (count == 0) {
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
    return items.at(opt);

}
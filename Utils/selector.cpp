#include "selector.h"
#if _WIN32
#define CLEAR system("cls")
#else
#define CLEAR system("clear")
#endif
Program::ISelectable* Program::Components::listSelector(std::vector<Program::ISelectable*> items, int size, std::string message) {
    int count = 0;
    std::cout << "size: " << size << "\n";
    if (items.size() == 0) {
        std::cout << "Lista nie moze byc pusta!\n";
        return nullptr;
    }
    std::cout << message << '\n';
    for (; count<items.size(); count++) {
        std::cout << "count: " << count << '\n';
        if (items[count] == nullptr) {
            std::cout << "nullptr!\n";
            continue;
        }
        std::cout << "[" << count+1 << "] " << items[count]->getName() << '\n'; // FIXME: segfault here.
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
#include "Wpis.h"


Program::Wpis* Program::Wpis::logPicker(std::array<Program::Wpis, 64>* logArray) {
    std::vector<Program::ISelectable*> logVector;
    for (int i=0; i<16; i++) {
        Program::Wpis* log = &logArray->at(i);
        if (log->getID() == 0 || log == nullptr) continue;
        logVector.push_back(log);
    }
    return (Program::Wpis*)Components::listSelector(logVector, logVector.size(), "Wybierz wpis z listy: ");
}
int Program::Wpis::countNonEmpty(std::array<Program::Wpis, 64> logArray) {
    int count=0;
    for (Program::Wpis& log : logArray) {
        if (log.id!=0) count++;
    }
    return count;
}
std::string Program::Wpis::getName() const {
    return "Wpis " + std::to_string(this->timestamp);
}
int Program::Wpis::getID() const {
    return this->id;
}
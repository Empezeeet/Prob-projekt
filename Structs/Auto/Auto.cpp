#include "Auto.h"


Program::Auto* Program::Auto::carPicker(std::array<Program::Auto, 16>* carArray) {
    std::vector<Program::ISelectable*> carVector;
    for (int i=0; i<16; i++) {
        Program::Auto* car = &carArray->at(i);
        if (car->getID() == 0 || car == nullptr) continue;
        carVector.push_back(car);
    }
    return (Program::Auto*)Components::listSelector(carVector, carVector.size(), "Wybierz auto z listy: ");
}
int Program::Auto::countNonEmpty(std::array<Program::Auto, 16> carArray) {
    int count=0;
    for (Program::Auto& car : carArray) {
        if (car.id!=0) count++;
    }
    return count;
}
std::string Program::Auto::getName() const {
    return this->nazwa;
}
int Program::Auto::getID() const {
    return this->id;
}
#include "StatsCalculator.h"

float Program::StatsCalculator::calculateAllTimeExpenses(Program::LogArray& logs) {
    float sum = 0;
    for (Program::Wpis log : logs) {
        sum += log.cena;
    }
    return sum;
}
float Program::StatsCalculator::calculateMonthlyExpenses(Program::LogArray& logs) {
    // FIXME: invalid pointer.
    // TODO: fix this function.
    //return -1;
    float sum = 0;
    const std::time_t currentTimestamp = std::time(nullptr);
    const std::tm* currentTime = std::localtime(&currentTimestamp);
    std:tm* logTime;
    for (Program::Wpis log : logs) {
        logTime = std::localtime(&log.timestamp);
        if (logTime->tm_year+1900 != currentTime->tm_year+1900 || logTime->tm_mon+1 != currentTime->tm_mon+1) 
            continue;
        sum += log.cena;
    }


    return sum;
}
float Program::StatsCalculator::fuelUsage(LogArray& logs, Program::Auto* car) {
    float ilosc = 0;
    for (int i=logs.size()-1; i>=0; i--) {
        if (logs.at(i).id == 0) continue;
        if (logs.at(i).auto_id != car->id) continue;
        ilosc += logs.at(i).ilosc;
    }
    //std::cout << "[Ilosc: " << ilosc << " | " << "Przebieg->car: " << car->przebieg << " | " << "M1: " << "] ";
    return (ilosc)/(car->przebieg)*100;
}




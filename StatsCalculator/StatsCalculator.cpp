#include "StatsCalculator.h"

float Program::StatsCalculator::calculateAllTimeExpenses(Program::LogArray* logs) {
    // TODO: Test AllTimeExpenses calculation
    float sum = 0;
    for (Program::Wpis log : *logs) {
        sum += log.cena;
    }
    return sum;
}
float Program::StatsCalculator::calculateMonthlyExpenses(Program::LogArray* logs) {
    // TODO: test monthly expenses calculation;
    float sum = 0;
    const std::time_t currentTimestamp = std::time(nullptr);
    const std::tm* currentTime = std::localtime(&currentTimestamp);
    std:tm* logTime;
    for (Program::Wpis log : *logs) {
        logTime = std::localtime(&log.timestamp);
        if (logTime->tm_year+1900 != currentTime->tm_year+1900 || logTime->tm_mon+1 != currentTime->tm_mon+1) 
            continue;
        sum += log.cena;
    }


    delete logTime;
    delete currentTime; 
    return sum;
}
float Program::StatsCalculator::fuelUsage(LogArray* logs, Program::Auto* car) {
    // formula is OK. TODO: test for-loop.
    // logs are sorted by date by default. highest index is latest log.
    bool skipped_one = false;
    long int mileage1;
    float ilosc;
    // mileage 2 = car->przebieg;
    for (int i=logs->size()-1; i>=0; i--) {
        if (logs->at(i).id == 0) continue;
        if (logs->at(i).auto_id != car->id) continue;
        // no useful data in latest log.
        if (skipped_one == false) skipped_one = true; 
        mileage1 = logs->at(i).przebieg;
        break;
    }
    return (100*ilosc)/(car->przebieg - mileage1);
}




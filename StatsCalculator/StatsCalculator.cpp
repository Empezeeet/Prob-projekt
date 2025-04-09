#include "StatsCalculator.h"

float Program::StatsCalculator::calculateAllTimeExpenses(Program::LogArray* logs) {
    float sum = 0;
    for (Program::Wpis log : *logs) sum += log.cena;
    
    return sum; 
}
float Program::StatsCalculator::calculateMonthlyExpenses(Program::LogArray logs) {
    std::time_t currentTimestamp;
    std::time(&currentTimestamp);
    std::tm* currentTime = std::localtime(&currentTimestamp);
    std::tm* logTime;
    float sum = 0;
    for (Program::Wpis log : logs) {
        logTime = std::localtime(&log.timestamp);
        if (logTime->tm_year+1900 != currentTime->tm_year+1900 || logTime->tm_mon+1 != currentTime->tm_mon+1)
            continue;
        sum += log.cena;
    }
    return sum;
}
float Program::StatsCalculator::averageFuelPrice(LogArray* logs) {
    float sum = 0;
    int count = 0;

    for (; count<logs->size(); count++) 
        sum += logs->at(count).cena / logs->at(count).ilosc;
    
    if (count == 0) return 0;
    return sum/count;
}
float Program::StatsCalculator::fuelUsage(LogArray* logs, Program::Auto* car) {
    float ilosc = 0;
    for (int i=logs->size()-1; i>=0; i--) {
        if (logs->at(i).id == 0) continue;
        if (logs->at(i).auto_id != car->id) continue;
        ilosc += logs->at(i).ilosc;
    }
    return (ilosc)/(car->przebieg)*100;
}
float Program::StatsCalculator::pricePerKilometer(LogArray* logs) { 
    float moneySum = 0;
    float distance = 0;
    for (int i=0; i<logs->size(); i++) {
        moneySum += logs->at(i).cena;
        distance += logs->at(i).przebieg - logs->at(i).previousPrzebieg;
    }
    if (distance == 0) return 0;
    return moneySum/distance;
}



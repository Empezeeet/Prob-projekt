#include "StatsCalculator.h"

float Program::StatsCalculator::calculateAllTimeExpenses(Program::LogArray* logs) {
    float sum = 0;
    for (Program::Wpis log : *logs) sum += log.cena;
    
    return sum; 
}
float Program::StatsCalculator::calculateMonthlyExpenses(Program::LogArray logs) {

    
    std::tm currentTime = Program::Time::createDatetimeNow();
    std::tm* logTime;
    float sum = 0;
    for (Program::Wpis log : logs) {
        logTime = std::localtime(&log.timestamp);
        if (logTime->tm_year+1900 != currentTime.tm_year+1900 || logTime->tm_mon+1 != currentTime.tm_mon+1)
            continue;
        sum += log.cena;
    }
    return sum;
}
float Program::StatsCalculator::averageFuelPrice(LogArray* logs) {
    float sum = 0; 
    int count = 0;

    for (int i=0; i<logs->size()-1; i++) {
        if (logs->at(i).id == 0) continue;
        sum += logs->at(i).cena / logs->at(i).ilosc;
        count++;
    }

    
    if (count == 0) return -1;
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
    std::cout << '\n';
    float moneySum = 0; // FIXME: wrong. returns really small amount;
    float distance = 0;
    for (int i=0; i<logs->size(); i++) {
        if (logs->at(i).id == 0) continue;
        std::cout << "cena: " << logs->at(i).cena << '\n';
        moneySum += logs->at(i).cena;
        std::cout << "+dst: " << logs->at(i).przebieg - logs->at(i).previousPrzebieg << "\n";
        distance += logs->at(i).przebieg - logs->at(i).previousPrzebieg;
    }
    std::cout << "MS: " << moneySum << "\n";
    std::cout << "dst: " << distance << "\n";
    if (distance == 0) return 0;
    return moneySum/distance;
}
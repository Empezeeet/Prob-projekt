#ifndef STATS_CALCULATOR_H
#define STATS_CALCULATOR_H

#include "../Manager/Manager.h"
#include <ctime>
namespace Program {
    class StatsCalculator {

    public:
        static float calculateAllTimeExpenses(LogArray* logs);
        static float calculateMonthlyExpenses(LogArray logs);
        static float fuelUsage(LogArray* logs, Program::Auto* car);
        static float averageFuelPrice(LogArray* logs); 
        static float pricePerKilometer(LogArray* logs); 
    };
}
#endif
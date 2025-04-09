#ifndef STATS_CALCULATOR_H
#define STATS_CALCULATOR_H

#include "../Manager/Manager.h"
#include <ctime>
namespace Program {
    
    class StatsCalculator {

        public:
        /*Available stats:
            - usage Liters per 100 km
            - monthly expenses
            - all-time expenses
            - 
        */
        static float calculateAllTimeExpenses(LogArray* logs);
        static float calculateMonthlyExpenses(LogArray logs);
        static float fuelUsage(LogArray* logs, Program::Auto* car);
        


    };
}
#endif
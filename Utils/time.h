#ifndef PROGRAM_TIME_H
#define PROGRAM_TIME_H
#include <ctime>
#include <string>

namespace Program {

    namespace Time {
        // function datetime to timestamp
        std::time_t datetimeToTimestamp(std::tm datetime);
        // function timestamp to date
        std::tm timestampToDate(std::time_t timestamp);
        // function create datetime
        std::tm createDatetimeNow();
        std::tm createDatetime(int year, int month, int day, int hour=0, int minute=0, int second=0);
        // function timestamp to string
        std::string timestampToString(std::time_t timestamp);
        std::time_t Now();
        
    } 
}
#endif
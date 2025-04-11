#include "time.h"

namespace Program::Time {


    std::time_t datetimeToTimestamp(std::tm datetime) {
        return std::mktime(&datetime);
    }
    std::tm createDatetimeNow() {
        std::time_t currentTime;
        std::time(&currentTime);
        std::tm* currentDatetime = std::localtime(&currentTime);
        return *currentDatetime;
    }
    std::tm timestampToDate(std::time_t timestamp) {
            // TODO: write timestampToDate function
    }   
    std::tm createDatetime(int year, int month, int day, int hour, int minute, int second) {
        std::tm datetime;
        datetime.tm_hour = hour;
        datetime.tm_min = minute;
        datetime.tm_sec = second;

        datetime.tm_year = year - 1900;
        datetime.tm_mon = month - 1;
        datetime.tm_mday = day;
        datetime.tm_isdst = -1; // automatic Daylight Saving time.
        return datetime;
    }
    std::string timestampToString(std::time_t timestamp) {
        timestamp += 3600*2;
        return std::ctime(&timestamp); 
    }
    std::time_t Now() {
        return std::time(NULL);
    }
}
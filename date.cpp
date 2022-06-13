//
//  date.cpp
//  AJC projet C++
//
//  Created by pardo jérémie on 13/06/2022.
//

#include <iostream>
#include "date.hpp"

date::date (unsigned short day, unsigned short month, unsigned short year) {
    this->day = day;
    this->month = month;
    this->year = year;
    
    asgoodformat ();
}

bool date::isbirthday () {
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    
    return day == now->tm_mday &&  month == (now->tm_mon + 1);
}
unsigned short date::getage () const {
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    
    unsigned short age = (now->tm_year + 1900) - year;
    
    if (!(month > (now->tm_mon + 1)) && !(month == (now->tm_mon + 1) && day >= now->tm_mday))
        age--;
    
    return age;
}
std::string date::tostring () const {
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << day << "/" << std::setw(2) <<  std::setfill('0')  << month << "/" << year;
    return oss.str();
}

void date::asgoodformat() { // between 1/1/1900 and today.
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    
    if (year < 1900 || year > (now->tm_year + 1900))
        throw std::invalid_argument("invalid argument in date creation: year format is invalide!");
    if (month > 12 || ( year == now->tm_year + 1900 && month > now->tm_mon + 1))
        throw std::invalid_argument("invalid argument in date creation: month format is invalide!");
    if (!asgooddayformat () || ( year == now->tm_year + 1900 && month == now->tm_mon + 1 && day > now->tm_mday))
        throw std::invalid_argument("invalid argument in date creation: day format is invalide!");
}


bool date::asgooddayformat () {
    unsigned short maxdaymonth = 0;
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            maxdaymonth = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            maxdaymonth = 30;
            break;
        case 2:
            if ( (year & 4) == 0  && ( (year % 100) != 0 || (year % 400) == 0))
                maxdaymonth = 29;
            else
                maxdaymonth = 28;
            break;
        default:
            break;
    }
    return 0 < day && day <= maxdaymonth;
}

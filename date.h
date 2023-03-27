#ifndef DATE_H
#define DATE_H

#include <string>
#include <iostream>

class Date{
    public:
        Date(int month, int day, int year);
        Date(std::string month, std::string day, std::string year);
        void print_date();
    private:
        std::string month_;
        std::string day_;
        std::string year_;
};

#endif
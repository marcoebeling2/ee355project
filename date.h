#ifndef DATE_H
#define DATE_H

#include <string>
#include <iostream>
#include <fstream>

class Date{
    public:
        Date(int month, int day, int year);
        Date(std::string month, std::string day, std::string year);
        void print_date();
        void print_date(std::string format);
        std::string getDate();
        // this is to help with Network::saveDB()
        void print_date(std::string format, std::ofstream &ofstr);
    private:
        std::string month_;
        std::string day_;
        std::string year_;
};

#endif
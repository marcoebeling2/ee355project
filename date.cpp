#include <iostream>
#include <string>
#include <ctime>
#include "date.h"

using namespace std;

const string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

Date::Date(int month, int day, int year): Date(months[month - 1], to_string(day), to_string(year)){}

Date::Date(string month, string day, string year): month_(month), day_(day), year_(year){}

void Date::print_date(){
    cout << month_ << ", " << day_ << " " << year_ << endl;
}

void Date::print_date(string format){
    cout << month_ << ", " << day_ << " " << year_ << endl;
}


string Date::getDate(){
    string out = "";
    out += month_ + "/" + day_ + "/" + year_;
    return out;
}


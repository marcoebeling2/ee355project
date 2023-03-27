#include <iostream>
#include <string>
#include <ctime>
#include "date.h"

using namespace std;

Date::Date(int month, int day, int year){
    // string vec to store month names
    const string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    Date(months[month - 1], to_string(day), to_string(year));
}

Date::Date(string month, string day, string year): month_(month), day_(day), year_(year){}

void Date::print_date(){
    cout << month_ << ", " << day_ << " " << year_ << endl;
}


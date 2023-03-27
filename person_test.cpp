#include <iostream>
#include <string>
#include <sstream>
#include "person.h"
#include "date.h"

using namespace std;

int main(){
    string myNum("4/14/2003");

    // parse birthday using string streams
    std::stringstream ss(myNum);
    // delimeter for birthdates
    char delimeter;
    int month;
    int day;
    int year;
    ss >> month >> delimeter >> day >> delimeter >> year;
    cout << month << " " << day << " " << year << endl;
    Date myDay(month, day, year);
    myDay.print_date();

    // okay testing this constructor now
    Person myGuy("Beast", "guy", "1/13/1961", "(Gmail) something@email.com", "(Office) 3102917482");
}


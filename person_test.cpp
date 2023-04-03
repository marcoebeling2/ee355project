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
    /*
    char delimeter;
    int month;
    int day;
    int year;
    ss >> month >> delimeter >> day >> delimeter >> year;
    cout << month << " " << day << " " << year << endl;
    Date myDay(month, day, year);
    myDay.print_date();
    */

    // okay testing this constructor now
    cout << "Person Test:" << endl;
    Person myGuy("Beast", "guy", "1/13/1961", "(Gmail) something@email.com", "(Office) 3102917482");
    myGuy.print_person();
    cout << endl;

    // that worked, now try to setperson(filename)
    myGuy.set_person("personal_template.txt");
    myGuy.print_person();
    cout << endl;

    /*/ okay I think that worked, now make another person with the empty constructor. Then test == and !=
    Person myGuy2;
    myGuy2.print_person();


    cout << endl;
    cout << endl;
    if (myGuy2 == myGuy){
        cout << "Good job == works" << endl;
    }
    else {
        cout << "Put the right input or check the operation overload" << endl;
    }
    cout << endl;
    cout << endl;

    if (myGuy2 != myGuy){
        cout << "Good job != works" << endl;
    }
    else {
        cout << "Put the right input or check the operation overload" << endl;
    }
    */


    // everything up to here works. I think there might be some errors with the set functions
    myGuy.set_person();
    myGuy.print_person();
}


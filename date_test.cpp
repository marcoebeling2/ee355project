#include <iostream>
#include <string>
#include "date.h"

using namespace std;

int main(){
    // construct dates
    Date day1(4, 14, 2003);
    Date day2("April", "14", "2003");
    // print dates out
    day1.print_date();
    day2.print_date();

    const string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    Date day3(months[3], to_string(14), to_string(2003));
    day3.print_date();
}
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
}
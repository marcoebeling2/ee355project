#include "contact.h"
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

// this cpp file is meant to test the functionality of contact.cpp

int main(){
    // test Phone first
    Phone myPhone("Personal", "123-456-7890");
    // print contents
    cout << "actual contents: " << myPhone.get_contact("else") << endl; // checking to see if the this does not print the hiphens
    myPhone.print();
    // change content
    myPhone.set_contact();
    // print again to check
    myPhone.print();


    // test email
    Email myEmail("School", "mebeling@usc.edu");
    // print contents in both styles
    myEmail.print();
    cout << "Actual email: " << myEmail.get_contact("else") << endl;
    // change email
    myEmail.set_contact();
    myEmail.print();
}

#ifndef PERSON_H
#define PERSON_H

#include "date.h"
#include "contact.h"
#include "fstream"
#include <string>
#include <fstream>
class Person{
    friend class Network;

private:
	string f_name;
	string l_name;
	Date *birthdate;
    Email *email;
    Phone *phone;
    // the following to attributes are used in the linked list.
    Person* next;
    Person* prev;

public: 
    Person();
    ~Person();
    Person(string filename);
    Person(string f_name, string l_name, string b_date, string email, string phone);
	void print_person();
	void set_person();
	void set_person(string filename);
    bool operator==(const Person& rhs);
    bool operator!=(const Person& rhs);

    // additions for opperator overloading
    string getFirstName() const;
    string getLastName() const;
    string getPhoneNum() const;

    // ctor and sets that we added to help with network
    void set_person(ifstream &ifstr);
    Person(ifstream &ifstr);

    // added this fuction to save files
    void print_person(ofstream &ofstr);
};


#endif
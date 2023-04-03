
#ifndef NETWORK_H
#define NETWORK_H

#include "person.h"
#include "date.h"
// You may need to add more libraries 
#include <stdlib.h>
class Network{

    private:
        Person* head;
        Person* tail;
        int count; 
        Person* search(Person* searchEntry);
        Person* search(string fname, string lname);

    public:
        Network();
        Network(string fileName);
        ~Network();
        void printDB();
        void push_front(Person* newEntry);
        void push_back(Person* newEntry);
        bool remove(string fname, string lname);
        // comment out for now
        //void showMenu();
        void loadDB(string filename);
        void saveDB(string filename);

        // friend functions
        // get functions for network
        Person* getNext(Person &p);
        Person* getPrev(Person &p);

        // set functions for network
        void setNext(Person &p, Person* newP);
        void setPrev(Person &p, Person* newP);

        // pop_back function to help with cleaning up
        void pop_back();
};

#endif

#include "network.h"
#include <limits>
#include "misc.h"
#include <fstream>
#include <iostream>
#include <string>

Network::Network(){
    head = NULL;
    tail = NULL;
    count = 0;
}


Network::Network(string fileName){
    // TODO: complete this method!
    // Implement it in one single line!
    // You may need to implement the load method before this!
}

Network::~Network(){ 
    while (count != 0){
        pop_back();
    }

}

Person* Network::search(Person* searchEntry){
    // Searches the Network for searchEntry
    // if found, returns a pointer to it, else returns NULL
    // TODO: Complete this method
}


Person* Network::search(string fname, string lname){
    // New == for Person, only based on fname and lname
    // if found, returns a pointer to it, else returns NULL
    // TODO: Complete this method
    // Note: two ways to implement this, 1st making a new Person with fname and lname and and using search(Person*), 2nd using fname and lname directly. 
}




void Network::loadDB(string filename){
    // TODO: Complete this method

    // load deletes everything, so start by deleting everything
    while (count > 0){
        // make pop_back function
        pop_back();
    }

    // make an ifstream to begin loading data
    ifstream ifstr;
    ifstr.open(filename);

    // keep making new Person object until the file is at the end
    while (!ifstr.eof()){
        // pass the ifstr to ctor of Person
        Person* newPerson = new Person(ifstr);

        // add the new person
        push_back(newPerson);

        // get the next line to get next input correct
        string nextLine;
        getline(ifstr, nextLine);
        if (ifstr.eof()){
            break;
        }
    }

    // close if stream
    ifstr.close();
}

void Network::saveDB(string filename){
    // TODO: Complete this method

    // i dont really know what to do here lol
}


void Network::printDB(){
    // Leave me alone! I know how to print! 
    // Note: Notice that we don't need to update this even after adding to Personattributes
    // This is a feature of OOP, classes are supposed to take care of themselves!
    cout << "Number of people: " << count << endl;
    cout << "------------------------------" << endl;
    Person* ptr = head;
    while(ptr != NULL){
        ptr->print_person();
        cout << "------------------------------" << endl;
        ptr = ptr->next;
    }
}



void Network::push_front(Person* newEntry){
    newEntry->prev = NULL;
    newEntry->next = head;

    if (head != NULL)
        head->prev = newEntry;
    else
        tail = newEntry;
    
    head = newEntry;
    count++;
}


void Network::push_back(Person* newEntry){
    // Adds a new Person (newEntry) to the back of LL
    // TODO: Complete this method

    // update DLL data
    // three case... count = 0, 1, not zero or 1

     if (count == 0){ // if this is the first person... tail and head are newPerson and other data is NULL
            head = newEntry;
            tail = newEntry;
            setNext(*newEntry, NULL);
            setPrev(*newEntry, NULL);
    }
    else if (count == 1) { // if this is the second person
            // change tail
            tail = newEntry;

            // change next for head
            setNext(*head, tail);

            // change prev for tail
            setPrev(*tail, head);

            // set next for new item to be NULL
            setNext(*tail, NULL);
    }
    else { // if this is the third person or later
            Person* oldTail = tail; // person* to keep track of the old tail
            
            // change tail
            tail = newEntry;

            // change next for the new tail to NULL
            setNext(*tail, NULL);

            // change next for old tail
            setNext(*oldTail, tail);

            // change prev for new tail
            setPrev(*tail, oldTail);
    }

    // increment count 
    count++;
    
}


bool Network::remove(string fname, string lname){
    // TODO: Complete this method

    // i guess return true if it was successfully removed?

    // start at head and just go through until it is found

    Person* temp = head; // pointer to index through

    bool removed = false; // bool to keep track if it was removed... assume to be false
    
    // index through all of them
    for (int i = 0; i < count; i++){
        // get the first name and last name of the indexed person and check for a match
        if ((temp->getFirstName() == fname) && (temp->getLastName() == lname)){
            // for testing purposes:
            cout << "removing:" << endl;
            temp->print_person();





            // if it is match, remove accordingly
            // four cases... count = 1; head; tail; none
            if (count == 1){ // just pop_back
                pop_back();
            }
            else if (temp == head){ // if it is at the head
                // change head
                head = getNext(*temp);

                // change the prev of the new head
                setPrev(*head, NULL);

                // delete the old head
                delete temp;

                // decrement count
                count--;
            }
            else if (temp == tail){ // if this is at the end just pop back
                pop_back();
            }
            else { // if it is in the middle change accordingly
                // change prev's next
                setNext(*(getPrev(*temp)), getNext(*temp));

                // change next's prev
                setPrev(*(getNext(*temp)), getPrev(*temp));

                // delete temp
                delete temp;

                // decrement count
                count--;
            }
            // change removed 
            removed = true;
            // change i to index to the next one without skipping
            i--;
        }
    }
    // return removed
    return removed;
}


// comment out for now
/*
void Network::showMenu(){
    // TODO: Complete this method!
    // All the prompts are given to you, 
    // You should add code before, between and after prompts!

    int opt;
    while(1){
        cout << "\033[2J\033[1;1H";
        printMe("banner"); // from misc library

        cout << "Select from below: \n";
        cout << "1. Save network database \n";
        cout << "2. Load network database \n";
        cout << "3. Add a new person \n";
        cout << "4. Remove a person \n";
        cout << "5. Print people with last name  \n";
        cout << "\nSelect an option ... ";
        
        if (cin >> opt) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Wrong option! " << endl;
            return;
        }
        
        // You may need these variables! Add more if you want!
        string fname, lname, fileName, bdate;
        cout << "\033[2J\033[1;1H";

        if (opt==1){
            // TODO: Complete me!
            cout << "Saving network database \n";
            cout << "Enter the name of the save file: ";
            cout << "Network saved in " << fileName << endl;
        }
        else if (opt==2){
            // TODO: Complete me!
            cout << "Loading network database \n";
            // TODO: print all the files in this same directory that have "networkDB.txt" format
            // Take a look into sample_files.cpp 
            cout << "Enter the name of the load file: "; 
            // If file with name FILENAME does not exist: 
            cout << "File FILENAME does not exist!" << endl;
            // If file is loaded successfully, also print the count of people in it: 
            cout << "Network loaded from " << fileName << " with " << count << " people \n";
        }
        else if (opt == 3){
            // TODO: Complete me!
            // TODO: use push_front, and not push_back 
            // Add a new Person ONLY if it does not exists!
            cout << "Adding a new person \n";
        }
        else if (opt == 4){
            // TODO: Complete me!
            // if found, cout << "Remove Successful! \n";
            // if not found: cout << "Person not found! \n";
            cout << "Removing a person \n";
            cout << "First name: ";
            cout << "Last name: ";
        }
        else if (opt==5){
            // TODO: Complete me!
            // print the people with the given last name
            // if not found: cout << "Person not found! \n";
            cout << "Print people with last name \n";
            cout << "Last name: ";
        }
        
        else
            cout << "Nothing matched!\n";
        
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "\n\nPress Enter key to go back to main menu ... ";
        string temp;
        std::getline (std::cin, temp);
        cout << "\033[2J\033[1;1H";
    }
}


*/



// friend functions
Person* Network::getNext(Person &p){
    return p.next;
}

Person* Network::getPrev(Person &p){
    return p.prev;
}

void Network::setNext(Person &p, Person* newP){
    p.next = newP;
}

void Network::setPrev(Person &p, Person* newP){
    p.prev = newP;
}

// pop back function to help with cleaning up
void Network::pop_back(){
    // do nothing if count is 0
    if (count == 0){
        return;
    }

    // special case if count is 1 // head == tail
    if (count == 1){
        // delete tail
        delete tail;

        // change head and tail to NULL
        head = NULL;
        tail = NULL;

        // decrement count
        count--;
        return;
    }

    // the new tail will be the tails previous
    Person* newTail = getPrev(*tail);

    // delete the current tail
    delete tail;

    // change tail
    tail = newTail;

    // change next on the new tail to be NULL
    setPrev(*tail, NULL);

    // decrement count
    count--;
}
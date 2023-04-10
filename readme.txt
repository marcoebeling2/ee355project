

contact.h
I made type a public data member in contact because children of contact are accessing type in methods.
I changed the data type for phone_num to a string. This will be easy to address each phone number.

contact.cpp
In the set_contact functions for email and phone, we chose to use string and getline() to handle the iostream and parsing.
The print functions were easy, just added "Email" or "Phone".
In each constructor, we changed the input argument to have an underscore after the name of the argument. For example type -> type_
I added a function to help with Network::saveDB().

contact_test.cpp
We made this file to test the funcionality of contact.cpp

Date.cpp
I added a function to help with Network::saveDB();


person.cpp
We used string streams to parse the birthdate for the Person::Person(string f_name_, string l_name_, string b_date_, string email_, string phone_) constructor. For opperator overloading, we added get name and get birthday member functions. I also added a set function and constructor similar to set(filename), except this time I pass an ofstr. I also added void print_person(ofstream &ofstr) to help with Network::saveDB. After  implementing saveDB, I realized that constructing the phone number may have to factor in cases when ten digits are not given.

network.cpp
First, we added the friend functions to get and set next and prev for person class. Then, we added a pop_back function to help with clearing everything for the dtor and loading in new data. We changed void saveDB() to be int saveDB(). The purpose of this was for error handling. I added a function that searches based only on last name to help with show menu option 4. Lines 9-14, 339-351, and 531-534 come from https://www.tutorialspoint.com/how-can-i-get-the-list-of-files-in-a-directory-using-c-or-cplusplus#:~:text=Call%20opendir()%20function%20to,name%20using%20en%2D%3Ed_name.These lines are used to find txt files in the current dirrectory.

main.cpp
In this file, I implement the main program with an empty network object.


compile with
g++ -g -std=c++0x network.cpp person.cpp contact.cpp date.cpp misc.cpp main.cpp -o networkTest
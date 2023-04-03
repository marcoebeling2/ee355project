

contact.h
I made type a public data member in contact because children of contact are accessing type in methods.
I changed the data type for phone_num to a string. This will be easy to address each phone number.

contact.cpp
In the set_contact functions for email and phone, we chose to use string and getline() to handle the iostream and parsing.
The print functions were easy, just added "Email" or "Phone".
In each constructor, we changed the input argument to have an underscore after the name of the argument. For example type -> type_

contact_test.cpp
We made this file to test the funcionality of contact.cpp

Date.cpp


person.cpp
We used string streams to parse the birthdate for the Person::Person(string f_name_, string l_name_, string b_date_, string email_, string phone_) constructor. For opperator overloading, we added get name and get birthday member functions. I also added a set function and constructor similar to set(filename), except this time I pass an ofstr.

network.cpp
First, we added the friend functions to get and set next and prev for person class. Then, we added a pop_back function to help with clearing everything for the dtor and loading in new data.

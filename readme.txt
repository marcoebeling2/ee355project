

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

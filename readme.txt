

contact.h
I made type a public data member in contact because children of contact are accessing type in methods.
I changed the data type for phone_num to a string. This will be easy to address each phone number.

contact.cpp
In the set_contact functions for email and phone, we chose to use string and getline() to handle the iostream and parsing.
The print functions were easy, just added "Email" or "Phone"
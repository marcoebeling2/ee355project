
#include "contact.h"
// TODO: Add needed libraries! 
#include <cstring>
#include <string>
#include <iostream>

Email::Email(string type_, string email_addr_){
    // TODO: Complete me!
    type = type_;
    email_addr = email_addr_;
}


void Email::set_contact(){
    // TODO: Do not change the prompts!
    cout << "Enter the type of email address: ";
    // some code here
    // use type as the output string
    getline(cin, type);
    cout << "Enter email address: ";
    // some code here
    // use email_addr as the output string
    getline(cin, email_addr);
}


string Email::get_contact(string style){
    // Note: We have default argument in declaration and not in definition!
    if (style=="full")
	    return "(" + type + "): " + email_addr;
    else 
        return email_addr;
}


void Email::print(){
    // Note: get_contact is called with default argument
	cout << "Email " << get_contact() << endl;
}


Phone::Phone(string type_, string num_){
    // TODO: It is possible that num includes "-" or not, manage it!
    // TODO: Complete this method!
    // Note: We don't want to use C++11! stol is not valid!
    // The code has been covered in the discussion session

    /* Note: Understand your own TA's bug!
     * This code has a bug, can you understand why?
    long int area_code = atoi(num.substr(0, 3).c_str());
    long int  number = atoi(num.substr(3).c_str()); 
    this->phone_num = area_code*10000000 + number; 
    */


    type = type_;
    // parse num_
    for (unsigned int i = 0; i < num_.length(); i++){
    // if the indexed num is not "-"... added it to phone_num
        if (num_[i] != '-'){
            phone_num += num_[i];
        }
    }
}


void Phone::set_contact(){
    // TODO: Complete this method
    // Use the same prompts as given!
	cout <<"Enter the type of phone number: ";
    // use type as output string
    getline(cin, type);
	cout << "Enter the phone number: ";
    // use phone_num as the output string
    // use a temp variable to parse
    string temp;
    getline(cin, temp);
    // reset phone_num
    phone_num = "";
    // parse temp
    for (unsigned int i = 0; i < temp.length(); i++){
    // if the indexed num is not "-"... added it to phone_num
        if (temp[i] != '-'){
            phone_num += temp[i];
        }
    }
}


string Phone::get_contact(string style){
    // TODO: Complete this method, get hint from Email 
    // The code has been covered in discussion session 

    /* Note: Understand your own TA's bug!
     * This code has a bug, can you understand it!
    int x1 = (phone_num/10000000);
	int x2 = ((phone_num)/10000)%1000;
	int x3 = phone_num%10000;
    */
    string out = "(" + type + "): ";
   if (style=="full"){
        for (int i = 0; i < phone_num.size(); i++){
            out += phone_num[i];
            if ((i == 2) || (i == 5)){
                out += "-";
            }
        }
        return out;
	    //return "(" + type + "): " + phone_num[0] + phone_num[1] + phone_num[2] + "-" + phone_num[3] + phone_num[4] + phone_num[5] + "-" +  phone_num[6] + phone_num[7] + phone_num[8] + phone_num[9];
   }
    else {
        return phone_num; 
    }
}


void Phone::print(){
    // Note: get_contact is called with default argument
	cout << "Phone " << get_contact() << endl;
}


// thses are two help with Network::saveDB()
void Phone::print(ofstream &ofstr){
    // Note: get_contact is called with default argument
	ofstr << "Phone " << get_contact() << endl;
}
void Email::print(ofstream &ofstr){
    // Note: get_contact is called with default argument
	ofstr << "Email " << get_contact() << endl;
}


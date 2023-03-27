
#include "person.h"
#include <string>
#include <sstream>
#include <fstream>

Person::Person(){
    // I'm already done! 
    set_person();
}


Person::~Person(){
    delete birthdate;
    // TODO: complete the method!
    delete email;
    delete phone;
}


Person::Person(string f_name_, string l_name_, string b_date_, string email_, string phone_): f_name(f_name_), l_name(l_name_) {
    // TODO: Complete this method!
    // phone and email strings are in full version

    // parse birthday using string streams
    std::stringstream ss(b_date_);
    // delimeter for birthdates
    char delimeter;
    int month;
    int day;
    int year;
    ss >> month >> delimeter >> day >> delimeter >> year;
    // allocate and construct birthdate
    Date* temp = new Date(month, day, year);
    birthdate = temp;

    // i am not really sure what "full form" means... I am just going to assume that it means in the format: (type) contact
    // email first
    std::stringstream ssE(email_);
    // split into type and email
    string typeE;
    string emailIn;
    ss >> typeE >> emailIn;
    // remove () from typeE
    typeE.erase(0, 1);
    typeE.erase(typeE.size() - 1, 1);
    // allocate and construct a new email object
    Email* tempE = new Email(typeE, emailIn);
    email = tempE;

    // phone now
    std::stringstream ssP(phone_);
    // split into type and email
    string typeP;
    string phoneIn;
    ss >> typeP, phoneIn;
    // remove () from typeP
    typeP.erase(0, 1);
    typeP.erase(typeP.size() - 1, 1);
    // allocate and construct a new phone object
    Phone* tempP = new Phone(typeP, phoneIn);
    phone = tempP;
}


Person::Person(string filename){
    set_person(filename);
}


void Person::set_person(){
    // prompts for the information of the user from the terminal
    // first/last name can have spaces!
    // date format must be "M/D/YYYY"
    // We are sure user enters info in correct format.
    // TODO: complete this method!
    
    string firstName;
    string lastName;
    string birthDate;

    cout << "First Name: ";
    // pay attention to how we read first name, as it can have spaces!
    std::getline(std::cin, firstName);

	cout << "Last Name: ";
    std::getline(std::cin, lastName);

    cout << "Birthdate (M/D/YYYY): ";
    std::getline(std::cin, birthDate);
    // pay attention to how we passed argument to the constructor of a new object created dynamically using new command
    // nah just do this in the constructor
    //birthdate = new Date(temp); 

    cout << "Type of email address: ";
    // code here
    string emailType;
    getline(std::cin, emailType);

    cout << "Email address: ";
    // code here
    string emailIn;
    getline(std::cin, emailIn);

    // create a string to pass to the constructor
    string emailCtor = "(" + emailType + ") " + emailIn;

    cout << "Type of phone number: ";
    // code here
    string phoneType;
    getline(std::cin, phoneType);
    cout << "Phone number: ";
    // code here
    string phoneIn;
    getline(std::cin, phoneIn);

    // create a string to pass to the constructor
    string phoneCtor = "(" + phoneType + ") " + phoneIn;


    // call ctor
    new (this) Person(firstName, lastName, birthDate, emailCtor, phoneCtor);
}


void Person::set_person(string filename){
    // reads a Person from a file
    // Look at person_template files as examples.     
    // Phone number in files can have '-' or not.
    // TODO: Complete this method!

    // create an ifstream to read in data
    ifstream ifstr;
    ifstr.open(filename);

    // read data in now using getline
    string firstName;
    string lastName;
    string birthDate;
    string emailIn;
    string phoneIn;

    getline(ifstr, firstName);
    getline(ifstr, lastName);
    getline(ifstr, birthDate);
    // because the input changes from networkDB.txt to personal_template.txt... check if the next line has an '@'... if it does, its the email line
    string temp;
    getline(ifstr, temp);
    // index through temp to find '@'
    bool isEmail = false;
    for (int i = 0; i < temp.size(); i++){
        if (temp[i] == '@'){
            isEmail = true;
        }
    }
    // if it is a email.. use temp as an email, else use it as a phone
    if (isEmail){
        emailIn = temp;
        getline(ifstr, phoneIn);
    }
    else {
        phoneIn = temp;
        getline(ifstr, emailIn);
    }

    // call the constructor now
    new (this) Person(firstName, lastName, birthDate, emailIn, phoneIn);

}


bool Person::operator==(const Person& rhs){
    // TODO: Complete this method!
    // Note: you should check first name, last name and birthday between two persons
    // refer to bool Date::operator==(const Date& rhs)
}

bool Person::operator!=(const Person& rhs){ 
    // TODO: Complete this method!
}


void Person::print_person(){
    // Already implemented for you! Do not change!
	cout << l_name <<", " << f_name << endl;
	birthdate->print_date("Month D, YYYY");
    email->print();
    phone->print();
}
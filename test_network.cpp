
#include "network.h"

using namespace std;

int main(){

    Network myNet;
    //myNet.showMenu(); 


    // testing loadDB and push_back
    myNet.loadDB("networkDB.txt");
    // this works

    cout << endl;
    myNet.printDB();
    cout << endl;


    cout << endl;
    // test saveDB
    int saveDBTest = myNet.saveDB("saving_DB_test.txt");
    if (saveDBTest == 0){
        cout << "good job saving DB was successful" << endl;
    }
    else {
        cout << "cmon bruh that wasnt successful" << endl;
    }
    // cool I think this works


    // test search
    /*
    Person* temp;
    temp = myNet.search("Guy", "Beast"); // should return NULL
    if (temp == NULL){
        cout << "good job. search correctly did not find anybody" << endl;
    }
    temp = myNet.search("Martin", "Van Nostrand"); // should return a ptr
    if (temp != NULL){
        cout << "good job. seach correctly found this person:" << endl;
        temp->print_person();
        cout << endl;
    }
    // this works nice

    // test search entry
    // use temp from the past to check if it returns true
    temp = myNet.search(temp);
    if (temp != NULL){
        cout << "good job. seach correctly found this person:" << endl;
        temp->print_person();
        cout << endl;
    }
    // change temp by creating a new person
    temp = new Person("personal_template.txt");
    temp = myNet.search(temp);
    if (temp == NULL){
        cout << "good job. search correctly did not find anybody" << endl;
    }
    */
    // boom works nice





    // testing to see if remove identifies correctly how to remove ONLY
    /*
    myNet.remove("Martin", "Van Nostrand");
    cout << endl;
    myNet.printDB();
    myNet.remove("Julia Scarlett Elizabeth", "Louis-Dreyfus");
    cout << endl;
    myNet.printDB();
    myNet.remove("Truman", "Burbank");
    cout << endl;
    myNet.printDB();
    */
    // i think it works




    return 0;
} 
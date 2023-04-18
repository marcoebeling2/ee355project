
#include "misc.h"
#include <cstring>

void printMe(string type){
    if (type == "banner"){
        char banner[] = \
"   ######## ########   #######        ##    ###    ##    ##         ########   #######   #######  ##    ## \n \
     ##    ##     ## ##     ##       ##   ## ##   ###   ##         ##     ## ##     ## ##     ## ##   ## \n \
     ##    ##     ## ##     ##       ##  ##   ##  ####  ##         ##     ## ##     ## ##     ## ##  ## \n \
     ##    ########  ##     ##       ## ##     ## ## ## ## ####### ########  ##     ## ##     ## ##### \n \
     ##    ##   ##   ##     ## ##    ## ######### ##  ####         ##     ## ##     ## ##     ## ##  ## \n \
     ##    ##    ##  ##     ## ##    ## ##     ## ##   ###         ##     ## ##     ## ##     ## ##   ## \n \
     ##    ##     ##  #######   ######  ##     ## ##    ##         ########   #######   #######  ##    ##\n";
        cout << endl << banner << endl << endl;
    }
}

string makeUniqueID(string fname, string lname){
    string out;
    // use string streams
    stringstream ss1(fname);
    stringstream ss2(lname);

    string temp;
    while (ss1 >> temp){
        out += temp;
        temp = "";
    }
    while (ss2 >> temp){
        out += temp;
        temp = "";
    }

    string uniqueID;
    for (char c : out) {
        uniqueID += std::tolower(c);
    }
    return uniqueID;
}
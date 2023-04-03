
#include "network.h"

using namespace std;

int main(){

    Network myNet;
    //myNet.showMenu(); 


    // testing loadDB and push_back
    myNet.loadDB("networkDB.txt");
    // this works

    // testing to see if remove identifies correctly how to remove ONLY
    //myNet.remove("Martin", "Van Nostrand");

    return 0;
} 
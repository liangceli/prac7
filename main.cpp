#include <iostream>
#include <vector>
#include "Autocomplete.h"
using namespace std;

int main(){
    Autocomplete * tree=new Autocomplete();
    vector<string> mytree;

    tree->insert("car");
    tree->insert("cat");
    mytree=tree->getSuggestions("car");
    
    for (string s : mytree) {
       cout << s << endl;
    }
    return 0;
}


#include <iostream>
#include <vector>
#include "Autocomplete.h"
using namespace std;

int main(){
    Autocomplete * tree=new Autocomplete();
    vector<string> mytree;

    tree->insert("banana");
    tree->insert("bandaid");
    tree->insert("bandana");

    cout << "Search " << tree->search_string("banana") << endl;
    cout << "Search " << tree->search_string("bandaid") << endl;
    cout << "Search " << tree->search_string("bandana") << endl;

    mytree=tree->getSuggestions("b");
    for (string& i : mytree) {  // 使用范围 for 循环遍历 vector
        cout << i << " ";
    }

    delete tree;
    return 0;
}


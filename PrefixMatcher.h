#pragma once
#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;

struct TrieNode {
    std::unordered_map<char, TrieNode*> children;
    int routerNumber;

    TrieNode() {
        routerNumber = -1;
    }
};

class PrefixMatcher{
    public:
    TrieNode* root; //建立root
    PrefixMatcher();

    int selectRouter(string networkAddress);  // return the router with the longest matching prefix
    // We've made this a string for ease of implementation, 
    //if you'd like to work with binary numbers in your implementation 
    //feel free but for testing you need to provide an interface that takes a string
    void insert(string address, int routerNumber); // add a router address  
};
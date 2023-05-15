#include<iostream>
#include<vector>
#include <unordered_map>
#include"PrefixMatcher.h"
using namespace std;

PrefixMatcher::PrefixMatcher(){
    root=new TrieNode(); 
}

void PrefixMatcher::insert(string address, int routerNumber){
    TrieNode* node = root;
        for (char c : address) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->routerNumber = routerNumber;
} 

int PrefixMatcher::selectRouter(string networkAddress){
    TrieNode* node = root;
        int longestPrefix = -1;
        int longestRouter = -1;
        for (int i = 0; i < networkAddress.size(); i++) {
            char c = networkAddress[i];
            if (node->children.find(c) == node->children.end()) {
                break;
            }
            node = node->children[c];
            if (node->routerNumber != -1) {
                longestPrefix = i;
                longestRouter = node->routerNumber;
            }
        }
        return longestRouter;
    }



#include <iostream>
#include <vector>
#include "Autocomplete.h"
using namespace std;

Autocomplete :: Autocomplete(){
    root=new TrieNode(); //为Trie tree的根 root分配空间
}

bool Autocomplete :: search_string(string s) {
    TrieNode* curr = root;
    for (char c : s) {
        int idx = c - 'a';
        if (curr->children[idx] == nullptr) {
            return false;
        }
        curr = curr->children[idx];
    }
    return curr->isEndOfword;
}

void Autocomplete :: insert(string word){
    TrieNode * node=root;
     //从根节点开始，遍历整个数组，看有没有这个单词
     for(char c : word){
        int index=c-'a';//计算字符串中的char在children中的索引

        if(!node->children[index]){ //如果node的children中没有这个char的情况下

        node->children[index]=new TrieNode(); //为这个字母建立一个新的node
        }

        node=node->children[index]; //将当前的node指向新建的node 往后面移动
     }

     node->isEndOfword=true; //插入完成之后将此时的这个字符串的最后一个char设为 true 证明插入完成
}

/*vector<string> Autocomplete :: getSuggestions(string partialWord){ //当输入partialword的时候提供提示 如果输入‘c’ 如果tree里面有“cat” “car” 存储在vector中并且打印出来

    TrieNode * curr_node=root;
    vector<string> suggestions;
    string temp;

    //首先看这个tree有没有partialword，并储存起来
    for(int i=0; i<partialWord.length(); i++){
      char c=partialWord.at(i);  
      TrieNode * child=curr_node->children[c-'a'];
      if(child==nullptr){
        return suggestions;
      }
      temp.push_back(c);
      curr_node=child;
    }

    while(true){
        bool found = false;

        for(int i=0; i<26; i++){

            TrieNode* next_child = curr_node->children[i];

            if(next_child != nullptr){

                temp.push_back('a' + i);

                if(next_child->isEndOfword==true){     
                    suggestions.push_back(temp);
                    curr_node = next_child;
                     found = true;

                     break;
                }
            }
        }

      

        if(!found){
            break;
        }
    }

    temp.clear();

    return suggestions;
}

Autocomplete::~Autocomplete(){
    delete root;
}*/


vector<string> Autocomplete::getSuggestions(string partialWord) {
    TrieNode* curr_node = root;
    vector<string> suggestions;

    // Traverse the trie to find the node corresponding to partialWord
    for (int i = 0; i < partialWord.length(); i++) {
        char c = partialWord.at(i);
        TrieNode* child = curr_node->children[c - 'a'];
        if (child == nullptr) {
           // return suggestions; // The trie does not contain words starting with partialWord
           break;
        }
        curr_node = child;
    }

    // Use DFS to find all words starting with partialWord
    string temp = partialWord;
    DFS(curr_node, temp, suggestions);

    return suggestions;
}

void Autocomplete::DFS(TrieNode* curr_node, string& temp, vector<string>& suggestions) {
    // If curr_node represents the end of a word, add it to suggestions
    if (curr_node->isEndOfword) {
        suggestions.push_back(temp);
    }

    // Traverse all children of curr_node
    for (int i = 0; i < 26; i++) {
        TrieNode* next_child = curr_node->children[i];
        if (next_child != nullptr) {
            temp.push_back('a' + i); // Append the character to temp
            DFS(next_child, temp, suggestions);
            temp.pop_back(); // Remove the character from temp
        }
    }
}
#include <iostream>
#include <vector>
#include "Autocomplete.h"
using namespace std;

/*Autocomplete :: Autocomplete(){
    root=new TrieNode(); //为Trie tree的根 root分配空间
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
     cout<<"okok";
}

vector<string> Autocomplete :: getSuggestions(string partialWord){ //当输入partialword的时候提供提示 如果输入‘c’ 如果tree里面有“cat” “car” 存储在vector中并且打印出来

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
void Autocomplete::insert(const std::string& word) {
    insert_helper(root, word);
}

void Autocomplete::insert_helper(TrieNode* node, const std::string& word) {
    if (word.empty()) {
        node->is_word = true;
        return;
    }
    
    char c = tolower(word[0]); // convert character to lowercase
    int idx = c - 'a';
    if (!node->children[idx]) {
        node->children[idx] = new TrieNode();
    }
    insert_helper(node->children[idx], word.substr(1));
}

// Returns a vector of words that start with the given partial word
std::vector<std::string> Autocomplete::getSuggestions(const std::string& partialWord) const {
    std::vector<std::string> suggestions;
    TrieNode* node = find_node(partialWord);
    if (node) {
        get_suggestions_helper(node, suggestions, partialWord);
    }
    return suggestions;
}

// Returns the node that represents the given word, or null if the word is not in the Trie
TrieNode* Autocomplete::find_node(const std::string& word) const {
    TrieNode* node = root;
    for (char c : word) {
        int idx = tolower(c) - 'a'; // convert character to lowercase and get index in children array
        if (!node->children[idx]) {
            return nullptr; // word not in Trie
        }
        node = node->children[idx];
    }
    return node;
}

// Recursively adds words to the suggestions vector that start with the prefix represented by node
void Autocomplete::get_suggestions_helper(TrieNode* node, std::vector<std::string>& suggestions, std::string& prefix) const {
    if (node->is_word) {
        suggestions.push_back(prefix);
    }
    
    for (int i = 0; i < 26; i++) {
        if (node->children[i]) {
            prefix.push_back(i + 'a');
            get_suggestions_helper(node->children[i], suggestions, prefix);
            prefix.pop_back();
        }
    }
}








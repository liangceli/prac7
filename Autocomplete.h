#pragma once
#include <iostream>
#include <vector>
using namespace std;

struct TrieNode{
    bool isEndOfword;
    vector<TrieNode*> children;
    // 假设 Trie 树中只包含小写字母，那么我们可以使用一个固定大小为 26 的 children 数组来存储子节点，其中每个元素对应一个小写字母。由于小写字母的 ASCII 码值是连续的，我们可以通过将字符 c 减去字符 'a' 的 ASCII 码值来计算其在 children 数组中的索引。
    //例如，假设 c 是小写字母 'c'，那么 'c' - 'a' 的结果是整数 2，表示在 children 数组中，与字符 'c' 对应的子节点存储在数组的第 2 个位置上。
    //通过将字符转换为索引值，我们可以使用一个简单的数组来存储 Trie 树的子节点，这样就能够高效地插入和检索字符串。

    //每个节点的children数组的作用是存储从该节点开始，所有可能的子节点。

    TrieNode(){
        isEndOfword=false;
        children=vector<TrieNode*>(26, nullptr); //表示创建一个全都是TrieNode类型的vector，里面有26个，同时将他们都设置为空指针
    }
};

class Autocomplete{
    public:
    TrieNode* root; //建立root

    Autocomplete();
    vector<string> getSuggestions(string partialWord);  // return the known words that start with partialWord(输入的部分字母)
    void insert(string word); // add a word to the known words
    bool search_string(string s);
    void DFS(TrieNode* curr_node, string& temp, vector<string>& suggestions);
    //~Autocomplete();
};

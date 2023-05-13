#pragma once
#include <iostream>
#include <vector>
using namespace std;

class TrieNode{ //每个node代表一个单词的字母
    public:
    bool isEndOfWord; //判断这个node是不是一个单词的最后一个单词
    vector<TrieNode *> children; //一个指向 TrieNode 对象的指针的向量，用于存储从当前节点出发，可以到达的所有子节点。

    TrieNode();
    void set_bool(bool y_n);
    bool get_bool();
    void set_children(vector<TrieNode *> new_children);
    vector<TrieNode *> get_children(); //返回从此node往后的字符串
};
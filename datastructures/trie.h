#ifndef TRIE_H_INCLUDED
#define TRIE_H_INCLUDED

#include <vector>
#include <unordered_map>

struct TrieNode{
    bool isWord;
    std::unordered_map<char, TrieNode*> childrens;
};

TrieNode* newNode(){
    TrieNode* root = new TrieNode();
    root->isWord = false;
    return root;
}

void add(std::string& word, TrieNode* root){
    int word_len = word.length();

    TrieNode* itr_node = root;
    std::unordered_map<char, TrieNode*>::iterator itr;
    for(int i=0; i<word_len; i++){
        itr = itr_node->childrens.find(word[i]);
        if(itr==itr_node->childrens.end()){
            TrieNode* itr_new_node = newNode();
            itr_node->childrens[word[i]] = itr_new_node;
            itr_node = itr_new_node;
        }else{
            itr_node = itr->second;
        }
    }

    itr_node->isWord = true;
    return;
}

bool search(std::string& word, TrieNode* root){
    int word_len = word.length();

    TrieNode* itr_node = root;
    std::unordered_map<char, TrieNode*>::iterator itr;
    for(int i=0; i<word_len; i++){
        itr = itr_node->childrens.find(word[i]);
        if(itr==itr_node->childrens.end())
            return false;

        itr_node = itr->second;
    }

    return itr_node->isWord;
}

bool startsWith(std::string& word, TrieNode* root){
    int word_len = word.length();

    TrieNode* itr_node = root;
    std::unordered_map<char, TrieNode*>::iterator itr;
    for(int i=0; i<word_len; i++){
        itr = itr_node->childrens.find(word[i]);
        if(itr==itr_node->childrens.end())
            return false;

        itr_node = itr->second;
    }

    return true;
}

#endif // TRIE_H_INCLUDED
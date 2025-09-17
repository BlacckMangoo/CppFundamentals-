#ifndef HUFFMANENCODER_H
#define HUFFMANENCODER_H

#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
#include <string>
#include <memory>

struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}

    ~Node() {
        delete left;
        delete right;
    }
};

class HuffmanEncoder {
private:
    Node* root;
    std::map<char, std::string> codes;
    
    // Comparator for priority queue
    struct Compare {
        bool operator()(Node* a, Node* b) {
            return a->freq > b->freq;
        }
    };

public:
    HuffmanEncoder() : root(nullptr) {}
    
    ~HuffmanEncoder() {
        delete root;
    }
    
    void ConvertStringMap(const std::string& input, std::map<char, int>& map);
    void BuildTheTree(std::map<char, int> freqMap);
    void GenerateCodes(Node* root, std::map<char, std::string>& map, std::string code);
    void Encode(const std::string& input);
    void PrintCodes();
    Node* GetRoot() { return root; }
    std::map<char, std::string>& GetCodes() { return codes; }
};

#endif
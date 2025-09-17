#include "HuffmanEncoder.h"

void HuffmanEncoder::ConvertStringMap(const std::string& input, std::map<char, int>& map) {
    for (auto& c : input) {
        if (c == ' ') continue;
        map[c] += 1;
    }
}

void HuffmanEncoder::BuildTheTree(std::map<char, int> freqMap) {
    std::priority_queue<Node*, std::vector<Node*>, Compare> sortedNodes;

    for (auto& p : freqMap) {
        sortedNodes.push(new Node(p.first, p.second));
    }
    
    while (sortedNodes.size() > 1) {
        Node* left = sortedNodes.top();
        sortedNodes.pop();

        Node* right = sortedNodes.top();
        sortedNodes.pop();

        Node* parent = new Node('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        sortedNodes.push(parent);
    }
    
    if (!sortedNodes.empty()) {
        root = sortedNodes.top();
    }
}

void HuffmanEncoder::GenerateCodes(Node* root, std::map<char, std::string>& map, std::string code) {
    if (root->left == nullptr && root->right == nullptr) {
        map[root->ch] = code;
        return;
    }
    
    if (root->left) {
        GenerateCodes(root->left, map, code + "0");
    }
    
    if (root->right) {
        GenerateCodes(root->right, map, code + "1");
    }
}

void HuffmanEncoder::Encode(const std::string& input) {
    std::map<char, int> freqMap;
    ConvertStringMap(input, freqMap);
    BuildTheTree(freqMap);
    
    if (root) {
        GenerateCodes(root, codes, "");
    }
}

void HuffmanEncoder::PrintCodes() {
    for (auto& pair : codes) {
        std::cout << "'" << pair.first << "': " << pair.second << std::endl;
    }
}
#ifndef BST_H
#define BST_H

#include <string>
#include <iostream>

class BST {
private:
    struct Node {
        std::string key;
        int value;
        Node* left;
        Node* right;

        Node(const std::string& k, int v)
            : key(k), value(v), left(nullptr), right(nullptr) {}
    };

    Node* root = nullptr;

    Node* insert(Node* node, const std::string& key, int value) {
        if (!node) return new Node(key, value);
        if (key < node->key)
            node->left = insert(node->left, key, value);
        else if (key > node->key)
            node->right = insert(node->right, key, value);
        else
            node->value = value; 
        return node;
    }

    Node* find(Node* node, const std::string& key) const {
        if (!node) return nullptr;
        if (key == node->key) return node;
        if (key < node->key) return find(node->left, key);
        return find(node->right, key);
    }
    
    void clear(Node* node) {
        if (!node) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

public:
    ~BST() {
        clear(root);
    }

    void insert(const std::string& key, int value) {
        root = insert(root, key, value);
    }

    void changeValue(const std::string& key, int value) {
        Node* node = find(root, key);
        if (node) {
            node->value = value;
        }
    }

    bool variableExists(const std::string& key) const {
        return find(root, key) != nullptr;
    }

    int getValue(const std::string& key) const {
        Node* node = find(root, key);
        if (node) return node->value;
        std::cerr << "Error: variable '" << key << "' not found\n";
        return 0;
    }
};

#endif

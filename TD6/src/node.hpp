#pragma once
#include <iostream>  
#include <vector>   
#include <algorithm>

class Node {
public:
int value;
Node* left;
Node* right;

    // Constructeur
    Node(int val) : value{val}, left{nullptr}, right{nullptr} {}

    // Ajouter cette méthode
    bool is_leaf() const {
        return (left == nullptr && right == nullptr);
    }


    // Méthodes
    void insert(int value) {
        if (value < this->value) {
            if (left == nullptr) {
                left = new Node(value);
            } else {
                left->insert(value);
            }
        } else {
            if (right == nullptr) {
                right = new Node(value);
            } else {
                right->insert(value);
            }
        }
    }

    int height() const {
        int h_left = (left == nullptr) ? 0 : left->height();
        int h_right = (right == nullptr) ? 0 : right->height();
        return 1 + std::max(h_left, h_right);
    }

    void delete_childs() {
        if (left != nullptr) {
            left->delete_childs();
            delete left;
            left = nullptr;
        }
        if (right != nullptr) {
            right->delete_childs();
            delete right;
            right = nullptr;
        }
    }

    void display_infixe() const {
        if (left != nullptr) {
            left->display_infixe();
        }
        std::cout << value << " ";
        if (right != nullptr) {
            right->display_infixe();
        }
    }

    std::vector<Node const*> prefixe() const {
        std::vector<Node const*> result;
        result.push_back(this);
        if (left != nullptr) {
            auto left_result = left->prefixe();
            result.insert(result.end(), left_result.begin(), left_result.end());
        }
        if (right != nullptr) {
            auto right_result = right->prefixe();
            result.insert(result.end(), right_result.begin(), right_result.end());
        }
        return result;
    }
};

Node* create_node(int value);
Node*& most_left(Node*& node);
bool remove(Node*& node, int value);
void delete_tree(Node* node);

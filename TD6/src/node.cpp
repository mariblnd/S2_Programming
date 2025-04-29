
#include "node.hpp"

Node* create_node(int value) {
    return new Node(value);
}

Node*& most_left(Node*& node){
    if (node->left == nullptr) {
        return node;
    } else {
        return most_left(node->left);
    }
}

bool remove(Node*& node, int value){
    if (node == nullptr) {
        return false;
    }
    if (value < node->value) {
        return remove(node->left, value);
    } else if (value > node->value) {
        return remove(node->right, value);
    } else {
        if (node->is_leaf()) {
            delete node;
            node = nullptr;
        } else if (node->left == nullptr) {
            Node* temp = node;
            node = node->right;
            delete temp;
        } else if (node->right == nullptr) {
            Node* temp = node;
            node = node->left;
            delete temp;
        } else {
            Node*& most_left_node = most_left(node->right);
            node->value = most_left_node->value;
            remove(node->right, most_left_node->value);
        }
        return true;
    }
}

void delete_tree(Node* node){
    if (node) {
        delete_tree(node->left);
        delete_tree(node->right);
        delete node;
    }
}
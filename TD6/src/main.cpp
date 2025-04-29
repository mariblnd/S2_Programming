#include <iostream>
#include "node.hpp"

void pretty_print_left_right(Node const& node, std::string const& prefix, bool is_left) {
    if (node.right) {
        pretty_print_left_right(*node.right, prefix + (is_left ? "|   " : "    "), false);
    }
    std::cout << prefix << (is_left ? "+-- " : "+-- ") << node.value << std::endl;
    if (node.left) {
        pretty_print_left_right(*node.left, prefix + (is_left ? "    " : "|   "), true);
    }
}

void pretty_print_left_right(Node const& node) {
    pretty_print_left_right(node, "", true);
}

int main() {
    Node* root = new Node{5};
    
    // Insertion des valeurs
    root->left = new Node{3};
    root->right = new Node{7};
    
    root->left->left = new Node{2};
    root->left->right = new Node{4};
    
    root->right->left = new Node{6};
    root->right->right = new Node{8};
    
    root->left->left->left = new Node{1};
    root->left->left->left->left = new Node{0};
    
    root->right->right->right = new Node{9};

    // Affichage de l'arbre
    pretty_print_left_right(*root);

    std::cout << "\nParcours infixe : ";
    root->display_infixe();
    std::cout << std::endl;

     // Calcul de la somme en utilisant le parcours préfixe
     auto nodes = root->prefixe();
     int sum = 0;
     for (const Node* node : nodes) {
         sum += node->value;
     }
     std::cout << "Somme des valeurs : " << sum << std::endl;

     std::cout << "Hauteur de l'arbre : " << root->height() << std::endl;

    // Libération de la mémoire
    // Note: Dans un cas réel, il faudrait implémenter une fonction de nettoyage récursif
    delete root;

    return 0;
}
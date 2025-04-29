#include "graphe.hpp"
#include <iostream>

int main() {
    // 1. Créer une matrice d'adjacence d'entiers
    std::vector<std::vector<int>> adjacency_matrix = {
        {0, 1, 0, 0, 2},
        {0, 0, 2, 4, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 6},
        {0, 0, 0, 0, 0}
    };

    // 2. Créer un premier graphe à partir de la matrice
    Graph::WeightedGraph graph1 = Graph::adjacency_list_from_adjacency_matrix(adjacency_matrix);

    // 3. Créer un deuxième graphe manuellement
    Graph::WeightedGraph graph2;
    graph2.add_vertex(0);
    graph2.add_vertex(1);
    graph2.add_vertex(2);
    graph2.add_vertex(3);
    graph2.add_vertex(4);

    // ATTENTION : ici on utilise add_directed_edge car le graphe est orienté
    graph2.add_directed_edge(0, 1, 1.0f);
    graph2.add_directed_edge(0, 4, 2.0f);
    graph2.add_directed_edge(1, 2, 2.0f);
    graph2.add_directed_edge(1, 3, 4.0f);
    graph2.add_directed_edge(2, 3, 1.0f);
    graph2.add_directed_edge(3, 4, 6.0f);
    // Pas besoin d'ajouter des arêtes pour 4 car il n'y a pas d'arêtes sortantes depuis 4

    // 4. Comparer les deux graphes
    if (graph1 == graph2) {
        std::cout << "Les deux graphes sont égaux." << std::endl;
    } else {
        std::cout << "Les deux graphes sont différents." << std::endl;
    }

    return 0;
}

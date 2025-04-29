#include "graphe.hpp"

namespace Graph {

    void WeightedGraph::add_vertex(int const id) {
        if (adjacency_list.find(id) == adjacency_list.end()) {
            adjacency_list[id] = std::vector<WeightedGraphEdge>{};
        }
    }

    void WeightedGraph::add_directed_edge(int const from, int const to, float const weight) {
        add_vertex(from);
        add_vertex(to);
    
        adjacency_list[from].push_back(WeightedGraphEdge{to, weight});
    }

    void WeightedGraph::add_undirected_edge(int const from, int const to, float const weight) {
        add_directed_edge(from, to, weight);
        add_directed_edge(to, from, weight); 
    }

    WeightedGraph adjacency_list_from_adjacency_matrix(std::vector<std::vector<int>> const& adjacency_matrix) {
        WeightedGraph graph;
    
        int n = adjacency_matrix.size(); 
    
        for (int i = 0; i < n; ++i) {
            graph.add_vertex(i); 
        }
    
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < adjacency_matrix[i].size(); ++j) {
                int weight = adjacency_matrix[i][j];
                if (weight != 0) {
                    graph.add_directed_edge(i, j, static_cast<float>(weight));
                }
            }
        }
    
        return graph;
    }

    void WeightedGraph::print_DFS(int const start) const {
        std::unordered_map<int, bool> visited;
        std::vector<int> stack;
    
        stack.push_back(start);
    
        while (!stack.empty()) {
            int current = stack.back();
            stack.pop_back();
    
            if (visited.find(current) == visited.end()) {
                visited[current] = true;
                std::cout << current << " ";
    
                for (auto const& edge : adjacency_list.at(current)) {
                    if (visited.find(edge.to) == visited.end()) {
                        stack.push_back(edge.to);
                    }
                }
            }
        }
    }

    void WeightedGraph::print_BFS(int const start) const {
        std::unordered_map<int, bool> visited;
        std::vector<int> queue;
    
        queue.push_back(start);
    
        while (!queue.empty()) {
            int current = queue.front();
            queue.erase(queue.begin());
    
            if (visited.find(current) == visited.end()) {
                visited[current] = true;
                std::cout << current << " ";
    
                for (auto const& edge : adjacency_list.at(current)) {
                    if (visited.find(edge.to) == visited.end()) {
                        queue.push_back(edge.to);
                    }
                }
            }
        }
    }

    void WeightedGraph::DFS(int const start, std::function<void(int const)> const& callback) const {
        std::unordered_map<int, bool> visited;
        std::stack<int> stack;
        stack.push(start);
    
        while (!stack.empty()) {
            int current = stack.top();
            stack.pop();
    
            if (!visited[current]) {
                callback(current); 
                visited[current] = true;
    
                for (auto const& edge : adjacency_list.at(current)) {
                    if (!visited[edge.to]) {
                        stack.push(edge.to);
                    }
                }
            }
        }
    }
    

    

}
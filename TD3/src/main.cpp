#include <iostream>
#include <vector>

#include "tri.hpp"

bool is_sorted(std::vector<int> const& vec) { 
    return std::is_sorted(vec.begin(), vec.end()); 
}

int main() {
    std::vector<int> array {2, 1, 3, 4, 5, 6, 7, 8, 9} ;
    bubble_sort(array);

    if (is_sorted(array)) {
        std::cout << "Le tableau est trié" << std::endl;
    } else {
        std::cout << "Le tableau n'est pas trié" << std::endl;
    }

    return 0;
}
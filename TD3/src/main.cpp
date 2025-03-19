#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

#include "tri.hpp"
#include "ScopedTimer.hpp"

std::vector<int> generate_random_vector(size_t const size, int const max = 100) {
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
}

std::vector<float> generate_random_vector_float(size_t const size, int const max = 100) {
    std::vector<float> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
}

bool is_sorted(std::vector<float> const& vec) { 
    return std::is_sorted(vec.begin(), vec.end()); 
}

bool is_sorted(std::vector<int> const& vec) { 
    return std::is_sorted(vec.begin(), vec.end()); 
}

int search(std::vector<int> const& vec, int const value) {
    int left = 0;
    int right = vec.size() - 1;

    while (left <= right) {
        int middle = (left + right) / 2;
        if (vec[middle] == value) {
            return middle;
        } else if (vec[middle] < value) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    return -1;
}

int main() {

    std::vector<int> array_int {2, 1, 3, 4, 5, 6, 7, 8, 9};
    std::vector<float> array_float {2.0, 1.0, 3.0, 4.0, 5, 6.0, 7.0, 8.0, 9.0} ;

    // EXERCICE 1

    bubble_sort(array_int);

    if (is_sorted(array_int)) {
        std::cout << "Le tableau est trié" << std::endl;
    } else {
        std::cout << "Le tableau n'est pas trié" << std::endl;
    }

    //EXERCICE 2

    quick_sort(array_float);

    if (is_sorted(array_float)) {
        std::cout << "Le tableau est trié" << std::endl;
    } else {
        std::cout << "Le tableau n'est pas trié" << std::endl;
    }

    //EXERCICE 3

    {
        ScopedTimer timer("nom du chronomètre");
        std::vector<int> vec = generate_random_vector(1000);
        bubble_sort(vec);
    }
    {
        ScopedTimer timer("nom du chronomètre");
        std::vector<float> vec = generate_random_vector_float(1000);
        quick_sort(vec);
    }

    // EXERCICE 4
    array_int = {1, 2, 2, 3, 4, 8, 12};
    std::cout << search(array_int, 8) << std::endl;

    array_int = {1, 2, 3, 3, 6, 14, 12, 15};
    std::cout << search(array_int, 15) << std::endl;

    array_int = {2, 2, 3, 4, 5, 8, 12, 15, 16};
    std::cout << search(array_int, 16) << std::endl;

    array_int = {5, 6, 7, 8, 9, 10, 11, 12, 13};
    std::cout << search(array_int, 6) << std::endl;

    array_int = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << search(array_int, 10) << std::endl;
    


    return 0;
}

//L'algorithme le plus performant est le quick_sort (Tri Rapide) car il a une complexité en O(n log n) alors que le bubble_sort a une complexité en O(n^2) ce qui le rend beaucoup plus lent.
//Le quick_sort est plus performant car il divise le tableau en deux parties et trie ces deux parties de manière récursive. Il est plus rapide car il ne compare pas tous les éléments entre eux.
//Le bubble_sort compare tous les éléments entre eux et les échange si besoin. Il est donc beaucoup plus lent que le quick_sort.
#include <iostream>
#include <vector>
#include <algorithm>

#include "tri.hpp"

void bubble_sort(std::vector<int> & vec){
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec.size() - 1; j++) {
            if (vec[j] > vec[j + 1]) {
                int temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
    }
}
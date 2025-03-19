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


size_t quick_sort_partition(std::vector<float> & vec, size_t left, size_t right, size_t const pivot) {
    float pivotValue = vec[pivot];
    std::swap(vec[pivot], vec[right]);
    size_t storeIndex = left;
    for (size_t i = left; i < right; i++) {
        if (vec[i] < pivotValue) {
            std::swap(vec[i], vec[storeIndex]);
            storeIndex++;
        }
    }
    std::swap(vec[storeIndex], vec[right]);
    return storeIndex;
}

void quick_sort(std::vector<float> & vec, size_t const left, size_t const right) {
    if (right > left) {
        size_t pivot = left + (right - left) / 2;
        pivot = quick_sort_partition(vec, left, right, pivot);
        if (pivot != 0) {
            quick_sort(vec, left, pivot - 1);
        }
        quick_sort(vec, pivot + 1, right);
    }
}

void quick_sort(std::vector<float> & vec) {
    quick_sort(vec, 0, vec.size() - 1);
}


// void merge_sort_merge(std::vector<float> & vec, size_t const left, size_t const middle, size_t const right){
//     std::vector<float> leftPart(vec.begin() + left, vec.begin() + middle + 1);
//     std::vector<float> rightPart(vec.begin() + middle + 1, vec.begin() + right + 1);
//     size_t leftIndex = 0;
//     size_t rightIndex = 0;
//     for (size_t i = left; i <= right; i++) {
//         if (leftIndex < leftPart.size() && rightIndex < rightPart.size()) {
//             if (leftPart[leftIndex] < rightPart[rightIndex]) {
//                 vec[i] = leftPart[leftIndex];
//                 leftIndex++;
//             } else {
//                 vec[i] = rightPart[rightIndex];
//                 rightIndex++;
//             }
//         } else if (leftIndex < leftPart.size()) {
//             vec[i] = leftPart[leftIndex];
//             leftIndex++;
//         } else if (rightIndex < rightPart.size()) {
//             vec[i] = rightPart[rightIndex];
//             rightIndex++;
//         }
//     }
// }

// void merge_sort(std::vector<float> & vec, size_t const left, size_t const right){
//     if (left < right) {
//         size_t middle = left + (right - left) / 2;
//         merge_sort(vec, left, middle);
//         merge_sort(vec, middle + 1, right);
//         merge_sort_merge(vec, left, middle, right);
//     }
// }
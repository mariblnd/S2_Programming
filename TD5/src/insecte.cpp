#include <iostream>
#include <functional>
#include <random>
#include <vector>
#include <algorithm>
#include <iterator>

#include "insecte.hpp"

std::vector<std::pair<Insect, int>> get_insect_observations(
    const size_t number_of_observations,
    std::vector<float> const& insect_probabilities,
    const unsigned int seed) {
    // Create a random engine with a given seed
    std::default_random_engine random_engine(seed);

    auto randInsectIndex { std::bind(std::discrete_distribution<size_t>{insect_probabilities.begin(), insect_probabilities.end()}, random_engine) };
    
    std::vector<std::pair<Insect, int>> observations {};
    observations.reserve(number_of_observations);

    for(size_t i {0}; i < number_of_observations; ++i) {
        size_t const random_insect_index { randInsectIndex() };
        Insect const random_insect { insect_values[random_insect_index] };
        
        //If we have already seen the same insect, increment the count on the last observation
        auto& previous_observation { observations.back() };
        if(previous_observation.first == random_insect) {
            previous_observation.second++;
            i -= 1;
        } else {
            observations.push_back({random_insect, 1});
        }
    }

    return observations;
}

std::vector<float> probabilities_from_count(std::vector<int> const& counts){
    std::vector<float> probabilities {};
    int somme {0};
    
    for(auto count : counts) {
        somme += count;
    }

    for(auto count : counts) {
        probabilities.push_back(static_cast<float>(count) / somme);
    }

    return probabilities;
}

std::string bonne_probabilite(float souhaite, float observe) {
    return (std::abs(souhaite - observe) <= 0.01) ? "OK" : "BAD";
}


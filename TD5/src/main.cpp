#include "iostream"
#include "string"
#include "vector"
#include "random"
#include "iomanip"
#include "unordered_map"

#include "hachage.hpp"
#include "insecte.hpp"
#include "card.hpp"

int main () {

    //EXERCICE 1

    // std::string s1 = "Guimiel";
    // std::string s2 = "Guimile";

    // std::cout << "Hash de " << s1 << " : " << folding_string_hash(s1, 100) << std::endl;
    // std::cout << "Hash de " << s1 << " : " << folding_string_ordered_hash(s1, 100) << std::endl;
    // std::cout << "Hash de " << s1 << " : " << polynomial_rolling_hash(s1, 31, 100) << std::endl;

    // std::cout << "Hash de " << s2 << " : " << folding_string_hash(s2, 100) << std::endl;
    // std::cout << "Hash de " << s2 << " : " << folding_string_ordered_hash(s2, 100) << std::endl;
    // std::cout << "Hash de " << s2 << " : " << polynomial_rolling_hash(s2, 31, 100) << std::endl;

    
    
    // EXERCICEE 2

    // std::vector<std::pair<Insect, int>> liste;
    // liste = get_insect_observations(10000, probabilities_from_count(expected_insect_counts), 42);

    // // Associer un int (nb total d'observation) à un insecte
    // std::unordered_map<Insect, int> compter_insecte;

    // for (auto& observation : liste) {
    //     //La clé de l'insecte
    //     auto& insecte = observation.first;
    //     // Le nombre
    //     auto& count = observation.second;

    //     // Si la clé de l'insecte n'est pas encore dans la map, on l'ajoute
    //     // Sinon, on incrémente le nombre d'observation
    //     if (compter_insecte.find(insecte) == compter_insecte.end()) {
    //         compter_insecte[insecte] = count;
    //     } else {
    //         compter_insecte[insecte] += count;
    //     }
    // }
    // std::cout << "Insectes observés : " << std::endl;
    // for (auto& insecte : compter_insecte) {
    //     std::cout << insect_to_string.at(insecte.first) << " : " << insecte.second << std::endl;
    // }
    // std::cout << std::endl;

    // std::vector<int> counts {};
    // for (auto& insecte : compter_insecte) {
    //     counts.push_back(insecte.second);
    // }

    // std::vector<float> probabilite = probabilities_from_count(counts);
    
    // //COMPARER

    // for(size_t i = 0; i < probabilite.size(); ++i) {
    //     float observe = probabilite[i];
    //     float souhaite = probabilities_from_count(expected_insect_counts)[i];

    //     std::string resultat = bonne_probabilite(souhaite, observe);

    //     std::cout << insect_to_string.at(insect_values[i]) << " : " << std::fixed << std::setprecision(3) << observe << "  VS  " << souhaite << "   " << resultat <<  std::endl;
    // }


    // return 0;


    // EXERCICE 3

    std::vector<Card> cards = get_cards(100);

    std::unordered_map<Card, int> compter_cartes;

    for(auto& card : cards ){
        auto& count = compter_cartes[card];
        if (count == 0) {
            count = 1;
        } else {
            count += 1;
        } 
    }

    std::cout << "Cartes observées : " << std::endl;                
    for (auto& card : compter_cartes) {
        card_name(card.first);
        std::cout << card_name(card.first) << " : " << card.second << std::endl;
    }
    std::cout << std::endl;


    return 0;
}
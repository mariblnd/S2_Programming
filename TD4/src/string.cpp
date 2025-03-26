#include <iostream>
#include <vector>

#include "string.hpp"

int nombre_de_caracteres(const std::string &s){
    auto espace {std::find(s.begin(), s.end(), ' ')};
    return std::distance(s.begin(), espace);
}

std::vector<std::string> split_string(std::string const& str){
    std::vector<std::string> resultat;
    std::string reste = str;
    
    while(reste.size() > 0){
        int nb_caracteres {nombre_de_caracteres(reste)};
        resultat.push_back(reste.substr(0, nb_caracteres));
        
        if(nb_caracteres < reste.size()){
            reste = reste.substr(nb_caracteres + 1);
        } else {
            reste = "";
        } 
    }
    
    return resultat;
}
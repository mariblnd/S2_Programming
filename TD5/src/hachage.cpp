#include <iostream>
#include <string>

#include "hachage.hpp"

size_t folding_string_hash(std::string const& s, size_t max){
    size_t hash = 0;
    for( char c : s){
        hash += static_cast<size_t>(c);
    }
    return hash % max;
}

size_t folding_string_ordered_hash(std::string const& s, size_t max){
    size_t hash = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        hash += static_cast<size_t>(s[i]) * (i + 1);
    }
    return hash % max;
}

size_t polynomial_rolling_hash(const std::string& s, size_t p, size_t max){
    size_t hash = 0;
    int power = 1;
    for (size_t i = 0; i < s.size(); i++)
    {
        power *= p;
        hash += (static_cast<size_t>(s[i]) * power);
    }
    
    return hash % max;

}
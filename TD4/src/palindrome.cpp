#include <iostream>
#include <vector>

#include "palindrome.hpp"

bool is_palindrome(const std::string &s){


    std::string reverse;

    for(auto it = s.rbegin(); it != s.rend(); ++it) {
        reverse.push_back(*it);
    }

    if(std::equal(s.begin(), s.end(), reverse.begin(), reverse.end())) {
        return true;
    } else {
        return false;
    }

}
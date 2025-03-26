#include "iostream"
#include "vector"
#include "random"


#include "string.hpp"
#include "palindrome.hpp"

int main () {
    
    // EXERRCICE 1

    // std::vector<int> array(10);

    // for (size_t i = 0; i < array.size(); i++)
    // {
    //     array[i] = rand() % 100;
    // }

    // for(std::vector<int>::iterator it = array.begin(); it != array.end(); ++it) {
    //     std::cout << *it << std::endl;
    // }

    // auto it { std::find(array.begin(), array.end(), 3) };

    // if(it != array.end()) {
    //     std::cout << *it << std::endl;
    // } else {
    //     std::cout << "Absent" << std::endl;
    // }

    // auto occurence { std::count(array.begin(), array.end(), 5)};

    // if(occurence != 0) {
    //     std::cout << "Occurence : " << occurence << std::endl;
    // } else {
    //     std::cout << "Il n'y en a pas" << std::endl;
    // }

    // std::sort(array.begin(), array.end());

    // int somme {std::accumulate(array.begin(), array.end(), 0)};
    // std::cout << "Somme : " << somme << std::endl;


//////////////////////////////////////////////////////////////////////////////////////

    // EXERCICE 2

    // std::string phrase {"Je suis en IMAC"};
    // std::vector<std::string> mots {split_string(phrase)};
    // for(std::vector<std::string>::iterator it = mots.begin(); it != mots.end(); ++it) {
    //     std::cout << *it << std::endl;
    // }



//////////////////////////////////////////////////////////////////////////////////////



    // EXERCICE 3
    std::string mot {"kayak"};
    std::cout << is_palindrome(mot) << std::endl;
    
    return 0;
}
#include <iostream>
#include <sstream>
#include <string>
#include <iterator>
#include <vector>
#include  <cctype>
#include <stack>

#include "npi.hpp"

std::vector<std::string> split_string(std::string const& s)
{
    std::istringstream in(s); // transforme une chaîne en flux de caractères, cela simule un flux comme l'est std::cin
    // l’itérateur va lire chaque element de "in", comme un flux d'entrée, chaque élément est séparé par un espace
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>()); 
}

// bool is_floating(std::string const& s){
    
//     bool isAFloat;

//     for (char c : s) 
//     {
//         if(std::isdigit(static_cast<unsigned char>(c)))
//         {
//            isAFloat = true;

//         } else if (c == '.') 
//         {
//             isAFloat = true;
//         } else 
//         {
//             isAFloat = false;
//         }
//     }

//     return isAFloat;

// }


// float npi_evaluate(std::vector<std::string> const& tokens){
    
//     std::stack<float> stack;

//     for (size_t i = 0; i < tokens.size(); i++)
//     {
//         if(is_floating(tokens[i]))
//         {
//             float num = std::stof(tokens[i]);
//             stack.push(num);
//         } 
//         else 
//         {
//             float rightOperand = stack.top();
//             stack.pop();
//             float leftOperand = stack.top();
//             stack.pop();

//             float result = 0.0f;

//             if(tokens[i]=="+")
//             {
//                 result = leftOperand+rightOperand;
//             }
//             else if(tokens[i]=="-")
//             {
//                 result = leftOperand-rightOperand;
//             }
//             else if(tokens[i]=="*")
//             {
//                 result = leftOperand*rightOperand;
//             }
//             else
//             {
//                 result = leftOperand/rightOperand;
//             }

//             stack.push(result);
                
//         }
//     }

//     return stack.top();
    
    
// }


int main(){

    std::string userInput;
    
    std::cout<< "Saisissez une expression arithmétique en notation polonaise inversée :" <<std::endl;
    std::getline(std::cin, userInput);
    
    std::vector<std::string> caractere(split_string(userInput));

    std::vector<Token> tokens = tokenize(caractere);

    float result = npi_evaluate(tokens);

    std::cout<<result<<std::endl;

    return 0;
}

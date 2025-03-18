#include "npi.hpp"

#include <iostream> 
#include <stack>
#include <cmath>

Token make_token(float value){
    
    Token element;

    element.type = TokenType::OPERAND;
    element.value = value;

    return element;

}

Token make_token(Operator op){
    
    Token element;

    element.type = TokenType::OPERATOR;
    element.op = op;
    element.value = NAN;

    return element;
    

}


std::vector<Token> tokenize(std::vector<std::string> const& words){

    std::vector<Token> stack;

    for (size_t i = 0; i < words.size(); i++)
    {   
        Token element;

            if(words[i] == "+")
            {
                element = make_token(Operator::ADD);
            } 
            else if (words[i] == "-")
            {
                element = make_token(Operator::SUB);
            }
            else if (words[i] == "*")
            {
                element = make_token(Operator::MUL); 
            }
            else if (words[i] == "/") 
            {
                element = make_token(Operator::DIV);
            } else 
            {
                float number = std::stof(words[i]);
                element = make_token(number);
            }

            stack.push_back(element);
        }

        return stack;     
}

float npi_evaluate(std::vector<Token> const& tokens){

    std::stack<float> stack;

    for (size_t i = 0; i < tokens.size(); i++)
    {
        if(tokens[i].type == TokenType::OPERAND)
        {
            stack.push(tokens[i].value);
        }
        else
        {
            float rightOperand = stack.top();
            stack.pop();
            float leftOperand = stack.top();
            stack.pop();

            float result = 0.0f;

            if(tokens[i].op == Operator::ADD)
            {
                result = leftOperand+rightOperand;
            }
            else if(tokens[i].op == Operator::SUB)
            {
                result = leftOperand-rightOperand;
            }
            else if(tokens[i].op == Operator::MUL)
            {
                result = leftOperand*rightOperand;
            }
            else 
            {
                result = leftOperand/rightOperand;
            }

            stack.push(result);
        }  
    }

    return stack.top();
    
}
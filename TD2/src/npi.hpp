#pragma once

#include <iostream>
#include <vector>

enum class Operator { ADD, SUB, MUL, DIV};

enum class TokenType { OPERATOR, OPERAND };

struct Token {
  TokenType type;
  float value;
  Operator op;
};

Token make_token(float value);
Token make_token(Operator op);

std::vector<Token> tokenize(std::vector<std::string> const& words);

float npi_evaluate(std::vector<Token> const& tokens);
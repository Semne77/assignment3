#pragma once
// The #pragma once directive ensures that the header file is included only once during compilation.
// This prevents multiple inclusions and potential compilation errors.

#include <iostream>
#include <stack>
#include <string>

// Function to check if a character is an operator (+, -, *, /, %)
bool isOperator(char c);

// Function to check if a character is a parenthesis (, ), {, }, [, ]
bool isParenthesis(char c);

// Function to check if a character is an integer digit (0-9)
bool isInt(char c);

// Function to check if a character is a valid part of the expression
bool checkString(char c);

// Function to determine the precedence of an operator
int getPrecedence(char op);

// Function to check if the precedence of op1 is higher than or equal to op2
bool isHigherPrecedence(char op1, char op2);

// Function to convert an infix expression to postfix notation
std::string infixToPostfix(const std::string& infix);

// Function to check if parentheses in the expression are balanced
bool isBalancedParentheses(const std::string& expression);
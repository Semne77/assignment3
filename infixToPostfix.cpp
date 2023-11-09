#include "infixToPostfix.h" // Include the necessary header file

// Function to check if a character is an operator (+, -, *, /, %)
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}

// Function to check if a character is a parenthesis (, ), {, }, [, ]
bool isParenthesis(char c) {
    return c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']';
}

// Function to check if a character is an integer digit (0-9)
bool isInt(char c) {
    return (c >= '0' && c <= '9');
}

// Function to check if a character is a valid part of the expression
bool checkString(char c) {
    return isOperator(c) || isParenthesis(c) || isInt(c);
}

// Function to determine the precedence of an operator
int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/' || op == '%')
        return 2;
    return 0;
}

// Function to check if the precedence of op1 is higher than or equal to op2
bool isHigherPrecedence(char op1, char op2) {
    return getPrecedence(op1) >= getPrecedence(op2);
}

// Function to convert an infix expression to postfix notation
std::string infixToPostfix(const std::string& infix) {
    std::string postfix; // Output string in postfix notation
    std::stack<char> operators; // Stack to store operators during conversion

    // Iterate through each character in the infix expression
    for (char c : infix) {
        if (checkString(c)) {
            if (!isParenthesis(c)) {
                if (isOperator(c)) {
                    // Process operators and handle precedence
                    while (!operators.empty() && operators.top() != '(' && isHigherPrecedence(operators.top(), c)) {
                        postfix += operators.top();
                        operators.pop();
                    }
                    operators.push(c); // Push the current operator onto the stack
                } else {
                    postfix += c; // Append operands directly to the postfix expression
                }
            } else if (c == '(') {
                operators.push(c); // Push opening parenthesis onto the stack
            } else if (c == ')') {
                // Process closing parenthesis and pop operators until an opening parenthesis is encountered
                while (!operators.empty() && operators.top() != '(') {
                    postfix += operators.top();
                    operators.pop();
                }
                if (!operators.empty() && operators.top() == '(')
                    operators.pop(); // Pop the opening parenthesis
                else
                    return "Invalid expression";
            }
        } else {
            return "Invalid expression"; // Invalid character in the expression
        }
    }

    // Process any remaining operators on the stack
    while (!operators.empty()) {
        if (isParenthesis(operators.top()))
            return "Invalid expression"; // Unmatched parenthesis on the stack
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

// Function to check if parentheses in the expression are balanced
bool isBalancedParentheses(const std::string& expression) {
    std::stack<char> parentheses; // Stack to store opening parentheses

    // Iterate through each character in the expression
    for (char c : expression) {
        if (c == '(' || c == '{' || c == '[') {
            parentheses.push(c); // Push opening parenthesis onto the stack
        } else if (c == ')' || c == '}' || c == ']') {
            if (parentheses.empty())
                return false; // Unmatched closing parenthesis
            char top = parentheses.top();
            // Check if the closing parenthesis matches the top of the stack
            if ((c == ')' && top == '(') || (c == '}' && top == '{') || (c == ']' && top == '[')) {
                parentheses.pop(); // Pop the matched opening parenthesis
            } else {
                return false; // Mismatched parentheses
            }
        }
    }

    return parentheses.empty(); // Expression is balanced if the stack is empty
}

// Main function to take user input and execute the expression conversion
int main() {
    std::string infixExpression;
    std::cout << "Enter an infix expression: ";
    std::getline(std::cin, infixExpression);

    if (isBalancedParentheses(infixExpression)) {
        std::string postfixExpression = infixToPostfix(infixExpression);
        if (postfixExpression == "Invalid expression") {
            std::cout << "Invalid expression" << std::endl;
        } else {
            std::cout << "Postfix expression: " << postfixExpression << std::endl;
        }
    } else {
        std::cout << "Invalid expression (unbalanced parentheses)" << std::endl;
    }

    return 0;
}
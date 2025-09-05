#include <iostream>
#include <stack>
#include <cctype>  // for isalnum
using namespace std;
// Function to return precedence of operators
int precedence(char op) {
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}
// Function to check associativity (only ^ is right-associative)
bool isRightAssociative(char op) {
    return (op == '^');
}
// Function to convert Infix -> Postfix
string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";

    for(char c : infix) {
        if(isalnum(c)) {
            // Operand → directly add to postfix
            postfix += c;
        }
        else if(c == '(') {
            st.push(c);
        }
        else if(c == ')') {
            // Pop until '(' is found
            while(!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop(); // remove '('
        }
        else {
            // Operator
            while(!st.empty() && precedence(st.top()) > precedence(c) ||
                 (!st.empty() && precedence(st.top()) == precedence(c) && !isRightAssociative(c))) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    // Pop remaining operators
    while(!st.empty()) {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}
int main() {
    string infix;
    cout << "Enter Infix Expression: ";
    cin >> infix;
    string postfix = infixToPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}



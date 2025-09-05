// #include <iostream>
// #include <stack>
// #include <cctype>  // for isalnum
// using namespace std;
// // Function to return precedence of operators
// int precedence(char op) {  // Higher value means higher precedence, returns precedence level of operator
//     if(op == '^') return 3;
//     if(op == '*' || op == '/') return 2;
//     if(op == '+' || op == '-') return 1;
//     else return -1; // for non-operators
//     return 0; 
// }
// // Function to check associativity (only ^ is right-associative)
// bool isRightAssociative(char op) {
//     return (op == '^');
// }
// // Function to convert Infix -> Postfix
// string infixToPostfix(string infix) {
//     stack<char> st;
//     string postfix = "";

//     for(char c : infix) {
//         if(isalnum(c)) {
//             // Operand → directly add to postfix
//             postfix += c;
//         }
//         else if(c == '(') {
//             st.push(c);
//         }
//         else if(c == ')') {
//             // Pop until '(' is found
//             while(!st.empty() && st.top() != '(') {
//                 postfix += st.top();
//                 st.pop();
//             }
//             st.pop(); // remove '('
//         }
//         else {
//             // Operator
//             while(!st.empty() && precedence(st.top()) > precedence(c) ||
//                  (!st.empty() && precedence(st.top()) == precedence(c) && !isRightAssociative(c))) {
//                 postfix += st.top();
//                 st.pop();
//             }
//             st.push(c);
//         }
//     }
//     // Pop remaining operators
//     while(!st.empty()) {
//         postfix += st.top();
//         st.pop();
//     }
//     return postfix;
// }
// int main() {
//     string infix;
//     cout << "Enter Infix Expression: ";
//     cin >> infix;
//     string postfix = infixToPostfix(infix);
//     cout << "Postfix Expression: " << postfix << endl;

//     return 0;
// }



#include <iostream>
#include <stack>
using namespace std;

int prec(char c) {
    if(c == '^') return 3;
    if(c == '*' || c == '/') return 2;
    if(c == '+' || c == '-') return 1;
    else return -1;
}

string infixToPostfix(string s) {
    stack<char> st;
    string res;

    for(int i=0;i<s.length();i++) {
        if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z' || s[i]>='0' && s[i]<='9') {
            res += s[i];
        }
        else if(s[i] == '(') {
            st.push(s[i]);
        }
        else if(s[i] == ')') {
            while(!st.empty() && st.top() != '(') {
                res += st.top();
                st.pop();
            }
            if(!st.empty()) st.pop();
        }
        else {
            while(!st.empty() && prec(st.top()) > prec(s[i]) || 
                 (!st.empty() && prec(st.top()) == prec(s[i]) && s[i] != '^')) {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()) {
        res += st.top();
        st.pop();
    }
    return res;
}

int main(){
    string s;
    cout<<"Enter Infix Expression : ";
    getline(cin, s);

    string result = infixToPostfix(s);
    cout<<"Postfix Expression is : "<<result<<endl;

    return 0;
}

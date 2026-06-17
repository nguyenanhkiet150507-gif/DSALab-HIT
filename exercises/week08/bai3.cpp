#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

// Hàm l?y ?? ?u tiên toán t?
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// 1. Chuy?n ??i t? Infix sang Postfix (H?u t?) kèm in t?ng b??c
string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";
    cout << "\n--- TI?N TRÌNH BI?N ??I INFIX -> POSTFIX ---\n";

    for (char ch : infix) {
        if (isalnum(ch)) {
            postfix += ch;
        }
        else if (ch == '(') {
            s.push(ch);
        }
        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty()) s.pop(); // B? d?u '('
        }
        else { // Toán t? +, -, *, /, ^
            while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
                // S?a l?i chính xác: N?u là toán t? '^' (Ph?i qua trái) thì không pop toán t? '^' c? ra tr??c
                if (ch == '^' && s.top() == '^') break;
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }

        // In tr?ng thái t?ng b??c
        cout << "Ký t?: " << ch << " | Stack: ";
        stack<char> temp = s;
        string st_str = "";
        while (!temp.empty()) { st_str = temp.top() + st_str; temp.pop(); }
        cout << st_str << " \t| Bi?u th?c Postfix: " << postfix << endl;
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

// 2. Chuy?n ??i t? Infix sang Prefix (Ti?n t?)
string infixToPrefix(string infix) {
    // B??c a: ??o ng??c chu?i infix
    reverse(infix.begin(), infix.end());

    // B??c b: ??i ngo?c trái thành ngo?c ph?i và ng??c l?i
    for (size_t i = 0; i < infix.length(); i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    // B??c c: Áp d?ng thu?t toán Postfix bi?n th? (toán t? cùng ?u tiên không pop ra ??i v?i quy trình ??o)
    stack<char> s;
    string prefix = "";

    for (char ch : infix) {
        if (isalnum(ch)) {
            prefix += ch;
        }
        else if (ch == '(') {
            s.push(ch);
        }
        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                prefix += s.top();
                s.pop();
            }
            if (!s.empty()) s.pop();
        }
        else {
            while (!s.empty() && precedence(s.top()) > precedence(ch)) {
                prefix += s.top();
                s.pop();
            }
            // X? lý riêng cho l?y th?a khi b? ??o ng??c chu?i
            if (!s.empty() && precedence(s.top()) == precedence(ch) && ch != '^') {
                prefix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }
    while (!s.empty()) {
        prefix += s.top();
        s.pop();
    }

    // B??c d: ??o ng??c k?t qu? m?t l?n n?a ?? ra Prefix chu?n
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int main() {
    string expr = "(A+B)*C-D^E^F";
    cout << "Bi?u th?c g?c (Infix): " << expr << endl;

    string post = infixToPostfix(expr);
    cout << "=> K?t qu? Postfix: " << post << endl;

    string pre = infixToPrefix(expr);
    cout << "=> K?t qu? Prefix: " << pre << endl;

    return 0;
}
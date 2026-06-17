#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include <vector>
#include <cctype>

using namespace std;

bool isOp(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int opPrecedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Tách chu?i thô thành m?ng các Token riêng bi?t (S? th?p phân và ký hi?u toán t?)
vector<string> parseTokens(const string& expr) {
    vector<string> tokens;
    string numBuffer = "";

    for (size_t i = 0; i < expr.length(); i++) {
        char c = expr[i];
        if (isspace(c)) continue;

        if (isdigit(c) || c == '.') {
            numBuffer += c; // Ghép các ch? s? và d?u ch?m ??ng liên ti?p
        }
        else {
            if (!numBuffer.empty()) {
                tokens.push_back(numBuffer);
                numBuffer = "";
            }
            string opToken(1, c);
            tokens.push_back(opToken);
        }
    }
    if (!numBuffer.empty()) {
        tokens.push_back(numBuffer);
    }
    return tokens;
}

// Chuy?n chu?i Token Infix sang Token Postfix
vector<string> tokensToPostfix(const vector<string>& tokens) {
    vector<string> postfix;
    stack<string> s;

    for (const string& token : tokens) {
        if (isdigit(token[0]) || (token.size() > 1 && token[0] == '.')) {
            postfix.push_back(token);
        }
        else if (token == "(") {
            s.push(token);
        }
        else if (token == ")") {
            while (!s.empty() && s.top() != "(") {
                postfix.push_back(s.top());
                s.pop();
            }
            if (!s.empty()) s.pop();
        }
        else if (isOp(token[0])) {
            while (!s.empty() && opPrecedence(s.top()[0]) >= opPrecedence(token[0])) {
                if (token == "^" && s.top() == "^") break; // Right-to-left
                postfix.push_back(s.top());
                s.pop();
            }
            s.push(token);
        }
    }
    while (!s.empty()) {
        postfix.push_back(s.top());
        s.pop();
    }
    return postfix;
}

// In tr?ng thái Stack s? th?c ra màn hình
void displayStackState(stack<double> s) {
    vector<double> elements;
    while (!s.empty()) {
        elements.push_back(s.top());
        s.pop();
    }
    cout << "[";
    for (int i = elements.size() - 1; i >= 0; i--) {
        cout << elements[i];
        if (i > 0) cout << ", ";
    }
    cout << "]\n";
}

// Duy?t Postfix và th?c hi?n tính toán trên Stack s? th?c
double computePostfix(const vector<string>& postfixTokens) {
    stack<double> s;
    cout << "\nB??c 2 — Tính toán:\n";

    for (const string& token : postfixTokens) {
        if (isdigit(token[0]) || (token.size() > 1 && token[0] == '.')) {
            double val = stod(token);
            s.push(val);
            cout << "  Push " << val << " \t? Stack: ";
            displayStackState(s);
        }
        else if (isOp(token[0])) {
            double val2 = s.top(); s.pop();
            double val1 = s.top(); s.pop();
            double res = 0;

            switch (token[0]) {
            case '+': res = val1 + val2; break;
            case '-': res = val1 - val2; break;
            case '*': res = val1 * val2; break;
            case '/': res = val1 / val2; break;
            case '^': res = pow(val1, val2); break;
            }
            s.push(res);
            cout << "  '" << token << "' ? Pop " << val2 << ", Pop " << val1 << " ? Push " << res << " \t? Stack: ";
            displayStackState(s);
        }
    }
    return s.top();
}

int main() {
    cout << "=== ?? MÁY TÍNH BI?U TH?C ===\n";
    string expression = "(3.5 + 4.5) * 2 - 8 / 4";
    cout << "Nh?p bi?u th?c m?c ??nh: " << expression << "\n";

    vector<string> tokens = parseTokens(expression);
    vector<string> postfix = tokensToPostfix(tokens);

    cout << "\nB??c 1 — Chuy?n sang Postfix: ";
    for (const string& t : postfix) {
        cout << t << " ";
    }
    cout << endl;

    double result = computePostfix(postfix);
    cout << "\n? K?t qu? cu?i cùng: " << expression << " = " << result << endl;

    return 0;
}
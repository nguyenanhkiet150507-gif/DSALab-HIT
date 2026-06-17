#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValidBrackets(const string& code) {
    stack<char> s;

    for (char ch : code) {
        // N?u g?p ngo?c m? thì ??y vào stack
        if (ch == '(' || ch == '[' || ch == '{') {
            s.push(ch);
        }
        // N?u g?p ngo?c ?óng thì ki?m tra s? t??ng thích
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (s.empty()) return false; // Th?a d?u ngo?c ?óng

            char open = s.top();
            if ((ch == ')' && open == '(') ||
                (ch == ']' && open == '[') ||
                (ch == '}' && open == '{')) {
                s.pop(); // Kh?p c?p, xóa ngo?c m? t??ng ?ng ra kh?i stack
            }
            else {
                return false; // Sai th? t? ?óng m? l?ng nhau
            }
        }
    }
    return s.empty(); // Stack r?ng ??ng ngh?a m?i d?u ngo?c ??u ???c ghép ?ôi chu?n xác
}

int main() {
    // Chu?i code th?c t? gi? l?p
    string validCode = "if (arr[i] == static_cast<int>(val)) { out.print(\"Done\"); }";
    string invalidCode = "void main() { int x = (5 + 3]; }"; // Sai ? (5 + 3]

    cout << "Test 1 (H?p l?): " << (isValidBrackets(validCode) ? "H?P L?" : "KHÔNG H?P L?") << endl;
    cout << "Test 2 (Sai): " << (isValidBrackets(invalidCode) ? "H?P L?" : "KHÔNG H?P L?") << endl;

    return 0;
}
#include <iostream>
using namespace std;

#define MAX 100

class ArrayStack {
private:
    int top;
    int arr[MAX];

public:
    ArrayStack() {
        top = -1;
    }

    // Thêm ph?n t? vào ??nh Stack
    bool push(int x) {
        if (top >= (MAX - 1)) {
            cout << "Stack Overflow (Ngh?n b? nh? stack)\n";
            return false;
        }
        arr[++top] = x;
        return true;
    }

    // Xóa và tr? v? ph?n t? ? ??nh Stack
    int pop() {
        if (top < 0) {
            cout << "Stack Underflow (Stack r?ng)\n";
            return 0; // Giá tr? m?c ??nh khi l?i
        }
        return arr[top--];
    }

    // Xem giá tr? ??nh Stack mà không xóa
    int peek() {
        if (top < 0) {
            cout << "Stack r?ng\n";
            return 0;
        }
        return arr[top];
    }

    // Ki?m tra Stack r?ng
    bool isEmpty() {
        return (top < 0);
    }
};

int main() {
    ArrayStack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Ph?n t? ??nh hi?n t?i: " << s.peek() << endl;
    cout << "?ã l?y ra: " << s.pop() << endl;
    cout << "Ph?n t? ??nh sau khi pop: " << s.peek() << endl;
    return 0;
}
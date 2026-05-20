#include <iostream>

using namespace std;

int Bai1_Lop1() {
    // Khai báo một mảng tĩnh có 5 phần tử kiểu số nguyên
    int a[5] = { 3, 5, 7, 9, 11 };

    // Truy cập và in ra giá trị của các phần tử trong mảng
    cout << "Phan tu tai chi so 0: " << a[0] << endl;
    cout << "Phan tu tai chi so 1: " << a[1] << endl;
    cout << "Phan tu tai chi so 2: " << a[2] << endl;
    cout << "Phan tu tai chi so 3: " << a[3] << endl;
    cout << "Phan tu tai chi so 4: " << a[4] << endl;

    cout << "----------------------" << endl;

    // Thay đổi giá trị của một phần tử
    a[2] = 42;
    cout << "Gia tri moi cua phan tu tai chi so 2: " << a[2] << endl;

    return 0;
}


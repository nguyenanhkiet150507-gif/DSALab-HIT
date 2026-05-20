#include <iostream>
using namespace std;

int binarySearch(int a[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (a[mid] == x) return mid;   // tìm thấy
        if (a[mid] < x) left = mid + 1;
        else right = mid - 1;
    }
    return -1; // không tìm thấy
}

int Bai2_Lop2() {
    int a[7] = { 1, 3, 5, 7, 9, 11, 13 };
    int n = 7;

    int pos = binarySearch(a, n, 9);
    cout << "Vi tri cua 9 la: " << pos; // in ra 4
    return 0;
}

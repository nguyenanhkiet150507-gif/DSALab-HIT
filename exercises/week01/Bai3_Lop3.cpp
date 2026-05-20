#include <iostream>

using namespace std;

// Hàm gộp hai nửa đã sắp xếp của mảng
void merge(int a[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Cấp phát mảng tạm động trên heap
    int* L = new int[n1];
    int* R = new int[n2];

    // Sao chép dữ liệu vào các mảng tạm
    for (int i = 0; i < n1; i++) {
        L[i] = a[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = a[mid + 1 + j];
    }

    // Gộp các mảng tạm trở lại mảng ban đầu
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k++] = L[i++];
        }
        else {
            a[k++] = R[j++];
        }
    }

    // Chép các phần tử còn lại của mảng L (nếu có)
    while (i < n1) {
        a[k++] = L[i++];
    }

    // Chép các phần tử còn lại của mảng R (nếu có)
    while (j < n2) {
        a[k++] = R[j++];
    }

    // Giải phóng bộ nhớ đã cấp phát
    delete[] L;
    delete[] R;
}

// Hàm chính để thực hiện Merge Sort
void mergeSort(int a[], int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);
    merge(a, left, mid, right);
}

int Bai3_Lop3() {
    int a[] = { 12, 4, 20, 1, 5, 15 };
    int n = sizeof(a) / sizeof(a[0]);

    cout << "Mang ban dau: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    mergeSort(a, 0, n - 1);

    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
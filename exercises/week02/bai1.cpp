#include <iostream>

int main() {
    int n;
    std::cout << "Nhap so phan tu n: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "So phan tu khong hop le!\n";
        return 0;
    }

    // Cấp phát mảng động bằng con trỏ thay vì mảng tĩnh tĩnh
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        std::cout << "Nhap arr[" << i << "]: ";
        std::cin >> arr[i];
    }

    // Khởi tạo các giá trị ban đầu
    int minVal = arr[0];
    int maxVal = arr[0];
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] < minVal) minVal = arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
        sum += arr[i];
    }

    double average = static_cast<double>(sum) / n;

    std::cout << "\n=== KET QUA ===" << std::endl;
    std::cout << "Min: " << minVal << std::endl;
    std::cout << "Max: " << maxVal << std::endl;
    std::cout << "Tong: " << sum << std::endl;
    std::cout << "Trung binh: " << average << std::endl;

    // Giải phóng bộ nhớ
    delete[] arr;
    return 0;
}


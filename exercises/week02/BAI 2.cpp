#include <iostream>
#include <iomanip>

// Hàm hi?n th? ma tr?n ??p
void printMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << "[ ";
        for (int j = 0; j < n; j++) {
            std::cout << std::setw(6) << matrix[i][j] << " ";
        }
        std::cout << "]" << std::endl;
    }
}

// Tính ??nh th?c ma tr?n 3x3 b?ng công th?c Sarrus
int determinant3x3(int** m) {
    return m[0][0] * m[1][1] * m[2][2] + m[0][1] * m[1][2] * m[2][0] + m[0][2] * m[1][0] * m[2][1]
        - m[0][2] * m[1][1] * m[2][0] - m[0][0] * m[1][2] * m[2][1] - m[0][1] * m[1][0] * m[2][2];
}

int main() {
    int n;
    std::cout << "Nhap kich thuoc ma trien vuong n: ";
    std::cin >> n;

    // C?p phát ??ng ma tr?n 2D
    int** A = new int* [n];
    int** B = new int* [n];
    int** C = new int* [n];
    for (int i = 0; i < n; i++) {
        A[i] = new int[n];
        B[i] = new int[n];
        C[i] = new int[n] {0}; // Kh?i t?o b?ng 0
    }

    std::cout << "\nNhap ma tran A:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) std::cin >> A[i][j];

    std::cout << "\nNhap ma tran B:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) std::cin >> B[i][j];

    // Tích ma tr?n: C[i][j] = t?ng(A[i][k] * B[k][j])
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    std::cout << "\nMa tran A:\n"; printMatrix(A, n);
    std::cout << "\nMa tran B:\n"; printMatrix(B, n);
    std::cout << "\nTich hai ma tran (C = A * B):\n"; printMatrix(C, n);

    if (n == 3) {
        std::cout << "\n=> Dinh thuc (Determinant) cua ma tran A (3x3): " << determinant3x3(A) << std::endl;
    }
    else {
        std::cout << "\nKich thuoc n != 3, bo qua tinh dinh thuc 3x3.\n";
    }

    // Gi?i phóng b? nh? vùng m?ng 2D
    for (int i = 0; i < n; i++) {
        delete[] A[i]; delete[] B[i]; delete[] C[i];
    }
    delete[] A; delete[] B; delete[] C;

    return 0;
}
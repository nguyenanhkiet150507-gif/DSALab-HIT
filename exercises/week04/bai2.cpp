#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

struct SortResult {
    long long comparisons = 0;
    long long swaps = 0;
};

SortResult bubbleSortCount(vector<int> arr) {
    SortResult res;
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            res.comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                res.swaps++;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
    return res;
}

SortResult selectionSortCount(vector<int> arr) {
    SortResult res;
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            res.comparisons++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(arr[i], arr[min_idx]);
            res.swaps++;
        }
    }
    return res;
}

SortResult insertionSortCount(vector<int> arr) {
    SortResult res;
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0) {
            res.comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                res.swaps++; // Tính l??t d?ch chuy?n t??ng ???ng hoán v?
                j--;
            }
            else {
                break;
            }
        }
    }
    return res;
}

int main() {
    srand(time(NULL));
    int N = 100;
    vector<int> original(N);

    // T?o m?ng ng?u nhiên 100 ph?n t?
    for (int i = 0; i < N; i++) {
        original[i] = rand() % 1000;
    }

    // Nhân b?n m?ng cho 3 thu?t toán
    SortResult b_res = bubbleSortCount(original);
    SortResult s_res = selectionSortCount(original);
    SortResult i_res = insertionSortCount(original);

    // In b?ng k?t qu?
    cout << "====================================================\n";
    cout << left << setw(18) << "Thuat Toan" << setw(18) << "So Phep So Sanh" << setw(18) << "So Hoan Vi / Dich" << "\n";
    cout << "====================================================\n";
    cout << left << setw(18) << "Bubble Sort" << setw(18) << b_res.comparisons << setw(18) << b_res.swaps << "\n";
    cout << left << setw(18) << "Selection Sort" << setw(18) << s_res.comparisons << setw(18) << s_res.swaps << "\n";
    cout << left << setw(18) << "Insertion Sort" << setw(18) << i_res.comparisons << setw(18) << i_res.swaps << "\n";
    cout << "====================================================\n";

    return 0;
}
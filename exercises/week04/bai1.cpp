#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printArray(const vector<int>& arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << "\n";
}

void bubbleSortDebug(vector<int> arr) {
    int n = arr.size();
    cout << "\n=== BUBBLE SORT ===" << endl;
    cout << "Ban dau: "; printArray(arr);
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        cout << "Vong lap " << i + 1 << ": "; printArray(arr);
        if (!swapped) break;
    }
}

void selectionSortDebug(vector<int> arr) {
    int n = arr.size();
    cout << "\n=== SELECTION SORT ===" << endl;
    cout << "Ban dau: "; printArray(arr);
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
        cout << "Vong lap " << i + 1 << ": "; printArray(arr);
    }
}

void insertionSortDebug(vector<int> arr) {
    int n = arr.size();
    cout << "\n=== INSERTION SORT ===" << endl;
    cout << "Ban dau: "; printArray(arr);
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        cout << "Vong lap " << i << ": "; printArray(arr);
    }
}

int main() {
    vector<int> data = { 5, 3, 8, 4, 2 };

    bubbleSortDebug(data);
    selectionSortDebug(data);
    insertionSortDebug(data);

    return 0;
}
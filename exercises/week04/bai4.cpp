#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"      // ?ang so sánh/??i ch?
#define GREEN   "\033[32m"      // ?ã x?p xong
#define CYAN    "\033[36m"      // Các thanh còn l?i

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    cout << "\033[H\033[J";
#endif
}

void renderVisualizer(const vector<int>& arr, int idx1 = -1, int idx2 = -1, int sorted_idx = -1, string msg = "") {
    clearScreen();
    cout << msg << "\n\n";

    for (int i = 0; i < arr.size(); i++) {
        string color = CYAN;
        if (i == idx1 || i == idx2) color = RED;
        else if (sorted_idx != -1 && i >= sorted_idx) color = GREEN;

        cout << color;
        // V? các thanh ngang b?ng ký t? '#'
        for (int j = 0; j < arr[i]; j++) cout << "#";

        cout << " " << arr[i] << RESET << "\n";
    }
    this_thread::sleep_for(chrono::milliseconds(200));
}

void bubbleSortVisual(vector<int> arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            renderVisualizer(arr, j, j + 1, n - i, "Bubble Sort -> Dang so sanh vi tri [" + to_string(j) + "] va [" + to_string(j + 1) + "]");
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                renderVisualizer(arr, j, j + 1, n - i, "Bubble Sort -> Hoan vi!");
            }
        }
    }
    renderVisualizer(arr, -1, -1, 0, "STATUS: Bubble Sort da hoan thanh!");
}

void selectionSortVisual(vector<int> arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            renderVisualizer(arr, min_idx, j, i, "Selection Sort -> Quet tim kiem Min. Min hien tai o index: " + to_string(min_idx));
            if (arr[j] < arr[min_idx]) min_idx = j;
        }
        swap(arr[i], arr[min_idx]);
        renderVisualizer(arr, i, min_idx, i + 1, "Selection Sort -> Dua Min ve dung vi tri dau dau mang");
    }
    renderVisualizer(arr, -1, -1, n, "STATUS: Selection Sort da hoan thanh!");
}

void insertionSortVisual(vector<int> arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            renderVisualizer(arr, j, j + 1, -1, "Insertion Sort -> Dich chuyen cac phan tu lon hon 'key' ra sau");
            j--;
        }
        arr[j + 1] = key;
        renderVisualizer(arr, j + 1, -1, -1, "Insertion Sort -> Chen 'key' (" + to_string(key) + ") vao cho trong");
    }
    renderVisualizer(arr, -1, -1, n, "STATUS: Insertion Sort da hoan thanh!");
}

int main() {
    vector<int> visualData = { 15, 8, 22, 12, 17, 5, 25, 10, 19 };

    while (true) {
        clearScreen();
        cout << "===== MINI SORTING VISUALIZER =====\n";
        cout << "1. Bubble Sort Visualizer\n";
        cout << "2. Selection Sort Visualizer\n";
        cout << "3. Insertion Sort Visualizer\n";
        cout << "4. Thoat chuong trinh\n";
        cout << "Chon chuc nang (1-4): ";

        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (choice == 1) bubbleSortVisual(visualData);
        else if (choice == 2) selectionSortVisual(visualData);
        else if (choice == 3) insertionSortVisual(visualData);
        else if (choice == 4) break;

        cout << "\nNhan ENTER de tiep tuc...";
        cin.ignore(10000, '\n');
        cin.get();
    }

    return 0;
}
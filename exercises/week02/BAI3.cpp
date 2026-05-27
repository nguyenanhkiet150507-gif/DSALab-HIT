#include <iostream>

class VectorSimulate {
private:
    int* data;
    int sizeCount;
    int maxCapacity;

    // Hàm m? r?ng dung l??ng b? nh? khi m?ng ??y
    void resize() {
        maxCapacity = (maxCapacity == 0) ? 1 : maxCapacity * 2;
        int* temp = new int[maxCapacity];
        for (int i = 0; i < sizeCount; i++) {
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
    }

public:
    VectorSimulate() : data(nullptr), sizeCount(0), maxCapacity(0) {}

    ~VectorSimulate() {
        delete[] data;
    }

    void push_back(int value) {
        if (sizeCount >= maxCapacity) {
            resize();
        }
        data[sizeCount] = value;
        sizeCount++;
    }

    void pop_back() {
        if (sizeCount > 0) {
            sizeCount--;
        }
        else {
            std::cout << "Mang dang trong, khong the xoa!\n";
        }
    }

    int at(int index) {
        if (index >= 0 && index < sizeCount) {
            return data[index];
        }
        std::cout << "Loi: Vi tri index nam ngoai vung mang!" << std::endl;
        return -1;
    }

    int size() const { return sizeCount; }
    int capacity() const { return maxCapacity; }
};

int main() {
    VectorSimulate vec;

    std::cout << "--- Them phan tu vao mien mang dong ---" << std::endl;
    for (int i = 1; i <= 5; i++) {
        vec.push_back(i * 10);
        std::cout << "Them " << i * 10 << " -> Size: " << vec.size() << ", Capacity: " << vec.capacity() << std::endl;
    }

    std::cout << "\nPhan tu tai vi tri index 2: " << vec.at(2) << std::endl;

    std::cout << "\nXoa phan tu cuoi cung (pop_back)..." << std::endl;
    vec.pop_back();
    std::cout << "Size hien tai sau xoa: " << vec.size() << std::endl;

    std::cout << "\nIn toan bo mang: ";
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec.at(i) << " ";
    }
    std::cout << std::endl;

    return 0;
}
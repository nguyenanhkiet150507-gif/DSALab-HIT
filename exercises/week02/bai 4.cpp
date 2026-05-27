#include <iostream>
#include <fstream>
#include <iomanip>

// ==========================================
// TH? VI?N X? LÝ CHU?I T? XÂY D?NG (KHÔNG STL)
// ==========================================

// Hàm sao chép chu?i
void customStrcpy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// Hàm so sánh hai chu?i (?ã s?a l?i logic tri?t ??)
bool customStrcmp(const char* s1, const char* s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *s1 == *s2;
}

// Hàm tìm ki?m chu?i con (Ph?c v? tìm ki?m theo tên)
bool customStrstr(const char* haystack, const char* needle) {
    if (*needle == '\0') return true;
    for (int i = 0; haystack[i] != '\0'; i++) {
        int j = 0;
        while (haystack[i + j] != '\0' && needle[j] != '\0' && haystack[i + j] == needle[j]) {
            j++;
        }
        if (needle[j] == '\0') return true;
    }
    return false;
}

// ==========================================
// C?U TRÚC D? LI?U & QU?N LÝ
// ==========================================

struct Student {
    char id[20];
    char name[50];
    double score;
};

class StudentManager {
private:
    Student* list;
    int count;
    int capacity;

    // T? ??ng nhân ?ôi dung l??ng m?ng ??ng khi ??y
    void expand() {
        capacity = (capacity == 0) ? 2 : capacity * 2;
        Student* temp = new Student[capacity];
        for (int i = 0; i < count; i++) {
            temp[i] = list[i];
        }
        delete[] list;
        list = temp;
    }

public:
    StudentManager() : list(nullptr), count(0), capacity(0) {}

    ~StudentManager() {
        delete[] list;
    }

    // 1. Thêm sinh viên
    void addStudent() {
        if (count >= capacity) expand();

        std::cout << "Nhap MSSV: ";
        std::cin >> list[count].id;
        std::cin.ignore(); // Xóa b? nh? ??m ?? không b? trôi dòng khi dùng getline phía sau

        std::cout << "Nhap ho va ten: ";
        std::cin.getline(list[count].name, 50);

        std::cout << "Nhap diem: ";
        std::cin >> list[count].score;

        count++;
        std::cout << "=> Them sinh vien thanh cong!\n";
    }

    // 2. Xóa sinh viên theo MSSV
    void deleteStudent() {
        if (count == 0) {
            std::cout << "Danh sach sinh vien dang trong!\n";
            return;
        }

        char targetId[20];
        std::cout << "Nhap MSSV can xoa: ";
        std::cin >> targetId;

        int foundIdx = -1;
        for (int i = 0; i < count; i++) {
            if (customStrcmp(list[i].id, targetId)) {
                foundIdx = i;
                break;
            }
        }

        if (foundIdx == -1) {
            std::cout << "Khong tim thay sinh vien co MSSV: " << targetId << "\n";
            return;
        }

        // D?ch chuy?n t?nh ti?n các ph?n t? phía sau lên ?è vào v? trí xóa
        for (int i = foundIdx; i < count - 1; i++) {
            list[i] = list[i + 1];
        }
        count--;
        std::cout << "=> Da xoa sinh vien khoi he thong.\n";
    }

    // 3. Tìm ki?m theo Tên ho?c MSSV
    void searchStudent() {
        if (count == 0) {
            std::cout << "Danh sach trong, khong co du lieu de tim kiem!\n";
            return;
        }

        int opt;
        std::cout << "1. Tim kiem theo MSSV exact (Kh?p hoàn toàn)\n2. Tim kiem theo ten t??ng doi (Ch?a t? khóa)\nLua chon: ";
        std::cin >> opt;

        char query[50];
        std::cout << "Nhap tu khoa can tim: ";
        std::cin.ignore();
        std::cin.getline(query, 50);

        std::cout << "\n---------------------------------------------------------\n";
        std::cout << std::left << std::setw(15) << "MSSV" << std::setw(30) << "Ho va Ten" << "Diem\n";
        std::cout << "---------------------------------------------------------\n";

        bool flag = false;
        for (int i = 0; i < count; i++) {
            if ((opt == 1 && customStrcmp(list[i].id, query)) ||
                (opt == 2 && customStrstr(list[i].name, query))) {
                std::cout << std::left << std::setw(15) << list[i].id
                    << std::setw(30) << list[i].name << list[i].score << "\n";
                flag = true;
            }
        }
        if (!flag) std::cout << "Khong tim thay thong tin trung khop voi tu khoa.\n";
    }

    // 4. S?p x?p theo ?i?m gi?m d?n (Dùng Bubble Sort) và hi?n th?
    void rankClass() {
        if (count == 0) {
            std::cout << "Danh sach trong.\n";
            return;
        }

        // Sao chép d? li?u ra m?ng ph? ?? gi? nguyên th? t? nh?p ban ??u trong vùng nh? g?c
        Student* temp = new Student[count];
        for (int i = 0; i < count; i++) temp[i] = list[i];

        // Thu?t toán Bubble Sort s?p x?p gi?m d?n
        for (int i = 0; i < count - 1; i++) {
            for (int j = 0; j < count - i - 1; j++) {
                if (temp[j].score < temp[j + 1].score) {
                    Student t = temp[j];
                    temp[j] = temp[j + 1];
                    temp[j + 1] = t;
                }
            }
        }

        std::cout << "\n=== BANG XEP HANG DIEM LOP ===\n";
        std::cout << std::left << std::setw(8) << "Hang" << std::setw(15) << "MSSV" << std::setw(30) << "Ho va Ten" << "Diem\n";
        std::cout << "---------------------------------------------------------\n";
        for (int i = 0; i < count; i++) {
            std::cout << std::left << std::setw(8) << i + 1
                << std::setw(15) << temp[i].id
                << std::setw(30) << temp[i].name << temp[i].score << "\n";
        }
        delete[] temp;
    }

    // 5. Xu?t báo cáo th?ng kê & Ghi file text
    void exportReport() {
        if (count == 0) {
            std::cout << "Chua co du lieu de xuat bao cao.\n";
            return;
        }

        double maxS = list[0].score, minS = list[0].score, total = 0;
        for (int i = 0; i < count; i++) {
            if (list[i].score > maxS) maxS = list[i].score;
            if (list[i].score < minS) minS = list[i].score;
            total += list[i].score;
        }
        double avg = total / count;

        // In th?ng kê nhanh ra màn hình Console
        std::cout << "\n=== THONG KE LOP HOC ===\n";
        std::cout << "Tong so sinh vien: " << count << "\n";
        std::cout << "Diem cao nhat: " << maxS << "\n";
        std::cout << "Diem thap nhat: " << minS << "\n";
        std::cout << "Diem trung binh: " << std::fixed << std::setprecision(2) << avg << "\n";

        // M? lu?ng ghi file text d? li?u sinh viên
        std::ofstream outFile("diem_sinhvien.txt");
        if (!outFile) {
            std::cout << "Loi mo file txt de ghi thong tin!\n";
            return;
        }

        outFile << "=== BAO CAO QUAN LY DIEM SINH VIEN ===\n\n";
        outFile << std::left << std::setw(15) << "MSSV" << std::setw(30) << "Ho ten" << "Diem\n";
        outFile << "---------------------------------------------------------\n";
        for (int i = 0; i < count; i++) {
            outFile << std::left << std::setw(15) << list[i].id
                << std::setw(30) << list[i].name << list[i].score << "\n";
        }
        outFile << "---------------------------------------------------------\n";
        outFile << "Thong ke tong quan:\n";
        outFile << "- DSSV hien tai: " << count << "\n";
        outFile << "- Diem cao nhat: " << maxS << "\n";
        outFile << "- Diem thap nhat: " << minS << "\n";
        outFile << "- Diem trung binh: " << avg << "\n";

        outFile.close();
        std::cout << "=> Da xuat file 'diem_sinhvien.txt' thanh cong!\n";
    }
};

// ==========================================
// CH??NG TRÌNH CHÍNH (MENU ?I?U KHI?N)
// ==========================================

int main() {
    StudentManager manager;
    int choice;

    do {
        std::cout << "\n=== QUAN LY DIEM SINH VIEN ===\n";
        std::cout << "1. Them sinh vien\n";
        std::cout << "2. Xoa sinh vien\n";
        std::cout << "3. Tim kiem\n";
        std::cout << "4. Xep hang lop\n";
        std::cout << "5. Xuat bao cao\n";
        std::cout << "0. Thoat\n";
        std::cout << "Lua chon cua ban: ";
        std::cin >> choice;

        switch (choice) {
        case 1: manager.addStudent(); break;
        case 2: manager.deleteStudent(); break;
        case 3: manager.searchStudent(); break;
        case 4: manager.rankClass(); break;
        case 5: manager.exportReport(); break;
        case 0: std::cout << "Da thoat chuong trinh. Tam biet!\n"; break;
        default: std::cout << "Lua chon khong hop le. Vui long chon tu 0 den 5!\n";
        }
    } while (choice != 0);

    return 0;
}
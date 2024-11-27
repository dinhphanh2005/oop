#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

class Reader {
public:
    int MDG;
    string Name;
    int Year_of_Birth;
    string Address;

    Reader(int mdg, string name, int year, string address) {
        this->MDG = mdg;
        this->Name = name;
        this->Year_of_Birth = year;
        this->Address = address;
    }

    Reader() {}

    friend istream& operator>>(istream& CIN, Reader& reader) {
        cout << "Nhap ma doc gia: ";
        CIN >> reader.MDG;
        CIN.ignore();
        cout << "Nhap ten doc gia: ";
        getline(CIN, reader.Name);
        cout << "Nhap nam sinh: ";
        CIN >> reader.Year_of_Birth;
        CIN.ignore();
        cout << "Nhap dia chi: ";
        getline(CIN, reader.Address);
        return CIN;
    }

    friend ostream& operator<<(ostream& COUT, const Reader& reader) {
        COUT << "Ma Doc Gia: " << reader.MDG << ", Ten: " << reader.Name << ", Nam Sinh: " << reader.Year_of_Birth << ", Dia Chi: " << reader.Address;
        return COUT;
    }
};

class Node {
public:
    Reader value;
    Node* next;

    Node(const Reader& reader) : value(reader), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}

    void addReader(const Reader& reader) {
        Node* newNode = new Node(reader);
        newNode->next = head;
        head = newNode;
        cout << "Them doc gia thanh cong." << endl;
    }

    void displayReader() const {
        Node* current = head;
        while (current->next != nullptr) {
            cout << current->value << endl;
            current = current->next;
        }
    }

    bool deleteReader(int mdg) {
        Node* current = head;
        Node* prev = nullptr;
        while (current && current->value.MDG != mdg) {
            prev = current;
            current = current->next;
        }
        if (!current) {
            cout << "Doc gia khong ton tai." << endl;
            return false;
        }
        if (prev != nullptr) {
            prev->next = current->next;
        } else {
            head = current->next;
        }
        delete current;
        cout << "Xoa doc gia thanh cong." << endl;
        return true;
    }

    bool updateReader(int mdg) {
        Node* current = head;
        while (current && current->value.MDG != mdg) {
            current = current->next;
        }
        if (!current) {
            cout << "Doc gia khong ton tai." << endl;
            return false;
        }
        cout << "Cap nhat thong tin doc gia:" << endl;
        cout << "Nhap ten moi: ";
        cin.ignore();
        getline(cin, current->value.Name);
        cout << "Nhap nam sinh moi: ";
        cin >> current->value.Year_of_Birth;
        cin.ignore();
        cout << "Nhap dia chi moi: ";
        getline(cin, current->value.Address);
        cout << "Cap nhat thanh cong." << endl;
        return true;
    }

    Reader* findReader(int mdg) const {
        Node* current = head;
        while (current) {
            if (current->value.MDG == mdg) {
                return &(current->value);
            }
            current = current->next;
        }
        return nullptr;
    }

    ~LinkedList() {
        Node* current = head;
        while (current) {
            Node* toDelete = current;
            current = current->next;
            delete toDelete;
        }
    }
};

void displayMenu() {
    cout << endl;
    cout << "Menu:" << endl;
    cout << "1. In danh sach doc gia" << endl;;
    cout << "2. Them doc gia" << endl;
    cout << "3. Xoa doc gia" << endl;
    cout << "4. Cap nhat doc gia" << endl;
    cout << "5. Tim kiem doc gia" << endl;
    cout << "6. Thoat" << endl;
}
int main() {
    LinkedList readers;
    int choice;

    do {
        displayMenu();
        cout << "Chon chuc nang: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Danh sach doc gia:" << endl;
                readers.displayReader();
                break;
            }
            case 2: {
                Reader reader;
                cin >> reader;  
                readers.addReader(reader);
                break;
            }
            case 3: {
                int mdg;
                cout << "Nhap ma doc gia can xoa: ";
                cin >> mdg;
                readers.deleteReader(mdg);
                break;
            }
            case 4: {
                int mdg;
                cout << "Nhap ma doc gia can cap nhat: ";
                cin >> mdg;
                readers.updateReader(mdg);
                break;
            }
            case 5: {
                int mdg;
                cout << "Nhap ma doc gia can tim: ";
                cin >> mdg;
                Reader* reader = readers.findReader(mdg);
                if (reader) {
                    cout << "Thong tin doc gia:\n" << *reader << endl;
                } else {
                    cout << "Doc gia khong ton tai." << endl;
                }
                break;
            }
            case 6: {
                cout << "Thoat chuong trinh." << endl;;
                break;
            }
            default:
                cout << "Lua chon khong hop le." << endl;
        }
    } while (choice != 6);

    return 0;
}

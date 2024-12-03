#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Product {
private:
    string Name;
    string Code;
    string Company;
    int Numbers;
    double Price;
public:
    Product(string name = "", string code = "", string company = "", int numbers = 0, double price = 0) : Name(name), Code(code), Company(company), Numbers(numbers), Price(price) {}

    virtual void input() {
        cin.ignore();
        cout << "Nhap ten san pham: ";
        getline(cin, Name);
        cout << "Nhap ma hang: ";
        cin >> Code;
        cout << "Nhap ten cong ty: ";
        cin.ignore();
        getline(cin, Company);
        cout << "Nhap so luong: ";
        cin >> Numbers;
        cout << "Nhap don gia: ";
        cin >> Price;
        // cin.ignore();
    }

    virtual void output() const {
        cout << Name << " " << Code << " " << Company << " " << Numbers << " " << Price << endl;
    }

    int getNumbers() const {
        return Numbers;
    }

    double getPrice() const {
        return Price;
    }
};

class Computer : public Product {
private:
    string CPU;
    string OS;
    double Weight;
public:
    Computer(string cpu = "", string os = "", double weight = 0) : CPU(cpu), OS(os), Weight(weight) {}

    void input() override {
        Product::input();
        cin.ignore();
        cout << "Nhap CPU: ";
        getline(cin, CPU);
        cout << "Nhap OS: ";
        // cin.ignore();
        getline(cin, OS);
        cout << "Nhap trong luong: ";
        cin >> Weight;
        // cin.ignore();
    }

    void output() const override {
        Product::output();
        cout << CPU << " " << OS << " " << Weight << endl;
    }

    string getOS() const {
        return OS;
    }
};

void print(vector<Computer> &ds) {
    cout << "Cac loai may tinh dang het hang la: ";
    bool check = false;
    for (const auto &mt : ds) {
        if (mt.getNumbers() == 0) {
            mt.output();
            check = true;
        }
    }
    if(!check) {
        cout << "khong co may tinh nao het hang" << endl;
    }
}

void maxPrice(vector<Computer> &ds) {
    if (ds.empty()) {
        cout << "khong co may tinh" << endl;
    }
    const Computer *cmp = nullptr;

    for (const auto &mt : ds) {
        if ((mt.getOS() == "Windows") || (mt.getOS() == "windows")) {
            if ((cmp == nullptr) || (mt.getPrice() > cmp->getPrice())) {
                cmp = &mt;
            }
        }
    }

    if (cmp != nullptr) {
        cout << "Cac may tinh he dieu hanh Windows co gia cao nhat la: ";
        cmp->output();
    } else {
        cout << "khong co may tinh he windows nao" << endl;
    }
}

int main() {
    vector<Computer> ds;
    int n;
    cout << "Nhap so luong may tinh: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin may tinh " << i + 1 << ": " << endl;
        Computer cmp;
        cmp.input();
        ds.push_back(cmp);
    }

    print(ds);
    maxPrice(ds);

    return 0;
}
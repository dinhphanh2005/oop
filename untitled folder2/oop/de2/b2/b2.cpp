#include <iostream>
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
    }

    virtual void output() const {
        cout << Name << " " << Code << " " << Company << " " << Numbers << " " << Price << endl;
    }

    string getName() const {
        return Name;
    }

    string getCode() const {
        return Code;
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
        getline(cin, OS);
        cout << "Nhap trong luong: ";
        cin >> Weight;
    }

    void output() const override {
        Product::output();
        cout << CPU << " " << OS << " " << Weight << endl;
    }
};

void maxPrice(vector<Computer> &ds) {
    if (ds.empty()) {
        cout << "khong co may tinh" << endl;
    }

    const Computer *cmp = &ds[0];
    for (const auto &mt : ds) {
        if (mt.getPrice() > cmp->getPrice()) {
            cmp = &mt;
        }
    }

    cout << "May tinh co gia cao nhat la: " << endl;
    cmp->output();
}

void find(vector<Computer> &ds) {
    cin.ignore();
    string name;
    cout << "Nhap thong tin (ma hang hoac ten hang) de tim kiem: ";
    getline(cin, name);
    for (const auto &mt : ds) {
        if (mt.getName() == name || mt.getCode() == name) {
            mt.output();
        }
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

    maxPrice(ds);
    find(ds);

    return 0;
}
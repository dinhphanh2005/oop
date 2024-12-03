#include <iostream>
using namespace std;

class QLH {
private: 
    string Code;
    string Name;
    string Country;
    int Type;
    int Quantity;
public:
    QLH(string code = "", string name = "", string country = "", int type = 0, int quantity = 0) : Code(code), Name(name), Country(country), Type(type), Quantity(quantity) {}

    virtual void input() {
        cin.ignore();
        cout << "Nhap ma hang: ";
        getline(cin, Code);
        cout << "Nhap ten hang: ";
        getline(cin, Name);
        cout << "Nhap noi xuat xu: ";
        getline(cin, Country);
        do {
            cout << "Nhap loai hang (1, 2, 3): ";
            cin >> Type;
        } while (Type < 1 || Type > 3);
        cout << "Nhap so luong: ";
        cin >> Quantity;
    }

    virtual void output() const {
        cout << Code << " " << Name << " " << Country << " " << Type << " " << Quantity << " ";
    }

    int getType() const {
        return Type;
    }

    int getQuantity() const {
        return Quantity;
    }
};

class Technology : public QLH {
private:
    int expired_date;
public:
    Technology(int exp = 0) : expired_date(exp) {}

    void input() override {
        QLH::input();
        cin.ignore();
        cout << "Nhap thoi gian bao hanh (thang): ";
        cin >> expired_date;
    }

    void output() const override {
        QLH::output();
        cout << expired_date << endl;
    }

    int getExp() const {
        return expired_date;
    }
};

void total_of_type(const vector<Technology> &ds) {
    int sum_type_1 = 0, sum_type_2 = 0, sum_type_3 = 0;
    for (const auto &mh : ds) {
        if (mh.getType() == 1) {
            sum_type_1 += mh.getQuantity();
        }
        if(mh.getType() == 2) {
            sum_type_2 += mh.getQuantity();
        }
        if(mh.getType() == 3) {
            sum_type_3 += mh.getQuantity();
        }
    }

    cout << "Tong loai 1: " << sum_type_1 << endl;
    cout << "Tong loai 2: " << sum_type_2 << endl;
    cout << "Tong loai 3: " << sum_type_3 << endl;
}

void find(vector<Technology> &ds) {
    const Technology *max = &ds[0];
    for (const auto &mh : ds) {
        if (mh.getExp() > max->getExp()) {
            max = &mh;
        }
    }

    cout << "Mat hang co thoi gian bao hanh lau nhat la: ";
    max->output();
}
int main() {
    int n;
    cout << "Nhap so luong hang: ";
    cin >> n;
    vector<Technology> ds;
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin mat hang: " << i + 1 << ": " << endl;
        Technology tch;
        tch.input();
        ds.push_back(tch);
    }

    total_of_type(ds);
    find(ds);

    return 0;
}
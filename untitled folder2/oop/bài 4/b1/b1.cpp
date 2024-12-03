#include <iostream>
using namespace std;

class SoPhuc {
private:
    double Ao;
    double Thuc;
public:
    SoPhuc(double thuc = 0, double ao = 0) : Thuc(thuc), Ao(ao) {}

    void nhap() {
        cout << "nhap thuc: ";
        cin >> Thuc;
        cout << "nhap ao: ";
        cin >> Ao;
    }

    void xuat() {
        cout << "so ao la: " << Thuc << " + " << Ao << "i" << endl;
    }

    SoPhuc operator+(const SoPhuc &other) {
        return SoPhuc(Thuc + other.Thuc, Ao + other.Ao);
    }
};

int main() {
    SoPhuc s1;
    SoPhuc s2;
    s1.nhap();
    s2.nhap();
    SoPhuc sum = s1 + s2;
    sum.xuat();

    return 0;
}
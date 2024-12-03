#include <iostream>
#include <cmath>
using namespace std;

class Diem {
private:
    double Hoanh_do;
    double Tung_do;
public:
    Diem(double hoanh = 0, double tung = 0) : Hoanh_do(hoanh), Tung_do(tung) {}

    void nhap() {
        cout << "Hoanh: ";
        cin >> Hoanh_do;
        cout << "Tung: ";
        cin >> Tung_do;
    }

    void xuat() {
        cout << "Diem: " << Hoanh_do << " " << Tung_do << endl;
    }

    double kc_goc() {
        return sqrt(pow(Hoanh_do, 2) + pow(Tung_do, 2));
    }

    double kc(const Diem &diem) {
        return sqrt(pow(Hoanh_do - diem.Hoanh_do, 2) + pow(Tung_do - diem.Tung_do, 2));
    }

    friend double kc(const Diem &d1, const Diem &d2);
};

double kc(const Diem &d1, const Diem &d2) {
    return sqrt(pow(d2.Hoanh_do - d1.Hoanh_do, 2) + pow(d2.Tung_do - d1.Tung_do, 2));
}

int main() {
    Diem d1;
    Diem d2;
    d1.nhap();
    d2.nhap();
    d1.xuat();
    d2.xuat();
    double kc1 = d1.kc_goc();
    cout << kc1 << endl;
    double kc2 = d2.kc_goc();
    cout << kc2 << endl;
    double kc3 = d1.kc(d2);
    cout << kc3 << endl;
    double kc4 = kc(d1, d2);
    cout << kc4 << endl;

    return 0;
}
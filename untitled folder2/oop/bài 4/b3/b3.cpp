#include <iostream>
using namespace std;

class Diem {
private:
    double X;
    double Y;
public:
    Diem(double x = 0, double y = 0) : X(x), Y(y) {}

    void nhap() { 
        cout << "Hoanh: ";
        cin >> X;
        cout << "Tung: ";
        cin >> Y;
    }

    void xuat() {
        cout << "Diem: " << X << " " << Y << endl;
    }

    friend double kc(const Diem &d1, const Diem &d2);

    friend double dientich(const Diem &d1, const Diem &d2, const Diem &d3);

    friend double dodai(const vector<Diem> ds);
};

double kc(const Diem &d1, const Diem &d2) {
    return sqrt(pow(d2.X - d1.X, 2) + pow(d2.Y - d1.Y, 2));
}

double dientich(const Diem &d1, const Diem &d2, const Diem &d3) {
    return abs((d2.X - d1.X) * (d3.Y - d1.Y) - (d3.X - d1.X) * (d2.Y - d1.Y)) / 2;
}

double dodai(const vector<Diem> ds) {
    double sum = 0;
    for (size_t i = 1; i < ds.size(); i++) {
        sum += kc(ds[i - 1], ds[i]);
    }

    return sum;
}

int main() {
    Diem d1;
    Diem d2;
    Diem d3;

    d1.nhap();
    d2.nhap();
    d3.nhap();

    d1.xuat();
    d2.xuat();
    d3.xuat();

    double kc1 = kc(d1, d2);
    cout << kc1 << endl;

    double dt = dientich(d1, d2, d3);
    cout << dt << endl;

    int n;
    cin >> n;
    vector<Diem> ds(n);
    for (int i = 0; i < n; i++) {
        cout << "Nhap toa do diem " << i + 1 << ": " << endl;;
        ds[i].nhap();
    }

    double sum = dodai(ds);
    cout << sum << endl;

    return 0;
}
#include <iostream>
using namespace std;

class Diem {
private: 
    double x, y;
public:
    Diem(double xVal = 0, double yVal = 0) : x(xVal), y(yVal) {};
    friend istream& operator>> (istream& CIN, Diem& diem) {
        cout << "Nhap x: ";
        CIN >> diem.x;
        cout << "Nhap y: ";
        CIN >> diem.y;
        return CIN;
    }

    friend ostream& operator<< (ostream& COUT, Diem& diem) {
        COUT << "Toa do: " << diem.x << " " << diem.y << endl;
        return COUT;
    }

    Diem operator* (const Diem& other) {
        return Diem(x * other.x, y * other.y);
    }
};

int main() {
    Diem d1;
    Diem d2;
    Diem d3;
    cin >> d1 >> d2 >> d3;
    cout << d1 << d2 << d3;
    Diem d = d1 * d2 * d3;
    cout << "Ket Qua " << d;

    return 0;
}
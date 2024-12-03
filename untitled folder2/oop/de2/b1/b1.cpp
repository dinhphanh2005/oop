#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

class PS {
private:
    int TS;
    int MS;
public:
    PS() : TS(0), MS(1) {}

    PS(int tu_so, int mau_so) {
        if (mau_so == 0) {
            cout << "Error" << endl;
            MS = 1;
        } else {
            MS = mau_so;
        }

        TS = tu_so;
        rut_gon();
    }

    void rut_gon() {
        int Gcd = gcd(TS, MS);
        TS /= Gcd;
        MS /= Gcd;
        if (MS < 0) {
            TS = -TS;
            MS = -MS;
        }
    }

    void input() {
        cout << "nhap tu so: ";
        cin >> TS;
        cout << "nhap mau so: ";
        cin >> MS;
    }

    void output() {
        cout << TS << " / " << MS << endl;
    }

    PS operator*(const PS &other) {
        int ts = TS * other.TS;
        int ms = MS * other.MS;
        return PS(ts, ms);
    }

    friend ostream& operator<< (ostream& COUT, PS& ps) {
        COUT << ps.TS << " / " << ps.MS;
        return COUT;
    }   
};

int main() {
    PS ps1, ps2;
    ps1.input();
    // ps2.input();
    cout << "Phan so 1: " << ps1 << " " << "Phan so 2: " << ps2 << endl;
    PS sum = ps1 * ps2;
    sum.output();

    return 0;
}

//if could use __gcd(num1, num2)
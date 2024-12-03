#include <iostream>
#include <cmath>
using namespace std;

class DT {
private:
    int n;
    double *a;
public:
    DT(int degree = 0) : n(degree) {
        a = new double[n + 1];
    }
    
    ~DT() {
        delete[] a;
    }

    void nhap() {
        for (int i = 0; i <= n; i++) {
            cout << "He so bac " << i << ": ";  
            cin >> a[i];
        }
    }

    void xuat() {
        for (int i = 0; i <= n; i++) {
            cout << a[i] << "x^" << i;
            if (i < n) {
                cout << " + ";
            }
        }
    }

    double gia_tri(double t) {
        double result = 0;
        for (int i = 0 ; i <= n; i++) {
            result += a[i] * pow(t, i);
        }
        return result;
    }
};


int main() {
    int degree;
    cout << "Nhap so bac: ";
    cin >> degree;
    DT dt(degree);

    dt.nhap();
    dt.xuat();
    cout << endl;

    double t;
    cout << "Nhap gia tri t: ";
    cin >> t;
    double result = dt.gia_tri(t);
    cout << result << endl;

    return 0;
}
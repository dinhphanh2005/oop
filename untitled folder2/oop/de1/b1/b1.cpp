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

    void input() {
        for (int i = 0; i <= n; i++) {
            cout << "He so cua bac " << i << ": ";
            cin >> a[i];
        }
    }

    void output() {
        for (int i = 0; i <= n; i++) {
            if (i == 0) {
                cout << a[i];
            } else {
                cout << a[i] << "x^" << i;
            }
            if (i < n) {
                cout << " + ";
            }
        }
    }

    double value(double t) {
        double result = 0;
        for (int i = 0; i <= n; i++) {
            result += a[i] * pow(t, i); 
        }
        return result;
    }
};

int main() {
    int degree;
    cout << "Nhap bac cua da thuc: ";
    cin >> degree;
    
    DT dt(degree);
    dt.input();
    dt.output();
    cout << endl;

    double t;
    cout << "Nhap gia tri t: ";
    cin >> t;
    double result = dt.value(t);
    cout << result << endl;

    return 0;
}
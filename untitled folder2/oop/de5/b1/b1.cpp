#include <iostream>
using namespace std;

class Diem {
private:
    double X;
    double Y;
public:
    Diem(double x = 0, double y = 0) : X(x), Y(y) {}

    void input() {
        cout << "x: ";
        cin >> X;
        cout << "y: ";
        cin >> Y;
    }
};
#include<bits/stdc++.h>
using namespace std;

class DaThuc{
	private:
		int n;
		double *a;
	public:
		DaThuc(){
			n=0;
			a=NULL;
		}
		void input(){
			cout << "Nhap bac da thuc: "; cin >> n;
			a = new double[n+1];
			cout << "Nhap cac he so da thuc\n";
			for(int i=0; i<=n; i++){
				cout << "a" << i << ": "; cin>>a[i];
			}
		}
		void output(){
			cout << a[0] << "+" << a[1] <<"x";
			for(int i=2; i<=n; i++){
				cout << "+" << a[i] << "x^" << i;
			}
		}
		double value(double x){
			double s=0;
			for(int i=0; i<=n; i++){
				s += a[i]*pow(x, i);
			}
			return s;
		}
};

int main()
{
 	DaThuc f;
 	f.input();
 	f.output();
 	double d;
 	cout << "\nNhap d = "; cin >> d;
 	cout << "f(d) = " << f.value(d);
 	return 0;
}

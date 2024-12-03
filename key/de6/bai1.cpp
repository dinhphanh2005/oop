#include<bits/stdc++.h>
using namespace std;

class DaThuc{
	private:
		int n;
		double *a;
	public:
		friend istream& operator >> (istream &is, DaThuc &f){
			cout << "Nhap bac da thuc: "; is>>f.n;
			f.a = new double[f.n+1];
			cout << "Nhap he so da thuc\n";
			for(int i=0; i<=f.n; i++){
				cout << "Nhap a" << i << ": ";
				is>>f.a[i];
			}
			return is;
		}
		void output(){
			cout << a[0] << "+" << a[1] << "x";
			for(int i=2; i<=n; i++){
				cout << "+" << a[i] << "x^" << i;
			}
		}
		friend double value(DaThuc f, double x){
			double s=0;
			for(int i=0; i<=f.n; i++){
				s += (f.a[i]*pow(x, i));
			}
			return s;
		}
		DaThuc transfer(){
			DaThuc q;
			q.n = n+1;
			q.a = new double[n+2];
			q.a[0] = 2021;
			for(int i=1; i<=q.n; i++){
				q.a[i] = a[i-1];
			}
			return q;
		}
};

int main(){
	DaThuc P;
	cin >> P;
	P.output();
	DaThuc Q = P.transfer();
	cout << "\nQ(x)="; Q.output();
	double d;
	cout << "\nNhap d: "; cin >> d;
	cout << "\nQ(d) = " << value(Q, d);
	return 0;
}
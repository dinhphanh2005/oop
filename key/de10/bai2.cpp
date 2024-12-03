#include<bits/stdc++.h>
using namespace std;

class Dathuc{
	private:
		int n;
		float *a;
	public:
		Dathuc(){
			n = 0;
			a = NULL;
		}
		Dathuc(int n, float *a){
			this->n = n;
			this->a = a;
		}
		friend istream& operator >> (istream &is, Dathuc &f){
			cout << "Nhap bac cua da thuc: "; is >> f.n;
			f.a = new float[f.n+1];
			cout << "Nhap he so cua da thuc\n";
			for(int i=0; i<=f.n; i++){
				cout << "Nhap a" << i <<": "; is >> f.a[i];
			}
			return is;
		}
		friend ostream& operator << (ostream &os, Dathuc &f){
			for(int i=0; i<=f.n; i++){
				os << f.a[i] << "*x^" << i;
				if(i != f.n) os << " + ";
			}
			return os;
		}
		Dathuc operator + (Dathuc f){
			Dathuc g(n, a);
			for(int i=0; i<=n; i++){
				g.a[i] = a[i] + f.a[i];
			}
			return g;
		}
		Dathuc& operator = (Dathuc f){
			n = f.n;
			a = new float[n+1];
			for(int i=0; i<=n; i++){
				a[i] = f.a[i];
			}
			return *this;
		}
};

int main()
{
 	Dathuc a, b;
 	cin >> a;
 	cout << "\na = " << a;
 	b = a;
 	cout << "\nb = " << a;
 	Dathuc c = a+b;
 	cout << "\nc = " << a;
 	return 0;
}

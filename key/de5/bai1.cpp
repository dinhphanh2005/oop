#include<bits/stdc++.h>
using namespace std;

class Diem{
	private:
		double x, y;
	public:
		void input(){
			cout << "Nhap hoanh do: "; cin>>x;
			cout << "Nhap tung do: "; cin>>y;
		}
		void output(){
			cout << "(" << x << ", " << y << ")";
		}
		double length(Diem p){
			return sqrt(pow(x-p.x, 2) + pow(y-p.y, 2));
		}
};

int main()
{
 	int n;
 	cout << "Nhap n: "; cin >> n;
 	Diem a[n];
 	cout << "Nhap thong tin cac diem\n";
 	for(int i=0; i<n; i++){
 		cout << "Nhap thong tin diem thu " << i+1 << "\n";
 		a[i].input();
	}
	double s=0;
	for(int i=2; i<n; i++){
		s += a[i].length(a[i-1]);
	}
	s += a[1].length(a[n-1]);
	cout << "Do dai: " << s;
 	return 0;
}

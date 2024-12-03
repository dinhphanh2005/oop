#include<bits/stdc++.h>
using namespace std;

class Mon_hoc{
	private:
		int ma, soTin;
		string tenMh;
	public:
		void input(){
			cout << "\nNhap ma mon: "; cin >> ma;
			cin.ignore();
			cout << "Nhap ten mon: "; getline(cin, tenMh);
			cout << "Nhap so tin chi: "; cin >> soTin;
		}
		void output(){
			cout << "\nMa mon: " << ma;
			cout << "\nTen mon: " << tenMh;
			cout << "\nSo tin chi: " << soTin;
		}
		int getSoTin(){
			return soTin;
		}
		int getMa(){
			return ma;
		}
};

class DKHP{
	private:
		int msv;
		string tenSv;
		Mon_hoc *ds;
	public:
		int n;
		void input(){
			cout << "\nNhap ma sinh vien: "; cin >> msv;
			cin.ignore();
			cout << "Nhap ten sinh vien: "; getline(cin, tenSv);
			cout << "Nhap so mon dang ky: "; cin >> n;
			ds = new Mon_hoc[n];
			cout << "Dang ky hoc\n";
			for(int i=0; i<n; i++){
				ds[i].input();
			}
		}
		void output(){
			cout << "\nMa sinh vien: " << msv;
			cout << "\nTen sinh vien: " << tenSv;
			cout << "\nDanh sach hoc phan da dang ky\n";
			for(int i=0; i<n; i++){
				ds[i].output();
			}
		}
		int tongTin(){
			int s=0;
			for(int i=0; i<n; i++){
				s += ds[i].getSoTin();
			}
			return s;
		}
		string getTenSv(){
			return tenSv;
		}
		bool getMa(int ma){
			for(int i=0; i<n; i++){
				if(ds[i].getMa()==ma) return true;
			}
			return false;
		}
};

int main()
{
 	int m, n;
 	cout << "Nhap so mon hoc: "; cin >> m;
 	Mon_hoc mh[m];
 	cout << "Nhap danh sach cac mon hoc\n";
 	for(int i=0; i<m; i++){
 		mh[i].input();
	}
	cout << "Nhap so sinh vien: "; cin >> n;
	DKHP sv[n];
	cout << "Nhap ban dang ky hoc phan cua " << n << " sinh vien";
	for(int i=0; i<n; i++){
		sv[i].input();
	}
	cout << "\nThong ke so tin chi cua tung sinh vien";
	for(int i=0; i<n; i++){
		cout << "\n" << i+1 << ".Sinh vien " << sv[i].getTenSv() << ": " << sv[i].tongTin();
	}
	int tim, tk=0;
	cout << "\nNhap ma mon hoc: "; cin >> tim;
	for(int i=0; i<n; i++){
		if(sv[i].getMa(tim)) tk++;
	}
	cout << "\nCo " << tk << " sinh vien da dang ky!";
 	return 0;
}

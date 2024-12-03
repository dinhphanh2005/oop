#include<bits/stdc++.h>
using namespace std;

class NGUOI{
	private:
		string ten;
		int age;
	public:
		void input(){
			cout << "Nhap ho ten: ";
			cin.ignore(); getline(cin, ten);
			cout << "Nhap tuoi: ";
			cin >> age;
		}
		void output(){
			cout << "\nHo ten: " << ten;
			cout << "\nTuoi: " << age;
		}
};

class QLNV:public NGUOI{
	private:
		int snct;
		long luong;
	public:
		void input(){
			NGUOI::input();
			cout << "Nhap so nam cong tac: "; cin >> snct;
			cout << "Nhap luong: "; cin >> luong;
		}
		void output(){
			NGUOI::output();
			cout << "\nSo nam cong tac: " << snct;
			cout << "\nLuong: " << luong;
		}
		long getLuong(){
			return luong;
		}
		int getSnct(){
			return snct;
		}
};

int main()
{
 	int n;
 	cout << "Nhap so nhan vien: "; cin >> n;
 	QLNV a[n];
 	cout << "Nhap thong tin cac nhan vien\n";
 	for(int i=0; i<n; i++){
 		cout << "Nhap thong tin nhan vien thu " << i+1 << "\n";
 		a[i].input();
	}
	double tb=0;
	for(int i=0; i<n; i++){
 		tb += a[i].getLuong()*1.0;
	}
	cout << "\nLuong trung binh cua cac nhan vien: " << tb/n;
	int max=0;
	for(int i=0; i<n; i++){
 		if(a[i].getSnct()>max) max=a[i].getSnct();
	}
	cout << "\nDanh sach cac nhan vien co so nam cong tac cao nhat\n";
	for(int i=0; i<n; i++){
 		if(a[i].getSnct()==max) a[i].output();
	}
 	return 0;
}

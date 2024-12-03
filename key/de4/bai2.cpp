#include<bits/stdc++.h>
using namespace std;

class MatHang{
	private:
		int ma, sl;
		string ten, nsx;
		long gia;
	public:
		MatHang(){
			
		}
		void input(){
			cout << "Nhap ma hang: "; cin >> ma;
			cout << "Nhap ten hang: ";
			cin.ignore(); getline(cin, ten);
			cout << "Nhap nha san xuat: ";
			cin.ignore(); getline(cin, nsx);
			cout << "Nhap so luong: "; cin >> sl;
			cout << "Nhap don gia: "; cin >> gia;
		}
		void output(){
			cout << "\nMa hang: " << ma;
			cout << "\nTen hang: " << ten;
			cout << "\nNha san xuat: " << nsx;
			cout << "\nSo luong: " << sl;
			cout << "\nDon gia: " << gia;
		}
		int getSl(){
			return sl;
		}
		long getGia(){
			return gia;
		}
};

class MayTinh:public MatHang{
	private:
		string cpu, os;
		float g;
	public:
		void input(){
			MatHang::input();
			cout << "Nhap CPU: ";
			cin.ignore(); getline(cin, cpu);
			cout << "Nhap he dieu hanh: ";
			cin.ignore(); getline(cin, os);
			cout << "Nhap trong luong: "; cin >> g;
		}
		void output(){
			MatHang::output();
			cout << "\nCPU: " << cpu;
			cout << "\nHe dieu hanh: " << os;
			cout << "\nTrong luong: " << g;
		}
		string getOs(){
			return os;
		}
};

int main()
{
 	int n;
 	cout << "Nhap so may tinh: "; cin >> n;
 	MayTinh a[n];
 	cout << "Nhap thong tin may tinh\n";
 	for(int i=0; i<n; i++){
 		cout << "Nhap thong tin may " << i+1 << "\n";
 		a[i].input();
	}
	bool het=false, haveWin=false;
	cout << "Danh sach cac loai may dang het hang\n";
	for(int i=0; i<n; i++){
 		if(a[i].getSl()==0){
 			het = true;
 			a[i].output();
		}
	}
	if(!het) cout << "\nKhong co loai nao het hang!";
	long max=0;
	for(int i=0; i<n; i++){
		if(a[i].getOs()=="Windows" && max<a[i].getGia()){
			haveWin = true;
			max = a[i].getGia();
		}
	}
	if(haveWin){
		cout << "\nDanh sach cac may tinh cai he dieu hanh Windows ma co don gia cao nhat\n";
		for(int i=0; i<n; i++){
			if(a[i].getOs()=="Windows" && max==a[i].getGia()){
				a[i].output();
			}
		}
	}
	else cout << "\nKhong co may Windows!";
 	return 0;
}

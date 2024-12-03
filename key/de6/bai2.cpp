#include<bits/stdc++.h>
using namespace std;

class MatHang{
	private:
		int ma;
		string ten, hsx;
		double tg, gia;
	public:
		MatHang(){
			
		}
		MatHang(int ma, string ten, string hsx, double tg, double gia){
			this->ma = ma;
			this->ten = ten;
			this->hsx = hsx;
			this->tg = tg;
			this->gia = gia;
		}
		void input(){
			cout << "Nhap ma: "; cin>>ma;
			cout << "Nhap ten: ";
			cin.ignore(); getline(cin, ten);
			cout << "Nhap hang san xuat: ";
			cin.ignore(); getline(cin, hsx);
			cout << "Nhap thoi gian bao hanh: "; cin >> tg;
			cout << "Nhap don gia: "; cin >> gia;
		}
		void output(){
			cout << "\nMa: " << ma;
			cout << "\nTen: " << ten;
			cout << "\nHang san xuat: " << hsx;
			cout << "\nThoi gian bao hanh: " << tg;
			cout << "\nDon gia: " << gia;
		}
		double getGia(){
			return gia;
		}
};

class DienThoai:public MatHang{
	private:
		string os, cpu;
		double g;
	public:
		void input(){
			MatHang::input();
			cout << "Nhap he dieu hanh: ";
			cin.ignore(); getline(cin, os);
			cout << "Nhap bo xu ly: ";
			cin.ignore(); getline(cin, cpu);
			cout << "Nhap trong luong: "; cin >> g;
		}
		void output(){
			MatHang::output();
			cout << "\nHe dieu hanh: " << os;
			cout << "\nBo xu ly: " << cpu;
			cout << "\nTrong luong: " << g; 
		}
		string getOs(){
			return os;
		}
};

int main()
{
 	int n, d=0, max=0;
 	cout << "Nhap so dien thoai: "; cin >> n;
 	DienThoai a[n];
 	cout << "Nhap thong tin cac dien thoai\n";
 	for(int i=0; i<n; i++){
 		cout << "Nhap thong tin dien thoai thu " << i+1 << "\n";
 		a[i].input();
	}
	double x, y;
	cout << "Nhap gia min: "; cin >> x;
	cout << "Nhap gia max: "; cin >> y;
	for(int i=0; i<n; i++){
		if(a[i].getGia()>=x && a[i].getGia()<=y) a[i].output();
	}
	if(d==0) cout << "\nKhong tim thay!";
	bool find = false;
	string fos;
	cout << "\nNhap he dieu hanh quan tam: ";
	cin.ignore(1); getline(cin, fos);
	for(int i=0; i<n; i++){
		if(a[i].getOs()==fos && max<a[i].getGia()){
			find = true;
			max = a[i].getGia();
		}
	}
	if(find){
		for(int i=0; i<n; i++){
			if(a[i].getOs()==fos && max==a[i].getGia()){
				a[i].output();
			}
		}
	}
	else cout << "\nKhong tim thay!";
 	return 0;
}

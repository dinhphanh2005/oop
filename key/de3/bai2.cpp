#include<bits/stdc++.h>
using namespace std;

class QLH{
	private:
		int ma, loai, sl;
		string ten, xs;
	public:
		void input(){
			cout << "Nhap ma hang: "; cin >> ma;
			cin.ignore();
			cout << "Nhap ten hang: "; 
			getline(cin, ten);
			cout << "Nhap xuat xu: ";
			getline(cin, xs);
			cout << "Nhap loai hang: "; cin >> loai;
			cout << "Nhap so luong: "; cin >> sl;
		}
		void output(){
			cout << "\nMa hang: " << ma;
			cout << "\nTen hang: " << ten;
			cout << "\nXuat xu: " << xs;
			cout << "\nLoai hang: " << loai;
			cout << "\nSo luong: " << sl;
		}
		int getLoai(){
			return loai;
		}
};

class DIENTU:public QLH {
	private:
		int tgbh;
	public:
		void input(){
			QLH::input();
			cout << "Nhap thoi gian bao hanh: "; cin >> tgbh;
		}
		void output(){
			QLH::output();
			cout << "\nThoi gian bao hanh: " << tgbh;
		}
		int getTgbh(){
			return tgbh;
		}
};

int main()
{
 	int n;
 	cout << "Nhap so mat hang: "; cin >> n;
 	DIENTU a[n];
 	cout << "Nhap danh sach hang dien tu";
 	for(int i=0; i<n; i++){
 		cout << "\nNhap mat hang thu " << i+1 << "\n";
 		a[i].input();
	}
	int l1, l2, l3;
	l1 = l2 = l3 = 0;
	for(int i=0; i<n; i++){
		if(a[i].getLoai()==1) l1++;
		if(a[i].getLoai()==2) l2++;
		if(a[i].getLoai()==3) l3++;
	}
	cout << "Co " << l1 << " loai hang 1\n";
	cout << "Co " << l2 << " loai hang 2\n";
	cout << "Co " << l3 << " loai hang 3\n";
	if(l1==0){
		cout << "Khong co loai hang 1";
	}
	else {
		int oldest = 0;
		for(int i=0; i<n; i++){
			if(a[i].getLoai()==1 && a[i].getTgbh()>oldest){
				oldest = a[i].getTgbh();
			}
		}
		for(int i=0; i<n; i++){
			if(a[i].getLoai()==1 && a[i].getTgbh()==oldest){
				a[i].output();
			}
		}
	}
 	return 0;
}

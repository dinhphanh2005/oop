#include<bits/stdc++.h>
using namespace std;

class Ds_nguyen{
	private:
		int n;
		int *a;
	public:
		friend istream& operator >> (istream &is, Ds_nguyen &ds){
			cout << "Nhap so phan tu: "; is >> ds.n;
			ds.a = new int[ds.n];
			cout << "Nhap day so:\n";
			for(int i=0; i<ds.n; i++){
				cout << "Phan tu " << i+1 << ": ";
				is >> ds.a[i];
			}
			return is;
		}
		float TBC(){
			int s=0, po=0;
			for(int i=0; i<n; i++){
				if(a[i]>0){
					s += a[i];
					po++;
				}
				
			}
			if(po==0){
				return 0;
			}
			return s*1.0/po;
		}
		int SoCP(){
			int dem=0;
			for(int i=0; i<n; i++){
				for(int j=0; j*j<=a[i]; j++){
					if(j*j==a[i]) dem++;
				}
			}
			return dem;
		}
};

int main()
{
 	Ds_nguyen ds;
 	cin >> ds;
 	float avgP = ds.TBC();
 	if(avgP==0) cout << "\nKhong co so duong";
 	else cout << "\nTrung binh cong cac so duong = " << avgP;
 	cout << "\nDay co " << ds.SoCP() << " so chinh phuong.";
 	return 0;
}

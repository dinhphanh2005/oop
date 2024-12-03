#include<bits/stdc++.h>
using namespace std;

class Diem{
	private:
		float x, y;
	public:
		Diem(){
			x = y = 0;
		}
		Diem(float x, float y){
			this->x = x;
			this->y = y;
		}
		friend istream& operator >> (istream &is, Diem &p){
			cout << "Nhap hoanh do: "; is >> p.x;
			cout << "Nhap tung do: "; is >> p.y;
			return is;
		}
		friend ostream& operator << (ostream &os, Diem &p){
			os << "(" << p.x << ", " << p.y << ")";
			return os;
		}
		bool operator == (Diem p){
			if(x==p.x && y==p.y) return true;
			return false;
		}
		Diem operator * (Diem p){
			Diem result;
			result.x = x*p.x;
			result.y = y*p.y;
			return result;
		}
		float kc(Diem p){
			return sqrt(pow(x-p.x, 2) + pow(y-p.y, 2));
		}
};

int main()
{
 	Diem A, B(4, 5);
 	cin >> A;
 	Diem C = A*B;
 	cout << "\nToa do diem A*B: " << C;
 	if(A==B) cout << "\nA trung B";
 	else cout << "\nA khac B";
 	return 0;
}

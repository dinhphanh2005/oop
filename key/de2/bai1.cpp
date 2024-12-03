#include<bits/stdc++.h>
using namespace std;

class PS{
	private:
		int ts, ms;
	public:
		PS(){
			
		}
		PS(int a, int b){
			ts = a;
			ms = b;
		}
		friend istream& operator >> (istream &is, PS &p){
			cout << "Nhap tu so: "; is >> p.ts;
			cout << "Nhap mau so: "; is >> p.ms;
			return is;
		}
		friend ostream& operator << (ostream &os, PS &p){
			int UCLN = __gcd(p.ts, p.ms);
			p.ts = p.ts/UCLN;
			p.ms = p.ms/UCLN;
			os << p.ts << "/" << p.ms;
			return os;
		}
		PS operator * (PS p){
			PS result;
			result.ts = ts*p.ts;
			result.ms = ms*p.ms;
			return result;
		}
};

int main()
{
 	PS p1(1, 2), p2;
 	cin >> p2;
 	PS p = p1*p2;
 	cout << "\np1 = " << p1;
 	cout << "\np2 = " << p2;
 	cout << "\np = " << p;
 	return 0;
}

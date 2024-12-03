#include<bits/stdc++.h>
using namespace std;

class PS{
	private:
		int ts, ms;
	public:
		void input(){
			cout << "Nhap tu: "; cin >> ts;
			cout << "Nhap mau: "; cin >> ms;
		}
		void output(){
			cout << ts << "/" << ms;
		}
		PS operator + (PS p){
			PS sum;
			sum.ts = p.ts*ms + ts*p.ms;
			sum.ms = ms*p.ms;
			return sum;
		}
};

int main()
{
 	PS p1, p2;
 	p1.input();
 	p2.input();
 	PS s = p1 + p2;
 	s.output();
 	return 0;
}

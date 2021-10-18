/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/

#include <iostream>
#include <string>
#include <complex>
#include <cstring>
#include <vector>

using namespace std;

int f(char x) {  return x; }
int f(int x) { return x+1;}
int f(float x) { return 5/x;}
int f(double x) { return x;}
int f(const char x[]) { return strlen(x);}
int f(string x) { return x.size()+1;}

template<typename T>
int g(T x) { return f(x);}

int main(){
string s("4");
cout<<g(4)<<g<float>(4)<<g(4.)<<g<int>('4')<<endl;
cout<<g("4")<<g(s)<<g("444")<<g<string>("444")<<endl;
int a(5),b(a),&c(a);
const int d(a), &e(a), &r(a+0);
a+=2;
cout<<a<<b<<c<<d<<e<<f<<endl;
double u(9);
complex<double> v(u), W(-v);
cout<<sqrt(u)<<setw(7)<<sqrt(v)<<" "<<sqrt(w)<<endl;
return 0;
}

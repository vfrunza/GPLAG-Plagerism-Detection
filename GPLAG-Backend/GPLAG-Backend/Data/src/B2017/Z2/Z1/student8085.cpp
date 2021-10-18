/*B 2017/2018, Zadaća 2, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <memory>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
std::function<int(int)>f(std::function<int(int,int)>g,int n){
	return [g,n](int x){ return g(g(x,n+1),n-1);};
}

template <typename T>
void g(T f, int &x, int y, int &z){
	f(x);
	f(y);
	f(z);
}
int main ()
{
	int a(3),b(4),c(5),d(6);
	g([&c](int x){ x++; c++; return x+c;},a,a,a);
	std::cout<<a<<" "<<c<<std::endl;
	g([&d](int &x){ x++; d++; return x+d;},b,b,b);
	std::cout<<b<<" "<<d<<std::endl;
	std::unique_ptr<int>p(new int[5]{3,4,2,7,1});
	auto p1(p.get()+3);
	for(int i=-2; i<=1; i++) std::cout<<p1[i]<<" ";
	std::cout<<std::endl;
	std::priority_queue<int> q;
	q.push(3); q.push(5); q.push(2); q.push(8);
	while(!q.empty()){
		std::cout<<q.top()<<" ";
		q.pop();
	}
	std::cout<<std::endl;
	std::vector<int> v{3,5,2,7,6};
	std::set<int> s{4,8,1,6,3,4,2,8};
	std::copy(s.rbegin(),s.rend(),std::inserter(v,v.begin()+3));
	for(auto x: v) std::cout<<x<<" ";
	std::cout<<std::endl;
	std::cout<<f([](double  x, double y) { return 2*x+3*y; },3)(2);
	return 0;
}
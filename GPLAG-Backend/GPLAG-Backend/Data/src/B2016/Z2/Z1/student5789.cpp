/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>

template<typename T, typename T2>
typedef std::vector<std::vector<T2>> Matrica;

Matrica UvrnutiPresjek(T p1, T p2, T2 p3, T2 p4, T2 f(T2)){
	Matrica m;
	int n=1;
	while(p1!=p2 && p3!=p4){
		T c1=f(*p1);
		T c2=f(*p3);
		if(c1==c2){
			m.resize(n);
			n++;
			
		}
	}
}
int main ()
{
	return 0;
}
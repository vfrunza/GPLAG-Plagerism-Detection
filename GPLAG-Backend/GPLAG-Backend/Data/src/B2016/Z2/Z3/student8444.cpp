/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
template <typename tip, typename tip1, typename Povratni>
auto UvrnutiPresjek(tip p1,tip p2, tip1 p3, tip1 p4, Povratni f(Povratni))-> decltype(*p1) {
	auto pomocna(*p1);
	std::set<decltype(pomocna)> skup;
	Povratni *vrati=skup[0];
	while(p1!=p2 && p3!=p4){
		if(f(*p1)==f(*p3) || f(*p3)==f(*p1)){
			*vrati=*p1;
			++vrati;++p1;++p3;
		}
		else if(f(*p1)<f(*p3))++p1;
		else if(f(*p3)<f(*p1))++p3;
		
	}
	int n=skup.size();
	std::vector<std::vector<decltype(pomocna)>> matrica(n,std::vector<decltype(pomocna)> (3));
}

int main ()
{
	return 0;
}
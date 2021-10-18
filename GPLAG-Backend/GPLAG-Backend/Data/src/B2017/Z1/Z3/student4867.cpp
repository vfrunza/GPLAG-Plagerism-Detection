/*B 2017/2018, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>
#include <deque>

bool JeLiStepen2 (int n) {
	
	while(n!=1) {
		if(n%2!=0) return false;
		else n/=2;
	}
	return true;
}
std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke (std::vector<int> v, enum Smjer{Rastuci, Opadajuci}) {
	
	//izbacuje one koji nisu stepeni 2
	for(int i=0; i<v.size(); i++) {
		if(!JeLiStepen2(v.at(i)))
		v.erase(v.begin()+i);
	}
	std::deque<std::vector<int>> v1;
	
	
}


int main ()
{
	return 0;
}
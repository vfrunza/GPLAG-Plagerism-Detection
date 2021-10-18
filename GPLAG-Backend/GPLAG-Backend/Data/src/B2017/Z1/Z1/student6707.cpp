/*B 2017/2018, Zadaća 1, Zadatak 1
	
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

bool DaLiJeProst(int n){
	int prost = true;
	
	if( n == 2) return true;
	if(n < 2 ) return false;
	for(int i = 2 ; i <= std::sqrt(n); i++){
		if(n%i == 0){
			prost = false;
			break;
		}
	}
	
	if(prost) return true;
	else return false;
}

std::vector<int> Simetrican(int broj){
	std::vector<int> vektor; 
		
	int suma(0);
	for(int i = 0 ; i < n ; i++){
		int x = 
		
	}
}
std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> vektor, bool provjera){
	std::vector<int> vektor_prostih;
	std::vector<int> vektor_slozenih;
}

int main ()
{
	return 0;
}
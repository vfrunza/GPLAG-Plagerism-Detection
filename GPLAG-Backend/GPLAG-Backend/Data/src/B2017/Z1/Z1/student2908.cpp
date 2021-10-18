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
#include <cmath>

typedef std::vector<int> vektor;

vektor ProstiSlozeni(vektor v, bool kakvi)
{
	vektor pov;
	for(int i=0; i<v.size(); i++) {
		int broj;
		bool prost(true);
		broj=v.at(i);
		if(broj<0) broj=std::abs(broj);
		for(int j=2; j<broj; j++) {
			if(broj%i==0) {
				prost=false;
				break;
			}
		}
		if(kakvi==prost) pov.push_back(v.at(i));
		prost=true;
	}
	return pov;
}

void BrojUTernarni(vektor v)
{
	int suma(0), ostatak(0), i(1);
	for(int i=0; i<v.size(); i++) {
		do {
			
		} while(v.at(i)>0)
	}
}

int main ()
{
	return 0;
}
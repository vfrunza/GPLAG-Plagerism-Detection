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

typedef std::deque<std::vector<int>> DekVektora;

bool StepenDvojke(int a){
	int broj;
	for(int i=1; i<=broj; i*=2){
		if(broj==i) return true;
	}
	return false;
}

DekVektora MaksimalniPodnizoviStepenaDvojke(std::vector<int> vektor, enum Smjer a){
	DekVektora dek;
	
	int broj_elemenata(0), brojac(1);
	
	for(int i=0; i<vektor.size()-1; i++){
		if(vektor[i]>vektor[i+1]){
			dek.resize(brojac);
			if(!StepenDvojke(vektor[i]) || !StepenDvojke(vektor[i])) continue;
			dek[broj_elemenata].push_back(vektor[i]);
			dek[broj_elemenata].push_back(vektor[i+1]);
		}
		brojac++, broj_elemenata++,i++;
		while(vektor(i)>vektor(i+1)){
			if(!StepenDvojke(vektor[i]) || !StepenDvojke(vektor[i+1])) continue;
			dek[broj_elemenata].push_back(vektor[i]);
			dek[broj_elemenata].push_back(vektor[i+1]);
		}
		i++; broj_elemenata++; brojac++;
		
	}
	std::vector<int> NajveciPodniz;
	for(i=0; i<broj_elemenata; i++){
		if(dek[i]>dek[i+1]) dek[i]=NajveciPodniz;
	}
	
}


int main ()
{
	return 0;
}
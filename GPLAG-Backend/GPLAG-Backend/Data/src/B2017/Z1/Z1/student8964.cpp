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

bool DaLiJeProst (int n) {
	if(n==1 || n==0 || n==-1) return false; //0 i 1 nisu ni prosti ni slozeni, o ovome povesti racuna
	for(int i(2); i <= std::sqrt(std::abs(n)); i++) {
		if (n%i == 0)
		return false;
	}
	return true; //true vraca ako je broj prost, false ako nije prost
}


long long int Ternarni (int n) {
	int znak(1);
	if(n < 0) {
		znak = -1;	
		n *= -1;	
	}
	int ostatak(0), stepen(0);
	long long int broj(0);
	while(n > 0) {
		ostatak = n % 3;
		broj += ostatak * std::pow(10, stepen);
		stepen++;
		n /=3;
	}
	std::cout<<broj<<std::endl;
	return broj * znak;		
}

bool Simetricni (long long int n) {
	long long int ternarni = Ternarni(n);
	long long int ternarni2 = ternarni, naopaki = 0;
	int znak(1);
	if(ternarni2 < 0) { 
		znak = -1;
		ternarni2 *= -1;
	}
	while(ternarni2 > 0) {
		naopaki = naopaki*10 + ternarni2%10;
		ternarni2 /=10;
	}
	if(naopaki*znak == ternarni) return true;
	else return false;
}

std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> v, bool logicka) {
	std::vector<int> finalni;
	if(logicka) {
		for(int i(0); i<v.size(); i++) {
			if(DaLiJeProst(v.at(i))) {
				if(Simetricni(v.at(i)) && Simetricni(v.at(i))!=-1) {
					finalni.push_back(v.at(i));
					int brojac_ponavljanja(0);
					for(int k(0); k < finalni.size(); k++) {  //algoritam da izbaca duple
						if(finalni.at(k) == v.at(i))
						brojac_ponavljanja++;
					}
					if(brojac_ponavljanja > 1) 
					finalni.resize(finalni.size() - brojac_ponavljanja+1);
				}
			}
		}
	}
	else {
		for(int i(0); i<v.size(); i++) {
			if(!DaLiJeProst(v.at(i))  && v.at(i)!=1 && v.at(i)!=-1) {
				if(Simetricni(v.at(i)))
				finalni.push_back(v.at(i));
				int brojac_ponavljanja(0);
				for(int k(0); k < finalni.size(); k++) {
					if(finalni.at(k) == v.at(i))
					brojac_ponavljanja++;
				}
				if(brojac_ponavljanja > 1)
				finalni.resize(finalni.size() - brojac_ponavljanja+1);
			}
		}
	}
	//ovaj algoritam ne radi 100% pravilno
	return finalni;
}

int main ()
{
	std::vector<int> v;
	long long int broj;
	
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	do {
		std::cin>>broj;
		if(broj != -1) v.push_back(broj);
	} while(broj != -1);
	
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int logicka;
	do {
		std::cin>>logicka;
		if(logicka != 1 && logicka != 0) std::cout<<"Neispravan unos! Unesite ponovo: ";
	} while(logicka != 1 && logicka != 0);
	
	std::vector<int> finalni;
	if(logicka) {
		finalni = IzdvojiSimetricneTernarne(v, logicka);
		if(finalni.size() == 0) {
			std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
			return 0;
		}
		else {
			std::cout<<"Prosti simetricni brojevi iz vektora su:";
			for(int i(0); i < finalni.size(); i++) {
				if(i < finalni.size()-1 )
				std::cout<<" "<<finalni.at(i)<<",";
				else std::cout<<" "<<finalni.at(i)<<".";
			}	
		}
	}
	else {
		finalni = IzdvojiSimetricneTernarne(v, logicka);
		if(finalni.size() == 0) {
			std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
			return 0;
		}
		else {
			std::cout<<"Slozeni simetricni brojevi iz vektora su:";
			for(int i(0); i < finalni.size(); i++) {
			if(i < finalni.size()-1 )
				std::cout<<" "<<finalni.at(i)<<",";
				else std::cout<<" "<<finalni.at(i)<<".";
			}
		}
	}
	return 0;
}
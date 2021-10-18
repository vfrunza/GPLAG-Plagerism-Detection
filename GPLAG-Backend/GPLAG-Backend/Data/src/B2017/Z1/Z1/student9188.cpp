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
std::vector<int> izbaci_iste(std::vector<int> v)
{
	for(int i=0; i<v.size(); i++) {
		for(int j=i; j<v.size(); j++) {
			if(v.at(i)==v.at(j) && i!=j) {
				v.erase(v.begin()+j);
				j--;
			}
		}
	}
	return v;
}
bool simetricni_ternarni(int k)
{
	std::vector<int> v;
	while(k!=0) {
		int a(std::abs(k%3));
		v.push_back(a);
		k/=3;
	}
	std::vector<int> v2;
	for(int i=(int)v.size()-1; i>=0; i--) {
		v2.push_back(v.at(i));
	}
	return v2 != v ? false : true;
}
bool DaLiJeProst(int n)
{
	if(n==1 || n==0 || n==-1) return false;
	for(int i=2; i<=sqrt(llabs(n)); i++) {
		if(llabs(n)%i==0) return false;
	}
	return true;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v, bool prosti_ili_slozeni)
{
	if(v.size()==0) return v;
	std::vector<int> simetricni;
	if(prosti_ili_slozeni) {
		for(int i=0; i<(int)v.size(); i++) {
			if(DaLiJeProst(v.at(i)) && simetricni_ternarni(v.at(i))) {
				simetricni.push_back(v.at(i));
			}
		}
		simetricni=izbaci_iste(simetricni);
		return simetricni;
	} else {
		for(int i=0; i<(int)v.size(); i++) {
			if(!DaLiJeProst(v.at(i))  && simetricni_ternarni((v.at(i)))) {
				simetricni.push_back(v.at(i));
			}

		}
		simetricni=izbaci_iste(simetricni);
		return simetricni;

	}

}

int main ()
{
	std::vector<int> brojevi;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	int n;
	do{
		std::cin>>n;
		if(n!=-1) 	brojevi.push_back(n);
	}while(n!=-1);
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int logicka;
	for(;;) {
		std::cin>>logicka;
		if(logicka==0 || logicka==1) break;
		else std::cout<<"Neispravan unos! Unesite ponovo: ";
	}
	if(logicka) {

		auto k=IzdvojiSimetricneTernarne(brojevi,logicka);
		if(k.size()==0) {
			std::cout<<"Nema prostih simetricnih brojeva u vektoru.";

		} else {
			std::cout<<"Prosti simetricni brojevi iz vektora su: ";
			for(int i=0; i<(int)k.size(); i++) {
				if(i!=k.size()-1)
					std::cout<<k.at(i)<<", ";
				else std::cout<<k.at(i)<<".";
			}
		}
	} else {

		auto k=IzdvojiSimetricneTernarne(brojevi,logicka);
		if(k.size()==0) {
			std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";

		} else {
			std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
			for(int i=0; i<(int)k.size(); i++) {
				if(i!=k.size()-1)
					std::cout<<k.at(i)<<", ";
				else	std::cout<<k.at(i)<<".";
			}
		}
	}
	return 0;

}
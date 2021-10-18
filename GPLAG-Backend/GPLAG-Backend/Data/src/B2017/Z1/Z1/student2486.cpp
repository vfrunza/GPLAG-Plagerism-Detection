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
#include <cmath>
#include <vector>

bool DaLiJeProst (int x) {
	if (x<0) x=x*(-1);
	if (x==1) return false;
	for (int i=2; i<=std::sqrt(x); i++) {
		if (x%i==0) return false;
	}
	return true;
}

int BrojCifara1 (int pomocna) {
	int broj_cifara(0);
	while (pomocna!=0) {
		pomocna=pomocna/3;
		broj_cifara++;
	}
	return broj_cifara;
}

int BrojCifara2 (int pomocna) {
	int broj_cifara(0);
	while (pomocna!=0) {
		pomocna=pomocna/10;
		broj_cifara++;
	}
	return broj_cifara;
}

int PretvoriUTernarni (int x) {
	if (x<0) x=x*(-1);
	int brc=BrojCifara1(x), ternarni_broj(0);
	float x1(x);
	for (int i=0; i<brc; i++) {
		x1=(int)x1/3.;
		int ostatak;
		if (x1-(int)x1>0.5) ostatak=2;
		else if (x1-(int)x1>0.3 && x1-(int)x1<0.5) ostatak=1;
		else ostatak=0;
		ternarni_broj=ternarni_broj+ostatak*pow(10,i);
	}
	return ternarni_broj;
}

bool DaLiJeSimetrican (int x) {
	int a=BrojCifara2(x), novibroj(0), x1(x), ZaMnozenje(0);
	for (int i=a-1; i>=0; i--) {
		ZaMnozenje=x1%10;
		novibroj+=ZaMnozenje*pow(10,i);
		x1=x1/10;
	}
	if (x==novibroj) return true;
	else return false;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v, bool prost) {
	int a=v.size();
	if (prost==true) {
		std::vector<int> V1;
		std::vector<int> V;
		bool isti(false);
		for (int i=0; i<a; i++) {
			for (int j=0; j<i; j++) {
				if (v.at(i)==v.at(j)) {
					isti=true;
					break;
				}
			}
			if (isti==true) continue;
			bool pbroj=DaLiJeProst(v.at(i));
			if (pbroj==true) {
				int x=PretvoriUTernarni(v.at(i));
				bool b=DaLiJeSimetrican(x);
				if (b==true) V.push_back(v.at(i));
			}
		}
		return V;
	}
	else {
		std::vector<int>V2;
		std::vector<int>V;
		bool isti(false);
		for (int i=0; i<a; i++) {
			for (int j=0; j<i; j++) {
				if (v.at(i)==v.at(j)) {
					isti=true;
					break;
				}
			}
			if (isti==true) continue;
			bool prbroj=DaLiJeProst(v.at(i));
			if (prbroj==false) {
				int x=PretvoriUTernarni(v.at(i));
				bool b=DaLiJeSimetrican(x);
				if (b==true) V.push_back(v.at(i));
			}
		}
		return V;
	}
}


int main ()
{
	std::vector<int> v;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	for (;;) {
		int broj;
		std::cin>>broj;
		if (broj==-1) break;
		else v.push_back(broj);
	}
	int odluka;
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: "; 
	for (;;) {
		std::cin>>odluka;
		if (odluka==1 || odluka==0) break;
		std::cout<<"Neispravan unos! Unesite ponovo: ";
	}
	std::vector<int> trazeni(IzdvojiSimetricneTernarne(v,odluka));
	if (odluka==true) {
		if (trazeni.size()==0) std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		else std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		for (int i=0; i<trazeni.size(); i++) {
			if (i==trazeni.size()-1) std::cout<< trazeni.at(i) <<".";
			else std::cout<< trazeni.at(i) <<", ";
		}
	}
	else {
		if (trazeni.size()==0) std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		else std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for (int i=0; i<trazeni.size(); i++) {
			if (i==trazeni.size()-1) std::cout<< trazeni.at(i) <<".";
			else std::cout<< trazeni.at(i) <<", ";
		}
	}
	return 0;
}








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
#include <sstream>

typedef std::vector<int> Vektor;

int BrojCifara(int n) {
	int brojac=0;
	while(n!=0) {
		brojac++;
		n/=10;
	}
	return brojac;
}

int PretvoriUTernarni(int n) {
	int e;
	Vektor Niz;
	while(n!=0) {
		e=n%3;
		Niz.push_back(e);
		n/=3;
	}
	
	int Ter(0), k(1);
	
	for(int i=0; i<Niz.size(); i++) {
		Ter+=Niz.at(i)*k;
		k*=10;
	}
	
	return Ter;
}

template <typename T> std::string PretvoriUString(T x) {
	std::ostringstream s; 
	s << x;
	return s.str();
}


bool DaLiJeSimetrican (int n) {
	bool Symmetric(true);
	int e = PretvoriUTernarni(n);
	std::string TerString(PretvoriUString(e));
	
	int j;
	j=BrojCifara(e)-1;
	for(int i=0; i<BrojCifara(e); i++) {
		if(i==j || j<i) break;
		if(TerString.at(i)!=TerString.at(j)) { 
			Symmetric=false;
			break;
		}
		j--;
	}
	
	return Symmetric;
}

bool DaLiJeProst (int n) {
	if(n==0 || n==1) return false;
	for(int i=2; i<=sqrt(n); i++) {
		if(n%i==0) {
			return false;
		}
	}
	return true;
}

Vektor IzdvojiSimetricneTernarne(Vektor v, bool a) {
	Vektor SimTer;
	for(int i=0; i<v.size(); i++) {
		if(a) {
			if(DaLiJeProst(abs(v.at(i)))==true && DaLiJeSimetrican(abs(v.at(i)))==true) {
				SimTer.push_back(v[i]);
			}
		}
		else if(!a) { 
			if(DaLiJeProst(abs(v.at(i)))==false && DaLiJeSimetrican(abs(v.at(i)))==true) {
				SimTer.push_back(v[i]);
			}
		}
	}
	return SimTer;
}

int main ()
{
	Vektor Brojevi;
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	for(int i=0; ; i++) {
		int n;
		std::cin >> n;
		if(n==-1) break;
		Brojevi.push_back(n);
	}
	
	int a1;
	
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	do {
		std::cin >> a1;
		if(a1!=0 && a1!=1) std::cout << "Neispravan unos! Unesite ponovo: ";
	} while(a1!=0 && a1!=1);
	
	bool a(a1);
	
	Vektor Izdvojeni = IzdvojiSimetricneTernarne(Brojevi, a);
	
	if(a) {
		if(Izdvojeni.size()==0) { 
			std::cout << "Nema prostih simetricnih brojeva u vektoru.";
			return 0;;
		}
		std::cout << "Prosti simetricni brojevi iz vektora su: ";
		for(int i=0; i<Izdvojeni.size(); i++) {
			if(i==Izdvojeni.size()-1) 
				std::cout << Izdvojeni[i] << ".";
			else 
				std::cout << Izdvojeni[i] << ", ";
		}
	}
	
	else if(!a) {
		if(Izdvojeni.size()==0) {
			std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
			return 0;
		}
		std::cout << "Slozeni simetricni brojevi iz vektora su: ";
		for(int i=0; i<Izdvojeni.size(); i++) {
			if(i==Izdvojeni.size()-1) 
				std::cout << Izdvojeni[i] << ".";
			else 
				std::cout << Izdvojeni[i] << ", ";
		}
	}
	
	return 0;
}
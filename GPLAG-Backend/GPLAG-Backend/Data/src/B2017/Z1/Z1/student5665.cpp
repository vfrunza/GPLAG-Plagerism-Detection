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
#include <deque>

typedef std::vector<int> Vektor;
typedef std::deque<int> Dek;


bool ProstiSlozeni (int n) {
	
	for (int i=2; i<=sqrt(n); i++)
		if (n%i==0)
			return false;

	return true;
}


Dek Ternarni (int n) {
	
	Dek ternar;
	
	while (n>0) {
		ternar.push_front(n%3);
		n/=3;
	}

	return ternar;
}


bool Simetrican (int n) {
	
	Dek original=Ternarni(n);
	Dek naopako;
	
	for (int i=original.size()-1; i>=0; i--)
		naopako.push_back(original.at(i));
	
	if (original==naopako) return true;
	
	return false;
}


Vektor StopPonavljanju(Vektor v) {
	
	int trenutni;
	
	for (int i=0; i<v.size(); i++) {
		trenutni=v.at(i);
		for (int j=i+1; j<v.size(); j++)
			if (v.at(j)==trenutni) {
				v.erase(v.begin()+j);
				j--;
			}
	}
	
	return v;
}


Vektor IzbaciUljeze(Vektor v) {
	
	for (int i=0; i<v.size(); i++)
		if (abs(v.at(i))<=1 || Simetrican(abs(v.at(i)))==false) {
			v.erase(v.begin()+i);
				i--;
		}

	return v;
}


Vektor IzdvojiSimetricneTernarne (Vektor v, bool ps) {
	
	v=IzbaciUljeze(v);
	
	
	if (ps==true)
		for (int i=0; i<v.size(); i++)
			if (ProstiSlozeni(abs(v.at(i)))==false) {
				v.erase(v.begin()+i);
				i--;
			}
		
	if (ps==false)
		for (int i=0; i<v.size(); i++)
			if (ProstiSlozeni(abs(v.at(i)))==true) {
				v.erase(v.begin()+i);
				i--;
			}


	v=StopPonavljanju(v);

	return v;
}


int main ()
{
	Vektor brojevi;
	int n(-1);
	
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	for (;;) {
		std::cin >> n;
		if (n==-1) break;
		brojevi.push_back(n);
	}
	
	int opcija(-1);
	
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	for (;;) {
		std::cin >> opcija;
		if (opcija==1 || opcija==0) break;
		std::cout << "Neispravan unos! Unesite ponovo: ";
	}
	
	brojevi=IzdvojiSimetricneTernarne(brojevi, opcija);
	
	if (brojevi.size()==0 && opcija==1) {
		std::cout << "Nema prostih simetricnih brojeva u vektoru.";
		return 0;
	}
	
	if (brojevi.size()==0 && opcija==0) {
		std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
		return 0;
	}
	
	if (opcija==1) std::cout << "Prosti simetricni brojevi iz vektora su: ";
	if (opcija==0) std::cout << "Slozeni simetricni brojevi iz vektora su: ";
	
	for (int i=0; i<brojevi.size(); i++) {
		if (i==brojevi.size()-1) std::cout << brojevi.at(i) << "." << std::endl;
		else std::cout << brojevi.at(i) << ", ";
	}
	
	return 0;
}
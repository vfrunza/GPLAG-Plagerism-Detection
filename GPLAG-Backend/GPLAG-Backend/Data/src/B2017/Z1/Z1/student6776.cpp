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
#include <limits>
#define e std::numeric_limits<double>::min()

int Napravi_Ternarni(int a)
{
	int ternarni(0);
	while(a!=0) {
		ternarni=ternarni*10+a%3;
		a/=3;
	}
	return ternarni;
}

int Obrni_Cifre (int x)
{
	int broj(0);
	while(x!=0) {
		broj=broj*10+x%10;
		x/=10;
	}
	return broj;
}

bool DaLiJeProst(int n)
{
	if(n<2) return false;
	int x(sqrt(n));
	while(x>1) {
		if(n%x==0) {
			return false;
		}
		x--;
	}
	return true;
}

bool Prost_Slozen (int n)
{
	if (n<0) {
		n=-n;
	}
	if(n<2) return true;
	int x(sqrt(n));
	while(x>1) {
		if(n%x==0) {
			return false;
		}
		x--;
	}
	return true;
}

std::vector<int> Formiranje_Vektora (std::vector<int> v)
{
	std::vector<int> vektor;
	for(auto x:v) {
		bool ima(false);
		int ternarni(Napravi_Ternarni(x));
		if(ternarni==Obrni_Cifre(ternarni)) {
			for(auto n:vektor) {
				if(x==n) {
					ima=true;
					break;
				}
			}
			if(ima) { //treba nekad znati izbaciti uslov izvan petlje
				continue;
			} else {
				vektor.push_back(x);
			}
		}
	}
	return vektor;
}

std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> v, bool logicka)
{
	std::vector<int> prosti(v.size());
	std::vector<int> slozeni(v.size());
	int p(0),s(0);
	for(int i(0) ; i<v.size() ; i++) {
		if(Prost_Slozen(v.at(i))) {
			prosti.at(p)=v.at(i);
			p++;
		} else {
			slozeni.at(s)=v.at(i);
			s++;
		}
	}
	prosti.resize(p);
	slozeni.resize(s);
	std::vector<int> simetricni_ternarni;
	if(logicka) {
		simetricni_ternarni=Formiranje_Vektora(prosti);
	} else {
		simetricni_ternarni=Formiranje_Vektora(slozeni);
	}
	return simetricni_ternarni;
}

void Ispisi(std::vector<int> v)
{
	for(int i(0) ; i<v.size() ; i++) {
		if(i==int(v.size())-1) {
			std::cout << v.at(i) << ".";
			break;
		}
		std::cout << v.at(i) << ", ";
	}
}
void Poruka()
{
	std::cout << "Neispravan unos! Unesite ponovo: ";
}

int main ()
{
	// ispis je kopiran iz autotesta
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	std::vector<int> v;
	while(1) { //beskrajna petlja
		int element;
		std::cin >> element;
		if(element!=-1) {
			v.push_back(element);
		} else {
			break;
		}
	}
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int unos;
	for(;;) { //jos jedna beskrajna petlja
		double opcija;
		std::cin >> opcija;
		unos=opcija;
		if(unos==1 || unos==0) {
			if(fabs(opcija-unos)>e) {
				Poruka();
				continue;
			}
			break;
		} else {
			Poruka();
			continue;
		}
	}
	switch(unos) {
	case 0:

		v=IzdvojiSimetricneTernarne(v,false);
		if(v.size()==0) {
			std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
		} else {
			std::cout << "Slozeni simetricni brojevi iz vektora su: ";
			Ispisi(v);
		}
		break;
	case 1:
		v=IzdvojiSimetricneTernarne(v,true);
		if(v.size()==0) {
			std::cout << "Nema prostih simetricnih brojeva u vektoru.";
		} else {
			std::cout << "Prosti simetricni brojevi iz vektora su: ";
			Ispisi(v);
		}
		break;
	default:
		return 0;
	}
	return 0;
}
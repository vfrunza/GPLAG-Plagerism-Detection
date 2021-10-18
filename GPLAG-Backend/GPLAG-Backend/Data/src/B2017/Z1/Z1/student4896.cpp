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

typedef std::vector<long long int> Vektor;

int Broj_Cifara(unsigned long long int n)
{
	int broj_cifara(0),k(0);
	while(k!=0) {
		k/=10;
		broj_cifara++;
	}
	return broj_cifara;
}

Vektor IzbaciIste(Vektor v)
{
	for(int i=0; i<v.size(); i++) {
		if(i==v.size()-1) break;
		for(int j=i+1; j<v.size(); j++) {
			if(v.at(i)==v.at(j)) {
				v.erase(v.begin()+j);
				j--;
			}
		}
	}
	return v;
}

unsigned long long int ObrniBroj(unsigned long long int n)
{
	unsigned long long int Broj(0);
	while(n!=0) {
		if(n/10!=0) {
			Broj=(Broj+(n%10))*10;
		} else {
			Broj=Broj+n%10;
		}
		n/=10;
	}
	return Broj;
}

unsigned long long int PretvoriUTernarni(unsigned long long int n)
{
	unsigned long long int pomocni(0);
	int nule(1),P;
	P=n;
	if(P%3==0) {
		while(P%3==0) {
			nule*=10;
			P/=3;
		}
	}
	do {
		pomocni=pomocni*10+(n%3);
		n=n/3;
	} while(n!=0);
	unsigned long long int novi(ObrniBroj(pomocni)*nule);
	return novi;
}

unsigned long long int PretvoriUTernarni1(unsigned long long int n)
{
	unsigned long long int pomocni(0);
	do {
		pomocni=pomocni*10+(n%3);
		n=n/3;
	} while(n!=0);
	return pomocni;
}

Vektor IzdvojiSimetricneTernarne(Vektor v, bool a)
{
	Vektor vec;
	if(a==true) {
		for(int i=0; i<v.size(); i++) {
			bool bio(true);
			if(v.at(i)<0) {
				v.at(i)=v.at(i)*(-1);
			} else {
				bio=false;
			}
			for(int j=2; j<v.at(i); j++) {
				if(v.at(i)%j==0) break;
				if(j==v.at(i)-1) {
					if(PretvoriUTernarni(v.at(i))==PretvoriUTernarni1(v.at(i))) {
						if(bio) {
							vec.push_back(v.at(i)*(-1));
						} else {
							vec.push_back(v.at(i));
						}
					}
				}
			}
		}
	} else {
		for(int i=0; i<v.size(); i++) {
			for(int j=2; j<v.at(i); j++) {
				if(v.at(i)%j==0) {
					if(Broj_Cifara(PretvoriUTernarni(v.at(i)))!=Broj_Cifara(ObrniBroj(PretvoriUTernarni(v.at(i))))) {
						break;
					}
					if(PretvoriUTernarni(v.at(i))==ObrniBroj(PretvoriUTernarni(v.at(i)))) {
						vec.push_back(v.at(i));
					}
					break;
				}
			}
		}
	}
	return vec;
}

int main ()
{
	Vektor V;
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	int n(0);
	do {
		std::cin >> n;
		if(n==-1) break;
		V.push_back(n);
	} while(n!=-1);
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int k;
	do {
		std::cin >> k;
		if(k==0 || k==1) break;
		std::cout << "Neispravan unos! Unesite ponovo: ";
	} while(k!=0 || k!=1);
	Vektor Novi(IzbaciIste(IzdvojiSimetricneTernarne(V,k)));
	if(k==1) {
		if(Novi.size()==0) {
			std::cout << "Nema prostih simetricnih brojeva u vektoru.";
			return 0;
		} else {
			std::cout << "Prosti simetricni brojevi iz vektora su: ";
			for(int i=0; i<Novi.size(); i++) {
				if(i==Novi.size()-1) {
					std::cout << Novi.at(i) << ".";
				} else {
					std::cout << Novi.at(i) << ", ";
				}
			}
		}
	} else {
		if(Novi.size()==0) {
			std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
			return 0;
		} else {
			std::cout << "Slozeni simetricni brojevi iz vektora su: ";
			for(int i=0; i<Novi.size(); i++) {
				if(i==Novi.size()-1) {
					std::cout << Novi.at(i) << ".";
				} else {
					std::cout << Novi.at(i) << ", ";
				}
			}
		}
	}
	return 0;
}
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

int BrojUnazad(int broj)
{
	int cifra, ElementUnazad(0);
	while(broj>0) {
		cifra=broj%10;
		ElementUnazad=ElementUnazad*10+cifra;
		broj=broj/10;
	}
	return ElementUnazad;
}

int Ternarni(int broj)
{
	int medjurezultat, ostatak, ternarni(0), broj_sabiraka(0);
	while(broj!=0) {
		medjurezultat=broj/3;
		ostatak=broj-medjurezultat*3;
		broj=medjurezultat;
		ternarni+=ostatak*std::pow(10,broj_sabiraka);
		broj_sabiraka=broj_sabiraka+1;
	}
	return ternarni;
}

bool prost(int broj1)
{
	if(broj1==1 || broj1==0)return false;
	broj1=fabs(broj1);
	for(int i=2; i<=std::sqrt(broj1); i++) {
		if(broj1%i==0) return false;
	}
	return true;
}

bool slozen(int broj2)
{
	if(broj2==1 || broj2==1)return false;
	broj2=fabs(broj2);
	for(int i=2; i<broj2; i++) {
		if(broj2%i==0) return true;
	}
	return false;
}

std::vector<int> IzbaciPonovljene(std::vector<int>v)
{
	for(int i=0; i<v.size(); i++) {
		for(int j=i+1; j<v.size(); j++) {
			if(v.at(i)==v.at(j)) {
				for(int k=j+1; k<v.size(); k++)
					v.at(k-1)=v.at(k);
				v.resize(v.size()-1);
				j--;
			}
		}
	}
	return v;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int>v, bool l)
{
	std::vector<int>VektorZaReturn, VektorZaReturn2;
	v=IzbaciPonovljene(v);
	for(int i=0; i<v.size(); i++) {
		if(l==true && prost(v.at(i)) && Ternarni(v.at(i))==BrojUnazad(Ternarni(v.at(i)))) {
			VektorZaReturn.push_back(v.at(i));
		} else if(l==false && slozen(v.at(i)) && Ternarni(v.at(i))==BrojUnazad(Ternarni(v.at(i)))) {
			VektorZaReturn.push_back(v.at(i));
		}
	}
	return VektorZaReturn;
}

int main ()
{
	int ElementVektora, logi;
	std::vector<int>NekiVektor, NekiVektor1;
	std::cout<< "Unesite elemente vektora (-1 za kraj): ";
	do {
		std::cin >> ElementVektora;
		if(ElementVektora!=-1) {
			NekiVektor.push_back(ElementVektora);
		}
	} while(ElementVektora!=-1);

	std::cout<< "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	
	for(;;) {
		std::cin >> logi;
		if(logi==1 || logi==0) break;
		else if(logi!=1 && logi!=0) {
			std::cout<< "Neispravan unos! Unesite ponovo: ";
		}
	}
	
	if(logi==1) {
		NekiVektor1=IzdvojiSimetricneTernarne(NekiVektor, logi);
		if(NekiVektor1.size()==0) {
			std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
			return 1;
		}

		std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		for(int i=0; i<NekiVektor1.size(); i++) {
			if(i==NekiVektor1.size()-1) {
				std::cout << NekiVektor1.at(i) << ".";
				break;
			}
			std::cout<<NekiVektor1.at(i)<< ", ";
		}
	} else if(logi==0) {
		NekiVektor1=IzdvojiSimetricneTernarne(NekiVektor, logi);
		if(NekiVektor1.size()==0) {
			std::cout<< "Nema slozenih simetricnih brojeva u vektoru.";
			return 1;
		}
		std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for(int i=0; i<NekiVektor1.size(); i++) {
			if(i==NekiVektor1.size()-1) {
				std::cout<< NekiVektor1.at(i) << ".";
				break;
			}
			std::cout<<NekiVektor1.at(i)<< ", ";
		}
	}
	return 0;
}
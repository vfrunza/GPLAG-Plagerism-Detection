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
#include <string>
bool DaLiJeProst(int n)
{
	if(n<0) n=-n;
	if(n<2) return false;
	for(int i=2; i<=sqrt(n); i++) {
		if(n%i==0)
			return false;
	}
	return true;
}


/*int PrebrojiCifre (int n)
{
	int brojcifara(0);
	do {
		n=n/10;
		brojcifara++;
	} while(n!=0);
	return brojcifara;
}*/


int PretvoriUTerarne(int n)
{
	if(n<0) n=-n;
	int rez(0);
	do {
		int	c=n%3;
		n=n/3;
		rez=rez*10+c;

	} while (n!=0);


	int obrni(0);
	do {
		int b=rez%10;
		obrni=obrni*10+b;
		rez=rez/10;

	} while(rez!=0);
	return obrni;
}

bool DaLiJeSimetrican(int n)
{
	if(n<0) n=-n;
	/*
	int brojcifara=PrebrojiCifre(n);
	for(int i=1; i<=brojcifara/2; i++) {
		int sdesna, slijeva;
		int desni=n;
		int lijevi=n;

		sdesna=desni%10;
		desni = desni/10;
		slijeva=lijevi/(int(std::pow(10,brojcifara-1)));
		lijevi=lijevi%(int(std::pow(10,brojcifara-1)));

		if(sdesna!=slijeva) return false;
	}
	return true;*/

	std::string broj;       //kako prvobitna verzija funkcije nije radila uradila sam je uz pomoć stringa
	broj+=std::to_string(n); // broj sam pretvorila u string
	int velicina=broj.size()-1; // zatim sam provjeravala simetricnost stringa
	for(int i=0; i<broj.size()/2; i++) {
		if(broj.at(i)!=broj.at(velicina-i)) return false;
	}
	return true;

}

std::vector<int>IzdvojiSimetricneTerarne(std::vector<int>vector1,bool istinitost)
{
	std::vector<int>povratni;
	if (istinitost==true) {
		for(int i=0; i<vector1.size(); i++) {
			int	element=vector1.at(i); //pozivanjem funkcija (koje su napravljene u prethodnim korcima) formiram funkciju koja izvaja simetrican i teraran element

			bool neponavljanje=true;
			for(int j=0; j<i; j++) {
				if(vector1.at(j)==element)
					neponavljanje=false;
			}

			if(DaLiJeProst(element)==true && neponavljanje && element!=1) {
				int terarnielement=PretvoriUTerarne(element);
				if(DaLiJeSimetrican(terarnielement)==true) {
					povratni.push_back(element);
				}
			}

		}

	}

	if(istinitost==false) {
		for(int i=0; i<vector1.size(); i++) {
			int element1=vector1.at(i);

			bool neponavljanje=true;
			for(int j=0; j<i; j++) {
				if(vector1.at(j)==element1)
					neponavljanje=false;
			}

			if(DaLiJeProst(element1)==false && neponavljanje && element1!=1) {
				int terarnielement1=PretvoriUTerarne(element1);
				if(DaLiJeSimetrican(terarnielement1)==true) {
					povratni.push_back(element1);
				}
			}
		}
	}

	return povratni;
}


int main ()
{


	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	std::vector<int>vektor;
	int n;
	do {
		std::cin>>n;
		vektor.push_back(n);
	} while(n!=-1);
	vektor.resize(vektor.size()-1);

	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int a;
	std::cin>>a;
	if (a!=0 && a!=1) {
		do {
			std::cout<<"Neispravan unos! Unesite ponovo: ";
			std::cin>>a;

		} while(a!=0&&a!=1);
	}

	std::vector<int>vektor1;
	vektor1=IzdvojiSimetricneTerarne(vektor,a);
	int velicina;
	velicina=vektor1.size();
	if(velicina==0 && a==0) {
		std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	} else if(velicina==0 && a==1) {
		std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
	} else if(velicina>0 && a==1) {
		std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		for(int i=0; i<vektor1.size(); i++) {
			std::cout << vektor1.at(i);
			if(i==vektor1.size()-1) std::cout<<".";
			else std::cout<<", ";
		}
	} else {
		std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for(int i=0; i<vektor1.size(); i++) {
			std::cout<< vektor1.at(i);
			if(i==vektor1.size()-1) std::cout<<".";
			else std::cout<<", ";
		}

	}


	return 0;
}
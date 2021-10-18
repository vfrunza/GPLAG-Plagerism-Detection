/*B 2017/2018, Zadaća 1, Zadatak 1*-

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
#include<cmath>
typedef std::vector<int> Vektor;


bool DaLiJeProst (int n)
{
	bool prost(true);
	if(n==0) prost=false;

	for(int i=2; (unsigned int) (i*i)<=n; i++) {
		if(n%i==0) prost=false;
	}
	return prost;
}

Vektor Ternarni2 (Vektor T1) //unazad
{
	Vektor T2;
	int s(0); //broj koji saljemo u vektor
	for(int i=0; i<T1.size(); i++) {
		int tmp(T1.at(i));
		while(tmp!=0) {
			s+=tmp%3;
			tmp/=3;
			s*=10;
		} //while (tmp!=0);
		s/=10;
		T2.push_back(s);
		s=0;
	}
	return T2;
}

Vektor Ternarni1 (Vektor T2) //normalan redoslijed
{
	Vektor T3;
	int o; //ostatak pri dijeljenju sa 3
	int b(-1); //eksponent broja 10(ostatak pri djeljenju mnozimo sa odredjenom potencijom broja 10)
	int s(0); //broj koji šaljemo u vektor
	for(int i=0; i<T2.size(); i++) {
		int tmp(T2.at(i));
		while(tmp!=0) {
			b++;
			o=tmp%3;
			tmp/=3;
			o*=pow(10,b);
			s+=o;
			o=0;
		} //while(tmp!=0);
		T3.push_back(s);
		o=0;
		b=-1;
		s=0;
	}
	return T3;
}

Vektor IzdvojiSimetricneTernarne (Vektor V, bool prost)
{

	Vektor Prosti; //prosti brojevi
	Vektor Slozeni; //simetricni slozeni
	for(int i=0; i<V.size(); i++) {
		if(V.at(i)!=1 && V.at(i)!=-1) {
			int v1(V.at(i));
			if((DaLiJeProst(v1))==true)
				Prosti.push_back(v1);
			else
				Slozeni.push_back(v1);
		}
	}


	Vektor Konacni;
	if(prost==true) {
		Vektor Tprosti1(Ternarni1(Prosti)); //normalan redoslijed
		Vektor Tprosti2(Ternarni2(Prosti)); //obrnut redoslijed
		Vektor Konacniprosti;
		for(int i=0; i<Prosti.size(); i++) {
			int tmp1(Tprosti1.at(i));
			int tmp2(Tprosti2.at(i));
			if(tmp1==tmp2) Konacni.push_back(Prosti.at(i));
		}
	} else {
		Vektor Tslozeni1(Ternarni1(Slozeni)); //normalan redoslijed
		Vektor Tslozeni2(Ternarni2(Slozeni)); //obrnut redoslijed

		for(int i=0; i<Slozeni.size(); i++) {
			int tmp1(Tslozeni1.at(i));
			int tmp2(Tslozeni2.at(i));
			if(tmp1==tmp2) Konacni.push_back(Slozeni.at(i));
		}
	}

	return Konacni;
}


int main ()
{
	int n;

	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	Vektor A;
	do {
		std::cin>>n;
		if(n==-1) break;
		A.push_back(n);
	} while(n!=-1);


	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int broj;
	std::cin>>broj;
	if (broj!=1 && broj!=0) {
		std::cout<<"Neispravan unos! Unesite ponovo: ";
		std::cin.clear();
		std::cin>>broj;
	}


	if(broj==1) {
		Vektor B(IzdvojiSimetricneTernarne(A,true));
		if(B.size()==0) std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		else {
			std::cout<<"Prosti simetricni brojevi iz vektora su: ";
			for(int i=0; i<B.size(); i++) {
				if(i==B.size()-1) std::cout<<B.at(i)<<".";
				else	std::cout<<B.at(i)<<", ";
			}
		}
	}

	if(broj==0) {
		Vektor C(IzdvojiSimetricneTernarne(A,false));
		if(C.size()==0)	std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		else {
			std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
			for(int i=0; i<C.size(); i++) {
				if(i==C.size()-1) std::cout<<C.at(i)<<".";
				else	std::cout<<C.at(i)<<", ";
			}
		}
	}

	return 0;
}
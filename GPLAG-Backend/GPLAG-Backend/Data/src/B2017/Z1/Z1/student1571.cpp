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
#include<vector>
#include<cmath>


typedef std::vector<int> vektor;

int BrojCifara(int n)
{
	int brojac(0);
	while(n!=0) {
		n=n/10;
		brojac++;

	}
	return brojac;
}




bool simetricnost(int brOj)

{
	int velicina_broj(BrojCifara(brOj));
	std::vector<int> v3;
	int c=brOj;

	while(brOj!=0) {
		int cifra=brOj%10;
		v3.push_back(cifra);
		brOj=brOj/10;
	}

	int broj_unazad(0);
	for(int i(0); i<velicina_broj; i++) {
		broj_unazad=broj_unazad*10+v3.at(i);
	}

	if(broj_unazad==c) return true;
	else return false;


}






bool Prost(int n)
{

	if(n<0 ) n=-n ;



	for(int i=2; i<=std::sqrt(n); i++) {

		if(n%i==0) return false;

	}

	return true;

}

int DekadniUTernarni(int broj)

{
	vektor v1;
	int cifra(0);

	while(broj!=0) {


		cifra=broj%3;
		broj/=3;
		v1.push_back(cifra);

	}
	int	ternarni(0);
	for(int i=v1.size()-1; i>=0; i--)
		ternarni=10*ternarni+v1.at(i);


	return ternarni;

}

vektor IzdvojiSimetricneTernarne(vektor a,bool b)
{
	vektor v,v1;
	for(int x :a ) {
		if(Prost(x) && simetricnost(DekadniUTernarni(x)))
			v.push_back(x);

		else if(Prost(x)==false  && simetricnost(DekadniUTernarni(x))==true)
			v1.push_back(x);
	}




	if(b==true) return v;
	else return v1;
}



int main ()
{
	int broj;
	vektor v;
	vektor d,p;

	std::cout<<"Unesite elemente vektora (-1 za kraj): ";

	while(std::cin>>broj,broj!=-1) {
		v.push_back(broj);
	}

	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int s;
	std::cin>>s;
	while(s!=0 && s!=1) {
		std::cout<<"Neispravan unos! Unesite ponovo: ";
		std::cin>>s;
	}



	if(s==1) {




		vektor d(IzdvojiSimetricneTernarne(v,true));
		if(d.size()==0) std::cout<<"Nema prostih simetricnih brojeva u vektoru.";

		else {
			std::cout<<"Prosti simetricni brojevi iz vektora su: ";
			for(int i=0; i<d.size(); i++) {

				if(i!=d.size()-1)
					std::cout<<d.at(i)<<", " ;
				else
					std::cout<<d.at(i)<<".";
			}
		}
	}


	else if(s==0) {
		vektor p(IzdvojiSimetricneTernarne(v,false));
		if(p.size()==0) std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		else {
			std::cout<<"Slozeni simetricni brojevi iz vektora su: ";

			for(int i=0; i<p.size(); i++) {
				if(i!=p.size()-1)
					std::cout<<p.at(i)<<", ";
				else
					std::cout<<p.at(i)<<".";
			}
		}
	}










	return 0;
}

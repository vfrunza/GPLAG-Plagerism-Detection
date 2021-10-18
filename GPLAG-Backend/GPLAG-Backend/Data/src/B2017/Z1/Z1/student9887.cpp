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
typedef std::vector<int> Vektor;
bool Prost(int broj)
{
	bool prost(true);
	if(broj<=1) {
		prost=false;
		return prost;
	}
	
	for(int i=2; i<=sqrt(broj); i++) {
		if(broj%i==0) {
			prost=false;
			break;
		}

	}
	return prost;
}
int Ternarna(int broj)
{

	int c(0),ternarni(0);
	while(broj!=0) {

		c=broj%3;
		ternarni=ternarni*10+c;
		broj/=3;
	}

	return ternarni;
}
bool Simetrican(int ternarni)
{

	int simetricni(0),kopija=ternarni,c(0);
	while(ternarni!=0) {
		c=ternarni%10;
		simetricni=simetricni*10+c;
		ternarni/=10;
	}
	if(simetricni==kopija)
		return true;
	return false;
}
Vektor IzdvojiSimetricneTernarne(Vektor v, bool logicka)
{
	Vektor v2;
	if(v.size()==0) return v2;
	for(int i=0; i<v.size(); i++) {
		if(logicka && Prost(fabs(v.at(i))) && Simetrican(Ternarna(fabs(v.at(i)))) && v.at(i)!=1) {
			v2.push_back(v.at(i));
		}
		if(logicka==false && Prost(fabs(v.at(i)))==false && Simetrican(Ternarna(fabs(v.at(i))))==true && v.at(i)!=1 )
			v2.push_back(v.at(i));
	}

	for(int i=0; i<v2.size(); i++) {
		for(int j=i+1; j<v2.size(); j++) {
			if(v2.at(i)==v2.at(j))
				v2.erase(v2.begin()+j);
		}
	}
	return v2;
}
int main ()
{

	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	Vektor v1;
	int broj;
	do {
		std::cin>>broj;
		if(broj!=-1) v1.push_back(broj);

	} while(broj!=-1);

	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int logi;
	std::cin>>logi;
	if((logi!=1 && logi!=0)  ) {
		do {
			
			std::cout<<"Neispravan unos! Unesite ponovo: ";
			std::cin>>logi;
		} while((logi!=1 && logi!=0) );
	}
	Vektor v3= IzdvojiSimetricneTernarne(v1,logi);
	if(v3.size()!=0 && logi==true) {
		std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		int i;
		for( i =0; i<v3.size()-1; i++) {
			std::cout<<v3.at(i);
			std::cout<<", ";
		}
		std::cout<<v3.at(i)<<".";
	}
	if(v3.size()==0 && logi==true)
		std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
	if(v3.size()!=0 && logi==false) {
		std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		int i;
		for( i =0; i<v3.size()-1; i++) {
			std::cout<<v3.at(i);
			std::cout<<", ";
		}
		std::cout<<v3.at(i)<<".";

	}
	if(v3.size()==0 && logi==false)std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	return 0;
}
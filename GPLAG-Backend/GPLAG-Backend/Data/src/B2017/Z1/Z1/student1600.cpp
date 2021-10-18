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

bool Simetricnost(int x)
{
	int y(x);
	int z=0;

	if(y<0) {
		x*=-1;
		y*=-1;
	}

	int brojac(0);
	while(y>0) {
		y/=10;
		brojac++;
	}

	y=x;
	int temp(1);

	while(brojac>0) {
		temp*=10;
		brojac--;
	}
	temp/=10;

	while(y>0) {

		z+=(y%10)*temp;
		temp/=10;
		y/=10;
	}

	if(x==z)
		return true;
	return false;
}

int DekadskiUTernarni(int n)
{
	int s(0), r, i(1);
	bool negativan(false);
	if(n<0) {
		n*=-1;
		negativan=true;
	}
	while(n>0) {

		r=n%3;
		s=s+(r*i);
		i*=10;
		n=n/3;
	}
	if(negativan)
		s*=-1;
	return s;
}

bool DaLiJeProst(int n)
{
	bool prost(true);

	if(n<0)
		n*=-1;

	for(int i=2; i<=std::sqrt(n); i++) {
		if(n%i==0) {
			prost=false;
			break;
		}
	}
	return prost;
}

std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> v, bool x)
{
	std::vector<int> prosti;
	std::vector<int> slozeni;

	for(int i=0; i<v.size(); i++) {
		if(v.at(i)!=0 && v.at(i)!=1 && DaLiJeProst (v.at(i)))
			prosti.push_back(v.at(i));
		else if((!DaLiJeProst(v.at(i)) && v.at(i)!=1) || v.at(i)==0)
			slozeni.push_back(v.at(i));
	}

	std::vector<int> prosti_ternarni;
	std::vector<int> slozeni_ternarni;

	for(int i=0; i<prosti.size(); i++) {
		prosti_ternarni.push_back(DekadskiUTernarni(prosti.at(i)));
	}

	for(int i=0; i<slozeni.size(); i++) {
		slozeni_ternarni.push_back(DekadskiUTernarni(slozeni.at(i)));
	}

	std::vector<int> prosti_ternarni_simetricni;
	std::vector<int> slozeni_ternarni_simetricni;

	if(prosti_ternarni.size()!=0)
		for(int i=0; i<prosti_ternarni.size(); i++) {
			int pom=prosti_ternarni.at(i);
			if(Simetricnost(pom))
				prosti_ternarni_simetricni.push_back(prosti.at(i));
		}
	if(slozeni_ternarni.size()!=0)
		for(int i=0; i<slozeni_ternarni.size(); i++) {
			int pom=slozeni_ternarni.at(i);
			if(Simetricnost(pom))
				slozeni_ternarni_simetricni.push_back(slozeni.at(i));
		}

	std::vector<int> prosti_rez=prosti_ternarni_simetricni;
	std::vector<int> slozeni_rez=slozeni_ternarni_simetricni;


	if(x==true)
		return prosti_rez;
	return slozeni_rez;

}

int main ()
{
	std::vector<int> v;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	int broj;
	do {
		std::cin>>broj;
		if(broj!=-1)
			v.push_back(broj);
	} while(broj!=-1);

	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";

	int unos;
	do {
		std::cin>>unos;
		if(unos!=1 && unos!=0) {
			std::cout<<"Neispravan unos! Unesite ponovo: ";
		}
	} while(unos!=1 && unos!=0);

	if(unos==1) {
		std::vector<int> prosti_rez=IzdvojiSimetricneTernarne(v,true);

		for(int i=0; i<prosti_rez.size(); i++) {
			for(int j=i+1; j<prosti_rez.size(); j++) {
				if(prosti_rez.at(i)==prosti_rez.at(j)) {
					prosti_rez.erase(prosti_rez.begin() + j);
					j--;
				}
			}
		}

		if(prosti_rez.size()==0)
			std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		else {
			std::cout<<"Prosti simetricni brojevi iz vektora su: ";
			for(int i=0; i<prosti_rez.size(); i++) {

				if(i==prosti_rez.size()-1)
					std::cout<<prosti_rez.at(i)<<".";
				else
					std::cout<<prosti_rez.at(i)<<", ";
			}
		}
	}

	if(unos==0) {
		std::vector<int> slozeni_rez=IzdvojiSimetricneTernarne(v,false);

		for(int i=0; i<slozeni_rez.size(); i++) {
			for(int j=i+1; j<slozeni_rez.size(); j++) {
				if(slozeni_rez.at(i)==slozeni_rez.at(j))
					slozeni_rez.erase(slozeni_rez.begin() + j);
		//		j--;
			}
		}

		if(slozeni_rez.size()==0)
			std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		else {
			std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
			for(int i=0; i<slozeni_rez.size(); i++) {

				if(i==slozeni_rez.size()-1)
					std::cout<<slozeni_rez.at(i)<<".";
				else
					std::cout<<slozeni_rez.at(i)<<", ";
			}
		}
	}
	return 0;
}

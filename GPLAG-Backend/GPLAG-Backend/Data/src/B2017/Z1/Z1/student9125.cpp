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

bool DaLiJeProst(unsigned long long int broj)
{
	bool prost(true);
	if(broj==0 || broj==1 || broj== -1) {

		return false;
	}

	else {
		for(int i=2; i<=std::sqrt(fabs(broj)); i++) {
			if(broj % i == 0) {
				prost=false;

				break;
			}
		}

		if(prost) return true;
		else  return false;

	}
}

bool DaLiJeBrojSimetrican(int broj)
{
	int temp;
	temp=broj;
	int novi_broj=0;
	while(temp>0){
		int cifra = temp % 10;
		novi_broj = (novi_broj*10) + cifra;
		temp = temp / 10;
	}
	if(broj==novi_broj)	return true;
	else return false;
}


int PretvoriUTernarni(unsigned long long int broj)
{
	int ternarni=0, brojac=0, ostatak;
	if(broj<0) broj = abs(broj);
	while(broj>0) {
		ostatak = broj % 3;
		ternarni = ternarni + (ostatak*pow(10, brojac));
		brojac++;
		broj /= 3;
	}
	return ternarni;
}

std::vector<int> IzbaciDuplikate(std::vector<int> V)
{

	for(int i=0; i<V.size(); i++) {
		for(int j=i+1; j<V.size(); j++) {
			if(V.at(i)==V.at(j)) {
				V.erase(V.begin() + j);
				j--;
			}
		}
	}
	return V;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int>v, bool x)
{

	std::vector<int> novi_vektor;
	std::vector<int> pomocni_vektor;

	for(int i=0; i<v.size(); i++) {
		if( DaLiJeProst(v.at(i))==x && DaLiJeBrojSimetrican(PretvoriUTernarni(v.at(i))))
			novi_vektor.push_back(v.at(i));
	}
	pomocni_vektor=IzbaciDuplikate(novi_vektor);
	return pomocni_vektor;

}
int main ()
{

	int broj;
	std::vector<int> vektor;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";


	do {
		std::cin>>broj;
		if(broj!=-1)
			vektor.push_back(broj);
	} while(broj!=-1);

	std::vector<int> vektor1;
	int x;
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	do {
		std::cin>>x;
		if(x!=1 && x!=0)
			std::cout<<"Neispravan unos! Unesite ponovo: ";
	} while(x!=1 && x!=0);

	vektor1=IzdvojiSimetricneTernarne(vektor,bool(x));

	if(bool(x)==true) {
		if(vektor1.size()==0) std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		else {
			std::cout<<"Prosti simetricni brojevi iz vektora su: ";
			for(int i=0; i<vektor1.size(); i++) {
				if(i==vektor1.size()-1) std::cout<<vektor1.at(i)<<"."<<std::endl;
				else std::cout<<vektor1.at(i)<<", ";
			}
		}

	} else {
		if(vektor1.size()==0) std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		else {
			std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
			for(int j=0; j<vektor1.size(); j++) {
				if(j==vektor1.size()-1) std::cout<<vektor1.at(j)<<"."<<std::endl;
				else std::cout<<vektor1.at(j)<<", ";
			}
		}
	}

	return 0;
}
//ovo je zadaca broj 1 hahaha
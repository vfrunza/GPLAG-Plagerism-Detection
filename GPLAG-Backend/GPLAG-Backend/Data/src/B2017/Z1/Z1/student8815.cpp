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

int obrnut(int n)
{
	int pom(0);
	while(n!=0) {
		pom=pom*10+n%10;
		n/=10;
	}
	return pom;
}

bool nepostoji (std::vector<int> v, int n)
{
	for(int i=0; i<v.size(); i++)
		if(v.at(i)==n) return false;
	return true;
}

int PretvoriUTernarni (int n)
{
	bool pretvorba(false);
	if(n<0) {
		n=-n;
		pretvorba=true;
	}
	std::vector<int> v, pom;
	int ter, stepen(0);
	do {
		ter=std::pow(3,stepen++);
		v.push_back(ter);
		pom.push_back(0);
	} while(ter>0);
	for(int i=19; i>-1; i--) {
		if(v.at(i)>n) continue;
		if(n<3) {
			pom.at(0)=n;
			break;
		} else if((n-v.at(i)>v.at(i))) {
			n-=v.at(i);
			pom.at(i)++;
			i++;
		} else {
			n-=v.at(i);
			pom.at(i)++;
		}
	}
	int izlaz(0);
	for(int i=19; i>-1; i--) izlaz=izlaz*10+pom.at(i);
	if(pretvorba) izlaz=-izlaz;
	return izlaz;
}

bool prosti (int n)
{
	if(n==1) return false;
	for(int i=2; i<=std::sqrt(n); i++)
		if(n%i==0) return false;
	return true;
}

std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> v, bool t)
{
	std::vector<int> v2;
	for(int i=0; i<v.size(); i++) {
		if(prosti(std::fabs(v.at(i)))==t) {
			int ter1=PretvoriUTernarni(std::abs(v.at(i)));
			int ter2=obrnut(ter1);
			if(ter1==ter2 && nepostoji(v2, v.at(i)))
				v2.push_back(v.at(i));
		}
	}
	return v2;
}

int main ()
{
	int n, opcija;
	std::vector<int> v2, v, v1;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	for(;;) {
		std::cin>>n;
		if(n!=-1) v.push_back(n);
		if(n==-1) break;
	}

	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	do {
		std::cin>>opcija;
		if(opcija!=0 && opcija!=1) std::cout<<"Neispravan unos! Unesite ponovo: ";
	} while(opcija!=0 && opcija!=1);
	if(opcija==1) {
		v2=IzdvojiSimetricneTernarne(v, true);
		if(v2==v1) std::cout<<"Nema prostih simetricnih brojeva u vektoru."<<std::endl;
		else {
			std::cout<<"Prosti simetricni brojevi iz vektora su: ";
			for(int i=0; i<v2.size(); i++) {
				if(i==v2.size()-1) std::cout<<v2.at(i)<<".";
				else std::cout<<v2.at(i)<<", ";
			}
		}
	} else if(opcija==0) {
		v2=IzdvojiSimetricneTernarne(v, false);
		if(v2==v1) std::cout<<"Nema slozenih simetricnih brojeva u vektoru."<<std::endl;
		else {
			std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
			for(int i=0; i<v2.size(); i++) {
				if(i==v2.size()-1) std::cout<<v2.at(i)<<".";
				else std::cout<<v2.at(i)<<", ";
			}
		}
	}
	return 0;
}
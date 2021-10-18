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
#include <deque>
#include <cmath>
bool DaLiJeProst(int n)
{
	if(n<=1) return false;
	int brojac(0);
	for(int i=2; i<=std::sqrt(n); i++) {
		if(n%i==0) return false;
	}
	return true;
}

bool DaLiJeSimetrican(std::deque<int> d)
{
	for(int i=0; i<(d.size()/2)+1; i++) {
		if(d.at(i) != d.at(d.size()-1-i)) return false;
	}
	return true;
}

std::deque<int> ternarnipretvori(int a)
{
	if(a<0) a=a*(-1);
	std::deque<int> vrati;
	while (a>0) {
		if(a%3==0) {
			vrati.push_front(a%3);
			a=a/3;
		} else {
			vrati.push_front(a%3);
			a=a/3;
		}
	}
	return vrati;
}


std::vector<int> IzdvojiCifre (int broj)
{
	std::vector<int> a;
	if(broj<0) broj=broj*(-1);
	while(broj>0) {
		int b;
		b=broj%10;
		broj=broj/10;
		a.push_back(b);
	}
	return a;
}
std::vector <int> IzdvojiSimetricneTernarne (std::vector<int> v,bool jeTernarni)
{
	std::vector <int> povratni;
	
		for(int i=0; i<v.size(); i++) {
			bool privremeni(false);
			if(DaLiJeProst(v.at(i))== jeTernarni && DaLiJeSimetrican(ternarnipretvori(v.at(i)))==true) {
				for(int j=0; j<povratni.size(); j++) {
					if(povratni.at(j)==v.at(i))
						privremeni=true;
					break;
				}
				if(privremeni==false) povratni.push_back(v.at(i));
			}
		}
	
	return povratni;
}


int main ()
{

	int n;
	std::vector <int> v1;
	std::cout << "Unesite elemente vektora (-1 za kraj): ";

	std::cin>>n;
	while(n!=-1) {
		if(n==-1) break;
		std::cin >> n;
		if(n!=-1) v1.push_back(n);
	}

	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int x;
	std::cin>>x;
	for(;;) {
		if(x==1 || x==0) break;
		std::cout<<"Neispravan unos! Unesite ponovo: ";
		std::cin>>x;

	}

	if(x==1) {
		std::vector<int> prost(IzdvojiSimetricneTernarne(v1,true));
		if(prost.size()==0) std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		else {
			std::cout<<"Prosti simetricni brojevi iz vektora su: ";
			for(int i=0; i<prost.size(); i++) {
				if(i<prost.size()-1) std::cout<<prost.at(i)<<", ";
				else if(i==prost.size()-1) std::cout<<prost.at(i)<<".";
			}
		}
	}

	if(x==0) {
		std::vector<int> slozen(IzdvojiSimetricneTernarne(v1,false));
		if(slozen.size()==0) std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		else {
			std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
			for(int i=0; i<slozen.size(); i++) {
				if(i<slozen.size()-1) std::cout<<slozen.at(i)<<", ";
				else if(i==slozen.size()-1) std::cout<<slozen.at(i)<<".";
			}
		}
	}





	return 0;
}
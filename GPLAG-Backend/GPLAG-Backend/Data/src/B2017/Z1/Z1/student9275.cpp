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
#include <iomanip>
#include <cmath>

bool Prost(int a)
{
	if(a<0) a=-a;
	if(a==1 || a==0) return false;
	for (int j=2; j<=std::sqrt(a); j++) {

		if(a%j==0) return false;
	}
	return true;
}

std::vector<int>	IzdvojiSimetricneTernarne(std::vector<int> a, bool s)
{
	std::vector<int> v1;
	if(s==true) {

		for(int i=0; i<a.size(); i++ ) {

			int P;
			int M=a.at(i);
			P=Prost(a[i]);
			if(P==true) {

				std::vector<int> S;
				//prebacanje u ternarni
				do {
					int s=0;
					s=std::abs(M%3);
					S.push_back(s);

					M/=3;

				} while(M!=0);
				//da li je simetrican
				bool simetrican(true);
				for (int j=0; j<=S.size()/2; j++) {
					if(S.at(j)!=S.at(S.size()-j-1)) {
						simetrican=false;
						break;
					}
				}

				if(simetrican)
					v1.push_back(a.at(i));
			}
		}
		return v1;
	}

	else {
		for(int i=0; i<a.size(); i++) {
			int P;
			P=Prost(a.at(i));
			if(P==false && a.at(i)!=0 && a.at(i)!=1) {
				std::vector<int> S;
				int M=a.at(i);
				do {
					int s=abs(M%3);
					S.push_back(s);
					M/=3;
				} while(M!=0);
				bool simetrican(true);
				for(int j=0; j<S.size()/2; j++) {
					if(S.at(j)!=S.at(S.size()-1-j)) {
						simetrican=false;
						break;
					}
				}
				if(simetrican)
					v1.push_back(a.at(i));
			}
		}
		return v1;
	}

}
int main()
{
	std::vector<int> s;

	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	int br;
	std::cin>>br;
	while(br!=-1) {
		s.push_back(br);
		std::cin>>br;
	}

	std::vector<int> a,b;
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int T;
	std::cin>>T;
	while(T!=0 && T!=1) {
		std::cout << "Neispravan unos! Unesite ponovo: ";
		std::cin >> T;
	}
	a=IzdvojiSimetricneTernarne(s,T);

	if(T==1) {
		if(a.size()==0) std::cout<<"Nema prostih simetricnih brojeva u vektoru." << std::endl;
		else {
			std::cout<<"Prosti simetricni brojevi iz vektora su: ";
			for(int i=0; i<a.size(); i++)
				if (i!=a.size()-1)
					std::cout<<a[i]<<", ";
				else
					std::cout << a.at(i) << "." << std::endl;
		}

	} else {
		if(a.size()==0) std::cout<<"Nema slozenih simetricnih brojeva u vektoru." << std::endl;
		else {
			std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
			for(int i=0; i<a.size(); i++)
				if (i!=a.size()-1)
					std::cout<<a[i]<<", ";
				else
					std::cout <<a[i] << "."<< std::endl;
		}
	}

	return 0;
}
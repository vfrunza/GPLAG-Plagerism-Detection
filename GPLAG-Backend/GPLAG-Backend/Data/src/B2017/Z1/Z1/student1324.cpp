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
#include <limits>
using std::vector;


bool DaLiJeProst (int n)
{
	if(n<=1) return false;
	for(int i(2); i<=std:: sqrt(n); i++)
		if(n%i==0) return false;

	return true;
}

vector<int> IzdvojiSimetricneTernarne ( vector<int> v, bool prost)
{
	vector<int> rezultantni;

	for(int i(0); i<v.size(); i++) {


		if(DaLiJeProst(abs(v.at(i))) == prost) {
			bool ubaciti(true);
			vector<int> cifre;
			int broj ( v.at(i) );


			do {
				cifre.push_back(abs(broj%3));
				broj/=3;


			} while(broj>0);


			//provjera simetricnosti

			for(int j=0; j<cifre.size()/2; j++) {
				if(cifre.at(j)!=cifre.at(cifre.size()-1-j)) {
					ubaciti=false;
					break;
				}
			}
	
			if(ubaciti)
				rezultantni.push_back(v.at(i));

		}
	}
	return rezultantni;

}

int main ()
{
	vector <int> a;
	int broj;
	std:: cout << "Unesite elemente vektora (-1 za kraj): ";
	do {

		std:: cin >> broj;
		if(broj!=-1)
			a.push_back(broj);

	} while(broj!=-1);

	int n;
	std:: cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	std:: cin >> n;
	while(n!=1 && n!=0) {
		std:: cout << "Neispravan unos! Unesite ponovo: ";
		std:: cin >> n;
	}


	vector<int> simetricni(IzdvojiSimetricneTernarne(a, n));


	if(n==1) {
		if(simetricni.size()!=0) {
			std:: cout << "Prosti simetricni brojevi iz vektora su: ";
			for(int i(0); i<simetricni.size(); i++) {
				if(i!=simetricni.size()-1)
					std:: cout  << simetricni.at(i) << ", ";
				else
					std::cout << simetricni.at(i) << ".";
			}

		} else {
			std:: cout << "Nema prostih simetricnih brojeva u vektoru.";
		}
	}
	if (n==0) {
		if(simetricni.size()!=0) {
			std::cout << "Slozeni simetricni brojevi iz vektora su: ";
			for(int i(0); i<simetricni.size(); i++) {
				if(i!=simetricni.size()-1)
					std:: cout << simetricni.at(i) << ", ";
				else
					std:: cout << simetricni.at(i) << ".";
			}
		} else  {
			std:: cout << "Nema slozenih simetricnih brojeva u vektoru.";
		}
	}

	return 0;
}
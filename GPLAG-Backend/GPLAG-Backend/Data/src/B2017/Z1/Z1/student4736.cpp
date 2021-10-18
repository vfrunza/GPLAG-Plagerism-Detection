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
#include <cmath>
#include <vector>

using namespace std;

bool daLiJeProst(int broj)
{
	for (int i = 2; i <= sqrt(broj); i++) {
		if(broj%i==0) return false;
	}
	return true;
}

int pretvoriDecimalniUTernarni(int broj)
{
	int ternarni = 0;
	int k=1;
	while(broj!=0) {
		int cifra = broj%3;
		ternarni+=cifra*k;
		k*=10;
		broj/=3;
	}
	return ternarni;
}

bool daLiJeBrojSimetrican(int broj)
{
	vector<int>cifre;

	while(broj!=0) {
		cifre.push_back(broj%10);
		broj/=10;
	}
	int j=cifre.size()-1;
	for (int i = 0; i <j; i++) {
		if(cifre.at(i)!=cifre.at(j)) return false;
		j--;
	}
	return true;
}

vector<int> IzdvojiSimetricneTernarne(vector<int> brojevi, bool prost)
{
	vector<int>rezultat;
	for (int i = 0; i < brojevi.size(); i++) {
		int prostostNasegBroja = daLiJeProst(brojevi.at(i));

		if ( (prost && prostostNasegBroja)|| (!prost && !prostostNasegBroja ) ) {
			int ternarni = pretvoriDecimalniUTernarni(brojevi.at(i));
			if(daLiJeBrojSimetrican(ternarni)) {
				bool duplikat = false;

				for (int j = 0; j < rezultat.size(); j++) {
					if(brojevi.at(i) == rezultat.at(j)) {
						duplikat=true;
						break;
					}
				}
				if(!duplikat) {
					rezultat.push_back(brojevi.at(i));
				}

			}
		}
	}
	return rezultat;
}

int main ()
{

	vector<int>brojevi;
	cout<<"Unesite elemente vektora (-1 za kraj): ";
	int broj;
	do {
		cin>>broj;
		if(broj==-1)break;
		brojevi.push_back(broj);
	} while(true);

	int prost;

	cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	do {
		cin>>prost;
		if(prost!=0&&prost!=1) {
			cout<<"Neispravan unos! Unesite ponovo: ";
		} else {
			break;
		}
	} while(true);
	vector<int> rezultat = IzdvojiSimetricneTernarne(brojevi, prost);

	if(rezultat.size()==0) {
		if(prost) {
			cout<<"Nema prostih simetricnih brojeva u vektoru.";
		} else {
			cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		}
	} else {
		if(prost) {
			cout<<"Prosti simetricni brojevi iz vektora su: ";
		} else {
			cout<<"Slozeni simetricni brojevi iz vektora su: ";
		}
		for (int i = 0; i < rezultat.size(); i++) {
			cout<<rezultat.at(i);
			if(i!=rezultat.size()-1)cout<<", ";
			else cout<<".";
		}
	}

	return 0;
}
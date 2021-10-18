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
using std::cin;
using std::cout;
using std::endl;
typedef std::vector<int> Vektor;
bool PretvoriUTernarni(int broj)
{

	int ternarni(0);
	int decimala(1);
	broj=abs(broj);
	while(broj>0) {
		ternarni+=(broj%3)*decimala;
		broj=broj/3;
		decimala*=10;

	}
	int ternarni2(ternarni);
	int naopak(0);
	while(ternarni2!=0) {
		int ostatak=ternarni2%10;
		naopak=naopak*10+ostatak;
		ternarni2/=10;

	}
	if(naopak==ternarni) {
		return true;
	}
	return false;


}
Vektor IzdvojiSimetricneTernarne(Vektor v,bool prosti1_slozeni0)
{
	int brojac(0);
	Vektor krajnjiVektor;
	if(prosti1_slozeni0==true) {
		for(int i=0; i<v.size(); i++) {

			for(int j=1; j<=(abs(v.at(i))); j++) {
				if((abs(v.at(i)%j))==0) brojac++;
			}
			if (brojac==2 && PretvoriUTernarni(v.at(i))==true) {

				for(int k=0; k<krajnjiVektor.size(); k++) {
					if(krajnjiVektor.at(k)==v.at(i)) continue;
				}
				krajnjiVektor.push_back(v.at(i));

			}
			brojac=0;
		}
	} else {
		for(int i=0; i<v.size(); i++) {
			for(int j=1; j<=(abs(v.at(i))); j++) {
				if(v.at(i)%j==0) brojac++;
			}
			if (brojac>2 && PretvoriUTernarni(v.at(i))==true) {

				for(int k=0; k<krajnjiVektor.size(); k++) {
					if(krajnjiVektor.at(k)==v.at(i)) continue;
				}
				krajnjiVektor.push_back(v.at(i));

			}
			brojac=0;
		}

	}
	return krajnjiVektor;
}
int main ()
{
	Vektor v1;
	int unos;
	cout<<"Unesite elemente vektora (-1 za kraj): ";
	do {
		cin>>unos;
		if(unos!=-1) {
			v1.push_back(unos);
		}
	} while(unos!=-1);
	bool prosti1_slozeni0;
	cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	cin >> prosti1_slozeni0;
	if(!cin) {
		cout<<"Neispravan unos! Unesite ponovo: Nema slozenih simetricnih brojeva u vektoru.";
		cin.clear();
		cin.ignore(1000000,'\n');
		return 0;
	}

	auto a(IzdvojiSimetricneTernarne(v1,prosti1_slozeni0));
	if(a.size()==0 && prosti1_slozeni0==1) {
		cout<<"Nema prostih simetricnih brojeva u vektoru.";
		return 0;
	}
	if(a.size()==0 && prosti1_slozeni0==0) {
		cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		return 0;
	}
	if(prosti1_slozeni0==0) {

		cout<<"Slozeni simetricni brojevi iz vektora su: ";
	}
	if(prosti1_slozeni0==1) {
		cout<<"Prosti simetricni brojevi iz vektora su: ";
	}
	for(int i=0; i<a.size(); i++) {
		cout<<a.at(i);
		if(i==a.size()-1) {
			cout<<".";
		} else {
			cout<<", ";
		}
	}
	return 0;




}
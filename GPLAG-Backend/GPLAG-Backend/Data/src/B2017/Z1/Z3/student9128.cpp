/*B 2017/2018, Zadaća 1, Zadatak 3
	
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
#define EPSILON 0.0001

using std::cout;
using std::cin;

typedef std::vector<int> vektor;
typedef std::deque<vektor> dek;

enum Smjer{Rastuci=1, Opadajuci};

bool DaLiJeStepenDvojke(int n) {
	for(int i=0; i<n; i++) {
		if(fabs(pow(2., i)-n)<EPSILON) return true;
	}
	return false;
}

dek MaksimalniPodnizoviStepenaDvojke (vektor v, Smjer tip) {
	dek nizovi;
	int broj_nizova(0);
	
	for(int i=0; i<v.size(); i++) {
		if(DaLiJeStepenDvojke(v.at(i))) {
			if(i==v.size()-1) break;
			vektor pomocni_vektor;
			pomocni_vektor.push_back(v.at(i));
			if(i<v.size()-1) {
				i++;
				if(tip==Rastuci) {
					while(i<v.size() && DaLiJeStepenDvojke(v.at(i)) && v.at(i)>=v.at(i-1)) {
						pomocni_vektor.push_back(v.at(i));
						i++;
					}
				}
				else {
					while(i<v.size() && DaLiJeStepenDvojke(v.at(i)) && v.at(i)<=v.at(i-1)) {
						pomocni_vektor.push_back(v.at(i));
						i++;
					}
				}
			}
			if(pomocni_vektor.size()<=1) {
				pomocni_vektor.resize(0);
				i--;
			} else {
				broj_nizova++;
				nizovi.resize(broj_nizova);
				//	nizovi[broj_nizova-1].resize(pomocni_vektor.size());
				nizovi[broj_nizova-1]=std::move(pomocni_vektor);
				i--;
			}
		}
	}
	return nizovi;
}

int main ()
{
	vektor v;
	int velicina, broj, izbor;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>velicina;
	cout<<"Unesite elemente vektora: ";
	for(int i=0; i<velicina; i++) {
		cin>>broj;
		v.push_back(broj);
	}
	cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	cin>>izbor;
	
	Smjer osobina_niza;
	if(izbor==1) osobina_niza=Rastuci;
	else osobina_niza=Opadajuci;
	
	dek rezultat(MaksimalniPodnizoviStepenaDvojke(v, osobina_niza));
	
	if(izbor==1) cout<<"Maksimalni rastuci podnizovi: \n";
	else cout<<"Maksimalni opadajuci podnizovi: \n";
	for(int i=0; i<rezultat.size(); i++) {
		for(int j=0; j<rezultat[i].size(); j++) {
			cout<<rezultat.at(i).at(j)<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
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
#include <deque>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <math.h>

typedef std::vector<int> Vektor;
typedef std::deque<int> Dek;

enum Smjer { Rastuci=1, Opadajuci=2} ;

int DaLiJeStepenDvojka (long long int a)
{
	
	while ((a%2==0) && a>1) a/=2;
	return (a==1);
}

void IspisiMatricu (std::deque<std::vector< int>> m)
{
	for (auto red : m) {
		for (auto x : red) std::cout << x << " ";
		std::cout << std::endl;
	}
}


std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke (Vektor a, enum Smjer b)
{

	std::deque<std::vector<int>> povratni;
	
	if (a.size()==0) return povratni; // Ako je prazan nek vrati prazan

	Vektor v;
 	int polozaj = 0;
	int brojac = 0;
	long long int i = 0;
	int drugi = 0;
	

	if (b==true) {

	

		for (long long int i = polozaj; i < a.size()-1; i++) {
			brojac=0;
			drugi=0;

			if (a.at(i)<=a.at(i+1) && DaLiJeStepenDvojka(a.at(i)) && DaLiJeStepenDvojka(a.at(i+1))) v.push_back(a.at(i));
			else continue;
			for (long long int j = i; j < a.size()-1; j++) {

				if (a.at(j)<=a.at(j+1) && DaLiJeStepenDvojka(a.at(j)&&DaLiJeStepenDvojka(a.at(j+1)))) {
					v.push_back(a.at(j+1));
					brojac++;

				} else if (a.at(j+1)<a.at(j) || !DaLiJeStepenDvojka(a.at(j)) ||!DaLiJeStepenDvojka(a.at(j+1))) {
					drugi++;
					i = j;
					break;
				}
			}

			if (brojac>0)
				povratni.push_back(v);
			if (drugi!=0)
				v.clear();
			if (drugi==0) {
				int vel = v.back();
				int vel2 = a.back();
				if (vel == vel2) return povratni;
			}
		}
	} else {

		
		for (long long int i = polozaj; i < a.size()-1; i++) {
			brojac=0;
			drugi=0;

			if (a.at(i)>=a.at(i+1) && DaLiJeStepenDvojka(a.at(i)) && DaLiJeStepenDvojka(a.at(i+1))) v.push_back(a.at(i));
			else continue;
			for (long long int j = i; j < a.size()-1; j++) {

				if (j==a.size()) break;
				if (a.at(j)>=a.at(j+1) && DaLiJeStepenDvojka(a.at(j)&&DaLiJeStepenDvojka(a.at(j+1)))) {
					v.push_back(a.at(j+1));
					brojac++;

				}

				else if (a.at(j+1)>a.at(j) || !DaLiJeStepenDvojka(a.at(j+1)) || !DaLiJeStepenDvojka(a.at(j))  ) {
					drugi++;
					i = j;
					break;
				}
			}
			if (brojac>0)
				povratni.push_back(v);
			if (drugi!=0)
				v.clear();
			if (drugi==0) {
				int vel = v.back();
				int vel2 = a.back();
				if (vel == vel2) return povratni;
			}
		}
	}
	return povratni;
}

int main ()
{
	Vektor v;
	int n;

	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;

	std::cout << "Unesite elemente vektora: ";
	 int p;
	Smjer smjer;

	while (v.size()!=n) {

		std::cin>>p;
		v.push_back(p);
	}
	int a;
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin >> a;

	for (;;) {
		if (a==1 || a==2) break;

		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
		std::cin>>a;

	}

	smjer=Smjer(a);
	std::deque<std::vector<int>> c;

	c =MaksimalniPodnizoviStepenaDvojke(v, smjer);

	if (a==1) {
		std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
		IspisiMatricu(c);
	} else if (a==2) {
		std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
		IspisiMatricu(c);
	}

	return 0;
}

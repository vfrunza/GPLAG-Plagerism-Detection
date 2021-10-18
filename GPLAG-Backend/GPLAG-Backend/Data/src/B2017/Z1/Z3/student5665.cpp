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

typedef std::vector<int> Vektor;

enum Smjer {Rastuci=1, Opadajuci=2};


bool StepenDvojke (int x) {
	
	if (x<1) return false;
	
	while (x%2==0 && x>1)
		x/=2;
	
	if (x==1) return true;
	
	return false;
}


std::deque<Vektor> MaksimalniPodnizoviStepenaDvojke(Vektor v, Smjer ro) {
	
	std::deque<Vektor> vektori;
	
	
	int i, j, pocetak, red(1);
	
	if (ro==1) {
		for (i=1; i<v.size(); i++) {
			pocetak=i-1;
			for (j=i; j<v.size(); j++) {
				if (v.at(j)>=v.at(j-1) && StepenDvojke(v.at(j))==true); // normala
				else break;
			}
			if (j-pocetak>1) {
				vektori.resize(red);
				for (; pocetak<j; pocetak++)
					if (StepenDvojke(v.at(pocetak))==true) vektori.at(red-1).push_back(v.at(pocetak));
				red++;
			}
			if (j!=i) i=j;
		}
	}
	
	if (ro==2) {
		for (i=1; i<v.size(); i++) {
			pocetak=i-1;
			for (j=i; j<v.size(); j++) {
				if (v.at(j)<=v.at(j-1) && StepenDvojke(v.at(j))==true); // normala
				else break;
			}
			if (j-pocetak>1) {
				vektori.resize(red);
				for (; pocetak<j; pocetak++)
					if (StepenDvojke(v.at(pocetak))==true) vektori.at(red-1).push_back(v.at(pocetak));
				red++;
			}
			if (j!=i) i=j;
		}
	}
	
	for (int i=0; i<vektori.size(); i++)
		if (vektori.at(i).size()<=1) {
			vektori.erase(vektori.begin()+i);
			i--;
		}
	
	return vektori;
}



int main ()
{
	Vektor brojevi;
	
	int n;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	
	std::cout << "Unesite elemente vektora: ";
	int broj;
	for (int i=0; i<n; i++) {
		std::cin >> broj;
		brojevi.push_back(broj);
	}
	
	Smjer ro;
	int k;
	
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin >> k;
	
	if (k==1) ro=Rastuci;
	if (k==2) ro=Opadajuci;
	
	std::deque<Vektor> podnizovi=MaksimalniPodnizoviStepenaDvojke(brojevi, ro);
	
	if (k==1) std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	if (k==2) std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	for (int i=0; i<podnizovi.size(); i++) {
		for (int j=0; j<podnizovi.at(i).size(); j++)
			std::cout << podnizovi.at(i).at(j) << " ";
	std::cout << std::endl;
	}
	
	return 0;
}
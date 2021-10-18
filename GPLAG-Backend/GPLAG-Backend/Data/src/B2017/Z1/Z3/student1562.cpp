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
#include <cmath>
#include <deque>

typedef std::deque<std::vector<int>> nizNizova;
enum Smjer {Rastuci, Opadajuci};


bool StepenDvojke(int broj)
{
		double broj1 = log2(broj);
		double broj2 = broj1 - int(broj1);

		if(broj2 == 0)
			return true;
		else
			return false;

}

bool Uporedi(int a, int b, Smjer _smjer)
{
	if (_smjer == Rastuci)
		return a > b;
	if (_smjer == Opadajuci)
		return a < b;
	else
		return false;
}

nizNizova MaksimalniPodnizoviStepenaDvojke(std::vector<int> nizBrojeva, Smjer _smjer)
{
	nizNizova podNizovi;
	std::vector<int> privremeniNiz;

	for (int i=0; i<nizBrojeva.size(); i++) {

		if(privremeniNiz.empty() && StepenDvojke(nizBrojeva.at(i))) {
			privremeniNiz.push_back(nizBrojeva.at(i));
		} else if(StepenDvojke(nizBrojeva.at(i)) && Uporedi(nizBrojeva.at(i),nizBrojeva.at(i-1),_smjer)) {
			privremeniNiz.push_back(nizBrojeva.at(i));


		} else {
			if(privremeniNiz.size()>1)
				podNizovi.push_back(privremeniNiz);
			if(!privremeniNiz.empty()) {
				privremeniNiz.clear();
				if(StepenDvojke(nizBrojeva.at(i)))
					i=i-1;
			}
		}
		if(i == nizBrojeva.size()-1 && privremeniNiz.size()>1)
			podNizovi.push_back(privremeniNiz);
	}
	return podNizovi;
}

/*nizNizova MaksimalniPodnidsaszoviStepenaDvojke(std::vector<int> &nizBrojeva, Smjer _smjer)
{
	nizNizova podNizovi;
	std::vector<int> privremeniNiz;

	for(int i = 0; i<nizBrojeva.size(); i++) {
		//ako je zadnji element
		if (i == nizBrojeva.size() - 1 && privremeniNiz.size() > 1 ) {
			if (StepenDvojke(nizBrojeva.at(i)) && Uporedi(nizBrojeva.at(i), nizBrojeva.at(i-1), _smjer))
				privremeniNiz.push_back(nizBrojeva.at(i));
			podNizovi.push_back(privremeniNiz);

		}

		if (StepenDvojke(nizBrojeva.at(i)) && privremeniNiz.empty()) {
			privremeniNiz.push_back(nizBrojeva.at(i));
		}

	else {
		if (privremeniNiz.size() > 1) {
			podNizovi.push_back(privremeniNiz);

		}

		if(!privremeniNiz.empty()) {
			privremeniNiz.clear();
			if(StepenDvojke(nizBrojeva.at(i)))
				i--;
		}
	}

}
return podNizovi;
}*/

std::vector<int> unesiBrojeve()
{
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;

	std::vector<int> brojevi(n);

	int broj;

	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i<n; i++) {
		std::cin>>broj;
		brojevi.push_back(broj);
	}
	return brojevi;

}

void IsprintajPodNizove(nizNizova sviPodNizovi)
{
	for(auto podNIz : sviPodNizovi) {

		for(auto clan : podNIz) {
			std::cout<<clan<< " ";
		}
		std::cout<<std::endl;
	}
}

int main ()
{

	std::vector<int> nizBrojeva = unesiBrojeve();
	int opcija;
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin>>opcija;
	nizNizova k;

	if(opcija == 1) {
		std::cout<<"Maksimalni rastuci podnizovi: \n";
		k = MaksimalniPodnizoviStepenaDvojke(nizBrojeva, Rastuci);
	} else if(opcija == 2) {
		std::cout<<"Maksimalni opadajuci podnizovi: \n";
		k = MaksimalniPodnizoviStepenaDvojke(nizBrojeva, Opadajuci);
	}
	IsprintajPodNizove(k);
	return 0;
}
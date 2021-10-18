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
#include <cmath>

typedef std::deque<std::vector<int>> Matrica;
enum Smjer {Rastuci=1,Opadajuci=2};

bool DaLiJeStepenDvojke(int broj) 	//provjera da li je broj stepen 2
{

	if(broj<=0) {
		return false;
	}

	while(broj!=1) {

		if(broj%2!=0) {
			return false;
		}

		broj/=2;
	}
	return true;
}

Matrica RastuciPodnizovi(std::vector<int>niz)	//rastuci
{

	Matrica rastuci;

	int i(0);

	do {
		std::vector<int>red;
		
		//prethodni<=sljedeci i provjera da li su stepen 2
		if(niz.at(i)<=niz.at(i+1) && DaLiJeStepenDvojke(niz.at(i))
		        && DaLiJeStepenDvojke(niz.at(i+1))) {
		        	
			red.push_back(niz.at(i));

			do {
				red.push_back(niz.at(i+1));
				i++;
			} while(i<(niz.size()-1) && niz.at(i)<=niz.at(i+1)
			        && DaLiJeStepenDvojke(niz.at(i)) &&
			        DaLiJeStepenDvojke(niz.at(i+1)));

			rastuci.push_back(red);
		}
		i++;
		
	} while(i<(niz.size()-1));	//kraj niza

	return rastuci;
}

Matrica OpadajuciPodnizovi(std::vector<int>niz)	//opadajuci
{

	Matrica opadajuci;

	int i(0);

	do {
		std::vector<int>red;

		//prethodni>=sljedeci i provjera da li su stepen 2
		if(niz.at(i)>=niz.at(i+1) && DaLiJeStepenDvojke(niz.at(i))
		        &&DaLiJeStepenDvojke(niz.at(i+1))) {
			red.push_back(niz.at(i));

			do {
				red.push_back(niz.at(i+1));
				i++;
			} while(i<(niz.size()-1) && niz.at(i)>=niz.at(i+1)
			        && DaLiJeStepenDvojke(niz.at(i)) && DaLiJeStepenDvojke(niz.at(i+1)));

			opadajuci.push_back(red);
		}
		i++;
	} while(i<(niz.size()-1));	//kraj niza

	return opadajuci;
}



Matrica MaksimalniPodnizoviStepenaDvojke(std::vector<int>v, Smjer podniz)
{

	Matrica maxniz;

	if(podniz==Rastuci) {
		maxniz=RastuciPodnizovi(v); //max rastuci podnizovi stepen 2
	}

	if(podniz==Opadajuci) {
		maxniz=OpadajuciPodnizovi(v);	//max opadajuci podnizovi stepen 2
	}

	return maxniz;

}


int main ()
{
	int brojel;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> brojel;

	if(brojel==0) {
		Matrica mat(0,std::vector<int>(0));
		for(int i=0; i<brojel; i++) {
			for(int j=0; j<brojel; j++) {
				std::cout << mat.at(i).at(j);
			}
			std::cout << std::endl;
		}
		return 1;
	}

	std::cout << "Unesite elemente vektora: ";
	std::vector<int>vektor;
	int element;

	for(int i=0; i<brojel; i++) {
		std::cin >> element;
		vektor.push_back(element);
	}

	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int unos;
	std::cin >> unos;

	while(unos!=1 && unos!=2) {
		std::cout << "Neispravan unos! Unesite ponovo: ";
		std::cin >> unos;
	}

	if(unos==1) {
		Matrica rastuci=(MaksimalniPodnizoviStepenaDvojke(vektor,Smjer(unos)));

		std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
		for(auto red: rastuci) {
			for(auto element: red) {
				std::cout << element << " ";
			}
			std::cout << std::endl;
		}
	}
 
	if(unos==2) {
		Matrica opadajuci(MaksimalniPodnizoviStepenaDvojke(vektor,Smjer(unos)));

		std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
		for(auto red: opadajuci) {
			for(auto element: red) {
				std::cout << element << " ";
			}
			std::cout  << std::endl;
		}
	}

	return 0;
}
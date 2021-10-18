/*B 2016/2017, Zadaća 1, Zadatak 3

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath> 

typedef std::vector<std::vector<double>> Matrica;

Matrica RastuciPodnizovi(std::vector<double>niz)	//rastuci
{
	Matrica rastuci;

	int i=0;

	do {
		std::vector<double>vektor;

		if(niz.at(i)<=niz.at(i+1)) {		//prethodni<=sljedeci
			vektor.push_back(niz.at(i));

			do {
				vektor.push_back(niz.at(i+1));
				i++;
			} while(i<(niz.size()-1) && niz.at(i)<=niz.at(i+1)); 	//kraj niza && prethodni<=sljedeci

			rastuci.push_back(vektor);
		}
		i++;

	} while(i<(niz.size()-1));

	return rastuci;

}

Matrica OpadajuciPodnizovi(std::vector<double>niz)	//opadajuci
{

	Matrica opadajuci;

	int i=0;

	do {
		std::vector<double>vektor;

		if(niz.at(i)>=niz.at(i+1)) {		//sljedeci>=prethodni
			vektor.push_back(niz.at(i));

			do {
				vektor.push_back(niz.at(i+1));
				i++;
			} while(i<(niz.size()-1) && niz.at(i)>=niz.at(i+1));	//kraj niza && prethodni>=sljedeci

			opadajuci.push_back(vektor);
		}
		i++;
	} while(i<(niz.size()-1));

	return opadajuci;

}

int main ()
{
	int broj;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin>> broj;

	std::cout << "Unesite elemente vektora: ";
	std::vector<double>niz;
	double element;

	for(int i=0; i<broj; i++) {
		std::cin>>element;
		niz.push_back(element);
	}

	Matrica rastuci=(RastuciPodnizovi(niz));

	std::cout << "Maksimalni rastuci podnizovi: " << std::endl;

	for(auto niz: rastuci) {
		for(auto element: niz) {
			std::cout << std::setprecision(12) << element << " ";
		}
		std::cout << std::endl;
	}

	Matrica opadajuci=(OpadajuciPodnizovi(niz));

	std::cout << "Maksimalni opadajuci podnizovi: "<< std::endl;

	for(auto niz: opadajuci) {
		for(auto element: niz) {
			std::cout << std::setprecision(12) << element << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}

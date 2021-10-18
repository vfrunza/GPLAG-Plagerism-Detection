/*B 2017/2018, Zadaća 2, Zadatak 3

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

int JeLiPeriodican(const std::vector<int> &v) {
	int period(0);
	for(int i=1; i<v.size(); i++) {
		bool periodican(true);
		for(int k=0; k<v.size()-i; k++) {
			if(v[k] != v[k+i]) periodican=false;
		}
		if(periodican) {
			period=i;
			break;
		}
	}
	
	return period;
}

int** AlocirajFragmentirano(const std::vector<int> &v, int &koliko_puta) {
	
	if(v.size()==0) throw "Nesto ne znam sada sta ugl neka poruka za main ";
	
	int period(JeLiPeriodican(v));
	if(period) {
		if(v.size()%period == 0 ) koliko_puta=period;
		else koliko_puta=period+1;
		//ovdje fakat ne znam kako da dopunis vektor ako je konstantan, vjerovatno za to sluzi ono koliko_puta
	}
	if(period==0) koliko_puta=2;
	}
	int* najveci_el(std::max_element(&v[0], &v[period+1]));
	
	/*std::cout << "Najveci " << *najveci_el << "\n";*/
	
	int** mat(nullptr);
	try {
		mat=new int* [v.size()]{};
		
			for(int i=0; i<v.size(); i++) mat[i]=new int [v.at(i)];
			
			for(int i=0; i<v.size(); i++) {
				for(int j=v[i]; j>=0; j--) {
					if(j==v[i]) mat[i][j] = *najveci_el+1;
					else mat[i][j]=mat[i][j+1] - 1;
				}
			}
			return mat;
	}
	catch(std::bad_alloc) {
			for(int i=0; i<v.size(); i++) delete [] mat[i];
			delete [] mat;
				throw;
	}
}
}

int main ()
{
	std::cout << "Unesite broj elemenata vektora: ";
	int br_elemenata;
	std::cin >> br_elemenata;
	
	std::cout << "Unesite elemente vektora: ";
	std::vector<int> vektor(br_elemenata);
	
	for(int i=0; i<br_elemenata; i++) {
		int element(0);
		std::cin >> element;
		vektor.at(i)=element;
	}
	
	std::cout << "Odaberite alokaciju: 1 – fragmentirana, 0 – kontinualna:" ;
	int alokacija(0);
	std::cin >> alokacija;
	
	try {
		int** rezultat(AlocirajFragmentirano(vektor, alokacija));
		std::cout << "Dinamicki alocirana matrica: \n";
		for(int i=0; i<vektor.size(); i++) {
			for (int j=0; j<vektor.at(i); j++) {
				std::cout << rezultat[i][j] << "  ";
			}
			std::cout << std::endl;
		}
		for(int i=0; i<vektor.size(); i++) delete [] rezultat[i];
		delete [] rezultat;
	}
	catch(std::bad_alloc) {
		std::cout << "nedostatak memorije: ";
	}
	
	
	
	return 0;
}


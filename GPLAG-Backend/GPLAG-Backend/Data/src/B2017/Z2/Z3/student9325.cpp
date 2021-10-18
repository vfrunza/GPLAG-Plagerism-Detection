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
#include <new>
#include <stdexcept>
#include <iomanip>

bool Periodican(const std::vector<int> &v, int per) {
	for (int i=0; i<v.size()-per; i++) {
		if (v.at(i)!=v.at(i+per)) return false;
	}
	return true;
}

int max(const std::vector<int> &v) {
	int maks(v.at(0));
	for (int i=1; i<v.size(); i++) {
		if (v.at(i)>maks) maks=v.at(i);
	}
	return maks;
}

template <typename CjelobrojniTip>
	int** AlocirajFragmentirano(const std::vector<CjelobrojniTip> &v, int &koliko_puta) {
		if (v.size()==0) throw "Prazan vektor!";
		int osnovni(0);
		for (int i=1; i<v.size(); i++) {
			if (Periodican(v, i)) {
				osnovni=i;
				break;
			}
		}
		if (osnovni>0) {
			int duzina(v.size());
			while (duzina%osnovni!=0) duzina++;
			koliko_puta=duzina/osnovni;
		}
		else {
			osnovni=v.size();
			koliko_puta=2;
		}
		for (int i=0; i<v.size(); i++) {
			if (v.at(i)<=0) throw std::domain_error("Neispravan vektor!");
		}
		int maks(max(v));
		int** pok(new int*[koliko_puta*osnovni]{});
		try {
			int broj_reda(-1);
			for (int i=0; i<koliko_puta; i++) {
				for (int j=0; j<osnovni; j++) {
					broj_reda++;
					pok[broj_reda]=new int[v.at(j)];
					for (int k=v.at(j)-1; k>=0; k--) {
						pok[broj_reda][k]=maks--;
					}
					maks=max(v);
				}
			}
		}
		catch(...) {
			for (int i=0; i<koliko_puta*osnovni; i++) delete[] pok[i];
			delete[] pok;
			throw;
		}
		return pok;
	}

template <typename CjelobrojniTip>
	int** AlocirajKontinualno(const std::vector<CjelobrojniTip> &v, int &koliko_puta) {
		if (v.size()==0) throw "Prazan vektor!";
		int osnovni(0);
		for (int i=1; i<v.size(); i++) {
			if (Periodican(v, i)) {
				osnovni=i;
				break;
			}
		}
		if (osnovni>0) {
			int duzina(v.size());
			while (duzina%osnovni!=0) duzina++;
			koliko_puta=duzina/osnovni;
		}
		else {
			osnovni=v.size();
			koliko_puta=2;
		}
		for (int i=0; i<v.size(); i++) {
			if (v.at(i)<=0) throw std::domain_error("Neispravan vektor!");
		}
		int rastuci_broj(1);
		int** pok(new int*[koliko_puta*osnovni]{});
		int ukupno(0);
		for (int i=0; i<koliko_puta; i++) {
			for (int j=0; j<osnovni; j++) {
				ukupno+=v.at(j);
			}
		}
		try {
			bool logicka(false);
			int broj_reda(0);
			pok[0]=new int[ukupno];
			for (int i=0; i<koliko_puta; i++) {
				for (int j=0; j<osnovni; j++) {
					broj_reda++;
					if (broj_reda==koliko_puta*osnovni) {
						logicka=true;
						break;
					}
					pok[broj_reda]=pok[broj_reda-1]+v.at(j);
				}
				if (logicka) break;
			}
		}
		catch(...) {
			delete[] pok[0];
			delete[] pok;
			throw;
		}
		int broj_reda(-1);
		for (int i=0; i<koliko_puta; i++) {
			for (int j=0; j<osnovni; j++) {
				broj_reda++;
				for (int k=v.at(j)-1; k>=0; k--) {
					pok[broj_reda][k]=rastuci_broj++;
				}
				rastuci_broj=1;
			}
		}
		return pok;
	}

int main ()
{
	int n;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	int broj;
	std::vector<int> vektor;
	std::cout << "Unesite elemente vektora: ";
	for (int i=0; i<n; i++) {
		std::cin >> broj;
		vektor.push_back(broj);
	}
	int osnovni(0);
	for (int i=1; i<vektor.size(); i++) {
		if (Periodican(vektor, i)) {
			osnovni=i;
			break;
		}
	}
	if (osnovni==0) osnovni=vektor.size();
	int tip_alokacije;
	std::cout << "Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
	std::cin >> tip_alokacije;
	try {
		int brojac;
		int** pok;
		if (tip_alokacije==0) {
			pok=AlocirajKontinualno(vektor, brojac);
		}
		else if (tip_alokacije==1) {
			pok=AlocirajFragmentirano(vektor, brojac);
		}
		std::cout << "Dinamicki alocirana matrica:" << std::endl;
		int broj_reda(-1);
		for (int i=0; i<brojac; i++) {
			for (int j=0; j<osnovni; j++) {
				broj_reda++;
				for (int k=0; k<vektor.at(j); k++) {
					std::cout << std::left << std::setw(3) << pok[broj_reda][k];
				}
				if (tip_alokacije==1) delete[] pok[broj_reda];
				std::cout << std::endl;
			}
		}
		if (tip_alokacije==0) delete[] pok[0];
		delete[] pok;
	}
	catch(const char tekst[]) {
		std::cout << "Izuzetak: " << tekst;
	}
	catch(std::domain_error e) {
		std::cout << "Izuzetak: " << e.what();
	}
	catch(...) {
		std::cout << "Izuzetak: Nedovoljno memorije!";
	}
	return 0;
}
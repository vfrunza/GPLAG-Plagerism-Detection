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
#include <iomanip>
#include <algorithm>

using std::vector;


template<typename tip>
	bool TestPerioda(const vector<tip> &nizBrojeva,int p) {
		if(p<1 || p>=nizBrojeva.size()) 
			return false;
		for(int i=0;i<nizBrojeva.size()-p;i++) {
			if(nizBrojeva.at(i) != nizBrojeva.at(i+p)) 
				return false;
		}
		return true;
	}
template<typename tip>
	int OdrediOsnovniPeriod(const vector<tip> &nizBrojeva) {
		for(int i=1;i<nizBrojeva.size();i++) {
			if(TestPerioda(nizBrojeva,i)==true) 
				return i;
		}
		return nizBrojeva.size(); // SAMO ZA OVAJ ZADATAK , INAČE JE 0 PERIOD
	}

template<typename tip>
	int **AlocirajFragmentirano(const vector<tip> &v , int &koliko_puta) {
		if (v.size() == 0)
			throw ("Prazan vektor!");
		for(tip x : v ) 
			if(x<=0) throw std::domain_error("Neispravan vektor!");
		int osnovniPeriod = OdrediOsnovniPeriod(v);
		int novaDuzina;
		if(osnovniPeriod == v.size()) {
			koliko_puta = 2;
			novaDuzina = v.size()*2;
		}
		else {
			novaDuzina = v.size();
			while(novaDuzina % osnovniPeriod != 0)
				novaDuzina++;
			koliko_puta = novaDuzina / osnovniPeriod ;
		}
		
		// ALOKACIJA I POPUNJAVANJE GRBAVE MATRICE
		int **grbava = new int*[novaDuzina]{};
			
		int brojac = 0;
		int max = *std::max_element(v.begin(),v.end());
		try {
			for(int i=0;i<koliko_puta;i++) {
				for(int j=0;j<osnovniPeriod;j++) {
					grbava[brojac] = new tip[v.at(j)]; // ALOKACIJA REDOVA
					for(int k=0;k<v.at(j);k++)
						grbava[brojac][v.at(j)-1-k] = max - k;	// POPUNJAVANJE REDA
					brojac++;
				}
			}
		}
		catch (std::bad_alloc) {
			for(int i=0;i<novaDuzina;i++)
				delete[] grbava[i];
			delete[] grbava;
			throw;
		}
		return grbava;
	}
template<typename tip>
	int **AlocirajKontinualno(const vector<tip> &v , int &koliko_puta) {
		if (v.size() == 0)
			throw ("Prazan vektor!");
		for(tip x : v ) 
			if(x<=0) throw std::domain_error("Neispravan vektor!");
		int osnovniPeriod = OdrediOsnovniPeriod(v);
		int novaDuzina;
		if(osnovniPeriod == v.size()) {
			koliko_puta = 2;
			novaDuzina = v.size()*2;
		}
		else {
			novaDuzina = v.size();
			while(novaDuzina % osnovniPeriod != 0)
				novaDuzina++;
			koliko_puta = novaDuzina / osnovniPeriod ;
		}
		
		// ALOKACIJA I POPUNJAVANJE GRBAVE MATRICE
		int **grbava = new int*[novaDuzina]{};
		int brElem = 0;
		for(int i=0;i<osnovniPeriod;i++)
			brElem+=v.at(i);
		brElem*=koliko_puta;
		
		int brojac = 1;
		try {
			grbava[0] = new tip[brElem];
				
			for(int i=0;i<koliko_puta;i++) {
				for(int j=0;j<osnovniPeriod;j++) {
					if(brojac==novaDuzina)
						break;
					grbava[brojac] = grbava[brojac-1]+v.at(j); // ALOKACIJA REDOVA
					brojac++;
				}
			}
			brojac = 0;
			for(int i=0;i<koliko_puta;i++) {
				for(int j=0;j<osnovniPeriod;j++) {   // POPUNJAVANJE REDOVA
					for(int k=0;k<v.at(j);k++)
						grbava[brojac][v.at(j)-1-k] = k+1;
					brojac++;
				}
			}
		}
		catch (std::bad_alloc) {
			delete[] grbava;
			throw;
		}
		return grbava;
	}

int main ()
{
	try {
		std::cout<<"Unesite broj elemenata vektora: ";
		int n;
		std::cin>>n;
		std::cout<<"Unesite elemente vektora: ";
		vector<int> v(n);
		for(int i=0;i<n;i++) 
			std::cin>>v.at(i);
		int izbor;
		std::cout<<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
		std::cin>>izbor;
		int **matrica = nullptr;
		int koliko_puta;
		if(izbor==1) 
			matrica = AlocirajFragmentirano(v,koliko_puta);
		else
			matrica = AlocirajKontinualno(v,koliko_puta);
		int brojac = 0;
		std::cout<<"Dinamicki alocirana matrica: \n";
		for(int i=0;i<koliko_puta;i++) {          // ISPIS
			for(int j=0;j<OdrediOsnovniPeriod(v);j++) {
				for(int k=0;k<v.at(j);k++)
					std::cout<<std::setw(3)<<std::left<<matrica[brojac][k];
				brojac++;
				std::cout<<"\n";
			}
		} 
		if(izbor==1) {
			for(int i=0;i<brojac;i++)
				delete[] matrica[i];
			delete[] matrica;
		}
		else {
			delete[] matrica[0];
			delete[] matrica;
		}
	} 
	catch (const char poruka[]) {
		std::cout<<"Izuzetak: "<<poruka;
	}
	catch(std::domain_error d) {
		std::cout<<"Izuzetak: "<<d.what();
	}
	
	return 0;
}
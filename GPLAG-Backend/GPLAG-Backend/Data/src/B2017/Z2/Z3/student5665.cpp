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
#include <new>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iomanip>


template <typename cjelobrojni>
bool JeLiPeriod (const std::vector<cjelobrojni> &v, int p) {
	if (p<1 || p>=v.size()) return false;
	
	int n(v.size()-p);
	
	for (int i=0; i<n; i++)
		if (v[i]!=v[i+p]) {
			return false;
			break;
		}
	
	return true;
}

template <typename cjelobrojni>
int OsnovniPeriod (const std::vector<cjelobrojni> &v) {
	
	for (int i=1; i<v.size(); i++)
		if (JeLiPeriod(v, i)==true)
			return i;
	
	return 0;
}


template <typename cjelobrojni>
int **AlocirajFragmentirano (const std::vector<cjelobrojni> &v, int &koliko_puta) {
	
	int osnovni_period(OsnovniPeriod(v));
	int velicina(v.size());
	
	if (v.size()==0) throw "Prazan vektor!";
	
	for (int i=0; i<v.size(); i++)
		if (v[i]<=0) throw std::domain_error ("Neispravan vektor!");
	
	// odredjivanje velicine najveceg reda
	int max=v[0];
	for (int i=0; i<v.size(); i++) 
		if (v[i]>max)
			max=v[i];
	
	if (osnovni_period!=0) {
		while (velicina%osnovni_period!=0) velicina++;
		koliko_puta=velicina/osnovni_period;
	}
	else {
		osnovni_period=v.size();
		velicina*=2;
		koliko_puta=2;
	}
	
	
	int n(koliko_puta*osnovni_period);
	
	try {
		int **pok(new int*[n] {});
		
		try {
			int j=0;
			for (int i=0; i<n; i++) {
				pok[i]=new int [v[j]];
				// popunjavanje
				int help_max=max;
				for (int k=v[j]-1; k>=0; k--, help_max--)
					pok[i][k]=help_max;
				
				if (j==osnovni_period-1) j=0;
				else j++;
			}
			
			return pok;
		}
		catch (std::bad_alloc) {
			for (int i=0; i<n; i++) delete[] pok[i];
			delete[] pok;
			throw std::bad_alloc();
		}	
	}
	catch (std::bad_alloc) {
		throw std::bad_alloc();
	}
}


template <typename cjelobrojni>
int** AlocirajKontinualno (const std::vector<cjelobrojni> &v, int &koliko_puta) {
	
	int osnovni_period(OsnovniPeriod(v));
	int velicina(v.size());
	
	if (v.size()==0) throw "Prazan vektor!";
	
	for (int i=0; i<v.size(); i++)
		if (v[i]<=0) throw std::domain_error ("Neispravan vektor!");
	
	if (osnovni_period!=0) {
		while (velicina%osnovni_period!=0) velicina++;
		koliko_puta=velicina/osnovni_period;
	}
	else {
		osnovni_period=v.size();
		velicina*=2;
		koliko_puta=2;
	}
	
	
	int n(koliko_puta*osnovni_period);
	
	int zbir_perioda(0);
	for (int i=0; i<osnovni_period; i++)
		zbir_perioda+=v[i];
	int broj_elemenata(zbir_perioda*koliko_puta);
	
	try {
		int **pok(new int*[n] {});
		
		try {
			int j=1;
			pok[0]=new int [broj_elemenata];
			int element=1;
			for (int k=v[0]-1; k>=0; k--, element++)
					pok[0][k]=element;
			int pozicija(v[0]);
			for (int i=1; i<n; i++) {
				pok[i]=pok[0]+pozicija;
				// popunjavanje
				element=1;
				for (int k=v[j]-1; k>=0; k--, element++)
					pok[i][k]=element;
				
				pozicija+=v[j];
				if (j==osnovni_period-1) j=0;
				else j++;
			}
			
			return pok;
		}
		catch (std::bad_alloc) {
			delete[] pok[0];
			delete[] pok;
			throw std::bad_alloc();
		}	
	}
	catch (std::bad_alloc) {
		throw std::bad_alloc();
	}
}



int main ()
{
	int broj, broj_perioda;
	bool opcija;
	
std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> broj;
	std::vector<int> v(broj);	
	std::cout << "Unesite elemente vektora: ";
	for (int i=0; i<broj; i++)
		std::cin >> v[i];
	std::cout << "Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
	std::cin >> opcija;

	try {
		int** p;
		if (opcija==1) p=AlocirajFragmentirano(v, broj_perioda);
		else p=AlocirajKontinualno(v, broj_perioda);
		std::cout << "Dinamicki alocirana matrica:" << std::endl;
		
		int osnovni_period(OsnovniPeriod(v));
		int n(broj_perioda*osnovni_period);
		if (osnovni_period==0) {
			osnovni_period=v.size();
			n=v.size()*2;
		}
		int j=0;
		for (int i=0; i<n; i++) {
			for (int k=0; k<v[j]; k++)
				std::cout << std::setw(3) << std::left << p[i][k];
			std::cout << std::endl;
			if (j==osnovni_period-1) j=0;
			else j++;
		}
		if (opcija==1) {
			for (int i=0; i<n; i++) delete[] p[i];
			delete[] p;
			return 0;
		}
		else {
			delete[] p[0];
			delete[] p;
			return 0;
		}
	}
	catch (const char poruka[]) {
		std::cout << "Izuzetak: " << poruka << std::endl;
	}
	catch (std::domain_error e) {
		std::cout << "Izuzetak: " << e.what() << std::endl;
	}
	catch (std::bad_alloc) {
		std::cout << "Izuzetak: " << "Problemi sa memorijom" << std::endl;
	}

	return 0;
}
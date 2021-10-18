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
#include <new>
#include <iomanip>

using namespace std;

template<typename NekiTip>
bool TestPerioda(const vector<NekiTip> &elementi, int period) {
	if (period >= elementi.size() || period <= 0)
		return false;
	for (int i = 0; i < elementi.size()-period; i++) 
		if (elementi.at(i) != elementi.at(i + period))
			return false;
	
	return true;
}

template<typename NekiTip>
int Period(const vector<NekiTip> &elementi) {
	//vraca 0 ako niz nije periodican	
	//u suprotnom vraca period
	for (int i = 1; i < elementi.size(); i++)
		if (TestPerioda(elementi, i)) return i;
		
	return 0;
}

template<typename NekiTip>
void ProvjeriVektor(const vector<NekiTip> &elementi) {
	//ako je prazan vektor
	if (elementi.size() == 0)
		throw ("Prazan vektor!");
	//ako u vektoru ima besmislenih vrijednosti	
	for (int i = 0; i < elementi.size(); i++)
		if (elementi.at(i) <= 0)
			throw domain_error("Neispravan vektor!");
}

template<typename NekiTip>
NekiTip** AlocirajFragmentirano(const vector<NekiTip> &elementi, int &koliko_puta) {
	//ne dodavati elemente u vektor nego pri alokaciji nastaviti dok se osnovni period ne ponovi do kraja
	NekiTip** matrica = nullptr;
	try {
		
		ProvjeriVektor(elementi);
		
		int period = Period(elementi);
		
		if (period == 0) {
			koliko_puta = 2;
			period = elementi.size();
		} 
		else {
			int brojac = 0;
			for (int i = period-1; i < elementi.size(); i += period)
				brojac++;
			
			if (elementi.at(elementi.size()-1) != elementi.at(period-1))
				brojac++;
			
			koliko_puta = brojac;	
		}
		
		int br_redova = period * koliko_puta;
		//alokacija redova
		matrica = new NekiTip* [br_redova]{};
		for (int i = 0; i < br_redova; i++)
			matrica[i] = nullptr;
			
		try {
			//alokacija kolona
			int periodicni_dio = period * (koliko_puta - 1);
			for (int i = 0; i < br_redova; i++) {
				NekiTip element;
				if (i < periodicni_dio)
					element = elementi.at(i);
				else
					element = elementi.at(i - period);
					
				matrica[i] = new NekiTip[element];
			}
			
			//najveci element u periodu
			NekiTip max_element = elementi.at(0);
			for (int i = 0; i < period; i++)
				if (elementi.at(i) > max_element)
					max_element = elementi.at(i);
			//popunjavanje matrice		
			for (int i = 0; i < br_redova; i++) {
				NekiTip temp = max_element;
				for (int j = elementi.at(i%period) - 1; j >= 0; j--) {
					matrica[i][j] = temp;
					temp--;
				}
			}
			
			return matrica;
			
		} catch (...) {
			for (int i = 0; i < koliko_puta * period; i++)
				delete[] matrica[i];
			delete[] matrica;
			
			throw;
		}
		
	} catch (...) {
		delete[] matrica;
		
		throw;
	}
}

/*------------------------------------------------------------------------------------------------------------------*/

template<typename NekiTip>
NekiTip** AlocirajKontinualno(const vector<NekiTip> &elementi, int &koliko_puta) {
	NekiTip** matrica = nullptr;
	try {
		
		ProvjeriVektor(elementi);
		
		int period = Period(elementi);
		if (period == 0) {
			koliko_puta = 2;
			period = elementi.size();
		}
		else {
			int brojac = 0;
			for (int i = period-1; i < elementi.size(); i += period)
				brojac++;
			
			if (elementi.at(elementi.size()-1) != elementi.at(period-1))
				brojac++;
			
			koliko_puta = brojac;
		}
		
		
		int br_redova = koliko_puta * period;
		matrica = new NekiTip* [br_redova]{};
		for (int i = 0; i < br_redova; i++)
			matrica[i] = nullptr;
			
		try {
			//treba nam suma svih elemenata
			int periodicni_dio = period * (koliko_puta - 1);
			int suma_elemenata = 0;
			for (int i = 0; i < koliko_puta * period; i++) {
				if (i < periodicni_dio)
					suma_elemenata += elementi.at(i);
				else
					suma_elemenata += elementi.at(i - period);
			}
			//alociranje kontinualne matrice
			matrica[0] = new NekiTip[suma_elemenata];
			//rasporedjivanje pokazivaca
			for (int i = 1; i < br_redova; i++) {
				NekiTip element;
				if (i - 1 < periodicni_dio)
					element = elementi.at(i - 1);
				else
					element = elementi.at(i - period - 1);
					
				matrica[i] = matrica[i - 1] + element;
			}
			//Popunjavanje matrice
			for (int i = 0; i < br_redova; i++) {
				NekiTip element;
				if (i < periodicni_dio)
					element = elementi.at(i);
				else
					element = elementi.at(i - period);

				for (int j = 0; j < element; j++) {
					matrica[i][j] = element - j;
				}
			}

			return matrica;
			
		} catch (...) {
			delete[] matrica[0];
			delete[] matrica;
			throw;
		}
	} catch (...) {
		delete[] matrica;
		throw;
	}
	
}


int main () {
	// 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5
	try {
		
		//ISPIS ZA FRAGMENTIRANU
		int broj_elemenata;
		cout << "Unesite broj elemenata vektora: ";
		cin >> broj_elemenata;
		
		cout << "Unesite elemente vektora: ";
		vector<int> elementi(broj_elemenata);
		for (int i = 0; i < broj_elemenata; i++)
			cin >> elementi.at(i);
		
		int f;	
		cout << "Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
		cin >> f;
		
		int koliko_puta;
		int** matrica;

		if (f == 1) 
			matrica = AlocirajFragmentirano(elementi, koliko_puta);
		else if (f == 0)
			matrica = AlocirajKontinualno(elementi, koliko_puta);
		
		int period = Period(elementi);
		//ako nije periodican niz vratit ce 0
		if (period == 0)
			period = elementi.size();
			
		int konacna_velicina = period * koliko_puta;
		int periodicni_dio = period * (koliko_puta - 1);
		
		//cout << periodicni_dio << endl << endl;
		
		cout << "Dinamicki alocirana matrica:" << endl;
		for (int i = 0; i < konacna_velicina; i++) {
			int granica;
			if (i < periodicni_dio)
				granica = elementi.at(i);
			else 
				granica = elementi.at(i - period);
				
			for (int j = 0; j < granica; j++)
				cout << setw(2) << left << matrica[i][j] << " ";
				
			cout << endl;
		}
		
		// 1 2 3 1 2 3 1 | 2 3 - ovi koji su dodani se moraju takodjer dealocirat
		if (f == 1)
			for (int i = 0; i < konacna_velicina; i++)
				delete[] matrica[i];
		else if (f == 0)
			delete[] matrica[0];
			
		delete[] matrica;
		
	} catch (bad_alloc izuzezak) {
		cout << "Izuzetak: " << izuzezak.what() << endl;
	} catch (domain_error izuzetak) {
		cout << "Izuzetak: " << izuzetak.what() << endl;
	} catch (const char poruka[]) {
		cout << "Izuzetak: " << poruka << endl;
	} 
	
	return 0;
}
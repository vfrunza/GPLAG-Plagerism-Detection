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

bool TestPerioda (const std::vector<int> &v, int p)
{
	for(int i=0; i<v.size()-p; i++) {
		if(v[i] != v[i+p])
			return false;
	}
	return true;
}

int OdrediOsnovniPeriod (const std::vector<int> &v)
{
	for(int i=1; i<v.size(); i++) {
		if(TestPerioda(v,i)) return i;
	}

	return v.size();
}

int** AlocirajFragmentirano (const std::vector<int> &v, int &koliko_puta)
{
	if(v.size() == 0) throw std::domain_error ("Prazan vektor!");
	for(int i=0; i<v.size(); i++) {
		if(v[i] <= 0) throw std::domain_error ("Neispravan vektor!");
	}

	int period(OdrediOsnovniPeriod(v));
	if(period != v.size() && v.size()%period == 0)
		koliko_puta = v.size() / period ;
	else if(period !=v.size())
		koliko_puta = int(v.size()/period) + 1;
	else
		koliko_puta=2;

	int** matrica(nullptr);
	try {
		int duzina(koliko_puta*period);
		matrica = new int*[duzina] {};
		for(int i=0; i<duzina; i++) {
			int m;
			if(i>=v.size()) m=i-period;
			else m=i;
			matrica[i] = new int[v[m]];
		}
		int m;
		for(int i=0; i<duzina; i++) {
			int k(v[period-1]);
			if(i>=v.size()) m=i-period;
			else m=i;
			for(int j=v[m]-1; j>=0; j--) {
				matrica[i][j] = k;
				k--;
			}
		}
	} catch(std::bad_alloc) {
		if(matrica != nullptr) {
			for( int i=0; i<koliko_puta*period; i++)
				delete[] matrica[i];
		}
		delete[] matrica;
		throw;
	}

	return matrica;
}

int** AlocirajKontinualno(const std::vector<int> &v, int &koliko_puta)
{ 
	if(v.size() == 0) throw std::domain_error ("Prazan vektor!");
	for(int i=0; i<v.size(); i++) {
		if(v[i] <= 0) throw std::domain_error ("Neispravan vektor!");
	}

	int period(OdrediOsnovniPeriod(v));
	if(period != v.size() && v.size()%period == 0)
		koliko_puta = v.size() / period ;
	else if(period !=v.size())
		koliko_puta = int(v.size()/period) + 1;
	else
		koliko_puta=2;

	int** matrica(nullptr); 
	try {
		int duzina(koliko_puta*period);
		matrica=new int*[duzina] {};

		int suma(0);
		for(int i=0; i<period; i++) suma+=v[i];
		matrica[0] = new int[koliko_puta*suma];
		int m;
		for(int i=1; i<duzina; i++) {
			if(i>v.size()) m=i-period;
			else m=i;
			matrica[i] = matrica[i-1] + v[m-1];
		}
		
		for(int i=0; i<duzina; i++) {
			int k(1);
			if(i>=v.size()) m=i-period;
			else m=i;
			for(int j=v[m]-1; j>=0; j--) {
				matrica[i][j] = k;
				k++;
			}
		}

	} catch (std::bad_alloc) {
		if(matrica != nullptr) delete[] matrica[0];
		delete[] matrica;
		throw;
	}


	return matrica;

}


int main ()
{
	std::cout << "Unesite broj elemenata vektora: ";
	int br_el;
	std::cin >> br_el;
	std::vector<int> v(br_el);
	std::cout << "Unesite elemente vektora: ";
	for(auto &e : v) std::cin >> e;

	std::cout << "Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
	int f;
	std::cin >> f;
	int koliko_puta;
	int**matrica(nullptr);

	int period;

	try {
		if(f==1) matrica=AlocirajFragmentirano(v,koliko_puta);
		else matrica=AlocirajKontinualno(v, koliko_puta);

		period=OdrediOsnovniPeriod(v);

		std::cout << "Dinamicki alocirana matrica:" << std::endl;
		int k;
		for( int i=0; i<koliko_puta*period; i++) {
			if(i>=v.size()) k=i-period;
			else k=i;
			for(int j=0; j<v[k]; j++) {
				std::cout << std::left << std::setw(3) << matrica[i][j];
			}
			std::cout << std::endl;
		}

		if(f==1) {
			for( int i=0; i<koliko_puta*period; i++)
				delete[] matrica[i];
			delete[] matrica;
		} else {
			if(matrica != nullptr) delete[] matrica[0];
			delete[] matrica;
		}
	} catch(std::domain_error izuzetak) {
		std::cout << "Izuzetak: " <<izuzetak.what() << std::endl;
	} catch(std::bad_alloc izuzetak) {
		std::cout << "Izuzetak: " <<izuzetak.what() << std::endl;
		if(f==1) {
			if(matrica!=nullptr) {
				for( int i=0; i<koliko_puta*period; i++)
					delete[] matrica[i];
			} 
			delete[] matrica;
		} else {
			if(matrica != nullptr) delete[] matrica[0];
			delete[] matrica;
		}
	}

	return 0;
}
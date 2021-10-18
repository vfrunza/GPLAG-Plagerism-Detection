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

template<typename Tip>
int Najvecielem( Tip &v1)
{
	int max = v1[0];
	for(int i = 0; i < v1.size(); i++) {
		if(v1[i] > max) max = v1[i];
	}
	return max;
}

template<typename Tip>
int Period(const std::vector<Tip> &vek1,int &n1)
{
	int period(1);
	bool jeste_period(false);
	for(int i=0; i <vek1.size(); i++) {
		if(i + period == vek1.size()-1 && vek1[i] == vek1[i+period]) {
			jeste_period = true;
			break;
		} else if(i + period == vek1.size()-1 && vek1[i] != vek1[i+period]) {
			jeste_period = false;
			break;
		}
		if (vek1.size() > 1) {
			if(vek1[i] != vek1[i+period]) {
				period++;
				i = -1;
			}
		}
	}
	if(jeste_period) {
		if(vek1.size() % period != 0) n1 = vek1.size()/period + 1;
		else n1 = vek1.size() / period;
	} else {
		period++;
		n1 = 2;
	}
	return period;
}

template<typename Tip>
int **AlocirajFragmentirano(const std::vector<Tip> &vek, int &n)
{
	if(vek.size() == 0) throw std::domain_error ("Prazan vektor!");
	for(int i = 0; i < vek.size(); i++) {
		if(vek[i] < 1) throw std::domain_error("Neispravan vektor!");
	}

	int period = Period(vek, n);

	int **pok(nullptr);
	try {
		pok = new int*[n*period] {};
		for(int i = 0; i < n*period; i++) {
			if(i > vek.size() - 1) {
				int ind = i;
				for(int j = i - period; j < n*period - period; j++) { // pravim nizove na koje ce pokazivaci pokazivati
					pok[ind] = new int[vek[j]];
					ind++;
				}
				break;
			} else pok[i] = new int[vek[i]];
		}

		int max(Najvecielem(vek));
		int najveci;
		//popunjavanje matrice
		for(int i = 0; i < n*period; i++) {//i
			najveci = max;
			if(i > vek.size() - 1) {
				for(int j = vek[i - period] - 1; j >= 0 ; j--) {//j
					pok[i][j] = najveci;
					najveci--;;
				}
			} else {
				for(int k = vek[i]-1; k >= 0; k--) {//k
					pok[i][k] = najveci;
					najveci--;
				}
			}
		}


	} catch (...) {
		for(int i = 0; i < n*period; i++) delete [] pok[i];
		delete [] pok;
		throw;
	}

	return pok;
}

//////////////////////////////////////////////////////////////////////////

template<typename Tip>
int **AlocirajKontiunalno(const std::vector<Tip> &vek, int &n)
{
	if(vek.size() == 0) throw std::domain_error ("Prazan vektor!");
	for(int i = 0; i < vek.size(); i++) {
		if(vek[i] < 1) throw std::domain_error("Neispravan vektor!");
	}

	int period = Period(vek,n);

	//suma
	int suma(0);
	for(int i = 0; i < period; i++) suma += vek[i];
	suma *= n;

	int **pok(nullptr);
	try {
		pok = new int*[n*period] {};
		pok[0] = new int[suma];

	bool prvi_put(true);
	int tmp(1);
	for(int i = 1; i < n*period; i++) {
			
			if(i > vek.size()-1) {
				 if(prvi_put && n==2) {
					int index = i - tmp;
					pok[i] = pok[i-1] + vek[index];
					tmp++;
					prvi_put = false;
				}
				 else {
					int index = i - period;
					if(index == 0) index += 1;
					pok[i] = pok[i-1] + vek[index-1];
				}
			} else {
				pok[i] = pok[i-1] + vek[i-1];
			
			}
		}

		//popunjavanje matrice
		for(int i = 0; i < n*period; i++) {//i
			if(i >= vek.size()) {
				int index1(0);
				for(int j = vek[i - period]; j > 0 ; j--) {//j
					pok[i][index1] = j;
					index1++;
				}
			} else {
				int index(0);
				for(int k = vek[i]; k > 0; k--) {//k
					pok[i][index] = k;
					index++;
				}
			}
		}


	} catch (...) {
		delete [] pok[0];
		delete [] pok;
		throw;
	}
	return pok;
}

int main ()
{
	int n;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;

	std::vector<int> v;
	std::cout << "Unesite elemente vektora: ";
	for(int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		v.push_back(x);
	}
	int aloc;
	std::cout << "Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
	std::cin >> aloc;
	int Kolikoima;
	try {


		if(aloc) {
			int **pok1 = AlocirajFragmentirano(v, Kolikoima);
			int period = Period(v,Kolikoima);

			std::cout << "Dinamicki alocirana matrica:" << std::endl;
			for(int i = 0; i < Kolikoima * period; i++) {
				if(i >= v.size() ) {
					for(int k = 0; k < v[i-period]; k++) {
						std::cout << pok1[i][k] << "  ";
					}
				} else {
					for(int j = 0; j < v[i]; j++) {
						std::cout << pok1[i][j] << "  ";
					}
				}
				std::cout << std::endl;
			}
			for(int i = 0; i < Kolikoima*period; i++) {
				delete [] pok1[i];
			}
			delete [] pok1;
		} else {
			if(aloc == 0) {
				int **pok1 = AlocirajKontiunalno(v, Kolikoima);

				int period = Period(v,Kolikoima);
				std::cout << "Dinamicki alocirana matrica:" << std::endl;
				for(int i = 0; i < Kolikoima * period; i++) {
					if(i >= v.size() ) {
						for(int k = 0; k < v[i-period]; k++) {
							std::cout << pok1[i][k] << "  ";
						}
					} else {
						for(int j = 0; j < v[i]; j++) {
							std::cout << pok1[i][j] << "  ";
						}
					}
					std::cout << std::endl;
				}
				delete [] pok1[0];
				delete [] pok1;

			}
		}


	} catch(std::domain_error Izuzetak) {
		std::cout << "Izuzetak: " << Izuzetak.what();
	} catch(std::bad_alloc) {
		std::cout << "Nedovoljno memorije!";
	}

	return 0;
}
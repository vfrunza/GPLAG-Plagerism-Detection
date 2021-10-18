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
#include <cmath>
#include <iomanip>
#include <stdexcept>
const double e(0.0001);

template <typename CjelobrojniTip1>
bool TestPerioda(const std::vector<CjelobrojniTip1> &V, int p)
{
	bool Period(true);
	if(p>=1 && p<V.size()) {
		for(int i=0; i<(V.size()-p); i++) {
			if(fabs(V.at(i)-V.at(i+p))>e) {
				return false;
			}
		}
	} else return false;
	return Period;
}

template <typename CjelobrojniTip3>
int Period(const std::vector<CjelobrojniTip3> &V)
{
	for(int i=0; i<V.size(); i++) {
		if(TestPerioda(V,i)) return i;
	}
	return 0;
}

template <typename CjelobrojniTip4>
int Najveci(const std::vector<CjelobrojniTip4> &V)
{
	int max(V[0]);
	for(int i=1; i<V.size(); i++) {
		if(V[i]>max) max=V[i];
	}
	return max;
}

template <typename CjelobrojniTip>

int **AlocirajFragmentirano(const std::vector<CjelobrojniTip> &V, int &koliko_puta)
{
	if(V.size()==0) throw "Izuzetak: Prazan vektor!";
	for(int i=0; i<V.size(); i++) {
		if(V[i]<=0) throw std::domain_error("Izuzetak: Neispravan vektor!");
	}
	int max(Najveci(V));
	int duzina(V.size()),period(0);
	for(int i=0; i<V.size(); i++) {
		if(TestPerioda(V,i)==true) {
			period=i;
			if(duzina%i!=0) {
				while(duzina%i!=0) {
					duzina++;
				}
				int br(1),brojac(0);
				for(int j=0; j<duzina; j++) {
					if(j==period*br-1) {
						brojac++;
						br*=2;
					}
				}
				koliko_puta=brojac;
				break;
			} else {
				koliko_puta=duzina/period;
				break;
			}
		}
		if(i==V.size()-1) {
			duzina*=2;
			koliko_puta=2;
			period=V.size();
		}
	}
	int **Mat=nullptr;
	try {
		Mat=new int*[duzina];
		for(int i=0; i<duzina; i++) {
			Mat[i]=nullptr;
		}
		try {
			int k(0);
			for(int i=0; i<duzina; i++) {
				Mat[i]=new int[V[k]];
				k++;
				if(k==period) k=0;
			}
			k=0;
			for(int i=0; i<duzina; i++) {
				int p(max);
				for(int j=V[k]-1; j>=0; j--) {
					Mat[i][j]=p;
					p--;
				}
				k++;
				if(k==period) k=0;
			}
			return Mat;
		} catch(std::bad_alloc) {
			for(int i=0; i<duzina; i++) {
				delete[] Mat[i];
			}
			delete[] Mat;
			throw;
		}
	} catch(std::bad_alloc) {
		throw;
	}
	return Mat;
}

template <typename CjelobrojniTip2>
int **AlocirajKontinualno(const std::vector<CjelobrojniTip2> &V, int &koliko_puta)
{
	if(V.size()==0) throw "Izuzetak: Prazan vektor!";
	for(int i=0; i<V.size(); i++) {
		if(V[i]<=0) throw std::domain_error("Izuzetak: Neispravan vektor!");
	}

	int duzina(V.size()), period(0);
	for(int i=0; i<V.size(); i++) {
		if(TestPerioda(V,i)==true) {
			period=i;
			if(duzina%i!=0) {
				while(duzina%i!=0) {
					duzina++;
				}
				int br(1),brojac(0);
				for(int j=0; j<duzina; j++) {
					if(j==br*period-1) {
						brojac++;
						br*=2;
					}
				}
				koliko_puta=brojac;
				break;
			} else {
				koliko_puta=duzina/period;
				break;
			}
		}
		if(i==V.size()-1) {
			duzina*=2;
			koliko_puta=2;
			period=V.size();
		}
	}

	int **M=nullptr;
	try {
		M=new int*[duzina];
		try {
			int br_elem(0);
			int m(0);
			for(int i=0; i<duzina; i++) {
				br_elem+=V[i];
				m++;
				if(m==period) break;
			}
			br_elem=koliko_puta*br_elem;
			M[0]=new int[br_elem];
			int k(0);
			for(int i=1; i<duzina; i++) {
				M[i]=M[i-1]+V[k];
				k++;
				if(k==period) k=0;
			}
		} catch(std::bad_alloc) {
			delete[] M;
			throw;
		}
	} catch(std::bad_alloc) {
		throw;
	}
	int k(0);
	for(int i=0; i<duzina; i++) {
		int p(1);
		for(int j=V[k]-1; j>=0; j--) {
			M[i][j]=p;
			p++;
		}
		k++;
		if(k==period) k=0;
	}
	return M;
}

int main ()
{

	std::cout << "Unesite broj elemenata vektora: ";
	int br_elem(0);
	std::cin >> br_elem;
	std::cout << "Unesite elemente vektora: ";
	std::vector<int> Vec;
	for(int i=0; i<br_elem; i++) {
		int broj;
		std::cin >> broj;
		Vec.push_back(broj);
	}
	int fk;
	std::cout << "Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
	std::cin >> fk;
	try {
		if(fk==1) {
			int period(Period(Vec));
			int broj_pon;
			int **AF(AlocirajFragmentirano(Vec,broj_pon));
			int br_redova(Vec.size());
			if(period==0) {
				period=Vec.size();
				br_redova*=2;
			} else {
				while(br_redova%period!=0) {
					br_redova++;
				}
			}
			std::cout << "Dinamicki alocirana matrica:" << std::endl;
			int i(0);
			for(int j=0; j<br_redova; j++) {
				for(int k=0; k<Vec[i]; k++) {
					std::cout << std::left << std::setw(3) << AF[j][k];
				}
				std::cout << std::endl;
				i++;
				if(i==period) i=0;
			}
			for(int i=0; i<br_redova; i++) {
				delete[] AF[i];
			}
			delete[] AF;
		} else if(fk==0) {
			int period(Period(Vec));
			int broj_pon;
			int **AK(AlocirajKontinualno(Vec,broj_pon));
			int br_redova(Vec.size());
			if(period==0) {
				period=Vec.size();
				br_redova*=2;
			} else {
				while(br_redova%period!=0) {
					br_redova++;
				}
			}
			std::cout << "Dinamicki alocirana matrica:" << std::endl;
			int i(0);
			for(int j=0; j<br_redova; j++) {
				for(int k=0; k<Vec[i]; k++) {
					std::cout << std::left << std::setw(3) << AK[j][k];
				}
				i++;
				if(i==period) i=0;
				std::cout << std::endl;
			}
			delete[] AK[0];
			delete[] AK;
		}
	} catch(std::bad_alloc) {
		std::cout << "Izuzetak: Nedovoljno memorije" << std::endl;
	} catch(const char izuzetak[]) {
		std::cout << izuzetak << std::endl;
	} catch(std::domain_error izuzetak) {
		std::cout << izuzetak.what() << std::endl;
	}
	return 0;
}
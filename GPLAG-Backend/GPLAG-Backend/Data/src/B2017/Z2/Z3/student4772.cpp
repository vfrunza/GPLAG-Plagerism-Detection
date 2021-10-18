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

template <typename CjelobrojniTip>
	bool DaLiJePeriodican(const std::vector<CjelobrojniTip>&v) {
		bool period;
		for (int i=1; i<int(v.size()); i++) {
			period=true;
			for (int j=0; j<int(v.size() - i); j++) {
				if(v.at(j)!=v.at(j+i)) {
					period=false;
					break;
				}
			}
			if (period) return true;
		}
		return false;
	}
	
template <typename CjelobrojniTip>
	int OsnovniPeriod (const typename std::vector<CjelobrojniTip>&v) {
		if(DaLiJePeriodican(v)) {
			for (int i=1; i<int(v.size()); i++) {
				bool period(true);
				for (int j=0; j<int(v.size()-i); j++) {
					if(v.at(j)!=v.at(j+i)) {
						period=false;
					}
				}
				if(period) return i;
			}
		} 
		return 0;
	}
	
template <typename CjelobrojniTip>
	int NajveciBroj (const typename std::vector<CjelobrojniTip>&v) {
		int max(v.at(0));
		for (int i=1; i<v.size(); i++) 
			if(v.at(i)>max) 
				max=v.at(i);
		return max;
	}

template <typename CjelobrojniTip>
	int** AlocirajFragmentirano (const typename std::vector<CjelobrojniTip>&v, int &koliko_puta) {
		if(v.size()==0) throw ("Prazan vektor!");
		for (int i=0; i<v.size(); i++) 
			if(v.at(i)<=0) throw std::domain_error ("Neispravan vektor!");
		int period (OsnovniPeriod(v));
		int vel;
		if(DaLiJePeriodican(v)) {
			for (int i=period+1; ; i++) {
				if(i%period==0) {
					vel=i;
					break;
				}
			}
			koliko_puta=vel/period;
		}
		else {
			koliko_puta=2;
			vel=koliko_puta*int(v.size());
		}
		int** p(nullptr);
		try {
			p=new int* [vel] {};	
			try {
				for (int i=0; i<vel; i++) {
					if(i<int(v.size()))
						p[i]=new int[v.at(i)];
					else {
						if(DaLiJePeriodican(v))
							p[i]=new int[v.at(i-period)];
						else p[i]=new int[v.at(i-v.size())];
					}
				}
				int maxbroj(NajveciBroj(v));
				for (int i=0; i<vel; i++) {
					if(i<int(v.size())) {
						p[i][0]=maxbroj-v.at(i) + 1;
						int k(p[i][0] + 1);
						for (int j=1; j<v[i]; j++) {
							p[i][j]=k;
							k++;
						}
					}
					else {
						if(DaLiJePeriodican(v)) {
							p[i][0]=maxbroj-v.at(i-period) + 1;
							int k(p[i][0] + 1);
							for (int j=1; j<v[i-period]; j++) {
								p[i][j]=k;
								k++;
							}
						} else {
							p[i][0]=maxbroj-v.at(i-v.size()) + 1;
							int k(p[i][0] + 1);
							for (int j=1; j<v[i-v.size()]; j++) {
								p[i][j]=k;
								k++;
							}
						}
					}
				}
				return p;
			} catch (std::bad_alloc) {
				for (int i=0; i<vel; i++) delete[] p[i];
				delete[] p;
				throw;
			}
		} catch (std::bad_alloc) {
			throw;
		}	
		
	}

	
template <typename CjelobrojniTip>
	int** AlocirajKontinualno (const typename std::vector<CjelobrojniTip>&v, int &koliko_puta) {
		/*Kopirala sam sadrzaj prethodne funkcije, pa onda prilagodjavala ovoj novoj funkciji*/
		if(v.size()==0) throw ("Prazan vektor!");
		for (int i=0; i<v.size(); i++) 
			if(v.at(i)<=0) throw std::domain_error ("Neispravan vektor!");
		int period (OsnovniPeriod(v));
		int vel;
		if(DaLiJePeriodican(v)) {
			for (int i=period+1; ; i++) {
				if(i%period==0) {
					vel=i;
					break;
				}
			}
			koliko_puta=vel/period;
		}
		else {
			koliko_puta=2;
			vel=koliko_puta*int(v.size());
		}
		int** p {};
		try {
			int suma(0);
			for (int i=0; i<v.size(); i++) suma+=v.at(i);
			p=new int* [vel] {};	
			try {
				p[0]=new int [suma];
			/*	for (int i=1; i<vel; i++) {
					if(DaLiJePeriodican(v)) {
						if(i<int((koliko_puta-1)*period)) {
							p[i]=p[i-1] + v.at(i-1);
						} else p[i]=p[i-1] + v.at(i-period);
					}
					else {
						if(i<v.size()) {
							p[i]=p[i-1] + v.at(i-1);
						} else p[i]=p[i-1] + v.at(i-int(v.size()));
					}
				}*/
				
				
				for (int i=1; i<vel; i++) {
					if (i<v.size()) p[i]=p[i-1] + v.at(i-1);
					else  {
						if(!DaLiJePeriodican(v))
							p[i]=p[i-1] + v.at(i-int(v.size()));
						else p[i]=p[i-1] + v.at(i-period);
					}
				}
				for (int i=0; i<vel; i++) {
					if(DaLiJePeriodican(v)) {
						if(i<int((koliko_puta-1)*period)) {
							p[i][0]=v.at(i);
							int k(p[i][0]-1);
							for (int j=1; j<v[i]; j++) {
								p[i][j]=k;
								k--;
							}
						} else {
							p[i][0]=v.at(i-period);
							int k(p[i][0]-1);
							for (int j=1; j<v.at(i-period); j++) {
								p[i][j]=k;
								k--;
							}
						}
					}
					else {
						if(i<v.size()) {
							p[i][0]=v.at(i);
							int k(p[i][0]-1);
							for (int j=1; j<v.at(i); j++) {
								p[i][j]=k;
								k--;
							}
						} else {
							int q=i-int(v.size());
							p[i][0]=v.at(q);
							int k(p[i][0]-1);
							for (int j=1; j<v.at(q); j++) {
								p[i][j]=k;
								k--;
							}
						}
						
					}
				}
				return p;
			} catch (std::bad_alloc) {
				delete[] p;
				throw;
			}
		} catch (std::bad_alloc) {
			throw;
		}	
		
	}

int main ()
{
	try {
		std::cout << "Unesite broj elemenata vektora: ";
		int n;
		std::cin >> n;
		std::vector<int> v (n);
		std::cout << "Unesite elemente vektora: ";
		for (int i=0; i<n; i++) 
			std::cin >> v.at(i);
		std::cout << "Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
		int opcija;
		std::cin >> opcija;
		int** p;
		int koliko_puta;
		int period(OsnovniPeriod(v));
		int vel;
		if(opcija==1) p=AlocirajFragmentirano(v, koliko_puta);
		else p=AlocirajKontinualno(v, koliko_puta);
		if(DaLiJePeriodican(v)) vel=koliko_puta*period;
		else vel=2*v.size();
		std::cout << "Dinamicki alocirana matrica:" << std::endl;
			if(DaLiJePeriodican(v)) {
					for (int i=0; i<vel; i++) {
						if(i<v.size()) {
							for (int j=0; j<v.at(i); j++) {
								std::cout << std::setw(3) << std::left << p[i][j];
							}
						} else for (int j=0; j<v.at(i-period); j++) 
							std::cout << std::setw(3) << std::left << p[i][j];
						std::cout << std::endl;
					}
			} else {
					for (int i=0; i<vel; i++) {
						if(i<v.size()) {
							for (int j=0; j<v.at(i); j++) {
								std::cout << std::setw(3) << std::left << p[i][j];
							}
						} else {
							int b=v.size();
							for (int j=0; j<v.at(i-b); j++) 
								std::cout << std::setw(3) << std::left << p[i][j];
						}
						std::cout << std::endl;
					}
			}
	
		if(opcija==0) delete[] p[0];
		else 
			for (int i=0; i<vel; i++) delete[] p[i];
		
		delete[] p;
	}	
	catch (std::domain_error izuzetak) {
		std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
	}
	catch (const char e[]) {
		std::cout << "Izuzetak: " << e << std:: endl;
	}
	catch (...) {
		std::cout << "Nedovoljno memorije." << std::endl;
	}
	
	return 0;
}
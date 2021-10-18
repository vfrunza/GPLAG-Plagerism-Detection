/*B 2017/2018, Zadaća 2, Zadatak 2

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
#include <deque>
#include <stdexcept>
#include <type_traits>

enum class SmjerKretanja
{
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template<typename tip>
tip PjescaniSat (tip kont, SmjerKretanja smjer)
{
	int n(kont.size());
	for(int i=0; i<n; i++) if(kont.at(i).size()!=n) throw std::domain_error ("3D matrica nema oblik kocke");
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++) if(kont.at(i).at(j).size()!=n) throw std::domain_error ("3D matrica nema oblik kocke");
	if(n%2==0) throw std::length_error ("3D kontejner ne zadovoljava uvjet neparnosti");
	tip sat(n, typename std::remove_reference<decltype(kont.at(0))>::type (n));
	//2
	if(smjer==SmjerKretanja::GoreDolje) {
		for(int k=0; k<n; k++) {
			for(int i=0; i<n; i++) {
				for(int j=0; j<n; j++) {
					if(i<=n/2 && (j>=i && j<(n-i))) sat.at(k).at(i).push_back(kont.at(k).at(i).at(j));
					else if(i>n/2 && (j>=(n-i-1) && j<=i)) sat.at(k).at(i).push_back(kont.at(k).at(i).at(j));
					else continue;
				}
			}
		}
	}
	//3
	else if(smjer==SmjerKretanja::DoljeGore) {
		for(int k=0; k<n; k++) {
			int br(0);
			for(int i=n-1; i>=0; i--) {
				for(int j=0; j<n; j++) {
					if(i<=n/2 && (j>=i && j<(n-i))) sat.at(k).at(br).push_back(kont.at(k).at(i).at(j));
					else if(i>n/2 && (j>=(n-i-1) && j<=i)) sat.at(k).at(br).push_back(kont.at(k).at(i).at(j));
				}
				br++;
			}
		}
	}
	//5
	else if(smjer==SmjerKretanja::DesnoLijevo) {
		for(int k=0; k<n; k++) {
			int br(0);
			for(int i=n-1; i>=0; i--) {
				for(int j=0; j<n; j++) {
					if(i<=n/2 && (j>=i && j<(n-i))) sat.at(k).at(br).push_back(kont.at(k).at(j).at(i));
					else if(i>n/2 && (j>=(n-i-1) && j<=i)) sat.at(k).at(br).push_back(kont.at(k).at(j).at(i));
				}
				br++;
			}
		}
	}
	//4
	else if(smjer==SmjerKretanja::LijevoDesno) {
		for(int k=0; k<n; k++) {
			int br(0);
			for(int i=0; i<n; i++) {
				for(int j=0; j<n; j++) {
					if(i<=n/2 && (j>=i && j<(n-i))) sat.at(k).at(br).push_back(kont.at(k).at(j).at(i));
					else if(i>n/2 && (j>=(n-i-1) && j<=i)) sat.at(k).at(br).push_back(kont.at(k).at(j).at(i));
				}
				br++;
			}
		}
	}
	//0
	else if(smjer==SmjerKretanja::NaprijedNazad) {
		for(int k=0; k<n; k++) {
			int br(0);
			for(int i=0; i<n; i++) {
				for(int j=0; j<n; j++) {
					if(i<=n/2 && (j>=i && j<(n-i))) sat.at(k).at(i).push_back(kont.at(br).at(k).at(j));
					else if(i>n/2 && (j>=(n-i-1) && j<=i)) sat.at(k).at(i).push_back(kont.at(br).at(k).at(j));
				}
				br++;
			}
		}
	}
	//1
	else if(smjer==SmjerKretanja::NazadNaprijed) {
		for(int k=0; k<n; k++) {
			int br(0);
			for(int i=n-1; i>=0; i--) {
				for(int j=0; j<n; j++) {
					if(i<=n/2 && (j>=i && j<(n-i))) sat.at(k).at(i).push_back(kont.at(br).at(k).at(j));
					else if(i>n/2 && (j>=(n-i-1) && j<=i)) sat.at(k).at(i).push_back(kont.at(br).at(k).at(j));
				}
				br++;
			}
		}
	}
	return sat;
}

int main ()
{
	int n, smjer;
	std::cout<<"Unesite dimenziju (x/y/z): ";
	do {
		std::cin>>n;
		if(n<=0) std::cout<<"Dimenzija nije ispravna, unesite opet: ";
	} while(n<=0);
	std::vector<std::deque<std::deque<int>>> kont (n, std::deque<std::deque<int>>(n, std::deque<int>(n))), ende;
	std::cout<<"Unesite elemente kontejnera: ";
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			for(int k=0; k<n; k++) std::cin>>kont.at(i).at(j).at(k);
	std::cout<<"Unesite smjer kretanja [0 - 5]: ";
	do {
		std::cin>>smjer;
		if(smjer<0 || smjer>5) std::cout<<"Smjer nije ispravan, unesite opet: ";
	} while(smjer<0 || smjer>5);
	std::cout<<std::endl;
	try {
		ende=PjescaniSat(kont, SmjerKretanja(smjer));
		std::cout<<"Pjescani sat unesene matrice je:"<<std::endl;
		std::cout<<std::endl;
		for(int k=0; k<n; k++) {
			int broj(4);
			std::cout<<std::endl;
			for(int i=0; i<n; i++) {
				for(int j=0; j<ende.at(k).at(i).size(); j++) {
					if(j==0) {
						std::cout.width(broj);
						std::cout<<ende.at(k).at(i).at(j);
						if(i<(n/2)) broj+=4;
						else broj-=4;
					} else {
						std::cout.width(4);
						std::cout<<ende.at(k).at(i).at(j);
					}
				}
				std::cout<<std::endl;
			}
		}
	} catch(std::domain_error iz1) {
		std::cout<<"Izuzetak: "<<iz1.what()<<std::endl;
	} catch(std::length_error iz2) {
		std::cout<<"Izuzetak: "<<iz2.what()<<std::endl;
	} catch(...) {
		std::cout<<"Bacen je izuzetak"<<std::endl;
	}
	return 0;
}
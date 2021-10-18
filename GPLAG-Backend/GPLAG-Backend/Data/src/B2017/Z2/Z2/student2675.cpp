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
#include <stdexcept>
#include <iomanip>
#include <type_traits>
#include <deque>

enum class SmjerKretanja 
{
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

typedef std::vector<std::deque<std::deque<int>>> Kontejner;
 
template <typename KontejnerskiTip>
KontejnerskiTip PjescaniSat (KontejnerskiTip &kontejner, SmjerKretanja s)
{

	for(auto matrica: kontejner) {
		if(matrica.size() != kontejner.size())
			throw std::domain_error("3D matrica nema oblik kocke");
		if(matrica.size() % 2 == 0 )
			throw std::length_error ("3D kontejner ne zadovoljava uvjet neparnosti");
		for(auto red:matrica) {
			if(red.size() != kontejner.size())
				throw std::domain_error("3D matrica nema oblik kocke");
			if(red.size() % 2 == 0 )
				throw std::length_error ("3D kontejner ne zadovoljava uvjet neparnosti");
		}
	}
	
	//{i,j,k,n-1}
	const int indeksi_1[6][4]= {{1,0,0,0}, {-1,0,0,1}, {0,0,1,0}, {0,0,1,0}, {0,0,1,0}, {0,0,1,0}};
	const int indeksi_2[6][4]= {{0,0,1,0}, {0,0,1,0}, {1,0,0,0}, {-1,0,0,1}, {0,1,0,0}, {0,1,0,0}};
	const int indeksi_3[6][4]= {{0,1,0,0}, {0,1,0,0}, {0,1,0,0}, {0,1,0,0}, {1,0,0,0}, {-1,0,0,1}};

	typedef typename std::remove_reference<decltype(kontejner.at(0))>::type Matrica;
	KontejnerskiTip rezultat(kontejner.size(), Matrica(kontejner.size()));

	int m, p;  
	int n(kontejner.size());
	for(int k=0; k<n; k++) {   
		for(int i=0; i<n; i++) {
			if(i<n/2) {
				m=n-i;
				p=i;
			} else {
				m=i+1;
				p=n-i-1;
			}
			for(int j=p; j<m; j++) {
				int a(indeksi_1[int(s)][0]*i+indeksi_1[int(s)][1]*j+indeksi_1[int(s)][2]*k+indeksi_1[int(s)][3]*(n-1));
				int b(indeksi_2[int(s)][0]*i+indeksi_2[int(s)][1]*j+indeksi_2[int(s)][2]*k+indeksi_2[int(s)][3]*(n-1));
				int c(indeksi_3[int(s)][0]*i+indeksi_3[int(s)][1]*j+indeksi_3[int(s)][2]*k+indeksi_3[int(s)][3]*(n-1));
				rezultat.at(k).at(i).push_back(kontejner.at(a).at(b).at(c));
			}
		}
	}

	return rezultat;
}



int main ()
{
	try {
		std::cout << "Unesite dimenziju (x/y/z): " ;
		int n;
		for(;;) {
			std::cin >> n;
			if(n<0) std::cout << "Dimenzija nije ispravna, unesite opet: ";
			else break;
		}

		Kontejner v(n, std::deque<std::deque<int>>(n, std::deque<int>(n)));
		std::cout << "Unesite elemente kontejnera: ";
		for(int k=0; k<n; k++) {
			for(int i=0; i<n; i++) {
				for(int j=0; j<n; j++) {
					int unos;
					std::cin >> unos; 
					v.at(k).at(i).at(j) = unos;
				}
			}
		}
 
		std::cout << "Unesite smjer kretanja [0 - 5]: ";
		int smjer;
		for(;;) {
			std::cin >> smjer;
			if(smjer<0 || smjer>5) std::cout << "Smjer nije ispravan, unesite opet: ";
			else break;
		}

		Kontejner rezultat(std::move(PjescaniSat(v, SmjerKretanja(smjer)))); 

		std::cout << std::endl <<"Pjescani sat unesene matrice je:" << std::endl;
		n=rezultat.size();
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(j!=0 && j<=n/2) {
					for(int m=0; m<j+1; m++) std::cout << "  ";
				}
				if(j!=n-1 && j>n/2) {
					for(int m=0; m<j-1; m++) std::cout << "  ";
				}
				for(int k=0; k<rezultat.at(i).at(j).size(); k++)
					std::cout << std::setw(4) << rezultat.at(i).at(j).at(k);
				std::cout << std::endl;
			}
			std::cout << std::endl << std::endl; 
		} 
	} catch(std::length_error izuzetak) {
		std::cout <<std::endl<< "Izuzetak: " << izuzetak.what();
	} catch(std::domain_error izuzetak) {
		std::cout << "Izuzetak: " << izuzetak.what(); 
	}
	return 0;
}
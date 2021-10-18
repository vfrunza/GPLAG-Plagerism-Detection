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
#include <iomanip>
#include <type_traits>

enum class SmjerKretanja
{
    NaprijedNazad=0, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};
template <typename Tip> auto PjescaniSat(Tip kont, SmjerKretanja smjer) -> Tip {
	int m(kont.size());
	if (m==0) {
		Tip prazan;
		return prazan;
	}
	for(int i=0; i<m; i++) {
		int n (kont.at(i).size());
		if(n!=m) throw std::domain_error ("3D matrica nema oblik kocke");
		for(int j=0; j<n; j++) {
			if(kont.at(i).at(j).size()!=m) throw std::domain_error ("3D matrica nema oblik kocke");
		}
	}
	if(m%2==0) throw std::length_error ("3D kontejner ne zadovoljava uvjet neparnosti");
	typedef typename std::remove_reference<decltype(kont.at(0).at(0))>::type Red;
	Tip nova(m);
	for(int k=0; k<m; k++) {
		for(int i=0; i<m; i++) {
			Red red;
			for(int j=0; j<m; j++) {
				if(smjer==SmjerKretanja::GoreDolje) {
					if((i>j && i+j<m-1) || (i<j && i+j>m-1)) continue;
					else red.push_back(kont.at(k).at(i).at(j));
				}
				if(smjer==SmjerKretanja::DoljeGore) {
					if((i>j && i+j<m-1) || (i<j && i+j>m-1)) continue;
					else red.push_back(kont.at(k).at(m-1-i).at(j));
				}
				if(smjer==SmjerKretanja::DesnoLijevo) {
					if((i<j && i+j>m-1)||(i>j && i+j<m-1)) continue;
					else red.push_back(kont.at(k).at(j).at(m-1-i));
				}
				if(smjer==SmjerKretanja::LijevoDesno) {
					if((i<j && i+j>m-1)||(i>j && i+j<m-1)) continue;
					else red.push_back(kont.at(k).at(j).at(i));
				}
				if(smjer==SmjerKretanja::NaprijedNazad) {
					if((i>j && i+j<m-1) || (i<j && i+j>m-1)) continue;
					else if(i<m/2) red.push_back(kont.at(i).at(k).at(i+j));
					else if(i==m/2) red.push_back(kont.at(i).at(k).at(i));
					else red.push_back(kont.at(i).at(k).at(m-1-i+j));
				}
				if(smjer==SmjerKretanja::NazadNaprijed) {
					if((i>j && i+j<m-1) || (i<j && i+j>m-1)) continue;
					else if(i<m/2) red.push_back(kont.at(m-1-i).at(k).at(i+j));
					else if(i==m/2) red.push_back(kont.at(i).at(k).at(i));
					else red.push_back(kont.at(m-1-i).at(k).at(m-1-i+j));
				}
			}
			nova.at(k).push_back(red);
		}
	}
	return nova;
}
int main ()
{
	typedef std::deque<std::deque<int>> matrica;
	int dim(0);
	std::cout << "Unesite dimenziju (x/y/z): ";
	std::cin >> dim;
	while(dim<0) {
		std::cout << "Dimenzija nije ispravna, unesite opet: ";
		std::cin >> dim;
	}
	std::cout << "Unesite elemente kontejnera: ";
	std::vector<matrica> kontejner (dim, matrica(dim, std::deque<int> (dim)));
	for(int i=0; i<dim; i++) {
		for(int j=0; j<dim; j++) {
			for(int k=0; k<dim; k++) {
				std::cin >> kontejner.at(i).at(j).at(k);
			}
		}
	}
	SmjerKretanja smjer;
	std::cout << "Unesite smjer kretanja [0 - 5]: ";
	int s(0);
	std::cin >> s;
	while(!(s>=0 && s<=5)) {
		std::cout << "Smjer nije ispravan, unesite opet: ";
		std::cin >> s;
	}
	smjer=SmjerKretanja(s);
	std::cout << std::endl;
	try {
		std::vector<matrica> p_sat;
		p_sat=PjescaniSat(kontejner,smjer);

		std::cout << "Pjescani sat unesene matrice je:" << std::endl;

		for(int i=0; i<p_sat.size(); i++) {
			for(int j=0; j<p_sat.at(i).size(); j++) {
				for(int k=0; k<p_sat.at(i).at(j).size(); k++) {
					int sirina((p_sat.size()-p_sat.at(i).at(j).size())/2);
					while(sirina!=0) {
						std::cout << std::setw(4)<<" ";
						sirina--;
					}
					std::cout << std::setw(4) << p_sat.at(i).at(j).at(k);
				}
				std::cout << std::endl;
			}
			std::cout  << std::endl;
		}

	} catch (std::domain_error greska) {
		std::cout << "Izuzetak: " << greska.what() << std::endl;
	} catch(std::length_error greska) {
		std::cout << "Izuzetak: "<< greska.what() << std::endl;
	}

	return 0;
}
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
#include <deque>
#include <vector>
#include <stdexcept>
#include <type_traits>
#include <iomanip>


enum class SmjerKretanja { NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo };
template <typename kont1>

auto PjescaniSat(kont1 kont, SmjerKretanja smjer) -> typename std::remove_reference<decltype(kont)>::type {
	
	if (kont.size()==0 || kont.at(0).size()==0 || kont.at(0).at(0).size()==0)
	return kont;
	
	for (int i(0); i<kont.size(); i++) {
		for (int j(0); j<kont.at(0).size(); j++) {
			if (kont.at(0).at(0).size()!=kont.at(i).at(j).size()) throw std::domain_error ("3D matrica nema oblik kocke");
		}
	}
	
	for (int i(0); i<kont.size(); i++) {
		if (kont.at(0).size()!=kont.at(i).size()) throw std::domain_error("3D matrica nema oblik kocke");
	}
	
	if (kont.at(0).size()%2==0 || kont.at(0).at(0).size()%2==0) {
		throw std::length_error("3D kontejner ne zadovoljava uvjet neparnosti");
	}	
	typename std::remove_reference<decltype(kont)>::type mat;
	typedef typename std::remove_reference<decltype(kont.at(0))>::type Tipkont1;
	typedef typename std::remove_reference<decltype(kont.at(0).at(0))>::type Tipkont2;
	int vel(kont.size());
	
	if (smjer==SmjerKretanja::GoreDolje || smjer==SmjerKretanja::LijevoDesno || smjer==SmjerKretanja::NaprijedNazad) {
		for (int i(0); i<vel; i++) {
			mat.push_back(Tipkont1());
			
			for (int j(0); j<vel; j++) {
				mat.at(i).push_back(Tipkont2());
				
				for (int k(0); k<vel; k++) {
					
					if ((k<=vel-j-1 && j<=k) || (j>=k && k>=vel-j-1)) {
						if (smjer==SmjerKretanja::GoreDolje) 
						mat.at(i).at(j).push_back(kont.at(i).at(j).at(k));
						else if (smjer==SmjerKretanja::NaprijedNazad)
						mat.at(i).at(j).push_back(kont.at(j).at(i).at(k));
						else if (smjer==SmjerKretanja::LijevoDesno)
						mat.at(i).at(j).push_back(kont.at(i).at(k).at(j));
					}
				}
			}
		}
	}
	
	else if (smjer==SmjerKretanja::DoljeGore || smjer==SmjerKretanja::NazadNaprijed || smjer==SmjerKretanja::DesnoLijevo) {
		for (int i(0); i<vel; i++) {
			mat.push_back(Tipkont1());
			int obratni(vel-1);
			int brojac(0);
			for (int j(vel-1); j>=0; j--) {
				mat.at(i).push_back(Tipkont2());
				
				for (int k(0); k<vel; k++) {
					
					if ((k<=vel-obratni-1 && obratni<=k) || (obratni>=k && k>=vel-obratni-1)) {
						if (smjer==SmjerKretanja::DoljeGore)
						mat.at(i).at(brojac).push_back(kont.at(i).at(j).at(k));
						else if (smjer==SmjerKretanja::NazadNaprijed)
						mat.at(i).at(brojac).push_back(kont.at(j).at(i).at(k));
						else if (smjer==SmjerKretanja::DesnoLijevo)
						mat.at(i).at(brojac).push_back(kont.at(i).at(k).at(j));
					}
				}
				obratni--;
				brojac++;
			}
		}
	}
return mat;	
}



int main ()
{
	
	try {
		std::cout << "Unesite dimenziju (x/y/z): ";
		int x(-1);
		
		while (x<0) {
			std::cin >> x;
			if (x<0) std::cout <<"Dimenzija nije ispravna, unesite opet: ";
		}
		
		std::cout << "Unesite elemente kontejnera: ";
		std::vector<std::deque<std::deque<int>>> v(x,std::deque<std::deque<int>>(x,std::deque<int>(x)));
		
		for (int i(0); i<v.size(); i++) {
			for (int j(0); j<v[0].size(); j++) {
				for (int k(0); k<v[0][0].size(); k++) {
					std::cin>>v[i][j][k];
				}
			}
		}
		
		std::cout << "Unesite smjer kretanja [0 - 5]: ";
		int br(-1);
		while (!(br==0 || br==1 || br==2 || br==3 || br==4 || br==5)) {
			std::cin >> br;
			if (!(br==0 || br==1 || br==2 || br==3 || br==4 || br==5)) {
				std::cout << "Smjer nije ispravan, unesite opet: ";
			}
		}
		
		std::vector<std::deque<std::deque<int>>> mat(0,std::deque<std::deque<int>>(0, std::deque<int>(0)));
		if (br==0) mat=PjescaniSat(v,SmjerKretanja::NaprijedNazad);
		else if (br==1) mat=PjescaniSat(v,SmjerKretanja::NazadNaprijed);
		else if (br==2) mat=PjescaniSat(v,SmjerKretanja::GoreDolje);
		else if (br==3) mat=PjescaniSat(v, SmjerKretanja::DoljeGore);
		else if (br==4) mat=PjescaniSat(v, SmjerKretanja::LijevoDesno);
		else if (br==5) mat=PjescaniSat(v, SmjerKretanja::DesnoLijevo);
		
		std::cout<<std::endl << "Pjescani sat unesene matrice je:";
		
		for (int i(0); i<mat.size(); i++) {
			int brojac(0);
			std::cout << std::endl;
			for (int j(0); j<mat[i].size(); j++) {
				
				for (int x(0); x<brojac; x++)
				std::cout << std::setw(4)<<" ";
				
				for (int k(0); k<mat[i][j].size(); k++)
				std::cout << std::setw(4)<< mat[i][j][k];
				
				std::cout << std::endl;
				
				if(j<mat.size()/2) brojac++;
				else brojac--;
			}
		}
	}
	
	catch(std::domain_error izuzetak) {
		std::cout<<std::endl <<"Izuzetak: " << izuzetak.what();
	}
	
	catch(std::length_error izuzetak) {
		std::cout<<std::endl <<"Izuzetak: " << izuzetak.what();
	}
	return 0;
}
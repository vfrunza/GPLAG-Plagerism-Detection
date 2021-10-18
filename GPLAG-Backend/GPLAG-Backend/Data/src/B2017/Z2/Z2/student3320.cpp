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
#include <string>
#include <vector>
#include <deque>
#include <cmath>
#include <iomanip>
#include <stdexcept>
#include <type_traits>

typedef std::vector<std::deque<std::deque<int>>> Tabla;

enum class SmjerKretanja { NaprijedNazad=0, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo=5 };

template<typename kontejner>
kontejner PjescaniSat(kontejner mat, SmjerKretanja smjer) {
	for(int i=0; i<mat.size()-1; i++) {
		if(mat.at(i).size()!=mat.at(i+1).size()) throw std::domain_error("3D matrica nema oblik kocke");
	}
	for(int i=0; i<mat.at(0).size()-1; i++) {
		if(mat.at(0).at(i).size()!=mat.at(0).at(i+1).size()) throw std::domain_error("3D matrica nema oblik kocke");
	}
	if(mat.size()%2==0) throw std::length_error("3D kontejner ne zadovoljava uvjet neparnosti");
	kontejner zamjena=mat;
	int vrijednost;

	switch(smjer) {
		case (SmjerKretanja::NazadNaprijed):
			for(int i=0; i<mat.size(); i++) {
				for(int j=0; j<mat.size(); j++) {
					for(int k=0; k<mat.size(); k++) {
						mat.at(i).at(j)=zamjena.at(j).at(i);
					}
				}
			}
			
			for(int i=0; i<mat.size(); i++) {
				for(int j=0; j<mat.size()/2; j++) {
					auto temp=mat.at(i).at(j);
					vrijednost=mat.size()-j-1;
					mat.at(i).at(j)=mat.at(i).at(vrijednost);
					mat.at(i).at(vrijednost)=temp;
				}
			}
			break;			//JEDAN
			
		case (SmjerKretanja::GoreDolje):	
			break;			//DVA
			
		case (SmjerKretanja::DoljeGore):
			for(int i=0; i<mat.size(); i++) {
				for(int j=0; j<mat.size()/2; j++) {
					auto temp=mat.at(i).at(j);
					vrijednost=mat.size()-j-1;
					mat.at(i).at(j)=mat.at(i).at(vrijednost);
					mat.at(i).at(vrijednost)=temp;
				}
			}
			break;			//TRI
			
		case (SmjerKretanja::LijevoDesno):
			for(int i=0; i<mat.size(); i++) {
				for(int j=0; j<mat.size(); j++) {
					for(int k=j; k<mat.size(); k++) {
						auto temp=mat.at(i).at(j).at(k);
						mat.at(i).at(j).at(k)=mat.at(i).at(k).at(j);
						mat.at(i).at(k).at(j)=temp;
					}
				}
			}
			break;			//CETIRI
			
		case (SmjerKretanja::DesnoLijevo):
			for(int i=0; i<mat.size(); i++) {
				for(int j=0; j<mat.size(); j++) {
					for(int k=j; k<mat.size(); k++) {
						auto temp=mat.at(i).at(j).at(k);
						mat.at(i).at(j).at(k)=mat.at(i).at(k).at(j);
						mat.at(i).at(k).at(j)=temp;
					}
				}
			}
			
			for(int i=0; i<mat.size(); i++) {
				for(int j=0; j<mat.size()/2; j++) {
					auto temp=mat.at(i).at(j);
					vrijednost=mat.size()-j-1;
					mat.at(i).at(j)=mat.at(i).at(vrijednost);
					mat.at(i).at(vrijednost)=temp;
				}
			}
			break;			//PET
			
		default:
			for(int i=0; i<mat.size(); i++) {
				for(int j=0; j<mat.size(); j++) {
					for(int k=0; k<mat.size(); k++) {
						mat.at(i).at(j)=zamjena.at(j).at(i);
					}
				}
			}
			break;			//NULA
	}
	
	for(int i=0; i<mat.size(); i++) {
		for(int j=0; j<mat.size(); j++) {
			vrijednost=mat.size()-j-1;
			if((j==mat.size()/2 || j<mat.size()/2)) {
				for(int k=0; k<mat.size()-j; k++) {
					mat.at(i).at(j).at(k)=mat.at(i).at(j).at(k+j);
				}
			} else {
				if(j>(mat.size()/2)-1 && j!=mat.size()-1) {
					for(int k=0; k<=j; k++) {
						mat.at(i).at(j).at(k)=mat.at(i).at(j).at(k+vrijednost);
					}
				}
			}
		}
		for(int j=0; j<=mat.size()/2; j++) {
			auto temp=mat.at(i).at(j);
			temp.resize(mat.size()-(2*j));
			mat.at(i).at(j)=temp;
		}
		for(int j=(mat.size()/2)+1; j<mat.size(); j++) {
			auto temp=mat.at(i).at(j);
			vrijednost=mat.size()-j-1;
			temp.resize(mat.size()-2*(vrijednost));
			mat.at(i).at(j)=temp;
		}
	}
	return mat;
}


int main () {
	
	std::cout << "Unesite dimenziju (x/y/z): ";
	int d;
opet:	
	std::cin >> d;
	if(d<0 || !(std::cin)) {
		std::cout << "Dimenzija nije ispravna, unesite opet: ";
		goto opet;
	}
	Tabla sat(d);
	std::cout << "Unesite elemente kontejnera: ";
	for(int a=0; a<d; a++) {
		sat.at(a).resize(d);
		for(int b=0; b<d; b++) {
			for(int c=0; c<d; c++) {
				int broj;
				std::cin >> broj;
				sat.at(a).at(b).push_back(broj);
			}
		}
	}
		
	std::cout << "Unesite smjer kretanja [0 - 5]: ";
	int broj;
opet1:	
	std::cin >> broj;
	if(broj<0 || broj>5) {
		std::cout << "Smjer nije ispravan, unesite opet: ";
		goto opet1;
	}
	SmjerKretanja smjer=SmjerKretanja(broj);
	
	try {
		sat=PjescaniSat(sat, smjer);
		std::cout << std::endl << "Pjescani sat unesene matrice je: " << std::endl << std::endl;

		for(int i=0; i<sat.size(); i++) {
			for(int j=0; j<sat.size(); j++) {
				if(j<=sat.size()/2) std::cout << std::setfill(' ') << std::setw(4*j) << " ";
				else std::cout << std::setfill(' ') << std::setw(4*(sat.size()-j-1)) << " ";
				for(int k=0; k<sat.at(i).at(j).size(); k++) {
					if(k==0 && (j==0 || j==sat.size()-1)) std::cout << std::setw(3) << std::right << sat.at(i).at(j).at(k);
					else std::cout << " " << std::setw(3) << std::right << sat.at(i).at(j).at(k);
				}
				std::cout << std::endl;
			}
			std::cout << std::endl;
		}
	}catch(std::domain_error jedan) {
		std::cout << std::endl << "Izuzetak: " << jedan.what();
	}catch(std::length_error dva) {
		std::cout << std::endl << "Izuzetak: " << dva.what();
	}
	return 0;
}
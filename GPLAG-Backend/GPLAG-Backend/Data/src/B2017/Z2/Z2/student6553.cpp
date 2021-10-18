#include <iostream>
#include <vector>
#include <cstdlib>
#include <deque>
#include <stdexcept>
#include <type_traits>
#include <iomanip>

enum class SmjerKretanja
{
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template <typename NekiTip>
NekiTip PjescaniSat(NekiTip pocetni, SmjerKretanja smjer)
{

	typedef typename std::remove_reference<decltype(pocetni.at(0))>::type matrica;
	typedef typename std::remove_reference<decltype(pocetni.at(0).at(0))>::type vektor;
	int duzina(pocetni.size());
	NekiTip pjescani;
	if(!duzina) return pjescani;
	for(int i=0; i<duzina; i++) {
		if(pocetni.at(i).size()!=duzina) throw std::domain_error("3D matrica nema oblik kocke");
		for(int j=0; j<duzina; j++) if(pocetni.at(i).at(i).size()!=duzina) throw std::domain_error("3D matrica nema oblik kocke");
	}
	if(duzina%2==0) throw std::length_error("3D kontejner ne zadovoljava uvjet neparnosti");


	for(int i=0; i<duzina; i++) {
		matrica pomocna;
		if(smjer==SmjerKretanja::GoreDolje || smjer==SmjerKretanja::NaprijedNazad || smjer==SmjerKretanja::LijevoDesno) {
			for(int j=0; j<duzina; j++) {
				vektor d;
				int razlika(std::abs(j-duzina/2));
				for(int k=0; k<2*razlika+1; k++) {
					if(smjer==SmjerKretanja::GoreDolje)	d.push_back(pocetni.at(i).at(j).at(k+std::abs(razlika-duzina/2)));
					else if(smjer==SmjerKretanja::NaprijedNazad) d.push_back(pocetni.at(j).at(i).at(k+std::abs(razlika-duzina/2)));
					else if(smjer==SmjerKretanja::LijevoDesno) d.push_back(pocetni.at(i).at(k+std::abs(razlika-duzina/2)).at(j));
				}
				pomocna.push_back(d);
			}
		} else if(smjer==SmjerKretanja::DoljeGore || smjer==SmjerKretanja::NazadNaprijed || smjer==SmjerKretanja::DesnoLijevo) {
			for(int j=duzina-1; j>=0; j--) {
				vektor d;
				int razlika(std::abs(j-duzina/2));
				for(int k=0; k<2*razlika+1; k++) {
					if(smjer==SmjerKretanja::DoljeGore)d.push_back(pocetni.at(i).at(j).at(k+std::abs(razlika-duzina/2)));
					else if(smjer==SmjerKretanja::NazadNaprijed) d.push_back(pocetni.at(j).at(i).at(k+std::abs(razlika-duzina/2)));
					else if(smjer==SmjerKretanja::DesnoLijevo) d.push_back(pocetni.at(i).at(k+std::abs(razlika-duzina/2)).at(j));
				}
				pomocna.push_back(d);
			}
		}
		pjescani.push_back(pomocna);
	}
	return pjescani;
}


int main ()
{
	int x;
	std::cout<<"Unesite dimenziju (x/y/z): ";
	do {
		std::cin>>x;
		if(x<0) std::cout<<"Dimenzija nije ispravna, unesite opet: ";
	} while(x<0);
	int duzina(x);
	try {
		std::vector<std::deque<std::deque<int>>> pocetni(x, std::deque<std::deque<int>>(x,std::deque<int>(x)));
		std::cout<<"Unesite elemente kontejnera: ";
		for(int i=0; i<x; i++) {
			for(int j=0; j<x; j++) {
				for(int k=0; k<x; k++) std::cin>>pocetni.at(i).at(j).at(k);
			}
		}
		std::cout<<"Unesite smjer kretanja [0 - 5]: ";
		do {
			std::cin>>x;
			if(x<0 || x>5) std::cout<<"Smjer nije ispravan, unesite opet:";
		} while(x<0 || x>5);
		std::vector<std::deque<std::deque<int>>>pjescani( PjescaniSat(pocetni, SmjerKretanja(x)));
		std::cout<<std::endl<<"Pjescani sat unesene matrice je: "<<std::endl;
		for(int i=0; i<duzina; i++) {
			for(int j=0; j<duzina; j++) {
				int razlika(std::abs(std::abs(j-duzina/2)-duzina/2));
				std::cout<<std::setw(4*(razlika+1))<<pjescani.at(i).at(j).at(0);
				for(int k=1; k<pjescani.at(i).at(j).size(); k++) std::cout<<std::setw(4)<<pjescani.at(i).at(j).at(k);
				std::cout<<std::endl;
			}
			std::cout<<std::endl;
		}
	} catch(std::bad_alloc) {}
	catch(std::length_error izuzetak) {
		std::cout<<std::endl<<"Izuzetak: "<<izuzetak.what();
	} catch(std::domain_error izuzetak) {
		std::cout<<std::endl<<"Izuzetak: "<<izuzetak.what();
	}

	return 0;
}
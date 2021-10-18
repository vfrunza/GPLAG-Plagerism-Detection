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
#include <stdexcept>
#include <deque>
#include <vector>
#include <type_traits>
#include <iomanip>
using std::cout;
using std::cin;
enum class SmjerKretanja { NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo };

template <typename TriDKont>
auto PjescaniSat(TriDKont Kontejner, SmjerKretanja smjer)-> TriDKont {
	for (int i=0;i<Kontejner.size();i++) {
		for (int j=0;j<Kontejner.size();j++) {
			if (Kontejner.at(i).size()!=Kontejner.at(i).at(j).size() || Kontejner.at(0).size()!=Kontejner.at(i).size() || Kontejner.size()!=Kontejner.at(i).size())
				throw std::domain_error("3D matrica nema oblik kocke");
		}
	}
	
	for (int i=0;i<Kontejner.size();i++) {
		for (int j=0;j<Kontejner.at(i).size();j++) {
			if (Kontejner.at(i).size()%2==0 || Kontejner.at(i).at(j).size()%2==0)
				throw std::length_error("3D kontejner ne zadovoljava uvjet neparnosti");
		}
	}
	TriDKont PovratniKont;
	for (int i=0;i<Kontejner.size();i++) {
		typename std::remove_reference<decltype(Kontejner.at(0))>::type DvaDKont;
		int brojac(0), brojac2(0);
		for (int j=0;j<Kontejner.at(i).size();j++) {
			typename std::remove_reference<decltype(Kontejner.at(0).at(0))>::type JedanDKont;
			for (int k=brojac;k<Kontejner.at(i).at(j).size()-brojac;k++) {
				if (smjer==SmjerKretanja::GoreDolje) JedanDKont.push_back(Kontejner.at(i).at(j).at(k));
				if (smjer==SmjerKretanja::DoljeGore) JedanDKont.push_back(Kontejner.at(i).at(Kontejner.size()-1-j).at(k));
				if (smjer==SmjerKretanja::LijevoDesno) JedanDKont.push_back(Kontejner.at(i).at(k).at(j));
				if (smjer==SmjerKretanja::DesnoLijevo) JedanDKont.push_back(Kontejner.at(i).at(k).at(Kontejner.size()-1-j));
				if (smjer==SmjerKretanja::NaprijedNazad) JedanDKont.push_back(Kontejner.at(j).at(i).at(k));
				if (smjer==SmjerKretanja::NazadNaprijed) JedanDKont.push_back(Kontejner.at(Kontejner.size()-1-j).at(i).at(k));
			}
			if (brojac2<Kontejner.at(i).at(j).size()/2) {
				brojac++; brojac2++; 
			}
			else
				brojac--;
			DvaDKont.push_back(JedanDKont);
		}
		PovratniKont.push_back(DvaDKont);
	}
	return PovratniKont;
}
void Printanje(int n) {
	for (int i=0;i<n;i++) {
		std::cout<<" ";
	}
}
int main ()
{
	cout<<"Unesite dimenziju (x/y/z): ";
	int n;
	cin>>n;
	if (n<0) {
		do {
		cout<<"Dimenzija nije ispravna, unesite opet: ";
		cin>>n;
		}while(n<0);
	}
	std::vector<std::deque<std::deque<int>>> Kontejner, pjescani;
	cout<<"Unesite elemente kontejnera: ";
	Kontejner.resize(n);
	for (int i=0;i<n;i++) {
		Kontejner.at(i).resize(n);
		for (int j=0;j<n;j++) {
			Kontejner.at(i).at(j).resize(n);
			for (int k=0;k<n;k++) {
				cin>>Kontejner.at(i).at(j).at(k);
			}
		}
	}
	cout<<"Unesite smjer kretanja [0 - 5]: ";
	int smjer;
	cin>>smjer;
	if (smjer<0 || smjer>5) {
		do {
			cout<<"Smjer nije ispravan, unesite opet: ";
			cin>>smjer;
		}while(smjer<0 || smjer>5);
	}
	try {
		pjescani=PjescaniSat(Kontejner, static_cast<SmjerKretanja>(smjer));
	}
	catch(std::domain_error domen) {
		std::cout<<std::endl<<"Izuzetak: "<<domen.what();
		return 0;
	}
	catch(std::length_error duzina) {
		std::cout<<std::endl<<"Izuzetak: "<<duzina.what();
		return 0;
	}
	std::cout<<std::endl<<"Pjescani sat unesene matrice je: "<<std::endl;
	for (auto x : pjescani) {
		int razmaci(0), brojac(0);
		for (auto y : x) {
			Printanje(razmaci);
			for (auto z : y) {
				std::cout<<std::setw(4)<<z;
			}
			Printanje(razmaci);
			if (brojac<=y.size()/2) {
				brojac++;
				razmaci+=4;
			}
			else
				razmaci-=4;
			std::cout<<std::endl;
		}
		std::cout<<std::endl;
	}
	return 0;
}
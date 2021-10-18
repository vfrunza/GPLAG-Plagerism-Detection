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
#include <iomanip>
#include <type_traits>
#include <stdexcept>
enum class SmjerKretanja
{
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo

};
template <typename NekiKontejner>
NekiKontejner PjescaniSat(  NekiKontejner kont, SmjerKretanja smjer)
{
	
	int prekid1(0),prekid2(0);
	for( int b=0; b<kont.size(); b++) {
		for( int i=0; i<kont[b].size(); i++) {
			if(kont[b].size()!=kont[b][i].size() || kont.size()!=kont[b].size()) {
				throw std::domain_error("3D matrica nema oblik kocke");
				prekid1=1;
				break;

			}
			if(prekid1==1) break;
		}

	}
	for(int b=0; b<kont.size(); b++) {
		for( int i=0; i<kont[b].size(); i++)
			if(kont[b].size()%2==0 || kont[b][i].size()%2==0) {
				throw std::length_error("3D kontejner ne zadovoljava uvjet neparnosti");
				prekid2=1;
				break;
			}
		if(prekid2==1) break;
	}
	
	return kont;
}

int main ()
{
	int dimenzija(0);
	std::cout<<"Unesite dimenziju (x/y/z): ";
	do {
		std::cin>>dimenzija;
		if( dimenzija<0) {
			std::cout<<"Dimenzija nije ispravna, unesite opet: ";
			std::cin>>dimenzija;

		}

	} while(dimenzija<0);
	std::vector<std::deque<std::deque<int>>> kontejner(dimenzija,std::deque<std::deque<int>>(dimenzija,std::deque<int>(dimenzija,0)));
	try {
		std::cout<<"Unesite elemente kontejnera: ";
		int element(0);
		for( int b=0; b<dimenzija; b++) {
			for( int i=0; i<dimenzija; i++) {
				for( int j=0; j<dimenzija; j++) {
					std::cin>>element;
					kontejner[b][i][j]=element;
				}
			}

		}
		int smjer(0);
		std::cout<<"Unesite smjer kretanja [0 - 5]: ";
		do {
			std::cin>>smjer;
			if(smjer>5 || smjer<0) {
				std::cout<<"Smjer nije ispravan, unesite opet: ";
				std::cin>>smjer;
			}

		} while(smjer>5 || smjer<0);
		auto novi_kontejner=PjescaniSat(kontejner,(SmjerKretanja)smjer);
		std::cout<<std::endl<<"Pjescani sat unesene matrice je: "<<std::endl;
	} catch(std::domain_error izuzetak1) {
		std::cout<<std::endl<<"Izuzetak: "<<izuzetak1.what()<<std::endl;
	} catch(std::length_error izuzetak2) {
		std::cout<<std::endl<<"Izuzetak: "<<izuzetak2.what()<<std::endl;
	}
	return 0;
}
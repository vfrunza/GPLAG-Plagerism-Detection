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
#include <vector>
#include <deque>

enum class SmjerKretanja
{
    NaprijedNazad=0, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template<typename nest>
nest PjescaniSat(nest kont, enum SmjerKretanja smjer)
{
	nest NoviKont;

	return NoviKont;
}


int main ()
{
	try {
		int dimenzija;
		std::cout<<"Unesite dimenziju (x/y/z): ";
		std::cin>>dimenzija;
		if(dimenzija%2==0)
			throw std::length_error("3D kontejner ne zadovoljava uvjet neparnosti!");
		std::cout<<"Unesite elemente kontejnera: ";
		std::vector<std::deque<std::vector<int>>> M;
		int element;
		for(int i = 0; i<5; i++) {
			for(int j=0; j<dimenzija; j++) {
				for(int k=0 ; k<dimenzija; k++) {
					std::cin>>element;
					M[i][j][k]=element;
				}
			}
		}
		int smjer;
		std::cout<<"Unesite smjer kretanja [0 - 5]:";
		std::cin>>smjer;
	auto PjescaniKontejner=PjescaniSat(M,smjer);
		std::cout<<"Pjescani sat unesene matrice je:";
		for(int i = 0; i<5; i++) {
			for(int j=0; j<dimenzija; j++) {
				for(int k=0 ; k<dimenzija; k++) {
					std::cout<<"    "<<M[i][j][k];
				}
				std::cout<<"\n";
			}
			std::cout<<"\n";
		}
	} catch (std::length_error izuzz){
		std::cout<<"Izuzetak: "<<izuzz.what();
	}
	return 0;
}
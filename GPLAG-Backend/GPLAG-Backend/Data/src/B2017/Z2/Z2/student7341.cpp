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

enum class SmjerKretanja {
	NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template <typename tip>

tip PjescaniSat (tip kont, SmjerKretanja smjer) {
	tip novi_3d;
	int br(0);
	for (int i (0); i<kont.size(); i++) {
		for (int j(0); j<kont.at(i).size(); j++) {
			for (int k(0); k<kont.at(i).at(j).size(); k++) {
				if (smjer==GoreDolje) {
					
				}
			}
				
			}
		}
	}
}

int main ()
{
	return 0;
}
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
#include <iomanip>
#include <vector>
#include <exception>

using namespace std;

enum class SmjerKretanja {
	NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo	
};

template <typename magic>
magic PjescaniSat(magic kont, SmjerKretanja smjerKretanja) {
	magic tjt;
	if(smjerKretanja == SmjerKretanja::NaprijedNazad) {
		
	}
	
	return tjt;
}

int main ()
{
	
	SmjerKretanja smjerKretanja = SmjerKretanja::NaprijedNazad;
	if(smjerKretanja == SmjerKretanja::0) cout << "aha";
	return 0;
}
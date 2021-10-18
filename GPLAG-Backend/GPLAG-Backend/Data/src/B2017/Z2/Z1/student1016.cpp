/*B 2017/2018, Zadaća 2, Zadatak 1
	
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

enum class Polje {
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina 
};
typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru (int n, const std::vector<std::vector<int>> &mine) {
	if (n<=0) throw std::domain_error ("Ilegalna velicina");
	Tabla povratna;
	povratna.resize(n);
	for (int i=0; i<n; i++) {
		povratna.at(i).resize(n);
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (mine.at(i).size()<2 || mine.at(i).size()>2) throw std::domain_error ("Ilegalan format zadavanja mina");
			else if (mine.at(i).at(j)>=n) throw std::domain_error ("Ilegalne pozicije mina");
			else if (j==0) povratna.at(mine.at(i).at(0)).at(mine.at(i).at(0))=Polje::Mina;
		}
	}
	return povratna;
}

int main () {
	
	std::cout<<"Unesite broj polja: ";
	return 0;
}
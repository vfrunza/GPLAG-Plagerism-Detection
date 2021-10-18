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
#include <vector>
#include <stdexcept>

using std::cin;
using std::cout;

enum class Polje {
	Prazno=0, Posjeceno, Mina=1, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};

typedef std::vector<std::vector<Polje>> Tabla;



Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine) {
	if(n<0) throw std::domain_error("Ilegalna velicina");
	for(int i=0; i<mine.size(); i++) {
		if(mine[i].size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
		for(int j=0; j<mine[0].size(); j++) {
			if(mine[i][j]>n-1) throw std::domain_error("Ilegalne pozicije mina");
		}
	}
	
	Tabla povratna{0};
	for(int i=0; i<n; i++) {
		std::vector<Polje> pomocni;
		for(int j=0; j<n; j++) {
			std::vector<int> indeksi;
			indeksi.push_back(i);
			indeksi.push_back(j);
			bool ubacivanje(false);
			for(int k=0; k<mine.size(); k++) {
				if(mine[k]==indeksi) {
					pomocni.push_back(1);
					ubacivanje=true;
				}
			}
			if(ubacivanje) {
				ubacivanje=false;
				continue;
			}
			pomocni.push_back(0);
		}
		povratna.push_back(pomocni);
	}
	return povratna;
}

/*int SumaOkolnih(const Tabla &polja, int x, int y) {
	int suma(0);
	if(x!=0 && y!=0) {
	int vel1(x-1), vel2(y-1);
	for(int i=vel1; i<vel1+3; i++) {
		for(int j=vel2; j<vel2+3; j++) {
			suma+=polja[i][j];
		}
	}
	suma-=polja[x][y];
	}
	if(x==0) {
		if(y==0) suma=polja[]
	}
}*/

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y) {
	if((x>polja.size()) || (y>polja[0].size()) throw std::domain_error("Polje ("<<x<<","<<y<<") ne postoji");
	int vel1(x-1), vel2(y-1);
	std::vector<std::vector<int>> povratna;
	for(int i=vel1; i<vel1+3; i++) {
		std::vector<int> pomocni;
		for(int j=vel2; j<vel2+3; j++) {
			pomocni.push_back(SumaOkolnih(polja, i,j));
		}
		povratna.push_back(pomocni);
	}
	return povratna;
}



int main ()
{
	return 0;
}
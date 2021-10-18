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
#include <

enum class Polje {
 Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	
}

void BlokirajPolje(Tabla &polja, int x, int y){
	
}

void DeblokirajPolje(Tabla &polja, int x, int y){
	
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	
	
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	
}



int main ()
{
	return 0;
}
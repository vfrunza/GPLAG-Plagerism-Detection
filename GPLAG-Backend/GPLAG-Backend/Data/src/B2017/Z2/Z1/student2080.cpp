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

typedef std::vector<std::vector<Polje>> Tabla;
enum class Polje { Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina };

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine) {
	std::vector<std::vector<int>> MatricaTable(n,std::vector<int>(n,Prazno));
	
}


int main ()
{
	return 0;
}
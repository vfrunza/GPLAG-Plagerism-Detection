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

enum class Polje
{
    Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru (int n, const std::vector<std::vector<int>> &mine)
{
	if (n<=0) throw domain_error ("Ilegalna veličina");
	Tabla tabla (n,std::vector<Polje>(n, Polje::Prazno));
	for (int i=0; i<tabla.size(); i++) {
		for (int j=0; j<tabla.at(i).size(); j++) {
			if (mine.at(i).size()!=2) throw domain_error ("Ilegalan format zadavanja mina");
			else if (mine.at(0)<0 || v.at(0)>=n || v.at(1)<0 || v.at(1)>=n) throw domain_error ("Ilegalne pozicije mina");
			tabla.at(mine.at(i).at(0)).at(mine.at(i).at(1)) = Polje::Mina;
		}
	}
	return tabla;
}

std::vector<std::vector<int>> PrikaziOkolinu (const Tabla &polja, int x, int y) {
	std::vector<std::vector<int>> matrica;
	int pozicija_red=x, pozicija_kolona=y;
	for (int i())
	
	return matrica;
}

int main ()
{
	return 0;
}
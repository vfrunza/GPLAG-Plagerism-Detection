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
using std::vector;
using std::cin;
using std::cout;
using std::endl;

enum class Polje {
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};
typedef std::vector<std::vector<Polje>> Tabla;


Tabla NapraviTablu (const vector<vector<int>> &lokacije) {
	
}

Tabla KreirajIgru (int n, const vector<vector<int>> &mine) {
	
	if (n<0 || n==0) throw std::domain_error ("Ilegalna velicina");
	for (int i(0); i<mine.size(); i++) {
		if (mine.at(i).size != 2 ) throw std::domain_error ("Ilegalan format zadavanja mina");
		if (mine.at(i).at(0) < 0 || mine.at(i).at(0) > n-1 || mine.at(i).at(1) < 0 || mine.at(i).at(1) > n-1)
			throw std::domain_error ("Ilegalne pozicije mina");
	}
	
	
}























int main ()
{
	return 0;
}
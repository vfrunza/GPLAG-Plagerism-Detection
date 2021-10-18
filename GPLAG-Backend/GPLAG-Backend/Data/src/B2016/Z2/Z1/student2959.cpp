/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/

#include <iostream>
#include <vector>
#include <stdexcept>

enum class Polje {
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru (int n, const std::vector<std::vector<int>> &mine) {
	Tabla x(n, std::vector<Polje>(n, Polje::Prazno));
	for (int i=0; i<mine.size(); i++) {
		if (mine[i].size()!=2) {
			throw std::domain_error ("Ilegalan format zadavanja mina");
		}
	}
	for (int i=0; i<mine.size(); i++) {
		for (int j=0; j<2; j++) {
			if (mine[i][j]>n) {
				throw std::domain_error ("Ilegalne pozicije mina");
			}
		}
	}
	int br(0);
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (i==mine[br][0] && j==mine[br][1]) {
				x[i][j] = Polje::Mina;
				br++;
			}
		}
	}
	return x;
}

std::vector<std::vector<int>> PrikaziOkolinu (const Tabla &polja, int x, int y) {
	
}

int main () {
	return 0;
}
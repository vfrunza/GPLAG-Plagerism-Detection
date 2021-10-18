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
typedef std::vector<std::vector<int>> Matrica;

Tabla KreirajIgru(int n, const Matrica &mine) {
	for(int i=0; i<mine.size(); i++) {
		if(mine[i].size() != 2) throw std::domain_error("Ilegalan format zadavanja mina");
		for(int j=0; j<mine[i].size(); j++)
			if(mine[i][j] > n-1 || mine[i][j] < 0) throw std::domain_error("Ilegalne pozicije mina");
	}
	Tabla t(n, std::vector<int> (n, Prazno));
	for(int i=0; i<mine.size(); i++)
		for(int j=0; j<mine[i].size()-1; j++)
			t[mine[i][j][mine[i][j+1]] = Mina; 
	return t;
}

Matrica PrikaziOkolinu(const Tabla &polja, int x, int y) {
	if(x >= polja.size() || x >= polja[0].size() || y >= polja.size() || y >= polja[0].size()) 
		throw std::domain_error("Polje (" + x + '0' + ", " + y + 0' + ") ne postoji");
	Matrica mat(3, std::vector<int> (3));
	for(int i=0; i<polja.size(); i++) {
		for(int j=0; j<polja[i].size(); j++) {
			
		}
		}
			
}

int main ()
{
	return 0;
}
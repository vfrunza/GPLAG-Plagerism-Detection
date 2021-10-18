/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/

enum class Polje {
 Prazno=0, Posjeceno, Mina=1, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>>, &mine) {
	Tabla t(n, std::vector<Polje>(n));
	for (int i(0); i<n; i++) t[i].size()=n;
	for (int i(0); i<n; i++) {
		for (int j(0); j<n; j++){
			t[i][j] = Prazno;
		}
	}
	for (int i(0); i<mine.size(); i++) {
		if (mine[i].size() != 2) throw std::domain_error ("Ilegalan format zadavanja mina.");
	}
	for (int i(0); i<n; i++) {
		for (int j(0); j<n; j++) {
			if (i == *mine[i] && j == *mine[j]) t[i][j] = Mina;
		}
	}
	return t;
}

int main (){
	return 0;
}
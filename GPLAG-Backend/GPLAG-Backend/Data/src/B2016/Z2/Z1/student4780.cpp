/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>

#define pb push_back

enum class Polje {
 Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};
enum class Smjerovi {
 GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};
enum class Status {
 NijeKraj, KrajPoraz, KrajPobjeda
};
enum class KodoviGresaka {
 PogresnaKomanda, NedostajeParmetar, SuvisanParametar, NeispravanParametar
};
enum class Komande {
 PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu,
 ZavrsiIgru, KreirajIgru
};

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine);
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y);
void BlokirajPolje(Tabla &polja, int x, int y);
void DeblokirajPolje(Tabla &polja, int x, int y);
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer);
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y);
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y);
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska);

int setamX[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int setamY[] = {-1, 0,   1,-1, 0, 1,-1, 0, 1};
int main ()
{
	std::vector<std::vector<int>> mine{{0,0}, {0,2}, {1,3}};
	
	auto TablaIgre = KreirajIgru(4, mine);
	
	for (int i = 0; i < TablaIgre.size(); i++) {
		for (int j = 0; j < TablaIgre.at(i).size(); j++)
			if (Polje::Mina == TablaIgre[i][j]) std::cout << 1 << " ";
			else std::cout << "0 ";
		std::cout << "\n";
	}
	auto okolina = PrikaziOkolinu(TablaIgre, 1, 1);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			std::cout << okolina[i][j] << " ";
		std::cout << "\n";
	}
	return 0;
}

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine) {
	Tabla ret;
	ret.resize(n);
	for (int i = 0; i < n; i++) {
		ret.at(i).resize(n);
		for (int j = 0; j < ret.at(i).size(); j++)
			ret[i][j] = Polje::Prazno;
	}
	for (int i = 0; i < mine.size(); i++) {
		if (mine.at(i).size() != 2) throw std::domain_error("Ilegalan format zadavanja mina");
		for (int j = 0; j < mine.at(i).size(); j++) {
			int value_polja = mine.at(i).at(j);
			if (value_polja < 0 || value_polja >= n) throw std::domain_error("Ilegalne pozicije mina");
		}
	}
	for (int i = 0; i < mine.size(); i++) {
		ret[mine[i][0]][mine[i][1]] = Polje::Mina;
	}
	return ret;
}
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y) {
	std::string zaIzuzetak = "(";
	zaIzuzetak += (x + '0'); zaIzuzetak += ','; zaIzuzetak += (y + '0'); zaIzuzetak += ')';
	if (x < 0 || x >= polja.size() || y < 0 || y >= polja.size()) throw std::domain_error("Polje " + zaIzuzetak + " ne postoji");
	std::vector<std::vector<int>> ret;
	std::vector<int> pusham;
	
	int n  = polja.size();
	int dodajem = 0;
	for (int d1 = 0; d1 < 9; d1++) {
		int xko = x + setamX[d1];
		int yko = y + setamY[d1];
		int br_susjeda = 0;
		if (xko < 0 || xko >= n || yko < 0 || yko >= n) br_susjeda = 0;
		else {
			for (int d2 = 0; d2 < 9; d2++) {
				int x1 = xko + setamX[d2];
				int y1 = yko + setamY[d2];
				if (!(x1 < 0 || x1 >= n || y1 < 0 || y1 >= n))
				if (polja[x1][y1] == Polje::Mina) br_susjeda++;
			}
			//std::cout << xko <<" , " << yko << " = " <<br_susjeda << "\n";
			dodajem++;
			if (polja[xko][yko] == Polje::Mina) {
				if (br_susjeda != 0) br_susjeda--;
			}
			pusham.pb(br_susjeda);
			if (dodajem == 3) {
				dodajem = 0;
				ret.pb(pusham);
				pusham.clear();
			}
		}
	}
	ret.pb(pusham);
	pusham.clear();
	dodajem = 0;
	return ret;
}
void BlokirajPolje(Tabla &polja, int x, int y) {
	std::string zaIzuzetak = "(";
	zaIzuzetak += (x + '0'); zaIzuzetak += ','; zaIzuzetak += (y + '0'); zaIzuzetak += ')';
	if (x < 0 || x >= polja.size() || y < 0 || y >= polja.size()) throw std::domain_error("Polje " + zaIzuzetak + " ne postoji");
	
	if (polja[x][y] == Polje::Mina) polja[x][y] = Polje::BlokiranoMina;
	if (polja[x][y] == Polje::Posjeceno) polja[x][y] = Polje::BlokiranoPosjeceno;
	if (polja[x][y] == Polje::Prazno) polja[x][y] = Polje::BlokiranoPrazno;
}

void DeblokirajPolje(Tabla &polja, int x, int y) {
	std::string zaIzuzetak = "(";
	zaIzuzetak += (x + '0'); zaIzuzetak += ','; zaIzuzetak += (y + '0'); zaIzuzetak += ')';
	if (x < 0 || x >= polja.size() || y < 0 || y >= polja.size()) throw std::domain_error("Polje " + zaIzuzetak + " ne postoji");
	
	if (polja[x][y] == Polje::BlokiranoMina) polja[x][y] = Polje::Mina;
	if (polja[x][y] == Polje::BlokiranoPosjeceno) polja[x][y] = Polje::Posjeceno;
	if (polja[x][y] == Polje::BlokiranoPrazno) polja[x][y] = Polje::Prazno;
}
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer) {
	int idx = 4;
	/*
		int setamX[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
		int setamY[] = {-1, 0,   1,-1, 0, 1,-1, 0, 1};
	*/
	if (smjer == Smjerovi::GoreLijevo) idx = 0;
	else if (smjer == Smjerovi::Gore) idx = 1;
	else if (smjer == Smjerovi::GoreDesno) idx = 2;
	else if (smjer == Smjerovi::Lijevo) idx = 3;
	else if (smjer == Smjerovi::Desno) idx = 5;
	else if (smjer == Smjerovi::DoljeLijevo) idx = 6;
	else if (smjer == Smjerovi::Dolje) idx = 7;
	else if (smjer == Smjerovi::DoljeDesno) idx = 8;
	
	polja[x][y] = Polje::Posjeceno;
	
	Status ret;
	int nX, nY;
	nX = x + setamX[idx]; nY = y + setamY[idx];
	
	if (nX < 0 || nX >= polja.size() || nY < 0 || nY >= polja.size()) throw std::out_of_range("Izlazak van igrace table");
	x = nX;
	y = nY;
	if (polja[nX][nY] == Polje::BlokiranoPosjeceno || polja[nX][nY] == Polje::BlokiranoPrazno || polja[nX][nY] == Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
	if (polja[nX][nY] == Polje::Mina) {
		for (int i = 0; i < polja.size(); i++)
			for (int j = 0; j < polja[i].size(); j++)
				polja[i][j] == Polje::Prazno;
		ret = Status::KrajPoraz;
		return ret;
	}
	
	int brojPraznih = 0;
	ret = Status::NijeKraj;
	for (int i = 0; i < polja.size(); i++)
		for (int j = 0; j < polja[i].size(); j++)
			if (polja[i][j] == Polje::Prazno) brojPraznih++;
	if (brojPraznih == 0) ret = Status::KrajPobjeda;
	
	return ret;
}
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y) {
	int nX, nY;
	nX = novi_x;
	nY = novi_y;
	Status ret;
	
	if (nX < 0 || nX >= polja.size() || nY < 0 || nY >= polja.size()) throw std::out_of_range("Izlazak van igrace table");
	x = nX;
	y = nY;
	if (polja[nX][nY] == Polje::BlokiranoPosjeceno || polja[nX][nY] == Polje::BlokiranoPrazno || polja[nX][nY] == Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
	if (polja[nX][nY] == Polje::Mina) {
		for (int i = 0; i < polja.size(); i++)
			for (int j = 0; j < polja[i].size(); j++)
				polja[i][j] == Polje::Prazno;
		ret = Status::KrajPoraz;
		return ret;
	}
	
	int brojPraznih = 0;
	ret = Status::NijeKraj;
	for (int i = 0; i < polja.size(); i++)
		for (int j = 0; j < polja[i].size(); j++)
			if (polja[i][j] == Polje::Prazno) brojPraznih++;
	if (brojPraznih == 0) ret = Status::KrajPobjeda;
	
	return ret;
	
}
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska) {
	std::string unos, s1, s2;
	getline(std::cin, unos);
	s1 = s2 = "";
	
	int koji_char = 0;
	char c1, c2;
	int idx2 = -1;
	
	for (int i = 0; i < unos.length(); i++) {
		if (unos.at(i) != ' ') {
			if (koji_char == 0) {
				c1 = unos.at(i);
				koji_char++;
			}
			else if (koji_char == 1) {
				c2 = unos.at(i);
				idx2 = i;
				koji_char++;
			}
			
		}
	}
	bool bio_char = 0;
	koji_char = 0;
	for (int i = idx2; i < unos.length(); i++) {
		if (unos[i] != ' ') bio_char = 1;
		if (!bio_char) continue;
		else {
			if (koji_char == 0) {
				for (int j = i; j < unos.length(); j++)
					if (unos[j] != ' ') s1 += unos[j];
					else break;
				koji_char++;
			}
			else if (koji_char == 1) {
				for (int j = i; j < unos.length(); j++)
					if (unos[j] != ' ') s1 += unos[j];
					else break;
				koji_char++;
			}
		}
	}
	
	if (c1 == 'P') {
		if (c2 == '>') {
			int br1, br2;
			br1 = br2 = 0;
			for (int i = s1.length() - 1; i >= 0; i--) br1 = br1 * 10 + (s1[i] - '0');
			for (int i = s2.length() - 1; i >= 0; i--) br2 = br2 * 10 + (s2[i] - '0');
			x = br1;
			y = br2;
			komanda = Komande::PomjeriDalje;
			return 1;
		}
		else if (c2 == '1')
	
		else {
			
		}
	}
	else if (c1 == 'B') {
		
	}
	else if (c1 == 'D') {
		
	}
	else if (c1 == 'Z') {
		
	}
	else if (c1 == 'K') {
		
	}
	return 1;
}
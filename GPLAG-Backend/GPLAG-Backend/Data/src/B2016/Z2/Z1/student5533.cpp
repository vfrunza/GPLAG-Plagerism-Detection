#include <vector>
#include <stdexcept>
#include <string>
#include <sstream>
#include <iostream>
#include <utility>
#include <algorithm>
#include <cctype>

using std::domain_error;
using std::logic_error;
using std::out_of_range;
using std::runtime_error;

const int nr[]{-1, -1, -1, 0, 1, 1, 1, 0, 0};
const int nc[]{-1, 0, 1, 1, 1, 0, -1, -1, 0};

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
	PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};

enum class Komande {
	PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};


typedef std::vector<std::vector<Polje>> Tabla;

bool PoljeOK(int r, int c, int n) {
	return (r >= 0 && c >= 0 && r < n && c < n);
}

bool KomandaOK(const std::string &k) {
	if (k == "P1" || k == "P>" || k == "B" || k == "D" || k == "PO" || k == "Z" || k == "K") return true;
	return false;
}

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine) {
	if (n < 0) throw domain_error("Ilegalna velicina polja");
	Tabla r(n, std::vector<Polje>(n, Polje::Prazno));
	
	for (int i = 0; i < mine.size(); i++) {
		if (mine[i].size() != 2) throw domain_error("Ilegalan format zadavanja mina");
		if (!PoljeOK(mine[i][0], mine[i][1], n)) throw domain_error("Ilegalne pozicije mina");
		r[mine[i][0]][mine[i][1]] = Polje::Mina;
	}
	
	return r;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y) {
	if (!PoljeOK(x, y, polja.size())) throw domain_error("Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji");
	std::vector<std::vector<int>> r(3, std::vector<int>(3));
	
	const int _nr[]{-1, -1, -1, 0, 0, 0, 1, 1, 1};
	const int _nc[]{-1, 0, 1, -1, 0, 1, -1, 0, 1};
	
	for (int i = 0; i < 9; i++) {
		int tr(x + _nr[i]), tc(y + _nc[i]);
		if (PoljeOK(tr, tc, polja.size())) {
			int cnt(0);
			for (int j = 0; j < 8; j++) {
				int sr(tr + nr[j]), sc(tc + nc[j]);
				if (PoljeOK(sr, sc, polja.size()) && polja[sr][sc] == Polje::Mina) cnt++;
			}
			r[i / 3][i % 3] = cnt;
		}
	}
	
	return r;
}

void BlokirajPolje(Tabla &polja, int x, int y) {
	if (!PoljeOK(x, y, polja.size())) throw domain_error("Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji");
	if (int(polja[x][y]) < 3) polja[x][y] = Polje(int(polja[x][y]) + 3);
}


void DeblokirajPolje(Tabla &polja, int x, int y) {
	if (!PoljeOK(x, y, polja.size())) throw domain_error("Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji");
	if (int(polja[x][y]) >= 3) polja[x][y] = Polje(int(polja[x][y]) - 3);
}

Status Idi(Tabla &polja, int &x, int &y, int tr, int tc) {
	if (!PoljeOK(tr, tc, polja.size())) throw out_of_range("Izlazak van igrace table");
	if (int(polja[tr][tc]) >= 3) throw logic_error("Blokirano polje");
	
	polja[x][y] = Polje::Posjeceno;
	
	x = tr;
	y = tc;
	if (polja[tr][tc] == Polje::Mina) {
		for (int i = 0; i < polja.size(); i++)
			std::fill(polja[i].begin(), polja[i].end(), Polje::Prazno);
		return Status::KrajPoraz;
	}
	
	int cnt(0);
	for (int i = 0; i < polja.size(); i++)
		cnt += std::count(polja[i].begin(), polja[i].end(), Polje::Prazno);
		
	if (cnt == 0) return Status::KrajPobjeda;
	
	if (cnt == 1 && polja[x][y] == Polje::Prazno) return Status::KrajPobjeda; // mozda ovo?
	
	return Status::NijeKraj;
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer) {
	int tr(x + nr[int(smjer)]), tc(y + nc[int(smjer)]);
	return Idi(polja, x, y, tr, tc);
}

void PrijaviGresku(KodoviGresaka kg, bool nl = true) {
	if (kg == KodoviGresaka::PogresnaKomanda) std::cout << "Nerazumljiva komanda!";
	if (kg == KodoviGresaka::NedostajeParametar) std::cout << "Komanda trazi parametar koji nije naveden!";
	if (kg == KodoviGresaka::NeispravanParametar) std::cout << "Parametar komande nije ispravan!";
	if (kg == KodoviGresaka::SuvisanParametar) std::cout << "Zadan je suvisan parametar nakon komande!";
	
	if (nl) std::cout << std::endl;
}

int ctype_digits(std::string s) {
	if (s.size() == 0) return false;
	if (s.size() == 1 && s[0] == '-') return false;
	
	if (!std::isdigit(s[0]) && s[0] != '-') return false;
	
	for (int i = 1; i < s.size(); i++) {
		if (!std::isdigit(s[i])) return false;
	}
	return true;
}

int to_int(std::string s) {
	int r(0), i(0);
	
	if (s[0] == '-') i = 1;
	for (; i < s.size(); i++) r = r * 10 + s[i] - '0';
	
	if (s[0] == '-') return -r;
	return r;
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska) {
	std::string tmp;
	std::getline(std::cin >> std::ws,  tmp);
	std::stringstream ss(tmp); /* sstream je ukratko obradjen u predavanjima: https://c2.etf.unsa.ba/file.php/76/Predavanje_3_b.pdf */
	
	ss >> tmp;
	if (!KomandaOK(tmp)) {
		greska = KodoviGresaka::PogresnaKomanda;
		return false;
	}
	
	if (tmp == "P1") {
		std::string param;
		
		if (!(ss >> param)) {
			greska = KodoviGresaka::NedostajeParametar;
			return false;
		}
		
		if (ss >> tmp) {
			greska = KodoviGresaka::SuvisanParametar;
			return false;
		}
		
		bool pok(false);
		std::vector<std::string> tvp{"GL", "G", "GD", "D", "DoD", "Do", "DoL", "L"};
		for (int i = 0; i < tvp.size(); i++) {
			if (tvp[i] == param) {
				pok = true;
				smjer = Smjerovi(i);
				break;
			}
		}
		
		if (!pok) {
			greska = KodoviGresaka::NeispravanParametar;
			return false;
		}
		
		komanda = Komande::PomjeriJednoMjesto;
		return true;
	}
	else if(tmp == "P>" || tmp == "B" || tmp == "D") {
		int cmd(1);
		if (tmp == "B") cmd = 2;
		else if (tmp == "D") cmd = 3;
		
		int tx, ty;
		
		ss >> std::ws;
		if (ss.eof()) {
			greska = KodoviGresaka::NedostajeParametar;
			return false;
		}
		
		if (!(ss >> tx >> std::ws)) {
			greska = KodoviGresaka::NeispravanParametar;
			return false;
		}

		if (ss.eof()) {
			greska = KodoviGresaka::NedostajeParametar;
			return false;
		}
		
		if (!(ss >> tmp)) {
			greska = KodoviGresaka::NeispravanParametar;
			return false;
		}
		
		if (!ctype_digits(tmp)) {
			greska = KodoviGresaka::NeispravanParametar;
			return false;
		}
		
		ty = to_int(tmp);
		
		if (ss >> tmp) {
			greska = KodoviGresaka::SuvisanParametar;
			return false;
		}
		
		komanda = Komande(cmd);
		x = tx;
		y = ty;
		return true;
	}
	else if(tmp == "PO" || tmp == "Z" || tmp == "K") {
		int cmd(4);
		if (tmp == "Z") cmd = 5;
		else if (tmp == "K") cmd = 6;
		
		if (ss >> tmp) {
			greska = KodoviGresaka::SuvisanParametar;
			return false;
		}
		
		komanda = Komande(cmd);
		return true;
	}
	
	return false;
}

void ZavrsiIgru(Tabla &polja) {
	for(int i = 0; i < polja.size(); i++)
		std::fill(polja[i].begin(), polja[i].end(), Polje::Prazno);
	
	throw runtime_error("Igra zavrsena");
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0) {
	try {
		if (komanda == Komande::PomjeriJednoMjesto) {
			auto r(Idi(polja, x, y, p_smjer));
			std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")" << std::endl;
			if (r == Status::KrajPobjeda) {
				std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
				ZavrsiIgru(polja);
			}
			else if (r == Status::KrajPoraz) {
				std::cout << "Nagazili ste na minu" << std::endl;
				ZavrsiIgru(polja);
			}
		}
		else if (komanda == Komande::PomjeriDalje) {
			auto r(Idi(polja, x, y, p_x, p_y));
			std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")" << std::endl;
			if (r == Status::KrajPobjeda) {
				std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
				ZavrsiIgru(polja);
			}
			else if (r == Status::KrajPoraz) {
				std::cout << "Nagazili ste na minu" << std::endl;
				ZavrsiIgru(polja);
			}
		}
		else if (komanda == Komande::Blokiraj) {
			BlokirajPolje(polja, p_x, p_y);
		}
		else if (komanda == Komande::Deblokiraj) {
			DeblokirajPolje(polja, p_x, p_y);
		}
		else if (komanda == Komande::PrikaziOkolinu) {
			auto r(PrikaziOkolinu(polja, x, y));
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) std::cout << r[i][j] << " ";
				std::cout << std::endl;
			}
		}
		else if (komanda == Komande::ZavrsiIgru) {
			ZavrsiIgru(polja);
		}
		else if (komanda == Komande::KreirajIgru) {
			int n;
			std::cout << "Unesite broj polja: ";
			while (!(std::cin >> n) || n < 0) {
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				std::cout << "Greska, unesite ponovo!" << std::endl;
			}
			std::cin.clear();
			
			std::cout << "Unesite pozicije mina: ";
			
			std::vector<std::vector<int>> mine;
			
			std::string tmp;
			
			while(std::getline(std::cin >> std::ws, tmp)) {
				if (tmp == ".") break;
				std::stringstream ss(tmp);
				
				char del1, del2, del3;
				int xx, yy;
				if (!(ss >> del1 >> xx >> del2 >> yy >> del3) || !PoljeOK(xx, yy, n) || del1 != '(' || del2 != ',' || del3 != ')') {
					std::cout << "Greska, unesite ponovo!" << std::endl;
					continue;
				}
				
				if (ss >> tmp) {
					std::cout << "Greska, unesite ponovo!" << std::endl;
					continue;
				}
				
				mine.push_back({xx, yy});
			}

			polja = KreirajIgru(n, mine);
		}
	}
	catch(domain_error e) {
		std::cout << e.what() << std::endl;
	}
	catch(out_of_range e) {
		std::cout << e.what() << std::endl;
	}
	catch(logic_error e) {
		std::cout << e.what() << std::endl;
	}
	catch(runtime_error e) {
		//std::cout << e.what() << std::endl;
		throw;
	}
}

int main ()
{
	try {
		Tabla polja;
		Komande komanda;
		Smjerovi smjer;
		int x(0), y(0);
		KodoviGresaka kod_greske;
		
		for(;;) {
			std::cout << "Unesite komandu: ";
			
			int X, Y;
			bool r(UnosKomande(komanda, smjer, X, Y, kod_greske));
			
			if (r) {
				IzvrsiKomandu(komanda, polja, x, y, smjer, X, Y);
			}
			else PrijaviGresku(kod_greske);
		}
	}
	catch (runtime_error e) {
		std::cout << "Dovidjenja!" << std::endl;	
	}
	
	return 0;
}
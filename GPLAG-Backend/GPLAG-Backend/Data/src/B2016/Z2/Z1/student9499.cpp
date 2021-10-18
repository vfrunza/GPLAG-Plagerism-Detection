/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/	
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

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
Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine) {
	Tabla igra(n, std::vector<Polje> (n, Polje::Prazno));
	for (int i = 0; i < mine.size(); i++) {
		if (mine[i].size() != 2) throw (std::domain_error("Ilegalan format zadavanja mina"));
		if (mine[i][0] >= n or mine[i][0] < 0 or mine[i][1] >= n or mine[i][1] < 0) throw (std::domain_error("Ilegalne pozicije mina"));
		igra[mine[i][0]][mine[i][1]] = Polje::Mina;
	}
	return igra;
}

int okolinaOkoline(const Tabla &polja, int x, int y) {
	int mine(0);
	for (int i = x - 1; i < x + 2; i++) {
		if (i < 0) 
			continue;
		if (i >= polja.size()) 
			break;
		for (int j = y - 1; j < y + 2; j++) {
			if (j < 0) 
				continue;
			if (j >= polja[i].size()) 
				break;
			if (polja[i][j] == Polje::Mina or polja[i][j] == Polje::BlokiranoMina)
				mine++;
		}
	}
	if (x < 0 or x >= polja.size() or y < 0 or y >= polja.size()) 
		return mine;
	if (polja[x][y] == Polje::Mina or polja[x][y] == Polje::BlokiranoMina) 
		mine--;
	return mine;
}		

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y) {
	if (x < 0 or y < 0 or x >= polja.size() or y >= polja.size()) 
		throw(std::domain_error ("Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji\n"));
	std::vector<std::vector<int>> matricaMina(3, std::vector<int> (3, 0));
	for (int i = 0; i < 3; i++) {
		int elementI(0);
		if (i == 0) 
			elementI--;
		else if (i == 2) 
			elementI++;
		for (int j = 0; j < 3; j++) {
			int elementJ(0);
			if (j == 0) 
				elementJ--;
			else if (j == 2) 
				elementJ++;
			matricaMina[i][j] = okolinaOkoline(polja, x + elementI, y + elementJ);
		}
	}
	return matricaMina;
}

void BlokirajPolje(Tabla &polja, int x, int y) {
	if (x < 0 or y < 0 or x >= polja.size() or y >= polja.size()) 
		throw (std::domain_error("Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji\n"));
	if (polja[x][y] == Polje::Prazno) polja[x][y] = Polje::BlokiranoPrazno;
	else if (polja[x][y] == Polje::Mina) polja[x][y] = Polje::BlokiranoMina;
	else if (polja[x][y] == Polje::Posjeceno) polja[x][y] = Polje::BlokiranoPosjeceno;
}
void DeblokirajPolje(Tabla &polja, int x, int y) {
	if (x < 0 or y < 0 or x >= polja.size() or y >= polja.size()) 
		throw (std::domain_error("Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji\n"));
	if (polja[x][y] == Polje::BlokiranoPrazno) polja[x][y] = Polje::Prazno;
	else if (polja[x][y] == Polje::BlokiranoMina) polja[x][y] = Polje::Mina;
	else if (polja[x][y] == Polje::BlokiranoPosjeceno) polja[x][y] = Polje::Posjeceno;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y) {
	if (novi_x < 0 or novi_x >= polja.size() or novi_y < 0 or novi_y >= polja.size()) throw (std::out_of_range("Izlazak van igrace table\n"));
	if (polja[novi_x][novi_y] == Polje::BlokiranoPosjeceno) throw (std::logic_error("Blokirano polje\n"));
	else if (polja[novi_x][novi_y] == Polje::BlokiranoPrazno) throw (std::logic_error("Blokirano polje\n"));
	else if (polja[novi_x][novi_y] == Polje::BlokiranoMina) throw (std::logic_error("Blokirano polje\n"));
	if (x < 0 or  x >= polja.size() or y < 0 or y >= polja.size()) throw (std::out_of_range("Izlazak van igrace table\n"));
	polja.at(x).at(y) = Polje::Posjeceno;
	if (polja[novi_x][novi_y] == Polje::Mina) { 
		std::vector<std::vector<int>> tmp;
		polja = KreirajIgru(polja.size(), tmp);
		return Status::KrajPoraz;
	}
	bool pobjeda(true);
	for (int i = 0; i < polja.size(); i++)
		for (int j = 0; j < polja.size(); j++)
			if (polja[i][j] == Polje::Prazno or polja[i][j] == Polje::BlokiranoPrazno) pobjeda = false;
	if (pobjeda) return Status::KrajPobjeda;
	x = novi_x;
	y = novi_y;
	return Status::NijeKraj;
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer) {
	int novi_x(0), novi_y(0);
	if (smjer == Smjerovi::GoreLijevo) { novi_x--; novi_y--; }
	else if (smjer == Smjerovi::Gore) novi_x--;
	else if (smjer == Smjerovi::GoreDesno) { novi_x--; novi_y++; }
	else if (smjer == Smjerovi::Desno) novi_y++;
	else if (smjer == Smjerovi::DoljeDesno) { novi_x++; novi_y++; }
	else if (smjer == Smjerovi::Dolje) novi_x++;
	else if (smjer == Smjerovi::DoljeLijevo) { novi_x++; novi_y--; }
	else if (smjer == Smjerovi::Lijevo) novi_y--;
	return Idi(polja, x, y, x + novi_x, y + novi_y);
}

void PrijaviGresku(KodoviGresaka kod) {
	if (kod == KodoviGresaka::PogresnaKomanda) std::cout << "Nerazumljiva komanda!\n";
	else if (kod == KodoviGresaka::NedostajeParametar) std::cout << "Komanda trazi parametar koji nije naveden!\n";
	else if (kod == KodoviGresaka::NeispravanParametar) std::cout << "Parametar komande nije ispravan!\n";
	else if (kod == KodoviGresaka::SuvisanParametar) std::cout << "Zadan je suvisan parametar nakon komande!\n";
}

int vratiBroj(const std::string &s, int poc, int kraj) {
	int suma(0);
	int inkrement(1);
	while (poc <= kraj) {
		if (!(s[kraj] >= '0' and s[kraj] <= '9')) {
			kraj --;
			continue;
		}
		suma += (s[kraj] - '0') * inkrement;
		inkrement *= 10;
		kraj--;
	}
	return suma;
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska) {
	std::string s;
	std::getline(std::cin, s);
	int i;
	for (i = 0; i < s.length(); i++)
		if (s[i] != ' ') break;
	if (s.length() == 0) {
		greska = KodoviGresaka::PogresnaKomanda;
		return false;
	}
	if (s[i] == 'P' and s[i + 1] == '1') {
		i += 2;
		while (s[i] == ' ') i++;
		
		if (s[i] == 'G') { // provjeravam samo g
			if (s[i + 1] == '\0') {
				smjer = Smjerovi::Gore;
				komanda = Komande::PomjeriJednoMjesto;
				return true;
			}
			if (s[i + 1] == ' ') {
				while (s[i + 1] == ' ') i++;
				if (s[i + 1] == '\0') {
					smjer = Smjerovi::Gore;
					komanda = Komande::PomjeriJednoMjesto;
					return true;
				}
				else {
					greska = KodoviGresaka::SuvisanParametar;
					return false;
				}
			}
			if (s[i + 1] == 'L') { // provjeravam g sa l "GL"
				if (s[i + 2] == '\0') {
					smjer = Smjerovi::GoreLijevo;
					komanda = Komande::PomjeriJednoMjesto;
					return true;
				}
				if (s[i + 2] == ' ') {
					while (s[i + 2] == ' ') i++;
					if (s[i + 2] == '\0') {
						smjer = Smjerovi::GoreLijevo;
						komanda = Komande::PomjeriJednoMjesto;
						return true;
					}
					else {
						greska = KodoviGresaka::SuvisanParametar;
						return false;
					}
				}
			}
			if (s[i + 1] == 'D') { // Provjeravam G sa D ili "GD"
				if (s[i + 2] == '\0') {
					smjer = Smjerovi::GoreDesno;
					komanda = Komande::PomjeriJednoMjesto;
					return true;
				}
				if (s[i + 2] == ' ') {
					while (s[i + 2] == ' ') i++;
					if (s[i + 2] == '\0') {
						smjer = Smjerovi::GoreDesno;
						komanda = Komande::PomjeriJednoMjesto;
						return true;
					}
					else {
						greska = KodoviGresaka::SuvisanParametar;
						return false;
					}
				}
			}
			greska = KodoviGresaka::SuvisanParametar;
			return false;
		}
		else if (s[i] == 'D') { // Provjeravam D
			if (s[i + 1] == '\0') {
				smjer = Smjerovi::Desno;
				komanda = Komande::PomjeriJednoMjesto;
				return true;
			}
			if (s[i + 1] == ' ') {
				while (s[i + 1] == ' ') i++;
				if (s[i + 1] == '\0') {
					smjer = Smjerovi::Desno;
					komanda = Komande::PomjeriJednoMjesto;
					return true;
				}
				else {
					greska = KodoviGresaka::SuvisanParametar;
					return false;
				}
			}
			if (s[i + 1] == 'o') { // Provejravam D sa o "Do"
				if (s[i + 2] == '\0') {
					smjer = Smjerovi::Dolje;
					komanda = Komande::PomjeriJednoMjesto;
					return true;
				}
				if (s[i + 2] == ' ') {
					while (s[i + 2] == ' ') i++;
					if (s[i + 2] == '\0') {
						smjer = Smjerovi::Dolje;
						komanda = Komande::PomjeriJednoMjesto;
						return true;
					}
					else {
						greska = KodoviGresaka::SuvisanParametar;
						return false;
					}
				}
				if (s[i + 2] == 'D') { // Provejravam D sa o sa ili "DoD"
					if (s[i + 3] == '\0') {
						smjer = Smjerovi::DoljeDesno;
						komanda = Komande::PomjeriJednoMjesto;
						return true;
					}
					if (s[i + 3] == ' ') {
						while (s[i + 3] == ' ') i++;
						if (s[i + 3] == '\0') {
							smjer = Smjerovi::DoljeDesno;
							komanda = Komande::PomjeriJednoMjesto;
							return true;
						}
						else {
							greska = KodoviGresaka::SuvisanParametar;
							return false;
						}
					}
				}
				if (s[i + 2] == 'L') { // Provejravam D sa o sa L ili "DoL"
					if (s[i + 3] == '\0') {
						smjer = Smjerovi::DoljeLijevo;
						komanda = Komande::PomjeriJednoMjesto;
						return true;
					}
					if (s[i + 3] == ' ') {
						while (s[i + 3] == ' ') i++;
						if (s[i + 3] == '\0') {
							smjer = Smjerovi::DoljeLijevo;
							komanda = Komande::PomjeriJednoMjesto;
							return true;
						}
						else {
							greska = KodoviGresaka::SuvisanParametar;
							return false;
						}
					}
				}
				greska = KodoviGresaka::SuvisanParametar;
				return false;
			}
		}
		else if (s[i] == 'L') { // Provjeravam L
			if (s[i + 1] == '\0') {
				smjer = Smjerovi::Lijevo;
				komanda = Komande::PomjeriJednoMjesto;
				return true;
			}
			if (s[i + 1] == ' ') {
				while (s[i + 1] == ' ') i++;
				if (s[i + 1] == '\0') {
					smjer = Smjerovi::Lijevo;
					komanda = Komande::PomjeriJednoMjesto;
					return true;
				}
				else {
					greska = KodoviGresaka::SuvisanParametar;
					return false;
				}
			}
			greska = KodoviGresaka::NeispravanParametar;
			return false;
		}
		greska = KodoviGresaka::NedostajeParametar;
		return false;
	}
	else if ( (s[i] == 'P' and s[i + 1] == '>') or (s[i] == 'B') or (s[i] == 'D') ) { // Pomjeri se za zadano polje
		char tmp(s[i]);
		if (s[i] == 'P')
			i += 2;
		else i++;
		while (s[i] == ' ') i++; // Bjezimo od razmaka
		int cifre(0);
		if (s[i] >= '0' and s[i] <= '9') {
			cifre++;
			i++;
			while (s[i] >= '0' and s[i] <= '9') { i++; cifre++; };
			int novi_x, novi_y;
			novi_x = vratiBroj(s, i - cifre, i);
			while (s[i] == ' ') i++;
			if (s[i] == '\0') {
				greska = KodoviGresaka::NedostajeParametar; // Poslije unosa prvog parametra nije unio drugi
				return false;
			}
			if (s[i] >= '0' and s[i] <= '9') {
				cifre = 1;
				while(s[i] >= '0' and s[i] <= '9') { i++; cifre++; }
				novi_y = vratiBroj(s, i - cifre, i);
				while (s[i] == ' ') i++;
				if (s[i] == '\0') {
					if (tmp == 'P') {
						komanda = Komande::PomjeriDalje;
						x = novi_x;
						y = novi_y;
						return true;
					}
					if (tmp == 'B') {
						komanda = Komande::Blokiraj;
						x = novi_x;
						y = novi_y;
						return true;
					}
					if (tmp == 'D') {
						komanda = Komande::Deblokiraj;
						x = novi_x;
						y = novi_y;
						return true;
					}
				}
				else {
					greska = KodoviGresaka::SuvisanParametar; // Nakon zadnjeg parametra nasao nesto
					return false;
				}
			}
			else {
				greska = KodoviGresaka::NeispravanParametar; // U sredini nasao nesto sto nije razmak
				return false; 
			}
		}
		else {
			greska = KodoviGresaka::NeispravanParametar; // Prvo na sta je naletio poslije razmaka nije broj
			return false;
		}
	}
	else if (s[i] == 'P' and s[i + 1] == 'O') { // Prikazi okolinu
		while (s[i + 2] == ' ') i++;
		if (s[i + 2] == '\0') {
			komanda = Komande::PrikaziOkolinu;
			return true;
		}
		else {
			greska = KodoviGresaka::SuvisanParametar;
			return false;
		}
	}
	else if (s[i] == 'Z') { // Zavrsi igru
		while (s[i + 1] == ' ') i++;
		if (s[i + 1] == '\0') {
			komanda = Komande::ZavrsiIgru;
			return true;
		}
		else {
			greska = KodoviGresaka::PogresnaKomanda;
			return false;
		}
	}
	else if (s[i] == 'K') { // Kreiraj igru
		while (s[i + 1] == ' ') i++;
		if (s[i + 1] == '\0') {
			komanda = Komande::KreirajIgru;
			return true;
		}
		else {
			greska = KodoviGresaka::PogresnaKomanda;
			return false;
		}
	}
	greska = KodoviGresaka::PogresnaKomanda;
	return false;
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0) {
	switch (komanda) {
		case Komande::PomjeriJednoMjesto: {
			try {
				Status stanje(Idi(polja, x, y, p_smjer));
				std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")\n";
				if (stanje == Status::NijeKraj) break;
				if (stanje == Status::KrajPobjeda) {
					std::cout << "Bravo, obisli ste sva sigurna polja\n";
					std::vector<std::vector<int>> tmp;
					polja = KreirajIgru(polja.size(), tmp);
					throw std::runtime_error("Igra zavrsena\n");
				}
				if (stanje == Status::KrajPoraz) {
					std::cout << "Nagazili ste na minu\n";
					std::vector<std::vector<int>> tmp;
					polja = KreirajIgru(polja.size(), tmp);
					throw std::runtime_error("Igra zavrsena\n");
				}
			}
			catch (...) {
				throw;
				}
			}
			break;	
			
		
		case Komande::PomjeriDalje: {
			try {
				Status stanje(Idi(polja, x, y, p_x, p_y));
				std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")\n";
				if (stanje == Status::NijeKraj) break;
				if (stanje == Status::KrajPobjeda) {
					std::cout << "Bravo, obisli ste sva sigurna polja\n";
					std::vector<std::vector<int >> tmp;
					polja = KreirajIgru(polja.size(), tmp);
					throw std::runtime_error("Igra zavrsena\n");
				}
				if (stanje == Status::KrajPoraz) {
					std::cout << "Nagazili ste na minu\n";
					std::vector<std::vector<int>> tmp;
					polja = KreirajIgru(polja.size(), tmp);
					throw std::runtime_error("Igra zavrsena\n");
				}
			}
			catch (...) {
				throw;
			}
			break;
		}
		case Komande::Blokiraj: {
			try {
				BlokirajPolje(polja, p_x, p_y);
			}
			
			catch (std::domain_error e) {
				std::cout << e.what();
			}
			break;
		}
		case Komande::Deblokiraj: {
			try {
				DeblokirajPolje(polja, p_x, p_y);
			}
			catch (std::domain_error e) {
				std::cout << e.what();
			}
			break;
		}
		case Komande::PrikaziOkolinu: {
			std::vector<std::vector<int>> mat;
			try {
				mat = PrikaziOkolinu(polja, x, y);
			}
			catch (std::domain_error e) {
				std::cout << e.what();
				break;
			}
			for (std::vector<int> x : mat) {
				for (int y : x) {
					std::cout << y << " ";
				} 
				std::cout << "\n";
			}
			break;
		}
		case Komande::ZavrsiIgru: {
			std::vector<std::vector<int>> tmp;
			polja = KreirajIgru(polja.size(), tmp);
			throw std::runtime_error("Dovidjenja!\n");
			break;
		}
		case Komande::KreirajIgru: {
			int n;
			std::string s;
			std::cout << "Unesite broj polja: ";
			std::cin >> n;
			std::cin.ignore(10000, '\n');
			std::vector<std::vector<int>> min;
			std::cout << "Unesite pozicije mina: ";
			for (;;) {
				std::string s;
				std::getline(std::cin, s);
				if (s[0] == '.') break;
				if (s[0] != '(') {
					std::cout << "Greska, unesite ponovo!\n";
					continue;
				}
				if ( !(s[1] >= '0' and s[1] <= '9')) {
					std::cout << "Greska, unesite ponovo!\n";
					continue;
				}
				int i(1), cifre(0);
				while (s[i] >= '0' and s[i] <= '9') {
					i++; cifre++;
				}
				int prviX(vratiBroj(s, i - cifre, i - 1));
				if (prviX < 0 or prviX >= n) {
					std::cout << "Greska, unesite ponovo!\n";
					continue;
				}
				if (s[i] != ',') {
					std::cout << "Greska, unesite ponovo!\n";
					continue;
				}
				i++;
				if (!(s[i] >= '0' and s[i] <= '9')) {
					std::cout << "Greska, unesite ponovo!\n";
					continue;
				}
				cifre = 0;
				while (s[i] >= '0' and s[i] <= '9') {
					i++; cifre++;
				}
				int drugiY(vratiBroj(s, i - cifre, i - 1));
				if (drugiY< 0 or drugiY >= n) {
					std::cout << "Greska, unesite ponovo!\n";
					continue;
				}
				if (s[i] != ')') {
					std::cout << "Greska, unesite ponovo!\n";
					continue;
				}
				i++;
				if (s[i] != '\0') {
					std::cout << "Greska, unesite ponovo!\n";
					continue;
				}
				min.resize(min.size() + 1);
				min[min.size() - 1].push_back(prviX);
				min[min.size() - 1].push_back(drugiY);
			}
			polja = KreirajIgru(n, min);
		}
	}
}

int main () {
	Status stanje(Status::NijeKraj);
	Komande komanda;
	Tabla igra;
	int x(0), noviX(0);
	int y(0), noviY(0);
	KodoviGresaka greska;
	Smjerovi smjer;
	while (stanje != Status::KrajPoraz or stanje != Status::KrajPobjeda) {
		std::cout << "Unesite komandu: ";
		if (UnosKomande(komanda, smjer, noviX, noviY, greska)) {
			try {
				IzvrsiKomandu(komanda, igra, x, y, smjer, noviX, noviY);
			}
			catch (std::domain_error e) {
				std::cout << e.what();
			}
			catch (std::out_of_range e) {
				std::cout << e.what();
			}
			catch (std::logic_error e) {
				std::cout << e.what();
			}
			catch (std::runtime_error e) {
				std::cout << e.what();
				break;
			}
		}
		else {
			PrijaviGresku(greska);
		}
	}
	return 0;
}
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
	for(unsigned int i(0); i < mine.size(); i++) {
		if(mine[i].size() != 2) throw std::domain_error("Ilegalan format zadavanja mina");
		if(mine[i][0] > n || mine[i][0] < 0 || mine[i][1] > n || mine[i][1] < 0) throw std::domain_error("Ilegalne pozicije mina");
	}
	Tabla tabla(n, std::vector<Polje>(n, Polje::Prazno));
	for(unsigned int i(0); i < mine.size(); i++)
		tabla[mine[i][0]][mine[i][1]] = Polje::Mina;
	return tabla;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y) {
	if(x < 0 || x > polja.size() || y < 0 || y > polja.size()) throw std::domain_error("Polje (x,y) ne postoji");
	std::vector<std::vector<int>> okolina(3, std::vector<int>(3, 0));
	for(int i(x - 2); i <= x; i++)
		for(int j(y - 2); j <= y; j++) {
			if(i == x - 1 && j == y - 1) okolina[0][0] += 0;
			if(i < 0 || j < 0 || i >= polja.size() || j >= polja.size()) continue;
			if(polja[i][j] == Polje::Mina) okolina[0][0]++;
		}
	for(int i(x - 2); i <= x; i++)
		for(int j(y - 1); j <= y + 1; j++) {
			if(i == x - 1 && j == y) okolina[0][1] += 0;
			if(i < 0 || j < 0 || i >= polja.size() || j >= polja.size()) continue;
			if(polja[i][j] == Polje::Mina) okolina[0][1]++;
		}
	for(int i(x - 2); i <= x; i++)
		for(int j(y); j <= y + 2; j++) {
			if(i == x - 1 && j == y + 1) okolina[0][2] += 0;
			if(i < 0 || j < 0 || i >= polja.size() || j >= polja.size()) continue;
			if(polja[i][j] == Polje::Mina) okolina[0][2]++;
		}
	for(int i(x - 1); i <= x + 1; i++)
		for(int j(y - 2); j <= y; j++) {
			if(i == x && j == y - 1) okolina[1][0] += 0;
			if(i < 0 || j < 0 || i >= polja.size() || j >= polja.size()) continue;
			if(polja[i][j] == Polje::Mina) okolina[1][0]++;
		}
	for(int i(x - 1); i <= x + 1; i++)
		for(int j(y - 1); j <= y + 1; j++) {
			if(i == x && j == y) okolina[1][1] += 0;
			if(i < 0 || j < 0 || i >= polja.size() || j >= polja.size()) continue;
			if(polja[i][j] == Polje::Mina) okolina[1][1]++;
		}
	for(int i(x - 1); i <= x + 1; i++)
		for(int j(y); j <= y + 2; j++) {
			if(i == x && j == y + 1) okolina[1][2] += 0;
			if(i < 0 || j < 0 || i >= polja.size() || j >= polja.size()) continue;
			if(polja[i][j] == Polje::Mina) okolina[1][2]++;
		}
	for(int i(x); i <= x + 2; i++)
		for(int j(y - 2); j <= y; j++) {
			if(i == x + 1 && j == y - 1) okolina[2][0] += 0;
			if(i < 0 || j < 0 || i >= polja.size() || j >= polja.size()) continue;
			if(polja[i][j] == Polje::Mina) okolina[2][0]++;
		}
	for(int i(x); i <= x + 2; i++)
		for(int j(y - 1); j <= y + 1; j++) {
			if(i == x + 1 && j == y) okolina[2][1] += 0;
			if(i < 0 || j < 0 || i >= polja.size() || j >= polja.size()) continue;
			if(polja[i][j] == Polje::Mina) okolina[2][1]++;
		}
	for(int i(x); i <= x + 2; i++)
		for(int j(y); j <= y + 2; j++) {
			if(i == x + 1 && j == y + 1) okolina[2][2] += 0;
			if(i < 0 || j < 0 || i >= polja.size() || j >= polja.size()) continue;
			if(polja[i][j] == Polje::Mina) okolina[2][2]++;
		}
	return okolina;
}

void BlokirajPolje(Tabla &polja, int x, int y) {
	if(x < 0 || x > polja.size() || y < 0 || y > polja.size()) throw std::domain_error("Polje (x,y) ne postoji");
	if(polja[x][y] == Polje::Prazno) polja[x][y] = Polje::BlokiranoPrazno;
	else if(polja[x][y] == Polje::Posjeceno) polja[x][y] = Polje::BlokiranoPosjeceno;
	else if(polja[x][y] == Polje::Mina) polja[x][y] = Polje::BlokiranoMina;
	else {}
}

void DeblokirajPolje(Tabla &polja, int x, int y) {
	if(x < 0 || x > polja.size() || y < 0 || y > polja.size()) throw std::domain_error("Polje (x,y) ne postoji");
	if(polja[x][y] == Polje::BlokiranoPrazno) polja[x][y] = Polje::Prazno;
	else if(polja[x][y] == Polje::BlokiranoPosjeceno) polja[x][y] = Polje::Posjeceno;
	else if(polja[x][y] == Polje::BlokiranoMina) polja[x][y] = Polje::Mina;
	else {}
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer) {
	Status status;
	if(smjer == Smjerovi::GoreLijevo) {
		if(x - 1 < 0 || y - 1 < 0) throw std::out_of_range("Izlazak van igrace table");
		if(polja[x - 1][y - 1] == Polje::BlokiranoPosjeceno || polja[x - 1][y - 1] == Polje::BlokiranoPrazno || polja[x - 1][y - 1] == Polje::BlokiranoMina)
			throw std::logic_error("Blokirano polje");
		x -= 1; y -= 1;
		if(polja[x][y] == Polje::Mina) status = Status::KrajPoraz;
		else if(polja[x][y] == Polje::Prazno) status = Status::NijeKraj;
		else status = Status::KrajPobjeda;
	}
	else if(smjer == Smjerovi::Gore) {
		if(x - 1 < 0) throw std::out_of_range("Izlazak van igrace table");
		if(polja[x - 1][y] == Polje::BlokiranoPosjeceno || polja[x - 1][y] == Polje::BlokiranoPrazno || polja[x - 1][y] == Polje::BlokiranoMina)
			throw std::logic_error("Blokirano polje");
		x -= 1;
		if(polja[x][y] == Polje::Mina) status = Status::KrajPoraz;
		else if(polja[x][y] == Polje::Prazno) status = Status::NijeKraj;
		else status = Status::KrajPobjeda;
	}
	else if(smjer == Smjerovi::GoreDesno) {
		if(x - 1 < 0 || y + 1 >= polja.size()) throw std::out_of_range("Izlazak van igrace table");
		if(polja[x - 1][y + 1] == Polje::BlokiranoPosjeceno || polja[x - 1][y + 1] == Polje::BlokiranoPrazno || polja[x - 1][y + 1] == Polje::BlokiranoMina)
			throw std::logic_error("Blokirano polje");
		x -= 1; y += 1;
		if(polja[x][y] == Polje::Mina) status = Status::KrajPoraz;
		else if(polja[x][y] == Polje::Prazno) status = Status::NijeKraj;
		else status = Status::KrajPobjeda;
	}
	else if(smjer == Smjerovi::Desno) {
		if(y + 1 >= polja.size()) throw std::out_of_range("Izlazak van igrace table");
		if(polja[x][y + 1] == Polje::BlokiranoPosjeceno || polja[x][y + 1] == Polje::BlokiranoPrazno || polja[x][y + 1] == Polje::BlokiranoMina)
			throw std::logic_error("Blokirano polje");
		y += 1;
		if(polja[x][y] == Polje::Mina) status = Status::KrajPoraz;
		else if(polja[x][y] == Polje::Prazno) status = Status::NijeKraj;
		else status = Status::KrajPobjeda;
	}
	else if(smjer == Smjerovi::DoljeDesno) {
		if(x + 1 >= polja.size() || y + 1 >= polja.size()) throw std::out_of_range("Izlazak van igrace table");
		if(polja[x + 1][y + 1] == Polje::BlokiranoPosjeceno || polja[x + 1][y + 1] == Polje::BlokiranoPrazno || polja[x + 1][y + 1] == Polje::BlokiranoMina)
			throw std::logic_error("Blokirano polje");
		x += 1; y += 1;
		if(polja[x][y] == Polje::Mina) status = Status::KrajPoraz;
		else if(polja[x][y] == Polje::Prazno) status = Status::NijeKraj;
		else status = Status::KrajPobjeda;
	}
	else if(smjer == Smjerovi::Dolje) {
		if(x + 1 >= polja.size()) throw std::out_of_range("Izlazak van igrace table");
		if(polja[x + 1][y] == Polje::BlokiranoPosjeceno || polja[x + 1][y] == Polje::BlokiranoPrazno || polja[x + 1][y] == Polje::BlokiranoMina)
			throw std::logic_error("Blokirano polje");
		x += 1;
		if(polja[x][y] == Polje::Mina) status = Status::KrajPoraz;
		else if(polja[x][y] == Polje::Prazno) status = Status::NijeKraj;
		else status = Status::KrajPobjeda;
	}
	else if(smjer == Smjerovi::DoljeLijevo) {
		if(x + 1 >= polja.size() || y - 1 < 0) throw std::out_of_range("Izlazak van igrace table");
		if(polja[x + 1][y - 1] == Polje::BlokiranoPosjeceno || polja[x + 1][y - 1] == Polje::BlokiranoPrazno || polja[x + 1][y - 1] == Polje::BlokiranoMina)
			throw std::logic_error("Blokirano polje");
		x += 1; y -= 1;
		if(polja[x][y] == Polje::Mina) status = Status::KrajPoraz;
		else if(polja[x][y] == Polje::Prazno) status = Status::NijeKraj;
		else status = Status::KrajPobjeda;
	}
	else {
		if(y - 1 < 0) throw std::out_of_range("Izlazak van igrace table");
		if(polja[x][y - 1] == Polje::BlokiranoPosjeceno || polja[x][y - 1] == Polje::BlokiranoPrazno || polja[x][y - 1] == Polje::BlokiranoMina)
			throw std::logic_error("Blokirano polje");
		y -= 1;
		if(polja[x][y] == Polje::Mina) status = Status::KrajPoraz;
		else if(polja[x][y] == Polje::Prazno) status = Status::NijeKraj;
		else status = Status::KrajPobjeda;
	}
	if(status == Status::KrajPoraz)
		for(unsigned int i(0); i < polja.size(); i++)
			for(unsigned int j(0); j < polja[i].size(); j++)
				polja[i][j] = Polje::Prazno;
	return status;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y) {
	if(novi_x < 0 || novi_x >= polja.size() || novi_y < 0 || novi_y >= polja.size()) throw std::out_of_range("Izlazak van igrace table");
	if(polja[novi_x][novi_y] == Polje::BlokiranoPosjeceno || polja[novi_x][novi_y] == Polje::BlokiranoPrazno || polja[novi_x][novi_y] == Polje::BlokiranoMina)
		throw std::logic_error("Blokirano polje");
	x = novi_x;
	y = novi_y;
	Status status;
	if(polja[x][y] == Polje::Mina) {
		status = Status::KrajPoraz;
		for(unsigned int i(0); i < polja.size(); i++)
			for(unsigned int j(0); j < polja[i].size(); j++)
				polja[i][j] = Polje::Prazno;
	}
	else if(polja[x][y] == Polje::Prazno) status = Status::NijeKraj;
	else status = Status::KrajPobjeda;
	return status;
}

void PrijaviGresku(KodoviGresaka greska) {
	if(greska == KodoviGresaka::PogresnaKomanda) std::cout << "Nerazumljiva komanda!" << std::endl;
	else if(greska == KodoviGresaka::NedostajeParametar) std::cout << "Komanda trazi parametar koji nije naveden!" << std::endl;
	else if(greska == KodoviGresaka::NeispravanParametar) std::cout << "Parametar komande nije ispravan!" << std::endl;
	else std::cout << "Zadan je suvisan parametar nakon komande!" << std::endl;
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska) {
	std::string s;
	std::cin >> s;
	if(s == "P1") {
		std::string s;
		std::cin >> s;
		if(s == "GL") {
			if(std::cin.peek() == 10) {
				smjer = Smjerovi::GoreLijevo;
			}
			else {
				greska = KodoviGresaka::NeispravanParametar;
				return false;
			}
		}
		else if(s == "G") {
			if(std::cin.peek() == 10) {
				smjer = Smjerovi::Gore;
			}
			else {
				greska = KodoviGresaka::NeispravanParametar;
				return false;
			}
		}
		else if(s == "GD") {
			if(std::cin.peek() == 10) {
				smjer = Smjerovi::GoreDesno;
			}
			else {
				greska = KodoviGresaka::NeispravanParametar;
				return false;
			}
		}
		else if(s == "D") {
			if(std::cin.peek() == 10) {
				smjer = Smjerovi::Desno;
			}
			else {
				greska = KodoviGresaka::NeispravanParametar;
				return false;
			}
		}
		else if(s == "Do") {
			if(std::cin.peek() == 10) {
				smjer = Smjerovi::Dolje;
			}
			else {
				greska = KodoviGresaka::NeispravanParametar;
				return false;
			}
		}
		else if(s == "DoD") {
			if(std::cin.peek() == 10) {
				smjer = Smjerovi::DoljeDesno;
			}
			else {
				greska = KodoviGresaka::NeispravanParametar;
				return false;
			}
		}
		else if(s == "DoL") {
			if(std::cin.peek() == 10) {
				smjer = Smjerovi::DoljeLijevo;
			}
			else {
				greska = KodoviGresaka::NeispravanParametar;
				return false;
			}
		}
		else if(s == "L") {
			if(std::cin.peek() == 10) {
				smjer = Smjerovi::Lijevo;
			}
			else {
				greska = KodoviGresaka::NeispravanParametar;
				return false;
			}
		}
		else {
			greska = KodoviGresaka::NedostajeParametar;
			return false;
		}
		komanda = Komande::PomjeriJednoMjesto;
		return true;
	}
	else if(s == "P>") {
		int a, b;
		std::cin >> a;
		if(!std::cin) {
			greska = KodoviGresaka::NeispravanParametar;
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			return false;
		}
		std::cin >> b;
		if(!std::cin) {
			greska = KodoviGresaka::NeispravanParametar;
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			return false;
		}
		x = a; y = b;
		komanda = Komande::PomjeriDalje;
		return true;
	}
	else if(s == "PO") {
		if(std::cin.peek() == 10) {
			komanda = Komande::PrikaziOkolinu;
			return true;
		}
		else {
			greska = KodoviGresaka::SuvisanParametar;
			return false;
		}
	}
	else if(s == "B") {
		int a, b;
		std::cin >> a;
		if(!std::cin) {
			greska = KodoviGresaka::NeispravanParametar;
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			return false;
		}
		std::cin >> b;
		if(!std::cin) {
			greska = KodoviGresaka::NeispravanParametar;
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			return false;
		}
		x = a; y = b;
		komanda = Komande::Blokiraj;
		return true;
	}
	else if(s == "D") {
		int a, b;
		std::cin >> a;
		if(!std::cin) {
			greska = KodoviGresaka::NeispravanParametar;
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			return false;
		}
		std::cin >> b;
		if(!std::cin) {
			greska = KodoviGresaka::NeispravanParametar;
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			return false;
		}
		x = a; y = b;
		komanda = Komande::Deblokiraj;
		return true;
	}
	else if(s == "Z") {
		if(std::cin.peek() == 10) {
			komanda = Komande::ZavrsiIgru;
			return true;
		}
		else {
			greska = KodoviGresaka::SuvisanParametar;
			return false;
		}
	}
	else if(s == "K") {
		if(std::cin.peek() == 10) {
			komanda = Komande::KreirajIgru;
			return true;
		}
		else {
			greska = KodoviGresaka::SuvisanParametar;
			return false;
		}
	}
	else {
		greska = KodoviGresaka::PogresnaKomanda;
		return false;
	}
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0) {
	try {
		if(komanda == Komande::PomjeriJednoMjesto) {
			Status status(Idi(polja, x, y, p_smjer));
			std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")" << std::endl;
			if(status == Status::KrajPobjeda) {
				std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
				for(std::vector<Polje> i : polja)
					for(Polje j : i) j = Polje::Prazno;
				throw std::runtime_error("Igra zavrsena");
			}
			if(status == Status::KrajPoraz) {
				std::cout << "Nagazili ste na minu" << std::endl;
				for(std::vector<Polje> i : polja)
					for(Polje j : i) j = Polje::Prazno;
				throw std::runtime_error("Igra zavrsena");
			}
		}
		else if(komanda == Komande::PomjeriDalje) {
			Status status(Idi(polja, x, y, p_x, p_y));
			std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")" << std::endl;
			if(status == Status::KrajPobjeda) {
				std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
				for(std::vector<Polje> i : polja)
					for(Polje j : i) j = Polje::Prazno;
				throw std::runtime_error("Igra zavrsena");
			}
			if(status == Status::KrajPoraz) {
				std::cout << "Nagazili ste na minu" << std::endl;
				for(std::vector<Polje> i : polja)
					for(Polje j : i) j = Polje::Prazno;
				throw std::runtime_error("Igra zavrsena");
			}
		}
		else if(komanda == Komande::Blokiraj) {
			BlokirajPolje(polja, x, y);
		}
		else if(komanda == Komande::Deblokiraj) {
			DeblokirajPolje(polja, x, y);
		}
		else if(komanda == Komande::PrikaziOkolinu) {
			std::vector<std::vector<int>> okolina(PrikaziOkolinu(polja, x, y));
			for(std::vector<int> i : okolina) {
				for(int j : i) std::cout << j << " ";
				std::cout << std::endl;
			}
			std::cout << std::endl;
		}
		else if(komanda == Komande::ZavrsiIgru) {
			for(std::vector<Polje> i : polja)
				for(Polje j : i) j = Polje::Prazno;
			throw std::runtime_error("Igra zavrsena");
		}
		else {
			std::cout << "Unesite broj polja: ";
			int n;
			std::cin >> n;
			std::cout << "Unesite pozicije mina: ";
			std::vector<std::vector<int>> mine;
			char c;
			int a, b;
			bool uredu(false);
			do {
				uredu = false;
				do {
					std::cin.clear();
					std::cin.ignore(1000, '\n');
					std::cin >> c;
					if(c == '.') break;
					if(c != '(') {
						std::cout << "Greska, unesite ponovo!" << std::endl;
						continue;
					}
					else {
						std::cin >> a;
						if(!std::cin || a < 0 || a >= n) {
							std::cout << "Greska, unesite ponovo!" << std::endl;
							continue;
						}
						else {
							std::cin >> c;
							if(c != ',') {
								std::cout << "Greska, unesite ponovo!" << std::endl;
								continue;
							}
							else {
								std::cin >> b;
								if(!std::cin || b < 0 || b >= n) {
									std::cout << "Greska, unesite ponovo!" << std::endl;
									continue;
								}
								else {
									std::cin >> c;
									if(c != ')') {
										std::cout << "Greska, unesite ponovo!" << std::endl;
										continue;
									}
									else {
										uredu = true;
										std::vector<int> v;
										v.push_back(a);
										v.push_back(b);
										mine.push_back(v);
									}
								}
							}
						}
					}
				} while(!uredu);
			} while(c != '.');
			polja = KreirajIgru(n, mine);
		}
	}
	catch(std::out_of_range izuzetak) { std::cout << izuzetak.what() << std::endl; }
	catch(std::logic_error izuzetak) { std::cout << izuzetak.what() << std::endl; }
	catch(std::domain_error izuzetak) { std::cout << izuzetak.what() << std::endl; }
}

int main ()
{
	Tabla polja;
	Komande komanda;
	Smjerovi smjer;
	KodoviGresaka greska;
	int x(0), y(0);
	try {
		for(;;) {
			std::cout << "Unesite komandu: ";
			if(UnosKomande(komanda, smjer, x, y, greska)) IzvrsiKomandu(komanda, polja, x, y);
			else PrijaviGresku(greska);
		}
	}
	catch(std::runtime_error izuzetak) {
		std::cout << "Dovidjenja!";
	}
	
	return 0;
}
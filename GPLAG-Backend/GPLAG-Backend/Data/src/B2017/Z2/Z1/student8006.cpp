#include <iostream>
#include <vector>
#include <stdexcept>	
#include <string>


enum class KodoviGresaka {
	PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};
enum class Komande {
	PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};
enum class Smjerovi {
	GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};
enum class Polje {
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};
enum class Status {
	NijeKraj, KrajPoraz, KrajPobjeda
};

typedef std::vector<std::vector<Polje>> Tabla;

///////////////////////////////////////////////////////////////////////////////////////////////

std::string PorukaIzuzetka(int x, int y) {
	std::string poruka("Polje (");
	poruka += std::to_string(x) + "," + std::to_string(y) + ") ne postoji";
	return poruka;
}

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine) {
	if (n <= 0) throw std::domain_error("Ilegalna velicina");
	Tabla t(n, std::vector<Polje>(n, Polje::Prazno));
	for (auto v : mine) {
		if (v.size() != 2) throw std::domain_error("Ilegalan format zadavanja mina");
		if (v[0] < 0 || v[0] >= n || v[1] < 0 || v[1] >= n) throw std::domain_error("Ilegalne pozicije mina");
		t[v[0]][v[1]] = Polje::Mina;
	}
	return t;
}

int OkolneMine(int x, int y, const Tabla &t) {
	int suma = 0;
	for (int i = x - 1; i <= x + 1; i++) {
		if (i < 0 || i >= t.size()) continue;
		for (int j = y - 1; j <= y + 1; j++) {
			if (j < 0 || j >= t.size() ||(i == x && j == y)) continue;
			if (t[i][j] == Polje::Mina) suma++;
		}
	}
	return suma;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &t, int x, int y) {
	if (x < 0 || x >= t.size() || y < 0 || y >= t.size()) throw std::domain_error(PorukaIzuzetka(x,y).c_str());	
	std::vector<std::vector<int>> mine(3, std::vector<int>(3));
	for (int i = 0; i < mine.size(); i++) 
		for (int j = 0; j < mine.size(); j++) 
			mine[i][j] = OkolneMine(x+i-1, y+j-1, t);
	return mine;
}

void BlokirajPolje(Tabla &t, int x, int y) {
	if (x < 0 || x >= t.size() || y < 0 || y >= t.size()) throw std::domain_error(PorukaIzuzetka(x,y).c_str());
	if (t[x][y] == Polje::Prazno) t[x][y] = Polje::BlokiranoPrazno;
	else if (t[x][y] == Polje::Mina) t[x][y] = Polje::BlokiranoMina;
	else if (t[x][y] == Polje::Posjeceno) t[x][y] = Polje::BlokiranoPosjeceno;
}

void DeblokirajPolje(Tabla &t, int x, int y) {
	if (x < 0 || x >= t.size() || y < 0 || y >= t.size()) throw std::domain_error(PorukaIzuzetka(x,y).c_str());
	if (t[x][y] == Polje::BlokiranoPrazno) t[x][y] = Polje::Prazno;
	else if (t[x][y] == Polje::BlokiranoMina) t[x][y] = Polje::Mina;
	else if (t[x][y] == Polje::BlokiranoPosjeceno) t[x][y] = Polje::Posjeceno;
}

bool DaLiJePobjeda(const Tabla &t, int i, int j) {
	for (int m = 0; m < t.size(); m++)  
		for (int n = 0; n < t.size(); n++) {
			if (m == i && n == j) continue;
			if (t[m][n] == Polje::Prazno) return false;
		}
	return true;
}

void StaviPrazno(Tabla &t) {
	for (auto &x : t)
		for (auto &y : x)
			y = Polje::Prazno;
}

Status Idi(Tabla &t, int &x, int &y, Smjerovi smjer) {
	int br1(x), br2(y);
	if (smjer == Smjerovi::Gore || smjer == Smjerovi::GoreDesno || smjer == Smjerovi:: GoreLijevo) {
		if (x == 0) throw std::out_of_range("Izlazak van igrace table");
		br1--;	
	}
	if (smjer == Smjerovi::Lijevo || smjer == ::Smjerovi::GoreLijevo || smjer == Smjerovi::DoljeLijevo) {
		if (y == 0) throw std::out_of_range("Izlazak van igrace table");
		br2--;	
	}
	if (smjer == Smjerovi::Dolje || smjer == Smjerovi::DoljeDesno || smjer == Smjerovi::DoljeLijevo) {
		if (x == t.size()-1) throw std::out_of_range("Izlazak van igrace table");
		br1++;
	}
	if (smjer == Smjerovi::Desno || smjer == Smjerovi::GoreDesno || smjer == Smjerovi::DoljeDesno) {
		if (y == t.size()) throw std::out_of_range("Izlazak van igrace table");
		br2++;
	}
	if (t[br1][br2] == Polje::BlokiranoPosjeceno || t[br1][br2] == Polje::BlokiranoPrazno || t[br1][br2] == Polje::BlokiranoMina)
		throw std::logic_error("Blokirano polje");
	t[x][y] = Polje::Posjeceno;
	x = br1; y = br2;
	Status rezultat(Status::NijeKraj);
	if (t[x][y] == Polje::Mina){
		StaviPrazno(t);
		rezultat = Status::KrajPoraz;
	}
	else if (DaLiJePobjeda(t,x,y)) rezultat = Status::KrajPobjeda;
	return rezultat;		
}

Status Idi(Tabla &t, int &x, int &y, int novi_x, int novi_y) {
	if (novi_x < 0 || novi_x >= t.size() || novi_y < 0 || novi_y >= t.size()) throw std::out_of_range("Izlazak van igrace table");
	if (t[novi_x][novi_y] == Polje::BlokiranoPosjeceno || t[novi_x][novi_y] == Polje::BlokiranoPrazno || t[novi_x][novi_y] == Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
	Status rezultat(Status::NijeKraj);
	t[x][y] = Polje::Posjeceno;
	x = novi_x; y = novi_y;
	if (t[x][y] == Polje::Mina) {
		StaviPrazno(t);
		rezultat = Status::KrajPoraz;
	}
	else if (DaLiJePobjeda(t,x,y)) rezultat = Status::KrajPobjeda;
	return rezultat;
}

void PrijaviGresku(KodoviGresaka greska) {
	if (greska == KodoviGresaka::PogresnaKomanda) std::cout << "Nerazumljiva komanda!" << std::endl; 
	else if (greska == KodoviGresaka::NedostajeParametar) std::cout << "Komanda trazi parametar koji nije naveden!" << std::endl;
	else if (greska == KodoviGresaka::SuvisanParametar) std::cout << "Zadan je suvisan parametar nakon komande!" << std::endl;
	else std::cout << "Parametar komande nije ispravan!" << std::endl;
}

bool ProvjeriPraznine() {
	char s;
	while (std::cin.peek() == ' ') std::cin.get(s);
	//	std::cin.get(s);
	if (std::cin.peek() != '\n') return false;
	return true;
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska) {	
	char s;
  	std::cin >> s;
 	if (s == 'P' && std::cin.peek() == '1') {
		std::cin >> s;
		if (std::cin.peek() != ' ' && std::cin.peek() != '\n') {
			greska = KodoviGresaka::PogresnaKomanda;
			std::cin.ignore(10000, '\n');
			return false;
		}
 			if (std::cin.peek() == ' ' && !ProvjeriPraznine()) {
 				std::cin >> s;
	 			if (s == 'G') {
	 				if (std::cin.peek() == 'D' && std::cin >> s) {
	 					if (std::cin.peek() == ' ' && !ProvjeriPraznine()) greska = KodoviGresaka::SuvisanParametar;
	 					else if (ProvjeriPraznine()) {
		 					smjer = Smjerovi::GoreDesno;
		 					komanda = Komande::PomjeriJednoMjesto;
		 					return true;
	 					}
	 				}
	 				else if (std::cin.peek() == 'L' && std::cin >> s) {
	 					if (std::cin.peek() == ' ' && !ProvjeriPraznine()) greska = KodoviGresaka::SuvisanParametar;
	 					else if (ProvjeriPraznine()) {
		 					smjer = Smjerovi::GoreLijevo;
		 					komanda = Komande::PomjeriJednoMjesto;
		 					return true;
	 					}
	 				}
	 				else if (std::cin.peek() == ' ' && !ProvjeriPraznine()) greska = KodoviGresaka::SuvisanParametar;
	 				else if (ProvjeriPraznine()) {
	 					smjer = Smjerovi::Gore;
	 					komanda = Komande::PomjeriJednoMjesto;
	 					return true;
	 				}
	 			}
	 			else if (s == 'D') {
	 				if (std::cin.peek() == 'o') {
	 					std::cin >> s;
	 					if (std::cin.peek() == 'D') {
	 						std::cin >> s;
	 						if (std::cin.peek() == ' ' && !ProvjeriPraznine()) greska = KodoviGresaka::SuvisanParametar;
		 					else if (ProvjeriPraznine()) {
			 					smjer = Smjerovi::DoljeDesno;
			 					komanda = Komande::PomjeriJednoMjesto;
		 						return true;
		 					}
	 					}
	 					else if(std::cin.peek() == 'L') {
	 						std::cin >> s;
	 						if (std::cin.peek() == ' ' && !ProvjeriPraznine()) greska = KodoviGresaka::SuvisanParametar;
		 					else if (ProvjeriPraznine()) {
			 					smjer = Smjerovi::DoljeLijevo;
			 					komanda = Komande::PomjeriJednoMjesto;
		 					return true;
	 					}
	 					}
	 					else if (std::cin.peek() == ' ' || std::cin.peek() == '\n') {
	 						if (!ProvjeriPraznine()) greska = KodoviGresaka::SuvisanParametar;
	 						else {
			 					smjer = Smjerovi::Dolje;
			 					komanda = Komande::PomjeriJednoMjesto;
		 						return true;
		 					}
	 					}
	 				}
	 				else if (std::cin.peek() == ' ' && !ProvjeriPraznine()) greska = KodoviGresaka::SuvisanParametar;
	 				else if (ProvjeriPraznine()) {
	 					smjer = Smjerovi::Desno;
	 					komanda = Komande::PomjeriJednoMjesto;
	 					return true;
	 				}
	 			}
	 			else if (s == 'L') {
	 				if (std::cin.peek() == ' ' && !ProvjeriPraznine()) {
	 						greska = KodoviGresaka::SuvisanParametar;
	 						return false;
	 				}
	 				else if (ProvjeriPraznine()) {
		 				smjer = Smjerovi::Lijevo;
		 				komanda = Komande::PomjeriJednoMjesto;
		 				return true;
	 				}
	 			}
	 			else {
	 				greska = KodoviGresaka::NeispravanParametar;
	 			}
 			}
 			else {
 				greska = KodoviGresaka::NedostajeParametar;
 			}
	}
	else if (s == 'P' && std::cin.peek() == '>') {
		std::cin >> s;
		if (std::cin.peek() != ' ' && std::cin.peek() != '\n') {
			greska = KodoviGresaka::PogresnaKomanda;
			std::cin.ignore(10000, '\n');
			return false;
		}
		if (ProvjeriPraznine()) 
			greska = KodoviGresaka::NedostajeParametar;
		else {
			int broj1, broj2;
			if (std::cin >> broj1 && std::cin.peek() == ' ') {
				if (ProvjeriPraznine()) greska = KodoviGresaka::NedostajeParametar;
				else if (!(std::cin >> broj2)) greska = KodoviGresaka::NeispravanParametar;
				else {
					if (std::cin.peek() != ' ' && std::cin.peek() != '\n') greska = KodoviGresaka::NeispravanParametar;
					else if (!ProvjeriPraznine()) greska = KodoviGresaka::SuvisanParametar;
					else {
						x = broj1;
						y = broj2;
						komanda = Komande::PomjeriDalje;
						return true;
					} //unos brojeva
				}
			}
			else {
				greska = KodoviGresaka::NeispravanParametar;
			}//neispravan prvi parametar
		}
	}
	else if (s == 'B' && (std::cin.peek() == ' ' || std::cin.peek() == '\n')) {
		int broj1, broj2;
		if (ProvjeriPraznine()) greska = KodoviGresaka::NedostajeParametar;
		else {
			if (!(std::cin >> broj1) || std::cin.peek() != ' ') greska = KodoviGresaka::NeispravanParametar;
			else {
				if (ProvjeriPraznine()) greska = KodoviGresaka::NedostajeParametar;
				else {
					if (!(std::cin >> broj2) || (std::cin.peek() != ' ' && std::cin.peek() != '\n')) greska = KodoviGresaka::NeispravanParametar;
					else {
						if (!ProvjeriPraznine()) greska = KodoviGresaka::SuvisanParametar;
						else {
							x = broj1;
							y = broj2;
							komanda = Komande::Blokiraj;
							return true;
						}
					}
				}
				
			}
		}
	}
	else if (s == 'D' && (std::cin.peek() == ' ' || std::cin.peek() == '\n')) {
		int broj1, broj2;
		if (ProvjeriPraznine()) greska = KodoviGresaka::NedostajeParametar;
		else {
			if (!(std::cin >> broj1) || std::cin.peek() != ' ') greska = KodoviGresaka::NeispravanParametar;
			else {
				if (ProvjeriPraznine()) greska = KodoviGresaka::NedostajeParametar;
				else {
					if (!(std::cin >> broj2) || (std::cin.peek() != ' ' && std::cin.peek() != '\n')) greska = KodoviGresaka::NeispravanParametar;
					else {
						if (!ProvjeriPraznine()) greska = KodoviGresaka::SuvisanParametar;
						else {
							x = broj1;
							y = broj2;
							komanda = Komande::Deblokiraj;
							return true;
						}
					}
				}
				
			}
		}
	}
	else if (s == 'P' && std::cin.peek() == 'O') {
		std::cin >> s;
		if (std::cin.peek() != ' ' && std::cin.peek() != '\n') {
			greska = KodoviGresaka::PogresnaKomanda;
			std::cin.ignore(10000, '\n');
			return false;
		}
		if (!ProvjeriPraznine()) greska = KodoviGresaka::SuvisanParametar;
		else {
			komanda = Komande::PrikaziOkolinu;
			return true;
		}
	}
	else if (s == 'Z' && (std::cin.peek() == ' ' || std::cin.peek() == '\n')) {
		if (!ProvjeriPraznine()) greska = KodoviGresaka::SuvisanParametar;
		else {
			komanda = Komande::ZavrsiIgru;
			return true;
		}
	}
	else if (s == 'K' && (std::cin.peek() == ' ' || std::cin.peek() == '\n')) {
		if (!ProvjeriPraznine()) greska = KodoviGresaka::SuvisanParametar;
		else {
			komanda = Komande::KreirajIgru;
			return true;
		}
	}
	else greska = KodoviGresaka::PogresnaKomanda;
	std::cin.clear();
	std::cin.ignore(10000, '\n');
	return false;
}

void IzvrsiKomandu(Komande komanda, Tabla &t, int &x, int &y, Smjerovi smjer = Smjerovi::Gore, int novi_x = 0, int novi_y = 0) {
	if (komanda == Komande::KreirajIgru) {
		int n(0);
		do {
			std::cout << "Unesite broj polja: ";
			if (!(std::cin >> n) || n <= 0) {
				std::cout << "Greska, unesite ponovo!" << std::endl;
				std::cin.clear(); std::cin.ignore(1000, '\n');
			}
		} while(n <= 0);
		std::cout << "Unesite pozicije mina: ";
		std::vector<std::vector<int>> mine;
		char s('\n');
		while (s != '.') {
			int br1, br2;
			do {
				if (std::cin >> s && (s == '.' || (s == '(' && std::cin >> br1 >> s && br1 >=0 && br1 < n && s == ',' && std::cin >> br2 && br2 >=0 && br2 < n && std::cin >> s && s == ')')) && ProvjeriPraznine()) break;
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				std::cout << "Greska, unesite ponovo!" << std::endl;
			} while (true);
			if (s == '.') break;
			mine.push_back({br1, br2});
		}
		t = KreirajIgru(n, mine);
		x = 0; y = 0;
	}
	else if (komanda == Komande::PrikaziOkolinu) {
		for (auto m : PrikaziOkolinu(t, x, y)) {
			for (auto n : m) std::cout << n << " ";
			std::cout << std::endl;
		}
	}
	else if (komanda == Komande::ZavrsiIgru) {
		t = KreirajIgru(t.size(), {});
		throw std::runtime_error("Dovidjenja!");
	}
	else if (komanda == Komande::Blokiraj) {
		BlokirajPolje(t, novi_x, novi_y);
	}
	else if (komanda == Komande::Deblokiraj) {
		DeblokirajPolje(t, novi_x, novi_y);
	}
	else if (komanda == Komande::PomjeriJednoMjesto || komanda == Komande::PomjeriDalje) {
		Status pozicija;
		if (komanda == Komande::PomjeriJednoMjesto) pozicija = Idi(t, x, y, smjer);
		else pozicija = Idi(t, x, y, novi_x, novi_y);
		std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")" << std::endl;
		if (pozicija == Status::KrajPobjeda) {
			std::cout << "Bravo, obrisali ste sva sigurna polja" << std::endl;
			throw std::runtime_error("Igra zavrsena");
		}
		else if (pozicija == Status::KrajPoraz) {
			std::cout << "Nagazili ste na minu" << std::endl;
			throw std::runtime_error("Igra zavrsena");
		}
	}
}

int main ()
{
	try {
		int x, y, novi_x, novi_y;
		Komande komanda;
		Tabla t;
		Smjerovi smjer;
		KodoviGresaka greska;
		while (true) {
			try {
				std::cout << "Unesite komandu: ";
				if (UnosKomande(komanda, smjer, novi_x, novi_y, greska)) IzvrsiKomandu(komanda, t, x, y, smjer, novi_x, novi_y);
				else PrijaviGresku(greska);
			}
			catch (std::domain_error izuzetak) {
				std::cout << izuzetak.what() << std::endl;
			}
			catch (std::out_of_range izuzetak) {
				std::cout << izuzetak.what() << std::endl;
			}
			catch (std::logic_error izuzetak) {
				std::cout << izuzetak.what() << std::endl;
			}
		}
	}
	catch (std::runtime_error izuzetak) {
		std::cout << izuzetak.what();
	}
//	std::cout << "Dovidjenja!";
	return 0;
}
/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>

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

bool DaLiJeIspravnaPozicija(const Tabla &polja, int x, int y) {
	if (x < 0 || x >= polja.size() || y < 0 || y >= polja.size()) return false;
	return true;
}

int ProvjeriOkolinu(const Tabla &polja, int n, int x, int y, bool istinitost) { // n je velicina table
	int brojac(0);
	for (int i = -1; i <= 1; i++) {
		if (x + i < 0 || x + i > n) continue;
		for (int j = -1; j <= 1; j++) {
			if (y + i < 0 || y + i > n) continue;
				if (polja[x+i][y+j] == Polje::Mina && istinitost == false) brojac++;
		}
	}
	return brojac;
}

bool DaLiJePobijedio(const Tabla &polja) {
	for (int i = 0; i < polja.size(); i++) {
		for (int j = 0; j < polja[0].size(); j++) {
			if (polja[i][j] != Polje::Mina && polja[i][j] == Polje::Prazno)
				return false;
		}
	}
	return true;
}

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine) {
	Tabla t(n, std::vector<Polje>(n, Polje::Prazno));
	for (int i = 0; i < mine.size(); i++) {
		if (mine[i].size() != 2) throw std::domain_error("Ilegalan format zadavanja mina");
		if (mine[i][0] > n || mine[i][0] < 0 || mine[i][1] > n || mine[i][1] < 0) throw std::domain_error("Ilegalne pozicije mina");
		t[mine[i][0]][mine[i][1]] = Polje::Mina;
	}
	return t;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y) {
	std::vector<std::vector<int>> Prikaz(3, std::vector<int>(3));
	int red(0), kolona(0);
	bool istinitost(true);
	if (x < 0 || x >= polja.size() || y < 0 || y >= polja.size()) throw std::domain_error("Polje (x,y) ne postoji");
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (i == 0 && j == 0) istinitost = true;
			Prikaz[red][kolona] = ProvjeriOkolinu(polja, polja.size()-1, x+i, y+j, istinitost);
			kolona++;
			istinitost = false;
		}
		red++; kolona = 0;
	}
	return Prikaz;
}

void BlokirajPolje(Tabla &polja, int x, int y) {
	if (x < 0 || x >= polja.size() || y < 0 || y >= polja.size()) throw std::domain_error("Polje (x,y) ne postoji");
	if (polja[x][y] == Polje::Prazno) polja[x][y] = Polje::BlokiranoPrazno;
	else if (polja[x][y] == Polje::Posjeceno) polja[x][y] = Polje::BlokiranoPosjeceno;
	else if (polja[x][y] == Polje::Mina) polja[x][y] = Polje::BlokiranoMina;
}

void DeblokirajPolje(Tabla &polja, int x, int y) {
	if (x < 0 || x >= polja.size() || y < 0 || y >= polja.size()) throw std::domain_error("Polje (x,y) ne postoji");
	if (polja[x][y] == Polje::BlokiranoPrazno) polja[x][y] = Polje::Prazno;
	else if (polja[x][y] == Polje::BlokiranoPosjeceno) polja[x][y] = Polje::Posjeceno;
	else if (polja[x][y] == Polje::BlokiranoMina) polja[x][y] = Polje::Mina;
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer) {
	if (smjer == Smjerovi::GoreLijevo) {
		if (DaLiJeIspravnaPozicija(polja, x-1, y-1) == true) {
			polja[x][y] = Polje::Posjeceno;
			x -= 1; y -= 1;
			if (polja[x][y] == Polje::BlokiranoPrazno || polja[x][y] == Polje::BlokiranoPosjeceno || polja[x][y] == Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		}
		else throw std::out_of_range("Izlazak van igrace table");
	}
	else if (smjer == Smjerovi::Gore) {
		if (DaLiJeIspravnaPozicija(polja, x-1, y) == true) {
			polja[x][y] = Polje::Posjeceno;
			x -= 1;
			if (polja[x][y] == Polje::BlokiranoPrazno || polja[x][y] == Polje::BlokiranoPosjeceno || polja[x][y] == Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		}
		else throw std::out_of_range("Izlazak van igrace table");
	}
	else if (smjer == Smjerovi::GoreDesno) {
		if (DaLiJeIspravnaPozicija(polja, x-1, y+1) == true) {
			polja[x][y] = Polje::Posjeceno;
			x -= 1; y += 1;
			if (polja[x][y] == Polje::BlokiranoPrazno || polja[x][y] == Polje::BlokiranoPosjeceno || polja[x][y] == Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		}
		else throw std::out_of_range("Izlazak van igrace table");
	}
	else if (smjer == Smjerovi::Desno) {
		if (DaLiJeIspravnaPozicija(polja, x, y+1) == true) {
			polja[x][y] = Polje::Posjeceno;
			y += 1;
			if (polja[x][y] == Polje::BlokiranoPrazno || polja[x][y] == Polje::BlokiranoPosjeceno || polja[x][y] == Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		}
		else throw std::out_of_range("Izlazak van igrace table");
	}
	else if (smjer == Smjerovi::DoljeDesno) {
		if (DaLiJeIspravnaPozicija(polja, x+1, y+1) == true) {
			polja[x][y] = Polje::Posjeceno;
			x += 1; y += 1;
			if (polja[x][y] == Polje::BlokiranoPrazno || polja[x][y] == Polje::BlokiranoPosjeceno || polja[x][y] == Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		}
		else throw std::out_of_range("Izlazak van igrace table");
	}
	else if (smjer == Smjerovi::Dolje) {
		if (DaLiJeIspravnaPozicija(polja, x+1, y) == true) {
			polja[x][y] = Polje::Posjeceno;
			x += 1;
			if (polja[x][y] == Polje::BlokiranoPrazno || polja[x][y] == Polje::BlokiranoPosjeceno || polja[x][y] == Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		}
		else throw std::out_of_range("Izlazak van igrace table");
	}
	else if (smjer == Smjerovi::DoljeLijevo) {
		if (DaLiJeIspravnaPozicija(polja, x+1, y-1) == true) {
			polja[x][y] = Polje::Posjeceno;
			x += 1; y -= 1;
			if (polja[x][y] == Polje::BlokiranoPrazno || polja[x][y] == Polje::BlokiranoPosjeceno || polja[x][y] == Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		}
		else throw std::out_of_range("Izlazak van igrace table");
	}  
	else if (smjer == Smjerovi::Lijevo) {
		if (DaLiJeIspravnaPozicija(polja, x, y-1) == true) {
			polja[x][y] = Polje::Posjeceno;
			y -= 1;
			if (polja[x][y] == Polje::BlokiranoPrazno || polja[x][y] == Polje::BlokiranoPosjeceno || polja[x][y] == Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		}
		else throw std::out_of_range("Izlazak van igrace table");
	}
	
	if (polja[x][y] == Polje::Mina) {
		for (int i = 0; i < polja.size(); i++) 
			for (int j = 0; j < polja[0].size(); j++) 
				polja[i][j] = Polje::Prazno;
		return Status::KrajPoraz;
	}
	else if (DaLiJePobijedio(polja) == true) 
		return Status::KrajPobjeda;
	else
		return Status::NijeKraj;
	
}
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y) {
	if (DaLiJeIspravnaPozicija(polja, novi_x, novi_y) == true) {
		polja[x][y] = Polje::Posjeceno;
		x = novi_x, y = novi_y;
		if (polja[x][y] == Polje::BlokiranoPrazno || polja[x][y] == Polje::BlokiranoPosjeceno || polja[x][y] == Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
	}
	else throw std::out_of_range("Izlazak van igrace table");
	
	if (polja[x][y] == Polje::Mina) {
		for (int i = 0; i < polja.size(); i++) 
			for (int j = 0; j < polja[0].size(); j++) 
				polja[i][j] = Polje::Prazno;
		return Status::KrajPoraz;
	}
	else if (DaLiJePobijedio(polja) == true) 
		return Status::KrajPobjeda;
	else
		return Status::NijeKraj;
}

void PrijaviGresku (KodoviGresaka kod_greske) {
    if (kod_greske == KodoviGresaka::PogresnaKomanda) std::cout << "Nerazumljiva komanda!" << std::endl;
    else if (kod_greske == KodoviGresaka::NedostajeParametar) std::cout << "Komanda trazi parametar koji nije naveden!" << std::endl;
    else if (kod_greske == KodoviGresaka::NeispravanParametar) std::cout << "Parametar komande nije ispravan!" << std::endl;
    else if (kod_greske == KodoviGresaka::SuvisanParametar) std::cout << "Zadan je suvisan parametar nakon komande!" << std::endl;
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska) {
	std::string unos;
	int pom(0);
	if (unos[0] == ' ') {
		while (unos[pom] == ' ')
			pom++;
	}
	if (unos[pom] == 'P') {
		if (unos.length() == 1 || pom == unos.length() - 1) {
			greska = KodoviGresaka::NedostajeParametar;
			return false;
		}
		if (unos[pom+1] == '1') {
			komanda = Komande::PomjeriJednoMjesto;
			int pom2 = pom + 2;
			if (unos[pom2] == ' ') {
				while (unos[pom2] == ' ') {
					if (unos[pom2] != ' ') {
						greska = KodoviGresaka::NeispravanParametar;
						return false;
					}
					pom2++;
				}
			}
			if (unos[pom2] == 'G' && unos[pom2+1] == 'L' && (pom2+1 == unos.size() - 1 || unos[pom2+2] == ' ')) {
				if (unos[pom2+2] == ' ') {
					int pom3 = pom2 + 2;
					while (pom3 < unos.size()) {
						if (unos[pom3] != ' ') {
							greska = KodoviGresaka::NeispravanParametar;
							return false;
						}
						pom3++;
					}
				}
				smjer = Smjerovi::GoreLijevo;
				return true;
			}
			else if (unos[pom2] == 'G' && (pom2 == unos.size() - 1 || unos[pom2+1] == ' ')) {
				if (unos[pom2+1] == ' ') {
					int pom3 = pom2 + 1;
					while (pom3 < unos.size()) {
						if (unos[pom3] != ' ') {
							greska = KodoviGresaka::NeispravanParametar;
							return false;
						}
						pom3++;
					}
				}
				smjer = Smjerovi::Gore;
				return true;
			}
			else if (unos[pom2] == 'G' && unos[pom2+1] == 'D' && (pom2+1 == unos.size() - 1 || unos[pom2+2] == ' ')) {
				if (unos[pom2+2] == ' ') {
					int pom3 = pom2 + 2;
					while (pom3 < unos.size()) {
						if (unos[pom3] != ' ') {
							greska = KodoviGresaka::NeispravanParametar;
							return false;
						}
						pom3++;
					}
				}
				smjer = Smjerovi::GoreDesno;
				return true;
			}
			else if (unos[pom2] == 'D' && (pom2 == unos.size() - 1 || unos[pom2+1] == ' ')) {
				if (unos[pom2+1] == ' ') {
					int pom3 = pom2 + 1;
					while (pom3 < unos.size()) {
						if (unos[pom3] != ' ') {
							greska = KodoviGresaka::NeispravanParametar;
							return false;
						}
						pom3++;
					}
				}
				smjer = Smjerovi::Desno;
				return true;
			}
			else if (unos[pom2] == 'D' && unos[pom2+1] == 'o' && unos[pom2+2] == 'D' && (pom2+2 == unos.size() - 1 || unos[pom2+3] == ' ')) {
				if (unos[pom2+3] == ' ') {
					int pom3 = pom2 + 3;
					while (pom3 < unos.size()) {
						if (unos[pom3] != ' ') {
							greska = KodoviGresaka::NeispravanParametar;
							return false;
						}
						pom3++;
					}
				}
				smjer = Smjerovi::DoljeDesno;
				return true;
			}
			else if (unos[pom2] == 'D' && unos[pom2+1] == 'o' && (pom2+1 == unos.size() - 1 || unos[pom2+2] == ' ')) {
				if (unos[pom2+2] == ' ') {
					int pom3 = pom2 + 2;
					while (pom3 < unos.size()) {
						if (unos[pom3] != ' ') {
							greska = KodoviGresaka::NeispravanParametar;
							return false;
						}
						pom3++;
					}
				}
				smjer = Smjerovi::Dolje;
				return true;
			}
			else if (unos[pom2] == 'D' && unos[pom2+1] == 'o' && unos[pom2+2] == 'L' && (pom2+2 == unos.size() - 1 || unos[pom2+3] == ' ')) {
				if (unos[pom2+3] == ' ') {
					int pom3 = pom2 + 3;
					while (pom3 < unos.size()) {
						if (unos[pom3] != ' ') {
							greska = KodoviGresaka::NeispravanParametar;
							return false;
						}
						pom3++;
					}
				}
				smjer = Smjerovi::DoljeLijevo;
				return true;
			}
			else if (unos[pom2] == 'L' && (pom2 == unos.size() - 1 || unos[pom2+1] == ' ')) {
				if (unos[pom2+1] == ' ') {
					int pom3 = pom2 + 1;
					while (pom3 < unos.size()) {
						if (unos[pom3] != ' ') {
							greska = KodoviGresaka::NeispravanParametar;
							return false;
						}
						pom3++;
					}
				}
				smjer = Smjerovi::Lijevo;
				return true;
			}
			else {
				greska = KodoviGresaka::NeispravanParametar;
				return false;
			}
		} // ovdje je za 1
		else if (unos[pom+1] == '>') {
			int pom2 = pom + 2;
			if (unos[pom2] == ' ') {
				while (unos[pom2] == ' ') {
					if (unos[pom2] != ' ') {
						greska = KodoviGresaka::NeispravanParametar;
						return false;
					}
					pom2++;
				}
			}
			if (unos[pom2] >= '0' && unos[pom2] <= '9') {
				int broj1(0), broj2(0), brojac1(0), brojac2(0);
				int pom3(pom2);
				while (unos[pom2] >= '0' && unos[pom2] <= '9') {
					brojac1++;
					pom2++;
				}
				if (unos[pom2] == ' ') {
					while (unos[pom2] == ' ')
						pom2++;
				}
				else {
					greska = KodoviGresaka::NeispravanParametar;
					return false;
				}
				int pom4(pom2);
				if (unos[pom2] >= '0' && unos[pom2] <= '9') {
					while (unos[pom2] >= '0' && unos[pom2] <= '9') {
						brojac2++;
						pom2++;
					} 
				}
				else {
					greska = KodoviGresaka::NeispravanParametar;
					return false;
				}
				for (int i = brojac1 - 1; i >= 0; i--) {
					broj1 = broj1 + (unos[pom3] - '0') * pow(10, i);
					pom3++;
				}
				for (int i = brojac2 - 1; i >= 0; i--) {
					broj2 = broj2 + (unos[pom4] - '0') * pow(10, i);
					pom4++;
				}
				komanda = Komande::PomjeriDalje;
				return true;
			}
		}
		else if (unos[pom+1] == 'O') {
			int pom2 = pom+1;
			while (pom2 < unos.length()) {
				if (unos[pom2] != ' ') {
					greska = KodoviGresaka::SuvisanParametar;
					return false;
				}
				pom2++;
			}
			komanda = Komande::PrikaziOkolinu;
			return true;
		}
		else {
			greska = KodoviGresaka::PogresnaKomanda;
			return false;
		}
	} // ovdje je za P
	else if (unos[pom] == 'B') {
		int pom2 = pom + 1;
		if (unos[pom2] == ' ') {
			while (unos[pom2] == ' ') 
				pom2++;
		}
		if (unos[pom2] >= '0' && unos[pom2] <= '9') {
			int broj1(0), broj2(0), brojac1(0), brojac2(0);
			int pom3(pom2);
			while (unos[pom2] >= '0' && unos[pom2] <= '9') {
				brojac1++;
				pom2++;
			}
			if (unos[pom2] == ' ') {
				while (unos[pom2] == ' ')
					pom2++;
			}
			else {
				greska = KodoviGresaka::SuvisanParametar;
				return false;
			}
			int pom4(pom2);
			if (unos[pom2] >= '0' && unos[pom2] <= '9') {
				while (unos[pom2] >= '0' && unos[pom2] <= '9') {
					brojac2++;
					pom2++;
				} 
			}
			else {
				greska = KodoviGresaka::SuvisanParametar;
				return false;
			}
			if (unos[pom2] == ' ') {
				while (pom2 < unos.length()) {
					if (unos[pom2] != ' ') {
						greska = KodoviGresaka::SuvisanParametar;
						return false;
					} 
				}
				pom2++;
			}
			for (int i = brojac1 - 1; i >= 0; i--) {
				broj1 = broj1 + (unos[pom3] - '0') * pow(10, i);
				pom3++;
			}
			for (int i = brojac2 - 1; i >= 0; i--) {
				broj2 = broj2 + (unos[pom4] - '0') * pow(10, i);
				pom4++;
			}
			komanda = Komande::Blokiraj;
			return true;
		}
		else {
			greska = KodoviGresaka::NeispravanParametar;
			return false;
		}
	}
	else if (unos[pom] == 'D') {
		int pom2 = pom + 1;
		if (unos[pom2] == ' ') {
			while (unos[pom2] == ' ')
				pom2++;
		}
		if (unos[pom2] >= '0' && unos[pom2] <= '9') {
			int broj1(0), broj2(0), brojac1(0), brojac2(0);
			int pom3(pom2);
			while (unos[pom2] >= '0' && unos[pom2] <= '9') {
				brojac1++;
				pom2++;
			}
			if (unos[pom2] == ' ') {
				while (unos[pom2] == ' ')
					pom2++;
			}
			else {
				greska = KodoviGresaka::SuvisanParametar;
				return false;
			}
			int pom4(pom2);
			if (unos[pom2] >= '0' && unos[pom2] <= '9') {
				while (unos[pom2] >= '0' && unos[pom2] <= '9') {
					brojac2++;
					pom2++;
				} 
			}
			else {
				greska = KodoviGresaka::SuvisanParametar;
				return false;
			}
			if (unos[pom2] == ' ') {
				while (pom2 < unos.length()) {
					if (unos[pom2] != ' ') {
						greska = KodoviGresaka::SuvisanParametar;
						return false;
					} 
				}
				pom2++;
			}
			for (int i = brojac1 - 1; i >= 0; i--) {
				broj1 = broj1 + (unos[pom3] - '0') * pow(10, i);
				pom3++;
			}
			for (int i = brojac2 - 1; i >= 0; i--) {
				broj2 = broj2 + (unos[pom4] - '0') * pow(10, i);
				pom4++;
			}
			komanda = Komande::Deblokiraj;
			return true;
		}
		else {
			greska = KodoviGresaka::NeispravanParametar;
			return false;
		}
	}
	else if (unos[pom] == 'Z') {
		if (unos[pom+1] == ' ') {
			int pom2 = pom + 1;
			while (pom2 < unos.length()) {
				if (unos[pom2] != ' ') {
					greska = KodoviGresaka::SuvisanParametar;
					return false;
				}
				pom2++;
			}
		}
		komanda = Komande::ZavrsiIgru;
		return true;
	}
	else if (unos[pom] == 'K') {
		if (unos[pom+1] == ' ') {
			int pom2 = pom + 1;
			while (pom2 < unos.length()) {
				if (unos[pom2] != ' ') {
					greska = KodoviGresaka::SuvisanParametar;
					return false;
				}
				pom2++;
			}
		}
		komanda = Komande::KreirajIgru;
		return true;
	}
	else {
		greska = KodoviGresaka::PogresnaKomanda;
		return false;
	}
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0) {
	if (komanda == Komande::PomjeriJednoMjesto) Idi(polja, x, y, p_smjer);
	else if (komanda == Komande::PomjeriDalje) Idi(polja, x, y, p_x, p_y);
	else if (komanda == Komande::Blokiraj) BlokirajPolje(polja, p_x, p_y);
	else if (komanda == Komande::Deblokiraj) DeblokirajPolje(polja, p_x, p_y);
	else if (komanda == Komande::PrikaziOkolinu) PrikaziOkolinu(polja, p_x, p_y);
	else if (komanda == Komande::ZavrsiIgru) 
}

int main ()
{
	return 0;
}
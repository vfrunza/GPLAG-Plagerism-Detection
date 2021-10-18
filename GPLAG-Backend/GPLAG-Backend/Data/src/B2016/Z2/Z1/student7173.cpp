/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/

#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::string;

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
	PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu,
		ZavrsiIgru, KreirajIgru
};

// int BROJPRAZNIH(0);

typedef vector<vector<Polje>> Tabla;
typedef vector<vector<int>> IntMat;

void print(const IntMat &mat) {
	for (auto v : mat) {
		for (int n : v) {
			cout << n << " ";
		}
		cout << endl;
	}
}


void printMine(const Tabla &polja) {
	for (auto v : polja) {
		for (auto p : v) {
			if (p == Polje::Prazno) {
				cout << 0;
			} else {
				cout << 1;
			}
			cout << " ";
		}
		cout << endl;
	}
}


// Ispituje da li n pripada opsegu (0, len - 1)
bool NInRange(int n, int len) {
	return (n >= 0 && n < len);
}


Tabla KreirajIgru(int n, const IntMat &mine)
{
	// Ispitati ispravnost vektora mina:
	for (vector<int> v : mine) {
		if (v.size() != 2) {
			throw std::domain_error("Ilegalan format zadavanja mina");
		} else {
			if (!NInRange(v[0], n) || !NInRange(v[1], n)) {
				throw std::domain_error("Ilegalne pozicije mina");
			}
		}
	}
	
	// BROJPRAZNIH = n*n;
	Tabla tab(n, vector<Polje> (n, Polje::Prazno));
	for (vector<int> v : mine) {
		// BROJPRAZNIH--;
		tab[v[0]][v[1]] = Polje::Mina;
	}
	
	return tab;
}


// Vraca broj mina koje se nalaze u neposrednom susjedstvu polja (x, y)
// TODO: polje ne mora pripadati tabli?
int Br_mina(const Tabla &polja, int x, int y)
{
	//cout << x << " " << y << endl;
	int broj(0), len(polja.size());
	for (int i = -1; i < 2; i++) {
		if (NInRange(x + i, len)) {
			for (int j = -1; j < 2; j++) {
				if (NInRange(y + j, len) && (i || j)) { // && (i != 0 || j != 0)
					Polje p = polja[x + i][y + j];
					if (p == Polje::Mina || p == Polje::BlokiranoMina) broj++;
				}
			}
		}
	}
	//cout << broj << endl << endl;
	return broj;
}


IntMat PrikaziOkolinu(const Tabla &polja, int x, int y)
{
	try {
		polja.at(x).at(y); // Baca izuzetak ako polje ne postoji
		
		IntMat broj_mina(3, vector<int>(3));
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				broj_mina[i][j] = Br_mina(polja, x - 1 + i, y - 1 + j);
			}
		}
		
		return broj_mina;
	} catch (std::out_of_range) {
		throw std::domain_error("Polje (x, y) ne postoji");
	}
}


void BlokirajPolje(Tabla &polja, int x, int y) {
	try {
		Polje &p(polja.at(x).at(y)); // Baca izuzetak ako polje ne postoji
		if (int(p) < 3) p = Polje(int(p) + 3);
	} catch (std::out_of_range &e) {
		throw std::domain_error("Polje (x, y) ne postoji");
	} 
}

void DeblokirajPolje(Tabla &polja, int x, int y) {
	try {
		Polje &p(polja.at(x).at(y)); // Baca izuzetak ako polje ne postoji
		if (int(p) > 2) p = Polje(int(p) - 3);
	} catch (std::out_of_range &e) {
		throw std::domain_error("Polje (x, y) ne postoji");
	}
}


void OcistiTablu(Tabla &polja) {
	// BROJPRAZNIH = 0;
	for (auto red : polja) {
		for (Polje &p : red) {
			// BROJPRAZNIH++;
			p = Polje::Prazno;
		}
	}
}


int BrojPraznih(const Tabla &polja) { // Moze li globalna var?
	int rez(0);
	for (auto red : polja) {
		for (auto p : red) {
			if (p == Polje::Prazno || p == Polje::BlokiranoPrazno) rez++;
		}
	}
	
	return rez;
}


Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y)
{
	try {
		Polje p = polja.at(novi_x).at(novi_y); // Baca izuzetak ako polje ne postoji
		
		if (int(p) > 2) {
			throw std::logic_error("Blokirano polje");
		} else if (p == Polje::Mina) {
			OcistiTablu(polja); // Ne moramo oznaciti prethodno polje kao Posjeceno
			return Status::KrajPoraz;
		} else {
			// "Pomjeramo" igraca
			polja[x][y] = Polje::Posjeceno;
			x = novi_x;
			y = novi_y;
			
			if (BrojPraznih(polja) == 1 && p == Polje::Prazno) {
				return Status::KrajPobjeda;
			} else {
				return Status::NijeKraj;
			}
		}
	} catch (std::out_of_range &e) {
		throw std::out_of_range("Izlazak van igrace table");
	}	
}


Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer)
{
	int x2(x), y2(y);
	if (int(smjer) < 3)	x2--; else if ((int(smjer) + 1) % 8 > 4) x2++;
	if ((int(smjer) + 7) % 8 > 4) y2--; else if ((int(smjer) + 3) % 8 > 4) y2++;
	
	//cout << endl << x2 << " A " << y2 << endl;

	return Idi(polja, x, y, x2, y2);
}


void PrijaviGresku(KodoviGresaka kod)
{
	string tekst;
	switch (kod) {
		case KodoviGresaka::PogresnaKomanda :
			tekst = "Nerazumljiva komanda!";
			break;
		case KodoviGresaka::NedostajeParametar :
			tekst = "Komanda trazi parametar koji nije naveden!";
			break;
		case KodoviGresaka::NeispravanParametar :
			tekst = "Parametar komande nije ispravan!";
			break;
		case KodoviGresaka::SuvisanParametar :
			tekst = "Zadan je suvisan parametar nakon komande!";
			// break;
	}
	
	cout << tekst;
}


void WhiteGuilt(const string &str, int &i) { // Pomjera indeks iza razmaka (tabulator?)
	while (i < str.length() && str[i] == ' ') i++;
}

void RijesiRazmake(string &str)  // Skida razmake sa pocetka i kraja
{
	
	int i(str.length() - 1);
	while (0 <= i && str[i] == ' ') i--;
	str.resize(i + 1); // Duzina stringa ce biti i + 1
	int j(0);
	WhiteGuilt(str, j);
	for (int k = 0; k < str.length() - j; k++) {
		str[k] = str[k + j];
	}
	str.resize(str.length() - j);
}


bool ZiliK (string &unos, Komande &komanda, KodoviGresaka &greska) 
{
	if (unos.length() == 1) {
		if (unos[0] == 'Z') {
			komanda = Komande::ZavrsiIgru;
		} else { // unos[0] == 'K'
			komanda = Komande::KreirajIgru;
		}
		return true;
	} else { // Slijedi ne-razmak
		greska = KodoviGresaka::SuvisanParametar;
		return false;
	}
}

bool P1G(string &unos, Komande &komanda, Smjerovi &smjer, 
	KodoviGresaka &greska, int &i)
{
	bool rez(true);
	int len(unos.length());
	if (++i == len) {
		smjer = Smjerovi::Gore;
	} else if (unos[i] == 'D') {
		if (++i == len) {
			smjer = Smjerovi::GoreDesno;
		} else {
			rez = false;
		}
	} else if (unos[i] == 'L') {
		if (++i == len) {
			smjer = Smjerovi::GoreLijevo;
		} else {
			rez = false;
		}
	} else {
		rez = false;
	}
	
	if (rez) {
		komanda = Komande::PomjeriJednoMjesto;
	} else {
		greska = KodoviGresaka::NeispravanParametar;
	}
	return rez;
}

bool P1D(string &unos, Komande &komanda, Smjerovi &smjer, 
	KodoviGresaka &greska, int &i)
{
	bool rez(true);
	int len(unos.length());
	if (++i == len) {
		smjer = Smjerovi::Desno;
	} else if (unos[i] == 'o') {
		if (++i == len) {
			smjer = Smjerovi::Dolje;
		} else if (unos[i] == 'D') {
			if (++i == len) {
				smjer = Smjerovi::DoljeDesno;
			} else {
				rez = false;
			}
		} else if (unos[i] == 'L') {
			if (++i == len) {
				smjer = Smjerovi::DoljeLijevo;
			} else {
				rez = false;
			}
		} else {
			rez = false;
		}
	} else {
		greska = KodoviGresaka::NeispravanParametar;
		rez = false;
	}
	
	if (rez) {
		komanda = Komande::PomjeriJednoMjesto;
	} else {
		greska = KodoviGresaka::NeispravanParametar;
	}
	return rez;
}

bool P1L(string &unos, Komande &komanda, Smjerovi &smjer, 
	KodoviGresaka &greska, int &i)
{
	if (i == unos.length() - 1) {
		komanda = Komande::PomjeriJednoMjesto;
		smjer = Smjerovi::Lijevo;
		return true;
	} else {
		greska = KodoviGresaka::NeispravanParametar;
		return false;
	}
}

bool P1(string &unos, Komande &komanda, Smjerovi &smjer, 
	KodoviGresaka &greska, int &i)
{
	int len(unos.length());
	if (len == 2) {
		greska = KodoviGresaka::NedostajeParametar;
		return false;
	} else {
		WhiteGuilt(unos, ++i);
		if (unos[i] == 'G') {
			return P1G(unos, komanda, smjer, greska, i);
		} else if (unos[i] == 'D') {
			return P1D(unos, komanda, smjer, greska, i);
		} else if (unos[i] == 'L') {
			return P1L(unos, komanda, smjer, greska, i);
		} else {
			greska = KodoviGresaka::NeispravanParametar;
			return false;
		}
	}
}

// Vraca true ako je izdvojen broj
// Nakon zavrsetka pokazivac ce pokazivati na prvo mjesto iza broja
bool IzdvojiBroj(const string &unos, KodoviGresaka &greska, int &i, int &n)
{
	WhiteGuilt(unos, i);
	if (i >= unos.length()) { // >= za svaki slucaj
		greska = KodoviGresaka::NedostajeParametar;
		return false;
	}
	while (i < unos.length() && 47 < unos[i] && unos[i] < 58) {
		n *= 10;
		n += unos[i++] - 48;
	}
	if (i == unos.length() || unos[i] == ' ') return true;
	greska = KodoviGresaka::NeispravanParametar;
	return false;
}

bool PVece(const string &unos, Komande &komanda, KodoviGresaka &greska, int &x, 
	int &y, int &i)
{
	if (unos.length() == 2) {
		greska = KodoviGresaka::NedostajeParametar;
	} else {
		if (IzdvojiBroj(unos, greska, ++i, x)) {
			if (IzdvojiBroj(unos, greska, ++i, y)) {
				if (unos[i] == ' ') {
					greska = KodoviGresaka::NeispravanParametar;
				} else {
					komanda = Komande::PomjeriDalje;
					return true;
				}
			}
		}
	} 

	return false;
}

bool PO(const string &unos, Komande &komanda, KodoviGresaka &greska, int &i)
{
	if (unos.length() == 2) {
		komanda = Komande::PrikaziOkolinu;
		return true;
	} else { // Naisli smo na ne-razmak
		greska = KodoviGresaka::SuvisanParametar;
		return false;
	}
}

bool B(const string &unos, Komande &komanda, KodoviGresaka &greska, int &x, 
	int &y, int &i)
{
	if (unos.length() == 1) {
		greska = KodoviGresaka::NedostajeParametar;
	} else {
		if (IzdvojiBroj(unos, greska, ++i, x)) {
			if (IzdvojiBroj(unos, greska, ++i, y)) {
				if (unos[i] == ' ') {
					greska = KodoviGresaka::NeispravanParametar;
				} else {
					komanda = Komande::Blokiraj;
					return true;
				}
			}
		}
	} 

	return false;
}

bool D(const string &unos, Komande &komanda, KodoviGresaka &greska, int &x, 
	int &y, int &i)
{
	if (unos.length() == 1) {
		greska = KodoviGresaka::NedostajeParametar;
	} else {
		if (IzdvojiBroj(unos, greska, ++i, x)) {
			if (IzdvojiBroj(unos, greska, ++i, y)) {
				if (unos[i] == ' ') {
					greska = KodoviGresaka::NeispravanParametar;
				} else {
					komanda = Komande::Deblokiraj;
					return true;
				}
			}
		}
	} 

	return false;
}


bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, 
	KodoviGresaka &greska)
{
	
	string unos;
	std::getline(std::cin, unos);
	RijesiRazmake(unos);

	int i(0), len(unos.length());
	if (len == 0) { // Dosegnut kraj unosa, sve razmaci
		greska = KodoviGresaka::PogresnaKomanda;
		return false;
	} else if (unos[0] == 'Z' || unos[0] == 'K') {
		return ZiliK(unos, komanda, greska);
	} else if (unos[0] == 'P') {
		i = 1;
		if (len == 1) {
			greska = KodoviGresaka::PogresnaKomanda;
			return false;
		} else if (unos[1] == '1') {
			return P1(unos, komanda, smjer, greska, i);
		} else if (unos[1] == '>') {
			return PVece(unos, komanda, greska, x, y, i);
		} else if (unos[1] == 'O') {
			return PO(unos, komanda, greska, i);
		}
	} else if (unos[0] == 'B') {
		return B(unos, komanda, greska, x, y, i);
	} else if (unos[0] == 'D') {
		return D(unos, komanda, greska, x, y, i);
	} else {
		greska = KodoviGresaka::PogresnaKomanda;
		return false;
	}
	
	return 0;
}



void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, 
	Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0) 
{
	switch (komanda) {
		case Komande::PomjeriJednoMjesto :
			Idi(polja, x, y, p_smjer);
			break;
		case Komande::PomjeriDalje :
			Idi(polja, x, y, p_x, p_y);
			break;
		case Komande::Blokiraj :
			BlokirajPolje(polja, p_x, p_y);
			break;
		case Komande::Deblokiraj :
			DeblokirajPolje(polja, p_x, p_y);
			break;
		case Komande::PrikaziOkolinu :
			PrikaziOkolinu(polja, x, y);
			break;
		case Komande::ZavrsiIgru :
			OcistiTablu(polja);
			throw std::runtime_error("Igra zavrsena");
	}	
}


int main ()
{
	string str;
	cout << "Unesite: " << endl;
	
	Komande komanda = Komande(0);
	Smjerovi smjer = Smjerovi(0);
	KodoviGresaka greska = KodoviGresaka(0);
	int x(0), y(0);
	cout << UnosKomande(komanda, smjer, x, y, greska);
	
	return 0;
}

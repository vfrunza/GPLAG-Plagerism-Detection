#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

enum class Polje {
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};

typedef std::vector<std::vector<Polje>> Tabla;

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

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0);

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine);

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y);

void BlokirajPolje(Tabla &polja, int x, int y);

void DeblokirajPolje(Tabla &polja, int x, int y);

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer);

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y);

bool PrijaviGresku(KodoviGresaka greska);

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska);

std::string ObrisiLijeveRazmake(std::string unos) {
	int pocetak (0);
	bool prvi_dozvoljeni_znak (false);
	for (char& c : unos) {
		if (prvi_dozvoljeni_znak == false && c == ' ') {
			pocetak++;
		} else {
			prvi_dozvoljeni_znak = true;
		}
	}
	unos = unos.substr(pocetak, unos.length() - pocetak);
	return unos;
}

std::string ObrisiVanjskeRazmake(std::string unos) {
	unos = ObrisiLijeveRazmake(unos);
	std::reverse(unos.begin(), unos.end());
	unos = ObrisiLijeveRazmake(unos);
	std::reverse(unos.begin(), unos.end());
	return unos;
}

std::string ObrisiDupleRazmake(std::string unos) {
	bool prosli_razmak (false);
	int pozicija (0);
	std::string novi = unos;
	for (char& c : unos) {
		if (prosli_razmak == true && c == ' ') {
			novi.erase(pozicija - 1, 1);
			pozicija--;
		}
		if (c == ' ') {
			prosli_razmak = true;	
		} else {
			prosli_razmak = false;
		}
		pozicija++;
	}
	return novi;
}

std::vector <std::string> ParsirajXY(std::string xy) {
		xy = ObrisiDupleRazmake(xy);
		xy = xy + " ";
		std::vector <std::string> parametri;
		int pozicija (0);
		int duzina (0);
		for (char& c : xy) {
			if (c == ' ') {
				std::string parametar = xy.substr(pozicija, duzina);
				parametri.push_back(parametar);
				pozicija = pozicija + duzina + 1;
				duzina = 0;
			} else {
				duzina++;
			}
		}
		for (int i = 0; i < parametri.size(); i++)
		std::cout << parametri.at(i);
		return parametri;
}

void ObradiUnos(std::string unos) {
	unos = ObrisiVanjskeRazmake(unos);
	unos = ObrisiDupleRazmake(unos);
	enum Komande komanda;
	enum Smjerovi smjer;
	enum KodoviGresaka greska;
	if (unos.substr(0, 2) == "P1") {
		komanda = Komande::PomjeriJednoMjesto;
		std::string smjer_komanda = ObrisiVanjskeRazmake(unos.substr(2, unos.length() - 2));
		if (smjer_komanda == "GL") {
			smjer = Smjerovi::GoreLijevo;
		} else if (smjer_komanda == "G") {
			smjer = Smjerovi::Gore;
		} else if (smjer_komanda == "GD") {
			smjer = Smjerovi::GoreDesno;
		} else if (smjer_komanda == "D") {
			smjer = Smjerovi::Desno;	
		} else if (smjer_komanda == "DoD") {
			smjer = Smjerovi::DoljeDesno;
		} else if (smjer_komanda == "Do") {
			smjer = Smjerovi::Dolje;
		} else if (smjer_komanda == "DoL") {
			smjer = Smjerovi::DoljeLijevo;
		} else if (smjer_komanda == "L") {
			smjer = Smjerovi::Lijevo;
		} else if (smjer_komanda == "") {
			greska = KodoviGresaka::NedostajeParametar;
		} else {
			greska = KodoviGresaka::NeispravanParametar;
		}
	} else if (unos.substr(0, 2) == "P>") {
		komanda = Komande::PomjeriDalje;
		std::string xy = ObrisiVanjskeRazmake(unos.substr(2, unos.length() - 2));
		std::vector <std::string> parametri = ParsirajXY(xy);
		std::string a = "0987";
		
		try{ 
			std::cout << std::stoi(a); 
		} catch (...) {
			
		}
	}
}

int main() {
	std::string unos;
	
	while (unos != "Z") {
		std::cout << "Unesite komandu: ";
		std::getline(std::cin, unos);
		ObradiUnos(unos);
	}
	
	return 0;
}
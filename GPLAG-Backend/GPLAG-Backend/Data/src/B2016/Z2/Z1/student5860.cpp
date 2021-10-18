/*B 16/17, Zadaća 2, Zadatak 1

	NAPOMENA: i javni ATo-vi su dio postavke

	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba

*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <cmath>

//
//Deklaracije enumova
//
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
    PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu,
    ZavrsiIgru, KreirajIgru
};
//
//Deklaracije funkcija
//
/*
void ispisiTablu(std::vector<std::vector<Polje>> polja) {
	for(int i = 0; i < polja.size(); i++) {
		for(int j = 0; j < polja[i].size(); j++) std::cout << int(polja[i][j]) << " ";
		std::cout << std::endl;
	}
}
//*/
void unesiKoordinate(int & x, int & y);
void PrijaviGresku(KodoviGresaka greska);
Tabla KreirajIgru(int n, const std::vector<std::vector<int>> & mine);
void BlokirajPolje(Tabla & polja, int x, int y);
void DeblokirajPolje(Tabla & polja, int x, int y);
Status Idi(Tabla & polja, int & x, int & y, Smjerovi smjer);
Status Idi(Tabla & polja, int & x, int & y, int novi_x, int novi_y);
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla & polja, int x, int y);
int izbrojiMine(const Tabla & polja, int x, int y);
void daLiJeBlokirano(const Tabla & polja, int x, int y);
Status daLiJeKrajIgre(const Tabla & polja);
bool UnosKomande(Komande & komanda, Smjerovi & smjer, int & x, int & y,KodoviGresaka & greska);
void unesiRijeci(std::vector<std::string> & rijeci);
void IzvrsiKomandu(Komande komanda, Tabla & polja, int & x, int & y,
                   Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0);
//
//Pravi kod woo
//ako netko ovo bude pregledaob meni je zao
//
int main () {

	try {
		Tabla polja;
		int x, y;
		while(true) {
			Komande komanda;
			Smjerovi smjer;
			int p_x, p_y;
			KodoviGresaka greska;
			std::cout << "Unesite komandu: ";
			if(UnosKomande(komanda, smjer, p_x, p_y, greska)) {
				IzvrsiKomandu(komanda, polja, x, y, smjer, p_x, p_y);
			} else {
				PrijaviGresku(greska);
			}
		}
	} catch(...) {
		std::cout << "Dovidjenja\n";
	}
	return 0;
}

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> & mine) {
	Tabla ploca(n);
	//Za stanje polja koristi Polje::"stanje"
	for(int i = 0; i < n; i++) {
		ploca[i].resize(n, Polje::Prazno);
	}
	for(int i = 0; i < mine.size(); i++) {
		if(mine[i].size() != 2) throw std::domain_error("Ilegalan format zadavanja mina");
		if(mine[i][0] < 0 || n <= mine[i][0] || mine[i][1] < 0 || n <= mine[i][1]) throw std::domain_error("Ilegalne pozicije mina");
		ploca[mine[i][0]][mine[i][1]] = Polje::Mina;
	}
	return ploca;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla & polja, int x, int y) {
	if(x < 0 || polja.size() <= x || y < 0 || polja[x].size() <= y) throw std::domain_error("Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji");
	std::vector<std::vector<int>> okolina(3);
	//
	//Obrati paznju da petlje pocinje od -1, ako korstis za alokaciju dodaj + 1
	//
	for(int i = -1; i <= 1; i++) {
		okolina[i + 1].resize(3, 0);
		if(x + i < 0 || polja.size() <= x + i) continue;
		for(int j = -1; j <= 1; j++) {
			if(y + j < 0 || polja[i + 1].size() <= y + j) continue;
			okolina[i + 1][j + 1] = izbrojiMine(polja, x + i, y + j);
		}
	}
	return okolina;
}
int izbrojiMine(const Tabla & polja, int x, int y) {
	//X,Y pozicija polja oko kojeg treba izbrojati mine
	int brojac(0);
	//
	//Obrati paznju da petlje pocinje od -1, ako korstis za alokaciju dodaj + 1
	//
	for(int i = -1; i < 2; i++) {
		if(x + i < 0 || polja.size() <= x + i) continue;
		for(int j = -1; j < 2; j++) {
			//da pregleda unutar opsega ploce
			if(y + j < 0 || polja[x + i].size() <= y + j) continue;
			//da ne gleda na polje oko kojeg se broje mine
			if(j == 0 && i == 0) continue;
			//ako je mina povecaj brojac mina
			if(polja[x + i][y + j] == Polje::Mina) brojac++;
		}
	}
	return brojac;
}

void BlokirajPolje(Tabla & polja, int x, int y) {
	if(x < 0 || polja.size() <= x || y < 0 || polja[x].size() <= y) throw std::domain_error("Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji");
	switch(polja[x][y]) {
	case Polje::Prazno:
		polja[x][y] = Polje::BlokiranoPrazno;
		break;
	case Polje::Mina:
		polja[x][y] = Polje::BlokiranoMina;
		break;
	case Polje::Posjeceno:
		polja[x][y] = Polje::BlokiranoPosjeceno;
		break;
	default:
		break;
	}
}
void DeblokirajPolje (Tabla & polja, int x, int y) {
	if(x < 0 || polja.size() <= x || y < 0 || polja[x].size() <= y) throw std::domain_error("Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji");
	switch(polja[x][y]) {
	case Polje::BlokiranoPrazno:
		polja[x][y] = Polje::Prazno;
		break;
	case Polje::BlokiranoMina:
		polja[x][y] = Polje::Mina;
		break;
	case Polje::BlokiranoPosjeceno:
		polja[x][y] = Polje::Posjeceno;
		break;
	default:
		break;
	}
}

Status Idi(Tabla & polja, int & x, int & y, Smjerovi smjer) {
	polja[x][y] = Polje::Posjeceno;
	switch(smjer) {
	case Smjerovi::GoreLijevo:
		if(x - 1 < 0 || y - 1 < 0) throw std::out_of_range("Izlazak van igrace table");
		x--;
		y--;
		break;
	case Smjerovi::Gore:
		if(x - 1 < 0) throw std::out_of_range("Izlazak van igrace table");
		x--;
		break;
	case Smjerovi::GoreDesno:
		if(x - 1 < 0 || polja[x].size() < y + 1) throw std::out_of_range("Izlazak van igrace table");
		x--;
		y++;
		break;
	case Smjerovi::Lijevo:
		if(y - 1 < 0) throw std::out_of_range("Izlazak van igrace table");
		y--;
		break;
	case Smjerovi::Desno:
		if(polja[x].size() < y + 1) throw std::out_of_range("Izlazak van igrace table");
		y++;
		break;
	case Smjerovi::DoljeLijevo:
		if(polja.size() < x + 1 || y - 1 < 0) throw std::out_of_range("Izlazak van igrace table");
		x++;
		y--;
		break;
	case Smjerovi::Dolje:
		if(polja.size() < x + 1) throw std::out_of_range("Izlazak van igrace table");
		x++;
		break;
	case Smjerovi::DoljeDesno:
		if(polja.size() < x + 1 || polja[x].size() < y + 1) throw std::out_of_range("Izlazak van igrace table");
		x++;
		y++;
		break;
	}
	daLiJeBlokirano(polja, x, y);
	if(polja[x][y] == Polje::Mina) {
		for(int i = 0; i < polja.size(); i++)
			for(int j = 0; j < polja[i].size(); j++)
				polja[i][j] = Polje::Prazno;
		return Status::KrajPoraz;
	}
	return daLiJeKrajIgre(polja);
}

void daLiJeBlokirano(const Tabla & polja, int x, int y) {
	switch(polja[x][y]) {
	case Polje::BlokiranoPosjeceno:
	case Polje::BlokiranoPrazno:
	case Polje::BlokiranoMina:
		throw std::logic_error("Blokirano polje");
		break;
	default:
		break;
	}
}
Status daLiJeKrajIgre(const Tabla & polja) {
	for(int i = 0; i < polja.size(); i++)
		for(int j = 0; j < polja[i].size(); j++)
			if(polja[i][j] != Polje::Posjeceno) return Status::NijeKraj;
	return Status::KrajPobjeda;
}

Status Idi(Tabla & polja, int & x, int & y, int novi_x, int novi_y) {
	polja[x][y] = Polje::Posjeceno;
	if(novi_x < 0 || polja.size() <= novi_x || novi_y < 0 || polja[novi_x].size() <= novi_y) throw std::out_of_range("Izlazak van igrace table");
	x = novi_x;
	y = novi_y;
	daLiJeBlokirano(polja, x, y);
	if(polja[x][y] == Polje::Mina) {
		for(int i = 0; i < polja.size(); i++)
			for(int j = 0; j < polja[i].size(); j++)
				polja[i][j] = Polje::Prazno;
		return Status::KrajPoraz;
	}
	return daLiJeKrajIgre(polja);
}
//
//Abandon hope all ye who enter here
//
bool UnosKomande(Komande & komanda, Smjerovi & smjer, int & x, int & y,KodoviGresaka & greska) {
	std::vector<std::string> naredba {};
	unesiRijeci(naredba);
	if(naredba.size() == 0) {
		greska = KodoviGresaka::PogresnaKomanda;
	}
	//*
	if(naredba.at(0) == "P1") {
		if(naredba.size() == 1) {
			greska = KodoviGresaka::NedostajeParametar;
			return false;
		}
		if(naredba.size() > 2) {
			greska = KodoviGresaka::SuvisanParametar;
			return false;
		}
		if(naredba.at(1) == "GL") {
			smjer = Smjerovi::GoreLijevo;
		} else if(naredba.at(1) == "G") {
			smjer = Smjerovi::Gore;
		} else if(naredba.at(1) == "GD") {
			smjer = Smjerovi::GoreDesno;
		} else if(naredba.at(1) == "L") {
			smjer = Smjerovi::Lijevo;
		} else if(naredba.at(1) == "D") {
			smjer = Smjerovi::Desno;
		} else if(naredba.at(1) == "DoL") {
			smjer = Smjerovi::DoljeLijevo;
		} else if(naredba.at(1) == "Do") {
			smjer = Smjerovi::Dolje;
		} else if(naredba.at(1) == "DoD") {
			smjer = Smjerovi::DoljeDesno;
		} else {
			greska = KodoviGresaka::NeispravanParametar;
			return false;
		}
		return true;
	} else if(naredba.at(0) == "P>") {
		if(naredba.size() < 2) {
			greska = KodoviGresaka::NedostajeParametar;
			return false;
		}
		if(naredba.size() > 3) {
			greska = KodoviGresaka::SuvisanParametar;
			return false;
		}
		komanda = Komande::PomjeriDalje;
		try {
			int pom(std::stoi(naredba.at(1)));
			if((int)std::log10(pom) + 1 != naredba.at(1).size()) throw 0;
			x = pom;
		} catch(...) {
			greska = KodoviGresaka::NeispravanParametar;
			return false;
		}
		if(naredba.size() < 3) {
			greska = KodoviGresaka::NedostajeParametar;
			return false;
		}
		try {
			int pom(std::stoi(naredba.at(2)));
			if((int)std::log10(pom) + 1 != naredba.at(2).size()) throw 0;
			y = pom;
		} catch(...) {
			greska = KodoviGresaka::NeispravanParametar;
			return false;
		}
		return true;
	} else if(naredba.at(0) == "B") {
		if(naredba.size() < 2) {
			greska = KodoviGresaka::NedostajeParametar;
			return false;
		}
		if(naredba.size() > 3) {
			greska = KodoviGresaka::SuvisanParametar;
			return false;
		}
		komanda = Komande::Blokiraj;
		try {
			int pom(std::stoi(naredba.at(1)));
			if((int)std::log10(pom) + 1 != naredba.at(1).size()) throw 0;
			x = pom;
		} catch(...) {
			greska = KodoviGresaka::NeispravanParametar;
			return false;
		}
		if(naredba.size() < 3) {
			greska = KodoviGresaka::NedostajeParametar;
			return false;
		}
		try {
			int pom(std::stoi(naredba.at(2)));
			if((int)std::log10(pom) + 1 != naredba.at(2).size()) throw 0;
			y = pom;
		} catch(...) {
			greska = KodoviGresaka::NeispravanParametar;
			return false;
		}
		return true;
	} else if(naredba.at(0) == "D") {
		if(naredba.size() < 2) {
			greska = KodoviGresaka::NedostajeParametar;
			return false;
		}
		if(naredba.size() > 3) {
			greska = KodoviGresaka::SuvisanParametar;
			return false;
		}

		komanda = Komande::Deblokiraj;

		try {
			int pom(std::stoi(naredba.at(1)));
			if((int)std::log10(pom) + 1 != naredba.at(1).size()) throw 0;
			x = pom;
		} catch(...) {
			greska = KodoviGresaka::NeispravanParametar;
			return false;
		}
		if(naredba.size() < 3) {
			greska = KodoviGresaka::NedostajeParametar;
			return false;
		}
		try {
			int pom(std::stoi(naredba.at(2)));
			if((int)std::log10(pom) + 1 != naredba.at(2).size()) throw 0;
			y = pom;
		} catch(...) {
			greska = KodoviGresaka::NeispravanParametar;
			return false;
		}
		return true;
	} else if(naredba.at(0) == "PO") {
		if(naredba.size() > 1) {
			greska = KodoviGresaka::SuvisanParametar;
			return false;
		}
		komanda = Komande::PrikaziOkolinu;
		return true;
	} else if(naredba.at(0) == "Z") {
		if(naredba.size() > 1) {
			greska = KodoviGresaka::SuvisanParametar;
			return false;
		}
		komanda = Komande::ZavrsiIgru;
		return true;
	} else if(naredba.at(0) == "K") {
		if(naredba.size() > 1) {
			greska = KodoviGresaka::SuvisanParametar;
			return false;
		}
		komanda = Komande::KreirajIgru;
		return true;
	} else {
		greska = KodoviGresaka::PogresnaKomanda;
		return false;
	}
//*/
	//ovo se ne bi trebalo dosegnuti, ali neka ga
	//u slucaju da se nesto promijeni
	return true;
}
void unesiRijeci(std::vector<std::string> & rijeci) {
	while(std::cin.peek() != '\n') {
		while(std::cin.peek() == ' ' || std::cin.peek() == '\t') std::cin.ignore();
		if(std::cin.peek() == '\n') break;
		std::string pom;
		std::cin >> pom;
		rijeci.push_back(pom);
	}
	std::cin.ignore();
}

void IzvrsiKomandu(Komande komanda, Tabla & polja, int & x, int & y, Smjerovi p_smjer, int p_x, int p_y) {
	switch(komanda) {
	case Komande::PomjeriJednoMjesto: {
		try {
			std::cout << "Tekuca pozicija igrača je (" << x << "," << y << ")" << "\n";
			switch(Idi(polja, x, y, p_smjer)) {
			case Status::KrajPoraz: {
				std::cout << "Nagazili ste na minu\n"; //BOOM ode noga
				for(int i = 0; i < polja.size(); i++)
					for(int j = 0; j < polja[i].size(); j++)
						polja[i][j] = Polje::Prazno;
				throw std::runtime_error("Igra zavrsena");
				break;
			}
			case Status::KrajPobjeda: {
				std::cout << "Bravo, obisli ste sva sigurna polja\n"; //moj rekord je 1:38, ne na ovoj verziji ofc
				for(int i = 0; i < polja.size(); i++)
					for(int j = 0; j < polja[i].size(); j++)
						polja[i][j] = Polje::Prazno;
				throw std::runtime_error("Igra zavrsena");
				break;
			}
			default:
				break;
			}
		} catch(std::out_of_range e) {
			std::cout << e.what() << "\n";
		}
		break;
	}
	case Komande::PomjeriDalje: {
		try {
			std::cout << "Tekuca pozicija igrača je (" << x << "," << y << ")" << "\n";
			switch(Idi(polja, x, y, p_x, p_y)) {
			case Status::KrajPoraz: {
				std::cout << "Nagazili ste na minu\n"; //BOOM ode noga
				for(int i = 0; i < polja.size(); i++)
					for(int j = 0; j < polja[i].size(); j++)
						polja[i][j] = Polje::Prazno;
				throw std::runtime_error("Igra zavrsena");
				break;
			}
			case Status::KrajPobjeda: {
				std::cout << "Bravo, obisli ste sva sigurna polja\n"; //moj rekord je 1:38, ne na ovoj verziji ofc
				for(int i = 0; i < polja.size(); i++)
					for(int j = 0; j < polja[i].size(); j++)
						polja[i][j] = Polje::Prazno;
				throw std::runtime_error("Igra zavrsena");
				break;
			}
			default:
				break;
			}
		} catch(std::out_of_range e) {
			std::cout << e.what() << "\n";
		}
		break;
	}
	case Komande::Blokiraj: {
		try {
			BlokirajPolje(polja, p_x, p_y);
		} catch(std::domain_error e) {
			std::cout << e.what() << "\n";
		}
		break;
	}
	case Komande::Deblokiraj: {
		try {
			DeblokirajPolje(polja, p_x, p_y);
		} catch(std::domain_error e) {
			std::cout << e.what() << "\n";
		}
		break;
	}
	case Komande::PrikaziOkolinu: {
		try {
			std::vector<std::vector<int>> okolina(PrikaziOkolinu(polja, x, y));
			for(int i = 0; i < okolina.size(); i++) {
				for(int j = 0; j < okolina[i].size(); j++)
					std::cout << okolina[i][j] << " ";
				std::cout << "\n";
			}
		} catch (std::domain_error e) {
			std::cout << e.what() << "\n";
		}
		break;
	}
	case Komande::ZavrsiIgru: {
		for(int i = 0; i < polja.size(); i++)
			for(int j = 0; j < polja[i].size(); j++)
				polja[i][j] = Polje::Prazno;
		throw std::runtime_error("Igra zavrsena");
		break;
	}
	case Komande::KreirajIgru: {
		std::vector<std::vector<int>> mine;
		int n;
		std::cout << "Unesite broj polja: ";
		std::cin >> n;
		std::cout << "Unesite pozicije mina: ";
		while(true) {
			try {
				int x, y;
				unesiKoordinate(x, y);
				std::vector<int> pom {x, y};
				mine.push_back(pom);
			} catch(std::range_error) {
				std::cout << "Greska, unesite ponovo!\n";
				continue;
			} catch (std::domain_error) {
				break;
			}
		}
		polja = KreirajIgru(n, mine);
		break;
	}
	}
}
/*
enum class KodoviGresaka {
    PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};
  PrijaviGresku(KodoviGresaka::PogresnaKomanda);
  PrijaviGresku(KodoviGresaka::NedostajeParametar);
  PrijaviGresku(KodoviGresaka::SuvisanParametar);
  PrijaviGresku(KodoviGresaka::NeispravanParametar);
//*/
void PrijaviGresku(KodoviGresaka greska) {
	switch(greska) {
	case KodoviGresaka::PogresnaKomanda: {
		std::cout << "Nerazumljiva komanda!\n";
		break;
	}
	case KodoviGresaka::NedostajeParametar: {
		std::cout << "Komanda trazi parametar koji nije naveden!\n";
		break;
	}
	case KodoviGresaka::NeispravanParametar: {
		std::cout << "Parametar komande nije ispravan!\n";
		break;
	}
	case KodoviGresaka::SuvisanParametar: {
		std::cout << "Zadan je suvisan parametar nakon komande!\n";
		break;
	}
	default:
		break;
	}
}
void unesiKoordinate(int & x, int & y) {
	char blaa;
	std::string ocisti;
	std::cin >> blaa;
	if(blaa == '.') {
		std::getline(std::cin,ocisti);
		throw std::domain_error("");
	}
	if(blaa != '(') {
		std::getline(std::cin,ocisti);
		throw std::range_error("");
	}
	if(!std::isdigit(std::cin.peek())) {
		std::getline(std::cin,ocisti);
		throw std::range_error("");
	}
	std::cin >> x;
	if(std::cin.peek() != ',') {
		std::getline(std::cin,ocisti);
		throw std::range_error("");
	}
	std::cin.ignore();
	if(!std::isdigit(std::cin.peek())) {
		std::getline(std::cin,ocisti);
		throw std::range_error("");
	}
	std::cin >> y;
	if(std::cin.peek() != ')') {
		std::getline(std::cin,ocisti);
		throw std::range_error("");
	}
	std::cin.ignore();
}
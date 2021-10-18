/*B 2017/2018, Zadaća 2, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

enum class Polje {Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina};
enum class Smjerovi {GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo};
enum class Status {NijeKraj, KrajPoraz, KrajPobjeda};
enum class KodoviGresaka {PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar};
enum class Komande {PomjeriJednoMjesto, PomjeriDalje, Blokkiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru};

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru (int n, const std::vector<std::vector<int>> &mine) {
	for (int i = 0 ; i < mine.size() ; i++) {
		for (int j = 0 ; j < mine.at(i).size() ; j++) {
			if (mine.at(i).size() != 2) throw std::domain_error ("Ilegalan format zadavanja mina");
		}
	}
	for (int i = 0 ; i < mine.size() ; i++) {
		for (int j = 0 ; j < mine.at(i).size() ; j++) {
			if (mine.at(i).at(j) > n)
				throw std::domain_error ("Ilegalne pozicije mina");
		}
	}
	if (n <= 0) throw std::domain_error ("ilegalna velicina");
	Tabla igrica(n, std::vector<Polje>(n));
	for (int i = 0 ; i < mine.size() ; i++) {
		int element1(0), element2(0);
		for (int j = 0 ; j < mine.at(i).size() ; j++) {
			element1 = mine.at(i).at(j);
			element2 = mine.at(i).at(j + 1);
			j++;
		}
		igrica.at(element1).at(element2) = Polje::Mina;
	}
	return igrica;	
}

void BlokirajPolje (Tabla &polja, int x, int y) {
	if (x >= polja.size() || y >= polja.at(0).size()) throw std::domain_error ("Polje (x,y) ne postoji");
	 Polje element(polja.at(x).at(y));
	 if (element == Polje::BlokiranoPrazno || element == Polje::BlokiranoPosjeceno || element == Polje::BlokiranoMina) return;
	 else if (element == Polje::Prazno)
	 	polja.at(x).at(y) = Polje::BlokiranoPrazno;
	 else if (element == Polje::Posjeceno)
	 	polja.at(x).at(y) = Polje::BlokiranoPosjeceno;
	 else if (element == Polje::Mina)
	 	polja.at(x).at(y) = Polje::BlokiranoMina;
}

void DeblokirajPolje (Tabla &polja, int x, int y) {
	if (x >= polja.size() || y >= polja.at(0).size()) throw std::domain_error ("Polje (x,y) ne postoji");
	Polje element (polja.at(x).at(y));
	if (element == Polje::Prazno || element == Polje::Mina || element == Polje::Posjeceno) return;
	else if (element == Polje::BlokiranoPrazno)
		polja.at(x).at(y) = Polje::Prazno;
	else if (element == Polje::BlokiranoPosjeceno)
		polja.at(x).at(y) = Polje::Posjeceno;
	else if (element == Polje::BlokiranoMina)
		polja.at(x).at(y) = Polje::Mina;
}

Status Idi (Tabla &polja, int &x, int &y, Smjerovi smjer) {
	Polje pozicija(polja.at(x).at(y));
	pozicija = Polje::Posjeceno;
	Polje nova_pozicija;
	if (smjer == Smjerovi::GoreLijevo) {
		x -= 1;
		y -= 1;
		nova_pozicija = polja.at(x).at(y);
	}
	else if (smjer == Smjerovi::Gore) {
		x -= 1;
		nova_pozicija = polja.at(x).at(y);
	}
	else if (smjer == Smjerovi::GoreDesno) {
		x -= 1;
		y += 1;
		nova_pozicija = polja.at(x).at(y);
	}
	else if (smjer == Smjerovi::Lijevo) {
		y -= 1;
		nova_pozicija = polja.at(x).at(y);
	}
	else if (smjer == Smjerovi::Desno) {
		y += 1;
		nova_pozicija = polja.at(x).at(y);
	}
	else if (smjer == Smjerovi::DoljeLijevo) {
		x += 1;
		y -= 1;
		nova_pozicija = polja.at(x).at(y);
	}
	else if (smjer == Smjerovi::Dolje) {
		x += 1;
		nova_pozicija = polja.at(x).at(y);
	}
	else if (smjer == Smjerovi::DoljeDesno) {
		x += 1;
		y += 1;
		nova_pozicija = polja.at(x).at(y);
	}
	if (nova_pozicija == Polje::BlokiranoPosjeceno || nova_pozicija == Polje::BlokiranoPrazno || nova_pozicija == Polje::BlokiranoMina)
			throw std::logic_error ("Blokirano polje");
	if (nova_pozicija == Polje::Mina) {
		for (int i = 0 ; i < polja.size() ; i++) {
			for (int j = 0 ; j < polja.at(i).size() ; j++) {
				polja.at(i).at(j) == Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
	for (int i = 0 ; i < polja.size() ; i++) {
		for (int j = 0 ; j < polja.at(i).size() ; j++) {
			if (nova_pozicija == Polje::Prazno && nova_pozicija != pozicija) 
				return Status::NijeKraj;
				break;
		}
	}
	return Status::KrajPobjeda;
}

Status Idi (Tabla &polja, int &x, int &y, int novi_x, int novi_y) {
	Polje pozicija (polja.at(x).at(y));
	pozicija = Polje::Posjeceno;
	Polje nova_pozicija (polja.at(novi_x).at(novi_y));
	if (nova_pozicija == Polje::BlokiranoPosjeceno || nova_pozicija == Polje::BlokiranoPrazno || nova_pozicija == Polje::BlokiranoMina)
			throw std::logic_error ("Blokirano polje");
	if (nova_pozicija == Polje::Mina) {
		for (int i = 0 ; i < polja.size() ; i++) {
			for (int j = 0 ; j < polja.at(i).size() ; j++) {
				polja.at(i).at(j) = Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
	for (int i = 0 ; i < polja.size() ; i++) {
		for (int j = 0 ; j < polja.at(0).size() ; j++) {
			if (nova_pozicija == Polje::Prazno && nova_pozicija != pozicija) return Status::NijeKraj;
			break;
		}
	}
	return Status::KrajPobjeda;
}

void PrijaviGresku (KodoviGresaka greska) {
	if (greska == KodoviGresaka::PogresnaKomanda)
		std::cout << "Nerazumljiva komanda!";
	else if (greska == KodoviGresaka::NedostajeParametar)
		std::cout << "Komanda trazi parametar koji nije naveden!";
	else if (greska == KodoviGresaka::NeispravanParametar)
		std::cout << "Parametar komande nije ispravan!";
	else if (greska == KodoviGresaka::SuvisanParametar)
		std::cout << "Zadan je suvisan parametar nakon komande!";
}

bool UnosKomande (Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska) {
	
}


int main ()
{
	return 0;
}
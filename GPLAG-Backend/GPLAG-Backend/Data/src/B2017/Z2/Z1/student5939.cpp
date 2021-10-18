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

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine) {
	for (int i=0; i<mine.size(); i++) {
		if (mine.at(i).size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
	}
	for (int i=0; i<mine.size(); i++) {
		if (mine.at(i).at(0)>=n || mine.at(i).at(0)<0) throw std::domain_error("Ilegalne pozicije mina");
		if (mine.at(i).at(1)>=n || mine.at(i).at(1)<0) throw std::domain_error("Ilegalne pozicije mina");
	}
	if (n<=0) throw std::domain_error("Ilegalna velicina");
	Tabla t;
	t.resize(n);
	for (int i=0; i<n; i++) t.at(i).resize(n);
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			t.at(i).at(j)=Polje::Prazno;
		}
	}
	for (int i=0; i<mine.size(); i++) {
		int x(mine.at(i).at(0));
		int y(mine.at(i).at(1));
		t.at(x).at(y)=Polje::Mina;
	}
	return t;
}

int BrojMinaOkolo(const Tabla &polja, int x, int y) {
	int broj(0);
	for (int i=x-1; i<=x+1; i++) {
		for (int j=y-1; j<=y+1; j++) {
			if (i<0 || j<0 || i>=polja.size() || j>=polja.at(0).size() || (i==x && j==y)) continue;
			if (polja.at(i).at(j)==Polje::Mina) broj++;
		}
	}
	return broj;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y) {
	if (x<0 || y<0 || x>=polja.size() || y>=polja.at(0).size())
		throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	std::vector<std::vector<int>> okolina;
	okolina.resize(3);
	for (int i=0; i<3; i++) okolina.at(i).resize(3);
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			okolina.at(i).at(j)=0;
		}
	}
	int brojreda(-1);
	for (int i=x-1; i<=x+1; i++) {
		brojreda++;
		int brojkolone(-1);
		for (int j=y-1; j<=y+1; j++) {
			brojkolone++;
			okolina.at(brojreda).at(brojkolone)=BrojMinaOkolo(polja, i, j);
		}
	}
	return okolina;
}

void BlokirajPolje(Tabla &polja, int x, int y) {
	if (x<0 || y<0 || x>=polja.size() || y>=polja.at(0).size())
		throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	if (polja.at(x).at(y)==Polje::Posjeceno) polja.at(x).at(y)=Polje::BlokiranoPosjeceno;
	if (polja.at(x).at(y)==Polje::Mina) polja.at(x).at(y)=Polje::BlokiranoMina;
	if (polja.at(x).at(y)==Polje::Prazno) polja.at(x).at(y)=Polje::BlokiranoPrazno;
}

void DeblokirajPolje(Tabla &polja, int x, int y) {
	if (x<0 || y<0 || x>=polja.size() || y>=polja.at(0).size())
		throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	if (polja.at(x).at(y)==Polje::BlokiranoPosjeceno) polja.at(x).at(y)=Polje::Posjeceno;
	if (polja.at(x).at(y)==Polje::BlokiranoMina) polja.at(x).at(y)=Polje::Mina;
	if (polja.at(x).at(y)==Polje::BlokiranoPrazno) polja.at(x).at(y)=Polje::Prazno;
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer) {
	polja.at(x).at(y)=Polje::Posjeceno;
	int novo_x, novo_y;
	if (smjer==Smjerovi::GoreLijevo) {
		novo_x=x-1;
		novo_y=y-1;
	}
	else if (smjer==Smjerovi::Gore) {
		novo_x=x-1;
		novo_y=y;
	}
	else if (smjer==Smjerovi::GoreDesno) {
		novo_x=x-1;
		novo_y=y+1;
	}
	else if (smjer==Smjerovi::Desno) {
		novo_x=x;
		novo_y=y+1;
	}
	else if (smjer==Smjerovi::DoljeDesno) {
		novo_x=x+1;
		novo_y=y+1;
	}
	else if (smjer==Smjerovi::Dolje) {
		novo_x=x+1;
		novo_y=y;
	}
	else if (smjer==Smjerovi::DoljeLijevo) {
		novo_x=x+1;
		novo_y=y-1;
	}
	else if (smjer==Smjerovi::Lijevo) {
		novo_x=x;
		novo_y=y-1;
	}
	if (novo_x<0 || novo_y<0 || novo_x>=polja.size() || novo_y>=polja.at(0).size()) throw std::out_of_range("Izlazak van igrace table");
	if (polja.at(novo_x).at(novo_y)==Polje::BlokiranoPosjeceno 
	|| polja.at(novo_x).at(novo_y)==Polje::BlokiranoMina 
	|| polja.at(novo_x).at(novo_y)==Polje::BlokiranoPrazno) 
		throw std::logic_error("Blokirano polje");
	x=novo_x;
	y=novo_y;
	if (polja.at(x).at(y)==Polje::Mina) {
		for (int i=0; i<polja.size(); i++) {
			for (int j=0; j<polja.at(i).size(); j++) {
				polja.at(i).at(j)=Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
	bool prekini(false);
	for (int i=0; i<polja.size(); i++) {
		for (int j=0; j<polja.at(i).size(); j++) {
			if (polja.at(i).at(j)==polja.at(x).at(y)) continue;
			if (polja.at(i).at(j)==Polje::Prazno) {
				prekini=true;
				break;
			}
		}
		if (prekini) break;
	}
	if (!prekini) return Status::KrajPobjeda;
	return Status::NijeKraj;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y) {
	polja.at(x).at(y)=Polje::Posjeceno;
	int novo_x, novo_y;
	novo_x=novi_x;
	novo_y=novi_y;
	if (novo_x<0 || novo_y<0 || novo_x>=polja.size() || novo_y>=polja.at(0).size()) throw std::out_of_range("Izlazak van igrace table");
	if (polja.at(novo_x).at(novo_y)==Polje::BlokiranoPosjeceno 
	|| polja.at(novo_x).at(novo_y)==Polje::BlokiranoMina 
	|| polja.at(novo_x).at(novo_y)==Polje::BlokiranoPrazno) 
		throw std::logic_error("Blokirano polje");
	x=novo_x;
	y=novo_y;
	if (polja.at(x).at(y)==Polje::Mina) {
		for (int i=0; i<polja.size(); i++) {
			for (int j=0; j<polja.at(i).size(); j++) {
				polja.at(i).at(j)=Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
	bool prekini(false);
	for (int i=0; i<polja.size(); i++) {
		for (int j=0; j<polja.at(i).size(); j++) {
			if (polja.at(i).at(j)==polja.at(x).at(y)) continue;
			if (polja.at(i).at(j)==Polje::Prazno) {
				prekini=true;
				break;
			}
		}
		if (prekini) break;
	}
	if (!prekini) return Status::KrajPobjeda;
	return Status::NijeKraj;
}

void PrijaviGresku(KodoviGresaka kod) {
	if (kod==KodoviGresaka::PogresnaKomanda)
		std::cout << "Nerazumljiva komanda!" << std::endl;
	else if (kod==KodoviGresaka::NedostajeParametar)
		std::cout << "Komanda trazi parametar koji nije naveden!" << std::endl;
	else if (kod==KodoviGresaka::NeispravanParametar)
		std::cout << "Parametar komande nije ispravan!" << std::endl;
	else if (kod==KodoviGresaka::SuvisanParametar)
		std::cout << "Zadan je suvisan parametar nakon komande!" << std::endl;
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska);

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0) {
	if (komanda==Komande::Blokiraj) {
		try {
			BlokirajPolje(polja, x, y);
		}
		catch(std::domain_error e) {
			std::cout << e.what() << std::endl;
		}
	}
	else if (komanda==Komande::Deblokiraj) {
		try {
			DeblokirajPolje(polja, x, y);
		}
		catch(std::domain_error e) {
			std::cout << e.what() << std::endl;
		}
	}
	else if (komanda==Komande::PrikaziOkolinu) {
		try {
			std::vector<std::vector<int>> matrica;
			matrica=PrikaziOkolinu(polja, x, y);
			for (int i=0; i<3; i++) {
				for (int j=0; j<3; j++) {
					std::cout << matrica.at(i).at(j) << " ";
				}
				std::cout << std::endl;
			}
		}
		catch(std::domain_error e) {
			std::cout << e.what() << std::endl;
		}
	}
	else if (komanda==Komande::PomjeriJednoMjesto) {
		try {
			Status rezultat;
			rezultat=Idi(polja, x, y, p_smjer);
			std::cout << "Tekuca pozicija igraca je ("+std::to_string(x)+","+std::to_string(y)+")"<< std::endl;
			if (rezultat==Status::KrajPobjeda) {
				std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
				for (int i=0; i<polja.size(); i++) {
					for (int j=0; j<polja.at(i).size(); j++) {
						polja.at(i).at(j)=Polje::Prazno;
					}
				}
				throw std::runtime_error("Igra zavrsena");
			}
			if (rezultat==Status::KrajPoraz) {
				std::cout << "Nagazili ste na minu" << std::endl;
				for (int i=0; i<polja.size(); i++) {
					for (int j=0; j<polja.at(i).size(); j++) {
						polja.at(i).at(j)=Polje::Prazno;
					}
				}
				throw std::runtime_error("Igra zavrsena");
			}
		}
		catch(std::out_of_range e) {
			std::cout << e.what() << std::endl;
		}
		catch(std::logic_error e) {
			std::cout << e.what() << std::endl;
		}
	}
	else if (komanda==Komande::PomjeriDalje) {
		try {
			Status rezultat;
			rezultat=Idi(polja, x, y, p_x, p_y);
			std::cout << "Tekuca pozicija igraca je ("+std::to_string(x)+","+std::to_string(y)+")"<< std::endl;
			if (rezultat==Status::KrajPobjeda) {
				std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
				for (int i=0; i<polja.size(); i++) {
					for (int j=0; j<polja.at(i).size(); j++) {
						polja.at(i).at(j)=Polje::Prazno;
					}
				}
				throw std::runtime_error("Igra zavrsena");
			}
			if (rezultat==Status::KrajPoraz) {
				std::cout << "Nagazili ste na minu" << std::endl;
				for (int i=0; i<polja.size(); i++) {
					for (int j=0; j<polja.at(i).size(); j++) {
						polja.at(i).at(j)=Polje::Prazno;
					}
				}
				throw std::runtime_error("Igra zavrsena");
			}
		}
		catch(std::out_of_range e) {
			std::cout << e.what() << std::endl;
		}
		catch(std::logic_error e) {
			std::cout << e.what() << std::endl;
		}
	}
	else if (komanda==Komande::ZavrsiIgru) {
		for (int i=0; i<polja.size(); i++) {
			for (int j=0; j<polja.at(i).size(); j++) {
				polja.at(i).at(j)=Polje::Prazno;
			}
		}
		throw std::runtime_error("Igra zavrsena");
	}
}

int main ()
{
	
	return 0;
}
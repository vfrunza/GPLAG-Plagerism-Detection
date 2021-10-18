/*B 16/17, Zadaća 2, Zadatak 1

	NAPOMENA: i javni ATo-vi su dio postavke

	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba

*/

// GLOBALNI OPSEG
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <complex>





enum class Polje
{
    Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno,BlokiranoMina
};

enum class Smjerovi
{
    GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};

enum class Status
{
    NijeKraj,KrajPoraz,KrajPobjeda
};

enum class KodoviGresaka
{
    PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};
enum class Komande
{
    PomjeriJednoMjesto,PomjeriDalje,Blokiraj, Deblokiraj, PrikaziOkolinu,ZavrsiIgru,KreirajIgru
};
typedef std::vector<std::vector<Polje>> Tabla;

bool JednakostTest(int x1,int y1, int x2, int y2)
{
	if (x1 == x2 and y1 == y2) return true;
	return false;
}

// FUNKCIJE IZ TEKSTA

Tabla KreirajIgru (int n, const std::vector<std::vector<int>> &mine)
{
	for (auto &i : mine) {
		if (i.size() != 2) throw std::domain_error("Ilegalan format zadavanja mina");
		for (auto &i2 : i) {
			if (i2 >= n or i2 < 0) throw std::domain_error("Ilegalne pozicije mina");
		}
	}

	Tabla KTabla(n,(std::vector<Polje>(n,Polje::Prazno)));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < mine.size(); k++) {
				if (JednakostTest(i,j,mine[k][0],mine[k][1])) KTabla[i][j] = Polje::Mina;
			}
		}
	}
	return KTabla;
}
int BrojMina (const Tabla &polja,int x, int y)
{
	int brojac(0);
	int n(polja.size());
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if(i == 0 and j == 0) continue;
			if (x+i >= n or x+i < 0 or y+j >= n or y+j < 0) continue;
			if(polja[x+i][y+j] == Polje::Mina) brojac++;
		}
	}
	return brojac;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y)
{
	std::string izuzetak {"Polje ("};
	izuzetak += std::to_string(x)+", "+std::to_string(y)+") ne postoji";

	int n(polja.size());
	if (x >= n or x < 0 or y >= n or y < 0) throw std::domain_error(izuzetak);
	std::vector<std::vector<int>> Matrica(3,std::vector<int> (3));
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (x+i >= n or x+i < 0 or y+j >= n or y+j < 0) Matrica[i+1][j+1] = 0;
			Matrica[i+1][j+1] = BrojMina(polja,x+i,y+j);
		}
	}
	return Matrica;

}

void BlokirajPolje (Tabla &polja,int x, int y)
{
	std::string izuzetak {"Polje ("};
	izuzetak += std::to_string(x)+", "+std::to_string(y)+") ne postoji";

	int n(polja.size());
	if (x >= n or x < 0 or y >= n or y < 0) throw std::domain_error(izuzetak);
	if (polja[x][y] == Polje::Prazno) polja[x][y] = Polje::BlokiranoPrazno;
	if (polja[x][y] == Polje::Posjeceno) polja[x][y] = Polje::BlokiranoPosjeceno;
	if (polja[x][y] == Polje::Mina) polja[x][y] = Polje::BlokiranoMina;


}

void DeblokirajPolje (Tabla &polja, int x, int y)
{
	std::string izuzetak {"Polje ("};
	izuzetak += std::to_string(x)+", "+std::to_string(y)+") ne postoji";

	int n(polja.size());
	if (x >= n or x < 0 or y >= n or y < 0) throw std::domain_error(izuzetak);
	if (polja[x][y] == Polje::BlokiranoPrazno) polja[x][y] = Polje::Prazno;
	if (polja[x][y] == Polje::BlokiranoPosjeceno) polja[x][y] = Polje::Posjeceno;
	if (polja[x][y] == Polje::BlokiranoMina) polja[x][y] = Polje::Mina;
}

Status Idi (Tabla &polja, int &x, int &y, Smjerovi smjer)
{
	int n(polja.size());
	switch (smjer) {
	case Smjerovi::Gore:
		if(x-1 >= n or x-1 < 0) throw std::out_of_range ("Izlazak van igrace table");
		if(polja[x-1][y] == Polje::BlokiranoPosjeceno or polja[x-1][y] == Polje::BlokiranoMina or polja[x-1][y] == Polje::BlokiranoPrazno)
			throw std::logic_error("Blokirano polje");
		polja[x][y] = Polje::Posjeceno;
		x = x-1;
		break;
	case Smjerovi::GoreLijevo:
		if(x-1 >= n or y-1 >= n or y-1 < 0 or x - 1 < 0) throw std::out_of_range ("Izlazak van igrace table");
		if(polja[x-1][y-1] == Polje::BlokiranoPosjeceno or polja[x-1][y-1] == Polje::BlokiranoMina or polja[x-1][y-1] == Polje::BlokiranoPrazno)
			throw std::logic_error("Blokirano polje");
		polja[x][y] = Polje::Posjeceno;
		x = x-1;
		y = y-1;
		break;
	case Smjerovi::GoreDesno:
		if(x-1 >= n or y+1 >= n or y+1 < 0 or x - 1 < 0) throw std::out_of_range ("Izlazak van igrace table");
		if(polja[x-1][y+1] == Polje::BlokiranoPosjeceno or polja[x-1][y+1] == Polje::BlokiranoMina or polja[x-1][y+1] == Polje::BlokiranoPrazno)
			throw std::logic_error("Blokirano polje");
		polja[x][y] = Polje::Posjeceno;
		x = x-1;
		y = y+1;
		break;
	case Smjerovi::Desno:
		if(y+1 >= n) throw std::out_of_range ("Izlazak van igrace table");
		if(polja[x][y+1] == Polje::BlokiranoPosjeceno or polja[x][y+1] == Polje::BlokiranoMina or polja[x][y+1] == Polje::BlokiranoPrazno)
			throw std::logic_error("Blokirano polje");
		polja[x][y] = Polje::Posjeceno;
		y = y+1;
		break;
	case Smjerovi::DoljeDesno:
		if(x+1 >= n or y+1 >= n or y+1 < 0 or x + 1 < 0) throw std::out_of_range ("Izlazak van igrace table");
		if(polja[x+1][y+1] == Polje::BlokiranoPosjeceno or polja[x+1][y+1] == Polje::BlokiranoMina or polja[x+1][y+1] == Polje::BlokiranoPrazno)
			throw std::logic_error("Blokirano polje");
		polja[x][y] = Polje::Posjeceno;
		x = x+1;
		y = y+1;
		break;
	case Smjerovi::Dolje:
		if(x+1 >= n) throw std::out_of_range ("Izlazak van igrace table");
		if(polja[x+1][y] == Polje::BlokiranoPosjeceno or polja[x+1][y] == Polje::BlokiranoMina or polja[x+1][y] == Polje::BlokiranoPrazno)
			throw std::logic_error("Blokirano polje");
		polja[x][y] = Polje::Posjeceno;
		x = x+1;
		break;
	case Smjerovi::Lijevo:
		if(y-1 >= n) throw std::out_of_range ("Izlazak van igrace table");
		if(polja[x][y-1] == Polje::BlokiranoPosjeceno or polja[x][y-1] == Polje::BlokiranoMina or polja[x][y-1] == Polje::BlokiranoPrazno)
			throw std::logic_error("Blokirano polje");
		polja[x][y] = Polje::Posjeceno;
		y = y-1;
		break;
	case Smjerovi::DoljeLijevo:
		if(x+1 >= n or y-1 >= n or y-1 < 0 or x + 1 < 0) throw std::out_of_range ("Izlazak van igrace table");
		if(polja[x+1][y-1] == Polje::BlokiranoPosjeceno or polja[x+1][y-1] == Polje::BlokiranoMina or polja[x+1][y-1] == Polje::BlokiranoPrazno)
			throw std::logic_error("Blokirano polje");
		polja[x][y] = Polje::Posjeceno;
		x = x+1;
		y = y-1;
		break;
	}
	if (polja[x][y] == Polje::Mina) {
		for (auto &i : polja) {
			for (auto &i2 : i) {
				i2 = Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
	bool ima_prazni(false);
	for (auto &i : polja) {
		if (std::find(i.begin(),i.end(),Polje::Prazno) != i.end()) {
			ima_prazni = true;
			break;
		}
	}
	if (ima_prazni) return Status::NijeKraj;
	else return Status::KrajPobjeda;
}

Status Idi (Tabla &polja, int &x, int &y,int novi_x, int novi_y)
{
	int n(polja.size());
	if (novi_x >= n or novi_x < 0 or novi_y >= n or novi_y < 0) throw std::out_of_range ("Izlazak van igrace table");
	if(polja[novi_x][novi_y] == Polje::BlokiranoPosjeceno or polja[novi_x][novi_y] == Polje::BlokiranoMina or polja[novi_x][novi_y] == Polje::BlokiranoPrazno)
		throw std::logic_error("Blokirano polje");
	x = novi_x;
	y = novi_y;
	if (polja[x][y] == Polje::Mina) {
		for (auto &i : polja) {
			for (auto &i2 : i) {
				i2 = Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
	bool ima_prazni(false);
	for (auto &i : polja) {
		if (std::find(i.begin(),i.end(),Polje::Prazno) != i.end()) {
			ima_prazni = true;
			break;
		}
	}
	if (ima_prazni) return Status::NijeKraj;
	else return Status::KrajPobjeda;
}


void PrijaviGresku (KodoviGresaka greska)
{
	switch(greska) {
	case KodoviGresaka::PogresnaKomanda:
		std::cout << "Nerazumljiva komanda!";
	case KodoviGresaka::NedostajeParametar:
		std::cout << "Komanda trazi parametar koji nije naveden!";
	case KodoviGresaka::NeispravanParametar:
		std::cout << "Parametar komande nije ispravan!";
	case KodoviGresaka::SuvisanParametar:
		std::cout << "Zadan je suvisan parametar nakon komande!";
	}
}

bool UnosKomande (Komande &komanda,Smjerovi &smjer,int &x, int &y, KodoviGresaka &greska)
{
	std::vector<std::string> komande {"P1","P>","B","D","PO","Z","K"};
	std::vector<std::string> smjerovi {"GL","G","GD","D","DoD","Do","DoL","L"};
	std::string Unos("");
	std::string param("");
	std::cout << "Unesite komandu: " << std::endl;
	std::cin >> Unos;
	if (std::find(komande.begin(),komande.end(),Unos) != komande.end()) {

		if(Unos == "P1") {
			std::cin >> param;
			if (std::find(smjerovi.begin(),smjerovi.end(),param) != smjerovi.end()) {
				komanda = Komande::PomjeriJednoMjesto;

				if(param == "GL") {
					smjer = Smjerovi::GoreLijevo;
					return true;
				} else if (param =="G") {
					smjer = Smjerovi::Gore;
					return true;
				} else if (param == "GD") {
					smjer = Smjerovi::GoreDesno;
					return true;
				} else if(param == "D") {
					smjer = Smjerovi::Desno;
					return true;
				} else if(param == "DoD") {
					smjer = Smjerovi::DoljeDesno;
					return true;
				} else if (param == "Do") {
					smjer = Smjerovi::Dolje;
					return true;
				} else if(param == "DoL") {
					smjer = Smjerovi::DoljeLijevo;
					return true;
				} else if(param ==  "L") {
					smjer = Smjerovi::Lijevo;
					return true;
				}
			}
			greska = KodoviGresaka::NeispravanParametar;
			return false;
		} else if(Unos == "P>") {
			int x1(0), y1(0);
			std::cin >> x >> y;
			if (!std::cin) {
				greska = KodoviGresaka::NeispravanParametar;
				return false;
			} else {
				x = x1;
				y = y1;
				komanda = Komande::PomjeriDalje;
				return true;
			}
		} else if(Unos == "B") {
			int x1(0), y1(0);
			std::cin >> x >> y;
			if (!std::cin) {
				greska = KodoviGresaka::NeispravanParametar;
				return false;
			} else {
				x = x1;
				y = y1;
				komanda = Komande::Blokiraj;
				return true;
			}
		} else if (Unos == "D") {
			int x1(0), y1(0);
			std::cin >> x >> y;
			if (!std::cin) {
				greska = KodoviGresaka::NeispravanParametar;
				return false;
			} else {
				x = x1;
				y = y1;
				komanda = Komande::Deblokiraj;
				return true;
			}
		} else if (Unos == "PO") {
			komanda = Komande::PrikaziOkolinu;
			return true;
		} else if (Unos == "Z") {
			komanda = Komande::ZavrsiIgru;
			return true;
		} else if (Unos =="K") {
			komanda = Komande::KreirajIgru;
			return true;
		}
	}
	return false;

	greska = KodoviGresaka::PogresnaKomanda;
	return false;

}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0)
{
	switch (komanda) {
	case Komande::PomjeriJednoMjesto:
		switch (Idi(polja,x,y,p_smjer)) {
		case Status::KrajPobjeda:
			std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
			throw std::runtime_error ("Igra zavrsena");
		case Status::KrajPoraz:
			std::cout << "Nagazili ste na minu" << std::endl;
			throw std::runtime_error ("Igra zavrsena");
		case Status::NijeKraj:
			break;
		}
		std::cout << "Tekuca pozicija igrača je (x,y)" << std::endl;
		break;
	case Komande::PomjeriDalje:
		Idi(polja,x,y,p_x,p_y);
		std::cout << "Tekuca pozicija igrača je (x,y)" << std::endl;
		break;
	case Komande::Blokiraj:
		BlokirajPolje(polja,p_x,p_y);
		break;
	case Komande::Deblokiraj:
		DeblokirajPolje(polja,p_x,p_y);
		break;
	case Komande::PrikaziOkolinu: {
		auto mat = PrikaziOkolinu(polja,x,y);
		for (auto i : mat) {
			for (auto i2 : i) {
				std::cout << i2 << " ";
			}
			std::cout  << std::endl;
		}
	}
	case Komande::ZavrsiIgru: {
		throw std::runtime_error ("Igra zavrsena");
	}
	case Komande::KreirajIgru: {
		std::cout << "Unesite broj polja: ";
		int n(0);
		std::cin >> n;
		std::cout << "Unesite pozicije mina: ";
		std::vector<std::vector<int>> matmine;
		std::complex<int> z1;
		while(1) {
			if (std::cin.peek() == '.') break;
			std::cin>> z1;
			std::cin.ignore(1000,'\n');
			if (!std::cin or z1.real() >= n or z1.imag() >= n) {
				std::cin.clear();
				std::cout << "wtf" << std::endl;
				
			} else{
			std::cout << z1 << std::endl;
			
			if (std::cin.peek() == '.') break;
			}
		}
		polja = KreirajIgru(n,matmine);
	}
	}
}

int main ()
{
	Komande komanda;
	int x(0),y(0);
	int x1(0),y1(0);
	KodoviGresaka greska;
	Smjerovi smjer;
	Tabla polja(0);
	while (true) {
		std::cout << "Unesite komandu: ";

		if (UnosKomande(komanda,smjer,x1,y1,greska)) {
			if (komanda ==Komande::ZavrsiIgru) break;
			try {
				IzvrsiKomandu(komanda,polja,x,y,smjer,x1,y1);
			} catch (std::runtime_error) {
				return 0;
			}


		}
	}

	return 0;
}
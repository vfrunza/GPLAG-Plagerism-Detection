/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/

#include <iostream>
#include <exception>
#include <stdexcept>
#include <vector>

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
	PogresnaKomanda, NedostajeParmetar, SuvisanParametar, NeispravanParametar
};

enum class Komande {
	PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine) {
	Tabla t;
	t.resize(n);
	for(int i = 0; i < n; i++) {
		t[i].resize(n);
	}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			t[i][j] = Polje::Prazno;
			
	for(int i = 0; i < mine.size(); i++) {
		if(mine[i].size() != 2)
			throw std::domain_error("Ilegalan format zadavanja mina");
			
		if(mine[i][0] >= n || mine[i][1] >= n)
			throw std::domain_error("Ilegalne pozicije mina");
			
		t[mine[i][0]][mine[i][1]] = Polje::Mina;
	}
	
	return t;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y) {
	if(x < 0 || y < 0 || x >= polja.size() || y >= polja.size())
		throw std::domain_error("Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji");
		
	std::vector<std::vector<int>> okolina;
	
	for(int i = x - 1; i <= x + 1; i++) {
		if(i < 0 || i >= polja.size())
			continue;
		
		okolina.resize(okolina.size() + 1);
		for(int j = y - 1; j <= y + 1; j++) {
			if(j < 0 || j >= polja.size())
				continue;
			
			int brMina = 0;
			for(int k = i - 1; k <= i + 1; k++) {
				if(k < 0 || k >= polja.size())
					continue;
					
				for(int l = j - 1; l <= j + 1; l++) {
					if(l < 0 || l >= polja.size() || (k == i && l == j))
						continue;
					
					if(polja[k][l] == Polje::Mina)
						brMina++;
				}
			}
			okolina[i].push_back(brMina);
		}
		
	}
	return okolina;
}

void BlokirajPolje(Tabla &polja, int x, int y) {
	if(x < 0 || y < 0 || x >= polja.size() || y >= polja.size())
		throw std::domain_error("Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji");
		
	switch(polja[x][y]) {
		case Polje::Prazno:
			polja[x][y] = Polje::BlokiranoPrazno;
			break;
		case Polje::Posjeceno:
			polja[x][y] = Polje::BlokiranoPosjeceno;
			break;
		case Polje::Mina:
			polja[x][y] = Polje::BlokiranoMina;
			break;
		default:
			break;
	}
}

void DeblokirajPolje(Tabla &polja, int x, int y) {
	if(x < 0 || y < 0 || x >= polja.size() || y >= polja.size())
		throw std::domain_error("Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji");
	
	switch(polja[x][y]) {
		case Polje::BlokiranoPrazno:
			polja[x][y] = Polje::Prazno;
			break;
		case Polje::BlokiranoPosjeceno:
			polja[x][y] = Polje::Posjeceno;
			break;
		case Polje::BlokiranoMina:
			polja[x][y] = Polje::Mina;
			break;
		default:
			break;
	}
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer) {
	int deltaX = 0;
	int deltaY = 0;
	
	switch(smjer) {
	case Smjerovi::Desno:
		deltaY = 1;
		break;
	case Smjerovi::Dolje:
		deltaX = 1;
		break;
	case Smjerovi::DoljeDesno:
		deltaX = 1;
		deltaY = 1;
		break;
	case Smjerovi::DoljeLijevo:
		deltaY = -1;
		deltaX = 1;
		break;
	case Smjerovi::Gore:
		deltaX = -1;
		break;
	case Smjerovi::GoreDesno:
		deltaX = -1;
		deltaY = 1;
		break;
	case Smjerovi::GoreLijevo:
		deltaY = -1;
		deltaX = -1;
		break;
	default:
		break;
	}
	
	if(x + deltaX < 0 || y + deltaY < 0 || x + deltaX >= polja.size() || y + deltaY >= polja.size())
		throw std::out_of_range("IIzlazak van igrace table");
		
	if(polja[x + deltaX][y + deltaY] == Polje::BlokiranoPrazno || polja[x + deltaX][y + deltaY] == Polje::BlokiranoPosjeceno || polja[x + deltaX][y + deltaY] == Polje::BlokiranoMina)
		throw std::logic_error("Blokirano polje");
		
	polja[x][y] = Polje::Posjeceno;
	x += deltaX;
	y += deltaY;
	
	if(polja[x][y] == Polje::Mina) {
		for(int i = 0; i < polja.size(); i++)
			for(int j = 0; j < polja.size(); j++)
				polja[i][j] = Polje::Prazno;
				
		return Status::KrajPoraz;
	}
		
	int brPraznih = 0;
	for(int i = 0; i < polja.size(); i++)
		for(int j = 0; j < polja.size(); j++)
			if(polja[i][j] == Polje::Prazno)
				brPraznih++;
				
	if(brPraznih <= 1)
		return Status::KrajPobjeda;
	else
		return Status::NijeKraj;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y) {
	if(novi_x < 0 || novi_y < 0 || novi_x >= polja.size() || novi_y >= polja.size())
		throw std::out_of_range("IIzlazak van igrace table");
		
	if(polja[novi_x][novi_y] == Polje::BlokiranoPrazno || polja[novi_x][novi_y] == Polje::BlokiranoPosjeceno || polja[novi_x][novi_y] == Polje::BlokiranoMina)
		throw std::logic_error("Blokirano polje");
		
	polja[x][y] = Polje::Posjeceno;
	x = novi_x;
	y = novi_y;
		
	if(polja[x][y] == Polje::Mina) {
		for(int i = 0; i < polja.size(); i++)
			for(int j = 0; j < polja.size(); j++)
				polja[i][j] = Polje::Prazno;
				
		return Status::KrajPoraz;
	}
	
	int brPraznih = 0;
	for(int i = 0; i < polja.size(); i++)
		for(int j = 0; j < polja.size(); j++)
			if(polja[i][j] == Polje::Prazno)
				brPraznih++;
				
	if(brPraznih <= 1)
		return Status::KrajPobjeda;
	else
		return Status::NijeKraj;
}

//std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y) {
	
//}

void PrijaviGresku (KodoviGresaka kod) {
	switch(kod) {
	case KodoviGresaka::PogresnaKomanda:
		std::cout << "Nerazumljiva komanda!" << std::endl;
		break;
	case KodoviGresaka::NedostajeParmetar:
		std::cout << "Komanda trazi parametar koji nije naveden!" << std::endl;
		break;
	case KodoviGresaka::SuvisanParametar:
		std::cout << "Zadan je suvisan parametar nakon komande!" << std::endl;
		break;
	case KodoviGresaka::NeispravanParametar:
		std::cout << "Parametar komande nije ispravan!" << std::endl;
		break;
	default:
		break;
	}
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska) {
	std::string k;
	std::getline(std::cin, k, ' ');
	
	if(k == "P1") {
		std::string s;
		std::getline(std::cin, s, ' ');
		std::string v;
		std::getline(std::cin, v);
		if(!s.empty() && !v.empty()) {
			greska = KodoviGresaka::SuvisanParametar;
			return false;
		}
		if(s == "GL" || (s.empty() && v == "GL")) {
			smjer = Smjerovi::GoreLijevo;
		}
		else if(s == "G" || (s.empty() && v == "G")) {
			smjer = Smjerovi::Gore;
		}
		else if(s == "GD" || (s.empty() && v == "GD")) {
			smjer = Smjerovi::GoreDesno;
		}
		else if(s == "D" || (s.empty() && v == "D")) {
			smjer = Smjerovi::Desno;
		}
		else if(s == "DoD" || (s.empty() && v == "DoD")) {
			smjer = Smjerovi::DoljeDesno;
		}
		else if(s == "Do" || (s.empty() && v == "Do")) {
			smjer = Smjerovi::Dolje;
		}
		else if(s == "DoL" || (s.empty() && v == "DoL")) {
			smjer = Smjerovi::DoljeLijevo;
		}
		else if(s == "L" || (s.empty() && v == "L")) {
			smjer = Smjerovi::Lijevo;
		}
		else if(s.empty() && v.empty()) {
			greska = KodoviGresaka::NedostajeParmetar;
			return	false;
		}
		else {
			greska = KodoviGresaka::NeispravanParametar;
			return	false;
		}
		komanda = Komande::PomjeriJednoMjesto;
	}
	else if(k == "P>") {
		//int x;
		//int y;
		std::string br;
		try {
			std::getline(std::cin, br, ' ');
			x = std::stoi(br);
			std::getline(std::cin, br, ' ');
			y = std::stoi(br);
		}
		catch(...) {
			greska = KodoviGresaka::NeispravanParametar;
			return false;
		}

		std::string v;
		std::getline(std::cin, v, ' ');
		if(!v.empty()) {
			greska = KodoviGresaka::SuvisanParametar;
			return false;
		}
		komanda = Komande::PomjeriDalje;
	}
	else if(k == "B") {
		//int x;
		//int y;
		std::string br;
		try {
			std::getline(std::cin, br, ' ');
			x = std::stoi(br);
			std::getline(std::cin, br, ' ');
			y = std::stoi(br);
		}
		catch(...) {
			greska = KodoviGresaka::NeispravanParametar;
			return false;
		}

		std::string v;
		std::getline(std::cin, v, ' ');
		if(!v.empty()) {
			greska = KodoviGresaka::SuvisanParametar;
			return false;
		}
		komanda = Komande::Blokiraj;
	}
	else if(k == "D") {
		//int x;
		//int y;
		std::string br;
		try {
			std::getline(std::cin, br, ' ');
			x = std::stoi(br);
			std::getline(std::cin, br, ' ');
			y = std::stoi(br);
		}
		catch(...) {
			greska = KodoviGresaka::NeispravanParametar;
			return false;
		}

		std::string v;
		std::getline(std::cin, v, ' ');
		if(!v.empty()) {
			greska = KodoviGresaka::SuvisanParametar;
			return false;
		}
		komanda = Komande::Deblokiraj;
	}
	else if(k == "PO") {
		komanda = Komande::PrikaziOkolinu;
	}
	else if(k == "Z") {
		komanda = Komande::ZavrsiIgru;
	}
	else if(k == "K") {
		komanda = Komande::KreirajIgru;
	}
	else {
		greska = KodoviGresaka::PogresnaKomanda;
		return false;
	}
	
	return true;
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0) {
	int brPolja, X, Y;
	std::string m;
	std::vector<int> temp;
	Status st, st1;
	std::vector<std::vector<int>> mine;
	switch(komanda) {
	case Komande::Blokiraj:
		BlokirajPolje(polja, x, y);
		break;
	case Komande::Deblokiraj:
		DeblokirajPolje(polja, x, y);
		break;
	case Komande::PomjeriDalje:
		st = Idi(polja, x, y, p_x, p_y);
		std::cout << "Tekuca pozicija igrača je (" + std::to_string(x) + "," + std::to_string(y) + ")" << std::endl;
		if(st == Status::KrajPobjeda) {
			std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
			for(int i = 0; i < polja.size(); i++)
				for(int j = 0; j < polja.size(); j++)
					polja[i][j] = Polje::Prazno;
		
			throw std::runtime_error("Igra zavrsena");
		}
		else if(st == Status::KrajPoraz) {
			std::cout << "Nagazili ste na minu" << std::endl;
			for(int i = 0; i < polja.size(); i++)
				for(int j = 0; j < polja.size(); j++)
					polja[i][j] = Polje::Prazno;
		
			throw std::runtime_error("Igra zavrsena");
		}
		break;
	case Komande::PomjeriJednoMjesto:
		st1 = Idi(polja, x, y, p_smjer);
		std::cout << "Tekuca pozicija igrača je (" + std::to_string(x) + "," + std::to_string(y) + ")" << std::endl;
		if(st1 == Status::KrajPobjeda) {
			std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
			for(int i = 0; i < polja.size(); i++)
				for(int j = 0; j < polja.size(); j++)
					polja[i][j] = Polje::Prazno;
		
			throw std::runtime_error("Igra zavrsena");
		}
		else if(st1 == Status::KrajPoraz) {
			std::cout << "Nagazili ste na minu" << std::endl;
			for(int i = 0; i < polja.size(); i++)
				for(int j = 0; j < polja.size(); j++)
					polja[i][j] = Polje::Prazno;
		
			throw std::runtime_error("Igra zavrsena");
		}
		break;
	case Komande::PrikaziOkolinu:
		break;
	case Komande::KreirajIgru:
		do {
			std::cout << "Unesite broj polja: "; // << std::endl;
			std::cin >> brPolja;
		} while(brPolja <= 0);
		
		do {
			std::getline(std::cin, m);
			if(m == ".")
				break;
			
			if(m[0] != '(' || m[m.size()-1] != ')') {
				std::cout << "Greska, unesite ponovo!" << std::endl;
				continue;
			}
			std::sscanf(m.c_str(), "(%d,%d)", &X, &Y);
			temp.clear();
			temp.push_back(X);
			temp.push_back(Y);
			mine.push_back(temp);
			//std::cin >> c1 >> X >> c2 >> Y >> c3;
			//if(c1 == '(' && c2 == "," && c3 == ")" && X >= 0 && X < brPolja && Y >= 0 && Y < brPolja) {
				
		} while(m != ".");
		
		polja = KreirajIgru(brPolja, mine);
		break;
	case Komande::ZavrsiIgru:
		for(int i = 0; i < polja.size(); i++)
			for(int j = 0; j < polja.size(); j++)
				polja[i][j] = Polje::Prazno;
		
		throw std::runtime_error("Igra zavrsena");
	}
}

int main ()
{
	std::vector<std::vector<int>> mine = {{0,2}, {1,3}, {1,5}, {4,2}, {5,1}, {5,5}} ;
	std::vector<std::vector<Polje>> tabla = KreirajIgru(6, mine);
  int x = 0, y = 0;
  Idi(tabla, x, y, Smjerovi::DoljeDesno);
  std::cout << x << " " << y << std::endl;
  Idi(tabla, x, y, Smjerovi::Dolje);
  std::cout << x << " " << y << std::endl;
	return 0;
}
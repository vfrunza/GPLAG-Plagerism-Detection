#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

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
	Tabla igrica(n, std::vector<Polje>(n, Polje::Prazno));
	
	for(int i = 0; i < mine.size(); i++) {
		if(mine[i].size() != 2) throw std::domain_error("Ilegalan format zadavanja mina");
		if(mine[i][1] >= n) throw std::domain_error("Ilegalne pozicije mina");
	}
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			for(int k = 0; k < mine.size(); k++)
				if(i == mine[k][0] && j == mine[k][1]) igrica[i][j] = Polje::Mina;
	
	return igrica;
}

void ZavrsiIgru(Tabla &tabla) {
	for(int i = 0; i < tabla.size(); i++) {
		for(int j = 0; j < tabla[i].size(); j++)
			tabla[i][j] = Polje::Prazno;
	}
	
	throw std::runtime_error("Igra zavrsena");
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y) {
	std::vector<std::vector<int>> okolina(3);
	if(x >= polja.size() || y >= polja.size() || x < 0 || y < 0) throw std::domain_error("Polje (x,y) ne postoji");
	
	int m = 0;
	
	for(int i = x - 1; i <= x + 1; i++) {
		for(int j = y - 1; j <= y + 1; j++) {
			int brojac = 0;
			for(int k = i - 1; k <= i + 1; k++) {
				for(int l = j - 1; l <= j + 1; l++) {
					if(i >= 0 && i < polja.size() && j >= 0 && j < polja[i].size() && k >= 0 && k < polja.size() && l >= 0 && l < polja[i].size() && !(k == i && j == l) && polja[k][l] == Polje::Mina)
						brojac++;
				}
			}
			
			okolina[m].push_back(brojac);
		}
		m++;
	}


	return okolina;
	
}

void BlokirajPolje(Tabla &polja, int x, int y) {
	if(x < 0 || y < 0 || x >= polja.size() || y >= polja.size()) throw std::domain_error("Polje (x,y) ne postoji");
	
	if(polja[x][y] == Polje::Prazno) polja[x][y] = Polje::BlokiranoPrazno;	
	else if(polja[x][y] == Polje::Posjeceno) polja[x][y] = Polje::BlokiranoPosjeceno;
	else if(polja[x][y] == Polje::Mina) polja[x][y] = Polje::BlokiranoMina;
}

void DeblokirajPolje(Tabla &polja, int x, int y) {
	if(x < 0 || y < 0 || x >= polja.size() || y >= polja.size()) throw std::domain_error("Polje (x,y) ne postoji");
	
	if(polja[x][y] == Polje::BlokiranoPrazno) polja[x][y] = Polje::Prazno;
	else if(polja[x][y] == Polje::BlokiranoPosjeceno) polja[x][y] == Polje::Posjeceno;
	else if(polja[x][y] == Polje::BlokiranoMina) polja[x][y] == Polje::Mina;
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer) {
	int novi_x = x;
	int novi_y = y;
	
	switch(smjer) {
		case Smjerovi::Gore:
			novi_x--;
			break;
		case Smjerovi::Desno:
			novi_y++;
			break;
		case Smjerovi::Dolje:
			novi_x++;
			break;
		case Smjerovi::Lijevo:
			novi_y--;
			break;
		case Smjerovi::GoreDesno:
			novi_x--;
			novi_y++;
			break;
		case Smjerovi::DoljeDesno:
			novi_x++;
			novi_y++;
			break;
		case Smjerovi::DoljeLijevo:
			novi_x++;
			novi_y--;
			break;
		case Smjerovi::GoreLijevo:
			novi_x--;
			novi_y--;
			break;
	}
	
	if(novi_x < 0 || novi_y < 0 || novi_x >= polja.size() || novi_y >= polja[0].size())
		throw std::out_of_range("Izlazak van igrace table");
	if(polja[novi_x][novi_y] == Polje::BlokiranoPosjeceno || polja[novi_x][novi_y] == Polje::BlokiranoPrazno || polja[novi_x][novi_y] == Polje::BlokiranoMina)
		throw std::logic_error("Blokirano polje");
	
	//krajPoraz
	if(polja[novi_x][novi_y] == Polje::Mina) {
		for(int i = 0; i < polja.size(); i++) {
			for(int j = 0; j < polja[i].size(); j++) 
				polja[i][j] = Polje::Prazno;
		}
		return Status::KrajPoraz;
	}
	
	//krajPobjeda
	
	bool prazno = false;
	for(int i = 0; i < polja.size(); i++)
		for(int j = 0; j < polja[i].size(); j++)
			if(polja[i][j] == Polje::Prazno) prazno = true;
	
	if(!prazno) return Status::KrajPobjeda;
	
	//ni poraz ni pobjeda
	
	
	polja[x][y] = Polje::Posjeceno;
	x = novi_x;
	y = novi_y;
	
	return Status::NijeKraj;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y) {
	if(novi_x >= polja.size() || novi_y >= polja.size() || novi_x < 0 || novi_y < 0) throw std::out_of_range("Izlazak van igrace table");
	if(polja[novi_x][novi_y] == Polje::BlokiranoPosjeceno || polja[novi_x][novi_y] == Polje::BlokiranoPrazno || polja[novi_x][novi_y] == Polje::BlokiranoMina) 
		throw std::logic_error("Blokirano polje");
	//ako je mina - poraz
	if(polja[novi_x][novi_y] ==  Polje::Mina) {
			for(int i = 0; i < polja.size(); i++)
				for(int j = 0; j < polja[i].size(); j++) polja[i][j] = Polje::Prazno;
			return Status::KrajPoraz;
	}
	//ako su sva posjecena - pobjeda
	bool prazno = false;
	for(int i = 0; i < polja.size(); i++) 
		for(int j = 0; j < polja[i].size(); j++) 
			if(polja[i][j] == Polje::Prazno) prazno = true;
	
	if(!prazno) return Status::KrajPobjeda;
	
	//ako nije ni poraz ni pobjeda, postavi nove koordinate, vrati NijeKraj
	polja[x][y] = Polje::Posjeceno;
	x = novi_x;
	y = novi_y;
	return Status::NijeKraj;
}

void PrijaviGresku(KodoviGresaka greska) {
	switch(greska) {
		case KodoviGresaka::PogresnaKomanda:
			std::cout << "Nerazumljiva komanda!" << std::endl; 
			break;
		case KodoviGresaka::NedostajeParametar:
			std::cout << "Komanda trazi parametar koji nije naveden!" << std::endl;
			break;
		case KodoviGresaka::NeispravanParametar:
			std::cout << "Parametar komande nije ispravan!" << std::endl;
			break;
		case KodoviGresaka::SuvisanParametar:
			std::cout << "Zadan je suvisan parametar nakon komande!" << std::endl;
			break;
	}
}

void IzbrisiRazmak(std::string &s, int i) {
	while(i < s.length())
	{
		if(s[i] == ' ') s.erase(i,1);
		if(s[i] != ' ') break;
		i++;
	}
}

void VratiXY(std::string unos, int m, int &x, int &y) {
	for(int k = 0; k < 2; k++) {
		int broj = 0;
		while(m < unos.length() && (unos[m] >= '0' && unos[m] <= '9')) {
			broj += unos[m] - '0';
			broj *= 10;
			m++;
		}
		broj /= 10;
		if(k == 0) x = broj;
		if(k == 1) y = broj;
		IzbrisiRazmak(unos,m);
	}
}

bool IspravanParametar(std::string unos, int m, KodoviGresaka &greska) {
	bool ima_razmak = false;
	while(m < unos.length()) {
		if(unos[m] == ' ') ima_razmak = true;
		if(!((unos[m] >= '0' && unos[m] <= '9') || unos[m] == ' ')) {
			greska = KodoviGresaka::NeispravanParametar;
			return false;
		}
		m++;
	}
	if(!ima_razmak) {
		greska = KodoviGresaka::NedostajeParametar;
		return false;
	}
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska) {
	std::string unos;
	std::vector<std::string> tabela = {"P1", "P>", "B", "D", "PO", "Z", "K"};
	
	std::getline(std::cin, unos);
	IzbrisiRazmak(unos,0);
	
	for(int i = 0; i < tabela.size(); i++) {
		std::string pomocni = tabela[i];
		int j = 0;
		int brojac = 0;
		while(j < pomocni.length()) {
			if(pomocni[j] == unos[j]) brojac++;
			j++;
		}
		IzbrisiRazmak(unos,j);
		
		if(brojac == pomocni.length()) {
			if(unos.length() != brojac) {
				if(i == 0) {
					std::vector<std::string> pomijeranja = {"GL", "G", "GD", "D", "DoD", "Do", "DoL", "L"};
					int n = 2;
					while(n < unos.length()) {
						if(unos[n] != 'G' && unos[n] != 'L' && unos[n] != 'D' && unos[n] != 'o' && unos[n] != ' ') {
							greska = KodoviGresaka::NeispravanParametar;
							return false;
						}
						n++;
					}
					
					komanda = Komande::PomjeriJednoMjesto;
					
					std::string pom_za_pomijeranje;
					n = 2;
					while(n < unos.length() && unos[n] != ' ') {
						pom_za_pomijeranje.push_back(unos[n]);
						n++;
					}
					
					int index;
					for(index = 0; index < pomijeranja.size(); index++) 
						if(pom_za_pomijeranje == pomijeranja[index]) break;
					
					switch(index) {
						case 0:
							smjer = Smjerovi::GoreLijevo;
							return true;
						case 1:
							smjer = Smjerovi::Gore;
							return true;
						case 2:
							smjer = Smjerovi::GoreDesno;
							return true;
						case 3:
							smjer = Smjerovi::Desno;
							return true;
						case 4:
							smjer = Smjerovi::DoljeDesno;
							return true;
						case 5:
							smjer = Smjerovi::Dolje;
							return true;
						case 6:
							smjer = Smjerovi::DoljeLijevo;
							return true;
						case 7:
							smjer = Smjerovi::Lijevo;
							return true;
					}
				}
				
				else if(i == 1 || i == 2 || i == 3) {
					if((i != 1 && unos.length() == 1) || (i == 1 && unos.length() == 2)) {
						greska = KodoviGresaka::NedostajeParametar;
						return false;
					}
					
					int m;
					if(i == 1) m = 2;
					else m = 1;
					
					if(!IspravanParametar(unos, m, greska)) return false;
					
					if(i == 1) m = 2;
					else m = 1;
					
					VratiXY(unos, m, x, y);
					
					if(i == 1) komanda = Komande::PomjeriDalje;
					if(i == 2) komanda = Komande::Blokiraj;
					if(i == 3) komanda = Komande::Deblokiraj;
					return true;
				}
				
				else {
					greska = KodoviGresaka::SuvisanParametar;
					return false;
				}
			}
			else {
				if(i == 0 || i == 1 || i == 2 || i == 3) {
					greska = KodoviGresaka::NedostajeParametar;
					return false;
				}
				
				switch(i) {
					case 4:
						komanda = Komande::PrikaziOkolinu;
						return true;
					case 5:
						komanda = Komande::ZavrsiIgru;
						return true;
					case 6:
						komanda = Komande::KreirajIgru;
						return true;
				}
			}
		}
	}
	
	greska = KodoviGresaka::PogresnaKomanda;
	return false;
}

std::vector<std::vector<int>> UnesiMine(int n) {
	std::vector<std::vector<int>> mine;
	int x, y;
	char znak;
	std::vector<int> baza_x;
	std::vector<int> baza_y;
	
	std::cout << "Unesite pozicije mina: ";
	
	for(;;) {
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cin >> znak;
		if(znak == '.') break;
		if(!std::cin || znak != '(' || std::cin.peek() == '\n' || std::cin.peek() == ' ') {
			std::cout << "Greska, unesite ponovo!" << std::endl;
			std::cin.clear();
			std::cin.ignore(100000,'\n');
			continue;
		}
		std::cin >> x;
		if(!std::cin || x < 0 || x > n || std::cin.peek() == '\n' || std::cin.peek() == ' ' || std::cin.peek() != ',') {
			std::cout << "Greska, unesite ponovo!" << std::endl;
			std::cin.clear();
			std::cin.ignore(100000, '\n');
			continue;
		}
		std::cin >> znak;
		if(!std::cin || znak != ',' || std::cin.peek() == '\n' || std::cin.peek() == ' ') {
			std::cout << "Greska, unesite ponovo!" << std::endl;
			std::cin.clear();
			std::cin.ignore(100000, '\n');
			continue;
		}
		std::cin >> y;
		if(!std::cin || y < 0 || y > n || std::cin.peek() == '\n' || std::cin.peek() == ' ' || std::cin.peek() != ')') {
			std::cout << "Greska, unesite ponovo!" << std::endl;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			continue;
		}
		std::cin >> znak;
		bool tacka = false;
		if(std::cin.peek() == '.') tacka = true;
		if(!std::cin || znak != ')' || std::cin.peek() != '\n' || tacka) {
			if(tacka) break;
			std::cout << "Greska, unesite ponovo!" << std::endl;
			std::cin.clear();
			std::cin.ignore(100000, '\n');
			continue;
		}
		baza_x.push_back(x);
		baza_y.push_back(y);
		if(std::cin.peek() == '.') break;
		std::cin.clear();
		std::cin.ignore(10000,'\n');
	}
	
	mine.resize(baza_x.size());
	for(int i = 0; i < mine.size(); i++)
		mine[i].resize(2);
		
	for(int i = 0; i < mine.size(); i++) {
		mine[i][0] = baza_x[i];
		mine[i][1] = baza_y[i];
	}
	
	return mine;

}

void IspisiOkolinu(std::vector<std::vector<int>> okolina) {
	for(int i = 0; i < okolina.size(); i++) {
		for(int j = 0; j < okolina[i].size(); j++)
			std::cout << okolina[i][j] << " ";
		std::cout << std::endl;
	}
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0) {
	Status trenutni;
	
	try {
	switch(komanda){
		case Komande::PomjeriJednoMjesto: {	
			trenutni = Idi(polja, x, y, p_smjer);
			if(trenutni == Status::NijeKraj) {
				std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")" << std::endl;
			}
			else if(trenutni == Status::KrajPoraz) {
				std::cout << "Nagazili ste na minu" << std::endl;
				ZavrsiIgru(polja);
			}
			else if(trenutni == Status::KrajPobjeda) {
				std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
				ZavrsiIgru(polja);
			}
		}
			break;
		case Komande::PomjeriDalje: {
			trenutni = Idi(polja, x, y, p_x, p_y);
			if(trenutni == Status::NijeKraj) {
				std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")" << std::endl;
			}
			else if(trenutni == Status::KrajPoraz) {
				std::cout << "Nagazili ste na minu" << std::endl;
				ZavrsiIgru(polja);
			}
			else if(trenutni == Status::KrajPobjeda) {
				std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
				ZavrsiIgru(polja);
			}
		}		
			break;
		case Komande::Blokiraj: {
			BlokirajPolje(polja, x, y);
		}
			break;
		case Komande::Deblokiraj: {
			DeblokirajPolje(polja, x, y);
		}
			break;
		case Komande::PrikaziOkolinu: {
			std::vector<std::vector<int>> okolina;
			okolina = PrikaziOkolinu(polja, x, y);
			IspisiOkolinu(okolina);
		}
			break;
		case Komande::ZavrsiIgru: {
			ZavrsiIgru(polja);
		}
			break;
		case Komande::KreirajIgru: {
			int n; 
			std::cout << "Unesite broj polja: ";
			std::cin >> n;
			std::vector<std::vector<int>> mine;
			mine = UnesiMine(n);
			polja = KreirajIgru(n, mine);
		}	
			break;
		}
	}
	catch(std::runtime_error izuzetak) {
		throw std::runtime_error(izuzetak.what());
	}
	catch(std::domain_error izuzetak) {
		std::cout << izuzetak.what() << std::endl;
	}
	catch(std::out_of_range izuzetak) {
		std::cout << izuzetak.what() << std::endl;
	}
	catch(std::logic_error izuzetak) {
		std::cout << izuzetak.what() << std::endl;
	}
	
	
}

int main ()
{
	Komande komanda;
	Smjerovi smjer;
	int x, y;
	KodoviGresaka greska;
	bool unos;
	Tabla polja;
	
	
	for(;;)
	{
		try {
			std::cout << "Unesi komandu: ";
			unos = UnosKomande(komanda, smjer, x, y, greska);
			if(!unos) {
				PrijaviGresku(greska);
			}
			else {
				IzvrsiKomandu(komanda, polja, x, y, smjer);
			}
		}
		catch(std::runtime_error izuzetak) {
			std::cout << izuzetak.what() << std::endl << "Dovidjenja!";
			return 0;
		}
		catch(...) {
			std::cout << "Neki drugi izuzetak";
		}
		
		
	}
	return 0;
}
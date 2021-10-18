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
	PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};

typedef std::vector<std::vector<Polje>> Tabla;

std::string FormirajTekst(int x, int y) {
	std::string tekst("Polje (");
	tekst += std::to_string(x);
	tekst += ",";
	tekst += std::to_string(y);
	tekst += ") ne postoji";
	return tekst;
}

void OcistiTablu(Tabla &tab) {
	for(int i = 0; i < tab.size(); i++)
		for(int j = 0; j < tab.size(); j++)
			tab[i][j] = Polje::Prazno;
}

Status ProvjeriStatus(Tabla tab, int x, int y) {
	if(tab[x][y] == Polje::Mina) {
		OcistiTablu(tab);	
		return Status::KrajPoraz;
	}
	bool krajPobjeda = true;
	for(int i = 0; i < tab.size(); i++)
		for(int j = 0; j < tab.size(); j++)
			if((i != x || j != y) && (tab[i][j] == Polje::Prazno || tab[i][j] == Polje::BlokiranoPrazno)) {
				krajPobjeda = false;
				i = tab.size();
				break;
			}
	if(krajPobjeda) return Status::KrajPobjeda;
	return Status::NijeKraj;
}

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine) {
	for(int i = 0; i < mine.size(); i++) {
		if(mine[i].size() != 2) throw std::domain_error("Ilegalan format zadavanja mina");
	}
	
	Tabla tab(n);
	for(int i = 0; i < n; i++) {
		tab[i].resize(n);
		for(int j = 0; j < n; j++)
			tab[i][j] = Polje::Prazno;
	}
	
	for(int i = 0; i < mine.size(); i++) {
		if(mine[i][0] < 0 || mine[i][0] >= n || mine[i][1] < 0 || mine[i][1] >= n)
			throw std::domain_error("Ilegalne pozicije mina");
	}
	if(n <= 0) throw std::domain_error("Ilegalna velicina");
	for(int i = 0; i < mine.size(); i++)
		tab[mine[i][0]] [mine[i][1]] = Polje::Mina;
	return tab;
}

std::vector<std::vector<int>> PrikaziOkolinu(Tabla tab, int x, int y) {
	if(x < 0 || y < 0 || x >= tab.size() || y >= tab.size()) throw std::domain_error(FormirajTekst(x, y));
	
	std::vector<std::vector<int>> mat;
	
	for(int i = 1; i >= -1; i--) {
		int tmp_x = x-i;
		std::vector<int> tmp_r;
		for(int j = 1; j >= -1; j--) {
			int br = 0, tmp_y = y-j;
			for(int k = tmp_x - 1; k <= tmp_x + 1; k++)
				for(int l = tmp_y - 1; l <= tmp_y + 1; l++)
					if(k >= 0 && l >= 0 && k < tab.size() && l < tab.size() && (k != tmp_x || l != tmp_y) &&
						(tab[k][l] == Polje::Mina || tab[k][l] == Polje::BlokiranoMina ))
							br++;
				
			tmp_r.push_back(br);
			br=0;
		}
		mat.push_back(tmp_r);
		tmp_r.resize(0);
	}
	return mat;
}

void BlokirajPolje(Tabla &tab, int x, int y) {
	if(x < 0 || y < 0 || x >= tab.size() || y >= tab.size()) throw std::domain_error(FormirajTekst(x,y));
	if(tab[x][y] == Polje::Prazno) tab[x][y] = Polje::BlokiranoPrazno;
	if(tab[x][y] == Polje::Posjeceno) tab[x][y] = Polje::BlokiranoPosjeceno;
	if(tab[x][y] == Polje::Mina) tab[x][y] = Polje::BlokiranoMina;
}

void DeblokirajPolje(Tabla &tab, int x, int y) {
	if(x < 0 || y < 0 || x >= tab.size() || y >= tab.size()) throw std::domain_error(FormirajTekst(x, y));
	if(tab[x][y] == Polje::BlokiranoPrazno) tab[x][y] = Polje::Prazno;
	if(tab[x][y] == Polje::BlokiranoPosjeceno) tab[x][y] = Polje::Posjeceno;
	if(tab[x][y] == Polje::BlokiranoMina) tab[x][y] = Polje::Mina;
}

Status Idi(Tabla &tab, int &cur_x, int &cur_y, Smjerovi smjer) {
	int new_x = cur_x, new_y = cur_y;
	
	switch(smjer) {
		case Smjerovi::GoreLijevo :
			new_x -= 1;
			new_y -= 1;
			break;
		case Smjerovi::Gore :
			new_x -= 1;
			break;
		case Smjerovi::GoreDesno :
			new_x -= 1;
			new_y += 1;
			break;
		case Smjerovi::Lijevo :
			new_y -= 1;
			break;
		case Smjerovi::Desno :
			new_y += 1;
			break;
		case Smjerovi::DoljeLijevo :
			new_x += 1;
			new_y -= 1;
			break;
		case Smjerovi::Dolje :
			new_x += 1;
			break;
		case Smjerovi::DoljeDesno :
			new_x += 1;
			new_y += 1;
			break;
	}
	
	if(new_x < 0 || new_y < 0 || new_x >= tab.size() || new_y >= tab.size()) throw std::out_of_range("Izlazak van igrace table");
	Polje polje = tab[new_x][new_y];
	if(polje == Polje::BlokiranoPosjeceno || polje == Polje::BlokiranoPrazno || polje == Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
	tab[cur_x][cur_y] = Polje::Posjeceno;
	cur_x = new_x; cur_y = new_y;
	return ProvjeriStatus(tab, cur_x, cur_y);
}

Status Idi(Tabla &tab, int &cur_x, int &cur_y, int new_x, int new_y) {
	if(new_x < 0 || new_y < 0 || new_x >= tab.size() || new_y >= tab.size()) throw std::out_of_range("Izlazak van igrace table");
	Polje polje = tab[new_x][new_y];
	if(polje == Polje::BlokiranoPosjeceno || polje == Polje::BlokiranoPrazno || polje == Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
	tab[cur_x][cur_y] = Polje::Posjeceno;
	cur_x = new_x; cur_y = new_y;
	return ProvjeriStatus(tab, cur_x, cur_y);
}

void PrijaviGresku(KodoviGresaka greska) {
	if(greska == KodoviGresaka::PogresnaKomanda) std::cout << "Nerazumljiva komanda!\n";
	if(greska == KodoviGresaka::NedostajeParametar) std::cout << "Komanda trazi parametar koji nije naveden!\n";
	if(greska == KodoviGresaka::NeispravanParametar) std::cout << "Parametar komande nije ispravan!\n";
	if(greska == KodoviGresaka::SuvisanParametar) std::cout << "Zadan je suvisan parametar nakon komande!\n";
}

void preskociRazmake(std::string u, int &i) {
	while(i < u.length() && u[i] == ' ') i++;
}

bool procitajBrojeve(std::string str, int &i, KodoviGresaka &greska, int &br1, int &br2) {
	preskociRazmake(str, i);
	
	if(i == str.length()) {
		greska = KodoviGresaka::NedostajeParametar;
		return false;
	}
	if(!(str[i] >= '0' && str[i] <= '9')) {
		greska = KodoviGresaka::NeispravanParametar;
		return false;
	}
	else {
		int c1 = i;
		while(i < str.length() && str[i] >= '0' && str[i] <= '9') i++;
		int c2 = i;
		preskociRazmake(str, i);
		if(i == str.length()) {
			greska = KodoviGresaka::NedostajeParametar;
			return false;
		}
		int c3 = i;
		while(i < str.length() && str[i] >= '0' && str[i] <= '9') i++;
		int c4 = i;
		preskociRazmake(str, i);
		if(i < str.length()) {
			greska = KodoviGresaka::NeispravanParametar;
			return false;
		}
		br1 = stoi(str.substr(c1, c2-c1));
		br2 = stoi(str.substr(c3, c4-c3));
		return true;
	}
	return false;
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska) {
	std::string str;
	std::getline(std::cin, str);
	std::vector<std::string> smj {"G", "D", "L", "GL", "GD", "Do", "DoD", "DoL"};
	
	for(int i = 0; i < str.length(); i++) {
		preskociRazmake(str, i);
		if(str.substr(i,2) == "P1") {
			i += 2;
			preskociRazmake(str, i);
			int tmp = i, ind = -1;
			for(int j = 0; j <= 2; j++)
				if(str.substr(i,1) == smj[j]) {tmp = i+1; ind = j;}
			for(int j = 3; j <= 5; j++)
				if(str.substr(i,2) == smj[j]) {tmp = i+2; ind = j;}
			for(int j = 6; j <= 7; j++)
				if(str.substr(i,3) == smj[j]) {tmp = i+3; ind = j;}
			if(tmp != i) {
				preskociRazmake(str, tmp);
				if(tmp < str.length()) {
					greska = KodoviGresaka::SuvisanParametar;
					return false;
				}
			}
			else {
				preskociRazmake(str, tmp);
				if(tmp < str.length()) greska = KodoviGresaka::NeispravanParametar;
				else greska = KodoviGresaka::NedostajeParametar;
				return false;
			}
			if(ind == 0) smjer = Smjerovi::Gore;
			if(ind == 1) smjer = Smjerovi::Desno;
			if(ind == 2) smjer = Smjerovi::Lijevo;
			if(ind == 3) smjer = Smjerovi::GoreLijevo;
			if(ind == 4) smjer = Smjerovi::GoreDesno;
			if(ind == 5) smjer = Smjerovi::Dolje;
			if(ind == 6) smjer = Smjerovi::DoljeDesno;
			if(ind == 7) smjer = Smjerovi::DoljeLijevo;
			komanda = Komande::PomjeriJednoMjesto;
			return true;
		}
		else if (str.substr(i,2) == "P>") {
			i += 2;
			if(procitajBrojeve(str, i, greska, x, y)) {
				komanda = Komande::PomjeriDalje;
				return true;
			}
			return false;
		}
		else if(str[i] == 'B') {
			i++;
			if(procitajBrojeve(str, i, greska, x, y)) {
				komanda = Komande::Blokiraj;
				return true;
			}
			return false;
		}
		else if(str[i] == 'D') {
			i++;
			if(procitajBrojeve(str, i, greska, x, y)) {
				komanda = Komande::Deblokiraj;
				return true;
			}
			return false;
		}
		else if(str.substr(i,2) == "PO") {
			i += 2;	
			preskociRazmake(str, i);
			if(i < str.length()) {
				greska = KodoviGresaka::SuvisanParametar;
				return false;
			}
			komanda = Komande::PrikaziOkolinu;
			return true;
		}
		else if(str[i] == 'Z') {
			i++;
			preskociRazmake(str, i);
			if(i < str.length()) {
				greska = KodoviGresaka::SuvisanParametar;
				return false;
			}
			komanda = Komande::ZavrsiIgru;
			return true;
		}
		else if(str[i] == 'K') {
			i++;
			preskociRazmake(str, i);
			if(i < str.length()) {
				greska = KodoviGresaka::SuvisanParametar;
				return false;
			}
			komanda = Komande::KreirajIgru;
			return true;
		}
		else {
			greska = KodoviGresaka::PogresnaKomanda;
			return false;
		}
	}
	return false;
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi, int, int);

void IspisPomjerajucaKomanda(Status stat, int x, int y, Tabla &polja) {
	std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")\n";
	if(stat == Status::KrajPobjeda) {
		std::cout << "Bravo, obisli ste sva sigurna polja\n";
		IzvrsiKomandu(Komande::ZavrsiIgru, polja, x, y, Smjerovi::Gore, 0, 0);
	}
	if(stat == Status::KrajPoraz) {
		std::cout << "Nagazili ste na minu\n";
		IzvrsiKomandu(Komande::ZavrsiIgru, polja, x, y, Smjerovi::Gore, 0, 0);
	}
	
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0) {
	try {
		if(komanda == Komande::PomjeriJednoMjesto) {
			Status stat = Idi(polja, x, y, p_smjer);
			IspisPomjerajucaKomanda(stat, x, y, polja);
		}
		else if(komanda == Komande::PomjeriDalje) {
			Status stat = Idi(polja, p_x, p_y, x, y);
			IspisPomjerajucaKomanda(stat, x, y, polja);
		}
		else if(komanda == Komande::Blokiraj) BlokirajPolje(polja, x, y);
		else if(komanda == Komande::Deblokiraj) DeblokirajPolje(polja, x, y);
		else if(komanda == Komande::PrikaziOkolinu) {
			auto tmp = PrikaziOkolinu(polja, x, y);
			for(auto i : tmp) {
				for(auto j : i) std::cout << j << " ";
				std::cout << std::endl;
			}
			
		}
		else if(komanda == Komande::ZavrsiIgru) {
			OcistiTablu(polja);
			throw std::runtime_error("Igra zavrsena");
		}
		else if(komanda == Komande::KreirajIgru) {
			int n;
			std::vector<std::vector<int>> mine;
			for(;;) {
				std::cout << "Unesite broj polja: ";
				std::cin >> n;
				if(!std::cin) {
					std::cout << "Greska, unesite ponovo!\n";
					std::cin.clear();
					std::cin.ignore(1000, '\n');
				}
				else if(n <= 0) std::cout << "Greska, unesite ponovo!\n";
				else break;
			}
			std::cout << "Unesite pozicije mina: ";
			for(;;) {
				std::string str;
				getline(std::cin, str);
				if(str == ".") break;
				
				for(int i = 0; i < str.length(); i++) {
					preskociRazmake(str, i);
					if(i == str.length() || str[i++] != '(') {
						std::cout << "Greska, unesite ponovo!\n";
						break;
					}
					int c1 = i;
					while(i < str.length() && str[i] >= '0' && str[i] <= '9') i++;
					int c2 = i;
					preskociRazmake(str, i);
					if(i == str.length() || str[i] != ',') {
						std::cout << "Greska, unesite ponovo!\n";
						break;
					}
					int c3 = ++i;
					while(i < str.length() && str[i] >= '0' && str[i] <= '9') i++;
					int c4 = i;
					preskociRazmake(str, i);
					if(i == str.length() || str[i] != ')') {
						std::cout << "Greska, unesite ponovo!\n";
						break;
					}
					i++;
					preskociRazmake(str, i);
					if(i != str.length()) {
						std::cout << "Greska, unesite ponovo!\n";
						break;
					}
					
					int br1 = stoi(str.substr(c1, c2-c1)), br2 = stoi(str.substr(c3, c4-c3));
					if(br1 >= n || br2 >= n || (br1 == 0 && br2 == 0)) {
						std::cout << "Greska, unesite ponovo!\n";
						break;
					}
					mine.push_back(std::vector<int>{br1,br2});
					break;
				}
			}
			polja = KreirajIgru(n, mine);
		}
		
		
	}
	catch(std::domain_error e) {
		std::cout << e.what() << "\n";
	}
	catch(std::logic_error e) {
		std::cout << e.what() << "\n";
	}
	catch(std::out_of_range e) {
		std::cout << e.what() << "\n";
	}
}



int main ()
{
	try {
		Komande kom;
		Smjerovi sm;
		KodoviGresaka greska;
		Tabla polja;
		int x = 0, y = 0;
		for(;;) {
			std::cout << "Unesite komandu: ";
			
			bool xd =UnosKomande(kom, sm, x, y, greska);
			if (xd) IzvrsiKomandu(kom, polja, x, y, sm);
			else PrijaviGresku(greska);
		}
	}
	catch(std::runtime_error e) {
		std::cout << "Dovidjenja!";
	}

	return 0;
}
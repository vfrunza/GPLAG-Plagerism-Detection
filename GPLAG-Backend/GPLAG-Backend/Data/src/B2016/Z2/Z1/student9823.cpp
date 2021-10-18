/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <sstream>

enum class Polje {
    Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};

typedef std::vector<std::vector<Polje>> Tabla;

template <typename T> std::string PretvoriUString(T x) {
    std::ostringstream s; s << x; return s.str();
}

void IspisiMatricu(std::vector<std::vector<int>> m){
	for(int i=0; i <m.size(); i++){
		for(int j=0; j < m[i].size(); j++){
			std::cout << m[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void IspisiPolja(Tabla polja){
	for(int i=0; i < polja.size(); i++){
		for(int j=0; j < polja[i].size(); j++){
			std::cout << int(polja[i][j]);
		}
		std::cout << std::endl;
	}
}

Tabla KreirajTablu(int broj){
	return Tabla(broj, std::vector<Polje>(broj));
}

std::vector<std::vector<int>> KreirajMatricu(){
	return std::vector<std::vector<int>> (3, std::vector<int>(3));
}

bool Provjeri(const Tabla &polja, int x, int y){
	if(x<0 || x>=polja.size()) return false;
	if(y<0 || y >= polja[x].size()) return false;
	
	return true;
}

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	Tabla nova(KreirajTablu(n));
	for(int i=0; i < n; i++) for(int j=0; j < n; j++) nova[i][j] = Polje::Prazno;
	
	for(int i=0; i < mine.size(); i++) if(mine[i].size() !=2) throw std::domain_error("Ilegalan format zadavanja mina");
	
	for(int i=0; i < mine.size(); i++){
		if(!Provjeri(nova, mine[i][0], mine[i][1])){
			throw std::domain_error("Ilegalne pozicije mina");
		}
	}	
	
	int x, y;
	for(int i=0; i < mine.size(); i++){
		for(int j=0; j < mine[i].size(); j++){
			x = mine[i][0];
			y = mine[i][1];
			nova[x][y] = Polje::Mina;
		}
	}
	return nova;
}

int VrijednostUTacki(const Tabla &polja, int x, int y){
	
	int pox=0, poy=0;
	auto duzina = polja.size();
	
	if((x==0 && y==0) || (x==0 && y==duzina-1) || (x==polja[0].size()-1 && y==0) || (x==polja[duzina-1].size()-1 && y == duzina-1) ){ pox=2; poy = 2; }
	else if(x == 0 || x == polja[0].size()-1){ pox = 3; poy = 2; }
	else if(y == 0 || y == duzina-1){ pox = 2; poy = 3; }
	else { pox = 3; poy = 3; }
	int pomocna1 = x;
	int pomocna2 = y;
	if(x-1>=0) pomocna1 = x-1;
	if(y-1>=0) pomocna2 = y-1;
	int reset1 = pomocna1;
	int brojac=0;
	for(int i=0; i < pox; i++){
		for(int j=0; j < poy; j++){
			if(polja[pomocna2][pomocna1] == Polje::Mina) brojac++;
			pomocna1++;
		}
		pomocna1 = reset1;
		pomocna2++;
	}
	return brojac;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	
	std::vector<std::vector<int>> Matrica(KreirajMatricu());
	if(!Provjeri(polja, x, y)) throw std::domain_error("Polje (" + PretvoriUString(x) + "," + PretvoriUString(y) + ") ne postoji");
	int pox=0, poy=0;
	
	auto duzina = polja.size();
	
	if((x==0 && y==0) || (x==0 && y==duzina-1) || (x==polja[0].size()-1 && y==0) || (x==polja[duzina-1].size()-1 && y == duzina-1) ){ pox=2; poy = 2; }
	else if(x == 0 || x == polja[0].size()-1){ pox = 3; poy = 2; }
	else if(y == 0 || y == duzina-1){ pox = 2; poy = 3; }
	else { pox = 3; poy = 3; }
	
	int pomocna1 = x;
	int pomocna2 = y;
	
	if(x-1>=0) pomocna1 = x-1;
	if(y-1>=0) pomocna2 = y-1;
	
	int reset1 = pomocna1;
	for(int i=0; i < pox ; i++){
		for(int j=0; j < poy; j++){
			Matrica[i][j] = VrijednostUTacki(polja, pomocna1, pomocna2);
			if(polja[pomocna2][pomocna1] == Polje::Mina) Matrica[i][j]--;
			pomocna1++;
		}
		pomocna1 = reset1;
		pomocna2++;
	}
	
	return Matrica;
}

void BlokirajPolje(Tabla &polja, int x, int y){
	if(!Provjeri(polja, x, y)) throw std::domain_error("Polje (" + PretvoriUString(x) + "," + PretvoriUString(y) + ") ne postoji");
	if(polja[x][y] == Polje::Prazno) polja[x][y] = Polje::BlokiranoPrazno;
	else if(polja[x][y] == Polje::Posjeceno) polja[x][y] = Polje::BlokiranoPosjeceno;
	else if(polja[x][y] == Polje::Mina) polja[x][y] = Polje::BlokiranoMina;
}

void DeblokirajPolje(Tabla &polja, int x, int y){
	if(!Provjeri(polja, x, y)) throw std::domain_error("Polje (" + PretvoriUString(x) + "," + PretvoriUString(y) + ") ne postoji");
	if(polja[x][y] == Polje::BlokiranoPrazno) polja[x][y] = Polje::Prazno;
	else if(polja[x][y] == Polje::BlokiranoPosjeceno) polja[x][y] = Polje::Posjeceno;
	else if(polja[x][y] == Polje::BlokiranoMina) polja[x][y] = Polje::Mina;
	
}

enum class Smjerovi {
    GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};

enum class Status {
    NijeKraj, KrajPoraz, KrajPobjeda
};

void OcistiMatricu(Tabla &polja){
	for(int i=0; i < polja.size(); i++){
		for(int j=0; j < polja[i].size(); j++){
			polja[i][j] = Polje::Prazno;
		}
	}
}

bool HaloMomak1(Tabla &polja, int x, int y){
	if(polja[x][y] == Polje::BlokiranoPrazno || polja[x][y] == Polje::BlokiranoPosjeceno || polja[x][y] == Polje::BlokiranoMina) return false;
	return true;
}

bool HaloMomak4(Tabla &polja, int x, int y){
	if(x<0 || y<0 || x>=polja.size() || y>=polja[x].size()) return false;
	return true;
}

bool HaloMomak2(Tabla &polja, int x, int y, Smjerovi novi){
	
	switch(int(novi)){
		case 0: x--; y--; break;
		case 1: x--; break;
		case 2: x++; y--; break;
		case 3: y++; break;
		case 4: x++; y++; break;
		case 5: x++; break;
		case 6: x++; y--; break;
		case 7: y--; break;
		
		default: break;
	}
	
	if(polja[x][y] == Polje::BlokiranoMina || polja[x][y] == Polje::BlokiranoPosjeceno || polja[x][y] == Polje::BlokiranoPrazno) return false;
	return true;
}

bool HaloMomak3(Tabla &polja, int x, int y, Smjerovi novi){
	
	switch(int(novi)){
		case 0: x--; y--; break;
		case 1: x--; break;
		case 2: x++; y--; break;
		case 3: y++; break;
		case 4: x++; y++; break;
		case 5: x++; break;
		case 6: x++; y--; break;
		case 7: y--; break;
		
		default: break;
	}
	
	if(x<0 || y<0 || x>=polja.size() || y>=polja[x].size()) return false;
	return true;
}

int RacunajPrazneMomak(Tabla &polja){
	int brojac=0;
	for(int i=0; i < polja.size(); i++){
		for(int j=0; j < polja[i].size(); j++){
			if(polja[i][j] == Polje::Prazno) brojac++;
		}
	}
	return brojac;
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
    if(!HaloMomak3(polja, x, y, smjer)) throw std::out_of_range("Izlazak van igrace table");
	if(!HaloMomak2(polja, x, y, smjer)) throw std::logic_error("Blokirano polje");
	if(polja[x][y] != Polje::BlokiranoPrazno && polja[x][y] != Polje::BlokiranoMina && polja[x][y] != Polje::BlokiranoPosjeceno) polja[x][y] = Polje::Posjeceno;

	switch(int(smjer)){
		case 0: x--; y--; break;
		case 1: x--; break;
		case 2: x++; y--; break;
		case 3: y++; break;
		case 4: x++; y++; break;
		case 5: x++; break;
		case 6: x++; y--; break;
		case 7: y--; break;
		default: break;
	}
	
	if(polja[x][y] == Polje::Mina){ OcistiMatricu(polja); return Status::KrajPoraz; }
	if(RacunajPrazneMomak(polja) == 0) return Status::KrajPobjeda;
	return Status::NijeKraj;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	
	if(!HaloMomak4(polja, novi_x, novi_y)) throw std::out_of_range("Izlazak van igrace table");
	if(!HaloMomak1(polja, novi_x, novi_y)) throw std::logic_error("Blokirano polje");
	if(polja[x][y] != Polje::BlokiranoPrazno && polja[x][y] != Polje::BlokiranoMina && polja[x][y] != Polje::BlokiranoPosjeceno) polja[x][y] = Polje::Posjeceno;
	x = novi_x; y = novi_y;
	if(polja[x][y] == Polje::Mina){ OcistiMatricu(polja); return Status::KrajPoraz; }
	if(RacunajPrazneMomak(polja) == 0) return Status::KrajPobjeda;
	return Status::NijeKraj;
}

enum class KodoviGresaka {
    PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};

void PrijaviGresku(KodoviGresaka greska){
	switch(int(greska)){
		case 0: std::cout << "Nerazumljiva komanda!" << std::endl; break;
		case 1: std::cout << "Komanda trazi parametar koji nije naveden!" << std::endl; break;
		case 2: std::cout << "Zadan je suvisan parametar nakon komande!" << std::endl; break;
		case 3: std::cout << "Parametar komande nije ispravan!" << std::endl; break;
		
		default: break;
	}
}

enum class Komande {
    PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};

void PreskociRazmake(){ while(std::cin.peek() == ' ') std::cin.get(); }

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	
	char z;
	PreskociRazmake();
	z = char(std::cin.get());
	switch(z) {
		case 'P':
			z = char(std::cin.get());
			if(z == '1') {
				PreskociRazmake();
				z = char(std::cin.get());
				if(z == '\n'){			// dood
					greska = KodoviGresaka::NedostajeParametar;
					return false;
				}
				switch(z) {
					case 'G':
						z = char(std::cin.peek());
						PreskociRazmake();
						if(z == '\n'){
							komanda = Komande::PomjeriJednoMjesto;
							smjer = Smjerovi::Gore;
							std::cin.ignore(10000, '\n');
							return true;
						}
						else if(z == 'L'){
							std::cin.get();
							z = char(std::cin.peek());
							if(z == ' ' || z == '\n'){
								PreskociRazmake();
								z = char(std::cin.peek());
								if (z == '\n'){
									komanda = Komande::PomjeriJednoMjesto;
									smjer = Smjerovi::GoreLijevo;
									std::cin.ignore(10000, '\n');
									return true;
								}
								else {
									greska = KodoviGresaka::SuvisanParametar;
									return false;
								}
							} else {
								greska = KodoviGresaka::SuvisanParametar;
								return false;
							}
							break;
						}else if(z == 'D'){
							std::cin.get();
							z = char(std::cin.peek());
							if (z == ' ' || z == '\n'){
								PreskociRazmake();
								z = char(std::cin.peek());
								if(z == '\n'){
									komanda = Komande::PomjeriJednoMjesto;
									smjer = Smjerovi::GoreDesno;
									std::cin.ignore(10000, '\n');
									return true;
								}
								else {
									greska = KodoviGresaka::SuvisanParametar;
									return false;
								}
							} else {
								greska = KodoviGresaka::SuvisanParametar;
								return false;
							}
							break;
						} else {
							greska = KodoviGresaka::NeispravanParametar;
							return false;
					}
					break;
					
				case 'D':
					z = char(std::cin.peek());
					if (z == ' '){
						PreskociRazmake();
						z = char(std::cin.peek());
						if(z == '\n'){
							komanda = Komande::PomjeriJednoMjesto;
							smjer = Smjerovi::Desno;
							std::cin.ignore(10000, '\n');
							return true;
						}
						else {
							greska = KodoviGresaka::SuvisanParametar;
							return false;
						}
						break;
					} else if( z == '\n'){
						komanda = Komande::PomjeriJednoMjesto;
						smjer = Smjerovi::Desno;
						std::cin.ignore(10000, '\n');
						return true;
					} 
					else if(z == 'o'){
						std::cin.get();
						z = char(std::cin.peek());
						if(z == ' '){
							PreskociRazmake();
							z = char(std::cin.peek());
							if (z == '\n'){
							komanda = Komande::PomjeriJednoMjesto;
							smjer = Smjerovi::Dolje;
							std::cin.ignore(10000, '\n');
							return true;
							}
							else {
							greska = KodoviGresaka::SuvisanParametar;
							return false;
							}
							break;
					
							} else if(z == '\n'){
								komanda = Komande::PomjeriJednoMjesto;
								smjer = Smjerovi::Dolje;
								std::cin.ignore(10000, '\n');
								return true;
							}
							else if(z == 'D' ){
							PreskociRazmake();
							std::cin.get();
							z = char(std::cin.peek());
							if(z == '\n'){
							komanda = Komande::PomjeriJednoMjesto;
							smjer = Smjerovi::DoljeDesno;
							std::cin.ignore(10000, '\n');
							return true;
						}
						else {
							greska = KodoviGresaka::SuvisanParametar;
							return false;
						}
						break;
					}
					else if(z == 'L'){
						PreskociRazmake();
						std::cin.get();
						z = char(std::cin.peek());
						if(z == '\n'){
							komanda = Komande::PomjeriJednoMjesto;
							smjer = Smjerovi::DoljeLijevo;
							std::cin.ignore(10000, '\n');
							return true;
						}
						else {
							greska = KodoviGresaka::SuvisanParametar;
							return false;
						}
						
						break;
					}
					} else {
						greska = KodoviGresaka::NeispravanParametar;
						return false;
					}
					break;
					
				case 'L':
					z = char(std::cin.peek());
					if(z == ' '){
						PreskociRazmake();
						z = char(std::cin.peek());
						if(z == '\n'){
							komanda = Komande::PomjeriJednoMjesto;
							smjer = Smjerovi::Lijevo;
							std::cin.ignore(10000, '\n');
							return true;
						}
						else {
							greska = KodoviGresaka::SuvisanParametar;
							return false;
						}
						break;
					} else if(z == '\n'){
						komanda = Komande::PomjeriJednoMjesto;
						smjer = Smjerovi::Lijevo;
						std::cin.ignore(10000, '\n');
						return true;
					}
					else { greska = KodoviGresaka::NeispravanParametar; }
					break;
					
				case '\n':
				greska = KodoviGresaka::NedostajeParametar; std::cin.ignore(10000, '\n');
				return false;
				break;
				
				default: greska = KodoviGresaka::NeispravanParametar;
				 return false;
				 break;
			}
	} else if(z == '>'){
		
		int a, b;
		PreskociRazmake();
		if(std::cin.peek() == '\n'){
			greska = KodoviGresaka::NedostajeParametar;
			return false;
		}
		if(!(std::cin >> a)){
			greska = KodoviGresaka::NeispravanParametar;
			return false;
		}
		PreskociRazmake();
		if(std::cin.peek() == '\n'){
			greska = KodoviGresaka::NedostajeParametar;
			return false;
		}
		if(!(std::cin >> b)){
			greska = KodoviGresaka::NeispravanParametar;
			return false;
		}
		PreskociRazmake();
		if (std::cin.peek() != '\n'){
			greska = KodoviGresaka::SuvisanParametar;
			return false;
		}
		komanda = Komande::PomjeriDalje;
		std::cin.ignore(10000, '\n');
		x = a; y = b;
		return true;
	}
	else if(z == 'O'){
		PreskociRazmake();
		if(std::cin.peek() != '\n'){
			greska = KodoviGresaka::SuvisanParametar;
			std::cin.ignore(10000, '\n');
			return false;
		}
		komanda = Komande::PrikaziOkolinu;
		std::cin.ignore(10000, '\n');
		return true;
	} else {
		greska = KodoviGresaka::PogresnaKomanda;
		return false;
	}
	break;
	
	case 'B':
		int a, b;
		PreskociRazmake();
		if(std::cin.peek() == '\n'){
			greska = KodoviGresaka::NedostajeParametar;
			return false;
		}
		if(!(std::cin >> a)){
			greska = KodoviGresaka::NeispravanParametar;
			return false;
		}
		PreskociRazmake();
		if(std::cin.peek() == '\n'){
			greska = KodoviGresaka::NedostajeParametar;
			return false;
		}
		if(!(std::cin >> b)){
			greska = KodoviGresaka::NeispravanParametar;
			return false;
		}
		PreskociRazmake();
		if (std::cin.peek() != '\n'){
			greska = KodoviGresaka::SuvisanParametar;
			return false;
		}
		komanda = Komande::Blokiraj;
		x = a; y = b;
		std::cin.ignore(10000, '\n');
		return true;
		break;
		
	case 'D':
		int i, j;
		PreskociRazmake();
		if(std::cin.peek() == '\n'){
			greska = KodoviGresaka::NedostajeParametar;
			return false;
		}
		if(!(std::cin >> i)){
			greska = KodoviGresaka::NeispravanParametar;
			return false;
		}
		PreskociRazmake();
		if(std::cin.peek() == '\n'){
			greska = KodoviGresaka::NedostajeParametar;
			return false;
		}
		if(!(std::cin >> j)){
			greska = KodoviGresaka::NeispravanParametar;
			return false;
		}
		PreskociRazmake();
		if (std::cin.peek() != '\n'){
			greska = KodoviGresaka::SuvisanParametar;
			return false;
		}
		komanda = Komande::Deblokiraj;
		x = i; y = j;
		std::cin.ignore(10000, '\n');
		return true;
		break;
		
	case 'Z':
		PreskociRazmake();
		if(std::cin.peek() != '\n'){
			greska = KodoviGresaka::SuvisanParametar;
			std::cin.ignore(10000, '\n');
			return false;
		}
		komanda = Komande::ZavrsiIgru;
		return true;
		break;
	case 'K':
		PreskociRazmake();
		if(std::cin.peek() != '\n'){
			greska = KodoviGresaka::SuvisanParametar;
			std::cin.ignore(10000, '\n');
			return false;
		}
		komanda = Komande::KreirajIgru;
		std::cin.ignore(10000, '\n');
		return true;
		break;
	default :
		greska = KodoviGresaka::PogresnaKomanda;
		break;
	}
	
	return true;
}

Status tok;

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x=0, int p_y=0){
	
	if(komanda == Komande::KreirajIgru){
		try {
			unsigned int k(0);
			char z;
			int a, b;
			std::cout << "Unesite broj polja: ";
			int n;
			std::cin >> n;
			std::cin.ignore(10000, '\n');
			std::vector<std::vector<int>> mine;
			std::cout << "Unesite pozicije mina: ";
			for(;;){
				z = char(std::cin.get());
				if(z == '.') break;
				if(z == '('){
					std::cin >> a;
					PreskociRazmake();
					z = char(std::cin.get());
					if(z == ','){
						std::cin >> b;
						PreskociRazmake();
						z = char(std::cin.get());
						if (z == ')'){
							PreskociRazmake();
							if(std::cin.get() != '\n'){
								std::cout << "Greska, unesite ponovo!" << std::endl;
								std::cin.ignore(10000, '\n');
								continue;
							} else {
								if(a < 0 || b < 0 || a > n || b > n){
									std::cout << "Greska, unesite ponovo!";
									std::cout << std::endl;
									continue;
								} else {
									mine.resize(k+1);
									mine[k].resize(2);
									mine[k][0] = a;
									mine[k][1] = b;
									k++;
								}
							}
						} else {
					std::cout << "Greska, unesite ponovo!" << std::endl;
					std::cin.ignore(10000, '\n');
					continue;
						}
					} else {
					std::cout << "Greska, unesite ponovo!" << std::endl;
					std::cin.ignore(10000, '\n');
					continue;
					}
				} else {
					std::cout << "Greska, unesite ponovo!" << std::endl;
					std::cin.ignore(10000, '\n');
					continue;
					
				}
				
			}
			
			polja = KreirajIgru(n, mine);
				
			}catch(std::domain_error exec){
			std::cout <<  exec.what() << std::endl;
			}
	}
	else if(komanda == Komande::PrikaziOkolinu){
		try{
			std::vector<std::vector<int>> matrica;
			matrica = PrikaziOkolinu(polja, x, y);
			IspisiMatricu(matrica);
		}catch(std::domain_error exec){
			std::cout << exec.what() << std::endl;
		}
	}
	else if(komanda == Komande::Blokiraj){
		try{
			BlokirajPolje(polja, p_x, p_y);
		}catch(std::domain_error exec){
			std::cout << exec.what() << std::endl;
		}
	}
	else if(komanda == Komande::Deblokiraj){
		try{
			DeblokirajPolje(polja, p_x, p_y);
		}catch(std::domain_error exec){
			std::cout <<  exec.what() << std::endl;
		}
	}
	else if(komanda == Komande::PomjeriJednoMjesto){
		
		try{
			tok = Idi(polja, x, y, p_smjer);
			std::cout << "Tekuca pozicija igraca je ("  << x << ',' << y << ")" << std::endl;
			if(tok == Status::KrajPobjeda){ std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl; komanda = Komande::ZavrsiIgru; return; }
			else if(tok == Status::KrajPoraz){ std::cout << "Nagazili ste na minu" << std::endl; komanda = Komande::ZavrsiIgru; return; }
			else tok = Status::NijeKraj;
		}catch(std::out_of_range exec){
			std::cout << exec.what() << std::endl;
		}catch(std::logic_error exec){
			std::cout << exec.what() << std::endl;
		}
	
	}
	else if(komanda == Komande::PomjeriDalje){
		
		try{
			tok = Idi(polja, x, y, p_x, p_y);
			std::cout << "Tekuca pozicija igraca je ("  << x << ',' << y << ")" << std::endl;
			if(tok == Status::KrajPobjeda){ std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl; komanda = Komande::ZavrsiIgru; return; }
			else if(tok == Status::KrajPoraz){ std::cout << "Nagazili ste na minu" << std::endl; komanda = Komande::ZavrsiIgru; return; }
			else tok = Status::NijeKraj;
		}catch(std::out_of_range exec){
			std::cout << exec.what() << std::endl;
		}catch(std::logic_error exec){
			std::cout << exec.what() << std::endl;
		}
	
	}
}

int main (){
	try{
		Komande komanda;
		Tabla a = { {} };
		Smjerovi smjer;
		int x=0, y=0;
		KodoviGresaka greska;
		int pomocna1 = 0, pomocna2 = 0;
		for(;;){  
			std::cout << "Unesite komandu: ";
			pomocna1 = x; pomocna2 = y;
			
			if(UnosKomande(komanda, smjer, x, y, greska)){
				if(komanda == Komande::PomjeriJednoMjesto || komanda == Komande::PomjeriDalje){
					IzvrsiKomandu(komanda, a, x, y, smjer, x, y);
				}else IzvrsiKomandu(komanda, a, pomocna1, pomocna2, smjer, x, y);
			} else PrijaviGresku(greska);	
			
			if(komanda == Komande::ZavrsiIgru){ std::cout << "Dovidjenja!"; return 0; }
			
			if(tok == Status::KrajPoraz || tok == Status::KrajPobjeda){
				std::cout << "Dovidjenja!";
				return 0;
			}
			if(komanda == Komande::KreirajIgru) std::cin.ignore(10000, '\n');
		}
	}
	catch(...){
		std::cout << "Uhvaceno!";
	}
	return 0;
}
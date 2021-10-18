/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
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

// logika
Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine);
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y);
void BlokirajPolje(Tabla &polja, int x, int y);
void DeblokirajPolje(Tabla &polja, int x, int y);
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer);
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y);

// upravljacke funkcije
void PrijaviGresku(KodoviGresaka kod);
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska);
void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0);

// pomocne funkcije
bool svePosjeceno(const Tabla &tabla);
bool unutarTable(const Tabla &tabla, int x, int y);

int main ()
{
	int x = 0, y = 0;
	Tabla polja;
	
	for(;;) {
		Komande komanda;
		Smjerovi smjer;
		KodoviGresaka greska;
		int p_x = x, p_y = y;
		
		std::cout << "Unesite komandu: ";
		if (UnosKomande(komanda, smjer, p_x, p_y, greska)) {
			try {
				IzvrsiKomandu(komanda, polja, x, y, smjer, p_x, p_y);
			} catch(std::runtime_error e) {
				break;
			}
		}
		else
			PrijaviGresku(greska);
	}
	
	std::cout << "Dovidjenja!" << std::endl;
		
	return 0;
}

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine) {
	// provjera ispravnosti podataka
	for (auto &polje : mine) {
		if (polje.size() != 2)
			throw std::domain_error("Ilegalan format zadavanja mina");
		if (polje[0] >= n || polje[1] >= n)
			throw std::domain_error("Ilegalne pozicije mina");
	}
	
	// inicijalizacija table
	Tabla tabla(n, std::vector<Polje>(n));
	
	// postavljanje svih polja na prazna
	for (auto &red : tabla)
		for (auto &polje : red)
			polje = Polje::Prazno;
			
	// ubacivanje mina
	for (auto &polje : mine)
		tabla[polje[0]][polje[1]] = Polje::Mina;
		
	return tabla;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y) {
	// provjera ispravnosti podataka
	if (x >= polja.size() || x < 0 || y >= polja.size() || y < 0)
		throw std::domain_error("Polje (" + std::to_string(x) + ", " + std::to_string(y) + ") ne postoji");
	
	// inicijalizacija okoline
	std::vector<std::vector<int>> okolina(3, std::vector<int>(3));
	
	// izracunavanje okoline
	for (int i = x - 1; i <= x + 1; i++) {
		// u slucaju da je red izvan table
		if (i < 0 || i >= polja.size()) {
			okolina[i - x + 1][0] = 0;
			okolina[i - x + 1][1] = 0;
			okolina[i - x + 1][2] = 0;
			continue;
		}
		
		for (int j = y - 1; j <= y + 1; j++) {
			// u slucaju da je kolona izvan table
			if (j < 0 || j >= polja.size()) {
				okolina[0][j - y + 1] = 0;
				okolina[1][j - y + 1] = 0;
				okolina[2][j - y + 1] = 0;
				continue;
			}
			
			// provjera okolnih polja
			for (int k = -1; k < 2; k++) {
				if (unutarTable(polja, i + k, j - 1) && polja[i + k][j - 1] == Polje::Mina)
					okolina[i - x + 1][j - y + 1] += 1;
					
				if (unutarTable(polja, i + k, j) && polja[i + k][j] == Polje::Mina)
					okolina[i - x + 1][j - y + 1] += 1;
					
				if (unutarTable(polja, i + k, j + 1) && polja[i + k][j + 1] == Polje::Mina)
					okolina[i - x + 1][j - y + 1] += 1;
			}
			
			// da ne bismo racunali polje (x, y)
			if (unutarTable(polja, i, j) && polja[i][j] == Polje::Mina)
				okolina[i - x + 1][j - y + 1] -= 1;
		}
	}
	
	return okolina;
}

void BlokirajPolje(Tabla &polja, int x, int y) {
	// provjera ispravnosti podataka
	if (x >= polja.size() || x < 0 || y >= polja.size() || y < 0)
		throw std::domain_error("Polje (" + std::to_string(x) + ", " + std::to_string(y) + ") ne postoji");
		
	// promjena stanja polja
	switch (polja[x][y]) {
		case Polje::Prazno:
			polja[x][y] = Polje::BlokiranoPrazno;
			return;
		case Polje::Posjeceno:
			polja[x][y] = Polje::BlokiranoPosjeceno;
			return;
		case Polje::Mina:
			polja[x][y] = Polje::BlokiranoMina;
			return;
		default:
			break;
	}
}

void DeblokirajPolje(Tabla &polja, int x, int y) {
	// provjera ispravnosti podataka
	if (x >= polja.size() || x < 0 || y >= polja.size() || y < 0)
		throw std::domain_error("Polje (" + std::to_string(x) + ", " + std::to_string(y) + ") ne postoji");
		
	// promjena stanja polja
	switch (polja[x][y]) {
		case Polje::BlokiranoPrazno:
			polja[x][y] = Polje::Prazno;
			return;
		case Polje::BlokiranoPosjeceno:
			polja[x][y] = Polje::Posjeceno;
			return;
		case Polje::BlokiranoMina:
			polja[x][y] = Polje::Mina;
			return;
		default:
			break;
	}
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer) {
	// pozivamo drugu varijantu ove funkcije
	// sa parametrima ovisnim o smjeru
	switch (smjer) {
		case Smjerovi::GoreLijevo:
			return Idi(polja, x, y, x - 1, y - 1);
		case Smjerovi::Gore:
			return Idi(polja, x, y, x - 1, y);
		case Smjerovi::GoreDesno:
			return Idi(polja, x, y, x - 1, y + 1);
		case Smjerovi::Desno:
			return Idi(polja, x, y, x, y + 1);
		case Smjerovi::DoljeDesno:
			return Idi(polja, x, y, x + 1, y + 1);
		case Smjerovi::Dolje:
			return Idi(polja, x, y, x + 1, y);
		case Smjerovi::DoljeLijevo:
			return Idi(polja, x, y, x + 1, y - 1);
		case Smjerovi::Lijevo:
			return Idi(polja, x, y, x, y - 1);
		default:
			return Status::NijeKraj;
	}
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y) {
	// provjera ispravnosti podataka
	if (novi_x >= polja.size() || novi_x < 0 || novi_y >= polja.size() || novi_y < 0) 
		throw std::out_of_range("Izlazak van igrace table");
		
	// provjera mogucnosti pomjeranja
	if (polja[novi_x][novi_y] == Polje::BlokiranoPrazno ||
		polja[novi_x][novi_y] == Polje::BlokiranoPosjeceno ||
		polja[novi_x][novi_y] == Polje::BlokiranoMina)
		throw std::logic_error("Blokirano polje");
		
	// azuriramo vrijednost polja
	polja[x][y] = Polje::Posjeceno;
	// i polozaj igraca
	x = novi_x;
	y = novi_y;
		
	// ukoliko smo stali na minu
	if (polja[x][y] == Polje::Mina) {
		for (auto &red : polja)
			for (auto &polje : red)
				polje = Polje::Prazno;
			
		return Status::KrajPoraz;
	}
	
	// ukoliko smo obisli cijelu tablu
	if (svePosjeceno(polja))
		return Status::KrajPobjeda;
		
	return Status::NijeKraj;
}

void PrijaviGresku(KodoviGresaka kod) {
	switch (kod) {
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

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska) {
	// deklaracija stringa i unos komande
	std::string unos;
	std::getline(std::cin, unos);
	
	// provjera prvog karaktera
	switch (unos[0]) {
		case 'P': {
			switch (unos[1]) {
				case '1': {
					// pomjeri za jedno
					int pos = unos.substr(2).find_first_not_of(' ');
					
					if (pos == std::string::npos) {
						greska = KodoviGresaka::NedostajeParametar;
						return false;
					}
					
					pos += 2;
					
					switch (unos[pos]) {
						case 'G': {
							if (unos.substr(pos + 1).find_first_not_of(' ') == std::string::npos) {
									komanda = Komande::PomjeriJednoMjesto;
									smjer = Smjerovi::Gore;
									return true;
							}
							
							
							if (unos.substr(pos + 2).find_first_not_of(' ') != std::string::npos) {
								greska = KodoviGresaka::SuvisanParametar;
								return false;
							}
								
							switch (unos[pos + 1]) {
								case 'L':
									komanda = Komande::PomjeriJednoMjesto;
									smjer = Smjerovi::GoreLijevo;
									return true;
								case 'D':
									komanda = Komande::PomjeriJednoMjesto;
									smjer = Smjerovi::GoreDesno;
									return true;
								default:
									greska = KodoviGresaka::NeispravanParametar;
									return false;
							}
						}
						case 'D': {
							if (unos.substr(pos + 1).find_first_not_of(' ') == std::string::npos) {
									komanda = Komande::PomjeriJednoMjesto;
									smjer = Smjerovi::Desno;
									return true;
								}
								
							if (unos.size() >= pos + 2 && unos[pos + 1] == 'o') {
								if (unos.substr(pos + 2).find_first_not_of(' ') == std::string::npos) {
									komanda = Komande::PomjeriJednoMjesto;
									smjer = Smjerovi::Dolje;
									return true;
								} else {
									if (unos.substr(pos + 3).find_first_not_of(' ') != std::string::npos) {
										greska = KodoviGresaka::SuvisanParametar;
										return false;
									}
									
									switch (unos[pos + 2]) {
										case 'D': {
											komanda = Komande::PomjeriJednoMjesto;
											smjer = Smjerovi::DoljeDesno;
											return true;
										}
										case 'L': {
											komanda = Komande::PomjeriJednoMjesto;
											smjer = Smjerovi::DoljeLijevo;
											return true;
										}
										default: {
											greska = KodoviGresaka::NeispravanParametar;
											return false;
										}
									}
								}
							} else {
								greska = KodoviGresaka::NeispravanParametar;
								return false;
							}
						}
						case 'L': {
							if (unos.substr(pos + 1).find_first_not_of(' ') == std::string::npos) {
								komanda = Komande::PomjeriJednoMjesto;
								smjer = Smjerovi::Lijevo;
								return true;
							} else {
								greska = KodoviGresaka::SuvisanParametar;
								return false;
							}
						}
						default: {
							greska = KodoviGresaka::NeispravanParametar;
							return false;
						}
					}
				}
					break;
				case '>': {
					// pomjeri na zadano
					int pos = unos.substr(2).find_first_not_of(' ');
					
					if (pos == std::string::npos) {
						greska = KodoviGresaka::NedostajeParametar;
						return false;
					}
					
					pos += 2;
					
					int x_pos, y_pos, kraj_x = 0, kraj_y = 0;
					
					try {
						kraj_x = unos.substr(pos).find_first_not_of("0123456789");
						x_pos = std::stoi(unos.substr(pos, kraj_x));
					} catch(...) {
						greska = KodoviGresaka::NeispravanParametar;
						return false;
					}
					
					if (unos.substr(kraj_x).find_first_not_of(' ') == std::string::npos) {
						greska = KodoviGresaka::NedostajeParametar;
						return false;
					}
					
					try {
						kraj_y = unos.substr(kraj_x).find_first_not_of("0123456789");
						y_pos = std::stoi(unos.substr(kraj_x + 1));
					} catch(...) {
						greska = KodoviGresaka::NeispravanParametar;
						return false;
					}
					
					//if (unos.substr(kraj_y).find_first_not_of(' ') != std::string::npos) {
					//	greska = KodoviGresaka::SuvisanParametar;
					//	return false;
					//}
					
					komanda = Komande::PomjeriDalje;
					x = x_pos;
					y = y_pos;
					return true;
				}
					break;
				case 'O': {
					// prikazi okolinu
					int pos = unos.substr(2).find_first_not_of(' ');
					
					if (pos == std::string::npos) {
						greska = KodoviGresaka::NedostajeParametar;
						return false;
					}
					
					pos += 2;
					
					int x_pos, y_pos, kraj_x = 0, kraj_y = 0;
					
					try {
						kraj_x = unos.substr(pos).find_first_not_of("0123456789");
						x_pos = std::stoi(unos.substr(pos, kraj_x));
					} catch(...) {
						greska = KodoviGresaka::NeispravanParametar;
						return false;
					}
					
					if (unos.substr(kraj_x).find_first_not_of(' ') == std::string::npos) {
						greska = KodoviGresaka::NedostajeParametar;
						return false;
					}
					
					try {
						kraj_y = unos.substr(kraj_x).find_first_not_of("0123456789");
						y_pos = std::stoi(unos.substr(kraj_x + 1));
					} catch(...) {
						greska = KodoviGresaka::NeispravanParametar;
						return false;
					}
					
					// if (unos.substr(kraj_y).find_first_not_of(' ') != std::string::npos) {
					// 	greska = KodoviGresaka::SuvisanParametar;
					// 	return false;
					// }
					
					komanda = Komande::PrikaziOkolinu;
					x = x_pos;
					y = y_pos;
					return true;
				}
					break;
				default: {
					greska = KodoviGresaka::PogresnaKomanda;
					return false;
					break;
				}
			}
		}
			break;
		case 'B': {
			// blokiraj
			int pos = unos.substr(1).find_first_not_of(' ');
					
			if (pos == std::string::npos) {
				greska = KodoviGresaka::NedostajeParametar;
				return false;
			}
			
			pos += 1;
			
			int x_pos, y_pos, kraj_x = 0, kraj_y = 0;
			
			try {
				kraj_x = unos.substr(pos).find_first_not_of("0123456789");
				x_pos = std::stoi(unos.substr(pos, kraj_x));
			} catch(...) {
				greska = KodoviGresaka::NeispravanParametar;
				return false;
			}
			
			if (unos.substr(kraj_x).find_first_not_of(' ') == std::string::npos) {
				greska = KodoviGresaka::NedostajeParametar;
				return false;
			}
			
			try {
				kraj_y = unos.substr(kraj_x).find_first_not_of("0123456789");
				y_pos = std::stoi(unos.substr(kraj_x + 1));
			} catch(...) {
				greska = KodoviGresaka::NeispravanParametar;
				return false;
			}
			
			// if (unos.substr(kraj_y).find_first_not_of(' ') != std::string::npos) {
			// 	greska = KodoviGresaka::SuvisanParametar;
			// 	return false;
			// }
			
			komanda = Komande::Blokiraj;
			x = x_pos;
			y = y_pos;
			return true;
			
			break;
		}
		case 'D': {
			// deblokiraj
			int pos = unos.substr(1).find_first_not_of(' ');
					
			if (pos == std::string::npos) {
				greska = KodoviGresaka::NedostajeParametar;
				return false;
			}
			
			pos += 1;
			
			int x_pos, y_pos, kraj_x = 0, kraj_y = 0;
			
			try {
				kraj_x = unos.substr(pos).find_first_not_of("0123456789");
				x_pos = std::stoi(unos.substr(pos, kraj_x));
			} catch(...) {
				greska = KodoviGresaka::NeispravanParametar;
				return false;
			}
			
			if (unos.substr(kraj_x).find_first_not_of(' ') == std::string::npos) {
				greska = KodoviGresaka::NedostajeParametar;
				return false;
			}
			
			try {
				kraj_y = unos.substr(kraj_x).find_first_not_of("0123456789");
				y_pos = std::stoi(unos.substr(kraj_x + 1));
			} catch(...) {
				greska = KodoviGresaka::NeispravanParametar;
				return false;
			}
			
			// if (unos.substr(kraj_y).find_first_not_of(' ') != std::string::npos) {
			// 	greska = KodoviGresaka::SuvisanParametar;
			// 	return false;
			//}
			
			komanda = Komande::Deblokiraj;
			x = x_pos;
			y = y_pos;
			return true;
			
			break;
		}
		case 'Z': {
			// zavrsi
			komanda = Komande::ZavrsiIgru;
			return true;
			
			break;
		}
		case 'K': {
			// kreiraj
			komanda = Komande::KreirajIgru;
			return true;
			
			break;
		}
		default: {
			greska = KodoviGresaka::PogresnaKomanda;
			return false;
		}
		}
	return true;
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer, int p_x, int p_y) {
	try {
		switch (komanda) {
			case Komande::PomjeriJednoMjesto: {
				switch (Idi(polja, x, y, p_smjer)) {
					case Status::KrajPoraz:
						std::cout << "Tekuca pozicija igraca je (" << x << ", " << y << ")" << std::endl;
						std::cout << "Nagazili ste na minu" << std::endl;
						break;
					case Status::KrajPobjeda:
						std::cout << "Tekuca pozicija igraca je (" << x << ", " << y << ")" << std::endl;
						std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
						break;
					case Status::NijeKraj:
						std::cout << "Tekuca pozicija igraca je (" << x << ", " << y << ")" << std::endl;
						break;
				}
				break;
			}
			case Komande::PomjeriDalje: {
				std::cout << "Tekuca pozicija igraca je (" << p_x << ", " << p_y << ")" << std::endl;
				switch (Idi(polja, x, y, p_x, p_y)) {
					case Status::KrajPoraz:
						std::cout << "Nagazili ste na minu" << std::endl;
						break;
					case Status::KrajPobjeda:
						std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
						break;
					case Status::NijeKraj:
						break;
				}
				break;
			}
			case Komande::Blokiraj: {
				BlokirajPolje(polja, p_x, p_y);
				break;
			}
			case Komande::Deblokiraj: {
				DeblokirajPolje(polja, p_x, p_y);
				break;
			}
			case Komande::PrikaziOkolinu: {
				auto mat = PrikaziOkolinu(polja, p_x, p_y);
				for (auto &red : mat) {
					for (auto &elem : red)
						std::cout << elem << " ";
					std::cout << std::endl;
				}
					
				break;
			}
			case Komande::ZavrsiIgru: {
				for (auto &red : polja)
					for (auto &polje : red)
						polje = Polje::Prazno;
						
				throw std::runtime_error("Igra zavrsena");
				break;
			}
			case Komande::KreirajIgru: {
				int broj_polja;
				std::vector<std::vector<int>> mine;
				
				std::cout << "Unesite broj polja: ";
				std::cin >> broj_polja;
				
				std::string unos = "";
				
				std::cout << "Unesite pozicije mina: ";
				std::cin.ignore(100, '\n');
				while (unos != ".") {
					std::getline(std::cin, unos);
					if (unos == ".")
						break;
						
					if (unos[0] != '(') {
						std::cout << "Greska, unesite ponovo!" << std::endl;
						continue;
					}
					
					int x_mine = 0, y_mine = 0;
					
					try {
						x_mine = std::stoi(unos.substr(1, unos.find_first_of(',')));
					} catch(std::exception e) {
						std::cout << "Greska, unesite ponovo!" << std::endl;
						std::cout << e.what() << std::endl;
						continue;
					}
					
					try {
						y_mine = std::stoi(unos.substr(unos.find_first_of(',') + 1, unos.find_first_of(')')));
					} catch(std::exception e) {
						std::cout << "Greska, unesite ponovo!" << std::endl;
						std::cout << e.what() << std::endl;
						continue;
					}
					
					std::vector<int> poz_mine;
					poz_mine.push_back(x_mine);
					poz_mine.push_back(y_mine);
					mine.push_back(poz_mine);
				}
				
				polja = KreirajIgru(broj_polja, mine);
				
				break;
			}
			default:
				break;
		}
	} catch(std::runtime_error e1) {
		return;
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

bool svePosjeceno(const Tabla &tabla) {
	for (auto &red : tabla)
		for (auto &polje : red)
			if (polje != Polje::Posjeceno)
				return false;
				
	return true;
}

bool unutarTable(const Tabla &tabla, int x, int y) {
	return !(x < 0 || y < 0 || x >= tabla.size() || y >= tabla.size());
}
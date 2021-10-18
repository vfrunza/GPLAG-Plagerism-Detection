#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
//																										//What could be problematic? ln: 117, 154
enum class Polje {Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina};
enum class Smjerovi {GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo};
enum class Status {NijeKraj, KrajPoraz, KrajPobjeda};
enum class KodoviGresaka {PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar};
enum class Komande {PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru};

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru (int n, const std::vector<std::vector<int>> &mine) {
	
	//uvjeti
	for (int i = 0; i < mine.size(); i++) {
		if (mine[i].size() != 2) throw std::domain_error("Ilegalan format zadavanja mina");
		if (mine[i][0] >= n || mine[i][0] < 0) throw std::domain_error("Ilegalne pozicije mina");
		if (mine[i][1] >= n || mine[i][1] < 0) throw std::domain_error("Ilegalne pozicije mina");
	}
	
	//kreiraj tablu formata n x n
	Tabla tabla;
	tabla.resize(n);
	for (int i = 0; i < n; i++) tabla[i].resize(n);
	//postavi sva polja na Prazno
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) tabla[i][j] = Polje::Prazno;
	
	//postavi mine
	for (int i = 0; i < mine.size(); i++) tabla[mine[i][0]][mine[i][1]] = Polje::Mina;
	
	//vrati ovako kreiranu tablu
	return tabla;
}

void BlokirajPolje(Tabla &polja, int x, int y) {
	
	bool exist(true);
	if (x >= polja.size() || y >= polja.size()) exist = false;
	if (x < 0 || y < 0) exist = false;
	if (!exist) {
		
		std::string error_msg("Polje (");
		error_msg+=std::to_string(x); error_msg+=std::string(",");
		error_msg+=std::to_string(y); error_msg+=std::string(") ");
		error_msg+=std::string("ne postoji");
		
		throw std::domain_error(error_msg);
	}
	
	if (polja[x][y] == Polje::BlokiranoPrazno 	 ||
		polja[x][y] == Polje::BlokiranoPosjeceno ||
		polja[x][y] == Polje::BlokiranoMina) return;
	
	if 		(polja[x][y] == Polje::Prazno) 		polja[x][y] = Polje::BlokiranoPrazno;
	else if (polja[x][y] == Polje::Posjeceno) 	polja[x][y] = Polje::BlokiranoPosjeceno;
	else if (polja[x][y] == Polje::Mina) 		polja[x][y] = Polje::BlokiranoMina;
}

void DeblokirajPolje(Tabla &polja, int x, int y) {
	
	bool exist(true);
	if (x >= polja.size() || y >= polja.size()) exist = false;
	if (x < 0 || y < 0) exist = false;
	if (!exist) {
		
		std::string error_msg("Polje (");
		error_msg+=std::to_string(x); error_msg+=std::string(",");
		error_msg+=std::to_string(y); error_msg+=std::string(") ");
		error_msg+=std::string("ne postoji");
		
		throw std::domain_error(error_msg);
	}
	
	if (polja[x][y] == Polje::Prazno 	||
		polja[x][y] == Polje::Posjeceno ||
		polja[x][y] == Polje::Mina) return;
	
	if 		(polja[x][y] == Polje::BlokiranoPrazno) 	polja[x][y] = Polje::Prazno;
	else if (polja[x][y] == Polje::BlokiranoPosjeceno) 	polja[x][y] = Polje::Posjeceno;
	else if (polja[x][y] == Polje::BlokiranoMina) 		polja[x][y] = Polje::Mina;
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer) {
	
	int new_x(x), new_y(y);
	if (smjer == Smjerovi::GoreLijevo  || smjer == Smjerovi::Gore   || smjer == Smjerovi::GoreDesno)   new_x--;
	if (smjer == Smjerovi::DoljeLijevo || smjer == Smjerovi::Dolje  || smjer == Smjerovi::DoljeDesno)  new_x++;
	if (smjer == Smjerovi::GoreDesno   || smjer == Smjerovi::Desno  || smjer == Smjerovi::DoljeDesno)  new_y++;
	if (smjer == Smjerovi::GoreLijevo  || smjer == Smjerovi::Lijevo || smjer == Smjerovi::DoljeLijevo) new_y--;
	
	bool exist(true);
	if (new_x < 0 || new_y < 0) exist = false;
	if (new_x >= polja.size() || new_y >= polja.size()) exist = false;
	if (!exist) throw std::out_of_range("Izlazak van igrace table");
	
	if (polja[new_x][new_y] == Polje::BlokiranoPrazno 	 ||
		polja[new_x][new_y] == Polje::BlokiranoPosjeceno ||
		polja[new_x][new_y] == Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
	
	polja[x][y] = Polje::Posjeceno;
	x = new_x; y = new_y;
	
	if (polja[x][y] == Polje::Mina) {
		for (int i = 0; i < polja.size(); i++) {
			for (int j = 0; j < polja.size(); j++) {
				polja[i][j] = Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
	
	bool finished(true);
	for (int i = 0; i < polja.size(); i++) {
		for (int j = 0; j < polja.size(); j++) {
			if ((polja[i][j] == Polje::Prazno || polja[i][j] == Polje::BlokiranoPrazno) && !(i==x && j==y)) {
				finished = false;
				break;
			}
		}
	}
	if (finished) return Status::KrajPobjeda;
	
	return Status::NijeKraj;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y) {
	
	bool exist(true);
	if (novi_x < 0 || novi_y < 0) exist = false;
	if (novi_x >= polja.size() || novi_y >= polja.size()) exist = false;
	if (!exist) throw std::out_of_range("Izlazak van igrace table");
	
	if (polja[novi_x][novi_y] == Polje::BlokiranoPrazno 	||
		polja[novi_x][novi_y] == Polje::BlokiranoPosjeceno  ||
		polja[novi_x][novi_y] == Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
	
	polja[x][y] = Polje::Posjeceno;
	x = novi_x; y = novi_y;
	
	if (polja[x][y] == Polje::Mina) {
		for (int i = 0; i < polja.size(); i++) {
			for (int j = 0; j < polja.size(); j++) {
				polja[i][j] = Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
	
	bool finished(true);
	for (int i = 0; i < polja.size(); i++) {
		for (int j = 0; j < polja.size(); j++) {
			if ((polja[i][j] == Polje::Prazno || polja[i][j] == Polje::BlokiranoPrazno) && !(i==x && j==y)) {
				finished = false;
				break;
			}
		}
	}
	
	if (finished) return Status::KrajPobjeda;
	
	return Status::NijeKraj;
}

//my Function
Polje InField (const Tabla &polja, int x, int y) {
	bool exist(true);
	if (x < 0 || y < 0) exist = false;
	if (x >= polja.size() || y >= polja.size()) exist = false;
	if (!exist) return Polje::Prazno;
	else return polja[x][y];
}
//end of my Function

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y) {
	
	std::vector<std::vector<int>> umfeld(3);
	
	bool exist(true);
	if (x >= polja.size() || y >= polja.size()) exist = false;
	if (x < 0 || y < 0) exist = false;
	if (!exist) {
		
		std::string error_msg("Polje (");
		error_msg+=std::to_string(x); error_msg+=std::string(",");
		error_msg+=std::to_string(y); error_msg+=std::string(") ");
		error_msg+=std::string("ne postoji");
		
		throw std::domain_error(error_msg);
	}
	
	int hi(0);
	for (int i = x-1; i <= x+1; i++) {
		for (int j = y-1; j <= y+1; j++) {
			
			int count(0);
			for (int w = i-1; w <= i+1; w++)
				for (int s = j-1; s <= j+1; s++) 
					if (InField(polja, w, s) == Polje::Mina && !(w == i && s == j)) count++;
			
			umfeld[hi].push_back(count);
		}
		hi++;
	}
	
	return umfeld;
}

void PrijaviGresku (KodoviGresaka greska) {
	if 		(greska == KodoviGresaka::PogresnaKomanda) 		std::cout << "Nerazumljiva komanda!" << std::endl;
	else if (greska == KodoviGresaka::NedostajeParametar) 	std::cout << "Komanda trazi parametar koji nije naveden!" << std::endl;
	else if (greska == KodoviGresaka::NeispravanParametar) 	std::cout << "Parametar komande nije ispravan!" << std::endl;
	else if (greska == KodoviGresaka::SuvisanParametar) 	std::cout << "Zadan je suvisan parametar nakon komande!" << std::endl;
}

void LoadEnter();

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool UnosKomande (Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska) {

	std::string order;
	std::getline(std::cin, order);
	LoadEnter();
	
	bool jump(false); //nisam skočio iz P> u D/B
	
	int start(0), gl_i(0), gl_j(0);
	for (start = 0; start < order.length(); start++) {
		if (order[start] == ' ') continue; 
		else break;
	}	
	for (int i = start; i < order.length(); i++) {
		
		if (order[i] == 'K') {
			for (int j = i+1; j < order.length(); j++) {
				if (order[j] != ' ') {
					greska = KodoviGresaka::SuvisanParametar;
					return false;
				}
			}
			komanda = Komande::KreirajIgru;
			goto out;
		}
		
		else if (order[i] == 'Z') {
			for (int j = i+1; j < order.length(); j++) {
				if (order[j] != ' ') {
					greska = KodoviGresaka::SuvisanParametar;
					return false;
				}
			}
			komanda = Komande::ZavrsiIgru;
			goto out;
		}
		
		else if (order[i] == 'D' || order[i] =='B') {
			jumped:
			bool JeLiBlokiraj;
			if (order[i] == 'B') JeLiBlokiraj = true;
			else JeLiBlokiraj = false;
			int j(0);
			if (jump) {
				i = gl_i;
				j = gl_j;
			}
			for (j = i+1; j < order.length(); j++) {
				
				if (order[j] >= '0' && order[j] <= '9') {
					int countx(0); int k(j);
					while (k < order.length() && order[k] >= '0' && order[k] <='9') {
						countx++; k++;
					}
					int pot_x = std::stoi(order.substr(j, countx));
					for (int l = k+1; l < order.length(); l++) {
						if (order[l] >= '0' && order[l] <= '9') {
							int county(0); int m(l);
							while (m < order.length() && order[m] >='0' && order[m] <= '9') {
								county++; m++;
							}
							int pot_y = std::stoi(order.substr(l, county));
							for (int n = m+1; n < order.length(); n++) {
								if (order[n]!=' ') {
									greska = KodoviGresaka::NeispravanParametar;
									return false;
								}
							}
							x = pot_x;
							y = pot_y;
							if (jump) {
								komanda = Komande::PomjeriDalje;
								jump = false;
								goto out;
							}
							if (JeLiBlokiraj) komanda = Komande::Blokiraj;
							else komanda = Komande::Deblokiraj;
							goto out;
						} else if (order[l]!=' ') {
							greska = KodoviGresaka::NeispravanParametar;
							return false;
						}
					}
				}
				else if (order[j] != ' ') {
					greska = KodoviGresaka::SuvisanParametar;
					return false;
				}
				
			}
			
			greska = KodoviGresaka::NedostajeParametar;
			return false;
		}
		
		else if (order[i] == 'P') {
			
			for (int j = i+1; j < order.length(); j++) {
				
				if (order[j] == 'O') {
					for (int k = j+1; k < order.length(); k++) {
						if (order[k] != ' ') {
							greska = KodoviGresaka::SuvisanParametar;
							return false;
						}
					}
					komanda = Komande::PrikaziOkolinu;
					goto out;
				}
				
				else if (order[j] == '>') {
					jump = true;
					gl_i = i; gl_j = j;
					goto jumped;
				}
				
				else if (order[j] == '1') {
					
					for (int k = j+1; k < order.length(); k++) {
						if ((order[k]>='A' && order[k]<='Z')||(order[k]>='a' && order[k]<='z')) { //slovo
							int start = k;
							while ((order[k]>='A' && order[k]<='Z')||(order[k]>='a' && order[k]<='z')) k++;
							k++;
							std::string potencijalna_komanda = order.substr(start, k-start);
							while (k < order.length()) {
								if (order[k] != ' ') {
									greska = KodoviGresaka::SuvisanParametar;
									return false;
								}
							}
							if (potencijalna_komanda == "GL") {
								komanda = Komande::PomjeriJednoMjesto;
								smjer = Smjerovi::GoreLijevo;
								return true;
							} else if (potencijalna_komanda == "G") {
								komanda = Komande::PomjeriJednoMjesto;
								smjer = Smjerovi::Gore;
								return true;
							} else if (potencijalna_komanda == "GD") {
								komanda = Komande::PomjeriJednoMjesto;
								smjer = Smjerovi::GoreDesno;
								return true;
							} else if (potencijalna_komanda == "D") {
								komanda = Komande::PomjeriJednoMjesto;
								smjer = Smjerovi::Desno;
								return true;
							} else if (potencijalna_komanda == "DoD") {
								komanda = Komande::PomjeriJednoMjesto;
								smjer = Smjerovi::DoljeDesno;
								return true;
							} else if (potencijalna_komanda == "Do") {
								komanda = Komande::PomjeriJednoMjesto;
								smjer = Smjerovi::Dolje;
								return true;
							} else if (potencijalna_komanda == "DoL") {
								komanda = Komande::PomjeriJednoMjesto;
								smjer = Smjerovi::DoljeLijevo;
								return true;
							} else if (potencijalna_komanda == "L") {
								komanda = Komande::PomjeriJednoMjesto;
								smjer = Smjerovi::Lijevo;
								return true;
							} else {
								greska = KodoviGresaka::NeispravanParametar;
								return false;
							}
						}
						else if (order[k] != ' ') {
							greska = KodoviGresaka::NeispravanParametar;
							return false;
						}
					}
					
					greska = KodoviGresaka::NedostajeParametar;
					return false;
				}
				
				else {
					greska = KodoviGresaka::PogresnaKomanda;
					return false;
				}
			}
			
			greska = KodoviGresaka::PogresnaKomanda;
			return false;
			
		}
		
		else {
			greska = KodoviGresaka::PogresnaKomanda;
			return false;
		}
	}
	
	out:
	return true;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//my Functions
void TekucaPozicija(int x, int y) {
	std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")" << std::endl;
}

void LoadEnter() {
	char a = std::cin.peek();
	if (a == '\n') a = getchar();
}
//end of my Functions

void IzvrsiKomandu (Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0) {
	
	if (komanda == Komande::PomjeriJednoMjesto) {
		
				try {
					auto status = Idi(polja, x, y, p_smjer);
					TekucaPozicija(x, y);
					
					if (status == Status::KrajPobjeda) {
						std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
						goto end_this_shit;
					} else if (status == Status::KrajPoraz) {
						std::cout << "Nagazili ste na minu" << std::endl;
						goto end_this_shit;
					}
				} catch (std::out_of_range err1) {
					std::cout << err1.what() << std::endl;
				} catch (std::logic_error err2) {
					std::cout << err2.what() << std::endl;
				}
		
	} else if (komanda == Komande::PomjeriDalje) {
		
				try {
					auto status = Idi(polja, x, y, p_x, p_y);
					TekucaPozicija(x, y);
					
					if (status == Status::KrajPobjeda) {
						std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
						goto end_this_shit;
					} else if (status == Status::KrajPoraz) {
						std::cout << "Nagazili ste na minu" << std::endl;
						goto end_this_shit;
					}
				} catch (std::out_of_range err1) {
					std::cout << err1.what() << std::endl;
				} catch (std::logic_error err2) {
					std::cout << err2.what() << std::endl;
				}
		 
	} else if (komanda == Komande::Blokiraj) {
		
				try {
					BlokirajPolje(polja, x, y);
				} catch (std::domain_error err) {
					std::cout << err.what() << std::endl;
				}
		
	} else if (komanda == Komande::Deblokiraj) {
		
				try {
					DeblokirajPolje(polja, x, y);
				} catch (std::domain_error err) {
					std::cout << err.what() << std::endl;
				}
		
	} else if (komanda == Komande::PrikaziOkolinu) {
		
				try {
					auto umfeld = PrikaziOkolinu(polja, x, y);
					for (int i = 0; i < 3; i++) {
						for (int j = 0; j < 3; j++) {
							std::cout << umfeld[i][j] << " ";
						}
						std::cout << std::endl;
					}
					std::cout << std::endl;
				} catch (std::domain_error err) {
					std::cout << err.what() << std::endl;
				}
		
	} else if (komanda == Komande::ZavrsiIgru) {
		end_this_shit:
				
				for (int i = 0; i < polja.size(); i++) {
					for (int j = 0; j < polja.size(); j++) {
						polja[i][j] = Polje::Prazno;
					}
				}
				
				throw std::runtime_error("Igra zavrsena");
		
	} else if (komanda == Komande::KreirajIgru) {
				
				std::cout << "Unesite broj polja: ";
				int n;
				std::cin >> n;
				
				std::cout << "Unesite pozicije mina: ";
				std::vector<std::vector<int>> mine;
				int mines_count(0);
				while (1) {
					std::string get_position;
					std::getline(std::cin, get_position);
					if (get_position == std::string(".")) break;
					
					//dovršiti
				}
	}
	
}


int main () {
	
	while (1) {
		try {
			std::cout << "Unesite komandu: ";
			Komande komanda;
			Smjerovi smjer;
			Tabla polja;
			int x, y, p_x, p_y;
			KodoviGresaka greska;
			bool stat = UnosKomande(komanda, smjer, x, y, greska);
			if (!stat) {
				PrijaviGresku(greska);
				continue;
			}
			IzvrsiKomandu (komanda, polja, x, y, smjer, p_x, p_y);
		} catch (...) {
			std::cout << "Dovidjenja!";
		}
	}
	
	return 0;
}
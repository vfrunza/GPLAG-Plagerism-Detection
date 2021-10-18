#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <stdexcept>
#include <string>
#include <sstream>

template<typename T> std::string PretvoriUString(T x) {
	std::ostringstream s; s << x; return s.str();
}

enum class Polje {
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina 
};

typedef std::vector<std::vector<Polje>> Tabla;

void Ispisi(Tabla m) {
	for(int i = 0; i < m.size(); i++) {
		for(int j = 0; j < m.size(); j++) {
			std::cout << int(m[i][j]) << " ";
		}
		std::cout << std::endl;
	}
}
void Ispisi(std::vector<std::vector<int>> m) {
	for(int i = 0; i < m.size(); i++) {
		for(int j = 0; j < m.size(); j++) {
			std::cout << m[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine) {
	for(int i = 0; i < mine.size(); i++) 
		if(mine[i].size() != 2) 
			throw std::domain_error("Ilegalan format zadavanja mina");
			
	for(int i = 0; i < mine.size(); i++) {
		for(int j = 0; j < mine[0].size(); j++) {
			if(mine[i][j] > n)
				throw std::domain_error("Ilegalne pozicije mina");
		}
	}
	
	Tabla igraca_tabla(n, std::vector<Polje> (n, Polje::Prazno));
	
	for(int i = 0; i < mine.size(); i++) {
		igraca_tabla[mine[i][0]][mine[i][1]] = Polje::Mina; 
	}
	
	return igraca_tabla;
}

int brojMina(Tabla m, int x, int y) {
	int broj_mina = 0;
	int vel = m.size() - 1;
	
	// PRVI RED
	if(x-1 >= 0 && y-1 >= 0 && x-1 <= vel && y-1 <= vel) 
		if(m[x-1][y-1] == Polje::Mina) broj_mina++;
	if(x-1 >= 0 && y >= 0  && x-1 <= vel && y <= vel) 
		if(m[x-1][y] == Polje::Mina) broj_mina++;
	if(x-1 >= 0 && y+1 >= 0 && x-1 <= vel  && y+1 <= vel) 
		if(m[x-1][y+1] == Polje::Mina) broj_mina++;
		
	// DRUGI RED
	if(x >= 0 && y-1 >= 0 && x <= vel && y <= vel) 
		if(m[x][y-1] == Polje::Mina) broj_mina++;
	if(x >= 0 && y+1 >= 0  && x <= vel && y+1 <= vel) 
		if(m[x][y+1] == Polje::Mina) broj_mina++;
		
	// TRECI RED
	if(x+1 >= 0 && y-1 >= 0 && x+1 <= vel && y-1 <= vel) 
		if(m[x+1][y-1] == Polje::Mina) broj_mina++;
	if(x+1 >= 0 && y >= 0 && x+1 <= vel && y <= vel) 
		if(m[x+1][y] == Polje::Mina) broj_mina++;
	if(x+1 >= 0 && x+1 >= 0 && x+1 <= vel && y+1 <= vel) 
		if(m[x+1][y+1] == Polje::Mina) broj_mina++;
	
	return broj_mina;
}
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y) {
	if(x > polja.size() - 1 || y > polja.size() - 1 || x < 0 || y < 0) {
		std::string izuzetak = "Polje (" + PretvoriUString(x) + "," + PretvoriUString(y) + ") ne postoji";
		throw std::domain_error(izuzetak);
	}
		
	std::vector<std::vector<int>> m(3, std::vector<int>(3));
	
	for(int i = 0, brojac_redova = x - 1; i < 3; i++, brojac_redova++) {
		for(int j = 0, brojac_kolona = y - 1; j < 3; j++, brojac_kolona++) {
			m[i][j] = brojMina(polja, brojac_redova, brojac_kolona);
		}
	}
	
	return m;
}

void BlokirajPolje(Tabla &polja, int x, int y) {
	if(x > polja.size() - 1 || y > polja.size() - 1 || x < 0 || y < 0) {
		std::string izuzetak = "Polje (" + PretvoriUString(x) + "," + PretvoriUString(y) + ") ne postoji";
		throw std::domain_error(izuzetak);
	}
	
	if(polja[x][y] == Polje::Prazno) {
		polja[x][y] = Polje::BlokiranoPrazno;
	}
	else if(polja[x][y] == Polje::Posjeceno) {
		polja[x][y] = Polje::BlokiranoPosjeceno;
	}
	else if(polja[x][y] == Polje::Mina) {
		polja[x][y] = Polje::BlokiranoMina;
	}
}
void DeblokirajPolje(Tabla &polja, int x, int y) {
	if(x > polja.size() - 1 || y > polja.size() - 1 || x < 0 || y < 0) {
		std::string izuzetak = "Polje (" + PretvoriUString(x) + "," + PretvoriUString(y) + ") ne postoji";
		throw std::domain_error(izuzetak);
	}
		
	if(polja[x][y] == Polje::BlokiranoPrazno) {
		polja[x][y] = Polje::Prazno;
	}
	else if(polja[x][y] == Polje::BlokiranoPosjeceno) {
		polja[x][y] = Polje::Posjeceno;
	}
	else if(polja[x][y] == Polje::BlokiranoMina) {
		polja[x][y] = Polje::Mina;
	}
}

enum class Smjerovi {
	GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};
enum class Status {
	NijeKraj, KrajPoraz, KrajPobjeda
};

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer) {
	int vel = polja.size() - 1;
	
	if(smjer == Smjerovi::GoreLijevo && x-1 >= 0 && y-1 >= 0) {
		if(polja[x-1][y-1] == Polje::BlokiranoMina || polja[x-1][y-1] == Polje::BlokiranoPosjeceno || polja[x-1][y-1] == Polje::BlokiranoPrazno)
			throw std::logic_error("Blokirano polje");
		polja[x][y] = Polje::Posjeceno;
		x -= 1; y -= 1;
	}
	else if(smjer == Smjerovi::Gore && x-1 >= 0) {
		if(polja[x-1][y] == Polje::BlokiranoMina || polja[x-1][y] == Polje::BlokiranoPosjeceno || polja[x-1][y] == Polje::BlokiranoPrazno)
			throw std::logic_error("Blokirano polje");
		polja[x][y] = Polje::Posjeceno;
		x -= 1;
	}
	else if(smjer == Smjerovi::GoreDesno && x-1 >= 0 && y+1 <= vel) {
		if(polja[x-1][y+1] == Polje::BlokiranoMina || polja[x-1][y+1] == Polje::BlokiranoPosjeceno || polja[x-1][y+1] == Polje::BlokiranoPrazno)
			throw std::logic_error("Blokirano polje");
		polja[x][y] = Polje::Posjeceno;
		x -= 1; y += 1;
	}
	else if(smjer == Smjerovi::Desno && y+1 <= vel) {
		if(polja[x][y+1] == Polje::BlokiranoMina || polja[x][y+1] == Polje::BlokiranoPosjeceno || polja[x][y+1] == Polje::BlokiranoPrazno)
			throw std::logic_error("Blokirano polje");
		polja[x][y] = Polje::Posjeceno;
		y += 1;
	}
	else if(smjer == Smjerovi::DoljeDesno && x+1 <= vel && y+1 <= vel) {
		if(polja[x+1][y+1] == Polje::BlokiranoMina || polja[x+1][y+1] == Polje::BlokiranoPosjeceno || polja[x+1][y+1] == Polje::BlokiranoPrazno)
			throw std::logic_error("Blokirano polje");
		polja[x][y] = Polje::Posjeceno;
		x += 1; y += 1;
	}
	else if(smjer == Smjerovi::Dolje && x+1 <= vel ) {
		if(polja[x+1][y] == Polje::BlokiranoMina || polja[x+1][y] == Polje::BlokiranoPosjeceno || polja[x+1][y] == Polje::BlokiranoPrazno)
			throw std::logic_error("Blokirano polje");
		polja[x][y] = Polje::Posjeceno;
		x += 1;
	}
	else if(smjer == Smjerovi::DoljeLijevo && x+1 <= vel && y-1 >= 0) {
		if(polja[x+1][y-1] == Polje::BlokiranoMina || polja[x+1][y-1] == Polje::BlokiranoPosjeceno || polja[x+1][y-1] == Polje::BlokiranoPrazno)
			throw std::logic_error("Blokirano polje");
		polja[x][y] = Polje::Posjeceno;
		x += 1; y -= 1;
	}
	else if(smjer == Smjerovi::Lijevo && y-1 >= 0) {
		if(polja[x][y-1] == Polje::BlokiranoMina || polja[x][y-1] == Polje::BlokiranoPosjeceno || polja[x][y-1] == Polje::BlokiranoPrazno)
			throw std::logic_error("Blokirano polje");
		polja[x][y] = Polje::Posjeceno;
		y -= 1;
	} 
	else throw std::out_of_range("Izlazak van igrace table");
	
	if(polja[x][y] == Polje::Mina) {
		for(int i = 0; i < polja.size(); i++) {
			for(int j = 0; j < polja.size(); j++) {
				polja[i][j] = Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
	bool ImaLiPraznih = false;
	for(int i = 0; i < polja.size(); i++) {
		for(int j = 0; j < polja.size(); j++) {
			if(i == x && j == y) continue;
			if(polja[i][j] == Polje::Prazno) {
				ImaLiPraznih = true;
			}
		}
	}
	if(ImaLiPraznih == false) return Status::KrajPobjeda;
	return Status::NijeKraj;
}
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y) {
	if(novi_x < 0 || novi_y < 0 || novi_x > polja.size() - 1 || novi_y > polja.size() - 1)
		throw std::out_of_range("Izlazak van igrace table");
	if(polja[novi_x][novi_y] == Polje::BlokiranoMina || polja[novi_x][novi_y] == Polje::BlokiranoPosjeceno || polja[novi_x][novi_y] == Polje::BlokiranoPrazno)
		throw std::logic_error("Blokirano polje");
	
	polja[x][y] = Polje::Posjeceno;
	x = novi_x;
	y = novi_y;
		
	if(polja[x][y] == Polje::Mina) {
		for(int i = 0; i < polja.size(); i++) {
			for(int j = 0; j < polja.size(); j++) {
				polja[i][j] = Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
	bool ImaLiPraznih = false;
	for(int i = 0; i < polja.size(); i++) {
		for(int j = 0; j < polja.size(); j++) {
			if(i == x && j == y) continue;
			if(polja[i][j] == Polje::Prazno) {
				ImaLiPraznih = true;
			}
		}
	}
	if(ImaLiPraznih == false) return Status::KrajPobjeda;
	return Status::NijeKraj;
}

enum class KodoviGresaka {
	PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};
void PrijaviGresku(KodoviGresaka greska) {
	if(greska == KodoviGresaka::PogresnaKomanda)
		std::cout << "Nerazumljiva komanda!\n";
	else if(greska == KodoviGresaka::NedostajeParametar) 
		std::cout << "Komanda trazi parametar koji nije naveden!\n";
	else if(greska == KodoviGresaka::SuvisanParametar)
		std::cout << "Zadan je suvisan parametar nakon komande!\n";
	else if(greska == KodoviGresaka::NeispravanParametar)
		std::cout << "Parametar komande nije ispravan!\n";
}

enum class Komande {
	PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, 
	ZavrsiIgru, KreirajIgru
};

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska) {
	std::string k;
	std::getline(std::cin, k);
	
	std::string p1 = "";
	bool usao = false;
	int brojac = 0;
	
	for(int i = 0; i < k.length(); i++) {
		if(k[i] == ' ') continue;
		
		if(k[i] == 'P' && i+1 < k.length() && k[i+1] == '1') {
			for(int j = i+2; j < k.length(); j++) {
				if(k[j] == ' ') continue;
				usao = true;
				
				if(k[j] == 'G' && j+1 < k.length() && k[j+1] == 'D') {
					for(int l = j+2; l < k.length(); l++) {
						if(k[l] == ' ') continue;
						else {
							greska = KodoviGresaka::SuvisanParametar;
							goto izlaz;
						}
					}
					komanda = Komande::PomjeriJednoMjesto;
					smjer = Smjerovi::GoreDesno;
					return true;
				}
				else if(k[j] == 'G' && j+1 < k.length() && k[j+1] == 'L') {
					for(int l = j+2; l < k.length(); l++) {
						if(k[l] == ' ') continue;
						else {
							greska = KodoviGresaka::SuvisanParametar;
							goto izlaz;
						}
					}
					komanda = Komande::PomjeriJednoMjesto;
					smjer = Smjerovi::GoreLijevo;
					return true;;
				}
				else if(k[j] == 'G') {
					for(int l = j+1; l < k.length(); l++) {
						if(k[l] == ' ') continue;
						else {
							greska = KodoviGresaka::SuvisanParametar;
							goto izlaz;
						}
					}
					komanda = Komande::PomjeriJednoMjesto;
					smjer = Smjerovi::Gore;
					return true;
				}
				
				else if(k[j] == 'D' && j+2 < k.length() && k[j+1] == 'o' && k[j+2] == 'D') {
					for(int l = j+3; l < k.length(); l++) {
						if(k[l] == ' ') continue;
						else {
							
							greska = KodoviGresaka::SuvisanParametar;
							goto izlaz;
						}
					}
					komanda = Komande::PomjeriJednoMjesto;
					smjer = Smjerovi::DoljeDesno;
					return true;
				}
				else if(k[j] == 'D' && j+2 < k.length() && k[j+1] == 'o' && k[j+2] == 'L') {
					for(int l = j+3; l < k.length(); l++) {
						if(k[l] == ' ') continue;
						else {
							greska = KodoviGresaka::SuvisanParametar;
							goto izlaz;
						}
					}
					komanda = Komande::PomjeriJednoMjesto;
					smjer = Smjerovi::DoljeLijevo;
					return true;
				}
				else if(k[j] == 'D' && j+1 < k.length() && k[j+1] == 'o') {
					
					for(int l = j+2; l < k.length(); l++) {
						if(k[l] == ' ') continue;
						else {
							
							greska = KodoviGresaka::SuvisanParametar;
							goto izlaz;
						}
					}
					komanda = Komande::PomjeriJednoMjesto;
					smjer = Smjerovi::Dolje;
					
					return true;
				}
			
				else if(k[j] == 'D') {
					for(int l = j+1; l < k.length(); l++) {
						if(k[l] == ' ') continue;
						else {
							greska = KodoviGresaka::SuvisanParametar;
							goto izlaz;
						}
					}
					komanda = Komande::PomjeriJednoMjesto;
					smjer = Smjerovi::Desno;
					return true;
				}
				else if(k[j] == 'L') {
					for(int l = j+1; l < k.length(); l++) {
						if(k[l] == ' ') continue;
						else {
							greska = KodoviGresaka::SuvisanParametar;
							goto izlaz;
						}
					}
					komanda = Komande::PomjeriJednoMjesto;
					smjer = Smjerovi::Lijevo;
					return true;
				}
				else if(k[j] == 'D' && j+2 < k.length() && k[j+1] == 'o') {
					
					for(int l = j+2; l < k.length(); l++) {
						if(k[l] == ' ') continue;
						else {
							
							greska = KodoviGresaka::SuvisanParametar;
							goto izlaz;
						}
					}
					komanda = Komande::PomjeriJednoMjesto;
					smjer = Smjerovi::Dolje;
					
					return true;
				}
				else {
					greska = KodoviGresaka::NeispravanParametar;
					goto izlaz;
				}
			}
			if(usao == false) {
				greska = KodoviGresaka::NedostajeParametar;
				goto izlaz;
			}
		}
		else if(k[i] == 'K') {
			for(int j = i+1; j < k.length(); j++) {
				if(k[j] == ' ') continue;
				else {
					greska = KodoviGresaka::SuvisanParametar;
					goto izlaz;
				}
			}
			komanda = Komande::KreirajIgru;
			return true;
		}
		else if(k[i] == 'P' && i+1 < k.length() && k[i+1] == 'O') {
			for(int j = i+2; j < k.length(); j++) {
				if(k[j] == ' ') continue;
				else {
					greska = KodoviGresaka::SuvisanParametar;
					goto izlaz;
				}
			}
			komanda = Komande::PrikaziOkolinu;
			return true;
		}
		else if(k[i] == 'Z') {
			for(int j = i+1; j < k.length(); j++) {
				if(k[j] == ' ') continue;
				else {
					greska = KodoviGresaka::SuvisanParametar;
					goto izlaz;
				}
			}
			komanda = Komande::ZavrsiIgru;
			return true;
		}
		else if(k[i] == 'B') {
			for(int j = i+1; j < k.length(); j++) {
				if(k[j] == ' ') continue;
				
				usao = true;
				p1.erase(p1.begin(), p1.end());
				
				if(brojac > 1) {
					greska = KodoviGresaka::SuvisanParametar;
					goto izlaz;
				}
				
				if(k[j] >= '0' && k[j] <= '9') {
					while(j < k.length() && k[j] >= '0' && k[j] <= '9') {
						p1 += k[j++];
					}
					if(brojac == 0) {
						x = std::stoi(p1);
						brojac++;
					}
					else if(brojac == 1) {
						y = std::stoi(p1);
						brojac++;
					}
				}
				else {
					greska = KodoviGresaka::NeispravanParametar;
					goto izlaz;
				}
			}
			
			if(usao == false) {
				greska = KodoviGresaka::NedostajeParametar;
				goto izlaz;
			} 
			
			komanda = Komande::Blokiraj;
			return true;
		}
		else if(k[i] == 'D') {
			for(int j = i+1; j < k.length(); j++) {
				if(k[j] == ' ') continue;
				
				usao = true;
				p1.erase(p1.begin(), p1.end());
				
				if(brojac > 1) {
					greska = KodoviGresaka::SuvisanParametar;
					goto izlaz;
				}
				
				if(k[j] >= '0' && k[j] <= '9') {
					while(j < k.length() && k[j] >= '0' && k[j] <= '9') {
						p1 += k[j++];
					}
					if(brojac == 0) {
						x = std::stoi(p1);
						brojac++;
					}
					else if(brojac == 1) {
						y = std::stoi(p1);
						brojac++;
					}
				}
				else {
					greska = KodoviGresaka::NeispravanParametar;
					goto izlaz;
				}
			}
			
			if(usao == false) {
				greska = KodoviGresaka::NedostajeParametar;
				goto izlaz;
			}
			
			komanda = Komande::Deblokiraj;
			return true;
		}
		else if(k[i] == 'P' && i+1 < k.length() && k[i+1] == '>') {
			for(int j = i+2; j < k.length(); j++) {
				if(k[j] == ' ') continue;
				usao = true;
				p1.erase(p1.begin(), p1.end());
				if(brojac > 1) {
					greska = KodoviGresaka::SuvisanParametar;
					goto izlaz;
				}
				
				if(k[j] >= '0' && k[j] <= '9') {
					while(j < k.length() && k[j] >= '0' && k[j] <= '9') {
						p1 += k[j++];
					}
					if(brojac == 0) {
						x = std::stoi(p1);
						brojac++;
					}
					else if(brojac == 1) {
						y = std::stoi(p1);
						brojac++;
					}
				}
				else {
					greska = KodoviGresaka::NeispravanParametar;
					goto izlaz;
				}
				
			}
			if(usao == false) {
				greska = KodoviGresaka::NedostajeParametar;
				goto izlaz;
			}
			
			komanda = Komande::PomjeriDalje;
			return true;
		}
		else {
			greska = KodoviGresaka::PogresnaKomanda;
			goto izlaz;
		}
	}
	
izlaz:
	return false;
	
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y,
Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0) {
	if(komanda == Komande::PomjeriJednoMjesto) {
		Status s;
		s = Idi(polja, x, y, p_smjer);
		
		if(s == Status::KrajPobjeda) {
			std::cout << "Bravo, obisli ste sva sigurna polja\n";
			for(int i = 0; i < polja.size(); i++) {
				for(int j = 0; j < polja.size(); j++) {
					polja[i][j] = Polje::Prazno;
				}
			}
			throw std::runtime_error("Igra zavrsena\n");
		}
		else if(s == Status::KrajPoraz) {
			std::cout << "Nagazili ste na minu\n";
			for(int i = 0; i < polja.size(); i++) {
				for(int j = 0; j < polja.size(); j++) {
					polja[i][j] = Polje::Prazno;
				}
			}
			throw std::runtime_error("Igra zavrsena\n");			
		}
		
		std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")\n";
	}
	else if(komanda == Komande::PomjeriDalje) {
		Status s;
		s = Idi(polja, x, y, p_x, p_y);	
		
		if(s == Status::KrajPobjeda) {
			std::cout << "Bravo, obisli ste sva sigurna polja\n";
			for(int i = 0; i < polja.size(); i++) {
				for(int j = 0; j < polja.size(); j++) {
					polja[i][j] = Polje::Prazno;
				}
			}
			throw std::runtime_error("Igra zavrsena");
		}
		else if(s == Status::KrajPoraz) {
			std::cout << "Nagazili ste na minu\n";
			for(int i = 0; i < polja.size(); i++) {
				for(int j = 0; j < polja.size(); j++) {
					polja[i][j] = Polje::Prazno;
				}
			}
			throw std::runtime_error("Igra zavrsena\n");			
		}
		
		std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")\n";
	}
	else if(komanda == Komande::Blokiraj) {
		BlokirajPolje(polja, p_x, p_y);
	}
	else if(komanda == Komande::Deblokiraj) {
		DeblokirajPolje(polja, p_x, p_y);
	}
	else if(komanda == Komande::PrikaziOkolinu) {
		auto m = PrikaziOkolinu(polja, x, y);
		Ispisi(m);
	}
	else if(komanda == Komande::ZavrsiIgru) {
		for(int i = 0; i < polja.size(); i++) {
			for(int j = 0; j < polja.size(); j++) {
				polja[i][j] = Polje::Prazno;
			}
		}
		throw std::runtime_error("Igra zavrsena");
	}
	else if(komanda == Komande::KreirajIgru) {
		int broj_polja;
		std::cout << "Unesite broj polja: ";
		std::cin >> broj_polja;
		std::string unos;
		
		std::vector<std::vector<int>> mine;
		std::vector<int> pomocni;
		
		std::cin.clear();
		std::cin.ignore(10000,'\n');
		
		std::cout << "Unesite pozicije mina: ";
		while(true) {
			std::getline(std::cin, unos);
			
			if(unos == ".") break;
			if(unos[0] != '(') {
				std::cout << "Greska, unesite ponovo!\n";
				continue;
			}
			std::string p1;
			std::string p2;
			for(int i = 1; i < unos.length(); i++) {
				while(i < unos.length() && unos[i] != ',' && unos[i] >= '0' && unos[i] <= '9') {
					p1+=unos[i];
					i++;
				}
				if(unos[i] != ',') {
					std::cout << "Greska, unesite ponovo!\n";
					break;
				}
				else {
					pomocni.push_back(std::stoi(p1));
					i++;
					while(i < unos.length() && unos[i] != ')' && unos[i] >= '0' && unos[i] <= '9') {
						p2+=unos[i];
						i++;
					}
					if(unos[i] != ')') {
						std::cout << "Greska, unesite ponovo!\n";
						pomocni.erase(pomocni.begin(), pomocni.end());
						break;
					}
					else {
						if(std::stoi(p1) > broj_polja-1 || std::stoi(p2) > broj_polja-1 || std::stoi(p1) < 0 || std::stoi(p2) < 0) {
							std::cout << "Greska, unesite ponovo!\n";
							pomocni.erase(pomocni.begin(), pomocni.end());
							break;							
						}
						pomocni.push_back(std::stoi(p2));
						mine.push_back(pomocni);
						pomocni.erase(pomocni.begin(), pomocni.end());
					}
				}
			}
		}
		polja = KreirajIgru(broj_polja, mine);
	}
}

int main() {
	bool daLiJeIspravanUnos;
	Komande komanda;
	Smjerovi smjer;
	int x = 0; int y = 0;
	KodoviGresaka greska;
	Tabla polja;
	int p_x = 0, p_y = 0;
	
	while(true) {
		std::cout << "Unesite komandu: ";
		
		daLiJeIspravanUnos = UnosKomande(komanda, smjer, p_x, p_y, greska);
		
		if(daLiJeIspravanUnos == false) {
			PrijaviGresku(greska);
		}
		else {
			try {
				IzvrsiKomandu(komanda, polja, x, y, smjer, p_x, p_y);
			}
			catch(std::runtime_error) {
				std::cout << "Dovidjenja!";
				return 0;
			}
			catch(std::domain_error izuzetak) {
				std::cout << izuzetak.what();
				std::cout << std::endl;
			}
			catch(std::logic_error izuzetak) {
				std::cout << izuzetak.what();
				std::cout << std::endl;
			}
			catch(std::out_of_range izuzetak) {
				std::cout << izuzetak.what();
				std::cout << std::endl;
			}
		}
	}
	return 0;
}
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <string>
#include <deque>
#include <cmath>

enum class Polje {
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};
enum class Smjerovi {
	GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};
enum class KodoviGresaka {
	PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};
enum class Komande {
	PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru,
	KreirajIgru
};
enum class Status {
	NijeKraj, KrajPoraz, KrajPobjeda
};

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru (int n, const std::vector<std::vector<int>> &mine) {
	Tabla kreirana_tabla (n, std::vector<Polje> (n, Polje::Prazno));
	
	for (int i=0; i<mine.size(); i++) {
			if (mine[i].size() < 2 || mine[i].size() > 2)
				throw std::domain_error ("Ilegalan format zadavanja mina");
			if (mine[i][0] < 0 || mine[i][0] > (n-1) || mine[i][1] < 0 || mine[i][1] > (n-1))
				throw std::domain_error ("Ilegalne pozicije mina");
		}
	for (int i=0; i<mine.size(); i++) {
		int prvi = mine[i][0];
		int drugi = mine[i][1];
		for (int j=0; j<n; j++) {
			for (int k=0; k<n; k++) {
				if (j==prvi && k==drugi)
					kreirana_tabla[j][k] = Polje::Mina;
			}
		}
	}
	return kreirana_tabla;
}
std::vector<std::vector<int>> PrikaziOkolinu (const Tabla &polja, int x, int y) {
	std::string izuzetak = "Polje (" + std::to_string (x) + "," + std::to_string(y) +") ne postoji";
	if (x < 0 || y < 0 || x >= polja.size() || y >= polja.size())
		throw std::domain_error (izuzetak);
	std::vector<std::vector<int>> mat (3, std::vector<int> (3));
	for (int i=x-1, a=0; a<3; a++, i++) {
		for (int j=y-1, b=0; b<3; b++, j++) {
				if (i>=0 && j>=0 && i<polja.size() && j<polja.size()) {
					int broj_mina(0);
					for (int c=i-1, d=0; d<3; c++, d++) {
						for (int e=j-1, f=0; f<3; e++, f++) {
							if (d==1 && f==1) continue;
							else if (c>=0 && e>=0 && c<polja.size() && e<polja.size() && polja[c][e]==Polje::Mina)
							broj_mina++;
						}
					}
					mat[a][b] = broj_mina;
				}
				else
					mat[a][b]=0;
			}
		}
	return mat;
}
Status Idi (Tabla &polja, int &x, int &y, int novi_x, int novi_y) {
	if (novi_y < 0 || novi_x < 0 || novi_x >= polja.size() || novi_y >= polja.size())
		throw std::out_of_range ("Izlazak van igrace table");

	if (polja[novi_x][novi_y] == (Polje::BlokiranoPosjeceno) || polja[novi_x][novi_y] ==  (Polje::BlokiranoPrazno) || polja[novi_x][novi_y] == (Polje::BlokiranoMina))
		throw std::logic_error ("Blokirano polje");

	int staro_x (x), staro_y (y);
	x = novi_x;
	y = novi_y;
	polja[staro_x][staro_y] = Polje::Posjeceno;
	
	if (polja[x][y] == Polje::Mina) {
		for (int i=0; i<polja.size(); i++) {
			for (int j=0; j<polja[i].size(); j++) 
				polja[i][j] = Polje::Prazno;
		}
		return Status::KrajPoraz;
	}
	bool posjeceno (true);
	for (int i=0; i<polja.size(); i++) {
		for (int j=0; j<polja[i].size(); j++) {
			if (polja[i][j] == Polje::BlokiranoPrazno || polja[i][j] == Polje::Prazno) {
				posjeceno = false;
				break;
			}
		}
	}
	if (posjeceno)	return Status::KrajPobjeda;
	return Status::NijeKraj;
}
bool da_li_je_blokirana (Tabla &polja, int x, int y) {
	bool jeste = false;
	if (polja[x][y] == Polje::BlokiranoPosjeceno || polja[x][y] == Polje::BlokiranoMina || polja[x][y] == Polje::BlokiranoPrazno)
		jeste = true;
	return jeste;
}
Status Idi (Tabla &polja, int &x, int &y, Smjerovi smjer) {
	if (smjer == Smjerovi::GoreLijevo) { 
		if (x <= 0) throw std::out_of_range ("Izlazak van igrace table");
		x -= 1; y -= 1;
		if (da_li_je_blokirana(polja,x,y)) throw std::logic_error ("Blokirano polje");
		polja[x + 1][y+1] = Polje::Posjeceno;
	}
	else if (smjer == Smjerovi::Gore) {
		if (x <= 0) throw std::out_of_range ("Izlazak van igrace table");
		x -= 1;
		if (da_li_je_blokirana(polja,x,y)) throw std::logic_error ("Blokirano polje");
		polja[x + 1][y] = Polje::Posjeceno;
	}
	else if (smjer == Smjerovi::GoreDesno)  { 
		if (x <= 0) throw std::out_of_range ("Izlazak van igrace table");
		x -= 1; y += 1;
		if (da_li_je_blokirana(polja,x,y)) throw std::logic_error ("Blokirano polje");
		polja[x + 1][y-1] = Polje::Posjeceno;
	}
	else if (smjer == Smjerovi::Desno) {
		if (y >= polja[0].size()) throw std::out_of_range ("Izlazak van igrace table");
		y += 1;
		if (da_li_je_blokirana(polja,x,y)) throw std::logic_error ("Blokirano polje");
		polja[x][y - 1] = Polje::Posjeceno;
	}
	else if (smjer == Smjerovi::DoljeDesno) { 
		if (x >= polja.size() || y >= polja[0].size()) throw std::out_of_range ("Izlazak van igrace table");
		x += 1;
		y += 1;
		if (da_li_je_blokirana(polja,x,y)) throw std::logic_error ("Blokirano polje");
		polja[x - 1][y-1] = Polje::Posjeceno;
	}
	else if (smjer == Smjerovi::DoljeLijevo) { 
		if (x >= polja.size() || y <= 0) throw std::out_of_range ("Izlazak van igrace table");
		x += 1;
		y -= 1;
		if (da_li_je_blokirana(polja,x,y)) throw std::logic_error ("Blokirano polje");
		polja[x - 1][y+1] = Polje::Posjeceno;
	}
	else if (smjer == Smjerovi::Dolje) {
		if (x >= polja.size()) throw std::out_of_range ("Izlazak van igrace table");
		x += 1;
		if (da_li_je_blokirana(polja,x,y)) throw std::logic_error ("Blokirano polje");
		polja[x - 1][y] = Polje::Posjeceno;
	}
	else if (smjer == Smjerovi::Lijevo) {
		if (y <= 0) throw std::out_of_range ("Izlazak van igrace table");
		y -= 1;
		if (da_li_je_blokirana(polja,x,y)) throw std::logic_error ("Blokirano polje");
		polja[x][y + 1] = Polje::Posjeceno;
	}
	if (polja[x][y] == Polje::Mina) {
		for (int i=0; i<polja.size(); i++) {
			for (int j=0; j<polja[i].size(); j++) 
				polja[i][j] = Polje::Prazno;
		}
		return Status::KrajPoraz;
	}
	bool posjeceno (true);
	for (int i=0; i<polja.size(); i++) {
		for (int j=0; j<polja[i].size(); j++) {
			if (polja[i][j] == Polje::Prazno || polja[i][j] == Polje::BlokiranoPrazno) {
				posjeceno = false;
				break;
			}
		}
	}
	if (posjeceno) return Status::KrajPobjeda;
	return Status::NijeKraj;
}

void BlokirajPolje (Tabla &polja, int x, int y) {
	std::string izuzetak = "Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji";
	for (int i=0; i<polja.size(); i++) {
		for (int j=0; j<polja[i].size(); j++) {
			if (x >= polja.size() || y >= polja.size() || x >= polja[i].size() || y > polja[i].size())
				throw std::domain_error (izuzetak);
				
			if (polja[x][y] == Polje::Prazno)
				polja[x][y] = Polje::BlokiranoPrazno;
			else if (polja[x][y] == Polje::Posjeceno)
				polja[x][y] = Polje::BlokiranoPosjeceno;
			else if (polja[x][y] == Polje::Mina)
				polja[x][y] = Polje::BlokiranoMina;
			else
				polja[x][y] = polja[x][y];
		}
	}
}
void DeblokirajPolje (Tabla &polja, int x, int y) {
	std::string poruka = "Polje (" + std::to_string (x) + "," + std::to_string (y) + ") ne postoji";
	for (int i=0; i<polja.size(); i++) {
		for (int j=0; j<polja[i].size(); j++) {
			if (x >= polja.size() || y >= polja.size() ||  x >= polja[i].size() || y >= polja[i].size())
				throw std::domain_error (poruka);
				
			if (polja[x][y] == Polje::BlokiranoPrazno)
				polja[x][y] = Polje::Prazno;
			else if (polja[x][y] == Polje::BlokiranoPosjeceno)
				polja[x][y] = Polje::Posjeceno;
			else if (polja[x][y] == Polje::BlokiranoMina)
				polja[x][y] = Polje::Mina;
			else
				polja[x][y] = polja[x][y];
		}
	}
}
void PrijaviGresku (KodoviGresaka greska) {
	if (greska == KodoviGresaka::PogresnaKomanda)
		std::cout << "Nerazumljiva komanda!" << std::endl;
	else if (greska == KodoviGresaka::NedostajeParametar) 
		std::cout << "Komanda trazi parametar koji nije naveden!" << std::endl;
	else if (greska == KodoviGresaka::NeispravanParametar)
		std::cout << "Parametar komande nije ispravan!" << std::endl;
	else if (greska == KodoviGresaka::SuvisanParametar)
		std::cout << "Zadan je suvisan parametar nakon komande!" << std::endl;
}
bool UnosKomande (Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska) {
	std::string komande;
	std::getline (std::cin, komande);
	
	if (komande.length() == 0) {
		greska = KodoviGresaka::PogresnaKomanda;
		return false;
	}
	for (int i=0; i<komande.length(); i++) {
		if (komande[i] == ' ') continue;
		else if (komande[i] == 'P' && komande.size() == 1) {
			greska = KodoviGresaka::PogresnaKomanda;
			return false;
		}
		else if (komande[i] == 'P') {
			for (int j=i+1; j<komande.size(); j++) {
				if (komande[j] != '1' && komande[j] != 'O' && komande[j] != '>') {
					greska = KodoviGresaka::PogresnaKomanda;
					return false;
				}
				else if (komande[j] == '1') { //P1
					for (int k=j+1; k<komande.length(); k++) {
						if (komande[k] == ' ') continue;
						else if (komande[k] != ' ' && komande[k] != 'G' && komande[k] != 'D' && komande[k] != 'L') {
							greska = KodoviGresaka::NedostajeParametar;
							return false;
						}
						else if (komande[k] == 'G') {
							if (komande[k] == 'G' && k == komande.length()-1) { //Gore
								smjer = Smjerovi::Gore;
								komanda = Komande::PomjeriJednoMjesto;
								return true;
							}
							for (int e=k+1; e<komande.length(); e++) {
								if (komande[e] != 'L' && komande[e] != 'D') {
									greska = KodoviGresaka::NedostajeParametar;
									return false;
								}
								else if (komande[e] == 'L') { //GoreLijevo
									smjer = Smjerovi::GoreLijevo;
									komanda = Komande::PomjeriJednoMjesto;
									return true;
								}
								else if (komande[e] == 'D') { //GoreDesno
									smjer = Smjerovi::GoreDesno;
									komanda = Komande::PomjeriJednoMjesto;
									return true;
								}
							}
						}
						else if (komande[k] == 'D') {
							if (komande[k] == 'D' && k == komande.length() - 1) { //Desno
								smjer = Smjerovi::Desno;
								return true;
							}
							for (int e=k+1; e<komande.length(); e++) {
								if (komande[e] != 'o') {
									greska = KodoviGresaka::SuvisanParametar;
									return false;
								}
								else if (komande[e] == 'o' && e == komande.length()-1) { //Dolje
									smjer = Smjerovi::Dolje;
									komanda = Komande::PomjeriJednoMjesto;
									return true;
								}
								else if (komande[e] == 'o') {
									for (int f=e+1; f<komande.length(); f++) {
										if (komande[f] != 'D' && komande[f] != 'L') {
											greska = KodoviGresaka::SuvisanParametar;
											return false;
										}
										else if (komande[f] ==  'D') { //DoljeDesno
											smjer = Smjerovi::DoljeDesno;
											komanda = Komande::PomjeriJednoMjesto;
											return true;
										}
										else if (komande[f] == 'L') { //DoljeLijevo
											smjer = Smjerovi::DoljeLijevo;
											return true;
											komanda = Komande::PomjeriJednoMjesto;
										}
									}
								}
							}
						}
						else if (komande[k] == 'L' && k == komande.length()-1) { //Lijevo
							smjer = Smjerovi::Lijevo;
							komanda = Komande::PomjeriJednoMjesto;
							return true;
						}
					}
				}
				else if ((komande[j] == 'O' && j == komande.length() - 1) || (komande[j] == 'O' && komande[j+1] == ' ')) { //Prikazi okolinu
					komanda = Komande::PrikaziOkolinu;
					return true;
				}
				else if (komande[j] == '>') { //Idi
					for (int k=j+1; k<komande.length(); k++) {
						if (komande[k] == ' ') continue;
						else if (komande[k] != ' ' && !(komande[k] >= '0' && komande[k] <= '9')) {
							greska = KodoviGresaka::NeispravanParametar;
							return false;
						}
						else if (komande[k] >= '0' && komande[k] <= '9') { //Idi na to polje
							x = (int)komande[k] - 48;
							for (int c=k+1; c<komande.length(); c++) {
								if (komande[c] == ' ') continue;
								else if (komande[c] >= '0' && komande[c] <= '9') {
									y = (int)komande[c] - 48;
									komanda = Komande::PomjeriDalje;
									return true;
								}
							}
						}
					}
				}
			}
		}
		else if (komande[i] == 'D') { //Deblokiraj polje
			for (int j=i+1; j<komande.length(); j++) {
				if (komande[j] == ' ') continue;
				else if (komande[j] != ' ' && !(komande[j] >= '0' && komande[j] <= '9')) {
					greska = KodoviGresaka::PogresnaKomanda;
					return false;
				}
				else if (komande[j] >= '0' && komande[j] <= '9') {
					for (int k=j+1; k<komande.length(); k++) {
						if (komande[k] == ' ') continue;
						else if (komande[k] != ' ' && !(komande[k] >= '0' && komande[k] <= '9')) {
							greska = KodoviGresaka::PogresnaKomanda;
							komanda = Komande::Deblokiraj;
							return false;
						}
						else if (komande[k] >= '0' && komande[k] <= '9') {
							x = (int) komande[j] - 48;
							y = (int) komande[k] - 48;
							komanda = Komande::Deblokiraj;
							return true;
						}
					}
				}
			}
		}
		else if (komande[i] == 'B') { // Blokiraj polje
			for (int j=i+1; j<komande.length(); j++) {
				if (komande[j] == ' ') continue;
				else if (komande[j] != ' ' && !(komande[j] >= '0' && komande[j] <= '9')) {
					greska = KodoviGresaka::SuvisanParametar;
					return false;
				}
				else if (komande[j] >= '0' && komande[j] <= '9') {
					for (int k=j+1; k<komande.length(); k++) {
						if (komande[k] == ' ') continue;
						else if (komande[k] != ' ' && !(komande[k] >= '0' && komande[k] <= '9')) {
							greska = KodoviGresaka::SuvisanParametar;
							return false;
						}
						else if (komande[k] >= '0' && komande[k] <= '9') {
							x = (int) komande[j] - 48;
							y = (int) komande[k] - 48;
							komanda = Komande::Blokiraj;
							return true;
						}
					}
				}
			}
		}
		else if ((komande[i] == 'Z' && i==komande.length()-1) || (komande[i] == 'Z' && komande[i+1] == ' ')) { //Zavrsi IGRU
			komanda = Komande::ZavrsiIgru;
			return true;
		}
		else if ((komande[i] == 'K' && i==komande.length()-1) || (komande[i] == 'K' && komande[i+1] == ' ')) { //Kreiraj IGRU
			komanda = Komande::KreirajIgru;
			return true;
		} 
	}
	return true;
}
void IzvrsiKomandu (Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0) {
	std::vector<std::vector<int>> pomocna;
	if (komanda == Komande::PomjeriJednoMjesto) {
		Idi(polja, x, y, p_smjer);
	}
	else if (komanda == Komande::PomjeriDalje) 
		Idi (polja, p_x, p_y, x, y);
		
	else if (komanda == Komande::Blokiraj)
		BlokirajPolje(polja, x, y);
		
	else if (komanda == Komande::Deblokiraj)
		DeblokirajPolje(polja, x, y);
		
	/*else if (komanda == Komande::PrikaziOkolinu)
		PrikaziOkolinu (mat, x, y);*/
		
	else if (komanda == Komande::ZavrsiIgru) {
		for (int i=0; i<polja.size(); i++) {
			for (int j=0; j<polja[i].size(); j++)
				polja[i][j] = Polje::Prazno;
		}
		throw std::runtime_error ("Igra zavrsena");
	}
	else if (komanda == Komande::KreirajIgru) {
		std::cout << "Unesite broj polja: ";
		int polje;
		std::cin >> polje;
		std::cout << "Unesite pozicije mina: ";
		std::vector<std::vector<int>> mat;
		for (;;) {
			char znak1, znak2, znak3;
			int x, y, i=0;
			std::cin >> znak1;
			if (znak1 == '.') {
				std::cin.clear();
				std::cin.ignore(10000,'\n');
				break;
			}
			if (znak1 != '(') {
				std::cin.clear();
				std::cin.ignore(10000,'\n');
				std::cout << "Greska, unesite ponovo!" << std::endl;
			}
				else {
					mat.resize(i+1);
					mat[i].push_back(x);
					mat[i].push_back(y);
					i++;
					}
		}
	}
	else if (komanda == Komande::PrikaziOkolinu) {
		std::vector<std::vector<int>> okolina = PrikaziOkolinu(polja,1,1);
		for (int i=0; okolina.size(); i++) {
			for (int j=0; j<okolina[i].size(); j++)
			 	std::cout << okolina[i][j] << " ";
			 std::cout << std::endl;
		}
	}
}

int main ()
{
	/*std::vector<std::vector<int>> mat = {{0,0}, {0,2}, {1,3}};
	Tabla mat1 (2, std::vector<Polje> (2));
	try{
		BlokirajPolje(mat1, 10, 15);
	}
	catch (std::domain_error poruka) {
		std::cout << poruka.what() << std::endl;
	}
	auto povratna = KreirajIgru(4, mat);
	for (int i=0; i<povratna.size(); i++) {
		for (int j=0; j<povratna[i].size(); j++)
			std::cout << std::setw(4) << static_cast<int> (povratna[i][j]);
		std::cout << std::endl;
	}*/
Komande komanda;
	Smjerovi smjer= Smjerovi::Gore;
	int x,y;
	KodoviGresaka greska;
	Tabla polja;
	int p_x=0, p_y=0;
	for(;;) {
		try {
			std::cout << "Unesite komandu: ";
			if (UnosKomande(komanda,smjer,x,y,greska)) {
				if (komanda == Komande::ZavrsiIgru) {
					std::cout << "Dovidenja!";
					break;
				}
			IzvrsiKomandu(komanda,polja,x,y,smjer,p_x,p_y);
			}
		else PrijaviGresku(greska);
		}
		catch (...) {
			std::cout << "Greska";
		}
	}
	return 0;
}
/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
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

std::string IntUString(int broj) {
	std::string ret;
	char sbroj[12];
	int i(0), tmp(broj);
	if (broj<0) {
		broj=-broj;
		sbroj[i++]='-';
	}
	do {
		i++;
		tmp/=10;
	} while(tmp!=0);
	sbroj[i--]='\0';
	while (broj!=0) {
		sbroj[i--]=broj%10+'0';
		broj/=10;
	}
	ret=std::string(sbroj);
	return ret;
}

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine) {
	Tabla kreirana_tabla (n, std::vector<Polje> (n, Polje::Prazno));
	for (int i=0; i<mine.size(); i++)
		for (int j=0; j<mine[i].size(); j++) {
			if (mine[i].size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
			if (mine[i][j]<0 || mine[i][j]>=n) throw std::domain_error("Ilegalne pozicije mina");
		}
	for (int k=0; k<mine.size(); k++)
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				if (i==mine[k][0] && j==mine[k][1]) kreirana_tabla[i][j]=Polje::Mina;
	return kreirana_tabla;
}

bool IspravnostPolja(const Tabla &polja, int x, int y) {
	if (x<0 || y<0 || x>=polja.size() || y>=polja.size()) return false;
	return true;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y) {
	std::vector<std::vector<int>> matrica (3, std::vector<int> (3));
	if (!IspravnostPolja(polja,x,y)) throw std::domain_error("Polje ("+IntUString(x)+","+IntUString(y)+") ne postoji");
	int indeks2{};
	for (int j=y-1; j<=y+1; j++) {
		int indeks1{};
		for (int i=x-1; i<=x+1; i++) {
			int brojac_mina{};
			if (IspravnostPolja(polja,i,j)) {
				for (int k=i-1; k<=i+1; k++) {
					for (int l=j-1; l<=j+1; l++) {
						if (IspravnostPolja(polja,k,l) && (polja[k][l]==Polje::Mina || polja[k][l]==Polje::BlokiranoMina)) brojac_mina++;
					}
				}
				if (polja[i][j]==Polje::Mina || polja[i][j]==Polje::BlokiranoMina) brojac_mina--;
				matrica[indeks1][indeks2]=brojac_mina;
				indeks1++;
			}
			else indeks1++;
		}
		indeks2++;
	}
	return matrica;
}

void BlokirajPolje(Tabla &polja, int x, int y) {
	if (!IspravnostPolja(polja,x,y)) throw std::domain_error("Polje ("+IntUString(x)+","+IntUString(y)+") ne postoji");
	if (polja[x][y]==Polje::Prazno) polja[x][y]=Polje::BlokiranoPrazno;
	else if (polja[x][y]==Polje::Posjeceno) polja[x][y]=Polje::BlokiranoPosjeceno;
	else if (polja[x][y]==Polje::Mina) polja[x][y]=Polje::BlokiranoMina;
}

void DeblokirajPolje(Tabla &polja, int x, int y) {
	if (!IspravnostPolja(polja,x,y)) throw std::domain_error("Polje ("+IntUString(x)+","+IntUString(y)+") ne postoji");
	if (polja[x][y]==Polje::BlokiranoPrazno) polja[x][y]=Polje::Prazno;
	else if (polja[x][y]==Polje::BlokiranoPosjeceno) polja[x][y]=Polje::Posjeceno;
	else if (polja[x][y]==Polje::BlokiranoMina) polja[x][y]=Polje::Mina;
}

bool BlokiranostPolja(const Tabla &polja, int x, int y) {
	if (polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoPosjeceno || polja[x][y]==Polje::BlokiranoMina) return true;
	return false;
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer) {
	if (IspravnostPolja(polja,x,y)) polja[x][y]=Polje::Posjeceno; 
	if (smjer==Smjerovi::GoreLijevo) {
		x--;
		y--;
		if (!IspravnostPolja(polja,x,y)) {
			x++;
			y++;
			throw std::out_of_range("Izlazak van igrace table");
		}
		else if (BlokiranostPolja(polja,x,y)) {
			x++;
			y++;
			throw std::logic_error("Blokirano polje");
		}
	}
	else if (smjer==Smjerovi::Gore) {
		x--;
		if (!IspravnostPolja(polja,x,y)) {
			x++;
			throw std::out_of_range("Izlazak van igrace table");
		}
		else if (BlokiranostPolja(polja,x,y)) {
			x++;
			throw std::logic_error("Blokirano polje");
		}
	}
	else if (smjer==Smjerovi::GoreDesno) {
		x--;
		y++;
		if (!IspravnostPolja(polja,x,y)) {
			x++;
			y--;
			throw std::out_of_range("Izlazak van igrace table");
		}
		else if (BlokiranostPolja(polja,x,y)) {
			x++;
			y--;
			throw std::logic_error("Blokirano polje");
		}
	}
	else if (smjer==Smjerovi::Desno) {
		y++;
		if (!IspravnostPolja(polja,x,y)) {
			y--;
			throw std::out_of_range("Izlazak van igrace table");
		}
		else if (BlokiranostPolja(polja,x,y)) {
			y--;
			throw std::logic_error("Blokirano polje");
		}
	}
	else if (smjer==Smjerovi::DoljeDesno) {
		x++;
		y++;
		if (!IspravnostPolja(polja,x,y)) {
			x--;
			y--;
			throw std::out_of_range("Izlazak van igrace table");
		}
		else if (BlokiranostPolja(polja,x,y)) {
			x--;
			y--;
			throw std::logic_error("Blokirano polje");
		}
	}
	else if (smjer==Smjerovi::Dolje) {
		x++;
		if (!IspravnostPolja(polja,x,y)) {
			x--;
			throw std::out_of_range("Izlazak van igrace table");
		}
		else if (BlokiranostPolja(polja,x,y)) {
			x--;
			throw std::logic_error("Blokirano polje");
		}
	}
	else if (smjer==Smjerovi::DoljeLijevo) {
		x++;
		y--;
		if (!IspravnostPolja(polja,x,y)) {
			x--;
			y++;
			throw std::out_of_range("Izlazak van igrace table");
		}
		else if (BlokiranostPolja(polja,x,y)) {
			x--;
			y++;
			throw std::logic_error("Blokirano polje");
		}
	}
	else if (smjer==Smjerovi::Lijevo) {
		y--;
		if (!IspravnostPolja(polja,x,y)) {
			y++;
			throw std::out_of_range("Izlazak van igrace table");
		}
		else if (BlokiranostPolja(polja,x,y)) {
			y++;
			throw std::logic_error("Blokirano polje");
		}
	}
	
	if (polja[x][y]==Polje::Mina) {
		for (int i=0; i<polja.size(); i++)
			for (int j=0; j<polja[i].size(); j++)
				polja[i][j]=Polje::Prazno;
		return Status::KrajPoraz;
	}
	int brojac_praznih_polja{};
	for (int i=0; i<polja.size(); i++)
		for (int j=0; j<polja[i].size(); j++)
			if (polja[i][j]==Polje::Prazno || polja[i][j]==Polje::BlokiranoPrazno) brojac_praznih_polja++;
	if (brojac_praznih_polja-1==0) return Status::KrajPobjeda;
	return Status::NijeKraj;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y) {
	if (IspravnostPolja(polja,x,y)) polja[x][y]=Polje::Posjeceno;
	int upamti_x=x, upamti_y=y;
	x=novi_x;
	y=novi_y;
	if (!IspravnostPolja(polja,x,y)) {
		x=upamti_x;
		y=upamti_y;
		throw std::out_of_range("Izlazak van igrace table");
	}
	else if (BlokiranostPolja(polja,x,y)) {
		x=upamti_x;
		y=upamti_y;
		throw std::logic_error("Blokirano polje");
	}
	if (polja[x][y]==Polje::Mina) {
		for (int i=0; i<polja.size(); i++)
			for (int j=0; j<polja[i].size(); j++)
				polja[i][j]=Polje::Prazno;
		return Status::KrajPoraz;
	}
	int brojac_praznih_polja{};
	for (int i=0; i<polja.size(); i++)
		for (int j=0; j<polja[i].size(); j++)
			if (polja[i][j]==Polje::Prazno || polja[i][j]==Polje::BlokiranoPrazno) brojac_praznih_polja++;
	if (brojac_praznih_polja-1==0) return Status::KrajPobjeda;
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

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska) {
	char unos{};
	std::cin >> unos;
	if (unos=='P') {
		if (std::cin.peek()=='\n') {
			greska=KodoviGresaka::PogresnaKomanda;
			return false;
		}
		else {
			std::cin >> unos;
			if (unos=='1') {
				if (std::cin.peek()=='\n') {
					greska=KodoviGresaka::NedostajeParametar;
					return false;
				}
				else { 
					std::cin >> unos;
					if (unos=='G') {
						if (std::cin.peek()=='\n') {
							smjer=Smjerovi::Gore;
							komanda=Komande::PomjeriJednoMjesto;
							return true;
						}
						else {
							std::cin >> unos;
							if (unos=='L') {
								if (std::cin.peek()!='\n') {
									std::cin.ignore(10000,'\n');
									greska=KodoviGresaka::SuvisanParametar;
									return false;
								}
								smjer=Smjerovi::GoreLijevo;
								komanda=Komande::PomjeriJednoMjesto;
								return true;
							}
							else if (unos=='D') {
								if (std::cin.peek()!='\n') {
									std::cin.ignore(10000,'\n');
									greska=KodoviGresaka::SuvisanParametar;
									return false;
								}
								smjer=Smjerovi::GoreDesno;
								komanda=Komande::PomjeriJednoMjesto;
								return true;
							}
							else {
								std::cin.ignore(10000,'\n');
								greska=KodoviGresaka::NeispravanParametar;
								return false;
							}
						}
					}
					else if (unos=='D') {
						if (std::cin.peek()=='\n') {
							smjer=Smjerovi::Desno;
							komanda=Komande::PomjeriJednoMjesto;
							return true;
						}
						else {
							std::cin >> unos;
							if (unos=='o') {
								if (std::cin.peek()=='\n') {
									smjer=Smjerovi::Dolje;
									komanda=Komande::PomjeriJednoMjesto;
									return true;
								}
								else {
									std::cin >> unos;
									if (unos=='L') {
										if (std::cin.peek()!='\n') {
											std::cin.ignore(10000,'\n');
											greska=KodoviGresaka::SuvisanParametar;
											return false;
										}
										smjer=Smjerovi::DoljeLijevo;
										komanda=Komande::PomjeriJednoMjesto;
										return true;
									}
									else if (unos=='D') {
										if (std::cin.peek()!='\n') {
											std::cin.ignore(10000,'\n');
											greska=KodoviGresaka::SuvisanParametar;
											return false;
										}
										smjer=Smjerovi::DoljeDesno;
										komanda=Komande::PomjeriJednoMjesto;
										return true;
									}
									else {
										std::cin.ignore(10000,'\n');
										greska=KodoviGresaka::NeispravanParametar;
										return false;
									}
								}
							}
							else {
								std::cin.ignore(10000,'\n');
								greska=KodoviGresaka::NeispravanParametar;
								return false;
							}
						}
					}
					else if (unos=='L') {
						if (std::cin.peek()=='\n') {
							smjer=Smjerovi::Lijevo;
							komanda=Komande::PomjeriJednoMjesto;
							return true;
						}
						else {
							std::cin.ignore(10000,'\n');
							greska=KodoviGresaka::SuvisanParametar;
							return false;
						}
					}
					else {
						std::cin.ignore(10000,'\n');
						greska=KodoviGresaka::NeispravanParametar;
						return false;
					}
				}
			}
			else if (unos=='>') {
				if (std::cin.peek()=='\n') {
					greska=KodoviGresaka::NedostajeParametar;
					return false;
				}
				else {
					std::cin >> x;
					if (!std::cin) {
						std::cin.clear();
						std::cin.ignore(10000,'\n');
						greska=KodoviGresaka::NeispravanParametar;
						return false;
					}
					else {
						if (std::cin.peek()=='\n') {
							greska=KodoviGresaka::NedostajeParametar;
							return false;
						}
						else {
							std::cin >> y;
							if (!std::cin) {
								std::cin.clear();
								std::cin.ignore(10000,'\n');
								greska=KodoviGresaka::NeispravanParametar;
								return false;
							}
							else if (std::cin.peek()!='\n') {
								std::cin.ignore(10000,'\n');
								greska=KodoviGresaka::SuvisanParametar;
								return false;
							}
						}
					}
				}
				komanda=Komande::PomjeriDalje;
				return true;
			}
			else if (unos=='O') {
				if (std::cin.peek()=='\n') {
					komanda=Komande::PrikaziOkolinu;
					return true;
				}
				else {
					std::cin.ignore(10000,'\n');
					greska=KodoviGresaka::SuvisanParametar;
					return false;
				}
			}
			else {
				std::cin.ignore(10000,'\n');
				greska=KodoviGresaka::PogresnaKomanda;
				return false;
			}
		}
	}
	else if (unos=='B') {
		if (std::cin.peek()=='\n') {
			greska=KodoviGresaka::NedostajeParametar;
			return false;
		}
		else {
			std::cin >> x;
			if (!std::cin) {
				std::cin.clear();
				std::cin.ignore(10000,'\n');
				greska=KodoviGresaka::NeispravanParametar;
				return false;
			}
			else {
				if (std::cin.peek()=='\n') {
					greska=KodoviGresaka::NedostajeParametar;
					return false;
				}
				else {
					std::cin >> y;
					if (!std::cin) {
						std::cin.clear();
						std::cin.ignore(10000,'\n');
						greska=KodoviGresaka::NeispravanParametar;
						return false;
					}
					else if (std::cin.peek()!='\n') {
						std::cin.ignore(10000,'\n');
						greska=KodoviGresaka::SuvisanParametar;
						return false;
					}
				}
			}
		}
		komanda=Komande::Blokiraj;
		return true;
	}
	else if (unos=='D') {
		if (std::cin.peek()=='\n') {
			greska=KodoviGresaka::NedostajeParametar;
			return false;
		}
		else {
			std::cin >> x;
			if (!std::cin) {
				std::cin.clear();
				std::cin.ignore(10000,'\n');
				greska=KodoviGresaka::NeispravanParametar;
				return false;
			}
			else {
				if (std::cin.peek()=='\n') {
					greska=KodoviGresaka::NedostajeParametar;
					return false;
				}
				else {
					std::cin >> y;
					if (!std::cin) {
						std::cin.clear();
						std::cin.ignore(10000,'\n');
						greska=KodoviGresaka::NeispravanParametar;
						return false;
					}
					else if (std::cin.peek()!='\n') {
						std::cin.ignore(10000,'\n');
						greska=KodoviGresaka::SuvisanParametar;
						return false;
					}
				}
			}
		}
		komanda=Komande::Deblokiraj;
		return true;
	}
	else if (unos=='Z') {
		if (std::cin.peek()=='\n') {
			komanda=Komande::ZavrsiIgru;
			return true;
		}
		else {
			std::cin.ignore(10000,'\n');
			greska=KodoviGresaka::SuvisanParametar;
			return false;
		}
	}
	else if (unos=='K') {
		if (std::cin.peek()=='\n') {
			komanda=Komande::KreirajIgru;
			return true;
		}
		else {
			std::cin.ignore(10000,'\n');
			greska=KodoviGresaka::SuvisanParametar;
			return false;
		}
	}
	else {
		std::cin.ignore(10000,'\n');
		greska=KodoviGresaka::PogresnaKomanda;
		return false;
	}
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer=Smjerovi::Gore, int p_x=0, int p_y=0) {
	switch(komanda) {
		case (Komande::PomjeriJednoMjesto):{
			try {
				auto s=Idi(polja,x,y,p_smjer);
				std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")" << std::endl;
				if (s==Status::KrajPobjeda) {
					std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
					for (int i=0; i<polja.size(); i++)
						for (int j=0; j<polja[i].size(); j++)
							polja[i][j]=Polje::Prazno;
					throw std::runtime_error("Igra zavrsena");
				}
				else if (s==Status::KrajPoraz) {
					std::cout << "Nagazili ste na minu" << std::endl;
					for (int i=0; i<polja.size(); i++)
						for (int j=0; j<polja[i].size(); j++)
							polja[i][j]=Polje::Prazno;
					throw std::runtime_error("Igra zavrsena");
				}
			}
			catch(std::runtime_error izuzetak) {
				throw;
			}
			catch(std::out_of_range izuzetak) {
				std::cout << izuzetak.what() << std::endl;
			}
			catch(std::logic_error izuzetak) {
				std::cout << izuzetak.what() << std::endl;
			}
			break;}
		case (Komande::PomjeriDalje):{
			try {
				auto s=Idi(polja,x,y,p_x,p_y);
				std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")" << std::endl;
				if (s==Status::KrajPobjeda) {
					std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
					for (int i=0; i<polja.size(); i++)
						for (int j=0; j<polja[i].size(); j++)
							polja[i][j]=Polje::Prazno;
					throw std::runtime_error("Igra zavrsena");
				}
				else if (s==Status::KrajPoraz) {
					std::cout << "Nagazili ste na minu" << std::endl;
					for (int i=0; i<polja.size(); i++)
						for (int j=0; j<polja[i].size(); j++)
							polja[i][j]=Polje::Prazno;
					throw std::runtime_error("Igra zavrsena");
				}
			}
			catch(std::runtime_error izuzetak) {
				throw;
			}
			catch(std::out_of_range izuzetak) {
				std::cout << izuzetak.what() << std::endl;
			}
			catch(std::logic_error izuzetak) {
				std::cout << izuzetak.what() << std::endl;
			}
			break;}
		case (Komande::Blokiraj):{
			try {
				BlokirajPolje(polja,p_x,p_y);	
			}
			catch(std::domain_error izuzetak) {
				std::cout << izuzetak.what() << std::endl;
			}
			break;}
		case (Komande::Deblokiraj):{
			try {
				DeblokirajPolje(polja,p_x,p_y);
			}
			catch(std::domain_error izuzetak) {
				std::cout << izuzetak.what() << std::endl;
			}
			break;}
		case (Komande::PrikaziOkolinu):{
			try {
				auto rezultat=PrikaziOkolinu(polja,x,y);
				for (int i=0; i<rezultat.size(); i++) {
					for (int j=0; j<rezultat[i].size(); j++)
						std::cout << rezultat[i][j] << " ";
					std::cout << std::endl;
				}
			}
			catch(std::domain_error izuzetak) {
				std::cout << izuzetak.what() << std::endl;
			}
			break;}
		case (Komande::ZavrsiIgru):{
			for (int i=0; i<polja.size(); i++)
				for (int j=0; j<polja[i].size(); j++)
					polja[i][j]=Polje::Prazno;
			throw std::runtime_error("Igra zavrsena");
			break;}
		case (Komande::KreirajIgru):{
			int broj_polja{};
			do {
				std::cout << "Unesite broj polja: ";
				std::cin >> broj_polja;
				if (broj_polja<0) std::cout << "Greska, unesite ponovo!" << std::endl;
			} while (broj_polja<0);
			std::cout << "Unesite pozicije mina: ";
			std::vector<std::vector<int>> mine;
			char unos;
			do {
				int broj1, broj2;
				std::vector<int> pomocni;
				std::cin >> unos;
				if (unos=='.' && std::cin.peek()=='\n') break;
				else if (unos=='(') {
					if (std::cin.peek()=='\n') {
						std::cout << "Greska, unesite ponovo!" << std::endl;
						std::cin.ignore(10000,'\n');
					}
					else {
						std::cin >> broj1;
						if (!std::cin) {
							std::cout << "Greska, unesite ponovo!" << std::endl;
							std::cin.clear();
							std::cin.ignore(10000,'\n');
						}
						else {
							if (std::cin.peek()=='\n') {
								std::cout << "Greska, unesite ponovo!" << std::endl;
								std::cin.ignore(10000,'\n');
							}
							else {
								std::cin >> unos;
								if (unos==',') {
									if (std::cin.peek()=='\n') {
										std::cout << "Greska, unesite ponovo!" << std::endl;
										std::cin.ignore(10000,'\n');
									}
									else {
										std::cin >> broj2;
										if (!std::cin) {
											std::cout << "Greska, unesite ponovo!" << std::endl;
											std::cin.clear();
											std::cin.ignore(10000,'\n');
										}
										else {
											if (std::cin.peek()=='\n') {
												std::cout << "Greska, unesite ponovo!" << std::endl;
												std::cin.ignore(10000,'\n');
											}
											else {
												std::cin >> unos;
												if (unos==')') {
													if (std::cin.peek()=='\n') {
														if(broj1>=0 && broj2>=0 && broj1<broj_polja && broj2<broj_polja)
														{pomocni.push_back(broj1);
														pomocni.push_back(broj2);
														mine.push_back(pomocni);}
														else{
															std::cout << "Greska, unesite ponovo!" << std::endl;
															std::cin.ignore(10000,'\n');
														}
													}
													else {
														std::cout << "Greska, unesite ponovo!" << std::endl;
														std::cin.ignore(10000,'\n');
													}
												}
												else {
													std::cout << "Greska, unesite ponovo!" << std::endl;
													std::cin.ignore(10000,'\n');
												}
											}
										}
									}
								}
								else {
									std::cout << "Greska, unesite ponovo!" << std::endl;
									std::cin.ignore(10000,'\n');
								}
							}
						}
					}
				}
				else {
					std::cout << "Greska, unesite ponovo!" << std::endl;
					std::cin.ignore(10000,'\n');
				}
			} while(unos!='.');
			try {
				polja=KreirajIgru(broj_polja,mine);
			}
			catch(std::domain_error izuzetak) {
				std::cout << izuzetak.what() << std::endl;
			}
			catch(std::logic_error izuzetak) {
				std::cout << izuzetak.what() << std::endl;
			}
			break;}
	}
}

int main () {
	Tabla polja;
	Komande komanda;
	KodoviGresaka greska;
	Smjerovi smjer;
	int x=0,y=0,p_x,p_y;
	try {
		do {
			std::cout << "Unesite komandu: ";
			bool rezultat=UnosKomande(komanda,smjer,p_x,p_y,greska);
			if (rezultat) IzvrsiKomandu(komanda,polja,x,y,smjer,p_x,p_y);
			else PrijaviGresku(greska);
		} while(1);
	}
	catch(std::runtime_error izuzetak) {
		std::cout << "Dovidjenja!" << std::endl;
	}
	return 0;
}
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdexcept>
#include <string>

enum class Polje { Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina };
enum class Smjerovi { GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo };
enum class Status { NijeKraj, KrajPoraz, KrajPobjeda };
enum class KodoviGresaka { PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar };
enum class Komande { PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru };


typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine) {
	Tabla matrica(n, std::vector<Polje>(n, Polje::Prazno));
	
	for(int i=0; i<mine.size(); i++) {
		if(mine.at(i).size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
		if(mine.at(i).at(0)>=n || mine.at(i).at(0)<0 || mine.at(i).at(1)>=n || mine.at(i).at(1)<0) throw std::domain_error("Ilegalne pozicije mina");
		matrica.at(mine.at(i).at(0)).at(mine.at(i).at(1))=Polje::Mina;
	}
	return matrica;
}

int Okolina(const Tabla &polja, int x0, int y0) {
	int brojac=0;
	for(int i=x0-1; i<=x0+1; i++) {
		for(int j=y0-1; j<=y0+1; j++) {
			if(i<0 || j<0 || i>=polja.size() || j>=polja.size()) continue;
			if(i==x0 && j==y0) continue;
			if(polja.at(i).at(j)==Polje::Mina) brojac++;
		}
	}
	return brojac;
}

std::vector<std::vector<int>>PrikaziOkolinu(const Tabla &polja, int x0, int y0) {
	std::vector<std::vector<int>>matrica(3, std::vector<int>(3,0));
	if(x0<0 || x0>=polja.size() || y0<0 || y0>=polja.size()) throw std::domain_error("Polje ("+std::to_string(x0)+","+std::to_string(y0)+") ne postoji");
	int temp=y0;
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			matrica.at(i).at(j)=Okolina(polja, x0-1, y0-1);
			y0++;
		}
		y0=temp;
		x0++;
	}
	return matrica;
}

void BlokirajPolje(Tabla &polja, int x0, int y0) {
	if(x0<0 || x0>=polja.size() || y0<0 || y0>=polja.size()) throw std::domain_error("Polje ("+std::to_string(x0)+","+std::to_string(y0)+") ne postoji");
	if(polja.at(x0).at(y0)==Polje::Mina) polja.at(x0).at(y0)=Polje::BlokiranoMina;
	if(polja.at(x0).at(y0)==Polje::Prazno) polja.at(x0).at(y0)=Polje::BlokiranoPrazno;
	if(polja.at(x0).at(y0)==Polje::Posjeceno) polja.at(x0).at(y0)=Polje::BlokiranoPosjeceno;
}

void DeblokirajPolje(Tabla &polja, int x0, int y0) {
	if(x0<0 || x0>=polja.size() || y0<0 || y0>=polja.size()) throw std::domain_error("Polje ("+std::to_string(x0)+","+std::to_string(y0)+") ne postoji");
	if(polja.at(x0).at(y0)==Polje::BlokiranoMina) polja.at(x0).at(y0)=Polje::Mina;
	if(polja.at(x0).at(y0)==Polje::BlokiranoPrazno) polja.at(x0).at(y0)=Polje::Prazno;
	if(polja.at(x0).at(y0)==Polje::BlokiranoPosjeceno) polja.at(x0).at(y0)=Polje::Posjeceno;
}

Status Idi(Tabla &polja, int &x0, int &y0, Smjerovi smjer) {
	polja.at(x0).at(y0)=Polje::Posjeceno;
	
	if(smjer==Smjerovi::Gore) {
		if(x0-1<0) throw std::out_of_range("Izlazak van igrace table");
		if(polja.at(x0-1).at(y0)==Polje::BlokiranoPosjeceno || polja.at(x0-1).at(y0)==Polje::BlokiranoPrazno || polja.at(x0-1).at(y0)==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		x0--;
	} else {
		if(smjer==Smjerovi::Dolje) {
			if(x0+1>=polja.size()) throw std::out_of_range("Izlazak van igrace table");
			if(polja.at(x0+1).at(y0)==Polje::BlokiranoPosjeceno || polja.at(x0+1).at(y0)==Polje::BlokiranoPrazno || polja.at(x0+1).at(y0)==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
			x0++;
		} else {
			if(smjer==Smjerovi::Lijevo) {
				if(y0-1<0) throw std::out_of_range("Izlazak van igrace table");
				if(polja.at(x0).at(y0-1)==Polje::BlokiranoPosjeceno || polja.at(x0).at(y0-1)==Polje::BlokiranoPrazno || polja.at(x0).at(y0-1)==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
				y0--;
			} else {
				if(smjer==Smjerovi::Desno) {
					if(y0+1>=polja.size()) throw std::out_of_range("Izlazak van igrace table");
					if(polja.at(x0).at(y0+1)==Polje::BlokiranoPosjeceno || polja.at(x0).at(y0+1)==Polje::BlokiranoPrazno || polja.at(x0).at(y0+1)==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
					y0++;
				} else {
					if(smjer==Smjerovi::GoreDesno) {
						if(x0-1<0 || y0+1>=polja.size()) throw std::out_of_range("izlazak van igrace table");
						if(polja.at(x0-1).at(y0+1)==Polje::BlokiranoPosjeceno || polja.at(x0-1).at(y0+1)==Polje::BlokiranoPrazno || polja.at(x0-1).at(y0+1)==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
						x0--;
						y0++;
					} else {
						if(smjer==Smjerovi::GoreLijevo) {
							if(x0-1<0 || y0+1<0) throw std::out_of_range("izlazak van igrace table");
							if(polja.at(x0-1).at(y0-1)==Polje::BlokiranoPosjeceno || polja.at(x0-1).at(y0-1)==Polje::BlokiranoPrazno || polja.at(x0-1).at(y0-1)==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
							x0--;
							y0--;
						} else {
							if(smjer==Smjerovi::DoljeDesno) {
								if(x0+1>polja.size() || y0+1>=polja.size()) throw std::out_of_range("izlazak van igrace table");
								if(polja.at(x0+1).at(y0+1)==Polje::BlokiranoPosjeceno || polja.at(x0+1).at(y0+1)==Polje::BlokiranoPrazno || polja.at(x0+1).at(y0+1)==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
								x0++;
								y0++;
							} else {
								if(smjer==Smjerovi::DoljeLijevo) {
									if(x0+1>polja.size() || y0-1<0) throw std::out_of_range("izlazak van igrace table");
									if((polja.at(x0+1).at(y0-1)==Polje::BlokiranoPosjeceno) || (polja.at(x0+1).at(y0-1)==Polje::BlokiranoPrazno) || (polja.at(x0+1).at(y0-1)==Polje::BlokiranoMina)) throw std::logic_error("Blokirano polje");
									x0++;
									y0--;
								}
							}
						}
					}
				}
			}
		}
	}
	return Status::KrajPobjeda; 
}

Status Idi(Tabla &polja, int &x0, int &y0, int x, int y) {
	polja.at(x0).at(y0)=Polje::Posjeceno;
	
	if(x<0 || y<0 || x>=polja.size() || y>=polja.size()) throw std::out_of_range("Izlazak van igrace table");
	if((polja.at(x).at(y)==Polje::BlokiranoPosjeceno) || (polja.at(x).at(y)==Polje::BlokiranoMina) || (polja.at(x).at(y)==Polje::BlokiranoPrazno)) throw std::logic_error("Blokirano polje");
	
	x0=x;
	y0=y;
	
	if(polja.at(x0).at(y0)==Polje::Mina) {
		std::vector<std::vector<int>>mat;
		polja=KreirajIgru(polja.size(), mat);
		return Status::KrajPoraz;
	}
	
	for(int i=0; i<polja.size(); i++) {
		for(int j=0; j<polja.size(); j++) {
			if(polja.at(x0).at(y0)==Polje::Prazno || polja.at(x0).at(y0)==Polje::BlokiranoPrazno) return Status::NijeKraj;
		}
	}
	return Status::KrajPobjeda;
}

void PrijaviGresku(KodoviGresaka a) {
	if(a==KodoviGresaka::PogresnaKomanda) std::cout << "Nerazumljiva komanda!" << std::endl;
	if(a==KodoviGresaka::NedostajeParametar) std::cout << "Komanda trazi parametar koji nije naveden!" << std::endl;
	if(a==KodoviGresaka::SuvisanParametar) std::cout << "Parametar komande nije ispravan!" << std::endl;
	if(a==KodoviGresaka::NeispravanParametar) std::cout << "Zadan je suvisan parametar nakon komande!" << std::endl;
}

int DajBroj(std::string s, int i, bool &test) {
	int temp=i;
	int suma=0;
	int k=1;
	while(s.at(i)<='9' && s.at(i)>='0') i++;
	
	if((s.at(i)>'9' || s.at(i)<'0') && s.at(i)!=' ' && s.at(i)!='\0') test=false;
	i--;
	while(i>=temp) {
		suma+=k*(s.at(i)-'0');
		k*=10;
		i--;
	}
	test=true;
	return suma;
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x0, int &y0, KodoviGresaka &greska) {
	std::string s;
	if(s.length()==0) {
		greska=KodoviGresaka::PogresnaKomanda;
		return false;
	}
	
	int i=0;
	while(s.at(i)==' ') i++;
	if(s.at(i)=='P' && s.at(i+1)=='1') { //pocetak 
		i++;
		i++;
		while(s.at(i)==' ') i++;
		
		switch(s.at(i)) {
			case 'G':	//Gore
				i++;
				switch(s.at(i)) {
					case 'D':
						i++;
						while(s.at(i)!='\0') {
							if(s.at(i)!=' ' && s.at(i)!='\n' && s.at(i)!='\0') {
								greska=KodoviGresaka::SuvisanParametar;
								return false;
							}
						}
						smjer=Smjerovi::GoreDesno;
						komanda=Komande::PomjeriJednoMjesto;
						return true;
					
					case 'L':	//Gore_Lijevo 
						while(s.at(i)!='\0') {
							if(s.at(i)!=' ' && s.at(i)!='\n' && s.at(i)!='\0') {
								greska=KodoviGresaka::SuvisanParametar;
								return false;
							}
							i++;
						}
						smjer=Smjerovi::GoreLijevo;
						komanda=Komande::PomjeriJednoMjesto;
						return true;
						
					case ' ':	//Greska
						i++;
						while(s.at(i)!='\0') {
							if(s.at(i)!=' ' && s.at(i)!='\n' && s.at(i)!='\0') {
								greska=KodoviGresaka::SuvisanParametar;
								return false;
							}
							i++;
						}
						smjer=Smjerovi::Gore;
						komanda=Komande::PomjeriJednoMjesto;
						return true;
						
					case '\0':	//Gore-kraj
						smjer=Smjerovi::Gore;
						komanda=Komande::PomjeriJednoMjesto;
						return true;
						
					default:
						greska=KodoviGresaka::SuvisanParametar;
						return false;
				}
				
			case 'L':	//Lijevo
				i++;
				switch(s.at(i)) {
					case ' ':
						while(s.at(i)!='\0') {
							if(s.at(i)!=' ' && s.at(i)!='\n' && s.at(i)!='\0') {
								greska=KodoviGresaka::SuvisanParametar;
								return false;
							}
							i++;
						}
						smjer=Smjerovi::Lijevo;
						komanda=Komande::PomjeriJednoMjesto;
						return true;
				
					case '\0':
						smjer=Smjerovi::Lijevo;
						komanda=Komande::PomjeriJednoMjesto;
						return true;
						
					default:
						greska=KodoviGresaka::SuvisanParametar;
						return false;
				}
			
			case 'D':	//Desno
				i++;
				switch(s.at(i)) {
					case '\0':	//Desno-kraj
						smjer=Smjerovi::Desno;
						komanda=Komande::PomjeriJednoMjesto;
						return true;
					
					case ' ':	//Greska
						while(s.at(i)!='\0') {
							if(s.at(i)!=' ' && s.at(i)!='\n' && s.at(i)!='\0') {
								greska=KodoviGresaka::SuvisanParametar;
								return false;
							}
							i++;
						}
						smjer=Smjerovi::Desno;
						komanda=Komande::PomjeriJednoMjesto;
						return true;
				
					case 'o':	//Veznik za komandu desno pa gdje onda...
						i++;
						switch(s.at(i)) {
							case '\0':		//Dolje-kraj
								smjer=Smjerovi::Dolje;
								komanda=Komande::PomjeriJednoMjesto;
								return true;
								
							case ' ':	//Greska
								while(s.at(i)!='\0') {
									if(s.at(i)!=' ' && s.at(i)!='\n' && s.at(i)!='\0') {
										greska=KodoviGresaka::SuvisanParametar;
										return false;
									}
									i++;
								}
								smjer=Smjerovi::Dolje;
								komanda=Komande::PomjeriJednoMjesto;
								return true;
								
							case 'D':	//Dolje-Desno
								i++;
								switch(s.at(i)) {
									case ' ':
										while(s.at(i)!='\0') {
											if(s.at(i)!=' ' && s.at(i)!='\n' && s.at(i)!='\0') {
												greska=KodoviGresaka::SuvisanParametar;
												return false;
											}
											i++;
										}
										smjer=Smjerovi::DoljeDesno;
										komanda=Komande::PomjeriJednoMjesto;
										return true;
										
									case '\0':	//Dolje-Desno-kraj
										smjer=Smjerovi::DoljeDesno;
										komanda=Komande::PomjeriJednoMjesto;
										return true;
										
									default:	//greska
										greska=KodoviGresaka::SuvisanParametar;
										return false;
								}
								
							case 'L':	//Dolje-Lijevo
								i++;
								switch(s.at(i)) {
									case ' ':	//Greska
										while(s.at(i)!='\0') {
											if(s.at(i)!=' ' && s.at(i)!='\n' && s.at(i)!='\0') {
												greska=KodoviGresaka::SuvisanParametar;
												return false;
											}
											i++;
										}
										smjer=Smjerovi::DoljeLijevo;
										komanda=Komande::PomjeriJednoMjesto;
										return true;
									
									case '\0':	//Dolje-Lijevo-Kraj
										smjer=Smjerovi::DoljeLijevo;
										komanda=Komande::PomjeriJednoMjesto;
										return true;
										
									default:
										greska=KodoviGresaka::SuvisanParametar;
										return false;
								}
							
							default:	//Greska
							 greska=KodoviGresaka::SuvisanParametar;
							 return false;
						}
					default:	//Greska
						greska=KodoviGresaka::SuvisanParametar;
						return false;
				}
		}
	} else {
		if(s.at(i)=='K') {	//Kreiraj igru
			i++;
			while(s.at(i)!='\0') {	//Greska
				if(s.at(i)!=' ' && s.at(i)!='\n' && s.at(i)!='\0') {
					greska=KodoviGresaka::SuvisanParametar;
					return false;
				}
				i++;
			}
			komanda=Komande::KreirajIgru;
			return true;
		} else {
			if(s.at(i)=='Z') {	//Zavrsi igru
				while(s.at(i)!='\0') {	//Greska
					if(s.at(i)!=' ' && s.at(i)!='\n' && s.at(i)!='\0') {
						greska=KodoviGresaka::SuvisanParametar;
						return false;
					}
					i++;
				}
				komanda=Komande::ZavrsiIgru;
				return true;
			} else {
				if(s.at(i)=='P' && s.at(i+1)=='>') {	//Pomak na zadano mjesto
					i++;
					i++;
					bool test1, test2;
					int x1, y1;
					while(s.at(i)==' ') i++;
					x1=DajBroj(s, i, test1);
					while(s.at(i)==' ') i++;
					if(s.at(i)=='\0') greska=KodoviGresaka::NedostajeParametar	 //Greska
					if((s.at(i)>'9' ||  s.at(i)<'0') && s.at(i)!=' ') {		//Greska
						greska=KodoviGresaka::NeispravanParametar;
						return false;
					}
					y1=DajBroj(s, i, test2);
					while(s.at(i)!='\0') {	//Greska
						if(s.at(i)!=' ') {
							greska=KodoviGresaka::SuvisanParametar;
							return false;
						}
					}
					if(test1 && test2) {
						x0=x1;
						y0=y1;
						komanda=Komande::PomjeriDalje;
						return true;
					} else {
						greska=KodoviGresaka::NeispravanParametar;
						return false;
					}
				} else {
					if(s.at(i)=='B') {	//Blokiraj polje
						i++;
						bool test1, test2;
						int x1, y1;
						while(s.at(i)==' ') i++;
						x1=DajBroj(s, i, test1);
						while(s.at(i)==' ') i++;
						if(s.at(i)=='\0') greska=KodoviGresaka::NedostajeParametar;		//Greska
						if((s.at(i)>'9' ||  s.at(i)<'0') && s.at(i)!=' ') {
							greska=KodoviGresaka::NeispravanParametar;
							return false;
						}
						y1=DajBroj(s, i, test2);
						while(s.at(i)!='\0') {		//Greska
							if(s.at(i)!=' ') {
								greska=KodoviGresaka::SuvisanParametar;
								return false;
							}
						}
						if(test1 && test2) {
							x0=x1;
							y0=y1;
							komanda=Komande::Blokiraj;
							return true;
						} else {
							greska=KodoviGresaka::NeispravanParametar;
							return false;
						}
					} else {
						if(s.at(i)=='D') {		//Deblokiraj polje
							i++;
							bool test1, test2;
							int x1, y1;
							while(s.at(i)==' ') i++;
							x1=DajBroj(s, i, test1);
							while(s.at(i)==' ') i++;
							if(s.at(i)=='\0') greska=KodoviGresaka::NedostajeParametar;		//Greska
							if((s.at(i)>'9' ||  s.at(i)<'0') && s.at(i)!=' ') {
								greska=KodoviGresaka::NeispravanParametar;
								return false;
							}
							y1=DajBroj(s, i, test2);
							while(s.at(i)!='\0') {		//Greska
								if(s.at(i)!=' ') {
									greska=KodoviGresaka::SuvisanParametar;
									return false;
								}
							}
							if(test1 && test2) {
								x0=x1;
								y0=y1;
								komanda=Komande::Deblokiraj;
								return true;
							} else {
								greska=KodoviGresaka::NeispravanParametar;
								return false;
							}
						} else {
							if(s.at(i)=='P' && s.at(i+1)=='O') {
								i++;
								i++;
								while(s.at(i)!='\0') {		//Greska
									if(s.at(i)!=' ') {
										greska=KodoviGresaka::PogresnaKomanda;
										return false;
									}
								}
								komanda=Komande::PrikaziOkolinu;
								return true;
							} else {
								greska=KodoviGresaka::PogresnaKomanda;		//Greska
								return false;
							}
						}
					}
				}
			}
		}
	}
	return false;
}
		
void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x0, int &y0, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0) {
	
	switch(komanda) {
		case (Komande::PomjeriJednoMjesto): {
			Status H=Idi(polja, x0, y0, p_smjer);
			std::cout << "Tekuca pozicija igraca je (" << x0 << ", " << y0 << ")" << std::endl;
			if(H==Status::NijeKraj) break;
			if(H==Status::KrajPobjeda) {
				std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
				std::vector<std::vector<int>>v;
				KreirajIgru(polja.size(), v);
				throw std::runtime_error("Igra zavrsena");
			}
			if(H==Status::KrajPoraz) {
				std::cout << "Nagazili ste na minu" << std::endl;
				std::vector<std::vector<int>>v;
				KreirajIgru(polja.size(), v);
			}
			break;
		}
		
		case (Komande::PomjeriDalje): {
			Status H1=Idi(polja, x0, y0, p_x, p_y);
			std::cout << "Tekuca pozicija igraca je (" << x0 << ", " << y0 << ")" << std::endl;
			if(H1==Status::NijeKraj) break;
			if(H1==Status::KrajPobjeda) {
				std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
				std::vector<std::vector<int>>v;
				KreirajIgru(polja.size(), v);
				throw std::runtime_error("Igra zavrsena");
			}
			if(H1==Status::KrajPoraz) {
				std::cout << "Nagazili ste na minu" << std::endl;
				std::vector<std::vector<int>>v;
				KreirajIgru(polja.size(), v);
			}
			break;
		}
		
		case (Komande::Blokiraj): {
			try {
				BlokirajPolje(polja, p_x, p_y);
			}catch(std::domain_error tri) {
				std::cout << tri.what() << std::endl;
			}
		}
		
			
		case (Komande::Deblokiraj): {
			try{
				DeblokirajPolje(polja, p_x, p_y);
			}catch(std::domain_error jedan) {
				std::cout << jedan.what() << std::endl;
			}
			break;
		}
		
		case (Komande::PrikaziOkolinu): {
			try {
				std::vector<std::vector<int>>okolina=PrikaziOkolinu(polja, x0, y0);
				for(int i=0; i<okolina.size(); i++) {
					for(int j=0; j<okolina.at(i).size(); j++) {
						std::cout << okolina.at(i).at(j) << " ";
					}
					std::cout << std::endl;
				}
			}catch(std::domain_error dva) {
				std::cout << dva.what() << std::endl;
			}
			break;
		}
		
		case (Komande::ZavrsiIgru): {
			std::vector<std::vector<int>>v;
			KreirajIgru(polja.size(), v);
			throw std::runtime_error("Igra zavrsena");
			break;
		}
			
		case (Komande::KreirajIgru):
			break;
	}
}
						

int main () {
	
/*	std::cout << "Unesite komandu: ";
	std::string s;
	std::getline(std::cin, s);
	try{
		bool ispravnost;
		int x=0, y=0;
		KodoviGresaka greska;
		Smjerovi smjer=Smjerovi::Gore;
		ispravnost=UnosKomande(s, Smjerovi(smjer), x, y, greska);
	}catch(std::domain_error izuzetak) {
		std::cout << izuzetak.what() << std::endl;
	}catch(std::out_of_range izuzetak1) {
		std::cout << izuzetak1.what() << std::endl;
	}catch(std::logic_error izuzetak2) {
		std::cout << izuzetak2.what() << std::endl;
	}*/
	
	
	
	
	Tabla matrica;
	try {
		matrica=KreirajIgru(3, {{1,2},{2,2}});
	}catch(std::domain_error izuzetak) {
		std::cout << izuzetak.what() << std::endl;
	}catch(std::out_of_range izuzetak1) {
		std::cout << izuzetak1.what() << std::endl;
	}catch(std::logic_error izuzetak2) {
		std::cout << izuzetak2.what() << std::endl;
	}
	return 0;
}



// Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine);
// std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y);
// void BlokirajPolje(Tabla &polja, int x, int y);
// void DeblokirajPolje(Tabla &polja, int x, int y);
// Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer);
// Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y);
// bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska);
// void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0);

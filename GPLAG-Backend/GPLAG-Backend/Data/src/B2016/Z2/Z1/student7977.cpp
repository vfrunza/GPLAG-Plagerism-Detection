/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <sstream>

enum class Polje { Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};


typedef std::vector<std::vector<Polje>> Tabla;
// Kreiraj igru
Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	Tabla tablica(n);
	for(int i=0; i<n; i++){
		tablica[i].resize(n);
		for(int j=0; j<n; j++){
			tablica[i][j] = Polje::Prazno;	
		}
	}
	for(int i=0; i<mine.size(); i++){
		if(n>0){
			if(mine[i].size() != 2) throw std::domain_error ("Ilegalan format zadavanja mina");
			for(int j=0; j<mine[i].size()-1; j++){
				if((mine[i][j] >= n) || (mine[i][j] < 0) || (mine[i][j+1] >= n) || (mine[i][j+1] < 0)) 
					throw std::domain_error ("Ilegalne pozicije mina");
				tablica[mine[i][j]][mine[i][j+1]] = Polje::Mina;
			}
		}
	}
	return tablica;
}
//Prikazi okolinu
template <typename T> std::string PretvoriUString(T x) {
	std::ostringstream s;  s << x; return s.str();
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	if((x<0) || (y<0) ||(x>=polja.size()) || (y>=polja[0].size())){
		std::string izuzetak("Polje (" + PretvoriUString(x) + "," + PretvoriUString(y) + ") ne postoji");
		throw std::domain_error (izuzetak);
	
	}
	std::vector<std::vector<int>> v(3);
	for(int i=0; i<3; i++){
		v[i].resize(3);
	}
	
	int suma(0), kolona(0), red(0);
	for(int i=x-1; i<x+2; i++){
		for(int j=y-1; j<y+2; j++){
				for(int k=i-1; k<i+2; k++){
					for(int h=j-1; h<j+2; h++){
						if(!((k<0) || (h<0) || (k>=polja.size()) || (h>=polja[x].size()))){
							if((polja[k][h] == Polje::Mina) && ((i != k)||(j != h))){
								suma++;
							}	
						}
					}
				}
				v[red][kolona] = suma;
				suma = 0;
				kolona++;
		}
		red++;
		kolona = 0;
	}
	return v;
}
//Blokiraj polje
void BlokirajPolje(Tabla &polja, int x, int y){
	if((x<0)||(y<0)||(x>=polja.size()||(y>=polja[0].size()))){
		throw std::domain_error ("Polje (" + PretvoriUString(x) + "," + PretvoriUString(y) + ") ne postoji");
	}
	if(polja[x][y] == Polje::Prazno) polja[x][y] = Polje::BlokiranoPrazno;
	if(polja[x][y] == Polje::Posjeceno) polja[x][y] = Polje::BlokiranoPosjeceno;
	if(polja[x][y] == Polje::Mina) polja[x][y] = Polje::BlokiranoMina;
}
//Deblokiraj Polje
void DeblokirajPolje(Tabla &polja, int x, int y){
	if((x<0)||(y<0)||(x>=polja.size())||(y>=polja[0].size())) 
		throw std::domain_error ("Polje (" + PretvoriUString(x) + "," + PretvoriUString(y) + ") ne postoji");
	if(polja[x][y] == Polje::BlokiranoPrazno) polja[x][y] = Polje::Prazno;
	if(polja[x][y] == Polje::BlokiranoPosjeceno) polja[x][y] = Polje::Posjeceno;
	if(polja[x][y] == Polje::BlokiranoMina) polja[x][y] = Polje::Mina;
}

enum class Smjerovi { GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo 
};

enum class Status { NijeKraj, KrajPoraz, KrajPobjeda
};

Status PomocnaFunkcija(Tabla &polja, int &x, int &y){
	if(polja[x][y] == Polje::Mina){
		for(int i=0; i<polja.size(); i++){
			for(int j=0; j<polja[i].size(); j++){
				polja[i][j] = Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
	int h, k;
	for(k=0; k<polja.size(); k++){
		for(h=0; h<polja[k].size(); h++){
			if((polja[k][h] == Polje::Prazno)&&(polja[k][h] != polja[x][y])) break;
		}
		if(h != polja[k].size()) break;
	}
	if(k != polja.size()) return Status::KrajPobjeda; 

	return Status::NijeKraj;
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	if(smjer == Smjerovi::GoreLijevo){
		if((x<=0) || (y<=0)) throw std::out_of_range ("Izlazak van igrace table");
		if((polja[x-1][y-1]==Polje::BlokiranoPrazno)||(polja[x-1][y-1]==Polje::BlokiranoPosjeceno)||(polja[x-1][y-1] == Polje::BlokiranoMina)){
			throw std::logic_error("Blokirano polje");
		}
		polja[x][y] = Polje::Posjeceno; x--; y--;
		
		return PomocnaFunkcija(polja, x, y); 

	}else if(smjer == Smjerovi::Gore){
		if(x<=0) throw std::out_of_range ("Izlazak van igrace table");
		if((polja[x-1][y]==Polje::BlokiranoPrazno)||(polja[x-1][y]==Polje::BlokiranoPosjeceno)||(polja[x-1][y] == Polje::BlokiranoMina)){
			throw std::logic_error ("Blokirano polje");
		}
		polja[x][y] = Polje::Posjeceno; x--;
		
		return PomocnaFunkcija(polja, x, y);
		
	}else if(smjer == Smjerovi::GoreDesno){
		if((x<=0) || (y>=polja[0].size()-1)) throw std::out_of_range ("Izlazak van igrace table");
		if((polja[x-1][y+1]==Polje::BlokiranoPrazno)||(polja[x-1][y+1]==Polje::BlokiranoPosjeceno)||(polja[x-1][y+1] == Polje::BlokiranoMina)){
			throw std::logic_error ("Blokirano polje");
		}
		polja[x][y] = Polje::Posjeceno; x--; y++;
		
		return PomocnaFunkcija(polja, x, y);
		
	}else if(smjer == Smjerovi::Desno){
		if(y>=polja[0].size()-1) throw std::out_of_range ("Izlazak van igrace table");
		if((polja[x][y+1]==Polje::BlokiranoPrazno)||(polja[x][y+1]==Polje::BlokiranoPosjeceno)||(polja[x][y+1] == Polje::BlokiranoMina)){
			throw std::logic_error ("Blokirano polje");
		}
		polja[x][y] = Polje::Posjeceno; y++;
		
		return PomocnaFunkcija(polja, x, y);
		
	}else if(smjer == Smjerovi::DoljeDesno){
		if((y>=polja[0].size()-1)||(x>=polja.size()-1)) 
			throw std::out_of_range ("Izlazak van igrace table");
		if((polja[x+1][y+1]==Polje::BlokiranoPrazno)||(polja[x+1][y+1]==Polje::BlokiranoPosjeceno)||(polja[x+1][y+1] == Polje::BlokiranoMina)){
			throw std::logic_error ("Blokirano polje");
		}
		polja[x][y] = Polje::Posjeceno; x++; y++;

		return PomocnaFunkcija(polja, x, y);
		
	}else if((smjer == Smjerovi::Dolje) && (x<polja.size()-1)){
		if(x>=polja.size()-1) throw std::out_of_range ("Izlazak van igrace table");
		if((polja[x+1][y]==Polje::BlokiranoPrazno)||(polja[x+1][y]==Polje::BlokiranoPosjeceno)||(polja[x+1][y] == Polje::BlokiranoMina)){
			throw std::logic_error ("Blokirano polje");
		}
		polja[x][y] = Polje::Posjeceno; x++;
	
		return PomocnaFunkcija(polja, x, y);
		
	}else if(smjer == Smjerovi::DoljeLijevo){
		if((x>=polja.size()-1)||(y<=0)) throw std::out_of_range ("Izlazak van igrace table");
		if((polja[x+1][y-1]==Polje::BlokiranoPrazno)||(polja[x+1][y-1]==Polje::BlokiranoPosjeceno)||(polja[x+1][y-1] == Polje::BlokiranoMina)){
			throw std::logic_error ("Blokirano polje");
	}
		polja[x][y] = Polje::Posjeceno; x++; y--;
		
		return PomocnaFunkcija(polja, x, y);
		
	}else if(smjer == Smjerovi::Lijevo){
		if(y<=0) throw std::out_of_range ("Izlazak van igrace table");
		if((polja[x][y-1]==Polje::BlokiranoPrazno)||(polja[x][y-1]==Polje::BlokiranoPosjeceno)||(polja[x][y-1] == Polje::BlokiranoMina)){
			throw std::logic_error ("Blokirano polje");
		}
		polja[x][y] = Polje::Posjeceno; y--;
		
		return PomocnaFunkcija(polja, x, y);
	}
	return Status::NijeKraj;
}

Status Idi(Tabla &polja, int &x, int&y, int novi_x, int novi_y){
	if((novi_x<0)||(novi_y<0)||(novi_x>=polja.size())||(novi_y>=polja[0].size())){
		throw std::out_of_range("Izlazak van igrace table");
	}
	if((polja[novi_x][novi_y]==Polje::BlokiranoPrazno)||(polja[novi_x][novi_y]==Polje::BlokiranoPosjeceno)||(polja[novi_x][novi_y]==Polje::BlokiranoMina)){
		throw std::logic_error("Blokirano polje");
	}

	polja[x][y] = Polje::Posjeceno;
	x=novi_x;
	y=novi_y;

	return PomocnaFunkcija(polja, x, y);
}

enum class KodoviGresaka { PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};

void PrijaviGresku(KodoviGresaka greska){
	if(greska == KodoviGresaka::PogresnaKomanda){
		std::cout << "Nerazumljiva komanda!" << std::endl;
	}else if(greska == KodoviGresaka::NedostajeParametar){
		std::cout << "Komanda trazi parametar koji nije naveden!" << std::endl;
	}else if(greska == KodoviGresaka::NeispravanParametar){
		std::cout << "Parametar komande nije ispravan!" << std::endl;
	}else if(greska == KodoviGresaka::SuvisanParametar){
		std:: cout << "Zadan je suvisan parametar nakon komande!" << std::endl;
	}
}

enum class Komande { 
	PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};

int OdstraniRazmake(std::string unos, int i){
	int j, povratna;
	bool a(true);
	for(j=i; j<unos.length(); j++){
		if(unos[j] == ' '){
			a = true;
		}else if( a==true ){
			a = false;
			povratna = j;
			break;
		}
	}
	if(j == unos.length()) povratna = j;
	return povratna;
}

int PretvoriUBroj(std::string s){
	int broj(0); 
	for(int i=0; i<s.length(); i++){
		broj = broj*10 + (s[i] - '0');
	}
	return broj;
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	std::string unos;
	std::getline(std::cin, unos);
	int kraj_unosa = unos.length();
	int j(OdstraniRazmake(unos, 0));
	bool povrat(false);
	
	if(j != kraj_unosa){
//Pomjeri se za jedno mjesto
		if(unos[j]=='P'){
			j++;
			if(j == kraj_unosa){
				greska = KodoviGresaka::PogresnaKomanda;
			}else if(unos[j]=='1'){
				j++;
				if(j == kraj_unosa){
					greska = KodoviGresaka::NedostajeParametar;
				}else if(unos[j] == ' '){
					j = OdstraniRazmake(unos, j);
					if(j != kraj_unosa){
						if(unos[j]=='G'){
							j++;
							if(j==kraj_unosa){
								povrat = true;
								komanda = Komande::PomjeriJednoMjesto;
								smjer = Smjerovi::Gore;
							}else if(unos[j] == ' '){
								j=OdstraniRazmake(unos, j);
								if(j==kraj_unosa){
									povrat = true;
									komanda = Komande::PomjeriJednoMjesto;
									smjer = Smjerovi::Gore;
								}else{
									greska = KodoviGresaka::SuvisanParametar;
								}
							}else if(unos[j] == 'L'){
								j++;	
								j = OdstraniRazmake(unos, j);
								if(j==kraj_unosa){
									povrat = true;
									komanda = Komande::PomjeriJednoMjesto;
									smjer = Smjerovi::GoreLijevo;
								}else{
									greska = KodoviGresaka::SuvisanParametar;
								}
							}else if(unos[j] == 'D'){
								j++;
								j = OdstraniRazmake(unos, j);
								if(j==kraj_unosa){
									povrat = true;
									komanda = Komande::PomjeriJednoMjesto;
									smjer = Smjerovi::GoreDesno;
								}else{
									greska = KodoviGresaka::SuvisanParametar;
								}
							}
						}else if(unos[j] == 'D'){
							j++;
							if(j==kraj_unosa){
								povrat = true;
								komanda = Komande::PomjeriJednoMjesto;
								smjer = Smjerovi::Desno;
							}else if(unos[j] == ' '){
								j = OdstraniRazmake(unos, j);
								if(j == kraj_unosa){
									povrat = true;
									komanda = Komande::PomjeriJednoMjesto;
									smjer = Smjerovi::Desno;
								}else{
									greska = KodoviGresaka::SuvisanParametar;
								}
							}else if(unos[j] == 'o'){
								j++;
								if(j == kraj_unosa){
									povrat = true;
									komanda = Komande::PomjeriJednoMjesto;
									smjer = Smjerovi::Dolje;
								}else if(unos[j] == ' '){
									j = OdstraniRazmake(unos, j);
									if(j == kraj_unosa){
										povrat = true;
										komanda = Komande::PomjeriJednoMjesto;
										smjer = Smjerovi::Dolje;
									}else{
										greska = KodoviGresaka::SuvisanParametar;
									}
								}else if(unos[j] == 'D'){
									j++;
									j = OdstraniRazmake(unos, j);
									if(j == kraj_unosa){
										povrat = true;
										komanda = Komande::PomjeriJednoMjesto;
										smjer = Smjerovi::DoljeDesno;
									}else{
										greska = KodoviGresaka::SuvisanParametar;
									}
								}else if(unos[j] == 'L'){
									j++;
									j = OdstraniRazmake(unos, j);
									if(j == kraj_unosa){
										povrat = true;
										komanda = Komande::PomjeriJednoMjesto;
										smjer = Smjerovi::DoljeLijevo;
									}else{
										greska = KodoviGresaka::SuvisanParametar;
									}
								}else{
									greska = KodoviGresaka::SuvisanParametar;
								}
							}
					
						}else if(unos[j] == 'L'){
							j++;
							if(j == kraj_unosa){
								povrat = true;
								komanda = Komande::PomjeriJednoMjesto;
								smjer = Smjerovi::Lijevo;
							}else if(unos[j] == ' '){
								j = OdstraniRazmake(unos, j);
								if(j == kraj_unosa){
									povrat = true;
									komanda = Komande::PomjeriJednoMjesto;
									smjer = Smjerovi::Lijevo;
								}else{
									greska = KodoviGresaka::SuvisanParametar;
								}
							}else{
								greska = KodoviGresaka::SuvisanParametar;
							}
						}else{
							greska = KodoviGresaka::NeispravanParametar;
						}
					}else{
						greska = KodoviGresaka::NedostajeParametar;
					}
				}else{
					greska = KodoviGresaka::PogresnaKomanda;
				}
// Pomjeri se na zadano polje
			}else if(unos[j]=='>'){
				j++;
				if(j == kraj_unosa){
					greska = KodoviGresaka::NedostajeParametar;
				}else if(unos[j] == ' '){
					j = OdstraniRazmake(unos, j);
					if(j == kraj_unosa){
						greska = KodoviGresaka::NedostajeParametar;
					}else if(unos[j] >= '0' && unos[j] <= '9'){
						int i;
						for(i=j; i<kraj_unosa; i++){
							if(!((unos[i] == ' ') || (unos[i] >= '0' && unos[i] <= '9'))){
								break;
							}
						}
						if(i == unos.length()){
							for(i=j; i<kraj_unosa; i++){
								if(unos[i] == ' ' || i == kraj_unosa) break;
							}
						
							int poten_x(PretvoriUBroj(unos.substr(j, i-j)));
							j=i;
							if(j == kraj_unosa){
								greska = KodoviGresaka::NedostajeParametar;
							}else if(unos[j] == ' '){
								j = OdstraniRazmake(unos, j);
								if(j == kraj_unosa){
									greska = KodoviGresaka::NedostajeParametar;
								}else{
									for(i=j; i<kraj_unosa; i++){
										if(unos[i] == ' ' || i==kraj_unosa) break;
									}
									int poten_y(PretvoriUBroj(unos.substr(j, i-j)));
									j=i;
									j = OdstraniRazmake(unos, j);
									if(j == kraj_unosa){
										povrat = true;
										komanda = Komande::PomjeriDalje;
										x = poten_x;
										y = poten_y;
									}else{
										greska = KodoviGresaka::SuvisanParametar;
									}
								}
							}
						}else{
							greska = KodoviGresaka::SuvisanParametar;
						}
						
					}else{
						greska = KodoviGresaka::NeispravanParametar;
					}
				}else{
					greska = KodoviGresaka::PogresnaKomanda;
				}
//Prikazi okolinu zadatog polja
			}else if(unos[j]=='O'){
				j++;
				if(j == kraj_unosa){
					povrat = true;
					komanda = Komande::PrikaziOkolinu;
				}else if(unos[j] == ' '){
					j = OdstraniRazmake(unos, j);
					if(j == kraj_unosa){
						povrat = true;
						komanda = Komande::PrikaziOkolinu;
					}else{
						greska = KodoviGresaka::SuvisanParametar;
					}
				}else{
					greska = KodoviGresaka::PogresnaKomanda;
				}
			}else{
				greska = KodoviGresaka::PogresnaKomanda;
			}
// Blokiraj polje
		}else if(unos[j]=='B'){
			j++;
			if(j == kraj_unosa){
				greska = KodoviGresaka::NedostajeParametar;
			}else if(unos[j] == ' '){
				j = OdstraniRazmake(unos, j);
				if(j == kraj_unosa){
					greska = KodoviGresaka::NedostajeParametar;
				}else if(unos[j] >= '0' && unos[j] <= '9'){
					int i;
					for(i=j; i<kraj_unosa; i++){
						if(!((unos[i] == ' ') || (unos[i] >= '0' && unos[i] <= '9'))){
							break;
						}
					}
					if(i == unos.length()){
						for(i=j; i<kraj_unosa; i++){
							if(unos[i] == ' ' || i == kraj_unosa) break;
						}
						
						int poten_x(PretvoriUBroj(unos.substr(j, i-j)));
						j=i;
						if(j == kraj_unosa){
							greska = KodoviGresaka::NedostajeParametar;
						}else if(unos[j] == ' '){
							j = OdstraniRazmake(unos, j);
							if(j == kraj_unosa){
								greska = KodoviGresaka::NedostajeParametar;
							}else{
								for(i=j; i<kraj_unosa; i++){
									if(unos[i] == ' ' || i == kraj_unosa) break;
								}
								int poten_y(PretvoriUBroj(unos.substr(j, i-j)));
								j=i;
								j = OdstraniRazmake(unos, j);
								if(j == kraj_unosa){
									povrat = true;
									komanda = Komande::Blokiraj;
									x = poten_x;
									y = poten_y;
								}else{
									greska = KodoviGresaka::SuvisanParametar;
								}
							}
						}
					}else{
						greska = KodoviGresaka::SuvisanParametar;
					}
					
				}else{
					greska = KodoviGresaka::NeispravanParametar;
				}
			}else{
				greska = KodoviGresaka::PogresnaKomanda;
			}
			
// Deblokiraj polje
		}else if(unos[j]=='D'){
			j++;
			if(j == kraj_unosa){
				greska = KodoviGresaka::NedostajeParametar;
			}else if(unos[j] == ' '){
				j = OdstraniRazmake(unos, j);
				if(j == kraj_unosa){
					greska = KodoviGresaka::NedostajeParametar;
				}else if(unos[j] >= '0' && unos[j] <= '9'){
					int i;
					for(i=j; i<kraj_unosa; i++){
						if(!((unos[i] == ' ') || (unos[j] >= '0' && unos[j] <= '9'))){
							break;
						}
					}
					if(i == unos.length()){
						for(i=j; i<kraj_unosa; i++){
							if(unos[i] == ' ' || i == kraj_unosa) break;
						}

						int poten_x(PretvoriUBroj(unos.substr(j, i-j)));
						j=i;
						if(j == kraj_unosa){
							greska = KodoviGresaka::NedostajeParametar;
						}else if(unos[j] == ' '){
							j = OdstraniRazmake(unos, j);
							if(j == kraj_unosa){
								greska = KodoviGresaka::NedostajeParametar;
							}else{
								for(i=j; i<kraj_unosa; i++){
									if(unos[i] == ' ' || i==kraj_unosa) break;
								}
								int poten_y(PretvoriUBroj(unos.substr(j, i-j)));
								j=i;
								j = OdstraniRazmake(unos, j);
								if(j == kraj_unosa){
									povrat = true;
									komanda = Komande::Deblokiraj;
									x = poten_x;
									y = poten_y;
								}else{
									greska = KodoviGresaka::SuvisanParametar;
								}
							}
						}
					}else{
						greska = KodoviGresaka::SuvisanParametar;
					}
					
				}else{
					greska = KodoviGresaka::NeispravanParametar;
				}
			}else{
				greska = KodoviGresaka::PogresnaKomanda;
			}
//Zavrsi igru
		}else if(unos[j]=='Z'){
			j++;
			if(j == kraj_unosa){
				povrat = true;
				komanda = Komande::ZavrsiIgru;
			}else if(unos[j] == ' '){
				j = OdstraniRazmake(unos, j);
				if(j == kraj_unosa){
					povrat = true;
					komanda = Komande::ZavrsiIgru;
				}else{
					greska = KodoviGresaka::SuvisanParametar;
				}
			}else{
				greska = KodoviGresaka::PogresnaKomanda;
			}
//Kreiraj igru
		}else if(unos[j]=='K'){
			j++;
			if(j == kraj_unosa){
				povrat = true;
				komanda = Komande::KreirajIgru;
			}else if(unos[j] == ' '){
				j = OdstraniRazmake(unos, j);
				if(j == kraj_unosa){
					povrat = true;
					komanda = Komande::KreirajIgru;
				}else{
					greska = KodoviGresaka::SuvisanParametar;
				}
			}else{
				greska = KodoviGresaka::PogresnaKomanda;
			}
				
		}else{
			greska = KodoviGresaka::PogresnaKomanda; 
		}
	}else{
		greska = KodoviGresaka::PogresnaKomanda;
	}
	return povrat;
}

void IzvrsiKomandu( Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0 ){
	
	if(komanda == Komande::PomjeriDalje){
		Status status;
		try{
			status = Idi(polja, p_x, p_y, x, y);
			std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")" << std::endl;
			if(status == Status::KrajPoraz){
				std::cout << "Nagazili ste na minu" << std::endl;
				for(int i=0; i<polja.size(); i++){
					for(int j=0; j<polja[i].size(); j++){
						polja[i][j] = Polje::Prazno;
					}
				}
				throw std::runtime_error ("Igra zavrsava");
				
			}else if(status == Status::KrajPobjeda){
				std::cout << "Bravo, obisli ste sva polja" << std::endl;
				for(int i=0; i<polja.size(); i++){
					for(int j=0; j<polja[i].size(); j++){
						polja[i][j] = Polje::Prazno;
					}
				}
				throw std::runtime_error ("Igra zavrsava");
			}
		}catch(std::logic_error izuzetak){
			std::cout << izuzetak.what() << std::endl;
		}catch(std::out_of_range izuzetak1){
			std::cout << izuzetak1.what() << std::endl;
		}
//POMJERI JEDNO MJESTO	
	}else if(komanda == Komande::PomjeriJednoMjesto){
		Status status;
		try{
			status = Idi(polja, x, y, p_smjer);
			std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")" << std::endl;
			if(status == Status::KrajPoraz){
				std::cout << "Nagazili ste na minu" << std::endl;
				for(int i=0; i<polja.size(); i++){
					for(int j=0; j<polja[i].size(); j++){
						polja[i][j] = Polje::Prazno;
					}
				}
				throw std::runtime_error ("Igra zavrsava");
			
			}else if(status == Status::KrajPobjeda){
				std::cout << "Bravo, obisli ste sva polja" << std::endl;
				for(int i=0; i<polja.size(); i++){
					for(int j=0; j<polja[i].size(); j++){
						polja[i][j] = Polje::Prazno;
					}
				}
				throw std::runtime_error ("Igra zavrsava");
			}
		}catch(std::logic_error izuzetak){
			std::cout << izuzetak.what() << std::endl;
		}catch(std::out_of_range izuzetak1){
			std::cout << izuzetak1.what() << std::endl;
		}
//Blokiraj		
	}else if(komanda == Komande::Blokiraj){
		
		try{
			BlokirajPolje(polja, x, y);
		}catch(std::domain_error izuzetak){
			std::cout << izuzetak.what() << std::endl;
		}
//Deblokiraj		
	}else if(komanda == Komande::Deblokiraj){
		
		try{
			DeblokirajPolje(polja, x, y);
		}catch(std::domain_error izuzetak){
			std::cout << izuzetak.what() << std::endl;
		}
//Prikazi okolinu		
	}else if(komanda == Komande::PrikaziOkolinu){
		std::vector<std::vector<int>> matrica;
		try{
			matrica = PrikaziOkolinu(polja, x, y);
		}catch(std::domain_error izuzetak){
			std::cout << izuzetak.what() << std::endl;
		}
		
		for(int i=0; i<matrica.size(); i++){
			for(int j=0; j<matrica[i].size(); j++){
				std::cout << matrica[i][j] << " ";
			}
			std::cout << std::endl;
		}
//Zavrsi igru		
	}else if(komanda == Komande::ZavrsiIgru){
		
		for(int i=0; i<polja.size(); i++){
			for(int j=0; j<polja[i].size(); j++){
				polja[i][j] = Polje::Prazno;
			}
		}
		throw std::runtime_error ("Igra zavrsava");
// Kreiraj igru		
	}else if(komanda == Komande::KreirajIgru){
		std::cout << "Unesite broj polja: ";
		int n;
		std::cin >> n;
		std::cin.ignore(1000,'\n');
		std::cout << "Unesite pozicije mina: ";
		std::vector<std::vector<int>> v;
		int br_redova(0);
		
		while(1){
			
			std::string unos;
			std::getline(std::cin, unos);
			
			if(unos.length() == 1 && unos[0] == '.') break;
			if(unos.length() == 0){
				std::cout << "Greska, unesite ponovo!" << std::endl;
				continue;
			}
			
			int i;
			for(i=0; i<unos.length(); i++){
				if(!((unos[i] >= '0' && unos[i] <= '9')||(unos[i] == '(')||(unos[i] == ')')||(unos[i] == ',')||(unos[i] == ' '))){
					break;
				}
			}
			
			if(i == unos.length()){
				i = 0;
				if(unos[i] == '('){
					i++;
					if((unos[i] >= '0' && unos[i] <= '9') && unos.length() != i){
						int j;
						for(j=i; j<unos.length(); j++){
							if(unos[j] == ',') break;
						}
						if(j != unos.length()){
							int a(PretvoriUBroj(unos.substr(i, j-i)));
							i = j;
							i++;
							if((unos[i] >= '0' && unos[i] <= '9') && i!=unos.length()){
								int j;
								for(j=i; j<unos.length(); j++){
									if(unos[j] == ')') break;
								}
								if(j!=unos.length()){
									int b(PretvoriUBroj(unos.substr(i,j-i)));
									i = j;
									i++;
									if(i == unos.length()){
										if(a<n && b<n && a>=0 && b>=0){
											if(a == 0 && b == 0){
												std::cout << "Greska, unesite ponovo!" << std::endl;
												continue;
											}else{
												v.resize(br_redova+1);
												v[br_redova].resize(2);
												v[br_redova][0] = a;
												v[br_redova][1] = b;
												br_redova++;
											}
										}else{
											std::cout << "Greska, unesite ponovo!" << std::endl;
											continue;
										}
									}else{
										std::cout << "Greska, unesite ponovo!" << std::endl;
										continue;
									}
								}else{
									std::cout << "Greska, unesite ponovo!" << std::endl;
									continue;
								}
							}else{
								std::cout << "Greska, unesite ponovo!" << std::endl;
								continue;
							}
						}else{
							std::cout << "Greska, unesite ponovo!" << std::endl;
							continue;
						}
					}else{
						std::cout << "Greska, unesite ponovo!" << std::endl;
						continue;
					}
				}else{
					std::cout << "Greska, unesite ponovo!" << std::endl;
					continue;
				}
			}else{
				std::cout << "Greska, unesite ponovo!" << std::endl;
				continue;
			}
		}
		try{
			polja = KreirajIgru(n, v);
		}catch(std::domain_error izuzetak){
			std::cout << izuzetak.what() << std::endl;
		}
	}
	
}

int main ()
{
	Komande komanda;
	Smjerovi smjer;
	int x(0), y(0), p_x(0), p_y(0);
	KodoviGresaka greska;
	Tabla polja;
	try{
		while(1){
			std::cout << "Unesite komandu: ";
			if(UnosKomande(komanda, smjer, x, y, greska)){
				IzvrsiKomandu(komanda, polja, x, y, smjer, p_x, p_y);
			}else{
				PrijaviGresku(greska);
			}
		}
	}catch(std::runtime_error){
		std::cout << "Dovidjenja!" << std::endl;
	}
	
	return 0;
}
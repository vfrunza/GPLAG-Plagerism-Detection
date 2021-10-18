#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

enum class Polje {Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina};
enum class Smjerovi {GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo};
enum class Status {NijeKraj, KrajPoraz, KrajPobjeda};
enum class KodoviGresaka {PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar};
enum class Komande {PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru};

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &Mine){
	if(n<=0) throw std::domain_error("Ilegalna velicina");
	
	for(int i=0; i<int(Mine.size()); i++)
		for(int j=0; j<int(Mine.at(i).size()); j++){
			if(Mine.at(i).size()!=2 || Mine.at(0).size()!=Mine.at(i).size()) throw std::domain_error("Ilegalan format zadavanja mina");
			else if(Mine.at(i).at(j)>=n || Mine.at(i).at(j)<0) throw std::domain_error("Ilegalne pozicije mina");
		}		
	Tabla tabla_igre(n,std::vector<Polje> (n, Polje::Prazno));
	
	for(int i=0; i<int(tabla_igre.size()); i++)
		for(int j=0; j<int(tabla_igre.at(i).size()); j++){
			if(i==0 && j==0) continue;
			for(int k=0; k<int(Mine.size()); k++)
				if(i==Mine.at(k).at(0) && j==Mine.at(k).at(1)) tabla_igre.at(i).at(j)=Polje::Mina;
		}
		
	return tabla_igre;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	if(x>=int(polja.size()) || x<0 || y>=int(polja.at(0).size()) || y<0) 
		throw std::domain_error("Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji");
	
	std::vector<std::vector<int>> Okolina(5, std::vector<int> (5,0));
	int i_brojac(0), j_brojac(0);
	for(int i=x-2; i<=x+2; i++){
		j_brojac=0;
		for(int j=y-2; j<=y+2; j++){
			if(i<0 || i>=int(polja.size()) || j<0 || j>=int(polja.at(0).size())) Okolina.at(i_brojac).at(j_brojac)=0;
			else if(polja.at(i).at(j)==Polje::Mina) Okolina.at(i_brojac).at(j_brojac)=1;
			else Okolina.at(i_brojac).at(j_brojac)=0;
			j_brojac++;
		}
		i_brojac++;
	} 

	std::vector<std::vector<int>> BrojMina(3, std::vector<int> (3,0));
	i_brojac=0;
	for(int i=1; i<int(Okolina.size())-1; i++){
		j_brojac=0;
		for(int j=1; j<int(Okolina.at(i).size())-1; j++){
			for(int k=i-1; k<=i+1; k++) 
				for(int l=j-1; l<=j+1; l++)
					if(k==i-1 || k==i+1 || l==j-1 || l==j+1) BrojMina.at(i_brojac).at(j_brojac)+=Okolina.at(k).at(l);
			j_brojac++;	
		}
		i_brojac++;
	}
	return BrojMina;
}

void BlokirajPolje(Tabla &polja, int x, int y){
	if(x>=int(polja.size()) || x<0 || y>=int(polja.at(0).size()) || y<0) 
		throw std::domain_error("Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji");
		
	switch(polja.at(x).at(y)){
		case Polje::Mina:
			polja.at(x).at(y)=Polje::BlokiranoMina;
			break;
		case Polje::Prazno:
			polja.at(x).at(y)=Polje::BlokiranoPrazno;
			break;
		case Polje::Posjeceno:
			polja.at(x).at(y)=Polje::BlokiranoPosjeceno;
			break;
		default:
			break;
	}
}

void DeblokirajPolje(Tabla &polja, int x, int y){
	if(x>=int(polja.size()) || x<0 || y>=int(polja.at(0).size()) || y<0) 
		throw std::domain_error("Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji");
		
	switch(polja.at(x).at(y)){
		case Polje::BlokiranoMina:
			polja.at(x).at(y)=Polje::Mina;
			break;
		case Polje::BlokiranoPrazno:
			polja.at(x).at(y)=Polje::Prazno;
			break;
		case Polje::BlokiranoPosjeceno:
			polja.at(x).at(y)=Polje::Posjeceno;
			break;
		default:
			break;
	}
}

void OcistiTablu(Tabla &polja){
	for(int i=0; i<int(polja.size()); i++)
		for(int j=0; j<int(polja.at(i).size()); j++) polja.at(i).at(j)=Polje::Prazno;
}

Status StatusIgre(Tabla &polja, int &x, int &y){
	if(polja.at(x).at(y)==Polje::Mina){
		OcistiTablu(polja);
		return Status::KrajPoraz;	
	} 
	for(int i=0; i<int(polja.size()); i++)
		for(int j=0; j<int(polja.at(i).size()); j++)
			if((i!=x || j!=y) && polja.at(i).at(j)==Polje::Prazno) return Status::NijeKraj;
	return Status::KrajPobjeda;
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	switch(smjer){
		case Smjerovi::GoreLijevo: 
			if(x-1<0 || y-1<0)
				throw std::out_of_range("Izlazak van igrace table");
			else if(polja.at(x-1).at(y-1)==Polje::BlokiranoPosjeceno || polja.at(x-1).at(y-1)==Polje::BlokiranoPrazno || polja.at(x-1).at(y-1)==Polje::BlokiranoMina)
				throw std::logic_error("Blokirano polje");
			polja.at(x).at(y)=Polje::Posjeceno; x--; y--; 
			return StatusIgre(polja, x, y);
		case Smjerovi::Gore:
			if(x-1<0)
				throw std::out_of_range("Izlazak van igrace table");
			else if(polja.at(x-1).at(y)==Polje::BlokiranoPosjeceno || polja.at(x-1).at(y)==Polje::BlokiranoPrazno || polja.at(x-1).at(y)==Polje::BlokiranoMina)
				throw std::logic_error("Blokirano polje");
			polja.at(x).at(y)=Polje::Posjeceno; x--;
			return StatusIgre(polja, x, y);
		case Smjerovi::GoreDesno:
			if(x-1<0 || y+1>=int(polja.size()))
				throw std::out_of_range("Izlazak van igrace table");
			else if(polja.at(x-1).at(y+1)==Polje::BlokiranoPosjeceno || polja.at(x-1).at(y+1)==Polje::BlokiranoPrazno || polja.at(x-1).at(y+1)==Polje::BlokiranoMina)
				throw std::logic_error("Blokirano polje");
			polja.at(x).at(y)=Polje::Posjeceno; x--; y++; 
			return StatusIgre(polja, x, y);
		case Smjerovi::Lijevo:
			if(y-1<0)
				throw std::out_of_range("Izlazak van igrace table");
			else if(polja.at(x).at(y-1)==Polje::BlokiranoPosjeceno || polja.at(x).at(y-1)==Polje::BlokiranoPrazno || polja.at(x).at(y-1)==Polje::BlokiranoMina)
				throw std::logic_error("Blokirano polje");
			polja.at(x).at(y)=Polje::Posjeceno; y--; 
			return StatusIgre(polja, x, y);
		case Smjerovi::Desno:
			if(y+1>=int(polja.size()))
				throw std::out_of_range("Izlazak van igrace table");
			else if(polja.at(x).at(y+1)==Polje::BlokiranoPosjeceno || polja.at(x).at(y+1)==Polje::BlokiranoPrazno || polja.at(x).at(y+1)==Polje::BlokiranoMina)
				throw std::logic_error("Blokirano polje");
			polja.at(x).at(y)=Polje::Posjeceno; y++; 
			return StatusIgre(polja, x, y);
		case Smjerovi::DoljeLijevo:
			if(x+1>=int(polja.size()) || y-1<0)
				throw std::out_of_range("Izlazak van igrace table");
			else if(polja.at(x+1).at(y-1)==Polje::BlokiranoPosjeceno || polja.at(x+1).at(y-1)==Polje::BlokiranoPrazno || polja.at(x+1).at(y-1)==Polje::BlokiranoMina)
				throw std::logic_error("Blokirano polje");
			polja.at(x).at(y)=Polje::Posjeceno; x++; y--; 
			return StatusIgre(polja, x, y);
		case Smjerovi::Dolje:
			if(x+1>=int(polja.size()))
				throw std::out_of_range("Izlazak van igrace table");
			else if(polja.at(x+1).at(y)==Polje::BlokiranoPosjeceno || polja.at(x+1).at(y)==Polje::BlokiranoPrazno || polja.at(x+1).at(y)==Polje::BlokiranoMina)
				throw std::logic_error("Blokirano polje");
			polja.at(x).at(y)=Polje::Posjeceno; x++;
			return StatusIgre(polja, x, y);
		case Smjerovi::DoljeDesno:
			if(x+1>=int(polja.size()) || y+1>=int(polja.size()))
				throw std::out_of_range("Izlazak van igrace table");
			else if(polja.at(x+1).at(y+1)==Polje::BlokiranoPosjeceno || polja.at(x+1).at(y+1)==Polje::BlokiranoPrazno || polja.at(x+1).at(y+1)==Polje::BlokiranoMina)
				throw std::logic_error("Blokirano polje");
			polja.at(x).at(y)=Polje::Posjeceno; x++; y++; 
			return StatusIgre(polja, x, y);
		default:
			return Status::NijeKraj;
	}
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	if(novi_x<0 || novi_y<0 || novi_x>=int(polja.size()) || novi_y>=int(polja.at(0).size())) 
		throw std::out_of_range("Izlazak van igrace table");
	else if(polja.at(novi_x).at(novi_y)==Polje::BlokiranoPosjeceno || polja.at(novi_x).at(novi_y)==Polje::BlokiranoPrazno || polja.at(novi_x).at(novi_y)==Polje::BlokiranoMina) 
		throw std::logic_error("Blokirano polje");
	polja.at(x).at(y)=Polje::Posjeceno; x=novi_x; y=novi_y;
	return StatusIgre(polja, x, y);
}

void PrijaviGresku(KodoviGresaka greska){
	switch(greska){
		case KodoviGresaka::PogresnaKomanda:
			std::cout << "Nerazumljiva komanda!" << std::endl; break;
		case KodoviGresaka::NedostajeParametar:
			std::cout << "Komanda trazi parametar koji nije naveden!" << std::endl; break;
		case KodoviGresaka::NeispravanParametar:
			std::cout << "Parametar komande nije ispravan!" << std::endl; break;
		case KodoviGresaka::SuvisanParametar:
			std::cout << "Zadan je suvisan parametar nakon komande!" << std::endl; break;
	}
}

bool PravilnoUneseneKoordinate(Komande &komanda, int &x, int &y, KodoviGresaka &greska, std::string &unesena_komanda, int i){
	char znak=unesena_komanda.at(i);
	i++;
	if(i>=int(unesena_komanda.size())){
		greska=KodoviGresaka::NedostajeParametar;
		return false;
	}
	while(i<int(unesena_komanda.size()) && unesena_komanda.at(i)==' ') i++;
	if(i>=int(unesena_komanda.length())){
		greska=KodoviGresaka::NedostajeParametar; return false;
	}
	else if(unesena_komanda.at(i)>='0' && unesena_komanda.at(i)<='9'){
		std::vector<int> koordinate(0);
		int broj(0);
		while(i<int(unesena_komanda.size()) && unesena_komanda.at(i)>='0' && unesena_komanda.at(i)<='9' ){
			broj=(broj*10)+(unesena_komanda.at(i)-'0');
			i++;
		}
		if(i>=int(unesena_komanda.length())){
			greska=KodoviGresaka::NedostajeParametar;
			return false;
		}
		else if(unesena_komanda.at(i)!=' '){
			greska=KodoviGresaka::NeispravanParametar;
			return false;
		}
		koordinate.push_back(broj);
		while(i<int(unesena_komanda.size()) && unesena_komanda.at(i)==' ') i++;
		if(i>=int(unesena_komanda.length())){
			greska=KodoviGresaka::NedostajeParametar; return false;
		}
		else if(unesena_komanda.at(i)>='0' && unesena_komanda.at(i)<='9'){
			broj=0;
			while(i<int(unesena_komanda.size()) && unesena_komanda.at(i)>='0' && unesena_komanda.at(i)<='9'){
				broj=(broj*10)+(unesena_komanda.at(i)-'0');
				i++;
			}
			koordinate.insert(koordinate.end(),broj);
			if(i>=int(unesena_komanda.length()) && int(koordinate.size())==2){
				x=koordinate.at(0);
				y=koordinate.at(1);
				if(znak=='B') komanda=Komande::Blokiraj;
				else if(znak=='D') komanda=Komande::Deblokiraj;
				else if(znak=='>') komanda=Komande::PomjeriDalje;
				return true;
			}
			else if(i!=int(unesena_komanda.length()) && unesena_komanda.at(i)!=' '){
				greska=KodoviGresaka::NeispravanParametar;
				return false;
			}
			
			while(i<int(unesena_komanda.length())){
				if(unesena_komanda.at(i)!=' '){
					greska=KodoviGresaka::NeispravanParametar; return false;
				}
				i++;
			}
			x=koordinate.at(0);
			y=koordinate.at(1);
			if(znak=='B') komanda=Komande::Blokiraj;
			else if(znak=='D') komanda=Komande::Deblokiraj;
			else if(znak=='>') komanda=Komande::PomjeriDalje;
			return true;
		}
		greska=KodoviGresaka::NeispravanParametar; return false;
	}
	greska=KodoviGresaka::NeispravanParametar; return false;
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	std::string unesena_komanda;
	std::getline(std::cin, unesena_komanda);
	for(int i=0; i<int(unesena_komanda.length()); i++){
		if(unesena_komanda.at(i)==' ') continue;
		else if(unesena_komanda.at(i)=='P' || unesena_komanda.at(i)=='D' || unesena_komanda.at(i)=='Z' || unesena_komanda.at(i)=='K' || unesena_komanda.at(i)=='B'){
			if(unesena_komanda.at(i)=='K' || unesena_komanda.at(i)=='Z'){
				char znak=unesena_komanda.at(i);
				i++;
				while(i<int(unesena_komanda.length())){ 
					if(unesena_komanda.at(i)!=' '){
						greska=KodoviGresaka::SuvisanParametar;
						return false;
					}
					i++;
				}
				if(znak=='K') komanda=Komande::KreirajIgru; 
				else if(znak=='Z') komanda=Komande::ZavrsiIgru;
				return true;
			}
			else if(unesena_komanda.at(i)=='D' || unesena_komanda.at(i)=='B') return PravilnoUneseneKoordinate(komanda, x, y, greska, unesena_komanda, i);	
			else if(unesena_komanda.at(i)=='P'){
				if(i+1>=int(unesena_komanda.length()) || (unesena_komanda.at(i+1)!='O'&& unesena_komanda.at(i+1)!='>' && unesena_komanda.at(i+1)!='1')){
					greska=KodoviGresaka::PogresnaKomanda;
					return false;
				}
				i++;
				if(unesena_komanda.at(i)=='1'){
					i++;
					while(i<int(unesena_komanda.length()) && unesena_komanda.at(i)==' ') i++;
					if(i>=int(unesena_komanda.length())){
						greska=KodoviGresaka::NedostajeParametar;
						return false;
					}
					switch(unesena_komanda.at(i)){
						case 'D':
							if(i+1>=int(unesena_komanda.length())){
								komanda=Komande::PomjeriJednoMjesto;
								smjer=Smjerovi::Desno;
								return true;
							}
							else if(unesena_komanda.at(i+1)==' '){
								i++;
								while(i<int(unesena_komanda.length())){
									if(unesena_komanda.at(i)!=' '){
										greska=KodoviGresaka::NeispravanParametar; return false;
									}
									 i++;
								}
								komanda=Komande::PomjeriJednoMjesto;
								smjer=Smjerovi::Desno;
								return true;
							}
							else if(unesena_komanda.at(i+1)!='o'){
								greska=KodoviGresaka::NeispravanParametar; return false;
							}
							else{
								i++;
								if(i+1>=int(unesena_komanda.length())){
									komanda=Komande::PomjeriJednoMjesto;
									smjer=Smjerovi::Dolje;
									return true;
								}
								else if(unesena_komanda.at(i+1)==' '){
									i++;
									while(i<int(unesena_komanda.length())){
										if(unesena_komanda.at(i)!=' '){
											greska=KodoviGresaka::NeispravanParametar; return false;
										}
									 i++;
									}
									komanda=Komande::PomjeriJednoMjesto;
									smjer=Smjerovi::Dolje;
									return true;
								}
								else if(unesena_komanda.at(i+1)=='D' || unesena_komanda.at(i+1)=='L'){
									i++;
									char znak=unesena_komanda.at(i);
									if(i+1>=int(unesena_komanda.length())){
										komanda=Komande::PomjeriJednoMjesto;
										if(znak=='D') smjer=Smjerovi::DoljeDesno;
										else smjer=Smjerovi::DoljeLijevo;
										return true;
									}
									else if(unesena_komanda.at(i+1)==' '){
										i++;
										while(i<int(unesena_komanda.length())){
											if(unesena_komanda.at(i)!=' '){
												greska=KodoviGresaka::NeispravanParametar; return false;
											}
										 i++;
										}
										komanda=Komande::PomjeriJednoMjesto;
										if(znak=='D')smjer=Smjerovi::DoljeDesno;
										else smjer=Smjerovi::DoljeLijevo;
										return true;
									}
									else{
										greska=KodoviGresaka::NeispravanParametar; return false;
									}
								}
								else{
									greska=KodoviGresaka::NeispravanParametar; return false;
								}
							}
						case 'L':
							if(i+1>=int(unesena_komanda.length())){
								komanda=Komande::PomjeriJednoMjesto;
								smjer=Smjerovi::Lijevo;
								return true;
							}
							else if(unesena_komanda.at(i+1)==' '){
								i++;
								while(i<int(unesena_komanda.length())){
									if(unesena_komanda.at(i)!=' '){
										greska=KodoviGresaka::NeispravanParametar; return false;
									}
									 i++;
								}
								komanda=Komande::PomjeriJednoMjesto;
								smjer=Smjerovi::Lijevo;
								return true;
							}
							else{
								greska=KodoviGresaka::NeispravanParametar; return false;
							}
						case 'G':
							if(i+1>=int(unesena_komanda.length())){
								komanda=Komande::PomjeriJednoMjesto;
								smjer=Smjerovi::Gore;
								return true;
							}
							else if(unesena_komanda.at(i+1)==' '){
								i++;
								while(i<int(unesena_komanda.length())){
									if(unesena_komanda.at(i)!=' '){
										greska=KodoviGresaka::NeispravanParametar; return false;
									}
									i++;
								}
								komanda=Komande::PomjeriJednoMjesto;
								smjer=Smjerovi::Gore;
								return true;
							}
							else if(unesena_komanda.at(i+1)=='L' || unesena_komanda.at(i+1)=='D'){
								i++;
								char znak=unesena_komanda.at(i);
								if(i+1>=int(unesena_komanda.length())){
									komanda=Komande::PomjeriJednoMjesto;
									if(znak=='D') smjer=Smjerovi::GoreDesno;
									else smjer=Smjerovi::GoreLijevo;
									return true;
								}
								else if(unesena_komanda.at(i+1)==' '){
									i++;
									while(i<int(unesena_komanda.length())){
										if(unesena_komanda.at(i)!=' '){
											greska=KodoviGresaka::NeispravanParametar; return false;
										}
										i++;
									}
									komanda=Komande::PomjeriJednoMjesto;
									if(znak=='D') smjer=Smjerovi::GoreDesno;
									else smjer=Smjerovi::GoreLijevo;
									return true;
								}
								else{
									greska=KodoviGresaka::NeispravanParametar; return false;
								}
							}
							else{
								greska=KodoviGresaka::NeispravanParametar; return false;
							}
						default:
							greska=KodoviGresaka::NeispravanParametar;
							return false;
					}
				}
				else if(unesena_komanda.at(i)=='O'){
					i++;
					while(i<int(unesena_komanda.length())){
						if(unesena_komanda.at(i)!=' '){
							greska=KodoviGresaka::SuvisanParametar;
							return false;
						}
						i++;
					}
					komanda=Komande::PrikaziOkolinu;
					return true;
				}
				else if(unesena_komanda.at(i)=='>')	 return PravilnoUneseneKoordinate(komanda, x, y, greska, unesena_komanda, i);
			}
		}
		greska=KodoviGresaka::PogresnaKomanda;
		return false;
	}
	greska=KodoviGresaka::PogresnaKomanda;
	return false;
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer=Smjerovi::Gore, int p_x=0, int p_y=0){
	switch(komanda){
		case Komande::KreirajIgru:{
			bool stop(false);
			int broj_polja(0);
			std::vector<std::vector<int>> mine(0);
			for(;;){
				std::string unos;
				std::cout << "Unesite broj polja: ";
				std::getline(std::cin, unos);
				int i(0);
				while(i<int(unos.length()) && unos.at(i)==' ') i++;
				if(i>=unos.length()) std::cout << "Greska, unesite ponovo!\n";
				else if(unos.at(i)>='0' && unos.at(i)<='9'){
					while(i<int(unos.length()) && unos.at(i)>='0' && unos.at(i)<='9'){
						broj_polja=(broj_polja*10)+(unos.at(i)-'0');
						i++;
					}
					bool NijeDobroUneseno=false;
					i++;
					while(i<int(unos.length())){
						if(unos.at(i)!=' '){
							NijeDobroUneseno=true;
							std::cout << "Greska, unesite ponovo!\n";
							break;
						} 
						i++;
					}
					if(broj_polja==0){
						std::cout << "Greska, unesite ponovo!\n";
						NijeDobroUneseno=true;
					} 
					if(!NijeDobroUneseno){
						std::cout << "Unesite pozicije mina: ";
						for(;;){
							std::getline(std::cin, unos);
							i=0;
							while(i<int(unos.length()) && unos.at(i)==' ') i++;
							if(i>=int(unos.length())) std::cout <<"Greska, unesite ponovo!\n";
							else if(unos.at(i)=='('){
								i++;
								while(i<int(unos.length()) && unos.at(i)==' ') i++;
								if(i>=int(unos.length())) std::cout <<"Greska, unesite ponovo!\n";
								else if(unos.at(i)>='0' && unos.at(i)<='9'){
									int broj_x(0);
									while(i<int(unos.length()) && unos.at(i)>='0' && unos.at(i)<='9'){
										broj_x=(broj_x*10)+(unos.at(i)-'0');
									i++;
									}
									if(i>=int(unos.length())) std::cout << "Greska, unesite ponovo!\n";
									else if(broj_x>=broj_polja) std::cout << "Greska, unesite ponovo!\n";
									else if(unos.at(i)==' ' || unos.at(i)==','){
										if(unos.at(i)==' '){
											while(i<int(unos.length()) && unos.at(i)==' ') i++;
											if(i>=int(unos.length())) std::cout <<"Greska, unesite ponovo!\n";	
										}
										if(unos.at(i)==','){
											i++;
											while(i<int(unos.length()) && unos.at(i)==' ') i++;
											if(i>=int(unos.length())) std::cout <<"Greska, unesite ponovo!\n";
											else if(unos.at(i)>='0' && unos.at(i)<='9'){
												int broj_y(0);
												while(i<int(unos.length()) && unos.at(i)>='0' && unos.at(i)<='9'){
													broj_y=(broj_y*10)+(unos.at(i)-'0');
													i++;
												}
												if(i>=int(unos.length())) std::cout << "Greska, unesite ponovo!\n";
												else if(broj_y>=broj_polja || (broj_y==0 && broj_x==0)) std::cout << "Greska, unesite ponovo!\n";
												else if(unos.at(i)==' ' || unos.at(i)==')'){
													if(unos.at(i)==' '){
														while(i<int(unos.length()) && unos.at(i)==' ') i++;
														if(i>=int(unos.length())) std::cout << "Greska, unesite ponovo!\n";
													}
													if(unos.at(i)==')'){
														i++;
														if(i>=int(unos.length())){
																mine.resize(mine.size()+1);
																mine.at(mine.size()-1).push_back(broj_x);
																mine.at(mine.size()-1).push_back(broj_y);
														}
														else if(unos.at(i)==' '){
															NijeDobroUneseno=false;
															while(i<int(unos.length())){
																if(unos.at(i)!=' '){
																	NijeDobroUneseno=true;
																	std::cout << "Greska, unesite ponovo!\n";
																	break;
																} 
																i++;
															}
															if(!NijeDobroUneseno){
																mine.resize(mine.size()+1);
																mine.at(mine.size()-1).push_back(broj_x);
																mine.at(mine.size()-1).push_back(broj_y);
															}
															
														}
														else std::cout << "Greska, unesite ponovo!\n";
													}
													else std::cout << "Greska, unesite ponovo!\n";
												}
												else std::cout << "Greska, unesite ponovo!\n";
											}
											else std::cout << "Greska, unesite ponovo!\n";
										}
										else std::cout << "Greska, unesite ponovo!\n";
									}
									else std::cout << "Greska, unesite ponovo!\n";
								}
								else std::cout << "Greska, unesite ponovo!\n";
							}
							else if(unos.at(i)=='.'){
								i++;
								while(i<int(unos.length())){
									if(unos.at(i)!=' '){
										std::cout <<"Greska, unesite ponovo!\n";
										break;
									}
									i++;
								}
								if(i>=int(unos.length())){
									stop=true;
									break;	
								} 
							}
							else std::cout <<"Greska, unesite ponovo!\n";
						}
					}
				}
				else std::cout << "Greska, unesite ponovo!\n";
				if(stop) break;
			}
			polja=KreirajIgru(broj_polja, mine);
		}
		break;
		case Komande::PrikaziOkolinu:{
			std::vector<std::vector<int>> okolina=PrikaziOkolinu(polja, x, y);
			for(int i=0; i<int(okolina.size()); i++){
				for(int j=0; j<int(okolina.at(i).size()); j++){
					std::cout << okolina.at(i).at(j) << " ";
				}
				std::cout << std::endl;
			}
		}
		break;
		case Komande::PomjeriJednoMjesto:{
			Status igra=Idi(polja,x,y,p_smjer);
			std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")\n";
			if(igra==Status::KrajPoraz || igra==Status::KrajPobjeda){
				komanda=Komande::ZavrsiIgru;
				if(igra==Status::KrajPoraz) std::cout << "Nagazili ste na minu\n";
				else if(igra==Status::KrajPobjeda) std::cout << "Bravo, obisli ste sva sigurna polja\n";
				throw std::runtime_error ("Igra zavrsena\n");
			}
			break;
		}
		case Komande::ZavrsiIgru:{
			std::cout << "Dovidjenja!\n";
			break;
		}
		case Komande::Blokiraj:{
			BlokirajPolje(polja, p_x, p_y);
			break;
		}
		case Komande::Deblokiraj:{
			DeblokirajPolje(polja, p_x, p_y);
			break;
		}
		case Komande::PomjeriDalje:{
			Status igra=Idi(polja,x,y,p_x,p_y);
			std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")\n";
			if(igra==Status::KrajPoraz || igra==Status::KrajPobjeda){
				komanda=Komande::ZavrsiIgru;
				if(igra==Status::KrajPoraz) std::cout << "Nagazili ste na minu\n";
				else if(igra==Status::KrajPobjeda) std::cout << "Bravo, obisli ste sva sigurna polja\n";
				throw std::runtime_error ("Igra zavrsena\n");
			}
			break;
		}
	}
}

int main ()
{	
	Tabla IgracaTabla(0, (std::vector<Polje>(0)));
	Komande komanda;
	Smjerovi smjer;
	int x(0), y(0), novi_x, novi_y;
	KodoviGresaka greska;
	for(;;){	
	 	std::cout << "Unesite komandu: ";
	 	if(UnosKomande(komanda, smjer, novi_x, novi_y, greska)){
	 		try{
	 			if(komanda==Komande::KreirajIgru || komanda==Komande::ZavrsiIgru || komanda==Komande::PrikaziOkolinu) 
	 				IzvrsiKomandu(komanda, IgracaTabla, x, y);
	 			else if(komanda==Komande::PomjeriDalje || komanda==Komande::Blokiraj || komanda==Komande::Deblokiraj) 
	 				IzvrsiKomandu(komanda, IgracaTabla, x, y, smjer, novi_x, novi_y);
	 			else IzvrsiKomandu(komanda, IgracaTabla, x, y, smjer);
	 		}
	 		catch(std::domain_error g){
	 			std::cout << g.what() << std::endl;
	 		}
	 		catch(std::runtime_error g){
	 			std::cout << g.what() << std::endl;
	 			break;
	 		}
	 		catch(std::out_of_range g){
	 			std::cout << g.what() << std::endl;
	 		}
	 		catch(std::logic_error g){
	 			std::cout << g.what() << std::endl;
	 		}
	 		if(komanda==Komande::ZavrsiIgru) break;
	 	}
	 	else PrijaviGresku(greska);
	}
	return 0;
}
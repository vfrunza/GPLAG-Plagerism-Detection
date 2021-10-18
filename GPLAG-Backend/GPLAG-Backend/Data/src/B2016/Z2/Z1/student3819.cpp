/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
enum class Polje {Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina};
enum class Smjerovi {GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo};
enum class Status {NijeKraj, KrajPoraz, KrajPobjeda};
enum class KodoviGresaka {PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar};
enum class Komande { PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru};
typedef std::vector<std::vector<Polje>> Tabla;
Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine);
void BlokirajPolje(Tabla &polja, int x, int y);
void DeblokirajPolje(Tabla &polja, int x, int y);
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer);
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y);
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y);
//dodatne prototipovi f-ja
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska);
//void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x=0, int p_y=0);

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine) {
	Tabla tabla(n, std::vector<Polje>(n));
	int x(0), y(0);
	for(int i(0); i<n; i++) 
		for(int j(0); j<n; j++)
			tabla[i][j]=Polje::Prazno;
	
	for(int i(0); i<mine.size(); i++) {
		if(mine[i].size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
			x=mine[i][0];
			y=mine[i][1];
			if(x<0 || x > n-1 || y<0 || y > n-1) throw std::domain_error("Ilegalne pozicije mina");
			tabla[x][y]=Polje::Mina;
	}
	return tabla;
}
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y) {
	std::vector<std::vector<int>> matrica(3, std::vector<int>(3));
	if(x<0 || y<0 || x>polja.size()-1 || y>polja.size()-1) {					//ne fercera ako su dvocifreni
		/*char x1= x+'0';                                                         // koristit std::to_string
    	char y1= y+'0';
    	std::string izuzetak = "Polje (,) ne postoji";
    	izuzetak.insert(izuzetak.begin()+7, x1);
    	izuzetak.insert(izuzetak.begin()+9, y1);*/
		std::string izuzetak;
    	izuzetak = "Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji";
		throw std::domain_error(izuzetak);
	}
	for(int i(x-1); i<x+1; i++) {
		for(int j(y-1); j<y+1; j++) {
			
		}
	}
	return matrica;
}
void BlokirajPolje(Tabla &polja, int x, int y) {
	if(x<0 || y<0 || x>polja.size()-1 || y>polja.size()-1) {
    	std::string izuzetak;
    	izuzetak = "Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji";
		throw std::domain_error(izuzetak);
	}
	if(polja[x][y]==Polje::Prazno) polja[x][y]=Polje::BlokiranoPrazno;
	else if(polja[x][y]==Polje::Posjeceno) polja[x][y]=Polje::BlokiranoPosjeceno;
	else if(polja[x][y]==Polje::Mina) polja[x][y]=Polje::BlokiranoMina;
}
void DeblokirajPolje(Tabla &polja, int x, int y) {
	if(x<0 || y<0 || x>polja.size()-1 || y>polja.size()-1) {
		std::string izuzetak;
    	izuzetak = "Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji";
		throw std::domain_error(izuzetak);
	}
	if(polja[x][y]==Polje::BlokiranoPrazno) polja[x][y]=Polje::Prazno;
	else if(polja[x][y]==Polje::BlokiranoPosjeceno) polja[x][y]=Polje::Posjeceno;
	else if(polja[x][y]==Polje::BlokiranoMina) polja[x][y]=Polje::Mina;
}
void PrijaviGresku(KodoviGresaka kodgreske) {
	switch(kodgreske) {
		case KodoviGresaka::PogresnaKomanda:
			std::cout << "Nerazumljiva komanda!\n";
			break;
		case KodoviGresaka::NedostajeParametar:
			std::cout << "Komanda trazi parametar koji nije naveden!\n";
			break;
		case KodoviGresaka::NeispravanParametar:
			std::cout << "Parametar komande nije ispravan!\n";
			break;
		case KodoviGresaka::SuvisanParametar:
			std::cout << "Zadan je suvisan parametar nakon komande!\n";
			break;
	}
}
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer) {
	if(smjer==Smjerovi::Gore) {													//ako bude zezalo u slucaju da se posalje pogresna trenutna pozicija dodati uslov ili 
		if(x-1<0) throw std::out_of_range("Izlazak van igrace table");
		else if(polja[x-1][y]==Polje::BlokiranoPrazno || polja[x-1][y]==Polje::BlokiranoPosjeceno || polja[x-1][y]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		polja[x][y]=Polje::Posjeceno;
		x=x-1;
	}
	else if(smjer==Smjerovi::Dolje) {
		if(x+1==polja.size()) throw std::out_of_range("Izlazak van igrace table");
		else if(polja[x+1][y]==Polje::BlokiranoPrazno || polja[x+1][y]==Polje::BlokiranoPosjeceno || polja[x+1][y]==Polje::BlokiranoMina) throw std::logic_error("Blokirno polje");
		polja[x][y]=Polje::Posjeceno;
		x=x+1;
	}
	else if(smjer==Smjerovi::Lijevo) {
		if(y-1<0) throw std::out_of_range("Izlazak van igrace table");
		else if(polja[x][y-1]==Polje::BlokiranoPrazno || polja[x][y-1]==Polje::BlokiranoPosjeceno || polja[x][y-1]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		polja[x][y]=Polje::Posjeceno;
		y=y-1;
	}
	else if(smjer==Smjerovi::Desno) {
		if(y+1==polja.size()) throw std::out_of_range("Izlazak van igrace table");
		else if(polja[x][y+1]==Polje::BlokiranoPrazno || polja[x][y+1]==Polje::BlokiranoPosjeceno || polja[x][y+1]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		polja[x][y]=Polje::Posjeceno;
		y=y+1;
	}
	else if(smjer==Smjerovi::GoreLijevo) {
		if(x-1<0 || y-1<0) throw std::out_of_range("Izlazak van igrace table");
		else if(polja[x-1][y-1]==Polje::BlokiranoPrazno || polja[x-1][y-1]==Polje::BlokiranoPosjeceno || polja[x-1][y-1]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		polja[x][y]=Polje::Posjeceno;
		x=x-1;
		y=y-1;
	}
	else if(smjer==Smjerovi::GoreDesno) {
		if(x-1<0 || y+1==polja.size()) throw std::out_of_range("Izlazak van igrace table");
		else if(polja[x-1][y+1]==Polje::BlokiranoPrazno || polja[x-1][y+1]==Polje::BlokiranoPosjeceno || polja[x-1][y+1]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		polja[x][y]=Polje::Posjeceno;
		x=x-1;
		y=y+1;
	}
	else if(smjer==Smjerovi::DoljeLijevo) {
		if(x+1==polja.size() || y-1<0) throw std::out_of_range("Izlazak van igrace table");
		else if(polja[x+1][y-1]==Polje::BlokiranoPrazno || polja[x+1][y-1]==Polje::BlokiranoPosjeceno || polja[x+1][y-1]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		polja[x][y]=Polje::Posjeceno;
		x=x+1;
		y=y-1;
	}
	else if(smjer==Smjerovi::DoljeDesno) {
		if(x+1==polja.size() || y+1==polja.size()) throw std::out_of_range("Izlazak van igrace table");
		else if(polja[x+1][y+1]==Polje::BlokiranoPrazno || polja[x+1][y+1]==Polje::BlokiranoPosjeceno || polja[x+1][y+1]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		polja[x][y]=Polje::Posjeceno;
		x=x+1;
		y=y+1;
	}
	if(polja[x][y]==Polje::Mina) {
		for(int i(0); i<polja.size(); i++) 
			for(int j(0); j<polja.size(); j++) 
				polja[i][j]=Polje::Prazno;
		return Status::KrajPoraz;
	}
	int temp(0);
	for(int i(0); i<polja.size(); i++) 
		for(int j(0); j<polja.size(); j++) 
			if(polja[i][j]==Polje::Prazno)
				temp=1;
	if(temp==0) return Status::KrajPobjeda;
	return Status::NijeKraj;
}
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y) {
	if(novi_x<0 || novi_y<0 || novi_x>=polja.size() || novi_y>=polja.size()) throw std::out_of_range("Izlazak van igrace table");
	//if(x<0 || y<0 || x>=polja.size() || y>=polja.size()) throw std::out_of_range("Izlazak van igrace table");
	else if(polja[novi_x][novi_y]==Polje::BlokiranoPrazno || polja[novi_x][novi_y]==Polje::BlokiranoPosjeceno || polja[novi_x][novi_y]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
	//else if(polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoPosjeceno || polja[x][y]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");

	polja[x][y]=Polje::Posjeceno;
	x=novi_x;
	y=novi_y;
	if(polja[x][y]==Polje::Mina) {
		for(int i(0); i<polja.size(); i++) 
			for(int j(0); j<polja.size(); j++)
				polja[i][j]=Polje::Prazno;
		return Status::KrajPoraz;
	}
	int temp(0);
	for(int i(0); i<polja.size(); i++) {
		for(int j(0); j<polja.size(); j++) {
			if(polja[i][j]==Polje::Prazno) temp=1;
		}
	}
	if(temp==0) return Status::KrajPobjeda;
	return Status::NijeKraj;
}
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska) {
	std::string string;
	std::string pomocni;
	int a(0), b(0);
	std::getline(std::cin, string);
	int i(0);
	if(string[0]==' ') {
		while(string[i]==' ') i++;
		while(i<string.length()) {
			pomocni.push_back(string[i]);
			i++;
		}
		string=pomocni;
		pomocni.clear();
		i=0;
	}
	if(string[0]=='K') {
		if(string.length()==1) {
			komanda=Komande::KreirajIgru;
			return true;
		}
		else {
			if(string[1]!=' ') {
				greska=KodoviGresaka::SuvisanParametar;
				return false;
			}
			else {
				int s(1);
				while(s<string.length()) {
					if(string[s]!=' ') {
						greska=KodoviGresaka::SuvisanParametar;
						return false;
					}
					s++;
				}
				if(s==string.length()) {
					komanda=Komande::KreirajIgru;
					return true;
				}
			}
		}
	}
	else if(string[0]=='Z') {
		if(string.length()==1) {
			komanda=Komande::ZavrsiIgru;
			return true;
		}
		else {
			if(string[1]!=' ') {
				greska=KodoviGresaka::SuvisanParametar;
				return false;
			}
			else {
				int s(1);
				while(s<string.length()) {
					if(string[s]!=' ') {
						greska=KodoviGresaka::SuvisanParametar;
						return false;
					}
					s++;
				}
				if(s==string.length()) {
					komanda=Komande::ZavrsiIgru;
					return true;
				}
			}
		}
	}
	else if(string[0]=='P' && string[1]=='O') {
		if(string.length()==2) {
			komanda=Komande::PrikaziOkolinu;
			return true;
		}
		else {
			if(string[2]!=' ') {
				greska=KodoviGresaka::SuvisanParametar;
				return false;
			}
			else {
				int s(2);
				while(s<string.length()) {
					if(string[s]!=' ') {
						greska=KodoviGresaka::SuvisanParametar;
						return false;
					}
					s++;
				}
				if(s==string.length()) {
					komanda=Komande::PrikaziOkolinu;
					return true;
				}
			}
		}
	}
	else if(string[0]=='D' || string[0]=='B') {
		if(string[1]==' ') {
			int s(1);
			while(string[s]==' ') s++;
			if(string[s]>='0' && string[s]<='9') {
				while(string[s]!=' ' && (string[s]>='0' && string[s]<='9')) {
					a=a*10+string[s]-'0';
					s++;
					if(!(string[s]>='0' && string[s]<='9') && string[s]!=' ') {
						greska=KodoviGresaka::NedostajeParametar;
						a=0;
						return false;
					}
				}
				if(string[s]==' ') {
					while(string[s]==' ') s++;
				}
				if(string[s]>='0' && string[s]<='9') {
					while(string[s]!=' ' && (string[s]>='0' && string[s]<='9')) {
						b=b*10+string[s]-'0';
						s++;
						/*if(!(string[s]>='0' && string[s]<='9') && string[s]!=' ') {
							greska=KodoviGresaka::NedostajeParametar;
							b=0;
							return false;
						}*/
					}
					if(string[s]==' ') {
						while(string[s]==' ') s++;
						if(s==string.length()) {
							if(string[0]=='D') {
								komanda=Komande::Deblokiraj;
								x=a;
								y=b;
								return true;
							}
							else {
								komanda=Komande::Blokiraj;
								x=a;
								y=b;
								return true;
							}
						}
						else {
							greska=KodoviGresaka::SuvisanParametar;
							return false;
						}
					}
					else if(s==string.length()) {
						if(string[0]=='D') {
							komanda=Komande::Deblokiraj;
							x=a;
							y=b;
							return true;
						}
						else {
							komanda=Komande::Blokiraj;
							x=a;
							y=b;
							return true;
						}
					}
					else {
						greska=KodoviGresaka::SuvisanParametar;
						return false;
					}
				}
				else {
					greska=KodoviGresaka::NedostajeParametar;
					return false;
				}
			}
			else {
				greska=KodoviGresaka::NedostajeParametar;
				return false;
			}
		}
		else if(string[1]>='0' && string[1]<='9') {																//odavde ako nema razmaka izmedju
			int s(1);
			while(string[s]!=' ' && (string[s]>='0' && string[s]<='9')) {
				a=a*10+string[s]-'0';
				s++;
				if(!(string[s]>='0' && string[s]<='9') && string[s]!=' ') {
					greska=KodoviGresaka::NedostajeParametar;
					a=0;
					return false;
				}
			}
			if(string[s]==' ') {
				while(string[s]==' ') s++;
			}
			if(string[s]>='0' && string[s]<='9') {
				while(string[s]!=' ' && (string[s]>='0' && string[s]<='9')) {
					b=b*10+string[s]-'0';
					s++;
					/*if(!(string[s]>='0' && string[s]<='9') && string[s]!=' ') {
						greska=KodoviGresaka::NedostajeParametar;
						b=0;
						return false;
					}*/
				}
				if(string[s]==' ') {
					while(string[s]==' ') s++;
					if(s==string.length()) {
						if(string[0]=='D') {
							komanda=Komande::Deblokiraj;
							x=a;
							y=b;
							return true;
						}
						else {
							komanda=Komande::Blokiraj;
							x=a;
							y=b;
							return true;
						}
					}
					else {
						greska=KodoviGresaka::SuvisanParametar;
						return false;
					}
				}
				else if(s==string.length()) {
					if(string[0]=='D') {
						komanda=Komande::Deblokiraj;
						x=a;
						y=b;
						return true;
					}
					else {
						komanda=Komande::Blokiraj;
						x=a;
						y=b;
						return true;
					}
				}
				else {
					greska=KodoviGresaka::SuvisanParametar;
					return false;
				}
			}
			else {
				greska=KodoviGresaka::NedostajeParametar;
				return false;
			}
		}
		else {
			greska=KodoviGresaka::NedostajeParametar;
			return false;
		}
	}
	else if(string[0]=='P' && string[1]=='>') {
		if(string[2]==' ') {
			int s(2);
			while(string[s]==' ') s++;
			if(string[s]>='0' && string[s]<='9') {
				while(string[s]!=' ' && (string[s]>='0' && string[s]<='9')) {
					a=a*10+string[s]-'0';
					s++;
					if(!(string[s]>='0' && string[s]<='9') && string[s]!=' ') {
						greska=KodoviGresaka::NedostajeParametar;
						a=0;
						return false;
					}
				}
				if(string[s]==' ') {
					while(string[s]==' ') s++;
				}
				if(string[s]>='0' && string[s]<='9') {
					while(string[s]!=' ' && (string[s]>='0' && string[s]<='9')) {
						b=b*10+string[s]-'0';
						s++;
						/*if(!(string[s]>='0' && string[s]<='9') && string[s]!=' ') {
							greska=KodoviGresaka::NedostajeParametar;
							b=0;
							return false;
						}*/
					}
					if(string[s]==' ') {
						while(string[s]==' ') s++;
						if(s==string.length()) {
							komanda=Komande::PomjeriDalje;
							x=a;
							y=b;
							return true;
						}
						else {
							greska=KodoviGresaka::SuvisanParametar;
							return false;
						}
					}
					else if(s==string.length()){
						komanda=Komande::PomjeriDalje;
						x=a;
						y=b;
						return true;
					}
					else {
						greska=KodoviGresaka::SuvisanParametar;
						return false;
					}
				}
				else {
					greska=KodoviGresaka::NedostajeParametar;
					return false;
				}
			}
			else {
				greska=KodoviGresaka::NedostajeParametar;
				return false;
			}
		}
		else if(string[2]>='0' && string[2]<='9') {	                            //ako nema razmaka izmedju komande i parametra
			int s(2);
			while(string[s]!=' ' && (string[s]>='0' && string[s]<='9')) {
				a=a*10+string[s]-'0';
				s++;
				if(!(string[s]>='0' && string[s]<='9') && string[s]!=' ') {
					greska=KodoviGresaka::NedostajeParametar;
					a=0;
					return false;
				}
			}
			if(string[s]==' ') {
				while(string[s]==' ') s++;
			}
			if(string[s]>='0' && string[s]<='9') {
				while(string[s]!=' ' && (string[s]>='0' && string[s]<='9')) {
					b=b*10+string[s]-'0';
					s++;
					/*if(!(string[s]>='0' && string[s]<='9') && string[s]!=' ') {
						greska=KodoviGresaka::NedostajeParametar;
						b=0;
						return false;
					}*/
				}
				if(string[s]==' ') {
					while(string[s]==' ') s++;
					if(s==string.length()) {
						komanda=Komande::PomjeriDalje;
						x=a;
						y=b;
						return true;
					}
					else {
						greska=KodoviGresaka::SuvisanParametar;
						return false;
					}
				}
				else if(s==string.length()) {
					komanda=Komande::PomjeriDalje;
					x=a;
					y=b;
					return true;
				}
				else {
					greska=KodoviGresaka::SuvisanParametar;
					return false;
				}
			}
			else {
				greska=KodoviGresaka::NedostajeParametar;
				return false;
			}
		}
		else {
			greska=KodoviGresaka::NedostajeParametar;
			return false;
		}
	}
	else if(string[0]=='P' && string[1]=='1') {
		if(string[2]==' ') {													//ako ima razmak izmedju komande i parametra
			int s(2);
			while(string[s]==' ') s++;
			if(!(string[s]>='A' && string[s]<='Z')) {							//ima komanda ali iza nije slovo
				greska=KodoviGresaka::NedostajeParametar;
				return false;
			}
			else {
				if(s==string.length()) {
					greska=KodoviGresaka::NedostajeParametar;
					return false;
				}
			}
			std::string strkomanda;
			while(s<string.length()){
				strkomanda.push_back(string[s]);
				s++;
			}
			int j(0);
			std::string suzeno;
			while(j<strkomanda.length()) {
				if(strkomanda[j]=='G' || strkomanda[j]=='D' || strkomanda[j]=='L' || strkomanda[j]=='o' || strkomanda[j]==' ') 
					suzeno.push_back(strkomanda[j++]);
				else {
					greska=KodoviGresaka::NedostajeParametar;
					return false;
				}
			}
			j=0;
			strkomanda.clear();
			while(j<suzeno.length()) {
				if(suzeno[j]!=' ') strkomanda.push_back(suzeno[j]);
				j++;
			}
			if(strkomanda=="G") {
				smjer=Smjerovi::Gore;
				komanda=Komande::PomjeriJednoMjesto;
				return true;
			}
			else if(strkomanda=="L") {
				smjer=Smjerovi::Lijevo;
				komanda=Komande::PomjeriJednoMjesto;
				return true;
			}
			else if(strkomanda=="D") {
				smjer=Smjerovi::Desno;
				komanda=Komande::PomjeriJednoMjesto;
				return true;
			}
			else if(strkomanda=="Do") {
				smjer=Smjerovi::Dolje;
				komanda=Komande::PomjeriJednoMjesto;
				return true;
			}
			else if(strkomanda=="GL") {
				smjer=Smjerovi::GoreLijevo;
				komanda=Komande::PomjeriJednoMjesto;
				return true;
			}
			else if(strkomanda=="GD") {
				smjer=Smjerovi::GoreDesno;
				komanda=Komande::PomjeriJednoMjesto;
				return true;
			}
			else if(strkomanda=="DoD") {
				smjer=Smjerovi::DoljeDesno;
				komanda=Komande::PomjeriJednoMjesto;
				return true;
			}
			else if(strkomanda=="DoL") {
				smjer=Smjerovi::DoljeLijevo;
				komanda=Komande::PomjeriJednoMjesto;
				return true;
			}
			else {
                greska=KodoviGresaka::SuvisanParametar;
                return false;
			}
		}
		else {																	//ako nema razmaka izmedju komande i parametra
			if(string[2]=='G') {
				if(string.length()==3) {
					smjer=Smjerovi::Gore;
					komanda=Komande::PomjeriJednoMjesto;
					return true;
				}
				else if(string[3]=='L') {
					if(string.length()==4) {
						smjer=Smjerovi::GoreLijevo;
						komanda=Komande::PomjeriJednoMjesto;
						return true;
					}
					else {
						int i(4);
						if(string[i]==' ') {
							while(string[i]==' ') i++;
							if(i==string.length()) {							//mozda bude zezalo
								smjer=Smjerovi::GoreLijevo;
								komanda=Komande::PomjeriJednoMjesto;
								return true;
							}
							else {
								greska=KodoviGresaka::SuvisanParametar;
								return false;
							}
						}
						else {
							greska=KodoviGresaka::SuvisanParametar;
							return false;
						}
					}
				}
				else if(string[3]=='D') {
					if(string.length()==4) {
						smjer=Smjerovi::GoreDesno;
						komanda=Komande::PomjeriJednoMjesto;
						return true;
					}
					else {
						int i(4);
						if(string[i]==' ') {
							while(string[i]==' ') i++;
							if(i==string.length()) {							//mozda bude zezalo
								smjer=Smjerovi::GoreDesno;
								komanda=Komande::PomjeriJednoMjesto;
								return true;
							}
							else {
								greska=KodoviGresaka::SuvisanParametar;
								return false;
							}
						}
						else {
							greska=KodoviGresaka::SuvisanParametar;
							return false;
						}
					}
				}
				else if(string[3]==' ') {
					int i(3);
					while(string[i]==' ') i++;
					if(i==string.length()) {							//mozda bude zezalo
						smjer=Smjerovi::Gore;
						komanda=Komande::PomjeriJednoMjesto;
						return true;
					}
					else {
						greska=KodoviGresaka::SuvisanParametar;
						return false;
					}
				}
				else {
					greska=KodoviGresaka::SuvisanParametar;
					return false;
				}
			}
			else if(string[2]=='L') {
				if(string.length()==3) {
					smjer=Smjerovi::Lijevo;
					komanda=Komande::PomjeriJednoMjesto;
					return true;
				}
				else {
					if(string[3]==' ') {
						int i(3);
						while(string[i]==' ') i++;
						if(i==string.length()) {
							smjer=Smjerovi::Lijevo;
							komanda=Komande::PomjeriJednoMjesto;
							return true;
						}
						else {
							greska=KodoviGresaka::SuvisanParametar;
							return false;
						}
					}
					else {
						greska=KodoviGresaka::SuvisanParametar;
						return false;
					}
				}
			}
			else if(string[2]=='D') {
				if(string.length()==3) {
					smjer=Smjerovi::Desno;
					komanda=Komande::PomjeriJednoMjesto;
					return true;
				}
				else if(string[3]==' ') {
					int i(3);
					while(string[i]==' ') i++;
					if(i==string.length()) {							//mozda bude zezalo
						smjer=Smjerovi::Desno;
						komanda=Komande::PomjeriJednoMjesto;
						return true;
					}
					else {
						greska=KodoviGresaka::SuvisanParametar;
						return false;
					}
				}
				else if(string[3]=='o') {
					if(string.length()==4) {
						smjer=Smjerovi::Dolje;
						komanda=Komande::PomjeriJednoMjesto;
						return true;
					}
					else if(string[4]==' ') {
						int i(4);
						while(string[i]==' ') i++;
						if(i==string.length()) {							//mozda bude zezalo
							smjer=Smjerovi::Dolje;
							komanda=Komande::PomjeriJednoMjesto;
							return true;
						}
						else {
							greska=KodoviGresaka::SuvisanParametar;
							return false;
						}
					}
					else if(string[4]=='L') {
						if(string.length()==5) {
							smjer=Smjerovi::DoljeLijevo;
							komanda=Komande::PomjeriJednoMjesto;
							return true;
						}
						else if(string[5]==' ') {
							int i(5);
							while(string[i]==' ') i++;
							if(i==string.length()) {							//mozda bude zezalo
								smjer=Smjerovi::DoljeLijevo;
								komanda=Komande::PomjeriJednoMjesto;
								return true;
							}
							else {
								greska=KodoviGresaka::SuvisanParametar;
								return false;
							}
						}
						else {
							greska=KodoviGresaka::SuvisanParametar;
							return false;
						}
					}
					else if(string[4]=='D') {
						if(string.length()==5) {
							smjer=Smjerovi::DoljeDesno;
							komanda=Komande::PomjeriJednoMjesto;
							return true;
						}
						else if(string[5]==' ') {
							int i(5);
							while(string[i]==' ') i++;
							if(i==string.length()) {							//mozda bude zezalo
								smjer=Smjerovi::DoljeDesno;
								komanda=Komande::PomjeriJednoMjesto;
								return true;
							}
							else {
								greska=KodoviGresaka::SuvisanParametar;
								return false;
							}
						}
						else {
							greska=KodoviGresaka::SuvisanParametar;
							return false;
						}
					}
					else {
						greska=KodoviGresaka::SuvisanParametar;
						return false;
					}
				}
				else {
					greska=KodoviGresaka::SuvisanParametar;
					return false;
				}
			}
		}
	}
	else {																		// ako ni komandu nije utrefio :-P, tu mu je i kraj
		greska=KodoviGresaka::PogresnaKomanda;
		return false;
	}
	return false;
}
void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer=Smjerovi::Gore, int p_x=0, int p_y=0) {
	std::vector<std::vector<int>> mine;
	std::vector<int> pomocni;
	std::string string;
	//Smjerovi smjer;
	Status status;
	if(komanda==Komande::KreirajIgru) {
		int n, x(0), y(0);
		std::cout << "Unesite broj polja: ";
		std::cin >> n;
		std::cout << "Unesite pozicije mina: ";
		do {
			std::getline(std::cin, string);
			if(string==".") break;
			int pogreska(0);
			for(int i(0); i<string.length(); i++) {
				if(!(string[i]=='(' || (string[i]>='0' && string[i]<='9') || string[i]==',' || string[i]==')')) {
					pogreska=1;
					break;
				}
			}
			if(pogreska==0) {
				int i(0);
				while(i<string.length()) {
					int k(1);
					if(string[0]!='(') {
						std::cout<< "Greska, unesite ponovo!\n";
						break;
					}
					if(!(string[k]>='0' && string[k]<='9')) {
						std::cout << "Greska, unesite ponovo!\n";
						break;
					}
					else {
						while(string[k]!=',' && (string[k]>='0' && string[k]<='9')) {
							x=x*10+string[k]-'0';
							k++;
							i=k;
							if(!(string[k]>='0' && string[k]<='9')) pogreska=1;
						}
					}
					if(string[i]==',') {
						i++;
						k++;
						if(!(string[k]>='0' && string[k]<='9')) {
							std::cout << "Greska, unesite ponovo!\n";
						}
						while(string[k]!=')' && (string[k]>='0' && string[k]<='9')){
							y=y*10+string[k]-'0';
							k++;
							i=k;
							if(!(string[k]>='0' && string[k]<='9')) pogreska=1;
						}
					}
					if(string[i]==')' && i==string.length()-1) {
						if(x<0 || y<0 || x>=n || y>=n) {
							std::cout << "Greska, unesite ponovo!\n";
							x=0;
							y=0;
						}
						else {
							pomocni.push_back(x);
							pomocni.push_back(y);
							mine.push_back(pomocni);
							pomocni.clear();
							x=0;
							y=0;
						}
					}
					else pogreska=1;
					i++;
				}
			}
			else if(pogreska==1){
				std::cout << "Greska, unesite ponovo!\n";
				x=0;
				y=0;
				pogreska=0;
			}
		}while(string!=".");
		try {
			polja=KreirajIgru(n,mine);
		}
		catch(std::domain_error izuzetak) {
			std::cout << izuzetak.what() << std::endl;
		}
	}
	else if(komanda==Komande::Blokiraj) {
		try {
			BlokirajPolje(polja, x, y);
		}
		catch(std::domain_error izuzetak) {
			std::cout << izuzetak.what() << std::endl;
		}
	}
	else if(komanda==Komande::Deblokiraj) {
		try{
			DeblokirajPolje(polja, x, y);
		}
		catch(std::domain_error izuzetak) {
			std::cout << izuzetak.what() << std::endl;
		}
	}
	else if(komanda==Komande::PomjeriJednoMjesto) {
		int a(x), b(y);
		try {
			status=Idi(polja, x, y, p_smjer);
			if(a!=x || b!=y) std::cout<< "Tekuca pozicija igraca je (" << x << "," << y << ")" << std::endl;
			if(status==Status::KrajPobjeda) {
				std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
				for(int i(0); i<polja.size(); i++) {
					for(int j(0); j<polja.size(); j++) {
						polja[i][j]=Polje::Prazno;
					}
				}
				throw std::runtime_error("Igra zavrsena");
			}
			else if(status==Status::KrajPoraz) {
				std::cout << "Nagazili ste na minu" << std::endl;
				for(int i(0); i<polja.size(); i++) {
					for(int j(0); j<polja.size(); j++) {
						polja[i][j]=Polje::Prazno;
					}
				}
				throw std::runtime_error("Igra zavrsena");
			}
		}
		catch(std::out_of_range izuzetak) {
			std::cout << izuzetak.what() << std::endl;
		}
		catch(std::logic_error izuzetak) {
			std::cout << izuzetak.what() << std::endl;
		}
	}
	else if(komanda==Komande::PomjeriDalje) {
		int a(0), b(0);
		try {
			status=Idi(polja, p_x, p_y, x, y);
			if(a!=x || b!=y) std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")" << std::endl;
			if(status==Status::KrajPobjeda) {
				std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
				for(int i(0); i<polja.size(); i++) {
					for(int j(0); j<polja.size(); j++) {
						polja[i][j]=Polje::Prazno;
					}
				}
				throw std::runtime_error("Igra zavrsena");
			}
			else if(status==Status::KrajPoraz) {
				std::cout << "Nagazili ste na minu" << std::endl;
				for(int i(0); i<polja.size(); i++) {
					for(int j(0); j<polja.size(); j++) {
						polja[i][j]=Polje::Prazno;
					}
				}
				throw std::runtime_error("Igra zavrsena");
			}
		}
		catch(std::out_of_range izuzetak) {
			std::cout << izuzetak.what() << std::endl;
		}
		catch(std::logic_error izuzetak) {
			std::cout << izuzetak.what() << std::endl;
		}
	}
	else if(komanda==Komande::PrikaziOkolinu) {
		std::vector<std::vector<int>> okolina(3, std::vector<int>(3));
		okolina=PrikaziOkolinu(polja, x, y);
		for(int i(0); i<okolina.size(); i++) {
			for(int j(0); j<okolina.size(); j++) {
				std::cout << okolina[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
	else if(komanda==Komande::ZavrsiIgru) {
		for(int i(0); i<polja.size(); i++) {
			for(int j(0); j<polja.size(); j++) {
				polja[i][j]=Polje::Prazno;
			}
		}
		throw std::runtime_error("Igra zavrsena");
	}
}
int main (){															//nema niko duzi :-)
	Tabla tabla;
	int x, y;
	Komande komanda;
	Smjerovi smjer;
	KodoviGresaka greska;
	bool jel=true;
	while(1) {
		try {
			std::cout << "Unesite komandu: ";
			jel=UnosKomande(komanda, smjer, x, y, greska);
			if(jel) IzvrsiKomandu(komanda, tabla, x, y);
			else PrijaviGresku(greska);
		}
		catch(...) {
			std::cout << "Dovidjenja!";
			return 0;
		}
	}
	return 0;
}
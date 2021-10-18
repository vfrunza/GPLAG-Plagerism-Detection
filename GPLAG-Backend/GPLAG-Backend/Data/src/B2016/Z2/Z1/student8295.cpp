/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

enum class Polje {
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno,BlokiranoMina
};
enum class Status {
	NijeKraj, KrajPoraz, KrajPobjeda	
};
enum class Smjerovi {
	GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo	
};
enum class KodoviGresaka {
	PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar	
};
enum class Komande {
	PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru	
};
typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine) {
	for(int i(0); i<mine.size(); i++) {
		if(mine[i].size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
	}
	for(int i(0); i<mine.size(); i++) {
		for(int j(0); j<mine[0].size(); j++) 
			if(mine[i][j]>=n || mine[i][j]<0) throw std::domain_error("Ilegalne pozicije mina");
	}
	Tabla rez;
	rez.resize(n);
	for(int i(0); i<rez.size(); i++) rez[i].resize(n);
	for(int i(0); i<rez.size(); i++) 
		for(int j(0); j<rez[0].size(); j++) rez[i][j]=Polje::Prazno;
	
	for(int i(0); i<rez.size(); i++) 
		for(int j(0); j<rez[0].size(); j++)
			for(int k(0); k<mine.size(); k++) 
				for(int l(0); l<mine[0].size()-1; l++) 
				if(i==mine[k][l] && j==mine[k][l+1]) rez[i][j]=Polje::Mina;
	return rez;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y) {
	if(x>polja.size()-1 || y>polja[0].size()-1) throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	std::vector<std::vector<int>> rez;
	rez.resize(3);
	int n(0);
	for(int i(x-1); i<x+2; i++) {
		for(int j(y-1); j<y+2; j++) {
			int brmina(0);
			if((i-1)>=(x-1)) {
				if(polja[i-1][j]==Polje::Mina) brmina++; }
			if((i+1)<=(polja.size()-1)) {
				if(polja[i+1][j]==Polje::Mina) brmina++; }
			if((j+1)<=(polja[0].size()-1)) {
				if(polja[i][j+1]==Polje::Mina) brmina++; }
			if((j-1)>=(y-1)) {
				if(polja[i][j-1]==Polje::Mina) brmina++; }
			if(((i-1)>=(x-1)) && ((j-1)>=(y-1))) {
				if(polja[i-1][j-1]==Polje::Mina) brmina++; }
			if(((j+1)<=(polja[0].size()-1)) && ((i+1)<=(polja.size()-1))) {
				if(polja[i+1][j+1]==Polje::Mina) brmina++; }
			if(((i-1)>=(x-1)) && ((j+1)<=(polja[0].size()-1))) {
				if(polja[i-1][j+1]==Polje::Mina) brmina++; }
			if(((i+1)<=(polja.size()-1)) && ((j-1)>=(y-1))) {
				if(polja[i+1][j-1]==Polje::Mina) brmina++; }
			rez[n].push_back(brmina);
		}
		n++;
	}
	return rez;
}

void BlokirajPolje(Tabla &polja, int x, int y) {
	if(x>polja.size()-1 || y>polja[0].size()-1) throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	else if(polja[x][y]==Polje::Prazno) polja[x][y]=Polje::BlokiranoPrazno;
	else if(polja[x][y]==Polje::Posjeceno) polja[x][y]=Polje::BlokiranoPosjeceno;
	else if(polja[x][y]==Polje::Mina) polja[x][y]=Polje::BlokiranoMina;
}

void DeblokirajPolje(Tabla &polja, int x, int y) {
	if(x>polja.size()-1 || y>polja[0].size()-1) throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	else if(polja[x][y]==Polje::BlokiranoPrazno) polja[x][y]=Polje::Prazno;
	else if(polja[x][y]==Polje::BlokiranoPosjeceno) polja[x][y]=Polje::Posjeceno;
	else if(polja[x][y]==Polje::BlokiranoMina) polja[x][y]=Polje::Mina;
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer) {
	polja[x][y]=Polje::Posjeceno;
	if(smjer==Smjerovi::Gore) {
		if((x-1)<0) throw std::out_of_range("Izlazak van igrace table");
		else if(polja[x-1][y]==Polje::BlokiranoPosjeceno || polja[x-1][y]==Polje::BlokiranoPrazno || polja[x-1][y]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		x--;
	}
	if(smjer==Smjerovi::Dolje) {
		if((x+1)>=polja.size()) throw std::out_of_range("Izlazak van igrace table");
		else if(polja[x+1][y]==Polje::BlokiranoPosjeceno || polja[x+1][y]==Polje::BlokiranoPrazno || polja[x+1][y]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		x++;
	}
	if(smjer==Smjerovi::Desno) {
		if((y+1)>=polja[0].size()) throw std::out_of_range("Izlazak van igrace table");
		else if(polja[x][y+1]==Polje::BlokiranoPosjeceno || polja[x][y+1]==Polje::BlokiranoPrazno || polja[x][y+1]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		y++;
	}
	if(smjer==Smjerovi::Lijevo) {
		if((y-1)<0) throw std::out_of_range("Izlazak van igrace table");
		else if(polja[x][y-1]==Polje::BlokiranoPosjeceno || polja[x][y-1]==Polje::BlokiranoPrazno || polja[x][y-1]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		y--;
	}
	if(smjer==Smjerovi::GoreLijevo) {
		if((x-1)<0 || (y-1)<0) throw std::out_of_range("Izlazak van igrace table");
		else if(polja[x-1][y-1]==Polje::BlokiranoPosjeceno || polja[x-1][y-1]==Polje::BlokiranoPrazno || polja[x-1][y-1]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		x--;
		y--;
	}
	if(smjer==Smjerovi::GoreDesno) {
		if((x-1)<0 || (y+1)>=polja[0].size()) throw std::out_of_range("Izlazak van igrace table");
		else if(polja[x-1][y+1]==Polje::BlokiranoPosjeceno || polja[x-1][y+1]==Polje::BlokiranoPrazno || polja[x-1][y+1]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		x--;
		y++;
	}
	if(smjer==Smjerovi::DoljeLijevo) {
		if((x+1)>=polja.size() || (y-1)<0) throw std::out_of_range("Izlazak van igrace table");
		else if(polja[x+1][y-1]==Polje::BlokiranoPosjeceno || polja[x+1][y-1]==Polje::BlokiranoPrazno || polja[x+1][y-1]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		x++;
		y--;
	}
	if(smjer==Smjerovi::DoljeDesno) {
		if((x+1)>=polja.size() || (y+1)>=polja[0].size()) throw std::out_of_range("Izlazak van igrace table");
		else if(polja[x+1][y+1]==Polje::BlokiranoPosjeceno || polja[x+1][y+1]==Polje::BlokiranoPrazno || polja[x+1][y+1]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		x++;
		y++;
	}
	if(polja[x][y]==Polje::Mina) {
		for(int i(0); i<polja.size(); i++) 
			for(int j(0); j<polja[0].size(); j++)
				polja[i][j]=Polje::Prazno;
		
		return Status::KrajPoraz;
	}
	bool prazno=true;
	for(int i(0); i<polja.size(); i++)
		for(int j(0); j<polja[0].size(); j++)
			if(polja[i][j]==Polje::Prazno) prazno=false;
	if(prazno) return Status::KrajPobjeda;
	return Status::NijeKraj;
}
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y) {
	if(novi_x<0 || novi_y<0 || novi_x>polja.size() || novi_y>polja[0].size()) throw std::out_of_range("Izlazak van igrace table");
	if(polja[novi_x][novi_y]==Polje::BlokiranoPosjeceno || polja[novi_x][novi_y]==Polje::BlokiranoPrazno || polja[novi_x][novi_y]==Polje::BlokiranoMina) throw std::domain_error("Blokirano polje");
	if(polja[x][y]==Polje::BlokiranoPosjeceno || polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoMina) throw std::domain_error("Blokirano polje");

	x=novi_x;
	y=novi_y;
	
	if(polja[x][y]==Polje::Mina) {
		for(int i(0); i<polja.size(); i++) 
			for(int j(0); j<polja[0].size(); j++)
				polja[i][j]=Polje::Prazno;
				
		return Status::KrajPoraz;
	}
	bool prazno=true;
	for(int i(0); i<polja.size(); i++)
		for(int j(0); j<polja[0].size(); j++)
			if(polja[i][j]==Polje::Prazno) prazno=false;
	if(prazno) return Status::KrajPobjeda;
	return Status::NijeKraj;
}

void PrijaviGresku(KodoviGresaka greskica) {
	
	if(greskica==KodoviGresaka::PogresnaKomanda) std::cout<<"Nerazumljiva komanda!"<<std::endl;
	else if(greskica==KodoviGresaka::NedostajeParametar) std::cout<<"Komanda trazi parametar koji nije naveden!"<<std::endl;
	else if(greskica==KodoviGresaka::NeispravanParametar) std::cout<<"Parametar komande nije ispravan!"<<std::endl;
	else if(greskica==KodoviGresaka::SuvisanParametar) std::cout<<"Zadan je suvisan parametar nakon komande!"<<std::endl;
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska) {
	std::string s;
	std::getline(std::cin,s);
	for(int i(0); i<s.length(); i++) {
		while (s[i]==' ') i++;
		if(s[i]=='K') {
			i++;
			while (s[i]==' ' && i<s.length()) i++;
			if(i==s.length()) {
				komanda=Komande::KreirajIgru;
				return true;
			}
			else {
				greska=KodoviGresaka::NeispravanParametar;
				return false;
			}
		}
		else if(s[i]=='Z') {
			i++;
			while (s[i]==' ' && i<s.length()) i++;
			if(i==s.length()) {
				komanda=Komande::ZavrsiIgru;
				return true;
			}
			else {
				greska=KodoviGresaka::NeispravanParametar;
				return false;
			}
		}
		else if(s[i]=='P') {
			i++;
			if(s[i]=='O') {
				i++;
				while (s[i]==' ' && i<s.length()) i++;
				if(i==s.length()) {
					komanda=Komande::PrikaziOkolinu;
					return true;
				}
				else {
					greska=KodoviGresaka::NeispravanParametar;
					return false;
				}
			}
			else if(s[i]=='1') {
				i++;
				while (s[i]==' ' && i<s.length()) i++;
				if(s[i]=='G') {
					i++;
					if(s[i]=='D') {
						i++;
						while (s[i]==' ' && i<s.length()) i++;
						if(i==s.length()){
						komanda=Komande::PomjeriJednoMjesto;
						smjer=Smjerovi::GoreDesno;
						return true;
						}
						else {
							greska=KodoviGresaka::NeispravanParametar;
							return false;
						}
					}
					else {
						while (s[i]==' ' && i<s.length()) i++;
						if(i==s.length()){
						komanda=Komande::PomjeriJednoMjesto;
						smjer=Smjerovi::Gore;
						return true;
						}
						else {
							greska=KodoviGresaka::NeispravanParametar;
							return false;
						}
					}
				}
				else if(s[i]=='L') {
					i++;
					while (s[i]==' ' && i<s.length()) i++;
					if(i==s.length()){
					komanda=Komande::PomjeriJednoMjesto;
					smjer=Smjerovi::Lijevo;
					return true;
					}
					else {
						greska=KodoviGresaka::NeispravanParametar;
						return false;
					}
				}
				else if(s[i]=='D') {
					i++;
					if(s[i]=='o') {
						i++;
						if(s[i]=='D') {
							i++;
							while (s[i]==' ' && i<s.length()) i++;
							if(i==s.length()){
							komanda=Komande::PomjeriJednoMjesto;
							smjer=Smjerovi::DoljeDesno;
							return true;
							}
							else {
								greska=KodoviGresaka::NeispravanParametar;
								return false;
							}
						}
						else if(s[i]=='L') {
							i++;
							while (s[i]==' ' && i<s.length()) i++;
							if(i==s.length()){
							komanda=Komande::PomjeriJednoMjesto;
							smjer=Smjerovi::DoljeLijevo;
							return true;
							}
							else {
								greska=KodoviGresaka::NeispravanParametar;
								return false;
							}
						}
						else {
							while (s[i]==' ' && i<s.length()) i++;
							if(i==s.length()){
							komanda=Komande::PomjeriJednoMjesto;
							smjer=Smjerovi::Dolje;
							return true;
							}
							else {
								greska=KodoviGresaka::NeispravanParametar; 
								return false;
							}
						}
					}
					else {
						while (s[i]==' ' && i<s.length()) i++;
						if(i==s.length()){
						komanda=Komande::PomjeriJednoMjesto;
						smjer=Smjerovi::Desno;
						return true;
						}
						else {
							greska=KodoviGresaka::NeispravanParametar;
							return false;
						}
					}
				}
				
				if(i==s.length()) {
					greska=KodoviGresaka::NedostajeParametar;
					return false;
				}
				else {
					greska=KodoviGresaka::SuvisanParametar;
					return false;
				}
			}
			else if(s[i]=='>') {
				i++;
				while (s[i]==' ' && i<s.length()) i++;
				if(s[i]>='0' && s[i]<='9') {
					int poc=i;
					while (i<s.length() && s[i]>='0' && s[i]<='9') i++;
					x=std::stoi(s.substr(poc,i-poc));
					while (s[i]==' ' && i<s.length()) i++;
					if(i==s.length()) {
						greska=KodoviGresaka::NedostajeParametar;
						return false;
					}
					else { poc=i;
					while (i<s.length() && s[i]>='0' && s[i]<='9') i++;
					y=std::stoi(s.substr(poc,i-poc)); 
						komanda=Komande::PomjeriDalje;
						return true;
					}
				}
				if(i==s.length()) {
					greska=KodoviGresaka::NedostajeParametar; 
					return false;
				}
				else {
					greska=KodoviGresaka::SuvisanParametar;
					return false;
				}
			}
			else {
			greska=KodoviGresaka::PogresnaKomanda;
			return false;
			}
		}
		else if(s[i]=='B') {
			i++;
				while (s[i]==' ' && i<s.length()) i++;
				if(s[i]>='0' && s[i]<='9') {
					int poc(i);
					while (i<s.length() && s[i]>='0' && s[i]<='9') i++;
					x=std::stoi(s.substr(poc,i-poc));
					while (s[i]==' ' && i<s.length()) i++;
					if(i==s.length()) {
						greska=KodoviGresaka::NedostajeParametar;
						return false;
					}
					else { poc=i;
					while (i<s.length() && s[i]>='0' && s[i]<='9') i++;
					y=std::stoi(s.substr(poc,i-poc)); 
						komanda=Komande::Blokiraj;
						return true;
					}
				}
				if(i==s.length()) {
					greska=KodoviGresaka::NedostajeParametar; 
					return false;
				}
				else {
					greska=KodoviGresaka::SuvisanParametar;
					return false;
				}
			}
		else if(s[i]=='D') {
			i++;
				while (s[i]==' ' && i<s.length()) i++;
				if(s[i]>='0' && s[i]<='9') {
					int poc(i);
					while (i<s.length() && s[i]>='0' && s[i]<='9') i++;
					x=std::stoi(s.substr(poc,i-poc));
					while (s[i]==' ' && i<s.length()) i++;
					if(i==s.length()) {
						greska=KodoviGresaka::NedostajeParametar;
						return false;
					}
					else { poc=i;
					while (i<s.length() && s[i]>='0' && s[i]<='9') i++;
					y=std::stoi(s.substr(poc,i-poc)); 
						komanda=Komande::Deblokiraj;
						return true;
					}
				}
				if(i==s.length()) {
					greska=KodoviGresaka::NedostajeParametar; 
					return false;
				}
				else {
					greska=KodoviGresaka::SuvisanParametar;
					return false;
				}
			}
			else {
			greska=KodoviGresaka::PogresnaKomanda;
			return false;
		}
	}
}
bool IspravanUnos(std::string s, int &x1, int &y1) {
	int i(0);
	if(i<s.length() && s[i]=='(') i++;
	else return false;
	int poc(i);
	if(i<s.length() && s[i]>='0' && s[i]<='9')
		while (i<s.length() && s[i]>='0' && s[i]<='9') i++;
	else return false;
	x1=std::stoi(s.substr(poc,i-poc));
	if(i<s.length() && s[i]==',') i++;
	else return false;
	poc=i;
	if(i<s.length() && s[i]>='0' && s[i]<='9') 
		while (i<s.length() && s[i]>='0' && s[i]<='9') i++;
		else return false;
		y1=std::stoi(s.substr(poc,i-poc));
		if(i<s.length() && s[i]==')') i++;
		else return false;
		if(i==s.length()) return true;
		else return false;
}
void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer=Smjerovi::Gore, int p_x=0, int p_y=0) {
		if(komanda==Komande::KreirajIgru) {
			int n;
			std::cout<<"Unesite broj polja: ";
			std::cin>>n;
			std::cin.clear();
			std::cin.ignore(10000,'\n');
			std::cout<<"Unesite pozicije mina: ";
			std::vector<std::vector<int>> mine;
			int index(0);
			while (1) {
				greska: std::string pom;
				std::getline(std::cin, pom);
				if(pom==std::string(".")) {
					break;
					index--;
				}
				int x1,y1;
				if(IspravanUnos(pom,x1,y1)) {
					if(x1<0 || y1>n) {
						std::cout<<"Greska, unesite ponovo!"<<std::endl;
						goto greska;
					}
					mine.resize(index+1);
					mine[index].push_back(x1);
					mine[index].push_back(y1);
					index++;
				}
				if(IspravanUnos(pom,x1,y1)==false) {
					std::cout<<"Greska, unesite ponovo!"<<std::endl;
				}
			}
			polja=KreirajIgru(n,mine);
		}
		if(komanda==Komande::PomjeriJednoMjesto) {
			Status nst=Idi(polja,x,y,p_smjer);
			std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
			if(nst==Status::KrajPobjeda) {
				std::cout<<"Bravo, obisli ste sva sigurna polja";
				for(int i(0); i<polja.size(); i++) 
				for(int j(0); j<polja[0].size(); j++)
				polja[i][j]=Polje::Prazno;
				throw std::runtime_error("Igra zavrsena");
			}
			else if(nst==Status::KrajPoraz) {
				std::cout<<"Nagazili ste na minu";
				for(int i(0); i<polja.size(); i++) 
				for(int j(0); j<polja[0].size(); j++)
				polja[i][j]=Polje::Prazno;
				throw std::runtime_error("Igra zavrsena");
			}
		}
		if(komanda==Komande::PomjeriDalje) {
		try{	Status nst1=Idi(polja,x,y,p_x,p_y);
			std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
				if(nst1==Status::KrajPobjeda) {
				std::cout<<"Bravo, obisli ste sva sigurna polja";
				for(int i(0); i<polja.size(); i++) 
				for(int j(0); j<polja[0].size(); j++)
				polja[i][j]=Polje::Prazno;
				throw std::runtime_error("Igra zavrsena");
			}
				else if(nst1==Status::KrajPoraz) {
				std::cout<<"Nagazili ste na minu";
				for(int i(0); i<polja.size(); i++) 
				for(int j(0); j<polja[0].size(); j++)
				polja[i][j]=Polje::Prazno;
				throw std::runtime_error("Igra zavrsena");
			}
		} catch(std::domain_error iz) {
			std::cout<<iz.what()<<std::endl;
		}
		}
		if(komanda==Komande::ZavrsiIgru) {
			for(int i(0); i<polja.size(); i++) 
				for(int j(0); j<polja[0].size(); j++)
					polja[i][j]=Polje::Prazno;
			throw std::runtime_error("Igra zavrsena");
		}
		if(komanda==Komande::Blokiraj) {
			try{
				BlokirajPolje(polja,x,y);
			} catch(std::domain_error izuzetak) {
				std::cout<<izuzetak.what();
			}
		} 
		if(komanda==Komande::Deblokiraj) {
			try {
				DeblokirajPolje(polja,x,y);
			} catch(std::domain_error izuzetak) {
				std::cout<<izuzetak.what();
			}
		}
		if(komanda==Komande::PrikaziOkolinu) {
				try {
					std::vector<std::vector<int>> okolina = PrikaziOkolinu(polja,x,y);
					for(int i(0); i<okolina.size(); i++) {
						for(int j(0); j<okolina[i].size(); j++) 
							std::cout<<okolina[i][j]<<" ";
						std::cout<<std::endl;
					}
				} catch(std::domain_error izuzetak) {
					std::cout<<izuzetak.what();
				}
		}
}
int main ()
{
	try {
		Komande komanda;
		Tabla polja;
		int x(0),y(0),x1(0),y1(0);
		Smjerovi p_smjer;
		KodoviGresaka greska;
			while (1) {
				std::cout<<"Unesite komandu: ";
				if(UnosKomande(komanda,p_smjer,x1,y1,greska))
				IzvrsiKomandu(komanda,polja,x,y,p_smjer,x1,y1);
				}
		}
		catch(std::runtime_error izuzetak) {
		
		}
		std::cout<<"Dovidjenja!";

	return 0;
}
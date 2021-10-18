/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <cstdlib>

enum class Polje { Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina };
enum class Smjerovi { GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo };
enum class Status { NijeKraj, KrajPoraz, KrajPobjeda };
enum class KodoviGresaka { PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar };
enum class Komande { PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru };

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine) {
	Tabla ploca(n, std::vector<Polje>(n, Polje::Prazno));
	
	for(auto vek : mine) {
		if(vek.size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
		if(vek[0]<0 || vek[0]>=n || vek[1]<0 || vek[1]>=n) throw std::domain_error("Ilegalne pozicije mina");
		ploca[vek[0]][vek[1]]=Polje::Mina;
	}
	
	return ploca;
}

bool DaLiPripadaTabli(const Tabla &polja, int x, int y) {
	if(x<0 || x>=polja.size() || y<0 || y>=polja.size()) return 0;
	return 1;
}

int BrojMinaUSusjedstvu(const Tabla &polja, int x, int y) {
	if(!(DaLiPripadaTabli(polja, x, y))) return 0;
	int broj(0);
	for(int i=x-1; i<x+2; i++) {
		for(int j=y-1; j<y+2; j++) {
			if(DaLiPripadaTabli(polja, i, j)) if(polja[i][j]==Polje::Mina) broj++;
		}
	}
	if(polja[x][y]==Polje::Mina) broj--;
	return broj;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y) {
	if(!DaLiPripadaTabli(polja, x, y)) throw std::domain_error("Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji");
	std::vector<std::vector<int>>v(3, std::vector<int>(3));
	
	for(int i=x-1; i<x+2; i++) {
		for(int j=y-1; j<y+2; j++) {
			v[i+1-x][j+1-y]=BrojMinaUSusjedstvu(polja, i, j);
		}
	}
	return v;
}

void BlokirajPolje(Tabla &polja, int x, int y) {
	if(!DaLiPripadaTabli(polja, x, y)) throw std::domain_error("Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji");
	
	if(polja[x][y]==Polje::Posjeceno) polja[x][y]=Polje::BlokiranoPosjeceno;
	else if(polja[x][y]==Polje::Prazno) polja[x][y]=Polje::BlokiranoPrazno;
	else if(polja[x][y]==Polje::Mina) polja[x][y]=Polje::BlokiranoMina;
}

void DeblokirajPolje(Tabla &polja, int x, int y) {
	if(!DaLiPripadaTabli(polja, x, y)) throw std::domain_error("Polje (" + std::string{char(x+'0')} + "," + std::string{char(y+'0')} + ") ne postoji");
	
	if(polja[x][y]==Polje::BlokiranoPosjeceno) polja[x][y]=Polje::Posjeceno;
	else if(polja[x][y]==Polje::BlokiranoPrazno) polja[x][y]=Polje::Prazno;
	else if(polja[x][y]==Polje::BlokiranoMina) polja[x][y]=Polje::Mina;
}

void OcistiTablu(Tabla &polja) {
	for(int i=0; i<polja.size(); i++) {
		for(int j=0; j<polja.size(); j++) polja[i][j]=Polje::Prazno;
	}
}

bool NemaPraznih(Tabla &polja) {
	for(int i=0; i<polja.size(); i++) {
		for(int j=0; j<polja.size(); j++) if(polja[i][j]==Polje::Prazno || polja[i][j]==Polje::BlokiranoPrazno) return 0;
	}
	return 1;
}

Status Kretanje(Tabla &polja, int &stari_x, int &stari_y, int novi_x, int novi_y) {
	if(!DaLiPripadaTabli(polja, novi_x, novi_y)) throw std::out_of_range("Izlazak van igrace table");
	if(polja[novi_x][novi_y]==Polje::BlokiranoPosjeceno || polja[novi_x][novi_y]==Polje::BlokiranoPrazno || polja[novi_x][novi_y]==Polje::BlokiranoMina) {
		throw std::logic_error("Blokirano polje");
	}
	if(polja[novi_x][novi_y]==Polje::Mina) {
		stari_x=novi_x; stari_y=novi_y;
		OcistiTablu(polja);
		return Status::KrajPoraz;
	}
	polja[stari_x][stari_y]=Polje::Posjeceno;
	polja[novi_x][novi_y]=Polje::Posjeceno;
	stari_x=novi_x; stari_y=novi_y;
	if(NemaPraznih(polja)) return Status::KrajPobjeda;
	return Status::NijeKraj;
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer) {
	int a(x), b(y);
	if(smjer==Smjerovi::Gore) a-=1;
	else if(smjer==Smjerovi::GoreLijevo) { a-=1; b-=1; }
	else if(smjer==Smjerovi::GoreDesno) { a-=1; b+=1; }
	else if(smjer==Smjerovi::Lijevo)  b-=1; 
	else if(smjer==Smjerovi::Desno) b+=1; 
	else if(smjer==Smjerovi::Dolje)  a+=1; 
	else if(smjer==Smjerovi::DoljeLijevo) { a+=1; b-=1; }
	else if(smjer==Smjerovi::DoljeDesno) { a+=1; b+=1; }
	return Kretanje(polja, x, y, a, b);
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y) {
	return Kretanje(polja, x, y, novi_x, novi_y);
}

void PrijaviGresku(KodoviGresaka greska) {
	if(greska==KodoviGresaka::PogresnaKomanda) std::cout << "Nerazumljiva komanda!\n";
	else if(greska==KodoviGresaka::NedostajeParametar) std::cout << "Komanda trazi parametar koji nije naveden!\n";
	else if(greska==KodoviGresaka::NeispravanParametar) std::cout << "Parametar komande nije ispravan!\n";
	else std::cout << "Zadan je suvisan parametar nakon komande!\n";
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &prvi, int &drugi, KodoviGresaka &greska) {
	std::string s;

	char c=std::getchar(); if(c=='\n') c=std::getchar();
	while(c==' ') c=std::getchar();
	while(c!='\n' && c!=' ') {
		s+=c;
		c=std::getchar();
	}
	
  	if(s=="P1") {
  		if(c=='\n') { greska=KodoviGresaka::NedostajeParametar; return false; }
		while(c==' ') c=std::getchar();
		s.clear();
		while(c!='\n') {
			s+=c;
			c=std::getchar();
		}
		if(s=="GL") { smjer=Smjerovi::GoreLijevo; komanda=Komande::PomjeriJednoMjesto; return true; }
		else if(s=="G") { smjer=Smjerovi::Gore; komanda=Komande::PomjeriJednoMjesto; return true; }
		else if(s=="GD") { smjer=Smjerovi::GoreDesno; komanda=Komande::PomjeriJednoMjesto; return true; }
		else if(s=="D") { smjer=Smjerovi::Desno; komanda=Komande::PomjeriJednoMjesto; return true; }
		else if(s=="L") { smjer=Smjerovi::Lijevo; komanda=Komande::PomjeriJednoMjesto; return true; }
		else if(s=="DoL") { smjer=Smjerovi::DoljeLijevo; komanda=Komande::PomjeriJednoMjesto; return true; }
		else if(s=="Do") { smjer=Smjerovi::Dolje; komanda=Komande::PomjeriJednoMjesto; return true; }
		else if(s=="DoD") { smjer=Smjerovi::DoljeDesno; komanda=Komande::PomjeriJednoMjesto; return true; }
		if(s.size()==0) { greska=KodoviGresaka::NedostajeParametar; return false; }
		greska=KodoviGresaka::NeispravanParametar; return false;
	}
	else if(s=="P>") {
		if(c=='\n') { greska=KodoviGresaka::NedostajeParametar; return false; }
		int a=0, b=0; bool ima=false;
		while(c==' ') c=std::getchar(); 
		if(c<'0' || c>'9') { greska=KodoviGresaka::NeispravanParametar; return false; }
		while(c>='0' && c<='9') { a*=10; a+=c-'0'; ima=true; c=std::getchar(); }
		if(!ima) { greska=KodoviGresaka::NedostajeParametar; return false; }
		ima=false;
		while(c==' ') { c=std::getchar(); ima=true; }
		if(!ima) { greska=KodoviGresaka::NedostajeParametar; return false; }
		if(c<'0' || c>'9') { greska=KodoviGresaka::NeispravanParametar; return false; }
		ima=false;
		while(c>='0' && c<='9') { b*=10; b+=c-'0'; ima=true; c=std::getchar(); }
		if(!ima) { greska=KodoviGresaka::NedostajeParametar; return false; }
		if(c!='\n') { greska=KodoviGresaka::SuvisanParametar; return false; }
		prvi=a; drugi=b; komanda=Komande::PomjeriDalje; return true;
		
	} 
	else if(s=="B") {
	  	if(c=='\n') { greska=KodoviGresaka::NedostajeParametar; return false; }
		int a=0, b=0; bool ima=false;
		while(c==' ') c=std::getchar(); 
		if(c<'0' || c>'9') { greska=KodoviGresaka::NeispravanParametar; return false; }
		while(c>='0' && c<='9') { a*=10; a+=c-'0'; ima=true; c=std::getchar(); }
		if(!ima) { greska=KodoviGresaka::NedostajeParametar; return false; }
		ima=false;
		while(c==' ') { c=std::getchar(); ima=true; }
		if(!ima) { greska=KodoviGresaka::NedostajeParametar; return false; }
		if(c<'0' || c>'9') { greska=KodoviGresaka::NeispravanParametar; return false; }
		ima=false;
		while(c>='0' && c<='9') { b*=10; b+=c-'0'; ima=true; c=std::getchar(); }
		if(!ima) { greska=KodoviGresaka::NedostajeParametar; return false; }
		if(c!='\n') { greska=KodoviGresaka::SuvisanParametar; return false; }
		prvi=a; drugi=b; komanda=Komande::Blokiraj; return true;
		
	}
	else if(s=="D") {
		if(c=='\n') { greska=KodoviGresaka::NedostajeParametar; return false; }
		int a=0, b=0; bool ima=false;
		while(c==' ') c=std::getchar(); 
		if(c<'0' || c>'9') { greska=KodoviGresaka::NeispravanParametar; return false; }
		while(c>='0' && c<='9') { a*=10; a+=c-'0'; ima=true; c=std::getchar(); }
		if(!ima) { greska=KodoviGresaka::NedostajeParametar; return false; }
		ima=false;
		while(c==' ') { c=std::getchar(); ima=true; }
		if(!ima) { greska=KodoviGresaka::NedostajeParametar; return false; }
		if(c<'0' || c>'9') { greska=KodoviGresaka::NeispravanParametar; return false; }
		ima=false;
		while(c>='0' && c<='9') { b*=10; b+=c-'0'; ima=true; c=std::getchar(); }
		if(!ima) { greska=KodoviGresaka::NedostajeParametar; return false; }
		if(c!='\n') { greska=KodoviGresaka::SuvisanParametar; return false; }
		prvi=a; drugi=b; komanda=Komande::Deblokiraj; return true;
	}
	else if(s=="PO") {
		while(c==' ') c=std::getchar();
		if(c!='\n') { greska=KodoviGresaka::SuvisanParametar; return false; }
		komanda=Komande::PrikaziOkolinu;
		return true;
	}
	else if(s=="Z") {
		while(c==' ') c=std::getchar();
		if(c!='\n') { greska=KodoviGresaka::SuvisanParametar; return false; }
		komanda=Komande::ZavrsiIgru;
		return true;
	}
	else if(s=="K") {
		while(c==' ') c=std::getchar();
		if(c!='\n') { greska=KodoviGresaka::SuvisanParametar; return false; }
		komanda=Komande::KreirajIgru;
		return true;
	}
	else {
		if(s.length()>1) {
			if(s[0]=='P' && (s[1]=='1' || s[1]=='>' || s[1]=='O')) greska=KodoviGresaka::SuvisanParametar;
			else if(s[0]=='B' || s[0]=='Z' || s[0]=='D' || s[0]=='K') greska=KodoviGresaka::SuvisanParametar;
			else greska=KodoviGresaka::PogresnaKomanda;
		}
		else greska=KodoviGresaka::PogresnaKomanda;
	}
	return false;
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer=Smjerovi::Gore, int p_x=0, int p_y=0) {
	
	if(polja.size()==0 && komanda!=Komande::KreirajIgru) { PrijaviGresku(KodoviGresaka::PogresnaKomanda); return; }
	try {
		if(komanda==Komande::Blokiraj) {
			BlokirajPolje(polja, p_x, p_y);
		}
		else if(komanda==Komande::Deblokiraj) {
			DeblokirajPolje(polja, p_x, p_y);
		}
		else if(komanda==Komande::PrikaziOkolinu) {
			auto matrica=PrikaziOkolinu(polja, x, y);
			for(auto a : matrica) {
				for(auto b : a) std::cout << b << " ";
				std::cout << "\n";
			}
		}
		else if(komanda==Komande::ZavrsiIgru) {
			OcistiTablu(polja); throw std::runtime_error("Igra zavrsena");
		}
		else if(komanda==Komande::PomjeriJednoMjesto) {
			auto st=Idi(polja, x, y, p_smjer);
			std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")\n";
			if(st==Status::KrajPoraz) {
				std::cout << "Nagazili ste na minu\n";
				OcistiTablu(polja); throw std::runtime_error("Igra zavrsena");
			}
			else if(st==Status::KrajPobjeda) {
				std::cout << "Bravo, obisli ste sva sigurna polja";
				OcistiTablu(polja); throw std::runtime_error("Igra zavrsena");
			}
		}
		else if(komanda==Komande::PomjeriDalje) {
			auto st=Idi(polja, x, y, p_x, p_y);
			std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")\n";
			if(st==Status::KrajPoraz) {
				std::cout << "Nagazili ste na minu\n";
				OcistiTablu(polja); throw std::runtime_error("Igra zavrsena");
			}
			else if(st==Status::KrajPobjeda) {
				std::cout << "Bravo, obisli ste sva sigurna polja\n";
				OcistiTablu(polja); throw std::runtime_error("Igra zavrsena");
			}
		}
		else {
			std::cout << "Unesite broj polja: ";
			int n; std::cin >> n;
			std::vector<std::vector<int>>mine;
			std::cout << "Unesite pozicije mina: ";
			std::string s;
			while(1) {
				bool ima=false; int a=0, b=0; char c=std::getchar(); if(c=='\n') c=std::getchar();  if(c=='.') break;
				if(c!='(') { std::cout << "Greska, unesite ponovo!\n"; std::cin.ignore(10000, '\n'); continue; }
				c=std::getchar();
				while(c>='0' && c<='9') { a*=10; a+=c-'0'; ima=true;  c=std::getchar(); }
				if(!ima || a<0 || a>=n) { std::cout << "Greska, unesite ponovo!\n"; std::cin.ignore(10000, '\n'); continue; }
				if(c!=',') { std::cout << "Greska, unesite ponovo!\n"; std::cin.ignore(10000, '\n'); continue; }
				c=std::getchar();
				while(c>='0' && c<='9') { b*=10; b+=(int)c-'0'; ima=true;  c=std::getchar(); }
				if(!ima || b<0 || b>=n || a+b==0) { std::cout << "Greska, unesite ponovo!\n"; std::cin.ignore(10000, '\n'); continue; }
				if(c!=')')  { std::cout << "Greska, unesite ponovo!\n"; std::cin.ignore(10000, '\n'); continue; }
				c=std::getchar();
		
				std::vector<int>red={a,b}; mine.push_back(red);
			}
			polja=KreirajIgru(n, mine);
		}
	}
	catch(std::out_of_range izuzetak){std::cout << izuzetak.what() << "\n"; }
	catch(std::domain_error izuzetak){std::cout << izuzetak.what() << "\n"; }
	catch(std::logic_error izuzetak) {std::cout << izuzetak.what() << "\n"; }
}

int main () {
	int x=0, y=0; Tabla polja;
	try { for(;;) {
		std::cout << "Unesite komandu: ";
		Komande k; Smjerovi smjer; KodoviGresaka greska; int prvi, drugi;
		if(UnosKomande(k, smjer, prvi, drugi, greska)) {
			IzvrsiKomandu(k, polja, x, y, smjer, prvi, drugi);
		}
		else {
			PrijaviGresku(greska);
			if(greska==KodoviGresaka::SuvisanParametar || greska==KodoviGresaka::NeispravanParametar) { std::cin.clear(); std::cin.ignore(10000, '\n'); }
		}
	}
	}
	catch(...) {
		std::cout << "Dovidjenja!";
		return 0;
	}
}
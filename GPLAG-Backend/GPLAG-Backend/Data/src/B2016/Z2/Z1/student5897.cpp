#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <complex>

enum class Polje {Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina};

enum class Smjerovi { GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo};

enum class Status { NijeKraj, KrajPoraz, KrajPobjeda } status;

enum class KodoviGresaka { PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar };

enum class Komande { PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru };

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine);
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y);
void BlokirajPolje(Tabla &polja, int x, int y);
void DeblokirajPolje(Tabla &polja, int x, int y);
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer);
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y);
Status PromijeniStatus(Tabla &polja, int x, int y);
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y);
KodoviGresaka IspitajGresku(std::string unos);

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine) {
	Tabla tabla(n, std::vector<Polje> (n, Polje(0)));
	
	for(int i=0; i<mine.size(); i++) {
		if(mine[i].size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
	}
	
	for(int i=0; i<mine.size(); i++) {
		int a=mine[i][0];
		int b=mine[i][1];
		if(a>=n || b>=n) throw std::domain_error("Ilegalne pozicije mina");
		tabla[a][b]=Polje(2);
	}
	
	//tabla[0][0]=Polje::Posjeceno;
	return tabla;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y) {
	
	if(x>=polja.size() || y>=polja[0].size() || x<0 || y<0) {
		std::string s="Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji";
		throw std::domain_error(s); 
	}
	
	std::vector<std::vector<int>> matrica(3, std::vector<int> (3));
	
	int k1=x, y2=y, kraj1=x, kraj2=y, i(0);
	
	if(k1-1>=0) k1=x-1;
	if(y2-1>=0) y2=y-1;
	
	if(kraj1+1<polja.size()) kraj1=x+1;
	if(kraj2+1<polja[0].size()) kraj2=y+1;
	
	for(; k1<=kraj1; k1++) {
		int j=0;
		for(int k2=y2; k2<=kraj2; k2++) {
			
			int m=k1, n=k1, a=k2, b=k2;
			if(k1-1>=0) m=k1-1;
			if(k1+1<polja.size()) n=k1+1;
			if(k2-1>=0) a=k2-1;
			if(k2+1<polja[0].size()) b=k2+1;
			int brojac_mina(0);
			for(int p=m; p<=n; p++) {
				for(int q=a; q<=b; q++) {
					
					if(p==k1 && q==k2) continue;
					if(polja[p][q]==Polje::Mina || polja[m][a]==Polje::BlokiranoMina) brojac_mina++;
				}
			}
			
			matrica[i][j]=brojac_mina; j++;
		}
		i++;
	}
	
	return matrica;
}

void BlokirajPolje(Tabla &polja, int x, int y) {
	
	if(x>=polja.size() || x<0 || y<0 || y>=polja[0].size()) {
		std::string s="Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji";
		throw std::domain_error(s);
	}
	
	if(polja[x][y]==Polje::Prazno) {  polja[x][y]=Polje::BlokiranoPrazno; }
	else if(polja[x][y]==Polje::Posjeceno) polja[x][y]=Polje::BlokiranoPosjeceno;
	else polja[x][y]=Polje::BlokiranoMina;
	
}

void DeblokirajPolje(Tabla &polja, int x, int y) {
	
	if(x>=polja.size() || y>=polja[0].size()) {
		std::string s="Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji";
		throw std::domain_error(s);
	}
	
	if(polja[x][y]==Polje(3)) polja[x][y]=Polje(0);
	else if(polja[x][y]==Polje(4)) polja[x][y]=Polje(1);
	else polja[x][y]=Polje(2);

}

void BlokiranoPolje(Tabla &polja, int x, int y) {
	if(polja[x][y]==Polje::BlokiranoPosjeceno || polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer) {
	
	BlokiranoPolje(polja, x, y);

	polja[x][y]=Polje::Posjeceno;
	
	if(smjer==Smjerovi::GoreLijevo && x>0 && y>0) {
		BlokiranoPolje(polja, x-1, x-1);
			x--; y--; }
			
	else if(smjer==Smjerovi::Gore && x>0) {
		BlokiranoPolje(polja, x-1, y);
		x--; }
		
	else if(smjer==Smjerovi::GoreDesno && x>0 && y<polja[0].size()-1) { 
		BlokiranoPolje(polja, x-1, y+1);
		x--; y++; }
	else if(smjer==Smjerovi::Desno && y<polja[0].size()-1) { BlokiranoPolje(polja, x, y+1); y++; }
	else if(smjer==Smjerovi::DoljeDesno && x<polja.size()-1 && y<polja[0].size()-1) { BlokiranoPolje(polja, x+1, y+1); x++; y++; }
	else if(smjer==Smjerovi::Dolje && x<polja.size()-1) { BlokiranoPolje(polja, x+1, y); x++; }
	else if(smjer==Smjerovi::DoljeLijevo && x<polja.size()-1 && y>0) { BlokiranoPolje(polja, x+1, y-1); x++; y--; }
	else if(smjer==Smjerovi::Lijevo && y>0) { BlokiranoPolje(polja, x, y-1); y--; }
	else {
		throw std::out_of_range("Izlazak van igrace table");
	}
	
	status=PromijeniStatus(polja, x, y);
	
	return status;
}

Status PromijeniStatus(Tabla &polja, int x, int y) {
	
	if(polja[x][y]==Polje::Mina)  {
		status=Status::KrajPoraz;
		
		for(int i=0; i<polja.size(); i++) {
			for(int j=0; j<polja[0].size(); j++) { 
				polja[i][j]=Polje::Prazno;
				return status;
			}
		}
	}
	
	//polja[x][y]=Polje::Posjeceno;
	bool ima_praznih=false;
	for(int i=0; i<polja.size(); i++) {
		for(int j=0; j<polja[i].size(); j++) {
			if(polja[i][j]==Polje::Prazno && i!=x && y!=j) { ima_praznih=true; break; }
		}
	}
	
	if(ima_praznih==false) status=Status::KrajPobjeda;
	else status=Status::NijeKraj;
	
	return status;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y) {
	
	if(novi_x>=polja.size() || novi_x<0 || novi_y>=polja[0].size() || novi_y<0) {
			polja[x][y]=Polje::Posjeceno;
		throw std::out_of_range("Izlazak van igrace table\n"); }
	
	if(polja[novi_x][novi_y]==Polje::BlokiranoPosjeceno || polja[novi_x][novi_y]==Polje::BlokiranoPrazno || polja[novi_x][novi_y]==Polje::BlokiranoMina) {
			polja[x][y]=Polje::Posjeceno;
		throw std::logic_error("Blokirano polje\n"); }
	
	polja[x][y]=Polje::Posjeceno;
	status=PromijeniStatus(polja, novi_x, novi_y);
	
	if(status==Status::NijeKraj) { 
		x=novi_x; y=novi_y; 
		polja[x][y]=Polje::Posjeceno;
	}
	
	if(status==Status::KrajPobjeda) { x=novi_x; y=novi_y; }
	return status;
}

void PrijaviGresku(KodoviGresaka kodovi) {
	if(kodovi==KodoviGresaka::PogresnaKomanda) std::cout << "Nerazumljiva komanda!" << std::endl;
	if(kodovi==KodoviGresaka::NedostajeParametar) std::cout << "Komanda trazi parametar koji nije naveden!" << std::endl;
	if(kodovi==KodoviGresaka::NeispravanParametar) std::cout << "Parametar komande nije ispravan!" << std::endl;
	if(kodovi==KodoviGresaka::SuvisanParametar) std::cout << "Zadan je suvisan parametar nakon komande!" << std::endl;
}

bool SpremiXiY(std::string pomoc, int &x, int &y, int i, KodoviGresaka &greska) {
	
	bool ispravno=false;
	while(pomoc[i]==' ') i++;
		if(pomoc[i]>='0' && pomoc[i]<='9') {
			int r=i; 
			while(pomoc[r]>='0' && pomoc[r]<='9') r++; 
			x=std::stoi(pomoc.substr(i, r));
			if(pomoc[r]==' ') {
				r++; i=r;
				while(pomoc[r]>='0' && pomoc[r]<='9') r++;
				y=std::stoi(pomoc.substr(i, r));
				//std::cout << y;
				int w=r;
				while(w!=pomoc.length()) w++;
				if(w!=r)  { ispravno=false; greska=KodoviGresaka::NeispravanParametar; return ispravno; }
				ispravno=true;
			}
		}
		
		//std::cout << "x: " << x << "y: " << y;
		return ispravno;
}

bool UnosKomande (Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &kod_greske) {
	
	std::string unos, peek;
	
	std::vector<Smjerovi> vekt_smjerova;
	std::getline(std::cin, unos);
	
	std::string pomoc(unos);
	int a(0);
	while(unos[a]==' ') a++;
	while(unos[unos.length()-1]==' ') pomoc.resize(pomoc.length()-1);
	pomoc = pomoc.substr(a, pomoc.length());
	
	std::vector<std::string> Faliparametara = {"P1", "D", "B", "P>"};
	
	for(int i=0; i<Faliparametara.size(); i++)
	if(pomoc==Faliparametara[i]) { kod_greske=KodoviGresaka::NedostajeParametar; return false; }
	
	//pomjeri za jedno mjesto
	std::vector<std::string> oznake{"P1 GL", "P1 G", "P1 GD", "P1 D", "P1 DoD", "P1 Do", "P1 DoL", "P1 L"};
	for(int i=0; i<oznake.size(); i++) {
		if(pomoc==oznake[i]) {
			smjer=Smjerovi(i);
			komanda=Komande::PomjeriJednoMjesto; return true;
		}
	}
	
	//pomjeri se na zadano polje
	if(pomoc.substr(0, 2)=="P>") {
		int i=2;
		if(!(SpremiXiY(pomoc, x, y, i, kod_greske))) { return false; }
		else {
			komanda=Komande::PomjeriDalje;
			return true;
		}
	}
	
	//Blokiraj i deblokiraj
	if(pomoc[0]=='B' || pomoc[0]=='D') {
		int i=1;
		if(!(SpremiXiY(pomoc, x, y, i, kod_greske))) { return false; }
		else {
			if(pomoc[0]=='B') { komanda=Komande::Blokiraj; }
			else komanda=Komande::Deblokiraj;
			return true;
		}
	}
	
	if(pomoc=="PO") { komanda=Komande::PrikaziOkolinu; return true; }
	else if(pomoc=="Z") { komanda=Komande::ZavrsiIgru; return true; }
	else if(pomoc=="K") { komanda=Komande::KreirajIgru; return true; }
	
	else if((pomoc[0]=='K' || pomoc[0]=='Z' ) && pomoc.length()>1) { kod_greske=KodoviGresaka::SuvisanParametar; return false; }
	else if(pomoc[0]=='P' && pomoc[1]=='O' && pomoc.length()>2) { kod_greske=KodoviGresaka::SuvisanParametar; return false; }
	else { kod_greske=KodoviGresaka::PogresnaKomanda; return false; }
	return true;
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer=Smjerovi::Gore, int p_x=0, int p_y=0) {
	
	if(komanda==Komande::PomjeriJednoMjesto) { 
		
		Status s = Idi(polja, x, y, p_smjer);
		
		std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")" << std::endl;
		
		if(s==Status::KrajPobjeda) {
			std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
			
			for(int i=0; i<polja.size(); i++) {
				for(int j=0; j<polja[0].size(); j++) {
					polja[i][j]=Polje::Prazno;
				}
			}
			x=0; y=0;
		
			throw std::runtime_error("Igra zavrsena");
			
		}
		else if(s==Status::KrajPoraz) { 
			std::cout << "Nagazili ste na minu" << std::endl;
			
			for(int i=0; i<polja.size(); i++) {
				for(int j=0; j<polja[0].size(); j++) {
					polja[i][j]=Polje::Prazno;
				}
			}
			x=0; y=0;
		
			throw std::runtime_error("Igra zavrsena");
			
		}
	}
	
	else if(komanda==Komande::PomjeriDalje) { 
		try{
		Status s = Idi(polja, p_x, p_y, x, y);
		x=p_x; y=p_y;
		
		std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")" << std::endl;
		
		if(s==Status::KrajPobjeda) {
			std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
			for(int i=0; i<polja.size(); i++) {
				for(int j=0; j<polja[0].size(); j++) {
					polja[i][j]=Polje::Prazno;
				}
			}
			x=0; y=0;
		
			throw std::runtime_error("Igra zavrsena");
		}
		
		else if(s==Status::KrajPoraz) { 
			std::cout << "Nagazili ste na minu" << std::endl;
			
			for(int i=0; i<polja.size(); i++) {
				for(int j=0; j<polja[0].size(); j++) {
					polja[i][j]=Polje::Prazno;
				}
			}
			x=0; y=0;
		
			throw std::runtime_error("Igra zavrsena\n");
		}
		}
		catch(std::logic_error s) { std::cout << s.what(); }
	}
	
	else if(komanda==Komande::Blokiraj) { 
		try { BlokirajPolje(polja, x, y); }
		catch(std::domain_error q) { std::cout << q.what() << std::endl; }
	} 
	
	else if(komanda==Komande::Deblokiraj) { 
		try { DeblokirajPolje(polja, x, y); }
		catch(std::domain_error q) { std::cout << q.what() << std::endl; }
	}
	
	else if(komanda==Komande::PrikaziOkolinu) { 
		
		std::vector<std::vector<int>> prikaz(PrikaziOkolinu(polja, x, y)); 
		
		for(int i=0; i<prikaz.size(); i++) {
			for(int j=0; j<prikaz[0].size(); j++) {
				std::cout << prikaz[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
	
	else if(komanda==Komande::ZavrsiIgru) {
		
		for(int i=0; i<polja.size(); i++) {
			for(int j=0; j<polja[0].size(); j++) {
				polja[i][j]=Polje::Prazno;
			}
		}
		
		x=0; y=0;
		
		throw std::runtime_error("Igra zavrsena");
	}
	
	else {
		
		std::cout << "Unesite broj polja: ";
		int n; 
		std::cin >> n;
		
		std::cout << "Unesite pozicije mina: ";
		std::vector<std::complex<int>> poz_mina;
		while(std::cin.peek()!='.') {
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::complex<int> unos;
			std::cin >> unos;
			
			if(!std::cin) { 
				std::cin.clear(); 
				if(std::cin.peek()=='.') { std::cin.clear(); std::cin.ignore(100000, '\n'); break; }
				else {std::cout << "Greska, unesite ponovo!" << std::endl; continue; } 
			}
			
			if(unos.real()>=n || unos.imag()<0 || unos.real()<0 || unos.imag()>=n) { std::cout << "Greska, unesite ponovo!" << std::endl; continue; }
			poz_mina.push_back(unos);
		}
		
		std::vector<std::vector<int>> mina(poz_mina.size(), std::vector<int> (2));
		for(int i=0; i<poz_mina.size(); i++) {
			mina[i][0]=real(poz_mina[i]);
		}
		
		for(int i=0; i<poz_mina.size(); i++) {
			mina[i][1]=imag(poz_mina[i]);
		}
		polja=KreirajIgru(n, mina);
		//polja[0][0]=Polje::Posjeceno;
		
		x=0; y=0;
	}
	
}

int main ()  {

	try {
		Komande komanda;
		Smjerovi smjer;
		int n_x(0), n_y(0), x(0), y(0);
		KodoviGresaka greska;
		Tabla polja;
		for(;;) {
			std::cout << "Unesite komandu: ";
			
			if(UnosKomande(komanda, smjer, x, y, greska)==true) { 
				IzvrsiKomandu(komanda, polja, x, y, smjer, n_x, n_y); 
				n_x=x; n_y=y;
			}
			else PrijaviGresku(greska);
		}
	}
	catch(std::domain_error izuzetak) {
		std::cout << izuzetak.what();
	}
	catch(std::out_of_range izuzetak1) {
		std::cout << izuzetak1.what();
	}
	catch(std::logic_error izuzetak2) {
		std::cout << izuzetak2.what();
	}
	catch(std::runtime_error izuzetak2) {}
	catch(...) {}
	
	std::cout << "Dovidjenja!";
	return 0;
} 


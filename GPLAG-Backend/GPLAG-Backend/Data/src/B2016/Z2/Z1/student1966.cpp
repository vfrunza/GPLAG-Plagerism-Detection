#include <iostream>
#include <vector>
#include <stdexcept>
#include <complex>
#include <cmath>
#include <string>
enum class Polje {
 Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};
enum class Smjerovi {
 GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};
enum class Status {
 NijeKraj, KrajPoraz, KrajPobjeda
};
enum class Komande {
 PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu,
 ZavrsiIgru, KreirajIgru
};
enum class KodoviGresaka {
 PogresnaKomanda, NedostajeParmetar, SuvisanParametar, NeispravanParametar
};

void PrijaviGresku(KodoviGresaka error) {
	if(error==KodoviGresaka::PogresnaKomanda) std::cout<<"Nerazumljiva komanda\n";
	else if(error==KodoviGresaka::NedostajeParmetar) std::cout<<"Komanda trazi parametar koji nije naveden!\n";
	else if(error==KodoviGresaka::SuvisanParametar) std::cout<<"Zadan je suvisan parametar nakon komande!\n";
	else if(error==KodoviGresaka::NeispravanParametar) std::cout<<"Parametar komande nije ispravan!\n";
}
typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine) {

for(std::vector<int> x: mine) {if(x.size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
	if(x[0]>=n || x[1]>=n) throw std::domain_error("Ilegalne pozicije mina");}
	Tabla povrsina(n);
	for(int i=0; i<n; i++) {povrsina[i].resize(n);}
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {povrsina[i][j]=Polje::Prazno;}}
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			for(int k=0; k<mine.size(); k++) {if(i==mine[k][0] && j==mine[k][1]) povrsina[i][j]=Polje::Mina;}}}
			return povrsina;}
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y) {
	int n=polja.size();
	std::vector<std::vector<int> > okoline(3);
	for(int i=0; i<3; i++) okoline[i].resize(3);
		int a=0, b=0;
		for(int i=x-1; i<=x+1; i++) {
			for(int j=y-1; j<=y+1; j++) {
				if(i>=0 && i<n && j>=0 && j<n) {
					int brojac=0;
					for(int k=i-1; k<=i+1; k++) {
						for(int l=j-1; l<=j+1; l++) {
							if(k>=0 && k<n && l>=0 && l<n) {
								if((k!=i && l!=j) && polja[l][k]==Polje::Mina) brojac++;}
						} okoline[a][b]=brojac; 	
					} 
				} b++;
			} a++;
		} return okoline;}
void BlokirajPolje(Tabla &polja, int x, int y) {
	if(x>=polja.size() || y>=polja.size() || x<0 || y<0) throw std::domain_error("Polje (x,y) ne postoji");
	for(int i=0; i<polja.size(); i++) {
		for(int j=0; j<polja.size(); j++) {
			if(i==x && j==y && polja[i][j]==Polje::Mina) polja[i][j]=Polje::BlokiranoMina;
			else if(i==x && j==y && polja[i][j]==Polje::Prazno) polja[i][j]=Polje::BlokiranoPrazno;
			else if(i==x && j==y && polja[i][j]==Polje::Posjeceno) polja[i][j]=Polje::BlokiranoPosjeceno;	}}}
void DeblokirajPolje(Tabla &polja, int x, int y) {
		if(x>=polja.size() || y>=polja.size() || x<0 || y<0) throw std::domain_error("Polje (x,y) ne postoji");
		for(int i=0; i<polja.size(); i++) {
			for(int j=0; j<polja.size(); j++) {
				if(i==x && j==y && polja[i][j]==Polje::BlokiranoMina) polja[i][j]=Polje::Mina;
				else if(i==x && j==y && polja[i][j]==Polje::BlokiranoPrazno) polja[i][j]=Polje::Prazno;
				else if(i==x && j==y && polja[i][j]==Polje::BlokiranoPosjeceno) polja[i][j]=Polje::Posjeceno;}}}
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer) {
	Status stanje(Status::NijeKraj);
	if(smjer==Smjerovi::Gore && x!=0 && polja[x-1][y]!=Polje::Mina) {polja[x][y]=Polje::Posjeceno; x--;}
	else if(smjer==Smjerovi::Gore && x!=0 && polja[x-1][y]==Polje::Mina) {stanje=Status::KrajPoraz;}
	else if(smjer==Smjerovi::Gore && x==0) {throw std::out_of_range("Izlazak van igrace table");}
	else if(smjer==Smjerovi::GoreDesno && y!=polja.size()-1 && x!=0 && polja[x-1][y+1]!=Polje::Mina) {polja[x][y]=Polje::Posjeceno; x++; y--;}
	else if(smjer==Smjerovi::GoreDesno && y!=polja.size()-1 && x!=0 && polja[x-1][y+1]!=Polje::Mina && (polja[x-1][y+1]==Polje::BlokiranoPosjeceno || polja[x-1][y+1]==Polje::BlokiranoPrazno ||polja[x-1][y+1]==Polje::BlokiranoMina)) throw std::logic_error("Blokirano polje");
	else if(smjer==Smjerovi::GoreDesno && y!=polja.size()-1 && x!=0 && polja[x-1][y+1]==Polje::Mina) {stanje=Status::KrajPoraz;}
	else if(smjer==Smjerovi::GoreDesno && (y==polja.size()-1 || x==0)) throw std::out_of_range("Izlazak van igrace table");
	else if(smjer==Smjerovi::GoreLijevo && x!=0 && y!=0 && polja[x-1][y-1]!=Polje::Mina) {polja[x][y]=Polje::Posjeceno; x--; y--;}
	else if(smjer==Smjerovi::GoreLijevo && x!=0 && y!=0 && polja[x-1][y-1]!=Polje::Mina && (polja[x-1][y-1]==Polje::BlokiranoPosjeceno || polja[x-1][y-1]==Polje::BlokiranoPrazno ||polja[x-1][y-1]==Polje::BlokiranoMina)) {throw std::logic_error("Blokirano polje");}
	else if(smjer==Smjerovi::GoreLijevo && x!=0 && y!=0 && polja[x-1][y-1]==Polje::Mina) stanje=Status::KrajPoraz;
	else if(smjer==Smjerovi::GoreLijevo && (x==0 || y==0)){ std::cout<<"Izlazak van igrace table\n"; }
	else if(smjer==Smjerovi::Dolje && x!=polja.size()-1 && polja[x+1][y]!=Polje::Mina) {polja[x][y]=Polje::Posjeceno; x++;}
	else if(smjer==Smjerovi::Dolje && x!=polja.size()-1 && polja[x+1][y]!=Polje::Mina && (polja[x+1][y]==Polje::BlokiranoPosjeceno || polja[x+1][y]==Polje::BlokiranoPrazno ||polja[x+1][y]==Polje::BlokiranoMina)) {throw std::logic_error("Blokirano polje");}
	else if(smjer==Smjerovi::Dolje && x!=polja.size()-1 && polja[x+1][y]==Polje::Mina) {stanje=Status::KrajPoraz;}
	else if(smjer==Smjerovi::Dolje && x==polja.size()-1) {throw std::out_of_range("Izlazak van igrace table");}
	else if(smjer==Smjerovi::DoljeDesno && y<polja.size()-1 && x<polja.size()-1 && polja[x+1][y+1]!=Polje::Mina) {polja[x][y]=Polje::Posjeceno; x++; y++;}
	else if(smjer==Smjerovi::DoljeDesno && y!=polja.size()-1 && x!=polja.size()-1 && polja[x+1][y+1]!=Polje::Mina && (polja[x+1][y+1]==Polje::BlokiranoPosjeceno || polja[x+1][y+1]==Polje::BlokiranoPrazno ||polja[x+1][y+1]==Polje::BlokiranoMina)) {throw std::logic_error("Blokirano polje");}
	else if(smjer==Smjerovi::DoljeDesno && y!=polja.size()-1 && x!=polja.size()-1 && polja[x+1][y+1]==Polje::Mina) {stanje=Status::KrajPoraz;}
	else if(smjer==Smjerovi::DoljeDesno && (y==polja.size()-1 || x==polja.size()-1)) {throw std::out_of_range("Izlazak van igrace table");}
	else if(smjer==Smjerovi::DoljeLijevo && x!=polja.size()-1 && y!=0 && polja[x+1][y-1]!=Polje::Mina) {polja[x][y]=Polje::Posjeceno; x++; y--;}
	else if(smjer==Smjerovi::DoljeLijevo && x!=polja.size()-1 && y!=0 && polja[x+1][y-1]!=Polje::Mina && (polja[x+1][y-1]==Polje::BlokiranoPosjeceno || polja[x+1][y-1]==Polje::BlokiranoPrazno ||polja[x+1][y-1]==Polje::BlokiranoMina)) {throw std::logic_error("Blokirano polje");}
	else if(smjer==Smjerovi::DoljeLijevo && x!=polja.size()-1 && y!=0 && polja[x+1][y-1]==Polje::Mina) {stanje=Status::KrajPoraz;}
	else if(smjer==Smjerovi::DoljeLijevo && (y==polja.size()-1 || x==0)) {throw std::out_of_range("Izlazak van igrace table");}
	else if(smjer==Smjerovi::Desno && y!=polja.size()-1 && polja[x][y+1]!=Polje::Mina) {polja[x][y]=Polje::Posjeceno; y++;}
	else if(smjer==Smjerovi::Desno && y!=polja.size()-1 && polja[y][y+1]!=Polje::Mina && (polja[x][y+1]==Polje::BlokiranoPosjeceno || polja[x][y+1]==Polje::BlokiranoPrazno ||polja[x][y+1]==Polje::BlokiranoMina)){ throw std::logic_error("Blokirano polje");}
	else if(smjer==Smjerovi::Desno && y!=polja.size()-1 && polja[x][y+1]==Polje::Mina) {stanje=Status::KrajPoraz;}
	else if(smjer==Smjerovi::Desno && y==polja.size()-1) {throw std::out_of_range("Izlazak van igrace table"); }
	else if(smjer==Smjerovi::Lijevo && y!=0 && polja[x][y-1]!=Polje::Mina) {polja[x][y]=Polje::Posjeceno; x--;}
	else if(smjer==Smjerovi::Lijevo && y!=0 && polja[x][y-1]!=Polje::Mina && (polja[x][y-1]==Polje::BlokiranoPosjeceno || polja[x][y-1]==Polje::BlokiranoPrazno ||polja[x][y-1]==Polje::BlokiranoMina)){ throw std::logic_error("Blokirano polje"); }
	else if(smjer==Smjerovi::Lijevo && y!=0 && polja[x][y-1]==Polje::Mina) {stanje=Status::KrajPoraz;}
	else if(smjer==Smjerovi::Lijevo && y==0) {throw std::out_of_range("Izlazak van igrace table");}
	if(stanje!=Status::KrajPoraz) {
		bool pobjeda=true;
	for(int i=0; i<polja.size(); i++) {
		for(int j=0; j<polja.size(); j++)	if(polja[i][j]==Polje::Prazno) pobjeda=false; break;
	} if(pobjeda==true) stanje=Status::KrajPobjeda;
	else stanje=Status::NijeKraj;}
	return stanje;}
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y) {
	Status stanje(Status::NijeKraj);
	if(novi_x>=0 && novi_x<polja.size() && novi_y>=0 && novi_y<polja.size()) {x=novi_x; y=novi_y;}
	else if(novi_x>=0 && novi_x<polja.size() && novi_y>=0 && novi_y<polja.size() && polja[x][y]==Polje::Mina) {return stanje=Status::KrajPoraz;}
	else if(novi_x>=0 && novi_x<polja.size() && novi_y>=0 && novi_y<polja.size() && (polja[novi_x][novi_y]==Polje::BlokiranoPosjeceno || polja[novi_x][novi_y]==Polje::BlokiranoPrazno || polja[novi_x][novi_y]==Polje::BlokiranoMina)) {throw std::logic_error("Blokirano polje");}
		if(stanje!=Status::KrajPoraz) {
		bool pobjeda=true;
	for(int i=0; i<polja.size(); i++) {
		for(int j=0; j<polja.size(); j++){	
			if(polja[i][j]==Polje::Prazno) {pobjeda=false; break;}
		}
	} if(pobjeda==true) stanje=Status::KrajPobjeda;
	else stanje=Status::NijeKraj;}
	return stanje;}
void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0) {
	if(komanda==Komande::Blokiraj) try{BlokirajPolje(polja, x, y);}
	catch(std::domain_error er) {std::cout<<er.what();}
	else if(komanda==Komande::Deblokiraj) try{DeblokirajPolje(polja, x, y);}
	catch(std::domain_error e2) {std::cout<<e2.what();}
	else if(komanda==Komande::PomjeriDalje) {
	try{	
	Status rezultat=Idi(polja, x, y, p_x, p_y);
	
		if(rezultat==Status::KrajPobjeda) std::cout<<"Bravo, obisli ste sva sigurna polja\n";
		else if(rezultat==Status::KrajPoraz) std::cout<<"Nagazili ste na minu\n";
		else std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<").\n"; }
		catch(std::out_of_range e3) {std::cout<<e3.what();}
		catch(std::logic_error e4) {std::cout<<e4.what();} }
	else if(komanda==Komande::PomjeriJednoMjesto) {
	try{
		Status rezultat=Idi(polja, x, y, p_smjer);
		
		if(rezultat==Status::KrajPobjeda) std::cout<<"Bravo, obisli ste sva sigurna polja\n";
		else if(rezultat==Status::KrajPoraz) std::cout<<"Nagazili ste na minu\n";
		else std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<").\n";}
		catch(std::domain_error a) {std::cout<<a.what();}
		catch(std::logic_error b) {std::cout<<b.what();}
	}
	else if(komanda==Komande::PrikaziOkolinu) {
		auto okolina=PrikaziOkolinu(polja, x, y);
		for(int i=0; i<okolina.size(); i++) {
		for(int j=0; j<okolina.size(); j++) std::cout<<okolina[i][j]<<" ";
		 std::cout<<std::endl;}
	}
	else if(komanda==Komande::KreirajIgru) {
			int n;
		std::cout<<"Unesite broj polja: ";
		std::cin>>n;
		std::vector<std::vector<int> > mine(1, std::vector<int> (2));
		int velicina=1;
		std::complex<int> z;
		std::cout<<"Unesite pozicije mina: ";
		while (std::cin && std::cin.peek()!='.') {
			std::cin>>z;
			if(!(std::cin) && std::cin.peek()=='.') {break;}
			else if(!(std::cin )&& std::cin.peek()!='.') {std::cout<<"Greska, unesite ponovo!\n"; 
std::cin.clear();
std::cin.ignore(100, '\n');
			velicina++;
			mine.resize(velicina);
			mine[velicina-1].resize(2);
			mine[velicina-1][0]=z.real();
			mine[velicina-1][1]=z.imag();
						if(!(std::cin) && std::cin.peek()=='.') {break;}
 }std::cin.ignore(10, '\n');
		}  
		try{polja=KreirajIgru(n, mine);}
		catch(std::domain_error e) {std::cout<<e.what();}}}

 bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska) {
	std::string naredba;
	std::cin.clear();
	std::getline(std::cin, naredba);
	if(naredba[0]=='K') {
		for(int i=1; i<naredba.size(); i++) if(naredba[i]!=' ') {greska=KodoviGresaka::SuvisanParametar; return false;}
		komanda=Komande::KreirajIgru; return true;}
	else if(naredba[0]=='Z') {
		for(int i=1; i<naredba.size(); i++) if(naredba[i]!=' ') {greska=KodoviGresaka::NeispravanParametar; return false;}
		komanda=Komande::ZavrsiIgru; return true;}
	else if(naredba[0]=='P' && naredba.size()>1 && naredba[1]=='O'){
		for(int i=2; i<naredba.size(); i++) if(naredba[1]!=' ') {greska=KodoviGresaka::NeispravanParametar; return false;}
		komanda=Komande::PrikaziOkolinu;
		return true;
	}
	else if(naredba[0]=='D') {
		for(int i=1; i<naredba.size(); i++) if(naredba[i]!=' ' && (naredba[i]<48 || naredba[i]>57)) {greska=KodoviGresaka::SuvisanParametar; return false;}
			int imaparametre(0);
			for(int i=1; i<naredba.size(); i++) {if(naredba[i]>='0' && naredba[i]<='9') imaparametre++;}
			if(imaparametre!=2) {greska=KodoviGresaka::NedostajeParmetar; return false;}
			komanda=Komande::Deblokiraj;
			return true;}
	else if(naredba[0]=='B') {
			for(int i=1; i<naredba.size(); i++) if(naredba[i]!=' ' && (naredba[i]<48 || naredba[i]>57)) {greska=KodoviGresaka::SuvisanParametar; return false;}
			if(naredba.size()==1) {greska=KodoviGresaka::NedostajeParmetar; return false;}
			int imaparametre;
			for(int i=1; i<naredba.size(); i++) {if(naredba[i]>='0' && naredba[i]<='9') imaparametre++;}
			if(imaparametre!=2) {greska=KodoviGresaka::NedostajeParmetar; return false;}
		komanda=Komande::Blokiraj;
		return true;
	}
	else if(naredba[0]=='P' && naredba.size()>1 && naredba[1]=='>') {
					int imaparametre(0);
			for(int i=2; i<naredba.size(); i++) {if(naredba[i]>='0' && naredba[i]<='9') imaparametre++;}
			if(imaparametre!=2) {
				for(int i=2; i<naredba.size(); i++) if(naredba[i]!=' ' && (naredba[i]<48 || naredba[i]>57)) {greska=KodoviGresaka::NeispravanParametar; return false;}
				greska=KodoviGresaka::NedostajeParmetar; return false;
				komanda=Komande::PomjeriDalje;
			}
		for(int i=2; i<naredba.size(); i++) if(naredba[i]!=' ' && (naredba[i]<48 || naredba[i]>57)) {greska=KodoviGresaka::SuvisanParametar; return false;}
		if(naredba.size()==2) {greska=KodoviGresaka::NedostajeParmetar; return false;}
		komanda=Komande::PomjeriDalje;
		int pocni;
		for(int i=0; i<naredba.size(); i++) {
			if(naredba[i]>='0' && naredba[i]<='9') {x=naredba[i]-48;
			pocni=i; break;}}
		 for(int i=pocni; i<naredba.size(); i++) if(naredba[i]>='0' && naredba[i]<='9') {y=naredba[i]-48;}
		 return true;}
	else if(naredba[0]=='P' && naredba.size()>1 && naredba[1]=='1') {
		if(naredba.size()==2) greska=KodoviGresaka::NedostajeParmetar;
		bool okay(false);
		int granica1, granica2;
		std::string kuda;
			for(int i=2; i<naredba.size(); i++) {
		if(naredba.substr(i, 3)=="DoD" || naredba.substr(i,3)=="DoL") {okay=true; granica1=i; kuda=naredba.substr(i,4); break;}
		else if(naredba.substr(i,2)=="Do" || naredba.substr(i,2)=="GL" ||naredba.substr(i,2)=="GD"){okay=true; granica1=i; kuda=naredba.substr(i,2); break;}
		else if(naredba[i]=='D' || naredba[i]=='L' || naredba[i]=='G') {okay=true; granica1=i; kuda=naredba[i]; break;}
		} 
	if(okay==false) {
		for(int i=2; i<naredba.size(); i++) if(naredba[i]!=' ') {greska=KodoviGresaka::NeispravanParametar; return false;}
		else greska=KodoviGresaka::NedostajeParmetar; return false;}
		if(kuda=="GL") smjer=Smjerovi::GoreLijevo;
		else if(kuda=="G") smjer=Smjerovi::Gore;
		else if(kuda=="GD") smjer=Smjerovi::GoreDesno;
		else if(kuda=="D") smjer=Smjerovi::Desno;
		else if(kuda=="DoD") smjer=Smjerovi::DoljeDesno;
		else if(kuda=="DoL") smjer=Smjerovi::DoljeLijevo;
		else if(kuda=="Do") smjer=Smjerovi::Dolje;
		else if(kuda=="L") smjer=Smjerovi::Lijevo;
		komanda=Komande::PomjeriJednoMjesto;
		return true;
		}
		else greska=KodoviGresaka::PogresnaKomanda; 
		return false;
		}
	
	int main() {
		Tabla polja;
		int x(0), y(0);
		Komande command, a;
	while(command!=Komande::ZavrsiIgru) {
	int  novi_x, novi_y;
	Smjerovi direction;
	KodoviGresaka greska;
	std::cout<<"Unesite komandu: ";
	bool igrica=UnosKomande(command, direction, novi_x, novi_y, greska);
	if(igrica==true) IzvrsiKomandu(command, polja, x, y, direction, novi_x, novi_y);
	else if(igrica==false) {PrijaviGresku(greska); command=a;}

	}
	std::cout<<"Dovidjenja!";
	 return 0;
	}
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

enum class Polje{Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina};
enum class Smjerovi{GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo};
enum class Status{NijeKraj, KrajPoraz, KrajPobjeda}; 
enum class KodoviGresaka{PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar}; 
enum class Komande{PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru}; 
typedef std::vector<std::vector<Polje>> Tabla;

void ObrisiTablu(Tabla &igra) {
	for(int i=0; i<igra.size(); i++)
	for(int j=0; j<igra[i].size(); j++)
	igra[i][j]=Polje::Prazno; }

void ProvjeraVektoraMina(const std::vector<std::vector<int>> &mine, bool &ilegalnapozicija, bool &ilegalanformat, int n) {
	for(int i=0; i<mine.size(); i++) {
		if(mine[i].size()!=2) ilegalanformat=true; //eh sad ovdje dal da breakam ili ne jer ne znam kojim redosljedom ide ono cudo?
		for(int j=0; j<mine[i].size(); j++) {
			if(mine[i][j]>=n || mine[i][j]<0) ilegalnapozicija=true; } } }

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine) {
	if(n<=0) throw std::domain_error("Ilegalna velicina");
	bool ilegalnapozicija(false), ilegalanformat(false); 
	ProvjeraVektoraMina(mine, ilegalnapozicija, ilegalanformat, n); 
	if(ilegalanformat) throw std::domain_error("Ilegalan format zadavanja mina");
	if(ilegalnapozicija) throw std::domain_error("Ilegalne pozicije mina"); 
	Tabla igra(n, std::vector<Polje> (n, Polje::Prazno)); 
	for(int i=0; i<mine.size(); i++)
	igra[mine[i][0]][mine[i][1]]=Polje::Mina; 
	return igra; }

int SumaOkoline(const Tabla &polja, int x, int y) {
	int suma(0); 
	for(int i=x-1; i<=x+1; i++) {
		if(i<0) continue;
		if(i==polja.size()) continue; 
	for(int j=y-1; j<=y+1; j++)
	{	if(j<0) continue;
		if(j==polja.size()) continue;
		if(i==x && j==y) continue;
	
		if(i<polja.size() && i>=0 && j<polja.size() && j>=0 && polja.at(i).at(j)==Polje::Mina) suma++; 
	
	} }
	return suma; }

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y) {
	if(x<0 || y<0 || x>=polja.size() || polja.size()==0) throw std::domain_error("Polje (" +std::to_string(x) +"," +std::to_string(y)+") ne postoji"); 
	if(y>=polja[0].size()) throw std::domain_error("Polje (" + std::to_string(x)+"," +std::to_string(y)+") ne postoji"); 
	std::vector<std::vector<int>> okolina(3, std::vector<int> (3,0));
	for(int i=0; i<3; i++)
	for(int j=0; j<3; j++){
//	if(x-1+i>=0 && y-1+j>=0 && x-1+i<polja.size() && y-1+j<polja.size())
	okolina[i][j]=SumaOkoline(polja, x-1+i, y-1+j); } 
	return okolina; }

void BlokirajPolje(Tabla &polja, int x, int y) {
	if(x<0 || y<0 || x>=polja.size()) throw std::domain_error(static_cast<std::string>("Polje (") +std::to_string(x) + "," + std::to_string(y)+ ") ne postoji"); 
	if(y>=polja[0].size()) throw std::domain_error("Polje (" +std::to_string(x) + "," +std::to_string(y) + ") ne postoji"); 
	if(polja[x][y]==Polje::Prazno) polja[x][y]=Polje::BlokiranoPrazno; 
	else if(polja[x][y]==Polje::Mina) polja[x][y]=Polje::BlokiranoMina; 
	else if(polja[x][y]==Polje::Posjeceno) polja[x][y]=Polje::BlokiranoPosjeceno; }

void DeblokirajPolje(Tabla &polja, int x, int y) {
	if(x<0 || y<0 || x>=polja.size()) throw std::domain_error("Polje (" +std::to_string(x) +"," + std::to_string(y)+ ") ne postoji"); 
	if(y>=polja[0].size()) throw std::domain_error("Polje (" +std::to_string(x) + "," + std::to_string(y) +") ne postoji"); 
	if(polja[x][y]==Polje::BlokiranoPrazno) polja[x][y]=Polje::Prazno; 
	else if(polja[x][y]==Polje::BlokiranoPosjeceno) polja[x][y]=Polje::Posjeceno; 
	else if(polja[x][y]==Polje::BlokiranoMina) polja[x][y]=Polje::Mina; }

bool PostojiJosPraznih(const Tabla &polja) { //ovdje se uzdam da mi je ok tabla ali eto mozda dodaj neku provjeru
	for(int i=0; i<polja.size(); i++)
	for(int j=0; j<polja[i].size(); j++) 
		if(polja[i][j]==Polje::Prazno) return true;
	return false; }

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer) {
	int potencijalno_novi_x(x);
	int potencijalno_novi_y(y); 
	if(smjer==Smjerovi::GoreLijevo) {
		potencijalno_novi_x=x-1;
		potencijalno_novi_y=y-1;
	}
	else if(smjer==Smjerovi::Gore) {
		potencijalno_novi_x=x-1;
	}
	else if(smjer==Smjerovi::GoreDesno) {
		potencijalno_novi_x=x-1;
		potencijalno_novi_y=y+1; 
	}
	else if(smjer==Smjerovi::Desno) {
		potencijalno_novi_y=y+1; 
	}
	else if(smjer==Smjerovi::DoljeDesno) {
		potencijalno_novi_x=x+1;
		potencijalno_novi_y=y+1; 
	}
	else if(smjer==Smjerovi::Dolje) {
		potencijalno_novi_x=x+1; 
	}
	else if(smjer==Smjerovi::DoljeLijevo) {
		potencijalno_novi_x=x+1;
		potencijalno_novi_y=y-1; 
	}
	else if(smjer==Smjerovi::Lijevo) {
		potencijalno_novi_y=y-1; 
	}
	if(potencijalno_novi_x<0 || potencijalno_novi_y<0 || potencijalno_novi_x>=polja.size() || potencijalno_novi_y>=polja[0].size()) throw std::out_of_range("Izlazak van igrace table"); 
	//razdvoji ovaj uslov za svaki slucaj
	if(polja[potencijalno_novi_x][potencijalno_novi_y]==Polje::BlokiranoPosjeceno || polja[potencijalno_novi_x][potencijalno_novi_y]==Polje::BlokiranoPrazno || polja[potencijalno_novi_x][potencijalno_novi_y]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
	polja[x][y]=Polje::Posjeceno; 
	x=potencijalno_novi_x;
	y=potencijalno_novi_y;
	if(polja[x][y]==Polje::Mina) { ObrisiTablu(polja); return Status::KrajPoraz; } 
	if(!PostojiJosPraznih(polja)) { ObrisiTablu(polja); return Status::KrajPobjeda; }
	return Status::NijeKraj; }

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y) {
	if(novi_x<0 || novi_y<0 || novi_x>=polja.size()) throw std::out_of_range("Izlazak van igrace table"); 
	if(novi_y>=polja[0].size()) throw std::out_of_range("Izlazak van igrace table"); 
	if(polja[novi_x][novi_y]==Polje::BlokiranoPosjeceno || polja[novi_x][novi_y]==Polje::BlokiranoPrazno || polja[novi_x][novi_y]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje"); 
	polja[x][y]=Polje::Posjeceno; 
	x=novi_x;
	y=novi_y;
	if(polja[x][y]==Polje::Mina) { ObrisiTablu(polja); return Status::KrajPoraz;	} 
	if(!PostojiJosPraznih(polja)) { ObrisiTablu(polja); return Status::KrajPobjeda; } 
	return Status::NijeKraj; }

bool JesuLiSviBrojevi(std::string rijec) {
	for(int i=0; i<rijec.size(); i++)
	if(!(rijec[i]>='0' && rijec[i]<='9')) return false; //************************************************ovo provjeri asja
	return true; }

bool ProvjeraZaP1(const std::vector<std::string> &recenica, KodoviGresaka &greska, Komande &komanda, Smjerovi &smjer) {
	if(recenica.size()< 2) { 
		greska=KodoviGresaka::NedostajeParametar;
		return false; }
	if(recenica.size()>2) {
		greska=KodoviGresaka::SuvisanParametar; 
		return false; }
	std::vector<std::string> lista{"GL", "G", "GD", "D", "DoD", "Do", "DoL", "L"};
	for(int i=0; i<8; i++) {
	if(recenica[1]==lista[i]) { 
	komanda=Komande::PomjeriJednoMjesto;
	smjer=static_cast<Smjerovi>(i);  // *********************WISHFUL THINKING ALL THE WAY***********************
	return true; } }
	greska=KodoviGresaka::NeispravanParametar;
	return false; }

bool ProvjeraZaPO(const std::vector<std::string> &recenica, KodoviGresaka &greska, Komande &komanda) {
	if(recenica.size()>1) {
		greska=KodoviGresaka::SuvisanParametar; 
		return false;
	}
	komanda=Komande::PrikaziOkolinu;
	return true; }

bool ProvjeraZaZ(const std::vector<std::string> &recenica, KodoviGresaka &greska, Komande &komanda) {
	if(recenica.size()>1) {
		greska=KodoviGresaka::SuvisanParametar;
		return false;
	}
	komanda=Komande::ZavrsiIgru; 
	return true; }
	
bool ProvjeraZaK(const std::vector<std::string> &recenica, KodoviGresaka &greska, Komande &komanda) {
	if(recenica.size()>1) {
		greska=KodoviGresaka::SuvisanParametar;
		return false;
	}
	komanda=Komande::KreirajIgru;
	return true; }

bool ProvjeraZaOveSa3Parametra(const std::vector<std::string> &recenica, KodoviGresaka &greska, int &x, int &y) {
	if(recenica.size()>=2 && !JesuLiSviBrojevi(recenica[1])) {greska=KodoviGresaka::NeispravanParametar; return false;}
	if(recenica.size()<3) {
		greska=KodoviGresaka::NedostajeParametar; 
		return false;
	}
	if(recenica.size()>3) {
		greska=KodoviGresaka::SuvisanParametar;
		return false; 
	}
	
	if(!JesuLiSviBrojevi(recenica[1]) || !JesuLiSviBrojevi(recenica[2])) {
		greska=KodoviGresaka::NeispravanParametar; 
		return false;
	}
	x=std::stoi(recenica[1]);
	y=std::stoi(recenica[2]); //std::cout<< "U ONOJ SAM PROVJERI x i y su" <<x << " " << y; 
	return true; }
	
bool ProvjeraZaPs(const std::vector<std::string> &recenica, KodoviGresaka &greska, Komande &komanda, int &x, int &y) {
	if(!ProvjeraZaOveSa3Parametra(recenica, greska, x, y)) return false;
	komanda=Komande::PomjeriDalje;
	return true; }

bool ProvjeraZaB(const std::vector<std::string> &recenica, KodoviGresaka &greska, Komande &komanda, int &x, int &y) {
	if(!ProvjeraZaOveSa3Parametra(recenica, greska, x, y)) return false; 
	komanda=Komande::Blokiraj;
	return true; }
	
bool ProvjeraZaD(const std::vector<std::string> &recenica, KodoviGresaka &greska, Komande &komanda, int &x, int &y) {
	if(!ProvjeraZaOveSa3Parametra(recenica, greska, x, y)) return false;
	komanda=Komande::Deblokiraj; 
	return true; }

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska) { 
	std::string recenica; 
	std::getline(std::cin, recenica);
	int brojrijeci(0);
	std::vector<std::string> lista; 
	std::string rijec; 
	bool bio_razmak(1); 
	for(int i=0; i<recenica.size(); i++) {
		if(recenica[i]==' ') {
			bio_razmak=true; 
		}
		else{	if(bio_razmak) {
				while(recenica[i]!=' ' && i!=recenica.size()) {
					rijec.push_back(recenica[i]); 
					i++;	}
					lista.push_back(rijec); 
					brojrijeci++;
					i--;
					rijec.resize(0);
					bio_razmak=false; } }
	}
	if(lista.size()==0) return false; //stavi neku greksu 
	if(lista[0]=="P1") { if(!ProvjeraZaP1(lista, greska, komanda, smjer)) return false; //1
		return true;
	}
	if(lista[0]=="PO") { if(!ProvjeraZaPO(lista, greska, komanda)) return false; //2
	return true; }
	if(lista[0]=="Z") { if(!ProvjeraZaZ(lista, greska, komanda)) return false; //3
	return true; }
	if(lista[0]=="K")	{ if(!ProvjeraZaK(lista, greska, komanda)) return false; //4
	return true; }
	if(lista[0]=="P>") { if(!ProvjeraZaPs(lista, greska, komanda, x, y)) return false; //5
	return true; }
	if(lista[0]=="B") { if(!ProvjeraZaB(lista, greska, komanda, x, y)) return false; //6
		return true; }
	if(lista[0]=="D") { if(!ProvjeraZaD(lista, greska, komanda, x, y)) return false; //7
		return true;
	}
	greska=KodoviGresaka::PogresnaKomanda;
	return false; }

void PrijaviGresku(KodoviGresaka greska) {
	if(greska==KodoviGresaka::PogresnaKomanda) std::cout << "Nerazumljiva komanda!" << std::endl; 
	else if(greska==KodoviGresaka::NedostajeParametar) std::cout << "Komanda trazi parametar koji nije naveden!" << std::endl;
	else if(greska==KodoviGresaka::NeispravanParametar) std::cout << "Parametar komande nije ispravan!" << std::endl;
	else if(greska==KodoviGresaka::SuvisanParametar) std::cout << "Zadan je suvisan parametar nakon komande!" <<std::endl; }

bool IspravnostUnosaKoordinataZaIgru(std::string linija, int &x, int &y, int n) { //valjda radi nemam pojma iskreno
	unsigned short broj_otvorenih_zagrada(0); 
	unsigned short broj_zatvorenih_zagrada(0); 
	unsigned int short broj_zareza(0);
	unsigned short sve_ostalo_sto_nije_cifra_ili_space(0); 
	for(int i=0; i<linija.size(); i++) {
		/*prvo brisem sve space*/
		if(linija[i]==' ') {
			linija.erase(linija.begin()+i); 
			i--;
		}
		else if(linija[i]=='(') broj_otvorenih_zagrada++;
		else if(linija[i]==')') broj_zatvorenih_zagrada++;
		else if(linija[i]==',') broj_zareza++; 
		else if(!(linija[i]>='0' && linija[i]<='9')) sve_ostalo_sto_nije_cifra_ili_space++; //ovdje sam valjda osigurala da su svi cifre ostali
	}
	if(broj_otvorenih_zagrada!=1 || linija.size()<5 || broj_zatvorenih_zagrada!=1 || broj_zareza!=1 || sve_ostalo_sto_nije_cifra_ili_space!=0) return false;
	if(linija[0]!='(' || linija[linija.size()-1]!=')') return false;
	std::string broj1, broj2; 
		int i=1;
		while(linija[i]!=',') {broj1.push_back(linija[i]); i++;}
		if(linija[i]==',') i++; 
		while(i!=linija.size()-1) {broj2.push_back(linija[i]); i++; }
		if(broj1.size()==0 || broj2.size()==0) return false;
		x=std::stoi(broj1); if(x>=n) return false;
		y=std::stoi(broj2); if(y>=n) return false;
		return true; }

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer=Smjerovi::Gore, int p_x=0, int p_y=0) {
	if(komanda==Komande::ZavrsiIgru) {
		ObrisiTablu(polja); 
		throw std::runtime_error("Igra zavrsena");
	}
	else if(komanda==Komande::PomjeriJednoMjesto) {
		try {
		Status tekuci(Idi(polja, x, y, p_smjer)); // OVDJE nisi dodala jer mislis da je ok
		if(tekuci==Status::KrajPoraz || tekuci==Status::KrajPobjeda) {
			if(tekuci==Status::KrajPoraz) std::cout << "Nagazili ste na minu" << std::endl;
			if(tekuci==Status::KrajPobjeda) std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
			ObrisiTablu(polja); 
			throw std::runtime_error("Igra zavrsena");
		}
		
		std::cout << "Tekuca pozicija igraca je (" << x << "," << y <<")" << std::endl;  }
		catch(std::out_of_range asja) {
			std::cout << asja.what() << std::endl; //to endl or not to endl
		}
		catch(std::logic_error m) {
			std::cout << m.what() << std::endl; // ditto
		} 
	}
	
	else if(komanda==Komande::PomjeriDalje) {
		try {
		Status tekuci(Idi(polja, x, y, p_x, p_y));
		if(tekuci==Status::KrajPoraz || tekuci==Status::KrajPobjeda) {
			if(tekuci==Status::KrajPoraz) std::cout << "Nagazili ste na minu" << std::endl; 
			if(tekuci==Status::KrajPobjeda) std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
			ObrisiTablu(polja); 
			throw std::runtime_error("Igra zavrsena"); 
		}
		
		std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")" << std::endl; }
		catch(std::out_of_range asja) {
			std::cout << asja.what() << std::endl;  //opet isto s endline da ili ne
		}
		catch(std::logic_error m) {
			std::cout << m.what() << std::endl; // endl?????????????
		}
	}
	
	else if(komanda==Komande::Blokiraj) {
		try {
			BlokirajPolje(polja, p_x, p_y); /*///////////*/
		}
		catch(std::domain_error a) {
			std::cout << a.what() << std::endl; //ne znam jel ovdje treba novi red or not, eventualno jos jedno thow nemam poja
		}
	}
	
	else if(komanda==Komande::Deblokiraj) {
		try{
			DeblokirajPolje(polja, p_x, p_y); /*/////////////////////////////////*/
		}
		catch(std::domain_error a) {
			std::cout << a.what() << std::endl; //ditto
		}
	}
	
	else if(komanda==Komande::PrikaziOkolinu) {
		try {
		std::vector<std::vector<int>> okolo(PrikaziOkolinu(polja, x, y));
		for(auto &x : okolo) { //mozda treba s obicnom petljom da osiguras da ti nije onaj zadnji razmak razmak
			for(auto &y : x) 
			std::cout << y << " "; 
			std::cout << std::endl;
		} }
		catch(std::domain_error d) {
			std::cout << d.what() << std::endl; //to endl or not
		}
	}
	else if(komanda==Komande::KreirajIgru) {
		try {
		std::cout << "Unesite broj polja: "; // TO END LINE OR NOT TO END LINE?
		int n; //safe unos uradi ne mogu sad ja to *****************************************
		std::cin >> n ;
		while(n<=0) {
			std::cout << "Greska, unesite ponovo!" << std::endl; 
			std::cout << "Unesite broj polja: ";
			std::cin >> n; 
		}
		std::cin.ignore(100000, '\n');
		std::cin.clear();//ovdje pazi jel ovako ili nije
		std::string pozicija; 
		std::cout << "Unesite pozicije mina: ";
		
		std::vector<std::vector<int>> mine;
		int nekox(0), nekoy(0), i(0);
		
		while(pozicija.size()!=1 || pozicija[0]!='.') {
			std::getline(std::cin, pozicija); 
			if(pozicija==".") break;
		while(!IspravnostUnosaKoordinataZaIgru(pozicija, nekox, nekoy, n) && pozicija!=".") { //dodaj ono
			std::cout << "Greska, unesite ponovo!" << std::endl; 
			std::getline(std::cin, pozicija); 
		}
			mine.resize(i+1);
			mine[i].resize(2); 
			mine[i][0]=nekox;
			mine[i][1]=nekoy;
			i++;
		}
		polja=KreirajIgru(n,mine); 	} 
	catch (std::domain_error d) {
	//	std::cout << "Greska,unesite ponovo!" << std::endl; 
	} }
}

int main ()
{
	try {
		Tabla igra;
		int x(0),y(0), p_x(1), p_y(1);
		Komande komanda;
		Smjerovi smjer;
		KodoviGresaka greska;
		while(1) {
			std::cout << "Unesite komandu: ";
			while(!UnosKomande(komanda, smjer, p_x, p_y, greska)) PrijaviGresku(greska); 
			IzvrsiKomandu(komanda, igra , x, y, smjer, p_x, p_y);
		}
	}
	catch(std::runtime_error a) {
		std::cout << "Dovidjenja!"; 
	}
	
	return 0;
}
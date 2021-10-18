#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstring>
#include <complex>
#include <iomanip>
#include <string>

enum class Polje
{
    Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};
enum class Smjerovi
{
    GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};
enum class Status
{
    NijeKraj, KrajPoraz, KrajPobjeda
};
enum class Komande
{
    PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj,PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};
enum class KodoviGresaka
{
    PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};

bool provjera_unosa()
{
	while(std::cin.peek()==' ') std::cin.get();
	if(std::cin.peek()=='\n') return false;
	return true;
}
void PrijaviGresku(KodoviGresaka greska)
{
	const char*p[4] {"Nerazumljiva komanda!", "Komanda trazi parametar koji nije naveden!", "Zadan je suvisan parametar nakon komande!","Parametar komande nije ispravan!"};
	for(int i=0; i<4; i++) {
		if(greska==KodoviGresaka(i)) std::cout<<p[i]<<std::endl;
	}
}

void odstrani_gresku()
{
	if(provjera_unosa() || !std::cin) {
		std::cin.clear();
		std::cin.ignore(1000,'\n');
	}
}

typedef std::vector<std::vector<Polje>> Tabla;
bool provjera(int x, int y, int n)
{
	if(x>=0 && y>=0 && x<n && y<n) return true;
	return false;
}

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine)
{
	for(int i=0; i<mine.size(); i++) {
		if(mine.at(i).size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
		for(int j=0; j<2; j++) {
			if(mine.at(i).at(j)<0 || mine.at(i).at(j)>=n) throw std::domain_error("Ilegalne pozicije mina");
		}

	}
	if(n<=0) throw std:: domain_error("Ilegalna velicina");
	Tabla ploca(n, std::vector<Polje>(n,Polje::Prazno));
	for(int i=0; i<mine.size(); i++) {
		ploca.at(mine.at(i).at(0)).at(mine.at(i).at(1))=Polje::Mina;
	}

	return ploca;
}

int BrojMina(const Tabla &polja, int x, int y)
{
	int broj(0),dimenzija(polja.size());
	for(int i=x-1; i<=x+1; i++) {
		for(int j=y-1; j<=y+1; j++) {
			if(provjera(i,j,dimenzija)&& (i==x-1 || i==x+1 || j==y-1 || j==y+1) && polja.at(i).at(j)==Polje::Mina) broj++;
		}
	}
	return broj;
}

std::vector<std::vector<int>> PrikaziOkolinu (const Tabla &polja, int x, int y)
{
	if(!provjera(x,y,polja.size())) throw std::domain_error("Polje ("+ std::to_string(x)+"," +std::to_string(y)+") ne postoji");
	std::vector<std::vector<int>> okolina(3, std::vector<int>(3,0));
	for(int i=x-1; i<=x+1; i++) {
		for(int j=y-1; j<=y+1; j++) {
			okolina.at(i-x+1).at(j-y+1)=BrojMina(polja, i,j);
		}
	}
	return okolina;
}
void BlokirajPolje(Tabla &polja, int x, int y)
{
	if(!provjera(x,y,polja.size())) throw std::domain_error("Polje ("+ std::to_string(x)+"," +std::to_string(y)+") ne postoji");
	for(int i=0; i<3; i++) {
		if(polja.at(x).at(y)==Polje(i)) polja.at(x).at(y)=Polje(i+3);
	}
}

void DeblokirajPolje (Tabla &polja, int x, int y)
{
	if(!provjera(x,y,polja.size())) throw std::domain_error("Polje ("+ std::to_string(x)+"," +std::to_string(y)+") ne postoji");
	for(int i=3; i<6; i++) {
		if(polja.at(x).at(y)==Polje(i)) polja.at(x).at(y)=Polje(i-3);
	}
}
Status Pomocna( Tabla &polja, int x, int y, int& nova1, int& nova2)
{
	
	int dimenzija(polja.size());
	if(!provjera(x,y,dimenzija)) throw std::out_of_range("Izlazak van igrace table\n");
	if(polja.at(x).at(y)==Polje::BlokiranoPosjeceno || polja.at(x).at(y)==Polje::BlokiranoPrazno || polja.at(x).at(y)==Polje::BlokiranoMina)
		throw std::logic_error("Blokirano polje\n");

	if(polja.at(x).at(y)==Polje::Mina) {
		polja=Tabla (dimenzija, std::vector<Polje>(polja.size(), Polje::Prazno));
		return Status::KrajPoraz;
	}
	polja.at(nova1).at(nova2)=Polje::Posjeceno;
	nova1=x;
	nova2=y;
	for(int i=0; i<dimenzija; i++) {
		for(int j=0; j<dimenzija; j++) {
			if(polja.at(i).at(j)!=Polje::Posjeceno && polja.at(i).at(j)!=Polje::Mina) return Status::NijeKraj;

		}
	}
	return Status:: KrajPobjeda;
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer)
{
	int pomocna1(x), pomocna2(y);
	std::vector<std::vector<int> > promjena {{pomocna1-1,pomocna2-1}, {pomocna1-1,pomocna2},{pomocna1-1,pomocna2+1},{pomocna1,pomocna2+1}
		,{pomocna1+1,pomocna2+1},{pomocna1+1,pomocna2},{pomocna1+1,pomocna2-1},{pomocna1,pomocna2-1}
	};

	for(int i=0; i<8; i++) {
		if(smjer==Smjerovi(i)) {
			pomocna1=promjena.at(i).at(0);
			pomocna2=promjena.at(i).at(1);
		}
	}
	try {
		return Pomocna(polja, pomocna1, pomocna2, x,y);
	} catch(...) {
		throw;
	}
}

Status Idi (Tabla &polja, int &x, int &y, int novi_x, int novi_y)
{
	int pomocna1(novi_x),pomocna2(novi_y);
	try {
		return Pomocna(polja, pomocna1, pomocna2, x,y);
	} catch(...) {
		throw;
	}
}
bool UnosSmjera(Smjerovi &smjer, KodoviGresaka &greska)
{
	const char* niz_smjerovi[] {"GL","G","GD","D","DoD","Do","DoL","L"};
	char smjer1[30];
	int i;

	if(provjera_unosa()) {
		std::cin>>std::setw(29)>>smjer1;
		for( i=0; i<8; i++) {
			if(strcmp(smjer1,niz_smjerovi[i])==0) {
				smjer=Smjerovi(i);
				if(provjera_unosa()) {

					greska=KodoviGresaka::SuvisanParametar;
					odstrani_gresku();
					return false;
				}
				return true;
			}
		}
		if(i==8) {
			greska=KodoviGresaka::NeispravanParametar;
			odstrani_gresku();
			return false;
		}
	}
	greska=KodoviGresaka::NedostajeParametar;
	odstrani_gresku();
	return false;
}
bool UnosCijelih(int &x, int &y, KodoviGresaka &greska)
{
	int n;

	if(provjera_unosa()) {

		if(!(std::cin>>n) ||  (std::cin.peek()!=' ' && std::cin.peek()!='\n')) {
			greska=KodoviGresaka::NeispravanParametar;
			odstrani_gresku();
			return false;
		} else {
			x=n;

			if(provjera_unosa()) {

				if(!(std::cin>>n) || (std::cin.peek()!='\n' && std::cin.peek()!=' ')) {
					greska=KodoviGresaka::NeispravanParametar;
					odstrani_gresku();
					return false;
				} else {
					y=n;
					if(provjera_unosa()) {

						greska=KodoviGresaka::SuvisanParametar;
						odstrani_gresku();
						return false;
					}
					return true;
				}
			} else {
				greska=KodoviGresaka::NedostajeParametar;
				
			}
		}
	}
	greska=KodoviGresaka::NedostajeParametar;
	return false;
}
bool UnosKomande (Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska)
{
	const char * naredbe [7] {"P1","P>","B","D","PO","Z","K"};
	bool pogreska(true);
	char komanda1[30];

	std::cin>>std::ws;
	std::cin>>std::setw(29)>>komanda1;
	int indeks(-1);
	for(int i=0; i<7; i++) {
		if(strcmp(komanda1, naredbe[i])==0) {
			indeks=i;
			komanda=Komande(i);
		}

	}

	if(indeks!=-1) {
		if(indeks==0) pogreska=UnosSmjera(smjer,greska);

		else if(indeks < 4) pogreska=UnosCijelih(x,y,greska);
		else {
			if(provjera_unosa()) {

				greska=KodoviGresaka::SuvisanParametar;
				odstrani_gresku();
				return false;
			}

			return true;
		}
	} else {
		pogreska=false;
		greska=KodoviGresaka::PogresnaKomanda;
		odstrani_gresku();
	}
	return pogreska;
}
void UnosMina(Komande &komanda, Tabla&polja,int &x, int&y, Smjerovi p_smjer=Smjerovi::Gore, int p_x=0,int p_y=0)
{
	std::vector<std::vector<int>> mine;
	int n;
	bool greska(false);
	do {
		std::cout<<"Unesite broj polja: ";

		std::cin>>n;
		greska=false;
		bool unos=provjera_unosa();
		if(!std::cin  || n<=0 || unos) {
			greska=true;
			std::cout<<"Greska, unesite ponovo!"<<std::endl;
			if(!std::cin || unos ) {
				std::cin.clear();
				std::cin.ignore(1000, '\n');
			}
		}


	} while(greska);


	std::complex<int> kompleksni;
	std::cout<<"Unesite pozicije mina: ";
	do {
		greska=false;
		std::cin>>std::ws;
		if(std::cin.peek()=='.') {
			std::cin.clear();

			std::cin.ignore(1000,'\n');
			break;
		}
		if(std::cin.peek()!='(') greska=true;
		std::cin>>kompleksni;
		if(!std::cin || greska || !provjera(kompleksni.real(),kompleksni.imag(), n)) {
			std::cout<<"Greska, unesite ponovo!"<<std::endl;
			if(!std::cin || greska) {
				std::cin.clear();
				std::cin.ignore(1000,'\n');
			}
		} else {
			std::vector<int> d {kompleksni.real(),kompleksni.imag()};
			mine.push_back(d);
		}
	} while(true);
	polja=KreirajIgru(n, mine);
}
void PrikaziIspis(Komande &komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer=Smjerovi::Gore, int p_x=0, int p_y=0)
{
	std::vector<std::vector<int>> okolina=PrikaziOkolinu(polja, x,y);
	for(std::vector<int> d: okolina) {
		for(int m: d) std::cout<<m<<" ";
		std::cout<<std::endl;
	}
}
void DB(Komande &komanda, Tabla&polja, int &x, int &y, Smjerovi p_smjer=Smjerovi::Gore, int p_x=0, int p_y=0)
{
	if(komanda==Komande::Blokiraj) BlokirajPolje(polja, p_x,p_y);
	else DeblokirajPolje(polja, p_x,p_y);
}
void zavrsi (Komande &komanda, Tabla&polja, int &x, int &y, Smjerovi p_smjer=Smjerovi::Gore, int p_x=0, int p_y=0)
{
	polja=Tabla(polja.size(),std::vector<Polje>(polja.size(),Polje::Prazno));
	throw std::runtime_error("Dovidjenja!");
}
void Polozaj(Komande &komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer=Smjerovi::Gore, int p_x=0, int p_y=0)
{

	Status stanje;
	try {
		if(komanda==Komande::PomjeriJednoMjesto) stanje=Idi(polja, x,y,p_smjer);
		else stanje=Idi(polja,x,y,p_x,p_y);
		if(stanje!=Status::NijeKraj) {

			if(stanje==Status::KrajPoraz) std::cout<<"Nagazili ste na minu"<<std::endl;
			else std::cout<<"Bravo, obisli ste sva sigurna polja"<<std::endl;
			zavrsi(komanda,polja, x,y);
		} else std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
	} catch(...) {
		throw;
	}
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer=Smjerovi::Gore, int p_x=0, int p_y=0)
{
	void (*pok[7])(Komande&,Tabla&,  int&, int&, Smjerovi, int, int)= {Polozaj,Polozaj,DB,DB, PrikaziIspis,zavrsi, UnosMina};

	try {
		for(int i=0; i<7; i++) {
			if(komanda==Komande(i)) pok[i](komanda,polja,x,y,p_smjer,p_x,p_y);
		}
	} catch(...) {
		throw;
	}
}


int main ()
{
	KodoviGresaka greska;
	Komande komanda;
	Smjerovi smjer;
	int x(0), y(0),novi_x(0),novi_y(0);
	Tabla polja;
	while(true) {
		try {
			std::cout<<"Unesite komandu: ";
			if(UnosKomande(komanda, smjer, novi_x,novi_y, greska)) {
				IzvrsiKomandu(komanda,polja,x,y,smjer,novi_x,novi_y);
			} else {
				PrijaviGresku(greska);
			}
		}

		catch(std::domain_error izuzetak) {
			std::cout<<izuzetak.what();
			return 0;
		} catch(std::out_of_range izuzetak) {
			std::cout<<izuzetak.what();
			return 0;
		} catch(std::logic_error izuzetak) {
			std::cout<<izuzetak.what();
		} catch(std::runtime_error izuzetak) {
			std::cout<<izuzetak.what();
			return 0;
		}
	}
	return 0;
}
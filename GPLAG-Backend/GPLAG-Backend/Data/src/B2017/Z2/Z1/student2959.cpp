/*B 2017/2018, Zadaća 2, Zadatak 1

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <complex>
#include <sstream>

enum class Polje
{
    Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};

typedef std::vector<std::vector<Polje>> Tabla;

enum class Smjerovi
{
    GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};

enum class Status
{
    NijeKraj, KrajPoraz, KrajPobjeda
};

enum class KodoviGresaka
{
    PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};

enum class Komande
{
    PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};

template <typename T> std::string PretvoriUString(T x)
{
	std::ostringstream s;
	s<<x;
	return s.str();
}

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine)
{
	if(n<=0) throw std::domain_error ("Ilegalna velicina");
	Tabla igraca_tabla(n,std::vector<Polje>(n,Polje::Prazno));
	for(auto &red: mine) {
		if(red.size()!=2) throw std::domain_error ("Ilegalan format zadavanja mina");
		if(red.at(0)<0 || red.at(0)>=n || red.at(1)<0 || red.at(1)>=n) throw std::domain_error ("Ilegalne pozicije mina");
		igraca_tabla.at(red.at(0)).at(red.at(1))=Polje::Mina;
	}
	return igraca_tabla;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y)
{
	std::vector<std::vector<int>> okolina(3,std::vector<int>(3,0));
	int dimenzija(polja.size());
	if (x<0 || x>=dimenzija || y<0 || y>=dimenzija) throw std::domain_error("Polje ("+PretvoriUString(x)+","+PretvoriUString(y)+") ne postoji");
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			int br_mina(0);
			int p=x-1+i;
			int r=y-1+j;
			for(int m=p-1; m<p+2; m++) {
				if(m<0 || m>=dimenzija ) continue;
				for(int n=r-1; n<r+2; n++) {
					if(n<0 || n>=dimenzija )continue;
					if(m==p && n==r) continue;
					if(polja.at(m).at(n)==Polje::Mina)br_mina++;
				}
			}
			okolina.at(i).at(j)=br_mina;
		}
	}
	return okolina;
}

void BlokirajPolje(Tabla &polja, int x, int y)
{
	int dimenzija(polja.size());
	if (x<0 || x>=dimenzija || y<0 || y>=dimenzija) throw std::domain_error("Polje ("+PretvoriUString(x)+","+PretvoriUString(y)+") ne postoji");
	if(polja.at(x).at(y)==Polje::Prazno) polja.at(x).at(y)=Polje::BlokiranoPrazno;
	else if(polja.at(x).at(y)==Polje::Mina) polja.at(x).at(y)=Polje::BlokiranoMina;
	else if(polja.at(x).at(y)==Polje::Posjeceno) polja.at(x).at(y)=Polje::BlokiranoPosjeceno;
}

void DeblokirajPolje(Tabla &polja, int x, int y)
{
	int dimenzija(polja.size());
	if (x<0 || x>=dimenzija || y<0 || y>=dimenzija) throw std::domain_error("Polje ("+PretvoriUString(x)+","+PretvoriUString(y)+") ne postoji");
	if(polja.at(x).at(y)==Polje::BlokiranoPrazno) polja.at(x).at(y)=Polje::Prazno;
	else if(polja.at(x).at(y)==Polje::BlokiranoMina) polja.at(x).at(y)=Polje::Mina;
	else if(polja.at(x).at(y)==Polje::BlokiranoPosjeceno) polja.at(x).at(y)=Polje::Posjeceno;
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer)
{
	int dimenzija(polja.size());
	int novi_x(x),novi_y(y);
	if(smjer==Smjerovi::Gore || smjer==Smjerovi::GoreDesno || smjer==Smjerovi::GoreLijevo) novi_x--;
	else if(smjer==Smjerovi::Dolje || smjer==Smjerovi::DoljeDesno || smjer==Smjerovi::DoljeLijevo) novi_x++;
	if(smjer==Smjerovi::Desno || smjer==Smjerovi::GoreDesno || smjer==Smjerovi::DoljeDesno) novi_y++;
	else if(smjer==Smjerovi::Lijevo || smjer==Smjerovi::GoreLijevo || smjer==Smjerovi::DoljeLijevo) novi_y--;

	if (novi_x<0 || novi_x>=dimenzija || novi_y<0 || novi_y>=dimenzija) throw std::out_of_range("Izlazak van igrace table");
	if (polja.at(novi_x).at(novi_y)==Polje::BlokiranoPosjeceno || polja.at(novi_x).at(novi_y)==Polje::BlokiranoMina || polja.at(novi_x).at(novi_y)==Polje::BlokiranoPrazno)
		throw std::logic_error("Blokirano polje");
	polja.at(x).at(y)=Polje::Posjeceno;
	x=novi_x;
	y=novi_y;
	if(polja.at(x).at(y)==Polje::Mina) {
		for(auto &red:polja)
			for(auto &j: red) j=Polje::Prazno;
		return Status::KrajPoraz;
	}
	bool kraj(true);
	for(int i=0; i<dimenzija; i++) {
		for(int j=0; j<dimenzija; j++) {
			if(i==x && j==y) continue;
			if(polja.at(i).at(j)!=Polje::Mina && polja.at(i).at(j)!=Polje::Posjeceno && polja.at(i).at(j)!=Polje::BlokiranoMina) {
				kraj=false;
				break;
			}
		}
	}
	if(kraj) return Status::KrajPobjeda;
	return Status::NijeKraj;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y)
{
	int dimenzija(polja.size());
	if (novi_x<0 || novi_x>=dimenzija || novi_y<0 || novi_y>=dimenzija) throw std::out_of_range("Izlazak van igrace table");
	if (polja.at(novi_x).at(novi_y)==Polje::BlokiranoPosjeceno || polja.at(novi_x).at(novi_y)==Polje::BlokiranoMina || polja.at(novi_x).at(novi_y)==Polje::BlokiranoPrazno) 
		throw std::logic_error("Blokirano polje");
	polja.at(x).at(y)=Polje::Posjeceno;
	x=novi_x;
	y=novi_y;
	if(polja.at(x).at(y)==Polje::Mina) {
		for(auto &red : polja)
			for(auto &j : red) j=Polje::Prazno;
		return Status::KrajPoraz;
	}
	bool kraj(true);
	for(int i=0; i<dimenzija; i++) {
		for(int j=0; j<dimenzija; j++) {
			if(i==x && j==y) continue;
			if(polja.at(i).at(j)!=Polje::Mina && polja.at(i).at(j)!=Polje::Posjeceno && polja.at(i).at(j)!=Polje::BlokiranoMina) {
				kraj=false;
				break;
			}
		}
	}
	if(kraj) return Status::KrajPobjeda;
	return Status::NijeKraj;
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int&y, KodoviGresaka &greska)
{
	std::string prvi;
	std::cin>>prvi;
	if(prvi=="P1") {
		komanda=Komande::PomjeriJednoMjesto;
		while(std::cin.peek()==' ') std::cin.get();
		if(std::cin.peek()=='\n') {greska=KodoviGresaka::NedostajeParametar; return false; }
		else {
			std::string drugi;
			std::cin>>drugi;
			if(drugi=="GL") smjer=Smjerovi::GoreLijevo;
			else if(drugi=="GD") smjer=Smjerovi::GoreDesno;
			else if(drugi=="G") smjer=Smjerovi::Gore;
			else if(drugi=="D") smjer=Smjerovi::Desno;
			else if(drugi=="DoD") smjer=Smjerovi::DoljeDesno;
			else if(drugi=="GL") smjer=Smjerovi::GoreLijevo;
			else if(drugi=="Do") smjer=Smjerovi::Dolje;
			else if(drugi=="DoL") smjer=Smjerovi::DoljeLijevo;
			else if(drugi=="L") smjer=Smjerovi::Lijevo;
			else {greska=KodoviGresaka::NeispravanParametar;std::cin.ignore(10000,'\n'); return false; }
			while(std::cin.peek()==' ') std::cin.get();
				if(std::cin.peek()!='\n') {
					greska=KodoviGresaka::SuvisanParametar;
					std::cin.ignore(10000,'\n');
					return false;
				}
		}
	} else if(prvi=="P>") komanda=Komande::PomjeriDalje;
	else if(prvi=="B") komanda=Komande::Blokiraj;
	else if(prvi=="D") komanda=Komande::Deblokiraj;
	else if(prvi=="PO") komanda=Komande::PrikaziOkolinu;
	else if(prvi=="Z") komanda=Komande::ZavrsiIgru;
	else if(prvi=="K") komanda=Komande::KreirajIgru;
	else {
		greska=KodoviGresaka::PogresnaKomanda;
		std::cin.ignore(10000,'\n');
		return false;
	}

	if(prvi=="P>" || prvi=="B" || prvi=="D") {
		while(std::cin.peek()==' ') std::cin.get();
		if(std::cin.peek()=='\n') {greska=KodoviGresaka::NedostajeParametar;return false; }
		else {
			std::cin>>x;
			if(!std::cin) {
				greska=KodoviGresaka::NeispravanParametar;
				std::cin.clear();
				std::cin.ignore(10000,'\n');
				return false;
			}
			while(std::cin.peek()==' ') std::cin.get();
			if(std::cin.peek()=='\n') {
				greska=KodoviGresaka::NedostajeParametar;
				std::cin.ignore(10000,'\n');
				return false;
			} else {
				std::cin>>y;
				if(!std::cin) {
					greska=KodoviGresaka::NeispravanParametar;
					std::cin.clear();
					std::cin.ignore(10000,'\n');
					return false;
				}
				while(std::cin.peek()==' ') std::cin.get();
				if(std::cin.peek()!='\n') {
					greska=KodoviGresaka::SuvisanParametar;
					std::cin.ignore(10000,'\n');
					return false;
				}
			}
		}
	}

	else if(prvi=="PO" || prvi=="Z" || prvi=="K") {
		while(std::cin.peek()==' ') std::cin.get();
		if(std::cin.peek()!='\n') {
			greska=KodoviGresaka::SuvisanParametar;
			std::cin.ignore(10000,'\n');
			return false;
		}
	}
	return true;
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y=0)
{
	try {
		Status s;
		if(komanda==Komande::PrikaziOkolinu) {
			auto matrica_okoline=PrikaziOkolinu(polja,x,y);
			for(auto &red:matrica_okoline) {
				for(auto j: red) std::cout<<j<<" ";
				std::cout<<std::endl;
			}
		} else if(komanda==Komande::Blokiraj) BlokirajPolje(polja,p_x,p_y);
		else if(komanda==Komande::Deblokiraj) DeblokirajPolje(polja,p_x,p_y);
		else if(komanda==Komande::PomjeriJednoMjesto) s=Idi(polja,x,y,p_smjer);
		else if(komanda==Komande::PomjeriDalje) s=Idi(polja,x,y,p_x,p_y);
		else if(komanda==Komande::ZavrsiIgru) {
			for(auto &red:polja)
				for(auto &j: red) j=Polje::Prazno;
			throw std::runtime_error ("Igra zavrsena");
		} else if(komanda==Komande::KreirajIgru) {
			int n;
			for(;;) {
				std::cout<<"Unesite broj polja: ";
				std::cin>>n;
				if(!std::cin || n<=0) {
					std::cout<<"Greska, unesite ponovo!"<<std::endl;
					std::cin.clear();
					std::cin.ignore(10000,'\n');
				} else break;
			}
			std::vector<std::vector<int>> mine;
			std::cout<<"Unesite pozicije mina: ";
			bool kraj(false);
			mine.resize(0);
			char z;
			int a,b;
			for(;;) {
				for(;;) {
					bool neispravno(false);
					std::cin.ignore(10000,'\n');
					std::cin>>z;
					if(z=='.') {
						kraj=true;
						break;
					} else if(z=='(') {
						std::cin>>a;
						if(!std::cin || a<0 || a>=n) neispravno=true;
						else {
							std::cin>>z;
							if(z!=',') neispravno=true;
							else {
								std::cin>>b;
								if(!std::cin || b<0 || b>=n) neispravno=true;
								else {
									std::cin>>z;
									if(z!=')') neispravno=true;
									else if(std::cin.peek()!=' ' && std::cin.peek()!='\n') neispravno=true;
								}
							}
						}
					} else neispravno=true;
					if(a==0 && b==0) neispravno=true;
					if(!neispravno) break;
					else {
						std::cout<<"Greska, unesite ponovo!"<<std::endl;
						std::cin.clear();
					}
				}
				if(!kraj) {
					std::vector<int> d(0);
					d.push_back(a);
					d.push_back(b);
					mine.push_back(d);
				} else break;
			}
			polja=KreirajIgru(n,mine);
		}
		if(komanda==Komande::PomjeriJednoMjesto || komanda==Komande::PomjeriDalje) {
			std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
			if(s==Status::KrajPobjeda) std::cout<<"Bravo, obisli ste sva sigurna polja"<<std::endl;
			else if(s==Status::KrajPoraz) {
				std::cout<<"Nagazili ste na minu"<<std::endl;
				for(auto &red:polja)
					for(auto &j: red) j=Polje::Prazno;
				throw std::runtime_error ("Igra zavrsena");
			}
		}
	} catch(std::exception &izuzetak) {
		std::cout<<izuzetak.what()<<std::endl;
	}
}
void PrijaviGresku(KodoviGresaka greska)
{
	if(greska==KodoviGresaka::PogresnaKomanda) std::cout<<"Nerazumljiva komanda!"<<std::endl;
	else if(greska==KodoviGresaka::NedostajeParametar) std::cout<<"Komanda trazi parametar koji nije naveden!"<<std::endl;
	else if(greska==KodoviGresaka::NeispravanParametar) std::cout<<"Parametar komande nije ispravan!"<<std::endl;
	else if(greska==KodoviGresaka::SuvisanParametar) std::cout<<"Zadan je suvisan parametar nakon komande!"<<std::endl;
}

int main ()
{
	Komande komanda;
	Smjerovi smjer;
	int x(0), y(0), novi_x(0), novi_y(0);
	KodoviGresaka greska;
	Tabla polja(0);
	for(;;) {
		std::cout<<"Unesite komandu: ";
		if(UnosKomande(komanda,smjer,novi_x,novi_y,greska)) {
			if(komanda==Komande::ZavrsiIgru) {
				std::cout<<"Dovidjenja!";
				break;
			} else IzvrsiKomandu(komanda,polja,x,y,smjer,novi_x,novi_y);
		} else PrijaviGresku(greska);
	}
	return 0;
}
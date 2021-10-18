#include <iostream>
#include <vector>
#include <stdexcept>
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
enum class KodoviGresaka
{
    PogresnaKomanda, NedostajeParmetar, SuvisanParametar, NeispravanParametar
};
enum class Komande
{
    PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};
typedef std::vector<std::vector<Polje>> Tabla;


Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine)
{
	if(n<=0) throw std::domain_error("Ilegalna veličina");
	for(auto v : mine) {
		if(v.size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
		else {
			if(v.at(0)<0 || v.at(0)>=n || v.at(1)<0 || v.at(1)>=n) throw std::domain_error("Ilegalne pozicije mina");
		}
	}

	Tabla polja(n,std::vector<Polje>(n));
	for(auto v : mine) {
		polja.at(v.at(0)).at(v.at(1))=Polje(2);
	}
	return polja;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y)
{
	if(x<0 || y<0 || x>=polja.size() || y>=polja.at(0).size()) {
		throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	}

	std::vector<std::vector<int>> okolina(3,std::vector<int>(3));

	int broj1(0),broj2(0);
	for(int i=x-1; i<=x+1; i++) {
		for(int j=y-1; j<=y+1; j++) {
			int suma(0);
			for(int k=i-1; k<=i+1; k++) {
				for(int l=j-1; l<=j+1; l++) {
					try {
						if((k!=i || l!=j) && polja.at(k).at(l)==Polje(2)) suma++;
					} catch(...) {}
				}
			}
			if(broj2==3) broj2=0;
			okolina.at(broj1).at(broj2++)=suma;
		}
		broj1++;
	}
	return okolina;
}

void BlokirajPolje(Tabla &polja, int x, int y)
{
	if(x<0 || y<0 || x>=polja.size() || y>=polja.at(0).size()) {
		throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	}

	if((int)polja.at(x).at(y)<3) polja.at(x).at(y)=Polje((int)polja.at(x).at(y)+3);
}

void DeblokirajPolje(Tabla &polja, int x, int y)
{
	if(x<0 || y<0 || x>=polja.size() || y>=polja.at(0).size()) {
		throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	}

	if((int)polja.at(x).at(y)>=3) polja.at(x).at(y)=Polje((int)polja.at(x).at(y)-3);
}
bool Pobjeda(const Tabla &polja)
{
	for(auto v : polja) {
		for(auto x : v)
			if(int(x)!=1 && int(x)!=4) return false;
	}
	return true;
}
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer)
{
	int dl(0),gd(0); //desno-lijevo, gore-dole
	bool error(false);
	if(smjer==Smjerovi(0)) {
		dl=-1,gd=-1;
	} else if(smjer==Smjerovi(1)) {
		gd=-1;
	} else if(smjer==Smjerovi(2)) {
		gd=-1;
		dl=1;
	} else if(smjer==Smjerovi(3)) {
		dl=1;
	} else if(smjer==Smjerovi(4)) {
		gd=1;
		dl=1;
	} else if(smjer==Smjerovi(5)) {
		gd=1;
	} else if(smjer==Smjerovi(6)) {
		gd=1;
		dl=-1;
	} else if(smjer==Smjerovi(7)) {
		dl=-1;
	}
	try {
		std::cout<<x<<" "<<y<<std::endl;
		if(polja.at(x+gd).at(y+dl)==Polje(0) || polja.at(x+gd).at(y+dl)==Polje(1)) {
			polja.at(x+gd).at(y+dl)=Polje(1);
			x+=gd;
			y+=dl;
			std::cout<<x<<" "<<y<<std::endl;
			if(Pobjeda(polja)) return Status(2);
			return Status(0);
		} else if(int(polja.at(x+gd).at(y+dl))>=3) error=true;
		else if(polja.at(x+gd).at(y+dl)==Polje(2)) {
			x+=gd;
			y+=dl;
			return Status(1);
		}
	} catch(std::logic_error izuzetak) {
		throw std::range_error("Izlazak van igrace table");
	}
	if(error) throw std::logic_error("Blokirano polje");
}
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y)
{
	bool error(false);
	try {
		if(polja.at(novi_x).at(novi_y)==Polje(0) || polja.at(novi_x).at(novi_y)==Polje(1)) {
			polja.at(novi_x).at(novi_y)=Polje(1);
			x=novi_x;
			y=novi_y;
			if(Pobjeda(polja)) return Status(2);
			return Status(0);
		} else if(int(polja.at(novi_x).at(novi_y))>=3) error=true;
		else if(polja.at(novi_x).at(novi_y)==Polje(2)) {
			x=novi_x;
			y=novi_y;
			return Status(1);
		}
	} catch(std::logic_error izuzetak) {
		throw std::range_error("Izlazak van igrace table");
	}
	if(error) throw std::logic_error("Blokirano polje");
}
void Ocisti(Tabla &polja)
{
	for(auto &v : polja) {
		for(auto &x : v)
			x=Polje(0);
	}
}
void PrijaviGresku(KodoviGresaka greska)
{
	if(greska==KodoviGresaka::PogresnaKomanda) std::cout<<"Nerazumljiva komanda!"<<std::endl;
	else if(greska==KodoviGresaka::NedostajeParmetar) std::cout<<"Komanda trazi parametar koji nije naveden!"<<std::endl;
	else if(greska==KodoviGresaka::NeispravanParametar) std::cout<<"Parametar komande nije ispravan!"<<std::endl;
	else if(greska==KodoviGresaka::SuvisanParametar) std::cout<<"Zadan je suvisan parametar nakon komadne!"<<std::endl;
}
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska)
{
	std::cout<<"Unesite komandu: ";
	std::string unos;
	std::cin>>unos;
	while(std::cin.peek()==' ') std::cin.get();
	if(unos=="P1") {
		if(std::cin.peek()=='\n') {
			greska=KodoviGresaka::NedostajeParmetar;
			std::cin.ignore(1000,'\n');
			return false;
		}
		std::string parametri;
		std::cin>>parametri;
		while(std::cin.peek()==' ') std::cin.get();
		if(std::cin.peek()=='\n') { //Normala
			if(parametri=="GL") smjer=Smjerovi::GoreLijevo;
			else if(parametri=="G") smjer=Smjerovi::Gore;
			else if(parametri=="GD") smjer=Smjerovi::GoreDesno;
			else if(parametri=="D") smjer=Smjerovi::Desno;
			else if(parametri=="DoD") smjer=Smjerovi::DoljeDesno;
			else if(parametri=="Do") smjer=Smjerovi::Dolje;
			else if(parametri=="DoL") smjer=Smjerovi::DoljeLijevo;
			else if(parametri=="L") smjer=Smjerovi::Lijevo;
			else {
				greska=KodoviGresaka::NeispravanParametar;
				std::cin.ignore(1000,'\n');
				return false;
			}
			komanda=Komande::PomjeriJednoMjesto;
		} else { //Viska parametri
			greska=KodoviGresaka::SuvisanParametar;
			std::cin.ignore(1000,'\n');
			return false;
		}
	} else if(unos=="K") {
		if(std::cin.peek()=='\n') { //Normala
			komanda=Komande::KreirajIgru;
			return true;
		} else { //Viska parametri
			greska=KodoviGresaka::SuvisanParametar;
			std::cin.ignore(1000,'\n');
			return false;
		}
	} else {
		greska=KodoviGresaka::PogresnaKomanda;
		std::cin.ignore(1000,'\n');
		return false;
	}
	std::cin.ignore(1000,'\n');
	return true;
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0)
{
	if(komanda==Komande::ZavrsiIgru) throw std::runtime_error("Igra zavrsena");
	else if(komanda==Komande::PomjeriJednoMjesto) {
		Status stanje=Idi(polja,x,y,p_smjer);
		if(stanje==Status::KrajPoraz) {
			std::cout<<"Nagazili ste na minu"<<std::endl;
			throw std::runtime_error("Igra zavrsena");
		} else if(stanje==Status::KrajPoraz) {
			std::cout<<"Bravo, obisli ste sva sigurna polja"<<std::endl;
			throw std::runtime_error("Igra zavrsena");
		}
	} else if(komanda==Komande::KreirajIgru) {
		int n;
		while(1) {
			std::cout<<"Unesite broj polja: ";
			std::cin>>n;
			if(std::cin.peek()=='\n') break;
			else {
				std::cout<<"Greska, unesite ponovo!"<<std::endl;
				std::cin.clear();
				std::cin.ignore(1000,'\n');
			}
		}
		std::vector<std::vector<int>> mine;
		std::cout<<"Unesite pozicije mina: ";
		int broj(0);
		while(1) {
			try {
				char c;
				int xm(0),ym(0);
				std::cin>>c;
				if(c=='.') break;
				else if(c!='(') throw std::domain_error("");
				else {
					if(std::cin.peek()=='\n') throw std::domain_error("");
					std::cin>>xm;
					if(std::cin.peek()=='\n') throw std::domain_error("");
					if(!std::cin) {
						throw std::domain_error("");
					}
					while(std::cin.peek()==' ') std::cin.get();
					if(std::cin.peek()!=',') {
						throw std::domain_error("");
					}
					std::cin.get();
					if(std::cin.peek()=='\n') throw std::domain_error("");
					std::cin>>ym;
					if(std::cin.peek()=='\n') throw std::domain_error("");
					if(!std::cin) {
						throw std::domain_error("");
					}
					while(std::cin.peek()==' ') std::cin.get();
					if(std::cin.peek()!=')') {
						throw std::domain_error("");
					}
					std::cin.get();
					if(std::cin.peek()!='\n') throw std::domain_error("");
				}
				std::cin.ignore(1000,'\n');
				mine.push_back(std::vector<int>());
				mine.at(broj).push_back(xm);
				mine.at(broj).push_back(ym);
				broj++;
			} catch(std::domain_error a) {
				std::cin.clear();
				std::cin.ignore(1000,'\n');
				std::cout<<"Greska, unesite ponovo!"<<std::endl;
			}
		}
		polja=KreirajIgru(n,mine);
	}
}
int main ()
{
	Tabla polja(0);
	int x=0,y=0;
	while(1) {
		try {
			Komande komanda;
			Smjerovi smjer;
			KodoviGresaka greska;
			bool unos=UnosKomande(komanda,smjer,x,y,greska);
			if(unos) IzvrsiKomandu(komanda,polja,x,y,smjer);
			else PrijaviGresku(greska);

		} catch(std::domain_error izuzetak) {
			std::cout<<"Domain_Error: "<<izuzetak.what()<<std::endl;
		} catch(std::range_error izuzetak) {
			std::cout<<"Range_Error: "<<izuzetak.what()<<std::endl;
		} catch(std::logic_error izuzetak) {
			std::cout<<"Logic_Error: "<<izuzetak.what()<<std::endl;
		} catch(std::runtime_error izuzetak) {
			std::cout<<"Runtime_Error: "<<izuzetak.what()<<std::endl;
			break;
		}
	}
	std::cout<<"Dovidjenja!";
	return 0;
}
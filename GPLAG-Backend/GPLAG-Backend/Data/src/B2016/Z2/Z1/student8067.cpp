/*B 16/17, Zadaća 2, Zadatak 1

	NAPOMENA: i javni ATo-vi su dio postavke

	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba

*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <cmath>
#include <complex>

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
    PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};
enum class Komande
{
    PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine)
{

	Tabla ploca(n, std::vector<Polje>(n, Polje::Prazno));
	for(int i(0); i<mine.size(); i++) {
		for(int j(0); j<mine.at(i).size(); j++) {
			if(mine.at(i).size()!=2) throw std::domain_error("“Ilegalan format zadavanja mina");
			if(mine.at(i).at(j)<0 || mine.at(i).at(j)>=n) throw std::domain_error("Ilegalne pozicije mina");
			ploca.at(mine.at(i).at(0)).at(mine.at(i).at(1))=Polje::Mina;
		}
	}
	return ploca;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y)
{
	std::vector<std::vector<int>> matrica;
	matrica.resize(3);
	if(x<0 || x>=polja.size() || y<0 || y>=polja.at(0).size()) throw std::domain_error("Polje (x,y) ne postoji");
	int m(0);
	for(int i(0); i<polja.size(); i++) {
		for(int j(0); j<polja.at(i).size(); j++) {
			int brojac(0);
			if((std::abs(i-x)==1 || x==i) && (std::abs(j-y)==1 || j==y))  {
				if(i==0) {
					if(j==0) {
						if(polja.at(i).at(j+1)==Polje::Mina) brojac++;
						if(polja.at(i+1).at(j)==Polje::Mina) brojac++;
						if(polja.at(i+1).at(j+1)==Polje::Mina) brojac++;
					} else if(j==polja.at(i).size()-1) {
						if(polja.at(i+1).at(j)==Polje::Mina) brojac++;
						if(polja.at(i).at(j-1)==Polje::Mina) brojac++;
						if(polja.at(i+1).at(j-1)==Polje::Mina) brojac++;

					} else {
						if(polja.at(i).at(j+1)==Polje::Mina) brojac++;
						if(polja.at(i+1).at(j)==Polje::Mina) brojac++;
						if(polja.at(i+1).at(j+1)==Polje::Mina) brojac++;
						if(polja.at(i).at(j-1)==Polje::Mina) brojac++;
						if(polja.at(i+1).at(j-1)==Polje::Mina) brojac++;

					}

				} else if(i==polja.size()-1) {
					if(j==0) {
						if(polja.at(i).at(j+1)==Polje::Mina) brojac++;
						if(polja.at(i-1).at(j)==Polje::Mina) brojac++;
						if(polja.at(i-1).at(j+1)==Polje::Mina) brojac++;
					} else if(j==polja.at(i).size()-1) {
						if(polja.at(i-1).at(j)==Polje::Mina) brojac++;
						if(polja.at(i).at(j-1)==Polje::Mina) brojac++;
						if(polja.at(i-1).at(j-1)==Polje::Mina) brojac++;

					} else {
						if(polja.at(i).at(j+1)==Polje::Mina) brojac++;
						if(polja.at(i-1).at(j)==Polje::Mina) brojac++;
						if(polja.at(i-1).at(j+1)==Polje::Mina) brojac++;
						if(polja.at(i).at(j-1)==Polje::Mina) brojac++;
						if(polja.at(i-1).at(j-1)==Polje::Mina) brojac++;

					}

				} else {
					if(j==0) {
						if(polja.at(i).at(j+1)==Polje::Mina) brojac++;
						if(polja.at(i-1).at(j)==Polje::Mina) brojac++;
						if(polja.at(i-1).at(j+1)==Polje::Mina) brojac++;
						if(polja.at(i+1).at(j)==Polje::Mina) brojac++;
						if(polja.at(i+1).at(j+1)==Polje::Mina) brojac++;

						else if(j==polja.at(i).size()-1) {
							if(polja.at(i).at(j-1)==Polje::Mina) brojac++;
							if(polja.at(i-1).at(j-1)==Polje::Mina) brojac++;
							if(polja.at(i+1).at(j-1)==Polje::Mina) brojac++;
							if(polja.at(i+1).at(j)==Polje::Mina) brojac++;
							if(polja.at(i-1).at(j)==Polje::Mina) brojac++;
						} else {
							if(polja.at(i).at(j-1)==Polje::Mina) brojac++;
							if(polja.at(i-1).at(j-1)==Polje::Mina) brojac++;
							if(polja.at(i+1).at(j-1)==Polje::Mina) brojac++;
							if(polja.at(i+1).at(j)==Polje::Mina) brojac++;
							if(polja.at(i-1).at(j)==Polje::Mina) brojac++;
							if(polja.at(i-1).at(j+1)==Polje::Mina) brojac++;
							if(polja.at(i).at(j+1)==Polje::Mina) brojac++;
							if(polja.at(i+1).at(j+1)==Polje::Mina) brojac++;

						}

					}

				}
				matrica.at(m).push_back(brojac);
				if(matrica.at(m).size()==3 && m<2) m++;
			}
		}
	}
	return matrica;
}
void BlokirajPolje(Tabla &polja, int x, int y)
{
	if(x<0 || x>=polja.size() || y<0 || y>=polja.at(0).size()) throw std::domain_error("Polje (x,y) ne postoji");
	for(int i(0); i<polja.size(); i++) {
		for(int j(0); j<polja.at(i).size(); j++) {
			if(x==i && y==j) {
				if(polja.at(x).at(y)==Polje::Prazno)
					polja.at(x).at(y)=Polje::BlokiranoPrazno;
				if(polja.at(x).at(y)==Polje::Posjeceno)
					polja.at(x).at(y)=Polje::BlokiranoPosjeceno;
				if(polja.at(x).at(y)==Polje::Mina)
					polja.at(x).at(y)=Polje::BlokiranoMina;
			}
		}
	}
}

void DeblokirajPolje(Tabla &polja, int x, int y)
{
	if(x<0 || x>=polja.size() || y<0 || y>=polja.at(0).size()) throw std::domain_error("Polje (x,y) ne postoji");
	for(int i(0); i<polja.size(); i++) {
		for(int j(0); j<polja.at(i).size(); j++) {
			if(x==i && y==j) {
				if(polja.at(x).at(y)==Polje::BlokiranoPrazno)
					polja.at(x).at(y)=Polje::Prazno;
				if(polja.at(x).at(y)==Polje::BlokiranoPosjeceno)
					polja.at(x).at(y)=Polje::Posjeceno;
				if(polja.at(x).at(y)==Polje::BlokiranoMina)
					polja.at(x).at(y)=Polje::Mina;
			}
		}
	}
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer)
{
	polja.at(x).at(y)=Polje::Posjeceno;
	if(Smjerovi::GoreLijevo==smjer) {
		if(x==0 || y==0) throw std::out_of_range("Izlazak van igrace table");
		if(polja.at(x-1).at(y-1)==Polje::BlokiranoPosjeceno || polja.at(x-1).at(y-1)==Polje::BlokiranoPrazno || polja.at(x-1).at(y-1)==Polje::BlokiranoMina)
			throw std::logic_error("Blokirano polje");
		x=x-1;
		y=y-1;
	}
	if(Smjerovi::Gore==smjer) {
		if(x==0) throw std::out_of_range("Izlazak van igrace table");
		if(polja.at(x-1).at(y)==Polje::BlokiranoPosjeceno || polja.at(x-1).at(y)==Polje::BlokiranoPrazno || polja.at(x-1).at(y)==Polje::BlokiranoMina)
			throw std::logic_error("Blokirano polje");
		x=x-1;
	}
	if(Smjerovi::GoreDesno==smjer) {
		if(x==0 || y==polja.at(0).size()-1) throw std::out_of_range("Izlazak van igrace table");
		if(polja.at(x-1).at(y+1)==Polje::BlokiranoPosjeceno || polja.at(x-1).at(y+1)==Polje::BlokiranoPrazno || polja.at(x-1).at(y+1)==Polje::BlokiranoMina)
			throw std::logic_error("Blokirano polje");
		x=x-1;
		y=y+1;
	}
	if(Smjerovi::Lijevo==smjer) {
		if(y==0) throw std::out_of_range("Izlazak van igrace table");
		if(polja.at(x).at(y-1)==Polje::BlokiranoPosjeceno || polja.at(x).at(y-1)==Polje::BlokiranoPrazno || polja.at(x).at(y-1)==Polje::BlokiranoMina)
			throw std::logic_error("Blokirano polje");
		y=y-1;
	}
	if(Smjerovi::Desno==smjer) {
		if(y==polja.at(0).size()-1) throw std::out_of_range("Izlazak van igrace table");
		if(polja.at(x).at(y+1)==Polje::BlokiranoPosjeceno || polja.at(x).at(y+1)==Polje::BlokiranoPrazno || polja.at(x).at(y+1)==Polje::BlokiranoMina)
			throw std::logic_error("Blokirano polje");

		y=y+1;
	}
	if(Smjerovi::DoljeLijevo==smjer) {
		if(x==polja.size()-1 || y==0) throw std::out_of_range("Izlazak van igrace table");
		if(polja.at(x+1).at(y-1)==Polje::BlokiranoPosjeceno || polja.at(x+1).at(y-1)==Polje::BlokiranoPrazno || polja.at(x+1).at(y-1)==Polje::BlokiranoMina)
			throw std::logic_error("Blokirano polje");

		x=x+1;
		y=y-1;
	}
	if(Smjerovi::Dolje==smjer) {
		if(x==polja.size()-1) throw std::out_of_range("Izlazak van igrace table");
		if(polja.at(x+1).at(y)==Polje::BlokiranoPosjeceno || polja.at(x+1).at(y)==Polje::BlokiranoPrazno || polja.at(x+1).at(y)==Polje::BlokiranoMina)
			throw std::logic_error("Blokirano polje");

		x=x+1;
	}
	if(Smjerovi::DoljeDesno==smjer) {
		if(x==polja.size()-1 || y==polja.at(0).size()-1) throw std::out_of_range("Izlazak van igrace table");
		if(polja.at(x+1).at(y+1)==Polje::BlokiranoPosjeceno || polja.at(x+1).at(y+1)==Polje::BlokiranoPrazno || polja.at(x+1).at(y+1)==Polje::BlokiranoMina)
			throw std::logic_error("Blokirano polje");

		x=x+1;
		y=y+1;
	}

	if(polja.at(x).at(y)==Polje::Mina) {
		for(int i(0); i<polja.size(); i++) {
			for(int j(0); j<polja.at(i).size(); j++) {
				polja.at(i).at(j)=Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
	bool m(true);
	for(int i(0); i<polja.size(); i++) {
		for(int j(0); j<polja.at(i).size(); j++) {
			if(polja.at(i).at(j)==Polje::Prazno) {
				m=false;
				break;

			}
		}
	}
	if(m==true) return Status::KrajPobjeda;
	return Status::NijeKraj;

}
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y)
{

	if(novi_x<0 || novi_y<0 || novi_x>=polja.size() || novi_y>=polja.at(0).size()) throw std::out_of_range("Izlazak van igrace table");
	polja.at(x).at(y)=Polje::Posjeceno;
	if(polja.at(novi_x).at(novi_y)==Polje::BlokiranoPosjeceno || polja.at(novi_x).at(novi_y)==Polje::BlokiranoPrazno || polja.at(novi_x).at(novi_y)==Polje::BlokiranoMina)
		throw std::logic_error("Blokirano polje");
	x=novi_x;
	y=novi_y;
	if(polja.at(x).at(y)==Polje::Mina) {
		for(int i(0); i<polja.size(); i++) {
			for(int j(0); j<polja.at(i).size(); j++) {
				polja.at(i).at(j)=Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
	bool m(true);
	for(int i(0); i<polja.size(); i++) {
		for(int j(0); j<polja.at(i).size(); j++) {
			if(polja.at(i).at(j)==Polje::Prazno) {
				m=false;
				break;
			}
		}
	}
	if(m==true) return Status::KrajPobjeda;
	return Status::NijeKraj;
}

void PrijaviGresku(KodoviGresaka greska)
{
	if(greska==KodoviGresaka::PogresnaKomanda)
		std::cout<<"Nerazumljiva komanda!";
	if(greska==KodoviGresaka::NedostajeParametar)
		std::cout<<"Komanda trazi parametar koji nije naveden!";
	if(greska==KodoviGresaka::NeispravanParametar)
		std::cout<<"Parametar komande nije ispravan!";
	if(greska==KodoviGresaka::SuvisanParametar)
		std::cout<<"Zadan je suvisan parametar nakon komande!";
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska)
{
	std::string unos;
	std::getline(std::cin, unos);
	std::cin.clear();
	std::cin.ignore(1000,'\n');
	int i(0);
	while(i!=unos.length()) {
		if(unos.at(i)==' ') {
			while(unos.at(i)==' ') i++;
		}
		if(unos.at(i)=='P') {
			i++;
			if(unos.at(i)=='1') {
				i++;
				if(unos.at(i)!=' ' && i!=unos.length() && (unos.at(i)<'A' || unos.at(i)>'z')) {
					greska=KodoviGresaka::PogresnaKomanda;
					return false;
				}
				if(unos.at(i)==' ') {
					while(unos.at(i)==' ') i++;
				}
				if(i==unos.length()) {
					greska=KodoviGresaka::NedostajeParametar;
					return false;
				} else if(unos.at(i)=='G') {
					if(unos.at(i+1)==' ' || i+1==unos.length())
						smjer=Smjerovi::Gore;
					else if(unos.at(i+1)=='L')
						smjer=Smjerovi::GoreLijevo;
					else if(unos.at(i+1)=='D')
						smjer=Smjerovi::GoreDesno;
					else {
						greska=KodoviGresaka::NeispravanParametar;
						return false;
					}
				} else if(unos.at(i)=='D') {
					if(unos.at(i+1)==' ' || i+1==unos.length())
						smjer=Smjerovi::Desno;
					else if(unos.at(i+1)=='o') {
						if(unos.at(i+2)==' ' || i+2==unos.length())
							smjer=Smjerovi::Dolje;
						else if(unos.at(i+2)=='D')
							smjer=Smjerovi::DoljeDesno;
						else if(unos.at(i+2)=='L')
							smjer=Smjerovi::DoljeLijevo;
						else {
							greska=KodoviGresaka::NeispravanParametar;
							return false;
						}
					} else {
						greska=KodoviGresaka::NeispravanParametar;
						return false;
					}
				} else if(unos.at(i)=='L') {
					if(unos.at(i+1)==' ' || i+1==unos.length())
						smjer=Smjerovi::Lijevo;
					else {
						greska=KodoviGresaka::NeispravanParametar;
						return false;
					}
				}
				while(unos.at(i)!=' ' && i!=unos.length()) {
					i++;
					if(unos.at(i)==' ') {
						while(unos.at(i)==' ') i++;
						if(i!=unos.length()) {
							greska=KodoviGresaka::SuvisanParametar;
							return false;
						}

					}
				}
				komanda=Komande::PomjeriJednoMjesto;
			} else if(unos.at(i)=='>') {
				i++;
				if(unos.at(i)!=' ' && i!=unos.length() && (unos.at(i)<48 || unos.at(i)>57)) {
					greska=KodoviGresaka::PogresnaKomanda;
					return false;
				}
				if(unos.at(i)==' ') {
					while(unos.at(i)==' ') i++;
				}
				if(i==unos.length()) {
					greska=KodoviGresaka::NedostajeParametar;
					return false;
				} else if(unos.at(i)>=48 && unos.at(i)<=57) {
					int j(i);
					while(unos.at(i)>=48 && unos.at(i)<=57)
						i++;
					int brojac(i-j-1),suma1(0);
					while(j!=i) {
						suma1=suma1+(unos.at(j)-48)*std::pow(10, brojac);
						x=suma1;
						brojac--;
						j++;
					}
					if(unos.at(i)!=' ' && i!=unos.length() && (unos.at(i)<48 || unos.at(i)>57)) {
						greska=KodoviGresaka::NeispravanParametar;
						return false;
					}

					if(unos.at(i)==' ') {
						while(unos.at(i)==' ') i++;
					}
					if(i==unos.length()) {
						greska=KodoviGresaka::NedostajeParametar;
						return false;
					}

					else if(unos.at(i)>=48 && unos.at(i)<=57) {
						j=i;
						while(unos.at(i)>=48 && unos.at(i)<=57)
							i++;
						brojac=i-j-1;
						int suma2(0);
						while(j!=i) {
							suma2=suma2+(unos.at(j)-48)*std::pow(10, brojac);
							y=suma2;
							brojac--;
							j++;
						}
						if(unos.at(i)!=' ' && i!=unos.length() && (unos.at(i)<48 || unos.at(i)>57)) {
							greska=KodoviGresaka::NeispravanParametar;
							return false;
						}
						if(unos.at(i)==' ') {
							while(unos.at(i)==' ') i++;
							if(i!=unos.length()) {
								greska=KodoviGresaka::SuvisanParametar;
								return false;
							}
						}
					} else {
						greska=KodoviGresaka::NeispravanParametar;
						return false;
					}
				} else {
					greska=KodoviGresaka::NeispravanParametar;
					return false;
				}
				komanda=Komande::PomjeriDalje;
			} else if(unos.at(i)=='O') {
				i++;
				if(unos.at(i)==' ') {
					while(unos.at(i)==' ') i++;
					if(i!=unos.length()) {
						greska=KodoviGresaka::SuvisanParametar;
						return false;
					}
				} else if(unos.at(i)!=' ' && i!=unos.length()) {
					greska=KodoviGresaka::PogresnaKomanda;
					return false;
				}
				komanda=Komande::PrikaziOkolinu;

			} else {
				greska=KodoviGresaka::PogresnaKomanda;
				return false;
			}
		} else if(unos.at(i)=='D' || unos.at(i)=='B') {
			int k(i);
			i++;
			if(unos.at(i)!=' ' && i!=unos.length() && (unos.at(i)<48 || unos.at(i)>57)) {
				greska=KodoviGresaka::PogresnaKomanda;
				return false;
			}
			if(unos.at(i)==' ') {
				while(unos.at(i)==' ') i++;
			}
			if(i==unos.length()) {
				greska=KodoviGresaka::NedostajeParametar;
				return false;
			} else if(unos.at(i)>=48 && unos.at(i)<=57) {
				int j(i);
				while(unos.at(i)>=48 && unos.at(i)<=57)
					i++;
				int brojac(i-j-1),suma1(0);
				while(j!=i) {
					suma1=suma1+(unos.at(j)-48)*std::pow(10, brojac);
					x=suma1;
					brojac--;
					j++;

				}
				if(unos.at(i)!=' ' && i!=unos.length() && (unos.at(i)<48 || unos.at(i)>57)) {
					greska=KodoviGresaka::NeispravanParametar;
					return false;
				}

				if(unos.at(i)==' ') {
					while(unos.at(i)==' ') i++;
				}
				if(i==unos.length()) {
					greska=KodoviGresaka::NedostajeParametar;
					return false;
				}

				else if(unos.at(i)>=48 && unos.at(i)<=57) {
					j=i;
					while(unos.at(i)>=48 && unos.at(i)<=57)
						i++;
					brojac=i-j-1;
					int suma2(0);
					while(j!=i) {
						suma2=suma2+(unos.at(j)-48)*std::pow(10, brojac);
						y=suma2;
						brojac--;
						j++;
					}
					if(unos.at(i)!=' ' && i!=unos.length() && (unos.at(i)<48 || unos.at(i)>57)) {
						greska=KodoviGresaka::NeispravanParametar;
						return false;
					}
					if(unos.at(i)==' ') {
						while(unos.at(i)==' ') i++;
						if(i!=unos.length()) {
							greska=KodoviGresaka::SuvisanParametar;
							return false;
						}
					}
				} else {
					greska=KodoviGresaka::NeispravanParametar;
					return false;
				}
			} else {
				greska=KodoviGresaka::NeispravanParametar;
				return false;
			}
			if(unos.at(k)=='D') komanda=Komande::Deblokiraj;
			else if(unos.at(k)=='B') komanda=Komande::Blokiraj;

		} else if(unos.at(i)=='K' || unos.at(i)=='Z') {
			int j(i);
			if(unos.at(j)=='K') komanda=Komande::KreirajIgru;
			else if(unos.at(j)=='Z') komanda=Komande::ZavrsiIgru;
			i++;
			if(i==unos.length()) break;
			if(unos.at(i)==' ') {
				while(unos.at(i)==' ') i++;
				if(i!=unos.length()) {
					greska=KodoviGresaka::SuvisanParametar;
					return false;
				}
			} else if(unos.at(i)!=' ' && i!=unos.length()) {
				greska=KodoviGresaka::PogresnaKomanda;
				return false;
			}


		} else greska=KodoviGresaka::PogresnaKomanda;


		if(i==unos.length()) break;
		i++;

	}
	return true;
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0)
{

	if(komanda==Komande::KreirajIgru) {
		int n, z(0);
		std::vector<std::vector<int>> v;
		std::cout<<"Unesite broj polja: ";
		std::cin>>n;
		std::cout<<"Unesite pozicije mina: ";
		while(true) {
			std::complex<int> tacka;
			std::cin>>tacka;
			if(!std::cin) {
				std::cin.clear();
				if(std::cin.peek()=='.') break;
				std::cout<<"Greska, unesite ponovo!"<<std::endl;
				std::cin.ignore(1000, '\n');
				continue;
			}
			if(std::cin.peek()=='.') break;
			std::cin.ignore(1000,'\n');
			int re, im;
			re=std::real(tacka);
			im=std::imag(tacka);
			if(re>=0 && re<n && im>=0 && im<n && !(re==0 && im==0)) {
				v.resize(z+1);
				v.at(z).push_back(re);
				v.at(z).push_back(im);
				z++;
			} else std::cout<<"Greska, unesite ponovo!"<<std::endl;
		}
		polja=KreirajIgru(n, v);
	}


	else if(komanda==Komande::PomjeriJednoMjesto) {
		Status rezultat(Idi(polja, p_x, p_y, p_smjer));
		std::cout<<"Tekuca pozicija igraca je ("<<p_x<<","<<p_y<<")"<<std::endl;
		if(rezultat==Status::KrajPobjeda) {
			std::cout<<"Bravo, obisli ste sva sigurna polja"<<std::endl;
			for(int i(0); i<polja.size(); i++) {
				for(int j(0); j<polja.at(i).size(); j++) {
					polja.at(i).at(j)=Polje::Prazno;
				}
			}
			throw std::runtime_error("Igra zavrsena");
		}
		if(rezultat==Status::KrajPoraz) {
			std::cout<<"Nagazili ste na minu"<<std::endl;
			for(int i(0); i<polja.size(); i++) {
				for(int j(0); j<polja.at(i).size(); j++) {
					polja.at(i).at(j)=Polje::Prazno;
				}
			}
			throw std::runtime_error("Igra zavrsena");
		}
	} else if(komanda==Komande::PomjeriDalje) {
		Status rezultat(Idi(polja, p_x, p_y, x, y));
		std::cout<<"Tekuca pozicija igraca je ("<<p_x<<","<<p_y<<")"<<std::endl;
		if(rezultat==Status::KrajPobjeda) {
			std::cout<<"Bravo, obisli ste sva sigurna polja"<<std::endl;
			for(int i(0); i<polja.size(); i++) {
				for(int j(0); j<polja.at(i).size(); j++) {
					polja.at(i).at(j)=Polje::Prazno;
				}
			}
			throw std::runtime_error("Igra zavrsena");
		}
		if(rezultat==Status::KrajPoraz) {
			std::cout<<"Nagazili ste na minu"<<std::endl;
			for(int i(0); i<polja.size(); i++) {
				for(int j(0); j<polja.at(i).size(); j++) {
					polja.at(i).at(j)=Polje::Prazno;
				}
			}
			throw std::runtime_error("Igra zavrsena");
		}

	} else if(komanda==Komande::Blokiraj) {
		BlokirajPolje(polja, x, y);

	} else if(komanda==Komande::Deblokiraj) {
		DeblokirajPolje(polja, x, y);

	} else if(komanda==Komande::PrikaziOkolinu) {
		std::vector<std::vector<int>> mat(PrikaziOkolinu(polja, x, y));
		for(int i(0); i<mat.size(); i++) {
			for(int j(0); j<mat.at(i).size(); j++) {
				std::cout<<mat.at(i).at(j)<<" ";
			}
			std::cout<<std::endl;
		}

	} else if(komanda==Komande::ZavrsiIgru) {
		for(int i(0); i<polja.size(); i++) {
			for(int j(0); j<polja.at(i).size(); j++) {
				polja.at(i).at(j)=Polje::Prazno;
			}
		}
		throw std::runtime_error("Igra zavrsena");

	}




}

int main ()
{
	int x(0), y(0);
	Tabla polja;
	try {
		while(true) {
			Smjerovi smjer;
			KodoviGresaka greska;
			Komande komanda;
			int p_x, p_y;
			std::cout<<"Unesite komandu: ";

			bool ispravnost(UnosKomande(komanda, smjer, p_x, p_y, greska));
			if(komanda==Komande::ZavrsiIgru) break;

			if(ispravnost==true) IzvrsiKomandu(komanda, polja, x, y, smjer, p_x, p_y);

			else PrijaviGresku(greska);
		}


	}
		catch(std::runtime_error izuzetak) {
			std::cout<<izuzetak.what()<<std::endl;
		} catch(std::domain_error izuzetak) {
			std::cout<<izuzetak.what()<<std::endl;
		} catch(std::out_of_range izuzetak) {
			std::cout<<izuzetak.what()<<std::endl;
		} catch(std::logic_error izuzetak) {
			std::cout<<izuzetak.what()<<std::endl;
		}

		std::cout<<"Dovidjenja!"<<std::endl;
		return 0;
	}
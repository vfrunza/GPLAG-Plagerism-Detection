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
    NijeKraj,KrajPoraz, KrajPobjeda
};
typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru (int n, const std::vector<std::vector<int>> &mine)
{
	if(n<=0) throw std::domain_error ("Ilegalna velicina");
	Tabla tab (n,std::vector<Polje>(n));
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			tab[i][j]=Polje::Prazno;
		}
	}
	for(int i=0; i<mine.size(); i++) if(mine.at(i).size()!=2) throw std::domain_error ("Ilegalan format zadavanja mina");
	for(int i=0; i<mine.size(); i++) {
		int a(mine.at(i).at(0));
		int b(mine.at(i).at(1));
		if(a<0 || a>=mine.size() || b<0 || b>=mine.size()) throw std::domain_error ("Ilegalne pozicije mina");
		tab[a][b]=Polje::Mina;
	}
	return tab;
}
std::vector<std::vector<int>> PrikaziOkolinu (const Tabla &polja, int x, int y)
{
	int a(polja.size());
	if(x<0 || x>=a || y<0 || y>=a) throw std::domain_error (std::string("Polje (") +std::to_string(x)+"," + std::to_string(y) + std::string(") ne postoji"));

	std::vector<std::vector<int>> okolo(3,std::vector<int>(3));
//	for(int k=)
	return okolo;
}
void BlokirajPolje(Tabla &polja, int x, int y)
{
	int n(polja.size());
	if(x<0 || x>=n || y<0 || y>=n) throw std::domain_error (std::string("Polje (") +std::to_string(x)+"," + std::to_string(y) + std::string(") ne postoji"));

	if(polja[x][y]==Polje::Prazno) polja[x][y]=Polje::BlokiranoPrazno;
	if(polja[x][y]==Polje::Mina) polja[x][y]=Polje::BlokiranoMina;
	if(polja[x][y]==Polje::Posjeceno) polja[x][y]=Polje::BlokiranoPosjeceno;
}
void DeblokirajPolje(Tabla &polja, int x,int y )
{
	int a(polja.size());
	if(x<0 || x>=a || y<0 || y>=a) throw std::domain_error (std::string("Polje (") +std::to_string(x)+","+ std::to_string(y) + std::string(") ne postoji"));
	if(polja[x][y]==Polje::BlokiranoPrazno) polja[x][y]=Polje::Prazno;
	if(polja[x][y]==Polje::BlokiranoMina) polja[x][y]=Polje::Mina;
	if(polja[x][y]==Polje::BlokiranoPosjeceno) polja[x][y]=Polje::Posjeceno;

}
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer)
{
	polja[x][y]=Polje::Posjeceno;
	if((smjer==Smjerovi::Gore || smjer==Smjerovi::GoreDesno || smjer== Smjerovi::GoreLijevo) && x-1<0) throw std::out_of_range ("Izlazak van igrace table");
	if((smjer==Smjerovi::Dolje || smjer==Smjerovi::DoljeDesno || smjer==Smjerovi::DoljeLijevo) && x+1>=polja.size()) throw std::out_of_range ("Izlazak van igrace table");
	if((smjer==Smjerovi::Lijevo || smjer==Smjerovi::DoljeLijevo || smjer==Smjerovi::GoreLijevo)&& y-1<0) throw std::out_of_range ("Izlazak van igrace table");
	if((smjer==Smjerovi::Desno || smjer==Smjerovi::DoljeDesno || smjer==Smjerovi::GoreDesno)&& y+1>=polja.size()) throw std::out_of_range ("Izlazak van igrace table");

	if(smjer==Smjerovi::Gore)	x--;
	if(smjer==Smjerovi::Dolje) x++;
	if(smjer==Smjerovi::GoreDesno) {
		x--;
		y++;
	}
	if(smjer==Smjerovi::GoreLijevo) {
		x--;
		y--;
	}
	if(smjer==Smjerovi::DoljeDesno) {
		x++;
		y++;
	}
	if(smjer==Smjerovi::DoljeLijevo) {
		x++;
		y--;
	}
	if(polja[x][y]==Polje::BlokiranoPosjeceno || polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
	if(polja[x][y]==Polje::Mina) {
		for(int i=0; i<polja.size(); i++) {
			for(int j=0; j<polja.size(); j++) {
				polja[i][j]=Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
	int brojac(0);
	for(int i=0; i<polja.size(); i++) {
		for(int j=0; j<polja.size(); j++) {
			if(polja[i][j]==Polje::Prazno)brojac++;
		}
	}
	if (brojac==0) return Status::KrajPobjeda;

	else return Status::NijeKraj;
}
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y)
{
	if(novi_x<0 || novi_x>=polja.size() || novi_y<0 || novi_y>=polja.size()) throw std::out_of_range ("Izlazak van igrace table");
	x=novi_x;
	y=novi_y;
	if(polja[x][y]==Polje::BlokiranoPosjeceno || polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
	if(polja[x][y]==Polje::Mina) {
		for(int i=0; i<polja.size(); i++) {
			for(int j=0; j<polja.size(); j++) {
				polja[i][j]=Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
	int brojac(0);
	for(int i=0; i<polja.size(); i++) {
		for(int j=0; j<polja.size(); j++) {
			if(polja[i][j]==Polje::Prazno)brojac++;
		}
	}
	if (brojac==0) return Status::KrajPobjeda;

	else return Status::NijeKraj;
}
int main ()
{
	return 0;
}
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
#include <algorithm>
#include <vector>
#include <iomanip>
#include <string>
#include <complex>
#include <stdexcept>
#include <stdio.h>

int X1 = 0, Y1 = 0;
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
    PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu,
    ZavrsiIgru, KreirajIgru
};

typedef std::vector<std::vector<Polje>> Tabla;


Tabla KreirajTablu (int broj_redova, int broj_kolona)
{

	return Tabla(broj_redova, std::vector<Polje>(broj_kolona));

}
void IspisiTablu(std::vector<std::vector<Polje>> polja)
{
	for(int i = 0; i < polja.size(); i++) {
		for(int j = 0; j < polja[i].size(); j++) std::cout << int(polja[i][j]) << " ";
		std::cout << std::endl;
	}
}
void IspisiMatricu (std::vector<std::vector<int>> polja)
{
	for(int i = 0; i < polja.size(); i++) {
		for(int j = 0; j < polja[i].size(); j++) std::cout << int(polja[i][j]) << " ";
		std::cout << std::endl;
	}


}
bool ispravno_polje (int row, int col, int vel)
{
	return (row >= 0) && (row < vel) &&
	       (col >= 0) && (col < vel);
}

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine)
{
	Tabla tablony;
	tablony = KreirajTablu(n,n);
	int brojac = 0;
	int vel = tablony.size();
	for (int v = 0; v < mine.size(); v++)
		if (mine.at(0).size()!=mine.at(v).size()) throw std::domain_error("Ilegalan format zadavanja mina");

	while (brojac<mine.size()) {

		int a = mine.at(brojac).at(0);
		int b = mine.at(brojac).at(1);

		if (ispravno_polje(a,b,vel)) {
			tablony[a][b] = Polje::Mina;

			brojac++;
		} else throw std::domain_error("Ilegalne pozicije mina");
	}
	return tablony;
}

bool minirano (int row, int col, const Tabla &polja)
{
	if (polja[row][col] == Polje::Mina)
		return (true);
	else
		return (false);
}


bool JelWin (Tabla polja,int x, int y)
{
	int brojac=0;
	int vel = polja.size();

	vel = vel * vel;

	for (int i = 0; i < polja.size(); i++) {

		for (int j = 0; j < polja.size(); j++) {

			if(polja[i][j]!=Polje::Prazno)
				brojac++;
		}
	}

	if (brojac==vel-1 && polja[x][y]==Polje::Prazno) return true;


	return false;
}

void OcistiTablu(Tabla &tabla)
{

	for (int i = 0; i < tabla.size(); i++) {
		for (int j = 0; j < tabla.size(); j++)

			tabla[i][j] = Polje::Prazno;
	}
}


std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y)
{


	std::vector<std::vector<int>> Minirano;
	int vel (polja.size());
	int brojac = 0;
	int a,b;
	std::vector<int> temp;

	if (ispravno_polje(x,y,vel)==false) throw std::domain_error ("Polje (" + std::to_string(x) + "," + std::to_string(y)+") ne postoji");

	if (ispravno_polje(x-1,y-1,vel)==true) {		// North-west
		a=x-1;
		b=y-1;

		if (ispravno_polje(a,b-1,vel)    && minirano (a,b-1,polja)==true) brojac++;
		if (ispravno_polje(a,b+1,vel)    && minirano (a,b+1,polja)==true) brojac++;
		if (ispravno_polje(a-1,b,vel)    && minirano (a-1,b,polja)==true) brojac++;
		if (ispravno_polje(a+1,b,vel)   &&  minirano (a+1,b,polja)==true) brojac++;
		if (ispravno_polje(a-1,b-1,vel) &&  minirano (a-1,b-1,polja)==true) brojac++;
		if (ispravno_polje(a-1,b+1,vel) &&  minirano (a-1,b+1,polja)==true) brojac++;
		if (ispravno_polje(a+1,b-1,vel) &&  minirano (a+1,b-1,polja)==true) brojac++;
		if (ispravno_polje(a+1,b+1,vel) &&  minirano (a+1,b+1,polja)==true) brojac++;
	}

	temp.push_back(brojac);

	if (ispravno_polje(x-1,y,vel)==true) { 		  // North
		a = x-1;
		b = y;

		brojac = 0;

		if (ispravno_polje(a,b-1,vel)    && minirano (a,b-1,polja)==true) brojac++;
		if (ispravno_polje(a,b+1,vel)    && minirano (a,b+1,polja)==true) brojac++;
		if (ispravno_polje(a-1,b,vel)    && minirano (a-1,b,polja)==true) brojac++;
		if (ispravno_polje(a+1,b,vel)   &&  minirano (a+1,b,polja)==true) brojac++;
		if (ispravno_polje(a-1,b-1,vel) &&  minirano (a-1,b-1,polja)==true) brojac++;
		if (ispravno_polje(a-1,b+1,vel) &&  minirano (a-1,b+1,polja)==true) brojac++;
		if (ispravno_polje(a+1,b-1,vel) &&  minirano (a+1,b-1,polja)==true) brojac++;
		if (ispravno_polje(a+1,b+1,vel) &&  minirano (a+1,b+1,polja)==true) brojac++;

	}
	temp.push_back(brojac);

	if (ispravno_polje(x-1,y+1,vel)==true) { // North-east
		a = x-1;
		b = y+1;

		brojac = 0;

		if (ispravno_polje(a,b-1,vel)    && minirano (a,b-1,polja)==true) brojac++;
		if (ispravno_polje(a,b+1,vel)    && minirano (a,b+1,polja)==true) brojac++;
		if (ispravno_polje(a-1,b,vel)    && minirano (a-1,b,polja)==true) brojac++;
		if (ispravno_polje(a+1,b,vel)   &&  minirano (a+1,b,polja)==true) brojac++;
		if (ispravno_polje(a-1,b-1,vel) &&  minirano (a-1,b-1,polja)==true) brojac++;
		if (ispravno_polje(a-1,b+1,vel) &&  minirano (a-1,b+1,polja)==true) brojac++;
		if (ispravno_polje(a+1,b-1,vel) &&  minirano (a+1,b-1,polja)==true) brojac++;
		if (ispravno_polje(a+1,b+1,vel) &&  minirano (a+1,b+1,polja)==true) brojac++;


	}
	temp.push_back(brojac);
	Minirano.push_back(temp);

	temp.clear();


	if (ispravno_polje(x,y-1,vel)==true) {		// west
		a = x;
		b = y-1;
		brojac = 0;

		if (ispravno_polje(a,b-1,vel)    && minirano (a,b-1,polja)==true) brojac++;
		if (ispravno_polje(a,b+1,vel)    && minirano (a,b+1,polja)==true) brojac++;
		if (ispravno_polje(a-1,b,vel)    && minirano (a-1,b,polja)==true) brojac++;
		if (ispravno_polje(a+1,b,vel)   &&  minirano (a+1,b,polja)==true) brojac++;
		if (ispravno_polje(a-1,b-1,vel) &&  minirano (a-1,b-1,polja)==true) brojac++;
		if (ispravno_polje(a-1,b+1,vel) &&  minirano (a-1,b+1,polja)==true) brojac++;
		if (ispravno_polje(a+1,b-1,vel) &&  minirano (a+1,b-1,polja)==true) brojac++;
		if (ispravno_polje(a+1,b+1,vel) &&  minirano (a+1,b+1,polja)==true) brojac++;

	}
	temp.push_back(brojac);

	if (ispravno_polje(x,y,vel)==true) { // Sredina
		a = x;
		b = y;
		brojac=0;

		if (ispravno_polje(a,b-1,vel)    && minirano (a,b-1,polja)==true) brojac++;
		if (ispravno_polje(a,b+1,vel)    && minirano (a,b+1,polja)==true) brojac++;
		if (ispravno_polje(a-1,b,vel)    && minirano (a-1,b,polja)==true) brojac++;
		if (ispravno_polje(a+1,b,vel)   &&  minirano (a+1,b,polja)==true) brojac++;
		if (ispravno_polje(a-1,b-1,vel) &&  minirano (a-1,b-1,polja)==true) brojac++;
		if (ispravno_polje(a-1,b+1,vel) &&  minirano (a-1,b+1,polja)==true) brojac++;
		if (ispravno_polje(a+1,b-1,vel) &&  minirano (a+1,b-1,polja)==true) brojac++;
		if (ispravno_polje(a+1,b+1,vel) &&  minirano (a+1,b+1,polja)==true) brojac++;

	}
	temp.push_back(brojac);

	if (ispravno_polje(x,y+1,vel)==true)  {			 // East
		a=x;
		b=y+1;
		brojac=0;

		if (ispravno_polje(a,b-1,vel)    && minirano (a,b-1,polja)==true) brojac++;
		if (ispravno_polje(a,b+1,vel)    && minirano (a,b+1,polja)==true) brojac++;
		if (ispravno_polje(a-1,b,vel)    && minirano (a-1,b,polja)==true) brojac++;
		if (ispravno_polje(a+1,b,vel)   &&  minirano (a+1,b,polja)==true) brojac++;
		if (ispravno_polje(a-1,b-1,vel) &&  minirano (a-1,b-1,polja)==true) brojac++;
		if (ispravno_polje(a-1,b+1,vel) &&  minirano (a-1,b+1,polja)==true) brojac++;
		if (ispravno_polje(a+1,b-1,vel) &&  minirano (a+1,b-1,polja)==true) brojac++;
		if (ispravno_polje(a+1,b+1,vel) &&  minirano (a+1,b+1,polja)==true) brojac++;

	}
	temp.push_back(brojac);
	Minirano.push_back(temp);

	temp.clear();


	if (ispravno_polje(x+1,y-1,vel)==true) {			// South-west

		a = x+1;
		b = y-1;
		brojac=0;

		if (ispravno_polje(a,b-1,vel)    && minirano (a,b-1,polja)==true) brojac++;
		if (ispravno_polje(a,b+1,vel)    && minirano (a,b+1,polja)==true) brojac++;
		if (ispravno_polje(a-1,b,vel)    && minirano (a-1,b,polja)==true) brojac++;
		if (ispravno_polje(a+1,b,vel)   &&  minirano (a+1,b,polja)==true) brojac++;
		if (ispravno_polje(a-1,b-1,vel) &&  minirano (a-1,b-1,polja)==true) brojac++;
		if (ispravno_polje(a-1,b+1,vel) &&  minirano (a-1,b+1,polja)==true) brojac++;
		if (ispravno_polje(a+1,b-1,vel) &&  minirano (a+1,b-1,polja)==true) brojac++;
		if (ispravno_polje(a+1,b+1,vel) &&  minirano (a+1,b+1,polja)==true) brojac++;

	}
	temp.push_back(brojac);


	if (ispravno_polje(x+1,y,vel)==true) { // South
		a = x+1;
		b = y-1;
		brojac=0;

		if (ispravno_polje(a,b-1,vel)    && minirano (a,b-1,polja)==true) brojac++;
		if (ispravno_polje(a,b+1,vel)    && minirano (a,b+1,polja)==true) brojac++;
		if (ispravno_polje(a-1,b,vel)    && minirano (a-1,b,polja)==true) brojac++;
		if (ispravno_polje(a+1,b,vel)   &&  minirano (a+1,b,polja)==true) brojac++;
		if (ispravno_polje(a-1,b-1,vel) &&  minirano (a-1,b-1,polja)==true) brojac++;
		if (ispravno_polje(a-1,b+1,vel) &&  minirano (a-1,b+1,polja)==true) brojac++;
		if (ispravno_polje(a+1,b-1,vel) &&  minirano (a+1,b-1,polja)==true) brojac++;
		if (ispravno_polje(a+1,b+1,vel) &&  minirano (a+1,b+1,polja)==true) brojac++;

	}
	temp.push_back(brojac);

	if (ispravno_polje(x+1,y+1,vel)==true) { // south-east
		a = x+1;
		b = y+1;
		brojac = 0;
		if (ispravno_polje(a,b-1,vel)    && minirano (a,b-1,polja)==true) brojac++;
		if (ispravno_polje(a,b+1,vel)    && minirano (a,b+1,polja)==true) brojac++;
		if (ispravno_polje(a-1,b,vel)    && minirano (a-1,b,polja)==true) brojac++;
		if (ispravno_polje(a+1,b,vel)   &&  minirano (a+1,b,polja)==true) brojac++;
		if (ispravno_polje(a-1,b-1,vel) &&  minirano (a-1,b-1,polja)==true) brojac++;
		if (ispravno_polje(a-1,b+1,vel) &&  minirano (a-1,b+1,polja)==true) brojac++;
		if (ispravno_polje(a+1,b-1,vel) &&  minirano (a+1,b-1,polja)==true) brojac++;
		if (ispravno_polje(a+1,b+1,vel) &&  minirano (a+1,b+1,polja)==true) brojac++;
	}

	temp.push_back(brojac);
	Minirano.push_back(temp);



	return Minirano;
}

void BlokirajPolje(Tabla &polja, int x, int y)
{
	if (ispravno_polje(x,y,polja.size())==false) throw std::domain_error ("Polje (" + std::to_string(x) + "," + std::to_string(y)+") ne postoji");

	if (polja[x][y]==Polje::Mina) polja[x][y]= Polje::BlokiranoMina;
	else if (polja[x][y]==Polje::Prazno) polja[x][y] = Polje::BlokiranoPrazno;
	else if (polja[x][y]==Polje::Posjeceno) polja[x][y] = Polje::BlokiranoPosjeceno;
}

void DeblokirajPolje(Tabla &polja, int x, int y)
{
	if (ispravno_polje(x,y,polja.size())==false) throw std::domain_error ("Polje (" + std::to_string(x) + "," + std::to_string(y)+") ne postoji");

	if (polja[x][y]==Polje::BlokiranoMina) polja[x][y]= Polje::Mina;
	else if (polja[x][y]==Polje::BlokiranoPrazno) polja[x][y] = Polje::Prazno;
	else if (polja[x][y]==Polje::BlokiranoPosjeceno) polja[x][y] = Polje::Posjeceno;

}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer)
{
	if (smjer == Smjerovi::DoljeDesno) {
		int a = x+1;
		int b = y+1;
		if (ispravno_polje(a,b,polja.size())==false) throw std::out_of_range ("Izlazak van igrace table");
		else if (polja[a][b]==Polje::BlokiranoPosjeceno) throw std::logic_error("Blokirano polje");
		else if (polja[a][b]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		else if (polja[a][b]==Polje::BlokiranoPrazno) throw std::logic_error("Blokirano polje");
		polja[x][y]=Polje::Posjeceno;
		x+=1;
		y+=1;
		if (!minirano(x,y,polja)) {
			if(JelWin(polja,x,y)) return Status::KrajPobjeda;
			return Status::NijeKraj;
		} else if (minirano(x,y,polja)) return Status::KrajPoraz;

	} else if (smjer==Smjerovi::GoreDesno) {
		int a = x-1;
		int b = y+1;
		if (ispravno_polje(a,b,polja.size())==false) throw std::out_of_range ("Izlazak van igrace table");
		else if (polja[a][b]==Polje::BlokiranoPosjeceno) throw std::logic_error("Blokirano polje");
		else if (polja[a][b]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		else if (polja[a][b]==Polje::BlokiranoPrazno) throw std::logic_error("Blokirano polje");
		polja[x][y]=Polje:: Posjeceno;
		x-=1;
		y+=1;
		if (!minirano(x,y,polja)) {
			if(JelWin(polja,x,y)) return Status::KrajPobjeda;
			return Status::NijeKraj;
		} else if (minirano(x,y,polja)) return Status::KrajPoraz;

	} else if (smjer==Smjerovi::GoreLijevo) {
		int a = x-1;
		int b = y-1;
		if (ispravno_polje(a,b,polja.size())==false) throw std::out_of_range ("Izlazak van igrace table");
		else if(polja[a][b]==Polje::BlokiranoPosjeceno) throw std::logic_error("Blokirano polje");
		else if (polja[a][b]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		else if (polja[a][b]==Polje::BlokiranoPrazno) throw std::logic_error("Blokirano polje");


		polja[x][y]=Polje::Posjeceno;
		x-=1;
		y-=1;
		if (!minirano(x,y,polja)) {
			if(JelWin(polja,x,y)) return Status::KrajPobjeda;
			return Status::NijeKraj;
		} else if (minirano(x,y,polja)) return Status::KrajPoraz;

	} else if (smjer==Smjerovi::DoljeLijevo) {
		int a = x+1;
		int b = y-1;
		if (ispravno_polje(a,b,polja.size())==false) throw std::out_of_range ("Izlazak van igrace table");
		else if(polja[a][b]==Polje::BlokiranoPosjeceno) throw std::logic_error("Blokirano polje");
		else if (polja[a][b]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		else if (polja[a][b]==Polje::BlokiranoPrazno) throw std::logic_error("Blokirano polje");

		polja[x][y]=Polje::Posjeceno;
		x+=1;
		y-=1;
		if (!minirano(x,y,polja)) {
			if(JelWin(polja,x,y)) return Status::KrajPobjeda;
			return Status::NijeKraj;
		} else if (minirano(x,y,polja)) return Status::KrajPoraz;


	} else if (smjer==Smjerovi::Gore) {
		int a = x-1;
		int b = y;
		if (ispravno_polje(a,b,polja.size())==false) throw std::out_of_range ("Izlazak van igrace table");
		else if (polja[a][b]==Polje::BlokiranoPosjeceno) throw std::logic_error("Blokirano polje");
		else if (polja[a][b]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		else if (polja[a][b]==Polje::BlokiranoPrazno) throw std::logic_error("Blokirano polje");
		polja[x][y]=Polje::Posjeceno;
		x-=1;

		if (!minirano(x,y,polja)) {
			if(JelWin(polja,x,y)) return Status::KrajPobjeda;
			return Status::NijeKraj;
		} else if (minirano(x,y,polja)) return Status::KrajPoraz;

	} else if (smjer==Smjerovi::Dolje) {

		int a = x+1;
		int b = y;
		if (ispravno_polje(a,b,polja.size())==false) throw std::out_of_range ("Izlazak van igrace table");
		else if(polja[a][b]==Polje::BlokiranoPosjeceno) throw std::logic_error("Blokirano polje");
		else if (polja[a][b]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		else if (polja[a][b]==Polje::BlokiranoPrazno) throw std::logic_error("Blokirano polje");

		polja[x][y]=Polje::Posjeceno;
		x+=1;
		if (!minirano(x,y,polja)) {
			if(JelWin(polja,x,y)) return Status::KrajPobjeda;
			return Status::NijeKraj;
		} else if (minirano(x,y,polja)) return Status::KrajPoraz;

	} else if (smjer==Smjerovi::Desno) {

		int a = x;
		int b = y+1;
		if (ispravno_polje(a,b,polja.size())==false) throw std::out_of_range ("Izlazak van igrace table");
		else if(polja[a][b]==Polje::BlokiranoPosjeceno) throw std::logic_error("Blokirano polje");
		else if (polja[a][b]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		else if (polja[a][b]==Polje::BlokiranoPrazno) throw std::logic_error("Blokirano polje");

		polja[x][y]=Polje::Posjeceno;
		y+=1;
		if (!minirano(x,y,polja)) {
			if(JelWin(polja,x,y)) return Status::KrajPobjeda;
			return Status::NijeKraj;
		} else if (minirano(x,y,polja)) return Status::KrajPoraz;

	} else if (smjer==Smjerovi::Lijevo) {

		int a = x;
		int b = y-1;
		if (ispravno_polje(a,b,polja.size())==false) throw std::out_of_range ("Izlazak van igrace table");
		else if(polja[a][b]==Polje::BlokiranoPosjeceno) throw std::logic_error("Blokirano polje");
		else if (polja[a][b]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		else if (polja[a][b]==Polje::BlokiranoPrazno) throw std::logic_error("Blokirano polje");

		polja[x][y]=Polje::Posjeceno;
		y-=1;
		if (!minirano(x,y,polja)) {
			if(JelWin(polja,x,y)) return Status::KrajPobjeda;
			return Status::NijeKraj;
		} else if (minirano(x,y,polja)) return Status::KrajPoraz;
	}
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y)
{

	int vel = polja.size();
	int a,b;
	
	a = X1;
	b = Y1;
	if (ispravno_polje(novi_x,novi_y,vel)) {
		
	
		if (polja[novi_x][novi_y]==Polje::BlokiranoPosjeceno) throw std::logic_error("Blokirano polje");
		else if (polja[novi_x][novi_y]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		else if (polja[novi_x][novi_y]==Polje::BlokiranoPrazno) throw std::logic_error("Blokirano polje");
		x = novi_x;
		y = novi_y;
		polja[novi_x][novi_y]=Polje::Posjeceno;
		X1 = x;
		Y1 = y;

		if (JelWin(polja,x,y)) return Status::KrajPobjeda;
		if (!minirano(x,y,polja)) {
			polja[a][b]=Polje::Posjeceno;
			if (JelWin(polja,x,y)) return Status::KrajPobjeda;
			return Status::NijeKraj;
		} else if (minirano(x,y,polja)) return Status::KrajPoraz;
		else return Status::KrajPobjeda;

	} else throw std::out_of_range ("Izlazak van igrace table");
	return Status::KrajPobjeda;
}

void PrijaviGresku (KodoviGresaka greska)
{
	if (greska==KodoviGresaka::PogresnaKomanda) std::cout << "Nerazumljiva komanda!"<<std::endl;
	else if (greska==KodoviGresaka::NedostajeParametar) std::cout << "Komanda trazi parametar koji nije naveden!"<<std::endl;
	else if (greska==KodoviGresaka::NeispravanParametar) std::cout << "Parametar komande nije ispravan!"<<std::endl;
	else if (greska==KodoviGresaka::SuvisanParametar) std::cout << "Zadan je suvisan parametar nakon komande!"<<std::endl;


}

std::string razmaci(std::string &str)
{
	str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
	return str;
}

int UnosBroja (std::string s , std::string s2 , int &broj)
{
	std::cout << s;
	std::cin >> broj;
	char c = std::cin.peek();

	while (!std::cin || broj<=0) {

		std::cout << s2<<std::endl;
		std::cout << s;
		std::cin.clear();
		std::cin.ignore (1000,'\n');
		std::cin >> broj;
		c = std::cin.peek();
	}


}

int UnosParametara (int &broj)
{
	std::cin >> broj;
	char c = std::cin.peek();
	if (!std::cin || broj<0) {
		throw ("A");
		std::cin.clear();
	}
	c = std::cin.peek();
}
void OcistiTok (int a)
{
	std::cin.clear();
	std::cin.ignore (1000,'\n');
}

int UnosBroja (std::string s, int &broj)
{
	std::cin >> broj;
	char c = std::cin.peek();
	while (!std::cin || broj<0) {

		std::cout << s<<std::endl;
		std::cin.clear();
		std::cin.ignore (1000,'\n');
		std::cin >> broj;
		c = std::cin.peek();
	}
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y,
                 KodoviGresaka &greska)
{

	std::string s;
	std::cin>>s;


	if (s=="K" || s[0]=='K') {
		std::string temp;
		std::getline(std::cin, temp);
		razmaci(temp);
		s = s + temp;

		if (s.length()!=1)  {
			greska=KodoviGresaka::SuvisanParametar;
			return false;
		}
		komanda = Komande::KreirajIgru;
		return true;
	} else if (s=="P1" || s=="P1DoD" || s== "P1G" || s== "P1Do" || s=="P1L" || s=="P1D" || s=="P1DoL" || s=="P1GL" || s=="P1GD") {

		std::string temp;
		std::getline(std::cin,temp);
		razmaci(temp);

		s+=temp;
		if (s=="P1") {
			greska = KodoviGresaka::NedostajeParametar;
			return false;
		}

		komanda = Komande::PomjeriJednoMjesto;
		if (s=="P1DoD") smjer = Smjerovi::DoljeDesno;
		else if (s=="P1G") smjer = Smjerovi::Gore;
		else if (s=="P1Do") smjer = Smjerovi::Dolje;
		else if (s=="P1L") smjer = Smjerovi::Lijevo;
		else if (s=="P1D") smjer = Smjerovi::Desno;
		else if (s=="P1DoL")smjer = Smjerovi::DoljeLijevo;
		else if (s=="P1GL")smjer = Smjerovi::GoreLijevo;
		else if (s=="P1GD") smjer = Smjerovi::GoreDesno;
		else {
			greska=KodoviGresaka::NedostajeParametar;
			return false;
		}

		if (s.length()>5) {
			greska = KodoviGresaka::SuvisanParametar;
			return false;
		}
		return true;

	}

	else if (s=="B") {
		komanda= Komande::Blokiraj;
		try {

			UnosParametara(x);
			UnosParametara(y);
		} catch (...) {
			greska=KodoviGresaka::NeispravanParametar;
			OcistiTok(1);
			return false;
		}

		return true;
	} else if (s=="D") {
		komanda = Komande::Deblokiraj;
		try {
			UnosParametara(x);
			UnosParametara(y);
		} catch (...) {
			greska=KodoviGresaka::NeispravanParametar;
			OcistiTok(1);
			return false;
		}

		return true;
	} else if (s=="P>") {
		try {
			UnosParametara(x);
			UnosParametara(y);
		} catch (...) {
			OcistiTok(1);
			greska=KodoviGresaka::NeispravanParametar;
			return false;
		}

		komanda = Komande::PomjeriDalje;
		return true;
	} else if (s=="PO") {
		std::getline(std::cin,s);
		razmaci(s);

		if (s.length()!=0)  {
			greska=KodoviGresaka::SuvisanParametar;
			return false;
		}
		komanda = Komande::PrikaziOkolinu;
		return true;
	} else if (s=="Z") {
		komanda = Komande::ZavrsiIgru;
		return true;

	} else {
		greska=KodoviGresaka::PogresnaKomanda;
		// Boze oprosti
	}
	return false;
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y,
                   Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0)
{	
	
	Status temp;
	if (komanda == Komande::KreirajIgru) {

		int n;
		UnosBroja("Unesite broj polja: ", "Greska, unesite ponovo!", n);
		int a,b;
		std::vector<std::vector<int>> mine;

		std::cout << "Unesite pozicije mina: ";

		char temp {')'};

		while (temp==')') {

			std::cin>>temp;
			if(temp!='(') {
				if(temp=='.') break;
				OcistiTok(1);
				std::cout<<"Greska, unesite ponovo!"<<std::endl;
				temp=')';
				continue;
			}
			std::cin>>a;
			std::cin>>temp;
			if(temp!=',' || a>=n) {
				if(temp=='.') break;
				OcistiTok(1);
				std::cout<<"Greska, unesite ponovo!"<<std::endl;
				temp=')';
				continue;
			}
			std::cin>>b;
			std::cin>>temp;
			if(temp==')' && b<n) {
				std::vector<int>m;
				m.push_back(a);
				m.push_back(b);
				mine.push_back(m);
				continue;
			} else {
				if(temp=='.') break;
				OcistiTok(1);
				std::cout<<"Greska, unesite ponovo!"<<std::endl;
				temp=')';
				continue;
			}
		}
		OcistiTok(1);
		X1=0;
		Y1=0;
		polja = KreirajIgru(n,mine);

	}

	else if (komanda==Komande::PomjeriJednoMjesto) {
		temp = Idi (polja, X1, Y1, p_smjer);
		if (temp == Status::KrajPoraz) {
			std::cout << "Nagazili ste na minu" << std::endl;
			throw std::runtime_error ("Igra zavrsena");
		} else if (temp == Status::KrajPobjeda) {
			std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
			throw std::runtime_error ("Igra zavrsena");
		}
		std::cout<<"Tekuca pozicija igraca je (" << X1 << "," << Y1 << ")" << std::endl;
	} else if (komanda==Komande::PomjeriDalje) {
		Status temp (Status::NijeKraj);

		OcistiTok(1);
		temp = Idi(polja,x,y,x,y);
		if (temp == Status::KrajPoraz) {
			std::cout << "Nagazili ste na minu" << std::endl;
			throw std::runtime_error ("Igra zavrsena");
		} else if (temp==Status::KrajPobjeda)  {
			std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
			throw std::runtime_error ("Igra zavrsena");
		}
		std::cout<<"Tekuca pozicija igraca je (" << X1 << "," << Y1 << ")" << std::endl;
	} else if (komanda==Komande::ZavrsiIgru) {
		OcistiTablu(polja);
		throw std::runtime_error("Dovidjenja!");

	} else if (komanda==Komande::Blokiraj) {
		BlokirajPolje(polja,x,y);
	} else if (komanda==Komande::Deblokiraj) {
		int a1,b1;
		DeblokirajPolje(polja,x,y);
	} else if (komanda==Komande::PrikaziOkolinu) {
		std::vector<std::vector<int>> okolina = PrikaziOkolinu(polja,X1,Y1);
		IspisiMatricu(okolina);
	};
}

int main ()
{
	Tabla tabla;

	std::vector<std::vector<int>> minoni;

	tabla = KreirajIgru(0,minoni);
	std::string s;
	int x=0, y =0;
	Komande komanda;
	Smjerovi GL;
	KodoviGresaka greska;

	while (1) {
		try {
Spas:
			std::cout << "Unesite komandu: ";
			if (UnosKomande(komanda,GL,x,y,greska)==true) IzvrsiKomandu(komanda,tabla,x,y,GL);
			else {
				PrijaviGresku(greska);
				continue;
			}
		} catch(const std::runtime_error &e) {
			std::cout <<  e.what() << std::endl;
			break;

		} catch(const std::logic_error &e) {
			std::cout << e.what() << std::endl;
		} catch(const std::out_of_range &e) {
			std::cout << e.what() << std::endl;
		}
	}
	return 0;

	// Ubaci prijavi gresku jos i tjt
}
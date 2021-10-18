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

bool IspravnoPolje(int x, int y, int n)
{
	return(x>=0 && x<=n-1 && y>=0 && y<=n-1);

}

Tabla KreirajIgru (int n, const std::vector<std::vector<int>> &mine)
{

	if(n<=0)
		throw std::domain_error("Ilegalna velicina!");

	Tabla t(n, std::vector<Polje>(n, Polje :: Prazno));

	for(int i=0; i<mine.size(); i++) {
		if(mine.at(i).size() != 2)
			throw std::domain_error ("Ilegalan format zadavanja mina!");

		for(int j=0; j<mine.at(0).size(); j++) {
			if(mine.at(i).at(j) < 0 || mine.at(i).at(j) > n-1
			        || mine.at(i).at(j+1) < 0 || mine.at(i).at(j+1) > n-1 )
				throw std::domain_error ("Ilegalne pozicije mina!");

			t.at(mine.at(i).at(j)).at(mine.at(i).at(j+1)) = Polje::Mina;
			j++;
		}
	}

	return t;
}

int BrojMinaUOkolini(const Tabla &polja, int x, int y)
{
	int mine(0);

	for(int i=x-1; i<=x+1; i++) {
		for(int j=y-1; j<=y+1; j++) {
			if(IspravnoPolje(i,j,polja.size()) && (i!=x || j!=y) && polja.at(i).at(j)==Polje :: Mina)
				mine++;
		}
	}

	return mine;
}

std::vector<std::vector<int>> PrikaziOkolinu (const Tabla &polja, int x, int y)
{

	if(!IspravnoPolje(x,y,polja.size()))
		throw std::domain_error (std::string("Polje (") + std::to_string(x) + std::string(",") + std::to_string(y) + std::string(") ne postoji"));
	std::vector<std::vector<int>> okolina(3, std::vector<int>(3,0));
	int m(0), n(0);
	for(int i=x-1; i<=x+1; i++) {
		n=0;
		for(int j=y-1; j<=y+1; j++) {
			okolina.at(m).at(n)=BrojMinaUOkolini(polja, i, j);
			n++;
		}
		m++;
	}

	return okolina;
}

void BlokirajPolje (Tabla &polja, int x, int y)
{

	if(x<0 || x>polja.size()-1 || y<0 || y>polja.size()-1)
		throw std::domain_error (std::string("Polje (") + std::to_string(x) + std::string(",") + std::to_string(y) + std::string(") ne postoji"));

	if (polja.at(x).at(y) == Polje :: Prazno)
		polja.at(x).at(y) = Polje :: BlokiranoPrazno;
	else if (polja.at(x).at(y) == Polje :: Posjeceno)
		polja.at(x).at(y) = Polje :: BlokiranoPosjeceno;
	else if (polja.at(x).at(y) == Polje :: Mina)
		polja.at(x).at(y) = Polje :: BlokiranoMina;
}

void DeblokirajPolje (Tabla &polja, int x, int y)
{
	if(x<0 || x>polja.size()-1 || y<0 || y>polja.size()-1)
		throw std::domain_error (std::string("Polje (") + std::to_string(x) + std::string(",") + std::to_string(y) + std::string(") ne postoji"));

	if (polja.at(x).at(y) == Polje :: BlokiranoPrazno)
		polja.at(x).at(y) = Polje :: Prazno;
	else if (polja.at(x).at(y) == Polje :: BlokiranoPosjeceno)
		polja.at(x).at(y) = Polje :: Posjeceno;
	else if (polja.at(x).at(y) == Polje :: BlokiranoMina)
		polja.at(x).at(y) = Polje :: Mina;
}

void OcistiMatricu(Tabla &polja)
{
	for(int i=0; i<polja.size(); i++) {
		for(int j=0; j<polja.at(i).size(); j++)
			polja.at(i).at(j) = Polje :: Prazno;
	}
}

int BrojPraznih (const Tabla &polja)
{
	int brojac(0);

	for(int i=0; i<polja.size(); i++) {
		for(int j=0; i<polja.at(i).size(); j++) {
			if(polja.at(i).at(j) == Polje :: Prazno)
				brojac++;
		}
	}

	return brojac;
}


Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer)
{

	const int pomak[8][2] {{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
	int tmp_x(x+pomak[int(smjer)][0]), tmp_y(y+pomak[int(smjer)][1]);

	if(polja.at(tmp_x).at(tmp_y) == Polje :: BlokiranoPosjeceno ||
	        polja.at(tmp_x).at(tmp_y) == Polje :: BlokiranoPrazno ||
	        polja.at(tmp_x).at(tmp_y) == Polje :: BlokiranoMina)
		throw std::logic_error ("Blokirano polje");
	if(IspravnoPolje(tmp_x, tmp_y, polja.size())) {
		x=tmp_x;
		x=tmp_y;
	} else
		throw std::out_of_range ("Izlazak van igrace table.");

	if(polja.at(x).at(y) == Polje :: Mina) {
		OcistiMatricu(polja);
		return Status :: KrajPoraz;
	} else if(polja.at(x).at(y) == Polje :: Prazno && BrojPraznih(polja)==0) {
		return Status :: KrajPobjeda;
	}

	polja.at(x).at(y) = Polje :: Posjeceno;
	return Status :: NijeKraj;

}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y)
{
	if(polja.at(novi_x).at(novi_y) == Polje :: BlokiranoPosjeceno ||
	        polja.at(novi_x).at(novi_y) == Polje :: BlokiranoPrazno ||
	        polja.at(novi_x).at(novi_y) == Polje :: BlokiranoMina)
		throw std::logic_error ("Blokirano polje");

	if(IspravnoPolje(novi_x, novi_y, polja.size())) {
		x=novi_x;
		y=novi_y;
	} else
		throw std::out_of_range ("Izlazak van igrace table.");

	if(polja.at(x).at(y) == Polje :: Mina) {
		OcistiMatricu(polja);
		return Status :: KrajPoraz;
	} else if(polja.at(x).at(y) == Polje :: Prazno && BrojPraznih(polja)==0) {
		return Status :: KrajPobjeda;
	}

	polja.at(x).at(y) = Polje :: Posjeceno;
	return Status :: NijeKraj;
}

void PrijaviGresku (KodoviGresaka greska)
{
	switch (greska) {
	case KodoviGresaka::PogresnaKomanda :
		std::cout << "Nerazumljiva komanda!" << std::endl;
		break;
	case KodoviGresaka::NedostajeParametar :
		std::cout << "Komanda trazi parametar koji nije naveden!" << std::endl;
		break;
	case KodoviGresaka::NeispravanParametar :
		std::cout << "Parametar komande nije ispravan!" << std::endl;
		break;
	case KodoviGresaka::SuvisanParametar :
		std::cout << "Zadan je suvisan parametar nakon komande!" << std::endl;
	}
}
 

int main ()
{
	return 0;
}

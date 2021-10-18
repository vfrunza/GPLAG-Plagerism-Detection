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

bool UnosKomande (Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska);

Tabla KreirajIgru (int n, const std::vector<std::vector<int>> &mine)
{
	std::vector<std::vector<Polje>> a (Prazno);

	if(n<=0) throw std::domain_error ("Ilegalna velicina");

	for(int i=0; i<n; i++)
		a.at(i).resize(n);

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			for(int p=0; p<mine.size(); p++) {
				//for(int r=p; r<mine.size(); r++)
				//{ if(p.at(r).size()!=2) throw std::domain_error ("Ilegalan format zadavanja mina"); }
				if(p.at(p).size()!=2)
					throw std::domain_error ("Ilegalan format zadavanja mina");
				for(int q=0; q<2; q++) {
					if(mine.at(q)<0 || mine.at(q)>n) throw std::domain_error ("Ilegalne pozicije mina");
					if(i==mine.at(p) && j==mine.at(q))
						a.at(i).at(j)==Mina;
				}
			}
		}
	}
	return a;
}

std::vector<std::vector<int>> PrikaziOkolinu (const Tabla &polja, int x, int y)
{
	if(x<0 || x>n || y<0 || y>n) throw std::domain_error ("Polje ("<<x<<","<<y<<") ne postoji");
	
	std::vector<std::vector<int>> b;

}

void BlokirajPolje (Tabla &polja, int x, int y)
{

}

void DeblokirajPolje (Tabla &polja, int x, int y)
{

}

Status Idi (Tabla &polja, int &x, int &y, Smjerovi smjer)
{

}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y)
{

}

void IzvrsiKomandu (Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer=Smjerovi::Gore, int p_x=0, int p_y=0);


int main ()
{
	return 0;
}

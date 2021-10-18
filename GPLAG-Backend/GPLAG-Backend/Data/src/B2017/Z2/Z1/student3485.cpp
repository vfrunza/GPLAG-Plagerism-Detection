#include <iostream>
#include <vector>
#include <stdexcept>

enum class Polje {
Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};

enum class Smjerovi {
GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};

enum class Status {
NijeKraj, KrajPoraz, KrajPobjeda
};

enum class KodoviGresaka {
    PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};

enum class Komande {
    PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n, std::vector<std::vector<int>> &m)
{
	if(n <= 0) throw std::domain_error ("Ilegalna velicina");
	Tabla t(n, std::vector<Polje> (n, Polje::Prazno));
	for(int i=0; i<m.size(); i++)
		if(m[i].size() != 2) 
			throw std::domain_error ("Ilegalan format zadavanja mina");
	for(int i=0; i<m.size(); i++)
	{
		for(int j=0; j<m[i].size(); j++)
		if(m[i][j]<0 || m[i][j] >=n)
			throw std::domain_error ("Ilegalne pozicije mina");
	}
	for(int i=0; i<m.size(); i++)
		if(!(m[i][0] == 0  && m[i][1] == 0))
			t[m[i][0]][m[i][1]] = Polje::Mina;
			
	return t;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polje, int x, int y)
{
	if(x<0 || x>=polje.size() || y<0 || y>=polje.size())
		throw std::domain_error ("Polje ("+ std::to_string(x) + "," + std::to_string(y) + ") ne postoji!");
	std::vector<std::vector<int>> O(3);
	int red(0);
	for(int i=x-1; i<=x+1; i++)
	{
		for(int j=y-1; j<=y+1; j++)
		{
			int br_mina(0);
			for(int k=i-1; k<=i+1; k++)
			{
				for(int l=j-1; j<=j+1; j++)
				{
					if(i>=0 && j>=0 && i<polje.size() && j<polje[0].size() && k>=0 && l>=0 && k<polje.size() && l<=polje[0].size()
					&& !(k==i && l==j) && !(k==x && l==y) && polje[k][l] == Polje::Mina)
						br_mina++;
				}
			}
			O[red].push_back(br_mina);
		}
		red++;
	}
	return O;
}

void BlokirajPolje(Tabla &polje, int x, int y)
{
	if(x<0 || x>=polje.size() || y<0 || y>=polje[0].size())
		throw std::domain_error ("Polje ("+ std::to_string(x) + "," + std::to_string(y) + ") ne postoji!");
	else if(polje[x][y] == Polje::Prazno) polje[x][y] = Polje::BlokiranoPrazno;
	else if(polje[x][y] == Polje::Mina) polje[x][y] = Polje::BlokiranoMina;
	else if(polje[x][y] == Polje::Posjeceno) polje[x][y] = Polje::BlokiranoPosjeceno;
}
 void DeblokirajPolje(Tabla &polje, int x, int y)
 {
 	if(x<0 || x>=polje.size() || y<0 || y>=polje[0].size())
		throw std::domain_error ("Polje ("+ std::to_string(x) + "," + std::to_string(y) + ") ne postoji!");
	else if(polje[x][y] == Polje::BlokiranoPrazno) polje[x][y] = Polje::Prazno;
	else if(polje[x][y] == Polje::BlokiranoMina) polje[x][y] = Polje::Mina;
	else if(polje[x][y] == Polje::BlokiranoPosjeceno) polje[x][y] = Polje::Posjeceno;
 }

Status Idi(Tabla &polje, int x, int y, Smjerovi s)
{
	if(s == Smjerovi::GoreLijevo)
	{
		if(x-1 < 0 || y-1 < 0)
			throw std::out_of_range ("Izlazak van igrace table");
		else if(polje[x-1][y-1] != Polje::BlokiranoPosjeceno && polje[x-1][y-1] != Polje::BlokiranoMina && polje[x-1][y-1] != Polje::BlokiranoPrazno) 
		{
			polje[x][y] = Polje::Posjeceno;
			x = x-1;
			y = y-1;
		}
		else throw std::logic_error ("Blokirano polje");
	}
	else if(s == Smjerovi::GoreDesno)
	{
		if(x-1 < 0 || y+1 >= polje[0].size())
			throw std::out_of_range ("Izlazak van igrace table");
		else if(polje[x-1][y+1] != Polje::BlokiranoPosjeceno && polje[x-1][y+1] != Polje::BlokiranoMina && polje[x-1][y+1] != Polje::BlokiranoPrazno)
		{
			polje[x][y] = Polje::Posjeceno;
			x = x-1;
			y = y+1;
		}
		else throw std::logic_error ("Blokirano polje");
	}
	else if(s == Smjerovi::Gore)
	{
		if(x-1 < 0)
			throw std::out_of_range ("Izlazak van igrace table");
		else if(polje[x-1][y] != Polje::BlokiranoPosjeceno && polje[x-1][y] != Polje::BlokiranoMina && polje[x-1][y] != Polje::BlokiranoPrazno)
		{
			polje[x][y] = Polje::Posjeceno;
			x = x-1;
		}
		else throw std::logic_error ("Blokirano polje");
	}
	else if(s == Smjerovi::Desno)
	{
		if(y+1 >= polje[0].size())
			throw std::out_of_range ("Izlazak van igrace table");
		else if(polje[x][y+1] != Polje::BlokiranoPosjeceno && polje[x][y+1] != Polje::BlokiranoMina && polje[x][y+1] != Polje::BlokiranoPrazno)
		{
			polje[x][y] = Polje::Posjeceno;
			y = y+1;
		}
		else throw std::logic_error ("Blokirano polje");
	}
	else if(s == Smjerovi::Dolje)
	{
		if(x+1 >= polje.size())
			throw std::out_of_range ("Izlazak van igrace table");
		else if(polje[x+1][y] != Polje::BlokiranoPosjeceno && polje[x+1][y] != Polje::BlokiranoMina && polje[x+1][y] != Polje::BlokiranoPrazno)
		{
			polje[x][y] = Polje::Posjeceno;
			x = x+1;
		}
		else throw std::logic_error ("Blokirano polje");
	}
	else if(s == Smjerovi::Lijevo)
	{
		if(y-1 < 0)
			throw std::out_of_range ("Izlazak van igrace table");
		else if(polje[x][y-1] != Polje::BlokiranoPosjeceno && polje[x][y-1] != Polje::BlokiranoMina && polje[x][y-1] != Polje::BlokiranoPrazno)
		{
			polje[x][y] = Polje::Posjeceno;
		}
		else throw std::logic_error ("Blokirano polje");
	}
	else if(s == Smjerovi::DoljeLijevo)
	{
		if(x+1 >= polje.size() || y+1 >= polje[0].size())
			throw std::out_of_range ("Izlazak van igrace table");
		else if(polje[x+1][y-1] != Polje::BlokiranoPosjeceno && polje[x+1][y-1] != Polje::BlokiranoMina && polje[x+1][y-1] != Polje::BlokiranoPrazno)
		{
			polje[x][y] = Polje::Posjeceno;
			x = x+1;
			y = y-1;
		}
		else throw std::logic_error ("Blokirano polje");
	}
	else if(s == Smjerovi::DoljeDesno)
	{
		if(x+1 >= polje.size() || y+1 >= polje[0].size())
			throw std::out_of_range ("Izlazak van igrace table");
		else if(polje[x+1][y+1] != Polje::BlokiranoPosjeceno && polje[x+1][y+1] != Polje::BlokiranoMina && polje[x+1][y+1] != Polje::BlokiranoPrazno)
		{
			polje[x][y] = Polje::Posjeceno;
			x = x+1;
			y = y+1;
		}
		else throw std::logic_error ("Blokirano polje");
	}
	
	if(polje[x][y] == Polje::Mina)
	{
		for(int i=0; i<polje.size(); i++)
		{
			for(int j=0; j<polje[i].size(); j++)
			{
				polje[i][j] = Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
	else 
	{
		for(int i=0; i<polje.size(); i++)
		{
			for(int j=0; j<polje[i].size(); j++)
			{
				if(i != x && j != y && polje[x][y] == Polje::Prazno) 
					return Status::NijeKraj;
			}
		}
		
		return Status::KrajPobjeda;
	}
}

Status Idi(Tabla &polje, int &x, int &y, int a, int b)
{
	if(a<0 || a>= polje.size() || b<0 || b>=polje.size())
		throw std::out_of_range ("Izlazak van igrace table");
	if(polje[a][b] != Polje::BlokiranoPosjeceno && polje[a][b] != Polje::BlokiranoMina && polje[a][b] != Polje::BlokiranoPrazno)
	{
		x = a;
		y = b;
	}
	else throw std::logic_error ("Blokirano polje");
	if(polje[x][y] == Polje::Mina)
	{
		for(int i=0; i<polje.size(); i++)
		{
			for(int j=0; j<polje[i].size(); j++)
			{
				polje[i][j] = Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
	else 
	{
		for(int i=0; i<polje.size(); i++)
		{
			for(int j=0; j<polje[i].size(); j++)
			{
				if(i != x && j != y && polje[x][y] == Polje::Prazno) 
					return Status::NijeKraj;
			}
		}
		
		return Status::KrajPobjeda;
	}
}

void PrjaviGresku(KodoviGresaka &g)
{
	if(g == KodoviGresaka::PogresnaKomanda)
		std::cout << "Nerazumljiva komanda!" << std::endl;
	else if(g == KodoviGresaka::NedostajeParametar) 
		std::cout << "Komanda trazi parametar koji nije naveden!" << std::endl;
	else if(g == KodoviGresaka::NeispravanParametar)
		std::cout << "Parametar komande nije ispravan!" << std::endl;
	else if(g == KodoviGresaka::SuvisanParametar)
		std::cout << "Zadan je suvisan parametar nakon komande!" << std::endl;
}

/*bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska)
{
	
}*/
int main()
{
	return 0;
}
/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/

#include <iostream>
#include <vector>
#include <stdexcept>

enum class Polje {
 Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine)
{
	for(auto i:mine) if(i.size() != 2) throw std::domain_error("Ilegalan format zadavanja mina");
	for(auto i:mine)
	for(auto j:i)
	{
		if(j < 0 || j >= n) throw std::domain_error("Ilegalne pozicije mina");
	}
	
	Tabla table(n, std::vector<Polje> (n, Polje::Prazno));
	for(auto i:mine)
	{
		table[i[0]][i[1]] = Polje::Mina;
	}
	return table;
}

int PrebrojOkolo(const Tabla &polja, int x, int y)
{
		std::cout << std::endl << "Brojim tacku (" << x << "," << y << ")";
	int cx = x;
	int cy = y;
	x--;
	y--;
	
	int brojac(0);
	for(int i = y; i < y+3; i++)
	{
		if(i<0 || i > polja.size()-1) continue;
		for(int j = x; j < x+3; j++)
		{
			if(j<0 || j > polja.size()-1) continue;
			if(cx == i && cy == y) continue;
			if(polja[i][j] == Polje::Mina) brojac++;
		}
	}
		std::cout << std::endl << " Vracam "<< brojac;
	return brojac;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y)
{
	if(x<0 || y<0 || x > polja.size()-1 || y > polja.size()-1) throw std::domain_error("Polje (x,y) ne postoji");
	std::vector<std::vector<int>> Okolina(3, std::vector<int>(3));
	x--;
	y--;
	for(int i=0; i<Okolina.size(); i++)
	{
		if(y+i<0 || y+i>polja.size()-1) continue;
		for(int j=0; j<Okolina[i].size(); j++)
		{
			if(x+j < 0 || x+j > polja.size()-1) continue;
			if(polja[x+j][y+i] == Polje::Mina)
			{
				Okolina[i][j] = 0;
				continue;
			}
			Okolina[i][j] = PrebrojOkolo(polja, x+j,y+i);
			
		}
		
	}
	return Okolina;
}

void PrikaziTablu(const Tabla &polja)
{
	std::vector<std::vector<int>> tab(polja.size(), std::vector<int>(polja.size()));
	for(int i=0; i<polja.size(); i++)
	for(int j=0; j<polja.size(); j++)
	{
		if(polja[i][j] == Polje::Mina) tab[i][j] = 1;
	}
	
	for(auto red : tab) 
	{
		for(auto x : red) std::cout << std::right << x << " ";
 		std::cout << std::endl;
	}
	
}	
int main ()
{
	std::vector<std::vector<int>> mine {{0,0}, {2,2}, {3,3}, {2,4}, {3,4}, {0,2}, {2,0}};
	Tabla Igra = KreirajIgru(5, mine);
	
	PrikaziTablu(Igra);
	
	std::cout << std::endl;
	
	std::vector<std::vector<int>> ok = PrikaziOkolinu(Igra, 4,4);
	for(auto red : ok) 
	{
		for(auto x : red) std::cout << std::right << x << " ";
 		std::cout << std::endl;
	}
	return 0;
}
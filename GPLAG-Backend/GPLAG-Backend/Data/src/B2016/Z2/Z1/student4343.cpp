/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include<iostream>
#include<vector>
#include<stdexcept>

enum class Polje {
 Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine)
{
	Tabla nova;
	nova.resize(n);
	for(int i=0; i<n; i++)
	{
		nova[i].resize(n);
		for(int j=0; j<n; j++)
		{
			nova[i][j]=Polje::Prazno;
		}
	}
	for(int i=0; i<mine.size(); i++)
	{
		if(mine[i].size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
		int a(mine[i][0]);
		int b(mine[i][1]);
		nova[a][b]=Polje::Mina;
	}
	return nova;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y)
{
	std::vector<std::vector<int>> novi;
	novi.resize(3);
	for(int i=0; i<3; i++)
	{
		novi[i].resize(3);
	}
	for(int i=x-1; i<=x+1; i++)
	{
		for(int j=y-1; j<=y+1; j++)
		{
			int br(0);
			if(polja[i-1][j-1]==Polje::Mina) br++;
			if(polja[i-1][j]==Polje::Mina) br++;
			if(polja[i-1][j+1]==Polje::Mina) br++;
			if(polja[i][j-1]==Polje::Mina) br++;
			if(polja[i][j]==Polje::Mina) br++;
			if(polja[i][j+1]==Polje::Mina) br++;
			if(polja[i+1][j-1]==Polje::Mina) br++;
			if(polja[i+1][j]==Polje::Mina) br++;
			if(polja[i+1][j+1]==Polje::Mina) br++;
			
		}
	}
	return novi;
}

int main ()
{
	std::vector<std::vector<int>> v {{0,0},{0,2},{1,3}};
	try
	{
		Tabla nova(KreirajIgru(4, v));
		for(int i=0; i<nova.size(); i++)
		{
			for(int j=0; j<nova[i].size(); j++)
			{
				if(nova[i][j]==Polje::Prazno) std::cout << "0 ";
				else std::cout << "1 ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl << std::endl;
		std::vector<std::vector<int>> Prikaz(PrikaziOkolinu(nova,1,2));
		for(int i=0; i<Prikaz.size(); i++)
		{
			for(int j=0; j<Prikaz[0].size(); j++)
			{
				std::cout << Prikaz[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
	catch(std::domain_error t)
	{
		std::cout << t.what();
	}
	return 0;
}
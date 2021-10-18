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
#include<vector>
#include<stdexcept>

typedef std::vector<std::vector<Polje>> Tabla;

enum Polje{Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina};
Tabla KreirajIgru(int n,const std::vector<std::vector<int>>&mine);
std::vector<std::vector<int>>PrikaziOkolinu(const Tabla &polja,int x,int y);
void BlokirajPolje(Tabla &polja,int x,int y);
void DeblokirajPolje(Tabla &polja,int x,int y);
Status Idi(Tabla &polja,int &x, int &y,Smjerovi smjer);
Status Idi(Tabla &polja,int &x, int &y,int novi_x,int novi_y);

Tabla KreirajIgru(int n,const std::vector<std::vector<int>>&mine)
{
	if(n<=0)
	throw std::domain_error("Ilegalna velicina.");
	
	for(int i=0;i<mine.size();i++)
	{
		for(int j=0;j<mine[i].size();j++)
		{
			if(mine[i].size()!=2)
			throw std::domain_error("Ilegalan format zadavanja mina");
		}
	}
	
	for(int i=0;i<mine.size();i++)
	{
		if(mine[i][0]<0 || mine[i][0]>=n || mine[i][1]>0 || mine[i][1]>=n)
		throw std::domain_error("Ilegalan format zadavanja mina");
	}
	Tabla polje(n,std::vector<Polje>Prazno);
	for(int i=0;i<mine.size();i++)
	{
		polje(mine[i][0]mine[i][1])==Mine;
	}
	return tabla;
}
std::vector<std::vector<int>>PrikaziOkolinu(const Tabla &polja,int x,int y)
{
	
}
void BlokirajPolje(Tabla &polja,int x,int y)
{
	
}



int main ()
{
	return 0;
}
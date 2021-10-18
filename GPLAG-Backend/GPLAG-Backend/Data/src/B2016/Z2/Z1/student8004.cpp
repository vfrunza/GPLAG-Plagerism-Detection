/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include<iostream>
#include<vector>
#include<stdexcept>

using namespace std;

enum class Polje {    Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina   };
typedef std::vector<std::vector<Polje>> Tabla; 

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine)
{
	Tabla f;
	f.resize(n);
	for(int i=0; i<n; i++) f[i].resize(n);
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			f[i][j]=Polje::Prazno;
	for(int i=0; i<mine.size(); i++)
	{
		int h=mine[i][0];
		int v=mine[i][1];
		f[h][v]=Polje::Mina;
	}
	return f;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y)
{
	vector<vector<int>> v;
	v.resize(3);
	for(int i=0; i<3; i++) v[i].resize(3);
	int ii=x-1, jj=y-1;
	for(int i=0; i<polja.size(); i++)
	{
		for(int j=0; j<polja.size(); j++)
		{
			if(i==x && j==y)
			{
				int uredu=0, ukoloni=0;
				int pomi=x-1;
				if(pomi<0) { pomi++; uredu++;}
				int br=0;
				for(int k=0; k<3; k++)
				{
					
				}
			}
		}
	}
	
}

int main ()
{
	return 0;
}
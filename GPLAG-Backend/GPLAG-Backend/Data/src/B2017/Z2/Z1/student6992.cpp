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
#include <cmath>

using namespace std;



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
 PogresnaKomanda, NedostajeParmetar, SuvisanParametar, NeispravanParametar
};

typedef std::vector<std::vector<Polje>> Tabla;


int PrebrojMine(const Tabla &polja,int x,int y)
{
	
	int suma(0);
	if((x>0 && x<polja.size()-1)&&(y>0 && y<polja.size()-1))
	{
		for(int i=x-1;i<=x+1;i++)
			for(int j=y-1;j<=y+1;j++)
				if(i!=x && j!=y && polja[i][j]==(Polje)1)
						suma++;
		
	}

	return suma;
	
}

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine)
{
	Tabla t(n,vector<Polje>(n));
	
	
	for(int i=0;i<mine.size();i++)
	{
		t[mine[i][0]][mine[i][1]]=(Polje)1;
	}
	
	
	
	
	for(int i=0;i<t.size();i++)
	{
		for(int j=0;j<t.size();j++)
			cout<<(int)t[i][j];
		cout<<endl;
	}
	
	return t;
}
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y)
{
	vector<vector<int>> mat(3,vector<int>(3));
	
	for(int i=x-1;i<=x+1;i++)
	{
		for(int j=y-1;j<=y+1;j++)
			mat[fabs(x-i-1)][fabs(y-j-1)]=PrebrojMine(polja,i,j);
			
	}
	
	
	for(int i=0;i<mat.size();i++)
	{
		for(int j=0;j<mat[i].size();j++)
			cout<<mat[i][j];
		cout<<endl;
	}
	
	return mat;
}
void BlokirajPolje(Tabla &polja, int x, int y);
void DeblokirajPolje(Tabla &polja, int x, int y);
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer);
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y);

int main ()
{	
	vector<vector<int>> mat= {{0,0},{1,1}, {0,2}, {1,3}};
	//KreirajIgru(4,mat);
	PrikaziOkolinu(KreirajIgru(4,mat),1,1);
	return 0;
}
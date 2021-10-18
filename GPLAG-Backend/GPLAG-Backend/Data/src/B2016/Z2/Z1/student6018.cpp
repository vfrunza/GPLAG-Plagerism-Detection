/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

using namespace std;


enum class KodoviGresaka {
 PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};

enum class Polje {
 Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};
enum class Smjerovi {
 GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};
enum class Status { NijeKraj, KrajPoraz, KrajPobjeda};


typedef vector<vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const vector<vector<int>> &mine)
{
	Tabla tabla(n);
	for(int i=0;i<n;i++)
	{
		tabla[i].resize(n);
	}
	for(int i=0;i<mine.size();i++)
	{
		if(mine[i].size()!=2)
		throw domain_error("Ilegalan format zadavanja mina");
		
	}
	for(int i=0;i<mine.size();i++)
	{
		for(int j=0;j<mine[i].size();j++)
		{
			if(mine[i][j]>=n)
			throw domain_error("Ilegalne pozicije mina");
		}
	}
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			tabla[i][j]=Polje::Prazno; 
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			for(int k=0;k<mine.size();k++)
			{
				if(i==mine[k][0]&&j==mine[k][1])
				tabla[i][j]=Polje::Mina;
				
			}
		}
	}
	return tabla;
	
}

void BlokirajPolje(Tabla &polja, int x, int y)
{
	if((x>=polja.size())||(y>=polja.size()))
	{
		string xx=to_string(x);
		string yy=to_string(y);
	
	throw domain_error("Polje ("+xx+","+yy+") ne postoji");
	}
	if(polja[x][y]==Polje::Prazno)
	polja[x][y]=Polje::BlokiranoPrazno;
	else if(polja[x][y]==Polje::Posjeceno)
	polja[x][y]=Polje::BlokiranoPosjeceno;
	else if(polja[x][y]==Polje::Mina)
	polja[x][y]=Polje::BlokiranoMina;
			
}

void DeblokirajPolje(Tabla &polja, int x, int y)
{
	if((x>=polja.size())||(y>=polja.size()))
	{
		string xx=to_string(x);
		string yy=to_string(y);
	
	throw domain_error("Polje ("+xx+","+yy+") ne postoji");
	}
	
	if(polja[x][y]==Polje::BlokiranoPrazno)
	polja[x][y]=Polje::Prazno;
	else if(polja[x][y]==Polje::BlokiranoPosjeceno)
	polja[x][y]=Polje::Posjeceno;
	else if(polja[x][y]==Polje::BlokiranoMina)
	polja[x][y]=Polje::Mina;
			
}


Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer)
{
	polja[x][y]=Polje::Posjeceno;
	Status status=Status::KrajPobjeda;
	for(int i=0;i<polja.size();i++)
	{
		for(int j=0;j<polja[i].size();j++)
		{
			if(polja[i][j]==Polje::Prazno || polja[i][j]==Polje::BlokiranoPrazno)
			{
				status=Status::NijeKraj;
				break;
			}
		}
	}
	
	if(smjer==Smjerovi::GoreLijevo)
	{
		y--;
		x--;
	}
	else if(smjer==Smjerovi::GoreDesno)
	{
		x--;
		y++;
	}
	else if(smjer==Smjerovi::Gore)
	x--;
	else if(smjer==Smjerovi::Dolje)
	x++;
	else if(smjer==Smjerovi::Desno)
	y++;
	else if(smjer==Smjerovi::Lijevo)
	y--;
	else if(smjer==Smjerovi::DoljeDesno)
	{
		y++;
		x++;
	}
	else
	{
		x++;
		y--;
	}
		if(x<0|| x>polja.size()|| y<0 || y>polja.size())
	throw out_of_range("Izlazak van igrace table");
	if((polja[x][y]==Polje::BlokiranoPosjeceno)||(polja[x][y]==Polje::BlokiranoMina)||(polja[x][y]==Polje::BlokiranoPrazno))
	throw logic_error("Blokirano polje");
	
	if(polja[x][y]==Polje::Mina)
	status=Status::KrajPoraz;
	return status;
	
	
	
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y)
{
	polja[x][y]=Polje::Posjeceno;
	Status status=Status::KrajPobjeda;
	for(int i=0;i<polja.size();i++)
	{
		for(int j=0;j<polja[i].size();j++)
		{
			if(polja[i][j]==Polje::Prazno || polja[i][j]==Polje::BlokiranoPrazno)
			{
				status=Status::NijeKraj;
				break;
			}
		}
	}
	
	x=novi_x;
	y=novi_y;
	if(x<0|| x>polja.size()|| y<0 || y>polja.size())
	throw out_of_range("Izlazak van igrace table");
	if((polja[x][y]==Polje::BlokiranoPosjeceno)||(polja[x][y]==Polje::BlokiranoMina)||(polja[x][y]==Polje::BlokiranoPrazno))
	throw logic_error("Blokirano polje");
	
	if(polja[x][y]==Polje::Mina)
	status=Status::KrajPoraz;
	return status;
	
}

void PrijaviGresku(KodoviGresaka greskica)
{
	if(greskica==KodoviGresaka::PogresnaKomanda)
	cout<<"Nerazumljiva komanda!"<<endl;
	else if(greskica==KodoviGresaka::NedostajeParametar)
	cout<<"Komanda trazi parametar koji nije naveden!"<<endl;
	else if(greskica==KodoviGresaka::NeispravanParametar)
	cout<<"Parametar komande nije ispravan!"<<endl;
	else if(greskica==KodoviGresaka::SuvisanParametar)
	cout<<"Zadan je suvisan parametar nakon komande!"<<endl;
}

vector<vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y)
{
	if((x>=polja.size())||(y>=polja.size()))
	{
		string xx=to_string(x);
		string yy=to_string(y);
	
	throw domain_error("Polje ("+xx+","+yy+") ne postoji");
	}
}
int main ()
{

}
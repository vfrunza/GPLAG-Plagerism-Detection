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
#include <utility>

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

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska)
{
	char s;
	std::cin >> s;
	if(s=='K'){
		komanda=Komande::KreirajIgru;
		std::cout << "Unesite broj polja: ";
	}
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0)
{
	//if(komanda==Komande::KreirajIgru)KreirajIgru(polja.size(), )
}

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine)
{
	Tabla Nova(n, std::vector<Polje>(n, Polje::Prazno));
	for(int i=0; i<mine.size(); i++)
	{
		for(int j=0; j<mine.at(i).size()-1; j++)
		{
			if(mine.at(i).size()!=2)throw(std::domain_error)"Ilegalan format zadavanja mina";
		// krah?	if(mine.at(i).at(j)>Nova.size() || mine.at(i).at(j+1)>Nova.at(i).size())throw(std::domain_error)"Ilegalna veličina";
			Nova.at(mine.at(i).at(j)).at(mine.at(i).at(j+1))=Polje::Mina;
		}
	}
	return Nova;
}

std::vector<std::vector<int>> PrikaziOkolinu(Tabla Nova, int x, int y)
{
	std::vector<std::vector<int>> Okolina(3, std::vector<int>(3));
	
	
	
	
	if(x<0 || y<0 || x>Nova.size() || y>Nova.at(0).size())throw(std::domain_error)"Polje (x,y) ne postoji";
	
	if(x==0)x=1;
	if(y==0)y=1;
	int k, l;
	int br(0);
	
	int je(0), dv(0);
	
	for(int i=x-1; i<x+2; i++)
	{
		if(i==Nova.size())break;
		for(int j=y-1; j<y+2; j++)
		{
			if(j==Nova.size())break;
			
			if(Nova[i][j]==Polje::Mina)br--;
			
			if(i==0)k=0;
			else k=i-1;
			for(;k<i+2;k++)
			{	
				if(k==Nova.size())break;
				if(j==0)l=0;
				else l=j-1;
				for(; l<j+2; l++)
				{
					if(j==Nova.size())break;
					
					if(Nova[k][l]==Polje::Mina)br++;
				}
			}
	
			Okolina[je][dv]=br;
			if(dv==2){je++;dv=0;} else dv++;
			br=0;
			
			
		}	
	}

	return Okolina;
}

void BlokirajPolje(Tabla &Nova, int x, int y)
{
	if(x<0 || y<0 || x>Nova.size() || y>Nova.at(0).size())throw(std::domain_error)"Polje (x,y) ne postoji";
	
	if(Nova[x][y]==Polje::Prazno)Nova[x][y]=Polje::BlokiranoPrazno;
	if(Nova[x][y]==Polje::Posjeceno)Nova[x][y]=Polje::BlokiranoPosjeceno;
	if(Nova[x][y]==Polje::Mina)Nova[x][y]=Polje::BlokiranoMina;
	
}

void DeblokirajPolje(Tabla &Nova, int x, int y)
{
	if(x<0 || y<0 || x>Nova.size() || y>Nova.at(0).size())throw(std::domain_error)"Polje (x,y) ne postoji";
	
	if(Nova[x][y]==Polje::BlokiranoPrazno)Nova[x][y]=Polje::Prazno;
	if(Nova[x][y]==Polje::BlokiranoPosjeceno)Nova[x][y]=Polje::Posjeceno;
	if(Nova[x][y]==Polje::BlokiranoMina)Nova[x][y]=Polje::Mina;
	
}

Status Idi(Tabla &Nova, int &x, int &y, Smjerovi Smjer)
{
	if(Smjer==Smjerovi::GoreLijevo)
	{
		if(x==0 || y==0)throw(std::out_of_range)"Izlazak van igrace table";
		if(Nova[x-1][y-1]==Polje::BlokiranoPrazno || Nova[x-1][y-1]==Polje::BlokiranoPosjeceno || Nova[x-1][y-1]==Polje::BlokiranoMina)throw(std::logic_error)"Blokirano polje";
		Nova[x][y]=Polje::Posjeceno;
		x--;
		y--;
		
	}
	if(Smjer==Smjerovi::Gore)
	{
		if(x==0)throw(std::out_of_range)"Izlazak van igrace table";
		if(Nova[x-1][y]==Polje::BlokiranoPrazno || Nova[x-1][y]==Polje::BlokiranoPosjeceno || Nova[x-1][y]==Polje::BlokiranoMina)throw(std::logic_error)"Blokirano polje";
		Nova[x][y]=Polje::Posjeceno;
		x--;
		
	}
	if(Smjer==Smjerovi::GoreDesno)
	{
		if(x==0 || y==Nova.size()-1)throw(std::out_of_range)"Izlazak van igrace table";
		if(Nova[x-1][y+1]==Polje::BlokiranoPrazno || Nova[x-1][y+1]==Polje::BlokiranoPosjeceno || Nova[x-1][y+1]==Polje::BlokiranoMina)throw(std::logic_error)"Blokirano polje";
		Nova[x][y]=Polje::Posjeceno;
		x--;
		y++;
		
	}
	if(Smjer==Smjerovi::Desno)
	{
		if(y==Nova.size()-1)throw(std::out_of_range)"Izlazak van igrace table";
		if(Nova[x][y+1]==Polje::BlokiranoPrazno || Nova[x][y+1]==Polje::BlokiranoPosjeceno || Nova[x][y+1]==Polje::BlokiranoMina)throw(std::logic_error)"Blokirano polje";
		Nova[x][y]=Polje::Posjeceno;
		y++;
		
	}
	if(Smjer==Smjerovi::DoljeDesno)
	{
		if(x==Nova.size()-1 || y==Nova.size()-1)throw(std::out_of_range)"Izlazak van igrace table";
		if(Nova[x+1][y+1]==Polje::BlokiranoPrazno || Nova[x+1][y+1]==Polje::BlokiranoPosjeceno || Nova[x+1][y+1]==Polje::BlokiranoMina)throw(std::logic_error)"Blokirano polje";
	    Nova[x][y]=Polje::Posjeceno;
		x++;
		y++;
		
	}
	if(Smjer==Smjerovi::Dolje)
	{
		if(x==Nova.size()-1)throw(std::out_of_range)"Izlazak van igrace table";
		if(Nova[x+1][y]==Polje::BlokiranoPrazno || Nova[x+1][y]==Polje::BlokiranoPosjeceno || Nova[x+1][y]==Polje::BlokiranoMina)throw(std::logic_error)"Blokirano polje";
		Nova[x][y]=Polje::Posjeceno;
		x++;
		
	}
	if(Smjer==Smjerovi::DoljeLijevo)
	{
		if(x==Nova.size()-1 || y==0)throw(std::out_of_range)"Izlazak van igrace table";
		if(Nova[x+1][y-1]==Polje::BlokiranoPrazno || Nova[x+1][y-1]==Polje::BlokiranoPosjeceno || Nova[x+1][y-1]==Polje::BlokiranoMina)throw(std::logic_error)"Blokirano polje";
		Nova[x][y]=Polje::Posjeceno;
		x++;
		y--;
		
	}
	if(Smjer==Smjerovi::Lijevo)
	{
		if(y==0)throw(std::out_of_range)"Izlazak van igrace table";
		if(Nova[x][y-1]==Polje::BlokiranoPrazno || Nova[x][y-1]==Polje::BlokiranoPosjeceno || Nova[x][y-1]==Polje::BlokiranoMina)throw(std::logic_error)"Blokirano polje";
		Nova[x][y]=Polje::Posjeceno;
		y--;
		
	}
	
	
	
	if(Nova[x][y]==Polje::Mina)
	{
		for(int i=0; i<Nova.size(); i++)
		{
			for(int j=0; j<Nova.size(); j++)
			{
				Nova[i][j]=Polje::Prazno;
					
			}
			
		}
		
		return Status::KrajPoraz;
	}
	
	for(int i=0; i<Nova.size(); i++)
	{
		for(int j=0; j<Nova.size(); j++)
		{
			if(Nova[i][j]==Polje::Prazno && Nova[i][j]!=Polje::Mina) return Status::NijeKraj;
		}
	}
	
	return Status::KrajPobjeda;
}

Status Idi(Tabla Nova, int &x, int &y, int x1, int y1)
{
	if(x1>=Nova.size() || y1>=Nova.size())throw(std::out_of_range)"Izlazak van igrace table";
		if(Nova[x1][y1]==Polje::BlokiranoPrazno || Nova[x1][y1]==Polje::BlokiranoPosjeceno || Nova[x1][y1]==Polje::BlokiranoMina)throw(std::logic_error)"Blokirano polje";
	else 
	{
	    Nova[x][y]=Polje::Posjeceno;
		x=x1;
	    y=y1;
	}
	
	if(Nova[x][y]==Polje::Mina)
	{
		for(int i=0; i<Nova.size(); i++)
		{
			for(int j=0; j<Nova.size(); j++)
			{
				Nova[i][j]=Polje::Prazno;
					
			}
			
		}
		
		return Status::KrajPoraz;
	}
	
	
	for(int i=0; i<Nova.size(); i++)
	{
		for(int j=0; j<Nova.size(); j++)
		{
			if(Nova[i][j]==Polje::Prazno && Nova[i][j]!=Polje::Mina) return Status::NijeKraj;
		}
	}
	
	return Status::KrajPobjeda;
}



int main ()
{
	
	
	std::cout << "Unesite komandu: ";
	Komande komanda;
	Smjerovi smjer = Smjerovi::GoreDesno;
	int x=0, y=0;
	Tabla tabla;
	KodoviGresaka greska = KodoviGresaka::SuvisanParametar;
	
	UnosKomande(komanda, smjer, x, y, greska);
	if(komanda==Komande::KreirajIgru){
		int n;
		std::cin >> n;
		Tabla tabla (n, std::vector<Polje>(n));
		
		std::cout << "Unesite pozicije mina: ";
		std::vector<std::vector<int>> mine;
	/*	while(1)
		{
			int i(0), j(0);
			mine.resize(i+1);
			mine[i].resize(2);
			int x;
			std::pair <int,int> par;
			std::cin >> x >> y;
			if(x == '.' || y=='.')break;
			par=std::make_pair(x, y);
			mine[i][0]=x;mine[i][1]=y;
			
			i++;
		}
		*/
		
	}

	
	IzvrsiKomandu(komanda, tabla, x, y);
	
	return 0;
}
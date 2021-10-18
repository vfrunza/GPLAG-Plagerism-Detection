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
#include <cmath>
#include <string>


using namespace std;

enum class Polje {
 Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};

typedef std::vector<std::vector<Polje>> Tabla;


Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine)
{   
	if(n<=0) throw domain_error("Ilegalna velicina");
	Tabla t(n,vector<Polje>(n));
	
	
	for(int i=0;i<mine.size();i++)
		if(mine[i].size()!=2) throw domain_error("Ilegalan format zadavanja mina");
	
	for(int i=0;i<mine.size();i++)
		for(int j=0;j<mine[i].size();j++)
			if(mine[i][j]>n || mine[i][j]<0) throw domain_error("Ilegalne pozicije mina");
	
	for(int i=0;i<mine.size();i++)
	{
		t[mine[i][0]][mine[i][1]]=(Polje)2;
	}
	
	return t;
}


int SaberiSusjede(const Tabla &polja,int x,int y)
{   
	int suma=0;
	
	if(x>0 && x<polja.size()-1 && y>0 && y<polja[0].size()-1)
	{    
	
	      for(int i=x-1;i<=x+1;i++)
	      	for(int j=y-1;j<=y+1;j++)
	      		if(i==x && j==y) continue;
	      		else if((int)polja[i][j]==2) 
	      			suma++;
	      	
	}
	else if(x==0)
	{
		if(y==0)
		{
			for(int i=0;i<=x+1;i++)
				for(int j=0;j<=y+1;j++)
					if(i==x && j==y) continue;
	      			else if((int)polja[i][j]==2) 
	      					suma++;
		}	
		else if (y==polja[0].size()-1)
		{
			for(int i=0;i<=x+1;i++)
				for(int j=polja[0].size()-1;j>=polja[0].size()-2;j--)
					if(i==x && j==y) continue;
	      			else if((int)polja[i][j]==2) 
	      					suma++;
		}
		else if(y>0 && y<polja[0].size()-1)
		{
			for(int i=0;i<=x+1;i++)
				for(int j=0;j<=y+1;j++)
					if(i==x && j==y) continue;
	      			else if((int)polja[i][j]==2) 
	      					suma++;
		}
		
	}
	else if(x==polja.size()-1)
	{
		if(y==0)
		{
			for(int i=polja.size()-1;i>=polja.size()-2;i--)
				for(int j=0;j<=y+1;j++)
					if(i==x && j==y) continue;
	      			else if((int)polja[i][j]==2) 
	      					suma++;
		}	
		else if (y==polja[0].size()-1)
		{
			for(int i=polja.size()-1;i>=polja.size()-2;i--)
				for(int j=polja[0].size()-1;j>=polja[0].size()-2;j--)
					if(i==x && j==y) continue;
	      			else if((int)polja[i][j]==2) 
	      					suma++;
		}
		else if(y>0 && y<polja[0].size()-1)
		{
			for(int i=polja.size()-1;i>=polja.size()-2;i--)
				for(int j=0;j<=y+1;j++)
					if(i==x && j==y) continue;
	      			else if((int)polja[i][j]==2) 
	      					suma++;
		}
	}
	else if(y==0)
	{
		if(x>0 && x<polja.size()-1)
		{
		    for(int i=x-1;i<=x+1;i++)
		    {
		    	for(int j=y;j<=y+1;j++)
		    			if(i==x && j==y) continue;
	      				else if((int)polja[i][j]==2) 
	      					suma++;
		    }
		}
	}
	else if(y==polja[0].size()-1)
	{
		if(x>0 && x<polja.size()-1)
		{
			for(int i=x-1;i<=x+1;i++)
			{
				for(int j=y;j>=y-1;j--)
					if(i==x && j==y) continue;
	      			else if((int)polja[i][j]==2) 
	      					suma++;
			}
		}
	}
	
	
	return suma;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y)
{   
	if(x<0 || y<0 || x>polja.size()-1 || y>polja[0].size()-1){string s;s="Polje (";s.push_back(x+'0');s.push_back(',');s.push_back(y+'0');s+=") ne postoji"; throw domain_error(s);}//dodaj x,y u izuzetak!!!!
	vector<vector<int>> o(3,vector<int>(3));
	
	for(int i=x-1;i<=x+1;i++)
	{
		for(int j=y-1;j<=y+1;j++)
		{
			if(i>=0 && j>=0 && i<polja.size() && j<polja[0].size())
				o[fabs(x-i-1)][fabs(y-j-1)]=SaberiSusjede(polja,i,j);
			
		}
	}
	return o;

}

void BlokirajPolje(Tabla &polja, int x, int y)
{
	if(x<0 || y<0 || x>polja.size()-1 || y>polja[0].size()-1){string s;s="Polje (";s.push_back(x+'0');s.push_back(',');s.push_back(y+'0');s+=") ne postoji"; throw domain_error(s);}//dodaj x,y u izuzetak!!!!	
	 
	if((int)polja[x][y]<=3)
		polja[x][y]=(Polje)((int)polja[x][y]+3);
	
	
}

void DeblokirajPolje(Tabla &polja, int x, int y)
{
	if(x<0 || y<0 || x>polja.size()-1 || y>polja[0].size()-1){string s;s="Polje (";s.push_back(x+'0');s.push_back(',');s.push_back(y+'0');s+=") ne postoji"; throw domain_error(s);}//dodaj x,y u izuzetak!!!!
	
	if((int)polja[x][y]>=3 && (int)polja[x][y]<6)
		polja[x][y]=(Polje)((int)polja[x][y]-3);
	
}

enum class Smjerovi {
 GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};

enum class Status {
 NijeKraj, KrajPoraz, KrajPobjeda
};


Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer)
{   	
	
	
		//if(x-1<0 || y-1<0 || x+1>polja.size()-1 || y+1>polja.size()-1) throw out_of_range("Izlazak van igrace table");//Postavi izuzetak prekoracenja x,y
		switch((int)smjer)
		{
			case 0:
			if(x-1<0 || y-1<0)  throw out_of_range("Izlazak van igrace table");
			if((int)polja[x-1][y-1]>=3) throw logic_error("Blokirano polje");
			polja[x][y]=(Polje)1;
			x=x-1;y=y-1;
			if((int)polja[x][y]==2) return Status::KrajPoraz;
			
			break;
			
			case 1:
			if(x-1<0)  throw out_of_range("Izlazak van igrace table");
			if((int)polja[x-1][y]>=3) throw logic_error("Blokirano polje");
			polja[x][y]=(Polje)1;
			x=x-1;
			if((int)polja[x][y]==2) return Status::KrajPoraz;
			
			break;
			
			case 2:
			if(x-1<0 || y+1>polja.size()-1)  throw out_of_range("Izlazak van igrace table");
			if((int)polja[x-1][y+1]>=3) throw logic_error("Blokirano polje");
			polja[x][y]=(Polje)1;
			x=x-1;y=y+1;
			if((int)polja[x][y]==2) return Status::KrajPoraz;
	    	break;
			
			case 3:
			if(y+1>polja.size()-1)  throw out_of_range("Izlazak van igrace table");
			if((int)polja[x][y+1]>=3) throw logic_error("Blokirano polje");
			polja[x][y]=(Polje)1;
			y=y+1;
			if((int)polja[x][y]==2) return Status::KrajPoraz;
			break;
			
			case 4:
			if(x+1>polja.size()-1 || y+1>polja.size()-1)  throw out_of_range("Izlazak van igrace table");
			if((int)polja[x+1][y+1]>=3) throw logic_error("Blokirano polje");
			polja[x][y]=(Polje)1;
			x=x+1;y=y+1;
			if((int)polja[x][y]==2) return Status::KrajPoraz;
			break;
			
			case 5:
			if(x+1>polja.size()-1)  throw out_of_range("Izlazak van igrace table");
			if((int)polja[x+1][y]>=3) throw logic_error("Blokirano polje");
			polja[x][y]=(Polje)1;
			x=x+1;
			if((int)polja[x][y]==2) return Status::KrajPoraz;
			break;
			
			case 6:
			if(x+1>polja.size()-1 || y-1<0)  throw out_of_range("Izlazak van igrace table");
			if((int)polja[x+1][y-1]>=3) throw logic_error("Blokirano polje");
			polja[x][y]=(Polje)1;
			x=x+1;y=y-1;
			if((int)polja[x][y]==2) return Status::KrajPoraz;
			break;
			
			case 7:
			if(y-1<0)  throw out_of_range("Izlazak van igrace table");
			if((int)polja[x][y-1]>=3) throw logic_error("Blokirano polje");
			polja[x][y]=(Polje)1;
			y=y-1;
			if((int)polja[x][y]==2) return Status::KrajPoraz;
			break;
			
		}

		
		return Status::NijeKraj;
}


Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y)
{
	if(novi_y<0 || novi_y>polja.size()-1 || novi_x<0 || novi_x>polja.size()-1) throw out_of_range("Izlazak van igrace table");
	if((int)polja[x][y]>3) throw logic_error("Blokirano polje");
	
	if(polja[x][y]==Polje::Mina) return Status::KrajPoraz;	
	x=novi_x;y=novi_y;
	
	if((int)polja[x][y]<2) //polja[x][y]=Polje::BlokiranoPosjeceno;
	  polja[x][y]=(Polje)1;
	
	return Status::NijeKraj;
}

enum class KodoviGresaka {
 PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};

void PrijaviGresku(KodoviGresaka greska)
{
	switch((int)greska)
	{
		case 0:
			cout<<"Nerazumljiva komanda!"<<endl;
			break;
		case 1:
			cout<<"Komanda trazi parametar koji nije naveden!"<<endl;
			break;
		case 2:
			cout<<"Parametar komande nije ispravan!"<<endl;
			break;
		case 3:
			cout<<"Zadan je suvisan parametar nakon komande!"<<endl;
			break;
	}
}

enum class Komande {
 PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu,
 ZavrsiIgru, KreirajIgru
};

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska)
{	
	string c;
	
	cin>>c;
	

		if(c[0]=='P')
		{
			if(c[1]=='1')
			{   
				komanda=Komande::PomjeriJednoMjesto;
				return true;
				
			}
			else if(c[1]=='>')
			{	
				komanda=Komande::PomjeriDalje;
				cin>>x>>y;
				return true;
			}
			else if(c[1]=='O')
			{
				komanda=Komande::PrikaziOkolinu;
				return true;
			}
			
		}
		else if(c[0]=='B')
		{  
			komanda=Komande::Blokiraj;
			cin>>x>>y;
			return true;
		}
		else if(c[0]=='D')
		{
			komanda=Komande::Deblokiraj;
			cin>>x>>y;
			return true;
		}
		else if(c[0]=='Z')
		{
			komanda=Komande::ZavrsiIgru;
			return true;
		}
		else if(c[0]=='K')
		{  
			komanda=Komande::KreirajIgru;
			return true;
		}		
		else
		{
			   	greska=(KodoviGresaka)0;
				 return false;	
		}
	
	return false;
	
}



void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0)
{
	switch((int)komanda)
	{
		case 0:
			Idi(polja,x,y,p_smjer);
			break;
		case 1:
		//	cout<<x<<" "<<y<<" "<<p_x<<" "<<p_y;
			Idi(polja,x,y,p_x,p_y);//cout<<(int)polja[x][y];
			if((int)polja[x][y]==2) cout<<"Mina"<<endl;
			else if((int)polja[x][y]>2 && (int)polja[x][y]<7) cout<<"Blokirano polje"<<endl;
			else cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<endl;
			break;
		case 2:
			BlokirajPolje(polja,x,y);
			//cout<<(int)polja[x][y];
			break;
		case 3:
			DeblokirajPolje(polja,x,y);
			break;
		case 4:
			PrikaziOkolinu(polja,x,y);
			break;
		case 5:
			//ZavrsiIgru
			break;
		case 6:
			cout<<"Unesite broj polja: ";
			int n;
			cin>>n;
			cout<<"Unesite pozicije mina: ";
			vector<vector<int>> mine;
			for(;;)
			{
				string s;
				cin>>s;vector<int> v;
				
				if(s.size()==1 && s[0]=='.')break;
				
				for(int i=0;i<s.size();i++)
				{	
					if(s[i]=='(' || s[i]==',')
					{
						i++;int broj=0;
						while(s[i]>='0' && s[i]<='9')
						{
							 broj=broj*10+(s[i]-'0');
							 i++;
						}
						v.push_back(broj);
					}
					if(s[i]==',')i--;
				}
				
				mine.push_back(v);
			}
			
			polja=KreirajIgru(n,mine);
			break;
	}
}


void ispisiTablu(std::vector<std::vector<Polje>> polja){
   for(int i = 0; i < polja.size(); i++) {
          for(int j = 0; j < polja[i].size(); j++) std::cout << int(polja[i][j]) << " ";
          std::cout << std::endl;
        }
}

int main ()
{	
	/*
	Komande komanda;
		Smjerovi smjer;
		int x=0,y=0;Tabla polja;
		KodoviGresaka greska;
		
	for(;;)
	{   
	
		cout<<"Unesite komandu: ";
		if(UnosKomande(komanda,smjer,x,y,greska))
		{	if((int)komanda==5){ cout<<"Dovidjenja!"; return 0;}
			IzvrsiKomandu(komanda,polja,x,y,smjer,x,y);
		}
		
	}*/
	
  int x = 0, y = 0;
 std::vector<std::vector<Polje>> tabla;
  IzvrsiKomandu(Komande::KreirajIgru, tabla, x, y);
  ispisiTablu(tabla);
  IzvrsiKomandu(Komande::KreirajIgru, tabla, x, y);
  ispisiTablu(tabla);
  IzvrsiKomandu(Komande::KreirajIgru, tabla, x, y);

    
	return 0;
}
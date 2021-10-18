/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
bool broj(char a)
{
	if(a>='1' && a<='9')
	return true;
	return false;
}
void izbaci_razmake(std::string &s)
{
	for(int i=0;i<s.size();i++)
	if(s[i]==' ')
	{s.erase(s.begin()+i);
		i--;
	}
	
}
enum class Polje { Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina};
typedef std::vector<std::vector<Polje>> Tabla;

enum class Smjerovi{ GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};

enum class Status {
 NijeKraj, KrajPoraz, KrajPobjeda
};

int pomocna_za_pregled_polja(const Tabla &polje,int x,int y)
{
	int vrati=0;
	
		if(x>0 && y>0)
		{
			if(polje[x-1][y-1]==Polje(2))
			vrati++;
		}
		if(x>0)
		{
			if(polje[x-1][y]==Polje(2))
			vrati++;
		}
		
		if(x>0 && y+1<polje.size())
		{
			if(polje[x-1][y+1]==Polje(2))
			vrati++;
		}
		if (y>0)
		{
			if(polje[x][y-1]==Polje(2))
			vrati++;
		}
		
	
		
		if(y+1<polje.size())
		{
			if(polje[x][y+1]==Polje(2))
			vrati++;
		}
		if(x+1<polje.size())
		{
			if(y>0)
			if(polje[x+1][y-1]==Polje(2))
			vrati++;
			if(polje[x+1][y]==Polje(2))
			vrati++;
			if(y+1<polje.size())
			if(polje[x+1][y+1]==Polje(2))
			vrati++;
		}
	return vrati;
}
Tabla KreirajIgru (int n,const std::vector<std::vector<int>> &mine)
{
	for(int i=0;i<mine.size();i++)
	{
		if(mine[i].size()!=2)
		throw std::domain_error("Ilegalan format zadavanja mina");
	}
	
	for(int i=0;i<mine.size();i++)
	{
		for(int j=0;j<mine[i].size();j++)
		{
			if(mine[i][j]>n)
			throw std::domain_error("Ilegalne pozicije mina");
		}
	}
	
	Tabla vrati;
	vrati.resize(n);
	
	for(int i=0;i<n;i++)
	{
		vrati[i].resize(n);
	}
	
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	{
		vrati[i][j]=Polje(0);
	}
	
	for(int i=0;i<mine.size();i++)
	{
		vrati[mine[i][0]][mine[i][1]]=Polje(2);
	}
	return vrati;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja,int x,int y)
{
	std::string izuzetak="Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji";
	if(x>=polja.size() || y>=polja.size() || x<0 || y<0)
	throw std::domain_error(izuzetak);
	
	std::vector<std::vector<int>> vrati;
	vrati.resize(3);
	for(int i=0;i<3;i++)
	vrati[i].resize(3);
	
	
	if(x>0)
	{
		if(y>0)
		vrati[0][0]=pomocna_za_pregled_polja(polja,x-1,y-1);
		vrati[0][1]=pomocna_za_pregled_polja(polja,x-1,y);
		if(y+1<polja.size())
		vrati[0][2]=pomocna_za_pregled_polja(polja,x-1,y+1);
		
	}
	if(y>0)
	vrati[1][0]=pomocna_za_pregled_polja(polja,x,y-1);
	vrati[1][1]=pomocna_za_pregled_polja(polja,x,y);
	if(y+1<polja.size())
	vrati[1][2]=pomocna_za_pregled_polja(polja,x,y+1);
	
	if(x+1<polja.size())
	{
		if(y>0)
		vrati[2][0]=pomocna_za_pregled_polja(polja,x+1,y-1);
		vrati[2][1]=pomocna_za_pregled_polja(polja,x+1,y);
		if(y+1<polja.size())
		vrati[2][2]=pomocna_za_pregled_polja(polja,x+1,y+1);
	}
	
	return vrati;
	
	
	
}

void BlokirajPolje(Tabla &polje,int x,int y)
{
	std::string izuzetak="Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji";
	if(x>=polje.size() || y>=polje.size())
	throw std::domain_error(izuzetak);
	
	if(polje[x][y]==Polje(0))
	polje[x][y]=Polje(3);
	
	if(polje[x][y]==Polje(1))
	polje[x][y]=Polje(4);
	
	if(polje[x][y]==Polje(2))
	polje[x][y]=Polje(5);
	
}


void DeblokirajPolje(Tabla &polje,int x,int y)
{
	std::string izuzetak="Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji";
	if(x>=polje.size() || y>=polje.size() || x<0 || y<0)
	throw std::domain_error(izuzetak);
	
	if(polje[x][y]==Polje(3))
	polje[x][y]=Polje(0);
	
	if(polje[x][y]==Polje(4))
	polje[x][y]=Polje(1);
	
	if(polje[x][y]==Polje(5))
	polje[x][y]=Polje(2);

}

Status Idi (Tabla &polja,int &x,int &y,Smjerovi smjerovi)
{
	int tempx=x;
	int tempy=y;
	if(smjerovi==Smjerovi(0))
	{
		x=x-1;
		y=y-1;
	}
	if(smjerovi==Smjerovi(1))
	x=x-1;
	if(smjerovi==Smjerovi(2))
	{
		x=x-1;
		y=y+1;
	}
	if(smjerovi==Smjerovi(3))
	y=y+1;
	if(smjerovi==Smjerovi(4))
	{
		x=x+1;
		y=y+1;
	}
	if(smjerovi==Smjerovi(5))
	{
		x=x+1;
	}
	if(smjerovi==Smjerovi(6))
	{
		x=x+1;
		y=y-1;
	}
	if(smjerovi==Smjerovi(7))
	y=y-1;
	
	
		if(x<0 || y<0 || x>=polja.size() || y>=polja.size())
	{	x=tempx;
		y=tempy;
		throw std::out_of_range("Izlazak van igrace table");
	}
	
	if(polja[x][y]==Polje(3) || polja[x][y]==Polje(4) || polja[x][y]==Polje(5))
	
	{
		x=tempx;
		y=tempy;
		throw std::logic_error("Blokirano polje");
	}
	polja[tempx][tempy]=Polje(1);
	if(polja[x][y]==Polje(2))
	{
		return Status(1);
	}
	for(int i=0;i<polja.size();i++)
	for(int j=0;j<polja.size();j++)
	{
		if(polja[i][j]==Polje(0))
		return Status(1);
		
	}

	return Status(0);
}

Status Idi (Tabla &polja,int &x,int &y,int novi_x,int novi_y)
{
	
	int tempx=x;
	int tempy=y;
	x=novi_x;
	y=novi_y;
	
	if(x<0 || y<0 || x>=polja.size() || y>=polja.size())
	{
		x=tempx;
		y=tempy;
		throw std::out_of_range("Izlazak van igrace table");
	}
	if(polja[x][y]==Polje(3) || polja[x][y]==Polje(4) || polja[x][y]==Polje(5))
	{
		x=tempx;
		y=tempy;
		throw std::logic_error("Blokirano polje");
	}
	polja[tempx][tempy]=Polje(1);
	if(polja[x][y]==Polje(2))
	{
		return Status(1);
	}
	for(int i=0;i<polja.size();i++)
	for(int j=0;j<polja.size();j++)
	{
		if(polja[i][j]==Polje(0))
		return Status(1);
		
	}

	return Status(0);
	
	
	
}
enum class KodoviGresaka {
 PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};

void PrijaviGresku (KodoviGresaka ulaz)
{
	
	if(ulaz==KodoviGresaka(0))
	std::cout<<"Nerazumljiva komanda!\n";
	if(ulaz==KodoviGresaka(1))
	std::cout<<"Komanda trazi parametar koji nije naveden!\n";
	if(ulaz==KodoviGresaka(2))
	std::cout<<"Parametar komande nije ispravan!\n";
	if(ulaz==KodoviGresaka(3))
	std::cout<<"Zadan je suvisan parametar nakon komande!\n";

	
	
}

enum class Komande {
 PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu,
 ZavrsiIgru, KreirajIgru
};


bool UnosKomande(Komande &komanda,Smjerovi &smjerovi,int &x,int &y,KodoviGresaka &greska)
{
	
	char znak1;
	int tempx;
	int tempy;
	std::cin>>znak1;
	if(znak1=='P')
	{
		
		std::cin>>znak1;
		if(znak1=='1')
		{
			std::string temp;
			std::getline(std::cin,temp);
			if((temp[0]!=' ' && temp[0]!='G' && temp[0]!='D' && temp[0]!='L') || temp.size()==0 )
			{
				greska=KodoviGresaka(1);
				return false;
			}
			
			izbaci_razmake(temp);
			
			if(temp=="GL")
			{
				komanda=Komande(0);
				smjerovi=Smjerovi(0);				
				
		//		x=x-1;
		//		y=y-1;
				return true;
			}
			if(temp=="G")
			{	
		//		x=x-1;
				komanda=Komande(0);
				smjerovi=Smjerovi(1);
				return true;
			}
			if(temp=="GD")
			{
			//	x=x-1;
			//	y=y+1;
				komanda=Komande(0);
				smjerovi=Smjerovi(2);
				return true;
			}
			if(temp=="D")
			{
			//	y=y+1;
				komanda=Komande(0);
				smjerovi=Smjerovi(3);
				return true;
			}
			if(temp=="DOD")
			{
		//		x=x+1;
		//		y=y+1;
				komanda=Komande(0);
				smjerovi=Smjerovi(4);
				return true;
			}
			if(temp=="DO")
			{
		//		x=x+1;
				komanda=Komande(0);
				smjerovi=Smjerovi(5);
				return true;
			}
			if(temp=="DOL")
			{
		//		x=x+1;
		//		y=y+1;
				komanda=Komande(0);
				smjerovi=Smjerovi(6);
				return true;
			}
			if(temp=="L")
			{
		//		y=y-1;
				komanda=Komande(0);
				smjerovi=Smjerovi(7);
				return true;
			}
			else
			{
				greska=KodoviGresaka(2);
				return false;
			}
			
		}
		if(znak1=='>')
		{
			
			
			std::cin>>tempx;
			int brojneki=std::cin.peek();
			if(brojneki!=10)
			{greska=KodoviGresaka(2);
			
				return false;
			}
			std::cin>>tempy;
			 brojneki=std::cin.peek();
				if(brojneki!=10)
			{
				greska=KodoviGresaka(0);
			
				return false;
			}
			x=tempx;
			y=tempy;
			komanda=Komande(1);
			return true;
		}
		
		
		if(znak1=='O')
		{
			
			if(std::cin.peek()!=10 || std::cin.peek()!=' ')
			{
				komanda=Komande(4);
				return true;
			}
			else {
				greska=KodoviGresaka(2);
				return false;
			}
		}

	}
	if(znak1=='B')
	{
		
		if(std::cin.peek()==10 || std::cin.peek()==' ')
		{
			std::cin>>tempx;
			std::cin>>tempy;
		x=tempx;
		y=tempy;
		komanda=Komande(2);
		return true;
		}
		else {
			greska=KodoviGresaka(1);
			return false;
		}
		
	}
	if(znak1=='D')
	{
		 
		std::cin>>tempx;
		std::cin>>tempy;
		if(std::cin.peek()==10 || std::cin.peek()==' ')
		{
		x=tempx;
		y=tempy;
		komanda=Komande(3);
			return true;
		}
		else{
			greska=KodoviGresaka(2);
			return false;
		}
	}
	
	if(znak1=='Z')
	{
		std::string temp;
		std::getline(std::cin,temp);
		izbaci_razmake(temp);
		if(temp.size()!=0)
		{
			greska=KodoviGresaka(2);
			return false;
		}
		komanda=Komande(5);
		return true;
	}
	if(znak1=='K')
	{
		std::string temp;
		std::getline(std::cin,temp);
		izbaci_razmake(temp);
		if(temp.size()!=0)
		{
			greska=KodoviGresaka(2);
			return false;
		}
		komanda=Komande(6);
		return true;
	}
	else{
	greska=KodoviGresaka(0);
	return false;
	}
	return false;

}

void IzvrsiKomadnu(Komande komanda,Tabla &polja,int &x,int &y,Smjerovi p_smjerovi=Smjerovi::Gore,int p_x=0,int p_y=0)
{
	

	/*	KodoviGresaka greska;
		std::cout<<"Unesite komandu:";
	auto	temp=UnosKomade(komanda,p_smjerovi,x,y,greska);
		while (komanda!=Komande(5)) {
			
			if(temp!=true)
			{
				std::cout<<"\nGreska unesite ponovo!";
			}
			else{
				if(komanda==Komande(4))
				{
					auto m=PrikaziOkolinu(polja,p_x,p_y);
					for(int i=0;i<m.size();i++)
					{
						for(int j=0;j<m[i].size();j++)
						std::cout<<m[i][j]<<" ";
						std::cout<<"\n";
					}
					
				}
				if(komanda==Komande(2))
				{
					BlokirajPolje(polja,x,y);
				}
				if(komanda==Komande(1))
				{
					Idi(polja,x,y,p_x,p_y);
				}
				if(komanda==Komande(0))
				{
					Idi(polja,x,y,p_smjerovi);
					
				}
				if(komanda==Komande(3))
				{
					DeblokirajPolje(polja,x,y);
				}
				
			}
			
			temp=UnosKomade(komanda,p_smjerovi,x,y,greska);
			
			
		}
		
		
		bool temp=true;
		KodoviGresaka greska;
		temp=UnosKomande(komanda,p_smjerovi,x,y,greska);
		while (komanda!=Komande(5)) {
			std::cout<<"Unesite komadnu: ";
			
		
		while (temp==false) {
			PrijaviGresku(greska);
			temp=UnosKomande(komanda,p_smjerovi,x,y,greska);
		}
		if(komanda==Komande(0))
		Idi(polja,x,y,x,y);
		if(komanda==Komande(2))
		BlokirajPolje(polja,x,y);
		if(komanda==Komande(3))
		DeblokirajPolje(polja,x,y);
		if(komanda==Komande(4))
		PrikaziOkolinu(polja,x,y);
		
		}
		*/
		KodoviGresaka greska;
		auto temp=UnosKomande(komanda,p_smjerovi,p_x,p_y,greska);
		if(temp==false)
		{
			PrijaviGresku(greska);
		}
		else{
			int prosa=0;
			Status status;
			if(komanda==Komande(0))
			{
				 status=Idi(polja,x,y,p_smjerovi);
				 prosa++;
			}
			if(komanda==Komande(1))
			{
				 status=Idi(polja,x,y,p_x,p_y);
				prosa++;
			}
			if(komanda==Komande(5))
			{
				for(int i=0;i<polja.size();i++)
				for(int j=0;j<polja[i].size();j++)
				{
					polja[i][j]=Polje(0);
				}
				throw std::runtime_error("Igra zavrsena");
			}
			if(prosa!=0)
			{
				if(status==Status(1))
				{
					std::cout<<"Nagazili ste na minu";
				    for(int i=0;i<polja.size();i++)
				    {
				    	for(int j=0;j<polja[i].size();j++)
				    	{
				    		polja[i][j]=Polje(0);
				    	}
				    }
					throw std::runtime_error("Igra zavrsena");
				}
				
				
			if(status==Status(2))
			{
				std::cout<<"Bravo,obisli ste sva sigurna polja";
				for(int i=0;i<polja.size();i++)
				for(int j=0;j<polja[i].size();j++)
				{
					polja[i][j]=Polje(0);
				}
				throw std::runtime_error("Igra zavrsena");
			}
			
			
			}
			if(prosa==0)
			{
				if(komanda==Komande(2))
				BlokirajPolje(polja,x,y);
				if(komanda==Komande(3))
				DeblokirajPolje(polja,x,y);
				if(komanda==Komande(4))
				PrikaziOkolinu(polja,x,y);
			
			}
			
		}
		
}



int main ()
{

}
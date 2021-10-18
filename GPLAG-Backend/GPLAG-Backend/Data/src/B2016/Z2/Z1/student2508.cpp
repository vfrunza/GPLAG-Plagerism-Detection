/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/

#include<iostream>
#include<vector>
#include<stdexcept>
#include<string>
enum class Polje
{
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};

typedef std::vector<std::vector <Polje>> Tabla;

enum class Smjerovi
{
	GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};

enum class Status
{
	NijeKraj, KrajPoraz, KrajPobjeda
};

enum class KodoviGresaka
{
	PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};

enum class Komande
{
	PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};

void PrijaviGresku(KodoviGresaka greska)
{
	switch(greska)
	{
		case KodoviGresaka::PogresnaKomanda:
			std::cout<<"Nerazumljiva komanda!"<<std::endl;
			break;
		case KodoviGresaka::NedostajeParametar:
			std::cout<<"Komanda trazi parametar koji nije naveden!"<<std::endl;
			break;
		case KodoviGresaka::NeispravanParametar:
			std::cout<<"Parametar komande nije ispravan!"<<std::endl;
			break;
		case KodoviGresaka::SuvisanParametar:
			std::cout<<"Zadan je suvisan parametar nakon komande!"<<std::endl;
			break;
	}
}

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine)
{
	Tabla t(n,std::vector<Polje> (n,Polje::Prazno));
	for(int i(0);i<mine.size();i++)
	{
		
		if(mine[i].size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
		if(mine[i][0]>=n || mine[i][1]>=n || mine[i][0]<0 || mine[i][1]<0) throw std::domain_error("Ilegalne pozicije mina");
		t[mine[i][0]][mine[i][1]]=Polje::Mina;
	}
	return t;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x,int y)
{
	if(x>polja.size() || x<0 || y>=polja[0].size() || y<0)
	{
		std::string s1(std::to_string(x));
		std::string s2(std::to_string(y));
		throw std::domain_error("Polje ("+s1+","+s2+") ne postoji");
	}
	
	std::vector<std::vector<int>> okolina(3,std::vector<int>(3,0));
	int red(0);
	for(int i(x-1);i<=x+1;i++)
	{
		if(i<0 || i>=polja.size()){red++; continue;}
		int kolona(0);
		for(int j(y-1);j<=y+1;j++)
		{
			
			int brojac(0);
			
			if(j<0 || j>=polja[i].size()){kolona++; continue;}
			for(int k(i-1);k<=i+1;k++)
			{
				if(k<0 || k>=polja.size()) continue;
				for(int l(j-1);l<=j+1;l++)
				{
					if(l<0 || l>=polja[i].size()) continue;
					if(polja[k][l]==Polje::Mina && !(l==j && k==i) )
						brojac++;
				}
			}
			okolina[red][kolona]=brojac;
			kolona++;
		}
		red++;
	}
	return okolina;
}

void BlokirajPolje(Tabla &polja, int x, int y)
{
	if(x>=polja.size() || x<0 || y>=polja[0].size() || y<0)
	{
		std::string s1(std::to_string(x));
		std::string s2(std::to_string(y));
		throw std::domain_error("Polje ("+s1+","+s2+") ne postoji");
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
	if(x>=polja.size() || x<0 || y>=polja[0].size() || y<0)
	{
		std::string s1(std::to_string(x));
		std::string s2(std::to_string(y));
		throw std::domain_error("Polje ("+s1+","+s2+") ne postoji");
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
	switch(smjer)
	{
		case Smjerovi::GoreLijevo:
			if(x-1<0 || y-1<0)
				throw std::out_of_range("Izlazak van igrace table");
			if(polja[x-1][y-1]==Polje::BlokiranoPosjeceno || polja[x-1][y-1]==Polje::BlokiranoPrazno || polja[x-1][y-1]==Polje::BlokiranoMina)
				throw std::logic_error("Blokirano polje");
			polja[x][y]=Polje::Posjeceno;
			x=x-1; y=y-1;	
			break;
		case Smjerovi::Gore:
			if(x-1<0)
				throw std::out_of_range("Izlazak van igrace table");
			if(polja[x-1][y]==Polje::BlokiranoPosjeceno || polja[x-1][y]==Polje::BlokiranoPrazno || polja[x-1][y]==Polje::BlokiranoMina)
				throw std::logic_error("Blokirano polje");
			polja[x][y]=Polje::Posjeceno;
			x=x-1;
			break;
		case Smjerovi::GoreDesno:
			if(x-1<0 || y+1>=polja.size())
				throw std::out_of_range("Izlazak van igrace table");
			if(polja[x-1][y+1]==Polje::BlokiranoPosjeceno || polja[x-1][y+1]==Polje::BlokiranoPrazno || polja[x-1][y+1]==Polje::BlokiranoMina)
				throw std::logic_error("Blokirano polje");
			polja[x][y]=Polje::Posjeceno;
			x=x-1; y=y+1;
			break;
		case Smjerovi::Desno:
			if(y+1>=polja.size())
				throw std::logic_error("Izlazak van igrace tabele");
			if(polja[x][y+1]==Polje::BlokiranoPosjeceno || polja[x][y+1]==Polje::BlokiranoPrazno || polja[x][y+1]==Polje::BlokiranoMina)
				throw std::logic_error("Blokirano polje");
			polja[x][y]=Polje::Posjeceno;
			y=y+1;
			break;
		case Smjerovi::DoljeDesno:
			if(x+1>polja.size() || y+1>polja.size())
				throw std::out_of_range("Izlazak van igrace table");
			if(polja[x+1][y+1]==Polje::BlokiranoPosjeceno || polja[x+1][y+1]==Polje::BlokiranoPrazno || polja[x+1][y+1]==Polje::BlokiranoMina)
				throw std::logic_error("Blokirano polje");
			polja[x][y]=Polje::Posjeceno;
			x=x+1; y=y+1;
			break;
		case Smjerovi::DoljeLijevo:
			if(y-1<0 || x+1>=polja.size())
				throw std::out_of_range("Izlazak van igrace table");
			if(polja[x+1][y-1]==Polje::BlokiranoPosjeceno || polja[x+1][y-1]==Polje::BlokiranoPrazno || polja[x+1][y-1]==Polje::BlokiranoMina)
				throw std::logic_error("Blokirano polje");
			polja[x][y]=Polje::Posjeceno;
			x=x+1; y=y-1;
			break;
		case Smjerovi::Lijevo:
			if(y-1<0)
				throw std::out_of_range("Izlazak van igrace table");
			if(polja[x][y-1]==Polje::BlokiranoPosjeceno || polja[x][y-1]==Polje::BlokiranoPrazno || polja[x][y-1]==Polje::BlokiranoMina)
				throw std::logic_error("Blokirano polje");
			polja[x][y]=Polje::Posjeceno;
			y=y-1;
			break;
		case Smjerovi::Dolje:
			if(x+1>=polja.size())
				throw std::out_of_range("Izlazak van igrace table");
			if(polja[x+1][y]==Polje::BlokiranoPosjeceno || polja[x+1][y]==Polje::BlokiranoPrazno || polja[x+1][y]==Polje::BlokiranoMina)
				throw std::logic_error("Blokirano polje");
			polja[x][y]=Polje::Posjeceno;
			x=x+1;
			break;
	}
	if(polja[x][y]==Polje::Mina)
	{
		for(int i(0);i<polja.size();i++)
		{
			for(int j(0);j<polja.size();j++)
			{
				polja[i][j]=Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
	else
	{
		int praznih(0);
		for(int i(0);i<polja.size();i++)
		{
			for(int j(0);j<polja.size();j++)
			{
				if(polja[i][j]==Polje::Prazno && !(i==x && j==y))
					praznih++;
			}
		}
		if(praznih==0)
			return Status::KrajPobjeda;
	}
	
	return Status::NijeKraj;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y)
{
	if(novi_x>=polja.size() || novi_x<0 || novi_y>=polja.size() || novi_y<0)
		throw std::out_of_range("Izlazak van igrace table");
	if(polja[novi_x][novi_y]==Polje::BlokiranoPosjeceno || polja[novi_x][novi_y]==Polje::BlokiranoPrazno || polja[novi_x][novi_y]==Polje::BlokiranoMina)
		throw std::logic_error("Blokirano polje");
	polja[x][y]=Polje::Posjeceno;
	x=novi_x; y=novi_y;
	if(polja[x][y]==Polje::Mina)
	{
		for(int i(0);i<polja.size();i++)
		{
			for(int j(0);j<polja.size();j++)
			{
				polja[i][j]=Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
	else
	{
		int praznih(0);
		for(int i(0);i<polja.size();i++)
		{
			for(int j(0);j<polja.size();j++)
			{
				if(polja[i][j]==Polje::Prazno && !(i==x && j==y))
					praznih++;
			}
		}
		if(praznih==0)
			return Status::KrajPobjeda;
	}
	
	return Status::NijeKraj;
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska)
{
	std::string s;
	std::getline(std::cin,s);
	for(int i(0);i<s.length();i++)
	{
		if(s[i]==' ') 
		{
			s.erase(s.begin()+i);
			i--;
		}
	}
		if(s.length()==0)
		{
			greska=KodoviGresaka::PogresnaKomanda;
			return false;
		}
		if(s.length()==1  && s[0]=='Z')
		{
			komanda=Komande::ZavrsiIgru;
			return true;
		}
		if(s.length()==1 && s[0]=='K')
		{
			komanda=Komande::KreirajIgru;
			return true;
		}
		if(s=="P" || s=="P>" || s=="B" || s=="D" || s=="P1")
		{
			greska=KodoviGresaka::NedostajeParametar;
			return false;
		}
		if(s.length()>1 && s[0]=='Z')
		{
			greska=KodoviGresaka::SuvisanParametar;
			return false;
		}
		if(s.length()>1 && s[0]=='K')
		{
			greska=KodoviGresaka::SuvisanParametar;
			return false;
		}
		if(s[0]!='P' && s[0]!='B' && s[0]!='D')
		{
			greska=KodoviGresaka::PogresnaKomanda;
			return false;
		}
		
		if(s[0]=='P')
		{
			if(s.length()>1 && s[1]=='1')
			{
				if(s.length()==2)
				{
					greska=KodoviGresaka::NeispravanParametar;
					return false;
				}
				if(s.length()==3)
				{
					if(s[2]!='G' && s[2]!='D' && s[2]!='L')
					{
						greska=KodoviGresaka::NeispravanParametar;
						return false;
					}
					if(s[2]=='G')
					{
						smjer=Smjerovi::Gore;
						komanda=Komande::PomjeriJednoMjesto;
						return true;
					}
					if(s[2]=='D')
					{
						smjer=Smjerovi::Desno;
						komanda=Komande::PomjeriJednoMjesto;
						return true;
					}
					if(s[2]=='L')
					{
						smjer=Smjerovi::Lijevo;
						komanda=Komande::PomjeriJednoMjesto;
						return true;
					}
				}
				if(s.length()==4)
				{
					if(s[2]!='D' && s[2]!='L' && s[2]!='G')
					{
						greska=KodoviGresaka::NeispravanParametar;
						return false;
					}
					if(s[3]!='L' && s[3]!='D' && s[3]!='o')
					{
						greska=KodoviGresaka::NeispravanParametar;
						return false;
					}
					if(s[2]=='G')
					{
						if(s[3]=='D')
						{
							smjer=Smjerovi::GoreDesno;
							komanda=Komande::PomjeriJednoMjesto;
							return true;
						}
						if(s[3]=='L')
						{
							smjer=Smjerovi::GoreLijevo;
							komanda=Komande::PomjeriJednoMjesto;
							return true;
						}
					}
					if(s[2]=='D')
					{
						if(s[3]=='o')
						{
							smjer=Smjerovi::Dolje;
							return true;
						}
					}
				}
				if(s.length()==5)
				{
					if(s[2]!='D' || s[3]!='o')
					{
						greska=KodoviGresaka::NeispravanParametar;
						return false;
					}
					else
					{
						if(s[4]=='L')
						{
							smjer=Smjerovi::DoljeLijevo;
							komanda=Komande::PomjeriJednoMjesto;
							return true;
						}
						else
						if(s[4]=='D')
						{
							smjer=Smjerovi::DoljeDesno;
							komanda=Komande::PomjeriJednoMjesto;
							return true;
						}
						else
						{
							greska=KodoviGresaka::SuvisanParametar;
							return false;
						}
					}
				}
			}
			else if(s.length()>1 && s[1]=='>')
			{
				if(s.length()==3)
				{
					greska=KodoviGresaka::NedostajeParametar;
					return false;
				}
				else
				if(s.length()>=4)
				{
					if(!(s[2]>='0' && s[2]<='9') || !(s[3]>='0' && s[3]<='9'))
					{
						greska=KodoviGresaka::NeispravanParametar;
						return false;
					}
					else
					{
						if(s.length()>4)
						{
							greska=KodoviGresaka::SuvisanParametar;
							return false;
						}
						else
						{
							x=s[2]-'0';
							y=s[3]-'0';
							komanda=Komande::PomjeriDalje;
							return true;
						}
					}
				}
			}
			else if(s.length()>1 && s[1]=='O')
			{
				if(s.length()>2)
				{
					greska=KodoviGresaka::SuvisanParametar;
					return false;
				}
				if(s.length()==2)
				{
					komanda=Komande::PrikaziOkolinu;
					return true;
				}
			}
		}
		if(s[0]=='B')
		{
				if(s.length()==2)
				{
					greska=KodoviGresaka::NedostajeParametar;
					return false;
				}
				else
				if(s.length()>=3)
				{
					if(!(s[1]>='0' && s[1]<='9') || !(s[2]>='0' && s[2]<='9'))
					{
						greska=KodoviGresaka::NeispravanParametar;
						return false;
					}
					else
					{
						if(s.length()>3)
						{
							greska=KodoviGresaka::SuvisanParametar;
							return false;
						}
						else
						{
							x=s[1]-'0';
							y=s[2]-'0';
							komanda=Komande::Blokiraj;
							return true;
						}
					}
				}
			
		}
		if(s[0]=='D')
		{
				if(s.length()==2)
				{
					greska=KodoviGresaka::NedostajeParametar;
					return false;
				}
				else
				if(s.length()>=3)
				{
					if(!(s[1]>='0' && s[1]<='9') || !(s[2]>='0' && s[2]<='9'))
					{
						greska=KodoviGresaka::NeispravanParametar;
						return false;
					}
					else
					{
						if(s.length()>3)
						{
							greska=KodoviGresaka::SuvisanParametar;
							return false;
						}
						else
						{
							x=s[1]-'0';
							y=s[2]-'0';
							komanda=Komande::Deblokiraj;
							return true;
						}
					}
				}
			
		}
		return false;
	}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer=Smjerovi::Gore, int p_x=0, int p_y=0)
{
	if(komanda==Komande::PomjeriJednoMjesto)
	{
			Status stanje(Idi(polja,x,y,p_smjer));
			if(stanje==Status::KrajPoraz)
			{
				std::cout<<"Nagazili ste na minu"<<std::endl;
				throw std::runtime_error("Igra zavrsena");
			}
			else if(stanje==Status::KrajPobjeda)
			{
				std::cout<<"Bravo, obisli ste sva sigurna polja"<<std::endl;
				throw std::runtime_error("Igra zavrsena");
			}
			else
			{
				std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
			}
	}
	else if(komanda==Komande::PomjeriDalje)
	{
		Status state(Idi(polja,p_x,p_y,x,y));
			if(state==Status::KrajPoraz)
			{
				std::cout<<"Nagazili ste na minu"<<std::endl;
				throw std::runtime_error("Igra zavrsena");
			}
			else if(state==Status::KrajPobjeda)
			{
				std::cout<<"Bravo, obisli ste sva sigurna polja"<<std::endl;
				throw std::runtime_error("Igra zavrsena");
			}
			else
			{
				std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
			}
	}
	else if(komanda==Komande::Blokiraj)
	{
			BlokirajPolje(polja,x,y);
	}
	else if (komanda==Komande::Deblokiraj)
			DeblokirajPolje(polja,x,y);
	else if(komanda==Komande::PrikaziOkolinu)
	{
			std::vector<std::vector<int>> mat(PrikaziOkolinu(polja,x,y));
			for(int i(0);i<3;i++)
			{
				for(int j(0);j<3;j++)
				{
					std::cout<<mat[i][j]<<" ";
				}
				std::cout<<std::endl;
			}
	}
	else if(komanda== Komande::ZavrsiIgru)
	{
			for(int i(0);i<polja.size();i++)
			{
				for(int j(0);j<polja.size();j++)
				{
					polja[i][j]=Polje::Prazno;
				}
			}
			throw std::runtime_error("Igra zavrsena");
	}
	else if(komanda== Komande::KreirajIgru)
	{
			std::cout<<"Unesite broj polja: ";
			int n;
			std::cin>>n;
			std::cin.ignore(10000,'\n');
			std::cout<<"Unesite pozicije mina: ";
			std::vector<std::vector<int>> mine;
			int i(0);
			for(;;)
			{
				std::string s;
				std::getline(std::cin,s);
				for(int i(0); i<s.length();i++)
				{
					if(s[i]=='\n' || s[i]==' ')
						s.erase(s.begin()+i);
				}
				if(s==".")
					break;
				/*if(s.length()!=5)
				{
					std::cout<<"Greska, unesite ponovo!"<<std::endl;
					continue;
				}*/
				if(s[0]!='(' || !(s[1]>='0' && s[1]<='9') || s[2]!=',' || !(s[3]>='0' && s[3]<='9') || s[4]!=')')
				{
					std::cout<<"Greska, unesite ponovo!"<<std::endl;
					continue;
				}
				if(s[1]-'0'>=n || s[3]-'0'>=n || (s[1]-'0'==0 && s[3]-'0'==0))
				{
					std::cout<<"Greska, unesite ponovo!"<<std::endl;
					continue;
				}
				mine.push_back(std::vector<int>());
				mine[i].push_back(s[1]-'0');
				mine[i].push_back(s[3]-'0');
				i++;
			}
			polja=KreirajIgru(n,mine);
	}
			
}

int main ()
{
try
{
	Tabla t; int x(0),y(0),pomx(0),pomy(0); 
	for(;;)
	{
		try
		{
			Smjerovi smjer; KodoviGresaka greska; Komande kom;
			std::cout<<"Unesite komandu: ";
			if(UnosKomande(kom,smjer,x,y,greska))
			{
				IzvrsiKomandu(kom,t,x,y,smjer,pomx,pomy);
			}
			else
			{
				PrijaviGresku(greska);
			}
		}
		catch(std::logic_error izuzetak)
		{
			std::cout<<izuzetak.what()<<std::endl;
		}
		catch(std::out_of_range izuzetak)
		{
			std::cout<<izuzetak.what()<<std::endl;
		}
		catch(std::domain_error izuzetak)
		{
			std::cout<<izuzetak.what()<<std::endl;
		}
		
	}
}
	catch(std::runtime_error izuzetak)
	{
			
	}
	std::cout<<"Dovidjenja!";
	
		return 0;
}
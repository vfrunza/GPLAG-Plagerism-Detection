/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <cstring>
using std::cout;
using std::cin;
using std::vector;
using std::string;
enum class Polje { Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina };
enum class Smjerovi { GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo };
enum class Status { NijeKraj, KrajPoraz, KrajPobjeda};
enum class KodoviGresaka { PogresnaKomanda, NedostajeParametar , SuvisanParametar, NeispravanParametar};
enum class Komande { PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru };
typedef vector<vector<Polje>> Tabla;
Tabla KreirajIgru(int n,const std::vector<std::vector<int>> &mine)
{
Tabla polja(n,vector<Polje>(n,Polje::Prazno));
	for(int i=0;i<mine.size();i++)
	{
		if(mine[i].size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
	}
	for(int i=0;i<mine.size();i++)
	{
		for(int j=0;j<mine[i].size();j++)
		if(mine[i][j]>=n || mine[i][j]<0) throw std::domain_error("Ilegalne pozicije mina");
	}
	for(int i=0;i<mine.size();i++)
	{
	 polja[mine[i][0]][mine[i][1]]=Polje::Mina;
	}
	return polja;
}
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y)
{
	vector<vector<int>> matrica(3,vector<int>(3,0));
	string recenica{"Polje ("};
   string recenica2{") ne postoji"};
   if(x<0)
   {
   	x*=-1;
   	recenica.push_back('-');
   }
   char znak='0'+x;
   recenica.push_back(znak);
   recenica.push_back(',');
   if(y<0)
   {
   	y*=-1;
   	recenica.push_back('-');
   }
   znak='0'+y;
   recenica.push_back(znak);
   recenica+=recenica2;
    if(x<0 || y<0 || x>=polja.size() || y>=polja[0].size()) throw std::domain_error(recenica);
    if(polja.size()==0 || polja.size()==1)
    return matrica;
    int tempi(0);
    for(int i=x-1;i<=x+1;i++)
    {
    int tempj(0);
    for(int j=y-1;j<=y+1;j++)
    {
    	if(i<0 || j<0 || i>=polja.size() || y>=polja[0].size())
    	matrica[tempi][tempj]=0;
    	int brojac(0);
    	if(i>0 && j>0 && i<(polja.size()-1) && j<(polja[0].size()-1))
    	{
    		if(polja[i-1][j-1]==Polje::Mina)
    		brojac++;
    		if(polja[i-1][j]==Polje::Mina)
    		brojac++;
    		if(polja[i-1][j+1]==Polje::Mina)
    		brojac++;
    		if(polja[i][j-1]==Polje::Mina)
    		brojac++;
    		if(polja[i][j+1]==Polje::Mina)
    		brojac++;
    		if(polja[i+1][j-1]==Polje::Mina)
    		brojac++;
    		if(polja[i+1][j]==Polje::Mina)
    		brojac++;
    		if(polja[i+1][j+1]==Polje::Mina)
    		brojac++;
    		matrica[tempi][tempj]=brojac;
    	}
    	if(i==0 && j>0 && i<(polja.size()-1) && j<(polja[0].size()-1))
    	{
    		if(polja[i][j-1]==Polje::Mina)
    		brojac++;
    		if(polja[i][j+1]==Polje::Mina)
    		brojac++;
    		if(polja[i+1][j-1]==Polje::Mina)
    		brojac++;
    		if(polja[i+1][j]==Polje::Mina)
    		brojac++;
    		if(polja[i+1][j+1]==Polje::Mina)
    		brojac++;
    		matrica[tempi][tempj]=brojac;	
    	}
    	if(i>0 && j==0 && i<(polja.size()-1) && j<(polja[0].size()-1))
    	{
    		if(polja[i-1][j]==Polje::Mina)
    		brojac++;
    		if(polja[i-1][j+1]==Polje::Mina)
    		brojac++;
    		if(polja[i][j+1]==Polje::Mina)
    		brojac++;
    		if(polja[i+1][j]==Polje::Mina)
    		brojac++;
    		if(polja[i+1][j+1]==Polje::Mina)
    		brojac++;
    		matrica[tempi][tempj]=brojac;	
    	}
    	if(i==(polja.size()-1) && j>0 && i>0 && j<(polja[0].size()-1))
    	{
    		if(polja[i-1][j]==Polje::Mina)
    		brojac++;
    		if(polja[i][j-1]==Polje::Mina)
    		brojac++;
    		if(polja[i][j+1]==Polje::Mina)
    		brojac++;
    		if(polja[i-1][j-1]==Polje::Mina)
    		brojac++;
    		if(polja[i-1][j+1]==Polje::Mina)
    		brojac++;
    		matrica[tempi][tempj]=brojac;	
    	}
    	if(i<(polja.size()-1) && j>0 && i>0 && j==(polja[0].size()-1))
    	{
    		if(polja[i-1][j]==Polje::Mina)
    		brojac++;
    		if(polja[i+1][j]==Polje::Mina)
    		brojac++;
    		if(polja[i][j-1]==Polje::Mina)
    		brojac++;
    		if(polja[i-1][j-1]==Polje::Mina)
    		brojac++;
    		if(polja[i+1][j-11]==Polje::Mina)
    		brojac++;
    		matrica[tempi][tempj]=brojac;	
    	}
    	if(i==0 && j==0)
    	{
    		if(polja[i][j+1]==Polje::Mina)
    		brojac++;
    		if(polja[i+1][j]==Polje::Mina)
    		brojac++;
    		if(polja[i+1][j+1]==Polje::Mina)
    		brojac++;
    		matrica[tempi][tempj]=brojac;	
    	}
    	if(i==0 && j==(polja[0].size()-1))
    	{
    		if(polja[i][j-1]==Polje::Mina)
    		brojac++;
    		if(polja[i+1][j]==Polje::Mina)
    		brojac++;
    		if(polja[i+1][j-1]==Polje::Mina)
    		brojac++;
    		matrica[tempi][tempj]=brojac;
    	}
    	if(i==(polja.size()-1) && j==0)
    	{
    		if(polja[i][j+1]==Polje::Mina)
    		brojac++;
    		if(polja[i-1][j]==Polje::Mina)
    		brojac++;
    		if(polja[i-1][j+1]==Polje::Mina)
    		brojac++;
    		matrica[tempi][tempj]=brojac;
    	}
    	if(i==(polja.size()-1) && j==(polja[0].size()-1))
    	{
    		if(polja[i][j-1]==Polje::Mina)
    		brojac++;
    		if(polja[i-1][j]==Polje::Mina)
    		brojac++;
    		if(polja[i-1][j-1]==Polje::Mina)
    		brojac++;
    		matrica[tempi][tempj]=brojac;
    	}
    	tempj++;
    }
    tempi++;
    }
    return matrica;
}
void BlokirajPolje(Tabla &polja, int x, int y)
{
//cout<<polja.size()<<" "<<x<<" "<<y;
string recenica{"Polje ("};
string recenica2{") ne postoji"};
if(x<0)
{
	x*=-1;
	recenica.push_back('-');
}
char znak='0'+x;
recenica.push_back(znak);
recenica.push_back(',');
if(y<0)
{
	y*=-1;
	recenica.push_back('-');
}
znak='0'+y;
recenica.push_back(znak);
recenica+=recenica2;
if(x<0 || y<0 || x>=polja.size() || y>=polja.size()) throw std::domain_error(recenica);
if(polja[x][y]==Polje::Prazno)
polja[x][y]=Polje::BlokiranoPrazno;
if(polja[x][y]==Polje::Mina)
polja[x][y]=Polje::BlokiranoMina;
if(polja[x][y]==Polje::Posjeceno)
polja[x][y]=Polje::BlokiranoPosjeceno;
}
void DeblokirajPolje(Tabla &polja, int x, int y)
{
//cout<<polja.size()<<" "<<x<<" "<<y;
string recenica{"Polje ("};
string recenica2{") ne postoji"};
if(x<0)
{
	x*=-1;
	recenica.push_back('-');
}
char znak='0'+x;
recenica.push_back(znak);
recenica.push_back(',');
if(y<0)
{
	y*=-1;
	recenica.push_back('-');
}
znak='0'+y;
recenica.push_back(znak);
recenica+=recenica2;
if(x<0 || y<0 || x>=polja.size() || y>=polja.size()) throw std::domain_error(recenica);
if(polja[x][y]==Polje::BlokiranoPrazno)
polja[x][y]=Polje::Prazno;
if(polja[x][y]==Polje::BlokiranoMina)
polja[x][y]=Polje::Mina;
if(polja[x][y]==Polje::BlokiranoPosjeceno)
polja[x][y]=Polje::Posjeceno;	
}
Status Idi(Tabla &polje, int &x, int &y, Smjerovi smjer)
{
if(polje.size()==0)
throw std::out_of_range("Izlazak van igrace table");
polje[x][y]=Polje::Posjeceno; //khm
	if(smjer==Smjerovi::GoreLijevo)
	{
		if(x<1 || y<1)
		throw std::out_of_range("Izlazak van igrace table");
		if(polje[x-1][y-1]==Polje::BlokiranoPosjeceno || polje[x-1][y-1]==Polje::BlokiranoPrazno || polje[x-1][y-1]==Polje::BlokiranoMina)
		throw std::logic_error("Blokirano polje");
		x=x-1;
		y=y-1;
	}
	if(smjer==Smjerovi::Gore)
	{
		if(x<1)
		throw std::out_of_range("Izlazak van igrace table");
		if(polje[x-1][y]==Polje::BlokiranoPosjeceno || polje[x-1][y]==Polje::BlokiranoPrazno || polje[x-1][y]==Polje::BlokiranoMina)
		throw std::logic_error("Blokirano polje");
		x=x-1;
	}
	if(smjer==Smjerovi::GoreDesno)
	{
		if(x<1 || y>=(polje.size()-1))
		throw std::out_of_range("Izlazak van igrace table");
		if(polje[x-1][y+1]==Polje::BlokiranoPosjeceno || polje[x-1][y+1]==Polje::BlokiranoPrazno || polje[x-1][y+1]==Polje::BlokiranoMina)
		throw std::logic_error("Blokirano polje");
		x=x-1;
		y=y+1;
	}
	if(smjer==Smjerovi::Desno)
	{
		if(y>=(polje.size()-1))
		throw std::out_of_range("Izlazak van igrace table");
		if(polje[x][y+1]==Polje::BlokiranoPosjeceno || polje[x][y+1]==Polje::BlokiranoPrazno || polje[x][y+1]==Polje::BlokiranoMina)
		throw std::logic_error("Blokirano polje");
		y=y+1;
	}
	if(smjer==Smjerovi::DoljeDesno)
	{
		if(x>=(polje.size()-1) || y>=(polje.size()-1))
		throw std::out_of_range("Izlazak van igrace table");
		if(polje[x+1][y+1]==Polje::BlokiranoPosjeceno || polje[x+1][y+1]==Polje::BlokiranoPrazno || polje[x+1][y+1]==Polje::BlokiranoMina)
		throw std::logic_error("Blokirano polje");
		x=x+1;
		y=y+1;
	}
	if(smjer==Smjerovi::Dolje)
	{
		if(x>=(polje.size()-1))
		throw std::out_of_range("Izlazak van igrace table");
		if(polje[x+1][y]==Polje::BlokiranoPosjeceno || polje[x+1][y]==Polje::BlokiranoPrazno || polje[x+1][y]==Polje::BlokiranoMina)
		throw std::logic_error("Blokirano polje");
		x=x+1;
	}
	if(smjer==Smjerovi::DoljeLijevo)
	{
		if(x>=(polje.size()-1) || y<1)
		throw std::out_of_range("Izlazak van igrace table");
		if(polje[x+1][y-1]==Polje::BlokiranoPosjeceno || polje[x+1][y-1]==Polje::BlokiranoPrazno || polje[x+1][y-1]==Polje::BlokiranoMina)
		throw std::logic_error("Blokirano polje");
		x=x+1;
		y=y-1;	
	}
	if(smjer==Smjerovi::Lijevo)
	{
		if(y<1)
		throw std::out_of_range("Izlazak van igrace table");
		if(polje[x][y-1]==Polje::BlokiranoPosjeceno || polje[x][y-1]==Polje::BlokiranoPrazno || polje[x][y-1]==Polje::BlokiranoMina)
		throw std::logic_error("Blokirano polje");
		y=y-1;
	}
	if(polje[x][y]==Polje::Mina)
	{
		for(int i=0;i<polje.size();i++)
		{
			for(int j=0;j<polje[0].size();j++)
			polje[i][j]=Polje::Prazno;
		}
		return Status::KrajPoraz;
	}
	for(int i=0;i<polje.size();i++)
	{
		for(int j=0;j<polje[0].size();j++)
		{
			if(polje[i][j]!=Polje::Prazno)
			return Status::NijeKraj;
		}
	}
	return Status::KrajPobjeda;
}
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y)
{
		//cout<<polja.size()<<" "<<x<<" "<<y<<" "<<novi_x<<" "<<novi_y;
		if(novi_x<0 || novi_x>(polja.size()-1) || novi_y<0 || novi_y>(polja.size()-1) || polja.size()==0)
		throw std::out_of_range("Izlazak van igrace table");
		if(polja[novi_x][novi_y]==Polje::BlokiranoPosjeceno || polja[novi_x][novi_y]==Polje::BlokiranoPrazno || polja[novi_x][novi_y]==Polje::BlokiranoMina)
		throw std::logic_error("Blokirano polje");
		polja[x][y]=Polje::Posjeceno; //khm
		x=novi_x;
		y=novi_y;
		if(polja[x][y]==Polje::Mina)
	{
		for(int i=0;i<polja.size();i++)
		{
			for(int j=0;j<polja[0].size();j++)
			polja[i][j]=Polje::Prazno;
		}
		return Status::KrajPoraz;
	}
	for(int i=0;i<polja.size();i++)
	{
		for(int j=0;j<polja[0].size();j++)
		{
			if(polja[i][j]!=Polje::Prazno)
			return Status::NijeKraj;
		}
	}
	return Status::KrajPobjeda;
}
void PrijaviGresku(KodoviGresaka kod)
{
	if(kod==KodoviGresaka::PogresnaKomanda)
	cout<<"Nerazumljiva komanda!"<<std::endl;
	if(kod==KodoviGresaka::NedostajeParametar)
	cout<<"Komanda trazi parametar koji nije naveden!"<<std::endl;
	if(kod==KodoviGresaka::NeispravanParametar)
	cout<<"Parametar komande nije ispravan!"<<std::endl;
	if(kod==KodoviGresaka::SuvisanParametar)
	cout<<"Zadan je suvisan parametar nakon komande!"<<std::endl;
}
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska)
{
vector<string> svekom{"P1","P>","B","D","PO","Z","K"};
vector<string> svismj{"GL","G","GD","D","DoD","Do","DoL","L"};
string kom;
std::getline(cin,kom);
int i=0;
if(kom.size()>0)
while(kom[i]==' ' && i<kom.size())
{
	i++;
}
string kom1;
int brojac(0);
while(kom[i]!=' ' && i<kom.size())
{
	kom1.push_back(kom[i]);
	if(kom[i]!='P')
	break;
	i++;
	if(brojac==1)
	break;
    brojac++;
}
int k(-1);
for(int j=0;j<svekom.size();j++)
{
	if(kom1==svekom[j])
	{
		k=j;
		break;
	}
}
if(k==-1)
{
greska=KodoviGresaka::PogresnaKomanda;
return false;
}
i++;
while(kom[i]==' ' && i<kom.size())
i++;
if(k==4 || k==5 || k==6)
{
	if(i!=kom.size())
	{
		greska=KodoviGresaka::SuvisanParametar;
		return false;
	}
	else
	{
		if(k==4)
		{
			komanda=Komande::PrikaziOkolinu;
			return true;
		}
		if(k==5)
		{
			komanda=Komande::ZavrsiIgru;
			return true;
		}
		if(k==6)
		{
			komanda=Komande::KreirajIgru;
			return true;
		}
	}
}
if(k==0 || k==1 || k==2 || k==3)
{
	if(i==kom.size())
	{
		greska=KodoviGresaka::NedostajeParametar;
		return false;
	}
}
string kom2;
int m(-1);
if(k==0)
{
while(i<kom.size() && kom[i]!=' ')	
{
	kom2.push_back(kom[i]);
	i++;
}
for(int l=0;l<svismj.size();l++)
{
	if(kom2==svismj[l])
	{
		m=l;
		break;
	}
}
}
while(i<kom.size() && kom[i]==' ')
i++;
if(k==0 && (m==-1 || i!=kom.size()))
{
	greska=KodoviGresaka::NeispravanParametar;
	return false;
}
if(m==0)
{
	komanda=Komande::PomjeriJednoMjesto;
	smjer=Smjerovi::GoreLijevo;
	return true;
}
if(m==1)
{
	komanda=Komande::PomjeriJednoMjesto;
	smjer=Smjerovi::Gore;
	return true;
}
if(m==2)
{
	komanda=Komande::PomjeriJednoMjesto;
	smjer=Smjerovi::GoreDesno;
	return true;
}
if(m==3)
{
    komanda=Komande::PomjeriJednoMjesto;
	smjer=Smjerovi::Desno;	
	return true;
}
if(m==4)
{
	komanda=Komande::PomjeriJednoMjesto;
	smjer=Smjerovi::DoljeDesno;
	return true;
}
if(m==5)
{
	komanda=Komande::PomjeriJednoMjesto;
	smjer=Smjerovi::Dolje;
	return true;
}
if(m==6)
{
	komanda=Komande::PomjeriJednoMjesto;
	smjer=Smjerovi::DoljeLijevo;
	return true;
}
if(m==7)
{
	komanda=Komande::PomjeriJednoMjesto;
	smjer=Smjerovi::Lijevo;
	return true;
}
if(k==1 || k==2 || k==3)
{
	if(i==kom.size())
	{
		greska=KodoviGresaka::NedostajeParametar;
		return false;
	}
	if(kom[i]<'0' || kom[i]>'9')
	{
		greska=KodoviGresaka::NeispravanParametar;
		return false;
	}
	else
	{
		int pom1=0;
		while(kom[i]>='0' && kom[i]<='9' && i<kom.size())
		{
			if(pom1!=0)
			pom1*=10;
			pom1+=int(kom[i]-'0');
		    i++;
		}
		while(kom[i]==' ' && i<kom.size())
		i++;
	if(i==kom.size())
	  {
		greska=KodoviGresaka::NedostajeParametar;
		return false;
	  }
	 if(kom[i]<'0' || kom[i]>'9')
	 {
	 	greska=KodoviGresaka::NeispravanParametar;
		return false;
	 }
	 	int pom2=0;
		while(kom[i]>='0' && kom[i]<='9' && i<kom.size())
		{
			if(pom2!=0)
			pom2*=10;
			pom2+=int(kom[i]-'0');
		    i++;
		}
	    if(i<kom.size())
	    {
	    	while(kom[i]==' ' && i<kom.size())
	    	i++;
	    	if(i!=kom.size())
	    	{
	    		greska=KodoviGresaka::NeispravanParametar; //
	    		return false;
	    	}
	    }
		if(k==1)
		{
			komanda=Komande::PomjeriDalje;
			x=pom1;
		    y=pom2;
			return true;
		}
		if(k==2)
		{
			komanda=Komande::Blokiraj;
			x=pom1;
		    y=pom2;
			return true;
		}
		if(k==3)
		{
			komanda=Komande::Deblokiraj;
			x=pom1;
		    y=pom2;
			return true;
		}
	}
}
return false;
}
void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0)
{
	if(komanda==Komande::PomjeriJednoMjesto)
	{
		try
		{
			Status stat1=Idi(polja,p_x,p_y,p_smjer);
			x=p_x;
			y=p_y;
			cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
			if(stat1==Status::KrajPobjeda)
			{
			cout<<"Bravo, obisli ste sva sigurna polja"<<std::endl;
			for(int i=0;i<polja.size();i++)
			{
				for(int j=0;j<polja.size();j++)
				polja[i][j]=Polje::Prazno;
			}
			}
			if(stat1==Status::KrajPoraz)
			{
			cout<<"Nagazili ste na minu"<<std::endl;
			for(int i=0;i<polja.size();i++)
			{
				for(int j=0;j<polja.size();j++)
				polja[i][j]=Polje::Prazno;
			}
			}
		}
		catch(std::out_of_range izuzetak)
		{
			cout<<izuzetak.what()<<std::endl;
		}
		catch(std::logic_error izuzetak2)
		{
			cout<<izuzetak2.what()<<std::endl;
		}
	}
	if(komanda==Komande::PomjeriDalje)
	{
		try
		{
			Status stat2=Idi(polja,p_x,p_y,x,y);
			cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
			if(stat2==Status::KrajPobjeda)
			{
			cout<<"Bravo, obisli ste sva sigurna polja"<<std::endl;
			for(int i=0;i<polja.size();i++)
			{
				for(int j=0;j<polja.size();j++)
				polja[i][j]=Polje::Prazno;
			}
			throw std::runtime_error("Igra zavrsena");
			}
			if(stat2==Status::KrajPoraz)
			{
			cout<<"Nagazili ste na minu"<<std::endl;
			for(int i=0;i<polja.size();i++)
			{
				for(int j=0;j<polja.size();j++)
				polja[i][j]=Polje::Prazno;
			}
			throw std::runtime_error("Igra zavrsena");
			}
		}
		catch(std::out_of_range izuzetak)
		{
			cout<<izuzetak.what()<<std::endl;
		}
		catch(std::logic_error izuzetak2)
		{
			cout<<izuzetak2.what()<<std::endl;
		}
	}
	if(komanda==Komande::Blokiraj)
	{
		try
		{
			BlokirajPolje(polja,x,y);
		}
		catch(std::domain_error izuzetak)
		{
			cout<<izuzetak.what()<<std::endl;
		}
	}
	if(komanda==Komande::Deblokiraj)
	{
		try
		{
		    DeblokirajPolje(polja,x,y);
		}
		catch(std::domain_error izuzetak2)
		{
			cout<<izuzetak2.what()<<std::endl;
		}
	}
	if(komanda==Komande::PrikaziOkolinu)
	{
		try
		{
			std::vector<std::vector<int>> mat=PrikaziOkolinu(polja,x,y);
			for(int i=0;i<mat.size();i++)
			{
				for(int j=0;j<mat.size();j++)
				{
				cout<<mat[i][j]<<" ";
				}
				cout<<std::endl;
			}
		}
		catch(std::domain_error izuzetak)
		{
			cout<<izuzetak.what()<<std::endl;
		}
	}
	if(komanda==Komande::ZavrsiIgru)
	{
		for(int i=0;i<polja.size();i++)
		for(int j=0;j<polja.size();j++)
		polja[i][j]=Polje::Prazno;
		throw std::runtime_error("Igra zavrsena");
	}
	if(komanda==Komande::KreirajIgru)
	{
		try
		{
			cout<<"Unesite broj polja: ";
			int n;
			cin>>n;
			vector<vector<int>> mat1;
			string mine;
			cout<<"Unesite pozicije mina: ";
			vector<int> vek(2);
			cin.clear();
			cin.ignore(1000,'\n');
			while(true)
			{
				std::getline(cin,mine);
				if(mine.size()==1 && mine[0]=='.')
				break;
				if((mine.size()>0 && mine[0]!='(') || mine.size()==0)
                {
                	cout<<"Greska, unesite ponovo!"<<std::endl;
                	continue;
                }
                if(mine.size()>1 && (mine[1]<'0' || mine[1]>'9'))
                {
                	cout<<"Greska, unesite ponovo!"<<std::endl;
                	continue;
                }
                if(mine.size()<5)
                {
                	cout<<"Greska, unesite ponovo!"<<std::endl;
                	continue;
                }
                int i(1);
                int pom1(0);
                while(mine[i]>='0' && mine[i]<='9' && i<mine.size())
                {
                	if(pom1!=0)
                	pom1*=10;
                	pom1+=int(mine[i]-'0');
                	i++;
                }
                if(i==mine.size())
                {
                	cout<<"Greska, unesite ponovo!"<<std::endl;
                	continue;
                }
                if(mine[i]!=',')
                {
                	cout<<"Greska, unesite ponovo!"<<std::endl;
                	continue;
                }
                i++;
                if(i==mine.size())
                {
                	cout<<"Greska, unesite ponovo!"<<std::endl;
                	continue;
                }
                if(mine[i]<'0' || mine[i]>'9')
                {
                	cout<<"Greska, unesite ponovo!"<<std::endl;
                	continue;
                }
                int pom2(0);
                while(mine[i]>='0' && mine[i]<='9' && i<mine.size())
                {
                   if(pom2!=0)
                	pom2*=10;
                	pom2+=int(mine[i]-'0');
                	i++;	
                }
                if(i==mine.size())
                {
                	cout<<"Greska, unesite ponovo!"<<std::endl;
                	continue;
                }
                if(mine[i]!=')')
                {
                	cout<<"Greska, unesite ponovo!"<<std::endl;
                	continue;
                }
                if(pom1==0 && pom2==0)
                {
                		cout<<"Greska, unesite ponovo!"<<std::endl;
                		continue;
                }
                if (pom1<n && pom2<n && pom1>=0 && pom2>=0)
                {
				vek[0]=pom1;
				vek[1]=pom2;
				mat1.push_back(vek);
                }
                else
                {
                	cout<<"Greska, unesite ponovo!"<<std::endl;
                	continue;
                }
			}
		    polja=KreirajIgru(n,mat1);
		}
		catch(std::domain_error izuzetak)
		{
			cout<<izuzetak.what()<<std::endl;
		}
	}
}
int main ()
{
int x(0),y(0);
Komande komanda;
Smjerovi smjer; 
KodoviGresaka greska;
Tabla polja;
while(true)
try
{
cout<<"Unesite komandu: ";
bool kom=UnosKomande(komanda,smjer,x,y,greska);
if(kom)
{
IzvrsiKomandu(komanda,polja,x,y,smjer);
}
else
PrijaviGresku(greska);
}
catch(...)
{
	
	cout<<"Dovidjenja!";
	return 0;
}
return 0;
}
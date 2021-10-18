/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include<iostream>
#include<vector>
#include<iomanip>
#include<stdexcept>

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
enum class Komande {
	PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu,
	ZavrsiIgru, KreirajIgru
	};
typedef std::vector<std::vector<Polje>> Tabla;
Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine)
{
	//ovdje moze provjera ako je n manje od 0
	
	Tabla tabla;
	tabla.resize(n);
	for(int i=0;i<n;i++)
	{
		tabla[i].resize(n);
		for(int j=0;j<n;j++)
		{
			tabla[i][j]=Polje::Prazno;
		}
		
	}
	for(int i=0;i<mine.size();i++)
	{
		if(mine[i].size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
		if(mine[i][0]<0 ||mine[i][0]>=n || mine[i][1]<0 || mine[i][1]>=n) throw std::domain_error("Ilegalne pozicije mina");
		tabla[mine[i][0]][mine[i][1]]=Polje::Mina;
		
	}
}
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y)
{
	int n=polja.size();
	if(x<0 || y<0 || x>=n || y>=n) throw std::domain_error("Polje (x,y) ne postoji");
	std::vector<std::vector<int>> okolina;
	okolina.resize(3);
	for(int i=0;i<3;i++) okolina[i].resize(3);
	int x1,y1;
	for(int i=-1;i<=1;i++)
	{
		for(int j=-1;j<=1;j++)
		{
			if((x+i)<0 || (x+i)>=n || (y+j)<0 || (y+j)>=n) okolina[i+1][j+1]=0;
			else
			{
				//sad trazi za ovaj x i y broj el;
				int x1,y1;
				x1=x+i;
				y1=y+j;
				//sad broji za ovo mjesto;
				int brojac=0;
				for(int k=-1;k<=1;k++)
				{
					for(int l=-1;l<=1;l++)
					{
						if((x1+k)<0 || (x1+k)>=n || (y1+l)<0 ||(y1+l)>=n)
						{
							//nista
							brojac+=0;
						}
						else
						{
							if(polja[x1+k][y1+l]==Polje::Mina) brojac++;
						}
					}
				}
				okolina[i+1][j+1]=brojac;
			}
		}
	}
}
void BlokirajPolje(Tabla &polja, int x, int y)
{
	int n=polja.size();
	if(x<0 || y<0 || x>=n || y>=n) throw std::domain_error("Polje (x,y) ne postoji");
	if(polja[x][y]==Polje::Prazno) polja[x][y]=Polje::BlokiranoPrazno;
	if(polja[x][y]==Polje::Posjeceno) polja[x][y]=Polje::BlokiranoPosjeceno;
	if(polja[x][y]==Polje::Mina) polja[x][y]=Polje::BlokiranoMina;
}
void DeBlokirajPolje(Tabla &polja, int x, int y)
{
	int n=polja.size();
	if(x<0 || y<0 || x>=n || y>=n) throw std::domain_error("Polje (x,y) ne postoji");
	if(polja[x][y]==Polje::BlokiranoPrazno) polja[x][y]=Polje::Prazno;
	if(polja[x][y]==Polje::BlokiranoPosjeceno) polja[x][y]=Polje::Posjeceno;
	if(polja[x][y]==Polje::BlokiranoMina) polja[x][y]=Polje::Mina;
}
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer)
{
	int i=0,j=0;
	if(smjer==Smjerovi::Gore) 
	{
		i=-1;j=0;
	}
	else if(smjer==Smjerovi::GoreLijevo) 
	{
		i=-1;j=-1;
	}
	else if(smjer==Smjerovi::GoreDesno) 
	{
		i=-1;j=1;
	}
	else if(smjer==Smjerovi::Lijevo) 
	{
		i=0;j=-1;
	}
	else if(smjer==Smjerovi::Desno) 
	{
		i=0;j=1;
	}
	else if(smjer==Smjerovi::Dolje) 
	{
		i=1;j=0;
	}
	else if(smjer==Smjerovi::DoljeDesno) 
	{
		i=1;j=1;
	}
	else if(smjer==Smjerovi::DoljeLijevo) 
	{
		i=1;j=-1;
	}
	x=x+i;
	y=y+j;
	int n=polja.size();
	if(x<0 || x>=n || y<0 || y>=n) throw std::out_of_range("Izlazak van igrace table");
	if(polja[x][y]==Polje::BlokiranoPosjeceno || polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
	if(polja[x][y]==Polje::Mina)
	{
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		polja[i][j]=Polje::Prazno;
		return Status::KrajPoraz;
	}
	else if(polja[x][y]==Polje::Prazno)
	{
		int sviPosjeceni=true;
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		if(polja[i][j]==Polje::Prazno &&(x!=i && y!=j))
		 {
		 	sviPosjeceni=false;
		 	break;
		 }
		 if(sviPosjeceni)
		 {
		 	return Status::KrajPobjeda;
		 	
		 }
		 else
		 {
		 	polja[x][y]=Polje::Posjeceno;
		 	return Status::NijeKraj;
		 }
	}
	
}
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y)
{
	x=novi_x;
	y=novi_y;
	int n=polja.size();
	if(x<0 || x>=n || y<0 || y>=n) throw std::out_of_range("Izlazak van igrace table");
	if(polja[x][y]==Polje::BlokiranoPosjeceno || polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
	if(polja[x][y]==Polje::Mina)
	{
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		polja[i][j]=Polje::Prazno;
		return Status::KrajPoraz;
	}
	else if(polja[x][y]==Polje::Prazno)
	{
		int sviPosjeceni=true;
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		if(polja[i][j]==Polje::Prazno &&(x!=i && y!=j))
		 {
		 	sviPosjeceni=false;
		 	break;
		 }
		 if(sviPosjeceni)
		 {
		 	return Status::KrajPobjeda;
		 	
		 }
		 else
		 {
		 	polja[x][y]=Polje::Posjeceno;
		 	return Status::NijeKraj;
		 }
	}
}
void PrijaviGresku(KodoviGresaka greska)
{
	if(greska==KodoviGresaka::PogresnaKomanda) std::cout<<"Nerazumljiva komanda!";
	else if(greska==KodoviGresaka::NedostajeParmetar) std::cout<<"Komanda trazi parametar koji nije naveden!";
	else if(greska==KodoviGresaka::NeispravanParametar) std::cout<<"Parametar komande nije ispravan!";
	else if(greska==KodoviGresaka::SuvisanParametar) std::cout<<"Zadan je suvisan parametar nakon komande!";
}
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska)
{
	std::string unos;
	std::cin>>unos;
	Komande privremena;
	bool nijeBilaKomanda=true,pogresnaNaredba=false,bilaNaredba=false,suvisnaKomanda=false,nedostajeParametar=true;
	for(int i=0;i<unos.size();i++)
	{
		while(unos[i]==' ') {
			if(i>=unos.size()) break;
			i++;
			
		}
		if(bilaNaredba)
		{
			for(i;i<unos.size();i++)
			{
				if(unos[i]!=' '){suvisnaKomanda=true; break;}
			}
			if(suvisnaKomanda) break;
		}
		else if(i<unos.size())
		{
			if(nijeBilaKomanda)
			{
				if(unos[i]=='K') {nijeBilaKomanda=false;privremena=Komande::KreirajIgru;}
				else if(unos[i]=='Z') {nijeBilaKomanda=false;privremena=Komande::ZavrsiIgru;}
				else if(unos[i]=='D') {nijeBilaKomanda=false;privremena=Komande::Deblokiraj;}
				else if(unos[i]=='B') {nijeBilaKomanda=false;privremena=Komande::Blokiraj;}
				else
				{
					//sad provjera ovih sa 2 znaka
					if((i+1)<unos.size())
					{
						if(unos[i]=='P' && unos[i+1]=='1') {
							nijeBilaKomanda=false;
							i++;
							privremena=Komande::PomjeriJednoMjesto;}
						else if(unos[i]=='P' && unos[i+1]=='>') {
							nijeBilaKomanda=false;
							i++;
							privremena=Komande::PomjeriDalje;}
						else if(unos[i]=='P' && unos[i+1]=='O') {
							nijeBilaKomanda=false;
							i++;
							privremena=Komande::PrikaziOkolinu;}
						else
						{
							//komanda ne postoji
							pogresnaNaredba=true;
							break;
						}
					}
				}
				
			}
			else
			{
				if(privremena==Komande::PomjeriJednoMjesto)
				{
					bilaNaredba=true;
					nedostajeParametar=false;
					if(unos[i]=='G')
					{
						smjer==Smjerovi::Gore;
					}
					else if(unos[i]=='L')
					{
						smjer==Smjerovi::Lijevo;
					}
					else if(unos[i]=='Do')
					{
						smjer==Smjerovi::Dolje;
					}
					else if(unos[i]=='D')
					{
						smjer==Smjerovi::Desno;
					}
					else if((i<unos.size()-1))
					{
						if(unos[i]=='G' && unos[i+1]=='L')
						{
							i++;
						smjer==Smjerovi::GoreLijevo;
						}
						else if(unos[i]=='G' && unos[i+1]=='D')
						{
							i++;
						smjer==Smjerovi::GoreDesno;
						}
						else if(i<(unos.size()-2))
						{
									if(unos[i]=='D' && unos[i+1]=='o' && unos[i+2]=='L')
							{
								i++;
							smjer==Smjerovi::DoljeLijevo;
							}
						else if(unos[i]=='D' && unos[i+1]=='o' && unos[i+2]=='D')
							{
							i++;
							smjer==Smjerovi::DoljeDesno;
							}
							else pogresnaNaredba=true;
						}
					}
				}
				else if(privremena==Komande::PomjeriDalje || privremena==Komande::Blokiraj  || privremena==Komande::Deblokiraj)
				{
					nedostajeParametar=false;
					bilaNaredba=true;
					int x1=0,y1=0;
					for(i;i<unos.size();i++)
					{
						if(unos[i]>='0' && unos[i]<='9')
						{
							int r=(unos[i]-'0');
							x1=x1*10+r;
						} else if(unos[i]==' ')
						break;
						else
						{pogresnaNaredba=true;}
					}
					while(unos[i]==' ')
					{
						if(unos.size()>=i) break;
						i++;
					}
					for(i;i<unos.size();i++)
					{
						if(unos[i]>='0' && unos[i]<='9')
						{
							int r=(unos[i]-'0');
							y1=y1*10+r;
						}
						else if(unos[i]==' ')
						{
							for(int k=i;k<unos.size();k++)
							if(unos[k]!=' ') pogresnaNaredba=true;
						}
						else if(unos[i]!=' ')
						{ suvisnaKomanda=true; break;}
					}
			x=x1; y=y1;
				}
				else if(privremena==Komande::ZavrsiIgru || privremena==Komande::PrikaziOkolinu  || privremena==Komande::KreirajIgru)
				{
					nedostajeParametar=false;
					bilaNaredba=true;
				}
			}
		}
		
	}
	komanda=privremena;
	if(bilaNaredba) greska=KodoviGresaka::SuvisanParametar;
	else if(pogresnaNaredba) greska==KodoviGresaka::PogresnaKomanda;
	else if(nedostajeParametar) greska=KodoviGresaka::NedostajeParmetar;
	if(greska==KodoviGresaka::SuvisanParametar || greska==KodoviGresaka::PogresnaKomanda || greska==KodoviGresaka::NedostajeParmetar)
	return false;
	else return true;
}
void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y,
Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0)
{
	if(komanda==Komande::PomjeriDalje)
	{
		Status status=Idi(polja,x,y,p_x,p_y);
		if(status==Status::KrajPoraz) std::cout<<"Nagazili ste na minu";
		else if(status==Status::KrajPobjeda) std::cout<<"Bravo, obisli ste sva sigurna polja";
	}
	else if(komanda==Komande::PomjeriJednoMjesto)
	{
		Status status=Idi(polja,x,y,p_smjer);
		if(status==Status::KrajPoraz) std::cout<<"Nagazili ste na minu";
		else if(status==Status::KrajPobjeda) std::cout<<"Bravo, obisli ste sva sigurna polja";
	}
	else if(komanda==Komande::PrikaziOkolinu)
	{
		auto p=PrikaziOkolinu(polja,x,y);
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			std::cout<<p[i][j]<<" ";
			std::cout<<std::endl;
		}
		
	}
	else if(komanda==Komande::Blokiraj)
	{
		BlokirajPolje(polja,p_x,p_y);
	}
	else if(komanda==Komande::Deblokiraj)
	{
		DeBlokirajPolje(polja,p_x,p_y);
	}
	else if(komanda==Komande::ZavrsiIgru)
	{
		for(int i=0;i<polja.size();i++)
		for(int j=0;j<polja[i].size();j++)
		polja[i][j]=Polje::Prazno;
		throw std::runtime_error("Igra zavrsena");
	}
}
int main ()
{
	return 0;
}
/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <complex>
enum class Polje{
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};

enum class Smjerovi{
	GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};

enum class Status{
	NijeKraj, KrajPoraz, KrajPobjeda
};

enum class KodoviGresaka{
	PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};

enum class Komande{
	PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};


typedef std::vector<std::vector<Polje>> Tabla;
Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine)
{
	std::vector<std::vector<Polje>> tabelica(n,std::vector<Polje>(n,Polje::Prazno));
	for(int i=0;i<mine.size();i++)
	{
		if(mine[i].size()!=2)
		throw std::domain_error("Ilegalan format zadavanja mina");                                        /* IZUZETAK */
		if(mine[i][0]<0 || mine [i][0]>n-1 || mine[i][1]<0 || mine [i][1]>n-1)
		throw std::domain_error("Ilegalne pozicije mina");                                                /* IZUZETAK */
		tabelica[mine[i][0]][mine[i][1]]=Polje::Mina;
	}
	return tabelica;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja,int x,int y)
{
	if(x<0 || x>=polja.size() || y<0 || y>=polja[x].size())
	{
		std::string s;
		s="Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji";
		throw std::domain_error(s);                                                        /*IZUZETAK*/
	}
	std::vector<std::vector<int>> matrica(3,std::vector<int>(3,0));
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(x+i-1<0 || x+i-1>=polja.size() || y+j-1<0 || y+j-1>=polja[x+i-1].size())
			continue;
			int t(0);
			for(int k=0;k<3;k++)
			{
				for(int p=0;p<3;p++)
				{
					if(x+i-1+k-1<0 || x+i-1+k-1>=polja.size() || y+j-1+p-1<0 || y+j-1+p-1>=polja[x+i-1+k-1].size() || (p==1 && k==1))
					continue;
					else
					{
						if(polja[x+i-1+k-1][y+j-1+p-1]==Polje::Mina)
						t++;
					}
				}
			}
			matrica[i][j]=t;
		}
	}
	return matrica;
}

void BlokirajPolje(Tabla &polja,int x,int y)
{
	if(x<0 || x>=polja.size() || y<0 || y>=polja[x].size())
	{
		std::string s;
		s="Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji";
		throw std::domain_error(s);                                                        /*IZUZETAK*/
	}                                                    
	if(polja[x][y]<=Polje::Mina && polja[x][y]>=Polje::Prazno)
	polja[x][y]=Polje(3+int(polja[x][y]));
}

void DeblokirajPolje(Tabla &polja,int x,int y)
{
	if(x<0 || x>=polja.size() || y<0 || y>=polja[x].size())
	{
		std::string s;
		s="Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji";
		throw std::domain_error(s);                                                        /*IZUZETAK*/
	}                                                 
	if(polja[x][y]<=Polje::BlokiranoMina && polja[x][y]>=Polje::BlokiranoPrazno)
	polja[x][y]=Polje(int(polja[x][y])-3);
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer)
{
	
	int x1(x),y1(y);
	for(;;)
	{
	if(smjer==Smjerovi::GoreLijevo)
	{x1=x-1;y1=y-1;break;}
	if(smjer==Smjerovi::GoreDesno)
	{x1=x-1;y1=y+1;break;}
	if(smjer==Smjerovi::DoljeLijevo)
	{x1=x+1;y1=y-1;break;}
	if(smjer==Smjerovi::DoljeDesno)
	{x1=x+1;y1=y+1;break;}
	if(smjer==Smjerovi::Gore)
	{x1=x-1;y1=y;break;}
	if(smjer==Smjerovi::Dolje)
	{x1=x+1;y1=y;break;}
	if(smjer==Smjerovi::Lijevo)
    {x1=x;y1=y-1;break;}
	if(smjer==Smjerovi::Desno)
	{x1=x;y1=y+1;break;}
	}
	if(x1<0 || x1>=polja.size() || y1<0 || y1>=polja[x1].size())
		throw std::out_of_range("Izlazak van igrace table");                                               /* IZUZETAK */
		if (polja[x1][y1]>=Polje::BlokiranoPrazno && polja[x1][y1]<=Polje::BlokiranoMina)
		throw std::logic_error("Blokirano polje");                                                     /* IZUZETAK */
		polja[x][y]=Polje::Posjeceno;
		x=x1;
		y=y1;
	if(polja[x][y]==Polje::Mina)
	return Status::KrajPoraz;
	else
	{
		for(int i=0;i<polja.size();i++)
		{
			for(int j=0;j<polja[i].size();j++)
			{
				if(polja[i][j]==Polje::Mina)
				return Status::NijeKraj;
			}
		}
		return Status::KrajPobjeda;
	}
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y)
{
	
	if(novi_x<0 || novi_x>=polja.size() || novi_y<0 || novi_y>=polja[novi_x].size())
	throw std::out_of_range("Izlazak van igrace table");                                                    /* IZUZETAK */
	if (polja[novi_x][novi_y]>=Polje::BlokiranoPrazno && polja[novi_x][novi_y]<=Polje::BlokiranoMina)
	throw std::logic_error("Blokirano polje");                                                             /* IZUZETAK */
	x=novi_x;y=novi_y;	
	if(polja[x][y]==Polje::Mina)
	return Status::KrajPoraz;
	else
	{
		for(int i=0;i<polja.size();i++)
		{
			for(int j=0;j<polja[i].size();j++)
			{
				if(polja[i][j]==Polje::Mina)
				return Status::NijeKraj;
			}
		}
		return Status::KrajPobjeda;
	}
	
}

void PrijaviGresku(KodoviGresaka greskica)
{
	if(greskica==KodoviGresaka::PogresnaKomanda)
	{std::cout<<"Nerazumljiva komanda!"<<std::endl;return;}
	if(greskica==KodoviGresaka::NedostajeParametar)
	{std::cout<<"Komanda trazi parametar koji nije naveden!"<<std::endl;return;}
	if(greskica==KodoviGresaka::NeispravanParametar)
	{std::cout<<"Parametar komande nije ispravan!"<<std::endl;return;}
	if(greskica==KodoviGresaka::SuvisanParametar)
	{std::cout<<"Zadan je suvisan parametar nakon komande!"<<std::endl;return;}
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer,int &x,int &y,KodoviGresaka &greska)
{
	std::string recenica,pomocni;
	std::getline(std::cin,recenica);
	int i=0;
	while(i<recenica.size() && recenica[i]==' ' )
	i++;
	recenica=recenica.substr(i,recenica.size());
	i=0;
	while(recenica.size()!=0)
	{
		if(recenica[recenica.size()-1]==' ')
		recenica.resize(recenica.size()-1);
		else break;
	}
	if(recenica.size()==0)
	{greska=KodoviGresaka::PogresnaKomanda;
	return false;}
	char znak=recenica[0];
	if(recenica[0]=='K')
	{
		if(recenica.size()!=1)
		{greska=KodoviGresaka::SuvisanParametar;
		return false;}
		komanda=Komande::KreirajIgru;
		return true;
	}
	if(recenica[0]=='Z')
	{
		if(recenica.size()!=1)
		{greska=KodoviGresaka::SuvisanParametar;
		return false;}
		komanda=Komande::ZavrsiIgru;
		return true;
	}
		if(recenica.size()>=2 && recenica[0]=='P' && recenica[1]=='O')
	{
		if(recenica.size()!=2)
		{greska=KodoviGresaka::SuvisanParametar;
		return false;}
		komanda=Komande::PrikaziOkolinu;
		return true;
	}
	if(recenica[0]=='D' || recenica[0]=='B')
	{
		
	
	    int i(1);int a(2),b(2);
		if(recenica.size()==1)
     	{greska=KodoviGresaka::NedostajeParametar;
    	return false;}
    	
		while(i<recenica.size() && recenica[i]==' ')
		i++;
		if(i==recenica.size())
		{greska=KodoviGresaka::NedostajeParametar;
    	return false;}
		
		recenica=recenica.substr(i,recenica.size());
		
		if(recenica[0]<='9' && recenica[0]>='0')
		a=std::stoi(recenica,nullptr);
		else
		{greska=KodoviGresaka::NeispravanParametar;
    	return false;}
		i=0;
		
		while(i<recenica.size() && recenica[i]<='9' && recenica[i]>='0')
		i++;
		if(i==recenica.size()) 
		{greska=KodoviGresaka::NedostajeParametar;
    	return false;}
    	if(recenica[i]!=' ')
		{greska=KodoviGresaka::NeispravanParametar;
    	return false;}
    	while(i<recenica.size() && recenica[i]==' ')
    	i++;
    	if(i==recenica.size())
		{greska=KodoviGresaka::NedostajeParametar;
    	return false;}
		recenica=recenica.substr(i,recenica.size()-1);
		if(recenica[0]<='9' && recenica[0]>='0')
		b=std::stoi(recenica,nullptr);
		i=0;
		while(i<recenica.size() && recenica[i]<='9' && recenica[i]>='0')
		i++;
		if(i==recenica.size())
		{
			x=a;y=b;
			if(znak=='D')
			komanda=Komande::Deblokiraj;
			else
			komanda=Komande::Blokiraj;
			return true;
		}
while(i<recenica.size() && recenica[i]==' ')
i++;
if(i==recenica.size())
		{
			x=a;y=b;
			if(znak=='D')
			komanda=Komande::Deblokiraj;
			else
			komanda=Komande::Blokiraj;
			return true;
		}
		else
		{greska=KodoviGresaka::NeispravanParametar;
    	return false;}
	
	}
	if(recenica.size()>=2 && recenica[0]=='P' && recenica[1]=='>')
	{
		
	
	    int i(2);int a(2),b(2);
		if(recenica.size()==2)
     	{greska=KodoviGresaka::NedostajeParametar;
    	return false;}
    	
		while(i<recenica.size() && recenica[i]==' ')
		i++;
		if(i==recenica.size())
		{greska=KodoviGresaka::NedostajeParametar;
    	return false;}
		recenica=recenica.substr(i,recenica.size());
		
     	
		if(recenica[0]<='9' && recenica[0]>='0')
		a=std::stoi(recenica,nullptr);
		else
		{greska=KodoviGresaka::NeispravanParametar;
    	return false;}
		i=0;
		
		while(i<recenica.size() && recenica[i]<='9' && recenica[i]>='0')
		i++;
		if(i==recenica.size())
		{greska=KodoviGresaka::PogresnaKomanda;
    	return false;}
    	if(recenica[i]!=' ')
		{greska=KodoviGresaka::NeispravanParametar;
    	return false;}
    	while(i<recenica.size() && recenica[i]==' ')
    	i++;
    	if(i==recenica.size())
		{greska=KodoviGresaka::SuvisanParametar;
    	return false;}
		recenica=recenica.substr(i,recenica.size());
		if(recenica[0]<='9' && recenica[0]>='0')
		b=std::stoi(recenica,nullptr);
		i=0;
		while(i<recenica.size() && recenica[i]<='9' && recenica[i]>='0')
		i++;
		if(i==recenica.size())
		{
			x=a;
			y=b;
			komanda=Komande::PomjeriDalje;
			return true;
		}
		while(i<recenica.size() && recenica[i]==' ')
		i++;
		if(i==recenica.size())
		{
			x=a;
			y=b;
			komanda=Komande::PomjeriDalje;
			return true;
		}
		else
		{greska=KodoviGresaka::SuvisanParametar;
    	return false;}

	
	}
	
	if(recenica.size()>=2 && recenica[0]=='P' && recenica[1]=='1')
	{
		int i(2);
		while(i<recenica.size() && recenica[i]==' ')
		i++;
		if(i==recenica.size())
		{greska=KodoviGresaka::NedostajeParametar;
    	return false;}
    	;
    	recenica=recenica.substr(i,recenica.size());
    	while(recenica.size()!=0 && recenica[recenica.size()-1]==' ')
    	recenica.resize(recenica.size()-1);
    	if(recenica.size()==1)
    	{
    		if(recenica=="G")
    		{
    			komanda=Komande::PomjeriJednoMjesto;
    			smjer=Smjerovi::Gore;
    			return true;
    		}
    		if(recenica=="D")
    		{
    			komanda=Komande::PomjeriJednoMjesto;
    			smjer=Smjerovi::Desno;
    			return true;
    		}
    		if(recenica=="L")
    		{
    			komanda=Komande::PomjeriJednoMjesto;
    			smjer=Smjerovi::Lijevo;
    			return true;
    		}
    		greska=KodoviGresaka::NeispravanParametar;
    	return false;
    	}
    	if(recenica.size()==2)
    	{
    		if(recenica=="GL")
    		{
    			komanda=Komande::PomjeriJednoMjesto;
    			smjer=Smjerovi::GoreLijevo;
    			return true;
    		}
    		if(recenica=="GD")
    		{
    			komanda=Komande::PomjeriJednoMjesto;
    			smjer=Smjerovi::GoreDesno;
    			return true;
    		}
    		if(recenica=="Do")
    		{
    			komanda=Komande::PomjeriJednoMjesto;
    			smjer=Smjerovi::Dolje;
    			return true;
    		}
    		greska=KodoviGresaka::NeispravanParametar;
    	return false;
    	}
    	if(recenica.size()==3)
    	{
    			if(recenica=="DoD")
    		{
    			komanda=Komande::PomjeriJednoMjesto;
    			smjer=Smjerovi::DoljeDesno;
    			return true;
    		}
    			if(recenica=="DoL")
    		{
    			komanda=Komande::PomjeriJednoMjesto;
    			smjer=Smjerovi::DoljeLijevo;
    			return true;
    		}
    		greska=KodoviGresaka::NeispravanParametar;
    	return false;
    	}
	}
	
	
	greska=KodoviGresaka::PogresnaKomanda;
    return false;
	
}


void IzvrsiKomandu(Komande komanda,Tabla &polja,int &x,int &y,Smjerovi p_smjer=Smjerovi::Gore,int p_x=0,int p_y=0)
{
	if(komanda==Komande::PomjeriJednoMjesto)  /* Pomjeri jedno mjesto*/
	{
		Status izvjestaj;
		try
		{
			izvjestaj=Idi(polja,x,y,p_smjer);
		}
		catch(std::out_of_range e)
		{
			std::cout<<e.what()<<std::endl;return;
		}
		catch(std::logic_error e)
		{
			std::cout<<e.what()<<std::endl;return;
		}
		
		std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
		if(izvjestaj==Status::NijeKraj)
		return;
		if(izvjestaj==Status::KrajPoraz)
		std::cout<<"Nagazili ste na minu";
		if(izvjestaj==Status::KrajPobjeda)
		std::cout<<"Bravo, obisli ste sva sigurna polja";
		for(int i=0;i<polja.size();i++)
		{
			for(int j=0;j<polja[i].size();j++)
			polja[i][j]=Polje::Prazno;
		}
			throw std::runtime_error("Igra zavrsena");                                                     /* IZUZETAK */
		
		
		
		
		
		
	}
	if(komanda==Komande::PomjeriDalje)  /* Pomjeri dalje*/
	{
		Status izvjestaj;
		try
		{
			izvjestaj=Idi(polja,x,y,x,y);
		}
		catch(std::out_of_range e)
		{
			std::cout<<e.what()<<std::endl;return;
		}
		catch(std::logic_error e)
		{
			std::cout<<e.what()<<std::endl;return;
		}
		std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
		if(izvjestaj==Status::NijeKraj)
		return;
		if(izvjestaj==Status::KrajPoraz)
		std::cout<<"Nagazili ste na minu"<<std::endl;
		if(izvjestaj==Status::KrajPobjeda)
		std::cout<<"Bravo, obisli ste sva sigurna polja"<<std::endl;
		for(int i=0;i<polja.size();i++)
		{
			for(int j=0;j<polja[i].size();j++)
			polja[i][j]=Polje::Prazno;
		}
			throw std::runtime_error("Igra zavrsena");                                                   /* IZUZETAK */
	}
	if(komanda==Komande::Blokiraj)  /* Blokiraj*/
	{
		try
		{
			BlokirajPolje(polja,x,y);
		}
		catch(std::domain_error e)
		{
			std::cout<<e.what()<<std::endl;
		}
		return;
	}
	if(komanda==Komande::Deblokiraj)  /* Deblokiraj*/
	{
		try
		{
			DeblokirajPolje(polja,x,y);
		}
		catch(std::domain_error e)
		{
			std::cout<<e.what()<<std::endl;
		}
		return;
	}
	if(komanda==Komande::PrikaziOkolinu)  /* Prikazi okolinu*/
	{
		std::vector<std::vector<int>> tabelica;
		try{
			tabelica=PrikaziOkolinu(polja,x,y);
		}
		catch(std::domain_error e)
		{
			std::cout<<e.what()<<std::endl;
		}
		for(int i=0;i<tabelica.size();i++)
		{
			for(int j=0;j<tabelica[i].size();j++)
			std::cout<<tabelica[i][j]<<" ";
			std::cout<<std::endl;
		}
	}
	if(komanda==Komande::ZavrsiIgru)  /* Zavrsi igru*/
	{
		for(int i=0;i<polja.size();i++)
		{
			for(int j=0;j<polja[i].size();j++)
			polja[i][j]=Polje::Prazno;
		}
			throw std::runtime_error("Igra zavrsena");                                                /* IZUZETAK */
	}
	if(komanda==Komande::KreirajIgru)  /* Kreiraj igru*/
	{
		std::cout<<"Unesite broj polja: ";
		int n;
		std::cin>>n;
		std::cin.ignore(10000,'\n');
		std::string ulaz;
		int prvi,drugi;
		std::vector<std::vector<int>>mine;
		std::cout<<"Unesite pozicije mina: ";
	
		for(;;)
		{
			std::getline(std::cin,ulaz);
			
			while(ulaz.size()!=0 && ulaz[ulaz.size()-1]==' ')
		    ulaz.resize(ulaz.size()-1);
		    
			if(ulaz==".")
			break;
			if(!(ulaz[0]=='(' && ulaz[ulaz.size()-1]==')'))
			{std::cout<<"Greska, unesite ponovo! "<<std::endl;continue;}
			
			if(ulaz.size()<5)
			{std::cout<<"Greska, unesite ponovo! "<<std::endl;continue;}
			
			ulaz=ulaz.substr(1,ulaz.size()-2);
			int i=0;
			if(ulaz[0]>'9' || ulaz[0]<'0')
			{std::cout<<"Greska, unesite ponovo! "<<std::endl;continue;}
			
			prvi=std::stoi(ulaz,nullptr);
			while(i<ulaz.size() && ulaz[i]<='9' && ulaz[i]>='0')
		    i++;
		    if(i==ulaz.size())
		    {std::cout<<"Greska, unesite ponovo! "<<std::endl;continue;}
		    
		    if(ulaz[i]==',')
		    i++;
		    ulaz=ulaz.substr(i,ulaz.size()-1);
			i=0;
			if(ulaz[0]>'9' || ulaz[0]<'0')
			{std::cout<<"Greska, unesite ponovo! "<<std::endl;continue;}
			
			drugi=std::stoi(ulaz,nullptr);
			
			while(i<ulaz.size() && ulaz[i]<='9' && ulaz[i]>='0')
		    i++;
		    if(i!=ulaz.size())
		    {std::cout<<"Greska, unesite ponovo! "<<std::endl;continue;}
		    else
		    {
		    	if(!(prvi<n && drugi<n))
		    	{std::cout<<"Greska, unesite ponovo! "<<std::endl;continue;}
		    	
		    	mine.resize(mine.size()+1);
		    	mine[mine.size()-1].push_back(prvi);
		    	mine[mine.size()-1].push_back(drugi);
		    	
		    }
		}
		
	polja=KreirajIgru(n,mine); 
	
		
	}
	
	
	
	
	
}

int main()
{

	Komande komanda;
	Smjerovi smjer=Smjerovi::Gore;
	int x=0;
	int y=0;
	KodoviGresaka greska;
	Tabla polja;
	
	int p_x=0;
	int p_y=0;
	try
	{
		for(;;)
		{
			std::cout<<"Unesite komandu: ";
			UnosKomande(komanda,smjer,x,y,greska);
			IzvrsiKomandu(komanda,polja,x,y,smjer,p_x,p_y);
		}
	}
	catch(std::domain_error e)
	{	std::cout<<"Izuzetak: "<<e.what();}
	catch(std::out_of_range e)
	{	std::cout<<"Izuzetak: "<<e.what();}
	catch(std::logic_error e)
	{	std::cout<<"Izuzetak: "<<e.what();}
	catch(std::runtime_error e)
	{	std::cout<<"Dovidjenja!";}
	
	return 0;
}

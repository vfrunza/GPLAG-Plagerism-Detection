/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <complex>

enum class Polje
{
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};
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
/*************************************************************/
typedef std::vector<std::vector<Polje>> Tabla;

bool DaLiJeIzuzetak(const Tabla polja, const int x, const int y)
{
	if(x<0 || y<0 || x>=polja.size())	return true;
	for(int i=0; i<polja.size(); i++)
		if(y>=polja[i].size())	return true;
	return false;		//petlja dodana
}
bool DaLiJeBlokirano(const Tabla polja, const int x, const int y)
{
	return(int(polja[x][y])>=3 && int(polja[x][y])<=5);
}
void OcistiMatricu(Tabla &polja)
{
	for(int i=0; i<polja.size(); i++)
		for(int j=0; j<polja[i].size(); j++)
			polja[i][j]=Polje::Prazno;
}
bool DaLiSuSvaPosjecena(const Tabla polja)
{
	for(int i=0; i<polja.size(); i++)
		for(int j=0; j<polja[i].size(); j++)
			if(polja[i][j]!=Polje::Posjeceno && polja[i][j]!=Polje::BlokiranoMina && polja[i][j]!=Polje::Mina && polja[i][j]!=Polje::BlokiranoPosjeceno)	return false;
	return true;
}
std::string PretvoriUString(int x)
{
	std::ostringstream s;
	s<<x;
	return s.str();
}
bool IspravanUnos(std::string s, int &x, int &y)
{
	int i(0);
	if(i<s.length() && s[i]=='(')	i++;
	else return false;
	int poc(i);
	if(i<s.length() && s[i]>='0' && s[i]<='9')
		while(i<s.length() && s[i]>='0' && s[i]<='9')	i++;
	else return false;
	x=stoi(s.substr(poc, i-poc));
	if(i<s.length() && s[i]==',')	i++;
	else return false;
	poc=i;
	if(i<s.length() && s[i]>='0' && s[i]<='9')
		while(i<s.length() && s[i]>='0' && s[i]<='9')	i++;
	else return false;
	y=stoi(s.substr(poc,i-poc));
	if(i<s.length() && s[i]==')')	i++;
	else return false;
	if(i==s.length())	return true;
	else return false;
	
	
	return true;
}
/*************************************************************/
Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine)
{
	std::vector<std::vector<Polje>> board(n, std::vector<Polje>(n, Polje::Prazno));
	for(int i=0; i<mine.size(); i++)
	{
		if(mine[i].size()!=2)	throw std::domain_error("Ilegalan format zadavanja mina");
		int x(mine[i][0]), y(mine[i][1]);
		if(x>=n || y>=mine[i].size() || x<0 || y<0)		throw std::domain_error("Ilegalne pozicije mina");//uslovi nule dodato
		board[x][y]=Polje::Mina;
	}
	return board;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y)
{
	//dodati uslov za y>polja[i].size() da li tabla moze biti grbava matrica? for-petlja
	std::vector<std::vector<int>> Okolina;
	
	if(DaLiJeIzuzetak(polja,x,y))	throw std::domain_error("Polje ("+PretvoriUString(x)+","+PretvoriUString(y)+") ne postoji");
	for(int i=x-1; i<x+2 ; i++)
	{
		std::vector<int> temp;
		for(int j=y-1; j<y+2; j++)
		{
			if(i<0 || j<0 || i>int(polja.size())-1 || j>int(polja[i].size())-1)	temp.push_back(0);
			else
			{
				int brojac(0);
				for(int k=i-1; k<i+2; k++)
					for(int l=j-1; l<j+2; l++)
					{
						if(k<0 || l<0 || k>int(polja.size())-1 || l>int(polja[i].size())-1) continue;
						if(k==i && l==j)	continue;
						else if(int(polja[k][l])==2)	brojac++;
					}
				temp.push_back(brojac);
			}
			if(temp.size()==3)	Okolina.push_back(temp);
		}
	}
	return Okolina;
}

void BlokirajPolje(Tabla &polja, int x, int y)
{
	if(DaLiJeIzuzetak(polja,x,y))	throw std::domain_error("Polje ("+PretvoriUString(x)+","+PretvoriUString(y)+") ne postoji");
	if(int(polja[x][y])<3) 	polja[x][y]=Polje(int(polja[x][y])+3);
}
void DeblokirajPolje(Tabla &polja, int x, int y)
{
	if(DaLiJeIzuzetak(polja,x,y))	throw std::domain_error("Polje ("+PretvoriUString(x)+","+PretvoriUString(y)+") ne postoji");
	if(int(polja[x][y])>2)	polja[x][y]=Polje(int(polja[x][y])-3);
}

Status Idi(Tabla &polja, int &x, int&y, Smjerovi smjer)
{
	int temp_x(x), temp_y(y);
	if(int(smjer)<=2)	temp_x--;
	else if(int(smjer)>=4 && int(smjer)<=6)	temp_x++;
	if(int(smjer)>=2 && int(smjer) <=4)	temp_y++;
	else if(int(smjer)>=6 || int(smjer)==0)	temp_y--;
	if(DaLiJeIzuzetak(polja,temp_x,temp_y))	throw std::out_of_range("Izlazak van igrace table");
	if(DaLiJeBlokirano(polja,temp_x,temp_y))	throw std::logic_error("Blokirano polje");
	polja[x][y]=Polje::Posjeceno;
	x=temp_x;
	y=temp_y;
	Status ishod(Status::NijeKraj);
	if(polja[x][y]==Polje::Mina)	
	{
		OcistiMatricu(polja);//prvo return pa onda cistiti u mainu?
		ishod=Status::KrajPoraz;
		return ishod;
	}
	Polje temp=polja[x][y];
	polja[x][y]=Polje::Posjeceno;
	if(DaLiSuSvaPosjecena(polja))
	{
		ishod=Status::KrajPobjeda;
		return ishod;					//dodat return
	}
	polja[x][y]=temp;
	return ishod;
}
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y)
{
	if(DaLiJeIzuzetak(polja,novi_x,novi_y))	throw std::out_of_range("Izlazak van igrace table");
	if(DaLiJeBlokirano(polja,novi_x,novi_y))	throw std::logic_error("Blokirano polje");
	polja[x][y]=Polje::Posjeceno;
	x=novi_x;
	y=novi_y;
	Status ishod(Status::NijeKraj);
	if(polja[x][y]==Polje::Mina)
	{
		OcistiMatricu(polja);
		ishod=Status::KrajPoraz;
	}
	else if(DaLiSuSvaPosjecena(polja)) ishod=Status::KrajPobjeda;
	
	return ishod;
}

void PrijaviGresku(KodoviGresaka greska)
{
	if(greska==KodoviGresaka::PogresnaKomanda)	std::cout<<"Nerazumljiva komanda!"<<std::endl;
	else if(greska==KodoviGresaka::NedostajeParametar) std::cout<<"Komanda trazi parametar koji nije naveden!"<<std::endl;
	else if(greska==KodoviGresaka::NeispravanParametar) std::cout<<"Parametar komande nije ispravan!"<<std::endl;
	else std::cout<<"Zadan je suvisan parametar nakon komande!"<<std::endl;
}
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska)
{
	std::string unos;
	std::getline(std::cin, unos);
	int br(0);
	while(br<unos.length() && unos[br]==' ')	br++;
	unos=unos.substr(br,int(unos.length())-br+1);
	
	std::vector<std::string> order{"P1","P>","B","D","PO","Z","K"};
	for(int i=0; i<7; i++)
	{
		int duz(order[i].length());
		if(unos.length()>=duz && unos.substr(0,duz)==order[i])
		{
			komanda=Komande(i);
			br=duz;
			while(br<unos.length() && unos[br]==' ')	br++;
				unos=unos.substr(br,unos.length()-br);
			br=0;
			//1 parametar funkcija P1
			if(i==0)
			{
				std::vector<std::string> direction{"GL","G","GD","D","DoD","Do","DoL","L"};
				if(unos.length()==0)	
				{
					greska=KodoviGresaka::NedostajeParametar;
					return false;
				}
				while(br<unos.length() && unos[br]!=' ')	br++;
				for(int j=0; j<8; j++)
					if(unos.substr(0,br)==direction[j])
					{
						while(br<unos.length() && br==' ')	br++;
						if(br==unos.length())
						{
							smjer=Smjerovi(j);
							return true;
						}
						else
						{
							greska=KodoviGresaka::SuvisanParametar;
							return false;
						}
					}
				greska=KodoviGresaka::NeispravanParametar;
				return false;
			}
			else if(i>=1 && i<=3)
			{
				int j(0);
				if(unos.length()==j)	
				{
					greska=KodoviGresaka::NedostajeParametar;
					return false;
				}
				int poc=j;
				while(j<unos.length() && unos[j]!=' ')	
				{
					if(unos[j]<'0' || unos[j]>'9')
					{
						greska=KodoviGresaka::NeispravanParametar;
						return false;
					}
					j++;
				}
				x=std::stoi(unos.substr(poc, j-poc));
				while(j<unos.length() && unos[j]==' ')	j++;
				if(unos.length()==j)
				{
					greska=KodoviGresaka::NedostajeParametar;
					return false;
				}
				poc=j;
				while(j<unos.length() && unos[j]!=' ')
				{
					if(unos[j]<'0' || unos[j]>'9')
					{
						greska=KodoviGresaka::NeispravanParametar;
						return false;
					}
					j++;
				}
				y=std::stoi(unos.substr(poc,j-poc));
				while(j<unos.length() && unos[j]==' ')	j++;
				if(unos.length()==j)	return true;
				else 
				{
					greska=KodoviGresaka::SuvisanParametar;
					return false;
				}
			}
			else if(i>=4)
			{
				if(unos.length()==0) return true;
				else
				{
					greska=KodoviGresaka::SuvisanParametar;
					return false;
				}
			}
			break;
		}
		else if(i==6)
		{
			greska=KodoviGresaka::PogresnaKomanda;
			return false;
		}
	}
	return false;
}
void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer=Smjerovi::Gore, int p_x=0, int p_y=0)
{
	try
	{
		if(komanda==Komande::PomjeriJednoMjesto)
		{
			auto temp(Idi(polja,x,y,p_smjer));
			std::cout<<"Tekuca pozicija igraca je ("+PretvoriUString(x)+","+PretvoriUString(y)+")"<<std::endl;
			if(temp==Status::KrajPobjeda)
			{
				std::cout<<"Bravo, obisli ste sva sigurna polja"<<std::endl;
				komanda=Komande::ZavrsiIgru;
			}
			else if(temp==Status::KrajPoraz)
			{
				std::cout<<"Nagazili ste na minu"<<std::endl;
				komanda=Komande::ZavrsiIgru;
			}
		}
		else if(komanda==Komande::PomjeriDalje)
		{
			Status temp=Idi(polja,x,y,p_x,p_y);
			std::cout<<"Tekuca pozicija igraca je ("+PretvoriUString(x)+","+PretvoriUString(y)+")"<<std::endl;
			if(temp==Status::KrajPobjeda)
			{
				std::cout<<"Bravo, obisli ste sva sigurna polja"<<std::endl;
				komanda=Komande::ZavrsiIgru;
			}
			else if(temp==Status::KrajPoraz)
			{
				std::cout<<"Nagazili ste na minu"<<std::endl;
				komanda=Komande::ZavrsiIgru;
			}
		}
		else if(komanda==Komande::Blokiraj)
		{
			BlokirajPolje(polja,p_x,p_y);
		}
		else if(komanda==Komande::Deblokiraj)
		{
			DeblokirajPolje(polja,p_x,p_y);
		}
		else if(komanda==Komande::PrikaziOkolinu)
		{
			std::vector<std::vector<int>> mat(PrikaziOkolinu(polja, x, y));
			for(int i=0; i<mat.size(); i++)
			{
				for(int j=0; j<mat[i].size(); j++)
				{
					if(j==int(mat[i].size())-1)	std::cout<<mat[i][j];
					else std::cout<<mat[i][j]<<" ";
				}
				std::cout<<std::endl;
			}
		}
		if(komanda==Komande::ZavrsiIgru)
		{
			OcistiMatricu(polja);
			throw std::runtime_error("Igra zavrsena");
		}
	}
	catch(std::domain_error izuzetak)
	{
		std::cout<<izuzetak.what()<<std::endl;
	}
	catch(std::out_of_range izuzetak)
	{
		std::cout<<izuzetak.what()<<std::endl;
	}
	catch(std::logic_error izuzetak)
	{
		std::cout<<izuzetak.what()<<std::endl;
	}
	if(komanda==Komande::KreirajIgru)
	{
		int n;
		std::cout<<"Unesite broj polja: ";
		std::cin>>n;
		std::string pozicija;
		int prva, druga;
		std::vector<std::vector<int>> mine;
		std::cout<<"Unesite pozicije mina: ";
		for(;;)
		{
			std::vector<int> temp;
			std::cin>>pozicija;
			if(IspravanUnos(pozicija, prva, druga))
			{
				if(prva>=n || druga>=n || prva<0 || druga<0)
				{
					std::cin.ignore(10000,'\n');
					std::cin.clear();
					std::cout<<"Greska, unesite ponovo!"<<std::endl;
				}
				else
				{
					temp.push_back(prva);
					temp.push_back(druga);
					mine.push_back(temp);
				}
			}
			else if(pozicija=="." && pozicija.size()==1)	
			{
				std::cin.ignore(10000,'\n');
				std::cin.clear();
				break;
			}
			else if(!IspravanUnos(pozicija, prva, druga))
			{
				std::cin.ignore(10000,'\n');
				std::cin.clear();
				std::cout<<"Greska, unesite ponovo!"<<std::endl;
			}
		}
		polja=KreirajIgru(n,mine);
	}
	
}
int main()
{
	try
	{
		Komande komanda;
		Tabla polja;
		int x(0),y(0), p_x(0), p_y(0);
		Smjerovi p_smjer;
		KodoviGresaka greska;
		
		for(;;)
		{
			std::cout<<"Unesite komandu: ";
			if(UnosKomande(komanda,p_smjer,p_x,p_y,greska))	IzvrsiKomandu(komanda,polja,x,y,p_smjer,p_x,p_y);
			else PrijaviGresku(greska);
		}
		
	}
	catch(std::runtime_error izuzetak)
	{
		//std::cout<<izuzetak.what()<<std::endl;
	}
	std::cout<<"Dovidjenja!";
}
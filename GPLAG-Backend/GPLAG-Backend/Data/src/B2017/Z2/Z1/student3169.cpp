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
#include <string>
#include <sstream>

enum class Polje{Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina};
enum class Smjerovi {GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo};
enum class Status {NijeKraj, KrajPoraz, KrajPobjeda};
enum class KodoviGresaka {PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar};
enum class Komande {PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru};

typedef std::vector<std::vector<Polje>> Tabla;

template <typename T> std::string U_string(T x)
{
	std::ostringstream s;
	s<<x;
	return s.str();
}

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine)
{
	for(int i(0);i<mine.size();i++)
	{
		if(mine.at(i).size()!=2)throw std::domain_error("Ilegalan format zadavanja mina");
	}
	for(int i(0);i<mine.size();i++)
	{
		for(int j(0);j<mine.at(i).size();j++)
		{
			if(mine.at(i).at(j)>=n)throw std::domain_error("Ilegalne pozicije mina");
		}
	}
	if(n<=0)throw std::domain_error("Ilegalna veličina");
	
	Tabla tab1(n, std::vector<Polje>(n,Polje::Prazno));
	for(int i(0);i<mine.size();i++)
	{
			tab1.at(mine.at(i).at(0)).at(mine.at(i).at(1))=Polje::Mina;
	}
	return tab1;
}

int suma(const Tabla &polja, int x, int y)
{
	int Suma(0);
	
	for(int i(x-1);i<=(x+1);i++)
	{
		if(i<0 || i>=polja.size())continue;
		for(int j(y-1);j<=(y+1);j++)
		{
			if(j<0 || j>=polja.size())continue;
			if(polja.at(i).at(j)==Polje::Mina)Suma++;
		}
	}
	if(x>=0 && x<polja.size() && y>=0 && y<polja.size() && polja.at(x).at(y)==Polje::Mina)Suma--;
	return Suma;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y)
{
	if(x<0 || y<0 || x>=polja.size() || y>=polja.size())throw std::domain_error("Polje ("+U_string(x)+","+U_string(y)+") ne postoji");
	std::vector<std::vector<int>>Matrica(3, std::vector<int>(3));
	int k(0);
	for(int i(x-1);i<=(x+1);i++)
	{
		int l(0);
		for(int j(y-1);j<=(y+1);j++)
		{
			Matrica.at(k).at(l)=suma(polja, i, j);
			l++;
		}
		k++;
	}
	return Matrica;
}

void BlokirajPolje(Tabla &polja, int x, int y)
{
	if(x<0 || y<0 || x>=polja.size() || y>=polja.size())throw std::domain_error("Polje ("+U_string(x)+","+U_string(y)+") ne postoji");
	if(polja.at(x).at(y)!=Polje::BlokiranoPrazno && polja.at(x).at(y)!=Polje::BlokiranoPosjeceno && polja.at(x).at(y)!=Polje::BlokiranoMina)
	{
		if(polja.at(x).at(y)==Polje::Prazno)polja.at(x).at(y)=Polje::BlokiranoPrazno;
		else if(polja.at(x).at(y)==Polje::Posjeceno)polja.at(x).at(y)=Polje::BlokiranoPosjeceno;
		else if(polja.at(x).at(y)==Polje::Mina)polja.at(x).at(y)=Polje::BlokiranoMina;
	}
}

void DeblokirajPolje(Tabla &polja, int x, int y)
{
	if(x<0 || y<0 || x>=polja.size() || y>=polja.size())throw std::domain_error("Polje ("+U_string(x)+","+U_string(y)+") ne postoji");
	if(polja.at(x).at(y)==Polje::BlokiranoPrazno || polja.at(x).at(y)==Polje::BlokiranoPosjeceno || polja.at(x).at(y)==Polje::BlokiranoMina)
	{
		if(polja.at(x).at(y)==Polje::BlokiranoPrazno)polja.at(x).at(y)=Polje::Prazno;
		else if(polja.at(x).at(y)==Polje::BlokiranoPosjeceno)polja.at(x).at(y)=Polje::Posjeceno;
		else if(polja.at(x).at(y)==Polje::BlokiranoMina)polja.at(x).at(y)=Polje::Mina;
	}
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer)
{
	int xx(x), yy(y);
	if(smjer==Smjerovi::GoreLijevo)
	{
		if(xx-1<0 || yy-1<0)throw std::out_of_range("Izlazak van igrace table");
		xx--;
		yy--;
	}
	if(smjer==Smjerovi::Gore)
	{
		if(xx-1<0)throw std::out_of_range("Izlazak van igrace table");
		xx--;
	}
	if(smjer==Smjerovi::GoreDesno)
	{
		if(xx-1<0 || yy+1>=polja.size())throw std::out_of_range("Izlazak van igrace table");
		xx--;
		yy++;
	}
	if(smjer==Smjerovi::Lijevo)
	{
		if(yy-1<0)throw std::out_of_range("Izlazak van igrace table");
		yy--;
	}
	if(smjer==Smjerovi::Desno)
	{
		if(yy+1>=polja.size())throw std::out_of_range("Izlazak van igrace table");
		yy++;
	}
	if(smjer==Smjerovi::DoljeDesno)
	{
		if(xx+1>=polja.size() || yy+1>=polja.size())throw std::out_of_range("Izlazak van igrace table");
		xx++;
		yy++;
	}
	if(smjer==Smjerovi::DoljeLijevo)
	{
		if(xx+1>=polja.size() || yy-1<0)throw std::out_of_range("Izlazak van igrace table");
		xx++;
		yy--;
	}
	if(smjer==Smjerovi::Dolje)
	{
		if(xx+1>=polja.size())throw std::out_of_range("Izlazak van igrace table");
		xx++;
	}
	
	if(polja.at(xx).at(yy)==Polje::BlokiranoPrazno || polja.at(xx).at(yy)==Polje::BlokiranoPosjeceno || polja.at(xx).at(yy)==Polje::BlokiranoMina)throw std::logic_error("Blokirano polje");
	polja.at(x).at(y)=Polje::Posjeceno;
	x=xx;
	y=yy;
	if(polja.at(x).at(y)==Polje::Mina)
	{
		for(int i(0);i<polja.size();i++)
		{
			for(int j(0);j<polja.at(i).size();j++){
				polja.at(i).at(j)=Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
	if(polja.at(x).at(y)==Polje::Posjeceno || polja.at(x).at(y)==Polje::Prazno)
	{
		for(int i(0);i<polja.size();i++)
		{
			for(int j(0);j<polja.at(i).size();j++)
			{
				if(i==x && j==y)continue;
				if(polja.at(i).at(j)==Polje::Prazno)
				{
					return Status::NijeKraj;
				}
			}
		}
	}
	
	return Status::KrajPobjeda;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y)
{
	if(novi_x<0 || novi_y<0 || novi_x>=polja.size() || novi_y>=polja.size())throw std::out_of_range("Izlazak van igrace table");
	if(polja.at(novi_x).at(novi_y)==Polje::BlokiranoPrazno || polja.at(novi_x).at(novi_y)==Polje::BlokiranoPosjeceno || polja.at(novi_x).at(novi_y)==Polje::BlokiranoMina)throw std::logic_error("Blokirano polje");
	polja.at(x).at(y)=Polje::Posjeceno;
	x=novi_x;
	y=novi_y;
	if(polja.at(x).at(y)==Polje::Mina)
	{
		for(int i(0);i<polja.size();i++)
		{
			for(int j(0);j<polja.at(i).size();j++)
			{
				polja.at(i).at(j)=Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
	if(polja.at(x).at(y)==Polje::Posjeceno || polja.at(x).at(y)==Polje::Prazno)
	{
		for(int i(0);i<polja.size();i++)
		{
			for(int j(0);j<polja.at(i).size();j++)
			{
				if(i==x && j==y)continue;
				if(polja.at(i).at(j)==Polje::Prazno)
				{
					return Status::NijeKraj;
				}
			}
		}
	}
	return Status::KrajPobjeda;
}

void PrijaviGresku(KodoviGresaka greske)
{
	if(greske==KodoviGresaka::NedostajeParametar)std::cout<<"Komanda trazi parametar koji nije naveden!"<<std::endl;
	if(greske==KodoviGresaka::NeispravanParametar)std::cout<<"Parametar komande nije ispravan!"<<std::endl;
	if(greske==KodoviGresaka::SuvisanParametar)std::cout<<"Zadan je suvisan parametar nakon komande!"<<std::endl;
	if(greske==KodoviGresaka::PogresnaKomanda)std::cout<<"Nerazumljiva komanda!"<<std::endl;
}
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska)
{
	char unos;
	std::cin>>unos;
	while(unos==' ')unos=std::cin.get();
	if(unos!='P' && unos!='B' && unos!='D' && unos!='Z' && unos!='K')
	{
		greska=KodoviGresaka::PogresnaKomanda;
		std::cin.ignore(10000,'\n');
		return false;
	}
	
	if(unos=='K')
	{
		while(std::cin.peek()==' ')unos=std::cin.get();
		if(std::cin.peek()!='\n')
		{
			greska=KodoviGresaka::SuvisanParametar;
			std::cin.ignore(10000,'\n');
			return false;
		}
		komanda=Komande::KreirajIgru;
		std::cin.ignore(10000,'\n');
		return true;
	}
	
	if(unos=='Z')
	{
		while(std::cin.peek()==' ')unos=std::cin.get();
		if(std::cin.peek()!='\n')
		{
			greska=KodoviGresaka::SuvisanParametar;
			std::cin.ignore(10000,'\n');
			return false;
		}
		komanda=Komande::ZavrsiIgru;
		std::cin.ignore(10000,'\n');
		return true;
	}
	
	if(unos=='P' && std::cin.peek()!='1' && std::cin.peek()!='O' && std::cin.peek()!='>')
	{
		greska=KodoviGresaka::PogresnaKomanda;
		std::cin.ignore(10000,'\n');
		return false;
	}
	
	if(unos=='P' && std::cin.peek()=='O')
	{
		unos=std::cin.get();
		while(std::cin.peek()==' ')unos=std::cin.get();
		if(std::cin.peek()!='\n')
		{
			greska=KodoviGresaka::SuvisanParametar;
			std::cin.ignore(10000,'\n');
			return false;
		}
		komanda=Komande::PrikaziOkolinu;
		std::cin.ignore(10000,'\n');
		return true;
	}
	
	if(unos=='P' && std::cin.peek()=='1')
	{
		unos=std::cin.get();
		while(std::cin.peek()==' ')unos=std::cin.get();
		if(std::cin.peek()=='\n')
		{
			greska=KodoviGresaka::NedostajeParametar;
			std::cin.ignore(10000,'\n');
			return false;
		}
		unos=std::cin.get();
		if(unos!='G' && unos!='D' && unos!='L')
		{
			greska=KodoviGresaka::NeispravanParametar;
			std::cin.ignore(10000,'\n');
			return false;
		}
		if(unos=='L')
		{
			while(std::cin.peek()==' ')unos=std::cin.get();
			if(std::cin.peek()!='\n')
			{
				greska=KodoviGresaka::SuvisanParametar;
				std::cin.ignore(10000,'\n');
				return false;
			}
			komanda=Komande::PomjeriJednoMjesto;
			smjer=Smjerovi::Lijevo;
			std::cin.ignore(10000,'\n');
			return true;
		}
		if(unos=='G' && (std::cin.peek()=='\n' || std::cin.peek()==' '))
		{
			while(std::cin.peek()==' ')unos=std::cin.get();
			if(std::cin.peek()!='\n')
			{
				greska=KodoviGresaka::SuvisanParametar;
				std::cin.ignore(10000,'\n');
				return false;
			}
			komanda=Komande::PomjeriJednoMjesto;
			smjer=Smjerovi::Gore;
			std::cin.ignore(10000,'\n');
			return true;
		}
		if(unos=='D' && (std::cin.peek()=='\n' || std::cin.peek()==' '))
		{
			while(std::cin.peek()==' ')unos=std::cin.get();
			if(std::cin.peek()!='\n')
			{
				greska=KodoviGresaka::SuvisanParametar;
				std::cin.ignore(10000,'\n');
				return false;
			}
			komanda=Komande::PomjeriJednoMjesto;
			smjer=Smjerovi::Desno;
			std::cin.ignore(10000,'\n');
			return true;
		}
		if(unos=='G' && std::cin.peek()!='\n' && std::cin.peek()!=' ')
		{
			unos=std::cin.get();
			if(unos!='L' && unos!='D')
			{
				greska=KodoviGresaka::NeispravanParametar;
				std::cin.ignore(10000,'\n');
				return false;
			}
			
			if(unos=='L')
			{
				while(std::cin.peek()==' ')unos=std::cin.get();
				if(std::cin.peek()!='\n')
				{
					greska=KodoviGresaka::SuvisanParametar;
					std::cin.ignore(10000,'\n');
					return false;
					
				}
				komanda=Komande::PomjeriJednoMjesto;
				smjer=Smjerovi::GoreLijevo;
				std::cin.ignore(10000,'\n');
				return true;
			}
			
			if(unos=='D')
			{
				while(std::cin.peek()==' ')unos=std::cin.get();
				if(std::cin.peek()!='\n')
				{
					greska=KodoviGresaka::SuvisanParametar;
					std::cin.ignore(10000,'\n');
					return false;
					
				}
				komanda=Komande::PomjeriJednoMjesto;
				smjer=Smjerovi::GoreDesno;
				std::cin.ignore(10000,'\n');
				return true;
			}
			
		}
		if(unos=='D' && std::cin.peek()!='\n' && std::cin.peek()!=' ')
		{
			unos=std::cin.get();
			if(unos!='o')
			{
				greska=KodoviGresaka::NeispravanParametar;
				std::cin.ignore(10000,'\n');
				return false;
			}
			if(std::cin.peek()=='\n' || std::cin.peek()==' ')
			{
				while(std::cin.peek()==' ')unos=std::cin.get();
				if(std::cin.peek()!='\n')
				{
					greska=KodoviGresaka::SuvisanParametar;
					std::cin.ignore(10000,'\n');
					return false;
					
				}
				komanda=Komande::PomjeriJednoMjesto;
				smjer=Smjerovi::Dolje;
				std::cin.ignore(10000,'\n');
				return true;
			}
			unos=std::cin.get();
			if(unos!='L' && unos!='D')
			{
				greska=KodoviGresaka::NeispravanParametar;
				std::cin.ignore(10000,'\n');
				return false;
			}
			
			if(unos=='L')
			{
				while(std::cin.peek()==' ')unos=std::cin.get();
				if(std::cin.peek()!='\n')
				{
					greska=KodoviGresaka::SuvisanParametar;
					std::cin.ignore(10000,'\n');
					return false;
					
				}
				komanda=Komande::PomjeriJednoMjesto;
				smjer=Smjerovi::DoljeLijevo;
				std::cin.ignore(10000,'\n');
				return true;
			}
			
			if(unos=='D')
			{
				while(std::cin.peek()==' ')unos=std::cin.get();
				if(std::cin.peek()!='\n')
				{
					greska=KodoviGresaka::SuvisanParametar;
					std::cin.ignore(10000,'\n');
					return false;
					
				}
				komanda=Komande::PomjeriJednoMjesto;
				smjer=Smjerovi::DoljeDesno;
				std::cin.ignore(10000,'\n');
				return true;
			}
			
		}
		
		
	}
	
	if(unos=='P' && std::cin.peek()=='>')
	{
		unos=std::cin.get();
		while(std::cin.peek()==' ')unos=std::cin.get();
		if(std::cin.peek()=='\n')
		{
			greska=KodoviGresaka::NedostajeParametar;
			std::cin.ignore(10000,'\n');
			return false;
		}
		if(!(std::cin.peek()>=48 && (std::cin.peek()<=57)))
		{
			greska=KodoviGresaka::NeispravanParametar;
			std::cin.ignore(10000,'\n');
			return false;
		}
		int a;
		std::cin>>a;
	/*	if(!(std::cin.peek()=='\n'))
		{
			greska=KodoviGresaka::NedostajeParametar;
			return false;
		}*/
		if(!(std::cin.peek()==' '))
		{
			greska=KodoviGresaka::NeispravanParametar;
			std::cin.ignore(10000,'\n');
			return false;
		}
		while(std::cin.peek()==' ')unos=std::cin.get();
		if(std::cin.peek()=='\n')
		{
			greska=KodoviGresaka::NedostajeParametar;
			std::cin.ignore(10000,'\n');
			return false;
		}
		int b;
		if(!(std::cin.peek()>=48 && (std::cin.peek()<=57)))
		{
			greska=KodoviGresaka::NeispravanParametar;
			std::cin.ignore(10000,'\n');
			return false;
		}
		std::cin>>b;
		while(std::cin.peek()==' ')unos=std::cin.get();
		if(!(std::cin.peek()==' ' || std::cin.peek()=='\n'))
		{
			greska=KodoviGresaka::SuvisanParametar;
			std::cin.ignore(10000,'\n');
			return false;
		}
		komanda=Komande::PomjeriDalje;
		x=a;
		y=b;
		std::cin.ignore(10000,'\n');
		return true;
		
	}
	
	if(unos=='B')
	{
		while(std::cin.peek()==' ')unos=std::cin.get();
		if(std::cin.peek()=='\n')
		{
			greska=KodoviGresaka::NedostajeParametar;
			std::cin.ignore(10000,'\n');
			return false;
		}
		if(!(std::cin.peek()>=48 && (std::cin.peek()<=57)))
		{
			greska=KodoviGresaka::NeispravanParametar;
			std::cin.ignore(10000,'\n');
			return false;
		}
		int a;
		std::cin>>a;
	/*	if(!(std::cin.peek()=='\n'))
		{
			greska=KodoviGresaka::NedostajeParametar;
			return false;
		}*/
		if(!(std::cin.peek()==' '))
		{
			greska=KodoviGresaka::NeispravanParametar;
			std::cin.ignore(10000,'\n');
			return false;
		}
		while(std::cin.peek()==' ')unos=std::cin.get();
		if(std::cin.peek()=='\n')
		{
			greska=KodoviGresaka::NedostajeParametar;
			std::cin.ignore(10000,'\n');
			return false;
		}
		int b;
		if(!(std::cin.peek()>=48 && (std::cin.peek()<=57)))
		{
			greska=KodoviGresaka::NeispravanParametar;
			std::cin.ignore(10000,'\n');
			return false;
		}
		std::cin>>b;
		while(std::cin.peek()==' ')unos=std::cin.get();
		if(!(std::cin.peek()==' ' || std::cin.peek()=='\n'))
		{
			greska=KodoviGresaka::SuvisanParametar;
			std::cin.ignore(10000,'\n');
			return false;
		}
		komanda=Komande::Blokiraj;
		x=a;
		y=b;
		std::cin.ignore(10000,'\n');
		return true;
		
	}
	
	
		if(unos=='D')
	{
		while(std::cin.peek()==' ')unos=std::cin.get();
		if(std::cin.peek()=='\n')
		{
			greska=KodoviGresaka::NedostajeParametar;
			std::cin.ignore(10000,'\n');
			return false;
		}
		if(!(std::cin.peek()>=48 && (std::cin.peek()<=57)))
		{
			greska=KodoviGresaka::NeispravanParametar;
			std::cin.ignore(10000,'\n');
			return false;
		}
		int a;
		std::cin>>a;
	/*	if(!(std::cin.peek()=='\n'))
		{
			greska=KodoviGresaka::NedostajeParametar;
			return false;
		}*/
		if(!(std::cin.peek()==' '))
		{
			greska=KodoviGresaka::NeispravanParametar;
			std::cin.ignore(10000,'\n');
			return false;
		}
		while(std::cin.peek()==' ')unos=std::cin.get();
		if(std::cin.peek()=='\n')
		{
			greska=KodoviGresaka::NedostajeParametar;
			std::cin.ignore(10000,'\n');
			return false;
		}
		int b;
		if(!(std::cin.peek()>=48 && (std::cin.peek()<=57)))
		{
			greska=KodoviGresaka::NeispravanParametar;
			std::cin.ignore(10000,'\n');
			return false;
		}
		std::cin>>b;
		if(!(std::cin.peek()==' ' || std::cin.peek()=='\n'))
		{
			greska=KodoviGresaka::SuvisanParametar;
			std::cin.ignore(10000,'\n');
			return false;
		}
		komanda=Komande::Deblokiraj;
		x=a;
		y=b;
		std::cin.ignore(10000,'\n');
		return true;
		
	}

	return false;
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0)
{
	if(komanda==Komande::Blokiraj)
	{
		BlokirajPolje(polja,p_x,p_y);
	}
	if(komanda==Komande::Deblokiraj)
	{
		DeblokirajPolje(polja,p_x,p_y);
	}
	if(komanda==Komande::ZavrsiIgru)
	{
		for(int i(0);i<polja.size();i++)
		{
			for(int j(0);j<polja.at(i).size();j++)
			{
				polja.at(i).at(j)=Polje::Prazno;
			}
		}
		throw std::runtime_error("Igra zavrsena");
	}
	if(komanda==Komande::PrikaziOkolinu)
	{
		std::vector<std::vector<int>>Matrica(PrikaziOkolinu(polja,x,y));
		for(int i(0);i<Matrica.size();i++)
		{
			for(int j(0);j<Matrica.at(i).size();j++)
			{
				std::cout<<Matrica.at(i).at(j)<<" ";
			}
			std::cout<<std::endl;
		}
	}
	if(komanda==Komande::PomjeriJednoMjesto)
	{
		Status idi(Idi(polja,x,y,p_smjer));
		if(idi==Status::KrajPobjeda)
		{
			std::cout<<"Bravo, obisli ste sva sigurna polja";
			for(int i(0);i<polja.size();i++)
		{
			for(int j(0);j<polja.at(i).size();j++)
			{
				polja.at(i).at(j)=Polje::Prazno;
			}
		}
		throw std::runtime_error("Igra zavrsena");
			
		}
		
		if(idi==Status::KrajPoraz)
		{
			std::cout<<"Nagazili ste na minu”";
			for(int i(0);i<polja.size();i++)
		{
			for(int j(0);j<polja.at(i).size();j++)
			{
				polja.at(i).at(j)=Polje::Prazno;
			}
		}
		throw std::runtime_error("Igra zavrsena");
			
		}
		
		if(idi==Status::NijeKraj)
		{
			std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
			
		}
	}
	if(komanda==Komande::PomjeriDalje)
	{
		Status idi(Idi(polja,x,y,p_x,p_y));
		if(idi==Status::KrajPobjeda)
		{
			std::cout<<"Bravo, obisli ste sva sigurna polja";
			for(int i(0);i<polja.size();i++)
		{
			for(int j(0);j<polja.at(i).size();j++)
			{
				polja.at(i).at(j)=Polje::Prazno;
			}
		}
		throw std::runtime_error("Igra zavrsena");
			
		}
		
		if(idi==Status::KrajPoraz)
		{
			std::cout<<"Nagazili ste na minu”";
			for(int i(0);i<polja.size();i++)
		{
			for(int j(0);j<polja.at(i).size();j++)
			{
				polja.at(i).at(j)=Polje::Prazno;
			}
		}
		throw std::runtime_error("Igra zavrsena");
			
		}
		
		if(idi==Status::NijeKraj)
		{
			std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
			
		}
	}
	if(komanda==Komande::KreirajIgru)
	{
		std::cout<<"Unesite broj polja: ";
		int broj;
		std::cin>>broj;
		while(!std::cin || std::cin.peek()!='\n' || broj<=0)
		{
			std::cout<<"Greska, unesite ponovo!"<<std::endl;
			std::cin.clear();
			std::cin.ignore(10000,'\n');
			std::cout<<"Unesite broj polja: ";
			std::cin>>broj;
		}
		std::vector<std::vector<int>>mine;
		std::cout<<"Unesite pozicije mina: ";
		int j(0);
		char unos;
		std::cin>>unos;
		start:

		while(unos!='.')
		{
			if(unos!=' ' && unos!='(')
			{
				std::cout<<"Greska, unesite ponovo!"<<std::endl;
				std::cin.clear();
				std::cin.ignore(10000,'\n');
				std::cin>>unos;
				goto start;
			}
			
			if(unos==' ')
			{
				while(std::cin.peek()==' ')unos=std::cin.get();
				if(std::cin.peek()!='(')
				{
					std::cout<<"Greska, unesite ponovo!"<<std::endl;
					std::cin.clear();
					std::cin.ignore(10000,'\n');
					std::cin>>unos;
					goto start;
				}
				unos=std::cin.get();
			}
			
			while(std::cin.peek()==' ')unos=std::cin.get();
			if(!(std::cin.peek()>=48 && (std::cin.peek()<=57)))
			{
				std::cout<<"Greska, unesite ponovo!"<<std::endl;
				std::cin.clear();
				std::cin.ignore(10000,'\n');
				std::cin>>unos;
				goto start;
			}
			int broj1;
			std::cin>>broj1;
			
			if(broj1<0 || broj1>=broj)
			{
				std::cout<<"Greska, unesite ponovo!"<<std::endl;
				std::cin.clear();
				std::cin.ignore(10000,'\n');
				std::cin>>unos;
				goto start;
			}
			
			if(std::cin.peek()!=',' && std::cin.peek()!=' ')
			{
				std::cout<<"Greska, unesite ponovo!"<<std::endl;
				std::cin.clear();
				std::cin.ignore(10000,'\n');
				std::cin>>unos;
				goto start;
			}
			while(std::cin.peek()==' ')unos=std::cin.get();
			if(std::cin.peek()!=',')
			{
				std::cout<<"Greska, unesite ponovo!"<<std::endl;
				std::cin.clear();
				std::cin.ignore(10000,'\n');
				std::cin>>unos;
				goto start;
			}
			unos=std::cin.get();
		
			while(std::cin.peek()==' ')unos=std::cin.get();
			if(!(std::cin.peek()>=48 && (std::cin.peek()<=57)))
			{
				std::cout<<"Greska, unesite ponovo!"<<std::endl;
				std::cin.clear();
				std::cin.ignore(10000,'\n');
				std::cin>>unos;
				goto start;
			}
			int broj2;
			std::cin>>broj2;
			if(broj2<0 || broj2>=broj)
			{
				std::cout<<"Greska, unesite ponovo!"<<std::endl;
				std::cin.clear();
				std::cin.ignore(10000,'\n');
				std::cin>>unos;
				goto start;
			}
			
			if(std::cin.peek()!=')' && std::cin.peek()!=' ')
			{
				std::cout<<"Greska, unesite ponovo!"<<std::endl;
				std::cin.clear();
				std::cin.ignore(10000,'\n');
				std::cin>>unos;
				goto start;
			}
			
			while(std::cin.peek()==' ')unos=std::cin.get();
			if(std::cin.peek()!=')')
			{
				std::cout<<"Greska, unesite ponovo!"<<std::endl;
				std::cin.clear();
				std::cin.ignore(10000,'\n');
				std::cin>>unos;
				goto start;
			}
			unos=std::cin.get();
			while(std::cin.peek()==' ')unos=std::cin.get();
			if(std::cin.peek()!='\n')
			{
				std::cout<<"Greska, unesite ponovo!"<<std::endl;
				std::cin.clear();
				std::cin.ignore(10000,'\n');
				std::cin>>unos;
				goto start;
			}
			
			mine.resize(mine.size()+1);
			mine.at(j).push_back(broj1);
			mine.at(j).push_back(broj2);
			j++;
			std::cin>>unos;
		}
		
		polja=KreirajIgru(broj,mine);
	}
}


int main ()
{
	Tabla polja;
	int x,y,p_x(0), p_y(0);
	Smjerovi smjer;
	KodoviGresaka greske;
	Komande K;
	
	try
	{
		
		while(true)
		{
			try{
			std::cout<<"Unesite komandu: ";
			if(UnosKomande(K,smjer,x,y,greske))IzvrsiKomandu(K,polja,p_x,p_y,smjer,x,y);
			else PrijaviGresku(greske);}
			
			catch(std::domain_error Izuzetak)
	{
		std::cout<<Izuzetak.what()<<std::endl;
	}
	catch(std::out_of_range Izuzetak)
	{
		std::cout<<Izuzetak.what()<<std::endl;
	}
	catch(std::logic_error Izuzetak)
	{
		std::cout<<Izuzetak.what()<<std::endl;
	}
			
		}
		
	}
	
	catch(std::runtime_error Izuzetak)
	{
		std::cout<<"Dovidjenja!";
		return 0;
		
	}
	
	
}

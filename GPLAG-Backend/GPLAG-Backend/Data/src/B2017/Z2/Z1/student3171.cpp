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
#include <stdexcept>
#include <vector>
#include <new>
#include <string>
#include <algorithm>
#include <complex>

enum class Polje
{
    Prazno=0, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};
enum class Smjerovi
{
    GoreLijevo=0, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};
enum class Status
{
    NijeKraj=0, KrajPoraz, KrajPobjeda
};
enum class KodoviGresaka
{
    PogresnaKomanda=0, NedostajeParametar, SuvisanParametar, NeispravanParametar
};
enum class Komande
{
    PomjeriJednoMjesto=0, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu,
    ZavrsiIgru, KreirajIgru
};

int string_to_int(std::string s);

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine);

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y);

void BlokirajPolje(Tabla &polja, int x, int y);

void DeblokirajPolje(Tabla &polja, int x, int y);

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer);

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y);

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska);

void IzvrsiKomandu(Komande komanda, Tabla &polja, int&, int&,
                   Smjerovi , int, int );

void PrijaviGresku(KodoviGresaka greska);

int main ()
{
	Tabla test {};
	Komande komanda;
	Smjerovi smjer;
	int x=0,y=0,px=0,py=0;
	KodoviGresaka greska;
//	std::cout<<int('.');
	try{
	for(;;)
	{
		std::cout<<"Unesite komandu: ";
		try{if(UnosKomande(komanda,smjer,px,py,greska))
		{
			IzvrsiKomandu(komanda,test,x,y,smjer,px,py );
		}
		else
		{
			PrijaviGresku(greska);
		}
		}
		catch(std::domain_error izuzetak)
		{
			std::cout<<izuzetak.what()<<"\n";
		}
	
		
	}
	}
	catch(std::runtime_error kraj)
	{
		std::cout<<"Dovidjenja!";
	}

	return 0;
}

int string_to_int(std::string s)
{
	int i=0;
	int result {0};
	while(i<s.length() && (s[i]>='0'&& s[i]<='9' ))
	{
		result*=10;
		result+=s[i]-'0';
		i++;
	}
	return result;
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y,
                   Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0)
{

	if(komanda==Komande::PrikaziOkolinu)
	{
		auto result(PrikaziOkolinu(polja,x,y));
		for(auto red: result)
		{
			for(auto kolona : red)
				std::cout<<kolona<<" ";
		}
		std::cout<<std::endl;
	}
	else if(komanda==Komande::PomjeriDalje)
	{
		Status next=Idi(polja,x,y,p_x,p_y);
		std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")";
		if(next==Status::KrajPoraz)
		{
			std::cout<<"Nagazili ste na minu";
			for(auto &red:polja)
				for(auto &kolona:red)
					kolona=Polje::Prazno;
			throw std::runtime_error("Igra zavrsena");
		}
		else if(next==Status::KrajPobjeda)
		{
			std::cout<<"Bravo, obisli ste sva sigurna polja";
			for(auto &red:polja)
				for(auto &kolona:red)
					kolona=Polje::Prazno;
			throw std::runtime_error("Igra zavrsena");
		}
	}
	else if(komanda==Komande::ZavrsiIgru)
	{
		for(auto &red : polja)
			for(auto &kolona : red)
				kolona=Polje::Prazno;
		throw std::runtime_error("Igra zavrsena");
	}
	else if(komanda== Komande::Blokiraj)
	{
		BlokirajPolje(polja,x,y);
	}
	else if(komanda==Komande::Deblokiraj)
	{
		DeblokirajPolje(polja,x,y);
	}
	else if(komanda==Komande::PomjeriJednoMjesto)
	{
		Status next(Idi(polja,x,y,p_smjer));
		std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")";
		if(next==Status::KrajPoraz)
		{
			std::cout<<"Nagazili ste na minu";
			for(auto &red:polja)
				for(auto &kolona:red)
					kolona=Polje::Prazno;
			throw std::runtime_error("Igra zavrsena");
		}
		else if(next == Status::KrajPobjeda)
		{
			std::cout<<"Bravo, obisli ste sva sigurna polja";
			for(auto &red:polja)
				for(auto &kolona:red)
					kolona=Polje::Prazno;
			throw std::runtime_error("Igra zavrsena");
		}
	}
	else if(komanda==Komande::KreirajIgru)
	{
		int broj_polja(0);
		for(;;)
		{
			std::cout<<"Unesite broj polja: ";
			std::cin>>broj_polja;
			if(std::cin && std::cin.peek()=='\n')break;
			std::cout<<"Greska, unesite ponovo!";
			std::cin.clear();
			std::cin.ignore(1000,'\n');
		}
		std::complex<int> polje;
		std::cout<<"Unesite pozicije mina: ";
		std::vector<std::vector<int>> mine;
		std::vector<int> jedna_mina(2,0);
		try
		{
			for(;;)
			{
				for(;;)
				{
					std::cin>>polje;
					int p(0);
					std::cin.clear();
					if((p=std::cin.peek())==46)throw 0;
				//	std::cout<<p;
					if(std::cin && polje.real()>=0 && polje.imag()>=0 && polje.real()<=broj_polja && polje.imag()<=broj_polja && (polje.real()!=0 || polje.imag()!=0 ) && std::cin.peek()=='\n')break;
					std::cout<<"Greska, unesite ponovo!";
					std::cin.clear();
					std::cin.ignore(1000,'\n');
				}
				jedna_mina[0]=polje.real();
				jedna_mina[1]=polje.imag();
				mine.push_back(jedna_mina);
			}
		}
		catch(int a)
		{
		std::cin.clear();
		std::cin.ignore(1000,'\n');
		}

		polja=KreirajIgru(broj_polja,mine);

	}

}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska)
{
	std::string input {};


	std::getline(std::cin,input);

	for(int i=1; i<input.length(); i++)
	{
		if(input[i-1]==input[i] && input[i]==' ')input.erase(input.begin()+i);
	}
	if(input[0]==' ')input.erase(input.begin());
	if(input[input.length()-1]==' ')input.erase(input.end()-1);
	std::string part[4] {};
	int k {0};
	bool neslovo(true);
	for(int i=0; i<input.length(); i++)
	{
		if(input[i]==' ')
		{
			if(!neslovo)k++;

			neslovo=true;
		}
		else
		{
			if(k==4)
			{
				break;
			}
			part[k]+=input[i];
			neslovo=false;
		}
	}
//	for(auto x:part)std::cout<<x<<" ";
//	std::cout<<"\n";
	const std::string zero[7] {"P1","P>","B","D","PO","Z","K"};
	const std::string first[8] {"GL","G","GD","D","DoD","Do","DoL","L"};
//if(part[0]==zero[6])std::cout<<" jest";
	for(int i=0; i<7; i++)
	{
		if(zero[i]==part[0])break;
		if(i==6)
		{
			greska=KodoviGresaka::PogresnaKomanda;
			return false;
		}
	}
	if(part[0]==zero[0])
	{
		int x;
		for(int i=0; i<8; i++)
		{
			if(part[1]==first[i])
			{
				x=i;
				break;
			}
			if(i==7)
			{
				if(part[1]=="")
				{
					greska=KodoviGresaka::NedostajeParametar;
					return false;
				}
				else
				{
					greska=KodoviGresaka::NeispravanParametar;
					return false;
				}
			}
		}
		if(part[2]=="")
		{
			komanda=Komande::PomjeriJednoMjesto;
			smjer=Smjerovi(x);
			return true;
		}
		else
		{
			greska=KodoviGresaka::SuvisanParametar;
			return false;
		}

	}
	for(int i=1; i<4; i++)
	{
		if(zero[i]==part[0])
		{
			if(std::to_string( string_to_int(part[1]))==part[1])
			{
				if(std::to_string( string_to_int(part[2]))==part[2])
				{
					if(part[3]=="")
					{
						komanda=Komande(i);
						x=string_to_int(part[1]);
						y=string_to_int(part[2]);
						return true;
					}
					else
					{
						greska=KodoviGresaka::SuvisanParametar;
						return false;
					}
				}
				else if(part[2]=="")
				{
					greska=KodoviGresaka::NedostajeParametar;
					return false;
				}
				else
				{
					greska=KodoviGresaka::NeispravanParametar;
					return false;
				}
			}
			else if(part[1]=="")
			{
				greska=KodoviGresaka::NedostajeParametar;
				return false;
			}
			else
			{
				greska=KodoviGresaka::NeispravanParametar;
				return false;
			}
		}

	}
	for(int i=4; i<7; i++)
	{
		if(part[0]==zero[i])
		{
			if(part[1]=="")
			{
				komanda=Komande(i);
				return true;
			}
			else
			{
				greska=KodoviGresaka::SuvisanParametar;
				return false;
			}
		}
		
	}
	
			greska=KodoviGresaka::PogresnaKomanda;
			return false;
	
}

void PrijaviGresku(KodoviGresaka greska)
{
	if(static_cast<int>(greska) > 3  || static_cast<int>(greska) <0)throw std::logic_error("Greska ne postoji!");
	std::string niz[4] {"Nerazumljiva komanda!\n","Komanda trazi parametar koji nije naveden!\n","Zadan je suvisan parametar nakon komande!\n","Parametar komande nije ispravan!\n"};
	std::cout<<niz[static_cast<int>(greska)];
}

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine)
{
	if (n<1)throw std::domain_error("Ilegalna velicina");
	Tabla temp(n,std::vector<Polje>(n,Polje::Prazno));

	for(int i=0; i<mine.size(); i++)
	{
		if(mine.at(i).size() != 2)throw std::domain_error("Ilegalan format zadavanja mina");
		if(mine.at(i).at(0) > n-1 || mine.at(i).at(1) > n-1 || mine.at(i).at(0) < 0 || mine.at(i).at(1) < 0)throw std::domain_error("Ilegalne pozicije mina");
		temp.at(mine.at(i).at(0)).at(mine.at(i).at(1)) = Polje::Mina;
	}
	return temp;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y)
{
	if( x < 0 || y < 0 || x >= polja.size() || y >= polja.size() )
		throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");

	std::vector<std::vector<int>> result(3,std::vector<int>(3,0));

	for(int i = x-1; i < x+2; i++ )
	{
		for(int j = y-1; j < y+2; j++)
		{
			if(j < 0 || i < 0 || j >= polja.size() || i >= polja.size())continue;
			int brojac {0};
			for(int k = i-1; k < i+2; k++ )
			{
				for(int q = j-1; q < j+2; q++)
				{
					if( k < 0 || q < 0 || k >= polja.size() || q >= polja.size() )continue;
					if(polja.at(k).at(q) == Polje::Mina)brojac++;
					if(polja.at(i).at(j) == Polje::Mina && i == k && j == q)brojac--;
				}
			}
			result.at( i-(x-1) ).at( j-(y-1) ) = brojac;
		}
	}
	return result;
}

void BlokirajPolje( Tabla &polja, int x, int y)
{
	if( x < 0 || y < 0 || x >= polja.size() || y >= polja.size() )
		throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	if(polja.at(x).at(y) < Polje(3) )polja.at(x).at(y)=Polje( static_cast<int>(polja.at(x).at(y) ) + 3);
}

void DeblokirajPolje( Tabla &polja, int x, int y)
{
	if( x < 0 || y < 0 || x >= polja.size() || y >= polja.size() )
		throw std::domain_error("Polje (" + std::to_string(x) + "," + std::to_string(y) +") ne postoji");
	if(polja.at(x).at(y) > Polje(2) ) polja.at(x).at(y) = Polje( static_cast<int>(polja.at(x).at(y)) -3);
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer )
{
	int where[8][2] { {x-1,y-1},{x-1,y},{x-1,y+1},{x,y+1},{x+1,y+1},{x+1,y},{x+1,y-1},{x,y-1} };
	int red { where[static_cast<int>(smjer)][0] },kolona { where[static_cast<int>(smjer)][1]};
	if(red < 0 || kolona < 0 || red >= polja.size() || kolona >= polja.size() )
		throw std::out_of_range("Izlazak van igrace table");
	if( static_cast<int>(polja.at(red).at( kolona ) ) > 2)
		throw std::logic_error("Blokirano polje");

	if (polja.at(red).at(kolona) == Polje::Mina)
	{
		for(auto &vanjski : polja)
		{
			for(auto &unutrasnji : vanjski)
			{
				unutrasnji = Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
	polja.at(x).at(y) = Polje::Posjeceno;
	if(polja.at(red).at(kolona) == Polje::Prazno)
	{
		int broj_praznih {0};
		for(auto vanjski : polja)
		{
			for(auto unutrasnji : vanjski)
			{
				if(unutrasnji == Polje::Prazno)broj_praznih++;
			}
		}
		if(broj_praznih<2)
			return Status::KrajPobjeda;
	}
	x=red;
	y=kolona;
	return Status::NijeKraj;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y)
{
	if(novi_x < 0 || novi_y < 0 || novi_x >= polja.size() || novi_y >= polja.size() )
		throw std::out_of_range("Izlazak van igrace table");
	if( static_cast<int>(polja.at(novi_x).at(novi_y)) > 2  )
		throw std::logic_error("Blokirano polje");
	if(polja.at(novi_x).at(novi_y) == Polje::Mina )
	{
		for( auto &red : polja)
		{
			for(auto &kolona : red)
			{
				kolona = Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
	polja.at(x).at(y) = Polje::Posjeceno;
	if(polja.at(novi_x).at(novi_y) == Polje::Prazno)
	{
		int broj_praznih {0};
		for(auto red : polja)
		{
			for(auto kolona : red)
			{
				if(kolona == Polje::Prazno)
				{
					broj_praznih++;
				}
			}
		}
		if(broj_praznih < 2)return Status::KrajPobjeda;
	}
	x=novi_x;
	y=novi_y;
	return Status::NijeKraj;
}
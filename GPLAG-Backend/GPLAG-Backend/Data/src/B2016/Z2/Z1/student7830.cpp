/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <stdio.h>

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
	
	//Provjera broja elemenata u mine
	for(int i = 0; i < mine.size(); i++)
		if(mine[i].size() != 2)
			throw std::domain_error("Ilegalan format zadavanja mina");
	
	//Provjera pozicija mina		
	for(int i = 0; i < mine.size(); i++)
		for(int j = 0; j < mine[i].size(); j++)
			if(mine[i][j] > n || mine[i][j] < 0)
				throw std::domain_error("Ilegalne pozicije mina");
	
	//Kreiranje Table
	Tabla tab(n, std::vector<Polje>(n, Polje::Prazno));
	
	//Oznacavanje Mina
	for(int i = 0; i < mine.size(); i++)
	{
		tab[mine[i][0]][mine[i][1]] = Polje::Mina;
	}
	std::cin.ignore(10000, '\n');
	return tab;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y)
{
	if(x > polja.size() || y > polja[0].size() || x < 0 || y < 0)
	{
		std::cout<<"Polje ("<<x<<","<<y<<") ";
		throw std::domain_error("ne postoji");
	}
	std::vector<std::vector<int>> okolina(3, std::vector<int>(3));
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			okolina[i][j] = 0;
	
	for(int i = x-1; i <= x+1; i++)
		for(int j = y-1; j <= y+1; j++)
		{
			if(i >= 0 && j >= 0 && i < polja.size() && j < polja.size())
			{
				if(i-1 >= 0 && j-1 >= 0)
				{
					if(polja[i-1][j-1] == Polje::Mina)
						okolina[i-x+1][j-y+1]++;
				}
				
				if(i-1 >= 0)
				{
					if(polja[i-1][j] == Polje::Mina)
						okolina[i-x+1][j-y+1]++;	
				}
					
				if(j-1 >= 0)
				{
					if(polja[i][j-1] == Polje::Mina)
						okolina[i-x+1][j-y+1]++;
				}
				
				if(i+1 < polja.size() && j-1 >= 0)
				{
					if(polja[i+1][j-1] == Polje::Mina)
							okolina[i-x+1][j-y+1]++;
				}
				
				if(i+1 < polja.size())
				{
					if(polja[i+1][j] == Polje::Mina)
							okolina[i-x+1][j-y+1]++;
				}
				
				if(i+1 < polja.size() && j+1 < polja.size())
				{
					if(polja[i+1][j+1] == Polje::Mina)
							okolina[i-x+1][j-y+1]++;
				}
				
				if(j+1 < polja.size())
				{
					if(polja[i][j+1] == Polje::Mina)
							okolina[i-x+1][j-y+1]++;
				}
				
				if(i-1 >= 0 && j+1 < polja.size())
				{
					if(polja[i-1][j+1] == Polje::Mina)
							okolina[i-x+1][j-y+1]++;
				}
			}
		}
		return okolina;
}

void BlokirajPolje(Tabla &polja, int x, int y)
{
	if(x > polja.size() || y > polja[0].size() || x < 0 || y < 0)
	{
		std::cout<<"Polje ("<<x<<","<<y<<") ";
		throw std::domain_error("ne postoji");
	}
	if(polja[x][y] == Polje::Prazno)
		polja[x][y] = Polje::BlokiranoPrazno;
	if(polja[x][y] == Polje::Posjeceno)
		polja[x][y] = Polje::BlokiranoPosjeceno;
	if(polja[x][y] == Polje::Mina)
		polja[x][y] = Polje::BlokiranoMina;
}

void DeblokirajPolje(Tabla &polja, int x, int y)
{
	if(x > polja.size() || y > polja[0].size() || x < 0 || y < 0)
	{
		std::cout<<"Polje ("<<x<<","<<y<<") ";
		throw std::domain_error("ne postoji");
	}
	if(polja[x][y] == Polje::BlokiranoPrazno)
		polja[x][y] = Polje::Prazno;
	if(polja[x][y] == Polje::BlokiranoPosjeceno)
		polja[x][y] = Polje::Posjeceno;
	if(polja[x][y] == Polje::BlokiranoMina)
		polja[x][y] = Polje::Mina;
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer)
{
	Status status(Status::KrajPobjeda);
	polja[x][y] = Polje::Posjeceno;
	int nx(0), ny(0);
	if(smjer == Smjerovi::GoreLijevo)
	{
		nx -= 1;
		ny -= 1;
	}
	else if(smjer == Smjerovi::Gore)
		nx -= 1;
	else if(smjer == Smjerovi::GoreDesno)
	{
		nx -= 1;
		ny += 1;
	}
	else if(smjer == Smjerovi::Desno)
		ny += 1;
	else if(smjer == Smjerovi::DoljeDesno)
	{
		nx += 1;
		ny += 1;
	}
	else if(smjer == Smjerovi::Dolje)
		nx += 1;
	else if(smjer == Smjerovi::DoljeLijevo)
	{
		nx += 1;
		ny -= 1;
	}
	else if(smjer == Smjerovi::Lijevo)
		ny -= 1;
	
	if(x + nx < 0 || y + ny < 0 || x + nx > polja.size()-1 || y + ny > polja.size()-1)
	{
		throw std::out_of_range("Izlazak van igrace table");
	}
	if(polja[x + nx][y + ny] == Polje::BlokiranoPrazno || polja[x + nx][y + ny] == Polje::BlokiranoMina || polja[x + nx][y + ny] == Polje::BlokiranoPosjeceno)
	{
		throw std::logic_error("Blokirano polje");
	}
	x += nx;
	y += ny;
	for(int i = 0; i < polja.size(); i++)
		for(int j = 0; j < polja[i].size(); j++)
			if(polja[i][j] == Polje::Prazno)
			{
				status = Status::NijeKraj;
				break;
			}
	if(polja[x][y] == Polje::Mina)
	{
		status = Status::KrajPoraz;
		for(int i = 0; i < polja.size(); i++)
			for(int j = 0; j < polja[i].size(); j++)
				polja[i][j] = Polje::Prazno;
	}
	return status;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y)
{
	if(novi_x > polja.size() || novi_y > polja[0].size() || novi_x < 0 || novi_y < 0)
		throw std::out_of_range("Izlazak van igrace table");
	if(polja[novi_x][novi_y] == Polje::BlokiranoPosjeceno || polja[novi_x][novi_y] == Polje::BlokiranoPrazno || polja[novi_x][novi_y] == Polje::BlokiranoMina)
		throw std::logic_error("Blokirano polje");
	Status status(Status::KrajPobjeda);
	polja[x][y] = Polje::Posjeceno;
	x = novi_x;
	y = novi_y;
	for(int i = 0; i < polja.size(); i++)
		for(int j = 0; j < polja[i].size(); j++)
			if(polja[i][j] == Polje::Prazno)
			{
				status = Status::NijeKraj;
				break;
			}
	if(polja[x][y] == Polje::Mina)
		status = Status::KrajPoraz;
	return status;	
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska)
{
	char s;
	s = std::cin.get();
	if(s == 10)
		s = std::cin.get();
	if(s == 'K')
		komanda = Komande::KreirajIgru;
	else if(s == 'Z')
		komanda = Komande::ZavrsiIgru;
	else if(s == 'P')
	{
		char s1(std::cin.get());
		if(s1 == 'O')
			komanda = Komande::PrikaziOkolinu;
		else if(s1 == '>')
		{
			komanda = Komande::PomjeriDalje;
			char k(107);
			std::cin>>x>>y;
			if(!std::cin)
			{
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				greska = KodoviGresaka::NeispravanParametar;
				return false;
			}
			k = std::cin.get();
			if(k != 107 && k != 10)
			{
				greska = KodoviGresaka::SuvisanParametar;
				return false;
			}
		}
		
		else if(s1 == '1')
		{
			komanda = Komande::PomjeriJednoMjesto;
			std::string st;
			std::getline(std::cin, st);
			for(int i = 0; i < st.size(); i++)
				if(st[i] == ' ')
					st.erase(st.begin() + i);
			if(st != "GD" && st != "GL" && st != "G" && st != "D" && st != "DoD" && st != "Do" && st != "DoL" && st != "L")
				greska = KodoviGresaka::NeispravanParametar;
			else
			{
				if(st == "GD")
					smjer = Smjerovi::GoreDesno;
				if(st == "GL")
					smjer = Smjerovi::GoreLijevo;
				if(st == "G")
					smjer = Smjerovi::Gore;
				if(st == "D")
					smjer = Smjerovi::Desno;
				if(st == "DoD")
					smjer = Smjerovi::DoljeDesno;
				if(st == "Do")
					smjer = Smjerovi::Dolje;
				if(st == "DoL")
					smjer = Smjerovi::DoljeLijevo;
				if(st == "L")
					smjer = Smjerovi::Lijevo;
			}
		}
		
		else
		{
			greska = KodoviGresaka::PogresnaKomanda;
			return false;
		}
	
	}
	
	else if(s == 'B')
	{
		komanda = Komande::Blokiraj;
		char k(107);
		std::cin>>x>>y;
		if(!std::cin)
		{
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			greska = KodoviGresaka::NedostajeParametar;
			return false;
		}
		k = std::cin.get();
		if(k != 107 && k != 10)
		{
			std::cout<<k;
			std::cout<<(int)k;
			greska = KodoviGresaka::SuvisanParametar;
			return false;
		}
	}
	
	else if(s == 'D')
	{
		komanda = Komande::Deblokiraj;
		char k(107);
		std::cin>>x>>y;
		if(!std::cin)
		{
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			greska = KodoviGresaka::NedostajeParametar;
			return false;
		}
		k = std::cin.get();
		if(k != 107 && k != 10)
		{
			std::cout<<k;
			greska = KodoviGresaka::SuvisanParametar;
			return false;
		}
	}
	
	else
	{
		greska = KodoviGresaka::PogresnaKomanda;
		return false;
	}
	return true;
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0)
{
	if(komanda == Komande::KreirajIgru)
	{
		std::cout<<"Unesite broj polja: ";
		int n, k(0); 
		std::cin>>n;
		std::cout<<"Unesite pozicije mina: ";
		std::vector<std::vector<int>> mine;
		while(std::cin.get() != '\n');
		for(;;)
		{
			int x(100), y(100);
			scanf("(%d,%d)", &x, &y);
			if(std::cin.get() == '.')
				break;
			if(x == 100 || y == 100)
			{
				std::cout<<"Greska, unesite ponovo!"<<std::endl;
				while(std::cin.get() != '\n');
				continue;	
			}
			if(x > n-1 || y > n-1 || x < 0 || y < 0)
			{
				std::cout<<"Greska, unesite ponovo!"<<std::endl;
				continue;
			}
			mine.push_back(std::vector<int>(2));
			mine[k][0] = x;
			mine[k][1] = y;
			k++;
		}
		polja = KreirajIgru(n, mine);
	}
	
	if(komanda == Komande::ZavrsiIgru)
	{
		for(int i = 0; i < polja.size(); i++)
			for(int j = 0; j < polja[i].size(); j++)
				polja[i][j] = Polje::Prazno;
		throw std::runtime_error("Igra zavrsena");
	}
	
	if(komanda == Komande::PomjeriJednoMjesto)
	{
			Status status;
			status = Idi(polja, x, y, p_smjer);
			std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
			if(status != Status::NijeKraj)
				throw std::runtime_error("Igra zavrsena");
	}
	
	if(komanda == Komande::PomjeriDalje)
	{
		try{
			Status status;
			status = Idi(polja, x, y, p_x, p_y);
			std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
			if(status != Status::NijeKraj)
				throw std::runtime_error("Igra zavrsena");
		}
		catch(std::logic_error y)
		{
			std::cout<<y.what()<<std::endl;
		}
	}
	
	if(komanda == Komande::Blokiraj)
	{
		BlokirajPolje(polja, p_x, p_y);
	}
	
	if(komanda == Komande::Deblokiraj)
	{
		DeblokirajPolje(polja, p_x, p_y);
	}
	
	if(komanda == Komande::PrikaziOkolinu)
	{
		std::vector<std::vector<int>> okolina(PrikaziOkolinu(polja, x, y));
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
				std::cout<<okolina[i][j]<<" ";
			std::cout<<std::endl;
		}
	}
	
}

void PrijaviGresku(KodoviGresaka greska)
{
	if(greska == KodoviGresaka::PogresnaKomanda)
		std::cout<<"Nerazumljiva komanda!"<<std::endl;
	if(greska == KodoviGresaka::NedostajeParametar)
		std::cout<<"Komanda trazi parametar koji nije naveden!"<<std::endl;
	if(greska == KodoviGresaka::NeispravanParametar)
		std::cout<<"Parametar komande nije ispravan!"<<std::endl;
	if(greska == KodoviGresaka::SuvisanParametar)
		std::cout<<"Zadan je suvisan parametar nakon komande!"<<std::endl;
}

int main ()
{
	try{
	Komande komanda;
	Smjerovi smjer;
	int x(0), y(0);
	int px(0), py(0);
	KodoviGresaka greska;
	Status status(Status::NijeKraj);
	Tabla polja;
	while(status != Status::KrajPoraz && status != Status::KrajPobjeda)
	{
		std::cout<<"Unesite komandu: ";
		bool kom(UnosKomande(komanda, smjer, px, py, greska));
		if(kom)
			IzvrsiKomandu(komanda, polja, x, y, smjer, px, py);
		if(!kom)
			PrijaviGresku(greska);
	}
	return 0;
	}
	catch(std::domain_error x)
	{
		std::cout<<x.what();
	}
	catch(std::runtime_error x)
	{
		std::cout<<"Dovidjenja!";
	}
	catch(std::logic_error x)
	{
		std::cout<<x.what();
	}
	catch(std::out_of_range x)
	{
		std::cout<<x.what();
	}
}
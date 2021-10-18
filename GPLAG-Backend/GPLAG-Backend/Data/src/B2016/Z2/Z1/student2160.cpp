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

enum class Status
{
	NijeKraj, KrajPoraz, KrajPobjeda
};

enum class Smjerovi
{
	GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};

enum class KodoviGresaka
{
	PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};

enum class Komande
{
	PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};

typedef std::vector<std::vector<Polje>> Tabla;
typedef std::vector<std::vector<int>> Matrica;

Tabla KreirajIgru (int n, const Matrica &mine)
{
	Tabla mat (n, std::vector<Polje> (n, Polje::Prazno));
	
	for(int i = 0; i < mine.size(); i++)
		if(mine.at(i).size() != 2)
			throw std::domain_error("Ilegalan format zadavanja mina");
			
	for(int i = 0; i < mine.size(); i++)
		for(int j = 0; j < mine.at(i).size(); j++)
			if(mine.at(i).at(j) >= mat.size() || mine.at(i).at(j) < 0)
				throw std::domain_error("Ilegalne pozicije mina");
			
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			for(int k = 0; k < mine.size(); k++)
				if(i == mine.at(k).at(0) && j == mine.at(k).at(1))
					mat.at(i).at(j) = Polje::Mina;
				
	return mat;
}

Matrica PrikaziOkolinu(const Tabla &polja, int x, int y)
{
	Matrica mat;
	int br(0);
	std::vector<int> vek;
	
	if(x < 0 || y < 0 || x > polja.size() - 1 || y > polja.size() - 1)
		throw std::domain_error("Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji");
		
	for(int i = x - 1; i <= x + 1; i++)
	{
		vek.clear();
		for(int j = y - 1; j <= y + 1; j++)
		{
			br = 0;
			for(int k = i - 1; k <= i + 1; k++)
			{
				for(int s = j - 1; s <= j + 1; s++)
				{
					if((k == i && s == j) || k < 0 || s < 0 || k >= polja.size() || s >= polja.size())
						continue;
							
					if(polja.at(k).at(s) == Polje::Mina)
						br++;
				}
			}
			vek.push_back(br);
		}
		mat.push_back(vek);
	}
	return mat;
}

void BlokirajPolje (Tabla &polja, int x, int y)
{
	if(x < 0 || y < 0 || x >= polja.size() || y >= polja.size())
		throw std::domain_error("Polje (" + std::to_string(x) + "," + std::to_string(y) +") ne postoji");
		
	if(polja.at(x).at(y) == Polje::Prazno)
		polja.at(x).at(y) = Polje::BlokiranoPrazno;
		
	else if(polja.at(x).at(y) == Polje::Mina)
		polja.at(x).at(y) = Polje::BlokiranoMina;
		
	else if(polja.at(x).at(y) == Polje::Posjeceno)
		polja.at(x).at(y) = Polje::BlokiranoPosjeceno;
}

void DeblokirajPolje (Tabla &polja, int x, int y)
{
	if(x < 0 || y < 0 || x >= polja.size() || y >= polja.size())
		throw std::domain_error("Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji");
		
	if(polja.at(x).at(y) == Polje::BlokiranoPrazno)
		polja.at(x).at(y) = Polje::Prazno;
		
	else if(polja.at(x).at(y) == Polje::BlokiranoMina)
		polja.at(x).at(y) = Polje::Mina;
		
	else if(polja.at(x).at(y) == Polje::BlokiranoPosjeceno)
		polja.at(x).at(y) = Polje::Posjeceno;
}

Status Idi (Tabla &polja, int &x, int &y, int novi_x, int novi_y)
{
	if(novi_x < 0 || novi_x >= polja.size() || novi_y < 0 || novi_y >= polja.size())
		throw std::out_of_range("Izlazak van igrace table");
		
	else if(polja.at(novi_x).at(novi_y) == Polje::BlokiranoPosjeceno 
	|| polja.at(novi_x).at(novi_y) == Polje::BlokiranoPrazno
	|| polja.at(novi_x).at(novi_y) == Polje::BlokiranoMina)
		throw std::logic_error("Blokirano polje");
		
	else
	{
		x = novi_x, y = novi_y;
		
		if(polja.at(x).at(y) == Polje::Mina)
		{
			for(int i = 0; i < polja.size(); i++)
				for(int j = 0; j < polja.at(i).size(); j++)
					polja.at(i).at(j) = Polje::Prazno;
					
			return Status::KrajPoraz;
		}
		
		int prazno = 0;
		
		for(int i = 0; i < polja.size(); i++)
			for(int j = 0; j < polja.at(i).size(); j++)
				if(polja.at(i).at(j) == Polje::Prazno)
					prazno++;
					
		if(prazno == 0)
			return Status::KrajPobjeda;
			
		return Status::NijeKraj;
	}
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer)
{
	if(smjer == Smjerovi::GoreLijevo)
		return Idi(polja, x, y, x - 1, y - 1);
		
	else if(smjer == Smjerovi::Gore)
		return Idi(polja, x, y, x - 1, y);
		
	else if(smjer == Smjerovi::GoreDesno)
		return Idi(polja, x, y, x - 1, y + 1);
		
	else if(smjer == Smjerovi::Desno)
		return Idi(polja, x, y, x, y + 1);
		
	else if(smjer == Smjerovi::DoljeDesno)
		return Idi(polja, x, y, x + 1, y + 1);
		
	else if(smjer == Smjerovi::Dolje)
		return Idi(polja, x, y, x + 1, y);
		
	else if(smjer == Smjerovi::DoljeLijevo)
		return Idi(polja, x, y, x + 1, y - 1);
		
	else if(smjer == Smjerovi::Lijevo)
		return Idi(polja, x, y, x, y - 1);
		
}
void PrijaviGresku (KodoviGresaka greska)
{
	if(greska == KodoviGresaka::PogresnaKomanda)
		std::cout << "Nerazumljiva komanda!";
		
	else if(greska == KodoviGresaka::NedostajeParametar)
		std::cout << "Komanda trazi parametar koji nije naveden!";
		
	else if(greska == KodoviGresaka::NeispravanParametar)
		std::cout << "Parametar komande nije ispravan!";
		
	else if(greska == KodoviGresaka::SuvisanParametar)
		std::cout << "Zadan je suvisan parametar nakon komande";
}

void IgnorisiRazmak()
{
	while(std::cin.peek() == ' ')
		std::cin.get();
}

void Ocisti()
{
	std::cin.clear();
	std::cin.ignore(1000, '\n');
}
bool UnosKomande (Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska)
{
	char c;
	
	std::cout << "Unesite komandu: ";
	std:: cin >> c;
	
	if(!std::cin)
	{
		greska = KodoviGresaka::PogresnaKomanda;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		return false;
	}
	
	IgnorisiRazmak();
	
	if(c == 'K')
	{
		if(std::cin.peek() == '\n')
		{
			komanda = Komande::KreirajIgru;
			return true;
		}
		
		greska = KodoviGresaka::SuvisanParametar;
		Ocisti();
		return false;
	}
		
	else if(c == 'Z')
	{
		if(std::cin.peek() == '\n')
		{
			komanda = Komande::ZavrsiIgru;
			return true;
		}
		
		greska = KodoviGresaka::SuvisanParametar;
		Ocisti();
		return false;
	}
		
	else if(c == 'P')
	{
		if(std::cin.peek() == '\n')
		{
			greska = KodoviGresaka::NedostajeParametar;
			Ocisti();
			return false;
		}
		
		char a = std::cin.get();
		
		if(a == '1')
		{
			IgnorisiRazmak();
			
			if(std::cin.peek() == '\n')
			{
				greska = KodoviGresaka::NedostajeParametar;
				Ocisti();
				return false;
			}
			char e = std::cin.peek();
			if(std::cin.peek() == 'G')
			{
				IgnorisiRazmak();
				
				
				if(std::cin.peek() == '\n')
				{
					smjer = Smjerovi::Gore;
					komanda = Komande::PomjeriJednoMjesto;
					return true;
				}
				std::cin.get();
				if(std::cin.peek() == 'L')
				{
					char d = std::cin.get();
					IgnorisiRazmak();
					if(std::cin.peek() == '\n')
					{
						smjer = Smjerovi::GoreLijevo;
						komanda = Komande::PomjeriJednoMjesto;
						return true;
					}
					
					greska = KodoviGresaka::SuvisanParametar;
					Ocisti();
					return false;
				}
				
				if(std::cin.peek() == 'D')
				{
					char d = std::cin.get();
					IgnorisiRazmak();
					if(std::cin.peek() == '\n')
					{
						smjer = Smjerovi::GoreDesno;
						komanda = Komande::PomjeriJednoMjesto;
						return true;
					}
					greska = KodoviGresaka::SuvisanParametar;
					Ocisti();
					return false;
				}
				greska = KodoviGresaka::NeispravanParametar;
				Ocisti();
				return false;
			}
			
			if(std::cin.peek() == 'D')
			{
				IgnorisiRazmak();
				
				if(std::cin.peek() == '\n')
				{
					smjer = Smjerovi::Desno;
					komanda = Komande::PomjeriJednoMjesto;
					return true;
				}
				
				if(std::cin.peek() == 'o')
				{
					char d = std::cin.get();
										
					if(std::cin.peek() == 'D')
					{
						char d = std::cin.get();
						IgnorisiRazmak();
						if(std::cin.peek() == '\n')
						{
							smjer = Smjerovi::DoljeDesno;
							komanda = Komande::PomjeriJednoMjesto;
							return true;
						}
						greska = KodoviGresaka::SuvisanParametar;
						Ocisti();
						return false;
					}
					
					if(std::cin.peek() == 'L')
					{
						char d = std::cin.get();
						IgnorisiRazmak();
						if(std::cin.peek() == '\n')
						{
							smjer = Smjerovi::DoljeLijevo;
							komanda = Komande::PomjeriJednoMjesto;
							return true;
						}
						greska = KodoviGresaka::SuvisanParametar;
						Ocisti();
						return false;
					}
					IgnorisiRazmak();
					if(std::cin.peek() == '\n')
					{
						smjer = Smjerovi::Dolje;
						komanda = Komande::PomjeriJednoMjesto;
						return true;
					}
					greska = KodoviGresaka::NeispravanParametar;
					Ocisti();
					return false;
				}
				
				greska = KodoviGresaka::PogresnaKomanda;
				Ocisti();
				return false;
			}
			if(std::cin.peek() == 'L')
			{
				char d = std::cin.get();
				IgnorisiRazmak();
					
				if(std::cin.peek() == '\n')
				{
					smjer = Smjerovi::Lijevo;
					komanda = Komande::PomjeriJednoMjesto;
					return true;
				}
				greska = KodoviGresaka::SuvisanParametar;
				Ocisti();
				return false;
			}
			
			greska = KodoviGresaka::NeispravanParametar;
			Ocisti();
			return false;
		}
		
		if(a == '>')
		{
			IgnorisiRazmak();
			if(std::cin.peek() == '\n')
			{
				greska = KodoviGresaka::NedostajeParametar;
				Ocisti();
				return false;
			}
			
			int m;
			std::cin >> m;
			
			if(!std::cin)
			{
				greska = KodoviGresaka::NeispravanParametar;
				Ocisti();
				return false;
			}
			
			char z = std::cin.get();
			
			if(z != ' ')
			{
				greska = KodoviGresaka::SuvisanParametar;
				Ocisti();
				return false;
			}
			
			int n;
			std::cin >> n;
			
			if(!std::cin)
			{
				greska = KodoviGresaka::NeispravanParametar;
				Ocisti();
				return false;
			}
			
			IgnorisiRazmak();
			
			if(std::cin.peek() != '\n')
			{
				greska = KodoviGresaka::SuvisanParametar;
				Ocisti();
				return false;
			}
			
			x = m;
			y = n;
			komanda = Komande::PomjeriDalje;
			return true;
		}
		
		if(a == 'O')
		{
			IgnorisiRazmak();
			if(std::cin.peek() == '\n')
			{
				komanda = Komande::PrikaziOkolinu;
				return true;
			}
			
			greska = KodoviGresaka::SuvisanParametar;
			Ocisti();
			return false;
		}
	}
	
	else if(c == 'B')
	{
		IgnorisiRazmak();
		
		if(std::cin.peek() == '\n')
		{
			greska = KodoviGresaka::NedostajeParametar;
			Ocisti();
			return false;
		}
		
		int m;
		std::cin >> m;
		
		if(!std::cin)
		{
			greska = KodoviGresaka::NeispravanParametar;
			Ocisti();
			return false;
		}
		
		char z = std::cin.get();
		
		if(z != ' ')
		{
			greska = KodoviGresaka::SuvisanParametar;
			Ocisti();
			return false;
		}
		
		int n;
		std::cin >> n;
		
		if(!std::cin)
		{
			greska = KodoviGresaka::NeispravanParametar;
			Ocisti();
			return false;
		}
		
		IgnorisiRazmak();
		
		if(std::cin.peek() != '\n')
		{
			greska = KodoviGresaka::SuvisanParametar;
			Ocisti();
			return false;
		}
		
		komanda = Komande::Blokiraj;
		x = m;
		y = n;
		return true;
	}
	
	else if(c == 'D')
	{
		IgnorisiRazmak();
		
		if(std::cin.peek() == '\n')
		{
			greska = KodoviGresaka::NedostajeParametar;
			Ocisti();
			return false;
		}
		
		int m;
		std::cin >> m;
		
		if(!std::cin)
		{
			greska = KodoviGresaka::NeispravanParametar;
			Ocisti();
			return false;
		}
		
		char z = std::cin.get();
		
		if(z != ' ')
		{
			greska = KodoviGresaka::SuvisanParametar;
			Ocisti();
			return false;
		}
		
		int n;
		std::cin >> n;
		
		if(!std::cin)
		{
			greska = KodoviGresaka::NeispravanParametar;
			Ocisti();
			return false;
		}
		
		IgnorisiRazmak();
		
		if(std::cin.peek() != '\n')
		{
			greska = KodoviGresaka::SuvisanParametar;
			Ocisti();
			return false;
		}
		
		komanda = Komande::Deblokiraj;
		x = m;
		y = n;
		return true;
	}
	greska = KodoviGresaka::PogresnaKomanda;
	Ocisti();
	return false;
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, 
					int p_x = 0, int p_y = 0)
{
	
}

int main()
{
	for(; ;)
	{
		Komande k;
		KodoviGresaka g;
		
		int x = 0, y = 0;
		
		Smjerovi s;
		bool a = UnosKomande(k, s, x, y, g);
		
		if(a)
		{
			std::cout << "Uspjesna, x = " << x << " y = " << y;
			
			if(k == Komande::PomjeriJednoMjesto)
				std::cout << "\nSmjer je " << int(s);
				
			std::cout << "\n a komanda je " << int(k);
		}
		
		else
		{
			std::cout << "Greska je " << int(g);
		}
	}
}
int main_1()
{ 
	try
	{
		auto x (KreirajIgru(4,  {{0,0}, {3,2}, {1,3}}));
		for(int i = 0; i < 4; i++)
		{	
			for(int j = 0; j < 4; j++)
				std::cout << int(x.at(i).at(j)) << " ";
			
				std::cout << std::endl;
		}
	}
	
	catch(std::domain_error e)
	{
		std::cout << e.what();
	}
	return 0;
}

int main_2()
{
	try
	{
		auto x (PrikaziOkolinu({
			{Polje::Prazno, Polje::Mina, Polje::Prazno, Polje::Prazno,Polje::Mina}, 
			{Polje::Prazno, Polje::Prazno, Polje::Prazno, Polje::Mina, Polje::Mina},
			{Polje::Mina,   Polje::Mina, Polje::Prazno, Polje::Mina, Polje::Prazno}, 
			{Polje::Prazno, Polje::Prazno, Polje::Prazno, Polje::Prazno, Polje::Prazno}
			
		}, 1 , 1));
		
		std::cout << "vel1 " << x.size() << std::endl;
		std::cout << "vel2 " << x.at(0).size() << std::endl;
		
		for(int i = 0; i < x.size(); i++)
		{
			for(int j = 0; j < x.at(i).size(); j++)
				std::cout << int(x.at(i).at(j)) << " ";
				
			std::cout << std::endl;
		}
	}
	
	catch(std::domain_error e)
	{
		std::cout << e.what();
	}
	
	return 0;
}
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

enum class Polje {Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina};
enum class Smjerovi {GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo};
enum class Status {NijeKraj, KrajPoraz, KrajPobjeda};
enum class KodoviGresaka {PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar};
enum class Komande {PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru};

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mint)
{
	for(int i(0); i < mint.size(); i++)
	{
		if(mint[i].size() != 2) throw std::domain_error("Ilegalan format zadavanja mina");
		for(int j(0); j < mint[i].size(); j++)
		{
			if(mint[i][j] < 0 || mint[i][j] >= n)
			  throw std::domain_error("Ilegalne pozicije mine");
		}
	}
	
	Tabla polja(n, std::vector<Polje>(n, Polje::Prazno));
	for(int i(0); i < n; i++)
	{
		for(int j(0); j < n; j++)
		{
			for(int k(0); k < mint.size(); k++)
			{
				if(mint[k][0] == i && mint[k][1] == j)
				  polja[i][j] = Polje::Mina;
			}
		}
	}
	return polja;
}

void BlokirajPolje(Tabla &polja, int x, int y)
{
	if(x < 0 || x >= polja.size() || y < 0 || y >= polja.size())
	  throw std::domain_error("Polje(x,y) ne postoji");
	
	if(polja[x][y] == Polje::Mina)
	  polja[x][y] = Polje::BlokiranoMina;
	else if(polja[x][y] == Polje::Posjeceno)
	  polja[x][y] = Polje::BlokiranoPosjeceno;
	else if(polja[x][y] == Polje::Prazno)
	  polja[x][y] = Polje::BlokiranoPrazno;
}

void DeblokirajPolje(Tabla &polja, int x, int y)
{
	if(x < 0 || x >= polja.size() || y < 0 || y >= polja.size())
	  throw std::domain_error("Polje(x,y) ne postoji");
	
	if(polja[x][y] == Polje::BlokiranoMina)
	  polja[x][y] = Polje::Mina;
	else if(polja[x][y] == Polje::BlokiranoPosjeceno)
	  polja[x][y] = Polje::Posjeceno;
	else if(polja[x][y] == Polje::BlokiranoPrazno)
	  polja[x][y] = Polje::Prazno;
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer);
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y);

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y)
{
	if(x < 0 || x >= polja.size() || y < 0 || y >= polja.size())
	  throw std::domain_error("Polje(x,y) ne postoji");
	
	std::vector<std::vector<int>> okolina(3, std::vector<int>(3, 0));
	for(int i(x - 1); i <= x + 1; i++)
	{
		for(int j(y - 1); j <= y + 1; j++)
		{
			if(i < 0 && i >= polja.size() && j < 0 && j >= polja[0].size())
			  okolina[i - (x - 1)][j - (y - 1)] = static_cast<int>(polja[i][j]);
		}
	}
	return okolina;
}

void PrijaviGresku(KodoviGresaka greska)
{
	if(greska == KodoviGresaka::PogresnaKomanda)
	  std::cout << "Nerazumljiva komanda!" << std::endl;
	else if(greska == KodoviGresaka::NedostajeParametar)
	  std::cout << "Komanda trazi parametar koji nije naveden!" << std::endl;
	else if(greska == KodoviGresaka::NeispravanParametar)
	  std::cout << "Parametar komande nije ispravan!" << std::endl;
	else
	  std::cout << "Zadan je suvisan parametar!" << std::endl;
}

void removespace(std::string &s)
{
	int i(0);
	while(i < s.length())
	{
		while(s[i] == ' ')
		  s.erase(i, 1);
		  i++;
	}
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska)
{
	std::string unos;
	std::getline(std::cin, unos);
	removespace(unos);
	
	if(unos[0] == 'P')
	{
		if(unos[1] == '1')
		{
			if(unos[2] == 'G')
			{
				if(unos[3] == 'L' && unos.length() == 4)
				{
					komanda = Komande::PomjeriJednoMjesto;
					smjer = Smjerovi::GoreLijevo;
					return true;
				}
				else if(unos.length() == 3)
				{
					komanda = Komande::PomjeriJednoMjesto;
					smjer = Smjerovi::Gore;
					return true;
				}
				else if(unos[3] == 'D' && unos.length() == 4)
				{
					komanda = Komande::PomjeriJednoMjesto;
					smjer = Smjerovi::GoreDesno;
					return true;
				}
				else
				{
					greska = KodoviGresaka::NeispravanParametar;
					return false;
				}
			}
			else if(unos[2] == 'D')
			{
				if(unos.length() == 3)
				{
					komanda = Komande::PomjeriJednoMjesto;
					smjer = Smjerovi::Desno;
					return true;
				}
				else if(unos[3] == 'o' && unos[4] == 'D' && unos.length() == 5)
				{
					komanda = Komande::PomjeriJednoMjesto;
					smjer = Smjerovi::DoljeDesno;
					return true;
				}
				else if(unos[3] == 'o' && unos.length() == 4)
				{
					komanda = Komande::PomjeriJednoMjesto;
					smjer = Smjerovi::Dolje;
					return true;
				}
				else if(unos[3] == 'o' && unos[4] == 'L' && unos.length() == 5)
				{
					komanda = Komande::PomjeriJednoMjesto;
					smjer = Smjerovi::DoljeLijevo;
					return true;
				}
				else
				{
					greska = KodoviGresaka::NeispravanParametar;
					return false;
				}
			}
			else if(unos[2] == 'L')
			{
				if(unos.length() == 3)
				{
					komanda = Komande::PomjeriJednoMjesto;
					smjer = Smjerovi::Lijevo;
					return true;
				}
				else
				{
					greska = KodoviGresaka::NeispravanParametar;
					return false;
				}
			}
			else if(unos.length() == 2)
			{
				greska = KodoviGresaka::NedostajeParametar;
				return false;
			}
			else
			{
				greska = KodoviGresaka::NeispravanParametar;
				return false;
			}
		}
		else if(unos[1] == '>')
		{
			
		}
		else if(unos[1] == 'O')
		{
			if(unos.length() == 2)
			{
				komanda = Komande::PrikaziOkolinu;
				return true;
			}
			else
			{
				greska = KodoviGresaka::SuvisanParametar;
				return false;
			}
		}
	}
	else if(unos[0] == 'Z')
	{
		if(unos.length() == 1)
		{
			komanda = Komande::ZavrsiIgru;
			return true;
		}
		else
		{
			greska = KodoviGresaka::SuvisanParametar;
			return false;
		}
	}
	else if(unos[0] == 'K')
	{
		if(unos.length() == 1)
		{
			komanda = Komande::KreirajIgru;
			return true;
		}
		else
		{
			greska = KodoviGresaka::SuvisanParametar;
			return false;
		}
	}
	greska = KodoviGresaka::PogresnaKomanda;
	return false;
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0)
{
	if(komanda == Komande::KreirajIgru)
	{
		try
		{
			int n;
			std::cout << "Unesite broj polja: ";
			std::cin >> n;
			std::vector<std::vector<int>> mine;
			std::complex<int> koordinate;
		
			std::cout << "Unesite pozicije mina: ";
			do
			{
				std::cin >> koordinate;
				if(std::cin.get() == '.') break;
				while(!std::cin || koordinate.real() < 0 || koordinate.real() >= n || koordinate.imag() < 0 || koordinate.imag() >= n)
				{
					std::cout << "Greska, unesite ponovo!" << std::endl;
					std::cin.clear();
					std::cin.ignore(10000, '\n');
					std::cin >> koordinate;
				}
				if(std::cin.get() == '.') break;
				std::vector<int> v(2);
				v[0] = koordinate.real();
				v[1] = koordinate.imag();
				mine.push_back(v);
			}while(1 == 1);
		
			polja = KreirajIgru(n, mine);
		}
		catch(std::domain_error izuzetak)
		{
			std::cout << izuzetak.what() << std::endl;
		}
		return;
	}
	else if()
}


int main ()
{
	bool IgramoSe(true);
	int x(0), y(0);
	Komande komanda;
	Smjerovi smjer;
	Tabla polja;
	KodoviGresaka greska;
	
	
	while(IgramoSe)
	{
		try
		{
			std::cout << "Unesite komandu: ";
			bool Ispravna = UnosKomande(komanda, smjer, x, y, greska);
			if(!Ispravna)
			{
				
			}
			else
			{
				IzvrsiKomandu(komanda, polja, x, y, )
			}
		}
		catch(...)
		{
			
		}
		
	}*/
	return 0;
}
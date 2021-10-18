/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/

#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <sstream>

enum class Polje {Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina};
enum class Status {NijeKraj, KrajPoraz, KrajPobjeda};
enum class Smjerovi {GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo};
enum class KodoviGresaka {PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar};
enum class Komande {PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru};



typedef std::vector<std::vector<Polje>> Tabla;
typedef std::vector<std::vector <int>> Matrica;

template<typename T> 
std::string PretvoriUString(T x) {
	std::ostringstream s; s << x; 
	return s.str();
}

Tabla KreirajIgru (int n, const std::vector<std::vector<int>> &mine)
{
	std::vector<std::vector<Polje>> tabla(n, std::vector<Polje>(n, Polje::Prazno));
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < mine.size(); k++)
			{
				if (mine[k].size() != 2)
					throw std::domain_error("Ilegalan format zadavanja mina\n");
				if (mine[k][0] < 0 || mine[k][0] >= n || mine[k][1] < 0 || mine[k][1] >= n)
						throw std::domain_error("Ilegalne pozicije mina\n");
					
				if (mine[k][0] == i && mine[k][1] == j) /*Koordinate???*/
				{
					tabla[i][j] = Polje::Mina;
					break;
				}
			} 
		}
	}
	
	return tabla;
}

Matrica PrikaziOkolinu(const Tabla &polja, int x, int y)
{	
	int n(polja.size());
	
	if (x < 0 || x > n - 1 || y < 0 || y > n - 1)
		throw std::domain_error(std::string("Polje (") + PretvoriUString(x) + "," + PretvoriUString(y) + ") ne postoji\n");
	
	Matrica okolina;
	int red_matrice_okoline(0);
	for (int i = y - 1; i <= y + 1; i++)
	{
		okolina.push_back(std::vector<int>(0));
		if (i >= 0 && i < n)
			for (int j = x - 1; j <= x + 1; j++)
			{
				if (j >= 0 && j < n)
				{
					int broj_mina(0);
					for (int k = i - 1; k <= i + 1; k++)
					{
						if (k >= 0 && k < n)
							for (int l = j - 1; l <= j + 1; l++)
							{
								if (l >= 0 && l < n)
									if ((polja[k][l] == Polje::Mina || polja[k][l] == Polje::BlokiranoMina) && !(k == i && l == j))
										broj_mina++;
							}
					}
					okolina[red_matrice_okoline].push_back(broj_mina);
				}
			}
		red_matrice_okoline++;
	}
	
	return okolina;
}

void BlokirajPolje(Tabla &polja, int x, int y)
{
	int n(polja.size());
	
	if (x < 0 || x > n - 1 || y < 0 || y > n - 1)
		throw std::domain_error(std::string("Polje (") + PretvoriUString(x) + "," + PretvoriUString(y) + ") ne postoji\n");
	
	if (polja[x][y] < Polje::BlokiranoPrazno)
		polja[x][y] = Polje(int(polja[x][y]) + 3);
}

void DeblokirajPolje(Tabla &polja, int x, int y)
{
	int n(polja.size());

	if (x < 0 || x > n - 1 || y < 0 || y > n - 1)
		throw std::domain_error(std::string("Polje (") + PretvoriUString(x) + "," + PretvoriUString(y) + ") ne postoji\n");
	
	if (polja[x][y] >= Polje::BlokiranoPrazno)
		polja[x][y] = Polje(int(polja[x][y]) - 3);
}

Status Idi (Tabla &polja, int &x, int &y, Smjerovi smjer)
{
	std::vector <int> y_promjene{-1, 0, 1, 1, 1, 0, -1, -1}; 
	std::vector <int> x_promjene{-1, -1, -1, 0, 1, 1, 1, 0};
	
	int x_idi(x_promjene[int(smjer)]);
	int y_idi(y_promjene[int(smjer)]);
	int n(polja.size());
	
	if (x + x_idi < 0 || x + x_idi >= n || y + y_idi < 0 || y + y_idi >= n)
		throw std::out_of_range("Izlazak van igrace table\n");
	else if (int(polja[x + x_idi][y + y_idi]) >= 3)
		throw std::logic_error("Blokirano polje\n");
	
	x += x_idi; //x i y po postavci zamijenjeni
	y += y_idi;
	
	Status status(Status::NijeKraj);
	
	if (polja[x][y] == Polje::Mina)
	{
		status = Status::KrajPoraz;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				polja[i][j] = Polje::Prazno;
	}
	else
	{
		polja[x - x_idi][y - y_idi] = Polje::Posjeceno;
		bool kraj(true);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if ((polja[i][j] == Polje::Prazno || polja[i][j] == Polje::BlokiranoPrazno) && !(i == x && j == y))
					kraj = false;
		if (kraj)
			status = Status::KrajPobjeda;
	}
	
	return status;
}

Status Idi (Tabla &polja, int &x, int &y, int novi_x, int novi_y)
{
	int n(polja.size());
	
	if (novi_x < 0 || novi_x >= n || novi_y < 0 || novi_y >= n )
		throw std::out_of_range("Izlazak van igrace table\n");
	else if (int(polja[novi_x][novi_y]) >= 3)
		throw std::logic_error("Blokirano polje\n");
	
	int stari_x(x);
	int stari_y(y);
	x = novi_x;
	y = novi_y;
	
	Status status(Status::NijeKraj);
	
	if (polja[x][y] == Polje::Mina)
	{
		status = Status::KrajPoraz;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				polja[i][j] = Polje::Prazno;
	}
	else
	{
		polja[stari_x][stari_y] = Polje::Posjeceno;
		bool kraj(true);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if ((polja[i][j] == Polje::Prazno || polja[i][j] == Polje::BlokiranoPrazno) && !(i == x && j == y))
					kraj = false;
		if (kraj)
			status = Status::KrajPobjeda;
	}
	
	return status;
	
}

void PrijaviGresku(KodoviGresaka kod_greske)
{
	std::vector<std::string> poruke{"Nerazumljiva komanda!\n", "Komanda trazi parametar koji nije naveden!\n", "Zadan je suvisan parametar nakon komande!\n", "Parametar komande nije ispravan!\n"};
	std::cout << poruke[int(kod_greske)];
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &kod_greske)
{
	std::vector<std::string>komande {"P1", "P>", "B", "D", "PO", "Z", "K"};
	std::vector<std::string>smjerovi {"GL", "G", "GD", "D", "DoD", "Do", "DoL", "L"};
	
	char znak;
	std::string unos;
	bool nadjena(false);
	int br_komande(0);
	
	znak = std::cin.get();
	while (znak != '\n')
	{
		unos.push_back(znak);
		for (int i = 0; i < komande.size(); i++)
		{
			if (unos == komande[i])
			{
				nadjena = true;
				br_komande = i;
				break;
			}
		}
		if (nadjena) break;
		znak = std::cin.get();
	}
	unos.resize(0);
	if (nadjena)
	{
		//P1
		if (br_komande == 0)
		{
			if (std::cin.peek() == '\n')
			{
				kod_greske = KodoviGresaka::NedostajeParametar;
				std::cin.ignore(1000,'\n');
				return false;
			}
			
			while (std::cin.peek() == ' ') std::cin.get(); //Brisanje razmaka
			//Citanje parametra
			while (std::cin.peek() != ' ' && std::cin.peek() != '\n')
			{
				znak = std::cin.get();
				unos.push_back(znak);
			}

			for (int i = 0; i < smjerovi.size(); i++)
			{
				if (unos == smjerovi[i])
				{
					while (std::cin.peek() == ' ') std::cin.get();
					if (std::cin.peek() != '\n') {
						kod_greske = KodoviGresaka::SuvisanParametar;
						std::cin.ignore(1000,'\n');
						return false;
					}
					else
					{
						komanda = Komande(br_komande);
						smjer = Smjerovi(i);
						break;
					}
				}
				if (i == smjerovi.size() - 1)
				{
					kod_greske = KodoviGresaka::NeispravanParametar; 
					std::cin.ignore(1000,'\n');
					return false;
				}
			}
		}
		
		//P>, B, D
		if (br_komande >= 1 && br_komande <= 3)
		{
			int px, py;
			
			//Trazi x
			while (std::cin.peek() == ' ') std::cin.get();
			if (std::cin.peek() == '\n') {kod_greske = KodoviGresaka::NedostajeParametar; std::cin.ignore(1000,'\n');return false;}
			else if (std::cin.peek() < '0' || std::cin.peek() > '9') {kod_greske = KodoviGresaka::NeispravanParametar; std::cin.ignore(1000,'\n');return false;}
			else if (std::cin.peek() >= '0' && std::cin.peek() <= '9') std::cin >> px;
			
			//Trazi y
			while (std::cin.peek() == ' ') std::cin.get();
			if (std::cin.peek() == '\n') {kod_greske = KodoviGresaka::NedostajeParametar; std::cin.ignore(1000,'\n');std::cin.ignore(1000,'\n');return false;}
			else if (std::cin.peek() < '0' || std::cin.peek() > '9') {kod_greske = KodoviGresaka::NeispravanParametar; std::cin.ignore(1000,'\n');return false;}
			else if (std::cin.peek() >= '0' && std::cin.peek() <= '9') std::cin >> py;
		
			//Imal sta suvisno
			while (std::cin.peek() == ' ') std::cin.get();
			if (std::cin.peek() != '\n')
			{
				kod_greske = KodoviGresaka::SuvisanParametar;
				std::cin.ignore(1000,'\n');
				return false;
			}
			
			komanda = Komande(br_komande);
			x = px;
			y = py;
		}
		
		//PO, Z, K
		if (br_komande >= 4 && br_komande <= 6)
		{
			while (std::cin.peek() == ' ') std::cin.get();
			if (std::cin.peek() != '\n')
			{
				kod_greske = KodoviGresaka::SuvisanParametar;
				std::cin.ignore(1000,'\n');
				return false;
			}
			else
			{
				komanda = Komande(br_komande);
				//std::cin.ignore(1000,'\n');
			}
		}
	}
	else
	{
		kod_greske = KodoviGresaka::PogresnaKomanda;
		//std::cin.ignore(1000,'\n');
		return false;
	}
	std::cin.ignore(1000,'\n');
	return true;
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0)
{
	Status status (Status::NijeKraj);
	bool zavrsi(false);
	try
	{
		if (komanda == Komande::PomjeriJednoMjesto)
		{
			status = Idi(polja, x, y, p_smjer);
			std::cout << "Tekuca pozicija igraca je (" << PretvoriUString(x) << "," << PretvoriUString(y) << ")\n"; 
		}
		if (komanda == Komande::PomjeriDalje)
		{
			status = Idi(polja, x, y, p_x, p_y);
			std::cout << "Tekuca pozicija igraca je (" << PretvoriUString(x) << "," << PretvoriUString(y) << ")\n"; 
		}
		if (komanda == Komande::PrikaziOkolinu)
		{
			Matrica ispis(PrikaziOkolinu(polja, x, y));
			for (std::vector<int> v:ispis)
			{
				for (int x:v)
					std::cout << x << " ";
				std::cout << "\n";
			}
		}
		if (komanda == Komande::Blokiraj)
			BlokirajPolje(polja, p_x, p_y);
		if (komanda == Komande::Deblokiraj)
			DeblokirajPolje(polja, p_x, p_y);
		if (komanda == Komande::ZavrsiIgru) 
			zavrsi = true;
		if (komanda == Komande::KreirajIgru)
		{
			int n;
			std::cout << "Unesite broj polja: ";
			std::cin >> n;
			std::cout << "Unesite pozicije mina: ";
			std::vector<std::vector<int>> mine;
			int i(0);
			bool gotovo(false);
			char znak;
			for(;;)
			{
				for (;;)
				{
					std::cin.ignore(10000,'\n');
					int x_k, y_k;
					znak = std::cin.get();
					if (znak == '.'){gotovo = true; break;}
					else if (znak != '('){std::cout << "Greska, unesite ponovo!\n"; continue;} 
					else if (std::cin.peek() >= '0' && std::cin.peek() <= '9') std::cin >> x_k;
					else {std::cout << "Greska, unesite ponovo!\n"; continue;}
					
					znak = std::cin.get();
					if (znak != ',') {std::cout << "Greska, unesite ponovo!\n"; continue;}
					else if (std::cin.peek() >= '0' && std::cin.peek() <= '9') std::cin >> y_k;
					else {std::cout << "Greska, unesite ponovo!\n"; continue;};
					
					znak = std::cin.get();
					if (znak != ')'){std::cout << "Greska, unesite ponovo!\n"; continue;}
					
					if (x_k >= n || y_k >= n) {std::cout << "Greska, unesite ponovo!\n"; continue;}
					
					mine.push_back(std::vector <int>(0));
					mine[i].push_back(x_k); mine[i++].push_back(y_k);
					break;
				}
				if (gotovo) break;
			}
			polja = KreirajIgru(n, mine);
			std::cin.ignore(1000,'\n');
		}
	}
	catch(std::domain_error e)
	{
		std::cout << e.what();
	}
	catch(std::out_of_range e)
	{
		std::cout << e.what();
	}
	catch(std::logic_error e)
	{
		std::cout << e.what();
	}
	
	if (status == Status::KrajPobjeda)
	{
		std::cout << "Bravo, obisli ste sva sigurna polja\n";
		zavrsi = true;
	}
	if (status == Status::KrajPoraz)
	{
		std::cout << "Nagazili ste na minu\n";
		zavrsi = true;
	}
	if (zavrsi)
	{
		for (int i = 0; i < polja.size(); i++)
			for (int j = 0; j < polja[i].size(); j++)
				polja[i][j] = Polje::Prazno;
		throw std::runtime_error("Igra zavrsena\n");
	}
}

int main ()
{
	Komande komanda;
	Smjerovi smjer;
	int x(0), y(0), px(0), py(0);
	KodoviGresaka kod_greske;
	Tabla polja;
	for(;;)
	{
		try 
		{
			std::cout << "Unesite komandu: ";
			if(UnosKomande(komanda,smjer, px, py, kod_greske))
			{
				IzvrsiKomandu(komanda, polja, x, y, smjer, px, py);
			}
			else
			{
				PrijaviGresku(kod_greske);
			}
		}
		catch(std::runtime_error e)
		{
			std::cout << "Dovidjenja!";
			break;
		}
	}
	
	return 0;
}
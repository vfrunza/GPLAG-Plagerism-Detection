/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>
#include <cstring>
#include <string>

using namespace std;

enum class Smjerovi {
	GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo 	
};

enum class Status {
	NijeKraj, KrajPoraz, KrajPobjeda	
};

enum class KodoviGresaka{
	PogresnaKomanda, NedostajeParametar, SuvisanParametas, NeispravanParametar	
};

enum class Komande{
	PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru	
};

enum class Polje {
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};

typedef vector<vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const vector<vector<int>> &mine);
vector<vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y);
void BlokirajPolje(Tabla &polja, int x, int y);
void DeblokirajPolje(Tabla &polja, int x, int y);
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer);
Status Idi(Tabla &polja, int &x, int &y,  int novi_x, int novi_y);
bool UnosKomande (Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska);

void Ispisi(Tabla tabla_a);
int PrebrojOkolinu(const Tabla &polja, int x, int y);

int main ()
{
	
	int No = 4;
	
	vector<vector<int>> pozicije;
	
	pozicije.push_back({0,0});
	pozicije.push_back({0,2});
	pozicije.push_back({1,3});
	
	Tabla tabla_r;
	
	Komande koma;
	KodoviGresaka kodg;
	int poc;
	int poc2;
	Smjerovi smje;
	
	/*
	tabla_r = KreirajIgru(No, pozicije);
	BlokirajPolje(tabla_r, 0,0);
	BlokirajPolje(tabla_r, 0,1);
	
	Ispisi(tabla_r);*/
	
	UnosKomande(koma, smje, poc, poc2, kodg);
	
	return 0;
}

void Ispisi(Tabla tabla_a)
{
	for(int i = 0; i < tabla_a.size(); i++)
	{
		for(int j = 0; j < tabla_a.at(i).size(); j++)
		{
			cout << int(tabla_a[i][j]);
		}
		cout << endl;
	}
}

Tabla KreirajIgru(int n, const vector<vector<int>> &mine)
{
	Tabla rez;
	
	for(int i = 0; i < n; i++)
	{
		vector<Polje> temp;
		for (int j = 0; j < n; j++)
		{
			temp.push_back(Polje::Prazno);
		}
		rez.push_back(temp);
	}
	
	for(int i = 0; i < mine.size(); i++)
	{
		int k_x = mine.at(i).at(0);
		int k_y = mine.at(i).at(1);
		
		rez.at(k_x).at(k_y) = Polje::Mina;
	}
	return rez;
}

int PrebrojOkolinu(const Tabla &polja, int x, int y)
{
	int suma = 0;
	int x_temp = x -2;
	int y_temp;
	
	for(int i = 0; i < 3; i++)
	{
		x_temp++;
		y_temp = y- 2;
		for(int j = 0; j < 3; j++)
		{
			y_temp++;
			if(x_temp < 0 || x_temp >= polja.size() || 
			   y_temp < 0 || y_temp >= polja.size())
			   {
			   	suma += 0;
			   }
			 else
			 {
			 	if(polja.at(x_temp).at(y_temp) == Polje::Mina)
			 	suma+=1;
			 }
		}
	}
	
	if(polja.at(x).at(y) == Polje::Mina) suma -= 1;
	return suma;
}

vector<vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y) 
{
	vector<vector<int>> rez;
	int x_temp = x - 2;
	int y_temp;
	
	for(int i = 0; i < 3; i++)
	{
		vector<int> redni;
		x_temp++;
		y_temp = y - 2;
		for(int j = 0; j < 3; j++)
		{
			y_temp++;
			if(x_temp < 0 || x_temp >= polja.size() ||
			   y_temp < 0 || y_temp >= polja.size())
			   {
			   	redni.push_back(0);
			   	
			   }
			else
			   {
			   	int a = PrebrojOkolinu(polja,x_temp ,y_temp);
			   	redni.push_back(a);
			   	
			   }
			
		}
		rez.push_back(redni);
	}
	return rez;
}

void BlokirajPolje(Tabla &polja, int x, int y)
{
	try{
		if(x < 0 || y < 0 || x >= polja.size() || y >= polja.size())
		{
			throw new domain_error("");
		}
		else
		{
			if(polja.at(x).at(y) == Polje::Prazno)
				polja.at(x).at(y) = Polje::BlokiranoPrazno;
				
			if(polja.at(x).at(y) == Polje::Posjeceno)
				polja.at(x).at(y) = Polje::BlokiranoPosjeceno;
				
			if(polja.at(x).at(y) == Polje::Mina)
				polja.at(x).at(y) = Polje::BlokiranoMina;
		}
	}catch(...)
	{
		cout << "Polje (" << x << "," << y << ") ne postoji" <<endl;
	}
}

void DeblokirajPolje(Tabla &polja, int x, int y)
{
	try{
		if(x < 0 || y < 0 || x >= polja.size() || y >= polja.size())
		{
			throw domain_error("");
		}
		else 
		{
			if(polja.at(x).at(y) == Polje::BlokiranoPrazno)
				polja.at(x).at(y) = Polje::Prazno;
				
			else if(polja.at(x).at(y) == Polje::BlokiranoPosjeceno)
				polja.at(x).at(y) = Polje::Posjeceno;
				
			else if(polja.at(x).at(y) == Polje::BlokiranoMina)
				polja.at(x).at(y) = Polje::Mina;
		}
	}catch(...)
	{
		cout << "Polje (" << x << "," << y << ") ne postoji" <<endl;
	}
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer)
{	
	try
	{
			if(smjer == Smjerovi::Gore)
				x -= 1;
			
			else if(smjer == Smjerovi::Dolje)
				x += 1;
				
			else if(smjer == Smjerovi::GoreLijevo)
			{
				x -= 1;
				y -= 1;
			}
			
			else if(smjer == Smjerovi::GoreDesno)
			{
				x -= 1;
				y += 1;
			}
			else if(smjer == Smjerovi::Desno)
			{
				y += 1;
			}
			else if(smjer == Smjerovi::DoljeDesno)
			{
				x += 1;
				y += 1;
			}	
			else if(smjer == Smjerovi::DoljeLijevo)
			{
				x += 1;
				y -= 1;
			}
			else if(smjer == Smjerovi::Lijevo)
			{
				y -= 1;
			}
		
		if(x < 0 || y < 0 || x >= polja.size() || y >= polja.size())
		{
			throw out_of_range("Izlazak van igrace table");
		}
		
		if(polja.at(x).at(y) == Polje::BlokiranoPosjeceno
				|| polja.at(x).at(y) == Polje::BlokiranoPrazno
				|| polja.at(x).at(y) == Polje::BlokiranoMina)
		{
			throw logic_error("Blokirano polje");
		}
		
		if(polja.at(x).at(y) == Polje::Mina)
		{
			return Status::KrajPoraz;
		}
		else
		{
			bool provjera = true;
			for(int i = 0; i < polja.size(); i++)
			{
				for(int j = 0; j < polja.at(i).size(); j++)
				{
					if(polja.at(i).at(j) == Polje::Prazno)
					{
						provjera = false;
					}
				}
			}
			if(provjera) return Status::KrajPobjeda;
			else return Status::NijeKraj;
		}
	}catch(exception& e)
	{
		cout << e.what() << endl;
	}

	
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y)
{
	try
	{
		if(novi_x < 0 || novi_y < 0 || novi_x >= polja.size() || novi_y >= polja.size())
		{
			throw out_of_range("Izlazak van igrace table");
		}
		if(polja.at(novi_x).at(novi_y) == Polje::BlokiranoPosjeceno
			|| polja.at(novi_x).at(novi_y) == Polje::BlokiranoPrazno
			|| polja.at(novi_x).at(novi_y) == Polje::BlokiranoMina)
		{
			throw logic_error("Blokirano polje");		
		}
		
		x = novi_x;
		y = novi_y;
		
		if(polja.at(x).at(y) == Polje::Mina)
		{
			return Status::KrajPoraz;
		}
		else
		{
			bool provjera = true;
			for(int i = 0; i < polja.size(); i++)
			{
				for(int j = 0; j < polja.at(i).size(); j++)
				{
					if(polja.at(i).at(j) == Polje::Prazno)
					{
						provjera = false;
					}
				}
			}
			if(provjera) return Status::KrajPobjeda;
			else return Status::NijeKraj;
		}
		
	}catch(exception& e)
	{
		cout << e.what() << endl;
	}
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska)
{
	bool rez = true;
	
	string kom;
	
	int velicina = kom.length() + 1;
	
	cout << "Unesite komandu: ";
	getline(cin, kom);
	
	char *c_kom = new char[velicina];
	strcpy(c_kom, kom.c_str());
	int brojac_razmaka = 0;
	
	for(int i = 0; i < velicina; i++)
	{
		if(strncmp(&c_kom[i], " ", 1)) brojac_razmaka++;
		cout << brojac_razmaka << " ";
	}
	
	cout << endl;
	
	int interni_brojac = 0;
	char *c_kom_pravi = new char[velicina-brojac_razmaka];
	
	for(int i = 0; i < velicina; i++)
	{
		if(c_kom[i] != ' ')
		{
			c_kom_pravi[interni_brojac] = c_kom[i];
			interni_brojac++;
			cout << interni_brojac << " ";
		}
	}
	
	delete[] c_kom;
	
	
	for(int i = 0; i < interni_brojac; i++)
		cout << c_kom_pravi[i];
	
	delete[] c_kom_pravi;
	return rez;
}
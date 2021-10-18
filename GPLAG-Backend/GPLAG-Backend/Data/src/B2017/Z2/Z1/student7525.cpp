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

enum class Polje {Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina};

typedef std::vector<std::vector<int>> Matrica;
typedef std::vector<std::vector<Polje>> Tabla;
Tabla KreirajTablu(int broj_redova, int broj_kolona)
{
	return Tabla(broj_redova, std::vector<Polje>(broj_kolona));
}

Matrica KreirajMatricu (int broj_redova, int broj_kolona)
{
	return Matrica(broj_redova, std::vector<int>(broj_kolona));
}

Tabla KreirajIgru (int n, const std::vector<std::vector<int>> &mine)
{
	auto tabla(KreirajTablu(n,n));
	
	std::vector<std::vector<int>> pomocni = mine;
	if (n <= 0) throw std::domain_error ("Ilegalna velicina");
	for (int i = 0; i < mine.size(); i++)
	{
		if (mine[i].size() != 2) throw std::domain_error ("Ilegalan format zadavanja mina");
	}
	
	for (int i = 0; i < mine.size(); i++)
	{
		for (int j = 0; j < mine[i].size(); j++)
		{
			if (mine[i][j] > mine.size()) throw std::domain_error ("Ilegalne pozicije mina");
		}
	}
	
	for (int i = 0; i < mine.size(); i++)
	{
		for (int j = 0; j < mine[i].size()-1; j++)
		{
			tabla[mine[i][j]][mine[i][j+1]] = Polje::Mina;
		}
	}
	
	return tabla;
}

std::vector<std::vector<int>> PrikaziOkolinu (const Tabla &polja, int x, int y)
{
	
	auto mine = KreirajMatricu(3,3);
	int brojac(0);
	for (int i = 0; i < polja.size(); i++)
	{
		for (int j = 0; j < polja[i].size(); j++)
		{
			
				if (x > polja.size()-1 || y > polja[i].size()) throw std::domain_error ("Polje (x,y) ne postoji");
			
		}
	}
	
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == x && j == y)
			{
				
			        if (polja[x-1][y] == Polje::Mina) brojac++;
			        if (polja[x][y] == Polje::Mina) brojac++;
			        if (polja[x][y-1] == Polje::Mina) brojac++;
			        mine[0][0] = brojac;
			        brojac = 0; 
				
				
					if (polja[x-1][y-1] == Polje::Mina) brojac++;
					if (polja[x-1][j+1] == Polje::Mina) brojac++;
					if (polja[x][j] == Polje::Mina) brojac++;
					if (polja[x][j+1] == Polje::Mina) brojac++;
					if (polja[x][y-1] == Polje::Mina) brojac++;
				    mine[0][1] = brojac;
				    brojac = 0; 
				
					if (polja[x-1][y+2] == Polje::Mina) brojac++;
					if (polja[x-1][y] == Polje::Mina) brojac++;
					if (polja[x][y] == Polje::Mina) brojac++;
					if (polja[x][y+1] == Polje::Mina) brojac++;
					if (polja[x][y+2] == Polje::Mina) brojac++;
				    mine[0][2] = brojac;
				    brojac = 0;
				    
				    if (polja[x-1][y-1] == Polje::Mina) brojac++;
				    if (polja[x][j-1] == Polje::Mina) brojac++;
				    if (polja[x-1][y] == Polje::Mina) brojac++;
				    if (polja[x][y] == Polje::Mina) brojac++;
				    if (polja[x+1][y-1] == Polje::Mina) brojac++;
				    if (polja[x+1][y] == Polje::Mina) brojac++;
				    mine[1][0] = brojac;
				    brojac = 0;
				    
				    if (polja[x-1][y-1] == Polje::Mina) brojac++;
				    if (polja[x-1][y] == Polje::Mina) brojac++;
				    if (polja[x-1][y+1] == Polje::Mina) brojac++;
				    if (polja[x][y+1] == Polje::Mina) brojac++;
				    if (polja[x][y-1] == Polje::Mina) brojac++;
				    if (polja[x+1][y-1] == Polje::Mina) brojac++;
				    if (polja[x+1][y] == Polje::Mina) brojac++;
				    if (polja[x+1][y+1] == Polje::Mina) brojac++;
				    mine[1][1] = brojac;
				    brojac = 0;
				    
				    if (polja[x][y] == Polje::Mina) brojac++;
				    if (polja[x-1][y] == Polje::Mina) brojac++;
				    if (polja[x-1][y+1] == Polje::Mina) brojac++;
				    if (polja[x-1][y+2] == Polje::Mina) brojac++;
				    if (polja[x][y+2] == Polje::Mina) brojac++;
				    if (polja[x+1][y-1] == Polje::Mina) brojac++;
				    if (polja[x+1][y] == Polje::Mina) brojac++;
				    if (polja[x+1][y+1] == Polje::Mina) brojac++;
				    mine[1][2] = brojac;
				    brojac = 0;
				    
				    if (polja[x+1][y-1] == Polje::Mina) brojac++;
				    if (polja[x][y-1] == Polje::Mina) brojac++;
				    if (polja[x+2][y-1] == Polje::Mina) brojac++;
				    if (polja[x+2][y] == Polje::Mina) brojac++;
				    if (polja[x][y] == Polje::Mina) brojac++;
				    mine[2][0] = brojac;
				    brojac = 0;
				    
				    if (polja[x][y-1] == Polje::Mina) brojac++;
				    if (polja[x][y] == Polje::Mina) brojac++;
				    if (polja[x][y+1] == Polje::Mina) brojac++;
				    if (polja[x+1][y-1] == Polje::Mina) brojac++;
				    if (polja[x][y+1] == Polje::Mina) brojac++;
				    if (polja[x+2][y-1] == Polje::Mina) brojac++;
				    if (polja[x+2][y] == Polje::Mina) brojac++;
				    if (polja[x+2][y+1] == Polje::Mina) brojac++;
				    mine[2][1] = brojac;
				    brojac = 0;
				    
				    if (polja[x][y] == Polje::Mina) brojac++;
				    if (polja[x][y+1] == Polje::Mina) brojac++;
				    if (polja[x][y+2] == Polje::Mina) brojac++;
				    if (polja[x+1][y] == Polje::Mina) brojac++;
				    if (polja[x+1][y+2] == Polje::Mina) brojac++;
				    if (polja[x+2][y] == Polje::Mina) brojac++;
				    if (polja[x+2][y+1] == Polje::Mina) brojac++;
				    if (polja[x+2][y+2] == Polje::Mina) brojac++;
				    mine[2][2] = brojac;
				    	
				    }
			}
		}
	return mine;
}

void BlokirajPolje (Tabla &polja, int x, int y)
{
	if (polja.size() < x || polja[0].size() < y) throw std::domain_error ("Polje (x,y) ne postoji");
	
	for (int i = 0; i < polja.size(); i++)
	{
		for (int j = 0; j < polja[i].size(); j++)
		{
			if (i == x && j == y)
			{
				if (polja[i][j] == Polje::Prazno) polja[i][j] = Polje::BlokiranoPrazno;
				if (polja[i][j] == Polje::Posjeceno) polja[i][j] = Polje::BlokiranoPosjeceno;
				if (polja[i][j] == Polje::Mina) polja[i][j] = Polje::BlokiranoMina;
			}
		}
	}
}


void DeblokirajPolje (Tabla &polja, int x, int y)
{
	if (polja.size() < x || polja[0].size() < y) throw std::domain_error ("Polje (x,y) ne postoji");
	
	for (int i = 0; i < polja.size(); i++)
	{
		for (int j = 0; j < polja[i].size(); j++)
		{
			if (i == x && j == y)
			{
				if (polja[i][j] == Polje::BlokiranoPrazno) polja[i][j] = Polje::Prazno;
				if (polja[i][j] == Polje::BlokiranoPosjeceno) polja[i][j] = Polje::Posjeceno;
				if (polja[i][j] == Polje::BlokiranoMina) polja[i][j] = Polje::Mina;
			}
		}
	}
}

enum class Smjerovi {GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo};
enum class Status {NijeKraj, KrajPoraz, KrajPobjeda};


Status Idi (Tabla &polja, int &x, int &y, Smjerovi smjer)
{
    Status s = Status::NijeKraj;
    
    if (x > polja.size() || y > polja[0].size()) throw std::out_of_range ("Izlazak van igrace table");
   
    
    if (x == 0 && y == 0) 
    {
    	polja[x][y] = Polje::Posjeceno;
    	polja[x][y] != Polje::Mina;
    }

		   if (smjer == Smjerovi::GoreLijevo )
		   {
		   	  polja[x][y] = Polje::Posjeceno;
		   	  x = x-1;
		   	  y = y-1;
		   	  if (polja[x][y] == Polje::BlokiranoPrazno) throw std::domain_error ("Blokirano polje");
		   	  if (polja[x][y] == Polje::Mina) s = Status::KrajPoraz;
		   	  
		   }
		   
		   if (smjer == Smjerovi::Gore)
		   {
		   	  polja[x][y] = Polje::Posjeceno;
		   	  x = x-1;
		   	  y = y;
		   	  if (polja[x][y] == Polje::BlokiranoPrazno) throw std::domain_error ("Blokirano polje");
		   	  if (polja[x][y] == Polje::Mina) s = Status::KrajPoraz;
		   	  
		   }
		   
		   if (smjer == Smjerovi::GoreDesno)
		   {
		   	   polja[x][y] = Polje::Posjeceno;
		   	   x = x-1;
		   	   y = y+1;
		   	   if (polja[x][y] == Polje::BlokiranoPrazno) throw std::domain_error ("Blokirano polje");
		   	   if (polja[x][y] == Polje::Mina) s = Status::KrajPoraz;
		   	  
		   }
		   
		   if (smjer == Smjerovi::Desno)
		   {
		   	   polja[x][y] == Polje::Posjeceno;
		   	   x = x;
		   	   y = y+1;
		   	   if (polja[x][y] == Polje::BlokiranoPosjeceno || polja[x][y] == Polje::BlokiranoPrazno || polja[x][y] == Polje::BlokiranoMina) throw std::domain_error ("Blokirano polje");
		   	   if (polja[x][y] == Polje::Mina) s = Status::KrajPoraz;
		   	   
		   }
		   
		   if (smjer == Smjerovi::DoljeDesno)
		   {
		   	   polja[x][y] = Polje::Posjeceno;
		   	   x = x+1;
		   	   y = y+1;
		   	   if (polja[x][y] == Polje::BlokiranoPrazno) throw std::domain_error ("Blokirano polje");
		   	   if (polja[x][y] == Polje::Mina) s = Status::KrajPoraz;
		   	   
		   }
		   
		   if (smjer == Smjerovi::Dolje)
		   {
		   	   polja[x][y] = Polje::Posjeceno;
		   	   x = x+1;
		   	   if (polja[x][y] == Polje::BlokiranoPrazno) throw std::domain_error ("Blokirano polje");
		   	   if (polja[x][y] == Polje::Mina) s = Status::KrajPoraz;
		   	   
		   }
		   
		   if (smjer == Smjerovi::DoljeLijevo)
		   {
		   	   polja[x][y] = Polje::Posjeceno;
		   	   x = x+1;
		   	   y = y-1;
		   	   if (polja[x][y] == Polje::BlokiranoPrazno) throw std::domain_error ("Blokirano polje");
		   	   if (polja[x][y] == Polje::Mina) s = Status::KrajPoraz;
		   
		   }
		   
		   if (smjer == Smjerovi::Lijevo)
		   {
		   	   polja[x][y] = Polje::Posjeceno;
		   	   x = x;
		   	   y = y-1;
		   	   if (polja[x][y] == Polje::Mina) s = Status::KrajPoraz;
		   }
		   
		   for (int i = 0; i < polja.size(); i++)
		   {
		   	  for (int j = 0; j < polja[i].size(); j++)
		   	  {
		   	  	if (polja[i][j] == Polje::Prazno) s = Status::KrajPobjeda;
		   	  }
		   }
    
    if (s == Status::KrajPoraz)
    {
    	for (int i = 0; i < polja.size(); i++)
    	{
    		for (int j = 0; j < polja[i].size(); j++)
    		{
    			polja[i][j] = Polje::Prazno;
    		}
    	}
    }
	
	return s;
}

Status Idi (Tabla &polja, int &x, int &y, int novi_x, int novi_y)
{
	if (novi_x > polja.size() || novi_y > polja[0].size()) throw std::out_of_range("Izlazak van igrace table");
	if (polja[novi_x][novi_y] == Polje::BlokiranoPrazno) throw std::domain_error ("Blokirano polje");
	
	Status s = Status::NijeKraj;
	polja[x][y] == Polje::Posjeceno;
	for (int i = 0; i < polja.size(); i++)
	{
		for (int j = 0; j < polja[i].size(); j++)
		{
			x = novi_x;
			y = novi_y;
			polja[x][y] = Polje::Posjeceno;
			if (polja[x][y] == Polje::Mina) 
			{
				s = Status::KrajPoraz;
				break;
			}
		}
	}
	
	for (int i = 0; i < polja.size(); i++)
	{
		for (int j = 0; j < polja[i].size(); j++)
		{
			if (polja[i][j] == Polje::Posjeceno) s = Status::KrajPobjeda;
		}
	}
    
    if (s == Status::KrajPoraz)
    {
    	for (int i = 0; i < polja.size(); i++)
    	{
    		for (int j = 0; j < polja[i].size(); j++)
    		{
    			polja[i][j] = Polje::Prazno;
    		}
    	}
    }
	
	return s;
	
}

enum class KodoviGresaka {PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar};

void PrijaviGresku (KodoviGresaka greska)
{
	if (greska == KodoviGresaka::PogresnaKomanda) std::cout << "Nerazumljiva komanda!" << std::endl;
	if (greska == KodoviGresaka::NedostajeParametar) std::cout << "Komanda trazi parametar koji nije naveden!" << std::endl;
	if (greska == KodoviGresaka::NeispravanParametar) std::cout << "Parametar komande nije ispravan!" << std::endl;
	if (greska == KodoviGresaka::SuvisanParametar) std::cout << "Zadan je suvisan parametar nakon komande!" << std::endl;
}

enum class Komande {
	PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};

bool UnosKomande (Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska)
{
	bool komanda1(false);
	std::string s;
	std::cout << "Unesite komandu: ";
	std::getline(std::cin, s);
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'K')komanda1 = true;
	}
}







void ispisiTablu(std::vector<std::vector<Polje>> polja){
   for(int i = 0; i < polja.size(); i++) {
          for(int j = 0; j < polja[i].size(); j++) std::cout << int(polja[i][j]) << " ";
          std::cout << std::endl;
        }
}


int main ()
{
	  int x = 0, y = 0;
    std::vector<std::vector<int>> mine = {{0,2}, {1,0}, {1,1}, {1,2}, {2,0}, {2,1}, {2,2}};
    std::vector<std::vector<Polje>> tabla = KreirajIgru(3, mine);
   try{
     Idi(tabla, x, y, Smjerovi::Lijevo);
   }
   catch(std::out_of_range e){
     std::cout << e.what() << std::endl;
   }
   BlokirajPolje(tabla, 0, 1);
   try{
     Idi(tabla, x, y, Smjerovi::Desno);
   }
   catch(std::logic_error e){
     std::cout << e.what() << std::endl;
   }
	return 0;
}
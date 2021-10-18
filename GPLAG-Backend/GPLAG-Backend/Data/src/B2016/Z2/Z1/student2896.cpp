/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba.
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

enum class Polje
{
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};
typedef std::vector<std::vector<Polje>> Tabla;

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

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine)
{
	Tabla igra(0,std::vector<Polje>(0));
	for(int i=0; i<mine.size(); i++)
	{
		if(mine.at(i).size() !=  2)
		{
			throw std::domain_error("Ilegalan format zadavanja mina");
		}
		if(mine.at(i).at(0) < 0 || mine.at(i).at(0) >= n) throw std::domain_error("Ilegalne pozicije mina");
		if(mine.at(i).at(1) < 0 || mine.at(i).at(1) >= n) throw std::domain_error("Ilegalne pozicije mina");
	}
	for(int i=0; i<n; i++)
	{
		igra.push_back(std::vector<Polje>(0));
		for(int j=0; j<n; j++)
		{
			igra.at(i).push_back(Polje::Prazno);
			for(int k=0; k<mine.size(); k++)
			{
				if(mine.at(k).at(0) == i && mine.at(k).at(1) == j)
				{
					igra.at(i).at(j) = Polje::Mina;
				}
			}
		}
	}
	if(n>0) igra.at(0).at(0) = Polje::Prazno;
	return igra;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y)
{
	std::vector<std::vector<int>> Okolina(3,std::vector<int>(3));
	if(x<0 || y<0 || x>=polja.size() || y>=polja.at(0).size())
	{
		std::string greska;
		greska += "Polje (" + std::to_string(x) + "," + std::to_string(y) +") ne postoji";
		throw std::domain_error(greska);
	}
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			int tx, ty;
			tx = x-1+i;
			ty = y-1+j;
			int br = 0;
			for(int k=ty-1; k<=ty+1; k++)
			{
				if(tx-1 >= 0 && k>=0 && k<polja.at(tx-1).size())
				{
					if(polja.at(tx-1).at(k) == Polje::Mina /*&& (x!=tx-1 || k!=y)*/)
					{
						br++;
					}
				}
				if(tx+1 < polja.size() && k>=0 && k<polja.at(tx+1).size())
				{
					if(polja.at(tx+1).at(k) == Polje::Mina/* && (x!=tx+1 || k!=y)*/)
					{
						br++;
					}
				}
			}
			if(tx>=0 && tx<polja.size()&& ty-1 >= 0 && polja.at(tx).at(ty-1) == Polje::Mina/* && (x!=tx || y!=ty-1)*/)
			{
				br++;
			}
			if(tx>=0 && tx<polja.size()&& ty+1 < polja.at(tx).size() && polja.at(tx).at(ty+1) == Polje::Mina/* && (x!=tx || y!=ty+1)*/)
			{
				br++;
			}
			Okolina.at(i).at(j) = br;
		}
	}
	return Okolina;
}

void BlokirajPolje(Tabla &polja, int x, int y)
{
	if(x<0 ||y<0 || x>=polja.size() || y>=polja.at(0).size())
	{
		std::string greska;
		greska += "Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji";
		throw std::domain_error(greska);
	}
	if(polja.at(x).at(y) == Polje::Prazno) polja.at(x).at(y) = Polje::BlokiranoPrazno;
	if(polja.at(x).at(y) == Polje::Posjeceno) polja.at(x).at(y) = Polje::BlokiranoPosjeceno;
	if(polja.at(x).at(y) == Polje::Mina) polja.at(x).at(y) = Polje::BlokiranoMina;
}

void DeblokirajPolje(Tabla &polja, int x, int y)
{
	if(x<0 ||y<0 || x>=polja.size() || y>=polja.at(0).size())
	{
		std::string greska;
		greska += "Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji";
		throw std::domain_error(greska);
	}
	if(polja.at(x).at(y) == Polje::BlokiranoPrazno) polja.at(x).at(y) = Polje::Prazno;
	if(polja.at(x).at(y) == Polje::BlokiranoPosjeceno) polja.at(x).at(y) = Polje::Posjeceno;
	if(polja.at(x).at(y) == Polje::BlokiranoMina) polja.at(x).at(y) = Polje::Mina;
	
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer)
{
	int novi_x = x;
	int novi_y = y;
	if(smjer  == Smjerovi::GoreLijevo) {novi_x -= 1; novi_y -= 1;}
	else if(smjer == Smjerovi::Gore) novi_x -= 1;
	else if(smjer == Smjerovi::GoreDesno) {novi_x -= 1; novi_y += 1;}
	else if(smjer == Smjerovi::Desno) novi_y += 1;
	else if(smjer == Smjerovi::DoljeDesno) {novi_x += 1; novi_y += 1;}
	else if(smjer == Smjerovi::Dolje) novi_x+=1;
	else if(smjer == Smjerovi::DoljeLijevo) {novi_x+=1; novi_y-=1;}
	else if(smjer == Smjerovi::Lijevo) novi_y-= 1;
	if(novi_x < 0 || novi_y < 0 || novi_x >= polja.size() || novi_y >= polja.at(0).size()) //f
	{
		throw std::out_of_range("Izlazak van igrace table");
	}
	if(polja.at(novi_x).at(novi_y) > Polje::Mina)
	{
		throw std::logic_error("Blokirano polje");
	}
	polja.at(x).at(y) = Polje::Posjeceno;
	x = novi_x;
	y = novi_y;
	if(polja.at(x).at(y) == Polje::Mina)
	{
		int m = polja.size();
		int n = polja.at(0).size();
		for(int i=0; i<m; i++)
		{
			for(int j=0; j<n; j++)
			{
				polja.at(i).at(j) = Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	} 
	int m = polja.size();
	int n = polja.at(0).size();
	bool imapraznih = false;
	for(int i= 0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(polja.at(i).at(j) == Polje::Prazno || polja.at(i).at(j) == Polje::BlokiranoPrazno)
			{
				imapraznih = true;
			}
		}
	}
	if(imapraznih == false)
	{
		return Status::KrajPobjeda;
	}
	return Status::NijeKraj;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y)
{
	if(novi_x < 0 ||novi_y < 0 || novi_x >= polja.size() ||novi_y >= polja.at(0).size())
	{
		throw std::out_of_range("Izlazak van igrace table");
	}
	if(int(polja[novi_x][novi_y]) > 2)
	{
		throw std::logic_error("Blokirano polje");
	}
	polja.at(x).at(y) = Polje::Posjeceno;
	x = novi_x;
	y = novi_y;
	if(polja.at(x).at(y) == Polje::Mina)
	{
		int m = polja.size();
		int n = polja.at(0).size();
		for(int i=0; i<m; i++)
		{
			for(int j=0; j<n; j++)
			{
				polja.at(i).at(j) = Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
	int m = polja.size();
	int n = polja.at(0).size();
	bool imapraznih = false;
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(polja.at(i).at(j) == Polje::Prazno ||polja.at(i).at(j) == Polje::BlokiranoPrazno)
			{
				imapraznih = true;
			}
		}
	}
	if(imapraznih == false)
	{
		return Status::KrajPobjeda;
	}
	return Status::NijeKraj;
}

void PrijaviGresku(KodoviGresaka greska)
{
	if(greska == KodoviGresaka::PogresnaKomanda) std::cout << "Nerazumljiva komanda!\n";
	else if(greska == KodoviGresaka::NedostajeParametar) std::cout << "Komanda trazi parametar koji nije naveden!\n";
	else if(greska == KodoviGresaka::NeispravanParametar) std::cout << "Parametar komande nije ispravan!\n";
	else if(greska == KodoviGresaka::SuvisanParametar) std::cout << "Zadan je suvisan parametar nakon komande!\n";
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska)
{
	std::string s;
	std::getline(std::cin, s);
	std::string p;
	std::vector<std::string> v(0);
	int duzina = 0;
	for(int i=0; i<=s.length(); i++)
	{
		if(i==s.length() || s[i] == ' ') //hh
		{
			if(duzina > 0)
			{
				v.push_back(p);
				p.resize(0);
				duzina = 0;
			}
			else
			{
				continue;
			}
		}
		else
		{
			p.push_back(s.at(i));
			duzina++;
		}
	}
	if(v.size() == 0) 
	{
		greska = KodoviGresaka::PogresnaKomanda;
		return false;
	}
	if(v.at(0) == "P1")
	{
		if(v.size() == 1)
		{
			greska = KodoviGresaka::NedostajeParametar;
			return false;
		}
		if(v.size() > 2)
		{
			greska = KodoviGresaka::SuvisanParametar;
			return false;
		}
		if(v.at(1) == "GL")
		{
			smjer = Smjerovi::GoreLijevo;
			komanda = Komande::PomjeriJednoMjesto;
			return true;
		}
		if(v.at(1) == "G")
		{
			smjer = Smjerovi::Gore;
			komanda = Komande::PomjeriJednoMjesto;
			return true;
		}
		if(v.at(1) == "GD")
		{
			smjer = Smjerovi::GoreDesno;
			komanda = Komande::PomjeriJednoMjesto;
			return true;
		}
		if(v.at(1) == "D")
		{
			smjer = Smjerovi::Desno;
			komanda = Komande::PomjeriJednoMjesto;
			return true;
		}
		if(v.at(1) == "DoD")
		{
			smjer = Smjerovi::DoljeDesno;
			komanda = Komande::PomjeriJednoMjesto;
			return true;
		}
		if(v.at(1) == "Do")
		{
			smjer = Smjerovi::Dolje;
			komanda = Komande::PomjeriJednoMjesto;
			return true;
		}
		if(v.at(1) == "DoL")
		{
			smjer = Smjerovi::DoljeLijevo;
			komanda = Komande::PomjeriJednoMjesto;
			return true;
		}
		if(v.at(1) == "L")
		{
			smjer = Smjerovi::Lijevo;
			komanda = Komande::PomjeriJednoMjesto;
			return true;
		}
		greska = KodoviGresaka::NeispravanParametar;
		return false;
	}
	if(v.at(0) == "P>" ||v.at(0) == "B" ||v.at(0) == "D")
	{
		if(v.size() < 3)
		{
			greska = KodoviGresaka::NedostajeParametar;
			return false;
		}
		if(v.size() > 3)
		{
			greska = KodoviGresaka::SuvisanParametar;
			return false;
		}
		for(int i=0; i<v.at(1).length(); i++)
		{
			if(v.at(1).at(i) < 48 || v.at(1).at(i) > 57)
			{
				greska = KodoviGresaka::NeispravanParametar;
				return false;
			}
		}
		for(int i=0; i<v.at(2).length(); i++)
		{
			if(v.at(2).at(i) < 48 ||v.at(2).at(i) > 57)
			{
				greska = KodoviGresaka::NeispravanParametar;
				return false;
			}
		}
		if(v.at(0) == "P>")
		{
			komanda = Komande::PomjeriDalje;
			x = std::stoi(v.at(1),nullptr);
			y = std::stoi(v.at(2),nullptr);
			return true;
		}
		if(v.at(0) == "B")
		{
			komanda = Komande::Blokiraj;
			x = std::stoi(v.at(1),nullptr);
			y = std::stoi(v.at(2),nullptr);
			return true;
		}
		if(v.at(0) == "D")
		{
			komanda = Komande::Deblokiraj;
			x = std::stoi(v.at(1),nullptr);
			y = std::stoi(v.at(2),nullptr);
			return true;
		}
		
	}
	if(v.at(0) == "PO")
	{
		if(v.size() > 1)
	
			greska = KodoviGresaka::SuvisanParametar; //hh
			return false;
		}
		komanda = Komande::PrikaziOkolinu;
		return true;
	}
	if(v.at(0) == "Z")
	{
		if(v.size() > 1)
		{
			greska = KodoviGresaka::SuvisanParametar;
			return false;
		}
		komanda = Komande::ZavrsiIgru;
		return true;
	}
	if(v.at(0) == "K")
	{
		if(v.size() > 1)
		{
			greska = KodoviGresaka::SuvisanParametar;
			return false;
		}
		komanda = Komande::KreirajIgru;
		return true;
	}
	greska = KodoviGresaka::PogresnaKomanda;
	return false;
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int  p_x = 0, int p_y = 0)
{
	try
	{
		if(komanda == Komande::PomjeriJednoMjesto)
		{
			Status stanje = Idi(polja, x, y, p_smjer);
			if(stanje == Status::KrajPoraz || stanje == Status::KrajPobjeda)
			{
				for(int i=0; i<polja.size(); i++)
				{
					for(int j=0; j<polja.at(i).size();j++)
					{
						polja.at(i).at(j) = Polje::Prazno;
					}
				}
				if(stanje == Status::KrajPoraz) std::cout << "Nagazili ste na minu" << std::endl;
				else if(stanje == Status::KrajPobjeda) std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
				throw std::runtime_error("Igra zavrsena\n");
			}
			else
			{
				std::string s;
				s += "Tekuca pozicija igraca je (" + std::to_string(x) + "," + std::to_string(y) + ")"; //ssks
				std::cout << s << std::endl;
			}
		}
		if(komanda == Komande::PomjeriDalje)
		{
			try
			{
				Status stanje = Idi(polja, x, y, p_x, p_y);
				if(stanje == Status::KrajPoraz ||stanje == Status::KrajPobjeda)
				{
					for(int i=0; i<polja.size(); i++)
					{
						for(int j=0; j<polja.at(i).size(); j++)
						{
							polja.at(i).at(j) = Polje::Prazno;
						}
					}
					if(stanje == Status::KrajPoraz) std::cout << "Nagazili ste na minu" << std::endl;
					else if(stanje == Status::KrajPobjeda) std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
					throw std::runtime_error("Igra zavrsena");
				}
				else
				{
					std::string s;
					s+= "Tekuca pozicija igraca je (" + std::to_string(x) + "," + std::to_string(y) + ")"; //
					std::cout << s << std::endl;
				}
			}
			catch(std::logic_error &e)
			{
				std::cout << e.what() << std::endl;
			}
		}
		if(komanda == Komande::PrikaziOkolinu)
		{
			std::vector<std::vector<int>> okolina = PrikaziOkolinu(polja, x, y);
			for(int i=0; i<okolina.size(); i++)
			{
				for(int j=0; j<okolina.at(i).size(); j++)
				{
					std::cout << okolina.at(i).at(j) << " ";
				}
				std::cout << std::endl;
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
		if(komanda == Komande::KreirajIgru)
		{
			std::cout << "Unesite broj polja: ";
			int n;
			std::cin >> n;
			std::cin.ignore();
			std::vector<std::vector<int>> mine(0);
			std::cout << "Unesite pozicije mina: ";
			for(;;)
			{
				std::string s;
				std::getline(std::cin, s);
				const char *unos = s.c_str();
				int a; 
				int b;
				if(s == ".")
				{
					break;
				}
				if((std::sscanf(unos,"(%d,%d)", &a, &b)) == 2)
				{
					if(a<0 || b<0 || a>=n || b>=n)
					{
						std::cout << "Greska, unesite ponovo!" << std::endl; //fff
						continue;
					}
					else
					{
						std::vector<int> temp(0);
						temp.push_back(a);
						temp.push_back(b);
						mine.push_back(temp);
					}
				}
				else
				{
					std::cout << "Greska, unesite ponovo!" << std::endl;
					continue;
				}
			}
			polja = KreirajIgru(n,mine);
		}
		if(komanda == Komande::ZavrsiIgru)
		{
			for(int i=0; i<polja.size(); i++)
			{
				for(int j=0; j<polja.at(i).size(); j++)
				{
					polja.at(i).at(j) = Polje::Prazno;
				}
			}
			throw std::runtime_error("Igra zavrsena");
		}
	}
	catch(std::domain_error &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(std::logic_error &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main () //huhuuuguu
{  
	try
	{
		Tabla polja(0);
		int x = 0;
		int y = 0;
		int px;
		int py;
		Smjerovi smjer;
		KodoviGresaka greska;
		Komande komanda;
		for(;;)
	    	{
	    		std::cout << "Unesite komandu: ";
	    		if(UnosKomande(komanda, smjer, px, py, greska))
	    		{
	    			IzvrsiKomandu(komanda, polja, x, y, smjer, px, py);
	    		}
	    		else
	    		{
	    			PrijaviGresku(greska);
	    		}
	    	}
	}
	catch(std::runtime_error &e)
	{
		std::cout << "Dovidjenja!";
	}
	return 0; //h
}
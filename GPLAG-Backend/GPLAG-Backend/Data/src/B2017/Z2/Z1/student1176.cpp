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
#include <complex>

enum class Polje { Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina};
enum class Smjerovi { GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo};
enum class Status { NijeKraj, KrajPoraz, KrajPobjeda};
enum class KodoviGresaka { PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar};
enum class Komande { PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru};

typedef std::vector<std::vector<Polje>> Tabla;
typedef std::vector<std::vector<int>> Matrica;

Tabla KreirajMatricu(int br_redova, int br_kolona)
{
	return Tabla(br_redova, std::vector<Polje>(br_kolona));
}

Matrica Kreiraj(int br_redova, int br_kolona)
{
	return Matrica(br_redova, std::vector<int>(br_kolona));
}

Matrica UnesiMatricu(int br_redova, int br_kolona)
{
	Matrica m(br_redova, std::vector<int>(br_kolona));
	for(int i=0; i<20; i++)
	{
		for(int j=0; j<2; j++)
		{
			std::cin >> m.at(i).at(j);
			if(m.at(i).at(j) == '.') break;
		}
	}
	return m;
}

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine)
{
	Tabla A = KreirajMatricu(n,n);
	
	for(int i=0; i<A.size(); i++)
	{
		for(int j=0; j<A.at(i).size(); j++)
		{
			A.at(i).at(j) = Polje::Prazno;
		}
	}
	
	Tabla Polja = KreirajMatricu(n,n);
	
	for(int i=0; i<A.size(); i++)
	{
		for(int j=0; j<A.at(i).size(); j++)
		{
			for(int k=0; k<mine.size(); k++)
			{
				if(i == mine.at(k).at(0) && j == mine.at(k).at(1))
				{
					Polja.at(i).at(j) = Polje::Mina;
				}
			}
		}
	}
	return Polja;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y)
{
	std::vector<int> niz_okolina;
	
	if(x == 1 && y == 1)
	{
		int glh=x-1, glv=y-1, gsh=x-1, gsv=y, gdh=x-1, gdv=y+1,
		    slh=x, slv=y-1, tth=x, ttv=y, sdh=x, sdv=y+1,
			dlh=x+1, dlv=y-1, dsh=x+1, dsv=y, ddh=x+1, ddv=y+1;
		
		int brojac1(0), brojac2(0), brojac3(0), brojac4(0), brojac5(0), brojac6(0), brojac7(0), brojac8(0), brojac9(0);
		
		for(int i=glh; i<glh+2; i++)
		{
			for(int j=glv; j<glv+2; j++)
			{
				if(polja.at(i).at(j) == Polje::Mina) 
					brojac1++;
				if(i == glh && j == glv && polja.at(i).at(j) == Polje::Mina)
					brojac1 -= 1;
			}
		}
		niz_okolina.push_back(brojac1);
		
		for(int i=gsh; i<gsh+2; i++)
		{
			for(int j=gsv; j<gsv+2; j++)
			{
				if(polja.at(i).at(j) == Polje::Mina) 
					brojac2++;
				if(i == gsh && j == gsv && polja.at(i).at(j) == Polje::Mina) 
					brojac2 -= 1;
			}
		}
		niz_okolina.push_back(brojac2);
		
		for(int i=gdh; i<gdh+2; i++)
		{
			for(int j=gdv; j<gdv+2; j++)
			{
				if(polja.at(i).at(j) == Polje::Mina) 
					brojac3++;
				if(i == gdh && j == gdv && polja.at(i).at(j) == Polje::Mina) 
					brojac3 -= 1;
			}
		}
		niz_okolina.push_back(brojac3);
		
		for(int i=slh - 1; i<slh+2; i++)
		{
			for(int j=slv; j<slv+2; j++)
			{
				if(polja.at(i).at(j) == Polje::Mina) 
					brojac4++;
				if(i == slh && j == slv && polja.at(i).at(j) == Polje::Mina)
					brojac4 -= 1;
			}
		}
		niz_okolina.push_back(brojac4);
		
		for(int i=tth -1; i<tth+2; i++)
		{
			for(int j=ttv - 1; j<ttv+2; j++)
			{
				if(polja.at(i).at(j) == Polje::Mina) 
					brojac5++;
				if(i == tth && j == ttv && polja.at(i).at(j) == Polje::Mina) 
					brojac5 -= 1;
			}
		}
		niz_okolina.push_back(brojac5);
		
		for(int i=sdh - 1; i<sdh+2; i++)
		{
			for(int j=sdv - 1; j<sdv+2; j++)
			{
				if(polja.at(i).at(j) == Polje::Mina) 
					brojac6++;
				if(i == sdh && j == sdv && polja.at(i).at(j) == Polje::Mina) 
					brojac6 -= 1;
			}
		}
		niz_okolina.push_back(brojac6);
		
		for(int i=dlh - 1; i<dlh+2; i++)
		{
			for(int j=dlv; j<dlv+2; j++)
			{
				if(polja.at(i).at(j) == Polje::Mina) 
					brojac7++;
				if(i == dlh && j == dlv && polja.at(i).at(j) == Polje::Mina) 
					brojac7 -= 1;
			}
		}
		niz_okolina.push_back(brojac7);
		
		for(int i=dsh-1; i<dsh+2; i++)
		{
			for(int j=dsv - 1; j<dsv+2; j++)
			{
				if(polja.at(i).at(j) == Polje::Mina) 
					brojac8++;
				if(i == dsh && j == dsv && polja.at(i).at(j) == Polje::Mina) 
					brojac8 -= 1;
			}
		}
		niz_okolina.push_back(brojac8);
		
		for(int i=ddh - 1; i<ddh+2; i++)
		{
			for(int j=ddv - 1; j<ddv+2; j++)
			{
				if(polja.at(i).at(j) == Polje::Mina) 
					brojac9++;
				if(i == ddh && j == ddv && polja.at(i).at(j) == Polje::Mina) 
					brojac9 -= 1;
			}
		}
		niz_okolina.push_back(brojac9);
		
		Matrica MatricaPonavljanja = Kreiraj(3,3);
		int h(0);
		for(int i=0; i<3; i++)
		{
			for(int j=0; j<3; j++)
			{
				MatricaPonavljanja.at(i).at(j) = niz_okolina.at(h);
				h++;
			}
		}
		return MatricaPonavljanja;
	}
	
	if(x>=2 && y>=2)
	{
		int glh=x-1, glv=y-1, gsh=x-1, gsv=y, gdh=x-1, gdv=y+1,
			slh=x, slv=y-1, tth=x, ttv=y, sdh=x, sdv=y+1,
			dlh=x+1, dlv=y-1, dsh=x+1, dsv=y, ddh=x+1, ddv=y+1;
		
		int brojac1(0), brojac2(0), brojac3(0), brojac4(0), brojac5(0), brojac6(0), brojac7(0), brojac8(0), brojac9(0);
		
		for(int i=glh - 1; i<glh+2; i++)
		{
			for(int j=glv - 1; j<glv+2; j++)
			{
				if(polja.at(i).at(j) == Polje::Mina) 
					brojac1++;
				if(i == glh && j == glv && polja.at(i).at(j) == Polje::Mina) 
					brojac1 -= 1;
			}
		}
		niz_okolina.push_back(brojac1);
		
		for(int i=gsh - 1; i<gsh+2; i++)
		{
			for(int j=gsv - 1; j<gsv+2; j++)
			{
				if(polja.at(i).at(j) == Polje::Mina) 
					brojac2++;
				if(i == gsh && j == gsv && polja.at(i).at(j) == Polje::Mina) 
					brojac2 -= 1;
			}
		}
		niz_okolina.push_back(brojac2);
		
		for(int i=gdh -1; i<gdh+2; i++)
		{
			for(int j=gdv - 1; j<gdv+2; j++)
			{
				if(polja.at(i).at(j) == Polje::Mina) 
					brojac3++;
				if(i == gdh && j == gdv && polja.at(i).at(j) == Polje::Mina) 
					brojac3 -= 1;
			}
		}
		niz_okolina.push_back(brojac3);
		
		for(int i=slh - 1; i<slh+2; i++)
		{
			for(int j=slv -1; j<slv+2; j++)
			{
				if(polja.at(i).at(j) == Polje::Mina) 
					brojac4++;
				if(i == slh && j == slv && polja.at(i).at(j) == Polje::Mina) 
					brojac4 -= 1;
			}
		}
		niz_okolina.push_back(brojac4);
		
		for(int i=tth -1; i<tth+2; i++)
		{
			for(int j=ttv - 1; j<ttv+2; j++)
			{
				if(polja.at(i).at(j) == Polje::Mina) 
					brojac5++;
				if(i == tth && j == ttv && polja.at(i).at(j) == Polje::Mina)  
					brojac5 -= 1;
			}
		}
		niz_okolina.push_back(brojac5);
		
		for(int i=sdh - 1; i<sdh+2; i++)
		{
			for(int j=sdv - 1; j<sdv+2; j++)
			{
				if(polja.at(i).at(j) == Polje::Mina) 
					brojac6++;
				if(i == sdh && j == sdv && polja.at(i).at(j) == Polje::Mina) 
					brojac6 -= 1;
			}
		}
		niz_okolina.push_back(brojac6);
		
		for(int i=dlh - 1; i<dlh+2; i++)
		{
			for(int j=dlv -1; j<dlv+2; j++)
			{
				if(polja.at(i).at(j) == Polje::Mina) 
					brojac7++;
				if(i == dlh && j == dlv && polja.at(i).at(j) == Polje::Mina) 
					brojac7 -= 1;
			}
		}
		niz_okolina.push_back(brojac7);
		
		for(int i=dsh-1; i<dsh+2; i++)
		{
			for(int j=dsv - 1; j<dsv+2; j++)
			{
				if(polja.at(i).at(j) == Polje::Mina) 
					brojac8++;
				if(i == dsh && j == dsv && polja.at(i).at(j) == Polje::Mina) 
					brojac8 -= 1;
			}
		}
		niz_okolina.push_back(brojac8);
		
		for(int i=ddh - 1; i<ddh+2; i++)
		{
			for(int j=ddv - 1; j<ddv+2; j++)
			{
				if(polja.at(i).at(j) == Polje::Mina) 
					brojac9++;
				if(i == ddh && j == ddv && polja.at(i).at(j) == Polje::Mina) 
					brojac9 -= 1;
			}
		}
		niz_okolina.push_back(brojac9);
		
		Matrica MatricaPonavljanja = Kreiraj(3,3);
		int h(0);
		for(int i=0; i<3; i++)
		{
			for(int j=0; j<3; j++)
			{
				MatricaPonavljanja.at(i).at(j) = niz_okolina.at(h);
				h++;
			}
		}
		return MatricaPonavljanja;	
	}
}

void BlokirajPolje(Tabla &polja, int x, int y)
{
	if(x<0 || x > polja.size() || y < 0 || y > polja.at(0).size())
		throw std::domain_error("Polje (x,y) ne postoji");
	
	for(int i=0; i<polja.size(); i++)
	{
		for(int j=0; j<polja.at(i).size(); j++)
		{
			if(i == x && j == y)
			{
				if(polja.at(i).at(j) == Polje::Prazno) polja.at(i).at(j) = Polje::BlokiranoPrazno;
				if(polja.at(i).at(j) == Polje::Posjeceno) polja.at(i).at(j) = Polje::BlokiranoPosjeceno;
				if(polja.at(i).at(j) == Polje::Mina) polja.at(i).at(j) = Polje::BlokiranoMina;
			}
		}
	}
}

void DeblokirajPolje(Tabla &polja, int x, int y)
{
	if(x < 0 || x > polja.size() || y < 0 || y > polja.at(0).size())
		throw std::domain_error("Polje (x,y) ne postoji");
		
	for(int i=0; i<polja.size(); i++)
	{
		for(int j=0; j<polja.at(i).size(); j++)
		{
			if(i == x && j == y)
			{
				if(polja.at(i).at(j) == Polje::BlokiranoPrazno) polja.at(i).at(j) = Polje::Prazno;
				if(polja.at(i).at(j) == Polje::BlokiranoPosjeceno) polja.at(i).at(j) = Polje::Posjeceno;
				if(polja.at(i).at(j) == Polje::BlokiranoMina) polja.at(i).at(j) = Polje::Mina;
			}
		}
	}
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer)
{
	Status s;
	for(int i=0; i<polja.size(); i++)
	{
		for(int j=0; j<polja.at(i).size(); j++)
		{
			if(i == x && j == y)
				polja.at(i).at(j) = Polje::Posjeceno;
		}
	}
	for(int i=0; i<polja.size(); i++)
	{
		for(int j=0; polja.at(i).size(); j++)
		{
			if(smjer == Smjerovi::GoreLijevo)
			{
				if(polja.at(i).at(j) == Polje::Mina)
				{
					s = Status::KrajPoraz;
					return s;
				}
				else if (polja.at(i).at(j) == Polje::Prazno)
				{
					x -=1;
					y -=1;
					s = Status::NijeKraj;
					return s;
				}
				else if((i == polja.size()-1 || j == polja.at(i).size()-1) && polja.at(i).at(j) == Polje::Prazno)
				{
					s = Status::KrajPobjeda;
					return s;
				}
			}
			else if (smjer == Smjerovi::Gore)
			{
				if(polja.at(i).at(j) == Polje::Mina)
				{
					s = Status::KrajPoraz;
					return s;
				}
				else if(polja.at(i).at(j) == Polje::Prazno)
				{
					x -= 1;
					s = Status::NijeKraj;
					return s;
				}
				else if((i == polja.size()-1 || j == polja.at(i).size()-1) && polja.at(i).at(j) == Polje::Prazno)
				{
					s = Status::KrajPobjeda;
					return s;
				}
			}
			else if(smjer == Smjerovi::GoreDesno)
			{
				if(polja.at(i).at(j) == Polje::Mina)
				{
					s = Status::KrajPoraz;
					return s;
				}
				else if(polja.at(i).at(j) == Polje::Prazno)
				{
					s = Status::NijeKraj;
					return s;
				}
				else if((i == polja.size()-1 || j == polja.at(i).size()-1) && polja.at(i).at(j) == Polje::Prazno)
				{
					s = Status::KrajPobjeda;
					return s;
				}
			}
			else if(smjer == Smjerovi::Lijevo)
			{
				if(polja.at(i).at(j) == Polje::Mina)
				{
					s = Status::KrajPoraz;
					return s;
				}
				else if(polja.at(i).at(j) == Polje::Prazno)
				{
					y -= 1;
					s = Status::NijeKraj;
					return s;
				}
				else if((i == polja.size()-1 || j == polja.at(i).size()-1) && polja.at(i).at(j) == Polje::Prazno)
				{
					s = Status::KrajPobjeda;
					return s;
				}
			}
			else if(smjer == Smjerovi::Desno)
			{
				if(polja.at(i).at(j) == Polje::Mina)
				{
					s = Status::KrajPoraz;
					return s;
				}
				else if(polja.at(i).at(j) == Polje::Prazno)
				{
					x += 1;
					s = Status::NijeKraj;
					return s;
				}
				else if((i == polja.size()-1 || j == polja.at(i).size()-1) && polja.at(i).at(j) == Polje::Prazno)
				{
					s = Status::KrajPobjeda;
					return s;
				}
			}
			else if(smjer == Smjerovi::DoljeLijevo)
			{
				if(polja.at(i).at(j) == Polje::Mina)
				{
					s = Status::KrajPoraz;
					return s;
				}
				else if(polja.at(i).at(j) == Polje::Prazno)
				{
					x += 1;
					y -= 1;
					s = Status::NijeKraj;
					return s;
				}
				else if((i == polja.size()-1 || j == polja.at(i).size()-1) && polja.at(i).at(j) == Polje::Prazno)
				{
					s = Status::KrajPobjeda;
					return s;
				}
			}
			else if(smjer == Smjerovi::Dolje)
			{
				if(polja.at(i).at(j) == Polje::Mina)
				{
					s= Status::KrajPoraz;
					return s;
				}
				else if(polja.at(i).at(j) == Polje::Prazno)
				{
					x += 1;
					s = Status::NijeKraj;
					return s;
				}
				else if((i == polja.size()-1 || j == polja.at(i).size()-1) && polja.at(i).at(j) == Polje::Prazno)
				{
					s = Status::KrajPobjeda;
					return s;
				}
			}
			else if(smjer == Smjerovi::DoljeDesno)
			{
				if(polja.at(i).at(j) == Polje::Mina)
				{
					s = Status::KrajPoraz;
					return s;
				}
				else if(polja.at(i).at(j) == Polje::Prazno)
				{
					x += 1;
					y += 1;
					s = Status::NijeKraj;
					return s;
				}
				else if((i == polja.size()-1 || j == polja.at(i).size()-1) && polja.at(i).at(j) == Polje::Prazno)
				{
					s = Status::KrajPobjeda;
					return s;
				}
			}
		}
	}
}

Status Idi (Tabla &polja, int &x, int &y, int X, int Y)
{
	if(X < 0 || X > polja.size() || Y < 0 || Y > polja.at(0).size())
		throw std::out_of_range ("Izlazak van Igrace table");
		
	for(int i=0; i<polja.size(); i++ )
	{
		for(int j=0; j<polja.at(i).size(); j++)
		{
			if(i == X && j == Y)
			{
				if(polja.at(i).at(j) == Polje::BlokiranoPrazno)
					throw std::logic_error("Blokirano polje");
			
				if(polja.at(i).at(j) == Polje::BlokiranoPosjeceno)
					throw std::logic_error("Blokirano polje");
					
				if(polja.at(i).at(j) == Polje::BlokiranoMina)
					throw std::logic_error("Blokirano polje");
					
					x = X;
					y = Y;
			}
		}
	}
}

bool UnesiKomandu(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska)
{
	std::string KOM;
	std::string NovKOM;
	std::getline (std::cin, KOM);
	
	for(int i=0; i<KOM.length(); i++)
	{
		while(KOM[i] == ' ') 
			i++;
		
		while(KOM[i] != ' ' && i < KOM.length())
		{
			NovKOM.push_back(KOM[i]);
			i++;
		}
	}
	for(int i=0; i<NovKOM.length(); i++)
	{
        if(NovKOM[i] == 'P' && NovKOM[i+1] == '1')
        {
            komanda = Komande::PomjeriJednoMjesto;
            
            if(NovKOM[i+2] == 'G' && NovKOM[i+3] == 'L')
            {
                smjer = Smjerovi::GoreLijevo;
                return true;
            }
            else if(NovKOM[i+2] == 'G') 
            {
                smjer = Smjerovi::Gore;
                return true;
            }
            else if(NovKOM[i+2] == 'G' && NovKOM[i+3] == 'D')
            {
                smjer = Smjerovi::GoreDesno;
                return true;
            }
            else if(NovKOM[i+2] == 'D')
            {
                smjer = Smjerovi::Desno;
                return true;
            }
            else if(NovKOM[i+2] == 'D' && NovKOM[i+3] == 'o' && NovKOM[i+4] == 'D')
            {
                smjer = Smjerovi::DoljeDesno;
                return true;
            }
            else if(NovKOM[i+2] == 'D' && NovKOM[i+3] == 'o') 
            {
                smjer = Smjerovi::Dolje;
                return true;
            }
            else if(NovKOM[i+2] == 'D' && NovKOM[i+3] == 'o' && NovKOM[i+4] == 'L')
            {
                smjer = Smjerovi::DoljeLijevo;
                return true;
            }
            else if(NovKOM[i+2] == 'L')
            {
                smjer = Smjerovi::Lijevo;
                return true;
            }
            else{
                greska = KodoviGresaka::PogresnaKomanda;
                return false;
            }
        }
        else if(NovKOM[i] == 'P' && NovKOM[i+1] == '>')
        {
            komanda = Komande::PomjeriDalje;
            if(NovKOM[i+2] >= '0' && NovKOM[i+2] < '9'
            && NovKOM[i+3] >= '0' && NovKOM[i+3]<='9')
            {
                x = NovKOM[i+2];
                y = NovKOM[i+3];
                return true;
            }
            else if(!(NovKOM[i+2] >= '0' && NovKOM[i+2] <= '9') ||
            		!(NovKOM[i+3] >= '0' && NovKOM[i+3] <= '9'))
            		{
                greska = KodoviGresaka::NeispravanParametar;
                return false;
            }
            else{
                greska = KodoviGresaka::NedostajeParametar;
                return false;
            }
        }
        else if(NovKOM[i] == 'B')
        {
            komanda = Komande::Blokiraj;
            if(NovKOM[i+1] >= '0' && NovKOM[i+1] <= '9' 
            && NovKOM[i+2] >= '0' && NovKOM[i+2] <= '9')
            {
                x = NovKOM[i+1];
                y = NovKOM[i+2];
                return true;
            }
            else if(!(NovKOM[i+1] >= '0' && NovKOM[i+1] <= '9') ||
            		!(NovKOM[i+2] >= '0' && NovKOM[i+2] <= '9'))
            		{
                greska = KodoviGresaka::NeispravanParametar;
                return false;
            }
            else
            {
                greska = KodoviGresaka::NedostajeParametar;
                return false;
            }
        }
        else if(NovKOM[i] == 'D')
        {
            komanda = Komande::Deblokiraj;
            if(NovKOM[i+1] >= '0' && NovKOM[i+1] <= '9' 
            && NovKOM[i+2] >= '0' && NovKOM[i+2] <= '9')
            {
                x = NovKOM[i+1];
                y = NovKOM[i+2];
                return true;
            }
            else if(!(NovKOM[i+1] >= '0' && NovKOM[i+1] <= '9') ||
            		!(NovKOM[i+2] >= '0' && NovKOM[i+2] <= '9'))
            		{
                greska = KodoviGresaka::NeispravanParametar;
                return false;
            }
            else
            {
                greska = KodoviGresaka::NedostajeParametar;
                return false;
            }
        }
        if(NovKOM[i]== 'P' && NovKOM[i+1] == 'O')
        {
            komanda = Komande::PrikaziOkolinu;
            if((NovKOM[i+2] >= 'A' && NovKOM[i+2] <= 'Z') ||
            (NovKOM[i+2] >= '0' && NovKOM[i+2] <= '9'))
            {
                greska = KodoviGresaka::SuvisanParametar;
            }
        }
        if(NovKOM[i] == 'Z')
        {
            komanda = Komande::ZavrsiIgru;
            if(NovKOM[i+1] == '\0')
            {
                return true;
            }
            else if((NovKOM[i+1] >= 'A' && NovKOM[i+1] <= 'Z') ||
            		(NovKOM[i+1] >= '0' && NovKOM[i+1] <= '9'))
            		{
                greska = KodoviGresaka::SuvisanParametar;
                return false;
            }
        }
        if(NovKOM[i] == 'K')
        {
            komanda = Komande::KreirajIgru;
            if(NovKOM[i+1] == '\0')
                return true;
            
            else if((NovKOM[i+1] >= 'A' && NovKOM[i+1] <= 'Z') ||
            		(NovKOM[i+1] >= '0' && NovKOM[i+1] <= '9'))
            		{
                greska = KodoviGresaka::SuvisanParametar;
                return false;
            }
        }
    }
}


void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x=0, int p_y=0)
{
	if(komanda == Komande::PomjeriJednoMjesto || komanda == Komande::PomjeriDalje)
	{
		std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")";
		Status status = Idi(polja, x, y, p_smjer);
		if(status == Status::KrajPobjeda) 
			std::cout << "Bravo, obisli ste sva sigurna polja";
			
		if(status == Status::KrajPoraz)
		{
			std::cout << "Nagazili ste na minu";
			for(int i=0; i<polja.size(); i++)
			{
				for(int j=0; j<polja.at(i).size(); j++)
					polja.at(i).at(j) == Polje::Prazno;
			}
		}
	}
	else if(komanda == Komande::PrikaziOkolinu)
	{
		Matrica P = PrikaziOkolinu(polja, x, y);
		for(int i=0; i<P.size(); i++)
		{
			for(int j=0; j<P.at(i).size(); j++) std::cout << P.at(i).at(j) << " ";
		
		std::cout << std:: endl;
		}
	}
	else if(komanda == Komande::ZavrsiIgru)
	{
		for(int i=0; i<polja.size(); i++)
		{
			for(int j=0; j<polja.at(i).size(); j++) polja.at(i).at(j) = Polje::Prazno;
		}
		throw std::runtime_error ("Igra zavrsena");
	}
	else if(komanda == Komande::KreirajIgru)
	{
		std::complex<int> z;
		std::vector<std::complex<int>> v;
		int n;
		std::cout << "Unesite broj polja: " << std::endl;
		std::cin >> n;
		std::cout << "Unesite pozicije mina: " << std::endl;
		while(std::cin.peek() != '.')
		{
			std::cin >> z;
			if(real(z)>n || imag(z) > n) std::cout << "Greska, unesite ponovo!";
		}
	}
}

int main ()
{
	int n;
	std::cout << "Unesite broj polja: ";
	std::cin >> n;
	std::vector<std::vector<int>> mine;
	int x, y;
	char znak { ')' };
	std::cout << "Unesite poziciju mina: ";
	while(znak == ')')
	{
		std::cin >> znak;
		if(znak != '(')
		{
			if(znak == '.') break;
			std::cin.clear();
			std::cin.ignore(300000, '\n');
			std::cout << "Greska unesite ponovo!";
			znak = ')';
			continue;
		}
		std::cin >> x;
		std::cin >> znak;
		if(znak != ',' || x >= n)
		{
			if(znak == '.') break;
			std::cin.clear();
			std::cin.ignore(30000, '\n');
			std::cout << "Greska unesite ponovo!";
			znak = ')';
			continue;
		}
		
		std::cin >> y;
		std::cin >> znak;
		if(znak == ')' && y < n)
		{
			std::vector<int> m;
			m.push_back(x);
			m.push_back(y);
			mine.push_back(m);
			continue;
		}
		else
		{
			if(znak == '.') break;
			std::cin.clear();
			std::cin.ignore(30000, '\n');
			std::cout << "Greska unesite ponovo!";
			znak = ')';
			continue;
		}
	}
	
	Tabla tab;
	
	try{
		tab = KreirajIgru(n, mine);
	}
	catch(std::domain_error izuzetak)
	{
		std::cout << izuzetak.what() << std::endl;
	}
	
	std::vector<std::vector<int>> okolina;
	std::cout << "Unesite koordinate tacke za trazenje okoline: ";
	std::cin >> x >> y;
	
	try{
		okolina = PrikaziOkolinu(tab, x, y);
		BlokirajPolje(tab, x, y);
	}
	catch(std::domain_error e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
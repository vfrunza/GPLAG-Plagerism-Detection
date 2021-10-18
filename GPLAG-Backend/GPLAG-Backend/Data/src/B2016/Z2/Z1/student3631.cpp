/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include<iostream>
#include<vector>
#include<stdexcept>
#include<string>
#include<complex>
#include<sstream>

using std::complex;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::getline;

enum class Polje {Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina};
enum class Smjerovi {GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo};
enum class Status {NijeKraj, KrajPoraz, KrajPobjeda};
enum class KodoviGresaka {PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar};
enum class Komande {PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru};

typedef std::vector<std::vector<Polje>> Tabla;

int br_mina(0);
int br_pos(0);
int br_blok(0);

// Funkcija KreirajIgru kreira igracu tablu
Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine)
{
	Tabla tabla(n, std::vector<Polje>(n, Polje::Prazno));
	
	for(int i=0; i<mine.size(); i++)
	{
		if(mine[i].size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
	}
	for(int i=0; i<mine.size(); i++)
	{
		for(int j=0; j<mine[i].size(); j++)
		{
			if(mine[i][j]<0 || mine[i][j]>=n) throw std::domain_error("Ilegalne pozicije mina");
		}
	}
	for(int i=0; i<mine.size(); i++)
	{
		int x, y;
		
		x=mine[i][0];
		y=mine[i][1];
		if(x==0 && y==0) continue;
		tabla[x][y]=Polje::Mina;
	}
	for(int i=0; i<tabla.size(); i++)
	{
		for(int j=0; j<tabla[i].size(); j++)
		{
			if(tabla[i][j]==Polje::Mina) br_mina++;
		}
	}
	
	return tabla;
}

template <typename T> 
std::string PretvoriUString(T x) 
{
     std::ostringstream s; 
     s << x; 
     return s.str();
} 

// Funkcija PrikaziOkolinu daje broj mina u neposrednom susjedstvu
// svih polja oko polja (x,y) koji su parametri funkcije
vector<vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y)
{
	string s;
	string x_s(PretvoriUString(x));
	string y_s(PretvoriUString(y));
	s="Polje (" + x_s + "," + y_s + ") ne postoji";
	if(x>=polja.size()) throw std::domain_error(s);
	for(int i=0; i<polja.size(); i++)
		if(polja[i].size()<=y) throw std::domain_error(s);
	std::vector<std::vector<int>> mat;
	
	for(int i=x-1; i<=x+1; i++)
	{
		std::vector<int> pom_vek;
		for(int j=y-1; j<=y+1; j++)
		{
			int brojac(0);
			
			if(i==0 && j==0)
			{
				if(polja.at(i+1).at(j)==Polje::Mina) brojac++;
				if(polja.at(i+1).at(j+1)==Polje::Mina) brojac++;
				if(polja.at(i).at(j+1)==Polje::Mina) brojac++;
			}
			if(i==0 && j>0 && j<polja[0].size()-1)
			{
				if(polja.at(i).at(j+1)==Polje::Mina) brojac++;
				if(polja.at(i).at(j-1)==Polje::Mina) brojac++;
				if(polja.at(i+1).at(j+1)==Polje::Mina) brojac++;
				if(polja.at(i+1).at(j-1)==Polje::Mina) brojac++;
				if(polja.at(i+1).at(j)==Polje::Mina) brojac++;
			}
			if(i==0 && j==polja[0].size()-1)
			{
				if(polja.at(i+1).at(j)==Polje::Mina) brojac++;
				if(polja.at(i+1).at(j-1)==Polje::Mina) brojac++;
				if(polja.at(i).at(j-1)==Polje::Mina) brojac++;
			}
			if(j==polja[0].size()-1 && i>0 && i<polja.size()-1)
			{
				if(polja.at(i-1).at(j)==Polje::Mina) brojac++;
				if(polja.at(i-1).at(j-1)==Polje::Mina) brojac++;
				if(polja.at(i).at(j-1)==Polje::Mina) brojac++;
				if(polja.at(i+1).at(j-1)==Polje::Mina) brojac++;
				if(polja.at(i+1).at(j)==Polje::Mina) brojac++;
			}
			if(i==polja.size()-1 && j==polja[0].size()-1)
			{
				if(polja.at(i-1).at(j)==Polje::Mina) brojac++;
				if(polja.at(i-1).at(j-1)==Polje::Mina) brojac++;
				if(polja.at(i).at(j-1)==Polje::Mina) brojac++;
			}
			if(i==polja.size()-1 && j>0 && j<polja[0].size()-1)
			{
				if(polja.at(i-1).at(j)==Polje::Mina) brojac++;
				if(polja.at(i-1).at(j+1)==Polje::Mina) brojac++;
				if(polja.at(i).at(j+1)==Polje::Mina) brojac++;
				if(polja.at(i-1).at(j-1)==Polje::Mina) brojac++;
				if(polja.at(i).at(j-1)==Polje::Mina) brojac++;
			}
			if(i==polja.size()-1 && j==0)
			{
				if(polja.at(i-1).at(j)==Polje::Mina) brojac++;
				if(polja.at(i-1).at(j+1)==Polje::Mina) brojac++;
				if(polja.at(i).at(j+1)==Polje::Mina) brojac++;
			}
			if(i>0 && i<polja.size()-1 && j==0)
			{
				if(polja.at(i-1).at(j)==Polje::Mina) brojac++;
				if(polja.at(i+1).at(j)==Polje::Mina) brojac++;
				if(polja.at(i+1).at(j+1)==Polje::Mina) brojac++;
				if(polja.at(i).at(j+1)==Polje::Mina) brojac++;
				if(polja.at(i-1).at(j+1)==Polje::Mina) brojac++;
			}
			if(i>=1 && j>=1 && i<polja.size()-1 && j<polja[0].size()-1)
			{
				if(polja.at(i-1).at(j-1)==Polje::Mina) brojac++;
				if(polja.at(i-1).at(j)==Polje::Mina) brojac++;
				if(polja.at(i-1).at(j+1)==Polje::Mina) brojac++;
				if(polja.at(i).at(j-1)==Polje::Mina) brojac++;
				if(polja.at(i+1).at(j-1)==Polje::Mina) brojac++;
				if(polja.at(i).at(j+1)==Polje::Mina) brojac++;
				if(polja.at(i+1).at(j)==Polje::Mina) brojac++;
				if(polja.at(i+1).at(j+1)==Polje::Mina) brojac++;
			}
			pom_vek.push_back(brojac);
		}
		mat.push_back(pom_vek);
	}
	
	return mat;
}

// Funkcija BlokirajPolje oznacava polje cije su koordinate prosljedjuju putem 
// parametara x i y kao neaktivno, tako da se igrac na to polje vise ne moze pomjerati
void BlokirajPolje(Tabla &polja, int x, int y)
{
	string s;
	string x_s(PretvoriUString(x));
	string y_s(PretvoriUString(y));
	s="Polje (" + x_s + "," + y_s + ") ne postoji";
	if(x>=polja.size() || y>=polja[0].size()) throw std::domain_error(s);
	if(polja[x][y]==Polje::Prazno) 
	{
		polja[x][y]=Polje::BlokiranoPrazno;
		br_blok++;
	}
	if(polja[x][y]==Polje::Posjeceno) polja[x][y]=Polje::BlokiranoPosjeceno;
	if(polja[x][y]==Polje::Mina) 
	{
		polja[x][y]=Polje::BlokiranoMina;
		br_blok++;
		br_mina--;
	}
	
	return;
}

// Funkcija DeblokirajPolje oznacava polje cije su koordinate prosljedjuju putem 
// parametara x i y kao aktivno, ako je to polje prethodno bilo blokirano
void DeblokirajPolje(Tabla &polja, int x, int y)
{
	string s;
	string x_s(PretvoriUString(x));
	string y_s(PretvoriUString(y));
	s="Polje (" + x_s + "," + y_s + ") ne postoji";
	if(x>=polja.size() || y>=polja[0].size()) throw std::domain_error(s);
	if(polja[x][y]==Polje::BlokiranoPrazno) 
	{
		polja[x][y]=Polje::Prazno;
		br_blok--;
	}
	if(polja[x][y]==Polje::BlokiranoPosjeceno) polja[x][y]=Polje::Posjeceno;
	if(polja[x][y]==Polje::BlokiranoMina) 
	{
		polja[x][y]=Polje::Mina;
		br_blok--;
		br_mina++;
	}
	
	return;
}

// Funkcija Idi na osnovu trenutne pozicije igraca te smjera koji je poslan
// funkciji kao parametar pomjera igraca za jedno polje u datom smjeru
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer)
{
	
	if(x==0 && y==0 && (smjer==Smjerovi::GoreLijevo || smjer==Smjerovi::GoreDesno || smjer==Smjerovi::Gore || smjer==Smjerovi::Lijevo || smjer==Smjerovi::DoljeLijevo)) throw std::out_of_range("Izlazak van igrace table");
	if(x==0 && y==polja[0].size()-1 && (smjer==Smjerovi::GoreLijevo || smjer==Smjerovi::GoreDesno || smjer==Smjerovi::Gore || smjer==Smjerovi::Desno || smjer==Smjerovi::DoljeDesno)) throw std::out_of_range("Izlazak van igrace table");
	if(x==polja.size()-1 && y==polja[0].size()-1 && (smjer==Smjerovi::DoljeLijevo || smjer==Smjerovi::DoljeDesno || smjer==Smjerovi::Dolje || smjer==Smjerovi::Desno || smjer==Smjerovi::GoreDesno)) throw std::out_of_range("Izlazak van igrace table");
	if(x==polja.size()-1 && y==0 && (smjer==Smjerovi::DoljeLijevo || smjer==Smjerovi::DoljeDesno || smjer==Smjerovi::Dolje || smjer==Smjerovi::Lijevo || smjer==Smjerovi::GoreLijevo)) throw std::out_of_range("Izlazak van igrace table");
	if(x==0 && y>0 && y<polja[0].size()-1 && (smjer==Smjerovi::GoreLijevo || smjer==Smjerovi::GoreDesno || smjer==Smjerovi::Gore)) throw std::out_of_range("Izlazak van igrace table");
	if(y==polja[0].size()-1 && x>0 && x<polja.size()-1 && (smjer==Smjerovi::DoljeDesno || smjer==Smjerovi::Desno || smjer==Smjerovi::GoreDesno)) throw std::out_of_range("Izlazak van igrace table");
	if(x==polja.size() && y>0 && y<polja[0].size()-1 && (smjer==Smjerovi::DoljeLijevo || smjer==Smjerovi::DoljeDesno || smjer==Smjerovi::Dolje)) throw std::out_of_range("Izlazak van igrace table");
	if(y==polja[0].size()-1 && x>0 && x<polja.size()-1 && (smjer==Smjerovi::DoljeDesno || smjer==Smjerovi::Desno || smjer==Smjerovi::GoreDesno)) throw std::out_of_range("Izlazak van igrace table");
	if(y==0 && x>0 && x<polja.size()-1 && (smjer==Smjerovi::DoljeLijevo || smjer==Smjerovi::Lijevo || smjer==Smjerovi::GoreLijevo)) throw std::out_of_range("Izlazak van igrace table");
	if(smjer==Smjerovi::Gore)
	{
		if(polja[x-1][y]==Polje::Mina)
		{
			for(int k=0; k<polja.size(); k++)
			{
				for(int l=0; l<polja[k].size(); l++)
				{
					polja[k][l]=Polje::Prazno;
				}
			}
			br_pos=0;
			br_mina=0;
			br_blok=0;
			return Status::KrajPoraz;
		}
		else if(polja[x-1][y]==Polje::BlokiranoPosjeceno || polja[x-1][y]==Polje::BlokiranoPrazno || polja[x-1][y]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		else if(polja[x-1][y]==Polje::Posjeceno) 
		{
			polja[x][y]=Polje::Posjeceno;
			x=x-1;
		}
		else if(polja[x-1][y]==Polje::Prazno)
		{
			polja[x][y]=Polje::Posjeceno;
			x=x-1;
			br_pos++;
			if(br_pos==polja.size()*polja.size()-br_mina-br_blok-1) 
			{
				return Status::KrajPobjeda;
			}
		}
		else return Status::NijeKraj;
	}
	
	if(smjer==Smjerovi::Dolje)
	{
		if(polja[x+1][y]==Polje::Mina)
		{
			for(int k=0; k<polja.size(); k++)
			{
				for(int l=0; l<polja[k].size(); l++)
				{
					polja[k][l]=Polje::Prazno;
				}
			}
			br_pos=0;
			br_mina=0;
			br_blok=0;
			return Status::KrajPoraz;
		}
		else if(polja[x+1][y]==Polje::BlokiranoPosjeceno || polja[x+1][y]==Polje::BlokiranoPrazno || polja[x+1][y]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		else if(polja[x+1][y]==Polje::Posjeceno) 
		{
			polja[x][y]=Polje::Posjeceno;
			x=x+1;
		}
		else if(polja[x+1][y]==Polje::Prazno)
		{
			polja[x][y]=Polje::Posjeceno;
			x=x+1;
			br_pos++;
			if(br_pos==polja.size()*polja.size()-br_mina-br_blok-1) 
			{
				return Status::KrajPobjeda;
			}
		}
		else return Status::NijeKraj;
	}
	
	if(smjer==Smjerovi::Desno)
	{
		if(polja[x][y+1]==Polje::Mina)
		{
			for(int k=0; k<polja.size(); k++)
			{
				for(int l=0; l<polja[k].size(); l++)
				{
					polja[k][l]=Polje::Prazno;
				}
			}
			br_pos=0;
			br_mina=0;
			br_blok=0;
			return Status::KrajPoraz;
		}
		else if(polja[x][y+1]==Polje::BlokiranoPosjeceno || polja[x][y+1]==Polje::BlokiranoPrazno || polja[x][y+1]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		else if(polja[x][y+1]==Polje::Posjeceno) 
		{
			polja[x][y]=Polje::Posjeceno;
			y=y+1;
		}
		else if(polja[x][y+1]==Polje::Prazno)
		{
			polja[x][y]=Polje::Posjeceno;
			y=y+1;
			br_pos++;
			if(br_pos==polja.size()*polja.size()-br_mina-br_blok-1) 
			{
				return Status::KrajPobjeda;
			}
		}
		else return Status::NijeKraj;
	}
	
	if(smjer==Smjerovi::Lijevo)
	{
		if(polja[x][y-1]==Polje::Mina)
		{
			for(int k=0; k<polja.size(); k++)
			{
				for(int l=0; l<polja[k].size(); l++)
				{
					polja[k][l]=Polje::Prazno;
				}
			}
			br_pos=0;
			br_mina=0;
			br_blok=0;
			return Status::KrajPoraz;
		}
		else if(polja[x][y-1]==Polje::BlokiranoPosjeceno || polja[x][y-1]==Polje::BlokiranoPrazno || polja[x][y-1]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		else if(polja[x][y-1]==Polje::Posjeceno) 
		{
			polja[x][y]=Polje::Posjeceno;
			y=y-1;
		}
		else if(polja[x][y-1]==Polje::Prazno)
		{
			polja[x][y]=Polje::Posjeceno;
			y=y-1;
			br_pos++;
			if(br_pos==polja.size()*polja.size()-br_mina-br_blok-1) 
			{
				return Status::KrajPobjeda;
			}
		}
		else return Status::NijeKraj;
	}
	
	if(smjer==Smjerovi::GoreLijevo)
	{
		if(polja[x-1][y-1]==Polje::Mina)
		{
			for(int k=0; k<polja.size(); k++)
			{
				for(int l=0; l<polja[k].size(); l++)
				{
					polja[k][l]=Polje::Prazno;
				}
			}
			br_pos=0;
			br_mina=0;
			br_blok=0;
			return Status::KrajPoraz;
		}
		else if(polja[x-1][y-1]==Polje::BlokiranoPosjeceno || polja[x-1][y-1]==Polje::BlokiranoPrazno || polja[x-1][y-1]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		else if(polja[x-1][y-1]==Polje::Posjeceno) 
		{
			polja[x][y]=Polje::Posjeceno;
			y=y-1;
			x=x-1;
		}
		else if(polja[x-1][y-1]==Polje::Prazno)
		{
			polja[x][y]=Polje::Posjeceno;
			y=y-1;
			x=x-1;
			br_pos++;
			if(br_pos==polja.size()*polja.size()-br_mina-br_blok-1) 
			{
				return Status::KrajPobjeda;
			}
		}
		else return Status::NijeKraj;
	}
	
	if(smjer==Smjerovi::GoreDesno)
	{
		if(polja[x-1][y+1]==Polje::Mina)
		{
			for(int k=0; k<polja.size(); k++)
			{
				for(int l=0; l<polja[k].size(); l++)
				{
					polja[k][l]=Polje::Prazno;
				}
			}
			br_pos=0;
			br_mina=0;
			br_blok=0;
			return Status::KrajPoraz;
		}
		else if(polja[x-1][y+1]==Polje::BlokiranoPosjeceno || polja[x-1][y+1]==Polje::BlokiranoPrazno || polja[x-1][y+1]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		else if(polja[x-1][y+1]==Polje::Posjeceno) 
		{
			polja[x][y]=Polje::Posjeceno;
			y=y+1;
			x=x-1;
		}
		else if(polja[x-1][y+1]==Polje::Prazno)
		{
			polja[x][y]=Polje::Posjeceno;
			y=y+1;
			x=x-1;
			br_pos++;
			if(br_pos==polja.size()*polja.size()-br_mina-br_blok-1) 
			{
				return Status::KrajPobjeda;
			}
		}
		else return Status::NijeKraj;
	}
	
	if(smjer==Smjerovi::DoljeLijevo)
	{
		if(polja[x+1][y-1]==Polje::Mina)
		{
			for(int k=0; k<polja.size(); k++)
			{
				for(int l=0; l<polja[k].size(); l++)
				{
					polja[k][l]=Polje::Prazno;
				}
			}
			br_pos=0;
			br_mina=0;
			br_blok=0;
			return Status::KrajPoraz;
		}
		else if(polja[x+1][y-1]==Polje::BlokiranoPosjeceno || polja[x+1][y-1]==Polje::BlokiranoPrazno || polja[x+1][y-1]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		else if(polja[x+1][y-1]==Polje::Posjeceno) 
		{
			polja[x][y]=Polje::Posjeceno;
			y=y-1;
			x=x+1;
		}
		else if(polja[x+1][y-1]==Polje::Prazno)
		{
			polja[x][y]=Polje::Posjeceno;
			y=y-1;
			x=x+1;
			br_pos++;
			if(br_pos==polja.size()*polja.size()-br_mina-br_blok-1) 
			{
				return Status::KrajPobjeda;
			}
		}
		else return Status::NijeKraj;
	}
	if(smjer==Smjerovi::DoljeDesno)
	{
		if(polja[x+1][y+1]==Polje::Mina)
		{
			for(int k=0; k<polja.size(); k++)
			{
				for(int l=0; l<polja[k].size(); l++)
				{
					polja[k][l]=Polje::Prazno;
				}
			}
			br_pos=0;
			br_mina=0;
			br_blok=0;
			return Status::KrajPoraz;
		}
		else if(polja[x+1][y+1]==Polje::BlokiranoPosjeceno || polja[x+1][y+1]==Polje::BlokiranoPrazno || polja[x+1][y+1]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		else if(polja[x+1][y+1]==Polje::Posjeceno) 
		{
			polja[x][y]=Polje::Posjeceno;
			y=y+1;
			x=x+1;
		}
		else if(polja[x+1][y+1]==Polje::Prazno)
		{
			polja[x][y]=Polje::Posjeceno;
			y=y+1;
			x=x+1;
			br_pos++;
			if(br_pos==polja.size()*polja.size()-br_mina-br_blok-1) 
			{
				return Status::KrajPobjeda;
			}
		}
		else return Status::NijeKraj;
	}
	return Status::NijeKraj;
}

// Funkcija Idi na osnovu trenutne pozicije igraca te koordinata novog polja 
// koje su poslane funkciji kao parametri pomjera igraca na to polje
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y)
{
	if(novi_x>=polja.size() || novi_y>=polja[0].size()) throw std::out_of_range("Izlazak van igrace table");
	if(polja[novi_x][novi_y]==Polje::Mina)
	{
		for(int k=0; k<polja.size(); k++)
		{
			for(int l=0; l<polja[k].size(); l++)
			{
				polja[k][l]=Polje::Prazno;
			}
		}
		br_pos=0;
		br_mina=0;
		br_blok=0;
		return Status::KrajPoraz;
	}
	else if(polja[novi_x][novi_y]==Polje::BlokiranoPosjeceno || polja[novi_x][novi_y]==Polje::BlokiranoPrazno || polja[novi_x][novi_y]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
	else if(polja[novi_x][novi_y]==Polje::Posjeceno) 
	{
		polja[x][y]=Polje::Posjeceno;
		x=novi_x;
		y=novi_y;
	}
	else if(polja[novi_x][novi_y]==Polje::Prazno)
	{
		polja[x][y]=Polje::Posjeceno;
		x=novi_x;
		y=novi_y;
		br_pos++;
		if(br_pos==polja.size()*polja.size()-br_mina-br_blok-1) 
		{
			return Status::KrajPobjeda;
		}
	}
	return Status::NijeKraj;
}

// Funkcija PrijaviGresku u zavisnosti od vrijednosti parametra koji joj je proslijedjen
// na ekran ispisuje neki od tekstova koji se mogu javiti kao greska u radu u toku igre
void PrijaviGresku(KodoviGresaka greska)
{
	if(greska==KodoviGresaka::PogresnaKomanda) cout << "Nerazumljiva komanda!" << endl;
	else if(greska==KodoviGresaka::NedostajeParametar) cout << "Komanda trazi parametar koji nije naveden!" << endl;
	else if(greska==KodoviGresaka::NeispravanParametar) cout << "Parametar komande nije ispravan!" << endl;
	else if(greska==KodoviGresaka::SuvisanParametar) cout << "Zadan je suvisan parametar nakon komande!" << endl;
	
	return;
}

// Funkcija UnosKomande omogucuje korisniku programa da zada komandu putem tastature
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska)
{
	string ulaz;
	getline(cin, ulaz);
	
	for(int i=0; i<ulaz.length(); i++)
	{
		string znak=ulaz.substr(i, 1);
		if(znak==" ") continue;
		else if(znak!="P" && znak!="B" && znak!="D" && znak!="Z" && znak!="K")
		{
			greska=KodoviGresaka::PogresnaKomanda;
			return false;
		}
		else if(znak=="P") //prvi znak komande
		{
			i++;
			znak=ulaz.substr(i, 1);
			
			if(znak!="1" && znak!=">" && znak!="O")
			{
				greska=KodoviGresaka::PogresnaKomanda;
				return false;
			}
			else if(znak=="1") // drugi znak komande
			{
				int j;
				for(j=i+1; j<ulaz.length(); j++)
				{
					znak=ulaz.substr(j, 1);
					if(znak==" ") continue;
					else if(znak!="G" && znak!="D" && znak!="L")
					{
						greska=KodoviGresaka::NeispravanParametar;
						return false;
					}
					else if(znak=="G") // prvi znak smjera
					{
						j++;
						znak=ulaz.substr(j, 1);
						
						if(znak!="L" && znak!=" " && znak!="D" && znak!="")
						{
							greska=KodoviGresaka::NeispravanParametar;
							return false;
						}
						else if(znak=="L") //drugi znak smjera
						{
							for(int k=j+1; k<ulaz.length(); k++)
							{
								znak=ulaz.substr(k, 1);
								if(znak==" ") continue;
								else if(znak=="") break;
								else
								{
									greska=KodoviGresaka::SuvisanParametar;
									return false;
								}
							}
							komanda=Komande::PomjeriJednoMjesto;
							smjer=Smjerovi::GoreLijevo;
							return true;
						}
						else if(znak==" ") // drugi znak smjera
						{
							for(int k=j+1; k<ulaz.length(); k++)
							{
								znak=ulaz.substr(k, 1);
								if(znak==" ") continue;
								else if(znak=="") break;
								else
								{
									greska=KodoviGresaka::SuvisanParametar;
									return false;
								}
							}
							komanda=Komande::PomjeriJednoMjesto;
							smjer=Smjerovi::Gore;
							return true;
						}
						else if(znak=="")
						{
							komanda=Komande::PomjeriJednoMjesto;
							smjer=Smjerovi::Gore;
							return true;
						}
						else if(znak=="D") // drugi znak smjera
						{
							for(int k=j+1; k<ulaz.length(); k++)
							{
								znak=ulaz.substr(k, 1);
								if(znak==" ") continue;
								else if(znak=="") break;
								else
								{
									greska=KodoviGresaka::SuvisanParametar;
									return false;
								}
							}
							komanda=Komande::PomjeriJednoMjesto;
							smjer=Smjerovi::GoreDesno;
							return true;
						}
					}
					else if(znak=="L") // prvi znak smjera
					{
						for(int k=j+1; k<ulaz.length(); k++)
						{
							znak=ulaz.substr(k, 1);
							if(znak==" ") continue;
							else if(znak=="") break;
							else
							{
								greska=KodoviGresaka::SuvisanParametar;
								return false;
							}
						}
						komanda=Komande::PomjeriJednoMjesto;
						smjer=Smjerovi::Lijevo;
						return true;
					}
					else if(znak=="D") // prvi znak smjera
					{
						j++;
						znak=ulaz.substr(j, 1);
						if(znak!=" " && znak!="o" && znak!="")
						{
							greska=KodoviGresaka::NeispravanParametar;
							return false;
						}
						else if(znak==" ") // drugi znak smjera
						{
							for(int k=j+1; k<ulaz.length(); k++)
							{
								znak=ulaz.substr(k, 1);
								if(znak==" ") continue;
								else if(znak=="") break;
								else
								{
									greska=KodoviGresaka::SuvisanParametar;
									return false;
								}
							}
							komanda=Komande::PomjeriJednoMjesto;
							smjer=Smjerovi::Desno;
							return true;
						}
						else if(znak=="")
						{
							komanda=Komande::PomjeriJednoMjesto;
							smjer=Smjerovi::Desno;
							return true;
						}
						else if(znak=="o") // drugi znak smjera
						{
							j++;
							znak=ulaz.substr(j, 1);
							if(znak!="D" && znak!="L" && znak!="" && znak!=" ")
							{
								greska=KodoviGresaka::NeispravanParametar;
								return false;
							}
							else if(znak==" ")
							{
								for(int k=j+1; k<ulaz.length(); k++)
								{
									znak=ulaz.substr(k, 1);
									if(znak==" ") continue;
									else if(znak=="") break;
									else
									{
										greska=KodoviGresaka::SuvisanParametar;
										return false;
									}
								}
								komanda=Komande::PomjeriJednoMjesto;
								smjer=Smjerovi::Dolje;
								return true;
							}
							else if(znak=="")
							{
								komanda=Komande::PomjeriJednoMjesto;
								smjer=Smjerovi::Dolje;
								return true;
							}
							else if(znak=="D") //treci znak smjera
							{
								for(int k=j+1; k<ulaz.length(); k++)
								{
									znak=ulaz.substr(k, 1);
									if(znak==" ") continue;
									else if(znak=="") break;
									else
									{
										greska=KodoviGresaka::SuvisanParametar;
										return false;
									}
								}
								komanda=Komande::PomjeriJednoMjesto;
								smjer=Smjerovi::DoljeDesno;
								return true;
							}
							else if(znak=="L") // treci znak smjera
							{
								for(int k=j+1; k<ulaz.length(); k++)
								{
									znak=ulaz.substr(k, 1);
									if(znak==" ") continue;
									else if(znak=="") break;
									else
									{
										greska=KodoviGresaka::SuvisanParametar;
										return false;
									}
								}
								komanda=Komande::PomjeriJednoMjesto;
								smjer=Smjerovi::DoljeLijevo;
								return true;
							}
						}
					}
				}
				if(j==ulaz.length())
				{
					greska=KodoviGresaka::NedostajeParametar;
					return false;
				}
			}
			else if(znak==">") // drugi znak komande
			{
				bool bila_cifra(false);
				string pom_x;
				int j;
				for(j=i+1; j<ulaz.length(); j++)
				{
					znak=ulaz.substr(j, 1);
					
					if(znak!=" " && !(znak>="0" && znak<="9") && bila_cifra==false)
					{
						greska=KodoviGresaka::NeispravanParametar;
						return false;
					}
					else if(znak==" " && bila_cifra==false) continue;
					else if(znak>="0" && znak<="9") // prvi parametar x
					{
						bila_cifra=true;
						pom_x+=znak;
					}
					else if(znak!=" " && !(znak>="0" && znak<="9") && bila_cifra)
					{
						greska=KodoviGresaka::NeispravanParametar;
						return false;
					}
					else if(znak==" " && bila_cifra) // drugi parametar y
					{
						bila_cifra=false;
						string pom_y;
						for(int k=j+1; k<ulaz.length(); k++)
						{
							bila_cifra=false;
							znak=ulaz.substr(k, 1);
						
							if(znak!=" " && !(znak>="0" && znak<="9") && bila_cifra==false)
							{
								greska=KodoviGresaka::NeispravanParametar;
								return false;
							}
							else if(znak==" " && bila_cifra==false) continue;
							else if(znak>="0" && znak<="9")
							{
								bila_cifra=true;
								pom_y+=znak;
							}
							else if(znak!=" " && !(znak>="0" && znak<="9") && bila_cifra)
							{
								greska=KodoviGresaka::NeispravanParametar;
								return false;
							}
							else if(znak==" " && bila_cifra) continue;
							else
							{
								greska=KodoviGresaka::SuvisanParametar;
								return false;
							}
						}
						x=std::stoi(pom_x);
						y=std::stoi(pom_y);
						komanda=Komande::PomjeriDalje;
						return true;
					}
				}
				if(j==ulaz.length())
				{
					greska=KodoviGresaka::NedostajeParametar;
					return false;
				}
			}
			else if(znak=="O") // drugi znak komande
			{
				for(int j=i+1; j<ulaz.length(); j++)
				{
					znak=ulaz.substr(j, 1);
					if(znak==" ") continue;
					else
					{
						greska=KodoviGresaka::SuvisanParametar;
						return false;
					}
				}
				komanda=Komande::PrikaziOkolinu;
				return true;
			}
		}
		else if(znak=="B") // prvi znak komande
		{
			bool bila_cifra(false);
			string pom_x;
			int j;
			for(j=i+1; j<ulaz.length(); j++)
			{
				znak=ulaz.substr(j, 1);
				
				if(znak!=" " && !(znak>="0" && znak<="9") && bila_cifra==false)
				{
					greska=KodoviGresaka::NeispravanParametar;
					return false;
				}
				else if(znak==" " && bila_cifra==false) continue;
				else if(znak>="0" && znak<="9") // prvi parametar x
				{
					bila_cifra=true;
					pom_x+=znak;
					
				}
				else if(znak!=" " && !(znak>="0" && znak<="9") && bila_cifra)
				{
					greska=KodoviGresaka::NeispravanParametar;
					return false;
				}
				else if(znak==" " && bila_cifra) // drugi parametar y
				{
					bila_cifra=false;
					string pom_y;
					for(int k=j+1; k<ulaz.length(); k++)
					{
						bila_cifra=false;
						znak=ulaz.substr(k, 1);
					
						if(znak!=" " && !(znak>="0" && znak<="9") && bila_cifra==false)
						{
							greska=KodoviGresaka::NeispravanParametar;
							return false;
						}
						else if(znak==" " && bila_cifra==false) continue;
						else if(znak>="0" && znak<="9")
						{
							bila_cifra=true;
							pom_y+=znak;
						}
						else if(znak!=" " && !(znak>="0" && znak<="9") && bila_cifra)
						{
							greska=KodoviGresaka::NeispravanParametar;
							return false;
						}
						else if(znak==" " && bila_cifra) continue;
						else
						{
							greska=KodoviGresaka::SuvisanParametar;
							return false;
						}
					}
					x=std::stoi(pom_x);
					y=std::stoi(pom_y);
					komanda=Komande::Blokiraj;
					return true;
				}
			}
			if(j==ulaz.length())
			{
				greska=KodoviGresaka::NedostajeParametar;
				return false;
			}
		}
		else if(znak=="D") // prvi znak komande
		{
			bool bila_cifra(false);
			string pom_x;
			int j;
			for(j=i+1; j<ulaz.length(); j++)
			{
				znak=ulaz.substr(j, 1);
				
				if(znak!=" " && !(znak>="0" && znak<="9") && bila_cifra==false)
				{
					greska=KodoviGresaka::NeispravanParametar;
					return false;
				}
				else if(znak==" " && bila_cifra==false) continue;
				else if(znak>="0" && znak<="9") // prvi parametar x
				{
					bila_cifra=true;
					pom_x+=znak;
				}
				else if(znak!=" " && !(znak>="0" && znak<="9") && bila_cifra)
				{
					greska=KodoviGresaka::NeispravanParametar;
					return false;
				}
				else if(znak==" " && bila_cifra) // drugi parametar y
				{
					bila_cifra=false;
					string pom_y;
					for(int k=j+1; k<ulaz.length(); k++)
					{
						bila_cifra=false;
						znak=ulaz.substr(k, 1);
					
						if(znak!=" " && !(znak>="0" && znak<="9") && bila_cifra==false)
						{
							greska=KodoviGresaka::NeispravanParametar;
							return false;
						}
						else if(znak==" " && bila_cifra==false) continue;
						else if(znak>="0" && znak<="9")
						{
							bila_cifra=true;
							pom_y+=znak;
						}
						else if(znak!=" " && !(znak>="0" && znak<="9") && bila_cifra)
						{
							greska=KodoviGresaka::NeispravanParametar;
							return false;
						}
						else if(znak==" " && bila_cifra) continue;
						else
						{
							greska=KodoviGresaka::SuvisanParametar;
							return false;
						}
					}
					x=std::stoi(pom_x);
					y=std::stoi(pom_y);
					komanda=Komande::Deblokiraj;
					return true;
				}
			}
			if(j==ulaz.length())
			{
				greska=KodoviGresaka::NedostajeParametar;
				return false;
			}
		}
		else if(znak=="Z") // prvi znak komande
		{
			for(int j=i+1; j<ulaz.length(); j++)
			{
				znak=ulaz.substr(j, 1);
				if(znak==" ") continue;
				else
				{
					greska=KodoviGresaka::SuvisanParametar;
					return false;
				}
			}
			komanda=Komande::ZavrsiIgru;
			return true;
		}
		else if(znak=="K") // prvi znak komande
		{
			for(int j=i+1; j<ulaz.length(); j++)
			{
				znak=ulaz.substr(j, 1);
				if(znak==" ") continue;
				else
				{
					greska=KodoviGresaka::SuvisanParametar;
					return false;
				}
			}
			komanda=Komande::KreirajIgru;
			return true;
		}
	}
	return false;
}

// Funkcija IzvrsiKomandu poziva neku od prethodnih funkcija u zavisnosti sta je zadano prvim parametrom funkcije
void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0)
{
	try
	{
		if(komanda==Komande::Blokiraj) BlokirajPolje(polja, p_x, p_y);
		else if(komanda==Komande::Deblokiraj) DeblokirajPolje(polja, p_x, p_y);
		else if(komanda==Komande::PrikaziOkolinu) 
		{
			vector<vector<int>> okolina(PrikaziOkolinu(polja, x, y));
			for(int i=0; i<okolina.size(); i++)
			{
				for(int j=0; j<okolina[i].size(); j++)
				{
					cout << okolina[i][j] << " ";
				}
				cout << endl;
			}
		}
		else if(komanda==Komande::KreirajIgru)
		{
			polja.resize(0);
			if(!cin)
			{
				cin.clear();
				cin.ignore(10000, '\n');
			}
			int n;
			cout << "Unesite broj polja: ";
			do
			{
				cin >> n;
				if(!cin || n<0) 
				{
					cout << "Greska, unesite ponovo!" << endl;
					cin.clear();
					cin.ignore(10000, '\n');
				}
				else 
				{
					cin.ignore(10000, '\n');
					break;
				}
			}while(1);
			vector<vector<int>> mine;
			
			cout << "Unesite pozicije mina: ";
			do
			{
				complex<int> mina{0,0};
				cin >> mina;
				
				if(!cin)
				{
					char znak(getchar());
					if(znak=='.') 
					{
						cin.clear();
						cin.ignore(10000, '\n');
						break;
					}
					else
					{
						cout << "Greska, unesite ponovo!" << endl;
						cin.clear();
						cin.ignore(10000, '\n');
					}
				}
				else if(int(mina.real())>=n || int(mina.imag())>=n || int(mina.real())<0 || int(mina.imag())<0)
				{
					cout << "Greska, unesite ponovo!" << endl;
					cin.ignore(10000, '\n');
				}
				else
				{
					vector<int> pom;
					pom.push_back(int(mina.real()));
					pom.push_back(int(mina.imag()));
					mine.push_back(pom);
					cin.ignore(10000, '\n');
				}
				
			} while(1);
			
			polja=KreirajIgru(n, mine);
		}
		else if(komanda==Komande::PomjeriDalje)
		{
			Status rez(Idi(polja, x, y, p_x, p_y));
			cout << "Tekuca pozicija igraca je (" << x << "," << y << ")" << endl;
			if(rez==Status::KrajPobjeda)
			{
				cout << "Bravo, obisli ste sva sigurna polja" << endl;
				for(int i=0; i<polja.size(); i++)
				{
					for(int j=0; j<polja[i].size(); j++)
					{
						polja[i][j]=Polje::Prazno;
					}
				}
				throw std::runtime_error("Igra zavrsena");
			}
			else if(rez==Status::KrajPoraz)
			{
				cout << "Nagazili ste na minu" << endl;
				for(int i=0; i<polja.size(); i++)
				{
					for(int j=0; j<polja[i].size(); j++)
					{
						polja[i][j]=Polje::Prazno;
					}
				}
				throw std::runtime_error("Igra zavrsena");
			}
		}
		else if(komanda==Komande::PomjeriJednoMjesto)
		{
			Status rez(Idi(polja, x, y, p_smjer));
			cout << "Tekuca pozicija igraca je (" << x << "," << y << ")" << endl;
			if(rez==Status::KrajPobjeda)
			{
				cout << "Bravo, obisli ste sva sigurna polja" << endl;
				for(int i=0; i<polja.size(); i++)
				{
					for(int j=0; j<polja[i].size(); j++)
					{
						polja[i][j]=Polje::Prazno;
					}
				}
				br_pos=0;
				br_mina=0;
				br_blok=0;
				throw std::runtime_error("Igra zavrsena");
			}
			else if(rez==Status::KrajPoraz)
			{
				cout << "Nagazili ste na minu" << endl;
				for(int i=0; i<polja.size(); i++)
				{
					for(int j=0; j<polja[i].size(); j++)
					{
						polja[i][j]=Polje::Prazno;
					}
				}
				br_pos=0;
				br_mina=0;
				br_blok=0;
				throw std::runtime_error("Igra zavrsena");
			}
		}
		else if(komanda==Komande::ZavrsiIgru)
		{
			for(int i=0; i<polja.size(); i++)
			{
				for(int j=0; j<polja[i].size(); j++)
				{
					polja[i][j]=Polje::Prazno;
				}
			}
			br_pos=0;
			br_mina=0;
			br_blok=0;
			throw std::runtime_error("Igra zavrsena");
		}
	}
	catch(std::domain_error izuzetak1)
	{
		cout << izuzetak1.what() << endl;
	}
	catch(std::out_of_range izuzetak2)
	{
		cout << izuzetak2.what() << endl;
	}
	catch(std::logic_error izuzetak2)
	{
		cout << izuzetak2.what() << endl;
	}
	
	return;
}

int main ()
{
	Tabla polja;
	Komande komanda;
	Smjerovi p_smjer;
	int x(0), y(0), p_x(0), p_y(0);
	KodoviGresaka greska;
	
	try
	{
		while(1)
		{
			cout << "Unesite komandu: ";
			
			if(UnosKomande(komanda, p_smjer, p_x, p_y, greska)) 
			{
				IzvrsiKomandu(komanda, polja, x, y, p_smjer, p_x, p_y);
				if(!cin)	
				{
					cin.clear();
					cin.ignore(1000, '\n');
				}
			}
			else
			{
				PrijaviGresku(greska);
				if(!cin)	
				{
					cin.clear();
					cin.ignore(1000, '\n');
				}
			}
		}
	}
	catch(std::runtime_error izuzetak)
	{
		cout << "Dovidjenja!" << endl;
	}
	
	return 0;
}



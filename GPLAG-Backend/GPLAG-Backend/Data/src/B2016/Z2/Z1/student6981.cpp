/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

enum class Polje {
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina	
};

enum class Smjerovi {
	GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, Dolje, DoljeLijevo, Lijevo
};

enum class Status {
	NijeKraj, KrajPoraz, KrajPobjeda
};

enum class KodoviGresaka {
	PogresnaKomanda, NedostajeParametar, SuvisniParametar, NeispravanParametar
};

enum class Komande {
	PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};

vector<vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const vector<vector<int>> &mine)
{
	Tabla tabla(n, vector<Polje>(n, Prazno));
	for(int i=0; i<mine.size(); i++)
	{
		if(mine[i].size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
		tabla[mine[i][0]][mine[i][1]]=Mina;
	}
	return tabla;
}

vector<vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y)
{
	if(x<0 || y<0 || x>=polja.size()) throw std::domain_error("Polje ("x", "y") ne postoji");
	if(polja.size()!=0)
		if(y>=polja[0].size()) throw std::domain_error("Polje ("x", "y") ne postoji");
	vector<vector<int>> br_mina(3, vector<int>(3));
	/*int i(0), j(0);
	for(int m=x-1; m<x+1; m++)
	{
		for(int n=y-1; n<y+1; n++)
		{
			for(int k=m-1; k<m+1; k++)
			{
				for(int l=n-1; l<n+1; l++)
				{
					if(polja[k][l]==Mina)br_mina[i][j]++;
				}
			}
			j++;
		}
		i++;
	}
}*/
	int i(0), j(0), m, m_kraj;
	if(x==0)m=x;
	else m=x-1;
	if(x==polja.size())m_kraj=x;
	else m_kraj=x+1;
	while(m<=m_kraj)
	{
		int n, n_kraj;
		if(y==0)n=y;
		else n=y-1;
		if(y==polja[x].size())n_kraj==y;
		else n_kraj;
		while(n<=n_kraj)
		{
			int k, k_kraj;
			if(m==0)k==m;
			else k=m-1;
			if(k==polja.size())k_kraj=m;
			else k_kraj=m+1;
			while(k<=k_kraj)
			{
				int l, l_kraj;
				if(n==0)l=n;
				else l=n-1;
				if(n==polja[m].size()) l=n;
				else l=n+1;
				while(l<=l_kraj)
				{
					if(polja[k][l]==Polje::Mina)br_mina[i][j]++;
					l++
				}
				k++;
			}
			n++;
			j++;
		}
		m++;
		i++;
	}
}

void BlokirajPolje(Tabla &polja, int x, int y)
{
	if(x<0 || y<0 || x>=polja.size()) throw std::domain_error("Polje ("x", "y") ne postoji");
	if(polja.size()!=0)
		if(y>=polja[0].size()) throw std::domain_error("Polje ("x", "y") ne postoji");
	if(polja[x][y]==Polje::Prazno)polja[x][y]=Polje::BlokiranoPrazno;
	if(polja[x][y]==Polje::Posjeceno)polja[x][y]=Polje::BlokiranoPosjeceno;
	if(polja[x][y]==Polje::Mina)polja[x][y]=Polje::BlokiranoMina;
}

void DeblokirajPolje(Tabla &polja, int x, int y)
{
	if(x<0 || y<0 || x>=polja.size()) throw std::domain_error("Polje ("x", "y") ne postoji");
	if(polja.size()!=0)
		if(y>=polja[0].size()) throw std::domain_error("Polje ("x", "y") ne postoji");
	if(polja[x][y]==Polje::BlokiranoPrazno)polja[x][y]=Polje::Prazno;
	if(polja[x][y]==Polje::BlokiranoPosjeceno)polja[x][y]=Polje::Posjeceno;
	if(polja[x][y]==Polje::BlokiranoMina)polja[x][y]=Polje::Mina;
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer)
{
	if(smjer==Smjerovi::GoreLijevo){ x-=1; y-=1; }
	if(smjer==Smjerovi::Gore) x-=1;
	if(smjer==Smjerovi::GoreDesno){ x-=1; y+=1; }
	if(smjer==Smjerovi::Desno) y+=1;
	if(smjer==Smjerovi::DoljeDesno){ x+=1; y+=1; }
	if(smjer==Smjerovi::Dolje) x+=1;
	if(smjer==Smjerovi::DoljeLijevo){ x+=1; y-=1; }
	if(smjer==Smjerovi::Lijevo) y-=1;
	
	if(x<0 || y<0 || x>=polja.size()) throw std::out_of_range("Izlazak van igrace table");
	if(polja.size()!=0)
		if(y>=polja[0].size()) throw std::out_of_range("Izlazak van igrace table");
		
	if(polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoPosjeceno || polja[x][y]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
	
	if(polja[x][y]==Polje::Mina)
	{
		for(int i=0; i<polja.size(); i++)
			for(int j=0; j<polja[0].size(); j++)
				polja[i][j]=Polje::Prazno;
		return Status::KrajPoraz;
	}
	
	for(int i=0; i<polja.size(); i++)
		for(int j=0; j<polja[0].size(); j++)
			if(polja[i][j]==Polje::Prazno)return Status::NijeKraj;
			
	return Status::KrajPobjeda;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y)
{
	if(novi_x<0 || novi_y>0 || novi_x>=polja.size()) throw std::out_of_range("Izlazak van igrace table");
	if(polja.size()!=0)
		if(y>=polja[0].size()) throw std::out_of_range("Izlazak van igrace table");
		
		x=x_novi;
		y=y_novi;
		
	if(polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoPosjeceno || polja[x][y]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
	
	if(polja[x][y]==Polje::Mina)
	{
		for(int i=0; i<polja.size(); i++)
			for(int j=0; j<polja[0].size(); j++)
				polja[x][y]=Polje::Prazno;
		return Status::KrajPoraz;
	}
	
	for(int i=0 i<polja.size(); i++)
		for(int j=0; j<polja[0].size(); j++)
			if(polja[i][j]==Polje::Prazno)return Status::NijeKraj;
			
	return Status::KrajPobjeda;
}

void PrijaviGresku(KodoviGresaka greska)
{
	if(greska==KodoviGresaka::PogresnaKomanda)cout<<"Nerazumljiva komanda!";
	else if(greska==KodoviGresaka::NedostajeParametar)cout<<"Komanda trazi parametar koji nije naveden!";
	else if(greska==KodoviGresaka::NeispravanParametar)cout<<"Parametar komande nije ispravan!";
	else if(greska==KodoviGresaka::SuvisniParametar)cout<<"Zadan je suvisan parametar nakon komande!";
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska)
{
	
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0)
{
	if(komanda==Komande::PomjeriJednoMjesto)
	{
		try
		{
			Status s=Idi(polja, x, y, p_smjer);
			cout<<"Tekuca pozicija igraca je ("<<x<<", "<<y<<")";
			if(s==Status::KrajPobjeda)
				cout<<"Bravo, obisli ste sva sigurna polja"<<endl;
			else if(s==Status::KrajPoraz)
				cout<<"Nagazili ste na minu"<<endl;
			if(s==Status::KrajPobjeda || s==Status::KrajPoraz)
			{
				if(polja.size()!=0)
					for(int i=0; i<polja.size(); i++)
						for(int j=0; j<polja[0].size(); j++)
							polja[i][j]=Polje::Prazno;
				throw std::runtime_error("Igra zavrsena");
			}
		}
		catch(std::out_of_range izuzetak)
		{
			cout<<izuzetak.what()<<endl;
		}
		catch(std::logic_error izuzetak)
		{
			cout<<izuzetak.what()<<endl;
		}
	}
	else if(komanda==Komande::PomjeriDalje)
	{
		try
		{
			Status s=Idi(polja, x, y, p_x, p_y)
			cout<<"Tekuca pozicija igraca je ("<<x<<", "<<y<<")";
			if(s==Status::KrajPobjeda)
				cout<<"Bravo, obisli ste sva sigurna polja"<<endl;
			else if(s==Status::KrajPoraz)
				cout<<"Nagazili ste na minu"<<endl;
			if(s==Status::KrajPobjeda || s==Status::KrajPoraz)
			{
				if(polja.size!=0)
					for(int i=0; i<polja.size(); i++)
						for(int j=0; j<polja[0].size(); j++)
							polja[i][j]=Polje::Prazno;
				throw std::runtime_error("Igra zavrsena");
			}
		}
		catch(std::out_of_range izuzetak)
		{
			cout<<izuzetak.what()<<endl;
		}
		catch(std::logic_error izuzetak)
		{
			cout<<izuzetak.what()<<endl;
		}
	}
	else if(komanda==Komande::Blokiraj)
	{
		try
		{
			BlokirajPolje(polja, x, y);
		}
		catch(std::domain_error izuzetak)
		{
			cout<<izuzetak.what()<<endl;
		}
	}
	else if(komanda==Komande::Deblokiraj)
	{
		try
		{
			DeblokirajPolje(polja, x, y);
		}
		catch(std::domain_error izuzetak)
		{
			cout<<izuzetak.what()<<endl;
		}
	}
	else if(komanda==Komande::PrikaziOkolinu)
	{
		try
		{
			vector<vector<int>> okolina(PrikaziOkolinu(polja, x, y));
			if(okolina.size()!=0)
				for(int i=0; i<okolina.size(); i++)
				{
					for(int j=0; j<okolina[0].size(); j++)
						cout<<okolina[i][j]<<" ";
					cout<<endl;
				}
		}
		catch(std::domain_error izuzetak)
		{
			cout<<izuzetak.what()<<endl;
		}
	}
	else if(komanda==Komande::ZavrsiIgru)
	{
		if(polja.size!=0)
			for(int i=0; i<polja.size(); i++)
				for(int j=0; j<polja[0].size(); j++)
					polja[i][j]==Polje::Prazno;
		throw std::runtime_error("Igra zavrsena");
	}
	else if(komanda==Komande::KreirajIgru)
	{
		int n;
		cout<<"Unesite broj polja: ";
		cin>>n;
		vector<vector<int>> mine;
		while(1)
		{
			if()
		}
	}
}

int main ()
{
	return 0;
}
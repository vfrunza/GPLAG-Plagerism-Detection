/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/

#include <iostream>
#include <vector>
#include <stdexcept>
#include <new>
#include <string>
#include <cctype>

using namespace std;

enum class Status {NijeKraj, KrajPoraz, KrajPobjeda};
enum class Smjerovi{GoreLijevo, Gore, GoreDesno, Desno, 
	DoljeDesno, Dolje, DoljeLijevo, Lijevo };
enum class KodoviGresaka{ PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar };
enum class Polje { Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina };
enum class Komande { PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru };

typedef vector<vector<Polje>> Tabla;

Tabla KreirajTablu(int n)
{
	return Tabla(n, vector<Polje>(n));
}

Tabla KreirajIgru(int n, const vector<vector<int>> &mine)
{
	for(unsigned int i=0; i < mine.size(); i++)
	{
		if(mine[i].size()!=2)  throw domain_error("Ilegalan format zadavanja mina");
		else if(mine[i][0] > n-1 || mine[i][0]<0 || mine[i][1]>n-1 || mine[i][1]<0 )
				throw domain_error("Ilegalne pozicije mina");
	}
	
	vector<vector<Polje>> t{KreirajTablu(n)};
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++)
			t[i][j]=Polje::Prazno;
	}
	
	for(unsigned int i=0;i<mine.size();i++)
	{
		for(int j=0;j<2;j++)
		{
			t[ mine[i][0] ][ mine[i][1] ] = Polje::Mina;
		}
	}
	return t;
}


vector<vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y)
{
	if( x==0 || y==0 || x==int(polja.size()-1) || y==int(polja.size()-1) )
		throw domain_error("Polje (x,y) ne postoji");
		
	vector<vector<int>> okolina;
	int brojac{0};
	
	int n{ int(polja.size()) };
	
	for(int i=-1; i<2; i++)
	{
		vector<int> m;
		for(int j=-1;j<2;j++)
		{
			brojac=0;
			if(x+i>=0  &&  y+j>=0 && x+i<n  &&  y+j<n)
			{
				//pristupili smo elementu ploca[x-i][y-j], jos da provjerimo kakva je njegova okolina
				for(int iPojedinacno=-1; iPojedinacno<2; iPojedinacno++)
				{
					for(int jPojedinacno=-1; jPojedinacno<2; jPojedinacno++)
					{
						if(iPojedinacno==0 && jPojedinacno==0)  continue;
						if(x+i+iPojedinacno>=0  &&  y+j+jPojedinacno>=0 && x+i+iPojedinacno<n  
						  &&  y+j+jPojedinacno<n && polja[x+i+iPojedinacno][y+j+jPojedinacno]==Polje::Mina)
						  		brojac++;
					}
				}
			}
			m.push_back(brojac);	
		}
		okolina.push_back(m);
		m.clear();
	}
	/*
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)    cout<<okolina[i][j]<<" ";
		cout<<endl;
	}*/
	
	return okolina;	
}


void BlokirajPolje(Tabla &polja, int x, int y)
{
	if(x<0 || y<0 || x>int(polja.size()-1) || y>int(polja.size()-1)  )
		throw domain_error("Polje (x,y) ne postoji");
	for(int i=0;i<3;i++)
	{
		if(polja[x][y]==Polje(i))    polja[x][y]=Polje(i+3);
	}
}


void DeblokirajPolje(Tabla &polja, int x, int y)
{
	if(x<0 || y<0 || x>int(polja.size()-1) || y>int(polja.size()-1)  )
		throw domain_error("Polje (x,y) ne postoji");
	for(int i=0;i<3;i++)
	{
		if(polja[x][y]==Polje(i+3))    polja[x][y]=Polje(i);
	}
}


Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer)
{
	int dimTable{ int(polja.size()) };
	polja[x][y] = Polje::Posjeceno;
	
	Status statusIgre{ Status::NijeKraj };
	
	bool mrtviSmo{false}, pobijediliSmo{false};
	
	if(smjer==Smjerovi::GoreLijevo)
	{
		if(x-1<0 || y-1<0 || x-1>=dimTable || y-1>=dimTable )
			throw out_of_range("Izlazak van igrace table");
		if(polja[x-1][y-1]>Polje(2))   throw logic_error("Blokirano polje");
		x-=1;
		y-=1;
		if(polja[x][y]==Polje(2))   mrtviSmo=true;
	}
	
	else if(smjer==Smjerovi::Gore)
	{
		if(x-1<0 || x-1>=dimTable)
			throw out_of_range("Izlazak van igrace table");
		if(polja[x-1][y]>Polje(2))   throw logic_error("Blokirano polje");
		x-=1;
		if(polja[x][y]==Polje(2))   mrtviSmo=true;
	}
	
	else if(smjer==Smjerovi::GoreDesno)
	{
		if(x-1<0 || y+1<0 || x-1>=dimTable || y+1>=dimTable)
			throw out_of_range("Izlazak van igrace table");
		if(polja[x-1][y+1]>Polje(2))   throw logic_error("Blokirano polje");
		x-=1;
		y+=1;
		if(polja[x][y]==Polje(2))   mrtviSmo=true;
	}
	
	
	else if(smjer==Smjerovi::Desno)
	{
		if(y+1<0 || y+1>=dimTable)
			throw out_of_range("Izlazak van igrace table");
		if(polja[x][y+1]>Polje(2))   throw logic_error("Blokirano polje");
		y+=1;
		if(polja[x][y]==Polje(2))   mrtviSmo=true;
	}
	
	else if(smjer==Smjerovi::DoljeDesno)
	{
		if(x+1<0 || y+1<0 || x+1>=dimTable || y+1>=dimTable)
			throw out_of_range("Izlazak van igrace table");
		if(polja[x+1][y+1]>Polje(2))   throw logic_error("Blokirano polje");
		x+=1;
		y+=1;
		if(polja[x][y]==Polje(2))   mrtviSmo=true;
	}
	
	else if(smjer==Smjerovi::Dolje)
	{
		if(x+1<0 || x+1>=dimTable)
			throw out_of_range("Izlazak van igrace table");
		if(polja[x+1][y]>Polje(2))   throw logic_error("Blokirano polje");
		x+=1;
		if(polja[x][y]==Polje(2))   mrtviSmo=true;
	}
	
	else if(smjer==Smjerovi::DoljeLijevo)
	{
		if(x+1<0 || y-1<0 || x+1>=dimTable || y-1>=dimTable)
			throw out_of_range("Izlazak van igrace table");
		if(polja[x+1][y-1]>Polje(2))   throw logic_error("Blokirano polje");
		x+=1;
		y-=1;
		if(polja[x][y]==Polje(2))   mrtviSmo=true;
	}
	
	else if(smjer==Smjerovi::Lijevo)
	{
		if(y-1<0 || y-1>=dimTable)
			throw out_of_range("Izlazak van igrace table");
		if(polja[x][y-1]>Polje(2))   throw logic_error("Blokirano polje");
		y-=1;
		if(polja[x][y]==Polje(2))   mrtviSmo=true;
	}
	
	if(mrtviSmo)
	{
		for(int i=0;i<dimTable;i++)
		{
			for(int j=0;j<dimTable;j++)  polja[i][j]=Polje::Prazno;
		}
		//polja.clear(); //???
		statusIgre = Status::KrajPoraz;
		return statusIgre;
	}
	
	if(pobijediliSmo)
	{
		statusIgre = Status::KrajPobjeda;
		return statusIgre;
	}
	
	return Status::NijeKraj;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y)
{
	int dimTable{ int(polja.size()) };
	polja[x][y]=Polje::Posjeceno;
	
	x=novi_x;
	y=novi_y;
	
	Status statusIgre{ Status::NijeKraj };
	bool mrtviSmo{false}, pobijediliSmo{false};
	
	if(novi_x<0  ||  novi_y<0  ||  novi_x>=dimTable || novi_y>=dimTable)
			throw out_of_range("Izlazak van igrace table");
	if(polja[novi_x][novi_y]>Polje(2))  throw logic_error("Blokirano polje");
	if(polja[novi_x][novi_y]==Polje::Mina)  mrtviSmo=true;
	
	if(mrtviSmo)  //ako smo nagazili na minu
	{
		for(int i=0;i<dimTable;i++)
		{
			for(int j=0;j<dimTable;j++)    polja[i][j]=Polje::Prazno;
		}
		statusIgre = Status::KrajPoraz;
		return statusIgre;
	}
	
	for(int i=0;i<dimTable;i++)
	{
		for(int j=0;j<dimTable;j++)
		{
			if(polja[i][j]!=Polje::Posjeceno)
			{
				pobijediliSmo=false;
				return statusIgre;
			}
		}
	}
	
	if(pobijediliSmo)
	{
		statusIgre = Status::KrajPobjeda;
		return statusIgre;
	}
	
	return Status::NijeKraj;
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &kod_greske)
{
	char prviZnak, drugiZnak, prvoSlovoSmjer;
	cin>>ws;
	
	prviZnak = cin.get();
	if(prviZnak=='P')
	{
		drugiZnak=cin.get();
		if(drugiZnak=='1')   //Uneseno je PomjeriJednoMjesto
		{
			komanda = Komande::PomjeriJednoMjesto;
			//while(cin.peek()!='\n' && isspace(cin.peek()))  cin.get();
			while (cin.peek()!='\n' && isspace(cin.peek())) cin.get();
			if(cin.peek()=='\n')
			{
				kod_greske=KodoviGresaka::NedostajeParametar;
				cin.clear();
				cin.ignore(10000,'\n');
				return false;
			}
			cin>>ws;
			if(cin.peek()=='\n')
			{
				kod_greske=KodoviGresaka::NedostajeParametar;
				cin.clear();
				cin.ignore(10000,'\n');
				return false;
			}
			if(cin.peek()=='G' && cin.get()=='G')
			{
				prvoSlovoSmjer='G';
				if(cin.peek()=='L' && cin.get()=='L')
				{
					
					smjer=Smjerovi::GoreLijevo;
					return true;
				}
				else if(cin.peek()=='D' && cin.get()=='D')
				{
					smjer=Smjerovi::GoreDesno;
					return true;
				}
				else if(cin>>ws && cin.get()=='\n')
				{
					smjer=Smjerovi::Gore;
					return true;
				}
				else{
					kod_greske=KodoviGresaka::NeispravanParametar;
					cin.clear();
					cin.ignore(10000,'\n');
					return false;
				}
			}
			
			else if(cin.peek()=='D' && cin.get()=='D')
			{
				if(cin.peek()=='o' && cin.get()=='o')
				{
					if(cin.peek()=='D' && cin.get()=='D')
					{
						smjer = Smjerovi::DoljeDesno;
						return true;
					}
					else if(cin.peek()=='L' && cin.get()=='L')
					{
						smjer = Smjerovi::DoljeLijevo;
						return true;
					}
					else if(cin>>ws && cin.get()=='\n')
					{
						smjer=Smjerovi::Dolje;
						return true;
					}
					else{
						kod_greske=KodoviGresaka::NeispravanParametar;
						cin.clear();
						cin.ignore(10000,'\n');
						return false;
					}
				}
				else if(cin>>ws && cin.get()=='\n')
				{
					smjer=Smjerovi::Desno;
					return true;
				}
				else
				{
					kod_greske=KodoviGresaka::NeispravanParametar;
					cin.clear();
					cin.ignore(10000,'\n');
					return false;	
				}
			}
			else if(cin.peek()=='L' && cin.get()=='L')
			{
				smjer=Smjerovi::Lijevo;
				return true;
			}
			//ako nije ni gore ni dolje ni desno ni lijevo
			else
			{
				kod_greske = KodoviGresaka::NeispravanParametar;
				cin.clear();
				cin.ignore(10000,'\n');
				return false;
			}
			drugiZnak=0;
		}
		
		else if(drugiZnak=='>')
		{
			while (cin.peek()!='\n' && isspace(cin.peek())) cin.get();
			if(cin.peek()=='\n')
			{
				kod_greske=KodoviGresaka::NedostajeParametar;
				cin.clear();
				cin.ignore(10000,'\n');
				return false;
			}
			cin>>x>>ws;
			if(!cin)
			{
				cin.clear();
				cin.ignore(10000,'\n');
				kod_greske=KodoviGresaka::NeispravanParametar;
				return false;
			}
			
			while (cin.peek()!='\n' && isspace(cin.peek())) cin.get();
			if(cin.peek()=='\n')
			{
				kod_greske=KodoviGresaka::NedostajeParametar;
				cin.clear();
				cin.ignore(10000,'\n');
				return false;
			}
			cin>>y>>ws;
			if(!cin)
			{
				cin.clear();
				cin.ignore(10000,'\n');
				kod_greske=KodoviGresaka::NeispravanParametar;
				return false;
			}
			while(cin.peek()!='\n')
			{
				if(!isspace(cin.get()))
				{
					kod_greske=KodoviGresaka::SuvisanParametar;
					cin.clear();
					cin.ignore(10000,'\n');
					return false;
				}
			}
			drugiZnak=0;
			komanda = Komande::PomjeriDalje;
			return true;
		}
		
		else if(drugiZnak=='O')
		{
			
			while(cin.peek()!='\n')
			{
				if(!isspace(cin.get()))
				{
					kod_greske=KodoviGresaka::SuvisanParametar;
					cin.clear();
					cin.ignore(10000,'\n');
					return false;
				}
			}
			drugiZnak=0;
			komanda=Komande::PrikaziOkolinu;
			return true;
		}
		
		//inace je pogresna komanda
		
		else
		{
			kod_greske = KodoviGresaka::PogresnaKomanda;
			cin.clear();
			cin.ignore(10000,'\n');
			return false;
		}
	}
	
	else if(prviZnak=='B')
	{
		cin>>ws;
		while(cin.peek()!='\n')
		{
			if(!isspace(cin.get()))
			{
				kod_greske=KodoviGresaka::NedostajeParametar;					
				cin.clear();
				cin.ignore(10000,'\n');
				return false;
			}
		}
		cin>>x>>y;
		if(!cin)
		{
			cin.clear();
			cin.ignore(10000,'\n');
			kod_greske=KodoviGresaka::NeispravanParametar;
			return false;
		}
		while(cin.peek()!='\n')
		{
			if(!isspace(cin.get()))
			{
				kod_greske=KodoviGresaka::SuvisanParametar;					
				cin.clear();
				cin.ignore(10000,'\n');
				return false;
			}
		}
		komanda = Komande::Blokiraj;
		return true;
	}
	
	else if(prviZnak=='D')
	{
		cin>>ws;
		while(cin.peek()!='\n')
		{
			if(!isspace(cin.get()))
			{
				kod_greske=KodoviGresaka::NedostajeParametar;					
				cin.clear();
				cin.ignore(10000,'\n');
				return false;
			}
		}
		cin>>x>>y;
		
		if(!cin)
		{
			cin.clear();
			cin.ignore(10000,'\n');
			kod_greske=KodoviGresaka::NeispravanParametar;
			return false;
		}
		cin>>ws;
		while (cin.peek()!='\n') 
		{	kod_greske=KodoviGresaka::SuvisanParametar;
			cin.clear();
			cin.ignore(10000,'\n');
			return false;
		}
		komanda = Komande::Deblokiraj;
		return true;
	}
		
	else if(prviZnak=='K')
	{
		while(cin.peek()!='\n')
		{
			if(!isspace(cin.get()))
			{
				kod_greske=KodoviGresaka::SuvisanParametar;
				cin.clear();
				cin.ignore(10000,'\n');
				return false;
			}
		}
		komanda = Komande::KreirajIgru;
		return true;
	}
	
	else if(prviZnak=='Z')
	{
		while(cin.peek()!='\n')
		{
			if(!isspace(cin.get()))
			{
				kod_greske=KodoviGresaka::SuvisanParametar;
				cin.clear();
				cin.ignore(10000,'\n');
				return false;
			}
		}
		komanda = Komande::ZavrsiIgru;
		return true;
	}
	
	//inace je pogresna komanda
	else
	{
		kod_greske=KodoviGresaka::PogresnaKomanda;
		cin.clear();
		cin.ignore(10000,'\n');
		return false;
	}
	return true;
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y,
	Smjerovi p_smjer=Smjerovi::Gore, int p_x=0, int p_y=0)
{
	if(komanda==Komande::PomjeriJednoMjesto)
	{
		Status stat{Idi(polja,x,y,p_smjer)};
		if(stat==Status::NijeKraj)
			cout<<"Tekuca pozicija igraca je (" << x << "," << y <<")"<<endl;
		else if(stat==Status::KrajPobjeda)
			cout<<"Bravo, obisli ste sva sigurna polja"<<endl;
		else  cout<<"Nagazili ste minu"<<endl;
	}
	
	else if(komanda==Komande::PomjeriDalje)
	{
		Status stat{Idi(polja,x,y,p_x,p_y)};
		if(stat==Status::NijeKraj)
			cout<<"Tekuca pozicija igraca je (" << x << "," << y <<")"<<endl;
		else if(stat==Status::KrajPobjeda)
			cout<<"Bravo, obisli ste sva sigurna polja"<<endl;
		else  cout<<"Nagazili ste minu"<<endl;
	}
	
	else if(komanda==Komande::Blokiraj)  BlokirajPolje(polja,x,y);
	else if(komanda==Komande::Deblokiraj) DeblokirajPolje(polja,x,y);
	else if(komanda==Komande::PrikaziOkolinu) 
	{
		vector<vector<int>> prikaz{ PrikaziOkolinu(polja,x,y) };
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)    cout<<prikaz[i][j]<<" ";
			cout<<endl;
		}
	}
	else if(komanda==Komande::ZavrsiIgru)
	{
		for(int i=0;i<polja.size();i++)
		{
			for(int j=0;j<polja[i].size();j++)
			{
				polja[i][j]=Polje::Prazno;
			}
			//cout<<endl;
		}
		cout<<"Dovidjenja!";
		throw runtime_error("Igra zavrsena");
	}
	
	else if(komanda==Komande::KreirajIgru)
	{
		int n;
		cout<<"Unesite broj polja: ";
		cin>>n;
		vector<vector<int>> mine;
		int x,y;
		char znak{')'};
		cout<<"Unesite pozicije mina: ";
		while(znak==')')
		{
			cin>>znak;
			if(znak!='(')
			{
				if(znak=='.')   break;
				cin.clear();
				cin.ignore(10000,'\n');
				cout<<"Greska, unesite ponovo!"<<endl;
				znak=')';
				continue;
			}
			cin>>x;
			cin>>znak;
			if(znak!=',' || x>=n)
			{
				if(znak=='.')   break;
				cin.clear();
				cin.ignore(10000,'\n');
				cout<<"Greska, unesite ponovo!"<<endl;
				znak=')';
				continue;
			}
			cin>>y;
			cin>>znak;
			if(znak==')' && y<n)
			{
				vector<int> m;
				m.push_back(x);
				m.push_back(y);
				mine.push_back(m);
				continue;
			}
			else
			{
				if(znak=='.')   break;
				cin.clear();
				cin.ignore(10000,'\n');
				cout<<"Greska, unesite ponovo!"<<endl;
				znak=')';
				continue;
			}
		}
		
		polja = KreirajIgru(n,mine);
	}
}


void PrijaviGresku(KodoviGresaka kod)
{
	if(kod==KodoviGresaka::PogresnaKomanda)
		cout<<"Nerazumljiva komanda!"<<endl;
	else if(kod==KodoviGresaka::NedostajeParametar)
		cout<<"Komanda trazi parametar koji nije naveden!"<<endl;
	else if(kod==KodoviGresaka::NeispravanParametar)
		cout<<"Parametar komande nije ispravan!"<<endl;
	else
		cout<<"Zadan je suvisan parametar nakon komande!"<<endl;
}


int main ()
{
	
	Tabla tab;
	Komande komanda;
	Smjerovi smjer;
	int x{0}, y{0}, tren_x{0}, tren_y{0};
	KodoviGresaka kod;
	bool rez{true};
	while(rez && cout<<"Unesite komandu: ")
	{
		rez=UnosKomande(komanda, smjer, x, x, kod);
		if(rez) {
			try {
				IzvrsiKomandu(komanda, tab, x, y, smjer, tren_x, tren_y);
			}
			catch(runtime_error e) {rez=false;}
			catch(exception e){
				cout<<e.what()<<endl;
			}
		}
		else {
			PrijaviGresku(kod);
		}
	}
	
	return 0;
}
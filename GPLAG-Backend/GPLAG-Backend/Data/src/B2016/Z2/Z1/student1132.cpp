#include<iostream>
#include<vector>
#include<algorithm>
#include<stdexcept>
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
enum class KodoviGresaka {
 PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};
enum class Komande {
 PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu,
 ZavrsiIgru, KreirajIgru
};


bool Ode(int n,int i,int j)
{
	return !(i>=0 && i<n && j>=0 && j<n);
}

Tabla KreirajIgru(int N, const std::vector<std::vector<int>> &mine)
{
	Tabla rez(N,std::vector<Polje>(N,Polje::Prazno));
	for(int i=0;i<mine.size();i++)
	{
		if(mine[i].size() != 2) throw std::domain_error("Ilegalan format zadavanja mina");
		if( Ode(N, mine[i][0], mine[i][1]) ) throw std::domain_error("Ilegalne pozicije mina");
		rez[mine[i].at(0)][mine[i].at(1)] = Polje::Mina;
	}
	return rez;
}

std::vector<std::vector<int> > PrikaziOkolinu(const Tabla &polja, int x, int y)
{
	if(Ode(polja.size(),x,y)) throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	
	std::vector<std::vector<int> > v(3,std::vector<int>(3));
	
	for(int i=-1;i<=1;i++)
	{
		for(int j=-1;j<=1;j++)
		{
				int cnt = 0;
				for(int k=-1;k<=1;k++)
					for(int h=-1;h<=1;h++)
						if(!Ode(polja.size(), x+i+k, y+j+h) && polja[x+i+k][y+j+h] == Polje::Mina) cnt++;
				if(!Ode(polja.size(),x+i,y+j) && polja[x+i][y+j] == Polje::Mina) cnt--;
				v[i+1][j+1] = cnt;
		}
	}
	return v;
}

void BlokirajPolje(Tabla &polja, int x, int y)
{
	if(Ode(polja.size(),x,y)) throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	if(polja[x][y] == Polje::Mina) polja[x][y] = Polje::BlokiranoMina;
	else if(polja[x][y] == Polje::Prazno) polja[x][y] = Polje::BlokiranoPrazno;
	else if(polja[x][y] == Polje::Posjeceno) polja[x][y] = Polje::BlokiranoPosjeceno;
}

void DeblokirajPolje(Tabla &polja, int x, int y)
{
	if(Ode(polja.size(),x,y)) throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	if(polja[x][y] == Polje::BlokiranoMina) polja[x][y] = Polje::Mina;
	else if(polja[x][y] == Polje::BlokiranoPrazno) polja[x][y] = Polje::Prazno;
	else if(polja[x][y] == Polje::BlokiranoPosjeceno) polja[x][y] = Polje::Posjeceno;
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer)
{
	int x1 = x,y1 = y;
	if(smjer == Smjerovi::Gore || smjer == Smjerovi::GoreLijevo || smjer == Smjerovi::GoreDesno) x1--;
	else if(smjer == Smjerovi::Dolje || smjer == Smjerovi::DoljeDesno || smjer == Smjerovi::DoljeLijevo) x1++;
	if(smjer == Smjerovi::GoreDesno || smjer == Smjerovi::Desno || smjer == Smjerovi::DoljeDesno) y1++;
	else if(smjer == Smjerovi::GoreLijevo || smjer == Smjerovi::Lijevo || smjer == Smjerovi::DoljeLijevo) y1--;
	
	if(Ode(polja.size(),x1,y1)) throw std::out_of_range("Izlazak van igrace table");
	if(int(polja[x1][y1]) >= 3) throw std::logic_error("Blokirano polje");
	polja[x][y] = Polje::Posjeceno;
	x = x1; y = y1;
	if(polja[x1][y1] == Polje::Mina) 
	{
		for(auto& e1:polja) for(auto& e:e1) e = Polje::Prazno;
		return Status::KrajPoraz;
	}
	int cnt = 0;
	for(auto& red: polja) 
	{
		cnt += std::count(red.begin(),red.end(),Polje::Prazno);
		cnt += std::count(red.begin(),red.end(),Polje::BlokiranoPrazno);
	}
	if(cnt == 0 || (cnt == 1 && (polja[x][y] == Polje::Prazno))) return Status::KrajPobjeda;

	return Status::NijeKraj;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y)
{
	int x1 = novi_x, y1 = novi_y;
	if(Ode(polja.size(),x1,y1)) throw std::out_of_range("Izlazak van igrace table");
	if(int(polja[x1][y1]) >= 3) throw std::logic_error("Blokirano polje");
	polja[x][y] = Polje::Posjeceno;
	x = x1; y = y1;
	if(polja[x1][y1] == Polje::Mina)
	{
		for(auto& e1:polja) for(auto& e:e1) e = Polje::Prazno;
		return Status::KrajPoraz;
	}
	int cnt = 0;
	for(auto& red: polja) 
	{
		cnt += std::count(red.begin(),red.end(),Polje::Prazno);
		cnt += std::count(red.begin(),red.end(),Polje::BlokiranoPrazno);
	}
	if(cnt == 0 || (cnt == 1 && (polja[x][y] == Polje::Prazno))) return Status::KrajPobjeda;
	
	return Status::NijeKraj;
}

void PrijaviGresku(KodoviGresaka gr)
{
	std::string niz[4] = { "Nerazumljiva komanda!", "Komanda trazi parametar koji nije naveden!",
	"Zadan je suvisan parametar nakon komande!","Parametar komande nije ispravan!"};
	std::cout<<niz[int(gr)]<<"\n";
}
bool parse(std::string s, int& x,int& y,KodoviGresaka& gr)
{
	while(s.size()!=0&&s[0]==' ')s.erase(s.begin());
	while(s.size()!=0&&s.back()==' ') s.pop_back();
	std::string s1,s2;
	int cntr = 0;
	int a1 = 0,a2 = 0,poc2 = 0,i;
	for(int i=0;i<s.size();i++)
	{
		if(i!=0 && s[i]==' ' && s[i-1]!=' ') cntr++;
		if(cntr==2) break;
		if((s[i]<='0' || s[i]>='9')&&s[i]!='-'&&s[i]!=' ')
		{
			gr = KodoviGresaka::NeispravanParametar;
			return false;
		}
	}
	for(i=0;i<s.size();i++)
	{
		if(i==0 && s[0] == '-') {s1+='-';continue;}
		else if(s[i]=='-') {gr = KodoviGresaka::NeispravanParametar; return false;}
		else if(s[i] >= '0' && s[i]<='9'){ a1 = a1*10 + s[i] - '0'; s1+=s[i];}
		else break;
	}
	if(s.size() != 0 && s[0] == '-') a1 = -a1;
	while(i!=s.size() && s[i]==' ') i++;
	poc2 = i;
	for(i = poc2;i<s.size();i++)
	{
		if(i==poc2 && s[poc2]=='-') {s2+='-';continue;}
		else if(s[i]=='-'){gr = KodoviGresaka::NeispravanParametar; return false;}
		else if(s[i]>='0' && s[i]<= '9' ) {a2 = a2*10 + s[i]-'0'; s2+=s[i];}
		else break;
	}
	if(s.size() != 0 && s[poc2] == '-') a2 = -a2;
	if(i!=s.size()) {gr = KodoviGresaka::SuvisanParametar; return false;}
	if(std::to_string(a1)!=s1 || std::to_string(a2)!=s2){gr = KodoviGresaka::NedostajeParametar;return false;}
	x = a1; y = a2;
	return true;
	
}
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska)
{
	std::string s;
	std::getline(std::cin, s);
	while(s.size() != 0 && s[0]==' ') s.erase(s.begin());
	while(s.size() != 0 && s.back()==' ') s.pop_back();
	if(s.size()==0) 
	{
		greska = KodoviGresaka::PogresnaKomanda;
		return false;
	}
	else if(s[0] == 'P')
	{
		if(s.size()==1)
		{
			greska = KodoviGresaka::PogresnaKomanda;
			return false;
		}
		if(s[1] == '1')
		{
			if(s.size() == 2)
			{
				greska = KodoviGresaka::NedostajeParametar;
				return false;
			}
			else
			{
				std::string a = s.substr(2,s.size()),niz[8]{"GL", "G", "GD", "D", "DoD", "Do", "DoL", "L"};
				while(a.size()!=0 && a[0]==' ') a.erase(a.begin());
				auto pok = std::find(niz,niz+8,a);
			//	std::cout<<"'"<<a<<"'\n";
				if(pok != niz+8)
				{
					komanda = Komande::PomjeriJednoMjesto;
					smjer = Smjerovi(pok-niz);
				}
				else
				{
					greska = KodoviGresaka::NeispravanParametar;
					return false;
				}
			}
		}
		else if(s[1]=='>')
		{
			std::string a = s.substr(2,s.size()),s1,s2;
		  	bool ok = parse(a, x, y, greska);
		  	komanda = Komande::PomjeriDalje;
			return ok;
		}
		else if(s[1]=='O')
		{
			if(s.size()!=2) {greska = KodoviGresaka::SuvisanParametar; return false;}
			else komanda = Komande::PrikaziOkolinu;
			return true;
		}
		else
		{
			greska = KodoviGresaka::PogresnaKomanda;
			return false;
		}
	}
	else if(s[0]=='B')
	{
		std::string a = s.substr(1,s.size());
		bool ok = parse(a,x,y,greska);
		komanda = Komande::Blokiraj;
		return ok;
	}
	else if(s[0]=='D')
	{
		std::string a = s.substr(1,s.size());
		bool ok = parse(a,x,y,greska);
		komanda = Komande::Deblokiraj;
		return ok;
	}
	else if(s[0]=='Z')
	{
		if(s.size() != 1) {greska = KodoviGresaka::SuvisanParametar; return false;}
		else komanda = Komande::ZavrsiIgru;
		return true;
	}
	else if(s[0] == 'K')
	{
		if(s.size()!=1){greska = KodoviGresaka::SuvisanParametar; return false;}
		else komanda = Komande::KreirajIgru;
		return true;
	}
	else
	{
		greska = KodoviGresaka::PogresnaKomanda;
		return false;
	}
	return true;
}
void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0)
{
	if(komanda == Komande::PomjeriJednoMjesto)
	{
		Status st;
		try
		{
			st = Idi(polja, x, y, p_smjer);
		}
		catch(std::out_of_range e)
		{
			std::cout<<e.what()<<"\n";
			return;
		}
		catch(std::logic_error e)
		{
			std::cout<<e.what()<<"\n";
			return;
		}
		if(st == Status::KrajPoraz) std::cout<<"Nagazili ste na minu\n";
		else if(st == Status::KrajPobjeda) std::cout<<"Bravo, obisli ste sva sigurna polja\n";
		if(st != Status::NijeKraj) 
		{
			for(int i=0;i<polja.size();i++) for(int j=0;j<polja[i].size();j++) polja[i][j] = Polje::Prazno;
			throw std::runtime_error("Igra zavrsena");
		}
		std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")\n";
	}
	else if(komanda == Komande::PomjeriDalje)
	{
		Status st;
		try
		{
			st = Idi(polja, x, y, p_x, p_y);
		}
		catch(std::out_of_range e)
		{
			std::cout<<e.what()<<"\n";
			return;
		}
		catch(std::logic_error e)
		{
			std::cout<<e.what()<<"\n";
			return;
		}
		if(st == Status::KrajPoraz) std::cout<<"Nagazili ste na minu\n";
		else if(st == Status::KrajPobjeda) std::cout<<"Bravo, obisli ste sva sigurna polja\n";
		if(st != Status::NijeKraj) 
		{
			for(int i=0;i<polja.size();i++) for(int j=0;j<polja[i].size();j++) polja[i][j] = Polje::Prazno;
			throw std::runtime_error("Igra zavrsena");
		}
		std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")\n";
	}
	else if(komanda == Komande::Blokiraj)
	{
		try
		{
			BlokirajPolje(polja,p_x,p_y);
		}
		catch(std::domain_error e)
		{
			std::cout<<e.what()<<"\n";
		}
	}
	else if(komanda == Komande::Deblokiraj)
	{
		try
		{
			DeblokirajPolje(polja,p_x,p_y);
		}
		catch(std::domain_error e)
		{
			std::cout<<e.what()<<"\n";
		}
	}
	else if(komanda == Komande::PrikaziOkolinu)
	{
		try
		{
			auto vv = PrikaziOkolinu(polja, x, y);
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++) std::cout<<vv[i][j]<<" ";
				std::cout<<"\n";
			}
		}
		catch(std::domain_error e)
		{
			std::cout<<e.what()<<"\n";
		}
	}
	else if(komanda == Komande::ZavrsiIgru)
	{
		for(int i=0;i<polja.size();i++) for(int j=0;j<polja[i].size();j++) polja[i][j] = Polje::Prazno;
		throw std::runtime_error("Igra zavrsena");
	}
	else if(komanda == Komande::KreirajIgru)
	{
		std::cout<<"Unesite broj polja: ";
		int N;
		std::cin>>N;
		std::cin.ignore(10000,'\n');
		std::vector<std::vector<int> > vv; 
		std::cout<<"Unesite pozicije mina: ";
		while(1)
		{
			char x;
			int a,b;
			while(std::cin.peek()==' ') std::cin.get();
			std::cin.get(x);
			if(x == '.' && std::cin.peek() == '\n'){std::cin.ignore(1,'\n'); break;}
			else if(x != '(') {std::cout<<"Greska, unesite ponovo!\n"; if(x!='\n') std::cin.ignore(10000,'\n');}
			else 
			{
				if(std::cin.peek()!='\n') std::cin>>a;
				if(!std::cin) {std::cout<<"Greska, unesite ponovo!\n"; std::cin.clear(); std::cin.ignore(10000,'\n');}
				else
				{
					std::cin.get(x);
					if(x != ',') {std::cout<<"Greska, unesite ponovo!\n"; if(x!='\n') std::cin.ignore(10000,'\n');}
					else
					{
						if(std::cin.peek()!='\n') std::cin>>b;
						if(!std::cin) {std::cout<<"Greska, unesite ponovo!\n"; std::cin.clear(); std::cin.ignore(10000,'\n');}
						else
						{
							std::cin.get(x);
							if(x != ')') {std::cout<<"Greska, unesite ponovo!\n"; if(x!='\n') std::cin.ignore(10000,'\n');}
							else
							{
								std::string s;
								std::getline(std::cin, s);
								if(std::count(s.begin(),s.end(),' ') != s.size()) std::cout<<"Greska, unesite ponovo!\n";
								else if(Ode(N,a,b)) std::cout<<"Greska, unesite ponovo!\n";
								else vv.push_back(std::vector<int>{a,b});
							}
						}
					}
				}
			}
		}
		try
		{
			polja = KreirajIgru(N, vv);
		}
		catch(std::domain_error e)
		{
			std::cout<<e.what()<<"\n";
		}
	}
}
int main ()
{
	
	KodoviGresaka gr;
	Komande kom;
	int x=0,y=0,p_x,p_y;
	Smjerovi smj;
	Tabla polja;
	while(1)
	{
		smj = Smjerovi::Gore;
		p_x = p_y = 0;
		std::cout<<"Unesite komandu: ";
		bool ok = UnosKomande(kom, smj, p_x, p_y, gr);
		if(!ok) PrijaviGresku(gr);
		else 
		{
			try
			{
				IzvrsiKomandu(kom, polja, x, y, smj, p_x, p_y);
			
			}
			catch(...)
			{
				std::cout<<"Dovidjenja!";
				return 0;
			}
		}
	}
	return 0;
}
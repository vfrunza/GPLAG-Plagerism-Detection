/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <iomanip>
#include <algorithm>

enum class Polje {
 Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};
typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajTablu(int br_redova, int br_kolona)
{
	return Tabla(br_redova, std::vector<Polje>(br_kolona));
}

char ps()
{
	char p;
	while(p=getchar(),p==' ');
	return p;
}

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine)
{
	Tabla nova=KreirajTablu(n,n);
	for(int i=0;i<mine.size();i++)
	{
		if(mine[i].size()!=2) throw std::domain_error("Ilegalan format zadavanja mina\n");
		if(mine[i][0]>=n || mine[i][1]>=n) throw std::domain_error("Ilegalne pozicije mina\n");
		nova[mine[i][0]][mine[i][1]]=Polje::Mina;
	}
	return nova;
}

typedef std::vector<std::vector<int>> Matrica;

Matrica KreirajMatricu(int br_redova, int br_kolona)
{
	return Matrica(br_redova, std::vector<int>(br_kolona));
}

Matrica PrikaziOkolinu(const Tabla &polja, int x, int y)
{
	if(x<0 || y<0 || x>=polja.size() || y>=polja.size())
	{
		std::string izlaz="Polje (";
		izlaz=izlaz+std::to_string(x)+","+std::to_string(y)+") ne postoji\n";
		throw std::domain_error(izlaz);
	}
	int n=polja.size();
	Matrica v=KreirajMatricu(3,3);
	for(int i=std::max(0,x-2);i<=std::min(n,x+2);i++)
	{
		for(int j=std::max(0,y-2);j<=std::min(n,y+2);j++)
		{
			if(i<=x && j<=y && (polja[i][j]==Polje::Mina || polja[i][j]==Polje::BlokiranoMina)&&(j!=y-1 || i!=x-1)) v[0][0]++;
			if(i<=x && j<=y+1 && j>=y-1 && (polja[i][j]==Polje::Mina || polja[i][j]==Polje::BlokiranoMina)&&(j!=y || i!=x-1)) v[0][1]++;
			if(i<=x && j>=y && (polja[i][j]==Polje::Mina || polja[i][j]==Polje::BlokiranoMina)&&(j!=y+1 || i!=x-1)) v[0][2]++;
			if(i<=x+1 && i>=x-1 && j<=y && (polja[i][j]==Polje::Mina || polja[i][j]==Polje::BlokiranoMina)&&(j!=y-1 || i!=x)) v[1][0]++;
			if(i<=x+1 && i>=x-1 && j<=y+1 && j>=y-1 && (polja[i][j]==Polje::Mina || polja[i][j]==Polje::BlokiranoMina)&&(j!=y || i!=x)) v[1][1]++;
			if(i<=x+1 && i>=x-1 && j>=y && (polja[i][j]==Polje::Mina || polja[i][j]==Polje::BlokiranoMina)&&(j!=y+1 || i!=x)) v[1][2]++;
			if(i>=x && j<=y&& (polja[i][j]==Polje::Mina || polja[i][j]==Polje::BlokiranoMina)&&(j!=y-1 || i!=x+1)) v[2][0]++;
			if(i>=x && j<=y+1 && j>=y-1 && (polja[i][j]==Polje::Mina || polja[i][j]==Polje::BlokiranoMina)&&(j!=y || i!=x+1)) v[2][1]++;
			if(i>=x && j>=y && (polja[i][j]==Polje::Mina || polja[i][j]==Polje::BlokiranoMina)&&(j!=y+1 || i!=x+1)) v[2][2]++;
		}
	}
	return v;
}

void BlokirajPolje(Tabla &polja, int x, int y)
{
	if(x<0 || y<0 || x>=polja.size() || y>=polja.size())
	{
		std::string izlaz="Polje (";
		izlaz=izlaz+std::to_string(x)+","+std::to_string(y)+") ne postoji\n";
		throw std::domain_error(izlaz);
	}
	if(polja[x][y]==Polje::Prazno) polja[x][y]=Polje::BlokiranoPrazno;
	if(polja[x][y]==Polje::Mina) polja[x][y]=Polje::BlokiranoMina;
	if(polja[x][y]==Polje::Posjeceno) polja[x][y]=Polje::BlokiranoPosjeceno;
}

void DeblokirajPolje(Tabla &polja, int x, int y)
{
	if(x<0 || y<0 || x>=polja.size() || y>=polja.size())
	{
		std::string izlaz="Polje (";
		izlaz=izlaz+std::to_string(x)+","+std::to_string(y)+") ne postoji\n";
		throw std::domain_error(izlaz);
	}
	if(polja[x][y]==Polje::BlokiranoPrazno) polja[x][y]=Polje::Prazno;
	if(polja[x][y]==Polje::BlokiranoMina) polja[x][y]=Polje::Mina;
	if(polja[x][y]==Polje::BlokiranoPosjeceno) polja[x][y]=Polje::Posjeceno;
}

enum class Smjerovi {
 GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};
enum class Status {
 NijeKraj, KrajPoraz, KrajPobjeda
};

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer)
{
	int gd=0,ld=0;
	if(x+gd<0 || y+ld<0 || x+gd>=polja.size() || y+ld>=polja.size()) throw std::out_of_range("Izlazak van igrace table\n");
	polja[x][y]=Polje::Posjeceno;
	if(smjer==Smjerovi::GoreLijevo) gd=-1,ld=-1;
	if(smjer==Smjerovi::Gore) gd=-1;
	if(smjer==Smjerovi::GoreDesno) gd=-1,ld=1;
	if(smjer==Smjerovi::Lijevo) ld=-1;
	if(smjer==Smjerovi::DoljeLijevo) gd=1,ld=-1;
	if(smjer==Smjerovi::Dolje) gd=1;
	if(smjer==Smjerovi::DoljeDesno) gd=1,ld=1;
	if(smjer==Smjerovi::Desno) ld=1;
	if(polja[x+gd][y+ld]==Polje::BlokiranoPosjeceno || polja[x+gd][y+ld]==Polje::BlokiranoMina || polja[x+gd][y+ld]==Polje::BlokiranoPrazno) throw std::logic_error("Blokirano polje\n");
	if(polja[x+gd][y+ld]==Polje::Mina) return Status::KrajPoraz;
	int prazna=0;
	for(int i=0;i<polja.size();i++)
	{
		for(int j=0;j<polja.size();j++)
		{
			if(polja[i][j]==Polje::Prazno) prazna++;
			if(prazna>1) break;
		}
	}
	if(prazna <=1) return Status::KrajPobjeda;
	x+=gd;
	y+=ld;
	return Status::NijeKraj;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y)
{
	if(novi_y<0 || novi_y >=polja.size() || novi_x< 0 || novi_x>=polja.size()) throw std::out_of_range("Izlazak van igrace table\n");
	polja[x][y]=Polje::Posjeceno;
	if(polja[novi_x][novi_y]==Polje::BlokiranoPosjeceno || polja[novi_x][novi_y]==Polje::BlokiranoMina || polja[novi_x][novi_y]==Polje::BlokiranoPrazno) throw std::logic_error("Blokirano polje\n");
	if(polja[novi_x][novi_y]==Polje::Mina) return Status::KrajPoraz;
	int prazna=0;
	for(int i=0;i<polja.size();i++)
	{
		for(int j=0;j<polja.size();j++)
		{
			if(polja[i][j]==Polje::Prazno) prazna++;
			if(prazna>1) break;
		}
	}
	if(prazna <=1) return Status::KrajPobjeda;
	x=novi_x;
	y=novi_y;
	return Status::NijeKraj;
}
enum class KodoviGresaka {
 PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};

void PrijaviGresku(KodoviGresaka x)
{
	if(x==KodoviGresaka::PogresnaKomanda) std::cout << "Nerazumljiva komanda!\n";
	else if(x==KodoviGresaka::NedostajeParametar) std::cout << "Komanda trazi parametar koji nije naveden!\n";
	else if(x==KodoviGresaka::NeispravanParametar) std::cout << "Parametar komande nije ispravan!\n";
	else std::cout << "Zadan je suvisan parametar nakon komande!\n";
}
enum class Komande {
 PomjeriJednoMjesto=0, PomjeriDalje=1, Blokiraj=2, Deblokiraj=3, PrikaziOkolinu=4,
 ZavrsiIgru=5, KreirajIgru=6
};

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y,KodoviGresaka &greska)
{
	bool brisi=true;
	char p;
	bool NemaGreske = true;
	std::cin >> p;
	if(p=='P')
	{
		p=getchar();
		if(p=='1')
		{
			p=ps();
			if(p=='G')
			{
				p=getchar();
				if(p=='\n')
				{
					komanda=Komande::PomjeriJednoMjesto;
					smjer=Smjerovi::Gore;
				}
				else if(p=='L')
				{
					komanda=Komande::PomjeriJednoMjesto;
					smjer=Smjerovi::GoreLijevo;
				}
				else if(p=='D')
				{
					komanda=Komande::PomjeriJednoMjesto;
					smjer=Smjerovi::GoreDesno;
				}
				else
				{
					greska=KodoviGresaka::NeispravanParametar;
					NemaGreske=false;
				}
				if(NemaGreske&&(smjer!=Smjerovi::Gore))
				{
					p=ps();
					if(p!='\n')
					{
						greska=KodoviGresaka::NeispravanParametar;
						NemaGreske=false;
					}
				}
			}
			else if(p=='L')
			{
				p=ps();
				if(p!='\n')
				{
					greska=KodoviGresaka::NeispravanParametar;
					NemaGreske=false;
				}
				else
				{
					komanda=Komande::PomjeriJednoMjesto;
					smjer=Smjerovi::Lijevo;
				}
			}
			else if(p=='D')
			{
				p=getchar();
				if(p=='\n')
				{
					komanda=Komande::PomjeriJednoMjesto;
					smjer=Smjerovi::Desno;
				}
				else if(p=='o')
				{
					p=getchar();
					if(p=='\n')
					{
						komanda=Komande::PomjeriJednoMjesto;
						smjer=Smjerovi::Dolje;
					}
					else if(p=='D')
					{
						komanda=Komande::PomjeriJednoMjesto;
						smjer=Smjerovi::DoljeDesno;
					}
					else if(p=='L')
					{
						komanda=Komande::PomjeriJednoMjesto;
						smjer=Smjerovi::DoljeLijevo;
					}
					else
					{
						greska=KodoviGresaka::NeispravanParametar;
						NemaGreske=false;
					}
					if(NemaGreske && p!='\n')
					{
						p=ps();
						if(p!='\n')
						{
							greska=KodoviGresaka::NeispravanParametar;
							NemaGreske=false;
						}
					}
				}
				else
				{
					greska=KodoviGresaka::NeispravanParametar;
					NemaGreske=false;
				}
			}
			else if(p=='\n')
			{
				brisi=false;
				greska=KodoviGresaka::NedostajeParametar;
				return false;
			}
			else
			{
				greska=KodoviGresaka::NeispravanParametar;
				NemaGreske=false;
			}
		}
		else if(p=='>')
		{
			p=std::cin.peek();
			if(p=='\n')
		{
			brisi=false;
			greska=KodoviGresaka::NedostajeParametar;
			NemaGreske=false;
		}
		else{
			std::cin >> x ;
			if(!std::cin) 
			{
				std::cin.clear(); /* Oporavak toka */
				greska=KodoviGresaka::NeispravanParametar;
				NemaGreske=false;
			}else{
			p=std::cin.peek();
			if(p=='\n')
			{
				//brisi=false;
			greska=KodoviGresaka::NedostajeParametar;
			NemaGreske=  false;
			}else{
			std::cin >> y;
			if(!std::cin) 
			{
				std::cin.clear(); /* Oporavak toka */
				greska=KodoviGresaka::NeispravanParametar;
				NemaGreske=false;
			}
			else
			{
				p=ps();
				if(p!='\n')
				{
					greska=KodoviGresaka::NeispravanParametar;
					NemaGreske=false;
				}
				else
				{
					komanda=Komande::PomjeriDalje;
				}
			}
		}}}}
		else if(p=='O')
		{
			p=ps();
			if(p!='\n')
			{
				greska=KodoviGresaka::SuvisanParametar;
				NemaGreske=false;
			}
			else
			{
				komanda=Komande::PrikaziOkolinu;
			}
		}
		else
		{
			if(p=='\n') brisi=false;
			greska=KodoviGresaka::PogresnaKomanda;
			NemaGreske=false;
		}
	}
	else if(p=='B')
	{
		p=std::cin.peek();
		if(p=='\n')
		{
			brisi=false;
			greska=KodoviGresaka::NedostajeParametar;
			NemaGreske=false;
		}
		else{
		std::cin >> x ;
			p=std::cin.peek();
			if(p=='\n')
			{
				brisi=false;
			greska=KodoviGresaka::NedostajeParametar;
			return false;
			}else{
			std::cin >> y;
		if(!std::cin) 
		{
			std::cin.clear(); /* Oporavak toka */
			greska=KodoviGresaka::NeispravanParametar;
			NemaGreske=false;
		}
		else
		{
			p=ps();
			if(p!='\n')
			{
				greska=KodoviGresaka::NeispravanParametar;
				NemaGreske=false;
			}
			else
			{
				komanda=Komande::Blokiraj;
			}
		}}}
	}
	else if(p=='D')
	{
		p=std::cin.peek();
		if(p=='\n')
		{
			brisi=false;
			greska=KodoviGresaka::NedostajeParametar;
			NemaGreske=false;
		}
		else {std::cin >> x ;
			p=std::cin.peek();
			if(p=='\n')
			{
				brisi=false;
			greska=KodoviGresaka::NedostajeParametar;
			NemaGreske = false;
			}else{
			std::cin >> y;
		if(!std::cin) 
		{
			std::cin.clear(); /* Oporavak toka */
			greska=KodoviGresaka::NeispravanParametar;
			NemaGreske=false;
		}
		else
		{
			p=ps();
			if(p!='\n')
			{
				greska=KodoviGresaka::NeispravanParametar;
				NemaGreske=false;
			}
			else
			{
				komanda=Komande::Deblokiraj;
			}
		}}}
	}
	else if(p=='Z')
	{
		p=ps();
		if(p!='\n')
		{
			greska=KodoviGresaka::SuvisanParametar;
			NemaGreske=false;
		}
		else
			komanda=Komande::ZavrsiIgru;
	}
	else if(p=='K')
	{
		p=ps();
		if(p!='\n')
		{
			greska=KodoviGresaka::SuvisanParametar;
			NemaGreske=false;
		}
		else
			komanda=Komande::KreirajIgru;
	}
	else 
	{
		greska=KodoviGresaka::PogresnaKomanda;
		NemaGreske=false;
	}
	if(!NemaGreske)
	 if(greska!=KodoviGresaka::NedostajeParametar && brisi) std::cin.ignore(10000, '\n');
	return NemaGreske;
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y,Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0)
{
	Status st;
	if(komanda==Komande(0))
	{
		st=Idi(polja,x,y,p_smjer);
		if(st==Status::NijeKraj)
		{
			std::cout <<"Tekuca pozicija igraca je ("<< x <<"," <<y <<")\n";
		}
		else if(st==Status::KrajPoraz)
		{
			std::cout << "Nagazili ste na minu\n";
			throw std::runtime_error("Igra zavrsena");
		}
		else
		{
			std::cout << "Bravo, obisli ste sva sigurna polja\n";
			throw std::runtime_error("Igra zavrsena");
		}
	}
	else if(komanda==Komande(1))
	{
		st=Idi(polja,x,y,p_x,p_y);
		if(st==Status::NijeKraj)
		{
			std::cout <<"Tekuca pozicija igraca je ("<< x <<"," <<y <<")\n";
		}
		else if(st==Status::KrajPoraz)
		{
			std::cout << "Nagazili ste na minu\n";
			throw std::runtime_error("Igra zavrsena");
		}
		else
		{
			std::cout << "Bravo, obisli ste sva sigurna polja\n";
			throw std::runtime_error("Igra zavrsena");
		}
	}
	else if(komanda==Komande(2))
	{
		BlokirajPolje(polja,p_x,p_y);
	}
	else if(komanda==Komande(3))
	{
		DeblokirajPolje(polja,p_x,p_y);
	}
	else if(komanda==Komande(4))
	{
		Matrica mat=PrikaziOkolinu(polja,x,y);
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++) std::cout << mat[i][j] << " ";
			std::cout << "\n";
		}
	}
	else if(komanda==Komande(5))
	{
		throw std::runtime_error("Igra zavrsena");
	}
	else
	{
		int n;
		std::cout << "Unesite broj polja: ";
		std::cin >> n;
		std::cout << "Unesite pozicije mina: ";
		std::vector<std::vector<int>> v;
		std::vector<int> vm(2);
		for(int i=0;;i++)
		{
			std::cin >> std::ws;
			char p=ps();
			if(p=='.') break;
			if(p!='(')
			{
				std::cout << "Greska, unesite ponovo!\n";
				i--;
				std::cin.ignore(10000, '\n');
				continue;
			}
			std::cin >> vm[0];
			p=ps();
			if(p!=',')
			{
				std::cout << "Greska, unesite ponovo!\n";
				i--;
				std::cin.ignore(10000, '\n');
				continue;
			}
			std::cin >> vm[1];
			p=ps();
			if(p!=')')
			{
				std::cout << "Greska, unesite ponovo!\n";
				i--;
				std::cin.ignore(10000, '\n');
				continue;
			}
			p=ps();
			if(p!='\n')
			{
				std::cout << "Greska, unesite ponovo!\n";
				i--;
				std::cin.ignore(10000, '\n');
				continue;
			}
			if(vm[0]<0 || vm[1]<0 || vm[0]>=n || vm[1]>=n)
			{
				std::cout << "Greska, unesite ponovo!\n";
				i--;
				continue;
			}
			v.push_back(vm);
		}
		polja=KreirajIgru(n,v);
	}
}

int main ()
{
	int x=0,y=0;
	KodoviGresaka g;
	Smjerovi s;
	Komande k;
	Tabla t;
	poc:
	try
	{
		std::cout << "Unesite komandu: ";
		int nx,ny;
		bool sd=UnosKomande(k,s,nx,ny,g);
		if(sd)
		{
			IzvrsiKomandu(k,t,x,y,s,nx,ny);
		}
		else
			PrijaviGresku(g);
		goto poc;
	}
	catch(std::domain_error x)
	{
		std::cout << x.what();
		goto poc;
	}
	catch(std::logic_error x)
	{
		std::cout << x.what();
		goto poc;
	}
	catch(std::runtime_error x)
	{
		std::cout << "Dovidjenja!";
	}
	return 0;
}
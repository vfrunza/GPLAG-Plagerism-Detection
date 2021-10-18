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
#include <cmath>
#include <vector>
#include <string>
#include <stdexcept>
#include <sstream>
template <typename T>
std::string PretvoriUString(T x){	std::ostringstream s;	s << x;		return s.str(); }
enum class Polje
{
    Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};
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
    PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu,
    ZavrsiIgru, KreirajIgru
};
typedef std::vector<std::vector<Polje>> Tabla;

int BrojMinaUOkolini(const Tabla &polja,int x,int y)
{
	int broj_mina(0);
	for(int i=0; i<=2; i++) {
		for(int j=0; j<=2; j++) {
			if((x+i-1)<0 || x+i-1>=polja.size() || (y+j-1)<0 || y+j-1>=polja.size()) continue;
			if(i==1 && j==1) continue;
			if(polja.at(x+i-1).at(y+j-1)==Polje::Mina) broj_mina++;
		}
	}
	return broj_mina;
}

bool DaLiJeBlokirano(Tabla &polja,int x,int y)
{
	if(polja[x][y]==Polje::BlokiranoMina || polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoPosjeceno) return true;
	return false;
}

void PostaviNaPrazno(Tabla &polja)
{
	for(int i=0; i<polja.size(); i++) {
		for(int j=0; j<polja.size(); j++) {
			polja.at(i).at(j)=Polje::Prazno;
		}
	}
}

bool DaLiJeKraj(const Tabla &polja)
{
	for(int i=0; i<polja.size(); i++) {
		for(int j=0; j<polja.size(); j++) {
			if(polja.at(i).at(j)!=Polje::Posjeceno) return false;
		}
	}
	return true;
}

bool DaLiJeSlovo(char x)
{
	if((x>='A' && x<='Z')|| (x>='a' && x<='z')) return true;
	return false;
}

bool DaLiJeBroj(char x)
{
	if(x>='0' && x<='9') return true;
	return false;
}

int PretvoriUBroj(std::string string1, int x, int y)
{
	int i(0);
	int broj(0);
	if(y-x==1) {
		broj+=string1[x]-'0';
		return broj;
	}
	while(y>=x) {
		broj+=(string1[y]-'0')*pow(10,i);
		i++;
		y--;
	}
	return broj;
}

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine)
{	
	if(n<=0) throw std::domain_error("Ilegalna velicina");
	Tabla igraca_tabla(n, std::vector<Polje>(n, Polje::Prazno));
	for(int i=0; i<mine.size(); i++) {
		if(mine.at(i).size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
	}
	for(int i=0; i<mine.size(); i++) {
		if(mine[i][0]>=n || mine[i][1]>=n) throw std::domain_error("Ilegalne pozicije mina");
	}
	for(int i=0; i<mine.size(); i++)
		igraca_tabla[mine[i][0]][mine[i][1]] = Polje::Mina;
	return igraca_tabla;

}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y)
{
	std::vector<int> pomocni;
	if(x<0 || x>=polja.size() || y<0 || y>=polja.at(0).size()) throw std::domain_error("Polje ("+ PretvoriUString(x)+ ","+PretvoriUString(y)+") ne postoji");
	std::vector<std::vector<int>> Matrica;
	for(int i=-1; i<=1; i++) {
		for(int j=-1; j<=1; j++) {
			pomocni.push_back(BrojMinaUOkolini(polja,x+i,y+j));
		}
		Matrica.push_back(pomocni);
		pomocni.resize(0);
	}
	return Matrica;
}

void BlokirajPolje(Tabla &polja, int x,int y)
{
	if(x<0 || x>=polja.size() || y<0 || y>=polja.at(0).size()) throw std::domain_error("Polje ("+PretvoriUString(x)+","+PretvoriUString(y)+") ne postoji");
	for(int i=0; i<polja.size(); i++) {
		for(int j=0; j<polja.at(i).size(); j++) {
			if(i==x && j==y) {
				if(polja.at(i).at(j)==Polje::Prazno) polja.at(i).at(j)=Polje::BlokiranoPrazno;
				else if(polja.at(i).at(j)==Polje::Posjeceno) polja.at(i).at(j)=Polje::BlokiranoPosjeceno;
				else if(polja.at(i).at(j)==Polje::Mina) polja.at(i).at(j)=Polje::BlokiranoMina;
			}
		}
	}
}

void DeblokirajPolje(Tabla &polja, int x,int y)
{
	if(x<0 || x>=polja.size() || y<0 || y>=polja.at(0).size()) throw std::domain_error("Polje (" + PretvoriUString(x) + "," + PretvoriUString(y) +") ne postoji");
	for(int i=0; i<polja.size(); i++) {
		for(int j=0; j<polja.at(i).size(); j++) {
			if(i==x && j==y) {
				if(polja.at(i).at(j)==Polje::BlokiranoPrazno) polja.at(i).at(j)=Polje::Prazno;
				else if(polja.at(i).at(j)==Polje::BlokiranoPosjeceno) polja.at(i).at(j)=Polje::Posjeceno;
				else if(polja.at(i).at(j)==Polje::BlokiranoMina) polja.at(i).at(j)=Polje::Mina;
			}
		}
	}
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer)
{
	if(!(x-1>=0) && !(y-1>=0) && smjer==Smjerovi::GoreLijevo) throw std::out_of_range("Izlazak van igrace table");
	else if(!(x-1>=0) && smjer==Smjerovi::Gore) throw std::out_of_range("Izlazak van igrace table");
	else if(!(x-1>=0) && !(y+1<polja.size()) && smjer==Smjerovi::GoreDesno) throw std::out_of_range("Izlazak van igrace table");
	else if(!(y-1>=0) && smjer==Smjerovi::Lijevo) throw std::out_of_range("Izlazak van igrace table");
	else if(!(y+1<polja.size()) && smjer==Smjerovi::Desno) throw std::out_of_range("Izlazak van igrace table");
	else if(!(x+1<polja.size()) && !(y-1>=0) && smjer==Smjerovi::DoljeDesno) throw std::out_of_range ("Izlazak van igrace table");
	else if(!(x+1<polja.size()) && smjer==Smjerovi::Dolje) throw std::out_of_range("Izlazak van igrace table");
	else if(!(x+1<polja.size()) && !(y+1<polja.size()) && smjer==Smjerovi::DoljeDesno) throw std::out_of_range("Izlazak van igrace table");
	bool mina(false);
	if(x-1>=0 && y-1>=0 && smjer==Smjerovi::GoreLijevo) {

		if(DaLiJeBlokirano(polja,x-1,y-1)) throw std::logic_error("Blokirano polje");
		polja[x][y] = Polje::Posjeceno;
		x-=1;
		y-=1;
		if(polja[x][y]==Polje::Mina) mina=true;
	} else if(x-1>=0 && smjer==Smjerovi::Gore) {
		if(DaLiJeBlokirano(polja,x-1,y)) throw std::logic_error("Blokirano polje");
		polja[x][y] = Polje::Posjeceno;
		x-=1;
		if(polja[x][y]==Polje::Mina) mina=true;
	} else if(x-1>=0 && y+1<polja.size() && smjer==Smjerovi::GoreDesno) {
		if(DaLiJeBlokirano(polja,x-1,y+1)) throw std::logic_error("Blokirano polje");
		polja[x][y] = Polje::Posjeceno;
		x-=1;
		y+=1;
		if(polja[x][y]==Polje::Mina) mina=true;
	} else if(y-1>=0 && smjer==Smjerovi::Lijevo) {
		int a=x;
		int b=y-1;
		if(DaLiJeBlokirano(polja,a,b)) throw std::logic_error("Blokirano polje");
		polja[x][y]=Polje::Posjeceno;
		y-=1;
		if(polja[x][y]==Polje::Mina) mina=true;
	} else if(y+1<polja.size() && smjer==Smjerovi::Desno) {
		if(DaLiJeBlokirano(polja,x,y+1)) throw std::logic_error("Blokirano polje");
		polja[x][y] = Polje::Posjeceno;
		y+=1;
		if(polja[x][y]==Polje::Mina) mina=true;
	} else if(x+1<polja.size() && y-1>=0 && smjer==Smjerovi::DoljeLijevo) {
		if(DaLiJeBlokirano(polja,x+1,y-1)) throw std::logic_error("Blokirano polje");
		polja[x][y]=Polje::Posjeceno;
		x+=1;
		y-=1;
		if(polja[x][y]==Polje::Mina) mina=true;
	} else if(x+1<polja.size() && smjer==Smjerovi::Dolje) {
		if(DaLiJeBlokirano(polja,x+1,y)) throw std::logic_error("Blokirano polje");
		polja[x][y]=Polje::Posjeceno;
		x+=1;
		if(polja[x][y]==Polje::Mina) mina=true;
	} else if(x+1<polja.size() && y+1<polja.size() && smjer==Smjerovi::DoljeDesno) {
		if(DaLiJeBlokirano(polja,x+1,y+1)) throw std::logic_error("Blokirano polje");
		polja[x][y]=Polje::Posjeceno;
		x+=1;
		y+=1;
		if(polja[x][y]==Polje::Mina) mina=true;
	}
	if(mina) {
		PostaviNaPrazno(polja);
		return Status::KrajPoraz;
	} else if(DaLiJeKraj(polja)) return Status::KrajPobjeda;
	return Status::NijeKraj;
}

Status Idi(Tabla &polja,int &x, int &y, int novi_x, int novi_y)
{
	if(std::abs(x-novi_x)<0 || x+novi_x>polja.size() || std::abs(y-novi_y)<0 || y+novi_y>polja.size()) throw std::out_of_range("Izlazak van igrace table");
	if(DaLiJeBlokirano(polja,novi_x,novi_y)) throw std::logic_error("Blokirano polje");
	bool mina(false);

	x=novi_x;
	y=novi_y;
	if(polja[x][y]==Polje::Mina) mina=true;
	if(mina) {
		PostaviNaPrazno(polja);
		return Status::KrajPoraz;
	} else if(DaLiJeKraj(polja))
		return Status::KrajPobjeda;

	return Status::NijeKraj;
}

void PrijaviGresku(KodoviGresaka greska)
{
	if(greska==KodoviGresaka::PogresnaKomanda) std::cout<<"Nerazumljiva komanda!"<<std::endl;
	else if(greska==KodoviGresaka::NedostajeParametar) std::cout<<"Komanda trazi parametar koji nije naveden!"<<std::endl;
	else if(greska==KodoviGresaka::NeispravanParametar)	std::cout<<"Parametar komande nije ispravan!"<<std::endl;
	else if(greska==KodoviGresaka::SuvisanParametar)	 std::cout<<"Zadan je suvisan parametar nakon komande!"<<std::endl;
}
std::string OdrediSmjeric(std::string s,int brojac)
{
	std::string k("NISAMSMJERIC");
	while(brojac<s.length()) {
		if(s[brojac]=='G' && brojac+1<s.length() && s[brojac+1]=='L') {
			k="GL";
			break;
		} else if(s[brojac]=='G' && brojac+1<s.length() && s[brojac+1]=='D') {
			k="GD";
			break;
		} else if(s[brojac]=='G') {
			k="G";
			break;
		} else if(s[brojac]=='L') {
			k="L";
			break;
		} else if(s[brojac]=='D' && brojac+2<s.length() && s[brojac+1]=='o' && s[brojac+2]=='D') {
			k="DoD";
			break;
		} else if(s[brojac]=='D' && brojac+2<s.length() && s[brojac+1]=='o' && s[brojac+2]=='L') {
			k="DoL";
			break;
		} else if(s[brojac]=='D' && brojac+1<s.length() && s[brojac+1]=='o') {
			k="Do";
		} else if(s[brojac]=='D') {
			k="D";
			break;
		}
		brojac++;
	}
	return k;
}
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska)
{
	std::string s;
	std::getline(std::cin, s);
	if(s.substr(0,2)=="P1") {
		komanda = Komande::PomjeriJednoMjesto;
		std::string smjeric(OdrediSmjeric(s,0));
		if(smjeric=="GL") smjer = Smjerovi::GoreLijevo;
		else if(smjeric=="GD") smjer = Smjerovi::GoreDesno;
		else if(smjeric=="G") smjer = Smjerovi::Gore;
		else if(smjeric=="L") smjer = Smjerovi::Lijevo;
		else if(smjeric=="D") smjer = Smjerovi::Desno;
		else if(smjeric=="DoD") smjer = Smjerovi::DoljeDesno;
		else if(smjeric=="Do") smjer = Smjerovi::Dolje;
		else if(smjeric=="DoL") smjer = Smjerovi::DoljeLijevo;
	} else if(s.substr(0,2)=="P>") {
		if(2<s.length() && (s[2]==' ' || DaLiJeBroj(s[2]))) {
			int pomocnibrojac(2);
			while(s[pomocnibrojac]==' ') pomocnibrojac++;
			if(!DaLiJeBroj(s[pomocnibrojac])) {
				greska = KodoviGresaka::PogresnaKomanda;
				return false;
			}
			char p=s[pomocnibrojac];
			int brojac(pomocnibrojac);
			while(p!=' ' && brojac<s.length()) {
				brojac++;
				p=s[brojac];
			}

			if(s[brojac]!=' ') {
				greska = KodoviGresaka::PogresnaKomanda;
				return false;
			}
			x = PretvoriUBroj(s,pomocnibrojac,brojac);

			pomocnibrojac=brojac;
			while(s[pomocnibrojac]==' ') pomocnibrojac++;
			brojac = pomocnibrojac;
			while(DaLiJeBroj(s[pomocnibrojac])) pomocnibrojac++;
			y = PretvoriUBroj(s,brojac,pomocnibrojac);
			komanda = Komande::PomjeriDalje;
		} else {
			greska = KodoviGresaka::PogresnaKomanda;
			return false;
		}
	} else if(s.substr(0,2)=="PO") {
		if(s.size()!=2) {
			greska = KodoviGresaka::SuvisanParametar;
			return false;
		}
		komanda = Komande::PrikaziOkolinu;
	} else if(s[0]=='Z') {
		if(s.size()!=1) {
			greska = KodoviGresaka::SuvisanParametar;
			return false;
		}
		komanda = Komande::ZavrsiIgru;
	} else if(s[0]=='K') {
		if(s.size()!=1) {
			greska = KodoviGresaka::SuvisanParametar;
			return false;
		}
		komanda = Komande::KreirajIgru;

	} else if(s[0]=='B' || s[0]=='D') {
		if(1<s.length() && (s[1]==' ' || DaLiJeBroj(s[1]))) {
			int pomocnibrojac(1);
			while(s[pomocnibrojac]==' ') pomocnibrojac++;
			if(!DaLiJeBroj(s[pomocnibrojac])) {
				greska = KodoviGresaka::PogresnaKomanda;
				return false;
			}
			char p=s[pomocnibrojac];
			int brojac(pomocnibrojac);
			while(p!=' ' && brojac<s.length()) {
				brojac++;
				p=s[brojac];
			}
			if(s[brojac]!=' ') {
				greska = KodoviGresaka::PogresnaKomanda;
				return false;
			}
			x = PretvoriUBroj(s,pomocnibrojac,brojac);
			pomocnibrojac=brojac;
			while(s[pomocnibrojac]==' ') pomocnibrojac++;
			brojac = pomocnibrojac;
			while(DaLiJeBroj(s[pomocnibrojac])) pomocnibrojac++;
			y = PretvoriUBroj(s,brojac,pomocnibrojac);
			if(s[0]=='B') komanda = Komande::Blokiraj;
			if(s[0]=='D') komanda = Komande::Deblokiraj;
		}
	}

	return true;
}
void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0)
{

	if(komanda  == Komande::PomjeriJednoMjesto) {
		try {
			Status status = Idi(polja,x,y,p_smjer);
			if(status==Status::NijeKraj) std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
			if(status == Status::KrajPobjeda) {
				std::cout<<"Bravo, obisli ste sva sigurna polja";
				PostaviNaPrazno(polja);
				throw std::runtime_error ("Igra zavrsena");
			} else if( status == Status::KrajPoraz) {
				std::cout<<"Nagazili ste na minu"<<std::endl;
				PostaviNaPrazno(polja);
				throw std::runtime_error ("Igra zavrsena");
			}
		} catch (std::out_of_range izuzetak) {
			std::cout << izuzetak.what() << std::endl;
		} catch (std::logic_error izuzetak1) {
			std::cout << izuzetak1.what() << std::endl;
		}

	} else if (komanda == Komande::PomjeriDalje) {
		try {
			Status status = Idi(polja,x,y,p_x,p_y);
			if(status==Status::NijeKraj) std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
			if(status == Status::KrajPobjeda) {
				std::cout<<"Bravo, obisli ste sva sigurna polja";
				PostaviNaPrazno(polja);
				throw std::runtime_error ("Igra zavrsena");
			} else if(status == Status::KrajPoraz) {
				std::cout<<"Nagazili ste na minu";
				PostaviNaPrazno(polja);
				throw std::runtime_error ("Igra zavrsena");
			}
		} catch (std::out_of_range izuzetak) {
			std::cout << izuzetak.what() << std::endl;
		} catch (std::logic_error izuzetak1) {
			std::cout << izuzetak1.what() << std::endl;
		}
	} else if (komanda == Komande::Blokiraj) {
		try {
			BlokirajPolje(polja,p_x,p_y);
		} catch (std::domain_error izuzetak) {
			std::cout << izuzetak.what() << std::endl;
		}
	} else if (komanda == Komande::Deblokiraj) {
		try {
			DeblokirajPolje(polja,p_x,p_y);
		} catch (std::domain_error izuzetak) {
			std::cout<<izuzetak.what()<<std::endl;
		}
	} else if (komanda == Komande::PrikaziOkolinu) {
		try {
			auto Matrica(PrikaziOkolinu(polja,x,y));
			for(auto red : Matrica) {
				for(auto broj : red) std::cout<<broj<<" ";
				std::cout<<std::endl;
			}
		} catch (std::domain_error izuzetak) {
			std::cout<<izuzetak.what()<<std::endl;
		}
	} else if (komanda == Komande::ZavrsiIgru) {
		PostaviNaPrazno(polja);
		throw std::runtime_error("Igra zavrsena");
	} else if (komanda == Komande::KreirajIgru) {
		std::cout<<"Unesite broj polja: ";
		int k;
		for(;;) {
			std::cin>>k;
			if(k>0) break;
			else std::cout<<"Greska, unesite ponovo!"<<std::endl<<"Unesite broj polja: ";
			
		}
		std::cin.ignore(10000,'\n');
		std::vector<std::vector<int>> mine;
		std::cout<<"Unesite pozicije mina: ";
		std::string mine1;
		int x,y;
		bool ispravno(true);
		for(;;) {
			std::getline(std::cin,mine1);
			if(mine1[0]=='.') break;
			if(mine1[0]!= '(' ) {
				std::cout<<"Greska, unesite ponovo!"<<std::endl;
				mine1.resize(0);
				continue;
			}
			if(mine1[0]=='(') {
				int i(1);
				while(mine1.at(i)==' ' && i<mine1.size()) {
					i++;
				}
				if(DaLiJeBroj(mine1[i])) x=mine1[i]-'0';
				else {
					std::cout<<"Greska, unesite ponovo!"<<std::endl;
					mine1.resize(0);
					continue;
				}
				if(i<mine1.size()) i++;
				while(mine1.at(i)==' ' && i<mine1.size()) {
					i++;
				}
				if(mine1.at(i)==',') {
					if(i<mine1.size()) i++;
					while(mine1.at(i)==' ' && i<mine1.size()) i++;
					if(DaLiJeBroj(mine1.at(i))) y = mine1[i]-'0';
					else {
						std::cout<<"Greska, unesite ponovo!"<<std::endl;
						mine1.resize(0);
						continue;
					}
				} else {
					std::cout<<"Greska, unesite ponovo!"<<std::endl;
					mine1.resize(0);
					continue;
				}
				if(DaLiJeBroj(mine1.at(i))) {
					if(i<mine1.size()) i++;
					while(mine1.at(i)==' ' && i<mine.size()) {
						i++;
					}
					if(mine1.at(i)==')') {
						ispravno=true;
						if(i<mine1.size()) i++;
						while(i<mine1.size()) {
							if(mine1.at(i)!=' ') ispravno=false;
							i++;
						}
						if(!ispravno) {
							std::cout<<"Greska, unesite ponovo!"<<std::endl;
							mine1.resize(0);
							continue;
						}
					} else {
						std::cout<<"Greska, unesite ponovo!"<<std::endl;
						mine1.resize(0);
						continue;
					}
				}
				if(x>k || y > k) {
					std::cout<<"Greska, unesite ponovo!"<<std::endl;
					mine1.resize(0);
					continue;
				}
				std::vector<int> pomocni;
				pomocni.push_back(x);
				pomocni.push_back(y);
				mine.push_back(pomocni);
				mine1.resize(0);
			}
		}
		polja = KreirajIgru(k,mine);
	}
}
int main ()
{

	try {
		Tabla polja;
		KodoviGresaka greske;
		Komande komanda;
		Smjerovi smjeric;
		int x(0),y(0),nx(0),ny(0);
		for(;;) {
			std::cout<<"Unesite komandu: ";
			if(UnosKomande(komanda,smjeric,nx,ny,greske)) {
				IzvrsiKomandu(komanda,polja,x,y,smjeric,nx,ny);
			} else PrijaviGresku(greske);
		}
	} catch(...) {
		std::cout<<"Dovidjenja!"<<std::endl;
	}
	return 0;
	
}
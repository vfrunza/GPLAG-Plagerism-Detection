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
enum class Smjerovi {GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo};
enum class Status {NijeKraj, KrajPoraz, KrajPobjeda};
enum class KodoviGresaka {PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar};
enum class Komande {PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru};

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine) {
	Tabla polja(n, std::vector<Polje> (n, Polje::Prazno));
	if(n<=0) throw std::domain_error ("Ilegalna velicina");
	for(int i=0; i<mine.size(); i++) if(mine[i].size()!=2) throw std::domain_error ("Ilegalan format zadavanja mina");
	for(int i=0; i<mine.size(); i++) {
		if(mine[i][0]>=n || mine[i][0]<0  || mine[i][1]>=n || mine[i][1]<0)  throw std::domain_error ("Ilegalna pozicija mine");
		polja[mine[i][0]][mine[i][1]]=Polje::Mina;
	}
	return polja;
}

int BrojMina(const Tabla &polje, int x, int y, int n) {
	int br(0);
	if(x-1>=0) {
		if(y-1>=0) if(polje[x-1][y-1]==Polje::Mina) br++;
		if(polje[x-1][y]==Polje::Mina) br++;
		if(y+1<n) if(polje[x-1][y+1]==Polje::Mina) br++;
	}
	if(y-1>=0) if(polje[x][y-1]==Polje::Mina) br++;
	if(y+1<n) if(polje[x][y+1]==Polje::Mina) br++;
	if(x+1<n) {
		if(y-1>=0) if(polje[x+1][y-1]==Polje::Mina) br++;
		if(polje[x+1][y]==Polje::Mina) br++;
		if(y+1<n) if(polje[x+1][y+1]==Polje::Mina) br++;
	}
	return br;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y) {
	std::vector<std::vector<int>> okolina(3, std::vector<int> (3, 0));
	int xx(x+1), yy(y+1);
	int n=polja.size();
	int brx(2), bry;
	if(x<0 || x>=polja.size() || y<0 || y>=polja.size()) throw std::domain_error ("Polje (x,y) ne postoji");
	while(xx>=0 && brx>=0) {
		bry=2;
		yy=y+1;
		while(yy>=0 && bry>=0) {
			okolina[brx][bry]=BrojMina(polja, xx, yy--, n);
			bry--;
		}
		
		if(bry==0) okolina[brx][bry]=BrojMina(polja, xx, yy, n);
		xx--; brx--;
	}
	if(bry==0) okolina[brx][bry]=BrojMina(polja, xx, yy, n);
	return okolina;
}

void BlokirajPolje(Tabla &polja, int x, int y) {
	if(x>polja.size()-1 || x<0 || y>polja.size()-1 || y<0) throw std::domain_error("Polje (x,y) ne postoj");
	if(polja[x][y]==Polje::Prazno) polja[x][y]=Polje::BlokiranoPrazno;
	else if(polja[x][y]==Polje::Posjeceno) polja[x][y]=Polje::BlokiranoPosjeceno;
	else if(polja[x][y]==Polje::Mina) polja[x][y]=Polje::BlokiranoMina;
}

void DeblokirajPolje(Tabla &polja, int x, int y) {
	if(x>polja.size()-1 || x<0 || y>polja.size()-1 || y<0) throw std::domain_error("Polje (x,y) ne postoji");
	if(polja[x][y]==Polje::BlokiranoPrazno) polja[x][y]=Polje::Prazno;
	else if(polja[x][y]==Polje::BlokiranoPosjeceno) polja[x][y]=Polje::Posjeceno;
	else if(polja[x][y]==Polje::BlokiranoMina) polja[x][y]=Polje::Mina;
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer) {
	int starox(x), staroy(y);
	polja[x][y]=Polje::Posjeceno;
	if(smjer==Smjerovi::GoreLijevo) {x--; y--;}
	else if(smjer==Smjerovi::Gore) x--;
	else if(smjer==Smjerovi::GoreDesno) {x--; y++;}
	else if(smjer==Smjerovi::Desno) y++;
	else if(smjer==Smjerovi::DoljeDesno) {y++; x++;}
	else if(smjer==Smjerovi::Dolje) x++;
	else if(smjer==Smjerovi::DoljeLijevo) {x++; y--;}
	else if(smjer==Smjerovi::Lijevo) y--;
	if(x<0 || y<0 || x>polja.size()-1 || y>polja.size()-1) {
		x=starox; y=staroy;
		throw std::out_of_range("Izlazak van igrace table");
	}
	if(polja[x][y]==Polje::Posjeceno) {
		x=starox; y=staroy;
		throw std::logic_error ("Blokirano polje");
	}
	if(polja[x][y]==Polje::Mina) {
		for(int i=0; i<polja.size(); i++)
			for(int j=0; j<polja.size(); j++) polja[i][j]=Polje::Prazno;
		return Status::KrajPoraz;
	}
	polja[x][y]=Polje::Posjeceno;
	bool ima_praznih(false);
	for(int i=0; i<polja.size(); i++)
			for(int j=0; j<polja.size(); j++) 
				if(polja[i][j]==Polje::Prazno) {
					ima_praznih=true;
					break;
				} 
	if(!ima_praznih){
		for(int i=0; i<polja.size(); i++)
			for(int j=0; j<polja.size(); j++) polja[i][j]=Polje::Prazno; 
		return Status::KrajPobjeda;
	}	
	return Status::NijeKraj;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y) {
	int starox(x), staroy(y);
	polja[x][y]=Polje::Posjeceno;
	x=novi_x; 
	y=novi_y;
	if(x<0 || y<0 || x>polja.size()-1 || y>polja.size()-1) {
		x=starox; y=staroy;
		throw std::out_of_range("Izlazak van igrace table");
	}
	if(polja[x][y]==Polje::Posjeceno) {
		x=starox; y=staroy;
		throw std::logic_error ("Blokirano polje");
	}
	if(polja[x][y]==Polje::Mina) {
		for(int i=0; i<polja.size(); i++)
			for(int j=0; j<polja.size(); j++) polja[i][j]=Polje::Prazno;
		return Status::KrajPoraz;
	}
	bool ima_praznih(false);
	polja[x][y]=Polje::Posjeceno;
	for(int i=0; i<polja.size(); i++)
			for(int j=0; j<polja.size(); j++) 
				if(polja[i][j]==Polje::Prazno) {
					ima_praznih=true;
					break;
				} 
	if(!ima_praznih){
		for(int i=0; i<polja.size(); i++)
			for(int j=0; j<polja.size(); j++) polja[i][j]=Polje::Prazno; 
		return Status::KrajPobjeda;
	}
	return Status::NijeKraj;
}

void PrijaviGresku(KodoviGresaka greska) {
	if(greska==KodoviGresaka::PogresnaKomanda) std::cout<<"Nerazumljiva komanda!"<<std::endl;
	else if(greska==KodoviGresaka::NedostajeParametar) std::cout<<"Komanda trazi parametar koji nije naveden"<<std::endl;
	if(greska==KodoviGresaka::NeispravanParametar) std::cout<<"Parametar koamnde nije ispravan!"<<std::endl;
	if(greska==KodoviGresaka::SuvisanParametar) std::cout<<"Zadan je suvisan parametar nakon komande!"<<std::endl;
}

bool UnosKomande(Komande &komanda, Smjerovi &smjerovi, int &x, int &y, KodoviGresaka &greska) {
		std::string s1, s2;
		int a(0), b(0);
		char c;
		std::cout<<"Unesite komandu: ";
		std::getline(std::cin, s1);
		for(int i=0; i<s1.size(); i++) {
			if(s1[i]!=' ' && s1[i]!='P' && s1[i]!='B' && s1[i]!='Z' && s1[i]!='D' && s1[i]!='K' && (s1[i]<'0' || s1[i]>'9')) {
					std::cout<<"Greska, unesite ponovo!"<<std::endl;
					break;
				}
			if(s1[i]=='P') {
				break;
			}
			if(s1[i]=='D' || s1[i]=='B' || (s1[i]=='P' && s1[i]=='>')) {
				c=s1[i];
				while(i<s1.size()) {
					if(s1[i]<='9' && s1[i]>='0') {
						while(s1[i]<='9' && s1[i]>='0') {
							a=a*10+s1[i]-'0';
							i++;
						}
					}
					if(s1[i]<='9' && s1[i]>='0') {
						while(s1[i]<='9' && s1[i]>='0') {
							b=b*10+s1[i]-'0';
							i++;
						}
					}
					i++;
				}
				break;
			}
		}
		if(c=='B') { 
			komanda=Komande::Blokiraj;
			x=a; y=b;
		}
		else if(c=='P') { 
			komanda=Komande::PomjeriDalje;
			x=a; y=b;
		}
		else if(c=='D') {
			komanda=Komande::Deblokiraj;
			x=a; y=b;
		}
		else if(c=='Z') komanda=Komande::ZavrsiIgru;
		else if(c=='K') komanda=Komande::KreirajIgru; 
		else {
			greska=KodoviGresaka::PogresnaKomanda;
			return false;
			}
	return true;
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x=0, int p_y=0) {
	Status st(Status::NijeKraj);
	if(komanda==Komande::PomjeriJednoMjesto) {
		st=Idi(polja, x, y, p_smjer);
		std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
	}
	else if(komanda==Komande::PomjeriDalje) {
		st=Idi(polja, x, y, p_x, p_y);
		std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
	}
	if(st==Status::KrajPoraz) {
		std::cout<<"Nagazili ste na minu"<<std::endl;
		throw std::runtime_error ("Igra zavrsena");
	}
	else if(st==Status::KrajPobjeda) {
		std::cout<<"Bravo, obisli ste sva sigurna polja"<<std::endl;
		throw std::runtime_error ("Igra zavrsena");
	}
	if(komanda==Komande::Blokiraj) BlokirajPolje(polja, x, y);
	else if(komanda==Komande::Deblokiraj) DeblokirajPolje(polja, x, y);
	else if(komanda==Komande::PrikaziOkolinu) {
		std::vector<std::vector<int>> v=PrikaziOkolinu(polja, x, y);
		for(std::vector<int> q : v) {
			for(int w : q) std::cout<<w<<" ";
		std::cout<<std::endl;
		}
	}
	else if(komanda==Komande::KreirajIgru) {
			int n;
			std::vector<std::vector<int>> pozicije_mina;
			std::cout<<"Unesite broj polja: ";
			while(!(std::cin>>n)) {
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				std::cout<<"Greska, unesite ponovo!"<<std::endl<<"Unesite broj polja: ";
			}
			std::cout<<"Unesite pozicije mina: ";
			for(;;) {
				int xx(0), yy(0);
				std::vector<int> mina(2);
				std::string s;
				std::getline(std::cin, s);
				if(s==".") break;
				for(int i=0; i<s.size(); i++) {
					if(s[i]!=' ' && s[i]!='(' && s[i]!=')' && s[i]!=',' && (s[i]<'0' || s[i]>'9')) {
						std::cout<<"Greska, unesite ponovo!"<<std::endl;
						break;
					}
					if(xx==0) while(s[i]>='0' && s[i]<='9') {
							xx=xx*10+s[i]-'0';
							i++;
						}
					if(yy==0) while(s[i]>='0' && s[i]<='9') {
							yy=yy*10+s[i]-'0';
							i++;
						}
					if(xx>n-1 || yy>n-1) {
						std::cout<<"Greska, unesite ponovo!"<<std::endl;
						break;	
					}
					mina[0]=xx;
					mina[1]=yy;
					pozicije_mina.push_back(mina);
				}
			}
	}
	else if(komanda==Komande::ZavrsiIgru) {
		for(int i=0; i<polja.size(); i++)
			for(int j=0; j<polja.size(); j++) polja[i][j]=Polje::Prazno;
		std::cout<<"Dovidjenja!"<<std::endl;
	}
}

int main ()
{
	int x(0), y(0);
	Tabla polja;
	Komande komanda;
	Smjerovi smjer;
	KodoviGresaka greska;
	for(;;) {
		if(UnosKomande(komanda, smjer, x, y, greska)) {
			if(komanda==Komande::PomjeriJednoMjesto) IzvrsiKomandu(komanda, polja, x, y, smjer);
			//else if(komanda==Komande::PomjeriDalje) IzvrsiKomandu(komanda, x, y, smjer);
			else if(komanda==Komande::Blokiraj) IzvrsiKomandu(komanda, polja, x, y);
			else if(komanda==Komande::Deblokiraj) IzvrsiKomandu(komanda, polja, x, y);
			else if(komanda==Komande::PrikaziOkolinu) IzvrsiKomandu(komanda, polja, x, y);
			else if(komanda==Komande::ZavrsiIgru){ 
				IzvrsiKomandu(komanda, polja, x, y);
				return 0;
			}
		}
		else PrijaviGresku(greska);
	}
	return 0;
}
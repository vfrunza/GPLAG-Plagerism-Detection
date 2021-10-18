/*B 16/17, Zadaća 2, Zadatak 1

	NAPOMENA: i javni ATo-vi su dio postavke

	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba

*/
#include <iostream>
#include <stdexcept>
#include <vector>
#include <deque>
#include <string>

using std::cin;

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

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine)
{
	Tabla igra(n, std::vector<Polje>(n, Polje::Prazno));
	for(int i=0; i<mine.size(); i++) {
		if(mine[i].size()!=2) throw std::domain_error ("Ilegalan format zadavanja mina");
		if(mine[i][0]>n-1 or mine[i][1]>n-1) throw std::domain_error ("Ilegalne pozicije mina");
		igra[mine[i][0]][mine[i][1]]=Polje::Mina;
	}
	return igra;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y)
{
	if(x<0 or y<0 or x>=polja.size() or y>=polja.size()) throw std::domain_error ("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	std::vector<std::vector<int>> brojmina(3, std::vector<int>(3, 0));
	int px(x), py(y);
	// px - pozicija x
	// p2x - pozicija x koordinate kad se ispituje ima li mina
	if(x==0 and y==0) {
		px=x;
		py=y;
	} else if(x!=0 and y!=0) {
		px=x-1;
		py=y-1;
	} else if(x==0) {
		px=x;
		py=y-1;
	} else if(y==0) {
		px=x-1;
		py=y;
	}
	for(int i=0; i<3; i++) {
		if(px+i>=polja.size()) continue;
		if(px+i>x+1) continue;
		for(int j=0; j<3; j++) {
			if(py+j>=polja.size()) continue;
			if(py+j>=y+2) continue;
			int p2x(px+i), p2y(py+j);
			if(px+i==0 and py+j==0) {
				p2x=px+i;
				p2y=py+j;
			} else if(px+i!=0 and py+j!=0) {
				p2x=px+i-1;
				p2y=py+j-1;
			} else if(px+i==0) {
				p2x=px+i;
				p2y=py+j-1;
			} else if(py+j==0) {
				p2x=px+i-1;
				p2y=py+j;
			}
			for(int p=p2x; p<p2x+3; p++) {
				if(p>polja.size()-1) break;
				if(p>px+i+1) continue;
				for(int q=p2y; q<p2y+3; q++) {
					if(q>polja.size()-1) break;
					if(q>py+j+1) continue;
					if(px+i==p and py+j==q) continue;
					if(polja[p][q]==Polje::Mina) {
						brojmina[i][j]++;
					}
				}
			}
		}
	}
	return brojmina;
}

void BlokirajPolje(Tabla &polja, int x, int y)
{
	if(x<0 or y<0 or x>=polja.size() or y>=polja.size()) throw std::domain_error ("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	if(polja[x][y]==Polje::Prazno) polja[x][y]=Polje::BlokiranoPrazno;
	if(polja[x][y]==Polje::Posjeceno) polja[x][y]=Polje::BlokiranoPosjeceno;
	if(polja[x][y]==Polje::Mina) polja[x][y]=Polje::BlokiranoMina;
}

void DeblokirajPolje(Tabla &polja, int x, int y)
{
	if(x<0 or y<0 or x>=polja.size() or y>=polja.size()) throw std::domain_error ("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	if(polja[x][y]==Polje::BlokiranoPrazno) polja[x][y]=Polje::Prazno;
	if(polja[x][y]==Polje::BlokiranoPosjeceno) polja[x][y]=Polje::Posjeceno;
	if(polja[x][y]==Polje::BlokiranoMina) polja[x][y]=Polje::Mina;
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer)
{	int novi_x(x), novi_y(y);
	if(smjer==Smjerovi::Gore) novi_x--;
	else if(smjer==Smjerovi::GoreDesno) {
		novi_x--;
		novi_y++;
	} else if(smjer==Smjerovi::GoreLijevo) {
		novi_x--;
		novi_y--;
	} else if(smjer==Smjerovi::DoljeLijevo) {
		novi_x++;
		novi_y--;
	} else if(smjer==Smjerovi::DoljeDesno) {
		novi_x++;
		novi_y++;
	} else if(smjer==Smjerovi::Dolje) novi_x++;
	else if(smjer==Smjerovi::Lijevo)novi_y--;
	else if(smjer==Smjerovi::Desno) novi_y++;
	if(novi_x<0 or novi_x>=polja.size() or novi_y<0 or novi_y>=polja.size()) throw std::out_of_range ("Izlazak van igrace table");
	if(polja[novi_x][novi_y]==Polje::BlokiranoPosjeceno or polja[novi_x][novi_y]==Polje::BlokiranoPrazno or polja[novi_x][novi_y]==Polje::BlokiranoMina)
		throw std::logic_error ("Blokirano polje");
	polja[x][y]=Polje::Posjeceno;
	x=novi_x;
	y=novi_y;
	if (polja[novi_x][novi_y]==Polje::Mina) return Status::KrajPoraz;
	bool nijekraj(false);
	for(int i=0; i<polja.size(); i++) {
		for(int j=0; j<polja[i].size(); j++) {
			if(polja[i][j]==Polje::Prazno) nijekraj=true;
		}
	}
	if(nijekraj) return Status::NijeKraj;
	return Status::KrajPobjeda;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y)
{
	if(novi_x<0 or novi_x>=polja.size() or novi_y<0 or novi_y>=polja.size()) throw std::out_of_range ("Izlazak van igrace table");
	if(polja[novi_x][novi_y]==Polje::BlokiranoPosjeceno or polja[novi_x][novi_y]==Polje::BlokiranoPrazno or polja[novi_x][novi_y]==Polje::BlokiranoMina)
		throw std::logic_error ("Blokirano polje");
	polja[x][y]=Polje::Posjeceno;
	x=novi_x;
	y=novi_y;
	if (polja[x][y]==Polje::Mina) return Status::KrajPoraz;
	bool nijekraj(false);
	for(int i=0; i<polja.size(); i++) {
		for(int j=0; j<polja[i].size(); j++) {
			if(polja[i][j]==Polje::Prazno) nijekraj=true;
		}
	}
	if(nijekraj) return Status::NijeKraj;
	return Status::KrajPobjeda;
}

enum class KodoviGresaka
{
    PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};
using std::cout;

void PrijaviGresku(KodoviGresaka greska)
{
	if(greska==KodoviGresaka::PogresnaKomanda) std::cout << "Nerazumljiva komanda!"<<std::endl;
	if(greska==KodoviGresaka::NedostajeParametar) std::cout<<"Komanda trazi parametar koji nije naveden!"<<std::endl;
	if(greska==KodoviGresaka::NeispravanParametar) cout << "Parametar komande nije ispravan!"<<std::endl;
	if(greska==KodoviGresaka::SuvisanParametar) cout <<"Zadan je suvisan parametar nakon komande!"<<std::endl;
}

enum class Komande
{
    PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu,
    ZavrsiIgru, KreirajIgru
};


bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y,KodoviGresaka &greska)
{
	std::string s;
	std::getline(std::cin, s);
	std::vector<std::string> komande {"PO", "K", "Z", "P1", "P>", "B", "D"};
	std::vector<Komande> komande_nestring {Komande::PrikaziOkolinu, Komande::KreirajIgru, Komande::ZavrsiIgru, Komande::PomjeriJednoMjesto, Komande::PomjeriDalje, Komande::Blokiraj, Komande::Deblokiraj};
	std::vector<std::string> parametri_p1 {"GD", "GL", "G", "DoD", "DoL", "Do","D", "L"};
	std::vector<Smjerovi> parametri_p1_nestr {Smjerovi::GoreDesno, Smjerovi::GoreLijevo, Smjerovi::Gore, Smjerovi::DoljeDesno, Smjerovi::DoljeLijevo, Smjerovi::Dolje, Smjerovi::Desno, Smjerovi::Lijevo};
	for(int i=0; i<s.length(); i++) {
		while(i<s.length() and s.at(i)==' ') i++;
		for(int k=0; k<komande.size(); k++) {
			if(i+komande[k].length()-1< s.length() and s.substr(i,komande[k].length())==komande[k]) {
				if(k<3) {
					if(s[i+komande[k].length()]=='\n'){ 
						komanda=komande_nestring[k];
						return true;
					}
					else if(i+komande[k].length()<s.length() and s[i+komande[k].length()]!=' ') {
						greska=KodoviGresaka::SuvisanParametar;
						return false;
					}
					while(i+komande[k].length()<s.length() and s[i+komande[k].length()]==' ') i++;
					if(i+komande[k].length()!=s.length()) {
						greska=KodoviGresaka::SuvisanParametar;
						return false;
					}
					komanda=komande_nestring[k];
					return true;
				} else if(k==3) {
					i+=komande[k].length();
					while(i<s.length() and s[i]==' ') i++;
					if(i==s.length()) {
						greska=KodoviGresaka::NedostajeParametar;
						return false;
					}
					for(int j=0; j<parametri_p1.size(); j++) {
						if(i+parametri_p1[j].length()<int(s.length()+1) and s.substr(i, parametri_p1[j].length())==parametri_p1[j]) {
							if(i+parametri_p1[j].length()<s.length() and s[i+parametri_p1[j].length()]!=' ') {
								greska=KodoviGresaka::NeispravanParametar;
								return false;
							}
							while(i+parametri_p1[j].length()<s.length() and s[i+parametri_p1[j].length()]==' ') i++;
							if(i+parametri_p1[j].length()!=s.length()) {
								greska=KodoviGresaka::NeispravanParametar;
								return false;
							}
							for (auto z=i+parametri_p1[j].length(); z<s.length(); z++){
								if(s[z]!=' '){
									greska=KodoviGresaka::NeispravanParametar;
									return false;
								}
							}
							smjer=parametri_p1_nestr[j];
							komanda=komande_nestring[k];
							return true;
						}
					}
					if(i!=s.length()) greska=KodoviGresaka::NeispravanParametar;
					else greska=KodoviGresaka::NedostajeParametar;
					return false;
				} else if(k>3) {
					i+=komande[k].length();
					while(i<s.length() and s[i]==' ') i++;
					if(i==s.length()) {
						greska=KodoviGresaka::NedostajeParametar;
						return false;
					}
					if(s[i]<'0' or s[i]>'9') {
						greska=KodoviGresaka::NeispravanParametar;
						return false;
					}
					int x1(i);
					if(i+1<s.length()) i++;
					while(i<s.length() and s[i]==' ') i++;
					if(i==s.length()) {
						greska=KodoviGresaka::NedostajeParametar;
						return false;
					}
					if(s[i]<'0' or s[i]>'9') {
						greska=KodoviGresaka::NeispravanParametar;
						return false;
					}
					for(auto z=i+1; z<s.length(); z++){
						if(s[z]!=' '){
							greska=KodoviGresaka::NeispravanParametar;
							return false;
						}
					}
					x=s[x1]-'0';
					y=s[i]-'0';
					komanda=komande_nestring[k];
					return true;
				}
			}
		}
	}
	greska=KodoviGresaka::PogresnaKomanda;
	return false;
}


void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0)
{
	std::vector<Komande> komande {Komande::PomjeriJednoMjesto, Komande::PomjeriDalje, Komande::Blokiraj, Komande::Deblokiraj, Komande::PrikaziOkolinu, Komande::ZavrsiIgru, Komande::KreirajIgru};
	int i;
	bool izuz(false);
	for(i=0; i<komande.size(); i++) {
		if(komanda==komande[i]) break;
	}
	Status status;
	if(i==0) {
		try {
			status=Idi(polja,x,y,p_smjer);
		} catch(std::out_of_range izuzetak) {
			cout << izuzetak.what() << std::endl;
			izuz=true;
		} catch (std::logic_error izuzetak) {
			cout << izuzetak.what() << std::endl;
			izuz=true;
		}
	} else if(i==1) {
		try {
			status=Idi(polja,x,y,p_x,p_y);
		} catch(std::out_of_range izuzetak) {
			cout << izuzetak.what() << std::endl;
			izuz=true;
		} catch (std::logic_error izuzetak) {
			cout << izuzetak.what() << std::endl;
			izuz=true;
		}

	} else if(i==2) {
		try {
			BlokirajPolje(polja,p_x,p_y);
		} catch(...) {
			cout << "Polje ("<< p_x << ","<<p_y <<") ne postoji!" << std::endl;
		}
	} else if(i==3) {
		try {
			DeblokirajPolje(polja, p_x,p_y);
		} catch(...) {
			cout << "Polje ("<< p_x << ","<<p_y <<") ne postoji!" << std::endl;
		}
	} else if(i==4) {
		try {
			std::vector<std::vector<int>> a(PrikaziOkolinu(polja,x,y));
			for(int j=0; j<3; j++) {
				for(int k=0; k<3; k++) {
					cout<< a[j][k] << " ";
				}
				cout << std::endl;
			}
		} catch(...) {
			cout << "Polje ("<< p_x << ","<<p_y <<") ne postoji!"<< std::endl;
		}
	} else if(i==5) {
		
		for(int j=0; j<polja.size(); j++) {
			for(int k=0; k<polja[j].size(); k++) {
				polja[j][k]=Polje::Prazno;
			}
		}
		throw std::runtime_error ("Igra zavrsena");
	} else if(i==6) {
		cout << "Unesite broj polja: ";
		int n;
		cin >> n;
		std::cin.ignore(10000, '\n');
		std::string s;
		std::vector<std::vector<int>> mine;
		std::vector<int> red;
		cout << "Unesite pozicije mina: ";
		std::getline(std::cin, s);
		for(;;) {
			if(s==".") break;
			bool greska(false);
			std::vector<int> red;
			if(int(s.length())!=5) {
				cout << "Greska, unesite ponovo!" << std::endl;
				s.resize(0);
				std::getline(std::cin, s);
				if(s==".") break;
				continue;
			}
			if(s[0]!='(') greska=true;
			if(s[1]<'0' or s[1]>'9' or s[1]-'0'>=n) greska=true;
			if(s[2]!=',') greska=true;
			if(s[3]<'0' or s[3]>'9' or s[3]-'0'>=n) greska=true;
			if(s[4]!=')') greska=true;
			if(s[1]==0 and s[3]==0) greska=true;
			if(greska) {
				cout << "Greska, unesite ponovo!" << std::endl;
				s.resize(0);
				std::getline(std::cin, s);
				if(s=="."){ 
					break;
				}
				continue;
			} else {
				red.push_back(s[1]-'0');
				red.push_back(s[3]-'0');
				mine.push_back(red);
				s.resize(0);
				std::getline(std::cin, s);
				if(s==".") break;
			}
		}
		try {
			polja=KreirajIgru(n, mine);
		} catch(std::domain_error izuzetak) {
			cout<<izuzetak.what()<<std::endl;
		}
	}
	if((i==0 or i==1) and !izuz) {
		if(status==Status::NijeKraj) cout << "Tekuca pozicija igraca je ("<< x << ","<<y <<")"<< std::endl;
		else if(status==Status::KrajPoraz) {
			cout << "Nagazili ste na minu"<< std::endl;
			for(int j=0; j<polja.size(); j++) {
				for(int k=0; k<polja[i].size(); k++) {
					polja[j][k]=Polje::Prazno;
				}
			}
			throw std::runtime_error ("Igra zavrsena");
		} else if(status==Status::KrajPobjeda) {
			cout << "Bravo, obisli ste sva sigurna polja";
			for(int j=0; j<polja.size(); j++) {
				for(int k=0; k<polja[i].size(); k++) {
					polja[j][k]=Polje::Prazno;
				}
			}
			throw std::runtime_error ("Igra zavrsena");
		}
	}

}



int main ()
{
	Tabla polja;
	int x(0), y(0), p_x(0), p_y(0);
	Komande komanda;
	KodoviGresaka greska;
	Smjerovi smjer;
	for(;;){
		cout << "Unesite komandu: ";
		if(UnosKomande(komanda, smjer, p_x, p_y, greska)){
			try{
				IzvrsiKomandu(komanda, polja, x, y, smjer, p_x, p_y);
			}
			catch(...){
				cout << "Dovidjenja!";
				break; 
			}
		}
		else PrijaviGresku(greska);
	}
	

	return 0;
}
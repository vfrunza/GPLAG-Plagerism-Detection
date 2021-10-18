#include <iostream>
#include <vector>
#include <sstream>
#include <exception>
#include <stdexcept>
#include <string>
using std::cout;
using std::cin;
using std::vector;
using std::string;
enum class Polje { Prazno=0, Posjeceno=1, Mina=2, BlokiranoPrazno=3,
    BlokiranoPosjeceno=4, BlokiranoMina=5
};
enum class Smjerovi { GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};
enum class Status { NijeKraj, KrajPoraz, KrajPobjeda
};
enum class KodoviGresaka { PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};
enum class Komande { PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};
typedef vector<vector<Polje>> Tabla;
template <typename T> std::string PretvoriUString(T x) {
	std::ostringstream s; s << x; return s.str();
}
void polje_izuzetak(string &s, const int &x, const int &y) {
	s="Polje (,) ne postoji";
	string s1 {PretvoriUString(x)}, s2 {PretvoriUString(y)};
	s.insert(7,s1); s.insert(s.find(',')+1,s2);
}
void Greska() { cout << "Greska, unesite ponovo!" << std::endl;
}
void WhiteSpaceEater() { while(cin.peek()==' ') cin.get();
}
void PrijaviGresku(KodoviGresaka greska) {
	vector<string> greske {{"Nerazumljiva komanda!"},{"Komanda trazi parametar koji nije naveden!"},
		{"Zadan je suvisan parametar nakon komande!"},{"Parametar komande nije ispravan!"}};
	cout << greske.at(static_cast<int>(greska)) <<std::endl;
}
bool ValidanUnosMina(string &s,int &x, int &y, int n) {
	string::iterator It {s.begin()};
	int temp {0}, faktor {1};
	while(*It==' ') It++;
	if(*It!='(') {
		Greska();
		return false;
	} else It++;
	while(*It==' ') It++;
	while(*It>=48 && *It<=57) It++;
	It--;
	while(*It>=48 && *It<=57) {
		temp=temp+faktor*(int(*It)-'0');
		faktor*=10;
		It--;
	}
	It++;
	while(*It>=48 && *It<=57) It++;;
	x=temp;
	temp=0;
	faktor=1;
	while(*It==' ') It++;
	if(*It!=',') {
		Greska();
		return false;
	} else It++;
	while(*It==' ') It++;
	while(*It>=48 && *It<=57) It++;
	It--;
	while(*It>=48 && *It<=57) {
		temp=temp+faktor*(int(*It)-'0');
		faktor*=10;
		It--;
	}
	It++;
	while(*It>=48 && *It<=57) It++;
	y=temp;
	while(*It==' ') It++;
	if(*It!=')') {
		Greska();
		return false;
	} else It++;
	if(It!=s.end()) {
		Greska();
		return false;
	}
	if(x>n-1 || y>n-1 || y<0 || x<0) {
		Greska();
		return false;
	}
	return true;
}
void IspisiMatricu(vector<vector<int>> M) {
	for(int i=0; i<M.size(); i++) {
		for(int j=0; j<M.at(i).size(); j++)
			cout << M.at(i).at(j) << " ";
		cout<<std::endl;
	}
}
void OcistiTablu(Tabla &polja) {
	for(int i=0; i<polja.size(); i++)
		for(int j=0; j<polja.at(i).size(); j++)
			polja.at(i).at(j)=Polje::Prazno;
}
int IspitajOkolinu(const Tabla &polja,int x,int y,int n) {
	int suma {0};
	for(int i=-1; i<2; i++)
		for(int j=-1; j<2; j++) {
			if((i==0 && j==0) || (x+i>n-1 || x+i<0 || y+j>n-1 || y+j<0)) continue;
			if(polja.at(x+i).at(y+j)==Polje::Mina) suma++;
		}
	return suma;
}
Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine) {
	if(n<=0) throw std::domain_error("Ilegalna veličina");
	Tabla tabla(n,vector<Polje>(n,Polje::Prazno));
	for(int i=0; i<mine.size(); i++) {
		if(mine.at(i).size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
		if(mine.at(i).at(0)>n-1 || mine.at(i).at(0)<0 || mine.at(i).at(1)>n-1 || mine.at(i).at(1)<0 )
			throw std::domain_error("Ilegalne pozicije mina");
		tabla.at(int(mine.at(i).at(0))).at(int(mine.at(i).at(1)))=Polje::Mina;
	}
	return tabla;
}
vector<vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y) {
	vector<vector<int>> Okolina(3,vector<int>(3));
	if(x>polja.size()-1 || x<0 || y>polja.size()-1 || y<0) {
		string s; polje_izuzetak(s,x,y);
		throw std::domain_error(s);
	}
	for(int i=-1,a=0; i<2; i++)
		if(!(x+i>polja.size()-1 || x+i<0)){
		for(int j=-1,b=0; j<2; j++) {
			int suma {0};
			if(!(y+j>polja.size()-1 || y+j<0)){
			suma=IspitajOkolinu(polja,x+i,y+j,polja.size());
			Okolina.at(a).at(b)=suma;
			b++;}
		}
		a++;}
	return Okolina;
}
void BlokirajPolje(Tabla &polja, int x, int y) {
	if(x>polja.size()-1 || x<0 || y>polja.size()-1 || y<0) { string s; polje_izuzetak(s,x,y);
		throw std::domain_error(s);}
	if(polja.at(x).at(y)<Polje::BlokiranoPrazno)
		polja.at(x).at(y) = static_cast<Polje>(int(polja.at(x).at(y))+3);
}
void DeblokirajPolje(Tabla &polja, int x, int y) {
	if(x>polja.size()-1 || x<0 || y>polja.size()-1 || y<0) {string s; polje_izuzetak(s,x,y);
		throw std::domain_error(s);}
	if(polja.at(x).at(y)>=Polje::BlokiranoPrazno)
		polja.at(x).at(y) = static_cast<Polje>(int(polja.at(x).at(y))-3);
}
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y) {
	if(novi_x>polja.size()-1 || novi_x<0 || novi_y>polja.size()-1 || novi_y<0)
		throw std::out_of_range("Izlazak van igrace table\n");
	if(polja.at(novi_x).at(novi_y)>=Polje::BlokiranoPrazno)
		throw std::logic_error("Blokirano polje\n");

	polja.at(x).at(y)=Polje::Posjeceno;
	x=novi_x; y=novi_y;
	if(polja.at(x).at(y)==Polje::Mina) {
		OcistiTablu(polja); return Status::KrajPoraz;
	}
	for(int i=0; i<polja.size(); i++)
		for(int j=0; j<polja.at(i).size(); j++) {
			if(i==x && j==y) continue;
			if(polja.at(i).at(j)==Polje::Prazno)
				return Status::NijeKraj;
		}
	return Status::KrajPobjeda;
}
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer) {
	vector<vector<int>> vsmjer {{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
	// Ima smisla ovdje pozvati funkciju koja prima konkretne koordinate
	return Idi(polja,x,y,x+vsmjer.at(int(smjer)).at(0),y+vsmjer.at(int(smjer)).at(1));
}
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska) {
	vector<string> skomande {"P1","P>","B","D","PO","Z","K"};
	string unos;
	bool SveOk {false};
	cin >> unos;
	for(int i=0; i<skomande.size(); i++)
		if(unos==skomande.at(i)) {
			komanda= static_cast<Komande>(i);
			SveOk=true;
			break;
		}

	if(!SveOk) {
		greska=KodoviGresaka::PogresnaKomanda;
		return false;}
		
	else if(SveOk) {
		
		if(komanda==Komande::PomjeriJednoMjesto) {
			vector<string> ssmjer {"GL","G","GD","D","DoD","Do","DoL","L"};
			string unos_smjer;
			if(cin.peek()==10) {
				greska=KodoviGresaka::NedostajeParametar;
				return false;
			}
			WhiteSpaceEater();
			cin >> unos_smjer;
			for(int i=0; i<ssmjer.size(); i++)
				if(unos_smjer==ssmjer.at(i)) {
					smjer=static_cast<Smjerovi>(i);
					SveOk=true;
					break;
				} else {
					greska=KodoviGresaka::NeispravanParametar;
					SveOk=false;
				}
			if(!SveOk) return false;
			while(cin.peek()!='\n') if(cin.get()!=' ') {
					greska=KodoviGresaka::SuvisanParametar;
					cin.ignore(1000,'\n');
					return false;
				}
		}

		else if(komanda>=Komande::PomjeriDalje && komanda<=Komande::Deblokiraj) {
			int a, b;
			SveOk=true;
			WhiteSpaceEater();
			if(cin.peek()=='\n') {
				greska=KodoviGresaka::NedostajeParametar;
				return false;
			}
			cin >> a;
			if(cin.peek()!=' ' || cin.fail()) {
				greska=KodoviGresaka::NeispravanParametar;
				cin.clear();
				cin.ignore(1000,'\n');
				return false;
			} else {
				WhiteSpaceEater();
				cin >> b;
				if(!(cin.peek()=='\n' || cin.peek()==' ') || cin.fail()) {
					greska=KodoviGresaka::NeispravanParametar;
					return false;
				}
				while(cin.peek()!='\n') if(cin.get()!=' ') {
						greska=KodoviGresaka::SuvisanParametar;
						cin.ignore(1000,'\n');
						return false;
					}
			}
			x=a;
			y=b;
		}

		else if(komanda>=Komande::PrikaziOkolinu) {
			while(cin.peek()!='\n') if(cin.get()!=' ') {
					greska=KodoviGresaka::SuvisanParametar;
					cin.ignore(1000,'\n');
					return false;
				}
		}
	}

	return true;
}
void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer=Smjerovi::Gore, int p_x=0, int p_y=0) {
	if(komanda==Komande::KreirajIgru) {
		int n;
		bool valid {true};
		do {
			valid=true;
			cout << "Unesite broj polja: ";
			cin >> n;
			if(cin.peek()!='\n' || cin.fail() || n<=0) {
				Greska();
				cin.clear();
				cin.ignore(1000,'\n');
				valid=false;
			}
		} while(!valid);
		cin.ignore(1000,'\n');
		cout << "Unesite pozicije mina: ";
		vector<vector<int>> m;
		int a,b;
		string s;
		for(;;) {
			WhiteSpaceEater();
			if(cin.peek()=='.') break;
			getline(cin,s);
			if(ValidanUnosMina(s,a,b,n))
				m.push_back({a,b});
		}
		try {
			cin.get();
			polja=KreirajIgru(n,m);
		} catch(std::exception& x) {
			cout << x.what();
			throw;
		}
	}

	else if(komanda==Komande::PomjeriDalje) {
		try {
			Status s = Idi(polja,x,y,p_x,p_y);
			if(s==Status::NijeKraj) cout << "Tekuca pozicija igraca je (" << x << "," << y << ")" << std::endl;
			else if (s==Status::KrajPobjeda) {
				cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
				komanda=Komande::ZavrsiIgru;
			} else {
				cout << "Nagazili ste na minu" << std::endl;
				komanda=Komande::ZavrsiIgru;
				OcistiTablu(polja);
			}
		} catch(std::exception& ex) {
			cout << ex.what();
		}
	}

	else if(komanda==Komande::PomjeriJednoMjesto) {
		try {
			Status s = Idi(polja,x,y,p_smjer);
			if(s==Status::NijeKraj) cout << "Tekuca pozicija igraca je (" << x << "," << y << ")" << std::endl;
			else if (s==Status::KrajPobjeda) {
				komanda=Komande::ZavrsiIgru;
				cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
			} else {
				cout << "Nagazili ste na minu" << std::endl;
				komanda=Komande::ZavrsiIgru;
				OcistiTablu(polja);
			}
		} catch(std::exception& ex) {
			cout << ex.what();
		}
	}

	else if(komanda==Komande::PrikaziOkolinu)
		try {
			IspisiMatricu(PrikaziOkolinu(polja,x,y));
		} catch(std::domain_error& d) {
			cout << d.what();
		}

	else if(komanda==Komande::Blokiraj)
		try {
			BlokirajPolje(polja,p_x,p_y);
		} catch(std::domain_error& d) {
			cout << d.what();
		}

	else if(komanda==Komande::Deblokiraj)
		try {
			DeblokirajPolje(polja, p_x, p_y);
		} catch(std::domain_error& d) {
			cout << d.what();
		}

	if(komanda==Komande::ZavrsiIgru) {
		OcistiTablu(polja);
		throw std::runtime_error("Igra zavrsena");
	}
}
int main (){
	try {
		Tabla b(0,vector<Polje>(0));
		int pozicija_x=0, pozicija_y=0;
		for(;;) {
			Komande komanda;
			Smjerovi smjer;
			KodoviGresaka greska;
			int nova_x,nova_y;
			cout << "Unesite komandu: ";
			if(UnosKomande(komanda,smjer,nova_x,nova_y,greska))
				IzvrsiKomandu(komanda, b, pozicija_x, pozicija_y, smjer, nova_x,nova_y);

			else PrijaviGresku(greska); 
			
		}
	} catch(std::exception) {
		cout << "Dovidjenja!";
	}

	return 0;
}
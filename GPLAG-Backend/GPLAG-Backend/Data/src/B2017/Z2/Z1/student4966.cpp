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
#include <algorithm>
#include <string>
#include <complex>

enum class Polje { Prazno=0, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina }; 
enum class Smjerovi { GoreLijevo=0, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo };
enum class Status { NijeKraj=0, KrajPoraz, KrajPobjeda };
enum class KodoviGresaka { PogresnaKomanda=0, NedostajeParametar, SuvisanParametar, NeispravanParametar};
enum class Komande { PomjeriJednoMjesto=0, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru};
typedef std::vector<std::vector<Polje>> Tabla;
typedef std::vector<int> Vektor;
typedef std::vector<Vektor> Matrica;
Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine) {
	if (n<=0) throw std::domain_error("Ilegalna veličina");
	for (int i=0;i<mine.size();i++) {
		if (mine[i].size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
		for (int j=0;j<mine[i].size();j++) {
			if (mine[i][j]>=n || mine[i][j]<0 || (mine[i][0]==0 && mine[i][1]==0)) throw std::domain_error("Ilegalne pozicije mina");
		}
	}
	Tabla tabla;
	for (int i=0;i<n;i++) 
		tabla.push_back(std::vector<Polje>(n, Polje::Prazno));
	for (int i=0;i<mine.size();i++) 
		tabla[mine[i][0]][mine[i][1]]=Polje::Mina;
	return tabla;
}
Matrica PrikaziOkolinu (const Tabla &tabla, int x, int y) {
	if (x<0 || y<0 || x>=tabla.size() || y>=tabla.size()) throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	Matrica mat(3, std::vector<int>(3));
	std::vector<Matrica> indeksi{{{x-2,y-2},{x-2,y-1},{x-2,y}},{{x-1,y-2},{x-1,y-1},{x-1,y}},{{x,y-2},{x,y-1},{x,y}}};
	for (int i=0;i<3;i++){
		for (int j=0;j<3;j++) {
			int suma(0);
			for (int k=indeksi[i][j][0];k<indeksi[i][j][0]+3;k++) {
				if (k<0 || k>=tabla.size())
					continue;
				for (int l=indeksi[i][j][1];l<indeksi[i][j][1]+3;l++) {
					if (l<0 || l>=tabla.size())
						continue;
					if (tabla[k][l]==Polje::Mina && (k!=indeksi[i][j][0]+1 || l!=indeksi[i][j][1]+1))
						suma++;
				}
			}
			mat[i][j]=suma;
		}
	}
	return mat;
}
void BlokirajPolje(Tabla &tabla, int x, int y) {
	if (x<0 || y<0 || x>=tabla.size() || y>=tabla.size()) throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	if (tabla[x][y]==Polje::Prazno) tabla[x][y]=Polje::BlokiranoPrazno;
	if (tabla[x][y]==Polje::Posjeceno) tabla[x][y]=Polje::BlokiranoPosjeceno;
	if (tabla[x][y]==Polje::Mina) tabla[x][y]=Polje::BlokiranoMina;
}
void DeblokirajPolje(Tabla &tabla, int x, int y) {
	if (x<0 || y<0 || x>=tabla.size() || y>=tabla.size()) throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	if (tabla[x][y]==Polje::BlokiranoPrazno) tabla[x][y]=Polje::Prazno;
	if (tabla[x][y]==Polje::BlokiranoPosjeceno) tabla[x][y]=Polje::Posjeceno;
	if (tabla[x][y]==Polje::BlokiranoMina) tabla[x][y]=Polje::Mina;
}
void OcistiTablu(Tabla &tabla) {
	for (int i=0;i<tabla.size();i++)
		for (int j=0;j<tabla[i].size();j++) 
			tabla[i][j]=Polje::Prazno;
}
bool ImaLiPraznih(Tabla &tabla, const int x, const int y) {
	bool imalipraznih(false);
	for (int i=0;i<tabla.size();i++) {
		for (int j=0;j<tabla.size();j++) {
			if (i==x && j==y) continue;
			if (tabla[i][j]==Polje::Prazno)
				imalipraznih=true;
		}
	}
	return imalipraznih;
}
Status Idi(Tabla &tabla, int &x, int &y, Smjerovi smjer) {
	Matrica mat{{x-1,y-1},{x-1,y},{x-1,y+1},{x,y+1},{x+1,y+1},{x+1,y},{x+1,y-1},{x,y-1}};
	if (mat[static_cast<int>(smjer)][0]<0 || mat[static_cast<int>(smjer)][0]>=tabla.size() || mat[static_cast<int>(smjer)][1]<0 || mat[static_cast<int>(smjer)][1]>=tabla.size()) 
		throw std::out_of_range("Izlazak van igrace table");
	if (tabla[mat[static_cast<int>(smjer)][0]][mat[static_cast<int>(smjer)][1]]==Polje::BlokiranoPosjeceno || tabla[mat[static_cast<int>(smjer)][0]][mat[static_cast<int>(smjer)][1]]==Polje::BlokiranoPrazno || tabla[mat[static_cast<int>(smjer)][0]][mat[static_cast<int>(smjer)][1]]==Polje::BlokiranoMina)
		throw std::logic_error("Blokirano polje");
	if (tabla[mat[static_cast<int>(smjer)][0]][mat[static_cast<int>(smjer)][1]]==Polje::Mina) {
		OcistiTablu(tabla);
		return Status::KrajPoraz;
	} 
	tabla[x][y]=Polje::Posjeceno;
	x=mat[static_cast<int>(smjer)][0]; y=mat[static_cast<int>(smjer)][1];
	if (!ImaLiPraznih(tabla, x, y))
		return Status::KrajPobjeda;
	return Status::NijeKraj;
}
Status Idi(Tabla &tabla, int &x, int &y, int novix, int noviy) {
	if (novix<0 || noviy<0 || novix>=tabla.size() || noviy>=tabla.size())
		throw std::out_of_range("Izlazak van igrace table");
	if (tabla[novix][noviy]==Polje::BlokiranoPosjeceno || tabla[novix][noviy]==Polje::BlokiranoPrazno || tabla[novix][noviy]==Polje::BlokiranoMina)
		throw std::logic_error("Blokirano polje");
	if (tabla[novix][noviy]==Polje::Mina) {
		OcistiTablu(tabla);
		return Status::KrajPoraz;
	}
	tabla[x][y]=Polje::Posjeceno;
	x=novix; y=noviy;
	if (!ImaLiPraznih(tabla, x, y))
		return Status::KrajPobjeda;
	return Status::NijeKraj;
}
void PrijaviGresku(KodoviGresaka greska) {
	std::vector<std::string> vektor{{"Nerazumljiva komanda!"}, {"Komanda trazi parametar koji nije naveden!"}, {"Zadan je suvisan parametar nakon komande!"}, {"Parametar komande nije ispravan!"}};
	std::cout<<vektor[static_cast<int>(greska)]<<std::endl;
}
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska) {
	std::vector<std::string> vektor{{"P1"},{"P>"},{"B"},{"D"},{"PO"},{"Z"},{"K"}};
	std::vector<std::string> smjerovi{{"GL"},{"G"},{"GD"},{"D"},{"DoD"},{"Do"},{"DoL"},{"L"}};
	std::string komanda1;
	std::cin.sync();
	std::cin>>std::ws>>komanda1;
	auto it=std::find(vektor.begin(), vektor.end(), komanda1);
	if (it!=vektor.end()) {
		if (it-vektor.begin()>=1 && it-vektor.begin()<=3) {
			while (std::cin.peek()==' ')
				std::cin.get();
			if (std::cin.peek()>='0' && std::cin.peek()<='9') {
				int xkoord, ykoord;
				std::cin>>xkoord;
				while (std::cin.peek()==' ')
					std::cin.get();
				if (std::cin.peek()<'0' || std::cin.peek()>'9') {
					greska=KodoviGresaka::NeispravanParametar;
					std::cin.ignore(50, '\n');
					return false;
				}
				else {
					std::cin>>ykoord;
					while (std::cin.peek()==' ')
						std::cin.get();
					if (std::cin.peek()!='\n') {
						greska=KodoviGresaka::SuvisanParametar;
						std::cin.ignore(50, '\n');
						return false;
					}
				}
				x=xkoord;
				y=ykoord;
				komanda=static_cast<Komande>(it-vektor.begin());
				return true;
			}
			else if (std::cin.peek()!='\n') {
				greska=KodoviGresaka::NeispravanParametar;
				std::cin.ignore(50, '\n');
				return false;
			}
			else {
				greska=KodoviGresaka::NedostajeParametar;
				std::cin.ignore(50,'\n');
				return false;
			}
		}
		else if (it-vektor.begin()==0) {
			while(std::cin.peek()==' ')
				std::cin.get();
			if (std::cin.peek()=='\n') {
				greska=KodoviGresaka::NedostajeParametar;
				std::cin.ignore(50, '\n');
				return false;
			}
			std::string smjer1;
			std::cin>>smjer1;
			while(std::cin.peek()==' ')
				std::cin.get();
			if (std::cin.peek()!='\n'){
				greska=KodoviGresaka::SuvisanParametar;
				std::cin.ignore(50, '\n');
				return false;
			}
			auto it2=std::find(smjerovi.begin(), smjerovi.end(), smjer1);
			if (it2==smjerovi.end()) {
				greska=KodoviGresaka::NeispravanParametar;
				std::cin.ignore(50, '\n');
				return false;
			}
			else {
				komanda=Komande::PomjeriJednoMjesto;
				smjer=static_cast<Smjerovi>(it2-smjerovi.begin());
				std::cin.ignore(50, '\n');
				return true;
			}
		}
		else {
			while (std::cin.peek()==' ')
				std::cin.get();
			if (std::cin.peek()!='\n') {
				greska=KodoviGresaka::SuvisanParametar;
				std::cin.ignore(50, '\n');
				return false;
			}
			komanda=static_cast<Komande>(it-vektor.begin());
			std::cin.ignore(50, '\n');
			return true;
		}
	}
	else {
		greska=KodoviGresaka::PogresnaKomanda;
		std::cin.ignore(50, '\n');
		return false;
	}
	return false;
}
bool ProvjeriUnos (std::string s, int &x, int &y) {
	for (auto it=s.begin();it!=s.end();it++) {
		if (*it==' ') {
			s.erase(it);
			it--;
		}
	}
	if (s.length()!=5) return false;
	if (s[0]=='(' && s[2]==',' && s[4]==')') {
		if ((s[1]>='0' && s[1]<='9') && (s[3]>='0' && s[3]<='9')) {
			x=s[1]-'0';
			y=s[3]-'0';
			return true;
		}
	}
	return false;
}
void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0) {
	try { 
		if (komanda==Komande::PomjeriJednoMjesto || komanda==Komande::PomjeriDalje) {
			Status status;
			if (komanda==Komande::PomjeriJednoMjesto)
				status=Idi(polja, x, y, p_smjer);
			else
				status=Idi(polja, x, y, p_x, p_y);
			if (status!=Status::NijeKraj) {
				if (status==Status::KrajPobjeda) std::cout<<"Bravo, obisli ste sva sigurna polja"<<std::endl;
				if (status==Status::KrajPoraz) std::cout<<"Nagazili ste na minu"<<std::endl;
				OcistiTablu(polja);
				throw std::runtime_error("Igra zavrsena");
			}
			std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
		}
		if (komanda==Komande::Blokiraj) BlokirajPolje(polja, p_x, p_y);
		if (komanda==Komande::Deblokiraj) DeblokirajPolje(polja, p_x, p_y);
		if (komanda==Komande::PrikaziOkolinu) { 
			Matrica mat=PrikaziOkolinu(polja, x, y);
			for (int i=0;i<mat.size();i++) {
				for (int j=0;j<mat[i].size();j++)
					std::cout<<mat[i][j]<<" ";
				std::cout<<std::endl;
			}
		}
		if (komanda==Komande::ZavrsiIgru) { OcistiTablu(polja); throw std::runtime_error("Igra zavrsena"); }
		if (komanda==Komande::KreirajIgru) {
			int brojpolja;
			bool logicka(true);
			do {
				logicka=true;
				std::cout<<"Unesite broj polja: ";
				std::cin.sync();
				std::cin>>brojpolja;
				if (brojpolja<=0) {
					logicka=false;
					std::cout<<"Greska, unesite ponovo!"<<std::endl;
				}
				if (!std::cin || std::cin.peek()!='\n') {
					std::cout<<"Greska, unesite ponovo!"<<std::endl;
					logicka=false;
					std::cin.clear();
					std::cin.sync();
					std::cin.ignore(100, '\n');
				}
			} while(!logicka);
			std::cout<<"Unesite pozicije mina: ";
			Matrica mine;
			bool dalijetacka(false);
			std::cin.get();
			do {
				std::string s;
				bool logicka2(true);
				int x, y;
				std::cin.sync();
				std::getline(std::cin, s);
				logicka2=ProvjeriUnos(s, x, y);
				if (s==".") dalijetacka=true;
				if (!logicka2) {
					if (!dalijetacka) std::cout<<"Greska, unesite ponovo!"<<std::endl;
				}
				else {
					if (x<0 || y<0 || x>=brojpolja || y>=brojpolja) std::cout<<"Greska, unesite ponovo!"<<std::endl;
					else { 
						std::vector<int> v;
						v.push_back(x); v.push_back(y);
						mine.push_back(v);
					}
				}
			} while(!dalijetacka);
			polja=KreirajIgru(brojpolja, mine);
		}
	}
	catch(std::domain_error domen) {
		std::cout<<domen.what()<<std::endl;
	}
	catch(std::out_of_range vanopsega) {
		std::cout<<vanopsega.what()<<std::endl;
	}
	catch(std::logic_error logika) {
		std::cout<<logika.what()<<std::endl;
	}
}
int main ()
{
	int x(0), y(0), p_x, p_y;
	Tabla tabla;
	Smjerovi smjer;
	KodoviGresaka greska;
	Komande komanda;
	bool logicka;
	for (;;) {
		std::cout<<"Unesite komandu: ";
		try {
			logicka=UnosKomande(komanda, smjer, p_x, p_y, greska);
			if (logicka) {
				IzvrsiKomandu(komanda, tabla, x, y, smjer, p_x, p_y);
			}
			else {
				PrijaviGresku(greska);
			}
		}
		catch(std::runtime_error err) {
			std::cout<<"Dovidjenja!";
			return 0;
		}
	}
	return 0;
}
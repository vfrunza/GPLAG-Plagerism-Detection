/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
using std:: cin;
using std:: cout;
using std:: vector;

enum class Polje {Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina};
typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru( int n, vector<vector<int>> mine){
	for (int i=0; i<mine.size(); i++){
		if(mine[i].size()!= 2) throw std::domain_error("Ilegalan format zadavanja mina");
		for(int j=0; j<2; j++) {
			if(mine[i][j]>=n || mine[i][j]<0) throw std::domain_error("Ilegalne pozicije mina");
		}
	}
	Tabla t(n, std::vector<Polje>(n,Polje:: Prazno) );
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			for(int k=0; k<mine.size(); k++){
				if(i==mine[k][0] && j== mine[k][1]) t[i][j]= Polje:: Mina;
			}
		}
	}
	return t;
}

vector<vector<int>> PrikaziOkolinu(Tabla t, int x, int y){
	vector<vector<int>> m(3, std::vector<int> (3,0));
	if(x<0|| y<0 || x>=t.size() || y>= t.size()) throw std::domain_error ("Polje (x,y) ne postoji");
	for (int i=0; i<t.size(); i++){
		for(int j=0; j<t.size(); j++){
			if(i==x && j==y){
				for(int k=i-1; k<i+2; k++){
					if(k<0 || k>=t.size()) continue;
					for(int l=j-1; l<j+2; l++){
						int br(0);
						if(l<0 || l>=t.size()) continue;
						for(int a=k-1; a<k+2; a++){
							if(a<0 || a>=t.size()) continue;
							for(int b=l-1; b<l+2; b++){
								if(b<0 || b>=t.size()) continue;
								if(t[a][b]==Polje::Mina && (a!=k || b!=l) ) br++;
							}
						}
						m[k-i+1][l-j+1]=br;
					}
					
					
				}
					
			}
		}
	}
	return m;
}
void BlokirajPolje (Tabla &t, int x, int y){
	if(x<0|| y<0 || x>=t.size() || y>= t.size()) throw std::domain_error ("Polje (x,y) ne postoji");
	for(int i=0; i<t.size(); i++){
		for(int j=0; j<t.size(); j++){
			if(i==x && j==y){
				if(t[i][j]== Polje::Prazno) t[i][j]=Polje:: BlokiranoPrazno;
				if(t[i][j]== Polje::Posjeceno) t[i][j]=Polje:: BlokiranoPosjeceno;
				if(t[i][j]== Polje::Mina) t[i][j]=Polje::BlokiranoMina;
			}
		}
	}
}
void DeblokirajPolje (Tabla &t, int x, int y){
	if(x<0|| y<0 || x>=t.size() || y>= t.size()) throw std::domain_error ("Polje (x,y) ne postoji");
	for(int i=0; i<t.size(); i++){
		for(int j=0; j<t.size(); j++){
			if(i==x && j==y){
				if(t[i][j]== Polje::BlokiranoPrazno) t[i][j]=Polje::Prazno;
				if(t[i][j]== Polje::BlokiranoPosjeceno) t[i][j]=Polje::Posjeceno;
				if(t[i][j]== Polje::BlokiranoMina) t[i][j]=Polje::Mina;
			}
		}
	}
}
enum class Smjerovi {
 GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};
enum class Status {
 NijeKraj, KrajPoraz, KrajPobjeda
};
Status StatusIgre(Tabla t, int x, int y){
	if(x<0 || y<0 || x>=t.size() || y>=t.size()) throw std::out_of_range ("Izlazak van igrace table");
	if(t[x][y]== Polje::BlokiranoPosjeceno || t[x][y]== Polje:: BlokiranoPrazno || t[x][y]== Polje:: BlokiranoMina) throw std::logic_error ("Blokirano polje");
	if(t[x][y]== Polje::Mina) return Status::KrajPoraz;
	for(int i=0; i<t.size(); i++){
		for(int j=0; j<t.size(); j++){
			if(t[i][j]==Polje::Prazno) return Status::NijeKraj;
		}
	}
	return Status::KrajPobjeda;
	
}

Status Idi(Tabla &t, int&x, int&y, Smjerovi s){
	int a(x), b(y);
	t[x][y]= Polje::Posjeceno;
	if(s== Smjerovi::Gore || s== Smjerovi::GoreDesno || s== Smjerovi::GoreLijevo) x--;
	if(s== Smjerovi::Dolje || s== Smjerovi::DoljeDesno || s== Smjerovi::DoljeLijevo) x++;
	if(s== Smjerovi::Desno || s== Smjerovi::GoreDesno || s== Smjerovi::DoljeDesno) y++;
	if(s== Smjerovi::Lijevo || s== Smjerovi::DoljeLijevo || s== Smjerovi::GoreLijevo) y++;
	try {return StatusIgre(t, x, y);}
	catch(...) {
		t[a][b]=Polje::Prazno;
		x=a;
		y=b;
		throw;}
}
Status Idi(Tabla &t, int&x, int&y, int x1, int y1){
	int a(x), b(y);
	x=x1; y=y1;
	try {return StatusIgre(t, x, y);}
	catch(...) {
		t[a][b]=Polje::Prazno;
		x=a;
		y=b;
		throw;}
	
}
enum class KodoviGresaka {
 PogresnaKomanda, NedostajeParmetar, SuvisanParametar, NeispravanParametar
};
void PrijaviGresku(KodoviGresaka greska){
	switch (greska){
		case KodoviGresaka(0): cout << "Nerazumljiva komanda!"; break;
		case KodoviGresaka(1): cout << "Komanda trazi parametar koji nije naveden!"; break;
		case KodoviGresaka(2): cout << "Parametar komande nije ispravan!"; break;
		case KodoviGresaka(3): cout << "Zadan je suvisan parametar nakon komande!" ;break;
	}
}
enum class Komande {
 PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu,
 ZavrsiIgru, KreirajIgru
};

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y,KodoviGresaka &greska){
	std::string s;
	std::getline(cin, s);
	for(int i=0; i<s.length(); i++)
		if(s[i]==' ') s.erase(s.begin()+i);
		if(s[0]=='Z'){
			if(s.length()!=1){
				greska=KodoviGresaka::SuvisanParametar;
				return false;
			}
			komanda=Komande:: ZavrsiIgru;
			return true;
		}
		if(s[0]=='K'){
			if(s.length()!=1){
				greska=KodoviGresaka::SuvisanParametar;
				return false;
			}
			komanda=Komande:: KreirajIgru;
			return true;
		}
		if(s[0]=='B'){
			if(s.length()<3) {
				greska=KodoviGresaka::NedostajeParmetar;
				return false;
			}
			if(s[1]>='0' && s[1]<='9' && s[2]>='0' && s[2]<='9'){
				x=s[1]-'0';
				y=s[2]-'0';
				komanda= Komande:: Blokiraj;
				return true;
				
			}
			else if(s.length()>3) greska=KodoviGresaka::SuvisanParametar;
			else greska=KodoviGresaka::NeispravanParametar;
			return false;
		}
		if(s[0]=='D'){
			if(s.length()<3) {
				greska=KodoviGresaka::NedostajeParmetar;
				return false;
			}
			if(s[1]>='0' && s[1]<='9' && s[2]>='0' && s[2]<='9'){
				x=s[1]-'0';
				y=s[2]-'0';
				komanda= Komande:: Deblokiraj;
				return true;
				
			}
			else if(s.length()>3) greska=KodoviGresaka::SuvisanParametar;
			else greska=KodoviGresaka::NeispravanParametar;
			return false;
		}
		if(s[0]=='P'){
			if(s.length()==1){
				greska=KodoviGresaka:: NedostajeParmetar;
				return false;
			}
			if(s[1]=='O'){
				if(s.length()==2){
					komanda=Komande:: PrikaziOkolinu;
					return true;
				}
				greska=KodoviGresaka::SuvisanParametar;
				return false;
			}
			if(s[1]=='1'){
			 if(s.length()==2){
				greska=KodoviGresaka:: NedostajeParmetar;
				return false;
			}
			
				if(s.substr(2,s.length())=="GL") {komanda=Komande:: PomjeriJednoMjesto; smjer= Smjerovi::GoreLijevo;return true;}
				if(s.substr(2,s.length())=="G") {komanda=Komande:: PomjeriJednoMjesto; smjer= Smjerovi::Gore; return true;}
				if(s.substr(2,s.length())=="GD"){ komanda=Komande:: PomjeriJednoMjesto; smjer= Smjerovi::GoreDesno;return true;}
				if(s.substr(2,s.length())=="D"){ komanda=Komande:: PomjeriJednoMjesto; smjer= Smjerovi::Desno; return true;}
				if(s.substr(2,s.length())=="DoD"){ komanda=Komande:: PomjeriJednoMjesto; smjer= Smjerovi::DoljeDesno; return true;}
				if(s.substr(2,s.length())=="Do") {komanda=Komande:: PomjeriJednoMjesto; smjer= Smjerovi::Dolje; return true;}
			    if(s.substr(2,s.length())=="DoL"){ komanda=Komande:: PomjeriJednoMjesto; smjer= Smjerovi::DoljeLijevo;return true;}
				if(s.substr(2,s.length())=="L"){ komanda=Komande:: PomjeriJednoMjesto; smjer= Smjerovi::Lijevo; return true;}
			
			 greska=KodoviGresaka:: NeispravanParametar; return false;
			
		   }
		   if(s[1]=='>'){
		   	if(s.length()<4) {
				greska=KodoviGresaka::NedostajeParmetar;
				return false;
			}
			if(s[2]>='0' && s[2]<='9' && s[3]>='0' && s[3]<='9'){
				x=s[2]-'0';
				y=s[3]-'0';
				komanda= Komande:: Blokiraj;
				return true;
				
			}
			
			else greska=KodoviGresaka::NeispravanParametar;
			return false;
		}
		   }
		   greska=KodoviGresaka:: PogresnaKomanda;
		return false;
	
}
void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y,Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0){
	
}

int main ()
{
	return 0;
}
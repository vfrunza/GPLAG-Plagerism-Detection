#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;
enum class Polje
{
    Prazno,Posjeceno,Mina,BlokiranoPrazno,BlokiranoPosjeceno,BlokiranoMina
};
enum class Smjerovi
{
    GoreLijevo,Gore,GoreDesno,Desno,DoljeDesno,Dolje,DoljeLijevo,Lijevo
};
enum class Status
{
    NijeKraj,KrajPoraz,KrajPobjeda
};
enum class KodoviGresaka
{
    PogresnaKomanda,NedostajeParametar,SuvisanParametar,NeispravanParametar
};
enum class Komande
{
    PomjeriJednoMjesto,PomjeriDalje,Blokiraj,Deblokiraj,PrikaziOkolinu,ZavrsiIgru,KreirajIgru
};
typedef vector<vector<Polje>> Tabla;
Tabla KreirajIgru(int n,const vector<vector<int>> &mine)
{
	for(int i=0; i<mine.size(); i++) {
		if(mine[i].size()!=2) throw domain_error("Ilegalan format zadavanja mina");
	}
	for(int i=0; i<mine.size(); i++) {
		for(int j=0; j<mine[i].size(); j++) {
			if(mine[i][j]>=n || mine[i][j]<0) throw domain_error("Ilegalne pozicije mina");
		}
	}
	if(n<=0) throw domain_error("Ilegalna velicina");
	Tabla tabla(n,vector<Polje>(n,Polje::Prazno));
	for(int i(0); i<mine.size(); i++) {
		for(int j(0); j<mine[i].size()-1; j++) {
			tabla[mine[i][j]][mine[i][j+1]]=Polje::Mina;
		}
	}
	return tabla;
}
vector<vector<int>> PrikaziOkolinu(const Tabla &polja, int x,int y)
{
	if(x>=polja.size() || x<0 || y>=polja.size() || y<0) throw domain_error("Polje (x, y) ne postoji");
	vector<vector<int>> matrica(3,vector<int> (3,0));
	int x1(0),y1(0);
	for(int i=x-1; i<=x+1; i++) {
		for(int j=y-1; j<=y+1; j++) {
			int brojac(0);
			if(y1==matrica.size()) {
				y1=0;
				x1++;
			}
			if(x1==matrica.size()) break;
			if(i>=0 && i<polja.size() && j>=0 && j<polja[0].size()) {
				for(int k=i-1; k<=i+1; k++) {
					for(int l=j-1; l<=j+1; l++) {
						if(k>=0 && k<polja.size() && l>=0 && l<polja[0].size()) {
							if(polja.at(k).at(l)==Polje::Mina &&( k!=i || l!=j)) brojac++;
						}
					}
				}
			}
			matrica.at(x1).at(y1)=brojac;
			y1++;
		}
	}
	return matrica;
}
void BlokirajPolje(Tabla &polja,int x,int y)
{
	if(x<0 || x>=polja.size() || y<0 || y>=polja.size()) throw domain_error("Polje (x, y) ne postoji");
	if(polja[x][y]==Polje::Prazno) polja[x][y]=Polje::BlokiranoPrazno;
	else if(polja[x][y]==Polje::Posjeceno) polja[x][y]=Polje::BlokiranoPosjeceno;
	else if(polja[x][y]==Polje::Mina) polja[x][y]=Polje::BlokiranoMina;
}
void DeblokirajPolje(Tabla &polja,int x,int y)
{
	if(x<0 || x>=polja.size() || y<0 || y>=polja.size()) throw domain_error("Polje (x, y) ne postoji");
	if(polja[x][y]==Polje::BlokiranoPrazno) polja[x][y]=Polje::Prazno;
	else if(polja[x][y]==Polje::BlokiranoPosjeceno) polja[x][y]=Polje::Posjeceno;
	else if(polja[x][y]==Polje::BlokiranoMina) polja[x][y]=Polje::Mina;
}
Status Idi (Tabla &polja, int &x, int &y, Smjerovi smjer)
{
	int tmp1(x),tmp2(y);
	if(smjer==Smjerovi::GoreLijevo) {
		tmp1--;
		tmp2--;
	} else if(smjer==Smjerovi::Gore) tmp1--;
	else if(smjer==Smjerovi::GoreDesno) {
		tmp1--;
		tmp2++;
	} else if(smjer==Smjerovi::Desno) tmp2++;
	else if(smjer==Smjerovi::DoljeDesno) {
		tmp1++;
		tmp2++;
	} else if(smjer==Smjerovi::Dolje) tmp1++;
	else if(smjer==Smjerovi::DoljeLijevo) {
		tmp1++;
		tmp2--;
	} else if(smjer==Smjerovi::Lijevo) tmp2--;
	if(tmp1<0 || tmp1>=polja.size() || tmp2<0 || tmp2>=polja[0].size()) throw out_of_range("Izlazak van igrace table");
	if(polja[tmp1][tmp2]==Polje::BlokiranoPosjeceno || polja[tmp1][tmp2]==Polje::BlokiranoPrazno || polja[tmp1][tmp2]==Polje::BlokiranoMina)
		throw logic_error("Blokirano polje");
	polja[x][y]=Polje::Posjeceno;
	x=tmp1;
	y=tmp2;
	if(polja[x][y]==Polje::Mina) {
		for(int i=0; i<polja.size(); i++) {
			for(int j=0; j<polja[i].size(); j++) {
				polja[i][j]=Polje::Prazno;
			}
		}
		return Status::KrajPoraz;

	} else {
		bool provjera=false;
		for(int i=0; i<polja.size(); i++) {
			for(int j=0; j<polja[i].size(); j++) {
				if(polja[i][j]==Polje::Prazno) provjera=true;
			}
		}
		if(provjera) return Status::NijeKraj;
		else return Status::KrajPobjeda;
	}
}
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y)
{
	if(novi_x<0 || novi_x>=polja.size() || novi_y<0 || novi_y>=polja[0].size()) throw out_of_range("Izlazak van igrace table");
	if(polja[novi_x][novi_y]==Polje::BlokiranoPosjeceno || polja[novi_x][novi_y]==Polje::BlokiranoPrazno || polja[novi_x][novi_y]==Polje::BlokiranoMina)
		throw logic_error("Blokirano polje");
	polja[x][y]=Polje::Posjeceno;
	x=novi_x;
	y=novi_y;
	if(polja[x][y]==Polje::Mina) {
		for(int i=0; i<polja.size(); i++) {
			for(int j=0; j<polja[i].size(); j++) {
				polja[i][j]=Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	} else {
		bool provjera=false;
		for(int i=0; i<polja.size(); i++) {
			for(int j=0; j<polja[i].size(); j++) {
				if(polja[i][j]==Polje::Prazno) provjera=true;
			}
		}
		if(provjera) return Status::NijeKraj;
		else return Status::KrajPobjeda;
	}
}
void PrijaviGresku(KodoviGresaka greska)
{
	if(greska==KodoviGresaka::PogresnaKomanda) cout<<"Nerazumljiva komanda!";
	else if(greska==KodoviGresaka::NedostajeParametar) cout<<"Komanda trazi parametar koji nije naveden!";
	else if(greska==KodoviGresaka::NeispravanParametar) cout<<"Parametar komande nije ispravan!";
	else if(greska==KodoviGresaka::SuvisanParametar) cout<<"Zadan je suvisan parametar nakon komande!";
}
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska)
{
	cout<<"Unesite komandu: ";
	vector<string> v {"P1","P>","B","D","PO","Z","K"};
	string unos,tmp;
	getline(cin,unos);
	int i(0);
	while(unos[i]==' ') {
		i++;
		if(i==unos.size()) break;
	}
	if(i==unos.size()) {
		greska=KodoviGresaka::PogresnaKomanda;
		return false;
	}
	bool provjera(false);
	while (unos[i]!=' ') {
		tmp.push_back(unos[i]);
		for(int j=0; j<v.size(); j++) {
			if(tmp==v[j]) {
				provjera=true;
				break;
			}
		}
		i++;
		if(provjera) break;
		if(i==unos.size()) break;
	}
	if(provjera) {
		if(i!=unos.size() && unos[i]!=' ') {
			greska=KodoviGresaka::SuvisanParametar;
			return false;
		} else {
			if(tmp=="K" || tmp=="Z" || tmp=="PO") {
				while (i!=unos.size()) {
					if(unos[i]!=' ') {
						greska=KodoviGresaka::SuvisanParametar;
						return false;
					}
					i++;
				}
				if(tmp=="K") komanda=Komande::KreirajIgru;
				else if(tmp=="Z") komanda=Komande::ZavrsiIgru;
				else komanda=Komande::PrikaziOkolinu;
			} else if(tmp=="P>" || tmp=="B" || tmp=="D") {
				int brojac(i);
				while(i!=unos.size()) {
					if(unos[i]!=' ' &&(!(unos[i]>='0' && unos[i]<='9'))) {
						greska=KodoviGresaka::NeispravanParametar;
						return false;
					}
					i++;
				}
				i=brojac;
				vector<int> koordinate;
				int broj(0);
				while(i!=unos.size()) {
					bool logicka=false;
					while(unos[i]>='0' && unos[i]<='9') {
						broj=broj*10+(unos[i]-'0');
						logicka=true;
						i++;
					}
					if(logicka) koordinate.push_back(broj);
					if(unos[i]==' ') i++;
				}
				if(koordinate.size()<2) {
					greska=KodoviGresaka::NedostajeParametar;
					return false;
				} else if(koordinate.size()>2) {
					greska=KodoviGresaka::NeispravanParametar;
					return false;
				} else {
					x=koordinate[0];
					y=koordinate[1];
					if(tmp=="P>") komanda=Komande::PomjeriDalje;
					else if(tmp=="B") komanda=Komande::Blokiraj;
					else komanda=Komande::Deblokiraj;
				}
			} else if(tmp=="P1") {
				int brojac(i);
				while(i!=unos.size()) {
					if(unos[i]!=' ' && unos[i]!='G' && unos[i]!='D' && unos[i]!='L' && unos[i]!='o') {
						greska=KodoviGresaka::NeispravanParametar;
						return false;
					}
					i++;
				}
				i=brojac;
				vector<string> s {"G","GL","GD","D","DoD","Do","DoL","L"};
				string rijec;
				while (i!=unos.size()) {
					while(unos[i]=='G' || unos[i]=='L' || unos[i]=='D' || unos[i]=='o') {
						rijec.push_back(unos[i]);
						i++;
					}
					if(unos[i]==' ') i++;
				}
				bool ispravna=false;
				for(int j=0; j<s.size(); j++) {
					if(rijec==s[j]) {
						ispravna=true;
						break;
					}
				}
				if(ispravna==false) {
					greska=KodoviGresaka::NeispravanParametar;
					return false;
				} else {
					komanda=Komande::PomjeriJednoMjesto;
					if(rijec=="GL") smjer=Smjerovi::GoreLijevo;
					else if(rijec=="G") smjer=Smjerovi::Gore;
					else if(rijec=="GD") smjer=Smjerovi::GoreDesno;
					else if(rijec=="D") smjer=Smjerovi::Desno;
					else if(rijec=="DoD") smjer=Smjerovi::DoljeDesno;
					else if(rijec=="Do") smjer=Smjerovi::Dolje;
					else if(rijec=="L") smjer=Smjerovi::Lijevo;
					else smjer=Smjerovi::DoljeLijevo;
				}
			}
		}
	} else {
		greska=KodoviGresaka::PogresnaKomanda;
		return false;
	}
	return true;
}
void IzvrsiKomandu(Komande komanda,Tabla &polja,int &x,int &y, Smjerovi p_smjer=Smjerovi::Gore,int p_x=0,int p_y=0)
{
	try {
		if(komanda==Komande::PomjeriJednoMjesto) {
			Status status=Idi(polja,x,y,p_smjer);
			if(status==Status::NijeKraj) cout<<"Tekuca pozicija je ("<<x<<","<<y<<")"<<endl;
			else {
				if(status==Status::KrajPobjeda) cout<<"Bravo, obisli ste sva sigurna polja"<<endl;
				else cout<<"Nagazili ste na minu"<<endl;
				for(int i=0; i<polja.size(); i++) {
					for(int j=0; j<polja[i].size(); j++) {
						polja[i][j]=Polje::Prazno;
					}
				}
				throw runtime_error("Igra zavrsena");
			}
		} else if(komanda==Komande::PomjeriDalje) {
			Status status=Idi(polja,x,y,p_x,p_y);
			if(status==Status::NijeKraj) cout<<"Tekuca pozicija je ("<<x<<","<<y<<")"<<endl;
			else {
				if(status==Status::KrajPobjeda) cout<<"Bravo, obisli ste sva sigurna polja"<<endl;
				else cout<<"Nagazili ste na minu"<<endl;
				for(int i=0; i<polja.size(); i++) {
					for(int j=0; j<polja.size(); j++) {
						polja[i][j]=Polje::Prazno;
					}
				}
				throw runtime_error("Igra zavrsena");
			}
		} else if(komanda==Komande::PrikaziOkolinu) {
			vector<vector<int>> matrica=PrikaziOkolinu(polja,p_x,p_y);
			for(int i=0; i<matrica.size(); i++) {
				for(int j=0; j<matrica[i].size(); j++) {
					cout<<matrica[i][j]<<" ";
				}
				cout<<endl;
			}
		} else if(komanda==Komande::Blokiraj) BlokirajPolje(polja,p_x,p_y);
		else if(komanda==Komande::Deblokiraj) DeblokirajPolje(polja,p_x,p_y);
		else if(komanda==Komande::ZavrsiIgru) {
			for(int i=0; i<polja.size(); i++) {
				for(int j=0; j<polja.size(); j++) {
					polja[i][j]=Polje::Prazno;
				}
			}
			throw runtime_error("Igra zavrsena");
		} else {
			double n1;
			cout<<"Unesite broj polja: ";
			while(!(cin>>n1)) {
				cout<<"Greska, unesite ponovo!"<<endl;
				cout<<"Unesite broj polja: ";
				cin.clear();
				cin.ignore(10000,'\n');
			}
			int n=int(n1);
			cout<<"Unesite pozicije mina: ";
			vector<vector<int>> v;
		}
	} catch(...) {}
}
int main ()
{
	return 0;
}
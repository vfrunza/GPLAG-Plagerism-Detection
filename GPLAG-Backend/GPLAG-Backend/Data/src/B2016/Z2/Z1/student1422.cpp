#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <sstream>
#include <string>

enum class Polje { Prazno, Prosjecno=9, Mina=1, BlokiranoPrazno, BlokiranoProsjecno, BlokiranoMina};

enum class Smjerovi { GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo};

enum class Status { NijeKraj, KrajPoraz, KrajPobjeda};

enum class KodoviGresaka { PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar};

enum class Komande { PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru};

typedef std::vector<std::vector<Polje>> Tabla;

//pomocne f-je:

void IspisiRed(std::vector<Polje> p){
	for(int i=0;i<int(p.size());i++)
	std::cout<<int(p[i])<<" ";
}

void IspisiTablu(const Tabla tabla){
	std::for_each(tabla.begin(),tabla.end(), [](std::vector<Polje> p){IspisiRed(p); std::cout<<std::endl;});
}

bool DvaElementa(std::vector<std::vector<int>> v){
	bool ima(1);
	for(int i=0;i<int(v.size());i++){
		if(int(v[i].size())!=2){
			ima=0;
			break;
		}
	}
	return ima;
}

bool IzlaziIzOpsegaTable(std::vector<std::vector<int>> v, int opseg){
	bool izlazi(0);
	for(int i=0;i<int(v.size());i++){
		for(int j=0;j<int(v[i].size());j++)
			if(v[i][j]>(opseg-1) || v[i][j]<0){
				izlazi=1;
				break;
			}
			if(izlazi) break;
	}
	return izlazi;
}

bool IzlaziIzOpsega(int x, int y, int opseg){
	if(x>(opseg-1) || y>(opseg-1) || x<0 || y<0) return true;
	return false;
}

int BrojMinaUBlizini(int x, int y, const Tabla &polja){
	int br_mina(0);
	int PocetnaPozicijaX(0),PocetnaPozicijaY(0);
	if(x>0) PocetnaPozicijaX=x-1;
	else PocetnaPozicijaX=x;
	if(y>0) PocetnaPozicijaY=y-1;
	else PocetnaPozicijaY=y;
	int KrajnjaPozicijaX(0),KrajnjaPozicijaY(0);
	if(x==int(polja.size())-1) KrajnjaPozicijaX=x;
	else KrajnjaPozicijaX=x+1;
	if(y==int(polja.size())-1) KrajnjaPozicijaY=y;
	else KrajnjaPozicijaY=y+1;
	
	for(int i=PocetnaPozicijaX;i<KrajnjaPozicijaX;i++){
		for(int j=PocetnaPozicijaY;j<KrajnjaPozicijaY;j++){
			if((polja[i][j]==Polje::Mina) && ((i==x && j!=y) || (i!=x && j==y) || (i!=x && j!=y))) br_mina++;
		}
	}
	return br_mina;
}

void OcistiTablu(std::vector<std::vector<Polje>> &v){
	for(int i=0;i<int(v.size());i++)
	for(int j=0;j<int(v[i].size());j++)
	v[i][j]=Polje::Prazno;
}

Smjerovi Smjer(string s){
	if(s=="GL") return Smjerovi::GoreLijevo;
	else if(s=="G") return Smjerovi::Gore;
	else if(s=="GD") return Smjerovi::GoreDesno;
	else if(s=="D") return Smjerovi::Desno;
	else if(s=="DoD") return Smjerovi::DoljeDesno;
	else if(s=="Do") return Smjerovi::Dolje;
	else if(s=="DoL") return Smjerovi::DoljeLijevo;
	else if(s=="L") return Smjerovi::Lijevo;
}

int BrojPraznihPolja(tabla t){
	int br_polja(0);
	for(int i=0;i<int(t.size());i++)
		for(int j=0; j<int(t[0].size());j++)
		if(t[i][j]==Polje::Prazno) br_polja++;
	return br_polja;
}

bool LegalnaKomanda(string k){
	const string Komande[7]{"P1","P>","B","D","PO","Z","K"};
	for(int i=0;i<7;i++)
		if(k==Komande[i]) return true;
	return false;
}

bool LegalanSmjer(string s){
	const string smjerovi[8]{"GL","GD","G","D","DoD","Do","DoL","L"};
	for(int i=0;i<8;i++)
		if(s==smjerovi[i]) return true;
	return false;
}

bool DaLiJeBroj(string n){
	if(int(n.length())==1 && n[0]=='0') return true;
	if(n[0]=='0') return false;
	for(int i=0;i<int(n.length());i++)
		if(n[i]<'0' || n[i]>'9') return false;
	return true;
}

int PretvoriUBroj(string s){
	int n(0), m(1);
	for(int i=0;i<int(s.length());i++)
	m*=10;
	for(int i=0;i<int(s.length());i++){
		int br=s[i]-'0';
		br*=m;	n+=br;	m/=10;
	}
	return n;
}

//potrebne f-je:

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	if(!DvaElementa(mine)) throw std::domain_error("Ilegalan format zadavanja mina");
	if(!IzlaziIzOpsegaTable(mine,n)) throw std::domain_error("Ilegalne pozicije mina");
	Tabla t(n, std::vector<Polje>(n,Polje::Prazno));
	for(int i=0;i<int(mine.size());i++){
		int xMina(mine[i][0]);
		int yMina(mine[i][1]);
		t[xMina][yMina]=Polje::Mina;
	}
	return t;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x,int y){
	if(IzlaziIzOpsega(x,y,int(polja.size())))
}

int main (){
	try{
		Komande K;
		Smjerovi S;
		Greske G;
		IzvsiKomandu()
	}
	catch{
		
	}
	return 0;
}
#include <iostream>
#include <vector>
#include <stdexcept>

enum class Polje {Prazno,Mina,Posjeceno,BlokiranoPrazno,BlokiranoPosjeceno,BlokiranoMina};
enum class Smjerovi {
GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};
enum class Status {
NijeKraj, KrajPoraz, KrajPobjeda
};

enum class KodoviGresaka {
PogresnaKomanda, NedostajeParmetar, SuvisanParametar, NeispravanParametar
};

enum class Komande {
PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu,
ZavrsiIgru, KreirajIgru
};

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	if(mine[0].size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
	int max(0);
	for(int i(0);i<mine.size();i++){
		for(int j(0);j<mine[0].size();j++){
			if(mine[i][j]>max) max=mine[i][j];
		}
	}
	if(max>(n-1)) throw std::domain_error("Ilegalne pozicije mina");
	std::vector<std::vector<Polje>>mat(n,std::vector<Polje>(n,Polje::Prazno));
	for(int i(0);i<mine.size();i++){
		for(int j(0);j<mine[0].size();j++){
   	mat[mine[i][0]][mine[i][mine[0].size()-1]]=Polje::Mina;
   		}
	}
   	return mat;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	for(int i=0;i<polja.size();i++){
		if(x>=polja.size() or x<0 or y>=polja[i].size() or y<0) throw std::domain_error ("Polje ne postoji");
	}
	std::vector<std::vector<int>>Okolina(3,std::vector<int>(3,0));
	for(int poc(x-1),i(0);poc<x+2,i<3;poc++,i++){
		for(int kol(y-1),j(0);kol<y+2,j<3;kol++,j++){
			if( kol-1<=0  or poc-1<=0  ) Okolina[i][j]+=0;
			if( kol-1>=0 && polja[poc][kol-1]==Polje::Mina) Okolina[i][j]+=1;
			if(kol-1>=0 && poc-1>=0 and polja[poc-1][kol-1]==Polje::Mina) Okolina[i][j]+=1;
			if(kol>=0 && poc-1>=0 and polja[poc-1][kol]==Polje::Mina) Okolina[i][j]+=1;// samo za 2. red radi ooj boze
			if( poc-1>=0 and polja[poc-1][kol+1]==Polje::Mina) Okolina[i][j]+=1;
			if( polja[poc][kol+1]==Polje::Mina) Okolina[i][j]+=1;
			if( polja[poc+1][kol+1]==Polje::Mina) Okolina[i][j]+=1;
			if( polja[poc+1][kol]==Polje::Mina) Okolina[i][j]+=1;
			if(kol-1>=0  and polja[poc+1][kol-1]==Polje::Mina) Okolina[i][j]+=1;
		}
	}
	return Okolina;
}

void BlokirajPolje(Tabla &polja, int x, int y){
	for(int i=0;i<polja.size();i++){
		if(x>=polja.size() or x<0 or y>=polja[i].size() or y<0) throw std::domain_error ("Polje ne postoji");//+za duplo blokanje??
	}
		
	for(int i(0);i<polja.size();i++){
		for(int j(0);j<polja[i].size();j++){
			if(polja[x][y]==Polje::Prazno) polja[x][y]=Polje::BlokiranoPrazno;
			if(polja[x][y]==Polje::Mina) polja[x][y]=Polje::BlokiranoMina;
			if(polja[x][y]==Polje::Posjeceno) polja[x][y]=Polje::BlokiranoPosjeceno;
		}
	}
}

void DeblokirajPolje(Tabla &polja, int x, int y){
	for(int i(0);i<polja.size();i++){
		for(int j(0);j<polja[i].size();j++){
			if(polja[x][y]==Polje::BlokiranoPrazno) polja[x][y]=Polje::Prazno;
			if(polja[x][y]==Polje::BlokiranoMina) polja[x][y]=Polje::Mina;
			if(polja[x][y]==Polje::BlokiranoPosjeceno) polja[x][y]=Polje::Posjeceno;
		}
	}
	
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	
		if(smjer==Smjerovi::GoreLijevo) polja[x-1][y-1]=Smjerovi::GoreLijevo; polja[x][y]=Polje::Posjeceno;
		if(smjer==Smjerovi::Gore) polja[x-1][y]=Smjerovi::Gore; polja[x][y]=Polje::Posjeceno;
		if(smjer==Smjerovi::GoreDesno) polja[x-1][y+1]=Smjerovi::GoreDesno; polja[x][y]=Polje::Posjeceno;
		if(smjer==Smjerovi::Desno)  polja[x][y+1]=Smjerovi::Desno;  polja[x][y]=Polje::Posjeceno;
		if(smjer==Smjerovi::DoljeDesno) polja[x+1][y+1]=Smjerovi::DoljeDesno;  polja[x][y]=Polje::Posjeceno;
		if(smjer==Smjerovi::Dolje )  polja[x+1][y]=Smjerovi::Dolje; polja[x][y]=Polje::Posjeceno;
		if(smjer==Smjerovi::DoljeLijevo) polja[x+1][y-1]=Smjerovi::DoljeLijevo; polja[x][y]=Polje::Posjeceno;
		if(smjer==Smjerovi::Lijevo)  polja[x][y-1]=Smjerovi::Lijevo; polja[x][y]=Polje::Posjeceno;
		
}
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	if(novi_x>=polja.size() or novi_x<0 or novi_y>=polja[i].size() or novi_y<0) throw std::out_of_range ("Izlazak van igrace table");
	for(int i(0);i<polja.size();i++){
		for(int j(0);j<polja[i].size();j++){
			if(polja[novi_x][novi_y]==Polje::BlokiranoPosjeceno || polja[novi_x][novi_y]==Polje::BlokiranoPrazno || polja[novi_x][novi_y]==Polje::BlokiranoMina ){
				throw std::logic_error("Blokirano polje");
			}
		if(polja[novi_x][novi_y]==Polje::Mina){
			return KrajPoraz;
			for(int i(0);i<polja.size();i++){
				for(int j(0);j<polja[i].size();j++){
						polja[i][j]==Polje::Prazno;
				}
			}
		}
		if(polja[novi_x][novi_y]!=Polje::Mina && polja[novi_x][novi_y]!=Polje::Prazno && polja[novi_x][novi_y]!=Polje::Posjeceno) {
			return KrajPobjeda;
		}
		else return NijeKraj;
		}
	}
}

void PrijaviGresku (KodoviGresaka StatusPar){
	switch(StatusPar){
		case 0: std::cout<<"Nerazumljiva komanda!"; break;
		case 1: std::cout<<"Komanda trazi parametar koji nije naveden!"; break;
		case 2: std::cout<<"Parametar komande nije ispravan!"; break;
		case 3: std::cout<<"Zadan je suvisan parametar nakon komande!"; break;
	}
} 

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y,KodoviGresaka &greska){
		std::string Komandee[8]={"GL","G","GD","D","DoD","Do","DoL","L"};
		char komandica[100];
		char parametar[100];
		std::cin>>komandica>>std::ws;
		std::cin>>parametar;
		for(int i(0);i<Komandee.size();i++){
			if(komandica=="P1" && parametar==Komandee[i]) komanda=Komande::PomjeriJednoMjesto;
		}
		if((komandica=="P>"  && sizeof parametar==2 )		parametar[0]=x; 	parametar[1]=y; komanda=Komande::PomjeriDalje; return true;
		if( komandica=="D"  && sizeof parametar==2 )	parametar[0]=x; 	parametar[1]=y; komanda=Komande::Deblokiraj; return true;
		if(komandica=="B" && sizeof parametar==2)   	parametar[0]=x; 	parametar[1]=y; komanda=Komande::Blokiraj; return true;
		if(komandica=="K" && sizeof parametar==0)  komanda=Komande::ZavrsiIgru; return true;
		if(komandica=="PO" && sizeof parametar==0) komanda=Komande::KreirajIgru; return true;
return false;
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y,Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0){
	if(komanda==Komande::PomjeriJednoMjesto)
}





int main ()
{
	int n;
	std::cin>>n;
	Tabla matrica (n,std::vector<Polje>(n,Polje::Prazno));
	
	try{
	matrica = KreirajIgru(n,{{0,0,}, {0,2}, {1,3}});
	}
	catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what();
	}
	try{
		
		 std::vector<std::vector<int>>  matrica2 (3,std::vector<int>(3));
		matrica2=PrikaziOkolinu(matrica,1,3);
	}
	catch(std::domain_error e){
		std::cout<<e.what();
	}
	BlokirajPolje(matrica,0,1);
	DeblokirajPolje(matrica,0,1);
		for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			std::cout<<static_cast<int>(matrica[i][j]);
		}
		std::cout<<"\n";
	}
	
	return 0;
}
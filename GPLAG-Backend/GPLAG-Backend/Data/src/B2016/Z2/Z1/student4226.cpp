/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

enum class Polje { Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina };

enum class Smjerovi { GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo };

enum class Status { NijeKraj, KrajPoraz, KrajPobjeda };

enum class KodoviGresaka { PogresnaKomanda, NedostajeParmetar, SuvisanParametar, NeispravanParametar };

enum class Komande { PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru };

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	for(int i(0); i<mine.size(); i++)
		if(mine[i].size() != 2) throw std::domain_error("Ilegalan format zadavanja mina");
	Tabla t;
	t.resize(n);
	for(int i(0); i<n; i++) t[i].resize(n);
	for(int i(0); i<n; i++)
		for(int j(0); j<n; j++)
			t[i][j] = Polje::Prazno;
	for(int i(0); i<int(mine.size()); i++){
		if((mine[i][0]>=n && mine[i][0]<=0) || (mine[i][1]>=n && mine[i][1]<=0)) throw std::domain_error("Ilegalne pozicije mina");
		t[mine[i][0]][mine[i][1]]=Polje::Mina;
	}
	return t;
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	std::string komanda1;
	std::cin >> komanda1;
	if(komanda1[0]=='P' && (komanda1[1]=='1' || komanda1[1]=='>' || komanda1[1]=='O') && komanda1.length()>2){
		greska = KodoviGresaka::SuvisanParametar;
		return false;
	}
	if(komanda1=="P"){
		greska = KodoviGresaka::PogresnaKomanda;
		return false;
	}
	if(komanda1=="P1"){
		std::string temp;
		std::cin >> temp;
		if(temp=="GL"){smjer = Smjerovi::GoreLijevo; komanda = Komande::PomjeriJednoMjesto; return true;}
		else if(temp=="G") {smjer = Smjerovi::Gore; komanda = Komande::PomjeriJednoMjesto; return true;}
		else if(temp=="GD") {smjer = Smjerovi::GoreDesno; komanda = Komande::PomjeriJednoMjesto; return true;}
		else if(temp=="D") {smjer = Smjerovi::Desno; komanda = Komande::PomjeriJednoMjesto; return true;}
		else if(temp=="DoD") {smjer = Smjerovi::DoljeDesno; komanda = Komande::PomjeriJednoMjesto; return true;}
		else if(temp=="Do") {smjer = Smjerovi::Dolje; komanda = Komande::PomjeriJednoMjesto; return true;}
		else if(temp=="DoL") {smjer = Smjerovi::DoljeLijevo; komanda = Komande::PomjeriJednoMjesto; return true;}
		else if(temp=="L") {smjer = Smjerovi::Lijevo; komanda = Komande::PomjeriJednoMjesto; return true;}
		else{
			greska = KodoviGresaka::NeispravanParametar;
			return false;
		}
	}
	if(komanda1=="P>"){
		std::cin >> x >> y;
		if(!std::cin){ 
			greska = KodoviGresaka::NeispravanParametar;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			return false;
		}
		else{
			komanda = Komande::PomjeriDalje;
			return true;
		}
	}
	if(komanda1=="PO"){
		komanda = Komande::PrikaziOkolinu;
		return true;
	}
	if((komanda1[0]=='B' || komanda1[0]=='D' || komanda1[0]=='Z' || komanda1[0]=='K') && int(komanda1.size())>1){
		greska = KodoviGresaka::SuvisanParametar;
		return false;
	}
	if(komanda1=="B"){
		std::cin >> x >> y;
		if(!std::cin){ 
			greska = KodoviGresaka::NeispravanParametar;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			return false;
		}
		else{
			komanda = Komande::Blokiraj;
			return true;
		}
	}
	if(komanda1=="D"){
		std::cin >> x >> y;
		if(!std::cin){ 
			greska = KodoviGresaka::NeispravanParametar;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			return false;
		}
		else{
			komanda = Komande::Deblokiraj;
			return true;
		}
	}
	if(komanda1=="Z"){
		komanda = Komande::ZavrsiIgru;
		return true;
	}
	if(komanda1=="K"){
		komanda=Komande::KreirajIgru;
		return true;
	}
	
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	std::vector<std::vector<int>> okolina;
	int brojac(0);
	//if(x>=1 && y>=1 && x+1<=polja.size() && y+1<=polja[0].size()){
		for(int i(x-1); i<x+2; i++)
			for(int j(y-1); j<y+2; j++){
				 if(i==0 && j==0){
				 	if(polja[i+1][j] == Polje::Mina) brojac++;
				 	if(polja[i+1][j+1] == Polje::Mina) brojac++;
				 	if(polja[i][j+1] == Polje::Mina) brojac++;
				 	okolina[i].push_back(brojac);
				 	brojac=0;
				 }
				 else if(i==0 && (j>0 && j<polja.size())){
				 	if(polja[i+1][j] == Polje::Mina) brojac++;
				 	if(polja[i+1][j+1] == Polje::Mina) brojac++;
				 	if(polja[i][j+1] == Polje::Mina) brojac++;
				 	if(polja[i+1][j-1] == Polje::Mina) brojac++;
				 	if(polja[i][j-1] == Polje::Mina) brojac++;
				 	okolina[i].push_back(brojac);
				 	brojac=0;
				 }
				 else if(i>0 && i<polja.size() && j==0){
				 	if(polja[i-1][j] == Polje::Mina) brojac++;
				 	if(polja[i-1][j+1] == Polje::Mina) brojac++;
				 	if(polja[i][j+1] == Polje::Mina) brojac++;
				 	if(polja[i+1][j+1] == Polje::Mina) brojac++;
				 	if(polja[i+1][j] == Polje::Mina) brojac++;
				 	okolina[i].push_back(brojac);
				 	brojac=0;
				 }
				 else if(i==polja.size()-1 && (j>0 && j<polja.size())){
				 	if(polja[i-1][j] == Polje::Mina) brojac++;
				 	if(polja[i-1][j+1] == Polje::Mina) brojac++;
				 	if(polja[i][j+1] == Polje::Mina) brojac++;
				 	if(polja[i-1][j-1] == Polje::Mina) brojac++;
				 	if(polja[i][j-1] == Polje::Mina) brojac++;
				 	okolina[i].push_back(brojac);
				 	brojac=0;
				 }
				 else if(i>0 && i<polja.size() && j==polja.size()-1){
				 	if(polja[i-1][j] == Polje::Mina) brojac++;
				 	if(polja[i-1][j-1] == Polje::Mina) brojac++;
				 	if(polja[i][j-1] == Polje::Mina) brojac++;
				 	if(polja[i+1][j-1] == Polje::Mina) brojac++;
				 	if(polja[i+1][j] == Polje::Mina) brojac++;
				 	okolina[i].push_back(brojac);
				 	brojac=0;
				 }
				 else{
				 	if(polja[i-1][j-1] == Polje::Mina) brojac++;
				 	if(polja[i+1][j+1] == Polje::Mina) brojac++;
				 	if(polja[i][j-1] == Polje::Mina) brojac++;
				 	if(polja[i][j+1] == Polje::Mina) brojac++;
				 	if(polja[i+1][j] == Polje::Mina) brojac++;
				 	if(polja[i-1][j] == Polje::Mina) brojac++;
				 	if(polja[i-1][j+1] == Polje::Mina) brojac++;
				 	if(polja[i+1][j-1] == Polje::Mina) brojac++;
				 	okolina[i].push_back(brojac);
				 	brojac=0;
				 }
				 
			}
	
}

/*void BlokirajPolje(Tabla &polja, int x, int y);
void DeblokirajPolje(Tabla &polja, int x, int y);
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer);
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y);
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y);
*//*
void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0){
	switch (komanda){
		case 
	}
}*/


int main (){/*
	int x(0), y(0);
	Komande kom = Komande::KreirajIgru;
	Smjerovi smjer = Smjerovi::Gore;
	KodoviGresaka belaj = KodoviGresaka::PogresnaKomanda;
	Tabla t;
	for(;;){
		if(UnosKomande(kom, smjer, x, y, belaj)) IzvrsiKomandu(kom, t, x, y);
	}
	std::cout << sqrt(3)*3.14;*/
	return 0;

}
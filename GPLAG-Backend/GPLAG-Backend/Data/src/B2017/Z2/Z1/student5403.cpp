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
#include <complex>
#include <string>
#include <algorithm>

enum class Polje {Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina};
enum class Smjerovi {GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo};
enum class Status {NijeKraj, KrajPoraz, KrajPobjeda};
enum class KodoviGresaka {PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar};
enum class Komande {PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru};



typedef std::vector<std::vector<Polje>> Tabla;
typedef std::vector<std::vector<int>> Matrica;

//POMOĆNE
Tabla KreirajTablu (int brojredova, int brojkolona){
	return (Tabla (brojredova, std::vector<Polje>(brojkolona)));
}
Matrica KreirajMatricu (int brojredova, int brojkolona){
	return (Matrica (brojredova, std::vector<int>(brojkolona)));
}

//GLAVNE
Tabla KreirajIgru(int n,const Matrica &mine){
	Tabla t;
	if (n<0) throw std::domain_error ("Ilegalna velicina");
	
	for (int i(0);i<mine.size();i++) {if (mine.at(i).size()!=2) throw std::domain_error ("Ilegalan format zadavanja mina");} 
	
	for (int i(0);i<mine.size();i++){
		for (int j(0);j<2;j++){
			if (n<mine.at(i).at(j)) throw std::domain_error ("Ilegalne pozicije mina");
		}
	}
	t=KreirajTablu(n,n);
	
	int s,k;
	for (int l(0);l<mine.size();l++){
		s=mine.at(l).at(0);
		k=mine.at(l).at(1);
		t.at(s).at(k)=Polje::Mina;
	}
	return t;
}
void PrijaviGresku (KodoviGresaka greska){
	if (greska==KodoviGresaka::PogresnaKomanda) std::cout << "Nerazumljiva komanda!" << std::endl;
	else if (greska==KodoviGresaka::NedostajeParametar) std::cout << "Komanda trazi parametar koji nije naveden!" << std::endl;
	else if (greska==KodoviGresaka::NeispravanParametar) std::cout << "Parametar komande nije ispravan!" << std::endl;
	else if (greska==KodoviGresaka::SuvisanParametar) std::cout << "Zadan je suvisan parametar nakon komande!" << std::endl;
}
Matrica PrikaziOkolinu(const Tabla &polja, int x, int y){ //Da li se smije poslati x=0 y=0 ?! 
	Matrica m(KreirajMatricu(3,3));
	int br(0),k;
	if (polja.size()<=x || polja.size()<=y || x<0 || y<0) throw std::domain_error ("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");				
	if (x>0 && y>0 && x<polja.size() && y<polja.size()){
		k=0;
		br=0; //Gore lijevo
		for (int i(x-2);i<x-1+2;i++){
			for (int j(y-2);j<y-1+2;j++){
				if (x-1==0 && y-1==0){
					k=1;
					if(polja.at(x).at(y)==Polje::Mina)br++;
					if(polja.at(x).at(y-1)==Polje::Mina)br++;
					if(polja.at(x-1).at(y)==Polje::Mina)br++;
					m.at(0).at(0)=br;
					br=0;
					break;
				}
				else if (x-1==0 && y-1!=0){
					k=1;
					if (polja.at(x).at(y)==Polje::Mina) br++;
					if (polja.at(x-1).at(y-2)==Polje::Mina) br++;
					if (polja.at(x).at(y-2)==Polje::Mina) br++;
					if (polja.at(x).at(y-1)==Polje::Mina) br++;
					if (polja.at(x-1).at(y)==Polje::Mina) br++;
					m.at(0).at(0)=br;
					br=0;
					break;
				}
				else if (x-1!=0 && y-1==0){
					k=1;
					if (polja.at(x).at(y)==Polje::Mina) br++;
					if (polja.at(x-1).at(y)==Polje::Mina) br++;
					if (polja.at(x).at(y-1)==Polje::Mina) br++;
					if (polja.at(x-2).at(y-1)==Polje::Mina) br++;
					if (polja.at(x-2).at(y)==Polje::Mina) br++;
					m.at(0).at(0)=br;
				}
				else {
					if (polja.at(i).at(j)==Polje::Mina) br++;
					if (polja.at(i).at(j)==Polje::Mina && i==x-1 && j==y-1) br=br-1;
					m.at(0).at(0)=br;
				}
			}
			if(k==1) break;
		}
		
		k=0;
		br=0;	//Gore
		for (int i(x-2);i<x-1+2;i++){
			for (int j(y-1);j<y+2;j++){
				if (x-1==0){
					k=1;
					if (polja.at(x).at(y)==Polje::Mina) br++;
					if (polja.at(x-1).at(y-1)==Polje::Mina) br++;
					if (polja.at(x).at(y-1)==Polje::Mina) br++;
					if (polja.at(x).at(y+1)==Polje::Mina) br++;
					if (polja.at(x-1).at(y+1)==Polje::Mina) br++;
					m.at(0).at(1)=br;
					br=0;
					break;
				}
				else {
					if (polja.at(i).at(j)==Polje::Mina) br++;
					if (polja.at(i).at(j)==Polje::Mina && i==x-1 && j==y) br=br-1;
					m.at(0).at(1)=br;
				}
			}
			if(k==1) break;
		}
		
		k=0;
		br=0;		//Gore desno
		for (int i(x-2);i<x-1+2;i++){
			for (int j(y);j<y+1+2;j++){
				if (x-1==0 && y+1==polja.size()){
					k=1;
					if(polja.at(x).at(y)==Polje::Mina)br++;
					if(polja.at(x).at(y+1)==Polje::Mina)br++;
					if(polja.at(x-1).at(y)==Polje::Mina)br++;
					m.at(0).at(2)=br;
					br=0;
					break;
				}
				else if (x-1==0){
					k=1;
					if (polja.at(x).at(y)==Polje::Mina) br++;
					if (polja.at(x-1).at(y)==Polje::Mina) br++;
					if (polja.at(x).at(y+1)==Polje::Mina) br++;
					if (polja.at(x).at(y+2)==Polje::Mina) br++;
					if (polja.at(x-1).at(y+2)==Polje::Mina) br++;
					m.at(0).at(2)=br;
					br=0;
					break;
				}
				else if (y-1==polja.size()){
					k=1;
					if (polja.at(x).at(y)==Polje::Mina) br++;
					if (polja.at(x-1).at(y)==Polje::Mina) br++;
					if (polja.at(x).at(y+1)==Polje::Mina) br++;
					if (polja.at(x-2).at(y+1)==Polje::Mina) br++;
					if (polja.at(x-2).at(y)==Polje::Mina) br++;
					m.at(0).at(2)=br;
				}
				else {
					if (polja.at(i).at(j)==Polje::Mina) br++;
					if (polja.at(i).at(j)==Polje::Mina && i==x-1 && j==y+1) br=br-1;
					m.at(0).at(2)=br;
				}
			}
			if(k==1) break;
		}
		
		k=0;
		br=0;	//Lijevo
		for (int i(x-1);i<x+2;i++){
			for (int j(y-2);j<y-1+2;j++){
				if (y-1==0){
					k=1;
					if (polja.at(x).at(y)==Polje::Mina) br++;
					if (polja.at(x-1).at(y-1)==Polje::Mina) br++;
					if (polja.at(x-1).at(y)==Polje::Mina) br++;
					if (polja.at(x+1).at(y-1)==Polje::Mina) br++;
					if (polja.at(x+1).at(y)==Polje::Mina) br++;
					m.at(1).at(0)=br;
					br=0;
					break;
				}
				else  {
					if (polja.at(i).at(j)==Polje::Mina) br++;
					if (polja.at(i).at(j)==Polje::Mina && i==x && j==y-1) br=br-1;
					m.at(1).at(0)=br;
				}
			}
			if(k==1) break;
		}
		
		k=0;
		br=0;	//Sredina		
		for (int i(x-1);i<x+2;i++){
			for (int j(y-1);j<y+2;j++){
				if (polja.at(i).at(j)==Polje::Mina) br++;
				if (polja.at(i).at(j)==Polje::Mina && i==x && j==y ) br=br-1;
				m.at(1).at(1)=br;
			}
		}
		
		k=0;
		br=0;	//Desno
		for (int i(x-1);i<x+2;i++){
			for (int j(y);j<y+1+2;j++){
				if (y-1==polja.size()){
					k=1;
					if (polja.at(x).at(y)==Polje::Mina) br++;
					if (polja.at(x-1).at(y)==Polje::Mina) br++;
					if (polja.at(x-1).at(y+1)==Polje::Mina) br++;
					if (polja.at(x+1).at(y+1)==Polje::Mina) br++;
					if (polja.at(x+1).at(y)==Polje::Mina) br++;
					m.at(1).at(2)=br;
					br=0;
					break;
				}
				else {
					if (polja.at(i).at(j)==Polje::Mina) br++;
					if (polja.at(i).at(j)==Polje::Mina && i==x && j==y+1) br=br-1;
					m.at(1).at(2)=br;
				}
			}
			if(k==1) break;
		}
		
		k=0;
		br=0; 	//Dolje lijevo
		for (int i(x);i<x+1+2;i++){
			for (int j(y-2);j<y-1+2;j++){
				if (x+1==polja.size() && y-1==0){
					k=1;
					if(polja.at(x).at(y)==Polje::Mina)br++;
					if(polja.at(x).at(y-1)==Polje::Mina)br++;
					if(polja.at(x+1).at(y)==Polje::Mina)br++;
					m.at(2).at(0)=br;
					br=0;
					break;
				}
				else if (x-1==polja.size()){
					k=1;
					if (polja.at(x).at(y)==Polje::Mina) br++;
					if (polja.at(x+1).at(y-2)==Polje::Mina) br++;
					if (polja.at(x).at(y-2)==Polje::Mina) br++;
					if (polja.at(x).at(y-1)==Polje::Mina) br++;
					if (polja.at(x+1).at(y)==Polje::Mina) br++;
					m.at(2).at(0)=br;
					br=0;
					break;
				}
				else if (y-1==0){
					k=1;
					if (polja.at(x).at(y)==Polje::Mina) br++;
					if (polja.at(x+1).at(y)==Polje::Mina) br++;
					if (polja.at(x).at(y-1)==Polje::Mina) br++;
					if (polja.at(x+2).at(y-1)==Polje::Mina) br++;
					if (polja.at(x+2).at(y)==Polje::Mina) br++;
					m.at(2).at(0)=br;
					br=0;
					break;
				}
				else {
					if (polja.at(i).at(j)==Polje::Mina) br++;
					if (polja.at(i).at(j)==Polje::Mina && i==x+1 && j==y-1) br=br-1;
					m.at(2).at(0)=br;
				}
			}
			if(k==1) break;
		}
		
		k=0;
		br=0;	//Dolje
		for (int i(x);i<x+1+2;i++){
			for (int j(y-1);j<y+2;j++){
				if (x+1==polja.size()){
					k=1;
					if (polja.at(x).at(y)==Polje::Mina) br++;
					if (polja.at(x+1).at(y-1)==Polje::Mina) br++;
					if (polja.at(x).at(y-1)==Polje::Mina) br++;
					if (polja.at(x).at(y+1)==Polje::Mina) br++;
					if (polja.at(x+1).at(y+1)==Polje::Mina) br++;
					m.at(2).at(1)=br;
					br=0;
					break;
				}
				else {
					if (polja.at(i).at(j)==Polje::Mina) br++;
					if (polja.at(i).at(j)==Polje::Mina && i==x+1 && j==y) br=br-1;
					m.at(2).at(1)=br;
				}
			}
			if(k==1) break;
		}
		
		k=0;
		br=0;		//Dolje desno
		for (int i(x);i<(x+1+2);i++){
			for (int j(y);j<y+1+2;j++){
				if (x+1==polja.size() && y+1==polja.size()){
					k=1;
					if(polja.at(x).at(y)==Polje::Mina)br++;
					if(polja.at(x).at(y+1)==Polje::Mina)br++;
					if(polja.at(x+1).at(y)==Polje::Mina)br++;
					m.at(2).at(2)=br;
					br=0;
					break;
				}
				else if (x+1==polja.size()){
					k=1;
					if (polja.at(x).at(y)==Polje::Mina) br++;
					if (polja.at(x+1).at(y)==Polje::Mina) br++;
					if (polja.at(x).at(y+1)==Polje::Mina) br++;
					if (polja.at(x).at(y+2)==Polje::Mina) br++;
					if (polja.at(x+1).at(y+2)==Polje::Mina) br++;
					m.at(2).at(2)=br;
					br=0;
					break;
				}
				else if (y-1==polja.size()){
					k=1;
					if (polja.at(x).at(y)==Polje::Mina) br++;
					if (polja.at(x+1).at(y)==Polje::Mina) br++;
					if (polja.at(x).at(y+1)==Polje::Mina) br++;
					if (polja.at(x+2).at(y+1)==Polje::Mina) br++;
					if (polja.at(x+2).at(y)==Polje::Mina) br++;
					m.at(2).at(2)=br;
					br=0;
					break;
				}
				else {
					if (polja.at(i).at(j)==Polje::Mina) br++;
					if (polja.at(i).at(j)==Polje::Mina && i==x+1 && j==y+1) br=br-1;
					m.at(2).at(2)=br;
				}
			}
			if(k==1) break;
		}
		
	}
	
	/*else if(x==0 && y==0){
		
	}*/
	
	return m;
}
void BlokirajPolje (Tabla &polja, int x,int y){
	if (polja.size()<=x || polja.size()<=y ||x<0 || y<0) throw std::domain_error ("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	if (polja.at(x).at(y)==Polje::Prazno) polja.at(x).at(y)=Polje::BlokiranoPrazno; 	
	else if (polja.at(x).at(y)==Polje::Posjeceno) polja.at(x).at(y)=Polje::BlokiranoPosjeceno;	
	else if (polja.at(x).at(y)==Polje::Mina) polja.at(x).at(y)=Polje::BlokiranoMina;
}
void DeblokirajPolje (Tabla &polja, int x,int y){ 
	if (polja.size()<=x || polja.size()<=y || x<0 || y<0) throw std::domain_error ("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	if (polja.at(x).at(y)==Polje::BlokiranoPrazno) polja.at(x).at(y)=Polje::Prazno; 	
	else if (polja.at(x).at(y)==Polje::BlokiranoPosjeceno) polja.at(x).at(y)=Polje::Posjeceno;	
	else if (polja.at(x).at(y)==Polje::BlokiranoMina) polja.at(x).at(y)=Polje::Mina;
	
}
Status Idi (Tabla &polja, int &x, int &y, Smjerovi smjer){
	polja.at(x).at(y)=Polje::Posjeceno;
	if (smjer==Smjerovi::GoreLijevo) {
		if (polja.size()<(x-1) || polja.size()<(y-1)) throw std::out_of_range ("Izlazak van igrace table");
		if (polja.at(x-1).at(y-1)==Polje::BlokiranoPosjeceno || polja.at(x-1).at(y-1)==Polje::BlokiranoPrazno || polja.at(x-1).at(y-1)==Polje::BlokiranoMina) throw std::logic_error ("Blokirano polje");
		if (polja.at(x-1).at(y-1)==Polje::Mina){
			for (int i(0);i<polja.size();i++){
				for(int j(0);j<polja.at(i).size();j++){
					polja.at(i).at(j)=Polje::Prazno;
				}
			}
			return Status::KrajPoraz;
		}
		else if (polja.at(x-1).at(y-1)==Polje::Prazno){
			for (int i(0);i<polja.size();i++){
				for (int j(0);j<polja.at(i).size();i++){
					if (polja.at(i).at(j)==Polje::Prazno) {
						x=x-1;
						y=y-1;
						return Status::NijeKraj;
					}
				}
			}
		return Status::KrajPobjeda;	
		}
	}
	else if (smjer==Smjerovi::Gore) {
		if (polja.size()<(x-1) || polja.size()<(y)) throw std::out_of_range ("Izlazak van igrace table");
		if (polja.at(x-1).at(y)==Polje::BlokiranoPosjeceno || polja.at(x-1).at(y)==Polje::BlokiranoPrazno || polja.at(x-1).at(y)==Polje::BlokiranoMina) throw std::logic_error ("Blokirano polje");
		if (polja.at(x-1).at(y)==Polje::Mina) {
			for (int i(0);i<polja.size();i++){
				for(int j(0);j<polja.at(i).size();j++){
					polja.at(i).at(j)=Polje::Prazno;
				}
			}
			return Status::KrajPoraz;
		}
		else if (polja.at(x-1).at(y)==Polje::Prazno){
			for (int i(0);i<polja.size();i++){
				for (int j(0);j<polja.at(i).size();i++){
					if (polja.at(i).at(j)==Polje::Prazno) {
						x=x-1;
						return Status::NijeKraj;
					}
				}
			}
		return Status::KrajPobjeda;	
		}
	}
	else if (smjer==Smjerovi::GoreDesno) {
		if (polja.size()<(x-1) || polja.size()<(y+1)) throw std::out_of_range ("Izlazak van igrace table");
		if (polja.at(x-1).at(y+1)==Polje::BlokiranoPosjeceno || polja.at(x-1).at(y+1)==Polje::BlokiranoPrazno || polja.at(x-1).at(y+1)==Polje::BlokiranoMina) throw std::logic_error ("Blokirano polje");
		if (polja.at(x-1).at(y+1)==Polje::Mina) {
			for (int i(0);i<polja.size();i++){
				for(int j(0);j<polja.at(i).size();j++){
					polja.at(i).at(j)=Polje::Prazno;
				}
			}
			return Status::KrajPoraz;
		}
		else if (polja.at(x-1).at(y+1)==Polje::Prazno){
			for (int i(0);i<polja.size();i++){
				for (int j(0);j<polja.at(i).size();i++){
					if (polja.at(i).at(j)==Polje::Prazno) {
						x=x-1;
						y=y+1;
						return Status::NijeKraj;
					}
				}
			}
		return Status::KrajPobjeda;	
		}
	}
	else if (smjer==Smjerovi::Lijevo) {
		if (polja.size()<(x) || polja.size()<(y-1)) throw std::out_of_range ("Izlazak van igrace table");
		if (polja.at(x).at(y-1)==Polje::BlokiranoPosjeceno || polja.at(x).at(y-1)==Polje::BlokiranoPrazno || polja.at(x).at(y-1)==Polje::BlokiranoMina) throw  std::logic_error ("Blokirano polje");
		if (polja.at(x).at(y-1)==Polje::Mina) {
			for (int i(0);i<polja.size();i++){
				for(int j(0);j<polja.at(i).size();j++){
					polja.at(i).at(j)=Polje::Prazno;
				}
			}
			return Status::KrajPoraz;
		}
		else if (polja.at(x).at(y-1)==Polje::Prazno){
			for (int i(0);i<polja.size();i++){
				for (int j(0);j<polja.at(i).size();i++){
					if (polja.at(i).at(j)==Polje::Prazno) {
						y=y-1;
						return Status::NijeKraj;
					}
				}
			}
		return Status::KrajPobjeda;	
		}
	}
	else if (smjer==Smjerovi::Desno) {
		if (polja.size()<(x) || polja.size()<(y+1)) throw std::out_of_range ("Izlazak van igrace table");
		if (polja.at(x).at(y+1)==Polje::BlokiranoPosjeceno || polja.at(x).at(y+1)==Polje::BlokiranoPrazno || polja.at(x).at(y+1)==Polje::BlokiranoMina) throw std::logic_error ("Blokirano polje");
		if (polja.at(x).at(y+1)==Polje::Mina) {
			for (int i(0);i<polja.size();i++){
				for(int j(0);j<polja.at(i).size();j++){
					polja.at(i).at(j)=Polje::Prazno;
				}
			}
			return Status::KrajPoraz;
		}
		else if (polja.at(x).at(y+1)==Polje::Prazno){
			for (int i(0);i<polja.size();i++){
				for (int j(0);j<polja.at(i).size();i++){
					if (polja.at(i).at(j)==Polje::Prazno) {
						y=y+1;
						return Status::NijeKraj;
					}
				}
			}
		return Status::KrajPobjeda;	
		}
	}
	else if (smjer==Smjerovi::DoljeLijevo) {
		if (polja.size()<(x+1) || polja.size()<(y-1)) throw std::out_of_range ("Izlazak van igrace table");
		if (polja.at(x+1).at(y-1)==Polje::BlokiranoPosjeceno || polja.at(x+1).at(y-1)==Polje::BlokiranoPrazno || polja.at(x+1).at(y-1)==Polje::BlokiranoMina) throw std::logic_error ("Blokirano polje");
		if (polja.at(x+1).at(y-1)==Polje::Mina) {
			for (int i(0);i<polja.size();i++){
				for(int j(0);j<polja.at(i).size();j++){
					polja.at(i).at(j)=Polje::Prazno;
				}
			}
			return Status::KrajPoraz;
		}
		else if (polja.at(x+1).at(y-1)==Polje::Prazno){
			for (int i(0);i<polja.size();i++){
				for (int j(0);j<polja.at(i).size();i++){
					if (polja.at(i).at(j)==Polje::Prazno) {
						x=x+1;
						y=y-1;
						return Status::NijeKraj;
					}
				}
			}
		return Status::KrajPobjeda;	
		}
	}
	else if (smjer==Smjerovi::Dolje) {
		if (polja.size()<(x+1) || polja.size()<(y)) throw std::out_of_range ("Izlazak van igrace table");
		if (polja.at(x+1).at(y)==Polje::BlokiranoPosjeceno || polja.at(x+1).at(y)==Polje::BlokiranoPrazno || polja.at(x+1).at(y)==Polje::BlokiranoMina) throw std::logic_error ("Blokirano polje");
		if (polja.at(x+1).at(y)==Polje::Mina) {
			for (int i(0);i<polja.size();i++){
				for(int j(0);j<polja.at(i).size();j++){
					polja.at(i).at(j)=Polje::Prazno;
				}
			}
			return Status::KrajPoraz;
		}
		else if (polja.at(x+1).at(y)==Polje::Prazno){
			for (int i(0);i<polja.size();i++){
				for (int j(0);j<polja.at(i).size();i++){
					if (polja.at(i).at(j)==Polje::Prazno) {
						x=x+1;
						return Status::NijeKraj;
					}
				}
			}
		return Status::KrajPobjeda;	
		}
	}
	else if (smjer==Smjerovi::DoljeDesno) {
		if (polja.size()<(x+1) || polja.size()<(y+1)) throw std::out_of_range ("Izlazak van igrace table");
		if (polja.at(x+1).at(y+1)==Polje::BlokiranoPosjeceno || polja.at(x+1).at(y+1)==Polje::BlokiranoPrazno || polja.at(x+1).at(y+1)==Polje::BlokiranoMina) throw std::logic_error ("Blokirano polje");
		if (polja.at(x+1).at(y+1)==Polje::Mina) {
			for (int i(0);i<polja.size();i++){
				for(int j(0);j<polja.at(i).size();j++){
					polja.at(i).at(j)=Polje::Prazno;
				}
			}
			return Status::KrajPoraz;
		}
		else if (polja.at(x+1).at(y+1)==Polje::Prazno){
			for (int i(0);i<polja.size();i++){
				for (int j(0);j<polja.at(i).size();i++){
					if (polja.at(i).at(j)==Polje::Prazno) {
						x=x+1;
						y=y+1;
						return Status::NijeKraj;
					}
				}
			}
		return Status::KrajPobjeda;	
		}
	}
}
Status Idi (Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	polja.at(x).at(y)=Polje::Posjeceno;
	if (polja.size()<novi_x || polja.size()<novi_y) throw std::out_of_range ("Izlazak van igrace table");
	if (polja.at(novi_x).at(novi_y)==Polje::BlokiranoPosjeceno || polja.at(novi_x).at(novi_y)==Polje::BlokiranoPrazno || polja.at(novi_x).at(novi_y)==Polje::BlokiranoMina) throw std::logic_error ("Blokirano polje");
	if (polja.at(novi_x).at(novi_y)==Polje::Mina) {
		for (int i(0);i<polja.size();i++){
			for(int j(0);j<polja.at(i).size();j++){
				polja.at(i).at(j)=Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
	else if (polja.at(novi_x).at(novi_y)==Polje::Prazno){
		polja.at(novi_x).at(novi_y)=Polje::Posjeceno;
		for (int i(0);i<polja.size();i++){
			for (int j(0);j<polja.at(i).size();i++){
				if (polja.at(i).at(j)==Polje::Prazno) {
					x=novi_x;
					y=novi_y;
					return Status::NijeKraj;
				}
			}
		}
	return Status::KrajPobjeda;	
	}
}
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	std::string komanda_1, nova_komanda;
	std::getline(std::cin,komanda_1);
	for (int i(0);i<komanda_1.length();i++){
		while (komanda_1.at(i) == ' ') i++;
		while (komanda_1.at(i) != ' ' && i<komanda_1.length()){
			nova_komanda.push_back(komanda_1.at(i));
			i++;
			if (i==komanda_1.length()) break;
		}
	}
	for (int i(0);i<nova_komanda.length();i++){
		if (nova_komanda.length()>=2 && nova_komanda.at(i)=='P' && nova_komanda.at(i+1)=='1'){
			if (nova_komanda.length()==2){ 
				greska=KodoviGresaka::NedostajeParametar;
				return false;
			}
			komanda=Komande::PomjeriJednoMjesto;
			if(nova_komanda.length() == 4 && nova_komanda.at(i+2)=='G' && nova_komanda.at(i+3)=='L'){
				smjer=Smjerovi::GoreLijevo;
				return true;
			}
			else if(nova_komanda.at(i+2)=='G' && nova_komanda.length()==3){
				smjer=Smjerovi::Gore;
				return true;
			}
			else if(nova_komanda.at(i+2)=='G' && nova_komanda.at(i+3)=='D' && nova_komanda.length()==4){
				smjer=Smjerovi::GoreDesno;
				return true;
			}
			else if(nova_komanda.at(i+2)=='L' && nova_komanda.length()==3){
				smjer=Smjerovi::Lijevo;
				return true;
			}
			else if(nova_komanda.at(i+2)=='D' && nova_komanda.length()==3){
				smjer=Smjerovi::Desno;
				return true;
			}
			else if(nova_komanda.length()==5 && nova_komanda.at(i+2)=='D' && nova_komanda.at(i+3)=='o' && nova_komanda.at(i+4)=='L'){
				smjer=Smjerovi::DoljeLijevo;
				return true;
			}
			else if(nova_komanda.length()==4 && nova_komanda.at(i+2)=='D' && nova_komanda.at(i+3)=='o'){
				smjer=Smjerovi::Dolje;
				return true;
			}
			else if(nova_komanda.length()==5 && nova_komanda.at(i+2)=='D' && nova_komanda.at(i+3)=='o' && nova_komanda.at(i+4)=='D'){
				smjer=Smjerovi::DoljeDesno;
				return true;
			}
			else{
				greska=KodoviGresaka::NeispravanParametar;
				return false;
			}
		}
		else if (nova_komanda.length()>1 && nova_komanda.at(i)=='P' && nova_komanda.at(i+1)=='>'){
			if (nova_komanda.length()==2){
				greska=KodoviGresaka::NedostajeParametar;
				return false;
			}
			komanda=Komande::PomjeriDalje;
			if (nova_komanda.at(i+2)>='0' && nova_komanda.at(i+2)<='9' && nova_komanda.at(i+3)>='0' && nova_komanda.at(i+3)<='9'){
				int j=0;
				for (int k('0');k<='9';k++){
					if (k==nova_komanda.at(i+2)) x=j;
					if (k==nova_komanda.at(i+3)) y=j;
					j++;
				}
				return true;
			}
			else if (!(nova_komanda.at(i+2)>='0' && nova_komanda.at(i+2)<='9') || !(nova_komanda.at(i+3)>='0' && nova_komanda.at(i+3)<='9')){
				greska=KodoviGresaka::NeispravanParametar;
				return false;
			}
			else {
				greska =KodoviGresaka::SuvisanParametar;
				return false;
			}
		}
		else if (nova_komanda.at(i)=='B'){
			if(nova_komanda.length()==1){
				greska=KodoviGresaka::NedostajeParametar;
				return false;
			}
			komanda=Komande::Blokiraj;
			if (nova_komanda.at(i+1)>='0' && nova_komanda.at(i+1)<='9' && nova_komanda.at(i+2)>='0' && nova_komanda.at(i+2)<='9'){
				int j=0;
				for (int k('0');k<='9';k++){
					if (k==nova_komanda.at(i+1)) x=j;
					if (k==nova_komanda.at(i+2)) y=j;
					j++;
				}
				return true;
			}
			else if (!(nova_komanda.at(i+1)>='0' && nova_komanda.at(i+1)<='9') || !(nova_komanda.at(i+2)>='0' && nova_komanda.at(i+2)<='9')){
				greska=KodoviGresaka::NeispravanParametar;
				return false;
			}
			else {
				greska =KodoviGresaka::NedostajeParametar;
				return false;
			}
			
		}	
		else if (nova_komanda.at(i)=='D'){
			if(nova_komanda.length()==1){
				greska=KodoviGresaka::NedostajeParametar;
				return false;
			}
			komanda=Komande::Deblokiraj;
			if (nova_komanda.at(i+1)>='0' && nova_komanda.at(i+1)<='9' && nova_komanda.at(i+2)>='0' && nova_komanda.at(i+2)<='9'){
				int j=0;
				for (int k('0');k<='9';k++){
					if (k==nova_komanda.at(i+1)) x=j;
					if (k==nova_komanda.at(i+2)) y=j;
					j++;
				}
				return true;
			}
			else if (!(nova_komanda.at(i+2)>='0' && nova_komanda.at(i+2)<='9') || !(nova_komanda.at(i+3)>='0' && nova_komanda.at(i+3)<='9')){
				greska=KodoviGresaka::NeispravanParametar;
				return false;
			}
			else {
				greska =KodoviGresaka::NedostajeParametar;
				return false;
			}
			
		}
		else if (nova_komanda.length()>1 && nova_komanda.at(i)=='P' && nova_komanda.at(i+1)=='O'){
			komanda=Komande::PrikaziOkolinu;
			if (nova_komanda.size()>2){
				greska=KodoviGresaka::SuvisanParametar;
				return false;
			}
			return true;
		}
		else if (nova_komanda.at(i)=='Z'){
			komanda=Komande::ZavrsiIgru;
			if (nova_komanda.size()>1){
				greska=KodoviGresaka::SuvisanParametar;
				return false;
			}
			return true;
		}
		else if (nova_komanda.at(i)=='K'){
			komanda=Komande::KreirajIgru;
			if (nova_komanda.size()>1){
				greska=KodoviGresaka::SuvisanParametar;
				return false;
			}
			return true;
		}
		else {
			greska=KodoviGresaka::PogresnaKomanda;
			return false;
		}
	}
}
void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0){
 	if (komanda==Komande::PomjeriJednoMjesto){
 		try{
 			Status status=Idi (polja,x,y,p_smjer);
 			if (status==Status::KrajPoraz) {
 				std::cout << "Nagazili ste na minu";
 				for (int i(0);i<polja.size();i++){
 					for (int j(0);j<polja.at(i).size();j++){
 						polja.at(i).at(j)=Polje::Prazno;
 					}
 				}
 				throw std::runtime_error ("Igra zavrsena");
 			}
 			else if (status==Status::KrajPobjeda){
 				std::cout << "Bravo, obisli ste sva sigurna polja";
 				for (int i(0);i<polja.size();i++){
 					for(int j(0);j<polja.at(i).size();j++){
 						polja.at(i).at(j)=Polje::Prazno;
 					}
 				}
 				throw std::runtime_error ("Igra zavrsena");
 			}
 			std::cout <<"Tekuca pozicija igraca je (" << x << "," << y << ")" << std::endl;
 		}
 		catch(std::out_of_range izuzetak){
        	std::cout << izuzetak.what() << std::endl;
 		}
        catch(std::logic_error izuzetak){
        	std::cout << izuzetak.what() << std::endl;
        }
    }
    else if (komanda==Komande::Blokiraj){
    	try{
    		BlokirajPolje(polja,x,y);
    	}
    	catch (std::domain_error izuzetak){
    		std::cout << izuzetak.what() << std::endl;
    	}
    }
    else if (komanda==Komande::Deblokiraj){
    	try{
    		DeblokirajPolje(polja,x,y);
    	}
    	catch (std::domain_error izuzetak){
    		std::cout << izuzetak.what() << std::endl;
    	}
    }
    else if (komanda==Komande::PomjeriDalje){
 		try{
 			Status status=Idi (polja,p_x,p_y,x,y);
 			x=p_x;
 			y=p_y;
 			if (status==Status::KrajPoraz) {
 				std::cout << "Nagazili ste na minu";
 				for (int i(0);i<polja.size();i++){
 					for (int j(0);j<polja.at(i).size();j++){
 						polja.at(i).at(j)=Polje::Prazno;
 					}
 				}
 				throw std::runtime_error ("Igra zavrsena");
 			}
 			else if (status==Status::KrajPobjeda){
 				std::cout << "Bravo, obisli ste sva sigurna polja";
 					for (int i(0);i<polja.size();i++){
 					for(int j(0);j<polja.at(i).size();j++){
 						polja.at(i).at(j)=Polje::Prazno;
 					}
 				}
 				throw std::runtime_error ("Igra zavrsena");
 			}
 			std::cout <<"Tekuca pozicija igraca je (" << x << "," << y << ")" << std::endl;
 			
 		}
 		catch(std::out_of_range izuzetak){
        	std::cout << izuzetak.what() << std::endl;
 		}
        catch(std::logic_error izuzetak){
        	std::cout << izuzetak.what() << std::endl;
        }
    }
 	else if(komanda==Komande::PrikaziOkolinu){
 		try{
 				Matrica m=PrikaziOkolinu(polja,x,y);
 			for (int i(0);i<m.size();i++){
 				for(int j(0);j<m.at(i).size();j++){
 					std::cout << m.at(i).at(j) << " ";
 				}
 				std::cout << std::endl;
 			}
 		}
 		catch (std::domain_error izuzetak){
 			std::cout << izuzetak.what() << std::endl;
 		}
 	}
 	else if(komanda==Komande::ZavrsiIgru){
 		for (int i(0);i<polja.size();i++){
 			for (int j(0);j<polja.at(i).size();j++){
 				polja.at(i).at(j)=Polje::Prazno;
 			}
 		}
 		throw std::runtime_error ("Igra zavrsena");
 	}
 	else if (komanda==Komande::KreirajIgru){   
 		int n,e(0);
 		while (e!=2){
 			std::cout << "Unesite broj polja: ";
 			std::cin >> n;
 			if (n<=0) std::cout << "Greska, unesite ponovo!" << std::endl;
 			else break;
 		}	
 		Matrica mine;
 		std::cout << "Unesite pozicije mina: ";
 		std::complex<int> mina;
 		while (true){
 			std::cin.clear();
 			std::cin.ignore(10000,'\n');
 			std::cin >> mina;
 			if(!std::cin){
 				std::cin.clear();
 				if(std::cin.peek()=='.'){
 					std::cin.ignore(10000,'\n');
 					break;
 				}
 				else {
 					std::cout << "Greska, unesite ponovo!" << std::endl;
 					continue;
 				}
 			}
 			else if(mina.real()<0 || mina.real()>=n || mina.imag()<0 || mina.imag()>=n){
 				std::cout << "Greska, unesite ponovo!"<< std::endl;
 				continue;
 			}
 			mine.push_back({mina.real(),mina.imag()});
 			x=0;
 			y=0;
 		}
 		try{
 			polja=KreirajIgru(n,mine);
 		}
 		catch(std::domain_error err){
 			std::cout << err.what() << std::endl;
 		}
 	}
 }


int main (){
	Komande komanda;
	KodoviGresaka greska;
	Tabla tabla;
	Smjerovi smjer;
	int x(0),y(0),X(0),Y(0);
	try{
		do{
			std::cout << "Unesite komandu: ";
			if (UnosKomande(komanda,smjer,x,y,greska)){
				IzvrsiKomandu(komanda,tabla,x,y,smjer,X,Y);
			}
			else PrijaviGresku(greska);
		}while(true);
	}
	catch (std::domain_error err){
		std::cout << err.what() << std::endl;
	}
	catch (std::runtime_error err){
	}
	catch (std::out_of_range err){
		std::cout << err.what() << std::endl;
	}
	catch (std::logic_error err){
		std::cout << err.what() << std::endl;
	}
	catch (...){}
	std::cout << "Dovidjenja!";
return 0;
}
/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

enum class Polje{Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina};
enum class Smjerovi{GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo};
enum class Status{NijeKraj, KrajPoraz, KrajPobjeda};
enum class KodoviGresaka{PogresnaKomanda, NedostajeParmetar, SuvisanParametar, NeispravanParametar};
enum class Komande{PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru};
typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	Tabla tabla(n,std::vector<Polje> (n));
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			tabla[i][j]=Polje::Prazno;
		}
	}
	//Provjeramo da li svaki od vektora vektora "mine" ima po dva elementa i da li neki od elmenata izlazi iz opsega
	for(int i=0; i<mine.size(); i++){
		if(mine[i].size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
	}
	
	for(int i=0; i<mine.size(); i++){
		for(int j=0; j<mine[i].size(); j++){
			if(mine[i][j]>n || mine[i][j]<0) throw std::domain_error ("Ilegalne pozicije mina");
		}
	}
	
	//Postavljanje mina
	for(int i=0; i<mine.size(); i++){
		int k_1 (mine[i][0]);
		int k_2 (mine[i][1]);
		tabla[k_1][k_2]=Polje::Mina;
	}
	
	return tabla;
}

/*
 
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	std::vector<std::vector<int>> matrica(3, std::vector<int> (3));
	
}
*/


void BlokirajPolje(Tabla &polja, int x, int y){
	std::string x1(std::to_string(x)), y1(std::to_string(y));
	if(x<0 || x>polja.size() || y<0 || y>polja.size()) throw std::domain_error ("Polje ("  + x1 + "," + y1 + ")ne postoji"); /////////////// (x,y)
	if(polja[x][y]==Polje::Prazno) polja[x][y]=Polje::BlokiranoPrazno;
	else if(polja[x][y]==Polje::Posjeceno) polja[x][y]=Polje::BlokiranoPosjeceno;
	else if(polja[x][y]==Polje::Mina) polja[x][y]=Polje::BlokiranoMina;
}



void DeblokirajPolje(Tabla &polja, int x, int y){
	if(x<0 || x>polja.size() || y<0 || y>polja.size()) throw std::domain_error ("Polje ("  + std::to_string(x) + "," + std::to_string(y) + ")ne postoji"); ///////////////// (x,y)
	if(polja[x][y]==Polje::BlokiranoPrazno) polja[x][y]=Polje::Prazno;
	else if(polja[x][y]==Polje::BlokiranoPosjeceno) polja[x][y]=Polje::Posjeceno;
	else if(polja[x][y]==Polje::BlokiranoMina) polja[x][y]=Polje::Mina;
}



Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	if(smjer==Smjerovi::GoreLijevo) {
		if(x==0 || y==0) throw std::out_of_range ("Izlazak van igrace table");
		polja[x][y]=Polje::Posjeceno;
		x=x-1;
		y=y-1;
		if(polja[x][y]==Polje::BlokiranoPosjeceno || polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoMina) throw std::logic_error ("Blokirano polje");
		//Vracanje statusa
		int br(0);
		for(int m=0; m<polja.size(); m++){
			for(int n=0; n<polja.size(); n++){
				if(polja[m][n]==Polje::Prazno) br++;
			}
		}
		if(br==0) return Status::KrajPobjeda;
		else if(polja[x][y]==Polje::Mina){ 
			for(int i=0; i<polja.size(); i++){
				for(int j=0; j<polja.size(); j++){
					polja[i][j]=Polje::Prazno;
				}
			}
			return Status::KrajPoraz; 
		}
		
		else return Status::NijeKraj;
	}
	
	
	else if(smjer==Smjerovi::Gore){
		if(x==0) throw std::out_of_range ("Izlazak van igrace table");
		polja[x][y]=Polje::Posjeceno;
		x=x-1;
		if(polja[x][y]==Polje::BlokiranoPosjeceno || polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoMina) throw std::logic_error ("Blokirano polje");
		//Vracanje statusa
		int br(0);
		for(int m=0; m<polja.size(); m++){
			for(int n=0; n<polja.size(); n++){
				if(polja[m][n]==Polje::Prazno) br++;
			}
		}
		if(br==0) return Status::KrajPobjeda;
		else if(polja[x][y]==Polje::Mina){ 
			for(int i=0; i<polja.size(); i++){
				for(int j=0; j<polja.size(); j++){
					polja[i][j]=Polje::Prazno;
				}
			}
			return Status::KrajPoraz; 
		}
		
		else return Status::NijeKraj;
	}
	
	
	else if(smjer==Smjerovi::GoreDesno){
		if(x==0 || y==polja.size()) throw std::out_of_range ("Izlazak van igrace table");
		polja[x][y]=Polje::Posjeceno;
		x=x-1;
		y=y+1;
		if(polja[x][y]==Polje::BlokiranoPosjeceno || polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoMina) throw std::logic_error ("Blokirano polje");
		//Vracanje statusa
		int br(0);
		for(int m=0; m<polja.size(); m++){
			for(int n=0; n<polja.size(); n++){
				if(polja[m][n]==Polje::Prazno) br++;
			}
		}
		if(br==0) return Status::KrajPobjeda;
		else if(polja[x][y]==Polje::Mina){ 
			for(int i=0; i<polja.size(); i++){
				for(int j=0; j<polja.size(); j++){
					polja[i][j]=Polje::Prazno;
				}
			}
			return Status::KrajPoraz; 
		}
		
		else return Status::NijeKraj;
	}
	
	
	else if(smjer==Smjerovi::Desno){
		if(y==0) throw std::out_of_range ("Izlazak van igrace table");
		polja[x][y]=Polje::Posjeceno;
		y=y+1;
		if(polja[x][y]==Polje::BlokiranoPosjeceno || polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoMina) throw std::logic_error ("Blokirano polje");
		//Vracanje statusa
		int br(0);
		for(int m=0; m<polja.size(); m++){
			for(int n=0; n<polja.size(); n++){
				if(polja[m][n]==Polje::Prazno) br++;
			}
		}
		if(br==0) return Status::KrajPobjeda;
		else if(polja[x][y]==Polje::Mina){ 
			for(int i=0; i<polja.size(); i++){
				for(int j=0; j<polja.size(); j++){
					polja[i][j]=Polje::Prazno;
				}
			}
			return Status::KrajPoraz; 
		}
		
		else return Status::NijeKraj;
	}
	
	
	else if(smjer==Smjerovi::DoljeDesno){
		if(x==polja.size() || y==polja.size()) throw std::out_of_range ("Izlazak van igrace table");
		polja[x][y]=Polje::Posjeceno;
		x=x+1;
		y=y+1;
		if(polja[x][y]==Polje::BlokiranoPosjeceno || polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoMina) throw std::logic_error ("Blokirano polje");
		//Vracanje statusa
		int br(0);
		for(int m=0; m<polja.size(); m++){
			for(int n=0; n<polja.size(); n++){
				if(polja[m][n]==Polje::Prazno) br++;
			}
		}
		if(br==0) return Status::KrajPobjeda;
		else if(polja[x][y]==Polje::Mina){ 
			for(int i=0; i<polja.size(); i++){
				for(int j=0; j<polja.size(); j++){
					polja[i][j]=Polje::Prazno;
				}
			}
			return Status::KrajPoraz; 
		}
		
		else return Status::NijeKraj;
	}
	
	
	else if(smjer==Smjerovi::Dolje){
		if(x==polja.size()) throw std::out_of_range ("Izlazak van igrace table");
		polja[x][y]=Polje::Posjeceno;
		x=x+1;
		if(polja[x][y]==Polje::BlokiranoPosjeceno || polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoMina) throw std::logic_error ("Blokirano polje");
		//Vracanje statusa
		int br(0);
		for(int m=0; m<polja.size(); m++){
			for(int n=0; n<polja.size(); n++){
				if(polja[m][n]==Polje::Prazno) br++;
			}
		}
		if(br==0) return Status::KrajPobjeda;
		else if(polja[x][y]==Polje::Mina){ 
			for(int i=0; i<polja.size(); i++){
				for(int j=0; j<polja.size(); j++){
					polja[i][j]=Polje::Prazno;
				}
			}
			return Status::KrajPoraz; 
		}
		
		else return Status::NijeKraj;
	}
	
	
	else if(smjer==Smjerovi::DoljeLijevo){
		if(x==polja.size() || y==0) throw std::out_of_range ("Izlazak van igrace table");
		polja[x][y]=Polje::Posjeceno;
		x=x+1;
		y=y-1;
		if(polja[x][y]==Polje::BlokiranoPosjeceno || polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoMina) throw std::logic_error ("Blokirano polje");
		//Vracanje statusa
		int br(0);
		for(int m=0; m<polja.size(); m++){
			for(int n=0; n<polja.size(); n++){
				if(polja[m][n]==Polje::Prazno) br++;
			}
		}
		if(br==0) return Status::KrajPobjeda;
		else if(polja[x][y]==Polje::Mina){ 
			for(int i=0; i<polja.size(); i++){
				for(int j=0; j<polja.size(); j++){
					polja[i][j]=Polje::Prazno;
				}
			}
			return Status::KrajPoraz; 
		}
		
		else return Status::NijeKraj;
	}
	
	
	else if(smjer==Smjerovi::Lijevo){
		if(y==0) throw std::out_of_range ("Izlazak van igrace table");
		polja[x][y]=Polje::Posjeceno;
		y=y-1;
		if(polja[x][y]==Polje::BlokiranoPosjeceno || polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoMina) throw std::logic_error ("Blokirano polje");
		//Vracanje statusa
		int br(0);
		for(int m=0; m<polja.size(); m++){
			for(int n=0; n<polja.size(); n++){
				if(polja[m][n]==Polje::Prazno) br++;
			}
		}
		if(br==0) return Status::KrajPobjeda;
		else if(polja[x][y]==Polje::Mina){ 
			for(int i=0; i<polja.size(); i++){
				for(int j=0; j<polja.size(); j++){
					polja[i][j]=Polje::Prazno;
				}
			}
			return Status::KrajPoraz; 
		}
		
		else return Status::NijeKraj;
	}
	
}



Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	if(novi_x<0 || novi_x>polja.size() || novi_y<0 || novi_y>polja.size()) throw std::out_of_range("Izlazak van igrace table");
	if(polja[novi_x][novi_y]==Polje::BlokiranoPosjeceno || polja[novi_x][novi_y]==Polje::BlokiranoPrazno || polja[novi_x][novi_y]==Polje::BlokiranoMina) throw std::logic_error ("Blokirano polje");
	x=novi_x;
	y=novi_y;
	//Vracanje statusa
	int br(0);
	for(int m=0; m<polja.size(); m++){
		for(int n=0; n<polja.size(); n++){
			if(polja[m][n]==Polje::Prazno) br++; 
		}
	}
	if(br==0) return Status::KrajPobjeda;
	else if(polja[x][y]==Polje::Mina){ 
		for(int i=0; i<polja.size(); i++){
			for(int j=0; j<polja.size(); j++){
				polja[i][j]=Polje::Prazno;
			}
		}
		return Status::KrajPoraz; 
	}
	else return Status::NijeKraj;
}



void PrijaviGresku(KodoviGresaka g){
	if(g==KodoviGresaka::PogresnaKomanda) std::cout<<"Nerazumljiva komanda!";
	else if(g==KodoviGresaka::NedostajeParmetar) std::cout<<"Komanda trazi parametar koji nije naveden!";
	else if(g==KodoviGresaka::NeispravanParametar) std::cout<<"Parametar komande nije ispravan!";
	else if(g==KodoviGresaka::SuvisanParametar)  std::cout<<"Zadan je suvisan parametar nakon komande!";
}



bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	std::cout<<"Unesite komandu: ";
	std::string s;
	std::getline(std::cin, s);
	int i(0);
	while(i<s.size()){
		if(s[i]==' '){
			while(s[i]==' ' && i<s.size()){  
				if(i==s.size()-1) {greska=KodoviGresaka::PogresnaKomanda; return false;}
				i++;
			}
		}
		if(s[i]!='P' || s[i]!='B' || s[i]!='D' || s[i]!='Z' || s[i]!='K') {greska=KodoviGresaka::PogresnaKomanda; return false;}
		
		
		//Za P1
		if(s[i]=='P' && i<s.size()){
			if((i+1)==s.size() || s[i+1]!='1') {greska=KodoviGresaka::PogresnaKomanda; return false;}
			if(s[i+1]=='1' && (i+1)<s.size()){
				int p1;
				i++;
				if(s[i+1]!=' ' || (i+1)==s.size() || (s[i+1]<'A' && s[i+1]>'Z')) {greska=KodoviGresaka::PogresnaKomanda; return false;} 
				if(s[i+1]==' ' && (i+1)<s.size()){ //Ako je poslije P1 razmak
					while(s[i]==' ' && i<s.size()) {
						if(i==s.size()-1) {greska=KodoviGresaka::PogresnaKomanda; return false;}
						i++;
					}
					if((s[i]<'A' && s[i]>'Z'))  {greska=KodoviGresaka::PogresnaKomanda; return false;}
				}
				//Kada naidje na veliko slovo
				if(s[i]>='A' && s[i]<='Z'){
					int brojac(0);
					p1=i;
					while(((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z')) && i<s.size()) {i++; brojac++;}
					//Ako je jedno slovo
					if(brojac==1 && (s.substr(p1,brojac)!="G" && s.substr(p1,brojac)!="D" && s.substr(p1,brojac)!="L")) {greska=KodoviGresaka::PogresnaKomanda; return false;}
					if(brojac==1 && (s.substr(p1,brojac)=="G" || s.substr(p1,brojac)=="D" || s.substr(p1,brojac)=="L")){
						while(i<s.size()){
							i++;
							if(s[i]!=' ') {greska=KodoviGresaka::PogresnaKomanda; return false;}
							if(i==s.size()-1) {
								komanda=Komande::PomjeriJednoMjesto; 
								if(s.substr(p1,brojac)=="G") smjer=Smjerovi::Gore;
								else if(s.substr(p1,brojac)=="D") smjer=Smjerovi::Desno;
								else if(s.substr(p1,brojac)=="L") smjer=Smjerovi::Lijevo;
								return true;
							}
						}
					}
				
					//Ako su dva slova
					if(brojac==2 && (s.substr(p1,brojac)!="GL" && s.substr(p1,brojac)!="GD" && s.substr(p1,brojac)!="Do")) {greska=KodoviGresaka::PogresnaKomanda; return false;}
					if(brojac==2 && (s.substr(p1,brojac)=="GL" || s.substr(p1,brojac)=="GD" || s.substr(p1,brojac)=="Do")){
						while(i<s.size()){
							i++;
							if(s[i]!=' ') {greska=KodoviGresaka::PogresnaKomanda; return false;}
							if(i==s.size()-1) {
								komanda=Komande::PomjeriJednoMjesto;
								if(s.substr(p1,brojac)=="GL") smjer=Smjerovi::GoreLijevo;
								else if(s.substr(p1,brojac)=="GD") smjer=Smjerovi::GoreDesno;
								else if(s.substr(p1,brojac)=="Do") smjer=Smjerovi::Dolje;
								return true;
							}
						}
					}
				
					//Ako su tri slova
					if(brojac==3 && (s.substr(p1,brojac)!="DoD" && s.substr(p1,brojac)!="DoL")) {greska=KodoviGresaka::PogresnaKomanda; return false;}
					if(brojac==3 && (s.substr(p1,brojac)=="DoD" || s.substr(p1,brojac)=="DoL")){
						while(i<s.size()){
							i++;
							if(s[i]!=' ') {greska=KodoviGresaka::PogresnaKomanda; return false;}
							if(i==s.size()-1) {
								komanda=Komande::PomjeriJednoMjesto;
								if(s.substr(p1,brojac)=="DoD") smjer=Smjerovi::DoljeDesno;
								else if(s.substr(p1,brojac)=="DoL") smjer=Smjerovi::DoljeLijevo;
								return true;
							}
						}
					}
				} 
			}
		}
		
		
		
		//Za P>
		if(s[i]=='P' && i<s.size()){
			if((i+1)==s.size() || s[i+1]!='>') {greska=KodoviGresaka::PogresnaKomanda; return false;}
			if(s[i+1]=='>' && (i+1)<s.size()){
				i++;
				if(i+1==s.size() || s[i+1]!=' ' || (s[i+1]<'0' && s[i+1]>'9')) {greska=KodoviGresaka::PogresnaKomanda; return false;}
				if(s[i+1]==' ' && (i+1)<s.size()){ //Ako je poslije P> razmak
					while(s[i]==' ' && i<s.size()) {
						if(i==s.size()-1) {greska=KodoviGresaka::PogresnaKomanda; return false;}
						i++;
					}
				}	
				if(s[i]<'0' && s[i]>'9') {greska=KodoviGresaka::PogresnaKomanda; return false;}	
				if(s[i]>='0' && s[i]<='9') x=s[i]; //Upisana x koordinata
				if(i+1==s.size() || (s[i+1]<'0' && s[i+1]>'9') || s[i+1]!=' ') {greska=KodoviGresaka::PogresnaKomanda; return false;}	
				if(s[i+1]==' ' && (i+1)<s.size()){ //Pomjeraj dok je razmak, ako ga ima
						i++;
						while(s[i]==' ' && i<s.size()){ 
							if(i==s.size()-1) {greska=KodoviGresaka::PogresnaKomanda; return false;}
							i++;
						}
					if(s[i]<'0' && s[i]>'9') {greska=KodoviGresaka::PogresnaKomanda; return false;} //Ako nije broj
				}
				
				if(s[i]>='0' && s[i]<='9') y=s[i]; //Ako jeste broj, upisana y koordinata
				if((i+1)==s.size()){ komanda=Komande::PomjeriDalje; return true;}
				if(s[i+1]!=' ' || (i+1)<s.size()) {greska=KodoviGresaka::PogresnaKomanda; return false;}
				if(s[i+1]==' ' && (i+1)<s.size()){
					i++;
					while(s[i]==' ' && i<s.size()) {
						if(i==s.size()-1 && s[i]==' ') {komanda=Komande::PomjeriDalje; return true;}
						i++;
					}
					if(s[i]!=' ') {greska=KodoviGresaka::PogresnaKomanda; return false;}
				}
			}
		}
		
		
		//Za B
		if(s[i]=='B' && i<s.size()){
			if(i+1==s.size() || s[i+1]!=' ' || (s[i+1]<'0' && s[i+1]>'9')) {greska=KodoviGresaka::PogresnaKomanda; return false;}
			if(s[i+1]==' '){ //Ako je poslije B razmak
				while(s[i]==' ' && i<s.size()) {
					if(i==s.size()-1) {greska=KodoviGresaka::PogresnaKomanda; return false;}
					i++;
				}
			}			
			if(s[i]<'0' && s[i]>'9') {greska=KodoviGresaka::PogresnaKomanda; return false;}
			int pamti_1, pamti_2;
			if(s[i]>='0' && s[i]<='9') pamti_1=s[i]; //Zapamcena x koordinata
			//Ako su koord. unesene sa razmakom npr. 3     1
			if(s[i+1]!=' ' && (s[i+1]<'0' && s[i+1]>'9') && i+1==s.size()) {greska=KodoviGresaka::PogresnaKomanda; return false;}
			if(s[i+1]==' ' && (i+1)<s.size()){
				i++;
				while(s[i]==' ' && i<s.size()){ 
					if(i==s.size()-1) {greska=KodoviGresaka::PogresnaKomanda; return false;}
					i++;
				}
			}
			if(s[i]<'0' && s[i]>'9')  {greska=KodoviGresaka::PogresnaKomanda; return false;}
			if(s[i]>='0' && s[i]<='9') pamti_2=s[i]; //Zapamcena y koordinata
			if((i+1)==s.size()) {
				komanda=Komande::Blokiraj; 
				
				return true;
			} 
			if((i+1)<s.size() && s[i+1]!=' ') {greska=KodoviGresaka::PogresnaKomanda; return false;}
			if((i+1)<s.size() && s[i+1]==' '){
				i++;
				while(s[i]==' ' && i<s.size()) {
					if(i==s.size()-1) {greska=KodoviGresaka::PogresnaKomanda; return false;}
					i++;
				}
			}
			if(s[i]!=' ') {greska=KodoviGresaka::PogresnaKomanda; return false;} ////////
			
		}
		
		
	
		//Za D
		if(s[i]=='D' && i<s.size()){
			if(i+1==s.size() || s[i+1]!=' ' || (s[i+1]<'0' && s[i+1]>'9')) {greska=KodoviGresaka::PogresnaKomanda; return false;}
			if(s[i+1]==' '){ //Ako je poslije B razmak
				while(s[i]==' ' && i<s.size()) {
					if(i==s.size()-1) {greska=KodoviGresaka::PogresnaKomanda; return false;}
					i++;
				}
			}			
			if(s[i]<'0' && s[i]>'9') {greska=KodoviGresaka::PogresnaKomanda; return false;}
			if(s[i]>='0' && s[i]<='9') x=s[i]; //Upisana x koordinata
			//Ako su koord. unesene sa razmakom npr. 3     1
			if(s[i+1]!=' ' && (s[i+1]<'0' && s[i+1]>'9') && i+1==s.size()) {greska=KodoviGresaka::PogresnaKomanda; return false;}
			if(s[i+1]==' ' && (i+1)<s.size()){
				i++;
				while(s[i]==' ' && i<s.size()){ 
					if(i==s.size()-1) {greska=KodoviGresaka::PogresnaKomanda; return false;}
					i++;
				}
			}
			if(s[i]<'0' && s[i]>'9')  {greska=KodoviGresaka::PogresnaKomanda; return false;}
			if(s[i]>='0' && s[i]<='9') y=s[i]; //Upisana y koordinata
			if((i+1)==s.size()) {komanda=Komande::PomjeriDalje; return true;}
			if((i+1)<s.size() && s[i+1]!=' ') {greska=KodoviGresaka::PogresnaKomanda; return false;}
			if((i+1)<s.size() && s[i+1]==' '){
				i++;
				while(s[i]==' ' && i<s.size()) {
					if(i==s.size()-1) {greska=KodoviGresaka::PogresnaKomanda; return false;}
					i++;
				}
			}
			if(s[i]!=' ') {greska=KodoviGresaka::PogresnaKomanda; return false;}
		}	
		
		
		
		
		//Za PO
		if(s[i]=='P' && i<s.size()){
			if((i+1)<s.size() && (s[i+1]!='O' || i+1==s.size())) {greska=KodoviGresaka::PogresnaKomanda; return false;}
			if(s[i+1]=='O' && i+1!=s.size()) {
				while(i<s.size()){
					i++;
					if(s[i]!=' ') {greska=KodoviGresaka::PogresnaKomanda; return false;}
				}
				if(i==s.size()-1) {komanda=Komande::PrikaziOkolinu; return true;}
			}
		}
		
		
		//Za Z
		if(s[i]=='Z' && i<s.size()){
			if((i+1)<s.size() && s[i+1]!=' ') {greska=KodoviGresaka::PogresnaKomanda; return false;}
				while(i<s.size()){
					i++;
					if(s[i]!=' ') {greska=KodoviGresaka::PogresnaKomanda; return false;}
				}
				if(i==s.size()-1) {komanda=Komande::PrikaziOkolinu; return true;}
		}
		
		
		//Za K
		if(s[i]=='K' && i<s.size()){
			if((i+1)<s.size() && s[i+1]!=' ') {greska=KodoviGresaka::PogresnaKomanda; return false;}
				while(i<s.size()){
					i++;
					if(s[i]!=' ') {greska=KodoviGresaka::PogresnaKomanda; return false;}
				}
				if(i==s.size()-1) {komanda=Komande::PrikaziOkolinu; return true;}
		}
		
		
		
		
	}
	
}

/*

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer=Smjerovi::Gore, int p_x=0, int p_y=0){
	if(komanda==)
}

*/

int main ()
{
//	int x(0), y(0);
	//bool unos (UnosKomande)
	
	
	return 0;
}
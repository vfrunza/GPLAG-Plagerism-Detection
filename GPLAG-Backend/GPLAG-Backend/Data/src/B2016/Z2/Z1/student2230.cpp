#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <string>
#include <complex>
#include <sstream>

enum class Polje{
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};

enum class Smjerovi{
	GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo,Lijevo
};
	
enum class Status{
	NijeKraj, KrajPoraz, KrajPobjeda	
};

enum class KodoviGresaka{
	PogresnaKomanda, NedostajeParmetar, SuvisanParametar, NeispravanParametar
};

enum class Komande{
	PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru	
};

typedef std::vector<std::vector<Polje>> Tabla;
typedef std::vector<std::vector<int>> Matrica;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	Tabla polja(n,std::vector<Polje>(n));
	if(mine.size()==0) throw std::domain_error("Ilegalne pozicije mina");
	for(int i(0);i<mine.size();i++){
		for(int j(0);j<mine[i].size();j++){
			if(mine[i][j]>=n) throw std::domain_error("Ilegalne pozicije mina");
		}
	}
	for(int i(0);i<mine.size();i++){
		if(mine[i].size()!=2) {throw std::domain_error("Ilegalan format zadavanja mina");}
	}
	for(int i(0);i<n;i++){
		for(int j(0);j<n;j++){
			polja[i][j]=Polje::Prazno;
		}
	}
	for(int i(0);i<mine.size();i++){
			int lijeviekstrem=mine[i][0];
			int desniekstrem=mine[i][1];
			polja[lijeviekstrem][desniekstrem]=Polje::Mina;
			}
	return polja;
}

int pomocna(const Tabla &polja,int y,int x){
	int brojac(0);
			if(x>0 && x<polja.size()-1 && y>0 && y<polja.size()-1){
				if(polja[y-1][x-1]==Polje::Mina) brojac++;
				if(polja[y-1][x]==Polje::Mina) brojac++;
				if(polja[y-1][x+1]==Polje::Mina) brojac++;
				if(polja[y][x-1]==Polje::Mina) brojac++;
				if(polja[y][x+1]==Polje::Mina) brojac++;
				if(polja[y+1][x-1]==Polje::Mina) brojac++;
				if(polja[y+1][x]==Polje::Mina) brojac++;
				if(polja[y+1][x+1]==Polje::Mina) brojac++;
			}
			else if(x==0 && y==0){
					brojac=0;
						if(polja[y][x+1]==Polje::Mina) brojac++;
						if(polja[y+1][x]==Polje::Mina) brojac++;
						if(polja[y+1][x+1]==Polje::Mina) brojac++;
					}
				
			
			else if(y==0 && x==polja.size()-1){
						brojac=0;
						if(polja[y][x-1]==Polje::Mina) brojac++;
						if(polja[y+1][x-1]==Polje::Mina) brojac++;
						if(polja[y+1][x]==Polje::Mina) brojac++;
					}
				
			
			else if(y==polja.size()-1 && x==0){
				brojac=0;
						if(polja[y-1][x]==Polje::Mina) brojac++;
						if(polja[y-1][x+1]==Polje::Mina) brojac++;
						if(polja[y][x+1]==Polje::Mina)brojac++;
					}
				
			
			else if(y==polja.size()-1 && x==polja.size()-1){
				brojac=0;
						if(polja[y][x-1]==Polje::Mina) brojac++;
						if(polja[y-1][x-1]==Polje::Mina) brojac++;
						if(polja[y-1][x]==Polje::Mina) brojac++;
					}
			else if(y==0 && x!=0 && x!=polja.size()-1){
				brojac=0;
						if(polja[y][x-1]==Polje::Mina) brojac++;
						if(polja[y][x+1]==Polje::Mina) brojac++;
						if(polja[y+1][x-1]==Polje::Mina) brojac++;
						if(polja[y+1][x]==Polje::Mina) brojac++;
						if(polja[y+1][x+1]==Polje::Mina) brojac++;
					}
		
			else if(x==0 && y!=0 && y!=polja.size()-1){
				brojac=0;
						if(polja[y-1][x]==Polje::Mina) brojac++;
						if(polja[y-1][x+1]==Polje::Mina) brojac++;
						if(polja[y][x+1]==Polje::Mina) brojac++;
						if(polja[y+1][x+1]==Polje::Mina) brojac++;
						if(polja[y+1][x]==Polje::Mina) brojac++;
					}
			else if(y==polja.size()-1 && x!=0 && x!=polja.size()-1){
				brojac=0;
						if(polja[y][x-1]==Polje::Mina) brojac++;
						if(polja[y-1][x-1]==Polje::Mina) brojac++;
						if(polja[y-1][x]==Polje::Mina) brojac++;
						if(polja[y-1][x+1]==Polje::Mina) brojac++;
						if(polja[y][x+1]==Polje::Mina) brojac++;
			}
			else if(x==polja.size()-1 && y!=0 && y!=polja.size()-1){
				brojac=0;
						if(polja[y-1][x]==Polje::Mina) brojac++;
						if(polja[y-1][x-1]==Polje::Mina) brojac++;
						if(polja[y][x-1]==Polje::Mina) brojac++;
						if(polja[y+1][x-1]==Polje::Mina) brojac++;
						if(polja[y+1][x]==Polje::Mina) brojac++;
						} 
	return brojac;	
	
}
Matrica PrikaziOkolinu(const Tabla &polja,int y, int x){
	Matrica matrica(3,std::vector<int>(3));
	for(int i(0);i<matrica.size();i++){
		for(int j(0);j<matrica.size();j++){
			matrica[i][j]=0;
		}
	}
	if(x>0 && x<polja.size()-1 && y>0 && y<polja.size()-1) {
		matrica[0][0]=pomocna(polja,y-1,x-1);
		matrica[0][1]=pomocna(polja,y-1,x);
		matrica[0][2]=pomocna(polja,y-1,x+1);
		matrica[1][0]=pomocna(polja,y,x-1);
		matrica[1][1]=pomocna(polja,y,x);	
		matrica[1][2]=pomocna(polja,y,x+1);
		matrica[2][0]=pomocna(polja,y+1,x-1);
		matrica[2][1]=pomocna(polja,y+1,x);
		matrica[2][2]=pomocna(polja,y+1,x+1);
	}
	else if(x==0 && y==0){
		matrica[0][0]=0;
		matrica[0][1]=0;
		matrica[0][2]=0;
		matrica[1][0]=0;
		matrica[2][0]=0;
		matrica[1][1]=pomocna(polja,y,x);
		matrica[1][2]=pomocna(polja,y,x+1);
		matrica[2][1]=pomocna(polja,y+1,x);
		matrica[2][2]=pomocna(polja,y+1,x+1);
	}
	else if(y==polja.size()-1 && x==0){
		matrica[0][0]=0;
		matrica[0][1]=pomocna(polja,y-1,x);
		matrica[0][2]=pomocna(polja,y-1,x+1);
		matrica[1][0]=0;
		matrica[1][1]=pomocna(polja,y,x);
		matrica[1][2]=pomocna(polja,y,x+1);
		matrica[2][0]=0;
		matrica[2][1]=0;
		matrica[2][2]=0;
	}
	else if(y==0 && x==polja.size()-1){
		matrica[0][0]=0;
		matrica[0][1]=0;
		matrica[0][2]=0;
		matrica[1][0]=pomocna(polja,y,x-1);
		matrica[1][1]=pomocna(polja,y,x);
		matrica[1][2]=0;
		matrica[2][0]=pomocna(polja,y+1,x-1);
		matrica[2][1]=pomocna(polja,y+1,x);
		matrica[2][2]=0;
	}
	else if(y==polja.size()-1 && x==polja.size()-1){
		matrica[0][0]=pomocna(polja,y-1,x-1);
		matrica[0][1]=pomocna(polja,y-1,x);
		matrica[0][2]=0;
		matrica[1][0]=pomocna(polja,y,x-1);
		matrica[1][1]=pomocna(polja,y,x);
		matrica[1][2]=0;
		matrica[2][0]=0;
		matrica[2][1]=0;
		matrica[2][2]=0;
	}
	else if(y==0 && x!=0 && x!=polja.size()-1){
		matrica[0][0]=0;
		matrica[0][1]=0;
		matrica[0][2]=0;
		matrica[1][0]=pomocna(polja,y,x-1);
		matrica[1][1]=pomocna(polja,y,x);
		matrica[1][2]=pomocna(polja,y,x+1);
		matrica[2][0]=pomocna(polja,y+1,x-1);
		matrica[2][1]=pomocna(polja,y+1,x);
		matrica[2][2]=pomocna(polja,y+1,x+1);
	}
	else if(x==0 && y!=0 && y!=polja.size()-1){
		matrica[0][0]=0;
		matrica[0][1]=pomocna(polja,y-1,x);
		matrica[0][2]=pomocna(polja,y-1,x+1);
		matrica[1][0]=0;
		matrica[1][1]=pomocna(polja,y,x);
		matrica[1][2]=pomocna(polja,y,x+1);
		matrica[2][0]=0;
		matrica[2][1]=pomocna(polja,y+1,x);
		matrica[2][2]=pomocna(polja,y+1,x+1);
	}
	else if(x==polja.size()-1 && y!=0 && y!=polja.size()-1){
		matrica[0][0]=pomocna(polja,y-1,x-1);
		matrica[0][1]=pomocna(polja,y-1,x);
		matrica[0][2]=0;
		matrica[1][0]=pomocna(polja,y,x-1);
		matrica[1][1]=pomocna(polja,y,x);
		matrica[1][2]=0;
		matrica[2][0]=pomocna(polja,y+1,x-1);
		matrica[2][1]=pomocna(polja,y+1,x);
		matrica[2][2]=0;
	}
	else if(y==polja.size()-1 && x!=0 && x!=polja.size()-1){
		matrica[0][0]=pomocna(polja,y-1,x-1);
		matrica[0][1]=pomocna(polja,y-1,x);
		matrica[0][2]=pomocna(polja,y-1,x+1);
		matrica[1][0]=pomocna(polja,y,x-1);
		matrica[1][1]=pomocna(polja,y,x);
		matrica[1][2]=pomocna(polja,y,x+1);
		matrica[2][0]=0;
		matrica[2][1]=0;
		matrica[2][2]=0;
	} 
	return matrica;
}

void BlokirajPolje(Tabla &polja,int y,int x){
	std::stringstream string;
	string<<"Polje ("<<y<<","<<x<<") ne postoji";
	std::string finalni=string.str();
	if(x<0 || x>polja.size()-1 || y<0 || y>polja.size()-1) throw std::domain_error(finalni);
	if(polja[y][x]==Polje::Prazno){
		polja[y][x]=Polje::BlokiranoPrazno;
	}
	else if(polja[y][x]==Polje::Posjeceno){
		polja[y][x]=Polje::BlokiranoPosjeceno;
	}
	else if(polja[y][x]==Polje::Mina){
		polja[y][x]=Polje::BlokiranoMina;
		}
}
void DeblokirajPolje(Tabla &polja, int y,int x){
	std::stringstream string;
	string<<"Polje ("<<y<<","<<x<<") ne postoji";
	std::string finalni=string.str();
	if(x<0 || x>polja.size()-1 || y<0 || y>polja.size()-1) throw std::domain_error(finalni);
	if(polja[y][x]==Polje::BlokiranoPrazno) polja[y][x]=Polje::Prazno;
	else if(polja[y][x]==Polje::BlokiranoMina) polja[y][x]=Polje::Mina;
	else if(polja[y][x]==Polje::BlokiranoPosjeceno) polja[y][x]=Polje::Posjeceno;
}

Status Idi(Tabla &polja, int &y, int &x, Smjerovi smjer){
	
	//if(polja[y][x]==Polje::BlokiranoPosjeceno || polja[y][x]==Polje::BlokiranoPrazno || polja[y][x]==Polje::BlokiranoMina) throw std::logic_error("Blokirano Polje");
	if(y<0 || y>polja.size()-1 || x<0 || x>polja.size()-1) throw std::out_of_range("Izlazak van igrace table");

	polja[y][x]=Polje::Posjeceno;
	if(smjer==Smjerovi::GoreLijevo){ y--; x--;
		if(polja[y][x]==Polje::BlokiranoPosjeceno || polja[y][x]==Polje::BlokiranoPrazno || polja[y][x]==Polje::BlokiranoMina) {y++;x++;throw std::logic_error("Blokirano polje");}
		if(y<0 || y>polja.size()-1 || x<0 || x>polja.size()-1){y++;x++; throw std::out_of_range("Izlazak van igrace table");}
	}
	
	else if(smjer==Smjerovi::Gore){
		y--;
		if(polja[y][x]==Polje::BlokiranoPosjeceno || polja[y][x]==Polje::BlokiranoPrazno || polja[y][x]==Polje::BlokiranoMina){y++; throw std::logic_error("Blokirano polje");}
		if(y<0 || y>polja.size()-1){y++; throw std::out_of_range("Izlazak van igrace table");}}
	
	else if(smjer==Smjerovi::GoreDesno){
		y--;x++;
		if(polja[y][x]==Polje::BlokiranoPosjeceno || polja[y][x]==Polje::BlokiranoPrazno || polja[y][x]==Polje::BlokiranoMina){y++;x--; throw std::logic_error("Blokirano polje");}
		if(y<0 || y>polja.size()-1 || x<0 || x>polja.size()-1){y++;x--; throw std::out_of_range("Izlazak van igrace table");}
	}
	
	else if(smjer==Smjerovi::Lijevo){ 
		x--;
		if(polja[y][x]==Polje::BlokiranoPosjeceno || polja[y][x]==Polje::BlokiranoPrazno || polja[y][x]==Polje::BlokiranoMina) {x++;throw std::logic_error("Blokirano polje");}
		if(x<0 || x>polja.size()-1) {x++; throw std::out_of_range("Izlazak van igrace table");}
	}
	
	else if(smjer==Smjerovi::DoljeLijevo){
		y++;x--;
		if(polja[y][x]==Polje::BlokiranoPosjeceno || polja[y][x]==Polje::BlokiranoPrazno || polja[y][x]==Polje::BlokiranoMina){y--;x++; throw std::logic_error("Blokirano polje");}
		if(y<0 || y>polja.size()-1 || x<0 || x>polja.size()-1){y--; x++; throw std::out_of_range("Izlazak van igrace table");}
	}
	
	else if(smjer==Smjerovi::Dolje){ 
		y++;
		if(polja[y][x]==Polje::BlokiranoPosjeceno || polja[y][x]==Polje::BlokiranoPrazno || polja[y][x]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		if(y<0 || y>polja.size()-1){y--; throw std::out_of_range("Izlazak van igrace table");}
	}
	
	else if(smjer==Smjerovi::DoljeDesno) {
		y++;x++;
		if(polja[y][x]==Polje::BlokiranoPosjeceno || polja[y][x]==Polje::BlokiranoPrazno || polja[y][x]==Polje::BlokiranoMina){y--; x--; throw std::logic_error("Blokirano polje");}
		if(y<0 || y>polja.size()-1 || x<0 || x>polja.size()-1){y--;x--; throw std::out_of_range("Izlazak van igrace table");}
	}
	
	else if(smjer==Smjerovi::Desno){ 
		x++;
		if(polja[y][x]==Polje::BlokiranoPosjeceno || polja[y][x]==Polje::BlokiranoPrazno || polja[y][x]==Polje::BlokiranoMina) {x--;throw std::logic_error("Blokirano polje");}
		if(x<0 || x>polja.size()-1){x--; throw std::out_of_range("Izlazak van igrace table");}
	}

	if(polja[y][x]==Polje::Mina){
	for(int i(0);i<polja.size();i++){
		for(int j(0);j<polja.size();j++){
			polja[i][j]=Polje::Prazno;
		}
	}
	return Status::KrajPoraz;
}
bool nijeposjeceno(false);
for(int i(0);i<polja.size();i++){
	for(int j(0);j<polja.size();j++){
		if(polja[i][j]==Polje::Prazno) nijeposjeceno=true; 
	}
}
if(nijeposjeceno==false) return Status::KrajPobjeda;
	
return Status::NijeKraj;
}

Status Idi(Tabla &polja, int &y, int &x, int novi_y, int novi_x){
	if(novi_x<0 || novi_x>polja.size()-1 || novi_y<0 || novi_y>polja.size()-1) throw std::out_of_range("Izlazak van igrace table");
	if(polja[novi_y][novi_x]==Polje::BlokiranoPosjeceno || polja[novi_y][novi_x]==Polje::BlokiranoPrazno || polja[novi_y][novi_x]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
	if(polja[novi_y][novi_x]==Polje::Mina){
		for(int i(0);i<polja.size();i++){
			for(int j(0);j<polja.size();j++){
				polja[i][j]=Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
	bool nijeposjeceno(false);
	for(int i(0);i<polja.size();i++){
		for(int j(0);j<polja.size();j++){
			if(polja[i][j]==Polje::Prazno) nijeposjeceno=true;
		}
	}
	x=novi_x;
	y=novi_y;
	if(nijeposjeceno==false) return Status::KrajPobjeda;

	return Status::NijeKraj;
}

void PrijaviGresku(KodoviGresaka kodovi){
	if(kodovi==KodoviGresaka::PogresnaKomanda) std::cout<<"Nerazumljiva komanda!"<<std::endl;
	else if(kodovi==KodoviGresaka::NedostajeParmetar) std::cout<<"Komanda trazi parametar koji nije naveden!"<<std::endl;
	else if(kodovi==KodoviGresaka::NeispravanParametar) std::cout<<"Parametar komande nije ispravan!"<<std::endl;
	else if(kodovi==KodoviGresaka::SuvisanParametar) std::cout<<"Zadan je suvisan parametar nakon komande!"<<std::endl;
}

int novay(0);
int novax(0);

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &y, int &x, KodoviGresaka &greska){
	std::cout<<"Unesite komandu: ";
	char c1,c2,c3;
	std::cin>>c1;
	if(c1!='P' && c1!='B' && c1!='D' && c1!='Z' && c1!='K'){greska=KodoviGresaka::PogresnaKomanda; return false;}
	std::string string;
	if(c1=='Z'){
		std::cin.get(c2);
		if(c2!=' ' && c2!='\n'){ greska=KodoviGresaka::SuvisanParametar; return false;}
		else if(c1=='Z' || (c1=='Z' && c2==' ')) komanda=Komande::ZavrsiIgru;
		return true;
	}
	else if(c1=='K'){
		std::cin.get(c2);
		if(c2!=' ' && c2!='\n') {greska=KodoviGresaka::SuvisanParametar; return false;}
		else if(c1=='K' || (c1=='K' && c2==' ')){ komanda=Komande::KreirajIgru;
		return true;}
	}
	else if(c1=='P'){
		std::cin.get(c2);
		if(c1=='P' && c2=='O'){
			//std::cin.get(c3);
			std::string s;
			std::getline(std::cin,s);
			if(s!=" " && s.length()!=0) {greska=KodoviGresaka::SuvisanParametar; return false;}
			else if((c1=='P' && c2=='O') || (c1=='P' && c2=='O' && (s==" " || s.length()==0))) komanda=Komande::PrikaziOkolinu;
			return true;
		}
		else if(c1=='P' && c2=='1'){
			std::cin.get(c3);
			if(c3!=' ') {greska=KodoviGresaka::SuvisanParametar; return false;}
			if(c1=='P' && c2=='1' && c3==' '){
				std::getline(std::cin,string);
				
				if(string!="GD" && string!="GD " && string!="G" && string!="G " && string!="GL" && string!="GL " && string!="L" && string!="L " && string!="D" && string!="D " && string!="DoL" && string!="DoL " && string!="Do" && string!="Do " && string!="DoD" && string!="DoD ") {greska=KodoviGresaka::SuvisanParametar; return false;}
				else{
					if(c1=='P' && c2=='1' && c3==' ' && (string=="GD" || string=="GD ")){
					komanda=Komande::PomjeriJednoMjesto;
					smjer=Smjerovi::GoreDesno;
					return true;
				}
				if(c1=='P' && c2=='1' && c3==' ' && (string=="G" || string=="G ")){
					komanda=Komande::PomjeriJednoMjesto;
					smjer=Smjerovi::Gore;
					return true;
				}
				if(c1=='P' && c2=='1' && c3==' ' && (string=="GL" || string=="GL ")){
					komanda=Komande::PomjeriJednoMjesto;
					smjer=Smjerovi::GoreLijevo;
					return true;
				}
				if(c1=='P' && c2=='1' && c3==' ' && (string=="D" || string=="D ")){
					komanda=Komande::PomjeriJednoMjesto;
					smjer=Smjerovi::Desno;
					return true;
				}
				if(c1=='P' && c2=='1' && c3==' ' && (string=="DoD" || string=="DoD ")){
					komanda=Komande::PomjeriJednoMjesto;
					smjer=Smjerovi::DoljeDesno;
					return true;
				}
				if(c1=='P' && c2=='1' && c3==' ' && (string=="Do" || string=="Do ")){
					komanda=Komande::PomjeriJednoMjesto;
					smjer=Smjerovi::Dolje;
					return true;
				}
				if(c1=='P' && c2=='1' && c3==' ' && (string=="DoL" || string=="DoL ")){
					komanda=Komande::PomjeriJednoMjesto;
					smjer=Smjerovi::DoljeLijevo;
					return true;
				}
				if(c1=='P' && c2=='1' && c3==' ' && (string=="L" || string=="L ")){
					komanda=Komande::PomjeriJednoMjesto;
					smjer=Smjerovi::Lijevo;
					return true;
				}
				std::cin.ignore(10000,'\n');
				}
			}
		}
		else if(c1=='P' && c2=='>'){
			std::cin.get(c3);
			if(c3!=' '){ greska=KodoviGresaka::SuvisanParametar; return false;}
			if(c1=='P' && c2=='>' && c3==' '){
				int p,q;
				std::cin>>p;  
				std::cin>>q;
				novay=p;
				novax=q;
				komanda=Komande::PomjeriDalje;
				return true;
			}
		}
	}
	else if(c1=='B'){
		std::cin.get(c2);
		if(c2!=' ' && c2!='\n') {greska=KodoviGresaka::SuvisanParametar; return false;}
		if(c1=='B' || (c1=='B' && c2==' ')){
			int p,q;
			std::cin>>p;
			std::cin>>q;
			novay=p;
			novax=q;
			komanda=Komande::Blokiraj;
			return true;
		}
	}
	else if(c1=='D'){
		std::cin.get(c2);
		if(c2!=' ' && c2!='\n'){ greska=KodoviGresaka::SuvisanParametar; return false;}
		if(c1=='D' || (c1=='D' && c2==' ')){
			int p,q;
			std::cin>>p;
			std::cin>>q;
			novay=p;
			novax=q;
			komanda=Komande::Deblokiraj;
			return true;
		}
	}
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &y, int &x, Smjerovi p_smjer=Smjerovi::Gore, int p_y=0, int p_x=0){
	//bool bul;
	//bul=UnosKomande(komanda,p_smjer,x,y,);
	if(komanda==Komande::Blokiraj){try{
		BlokirajPolje(polja,p_y,p_x);}
		catch(std::domain_error izuzetak){
			std::cout<<izuzetak.what()<<std::endl;
		}
	}
	else if(komanda==Komande::Deblokiraj){try{
		DeblokirajPolje(polja,p_y,p_x);}
		catch(std::domain_error izuzetak){
			std::cout<<izuzetak.what()<<std::endl;
		}
	}
	else if(komanda==Komande::KreirajIgru){
		int br_polja;
		char c1,c2,c3;
		//int i(0);
		std::vector<std::vector<int>> mine;
		std::vector<int> pomocni;
		std::cout<<"Unesite broj polja: ";
		std::cin>>br_polja;
		std::cout<<"Unesite pozicije mina: ";		
	//	std::complex<int> Kompleksni;
		do{	
		//	std::cout<<"opee"<<std::endl;
			std::cin>>c1;
			if(c1=='.') break;
			if(c1!='(') {std::cout<<"Greska, unesite ponovo!"<<std::endl; std::cin.clear(); std::cin.ignore(10000,'\n'); continue;}
			if(c1=='('){
				std::cin>>p_y;
				if(p_y<0 || p_y>br_polja-1) {std::cout<<"Greska, unesite ponovo!"<<std::endl; std::cin.ignore(10000,'\n'); continue;}
				std::cin>>c2;
				if(c2!=','){ std::cout<<"Greska, unesite ponovo!"<<std::endl; std::cin.ignore(10000,'\n'); continue;}
				if(c2==','){
					std::cin>>p_x;
					if(p_x<0 || p_x>br_polja-1){std::cout<<"Greska, unesite ponovo!"<<std::endl; std::cin.clear(); std::cin.ignore(10000,'\n'); continue;}
					std::cin>>c3;
					if(c3!=')') {std::cout<<"Greska, unesite ponovo!"<<std::endl; std::cin.clear(); std::cin.ignore(10000,'\n'); continue;}
						if(c3==')'){
							if(p_y!=0 || p_x!=0){
							pomocni.push_back(p_y);
							pomocni.push_back(p_x);
							mine.push_back(pomocni);
							pomocni.clear();}
							else continue;
					}
			}}
			else{
				std::cout<<"Greska, unesite ponovo!"<<std::endl;
			}
		}while(c1!='.');
	try{	
	polja=KreirajIgru(br_polja,mine);}
	catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what()<<std::endl;
	}
	}
	else if(komanda==Komande::ZavrsiIgru){
		for(int i(0);i<polja.size();i++){
			for(int j(0);j<polja.size();j++){
				polja[i][j]=Polje::Prazno;
			}
		}
		throw std::runtime_error ("Igra zavrsena");
	}
	else if(komanda==Komande::PomjeriJednoMjesto){try{
		Status a;
		a=Idi(polja,y,x,p_smjer);
		std::cout<<"Tekuca pozicija igraca je ("<<y<<","<<x<<")"<<std::endl;
		if(a==Status::KrajPobjeda) std::cout<<"Bravo, obisli ste sva sigurna polja"<<std::endl;
		if(a==Status::KrajPoraz) {
			std::cout<<"Nagazili ste na minu"<<std::endl;
			for(int i(0);i<polja.size();i++){
				for(int j(0);j<polja.size();j++){
					polja[i][j]=Polje::Prazno;
					}
				}
				throw std::runtime_error("Igra zavrsena");
			}
		}
		catch(std::logic_error izuzetak){
			std::cout<<izuzetak.what()<<std::endl;
		}
		catch(std::out_of_range izuzetak){
			std::cout<<izuzetak.what()<<std::endl;
		}
	}
	else if(komanda==Komande::PomjeriDalje){try{
		Status a;
		KodoviGresaka greska;
		a=Idi(polja,y,x,novay,novax);
		std::cout<<"Tekuca pozicija igraca je ("<<y<<","<<x<<")"<<std::endl;
		if(a==Status::KrajPobjeda) std::cout<<"Bravo, obisli ste sva sigurna polja"<<std::endl;
		if(a==Status::KrajPoraz){
			std::cout<<"Nagazili ste na minu"<<std::endl;
			for(int i(0);i<polja.size();i++){
				for(int j(0);j<polja.size();j++){
					polja[i][j]=Polje::Prazno;
				}
			}
			komanda=Komande::ZavrsiIgru;
			throw std::runtime_error("Igra zavrsena");
		}
		
	}
	catch(std::logic_error izuzetak){
		std::cout<<izuzetak.what()<<std::endl;
		}
	catch(std::out_of_range izuzetak){
		std::cout<<izuzetak.what()<<std::endl;
		}
	}
	else if(komanda==Komande::PrikaziOkolinu){
		Matrica matrica=PrikaziOkolinu(polja,y,x);
		for(int i(0);i<3;i++){
			for(int j(0);j<3;j++){
				std::cout<<matrica[i][j]<<" ";
			}
			std::cout<<std::endl;
		}
	}
}
/*void ispisiTablu(Tabla &polja){
	for(int i(0);i<polja.size();i++){
		for(int j(0);j<polja[i].size();j++){
			std::cout<<int(polja[i][j])<<" ";
		}
		std::cout<<std::endl;
	}
}*/

int main (){

	Tabla polja;
	Komande komanda;
	Smjerovi smjer;
	Smjerovi p_smjer;
	int p_y,p_x;
	KodoviGresaka greska;
	int x(0),y(0);
	do{
		
		bool opet=UnosKomande(komanda,smjer,y,x,greska);
		if(komanda==Komande::ZavrsiIgru) {std::cout<<"Dovidjenja!"; break;}
		try{
			if(opet==true) IzvrsiKomandu(komanda,polja,y,x,smjer,novay,novax);}
			catch(std::runtime_error izuzetak){std::cout<<izuzetak.what()<<std::endl; y=0; x=0; break;}
			//ispisiTablu(polja);
	}
	while(komanda!=Komande::ZavrsiIgru);

	return 0;
}


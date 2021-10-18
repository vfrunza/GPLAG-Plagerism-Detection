#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <sstream>
#include <cstdlib>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::domain_error;
using std::out_of_range;
using std::logic_error;
using std::string;

enum class Polje {
 Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};

typedef std::vector<std::vector<Polje>> Tabla;
typedef std::vector<Polje> VektorPolja;
typedef std::vector<std::vector<int>> VektorCijelih;

template <typename T> std::string PretvoriUString(T x) {
 std::ostringstream s; s << x; return s.str();
}

int toInt(string s){
    int rez(0);
    int stepen=1;
    for(int i=int(s.length()-1); i>=0; i--){
        rez+=(s.at(i)-'0') * stepen;
        stepen*=10;
    }
    return rez;
}

Tabla KreirajIgru(int n, const VektorCijelih &mine){ //Kreiramo tablu za igru
	Tabla igracaTabla(n,VektorPolja(n,Polje::Prazno));
	for(int i=0; i<mine.size(); i++){
		int prva_koord,druga_koord;
		if(mine[i].size()!=2) throw domain_error("Ilegalan format zadavanja mina");
		prva_koord=mine[i][0]; druga_koord=mine[i][1];
		if(prva_koord<0 or prva_koord>=n or druga_koord<0 or druga_koord>=n) throw domain_error("Ilegalne pozicije mina");
		igracaTabla[prva_koord][druga_koord]=Polje::Mina; //Postavi mine
	}
	return igracaTabla;
}

int IzbrojiMine(const Tabla &polja, int x, int y) {
	int broj_mina(0);
	for(int i=x-1; i<int(polja.size()); i++){
		if(i<0) continue;   //x je lijevi rub
		for(int j=y-1; j<int(polja.at(i).size()); j++){
			if(j<0) continue;	//y je lijevi rub
			if(i==x and j==y) continue;
			if(polja.at(i).at(j)==Polje::Mina) broj_mina++;
			if(j==y+1) break; //Nema potrebe dalje gledati
		}
		if(i==x+1) break;
	}
	return broj_mina;

}
VektorCijelih PrikaziOkolinu(const Tabla &polja, int x, int y){ //Prikazujemo okolinu
    VektorCijelih okolina;
	if(x<0 or x>=polja.size() or y<0 or y>=polja.size()) throw domain_error("Polje ("+PretvoriUString(x)+","+PretvoriUString(y)+") ne postoji");
	if(x==0 or x==polja.size()-1) okolina.resize(2); //Samo 2 reda ako je na vrhu ili dnu table
	else okolina.resize(3); // U svakom dr slucaju 3
	int brojac(0);
	for(int i=x-1; i<int(polja.size()); i++){
		if(i<0) continue;   //x je lijevi rub
		for(int j=y-1; j<int(polja.at(i).size()); j++){
			if(j<0) continue;					//y je lijevi rub
			okolina.at(brojac).push_back(IzbrojiMine(polja,i,j));
			if(j==y+1) break;
		}
		brojac++;
		if(i==x+1) break;
	}
	return okolina;
}

void BlokirajPolje(Tabla& polja, int x, int y){
	//U slucaju da je prazno "polja", vec na drugom uslovu ce se bacit izuzetak, tako da je polja[0] validno koristiti
	if(x<0 or x>=polja.size() or y<0 or y>=polja[0].size()) throw domain_error("Polje ("+PretvoriUString(x)+","+PretvoriUString(y)+") ne postoji");
	if(polja.at(x).at(y)>=Polje(3)) return;
	polja.at(x).at(y)=Polje(int(polja.at(x).at(y))+3);
}

void DeblokirajPolje(Tabla& polja, int x, int y){
	//U slucaju da je prazno "polja", vec na drugom uslovu ce se bacit izuzetak, tako da je polja[0] validno koristiti
	if(x<0 or x>=polja.size() or y<0 or y>=polja[0].size()) throw domain_error("Polje ("+PretvoriUString(x)+","+PretvoriUString(y)+") ne postoji");
	if(polja.at(x).at(y)<Polje(3)) return;
	polja.at(x).at(y)=Polje(int(polja.at(x).at(y))-3);
}

enum class Smjerovi {
 GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};

enum class Status {
 NijeKraj, KrajPoraz, KrajPobjeda
};


Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){

	switch(smjer){
		case Smjerovi::GoreLijevo :
			if(x-1<0 or y-1<0) throw out_of_range("Izlazak van igrace table");
			if(polja.at(x-1).at(y-1)>=Polje::BlokiranoPrazno) throw logic_error("Blokirano polje");
			polja.at(x).at(y)=Polje::Posjeceno;
			x--; y--; break;
		case Smjerovi::Gore:
		    if(x-1<0) throw out_of_range("Izlazak van igrace table");
		    if(polja.at(x-1).at(y)>=Polje::BlokiranoPrazno) throw logic_error("Blokirano polje");
		    polja.at(x).at(y)=Polje::Posjeceno;
		    x--; break;
		case Smjerovi::GoreDesno:
			if(x-1<0 or y+1>=polja.at(0).size()) throw out_of_range("Izlazak van igrace table");
			if(polja.at(x-1).at(y+1)>=Polje::BlokiranoPrazno) throw logic_error("Blokirano polje");
			polja.at(x).at(y)=Polje::Posjeceno;
			x--; y++; break;
		case Smjerovi::Desno:
			if(y+1>=polja.at(0).size()) throw out_of_range("Izlazak van igrace table");
			if(polja.at(x).at(y+1)>=Polje::BlokiranoPrazno) throw logic_error("Blokirano polje");
		    polja.at(x).at(y)=Polje::Posjeceno;
		    y++; break;
		case Smjerovi::DoljeDesno:
			if(x+1>=polja.size() or y+1>=polja.at(0).size()) throw out_of_range("Izlazak van igrace table");
			if(polja.at(x+1).at(y+1)>=Polje::BlokiranoPrazno) throw logic_error("Blokirano polje");
			polja.at(x).at(y)=Polje::Posjeceno;
			x++; y++; break;
		case Smjerovi::Dolje:
			if(x+1<0) throw out_of_range("Izlazak van igrace table");
			if(polja.at(x+1).at(y)>=Polje::BlokiranoPrazno) throw logic_error("Blokirano polje");
		    polja.at(x).at(y)=Polje::Posjeceno;
		    x++; break;
		case Smjerovi::DoljeLijevo:
			if(x+1>=polja.size() or y-1<0) throw out_of_range("Izlazak van igrace table");
			if(polja.at(x+1).at(y-1)>=Polje::BlokiranoPrazno) throw logic_error("Blokirano polje");
			polja.at(x).at(y)=Polje::Posjeceno;
			x++; y--; break;
		case Smjerovi::Lijevo:
			if(y-1<0) throw out_of_range("Izlazak van igrace table");
			if(polja.at(x).at(y-1)>=Polje::BlokiranoPrazno) throw logic_error("Blokirano polje");
		    polja.at(x).at(y)=Polje::Posjeceno;
		    y--; break;
	}
	if(polja.at(x).at(y)==Polje::Mina) return Status::KrajPoraz;
	else if(polja.at(x).at(y)==Polje::Prazno){
		bool pobjeda(true);
		for(int i=0; i<polja.size(); i++){
			for(int j=0; j<polja.at(i).size(); j++){
                if(i==x and j==y) continue;
				if(polja.at(i).at(j)==Polje::Prazno or polja.at(i).at(j)==Polje::BlokiranoPrazno)
                {	pobjeda=false;
                    break;
                }
                if(!pobjeda) break;
			}
		}
		if(pobjeda)
            return Status::KrajPobjeda;
	}
	return Status::NijeKraj;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	if(novi_x<0 or novi_x>=polja.size() or novi_y<0 or novi_y>=polja.at(0).size()) throw out_of_range("Izlazak van igrace table");
	if(polja.at(novi_x).at(novi_y)>=Polje::BlokiranoPrazno) throw logic_error("Blokirano polje");
	polja.at(x).at(y)=Polje::Posjeceno;
	x=novi_x; y=novi_y;
	if(polja.at(x).at(y)==Polje::Mina) return Status::KrajPoraz;
	if(polja.at(x).at(y)==Polje::Prazno or polja.at(x).at(y)==Polje::Posjeceno){ //U prvom trenutku kada se ocita da su sva posjecena, to je pobjeda ( Drugi uslov ako dodjemo na isto polje)
		bool pobjeda(true);
		for(int i=0; i<polja.size(); i++){
			for(int j=0; j<polja.at(i).size(); j++){
                if(i==x and j==y) continue;
				if(polja.at(i).at(j)==Polje::Prazno or polja.at(i).at(j)==Polje::BlokiranoPrazno)
                {	pobjeda=false;
                    break;
                }
			}
		}
		if(pobjeda)
            return Status::KrajPobjeda;
	}
	return Status::NijeKraj;
}

enum class KodoviGresaka {
 PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};

void PrijaviGresku(KodoviGresaka greska){
	switch(greska){
		case KodoviGresaka::PogresnaKomanda:
			cout<<"Nerazumljiva komanda!"<<endl;break;
		case KodoviGresaka::NedostajeParametar:
			cout<<"Komanda trazi parametar koji nije naveden!"<<endl; break;
		case KodoviGresaka::SuvisanParametar:
			cout<<"Zadan je suvisan parametar nakon komande!"<<endl; break;
		case KodoviGresaka::NeispravanParametar:
			cout<<"Parametar komande nije ispravan!"<<endl; break;
	}
}

enum class Komande {PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu,ZavrsiIgru, KreirajIgru};


bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska) {
	string unos;
	getline(cin,unos);
	for(int i=0; i<unos.length(); i++){
		if(unos.at(i)==' ') continue;
		switch(unos.at(i)){
			case 'P':{
			    i++;
				if(i==unos.length()) break; //Uneseno samo 'P', pogresna komadna
				if(unos.at(i)=='1'){  //P1 komanda
					i++;
					if(i==unos.length()){greska = KodoviGresaka::NedostajeParametar; return false;} //P1 bez parametra
					while(i<unos.length() and unos.at(i)==' ') i++; //Preskoci sve razmake
					if(i==unos.length()){greska = KodoviGresaka::NedostajeParametar; return false;} //P1 bez parametra
					switch(unos.at(i)){
						case 'G':
							i++;
							if(i==unos.size()){komanda=Komande::PomjeriJednoMjesto; smjer=Smjerovi::Gore; return true;}
							switch(unos.at(i)){
								case 'D':
								    i++;
									while(i<unos.length() and unos.at(i)==' ') i++; //Preskoci eventualne razmake
									if(i==unos.length()){komanda=Komande::PomjeriJednoMjesto; smjer=Smjerovi::GoreDesno; return true;} //P1 GD
									else {
										while(i!=unos.length()){
											if((unos.at(i)!='G' and unos.at(i)!='D' and unos.at(i)!=' ' and unos.at(i)!='L' and unos.at(i)!='o')){
												greska=KodoviGresaka::SuvisanParametar; return false;
											}
											else if(unos.at(i)=='o' and unos.at(i-1)!='D'){
												greska=KodoviGresaka::SuvisanParametar; return false;
											}
											i++;
										}
										greska=KodoviGresaka::SuvisanParametar; return false;
									}
								case 'L':
								    i++;
									if(i==unos.length()){komanda=Komande::PomjeriJednoMjesto; smjer=Smjerovi::GoreLijevo; return true;} //P1 GL
									else {
										while(i!=unos.length()){
											if((unos.at(i)!='G' and unos.at(i)!='D' and unos.at(i)!=' ' and unos.at(i)!='L' and unos.at(i)!='o')){
												greska=KodoviGresaka::SuvisanParametar; return false;
											}
											else if(unos.at(i)=='o' and unos.at(i-1)!='D'){
												greska=KodoviGresaka::SuvisanParametar; return false;
											}
											i++;
										}
										greska=KodoviGresaka::SuvisanParametar; return false;
									}
								case ' ':
									while(i<unos.length() and unos.at(i)==' ') i++; //Preskoci eventualne razmake
									if(i==unos.length()){komanda=Komande::PomjeriJednoMjesto; smjer=Smjerovi::Gore; return true;} //P1 G
									else{greska=KodoviGresaka::SuvisanParametar; return false;}
								default :
									greska=KodoviGresaka::NeispravanParametar; return false; //P1 G* neeki drugi znak
							}

						case 'D':
							i++;
							if(i==unos.length()){komanda = Komande::PomjeriJednoMjesto; smjer=Smjerovi::Desno; return true;}
							switch(unos.at(i)){
								case 'o':
									i++;
									if(i==unos.length()){komanda = Komande::PomjeriJednoMjesto; smjer=Smjerovi::Dolje; return true;}
									switch(unos.at(i)){
										case 'D':
										    i++;
											while(i<unos.length() and unos.at(i)==' ') i++; //Preskoci eventualne razmake
											if(i==unos.length()){komanda=Komande::PomjeriJednoMjesto; smjer=Smjerovi::DoljeDesno; return true;} //P1 DoD
											else {
												while(i!=unos.length()){
													if((unos.at(i)!='G' and unos.at(i)!='D' and unos.at(i)!=' ' and unos.at(i)!='L' and unos.at(i)!='o')){
														greska=KodoviGresaka::SuvisanParametar; return false;
													}
													else if(unos.at(i)=='o' and unos.at(i-1)!='D'){
														greska=KodoviGresaka::SuvisanParametar; return false;
													}
													i++;
												}
												greska=KodoviGresaka::SuvisanParametar; return false;
											}
										case 'L':
										    i++;
											if(i==unos.length()){komanda=Komande::PomjeriJednoMjesto; smjer=Smjerovi::DoljeLijevo; return true;} //P1 DoL
											else {
												while(i!=unos.length()){
													if((unos.at(i)!='G' and unos.at(i)!='D' and unos.at(i)!=' ' and unos.at(i)!='L' and unos.at(i)!='o')){
														greska=KodoviGresaka::SuvisanParametar; return false;
													}
													else if(unos.at(i)=='o' and unos.at(i-1)!='D'){
														greska=KodoviGresaka::SuvisanParametar; return false;
													}
													i++;
												}
												greska=KodoviGresaka::SuvisanParametar; return false;
											}
										case ' ':
											while(i<unos.length() and unos.at(i)==' ') i++; //Preskoci eventualne razmake
											if(i==unos.length()){komanda=Komande::PomjeriJednoMjesto; smjer=Smjerovi::Dolje; return true;} //P1 Do
											else{greska=KodoviGresaka::SuvisanParametar; return false;}
										default :
											greska=KodoviGresaka::NeispravanParametar; return false; //P1 Do* neeki drugi znak
									}
								case ' ':
									while(i<unos.length() and unos.at(i)==' ') i++; //Preskoci eventualne razmake
									if(i==unos.length()){komanda=Komande::PomjeriJednoMjesto; smjer=Smjerovi::Desno; return true;} //P1 D
									else{greska=KodoviGresaka::SuvisanParametar; return false;}
									
								default :
									greska=KodoviGresaka::NeispravanParametar; return false; //P1 D* neki suvisan aprametar
							}
						case 'L':
						    i++;
							if(i==unos.length()){komanda=Komande::PomjeriJednoMjesto; smjer=Smjerovi::Lijevo; return true;} //P1 L
							else {
								while(i!=unos.length()){
									if((unos.at(i)!='G' and unos.at(i)!='D' and unos.at(i)!=' ' and unos.at(i)!='L' and unos.at(i)!='o')){
										greska=KodoviGresaka::SuvisanParametar; return false;
									}
									else if(unos.at(i)=='o' and unos.at(i-1)!='D'){
										greska=KodoviGresaka::SuvisanParametar; return false;
									}
									i++;
								}
								greska=KodoviGresaka::SuvisanParametar; return false;
							}
						default:                                                    //P1 * neki drugi znak
							greska=KodoviGresaka::NeispravanParametar; return false;
					}

				}
				else if(unos.at(i)=='>') { //P> komanda
                    i++;
                    if(i==unos.length()){greska = KodoviGresaka::NedostajeParametar; return false;} //P> bez parametra
                    while(i<unos.length() and unos.at(i)==' ') i++; //Preskoci sve razmake
                    if(unos.at(i)>='0' and unos.at(i)<='9'){
                        int poc=i;
                        while(i<unos.length() and unos.at(i)>='0' and unos.at(i)<='9') i++;
                        if(i==unos.length()) {greska = KodoviGresaka::NedostajeParametar; return false;} //Samo jedan broj
                        if(unos.at(i)!=' '){greska = KodoviGresaka::NeispravanParametar; return false;} //Nije razmak poslije broja
                        int prvi=toInt(unos.substr(poc,i-poc));
                        while(i<unos.length() and unos.at(i)==' ') i++; //Preskoci sve razmake
                        if(i==unos.length()) {greska = KodoviGresaka::NedostajeParametar; return false;} //Samo jedan broj
                        if(!(unos.at(i)>='0' and unos.at(i)<='9')){greska = KodoviGresaka::NeispravanParametar; return false;}//Broj i pogr parametar
                        poc=i;
                        while(i<unos.length() and unos.at(i)>='0' and unos.at(i)<='9') i++;
                        if(i!=unos.length() and unos.at(i)!=' '){greska = KodoviGresaka::NeispravanParametar; return false;} //Nije razmak poslije broja a nije kraj
                        int drugi=toInt(unos.substr(poc,i-poc));
                        while(i<unos.length() and unos.at(i)==' ') i++; //Preskoci sve razmake
                        if(i!=unos.length() and (unos.at(i)<'0' or unos.at(i)>'9')) {greska = KodoviGresaka::NeispravanParametar; return false;}
                        if(i!=unos.length() and unos.at(i)>='0' and unos.at(i)<='9') {greska = KodoviGresaka::SuvisanParametar; return false;} //Treci broj
                        x=prvi; y=drugi;
                        komanda=Komande::PomjeriDalje; return true;
                    }
                    else{greska = KodoviGresaka::NeispravanParametar; return false;}
				}
				else if(unos.at(i)=='O') {
                    i++;
					while(i<unos.length() and unos.at(i)==' ') i++;
					if(i==unos.length()){komanda=Komande::PrikaziOkolinu; return true;}
					else{greska=KodoviGresaka::SuvisanParametar; return false;}
				}
				else{greska=KodoviGresaka::PogresnaKomanda; return false;} //ako je nesto drugo, treba otici na kraj petlje
			}
			case 'B':
			case 'D':{
			  char znak=unos.at(i);
			  i++;
                if(i==unos.length()){greska = KodoviGresaka::NedostajeParametar; return false;} //P> bez parametra
                while(i<unos.length() and unos.at(i)==' ') i++; //Preskoci sve razmake
                if(unos.at(i)>='0' and unos.at(i)<='9'){
                    int poc=i;
                    while(i<unos.length() and unos.at(i)>='0' and unos.at(i)<='9') i++;
                    if(i==unos.length()) {greska = KodoviGresaka::NedostajeParametar; return false;} //Samo jedan broj
                    if(unos.at(i)!=' '){greska = KodoviGresaka::NeispravanParametar; return false;} //Nije razmak poslije broja
                    int prvi=toInt(unos.substr(poc,i-poc));
                    while(i<unos.length() and unos.at(i)==' ') i++; //Preskoci sve razmake
                    if(i==unos.length()) {greska = KodoviGresaka::NedostajeParametar; return false;} //Samo jedan broj
                    if(!(unos.at(i)>='0' and unos.at(i)<='9')){greska = KodoviGresaka::NeispravanParametar; return false;}//Broj i pogr parametar
                    poc=i;
                    while(i<unos.length() and unos.at(i)>='0' and unos.at(i)<='9') i++;
                    if(i!=unos.length() and unos.at(i)!=' '){greska = KodoviGresaka::NeispravanParametar; return false;} //Nije razmak poslije broja a nije kraj
                    int drugi=toInt(unos.substr(poc,i-poc));
                    while(i<unos.length() and unos.at(i)==' ') i++; //Preskoci sve razmake
                    if(i!=unos.length() and (unos.at(i)<'0' or unos.at(i)>'9')) {greska = KodoviGresaka::NeispravanParametar; return false;}
                    if(i!=unos.length() and unos.at(i)>='0' and unos.at(i)<='9') {greska = KodoviGresaka::SuvisanParametar; return false;} //Treci broj
                    x=prvi; y=drugi;
                    if(znak=='B') komanda=Komande::Blokiraj;
                    else if(znak=='D') komanda=Komande::Deblokiraj;
                    return true;
                }
                else{greska = KodoviGresaka::NeispravanParametar; return false;}
			}
			case 'Z':
			case 'K':{
			    char znak=unos.at(i);
			    i++;
				while(i<unos.length() and unos.at(i)==' ') i++;
				if(i==unos.length()){
					if(znak=='Z')komanda=Komande::ZavrsiIgru;
					else if(znak=='K')komanda=Komande::KreirajIgru;
					return true;
                }
				else{greska=KodoviGresaka::SuvisanParametar; return false;}
			}
		}
	}
	greska = KodoviGresaka::PogresnaKomanda;
	return false;


}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0){
 	switch(komanda){
 	    case Komande::PomjeriDalje:
 		case Komande::PomjeriJednoMjesto:{
 		    Status status;
 		    if(komanda==Komande::PomjeriJednoMjesto) status=Idi(polja,x,y,p_smjer);
            else status=Idi(polja,x,y,p_x,p_y);
 			if(status==Status::KrajPobjeda){
                cout<<"Bravo, obisli ste sva sigurna polja"<<endl;
                for(auto &red: polja){
                    for(auto &el:red)
                        el=Polje::Prazno;
                }
                throw std::runtime_error("Igra zavrsena");
 			}
            else if(status==Status::KrajPoraz){
                cout<<"Nagazili ste na minu"<<endl;
                for(auto &red: polja){
                    for(auto &el:red)
                        el=Polje::Prazno;
                }
                throw std::runtime_error("Igra zavrsena");
            }
            else
                cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<endl;
            break;
 		}
 		case Komande::Blokiraj:{
 			BlokirajPolje(polja,p_x,p_y); break;
 		}
 		case Komande::Deblokiraj:{
 			DeblokirajPolje(polja,p_x,p_y); break;
 		}
 		case Komande::PrikaziOkolinu:{
 			VektorCijelih okolina (PrikaziOkolinu(polja,x,y));
 			for(auto red: okolina){
                for(auto el:red)
                    cout<<el<<" ";
                cout<<endl;
 			}
 			break;
 		}
 		case Komande::ZavrsiIgru:{
 		    for(auto &red: polja){
                for(auto &el:red)
                     el=Polje::Prazno;
 			}
 			throw std::runtime_error("Igra zavrsena");

 		}
 		case Komande::KreirajIgru:{
 		    cout<<"Unesite broj polja: ";
 		    int n;
 		    cin>>n;
 		    cin.ignore(1000,'\n');
 		    cout<<"Unesite pozicije mina: ";
 		    VektorCijelih mine;
 		    for(int brojac=0;;){
                try{
                    int i(0);
                    string unos;
                    getline(cin,unos);
                    unos.erase(remove(unos.begin(),unos.end(),' '),unos.end());
                    if(unos.at(i)=='.') break;
                    if(unos.at(i++)!= '(') throw std::domain_error("Greska");
                    while(unos.at(i)>='0' and unos.at(i)<='9') i++;
                    if(i==1 or unos.at(i)!=',') throw std::domain_error("Greska");
                    int prvi = toInt(unos.substr(1,i-1));
                    if(prvi>=n) throw std::domain_error("Greska");
                    i++; int poc=i;
                    while(unos.at(i)>='0' and unos.at(i)<='9') i++;
                    if(i==poc or unos.at(i)!=')') throw std::domain_error("Greska");
                    int drugi=toInt(unos.substr(poc,i-poc));
                    if(drugi>=n) throw std::domain_error("Greska");
                    i++;
                    if(i!=unos.length()) throw std::domain_error("Greska");
                    mine.resize(brojac+1);
                    mine.at(brojac).push_back(prvi); mine.at(brojac).push_back(drugi);
                    brojac++;
                }
                catch(...){
                    cout<<"Greska, unesite ponovo!"<<endl;
                }
 		    }
 		    polja=KreirajIgru(n,mine);
 		}
 	}
 }


int main ()
{
    Tabla tabla;
    Komande komanda;
    Smjerovi smjer;
    KodoviGresaka greska;
    int x(0),y(0), novi_x(0), novi_y(0);
    while(true){
        cout<<"Unesite komandu: ";
        try{
            if(UnosKomande(komanda,smjer,novi_x,novi_y,greska))
                IzvrsiKomandu(komanda,tabla,x,y,smjer,novi_x,novi_y);
            else{
                PrijaviGresku(greska);
            }
        }
        catch(std::runtime_error){
            cout<<"Dovidjenja!";
            break;

        }
        catch(std::domain_error e){
            cout<<e.what()<<endl;
        }
        catch(std::out_of_range e){
            cout<<e.what()<<endl;
        }
        catch(std::logic_error e){
            cout<<e.what()<<endl;
        }

    }
	return 0;
}



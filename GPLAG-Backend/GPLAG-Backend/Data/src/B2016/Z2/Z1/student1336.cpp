/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <complex>

enum class Polje {
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};


typedef std::vector<std::vector<Polje>> Tabla;


Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	
	for(int i(0); i<int(mine.size()); i++){
		if(int(mine.at(i).size())!=2) throw std::domain_error("Ilegalan format zadavanja mina");
		for(int j(0); j<int(mine.at(i).size()); j++){
			if(mine.at(i).at(j)>n-1 || n-1<0) throw std::domain_error("Ilegalne pozicije mina");
		}
	}
	
	Tabla tab(n);
	
	for(int i(0); i<n; i++){
		for(int j(0); j<n; j++){
			bool nijeupisano(true);
			for(int k(0); k<int(mine.size()); k++){
				if(mine.at(k).at(0)==i && mine.at(k).at(1)==j ) {
					tab.at(i).push_back(Polje::Mina);
					nijeupisano=false;
				}
			}
		if(nijeupisano) tab.at(i).push_back(Polje::Prazno);
		}
	}
	
	return tab;
}

void BacanjeIzuzetka (const Tabla &polja, int x, int y){
	
	std::string s("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	if( x>int(polja.size())-1 || x<0 || y<0 ) throw std::domain_error (s);
	for(int i(0); i<int(polja.size()); i++ ){
		if( y>int(polja.at(i).size())-1  ) throw std::domain_error (s);
	}
}

void BlokirajPolje(Tabla &polja, int x, int y){
	
	try {
		BacanjeIzuzetka(polja, x, y);
	}
	catch(...){
		throw;
	}
	
	for(int i(0); i<int(polja.size()); i++){
		for(int j(0); j<int(polja.at(i).size()); j++ ){
			if(i==x && j==y){
				if(polja.at(i).at(j)==Polje::Prazno) polja.at(i).at(j)=Polje::BlokiranoPrazno;
				if(polja.at(i).at(j)==Polje::Posjeceno) polja.at(i).at(j)=Polje::BlokiranoPosjeceno;
				if(polja.at(i).at(j)==Polje::Mina) polja.at(i).at(j)=Polje::BlokiranoMina;
			}
		}
	}
	
}

void DeblokirajPolje(Tabla &polja, int x, int y){
	
	try {
		BacanjeIzuzetka(polja, x, y);
	}
	catch(...){
		throw;
	}
	
	for(int i(0); i<int(polja.size()); i++){
		for(int j(0); j<int(polja.at(i).size()); j++ ){
			if(i==x && j==y){
				if(polja.at(i).at(j)==Polje::BlokiranoPrazno) polja.at(i).at(j)=Polje::Prazno;
				if(polja.at(i).at(j)==Polje::BlokiranoPosjeceno) polja.at(i).at(j)=Polje::Posjeceno;
				if(polja.at(i).at(j)==Polje::BlokiranoMina) polja.at(i).at(j)=Polje::Mina;
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

void Pomjeri(Tabla &polja, int &x, int &y, int i, int j){

	if(int(polja.size())==0) throw std::out_of_range ("Izlazak van igrace table");
	
	int red(int(polja.size())), kolona(int(polja.at(0).size()));

	if(x+i<0 || x+i>=red || y+j<0 || y+j>=kolona) throw std::out_of_range ("Izlazak van igrace table");
	
	if(polja.at(x+i).at(y+j)==Polje::BlokiranoPrazno || polja.at(x+i).at(y+j)==Polje::BlokiranoPosjeceno || polja.at(x+i).at(y+j)==Polje::BlokiranoMina ) throw std::logic_error ("Blokirano polje");
	polja.at(x).at(y)=Polje::Posjeceno;
	x=x+i;
	y=y+j;
	
}

Status DaLiJeKraj(Tabla &polja, int &x, int &y ){
	
	if(polja.at(x).at(y)==Polje::Mina) return Status::KrajPoraz;
	
	for(int i(0); i<int(polja.size()); i++){
		for(int j(0); j<int(polja.at(i).size()); j++){
			if( (polja.at(i).at(j)==Polje::Mina || polja.at(i).at(j)==Polje::Posjeceno || (x==i && y==j))==false ) return Status::NijeKraj;
		}
	}
	return Status::KrajPobjeda;
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	try{
		
		if(smjer==Smjerovi::GoreLijevo) Pomjeri(polja, x, y, -1, -1);
		else if(smjer==Smjerovi::Gore) Pomjeri(polja, x, y, -1, 0);
		else if(smjer==Smjerovi::GoreDesno) Pomjeri(polja, x, y, -1, 1);
		else if(smjer==Smjerovi::Desno) Pomjeri(polja, x, y, 0, 1);
		else if(smjer==Smjerovi::DoljeDesno) Pomjeri(polja, x, y, 1, 1);
		else if(smjer==Smjerovi::Dolje) Pomjeri(polja, x, y, 1, 0);
		else if(smjer==Smjerovi::DoljeLijevo) Pomjeri(polja, x, y, 1, -1);
		else if(smjer==Smjerovi::Lijevo) Pomjeri(polja,x, y, 0, -1);
		
	}
	catch(...){
		throw;
	}
	return DaLiJeKraj(polja,x,y);
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	
	if( int(polja.size())==0 ) throw std::out_of_range ("Izlazak van igrace table");
	if(novi_x<0 || int(polja.size())<=novi_x || novi_y<0 || int(polja.at(0).size())<=novi_y ) throw std::out_of_range("Izlazak van igrace table");
	
	if(polja.at(novi_x).at(novi_y)==Polje::BlokiranoPrazno || polja.at(novi_x).at(novi_y)==Polje::BlokiranoPosjeceno || polja.at(novi_x).at(novi_y)==Polje::BlokiranoMina  ) throw std::logic_error ("Blokirano polje");
	
	x=novi_x;
	y=novi_y;
	
	return DaLiJeKraj(polja,x,y);
}

int OkolinaTacke(const Tabla &polja, int x, int y){
	int suma(0);
	for(int i(-1); i<=1; i++){
		for(int j(-1); j<=1; j++ ){
			if(i==0 && j==0) continue;
			if( x+i>=0 && y+j>=0 && (x+i)<int(polja.size()) && (y+j)<int(polja.at(0).size()) ){
				if(polja.at(x+i).at(y+j)==Polje::Mina) suma=suma+1;
			}
		}
	}
	return suma;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	
	try {
		BacanjeIzuzetka(polja, x, y);
	}
	catch(...){
		throw;
	}
	
	std::vector<std::vector<int>> okolina(3, std::vector<int> (3));
	for(int i(-1), m(0); i<=1 && m<3; i++, m++){
		for(int j(-1), n(0); j<=1 && n<3; j++, n++ ){
			okolina.at(m).at(n)=OkolinaTacke(polja, x+i, y+j);
		}
	}
	
	return okolina;
}

enum class KodoviGresaka {
	PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};

void PrijaviGresku (KodoviGresaka kod){
	if(kod==KodoviGresaka::PogresnaKomanda ) std::cout<<"Nerazumljiva komanda!"<<std::endl;
	if(kod==KodoviGresaka::NedostajeParametar) std::cout<<"Komanda trazi parametar koji nije naveden!"<<std::endl;
	if(kod==KodoviGresaka::NeispravanParametar) std::cout<<"Parametar komande nije ispravan!"<<std::endl;
	if(kod==KodoviGresaka::SuvisanParametar) std::cout<<"Zadan je suvisan parametar nakon komande!"<<std::endl;
}

enum class Komande {
	PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};

bool ParametarJeSuvisan(std::string &s, int i, KodoviGresaka &greska){
	while(i<int(s.size())) {
		if(s.at(i)!=' ') {
			greska=KodoviGresaka::SuvisanParametar;
			return true;
		}
		i++;
	}
	return false;
}

bool ParametarJeNeispravan(std::string &s, int i, KodoviGresaka &greska){
	while(i<int(s.size())){
		if(s.at(i)!=' '){
			greska=KodoviGresaka::NeispravanParametar;
			return true;
		}
		i++;
	}
	return false;
}

bool ParametarNedostaje(std::string &s, int i, KodoviGresaka &greska){
	while(i<int(s.size())){
		if(s.at(i)!=' ')
		i++;
	}
	return true;
}

bool UnosKomande (Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	
	
	std::string s;
	std::getline(std::cin, s);
	
	
	if(int(s.size())==0) {
		greska=KodoviGresaka::PogresnaKomanda;
	}
	int i(0);
	while(s.at(i)==' ') {
		i++;
		if(i>=int(s.size())){	greska=KodoviGresaka::PogresnaKomanda;	return false;	}
	}
	if( s.at(i)!='P' && s.at(i)!='B' && s.at(i)!='D' && s.at(i)!='Z' && s.at(i)!='K' ){ greska=KodoviGresaka::PogresnaKomanda;	return false; }
		
		
		
		if(s.at(i)=='P'){
			i++;
			if(i>=int(s.size())) { greska=KodoviGresaka::PogresnaKomanda; return false; }
			
			if( s.at(i)!='1' && s.at(i)!='>' && s.at(i)!='O' ){ greska=KodoviGresaka::PogresnaKomanda; return false;	}
			
				if(s.at(i)=='O'){
					i++;
					if(ParametarJeSuvisan(s,i,greska)) return false;
					komanda=Komande::PrikaziOkolinu; return true;
				}
			
				if(s.at(i)=='1'){
					i++;
					while(i<int(s.size()) && s.at(i)==' ' ){
						i++;
					}
					if(i>=int(s.size())){ greska=KodoviGresaka::NedostajeParametar; return false; }
					if(s.at(i)!='G' && s.at(i)!='D' && s.at(i)!='L') { greska=KodoviGresaka::NeispravanParametar; return false; }
					
					if(s.at(i)=='G'){
						i++;
						if(i>=int(s.size())) { komanda=Komande::PomjeriJednoMjesto; smjer=Smjerovi::Gore; return true; }
						if(s.at(i)=='L') {
							i++;
							if(ParametarJeSuvisan(s,i,greska)) return false;
							komanda=Komande::PomjeriJednoMjesto; smjer=Smjerovi::GoreLijevo; return true;
						}
						if(s.at(i)=='D') {
							i++;
							if(ParametarJeSuvisan(s,i,greska)) return false;
							komanda=Komande::PomjeriJednoMjesto; smjer=Smjerovi::GoreDesno; return true;
						}
						if(ParametarJeNeispravan(s,i,greska)) return false;
						komanda=Komande::PomjeriJednoMjesto; smjer=Smjerovi::Gore; return true;
					}
					if(s.at(i)=='D'){
						i++;
						if(i>=int(s.size())) {komanda=Komande::PomjeriJednoMjesto; smjer=Smjerovi::Desno; return true;}
						if(s.at(i)=='o'){
							i++;
							if(i>=int(s.size())){komanda=Komande::PomjeriJednoMjesto; smjer=Smjerovi::Dolje; return true;}
							if(s.at(i)=='D'){
								i++;
								if(ParametarJeSuvisan(s,i,greska)) return false;
								komanda=Komande::PomjeriJednoMjesto; smjer=Smjerovi::DoljeDesno; return true;
							}
							if(s.at(i)=='L'){
								i++;
								if(ParametarJeSuvisan(s,i,greska)) return false;
								komanda=Komande::PomjeriJednoMjesto; smjer=Smjerovi::DoljeLijevo; return true;
							}
							if(ParametarJeNeispravan(s,i,greska)) return false;
							komanda=Komande::PomjeriJednoMjesto; smjer=Smjerovi::Gore; return true;
						}
					}
					if(s.at(i)=='L'){
						if(ParametarJeSuvisan(s,i,greska)) return false;
						komanda=Komande::PomjeriJednoMjesto; smjer=Smjerovi::Lijevo; return true;
					}
					
				}
				
				if(s.at(i)=='>'){
					i++;
					while(i!=int(s.size()) && s.at(i)==' ') i++;
					if(i>=int(s.size())) {greska=KodoviGresaka::NedostajeParametar; return false;}
					if((s.at(i)>='0' && s.at(i)<='9')==false) {greska=KodoviGresaka::NeispravanParametar; return false;}
					
						int br(0), prx, pry;
						while(s.at(i)>='0' && s.at(i)<='9' && i<int(s.size())){ i++; br++;}
						if(i>=int(s.size())) {greska=KodoviGresaka::NedostajeParametar; return false;}
						if(s.at(i)!=' ') {greska=KodoviGresaka::NeispravanParametar; return false;}
						prx=std::stoi(s.substr(i-br,i));
						while(s.at(i)==' ' && i<int(s.size()) ) i++;
						if(i>=int(s.size())) {greska=KodoviGresaka::NedostajeParametar; return false;}
						if((s.at(i)>='0' && s.at(i)<='9')==false) {greska=KodoviGresaka::NeispravanParametar; return false;}
						br=0;
						while(s.at(i)>='0' && s.at(i)<='9' && i<int(s.size())) {i++;br++;}
						if(i>=int(s.size())){
							i--; br--;
							pry=std::stoi(s.substr(i-br,i));
							komanda=Komande::PomjeriDalje; x=prx; y=pry; return true;
						}
						if(s.at(i)!=' ') {greska=KodoviGresaka::SuvisanParametar; return false;}
						int p(i);
						while(s.at(i)==' ' && i<int(s.size())) i++;
						if(i>=int(s.size())){
							p--; br--; 
							pry=std::stoi(s.substr(i-br,i));
							komanda=Komande::PomjeriDalje; x=prx; y=pry; return true;
						}
						greska=KodoviGresaka::SuvisanParametar; return false;
				}
				
					
			
		}
		if(s.at(i)=='Z'){
			while(i<int(s.size())){
				i++;
				if(i>=int(s.size())) { komanda=Komande::ZavrsiIgru; return true; }
				if(s.at(i)!=' '){ greska=KodoviGresaka::SuvisanParametar; return false; }
			}
		}
		if(s.at(i)=='K'){
			while(i<int(s.size())){
				i++;
				if(i>=int(s.size())){ komanda=Komande::KreirajIgru; return true; }
				if(s.at(i)!=' ') { greska=KodoviGresaka::SuvisanParametar; return false; }
			}
		}
	
	return false;
}



void KakoDalje (Status trenutno, Komande &komanda){
	if(trenutno==Status::KrajPobjeda){
		std::cout<<"Bravo obisli ste sva sigurna polja"<<std::endl;
		komanda=Komande::ZavrsiIgru;
	}
	if(trenutno==Status::KrajPoraz){
		std::cout<<"Nagazili ste na minu"<<std::endl;
		komanda=Komande::ZavrsiIgru;
	}
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer=Smjerovi::Gore, int p_x=0, int p_y=0){
	
	try{
		if(komanda==Komande::PomjeriJednoMjesto) {
			Status trenutno(Idi(polja, x, y, p_smjer));
			std::cout<<"Tekuca pozicija igraca je ("<<std::to_string(x)<<","<<std::to_string(y)<<")"<<std::endl;
			KakoDalje(trenutno, komanda);
		}
		if(komanda==Komande::PomjeriDalje) {
			Status trenutno(Idi(polja, x, y, p_x,p_y));
			std::cout<<"Tekuca pozicija igraca je ("<<std::to_string(x)<<","<<std::to_string(y)<<")"<<std::endl;
			KakoDalje(trenutno, komanda);
		}
		if(komanda==Komande::Blokiraj) BlokirajPolje(polja,x,y);
		if(komanda==Komande::Deblokiraj) DeblokirajPolje(polja,x,y);
		if(komanda==Komande::PrikaziOkolinu) {
			std::vector<std::vector<int>> mat;
			mat=PrikaziOkolinu(polja, x, y);
			for(int i(0); i<int(mat.size()); i++ ){
				for(int j(0); j<int(mat.at(i).size()); j++){
					if(j<int(mat.at(i).size())-1 ) std::cout<<mat.at(i).at(j)<<" ";
					else std::cout<<mat.at(i).at(j);
				}
				std::cout<<std::endl;
			}
		}
		if(komanda==Komande::ZavrsiIgru) {
			for(int i(0); i<int(polja.size()); i++){
				for(int j(0); j<int(polja.at(i).size()); j++ ){
					polja.at(i).at(j)=Polje::Prazno;
				}
			}
			throw std::runtime_error ("Igra Zavrsena");
		}
		if(komanda==Komande::KreirajIgru) {
			int n;
			std::cout<<"Unesite broj polja: ";
			std::cin>>n;
			
			std::cout<<"Unesite pozicije mina: ";
			std::complex<int> koordinata;
			
			std::vector<std::vector<int>> v;
			int b(0);
			for(;;){
				bool tacka(false);
				std::cin>>koordinata;
				while(!std::cin || koordinata.real()>=5 || koordinata.real()<0 || koordinata.imag()<0 || koordinata.imag()>=5  ){
					
					if(std::cin.peek()=='.' ){
						std::cin.clear();
						std::cin.ignore(1000,'\n');
						tacka=true;
					}
					if(tacka) break;
					std::cout<<"Greska, unesite ponovo!"<<std::endl;
					std::cin.clear();
					std::cin.ignore(1000,'\n');
					std::cin>>koordinata;
				}
				if(tacka) break;
				
				v.push_back({}); 
				v.at(b).push_back(koordinata.real()); 
				v.at(b).push_back(koordinata.imag());
				b++;
			}
			polja=KreirajIgru(n,v);
		}
	}
	catch(std::out_of_range izuzetak){
		std::cout<<izuzetak.what()<<std::endl;
	}
	catch(std::logic_error izuzetak){
		std::cout<<izuzetak.what()<<std::endl;
	}
	catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what()<<std::endl;
	}
	catch(std::runtime_error izuzetak){
		throw izuzetak;
	}
	
}


int main ()
{
	Komande komanda;
	Tabla polja;
	int x(0);
	int y(0);
	Smjerovi smjer;
	KodoviGresaka greska;
	for(;;){
	
		try{
			
			std::cout<<"Unesi Komandu: ";
			if(UnosKomande(komanda,smjer,x,y,greska)){
				IzvrsiKomandu(komanda,polja,x,y,smjer);
			}
			else (PrijaviGresku(greska));
		}
		catch(std::runtime_error){
			for(int i(0); i<int(polja.size()); i++){
				for(int j(0); j<int(polja.size()); j++) polja.at(i).at(j)=Polje::Prazno;
			}
			std::cout<<"Dovidjena: ";
			break;
		}
	}
	
	return 0;
}
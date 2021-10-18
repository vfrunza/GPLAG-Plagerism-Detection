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
#include <string>
#include <sstream>

template <typename T> std::string PretvoriUstring(T x){
	std::ostringstream s; s<<x; return s.str();
}
enum class Polje {
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};

enum class Smjerovi {
	GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};

enum class Status{
	NijeKraj, KrajPoraz, KrajPobjeda
};

enum class KodoviGresaka{
	PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};

enum class Komande{
	PomjeriJednoMjesto, PomjeriDalje, Blokiraj , Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	if(n<=0) throw std::domain_error ("Ilegalna velicina");
	for(int i=0 ; i<mine.size() ; i++){
		if(mine.at(i).size()!=2) throw std::domain_error ("Ilegalan format zadavanja mina");
		for(int j=0 ; j<2 ; j++){
			if(mine.at(i).at(j)>=n || mine.at(i).at(j)<0) throw std::domain_error ("Ilegalne pozicije mina");
		}
	}
	Tabla t(n,std::vector<Polje> (n,Polje::Prazno));
	
	for(int i=0 ; i<mine.size() ; i++){
		t.at(mine.at(i).at(0)).at(mine.at(i).at(1))=Polje::Mina;
	}
	
	return t;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x , int y){
	if(x<0 || y<0 || x>=polja.size() || y>=polja.size()) throw std::domain_error ("Polje (" + PretvoriUstring(x) + "," + PretvoriUstring(y) + ") ne postoji");
	std::vector<std::vector<int>> m(3,std::vector<int>(3));
	int a(0);
	for(int i=x-1 ; i<=x+1 ; i++){
		int b(0);
		for(int j=y-1 ; j<=y+1 ; j++){
			int br(0);
			for(int k=i-1 ; k<=i+1 ; k++){
				for(int l=j-1 ; l<=j+1 ; l++){
					if(k>=0 && k<int(polja.size()) && l>=0 && l<int(polja.size()) && !(k==i && l==j) && (polja.at(k).at(l)==Polje::Mina || polja.at(k).at(l)==Polje::BlokiranoMina)) br++;
				}
			}
		m.at(a).at(b)=br;
		b++;
		}
		a++;
	}
	return m;
}

void BlokirajPolje(Tabla &polja, int x, int y){
	if(x<0 || y<0 || x>=polja.size() || y>=polja.size()) throw std::domain_error ("Polje (" + PretvoriUstring(x) + "," + PretvoriUstring(y) + ") ne postoji");
	if(polja.at(x).at(y)==Polje::Posjeceno) polja.at(x).at(y)=Polje::BlokiranoPosjeceno;
	if(polja.at(x).at(y)==Polje::Prazno) polja.at(x).at(y)=Polje::BlokiranoPrazno;
	if(polja.at(x).at(y)==Polje::Mina) polja.at(x).at(y)=Polje::BlokiranoMina;
}

void DeblokirajPolje(Tabla &polja, int x, int y){
	if(x<0 || y<0 || x>=polja.size() || y>=polja.size()) throw std::domain_error ("Polje (" + PretvoriUstring(x) + "," + PretvoriUstring(y) + ") ne postoji");
	if(polja.at(x).at(y)==Polje::BlokiranoPosjeceno) polja.at(x).at(y)=Polje::Posjeceno;
	if(polja.at(x).at(y)==Polje::BlokiranoPrazno) polja.at(x).at(y)=Polje::Prazno;
	if(polja.at(x).at(y)==Polje::BlokiranoMina) polja.at(x).at(y)=Polje::Mina;
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	
	polja.at(x).at(y)=Polje::Posjeceno;
	if(smjer==Smjerovi::Gore) x--;
	if(smjer==Smjerovi::GoreDesno) { x--; y++; }
	if(smjer==Smjerovi::GoreLijevo) { x--; y--; }
	if(smjer==Smjerovi::Lijevo) y--;
	if(smjer==Smjerovi::Desno) y++;
	if(smjer==Smjerovi::Dolje) x++;
	if(smjer==Smjerovi::DoljeDesno) { x++; y++; }
	if(smjer==Smjerovi::DoljeLijevo) { x++; y--;}
	if(x<0 || x>=int(polja.size()) || y<0 || y>=int(polja.size()))throw std::out_of_range ("Izlazak van igrace table");
	if(polja.at(x).at(y)==Polje::BlokiranoPosjeceno || polja.at(x).at(y)==Polje::BlokiranoPrazno || polja.at(x).at(y)==Polje::BlokiranoMina) throw std::logic_error ("Blokirano polje");
	
	
	if(polja.at(x).at(y)==Polje::Mina) {
		for(int i=0 ; i<polja.size() ; i++){
			for(int j=0 ; j<polja.size() ; j++) polja.at(x).at(y)=Polje::Prazno;
		}
	    return Status::KrajPoraz;
		
	}
	bool t(true);
	for(int i=0 ; i<polja.size() ; i++){
		for(int j=0 ; j<polja.size() ; j++){
			if(polja.at(x).at(y)!=Polje::Prazno){ 
				t=false; break; 
			 }
		}
	}
	if(t==true) return Status::KrajPobjeda;
	else return Status::NijeKraj;
		
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	if(novi_x<0 || novi_x>=polja.size() || novi_y<0 || novi_y>=polja.size()) throw std::out_of_range ("Izlazak van igrace table");
	polja.at(x).at(y)=Polje::Posjeceno;
	x=novi_x;
	y=novi_y;
	if(polja.at(x).at(y)==Polje::BlokiranoPosjeceno || polja.at(x).at(y)==Polje::BlokiranoPrazno || polja.at(x).at(y)==Polje::BlokiranoMina) throw std::logic_error ("Blokirano polje");
	
	if(polja.at(x).at(y)==Polje::Mina) {
		for(int i=0 ; i<polja.size() ; i++){
			for(int j=0 ; j<polja.size() ; j++) polja.at(x).at(y)=Polje::Prazno;
		}
	    return Status::KrajPoraz;
		
	}
	bool t(false);
	for(int i=0 ; i<polja.size() ; i++){
		for(int j=0 ; j<polja.size() ; j++){
			if(polja.at(x).at(y)==Polje::Prazno){ 
				t=true; break; 
			 }
		}
	}
	if(t==true) return Status::NijeKraj;
	else return Status::KrajPobjeda;
}

void PrijaviGresku( KodoviGresaka k){
	if(k==KodoviGresaka::PogresnaKomanda) std::cout<<"Nerazumljiva komanda!"<<std::endl;
	if(k==KodoviGresaka::NedostajeParametar) std::cout<<"Komanda trazi parametar koji nije naveden!"<<std::endl;
	if(k==KodoviGresaka::SuvisanParametar) std::cout<<"Zadan je suvisan parametar nakon komande!"<<std::endl;
	if(k==KodoviGresaka::NeispravanParametar) std::cout<<"Parametar komande nije ispravan!"<<std::endl;
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	bool t(true);
	std::string s;
	std::getline(std::cin,s);
	int duz(s.length());
	int i(0);
	while(i<duz || s.at(i)==' ') i++;
	if(i==duz || (s.at(i)!='P' && s.at(i)!='B' && s.at(i)!='D' && s.at(i)!='Z' && s.at(i)!='K')) { greska=KodoviGresaka::PogresnaKomanda; t=false; return t; }
	
	if(s.at(i)=='P'){
		i++;
		if(i==duz || (s.at(i)!='1' && s.at(i)!='>' && s.at(i)!='O')) { greska=KodoviGresaka::PogresnaKomanda; t=false; return t; }
		
		if(s.at(i)=='1'){
			komanda=Komande::PomjeriJednoMjesto;
			i++;
			while(i<duz || s.at(i)==' ') i++;
			if(i==duz || !(s.at(i)>='A' && s.at(i)<='Z')){ greska=KodoviGresaka::NedostajeParametar; t=false; return t; }
			
			std::string pomocni;
			while((s.at(i)>='A' && s.at(i)<='Z') ||(s.at(i)>='a' && s.at(i)<='z')) { pomocni.push_back(s.at(i)); i++; }
				while(i<duz ){
					if(i!=' ') { greska=KodoviGresaka::SuvisanParametar; t=false; return t;}
					i++;
				}
			if(i==duz){
				if(pomocni=="GL") smjer=Smjerovi::GoreLijevo;
				else if(pomocni==std::string("G")) smjer=Smjerovi::Gore;
				else if(pomocni=="GD") smjer=Smjerovi::GoreDesno;
				else if(pomocni=="D") smjer=Smjerovi::Desno;
				else if(pomocni=="DoD") smjer=Smjerovi::DoljeDesno;
				else if(pomocni=="Do") smjer=Smjerovi::Dolje;
				else if(pomocni=="DoL") smjer=Smjerovi::DoljeLijevo;
				else if(pomocni=="L") smjer=Smjerovi::Lijevo;
				else { greska=KodoviGresaka::PogresnaKomanda; t=false; return t;}
			}
		}
		
		if(s.at(i)=='>'){
			komanda=Komande::PomjeriDalje;
			i++;
			while(i<duz || s.at(i)==' ') i++;
			if(i==duz){ greska=KodoviGresaka::NedostajeParametar; t=false; return t; }
			if(!(s.at(i)>='0' && s.at(i)<='9')) { greska=KodoviGresaka::PogresnaKomanda; t=false; return t; }
			int broj(0),j(1);
			while(s.at(i)>='0' && s.at(i)<='9') i++;
			i--;
			while(s.at(i)>='0' && s.at(i)<='9'){
				 broj=broj+(s.at(i)*j); 
				i--;
				j *=10;
			}
			x=broj;
			broj=0; j=1;
			while(s.at(i)>='0' && s.at(i)<='9') i++;
			while(i<duz || s.at(i)==' ') i++;
			if(i==duz){ greska=KodoviGresaka::NedostajeParametar; t=false; return t; }
			if(!(s.at(i)>='0' && s.at(i)<='9')) { greska=KodoviGresaka::PogresnaKomanda; t=false; return t; }
			while(s.at(i)>='0' && s.at(i)<='9') i++;
			i--;
			while(s.at(i)>='0' && s.at(i)<='9'){
				 broj=broj+(s.at(i)*j); 
				i--;
				j *=10;
			}
			y=broj;
			while(s.at(i)>='0' && s.at(i)<='9') i++;
			while(i<duz || i==' ') {
				i++;
				if(i!=' ') { greska=KodoviGresaka::SuvisanParametar; t=false; return t; }
			}
		}
		
		if(s.at(i)=='O'){
			komanda=Komande::PrikaziOkolinu;
				while(i<duz || i==' ') {
					i++;
					if(i!=' ') { greska=KodoviGresaka::SuvisanParametar; t=false; return t;}
					}
		}
	} 
	
	if(s.at(i)=='B'){
			komanda=Komande::Blokiraj;
			i++;
			while(i<duz || s.at(i)==' ') i++;
			if(i==duz){ greska=KodoviGresaka::NedostajeParametar; t=false; return t; }
			if(!(s.at(i)>='0' && s.at(i)<='9')) { greska=KodoviGresaka::PogresnaKomanda; t=false; return t; }
			int broj(0),j(1);
			while(s.at(i)>='0' && s.at(i)<='9') i++;
			i--;
			while(s.at(i)>='0' && s.at(i)<='9'){
				 broj=broj+(s.at(i)*j); 
				i--;
				j *=10;
			}
			x=broj;
			broj=0; j=1;
			while(s.at(i)>='0' && s.at(i)<='9') i++;
			while(i<duz || s.at(i)==' ') i++;
			if(i==duz){ greska=KodoviGresaka::NedostajeParametar; t=false; return t; }
			if(!(s.at(i)>='0' && s.at(i)<='9')) { greska=KodoviGresaka::PogresnaKomanda; t=false; return t; }
			while(s.at(i)>='0' && s.at(i)<='9') i++;
			i--;
			while(s.at(i)>='0' && s.at(i)<='9'){
				 broj=broj+(s.at(i)*j); 
				i--;
				j *=10;
			}
			y=broj;
			while(s.at(i)>='0' && s.at(i)<='9') i++;
			while(i<duz || i==' ') {
				i++;
				if(i!=' ') { greska=KodoviGresaka::SuvisanParametar; t=false; return t; }
			}
		}
		
		if(s.at(i)=='D'){
			komanda=Komande::Deblokiraj;
			i++;
			while(i<duz || s.at(i)==' ') i++;
			if(i==duz){ greska=KodoviGresaka::NedostajeParametar; t=false; return t; }
			if(!(s.at(i)>='0' && s.at(i)<='9')) { greska=KodoviGresaka::PogresnaKomanda; t=false; return t; }
			int broj(0),j(1);
			while(s.at(i)>='0' && s.at(i)<='9') i++;
			i--;
			while(s.at(i)>='0' && s.at(i)<='9'){
				 broj=broj+(s.at(i)*j); 
				i--;
				j *=10;
			}
			x=broj;
			broj=0; j=1;
			while(s.at(i)>='0' && s.at(i)<='9') i++;
			while(i<duz || s.at(i)==' ') i++;
			if(i==duz){ greska=KodoviGresaka::NedostajeParametar; t=false; return t; }
			if(!(s.at(i)>='0' && s.at(i)<='9')) { greska=KodoviGresaka::PogresnaKomanda; t=false; return t; }
			while(s.at(i)>='0' && s.at(i)<='9') i++;
			i--;
			while(s.at(i)>='0' && s.at(i)<='9'){
				 broj=broj+(s.at(i)*j); 
				i--;
				j *=10;
			}
			y=broj;
			while(s.at(i)>='0' && s.at(i)<='9') i++;
			while(i<duz || i==' ') {
				i++;
				if(i!=' ') { greska=KodoviGresaka::SuvisanParametar; t=false; return t; }
			}
		}
		
		
	
	if(s.at(i)=='K') {
		komanda=Komande::KreirajIgru; 
			while(i<duz ) {
				i++;
				if(i!=' ') { greska=KodoviGresaka::SuvisanParametar; t=false; return t; }
			}
			
	}
	if(s.at(i)=='Z') {
		komanda=Komande::ZavrsiIgru; 
			while(i<duz || i==' ') {
				i++;
				if(i!=' '){ greska=KodoviGresaka::SuvisanParametar; t=false; return t; }
			}
	} 
	
return t;
	
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y,Smjerovi  p_smjer=Smjerovi::Gore, int p_x=0, int p_y=0){
	try{
		Status stat(Status::NijeKraj);
		if(komanda == Komande::Blokiraj) BlokirajPolje(polja, p_x, p_y);
		else if(komanda == Komande::Deblokiraj) DeblokirajPolje(polja, p_x, p_y);
		else if(komanda == Komande::PomjeriDalje) {
			stat=Idi(polja, x, y, p_x, p_y);
			std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
			if(stat==Status::KrajPobjeda) std::cout<<"Bravo, obisli ste sva sigurna polja"<<std::endl;
			if(stat==Status::KrajPoraz) std::cout<<"Nagazili ste na minu"<<std::endl;
			if(stat!=Status::NijeKraj) komanda=Komande::ZavrsiIgru;
		}
		else if(komanda == Komande::PomjeriJednoMjesto) {
			stat=Idi(polja, x, y, p_smjer);
			std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
			if(stat==Status::KrajPobjeda) std::cout<<"Bravo, obisli ste sva sigurna polja"<<std::endl;
			if(stat==Status::KrajPoraz) std::cout<<"Nagazili ste na minu"<<std::endl;
			if(stat!=Status::NijeKraj) komanda=Komande::ZavrsiIgru;
		}
		else if(komanda==Komande::PrikaziOkolinu){
			std::vector<std::vector<int>> o(PrikaziOkolinu(polja, x, y));
			for(int i=0 ; i<3 ; i++)
				for(int j=0 ; j<3 ; j++)
				std::cout<<o.at(i).at(j)<<" ";
				std::cout<<std::endl;
			
		}
		else if(komanda==Komande::KreirajIgru){
			int n;
			std::cout<<"Unesite broj polja: ";
			std::cin>>n;
			std::vector<std::vector<int>> v_mina;
			for( ; ; ){
				bool greska(false);
				int x,y;
				char znak(std::cin.get());
				if(znak=='.') break;
				while(znak!='(') {
					znak=std::cin.get();
					if(znak!=' ') {greska=true; break;}
				}
				
				if(!greska && znak=='('){
					while(!(std::cin.peek()>='0' && std::cin.peek()<='9')){
						znak=std::cin.get();
						if(znak!=' ') { greska=true; break;}
					}
					
					
				}
				if(!greska){
					std::cin>>x>>znak;
					if(!std::cin || znak!=',' || znak!=' ') greska=true;
					while(!(std::cin.peek()>='0' && std::cin.peek()<='9')){
						znak=std::cin.get();
						if(znak==',') break;
						if(znak!=' ') { greska=true; break;}
						
					}
					
					
				}
				if(!greska && znak==','){
					while(!(std::cin.peek()>='0' && std::cin.peek()<='9')){
						znak=std::cin.get();
						if(znak!=' ') { greska=true; break;}
					}
				}
				if(!greska){
					std::cin>>y>>znak;
					if(!std::cin || znak!=')' || znak!=' ') greska=true;
					while(!(std::cin.peek()>='0' && std::cin.peek()<='9')){
						znak=std::cin.get();
						if(znak==')') break;
						if(znak!=' ') { greska=true; break;}
					}
					
					
				}
				while(std::cin.peek()!='\n'){
						znak=std::cin.get();
						if(znak!=' ') { greska=true; break;}
					}
					
				if(greska || x<0 || x>=n || y<0 || y>=n){
					std::cin.clear();
					std::cin.ignore(10000, '\n');
					std::cout<<"Greska, unesite ponovo!"<<std::endl;
					
				}
				else v_mina.push_back({x,y});
			}
			
			polja=KreirajIgru(n,v_mina);
			
		}
	}
	catch(std::domain_error e){
		std::cout<<e.what()<<std::endl;
	}
	catch(std::out_of_range e){
		std::cout<<e.what()<<std::endl;
	}
	catch(std::logic_error e){
		std::cout<<e.what()<<std::endl;
	}
	if(komanda== Komande::ZavrsiIgru){
		for(int i=0 ; i<polja.size() ; i++){
			for(int j=0 ; j<polja.at(i).size() ; j++)
			polja.at(i).at(j)=Polje::Prazno;
		}
		throw std::runtime_error ("Igra zavrsena");
	}
}

int main ()
{
	

	try{
		Tabla polja;
		int a(0),b(0);
		for( ;; ){
			Komande kom;
			Smjerovi s;
			KodoviGresaka greska;
			int x,y;
			std::cout<<("Unesite komandu: ");
			if(UnosKomande(kom, s, x, y, greska)) IzvrsiKomandu(kom, polja, a, b, s, x, y);
			else PrijaviGresku(greska);
		}
	}
	catch(...){
		std::cout<<"Dovidjenja!"<<std::endl;
	}
	return 0;
}
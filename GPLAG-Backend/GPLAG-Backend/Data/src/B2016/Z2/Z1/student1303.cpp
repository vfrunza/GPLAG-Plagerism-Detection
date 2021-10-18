/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <complex>

enum class Polje {
 Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};
enum class Smjerovi {
 GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};
enum class Status {
 NijeKraj, KrajPoraz, KrajPobjeda
};
enum class KodoviGresaka {
 PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};
enum class Komande {
 PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu,
 ZavrsiIgru, KreirajIgru
};

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	Tabla m(n, std::vector<Polje>(n));
	for(int i(0); i<m.size(); i++){
		for(int j(0); j<m[i].size(); j++){
			m[i][j]=Polje::Prazno;
		}
	}
	try{
		for(int i(1); i<mine.size(); i++){
			if(mine[0].size()!=mine[i].size()) throw std::domain_error ("Ilegalan format zadavanja mina");
		}
		for(int i(0); i<mine.size(); i++){
			for(int j(0); j<mine[i].size(); j++){
				if(mine[i][j]<0 || mine[i][j]>=n) throw std::domain_error("Ilegalne pozicije mina");
			}
		}
		for(int i(0); i<mine.size(); i++){
			int x(mine[i][0]);
			int y(mine[i][1]);
			m[x][y]=Polje::Mina;
		}
		
	}
	
	catch(...){
		throw;
}
return m;
}
int Prebroj(const Tabla &polja, int x, int y){
	int brojac(0);
	for(int i(-1); i<2; i++){
		for(int j(-1); j<2; j++){
			if(i!=0 || j!=0){
				if((x+i)<0 || (y+j)<0 || (x+i)>=polja.size() || (y+j)>=polja.size());
				else if (polja[x+i][y+j]==Polje::Mina ||polja[x+i][y+j]==Polje::BlokiranoMina) brojac++;
			}
		}
	}
	return brojac;
}
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	try{
		if(x<0 || y<0 || x>=polja.size() || y>polja.size()) {
                std::string izuzetak;
                izuzetak=std::string("Polje (") + char(x+'0') +  std::string(",") + char(y+'0') + std::string(") ne postoji");
                throw std::domain_error (izuzetak);
        }
		std::vector<std::vector<int>> mat(3, std::vector<int> (3));
		for(int i(-1); i<2; i++){
			for(int j(-1); j<2; j++){
				mat[i+1][j+1]=Prebroj(polja, x+i, y+j);
			}
		}
		return mat;
	}
	catch(...){
		throw;
	}
}
void BlokirajPolje(Tabla &polja, int x, int y){
	try{
		if(x<0 || y<0 || x>=polja.size() || y>polja.size()) {
                std::string izuzetak;
                izuzetak=std::string("Polje (") + char(x+'0') +  std::string(",") + char(y+'0') + std::string(") ne postoji");
                throw std::domain_error (izuzetak);
        }
		else if(polja[x][y]==Polje::Mina) polja[x][y]=Polje::BlokiranoMina;
		else if(polja[x][y]==Polje::Prazno) polja[x][y]=Polje::BlokiranoPrazno;
		else if(polja[x][y]==Polje::Posjeceno) polja[x][y]=Polje::BlokiranoPosjeceno;
	}
	catch(...){
		throw;
	}
}
void DeblokirajPolje(Tabla &polja, int x, int y){
	try{
		if(x<0 || y<0 || x>=polja.size() || y>polja.size()) {
                std::string izuzetak;
                izuzetak=std::string("Polje (") + char(x+'0') +  std::string(",") + char(y+'0') + std::string(") ne postoji");
                throw std::domain_error (izuzetak);
        }
		else if(polja[x][y]==Polje::BlokiranoMina) polja[x][y]=Polje::Mina;
		else if(polja[x][y]==Polje::BlokiranoPrazno) polja[x][y]=Polje::Prazno;
		else if(polja[x][y]==Polje::BlokiranoPosjeceno) polja[x][y]=Polje::Posjeceno;
	}
	catch(...){
		throw;
	}
}
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	polja[x][y]=Polje::Posjeceno;
	try{
	if(x==0 && ( smjer==Smjerovi::Gore ||  smjer==Smjerovi::GoreLijevo ||  smjer==Smjerovi::GoreDesno)) throw std::out_of_range ("Izlazak van igrace table");
	if(x==polja.size()-1  && ( smjer==Smjerovi::Dolje ||  smjer==Smjerovi::DoljeLijevo ||  smjer==Smjerovi::DoljeDesno)) throw std::out_of_range ("Izlazak van igrace table");
	if(y==0 && ( smjer==Smjerovi::Lijevo ||  smjer==Smjerovi::GoreLijevo ||  smjer==Smjerovi::DoljeLijevo)) throw std::out_of_range ("Izlazak van igrace table");
	if(y==polja.size()-1  && ( smjer==Smjerovi::Desno ||  smjer==Smjerovi::GoreDesno ||  smjer==Smjerovi::DoljeDesno)) throw std::out_of_range ("Izlazak van igrace table");
	
	if(smjer==Smjerovi::GoreLijevo){
		x--, y--;
		if (polja[x][y]==Polje::BlokiranoPosjeceno || polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoMina){
			x++;
			y++;
			throw std::logic_error ("Blokirano polje");
		}
	} 
	else if(smjer==Smjerovi::Gore){
		x--;
		if (polja[x][y]==Polje::BlokiranoPosjeceno || polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoMina){
			x++;
			throw std::logic_error ("Blokirano polje");
		}
	}
	else if(smjer==Smjerovi::GoreDesno){
		x--;
		y++;
		if (polja[x][y]==Polje::BlokiranoPosjeceno || polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoMina){
			x++;
			y--;
			throw std::logic_error ("Blokirano polje");
		}
	}
	else if(smjer==Smjerovi::Lijevo){
		y--;
		if (polja[x][y]==Polje::BlokiranoPosjeceno || polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoMina){
			y++;
			throw std::logic_error ("Blokirano polje");
		}
	} 
	else if(smjer==Smjerovi::Desno){
		y++;
		if (polja[x][y]==Polje::BlokiranoPosjeceno || polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoMina){
			y--;
			throw std::logic_error ("Blokirano polje");
		}
	}
	else if(smjer==Smjerovi::DoljeLijevo){
		x++,y--;
		if (polja[x][y]==Polje::BlokiranoPosjeceno || polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoMina){
			x--;
			y++;
			throw std::logic_error ("Blokirano polje");
		}
	}
	else if(smjer==Smjerovi::Dolje){
		x++;
		if (polja[x][y]==Polje::BlokiranoPosjeceno || polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoMina){
			x--;
			throw std::logic_error ("Blokirano polje");
		}
	}
	else if(smjer==Smjerovi::DoljeDesno) {
		x++, y++;
		if (polja[x][y]==Polje::BlokiranoPosjeceno || polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoMina){
			x--;
			y--;
			throw std::logic_error ("Blokirano polje");
		}
	}
	if( polja[x][y]==Polje::Mina){
			for(int i(0); i<polja.size(); i++){
				for(int j(0); j<polja[i].size(); j++){
					polja[i][j]=Polje::Prazno;
				}
			}
			return Status::KrajPoraz;
		} 
	int i;
	for(i=0; i<polja.size(); i++){
		for(int j(0); j<polja.size(); j++){
			if(polja[x][y]==Polje::Prazno) return Status::NijeKraj;
		}
	}
	return Status::KrajPobjeda;
}
catch(...) {
	throw;
}

}
		

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	try{
		if(novi_x<0 || novi_x>=polja.size() || novi_y<0 ||novi_y>=polja.size()) throw std::out_of_range ("Izlazak van igrace table");
		else if (polja[novi_x][novi_y]==Polje::BlokiranoPosjeceno || polja[novi_x][novi_y]==Polje::BlokiranoPrazno || polja[novi_x][novi_y]==Polje::BlokiranoMina) throw std::logic_error ("Blokirano polje");
		x=novi_x;
		y=novi_y;
		if( polja[x][y]==Polje::Mina){
			for(int i(0); i<polja.size(); i++){
				for(int j(0); j<polja[i].size(); j++){
					polja[i][j]=Polje::Prazno;
				}
			}
			return Status::KrajPoraz;
		} 
		for(int i(0); i<polja.size(); i++){
			for(int j(0); j<polja.size(); j++){
				if(polja[x][y]==Polje::Prazno) return Status::NijeKraj;
			}
		}
		return Status::KrajPobjeda;
	}
	catch(...){
		throw;
	}
}
void PrijaviGresku(KodoviGresaka greska){
	if(greska==KodoviGresaka::PogresnaKomanda) std::cout<<"Nerazumljiva komanda!"<<std::endl;
	if(greska==KodoviGresaka::NedostajeParametar) std::cout<<"Komanda trazi parametar koji nije naveden!"<<std::endl;
	if(greska==KodoviGresaka::NeispravanParametar) std::cout<<"Parametar komande nije ispravan!"<<std::endl;
	if(greska==KodoviGresaka::SuvisanParametar) std::cout<<"Zadan je suvisan parametar nakon komande!"<<std::endl;
}
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	std::string s;
	std::getline(std::cin, s);
	try{
		int gr(0);
	for(int i(0); i<s.size(); i++){
		while(s.at(i)==' ' && i<s.size()-1) i++;
		if(s.substr(i,2)=="P1"){
			int brojac(0);//dobili smo komandu, sad trazimo smjer
			komanda=Komande::PomjeriJednoMjesto;
			while(i<s.size()-1 && s.at(i)==' ') i++;
			if(s.substr(i,2)=="GL") {smjer=Smjerovi::GoreLijevo; i+=2; brojac++;}
			else if(s.at(i)=='G') {smjer=Smjerovi::Gore; i++; brojac++;}
			else if(s.substr(i,2)=="GD") {smjer=Smjerovi::GoreDesno; i+=2; brojac++;}
			else if(s.at(i)=='D') {smjer=Smjerovi::Desno; i++; brojac++;}
			else if(s.substr(i,3)=="DoD") {smjer=Smjerovi::DoljeDesno; i+=3; brojac++;}
			else if(s.substr(i,2)=="Do") {smjer=Smjerovi::Dolje; i+=2; brojac++;}
			else if(s.substr(i,3)=="DoL"){ smjer=Smjerovi::DoljeLijevo; i+=3; brojac++;}
			else if(s.at(i)=='L') {smjer=Smjerovi::Lijevo; i++; brojac++;}
			else{
				while(s.at(i)==' ' && i<s.size()-1 ) i++;
				if(s.at(i)!=s.at(s.size()-1) && brojac>0) greska=KodoviGresaka::SuvisanParametar, gr++;
				if(s.at(i)==s.at(s.size()-1) && brojac==0) greska=KodoviGresaka::NedostajeParametar, gr++;
			}
		
		}
		else if(s.substr(i,2)=="P>"){
			komanda=Komande::PomjeriDalje;
			int a(-1),b(-1);
			while(i<s.size() && s.at(i)==' ') i++;
			if(i<s.size() && s.at(i)>='0' && s.at(i)<='9' && s.at(i+1)==' ') a=s.at(i)-'0', i++;
			while(i<s.size() && s.at(i)==' ') i++;
			if(i<s.size() && s.at(i)>='0' && s.at(i)<='9') b=s.at(i)-'0';
			if(a==-1 || b==-1) greska=KodoviGresaka::NedostajeParametar, gr++;
			while(i<s.size() && s.at(i)==' ') i++;
			if(i!=s.size()-1) greska=KodoviGresaka::SuvisanParametar, gr++;
			x=a;
			y=b;
		
			
		}
		else if(s.at(i)=='B'){
			komanda=Komande::Blokiraj;
			int a(-1),b(-1);
			while(i<s.size() && s.at(i)==' ') i++;
			
			if(i<s.size() && s.at(i)>='0' && s.at(i)<='9' && s.at(i+1)==' ') a=s.at(i)-'0', i++;
			
			while(i<s.size() && s.at(i)==' ') i++;
			
			if(i<s.size() && s.at(i)>='0' && s.at(i)<='9') b=s.at(i)-'0';
			
			if(a==-1 || b==-1) greska=KodoviGresaka::NedostajeParametar, gr++;
			
			while(i<s.size() && s.at(i)==' ') i++;
			
			if(i!=s.size()-1) greska=KodoviGresaka::SuvisanParametar, gr++;
			x=a;
			y=b;
		
			
		}
		else if(s.at(i)=='D'){
			komanda=Komande::Deblokiraj;
			int a(-1),b(-1);
			while(i<s.size() && s.at(i)==' ') i++;
			if(i<s.size() && s.at(i)>='0' && s.at(i)<='9' && s.at(i+1)==' ') a=s.at(i)-'0', i++;
			while(i<s.size() && s.at(i)==' ') i++;
			if(i<s.size() && s.at(i)>='0' && s.at(i)<='9') b=s.at(i)-'0';
			if(a==-1 || b==-1) greska=KodoviGresaka::NedostajeParametar, gr++;
			while(i<s.size() && s.at(i)==' ') i++;
			if(i!=s.size()-1) greska=KodoviGresaka::SuvisanParametar, gr++;
			x=a;
			y=b;
		
			
		}
		else if(s.substr(i,2)=="PO"){
			if(s.at(i+2)==' ' || i+2==s.size()) komanda=Komande::PrikaziOkolinu;
			else greska=KodoviGresaka::SuvisanParametar, gr++;
		
		} 
		else if(s.at(i)=='Z'){
			if(s.at(i+1)==' ' || i+1==s.size()) komanda=Komande::ZavrsiIgru;
			else greska=KodoviGresaka::SuvisanParametar, gr++;
		
		}
		else if(s.at(i)=='K'){
			if(s.at(i+1)==' ' || i+1==s.size()) komanda=Komande::KreirajIgru;
			else greska=KodoviGresaka::SuvisanParametar, gr++;
		
		}
		else{
			greska=KodoviGresaka::PogresnaKomanda, gr++;
		
		}
	}
	if(gr>0) return false;
	return true;
	}
	catch(...){
		throw;
	}
}
void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0){
	if(komanda==Komande::KreirajIgru){
		int n;
		std::cout<<"Unesite broj polja: ";
		std::cin>>n;
		std::vector<std::vector<int>> mine(n, std::vector<int>(2));
		
		std::cout<<"Unesite pozicije mina: ";
		int i(0);
		do{
			std::complex<int> z;
			if(std::cin>>z){
				if(z.real()>=0 && z.real()<n && z.imag()>=0 && z.imag()<n){
					mine[i][0]=z.real();
					mine[i][1]=z.imag();
					i++;
				}
				else std::cout<<"Greska, unesite ponovo!"<<std::endl;
			}
			else{
				std::cout<<"Greska, unesite ponovo!"<<std::endl;
				std::cin.clear();
				std::cin.ignore(10000, '\n');
			}
			
			
		}while(std::cin.peek()!='.');
		
	}
	else if(komanda==Komande::ZavrsiIgru){
		for(int i(0); i<polja.size(); i++){
			for(int j(0); j<polja.size(); j++){
				polja[i][j]=Polje::Prazno;
				throw std::runtime_error ("Igra zavrsena");
			}
		}
	}
	else if(komanda==Komande::PomjeriJednoMjesto){
		Status a(Idi(polja, x, y, p_smjer));
		std::cout<<"Tekuca pozicija igraca je ("<< x <<","<< y <<")"<<std::endl;
		if(a==Status::KrajPobjeda) std::cout<<"bravo, obisli ste sva sigurna polja";
		else if(a==Status::KrajPoraz) std::cout<<"Nagazili ste na minu";
	}
	else if(komanda==Komande::PomjeriDalje){
		Status a(Idi(polja, x, y, p_x, p_y));
		std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
		if(a==Status::KrajPobjeda) std::cout<<"bravo, obisli ste sva sigurna polja";
		else if(a==Status::KrajPoraz) std::cout<<"Nagazili ste na minu";
	}
	
}

int main ()
{
	
	try{
		Tabla polja;
		Komande komanda;
		int x(0),y(0), p_x(0), p_y(0);
		Smjerovi smjer;
		KodoviGresaka greska;
		
	for(;;){
		std::cout<<"Unesite komandu: ";
		if(UnosKomande(komanda, smjer, x, y, greska)) IzvrsiKomandu(komanda, polja, x, y, smjer, p_x, p_y);
		else PrijaviGresku(greska);
		std::cout<<std::endl;
	}
	}
	catch(std::domain_error e){
		std::cout<<e.what()<<std::endl;
	}
	catch(std::out_of_range e){
		std::cout<<e.what()<<std::endl;
	}
	
	catch(std::runtime_error e){
		std::cout<<e.what()<<std::endl;
	}
	catch(std::logic_error e){
		std::cout<<e.what()<<std::endl;
	}
	return 0;
}


/* 
Izmijeniti zadnje dvije funkcije, nie valja ovakav unos, probaj unosbez razmaka, ako se ne bude kontrolisalo, onda ce prolaziti.
a ako bude frka, probaj sa predefinisanim stringovima.
*/
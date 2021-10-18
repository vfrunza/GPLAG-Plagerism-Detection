/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstring>
#include <string>
#include <complex>

const double epsilon(0.0001);

enum class Polje {
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};

enum class Smjerovi {
	GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};

enum class Status {
	NijeKraj, KrajPoraz, KrajPobjeda
};

enum class KodoviGresaka{
	PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};

enum class Komande{
	PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};
typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru (int n, const std::vector<std::vector<int>> &mine){
	Tabla tabla(n, std::vector<Polje> (n, Polje::Prazno));
	for(int i=0; i<mine.size(); i++){
		if(mine[i].size()!=2 ) throw std::domain_error ("Ilegalan format zadavanja mina");
		for(int j=0; j<2; j++){
			if(mine[i][j]>=n || mine[i][j]<0) throw std::domain_error ("Ilegalne pozicije mina");
		}
		tabla[mine[i][0]][mine[i][1]]=Polje::Mina;
	}
	return tabla;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	if(x>=polja.size() || y>=polja.size() || x<0 || y<0) throw std::domain_error ("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	std::vector<std::vector<int>> matrica(3, std::vector<int> (3, 0));
	int broj(0);
	for(int i=x-1; i<x+2; i++){
		for(int j=y-1; j<y+2; j++){
			broj=0;
			for(int k=i-1; k<i+2; k++){
				for(int l=j-1; l<j+2; l++){
					if((k>=0 && k<polja.size()) && (l>=0 && l<polja.size())){
						if(polja[k][l]==Polje::Mina && (k!=i || l!=j)) broj++;
					}
				}
			}
			matrica[i-(x-1)][j-(y-1)]=broj;
		}
	}
	return matrica;
}

void BlokirajPolje(Tabla &polja, int x, int y){
	if(x>=polja.size() || y>=polja.size() || x<0 || y<0) throw std::domain_error ("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	if(polja[x][y]==Polje::Prazno) polja[x][y]=Polje::BlokiranoPrazno;
	if(polja[x][y]==Polje::Posjeceno) polja[x][y]=Polje::BlokiranoPosjeceno;
	if(polja[x][y]==Polje::Mina) polja[x][y]=Polje::BlokiranoMina;
}

void DeblokirajPolje(Tabla &polja, int x, int y){
	if(x>=polja.size() || y>=polja.size() || x<0 || y<0) throw std::domain_error ("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	if(polja[x][y]==Polje::BlokiranoPosjeceno) polja[x][y]=Polje::Posjeceno;
	if(polja[x][y]==Polje::BlokiranoPrazno) polja[x][y]=Polje::Prazno;
	if(polja[x][y]==Polje::BlokiranoMina) polja[x][y]=Polje::Mina;
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	int n(polja.size());
	if(smjer==Smjerovi::GoreLijevo){
		if(x-1>=0 && y-1>=0 && x-1<n && y-1<n){
			if(polja[x-1][y-1] != Polje:: BlokiranoPosjeceno && polja[x-1][y-1] != Polje:: BlokiranoMina && 
			polja[x-1][y-1] != Polje:: BlokiranoPrazno) {
				polja[x][y]=Polje::Posjeceno;
				x--;
				y--;
			}
			else throw std::logic_error ("Blokirano polje");
		}
		else throw std::out_of_range ("Izlazak van igrace table");
	}
	if(smjer==Smjerovi::Gore){
		if(x-1>=0 && x-1<n){
			if(polja[x-1][y] != Polje:: BlokiranoPosjeceno && polja[x-1][y] != Polje:: BlokiranoMina && 
			polja[x-1][y] != Polje:: BlokiranoPrazno) {
				polja[x][y]=Polje::Posjeceno;
				x--;
			}
			else throw std::logic_error ("Blokirano polje");
		}
		else throw std::out_of_range ("Izlazak van igrace table");
	}
	if(smjer==Smjerovi::GoreDesno){
		if(x-1>=0 && y+1>=0 && x-1<n && y+1<n){
			if(polja[x-1][y+1] != Polje:: BlokiranoPosjeceno && polja[x-1][y+1] != Polje:: BlokiranoMina && 
			polja[x-1][y+1] != Polje:: BlokiranoPrazno) {
				polja[x][y]=Polje::Posjeceno;
				x--;
				y++;
			}
			else throw std::logic_error ("Blokirano polje");
		}
		else throw std::out_of_range ("Izlazak van igrace table");
	}
	if(smjer==Smjerovi::DoljeLijevo){
		if(x+1>=0 && y-1>=0 && x+1<n && y-1<n){
			if(polja[x+1][y-1] != Polje:: BlokiranoPosjeceno && polja[x+1][y-1] != Polje:: BlokiranoMina && 
			polja[x+1][y-1] != Polje:: BlokiranoPrazno) {
				polja[x][y]=Polje::Posjeceno;
				x++;
				y--;
			}
			else throw std::logic_error ("Blokirano polje");
		}
		else throw std::out_of_range ("Izlazak van igrace table");
	}
	if(smjer==Smjerovi::DoljeDesno){
		if(x+1>=0 && y+1>=0 && x+1<n && y+1<n){
			if(polja[x+1][y+1] != Polje:: BlokiranoPosjeceno && polja[x+1][y+1] != Polje:: BlokiranoMina && 
			polja[x+1][y+1] != Polje:: BlokiranoPrazno) {
				polja[x][y]=Polje::Posjeceno;
				x++;
				y++;
			}
			else throw std::logic_error ("Blokirano polje");
		}
		else throw std::out_of_range ("Izlazak van igrace table");
	}
	if(smjer==Smjerovi::Desno){
		if(y+1>=0 && y+1<n){
			if(polja[x][y+1] != Polje:: BlokiranoPosjeceno && polja[x][y+1] != Polje:: BlokiranoMina && 
			polja[x][y+1] != Polje:: BlokiranoPrazno) {
				polja[x][y]=Polje::Posjeceno;
				y++;
			}
			else throw std::logic_error ("Blokirano polje");
		}
		else throw std::out_of_range ("Izlazak van igrace table");
	}
	if(smjer==Smjerovi::Dolje){
		if(x+1>=0 && x+1<n){
			if(polja[x+1][y] != Polje:: BlokiranoPosjeceno && polja[x+1][y] != Polje:: BlokiranoMina && 
			polja[x+1][y] != Polje:: BlokiranoPrazno) {
				polja[x][y]=Polje::Posjeceno;
				x++;
			}
			else throw std::logic_error ("Blokirano polje");
		}
		else throw std::out_of_range ("Izlazak van igrace table");
	}
	if(smjer==Smjerovi::Lijevo){
		if(y-1>=0 && y-1<n){
			if(polja[x][y-1] != Polje:: BlokiranoPosjeceno && polja[x][y-1] != Polje:: BlokiranoMina && 
			polja[x][y-1] != Polje:: BlokiranoPrazno) {
				polja[x][y]=Polje::Posjeceno;
				y--;
			}
			else throw std::logic_error ("Blokirano polje");
		}
		else throw std::out_of_range ("Izlazak van igrace table");
	}
	
	if(polja[x][y]==Polje::Mina){
		for(int i=0; i<polja.size(); i++)
			for(int j=0; j<polja.size(); j++)
				polja[i][j]=Polje::Prazno;
		return Status::KrajPoraz;
	} 
	for(int i=0; i<polja.size(); i++)
			for(int j=0; j<polja.size(); j++)
				if(polja[i][j]==Polje::Prazno) return Status::NijeKraj;
	return Status::KrajPobjeda;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	int n(polja.size());
	if(novi_x>=0 && novi_x<n && novi_y>=0 && novi_y<n){
		if(polja[novi_x][novi_y] != Polje::BlokiranoPosjeceno && polja[novi_x][novi_y] != Polje::BlokiranoPrazno
		&& polja[novi_x][novi_y] != Polje::BlokiranoMina) {
			polja[x][y]=Polje::Posjeceno;
			x=novi_x;
			y=novi_y;
		}
		else throw std::logic_error ("Blokirano polje");
	}
	else throw std::out_of_range ("Izlazak van igrace table");
	
	if(polja[x][y]==Polje::Mina){
		for(int i=0; i<polja.size(); i++)
			for(int j=0; j<polja.size(); j++)
				polja[i][j]=Polje::Prazno;
		return Status::KrajPoraz;
	} 
	for(int i=0; i<polja.size(); i++)
			for(int j=0; j<polja.size(); j++)
				if(polja[i][j]==Polje::Prazno) return Status::NijeKraj;
	return Status::KrajPobjeda;
}

void PrijaviGresku(KodoviGresaka greska){
	if(greska==KodoviGresaka::PogresnaKomanda) std::cout<<"Nerazumljiva komanda!"<<std::endl;
	if(greska==KodoviGresaka::NedostajeParametar) std::cout<<"Komanda trazi parametar koji nije naveden!"<<std::endl;
	if(greska==KodoviGresaka::NeispravanParametar) std::cout<<"Parametar komande nije ispravan!"<<std::endl;
	if(greska==KodoviGresaka::SuvisanParametar) std::cout<<"Zadan je suvisan parametar nakon komande!"<<std::endl;
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	char s[2];
	std::cin>>s[0];
	s[1]='\0';
	int c;
	if(s[0]=='P' || s[0]=='B' || s[0]=='D' || s[0]=='Z' || s[0]=='K'){
		if(s[0]=='P'){
			c=std::cin.get();
			if(c=='1' || c=='>' || c=='O'){ 
				if(c=='1') {
					while(std::cin.peek()==' ') c=std::cin.get();
					if(std::cin.peek()=='\n' || c=='\n'){
						std::cin.ignore(1000,'\n');
						greska=KodoviGresaka::NedostajeParametar;
						return false;
					}
					char a[4];
					int z(0);
					while(std::cin.peek()!='\n' && z<3) a[z++]=std::cin.get();
					a[z]='\0';
					if(strcmp(a,"GL")==0){
						if(std::cin && std::cin.peek()!='\n') {greska=KodoviGresaka::SuvisanParametar; std::cin.ignore(1000,'\n'); return false;}
						smjer=Smjerovi::GoreLijevo;
						komanda=Komande::PomjeriJednoMjesto;
						return true;
					}
					else if(strcmp(a,"DoL")==0){
						if(std::cin && std::cin.peek()!='\n') {greska=KodoviGresaka::SuvisanParametar; std::cin.ignore(1000,'\n'); return false;}
						smjer=Smjerovi::DoljeLijevo;
						komanda=Komande::PomjeriJednoMjesto;
						return true;
					}
					else if(strcmp(a,"GD")==0){
						if(std::cin && std::cin.peek()!='\n') {greska=KodoviGresaka::SuvisanParametar; std::cin.ignore(1000,'\n'); return false;}
						smjer=Smjerovi::GoreDesno;
						komanda=Komande::PomjeriJednoMjesto;
						return true;
					}
					else if(strcmp(a,"G")==0){
						if(std::cin && std::cin.peek()!='\n') {greska=KodoviGresaka::SuvisanParametar; std::cin.ignore(1000,'\n'); return false;}
						smjer=Smjerovi::Gore;
						komanda=Komande::PomjeriJednoMjesto;
						return true;
					}
					else if(strcmp(a,"Do")==0){
						if(std::cin && std::cin.peek()!='\n') {greska=KodoviGresaka::SuvisanParametar; std::cin.ignore(1000,'\n'); return false;}
						smjer=Smjerovi::Dolje;
						komanda=Komande::PomjeriJednoMjesto;
						return true;
					}
					else if(strcmp(a,"L")==0){
						if(std::cin && std::cin.peek()!='\n') {greska=KodoviGresaka::SuvisanParametar; std::cin.ignore(1000, '\n'); return false;}
						smjer=Smjerovi::Lijevo;
						komanda=Komande::PomjeriJednoMjesto;
						return true;
					}
					else if(strcmp(a,"D")==0){
						if(std::cin && std::cin.peek()!='\n') {greska=KodoviGresaka::SuvisanParametar; std::cin.ignore(1000, '\n'); return false;}
						smjer=Smjerovi::Desno;
						komanda=Komande::PomjeriJednoMjesto;
						return true;
					}
					else if(strcmp(a,"DoD")==0){
						if(std::cin && std::cin.peek()!='\n') {greska=KodoviGresaka::SuvisanParametar; std::cin.ignore(1000, '\n'); return false;}
						smjer=Smjerovi::DoljeDesno;
						komanda=Komande::PomjeriJednoMjesto;
						return true;
					}
					else{
						greska=KodoviGresaka::NeispravanParametar;
						std::cin.ignore(1000,'\n');
						return false;
					}
				}
				else if(c=='>'){
					while(std::cin.peek()==' ') c=std::cin.get();
					if(std::cin.peek()=='\n' || c=='\n'){
						greska=KodoviGresaka::NedostajeParametar;
						std::cin.ignore(1000,'\n');
						return false;
					}
					int r(std::cin.peek());
					if((r-'0')>=0 &&(r-'0')<=9){
						int m;
						std::cin>>m;
						while(std::cin.peek()==' ') c=std::cin.get();
						int f(std::cin.peek());
						if((f-'0')>=0 && (f-'0')<=9){
							int e;
							std::cin>>e;
							while(std::cin.peek()==' ') std::cin.get();
							if(std::cin.peek()!='\n'){
								greska=KodoviGresaka::SuvisanParametar;
								std::cin.ignore(1000, '\n');
								return false;
							}
							x=m;
							y=e;
							komanda=Komande::PomjeriDalje;
							return true;
						}
					}
					else{
						greska=KodoviGresaka::NeispravanParametar;
						std::cin.ignore(1000,'\n');
						return false;
					}
				}
				else if(c=='O'){
					while(std::cin.peek()==' ') c=std::cin.get();
					if(std::cin && std::cin.peek()!='\n'){
						greska=KodoviGresaka::SuvisanParametar;
						std::cin.ignore(1000,'\n');
						return false;
					}
					komanda=Komande::PrikaziOkolinu;
					return true;
				}
				else{
					greska=KodoviGresaka::PogresnaKomanda; std::cin.ignore(1000,'\n'); return false;
				}
			}
			else{ greska=KodoviGresaka::PogresnaKomanda; std::cin.ignore(1000, '\n'); return false; }
		}
		if(s[0]=='B'){
			while(std::cin.peek()==' ') c=std::cin.get();
			int a(std::cin.peek());
			if((a-'0')>=0 && (a-'0')<=9){
				int m;
				std::cin>>m;
				while(std::cin.peek()==' ') std::cin.get();
				int k(std::cin.peek());
				if((k-'0')>=0 && (k-'0')<=9){
					int e;
					std::cin>>e;
					while(std::cin.peek()==' ')  std::cin.get();
					if(std::cin.peek() !='\n') { greska=KodoviGresaka::SuvisanParametar; std::cin.ignore(1000,'\n'); return false;}
					x=m;
					y=e;
					komanda=Komande::Blokiraj;
					return true;
				}
				else{
					greska=KodoviGresaka::NeispravanParametar;
					std::cin.ignore(1000,'\n');
					return false;
				}
			}
			else{
				greska=KodoviGresaka::NedostajeParametar;
				std::cin.ignore(1000,'\n');
				return false;
			}
		}
		if(s[0]=='D'){
			while(std::cin.peek()==' ') std::cin.get();
			int a(std::cin.peek());
			if((a-'0')>=0 && (a-'0')<=9){
				int m;
				std::cin>>m;
				while(std::cin.peek()==' ') std::cin.get();
				int k(std::cin.peek());
				if((k-'0')>=0 && (k-'0')<=9){
					int e;
					std::cin>>e;
					while(std::cin.peek()==' ') std::cin.get();
					if(std::cin.peek()!='\n'){ greska=KodoviGresaka::SuvisanParametar; std::cin.ignore(1000, '\n'); return false;}
					x=m;
					y=e;
					komanda=Komande::Deblokiraj;
					return true;
				}
				else{
					greska=KodoviGresaka::NeispravanParametar;
					std::cin.ignore(1000,'\n');
					return false;
				}
			}
			else{
				greska=KodoviGresaka::NedostajeParametar;
				std::cin.ignore(1000,'\n');
				return false;
			}
		}
		if(s[0]=='Z'){
			if(std::cin && std::cin.peek()!='\n'){
				greska=KodoviGresaka::SuvisanParametar;
				std::cin.ignore(1000,'\n');
				return false;
			}
			komanda=Komande::ZavrsiIgru;
			return true;
		}
		if(s[0]=='K'){
			if(std::cin && std::cin.peek()!='\n'){
				greska=KodoviGresaka::SuvisanParametar;
				std::cin.ignore(1000,'\n');
				return false;
			}
			komanda=Komande::KreirajIgru;
			return true;
		}
	}
	else{ greska=KodoviGresaka::PogresnaKomanda; std::cin.ignore(1000,'\n'); return false;}
	return false;
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer=Smjerovi::Gore, int p_x=0, int p_y=0){
	try{
		if(komanda==Komande::PomjeriDalje){
			Status status(Idi(polja,p_x,p_y,x,y));
			std::cout<<"Tekuca pozicija igraca je ("<< x<<","<<y<<")"<<std::endl;
			if(status== Status::KrajPoraz) {
				std::cout<<"Nagazili ste na minu"<<std::endl;
				for(int i=0; i<polja.size(); i++)
					for(int j=0; j<polja.size(); j++)
						polja[i][j]=Polje::Prazno;
				throw std::runtime_error ("Igra zavrsena");
			}
			else if(status==Status::KrajPobjeda){
				std::cout<<"Bravo, obisli ste sva sigurna polja"<<std::endl;
				for(int i=0; i<polja.size(); i++)
					for(int j=0; j<polja.size(); j++)
						polja[i][j]=Polje::Prazno;
				throw std::runtime_error ("Igra zavrsena");
			}
		}
		if(komanda==Komande::PomjeriJednoMjesto){
			Status status(Idi(polja, x, y, p_smjer));
			std::cout<<"Tekuca pozicija igraca je ("<< x<<","<<y<<")"<<std::endl;
			if(status== Status::KrajPoraz) {
				std::cout<<"Nagazili ste na minu"<<std::endl;
				for(int i=0; i<polja.size(); i++)
					for(int j=0; j<polja.size(); j++)
						polja[i][j]=Polje::Prazno;
				throw std::runtime_error ("Igra zavrsena");
			}
			else if(status==Status::KrajPobjeda){
				std::cout<<"Bravo, obisli ste sva sigurna polja"<<std::endl;
				for(int i=0; i<polja.size(); i++)
					for(int j=0; j<polja.size(); j++)
						polja[i][j]=Polje::Prazno;
				throw std::runtime_error ("Igra zavrsena");
			}
		}
		if(komanda==Komande::Blokiraj){
			BlokirajPolje(polja, x, y);
		}
		if(komanda==Komande::Deblokiraj){
			DeblokirajPolje(polja, x, y);
		}
		if(komanda==Komande::KreirajIgru){
			
		}
		if(komanda==Komande::PrikaziOkolinu){
			std::vector<std::vector<int>> matrica(3, std::vector<int> (3,0));
			matrica=PrikaziOkolinu(polja, x, y);
			for(int i=0; i<3; i++){
				for(int j=0; j<3; j++){
					std::cout<<matrica[i][j]<<" ";
				}
				std::cout<<std::endl;
			}
		}
		if(komanda==Komande::ZavrsiIgru){
				for(int i=0; i<polja.size(); i++)
					for(int j=0; j<polja.size(); j++)
						polja[i][j]=Polje::Prazno;
				throw std::runtime_error ("Igra zavrsena");
		}
		if(komanda==Komande::KreirajIgru){
			std::cout<<"Unesite broj polja: ";
			int n;
			std::cin>>n;
			std::cout<<"Unesite pozicije mina: ";
			std::vector<std::vector<int>> vektor(0);
			int i(0);
			for(;;){
				std::cin>>std::ws;
				std::complex<float> broj;
				if(std::cin.peek()=='.') {
					if(epsilon>(broj.real()-0) && (broj.imag()-0)<epsilon) vektor.resize(0);
					polja=(KreirajIgru(n,vektor));
					std::cin.clear();
					std::cin.ignore(1000, '\n');
					break;
				}
				vektor.resize(i+1);
				std::cin>>broj;
				int a, b;
				a=broj.real();
				b=broj.imag();
				if((a==0 && b==0) || a>=n || b>=n || a<0 || b<0){
					std::cout<<"Greska, unesite ponovo!"<<std::endl;
					std::cin.clear();
					std::cin.ignore(1000, '\n');
					continue;
				}
				vektor[i].push_back(a);
				vektor[i].push_back(b);
				i++;
				if(std::cin.peek()=='\n') std::cin.get();
				if(std::cin.peek()=='.') {
					polja=(KreirajIgru(n,vektor));
					std::cin.clear();
					std::cin.ignore(1000, '\n');
					break;
				
				}
			}
			
		}
	}
	catch(std::runtime_error izuzetak){
		std::cout<<"Dovidjenja!"<<std::endl;
		throw;
	}
	catch(std::out_of_range izuzetak){
		std::cout<<izuzetak.what()<<std::endl;
	}
	catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what()<<std::endl;
	}
	catch(std::logic_error izuzetak){
		std::cout<<izuzetak.what()<<std::endl;
	}
	catch(...){
		std::cout<<"Bacen je nepoznat izuzetak"<<std::endl;
	}
}
int main ()
{
	try{
		Komande komanda;
		Smjerovi smjer;
		Tabla tabla;
		KodoviGresaka greska;
		int x(0), y(0);
		for(;;){
			std::cout<<"Unesite komandu: ";
			bool istina(UnosKomande(komanda, smjer, x, y, greska ));
			if(istina) IzvrsiKomandu(komanda, tabla, x, y, smjer);
			else PrijaviGresku(greska);
		}
	}catch(std::runtime_error){
		return 0;
	}
	
}
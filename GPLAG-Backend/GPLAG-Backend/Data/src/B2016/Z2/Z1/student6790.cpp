#include <iostream>
#include <vector>
#include <complex>
#include <stdexcept>
#include <cmath>

enum class Status {
 NijeKraj, KrajPoraz, KrajPobjeda
};
enum class Polje {
 Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};
enum class Smjerovi {
 GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};
enum class KodoviGresaka {
 PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};
enum class Komande {
 PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu,
 ZavrsiIgru, KreirajIgru
};
typedef std::vector<std::vector<Polje>> Tabla;


Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine) {
	
	Tabla tabla (n, std::vector<Polje>(n));                      //deklaracija promjenjive tipa Tabla(vektor vektora)
	for(int i=0; i<n; i++) 
		for(int j=0; j<n; j++)
			tabla[i][j]=Polje::Prazno;                          //inicijalizacija svih el. vektora na prazno
			
	for(int i=0; i<mine.size(); i++) {
		for(int j=0; j<mine[i].size(); j++) {                                                //bacanje izuzetaka
			if(mine[i].size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
			if(mine[i][j]>=n) throw std::domain_error("Ilegalne pozicije mina");
		}
	}
	
	for(int i=0; i<mine.size(); i++) {
		tabla[mine[i][0]][mine[i][1]]=Polje::Mina;
	}		
	return tabla;
}

int brojac_mina(int i, int j, const Tabla &polja) {								//pomocna funkcija!!
	int brojac=0;
	int n=polja.size();
	if (i>=0 && i<n && (j-1)>=0 && (j-1)<n && polja[i][j-1]==Polje::Mina) brojac++;
	if (i>=0 && i<n && (j+1)>=0 && (j+1)<n && polja[i][j+1]==Polje::Mina) brojac++;
	if ((i+1)>=0 && (i+1)<n && (j-1)>=0 && (j-1)<n && polja[i+1][j-1]==Polje::Mina) brojac++;
	if ((i+1)>=0 && (i+1)<n && j>=0 && j<n && polja[i+1][j]==Polje::Mina) brojac++;
	if ((i+1)>=0 && (i+1)<n && (j+1)>=0 && (j+1)<n && polja[i+1][j+1]==Polje::Mina) brojac++;
	if ((i-1)>=0 && (i-1)<n && (j-1)>=0 && (j-1)<n && polja[i-1][j-1]==Polje::Mina) brojac++;
	if ((i-1)>=0 && (i-1)<n && j>=0 && j<n && polja[i-1][j]==Polje::Mina) brojac++;
	if ((i-1)>=0 && (i-1)<n && (j+1)>=0 && (j+1)<n && polja[i-1][j+1]==Polje::Mina) brojac++;
	
	return brojac;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y) {
	if (x<0 || y<0 || x>=polja.size() || y>=polja.size()) {
		const std::string s("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
		throw std::domain_error(s);}
		
	std::vector<std::vector<int>> matrica3 (3, std::vector<int>(3, 0));
	for(int i=0; i<3; i++) 
		for(int j=0; j<3; j++) 
	matrica3[i][j]=brojac_mina(x+(i-1), y+(j-1), polja);
	
	return matrica3;
}

void BlokirajPolje(Tabla &polja, int x, int y) {
	if (x<0 || y<0 || x>=polja.size() || y>=polja.size()) {
		const std::string s("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
		throw std::domain_error(s);}
		
	if(polja[x][y]==Polje::Prazno) polja[x][y]=Polje::BlokiranoPrazno;
	if(polja[x][y]==Polje::Posjeceno) polja[x][y]=Polje::BlokiranoPosjeceno;
	if(polja[x][y]==Polje::Mina) polja[x][y]=Polje::BlokiranoMina;
}

void DeblokirajPolje(Tabla &polja, int x, int y) {
	if (x<0 || y<0 || x>=polja.size() || y>=polja.size()) {
		const std::string s("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
		throw std::domain_error(s);}
		
	if(polja[x][y]==Polje::BlokiranoPrazno) polja[x][y]=Polje::Prazno;
	if(polja[x][y]==Polje::BlokiranoPosjeceno) polja[x][y]=Polje::Posjeceno;
	if(polja[x][y]==Polje::BlokiranoMina) polja[x][y]=Polje::Mina;
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer) {
	
	if(smjer==Smjerovi::Desno) {
		if((x)<0 || (x)>=polja.size() || (y+1)<0 || (y+1)>=polja.size()) throw std::out_of_range("Izlazak van igrace table");
		if (polja[x][y+1]==Polje::BlokiranoPosjeceno || polja[x][y+1]==Polje::BlokiranoPrazno  || polja[x][y+1]==Polje::BlokiranoMina) 
		 throw std::logic_error("Blokirano polje");
		 polja[x][y]=Polje::Posjeceno;
		 y=y+1;
	}
	if(smjer==Smjerovi::Lijevo) {
		if((x)<0 || (x)>=polja.size() || (y-1)<0 || (y-1)>=polja.size()) throw std::out_of_range("Izlazak van igrace table");
		if (polja[x][y-1]==Polje::BlokiranoPosjeceno || polja[x][y-1]==Polje::BlokiranoPrazno  || polja[x][y-1]==Polje::BlokiranoMina) 
		 throw std::logic_error("Blokirano polje");
		 polja[x][y]=Polje::Posjeceno;
		 y=y-1;
	}
	if(smjer==Smjerovi::GoreLijevo) {
		if((x-1)<0 || (x-1)>=polja.size() || (y-1)<0 || (y-1)>=polja.size()) throw std::out_of_range("Izlazak van igrace table");
		if (polja[x-1][y-1]==Polje::BlokiranoPosjeceno || polja[x-1][y-1]==Polje::BlokiranoPrazno  || polja[x-1][y-1]==Polje::BlokiranoMina) 
		 throw std::logic_error("Blokirano polje");
		 polja[x][y]=Polje::Posjeceno;
		 x=x-1;
		 y=y-1;
	}
	if(smjer==Smjerovi::GoreDesno) {
		if((x-1)<0 || (x-1)>=polja.size() || (y+1)<0 || (y+1)>=polja.size()) throw std::out_of_range("Izlazak van igrace table");
		if (polja[x-1][y+1]==Polje::BlokiranoPosjeceno || polja[x-1][y+1]==Polje::BlokiranoPrazno  || polja[x-1][y+1]==Polje::BlokiranoMina) 
		 throw std::logic_error("Blokirano polje");
		 polja[x][y]=Polje::Posjeceno;
		 x=x-1;
		 y=y+1;
	}
	if(smjer==Smjerovi::Gore) {
		if((x-1)<0 || (x-1)>=polja.size() || (y)<0 || (y)>=polja.size()) throw std::out_of_range("Izlazak van igrace table");
		if (polja[x-1][y]==Polje::BlokiranoPosjeceno || polja[x-1][y]==Polje::BlokiranoPrazno  || polja[x-1][y]==Polje::BlokiranoMina) 
		 throw std::logic_error("Blokirano polje");
		 polja[x][y]=Polje::Posjeceno;
		 x=x-1;
		
	}
	if(smjer==Smjerovi::DoljeDesno) {
		if((x+1)<0 || (x+1)>=polja.size() || (y+1)<0 || (y+1)>=polja.size()) throw std::out_of_range("Izlazak van igrace table");
		if (polja[x+1][y+1]==Polje::BlokiranoPosjeceno || polja[x+1][y+1]==Polje::BlokiranoPrazno  || polja[x+1][y+1]==Polje::BlokiranoMina) 
		 throw std::logic_error("Blokirano polje");
		 polja[x][y]=Polje::Posjeceno;
		 x=x+1;
		 y=y+1;
	}
	if(smjer==Smjerovi::DoljeLijevo) {
		if((x+1)<0 || (x+1)>=polja.size() || (y-1)<0 || (y-1)>=polja.size()) throw std::out_of_range("Izlazak van igrace table");
		if (polja[x+1][y-1]==Polje::BlokiranoPosjeceno || polja[x+1][y-1]==Polje::BlokiranoPrazno  || polja[x+1][y-1]==Polje::BlokiranoMina) 
		 throw std::logic_error("Blokirano polje");
		 polja[x][y]=Polje::Posjeceno;
		 x=x+1;
		 y=y-1;
	}
	if(smjer==Smjerovi::Dolje) {
		if((x+1)<0 || (x+1)>=polja.size() || (y)<0 || (y)>=polja.size()) throw std::out_of_range("Izlazak van igrace table");
		if (polja[x+1][y]==Polje::BlokiranoPosjeceno || polja[x+1][y]==Polje::BlokiranoPrazno  || polja[x+1][y]==Polje::BlokiranoMina) 
		 throw std::logic_error("Blokirano polje");
		 polja[x][y]=Polje::Posjeceno;
		 x=x+1;
	}
	if(polja[x][y]==Polje::Mina){
		for(int i=0; i<polja.size(); i++) 
		for(int j=0; j<polja.size(); j++)
			polja[i][j]=Polje::Prazno;
		return Status::KrajPoraz;
	} 
	for(int i=0; i<polja.size(); i++) 
		for(int j=0; j<polja.size(); j++)
		if(polja[i][j]==Polje::Prazno) return Status::NijeKraj; //Provjeravamo je li ima i jedno prazno polje, ako ima nije kraj igre

	return Status::KrajPobjeda;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y) {
	if(novi_x<0 || novi_x>=polja.size() || novi_y<0 || novi_y>=polja.size()) throw std::out_of_range("Izlazak van igrace table");
		if (polja[novi_x][novi_y]==Polje::BlokiranoPosjeceno || polja[novi_x][novi_y]==Polje::BlokiranoPrazno  || polja[novi_x][novi_y]==Polje::BlokiranoMina) 
		 throw std::logic_error("Blokirano polje");
		 polja[x][y]=Polje::Posjeceno;
		 x=novi_x;
		 y=novi_y;
	if(polja[x][y]==Polje::Mina){
		for(int i=0; i<polja.size(); i++) 
		for(int j=0; j<polja.size(); j++)
			polja[i][j]=Polje::Prazno;
		return Status::KrajPoraz;
	} 
	for(int i=0; i<polja.size(); i++) 
		for(int j=0; j<polja.size(); j++)
		if(polja[i][j]==Polje::Prazno) return Status::NijeKraj; //Provjeravamo je li ima i jedno prazno polje, ako ima nije kraj igre

	return Status::KrajPobjeda;
}

void PrijaviGresku(KodoviGresaka k)  {
	if(k==KodoviGresaka::PogresnaKomanda) std::cout<<"Nerazumljiva komanda!"<<std::endl;
	if(k==KodoviGresaka::NedostajeParametar) std::cout<<"Komanda trazi parametar koji nije naveden!"<<std::endl;
	if(k==KodoviGresaka::NeispravanParametar) std::cout<<"Parametar komande nije ispravan!"<<std::endl;
	if(k==KodoviGresaka::SuvisanParametar) std::cout<<"Zadan je suvisan parametar nakon komande!"<<std::endl;
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska) {
	char komand[1000];
	std::cin.getline(komand, 100);
	char *kom=komand;
	char *kom1=kom;
	while(*kom1!='\0') {kom1++;}
	while(*kom==' ') kom++;
	if(*kom=='P') {
		kom++;
		while(*kom==' ') kom++;
		if(*(kom)=='1') {
			kom++;
			while(*kom==' ') kom++;
			if(*kom=='G' && *(kom+1)=='L') {
				kom++;
				kom++;
				while(*kom==' ') kom++;
				if(kom!=kom1) {greska=KodoviGresaka::SuvisanParametar; return false;}
				smjer=Smjerovi::GoreLijevo; 
				komanda=Komande::PomjeriJednoMjesto;
			}
			else if(*kom=='G' && *(kom+1)=='D') {
				kom++;
				kom++;
				while(*kom==' ') kom++;
				if(kom!=kom1) {greska=KodoviGresaka::SuvisanParametar; return false;}
				smjer=Smjerovi::GoreDesno; komanda=Komande::PomjeriJednoMjesto;}
			else if(*kom=='G') {
				kom++;
				while(*kom==' ') kom++;
				if(kom!=kom1) {greska=KodoviGresaka::SuvisanParametar; return false;}
				smjer=Smjerovi::Gore; komanda=Komande::PomjeriJednoMjesto;}
			else if(*kom=='D' && *(kom+1)=='o' && *(kom+2)=='D') {
				kom=kom+3;
				while(*kom==' ') kom++;
				if(kom!=kom1) {greska=KodoviGresaka::SuvisanParametar; return false;}
				smjer=Smjerovi::DoljeDesno; komanda=Komande::PomjeriJednoMjesto;}
			else if(*kom=='D' && *(kom+1)=='o' && *(kom+2)=='L') {
				kom=kom+3;
				while(*kom==' ') kom++;
				if(kom!=kom1) {greska=KodoviGresaka::SuvisanParametar; return false;}
				smjer=Smjerovi::DoljeLijevo; komanda=Komande::PomjeriJednoMjesto;}
			else if(*kom=='D' && *(kom+1)=='o') {
				kom++;
				kom++;
				while(*kom==' ') kom++;
				if(kom!=kom1) {greska=KodoviGresaka::SuvisanParametar; return false;}
				smjer=Smjerovi::Dolje; komanda=Komande::PomjeriJednoMjesto;}
			else if(*kom=='L') {
				kom++;
				while(*kom==' ') kom++;
				if(kom!=kom1) {greska=KodoviGresaka::SuvisanParametar; return false;}
				smjer=Smjerovi::Lijevo; komanda=Komande::PomjeriJednoMjesto;}
			else if(*kom=='D') {
				kom++;
				while(*kom==' ') kom++;
				if(kom!=kom1) {greska=KodoviGresaka::SuvisanParametar; return false;}
				smjer=Smjerovi::Desno; komanda=Komande::PomjeriJednoMjesto;}
			else if(kom==kom1) {greska=KodoviGresaka::NedostajeParametar; return false;}
			else {greska=KodoviGresaka::NeispravanParametar; return false;}
		}
	
		else if(*kom=='>') {
			kom++;
			while(*kom==' ') kom++;
			int brojac=0;
			if(kom==kom1) {greska=KodoviGresaka::NedostajeParametar; return false;}
			if(*kom>='0' && *kom<='9') {
				while (*kom>='0' && *kom<='9') {kom++; brojac++;}
				x=0;
				while(brojac!=0) {
					x=pow(10,(brojac-1))*(*(kom-brojac)-'0')+x;
					brojac--;
				}	
			}
			else if(kom==kom1) {greska=KodoviGresaka::NedostajeParametar; return false;}
			else {greska=KodoviGresaka::NeispravanParametar; return false;}
		while(*kom==' ') kom++;
			brojac=0;
			if(*kom>='0' && *kom<='9') {
				while (*kom>='0' && *kom<='9') {kom++; brojac++;}
				y=0;
				while(brojac!=0) {
					y=pow(10,(brojac-1))*(*(kom-brojac)-'0')+y;
					brojac--;
				}
			/*	std::cout<<x<<" "<<y;*/
			}

			else {greska=KodoviGresaka::NeispravanParametar; return false;}
			komanda=Komande::PomjeriDalje;
		}
		else if(*kom=='O') {
			kom++;
			while(*kom==' ') kom++;
			if(kom==kom1) komanda=Komande::PrikaziOkolinu;
			else {greska=KodoviGresaka::PogresnaKomanda; return false;}
		}
		else {greska=KodoviGresaka::PogresnaKomanda; return false;}
	}
	else if(*kom=='B') {
		kom++;
			while(*kom==' ') kom++;
			int brojac=0;
			if(kom==kom1) {greska=KodoviGresaka::NedostajeParametar; return false;}
			if(*kom>='0' && *kom<='9') {
				while (*kom>='0' && *kom<='9') {kom++; brojac++;}
				x=0;
				while(brojac!=0) {
					x=pow(10,(brojac-1))*(*(kom-brojac)-'0')+x;
					brojac--;
				}	
			}
			else if(kom==kom1) {greska=KodoviGresaka::NedostajeParametar; return false;}
			else {greska=KodoviGresaka::PogresnaKomanda; return false;}
			while(*kom==' ') kom++;
			brojac=0;
			if(*kom>='0' && *kom<='9') {
				while (*kom>='0' && *kom<='9') {kom++; brojac++;}
				y=0;
				while(brojac!=0) {
					y=pow(10,(brojac-1))*(*(kom-brojac)-'0')+y;
					brojac--;
				}
			}
			else {greska=KodoviGresaka::PogresnaKomanda; return false;}
			komanda=Komande::Blokiraj;
		}
		else if(*kom=='D') {
		kom++;
			while(*kom==' ') kom++;
			int brojac=0;
			if(kom==kom1) {greska=KodoviGresaka::NedostajeParametar; return false;}
			if(*kom>='0' && *kom<='9') {
				while (*kom>='0' && *kom<='9') {kom++; brojac++;}
				x=0;
				while(brojac!=0) {
					x=pow(10,(brojac-1))*(*(kom-brojac)-'0')+x;
					brojac--;
				}	
			}
			else if(kom==kom1) {greska=KodoviGresaka::NedostajeParametar; return false;}
			else {greska=KodoviGresaka::PogresnaKomanda; return false;}
			while(*kom==' ') kom++;
			brojac=0;
			if(*kom>='0' && *kom<='9') {
				while (*kom>='0' && *kom<='9') {kom++; brojac++;}
				y=0;
				while(brojac!=0) {
					y=pow(10,(brojac-1))*(*(kom-brojac)-'0')+y;
					brojac--;
				}
			}
			else {greska=KodoviGresaka::PogresnaKomanda; return false;}
			komanda=Komande::Deblokiraj;
		}
		else if(*kom=='Z') {
			kom++;
			while(*kom==' ') kom++;
			if(kom==kom1) komanda=Komande::ZavrsiIgru;
			else {greska=KodoviGresaka::PogresnaKomanda; return false;}
		}
		else if(*kom=='K') {
			kom++;
			while(*kom==' ') kom++;
			if(kom!=kom1) {greska=KodoviGresaka::SuvisanParametar; return false;}
			if(kom==kom1) komanda=Komande::KreirajIgru;
			
		}
		else {greska=KodoviGresaka::PogresnaKomanda; return false;}
	
	
	return true;
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0) {
	
	if(komanda==Komande::PomjeriJednoMjesto) {
		Status s=Idi(polja, x, y, p_smjer);
		if (s==Status::KrajPobjeda) {std::cout<<"Bravo, obisli ste sva sigurna polja"<<std::endl;
		for(int i=0; i<polja.size(); i++) 
		for(int j=0; j<polja.size(); j++)
			polja[i][j]=Polje::Prazno;
			throw std::runtime_error("Igra zavrsena");
		}
		else if(s==Status::KrajPoraz) {std::cout<<"Nagazili ste na minu"<<std::endl;
		for(int i=0; i<polja.size(); i++) 
		for(int j=0; j<polja.size(); j++)
			polja[i][j]=Polje::Prazno;
			throw std::runtime_error("Igra zavrsena");
		}
		std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
	}
	else if(komanda==Komande::PomjeriDalje) {
		Status s=Idi(polja, x, y, p_x, p_y);
		if (s==Status::KrajPobjeda) {std::cout<<"Bravo, obisli ste sva sigurna polja"<<std::endl;
		for(int i=0; i<polja.size(); i++) 
		for(int j=0; j<polja.size(); j++)
			polja[i][j]=Polje::Prazno;
			throw std::runtime_error("Igra zavrsena");
		}
		else if(s==Status::KrajPoraz) {std::cout<<"Nagazili ste na minu"<<std::endl;
		for(int i=0; i<polja.size(); i++) 
		for(int j=0; j<polja.size(); j++)
			polja[i][j]=Polje::Prazno;
			throw std::runtime_error("Igra zavrsena");
		}
		std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
	}
	
	else if(komanda==Komande::Blokiraj) {
		BlokirajPolje(polja, x, y);
	}
	else if(komanda==Komande::Deblokiraj) {
		DeblokirajPolje(polja, x, y);
	}
	else if(komanda==Komande::ZavrsiIgru) {
		for(int i=0; i<polja.size(); i++) 
			for(int j=0; j<polja.size(); j++)
				polja[i][j]=Polje::Prazno;
			throw std::runtime_error("Igra zavrsena");
	}
	else if(komanda==Komande::PrikaziOkolinu) {
		std::vector<std::vector<int>> mat=PrikaziOkolinu(polja, x, y);
		for(int i=0; i<mat.size();i++) {
			for(int j=0; j<mat[0].size(); j++) {
				std::cout<<mat[i][j]<<" ";
			}
			std::cout<<std::endl;
		}
	}
	else if(komanda==Komande::KreirajIgru) {
		std::cout<<"Unesite broj polja: ";
		int n;
		std::cin>>n;
		std::cin.ignore(1000, '\n');
		std::cin.clear();
		std::cout<<"Unesite pozicije mina: ";
		char string[100];
		char* s=string;
		int red=0;
		int prvi, drugi;
		std::vector<std::vector<int>> mine;
	for(;;) {
	a:	std::cin.getline(s,100);
		while(*s==' ') s++;
		if(*s=='.') break;
		if(*s!='(') {std::cout<<"Greska, unesite ponovo!"<<std::endl; goto a;}
		else s++;
		if(*s<'0' || *s>'9') {std::cout<<"Greska, unesite ponovo!"<<std::endl; goto a;}
		else{
			int brojac=0;
			while (*s>='0' && *s<='9') {s++; brojac++;}
				prvi=0;
				while(brojac!=0) {
					prvi=pow(10,(brojac-1))*(*(s-brojac)-'0')+prvi;								//PROMJENA
					brojac--;
				}	
		}
		if(*s!=',') {std::cout<<"Greska, unesite ponovo!"<<std::endl; goto a;}
		else s++;
		if(*s<'0' || *s>'9') {std::cout<<"Greska, unesite ponovo!"<<std::endl; goto a;}
		else{
			int brojac=0;
			while (*s>='0' && *s<='9') {s++; brojac++;}
				drugi=0;
				while(brojac!=0) {
					drugi=pow(10,(brojac-1))*(*(s-brojac)-'0')+drugi;							//PROMJENA
					brojac--;
				}	
		}
		if(*s!=')') {std::cout<<"Greska, unesite ponovo!"<<std::endl; goto a;}
		else s++;
		while(*s==' ') s++;
		if(*s=='\0') {
			if(prvi>=n || drugi>=n) {std::cout<<"Greska, unesite ponovo!"<<std::endl; s++; goto a;}
			else {
			mine.resize(red+1);
			mine[red].resize(2);
			mine[red][0]=prvi;
			mine[red][1]=drugi;
			red++;
	
			goto a; }
		}
		else {std::cout<<"Greska, unesite ponovo!"<<std::endl; goto a;}
		
	}
	polja=KreirajIgru(n, mine);
	}

}



int main ()
{
	try {

	Komande kom; 
	Smjerovi smjer;
	int x=0; 
	int y=0;
	int x1, y1;
	Tabla polja;
	KodoviGresaka greska;
	for(;;){
	std::cout<<"Unesite komandu: ";
	try{
	bool a=UnosKomande(kom, smjer, x, y, greska);
	x1=x; y1=y;
	if (a==false) {PrijaviGresku(greska);}
	else IzvrsiKomandu(kom, polja, x, y, smjer, x1, y1);
	}
	catch(std::logic_error m){std::cout<<m.what()<<std::endl;}
	catch(std::domain_error m){std::cout<<m.what()<<std::endl;}
		}		
			
		}
	catch(std::runtime_error) { std::cout<<"Dovidjenja!"; }
	return 0;
	
}
	
	
	
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <new>
#include <stdexcept>
#include <string>

enum class Polje { Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina };
enum class Smjerovi { GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo };
enum class Status { NijeKraj, KrajPoraz, KrajPobjeda };
enum class KodoviGresaka { PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar };
enum class Komande { PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru };

typedef std::vector<std::vector<Polje>> Tabla;
Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine) {
	Tabla a;
	 a=std::vector<std::vector<Polje>> (n,std::vector<Polje> (n));
	 for(int j=0;j<n;j++) {
	     for(int k=0;k<n;k++) {
	         a[j][k]=Polje::Prazno;
	     }
	 }
	 try   {
	         for(std::vector<int> b: mine) {
	             if(b.size()<2) {
	                 throw std::domain_error("Ilegalan format zadavanja mina");
	             }
	             else {
	                 std::vector<int> c(b);
	                 for(int d=0;d<c.size();d++){
	                     if(c[d]>=n) {
	                     throw std::domain_error ("Ilegalne pozicije mina");
	                 }
	             }
	          
	             a[b[0]][b[1]]=Polje::Mina;
	     }
	         }
	 }
	catch(std::domain_error e) {
		std::cout<<e.what()<<std::endl; 
	}
	return a;
	}
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja,int x,int y) {
    if(x>=polja.size() || y>=polja.size()) {
    	throw std::domain_error("Polje (a,b) ne postoji" );
    }
    std::vector<std::vector<int>> h(3,std::vector<int>(3,0));
     int z(0),m(0),o(0),r(0);
      int n(0),q(0),p(0),w(0);
    for(int i=x-1;i<x+2;i++) {
       for(int j=y-1;j<y+2;j++) {
      if(x>0 && y>0) {
         int broj=0;
     
      if(polja[x-1][y-1]==Polje::Mina) broj++;
     if(polja[x-1][y]==Polje::Mina) broj++;
     if(polja[x-1][y+1]==Polje::Mina) broj++;
     
     if(polja[x][y-1]==Polje::Mina) broj++;
     if(polja[x][y]==Polje::Mina) broj++;
     if(polja[x][y+1]==Polje::Mina) broj++;
     
     if(polja[x+1][y-1]==Polje::Mina) broj++;
     if(polja[x+1][y]==Polje::Mina) broj++;
     if(polja[x+1][y+1]==Polje::Mina) broj++;
    
     h[m][n]=broj;
      }
      	if(x==0 && y>0) {
      	int	mina=0;
      		if(polja[x][y-1]==Polje::Mina) mina++;
      		if(polja[x][y+1]==Polje::Mina) mina++;
      		
      		if(polja[x+1][y-1]==Polje::Mina) mina++;
      		if(polja[x+1][y]==Polje::Mina) mina++;
      		if(polja[x+1][y+1]==Polje::Mina) mina++;
      		h[z][q]=mina;
      	}
        		if(y==0 && x>0) {
                   int ponavljanje=0;
      			 if(polja[x-1][y]==Polje::Mina) ponavljanje++;
      			 if(polja[x-1][y+1]==Polje::Mina) ponavljanje++;
      			 
      			 if(polja[x][y+1]==Polje::Mina) ponavljanje++;
      			 if(polja[x+1][y]==Polje::Mina) ponavljanje++;
      			 if(polja[x+1][y+1]==Polje::Mina) ponavljanje++;
      			
      			 h[r][w]=ponavljanje;
        		}
           		if(x==0 && y==0) {
          			int kopije(0);
      			if(polja[x][y+1]==Polje::Mina) kopije++;
      			if(polja[x+1][y]==Polje::Mina) kopije++;
      			if(polja[x+1][y+1]==Polje::Mina) kopije++;
           	
           	h[o][p]=kopije;
           		}
      	n++; q++;
    		w++; p++;
     }
      z++;
    m++;
    o++;
    r++;
     }
return h;
}
void BlokirajPolje(Tabla &polja,int x,int y) {
for(int i=0;i<3;i++) {
	if(Polje(i)==polja[x][y]) {
		polja[x][y]=Polje(i+3);
}
}
}
void DeblokirajPolje(Tabla &polja,int x,int y) {
for(int j=3;j<6;j++) {
	if(Polje(j)==polja[x][y]) { 
		polja[x][y]=Polje(j-3);
}
}
}

Status Idi(Tabla &polja,int &x,int &y,Smjerovi smjer) {
switch(smjer) {
	case Smjerovi::GoreLijevo:
	polja[x][y]=Polje::Posjeceno;
	x-=1;
	y-=1;
	break;
	case Smjerovi::Gore:
	polja[x][y]=Polje::Posjeceno;
	x-=1;
	break;
	case Smjerovi::GoreDesno:
	polja[x][y]=Polje::Posjeceno;
	x-=1;
	y+=1;
	break;
	case Smjerovi::Desno:
	polja[x][y]=Polje::Posjeceno;
	y+=1;
	break;
	case Smjerovi::DoljeDesno:
	polja[x][y]=Polje::Posjeceno;
	x+=1;
	y+=1;
	break;
	case Smjerovi::Dolje:
	polja[x][y]=Polje::Posjeceno;
	x+=1;
	break;
	case Smjerovi::DoljeLijevo:
	polja[x][y]=Polje::Posjeceno;
	x+=1;
	y-=1;
	break;
	case Smjerovi::Lijevo:
	polja[x][y]=Polje::Posjeceno;
	y-=1;
	break;
	default:
	break;
}
if(polja[x][y]==Polje::Mina) {
for(int j=0;j<polja.size();j++) {
	for(int k=0;k<polja.size();k++) {
	         polja[j][k]=Polje::Prazno;
	     }
}
return Status::KrajPoraz;
}
else {
	int broj=0;
	for(int i=0;i<polja.size();i++) {
	for(int j=0;j<polja.size();j++) { 
		if(polja[i][j]==Polje::Prazno)
		broj++;
 	}
	}
	if(broj==0) return Status::KrajPobjeda;
	else 
	return Status::NijeKraj;
	}
}
Status Idi(Tabla &polja,int &x,int &y,int novi_x,int novi_y) {
	try {
	if(novi_x>=polja.size() || novi_y>=polja.size()) throw std::out_of_range("Izlazak van igrace table");
	else  {
		if(polja[novi_x][novi_y]==Polje::BlokiranoPrazno)
		throw std::logic_error("Blokirano polje");
	}
	polja[x][y]=Polje::Posjeceno;
	x=novi_x;
	y=novi_y;
	}
catch(std::logic_error e) {
	std::cout<<e.what()<<std::endl;
}
catch(std::out_of_range d) {
	std::cout<<d.what()<<std::endl;
}
if(polja[x][y]==Polje::Mina) {
for(int j=0;j<polja.size();j++) {
	for(int k=0;k<polja.size();k++) {
	         polja[j][k]=Polje::Prazno;
	     }
}
return Status::KrajPoraz;
}
else {
	int broj=0;
	for(int i=0;i<polja.size();i++) {
	for(int j=0;j<polja.size();j++) { 
		if(polja[i][j]==Polje::Prazno)
		broj++;
 	}
	}
	if(broj==0) return Status::KrajPobjeda;
	else 
	return Status::NijeKraj;
	}
}
KodoviGresaka PrijaviGresku(KodoviGresaka greska) {
	for(int i=0;i<4;i++) {
		if(KodoviGresaka(i)==greska) {
			return greska;
		}
	}
}
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y,KodoviGresaka &greska) {
	
	if((komanda<Komande(0) && komanda>=Komande(6)) || (smjer<Smjerovi(0) && smjer>=Smjerovi(7)) || (greska<KodoviGresaka(0) && greska>=KodoviGresaka(3)))
	return false;
	else return true;
}
void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y,
 Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0) {
 	std::vector<std::vector<int>> m;
 	for(int i=0;i<6;i++) {
 		if(Komande(i)==komanda) {
 		Idi(polja,x,y,p_smjer);
 		BlokirajPolje(polja,x,y);
 	m = PrikaziOkolinu(polja,x,y);
 		}
 	}
 }

int main ()
{
	Tabla igra;
	std::vector<std::vector<int>> v;
	int n,x,y;
	 do {
	std::cout<<"Unesite komandu: ";
std::string unos;
std::getline(std::cin,unos);

std::cin>>x;
std::cin>>y;

Komande zadatak{Komande(n)};
Smjerovi uputa{Smjerovi(n)};
KodoviGresaka greska{KodoviGresaka(n)};
	std::cout<<"Unesite broj polja: ";
	int g;
	std::cin>>g;
	v.resize(g);
	std::cout<<"Unesite pozicije mina: ";
	for(int i=0;i<g;i++) {
		for(int j=0;j<2;j++) {
		v[i].resize(2);
		std::cin>>v[i][j];
	while(v[i][j]>=n)  {
		std::cout<<"Greska, unesite ponovo!"<<std::endl;
		v[i][j]=0;
	}
	}
	}
if(UnosKomande(zadatak,uputa,x,y,greska)) {
	igra=KreirajIgru(n,v);
	IzvrsiKomandu(Komande(n),igra,x,y,uputa);
}
else {
	PrijaviGresku(KodoviGresaka(n));
}
}while(Idi(igra,x,y,Smjerovi(n))!=Status::KrajPoraz);
	return 0;
}
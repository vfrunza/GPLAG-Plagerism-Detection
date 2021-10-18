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

enum class Polje {Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina};
enum class Smjerovi {GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo};
enum class Status {NijeKraj, KrajPoraz, KrajPobjeda};
enum class KodoviGresaka {PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar};
enum class Komande {PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru};
typedef std::vector<std::vector<Polje>> Tabla;

bool Blokirano(Polje polje) {
	
	if(polje==Polje::BlokiranoPosjeceno || polje==Polje::BlokiranoPrazno || polje==Polje::BlokiranoMina)
	return true;
	return false;
}

void PostaviPrazno (Tabla &polja) {

for(int i=0;i<polja.size();i++) 
for(int j=0;j<polja[i].size();j++)
polja[i][j]=Polje::Prazno;

}

bool Pobjeda (Tabla &polja,int x, int y) {
	for(int i=0;i<polja.size();i++)
	for(int j=0;j<polja[i].size();j++)
	if(polja[i][j]==Polje::Prazno && i!=x && i!=y)
	return false;
	
	return true;
}


Tabla KreirajIgru (int n, const std::vector<std::vector<int>> &mine) {
	
	if(n<=0) throw std::domain_error("Ilegalna velicina");
	Tabla tabla (n,std::vector<Polje> (n,Polje::Prazno));
	for(int i=0;i<mine.size();i++) {
		if(mine[i].size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
		if(mine[i][0]>=tabla.size() || mine[i][1]>=tabla[mine[i][0]].size()) throw std::domain_error("Ilegalne pozicije mina");
		tabla[mine[i][0]][mine[i][1]]=Polje::Mina;
	}

	return tabla;
}

std::vector<std::vector<int>> PrikaziOkolinu (const Tabla &polja, int x, int y) {

if(x>=polja.size() || y>=polja[0].size())  {
	char x='0'+x; char y='0'+y;
	std::string poruka=std::string()+"Polje " + "("+x+","+y+")"+" ne postoji";
	throw std::domain_error(poruka);
}

std::vector<std::vector<int>> matrica(3,std::vector<int>(3,0));

for(int i=-1;i<2;i++) {

for(int j=-1;j<2;j++) {
int brojac=0;
if(x+i<polja.size() && x+i>=0 && y+j<polja[0].size() && y+j>=0) {

for(int k=-1;k<2;k++) {
	
	for(int m=-1;m<2;m++) {
	if( x+i+k>=0 && x+i+k<polja.size() && y+j+m>=0 && y+j+m<polja[0].size()&& polja[x+i+k][y+j+m]==Polje::Mina && (m!=0 || k!=0) ) brojac++;
	
	}
}

}
matrica[i+1][j+1]=brojac;
}

}

return matrica;
}

void BlokirajPolje(Tabla &polja, int x, int y) {

if(x>=polja.size() || y>=polja[0].size())  {
	char x='0'+x; char y='0'+y;
	std::string poruka=std::string()+"Polje " + "("+x+","+y+")"+" ne postoji";
	throw std::domain_error(poruka);
	
}

if(polja[x][y]!=Polje::BlokiranoPrazno &&polja[x][y]!=Polje::BlokiranoPosjeceno&&polja[x][y]!=Polje::BlokiranoMina) {

if(polja[x][y]==Polje::Prazno)polja[x][y]=Polje::BlokiranoPrazno;
if(polja[x][y]==Polje::Posjeceno)polja[x][y]=Polje::BlokiranoPosjeceno;
if(polja[x][y]==Polje::Mina)polja[x][y]=Polje::BlokiranoMina;	
}

}

void DeblokirajPolje(Tabla &polja, int x, int y) {

if(x>=polja.size() || y>=polja[0].size())  {
	char x='0'+x; char y='0'+y;
	std::string poruka=std::string()+"Polje " + "("+x+","+y+")"+" ne postoji";
	throw std::domain_error(poruka);
}

if(polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoPosjeceno || polja[x][y]==Polje::BlokiranoMina) {
	
if(polja[x][y]==Polje::BlokiranoPrazno)polja[x][y]=Polje::Prazno;
if(polja[x][y]==Polje::BlokiranoPosjeceno)polja[x][y]=Polje::Posjeceno;
if(polja[x][y]==Polje::BlokiranoMina)polja[x][y]=Polje::Mina;

}

}

Status Idi (Tabla &polja, int&x,int&y, Smjerovi smjer) {


if(smjer==Smjerovi::Lijevo){
	if(y-1<0) throw std::out_of_range("Izlazak van igrace table");
	if(Blokirano(polja[x][y-1])) throw std::logic_error("Blokirano polje");
	if(polja[x][y-1]==Polje::Mina) {
		PostaviPrazno(polja);
		return Status::KrajPoraz;
	}
	polja[x][y]=Polje::Posjeceno;
	y=y-1;
	
if (Pobjeda(polja,x,y)) return Status::KrajPobjeda;
}

else if(smjer==Smjerovi::GoreLijevo){
	if(x-1<0 || y-1<0) throw std::out_of_range("Izlazak van igrace table");
	if(Blokirano(polja[x-1][y-1])) throw std::logic_error("Blokirano polje");
	if(polja[x-1][y-1]==Polje::Mina) {
		PostaviPrazno(polja);
		return Status::KrajPoraz;
	}
	polja[x][y]=Polje::Posjeceno;
	x=x-1;y=y-1;
	
if (Pobjeda(polja,x,y)) return Status::KrajPobjeda;
}

else if(smjer==Smjerovi::Gore){
	if(x-1<0) throw std::out_of_range("Izlazak van igrace table");
	if(Blokirano(polja[x-1][y])) throw std::logic_error("Blokirano polje");
	if(polja[x-1][y]==Polje::Mina) {
		PostaviPrazno(polja);
		return Status::KrajPoraz;
	}
	polja[x][y]=Polje::Posjeceno;
    x=x-1;
    
if (Pobjeda(polja,x,y)) return Status::KrajPobjeda;
}

else if(smjer==Smjerovi::GoreDesno){
	if(x-1<0 || y+1>=polja[0].size()) throw std::out_of_range("Izlazak van igrace table");
	if(Blokirano(polja[x-1][y+1])) throw std::logic_error("Blokirano polje");
	if(polja[x-1][y+1]==Polje::Mina) {
		PostaviPrazno(polja);
		return Status::KrajPoraz;
	}
	polja[x][y]=Polje::Posjeceno;
	x=x-1;y=y+1;
	
if (Pobjeda(polja,x,y)) return Status::KrajPobjeda;
}

else if(smjer==Smjerovi::Desno){
	if(y+1>=polja[x].size()) throw std::out_of_range("Izlazak van igrace table");
	if(Blokirano(polja[x][y+1])) throw std::logic_error("Blokirano polje");
	if(polja[x][y+1]==Polje::Mina) {
		PostaviPrazno(polja);
		return Status::KrajPoraz;
	}
	polja[x][y]=Polje::Posjeceno;
    y=y+1;
	
if (Pobjeda(polja,x,y)) return Status::KrajPobjeda;
}

else if(smjer==Smjerovi::DoljeDesno){
	if(x+1>=polja.size() || y+1>=polja[0].size()) throw std::out_of_range("Izlazak van igrace table");
	if(Blokirano(polja[x+1][y+1])) throw std::logic_error("Blokirano polje");
	if(polja[x+1][y+1]==Polje::Mina) {
		PostaviPrazno(polja);
		return Status::KrajPoraz;
	}
	polja[x][y]=Polje::Posjeceno;
    y=y+1;x=x+1;
	
if (Pobjeda(polja,x,y)) return Status::KrajPobjeda;
}

else if(smjer==Smjerovi::Dolje){
	if(x+1>=polja.size()) throw std::out_of_range("Izlazak van igrace table");
	if(Blokirano(polja[x+1][y])) throw std::logic_error("Blokirano polje");
	if(polja[x+1][y]==Polje::Mina) {
		PostaviPrazno(polja);
		return Status::KrajPoraz;
	}
	polja[x][y]=Polje::Posjeceno;
   x=x+1;
	
if (Pobjeda(polja,x,y)) return Status::KrajPobjeda;
}

else if(smjer==Smjerovi::DoljeLijevo){
	if(x+1>=polja.size() || y-1<0) throw std::out_of_range("Izlazak van igrace table");
	if(Blokirano(polja[x+1][y-1])) throw std::logic_error("Blokirano polje");
	if(polja[x+1][y-1]==Polje::Mina) {
		PostaviPrazno(polja);
		return Status::KrajPoraz;
	}
	polja[x][y]=Polje::Posjeceno;
    y=y-1;x=x+1;
	
if (Pobjeda(polja,x,y)) return Status::KrajPobjeda;
}



return Status::NijeKraj;
}


Status Idi (Tabla &polja, int&x, int&y, int novi_x, int novi_y) {

if(novi_x>=polja[0].size() || novi_x <0 || novi_y>=polja.size() || novi_y<0) throw std::out_of_range("Izlazak van igrace table");
if(Blokirano(polja[novi_x][novi_y])) throw std::logic_error("Blokirano polje");
if(polja[novi_x][novi_y]==Polje::Mina) {
	PostaviPrazno(polja);
	return Status::KrajPoraz;
}


polja[x][y]=Polje::Posjeceno;
x=novi_x;y=novi_y;
if(Pobjeda(polja,x,y)) return Status::KrajPobjeda;

return Status::NijeKraj;
}


void PrijaviGresku (KodoviGresaka greska) {

if(greska==KodoviGresaka::PogresnaKomanda) std::cout<<"Nerazumljiva komanda!"<<std::endl;
else if(greska==KodoviGresaka::NedostajeParametar) std::cout<<"Komanda trazi parametar koji nije naveden!"<<std::endl;
else if(greska==KodoviGresaka::NeispravanParametar) std::cout<<"Parametar komande nije ispravan!"<<std::endl;
else if(greska==KodoviGresaka::SuvisanParametar) std::cout<<"Zadan je suvisan parametar nakon komande!"<<std::endl;

}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int&x, int&y, KodoviGresaka &greska){

std::string rijec;
std::getline(std::cin,rijec);
int i=0;
	
	while(i<rijec.size() &&rijec[i]==' ')i++;
	if(i==rijec.size()) {greska=KodoviGresaka::PogresnaKomanda;return false;}
	if(rijec[i]=='P') {
		i++;
		 
		
		if(rijec[i]=='1') {
			i++;
			while(i<rijec.size() && rijec[i]==' ') i++;
			if(i==rijec.size()) {greska=KodoviGresaka::NedostajeParametar; return false;}
			

			if(rijec[i]=='G') {
			i++;
		
				if(i<rijec.size() && (rijec[i]='D' || rijec[i]=='L')) {
					char a=rijec[i];
					i++;
			while(i<rijec.size()&&rijec[i]==' ') i++;
			if(i==rijec.size()) {
				if(a=='D')smjer=Smjerovi::GoreDesno;komanda=Komande::PomjeriJednoMjesto; return true;
				if(a=='L')smjer=Smjerovi::GoreLijevo;komanda=Komande::PomjeriJednoMjesto;return true;
				}
			else {greska=KodoviGresaka::NeispravanParametar; return false;}
		   }
			
			while(i<rijec.size() && rijec[i]==' ')i++;
			if(i==rijec.size()) {smjer=Smjerovi::Gore;komanda=Komande::PomjeriJednoMjesto; return true;}
			else {greska=KodoviGresaka::NeispravanParametar; return false;}
			
			}
			
			if(rijec[i]=='D') {
			i++;
		
			if(i<rijec.size() && rijec[i]=='o') {
				i++;
				
				if(i<rijec.size() && (rijec[i]='D' || rijec[i]=='L')) {
					char a=rijec[i];
					i++;
			while(i<rijec.size()&&rijec[i]==' ') i++;
			if(i==rijec.size()) {
				if(a=='D')smjer=Smjerovi::DoljeDesno; komanda=Komande::PomjeriJednoMjesto;return true;
				if(a=='L')smjer=Smjerovi::DoljeLijevo;komanda=Komande::PomjeriJednoMjesto;return true;
				}
			else {greska=KodoviGresaka::NeispravanParametar; return false;}
		   }
		   
		   while(i<rijec.size() && rijec[i]==' ')i++;
			if(i==rijec.size()) {smjer=Smjerovi::Dolje;komanda=Komande::PomjeriJednoMjesto; return true;}
			else {greska=KodoviGresaka::NeispravanParametar; return false;}
	    }
	    
	     while(i<rijec.size() && rijec[i]==' ')i++;
			if(i==rijec.size()) {smjer=Smjerovi::Desno;komanda=Komande::PomjeriJednoMjesto; return true;}
			else {greska=KodoviGresaka::NeispravanParametar; return false;}
}

     if(rijec[i]=='L') {
     	 while(i<rijec.size() && rijec[i]==' ')i++;
			if(i==rijec.size()) {smjer=Smjerovi::Lijevo;komanda=Komande::PomjeriJednoMjesto; return true;}
			else {greska=KodoviGresaka::NeispravanParametar; return false;}
     }

else {greska=KodoviGresaka::NeispravanParametar; return false;}

}//p1 uslov


if(rijec[i]=='>') {

i++;
while(i<rijec.size() && rijec[i]==' ')i++;
if(i==rijec.size()) {greska=KodoviGresaka::NedostajeParametar; return false;}
int pomocnix=0,pomocniy=0;

while(i<rijec.size()&&'0'<=rijec[i] && rijec[i]<='9') {pomocnix*=10; pomocnix=pomocnix+rijec[i]-48; i++; }

if(i==rijec.size()) {greska=KodoviGresaka::NedostajeParametar; return false;}

if(rijec[i]==' ') {
	while(i<rijec.size() && rijec[i]==' ')i++;
	if(i==rijec.size()){greska=KodoviGresaka::NedostajeParametar;return false;}
	while(i<rijec.size() && '0'<=rijec[i] && rijec[i]<='9') {pomocniy*=10; pomocniy=pomocniy+rijec[i]-48;i++;}
	while(i<rijec.size() && rijec[i]==' ')i++;
	if(i!=rijec.size()){greska=KodoviGresaka::NeispravanParametar; return false; }
	else {
		x=pomocnix; y=pomocniy;komanda=Komande::PomjeriDalje; return true;
	}
}

else {greska=KodoviGresaka::NeispravanParametar; return false;}

}//>uslov

if(rijec[i]=='O') {
i++;
while(i<rijec.size() && rijec[i]==' ')i++;
if(i!=rijec.size()) {greska=KodoviGresaka::PogresnaKomanda; return false;}
komanda=Komande::PrikaziOkolinu; return true;

}

else {greska=KodoviGresaka::PogresnaKomanda; return false;}

}  //p uslov

if(rijec[i]=='B') {


i++;
while(i<rijec.size() && rijec[i]==' ')i++;
if(i==rijec.size()) {greska=KodoviGresaka::NedostajeParametar; return false;}
int pomocnix=0,pomocniy=0;

while(i<rijec.size()&&'0'<=rijec[i] && rijec[i]<='9') {pomocnix*=10; pomocnix=pomocnix+rijec[i]-48; i++; }

if(i==rijec.size()) {greska=KodoviGresaka::NedostajeParametar; return false;}

if(rijec[i]==' ') {
	while(i<rijec.size() && rijec[i]==' ')i++;
	if(i==rijec.size()){greska=KodoviGresaka::NedostajeParametar;return false;}
	while(i<rijec.size() && '0'<=rijec[i] && rijec[i]<='9') {pomocniy*=10; pomocniy=pomocniy+rijec[i]-48;i++;}
	while(i<rijec.size() && rijec[i]==' ')i++;
	if(i!=rijec.size()){greska=KodoviGresaka::NeispravanParametar; return false; }
	else {
		x=pomocnix; y=pomocniy;komanda=Komande::Blokiraj; return true;
	}
}

else {greska=KodoviGresaka::NeispravanParametar; return false;}

}

if(rijec[i]=='D') {
i++;
while(i<rijec.size() && rijec[i]==' ')i++;
if(i==rijec.size()) {greska=KodoviGresaka::NedostajeParametar; return false;}
int pomocnix=0,pomocniy=0;

while(i<rijec.size()&&'0'<=rijec[i] && rijec[i]<='9') {pomocnix*=10; pomocnix=pomocnix+rijec[i]-48; i++; }

if(i==rijec.size()) {greska=KodoviGresaka::NedostajeParametar; return false;}

if(rijec[i]==' ') {
	while(i<rijec.size() && rijec[i]==' ')i++;
	if(i==rijec.size()){greska=KodoviGresaka::NedostajeParametar;return false;}
	while(i<rijec.size() && '0'<=rijec[i] && rijec[i]<='9') {pomocniy*=10; pomocniy=pomocniy+rijec[i]-48;i++;}
	while(i<rijec.size() && rijec[i]==' ')i++;
	if(i!=rijec.size()){greska=KodoviGresaka::NeispravanParametar; return false; }
	else {
		x=pomocnix; y=pomocniy;komanda=Komande::Deblokiraj; return true;
	}
}

else {greska=KodoviGresaka::NeispravanParametar; return false;}

}


if(rijec[i]=='Z') {
	i++;
while(i<rijec.size() && rijec[i]==' ')i++;
if(i!=rijec.size()) {greska=KodoviGresaka::PogresnaKomanda; return false;}

komanda=Komande::ZavrsiIgru; return true;
}

if(rijec[i]=='K') {
	i++;
while(i<rijec.size() && rijec[i]==' ')i++;
if(i!=rijec.size()) {greska=KodoviGresaka::PogresnaKomanda; return false;}

komanda=Komande::KreirajIgru; return true;
}

else {greska=KodoviGresaka::PogresnaKomanda;return false;}


	return true;
}


void IzvrsiKomandu(Komande komanda, Tabla &polja, int&x, int&y, Smjerovi p_smjer=Smjerovi::Gore, int p_x=0, int p_y=0){
	
	
	
try {

	if(komanda==Komande::KreirajIgru) {
	
	std::cout<<"Unesite broj polja: "; 
	int n;
	std::cin>>n;
	while(!std::cin || std::cin.peek()!='\n' || n<=0)
	{
		std::cout<<"Greska, unesite ponovo!"<<std::endl;
		std::cout<<"Unesite broj polja: ";
		std::cin>>n;
	}
	std::cin.ignore(1000,'\n');
	std::vector<std::vector<int>> matrica;

	std::cout<<"Unesite pozicije mina: ";
	std::string recenica;
	bool greska=false;
do{greska=false;
	std::vector<int> pomocni;
	std::getline(std::cin, recenica);
	if(recenica[0]=='.')break;
	int i=0,x=0,y=0;
while(i<recenica.size() && recenica[i]==' ')i++;
	if(i!=recenica.size() && recenica[i]=='(') {
		i++;
		
	while(i<recenica.size()&& recenica[i]==' ')i++;
	if(i!=recenica.size() && recenica[i]<='9' && recenica[i]>='0' && recenica[i]-48<n) {
	
		pomocni.push_back(recenica[i]-48);
		i++;
	while(i<recenica.size()&& recenica[i]==' ')i++; 
		if(i!=recenica.size() && recenica[i]==',') {
			i++;
		
			while(i<recenica.size() && recenica[i]==' ')i++;
			if(i!=recenica.size() && recenica[i]<='9' && recenica[i]>='0' && recenica[i]-48<n ) {
				pomocni.push_back(recenica[i]-48);
				i++;
			
				while(i<recenica.size() && recenica[i]==' ')i++;
                 if(i!=recenica.size()&&recenica[i]==')') {
                 
                 	i++; while(i<recenica.size()&&recenica[i]==' ')i++;
                 	if(i==recenica.size())matrica.push_back(pomocni);
                 	else {std::cout<<"Greska, unesite ponovo!"; greska=true;}
                 }
				else {std::cout<<"Greska, unesite ponovo!"<<std::endl; greska=true;}
			}
				else {std::cout<<"Greska, unesite ponovo!"<<std::endl; greska=true;}
		}
			else {std::cout<<"Greska, unesite ponovo!"<<std::endl; greska=true;}
	}
		else {std::cout<<"Greska, unesite ponovo!"<<std::endl; greska=true;}
	}
	else {std::cout<<"Greska, unesite ponovo!"<<std::endl; greska=true;}
	
}
	while(greska==true || recenica[0]!='.');
	

	polja=KreirajIgru(n,matrica);
	}
	
	if(komanda==Komande::ZavrsiIgru) {
	
	PostaviPrazno(polja);
	throw std::runtime_error("Igra zavrsena");
	}
	
	if(komanda==Komande::PomjeriJednoMjesto) {

	if (Idi(polja,x,y,p_smjer)==Status::NijeKraj) {
		std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
	}
	else if(Idi(polja,x,y,p_smjer)==Status::KrajPobjeda) {
		std::cout<<"Bravo, obisli ste sva sigurna polja"<<std::endl;
		PostaviPrazno(polja);
	throw std::runtime_error("Igra zavrsena");
	}
	
	else if(Idi(polja,x,y,p_smjer)==Status::KrajPoraz) {
		std::cout<<"Nagazili ste na minu"<<std::endl;
		PostaviPrazno(polja);
	throw std::runtime_error("Igra zavrsena");
	}
	
	}
	
	if(komanda==Komande::PomjeriDalje) {
	
	Status pomocni=Idi(polja,x,y,p_x,p_y);
		if(pomocni==Status::NijeKraj) {
		
			std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
		}
		else if(pomocni==Status::KrajPobjeda) {
		std::cout<<"Bravo, obisli ste sva sigurna polja"<<std::endl;
		PostaviPrazno(polja);
	throw std::runtime_error("Igra zavrsena");
	}
  else	 if(pomocni==Status::KrajPoraz) {
		
		std::cout<<"Nagazili ste na minu"<<std::endl;
		PostaviPrazno(polja);
	throw std::runtime_error("Igra zavrsena");
	}
		
	}
	
	if(komanda==Komande::Blokiraj) {
	BlokirajPolje(polja,p_x,p_y);
	}
	
	if(komanda==Komande::Deblokiraj) {
		DeblokirajPolje(polja,p_x,p_y);
	}
	
	if(komanda==Komande::PrikaziOkolinu) {
	
	std::vector<std::vector<int>> matrica=PrikaziOkolinu(polja,p_x,p_y);
	for(auto &b:matrica) {
		for(auto &a:b) {
			std::cout<<a<<" ";
		}
		std::cout<<std::endl;
	}
	
	}
}
catch(std::domain_error izuzetak) {
	std::cout<<izuzetak.what()<<std::endl;
}

catch(std::out_of_range izuzetak) {
	std::cout<<izuzetak.what()<<std::endl;
}
	catch(std::logic_error izuzetak) {
	std::cout<<izuzetak.what()<<std::endl;
}

catch(std::runtime_error izuzetak) {
	throw;
}

	
}


int main ()
{
	Tabla polja;
	int x=0,y=0,px=0,py=0;
    KodoviGresaka greska;
    Komande komanda;
    Smjerovi smjer;
	try {
	while(1) {
	std::cout<<"Unesite komandu: ";
	if(UnosKomande(komanda,smjer,px,py,greska)) {
	IzvrsiKomandu(komanda,polja,x,y,smjer,px,py);
	}
	else PrijaviGresku(greska);
	}
	}
	catch(std::runtime_error) {
		std::cout<<"Dovidjenja!";
	}
	
	return 0;	
	}

	
	
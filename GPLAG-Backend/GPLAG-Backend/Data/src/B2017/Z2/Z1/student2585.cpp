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

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	for(int i=0;i<mine.size();i++)
		if(mine.at(i).size()!=2) throw std::domain_error ("Ilegalan format zadavanja mina");
	for(int i=0;i<mine.size();i++)
		for(int j=0;j<2;j++)
			if(mine.at(i).at(j)<0 || mine.at(i).at(j)>=n) throw std::domain_error("Ilegalne pozicije mina");
		
	if(n<=0) throw std::domain_error ("Ilegalna velicina");
	
	Tabla povratna(n, std::vector<Polje>(n, Polje::Prazno));
	
	for(int i=0;i<mine.size();i++){
		povratna.at(mine.at(i).at(0)).at(mine.at(i).at(1))=Polje::Mina;
	}
	return povratna;
}


std::vector<std::vector<int>> PrikaziOkolinu(Tabla mat, int x, int y){
	if(x<0 || y<0 || x>=mat.size() || y>=mat.at(0).size()) {
		std::string greska="Polje (";
		greska+=std::to_string(x)+","+std::to_string(y)+") ne postoji";
		throw std::domain_error(greska);
	}
	std::vector<std::vector<int>> povratna;
	
	int PocetakPoX(x);
	int KrajPoX(x);
	
	int PocetakPoY(y);
	int KrajPoY(y);
	
	if(x>0) PocetakPoX-=1;
	if(x<mat.size()-1) KrajPoX+=1;
	
	if(y>0) PocetakPoY-=1;
	if(y<mat.at(0).size()-1) KrajPoY+=1;
	
	int OdaklePoX(PocetakPoX);
	int DoklePoX(KrajPoX);
	
	int OdaklePoY(PocetakPoY);
	int DoklePoY(KrajPoY);

	std::vector<int> pomocna;
	
	for (int i=PocetakPoX; i<=KrajPoX; i++){
		
		for(int j=PocetakPoY; j<=KrajPoY; j++){
			OdaklePoX=i;
			DoklePoX=i;
			OdaklePoY=j;
			DoklePoY=j;
			// dokle ici po x :)
			if (i-1>=0) OdaklePoX-=1;
			else OdaklePoX=i;
			if(i+1<=mat.size()-1) DoklePoX+=1;
			else DoklePoX=i;
			
			// dokle ici po y :)
			if(j-1>=0) OdaklePoY-=1;
			else OdaklePoY=j;
			if(j+1<=mat.at(0).size()-1) DoklePoY+=1;
			else DoklePoY=j;
			
			//algoritam za okolinu polja 
			int suma=0;
			
			for(int k=OdaklePoX; k<=DoklePoX; k++)
				for(int l=OdaklePoY; l<=DoklePoY; l++)
					if(mat.at(k).at(l)==Polje::Mina) suma+=1;
				
			
			if (mat.at(i).at(j)==Polje::Mina) suma-=1;
			pomocna.push_back(suma);
			
			
		}
		povratna.push_back(pomocna);
		pomocna.resize(0);
	}
	
	return povratna;
}

void BlokirajPolje(Tabla &mat, int x, int y){
	if(x<0 || y<0 || x>=mat.size() || y>=mat.at(0).size()) {
		std::string greska("Polje (");
		greska+=std::to_string(x)+","+std::to_string(y)+") ne postoji";
		throw std::domain_error(greska);
	}
	if(mat.at(x).at(y)==Polje::Prazno) mat.at(x).at(y)=Polje::BlokiranoPrazno;
	else if(mat.at(x).at(y)==Polje::Posjeceno) mat.at(x).at(y)=Polje::BlokiranoPosjeceno;
	else if(mat.at(x).at(y)==Polje::Mina) mat.at(x).at(y)=Polje::BlokiranoMina;
}


void DeblokirajPolje(Tabla &mat, int x, int y){
	if(x<0 || y<0 || x>=mat.size() || y>=mat.at(0).size()) {
		std::string greska("Polje (");
		greska+=std::to_string(x)+","+std::to_string(y)+") ne postoji";
		throw std::domain_error(greska);
	}
	if(mat.at(x).at(y)==Polje::BlokiranoPrazno) mat.at(x).at(y)=Polje::Prazno;
	else if(mat.at(x).at(y)==Polje::BlokiranoPosjeceno) mat.at(x).at(y)=Polje::Posjeceno;
	else if(mat.at(x).at(y)==Polje::BlokiranoMina) mat.at(x).at(y)=Polje::Mina;
}



Status Idi(Tabla &mat, int &x, int &y, Smjerovi gdje){
	int velicina(mat.size()-1);
	if(gdje==Smjerovi::GoreLijevo && (x==0 || y==0)) throw std::out_of_range("Izlazak van igrace table");
	else if(gdje==Smjerovi::Gore && x==0) throw std::out_of_range("Izlazak van igrace table");
	else if(gdje==Smjerovi::GoreDesno && (x==0 || y==velicina)) throw std::out_of_range("Izlazak van igrace table");
	else if(gdje==Smjerovi::Desno && y==velicina) throw std::out_of_range("Izlazak van igrace table");
	else if(gdje==Smjerovi::DoljeDesno && (x==velicina || y==velicina)) throw std::out_of_range("Izlazak van igrace table");
	else if(gdje==Smjerovi::Dolje && x==velicina) throw std::out_of_range("Izlazak van igrace table");
	else if(gdje==Smjerovi::DoljeLijevo && (x==velicina || y==0)) throw std::out_of_range("Izlazak van igrace table");
	else if(gdje==Smjerovi::Lijevo && y==0) throw std::out_of_range("Izlazak van igrace table");
	
	if(gdje==Smjerovi::GoreLijevo && (mat.at(x-1).at(y-1)==Polje::BlokiranoPosjeceno || mat.at(x-1).at(y-1)==Polje::BlokiranoPrazno || mat.at(x-1).at(y-1)==Polje::BlokiranoMina)) throw std::logic_error("Blokirano polje");
	else if(gdje==Smjerovi::Gore && (mat.at(x-1).at(y)==Polje::BlokiranoPosjeceno || mat.at(x-1).at(y)==Polje::BlokiranoPrazno || mat.at(x-1).at(y)==Polje::BlokiranoMina)) throw std::logic_error("Blokirano polje");
	else if(gdje==Smjerovi::GoreDesno && (mat.at(x-1).at(y+1)==Polje::BlokiranoPosjeceno || mat.at(x-1).at(y+1)==Polje::BlokiranoPrazno || mat.at(x-1).at(y+1)==Polje::BlokiranoMina))  throw std::logic_error("Blokirano polje");
	else if(gdje==Smjerovi::Desno && (mat.at(x).at(y+1)==Polje::BlokiranoPosjeceno || mat.at(x).at(y+1)==Polje::BlokiranoPrazno || mat.at(x).at(y+1)==Polje::BlokiranoMina)) throw std::logic_error("Blokirano polje");
	else if(gdje==Smjerovi::DoljeDesno && (mat.at(x+1).at(y+1)==Polje::BlokiranoPosjeceno || mat.at(x+1).at(y+1)==Polje::BlokiranoPrazno || mat.at(x+1).at(y+1)==Polje::BlokiranoMina)) throw std::logic_error("Blokirano polje");
	else if(gdje==Smjerovi::Dolje && (mat.at(x+1).at(y)==Polje::BlokiranoPosjeceno || mat.at(x+1).at(y)==Polje::BlokiranoPrazno || mat.at(x+1).at(y)==Polje::BlokiranoMina)) throw std::logic_error("Blokirano polje");
	else if(gdje==Smjerovi::DoljeLijevo && (mat.at(x+1).at(y-1)==Polje::BlokiranoPosjeceno || mat.at(x+1).at(y-1)==Polje::BlokiranoPrazno || mat.at(x+1).at(y-1)==Polje::BlokiranoMina)) throw std::logic_error("Blokirano polje");
	else if(gdje==Smjerovi::Lijevo && (mat.at(x).at(y-1)==Polje::BlokiranoPosjeceno || mat.at(x).at(y-1)==Polje::BlokiranoPrazno || mat.at(x).at(y-1)==Polje::BlokiranoMina)) throw std::logic_error("Blokirano polje");

	mat.at(x).at(y)=Polje::Posjeceno;
	
	if(gdje==Smjerovi::GoreLijevo) {x=x-1;y=y-1;}
	else if(gdje==Smjerovi::Gore) {x=x-1;}
	else if(gdje==Smjerovi::GoreDesno) {x=x-1; y=y+1;}
	else if(gdje==Smjerovi::Desno) {y=y+1;}
	else if(gdje==Smjerovi::DoljeDesno) {x=x+1;y=y+1;}
	else if(gdje==Smjerovi::Dolje) {x=x+1;}
	else if(gdje==Smjerovi::DoljeLijevo) {x=x+1; y=y-1;}
	else if(gdje==Smjerovi::Lijevo) {y=y-1;}
	
	if (mat.at(x).at(y)==Polje::Mina) {
		for(int i=0;i<mat.size();i++)
			for(int j=0;j<mat.size();j++) mat.at(i).at(j)=Polje::Prazno;
		
		return Status::KrajPoraz;
	}
	
	int koliko(0);
	for(int i=0;i<mat.size();i++)
		for(int j=0;j<mat.size();j++)
			if(mat.at(i).at(j)==Polje::Prazno)koliko++;
		
	if(koliko==1) return Status::KrajPobjeda;
	else return Status::NijeKraj;
	
}
Status Idi(Tabla &mat, int &x, int &y, int a, int b){
	if(a<0 || a>=mat.size() || b<0 || b>=mat.size()) throw std::out_of_range("Izlazak van igrace table");
	
	if(mat.at(a).at(b)==Polje::BlokiranoPosjeceno || mat.at(a).at(b)==Polje::BlokiranoPrazno || mat.at(a).at(b)==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
	
	mat.at(x).at(y)=Polje::Posjeceno;
	x=a;
	y=b;
	if(mat.at(x).at(y)==Polje::Mina) {
		for(int i=0;i<mat.size();i++)
			for(int j=0;j<mat.size();j++) mat.at(i).at(j)=Polje::Prazno;
	
		return Status::KrajPoraz;
	}
	int koliko(0);
	for(int i=0;i<mat.size();i++)
		for(int j=0;j<mat.size();j++)
		if(mat.at(i).at(j)==Polje::Prazno) koliko++;
	
	if(koliko==1) return Status::KrajPobjeda;
	else return Status::NijeKraj;
	
}


void PrijaviGresku(KodoviGresaka greska){
	if(greska==KodoviGresaka::PogresnaKomanda) std::cout<<"Nerazumljiva komanda!\n";
	else if(greska==KodoviGresaka::NedostajeParametar) std::cout<<"Komanda trazi parametar koji nije naveden!\n";
	else if(greska==KodoviGresaka::NeispravanParametar) std::cout<<"Parametar komande nije ispravan!\n";
	else if(greska==KodoviGresaka::SuvisanParametar) std::cout<<"Zadan je suvisan parametar nakon komande!\n";
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	/*while(std::cin.peek()==' '){
		char znak=std::cin.get();
	}
	if(std::cin.peek()=='\n'){
		greska=KodoviGresaka::NeispravanParametar;
		return false;
	}*/
	
	std::string a{};
	std::cin>>a;
	
	if(a=="PO"){
		char znak=std::cin.get();
		while(znak!='\n'){
			if(znak!=' '){ greska=KodoviGresaka::SuvisanParametar; std::cin.ignore(10000, '\n'); return false;}
			znak=std::cin.get();
		}
		komanda=Komande::PrikaziOkolinu;
	}
	else if(a=="Z"){
		char znak=std::cin.get();
		while(znak!='\n'){
			if(znak!=' ') {greska=KodoviGresaka::SuvisanParametar; std::cin.ignore(10000, '\n'); return false;}
			znak=std::cin.get();
	}
		komanda=Komande::ZavrsiIgru;
	}
	else if(a=="K"){
		char znak=std::cin.get();
		while(znak!='\n'){
			if(znak!=' ') {greska=KodoviGresaka::SuvisanParametar; std::cin.ignore(10000, '\n'); return false;}
			znak=std::cin.get();
		}
		komanda=Komande::KreirajIgru;
	}
	else if(a=="P1"){
		while(std::cin.peek()==' '){
			char znak=std::cin.get();
		}
		if(std::cin.peek()=='\n'){greska=KodoviGresaka::NedostajeParametar; std::cin.ignore(10000, '\n'); return false;}
		std::string s{};
		std::cin>>s;
		char znak=std::cin.get();
		while(znak!='\n'){
			if(znak!=' '){greska=KodoviGresaka::NeispravanParametar; std::cin.ignore(10000, '\n'); return false;}
			znak=std::cin.get();
		}
		
		if(s=="GL") {smjer=Smjerovi::GoreLijevo; komanda=Komande::PomjeriJednoMjesto;}
		else if(s=="G") {smjer=Smjerovi::Gore; komanda=Komande::PomjeriJednoMjesto;}
		else if(s=="GD") {smjer=Smjerovi::GoreDesno; komanda=Komande::PomjeriJednoMjesto;}
		else if(s=="D") {smjer=Smjerovi::Desno; komanda=Komande::PomjeriJednoMjesto;}
		else if(s=="DoD") {smjer=Smjerovi::DoljeDesno; komanda=Komande::PomjeriJednoMjesto;}
		else if(s=="Do") {smjer=Smjerovi::Dolje; komanda=Komande::PomjeriJednoMjesto;}
		else if(s=="DoL") {smjer=Smjerovi::DoljeLijevo; komanda=Komande::PomjeriJednoMjesto;}
		else if(s=="L") {smjer=Smjerovi::Lijevo; komanda=Komande::PomjeriJednoMjesto;}
		else{ greska=KodoviGresaka::NeispravanParametar; std::cin.ignore(10000, '\n'); return false;}
		
	}
	else if(a=="P>"){
		while(std::cin.peek()==' '){
			char znak=std::cin.get();
		}
		if(std::cin.peek()=='\n') {greska=KodoviGresaka::NedostajeParametar; std::cin.ignore(10000, '\n'); return false;}
		if(std::cin.peek()<'0' || std::cin.peek()>'9') {greska=KodoviGresaka::NeispravanParametar; std::cin.ignore(10000, '\n'); return false;}
		int x1(0), y1(0);
		std::cin>>x1;
		while(std::cin.peek()==' '){
			char znak=std::cin.get();
		}
		if(std::cin.peek()=='\n') {greska=KodoviGresaka::NedostajeParametar; std::cin.ignore(10000, '\n'); return false;}
		if(std::cin.peek()<'0' || std::cin.peek()>'9'){greska=KodoviGresaka::NeispravanParametar; std::cin.ignore(10000, '\n'); return false;}
		std::cin>>y1;
		while(std::cin.peek()!='\n'){
			char znak=std::cin.get();
			if(znak!=' ') {greska=KodoviGresaka::SuvisanParametar; std::cin.ignore(10000, '\n'); return false;}
		}
		x=x1;
		y=y1;
		komanda=Komande::PomjeriDalje;
	}
	else if(a=="B"){
		while(std::cin.peek()==' '){
			char znak=std::cin.get();
		}
		if(std::cin.peek()=='\n') {greska=KodoviGresaka::NedostajeParametar; std::cin.ignore(10000, '\n'); return false;}
		if(std::cin.peek()<'0' || std::cin.peek()>'9') {greska=KodoviGresaka::NeispravanParametar; std::cin.ignore(10000, '\n'); return false;}
		int x1(0), y1(0);
		std::cin>>x1;
		while(std::cin.peek()==' '){
			char znak=std::cin.get();
		}
		if(std::cin.peek()=='\n') {greska=KodoviGresaka::NedostajeParametar; std::cin.ignore(10000, '\n'); return false;}
		if(std::cin.peek()<'0' || std::cin.peek()>'9') {greska=KodoviGresaka::NeispravanParametar; std::cin.ignore(10000, '\n'); return false;}
		std::cin>>y1;
		while(std::cin.peek()!='\n'){
			char znak=std::cin.get();
			if(znak!=' ') {greska=KodoviGresaka::SuvisanParametar; std::cin.ignore(10000, '\n'); return false;}
		}
		x=x1;
		y=y1;
		komanda=Komande::Blokiraj;
	}
	else if(a=="D"){
		while(std::cin.peek()==' '){
			char znak=std::cin.get();
		}
		if(std::cin.peek()=='\n') {greska=KodoviGresaka::NedostajeParametar; std::cin.ignore(10000, '\n'); return false;}
		if(std::cin.peek()<'0' || std::cin.peek()>'9') {greska=KodoviGresaka::NeispravanParametar; std::cin.ignore(10000, '\n'); return false;}
		int x1(0), y1(0);
		std::cin>>x1;
		while(std::cin.peek()==' '){
			char znak=std::cin.get();
		}
		if(std::cin.peek()=='\n') {greska=KodoviGresaka::NedostajeParametar; std::cin.ignore(10000, '\n'); return false;}
		if(std::cin.peek()<'0' || std::cin.peek()>'9') {greska=KodoviGresaka::NeispravanParametar; std::cin.ignore(10000, '\n'); return false;}
		std::cin>>y1;
		while(std::cin.peek()!='\n'){
			char znak=std::cin.get();
			if(znak!=' ') {greska=KodoviGresaka::SuvisanParametar; std::cin.ignore(10000, '\n'); return false;}
		}
		x=x1;
		y=y1;
		komanda=Komande::Deblokiraj;
	}
	else {
		greska=KodoviGresaka::PogresnaKomanda;
		std::cin.ignore(10000, '\n');
		return false;
	}
	//std::cin.ignore(10000, '\n');
	return true;
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer=Smjerovi::Gore, int p_x=0, int p_y=0){
	
}
/*bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	std::string a;
	std::cin>>std::ws>>a;
	if(a=="P1"){
		std::string s{};
		std::cin>>std::ws>>s;
		if(s.length()!=0 && s!="GL" && s!="G" && s!="GD" && s!="D" && s!="DoD" && s!="Do" && s!="DoL" && s!="L"){
			greska=KodoviGresaka::SuvisanParametar;
			}
			else if(s=="GL" || s=="G" || s=="GD" || s=="D" || s=="DoD" || s=="Do" || s=="DoL" || s=="L"){
				char znak=std::cin.get();
				while(znak!='\n'){
					if(znak!=' ') {
						greska=KodoviGresaka::SuvisanParametar;
						std::cin.clear();
						std::cin.ignore(10000, '\n');
						break;
					}
				}
				if(znak=='\n') {
					if(s=="GL") smjer=Smjerovi::GoreLijevo;
					else if(s=="G") smjer=Smjerovi::Gore;
					else if(s=="GD") smjer=Smjerovi::GoreDesno;
					else if(s=="D") smjer=Smjerovi::Desno;
					else if(s=="DoD") smjer=Smjerovi::DoljeDesno;
					else if(s=="Do") smjer=Smjerovi::Dolje;
					else if(s=="DoL") smjer=Smjerovi::DoljeLijevo;
					else if(s=="L") smjer=Smjerovi::Lijevo;
				}
			}
			else if(s.length()==0) greska=KodoviGresaka::NedostajeParametar;
		}
		else if(a=="P>"){
			int x(0), y(0);
			std::cin>>x;
			bool tacno(true);
			if(!std::cin){
				greska=KodoviGresaka::SuvisanParametar;
				
			}
			
			
		}
		else if(a=="B"){
			
		}
		else if(a=="D"){
			
		}
		else if(a=="PO"){
			char znak=std::cin.get();
			while(znak!='\n'){
				if(znak!=' ') {
					greska=KodoviGresaka::SuvisanParametar;
					std::cin.clear();
					std::cin.ignore(10000, '\n');
					break;
				}
			}
			if(znak=='\n') {
				komanda=Komande::PrikaziOkolinu;
				return true;
				
			}
		}
		else if(a=="Z"){
				char znak=std::cin.get();
			while(znak!='\n'){
				if(znak!=' ') {
					greska=KodoviGresaka::SuvisanParametar;
					std::cin.clear();
					std::cin.ignore(10000, '\n');
					break;
				}
			}
			if(znak=='\n') {
				komanda=Komande::ZavrsiIgru;
				return true;
				
			}
				
			}
		else if(a=="K"){
				char znak=std::cin.get();
			while(znak!='\n'){
				if(znak!=' ') {
					greska=KodoviGresaka::SuvisanParametar;
					std::cin.clear();
					std::cin.ignore(10000, '\n');
					break;
				}
			}
			if(znak=='\n') {
				komanda=Komande::KreirajIgru;
			return true;
				
			}
		}
	
	else {
		greska=KodoviGresaka::PogresnaKomanda;
		return false;
	}
	
	
}*/
int main ()
{
/*	Komande komanda;
	Tabla mat;
	Smjerovi smjer;
	
	while (true) {
      Komande komanda;
      Smjerovi smjer = Smjerovi::GoreDesno;
      int x = 0, y = 0;
      KodoviGresaka greska = KodoviGresaka::SuvisanParametar;
      UnosKomande(komanda, smjer, x, y, greska);
      if(komanda == Komande::ZavrsiIgru) break;
      std::cout << "Unesena komanda: " << int(komanda);
      std::cout << ", (x,y) = (" << x << "," << y <<")";
     
      if(smjer != Smjerovi::GoreDesno) std::cout << " azuriran smjer na " << int(smjer);
      std::cout  << std::endl;
    }*/
   //std::cout<<"armin";
 /*while (true) {
      Komande komanda  = Komande::PomjeriDalje;
      Smjerovi smjer;
      int x = 0, y = 0;
      KodoviGresaka greska = KodoviGresaka::SuvisanParametar;
      UnosKomande(komanda, smjer, x, y, greska);
      if(komanda == Komande::ZavrsiIgru) break;
      std::cout << int(greska) << " ";
    }
    std::cout<<"armin";*/
/*	std::vector<std::vector<int>> mine{{0,0}, {0,2}, {1,0}};
	try{
	Tabla test=KreirajIgru(3, mine);
	for(int i=0;i<test.size();i++){
		for(int j=0;j<test.size();j++) std::cout<<int(test.at(i).at(j))<<" ";
		std::cout<<std::endl;
	}
	std::cout<<std::endl;
	std::vector<std::vector<int>> pokusaj=PrikaziOkolinu(test,-5, 5);
	for(int i=0;i<pokusaj.size();i++){
		for(int j=0;j<pokusaj.at(i).size();j++){
			std::cout<<pokusaj.at(i).at(j)<<" ";
		}
		std::cout<<std::endl;
	}
	}
	catch(std::domain_error e){
		std::cout<<e.what();
	}
	*/
/*	std::string a;
	std::cin>>std::ws>>a;
	if(a=="P1"){
		std::string smjer;
		std::cin>>std::ws>>smjer;
		
		char znak=std::cin.get();
		while(znak!='\n'){
			if(znak!=' '){
				std::cout<<"ne valja";
				break;
			}
			znak=std::cin.get();
			
		}
	}*/
/*	int x, int y;
	Komande komanda;
	Smjerovi smjer;
	KodoviGresaka greska;
	UnosKomande(komanda, smjer, x, y, greska);
	return 0;*/
	return 0;
}
/*
0 1 0 0 1
0 0 0 1 1
1 1 0 1 0
0 0 0 0 0
0 0 0 0 0

1, 0, 2
2, 3, 4
1, 1, 3
*/
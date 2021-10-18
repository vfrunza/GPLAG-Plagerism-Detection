#include <iostream>
#include <vector>
#include <stdexcept>

enum class Polje{Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoProsjecno, BlokiranoMina};
typedef std::vector<std::vector<Polje>> Tabla;
enum class Smjerovi{GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo};
enum class Status{NijeKraj, KrajPoraz, KrajPobjeda};
enum class KodoviGresaka{PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar};
enum class Komande{PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru}
Tabla KreirajIgru (int n, const std::vector<std::vector<int>> &mine) {
	Tabla prazna;
	if(n==0) return prazna;
	Tabla a(n, std::vector<Polje> (n, Polje(0))); 

	
	/*PROVJERA ISPRAVNOSTI KOORDINATA MINA*/
	
	for(unsigned int i=0; i<mine.size(); i++) {
		if(mine[i].size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
		if(i==mine.size()-1) break;
		
		}
	

	for(unsigned int i=0; i<mine.size(); i++) {
		
		if(mine[i][0]>n || mine[i][1]>n) throw std::domain_error("Ilegalne pozicije mina");
			
			if(i==mine.size()-1) break;
	}
	
	for(unsigned int i=0; i<mine.size(); i++) {
		int x;
		int y;
		x=mine[i][0];
		y=mine[i][1];
		a[x][y]=Polje(2);
		if(i==mine.size()-1) break;
	}
	
	return a;
	}



std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y) { 
	std::vector<std::vector<int>> okolina(3, std::vector<int> (3,0));
	if(x>=polja.size() || y>=polja[0].size() || x<0 || y<0) throw std::domain_error("Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji");// pretposatavila sam da je pravilna matrica a ne grbava, provjeri jel to ok
// mogao bi biti problem ako su polja prazna matrica jer pristupam elementu kog nema 
				int brojac(0);
				
				for(int k=0; k<3; k++) {
					for(int l=0; l<3; l++) {
			
							int a;
							a=x+k-1;
							int b;
							b=y+l-1;
						a=a-1; 	
						b=b-1;	
						for(int o=a; o<=a+2; o++) {
						if(o<0 || o>polja.size()) continue;
						
						for(int p=b; p<=b+2; p++) {
								if( p<0 || p>polja.size()) continue; 
								else {
									if(o==x+k-1 && p==y+l-1)  continue;
								else if(polja[o][p]==Polje(2))  brojac++;   } } }
							
							okolina[k][l]=brojac;
							brojac=0;
		
					}
				}
	
return okolina;
}

void BlokirajPolje(Tabla &polja, int x, int y) {
	if(x>=polja.size() || x<0 || y<0 || y>=polja[0].size()) throw std::domain_error("Polje (" + std::to_string(x) + "," + std::to_string(y)+") ne postoji");
	/*ovo sve moze u petlju*/
	// ovo polja[0] bi moglo stavarat problem ako se posalje prazna matrica
	if(polja[x][y]==Polje(0)) polja[x][y]=Polje(3);
	if(polja[x][y]==Polje(1)) polja[x][y]=Polje(4);
	if(polja[x][y]==Polje(2)) polja[x][y]=Polje(5);
	
}

void DeblokirajPolje(Tabla &polja, int x, int y) {
	if(x>=polja.size() || x<0 || y>=polja[0].size() || y<0) throw std::domain_error("Polje (" + std::to_string(x) + "," + std::to_string(y)+ ") ne postoji");
	// opet problem ako je matrica prazna
	/*opet sve je moglo u petlju*/
	if(polja[x][y]==Polje(3)) polja[x][y]=Polje(0);
	if(polja[x][y]==Polje(4)) polja[x][y]=Polje(1);
	if(polja[x][y]==Polje(5)) polja[x][y]=Polje(2);
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer) {
	polja[x][y]=Polje(1);
	if(smjer==Smjerovi(0)) {
		if (x-1<0 || y-1<0) throw std::out_of_range("Izlazak van granica table");
		if(polja[x-1][y-1]==Polje(3) || polja[x-1][y-1]==Polje(4) || polja[x-1][y-1]==Polje(5)) throw std::logic_error("Blokirano polje");
	
		x=x-1;
		y=y-1;
	}
	if(smjer==Smjerovi(1)) {
		if(x-1<0) throw std::out_of_range("Izlazak van granica table");
		if(polja[x-1][y]==Polje(3) || polja[x-1][y]==Polje(4) || polja[x-1][y]==Polje(5)) throw std::logic_error("Blokirano polje");
	
		x=x-1;
		}
	if(smjer==Smjerovi(2)) {
		if(x-1<0 || y+1>=polja.size()) throw std::out_of_range("Izvan granica table");
		if(polja[x-1][y+1]==Polje(3) || polja[x-1][y+1]==Polje(4) || polja[x-1][y+1]==Polje(5)) throw std::logic_error("Blokirano polje");
	
		x=x-1;
		y=y+1;
	}

	if(smjer==Smjerovi(3)) {
		if(y+1>=polja.size()) throw std::out_of_range("Izvan granica table");
		if(polja[x][y+1]==Polje(3) || polja[x][y+1]==Polje(4) || polja[x][y+1]==Polje(5) ) throw std::logic_error("Blokirano polje");
	
		y=y+1;
	}
	
	if(smjer==Smjerovi(4)) {
		if(x+1>=polja.size() || y>=polja.size()) throw std::out_of_range("Izvan granica table");
		if(polja[x+1][y+1]==Polje(3) || polja[x+1][y+1]==Polje(4) || polja[x+1][y+1]==Polje(5)) throw std::logic_error("Blokirano polje");
	
		x=x+1;
		y=y+1;
	}
	
	if(smjer==Smjerovi(5)) {
		if(x+1>=polja.size()) throw std::out_of_range("Izvan granica table");
		if(polja[x+1][y]==Polje(3) || polja[x+1][y]==Polje(4) || polja[x+1][y]==Polje(5)) throw std::logic_error("Blokirano polje");
		
		x=x+1;
	}
	
	if(smjer==Smjerovi(6)) {
		if(x+1>=polja.size() || y-1<0) throw std::out_of_range("Izvan granica table");
		if(polja[x+1][y-1]==Polje(3) || polja[x+1][y-1]==Polje(4) || polja[x+1][y-1]==Polje(5)) throw std::out_of_range("Blokirano polje");
		
		x=x+1;
		y=y-1;
	}
	
	if(smjer==Smjerovi(7)) {
		if(y-1<0) throw std::out_of_range("Izvan granica table");
		if(polja[x][y-1]==Polje(3) || polja[x][y-1]==Polje(4) || polja[x][y-1]==Polje(5)) throw std::out_of_range("Blokirano polje");
		
		y=y-1;
	}
		
		
		if(polja[x][y]==Polje(2)) {
			for(unsigned int i=0; i<polja.size(); i++) {
				for(unsigned int j=0; j<polja.size(); j++) // jer je kvadratna matrica
				polja[i][j]=Polje(0);
			}
			
			return Status(1);
		}
		
		for(unsigned int i=0; i<polja.size(); i++) {
			for(unsigned int j=0; j<polja.size(); j++)
			if(polja[i][j]==Polje(0)) return Status(0);
		}
		
		return Status(2);
	}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y) {
	
	if(novi_x<0 ||  novi_y<0 || novi_x>=polja.size() || novi_y>=polja.size()) throw std::out_of_range("Izvan granica table");
	if( polja[novi_x][novi_y]==Polje(3) || polja[novi_x][novi_y]==Polje(4) || polja[novi_x][novi_y]==Polje(5)) throw std::logic_error("Blokirano polje");
	polja[x][y]=Polje(1);
	x=novi_x;
	y=novi_y;
	if(polja[x][y]==Polje(2)) {
		for(unsigned int i=0; i<polja.size(); i++) 
		for(unsigned int j=0; j<polja.size(); j++) polja[i][j]=Polje(0);
		return Status(1);
		}
	for(unsigned int i=0; i<polja.size(); i++) {
		for(unsigned j=0; j<polja.size(); j++)
		if(polja[i][j]==Polje(0)) return Status(0);
	}
	
	return Status(2);
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska)
{
	
	
}

/*void ispisiTablu(std::vector<std::vector<Polje>> polja) {
	for(int i=0; i<polja.size(); i++) {
		for(int j=0; j<polja[i].size(); j++) {
			std::cout << int(polja[i][j]) << " ";
		}
		std::cout << std::endl;
	}
}*/
	
	
	int main() {
	
	/*
	
	
	
	std::vector<std::vector<int>> mine={{0,2}, {1,3}, {1,5}, {4,2}, {5,1}, {5,5}};
	std::vector<std::vector<Polje>> tabla=KreirajIgru(0, mine);
	ispisiTablu(tabla);*/ 

/*	
	try{
		std::vector<std::vector<int>> mine={{1,0}, {6,1}};
		std::vector<std::vector<Polje>> tabla=KreirajIgru(5, mine);
	}
	
	catch (std::domain_error e) {
		std::cout << e.what() << std::endl;
	}
	
	try {
		std::vector<std::vector<int>> mine={{1,0}, {6,1}};
		std::vector<std::vector<Polje>> tabla=KreirajIgru(5, mine);
	}
		catch(std::domain_error e){
		std::cout << e.what() << std::endl;
	}*/
	
/*	
	try {
		std::vector<std::vector<int>> mine={{1,0}, {1}};
		std::vector<std::vector<Polje>> tabla=KreirajIgru(5, mine);
	}
	
	catch(std::domain_error e) {
		std::cout << e.what() << std::endl;
	}
	
	
	try{
		std::vector<std::vector<int>> mine={{1,0}, {1,2,3}};
		std::vector<std::vector<Polje>> tabla=KreirajIgru(5, mine);
	}
	
	catch(std::domain_error e) {
		std::cout << e.what() << std::endl;
	} */
	
//AT	2 
/*
	std::vector<std::vector<int>> mine={{0,1}, {0,4}, {1,3}, {1,4}, {2,0}, {2,1}, {2,3}};
	std::vector<std::vector<Polje>> tabla=KreirajIgru(5,mine);
	std::vector<std::vector<int>> okolina=PrikaziOkolinu(tabla, 1, 1);
	for(int i=0; i<okolina.size(); i++) {
		for(int j=0; j<okolina[i].size(); j++) std::cout << okolina[i][j] << " ";
		std::cout << std::endl;
	} */
	
//AT  10

std::vector<std::vector<int>> mine={{0,1}, {0,2}, {1,0}, {1,1}, {1,2}, {2,0}, {2,1 }, {2,2}};
std::vector<std::vector<Polje>> tabla=KreirajIgru(3, mine);

try {
	auto okolina=PrikaziOkolinu(tabla, 3, 5);
}
catch(std::domain_error e) {
	std::cout << e.what() << std::endl;
}
try {
	auto okolina=PrikaziOkolinu(tabla, 1, 5);
}
catch(std::domain_error e) {
	std::cout << e.what() << std::endl;
}
try{
	auto okolina=PrikaziOkolinu(tabla, 3, 1); 
}
catch(std::domain_error e) {
	std::cout << e.what() << std::endl;
}
	return 0;
	
}


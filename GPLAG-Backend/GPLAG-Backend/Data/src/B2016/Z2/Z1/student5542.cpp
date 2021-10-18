#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

enum class Polje {
		Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
    };
enum class Status {
        NijeKraj, KrajPoraz, KrajPobjeda
    };
enum class Smjerovi {
        GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
    };
enum class KodoviGresaka {
        PogresnaKomanda, NedostajeParmetar, SuvisanParametar, NeispravanParametar
    };
enum class Komande {
        PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
    };




typedef std::vector<std::vector<Polje>> Tabla;


Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine) {
	
	for(int i=0; i<mine.size(); i++) {
		if(mine[i].size()!=2) throw std::domain_error ("Ilegalan format zadavanja mina");
	}
	
	for(int i=0; i<mine.size(); i++) {
		for(int j=0; j<mine[0].size(); j++) {
			if(mine[i][j]>=n || mine[i][j]<0) throw std::domain_error("Ilegalne pozicije mina");
		}
	}
	
	Tabla tabla(n, std::vector<Polje> (n));
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			tabla[i][j]=Polje::Prazno;
			
		}
	}
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			for(int z=0; z<mine.size(); z++)
			tabla[mine[z][0]][mine[z][1]] = Polje::Mina;
		}
	}
	
		for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			std::cout << int(tabla[i][j]) << " ";
		}
		std::cout << std::endl;
	}
	
	return tabla;
	
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y) {
	
	std::vector<std::vector<int>> brojmina(3, std::vector<int> (3, 0));
	int brojredova=polja.size();
	int brojkolona=polja[0].size();
	
	for(int i=0; i<brojredova; i++) {
		for(int j=0; j<brojkolona; j++) {
			
			if(i==x-1 && j==y-1) { 
				if(polja[i+1][j]==Polje::Mina) brojmina[0][0]++;
				if(polja[i][j+1]==Polje::Mina) brojmina[0][0]++;
				if(polja[i+1][j+1]==Polje::Mina) brojmina[0][0]++;
				if(polja[i-1][j-1]==Polje::Mina) brojmina[0][0]++;
				if(polja[i-1][j]==Polje::Mina) brojmina[0][0]++;
				if(polja[i-1][j+1]==Polje::Mina) brojmina[0][0]++;
				if(polja[i][j-1]==Polje::Mina) brojmina[0][0]++;
				if(polja[i+1][j-1]==Polje::Mina) brojmina[0][0]++;
			}
			
			if(i==x-1 && j==y) {
				if(polja[i+1][j]==Polje::Mina) brojmina[0][1]++;
				if(polja[i][j+1]==Polje::Mina) brojmina[0][1]++;
				if(polja[i+1][j+1]==Polje::Mina) brojmina[0][1]++;
				if(polja[i-1][j-1]==Polje::Mina) brojmina[0][1]++;
				if(polja[i-1][j]==Polje::Mina) brojmina[0][1]++;
				if(polja[i-1][j+1]==Polje::Mina) brojmina[0][1]++;
				if(polja[i][j-1]==Polje::Mina) brojmina[0][1]++;
				if(polja[i+1][j-1]==Polje::Mina) brojmina[0][1]++;
				
			}
			if(i==x-1 && j==y+1) {
				if(polja[i+1][j]==Polje::Mina) brojmina[0][2]++;
				if(polja[i][j+1]==Polje::Mina) brojmina[0][2]++;
				if(polja[i+1][j+1]==Polje::Mina) brojmina[0][2]++;
				if(polja[i-1][j-1]==Polje::Mina) brojmina[0][2]++;
				if(polja[i-1][j]==Polje::Mina) brojmina[0][2]++;
				if(polja[i-1][j+1]==Polje::Mina) brojmina[0][2]++;
				if(polja[i][j-1]==Polje::Mina) brojmina[0][2]++;
				if(polja[i+1][j-1]==Polje::Mina) brojmina[0][2]++;
			}
			if(i==x && j==y-1) {
				if(polja[i+1][j]==Polje::Mina) brojmina[1][0]++;
				if(polja[i][j+1]==Polje::Mina) brojmina[1][0]++;
				if(polja[i+1][j+1]==Polje::Mina) brojmina[1][0]++;
				if(polja[i-1][j-1]==Polje::Mina) brojmina[1][0]++;
				if(polja[i-1][j]==Polje::Mina) brojmina[1][0]++;
				if(polja[i-1][j+1]==Polje::Mina) brojmina[1][0]++;
				if(polja[i][j-1]==Polje::Mina) brojmina[1][0]++;
				if(polja[i+1][j-1]==Polje::Mina) brojmina[1][0]++;
			}
			if(i==x && j==y) {
				if(polja[i+1][j]==Polje::Mina) brojmina[1][1]++;
				if(polja[i][j+1]==Polje::Mina) brojmina[1][1]++;
				if(polja[i+1][j+1]==Polje::Mina) brojmina[1][1]++;
				if(polja[i-1][j-1]==Polje::Mina) brojmina[1][1]++;
				if(polja[i-1][j]==Polje::Mina) brojmina[1][1]++;
				if(polja[i-1][j+1]==Polje::Mina) brojmina[1][1]++;
				if(polja[i][j-1]==Polje::Mina) brojmina[1][1]++;
				if(polja[i+1][j-1]==Polje::Mina) brojmina[1][1]++;
			}
			if(i==x && j==y+1) {
				if(polja[i+1][j]==Polje::Mina) brojmina[1][2]++;
				if(polja[i][j+1]==Polje::Mina) brojmina[1][2]++;
				if(polja[i+1][j+1]==Polje::Mina) brojmina[1][2]++;
				if(polja[i-1][j-1]==Polje::Mina) brojmina[1][2]++;
				if(polja[i-1][j]==Polje::Mina) brojmina[1][2]++;
				if(polja[i-1][j+1]==Polje::Mina) brojmina[1][2]++;
				if(polja[i][j-1]==Polje::Mina) brojmina[1][2]++;
				if(polja[i+1][j-1]==Polje::Mina) brojmina[1][2]++;
				
			}
			if(i==x+1 && j==y-1) {
				if(polja[i+1][j]==Polje::Mina) brojmina[2][0]++;
				if(polja[i][j+1]==Polje::Mina) brojmina[2][0]++;
				if(polja[i+1][j+1]==Polje::Mina) brojmina[2][0]++;
				if(polja[i-1][j-1]==Polje::Mina) brojmina[2][0]++;
				if(polja[i-1][j]==Polje::Mina) brojmina[2][0]++;
				if(polja[i-1][j+1]==Polje::Mina) brojmina[2][0]++;
				if(polja[i][j-1]==Polje::Mina) brojmina[2][0]++;
				if(polja[i+1][j-1]==Polje::Mina) brojmina[2][0]++;
				
			}
			if(i==x+1 && j==y) {
				if(polja[i+1][j]==Polje::Mina) brojmina[2][1]++;
				if(polja[i][j+1]==Polje::Mina) brojmina[2][1]++;
				if(polja[i+1][j+1]==Polje::Mina) brojmina[2][1]++;
				if(polja[i-1][j-1]==Polje::Mina) brojmina[2][1]++;
				if(polja[i-1][j]==Polje::Mina) brojmina[2][1]++;
				if(polja[i-1][j+1]==Polje::Mina) brojmina[2][1]++;
				if(polja[i][j-1]==Polje::Mina) brojmina[2][1]++;
				if(polja[i+1][j-1]==Polje::Mina) brojmina[2][1]++;
				
			}
			if(i==x+1 && j==y+1) {
				if(polja[i+1][j]==Polje::Mina) brojmina[2][2]++;
				if(polja[i][j+1]==Polje::Mina) brojmina[2][2]++;
				if(polja[i+1][j+1]==Polje::Mina) brojmina[2][2]++;
				if(polja[i-1][j-1]==Polje::Mina) brojmina[2][2]++;
				if(polja[i-1][j]==Polje::Mina) brojmina[2][2]++;
				if(polja[i-1][j+1]==Polje::Mina) brojmina[2][2]++;
				if(polja[i][j-1]==Polje::Mina) brojmina[2][2]++;
				if(polja[i+1][j-1]==Polje::Mina) brojmina[2][2]++;
				
			}
		}
	}
	
	return brojmina;
}

void BlokirajPolje(Tabla &polja, int x, int y) {
	
	if(x<0 || y<0 || x>polja.size()-1 || y>polja[0].size()-1) throw std::domain_error("Polje (x,y) ne postoji");
	
	if(polja[x][y]!=Polje::BlokiranoPrazno && polja[x][y]!=Polje::BlokiranoPosjeceno && polja[x][y]!=Polje::BlokiranoMina) {
		
	for(int i=0; i<polja.size(); i++) {
		for(int j=0; j<polja[0].size(), j++) {
			if(i==x && j==y) {
				if(polja[i][j]==Polje::Prazno) polja[i][j]==Polje::BlokiranoPrazno;
				if(polja[i][j]==Polje::Posjeceno) polja[i][j]==Polje::BlokiranoPosjeceno;
				if(polja[i][j]==Polje::Mina) polja[i][j]==Polje::BlokiranoMina;
			}
		}
	}

	}
}

void DeblokirajPolje(Tabla &polja, int x, int y) {
	
	if(x<0 || y<0 || x>polja.size()-1 || y>polja[0].size()-1) throw std::domain_error("Polje (x,y) ne postoji");
	
	if(polja[x][y]==Polje::BlokiranoPrazno && polja[x][y]==Polje::BlokiranoPosjeceno && polja[x][y]==Polje::BlokiranoMina) {
		
	for(int i=0; i<polja.size(); i++) {
		for(int j=0; j<polja[0].size(), j++) {
			if(i==x && j==y) {
				if(polja[i][j]==Polje::BlokiranoPrazno) polja[i][j]==Polje::Prazno;
				if(polja[i][j]==Polje::BlokiranoPosjeceno) polja[i][j]==Polje::Posjeceno;
				if(polja[i][j]==Polje::BlokiranoMina) polja[i][j]==Polje::Mina;
			}
		}
	}

	}
	
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer) {
	
	int a=x;
	int b=y;
	polje[a][b]=Polje::Posjeceno;
	

				if(smjer==Smjerovi::GoreLijevo) { x=x-1; y=y-1; }
				if(smjer==Smjerovi::Gore) { x=x-1; y=y; }
				if(smjer==Smjerovi::GoreDesno) { x=x-1; y=y+1; }
				if(smjer==Smjerovi::Desno) { x=x; y=y+1; }
				if(smjer==Smjerovi::DoljeDesno) { x=x+1; y=y+1; }
				if(smjer==Smjerovi::Dolje) { x=x+1; y=y; }
				if(smjer==Smjerovi::DoljeLijevo) { x=x+1; y=y-1; }
				if(smjer==Smjerovi::Lijevo) { x=x; y=y-1; }
				
    
    if(polje[x][y]==Polje::Mina) {
		for(int i=0; i<polja.size(); i++) {
		     for(int j=0; j<polja[0].size(), j++) {
		     	polje[i][j]=Polje::Prazno;
		     }
		}
		return KrajPoraz;
	}
	
	else {
		for(int i=0; i<polja.size(); i++) {
		     for(int j=0; j<polja[0].size(), j++) {
		     	if(polje[i][j]==Polje::Prazno) pobjeda=0;
		     }
		}
		
		if(pobjeda==1) return KrajPobjeda;
		if(pobjeda==0) return NijeKraj;
		
	}
}


Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y) {
	if(novi_x<0 || novi_y<0 || novi_x>polja.size()-1 || novi_y>polja[0].size()-1) throw std::out_of_range("Izlazak van igrace table");
	if(polja[novi_x][novi_y]==Polje::Blokirano) throw logic_error("Blokirano polje");
	
	x=novi_x;	y=novi_y;
	int pobjeda=1;
	
	if(polje[novi_x][novi_y]==Polje::Mina) {
		for(int i=0; i<polja.size(); i++) {
		     for(int j=0; j<polja[0].size(), j++) {
		     	polje[i][j]=Polje::Prazno;
		     }
		}
		return KrajPoraz;
	}
	
	else {
		for(int i=0; i<polja.size(); i++) {
		     for(int j=0; j<polja[0].size(), j++) {
		     	if(polje[i][j]==Polje::Prazno) pobjeda=0;
		     }
		}
		
		if(pobjeda==1) return KrajPobjeda;
		if(pobjeda==0) return NijeKraj;
		
	}
	
}

void PrijaviGresku(KodoviGresaka greska) {
	
	if(greska==KodoviGresaka::PogresnaKomanda) std::cout << "Nerazumljiva komanda!";
	if(greska==KodoviGresaka::NedostajeParmetar) std::cout << "Komanda trazi parametar koji nije naveden!";
	if(greska==KodoviGresaka::NeispravanParametar) std::cout << "Parametar komande nije ispravan!";
	if(greska==KodoviGresaka::SuvisanParametar) std::cout << "Zadan je suvisan parametar nakon komande!";
	
}

	
	
	
}
int main ()
{
	std::string komanda;
		bool ispravnost;
	for(;;) {
		
		std::cout << "Unesi komandu: ";
		
		UnosKomande();
		
		
		
			
		}
	

	return 0;
}
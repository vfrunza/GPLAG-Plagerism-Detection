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

enum class Polje {
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru (int n, const std::vector<std::vector<int>> &mine) {
	if(n<=0) throw std::domain_error("Ilegalna velicina");
	Tabla tabla(n, std::vector<Polje>(n, Polje::Prazno));
	for (int i=0; i<mine.size(); i++) {
		if(mine[i].size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
		if(i>=n || mine[i].size()>=n) throw std::domain_error("Ilegalne pozicije mina");
	}
	for (int i=0; i<mine.size(); i++) {
		int x=mine[i][0];
		int y=mine[i][1];
		tabla[x][y]=Polje::Mina;
	}
	return tabla;
}

int OkolinaPolja (const Tabla &polja, int x, int y) {
	int br(0);
	if(x==0 && y==0) {
		for (int i=x; i<=x+1; i++) {
			for (int j=y; j<=y+1; j++) {
				if (i!=x && j!=y && polja[i][j]==Mina) br++;
			}
		}
	} else if (x==polja.size()-1 && y==0) {
		for (int i=x-1; i<=x; i++) {
			for (int j=0; j<=1; j++) {
				if(i!=x && j!=y && polja[i][j]==Mina) br++;
			}
		}
	} else if (x==0 && y==polja.size()-1) {
		for (int i=0; i<=x+1; i++) {
			for (int j=y-1; j<=polja.size()-1) {
				if (i!=x && j!=y && polja[i][j]==Mina) br++;
			}
		}
	} else if (x==polja.size()-1 && y==polja.size()-1) {
		for (int i=x-1; i<=x; i++) {
			for (int j=y-1; j<y; j++) {
				if(i!=x && y!=y && polja[i][j]==Mina) br++;
			}
		}
	} else if(x==0) {
		for (int i=x; i<=x+1; i++) {
			for (int j=y-1; j<=y+1; j++) {
				if(i!=x && j!=y && polja[i][j]==Mina) br++;
			}
		}
	} else if (y==0) {
		for (int i=x-1; i<=x+1; i++) {
			for (int j=y; j<=y+1; j++) {
				if(i!=x && j!=y && polja[i][j]==Mina) br++;
			}
		}
	} else if (x==polja.size()-1) {
		for (int i=x-1; i<=x; i++) {
			for (int j=y-1; j<=y+1; j++) {
				if (i!=x && j!=< && polja[i][j]==Mina) br++;
			}
		}
	} else if (y==polja.size()-1) {
		for (int i=x-1; i<=x+1; i++) {
			for (int j=y-1; j<=y; j++) {
				if (i!=x && j!=y && polja[i][j]==Mina) br++;
			}
		}
	} else {
		for (int i=x-1; i<=x+1; i+=2) {
			for (int j=y-1; j<=y+1; j+=2) {
				if(polja[i][j]==Mina) br++;
			}
		}
	} 
	
	
	return br;
}

std::vector<std::vector<int>> PrikaziOkolinu (const Tabla &polja, int x, int y) {
	if(x>=polja.size() || y>=polja[0].size() || x<0 || y<0) throw std::domain_error("Polje (x,y) ne postoji");
	std::vector<std::vector<int>> okolina(3, std::vector<int>(3));
	int red, kolona;
	if(x==0) {
		okolina[0]={0,0,0};
		if(y==0) {
			okolina[1][0]=0;
			okolina[2][0]=0;
			red=1; kolona=1;
			for (int i=0; i<=1; i++) {
				for (int j=0; j<=1; j++) {
					okolina[red][kolona]=OkolinaPolja(polja, i, j);
					kolona++;
				}
				red++;
			}
			
		} else if(y==polja.size()-1) {
			okolina[1][2]=0;
			okolina[2][2]=0;
			red=1; kolona=0;
			for (int i=0; i<=1; i++) {
				for (int j=y-1; j<=y; j++) {
					okolina[red][kolona]=OkolinaPolja(polja, i, j);
					kolona++;
				}
				red++;
			}
		} else {
			red=1; kolona=0;
			for (int i=0; i<=1; i++) {
				for (int j=y-1; j<=y+1; j++) {
					okolina[red][kolona]=OkolinaPolja(polja, i, j);
					kolona++;
				}
				red++;
			}
		}
	}
	else if (x==polja.size()-1) {
		okolina[2]={0,0,0};
		red=0;
		if(y==0) {
			okolina[0][0]=0;
			okolina[1][0]=0;
			kolona=1;
			for (int i=x-1; i<=x; i++) {
				for (int j=0; j<=1; j++) {
					okolina[red][kolona]=OkolinaPolja(polja, i, j);
					kolona++;
				}
				red++;
			}
		} else if (y==polja.size()-1) {
			okolina[0][2]=0;
			okolina[1][2]=0;
			for (int i=x-1; i<=x; i++) {
				for (int j=y-1; j<=y; j++) {
					okolina[red][kolona]=OkolinaPolja(polja, i, j);
					kolona++;
				}
				red++;
			}
		} else {
			
			
		}
		
	}
	
}



int main ()
{
	return 0;
}
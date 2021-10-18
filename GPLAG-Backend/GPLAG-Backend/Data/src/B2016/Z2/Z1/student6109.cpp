/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <complex>

enum class Polje {Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina};
enum class Smjerovi {GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo};
enum class Status {NijeKraj, KrajPoraz, KrajPobjeda};
enum class KodoviGresaka {PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar};
enum class Komande {PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru};

typedef std::vector<std::vector<Polje>>Tabla;

Tabla KreirajIgru(int n, std::vector<std::vector<int>>&mine) {
	Tabla Matrica(n, std::vector<Polje>(n, Polje::Prazno));
	int i=0;
	while(i<mine.size()) {
//		if(mine[i].size() != 2) {
//			throw domain_error("Ilegalan format zadavanja mina");
//		} else {
//			if(mine[i][0] >= n or mine[i][0] or mine[i][1] >= n or mine[i][1] < 0) {
//				throw domain_error("Ilegalne pozicije mina");
//			} else {
			Matrica[mine[i][0]][mine[i][1]] = Polje::Mina;
//			}
//		}
		i++;
	}
	return Matrica;	
}

void BlokirajPolje(Tabla &Polja, int x, int y) {
	if(Polja[x][y]==Polje::Mina) {
		Polja[x][y]=Polje::BlokiranoMina;
	} else {
		if(Polja[x][y]==Polje::Prazno) {
			Polja[x][y]=Polje::BlokiranoPrazno;
		} else {
			if(Polja[x][y]==Polje::Posjeceno) {
				Polja[x][y]=Polje::BlokiranoPosjeceno;
			}
		}
	}
}

void DeblokirajPolje(Tabla &Polja, int x, int y) {
	if(Polja[x][y]==Polje::BlokiranoMina) {
		Polja[x][y]=Polje::Mina;
	} else {
		if(Polja[x][y]==Polje::BlokiranoPrazno) {
			Polja[x][y]=Polje::Prazno;
		} else {
			if(Polja[x][y]==Polje::BlokiranoPosjeceno) {
				Polja[x][y]=Polje::Posjeceno;
			}
		}
	}
}

std::vector<std::vector<int>>PrikaziOkolinu(const Tabla &polja, int x, int y) {
	std::vector<std::vector<int>>Matrica(3, std::vector<int>(3));
	int a, b;
	int MINA=0;
	a=-1;
	b=0;
	for(int i=x-1; i<(x+2); i++) {
		a++;
		b=0;
		for(int j=y-1; j<(y+2); j++) {
			MINA=0;
			if(i<0 or i>=polja.size() or j<0 or j>=polja[0].size()) {
				b++;
				continue;
				} else {
					for(int k=i-1; k<i+2; k++) {
						for(int l=j-1; l<j+2; l++) {
							if(k<0 or k>=polja.size() or l<0 or l>=polja[0].size() or (k==i and l==j)) {
								continue;
							} else {
								if(polja[k][l]==Polje::Mina) {
								MINA++;
							}
						}
					}
				}
			Matrica[a][b]=MINA;
			b++;
			}
		}
	}
	return Matrica;
}

void BlokirajPolje(Tabla &polja, int x, int y) {
	
}

void PrijaviGresku(KodoviGresaka temp) {
	if(temp == KodoviGresaka::PogresnaKomanda) { std::cout << "Nerazumljiva komanda!"; }
	else { if(temp== KodoviGresaka::NedostajeParametar) { std::cout << "Komanda trazi parametar koji nije naveden!"; }
	else { if(temp == KodoviGresaka::NeispravanParametar) { std::cout << "Parametar komande nije ispravan!"; }
	else { if(temp == KodoviGresaka::SuvisanParametar) { std::cout << "Zadan je suvisan parametar nakon komande!"; }
			}
		}
	}
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer) {
	int x1=0;
	int y1=0;
	
	if(smjer == Smjerovi::Gore) {
		x1--;
	} else {
		if(smjer == Smjerovi::Dolje) {
			x1++;
		} else {
			if(smjer == Smjerovi::Lijevo) {
				y1--;
			} else {
				if(smjer == Smjerovi::Desno) {
					y1++;
				} else {
					if(smjer == Smjerovi::GoreLijevo) {
						x1--;
						y1--;
					} else {
						if(smjer == Smjerovi::GoreDesno) {
							x1--;
							y1++;
						} else {
							if(smjer == Smjerovi::DoljeLijevo) {
								x1++;
								y1--;
							} else {
								if(smjer == Smjerovi::DoljeDesno) {
									x1++;
									y1++;
								}
							}
						}
					}
				}
			}
		}
	}
	return Idi(polja, x, y, x+x1, y+y1);
}



int main () {
	std::vector<std::vector<int>> vek{ {0,0}, {1,1}, {2,2}, {3,3} };
	Tabla Matrica = KreirajIgru(4, vek);
	std::vector<std::vector<int>> okolina(PrikaziOkolinu(Matrica, 2, 1));
	for(std::vector<int> x : okolina) {
		for(int y : x) {
			std::cout << y << " ";
		}
		std::cout << std::endl;
	}
	
	return 0;
}
/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <string>

enum class Polje {
Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};

enum class Smjerovi {
GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};

typedef std::vector<std::vector<Polje>> Tabla;
typedef std::vector<std::vector<int>> Matrica;

Tabla KreirajTablu(int n){
	return Tabla(n, std::vector<Polje>(n, Polje::Prazno));
}

void IspisiTablu(const Tabla &t, int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++) std::cout << std::setw(4) << (int)t[i][j];
		std::cout << std::endl;
	}
}

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	auto tabla(KreirajTablu(n));
	if(mine.size()==0) throw std::domain_error("Ilegalan format zadavanja mina");
	for(int i=0; i<mine.size(); i++){
		if(mine[i].size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
		for(int j=0; j<mine[i].size(); j++){
			if(mine[i][j]>=n) throw std::domain_error("Ilegalne pozicije mina");
			int prva_kor(mine[i][0]), druga_kor(mine[i][1]);
			tabla[prva_kor][druga_kor]=Polje::Mina;
		}
	}
	return tabla;
}

int BrojacMina(const Tabla &t, int x, int y){
	int brojac(0);
	for(int i=x-1; i<=x+1; i++){
		for(int j=y-1; j<=y+1; j++){
			if(t[i][j]==Polje::Mina) brojac++;
		}
	}
	return brojac;
}

Matrica PrikaziOkolinu(const Tabla &polja, int x, int y){
	Matrica mat(3,std::vector<int>(3,0));
	bool lijevicosak(false), desnicosak(false), gornjicosak(false), donjicosak(false);
	if(x==0) lijevicosak=true;
	if(x==3) desnicosak=true;
	if(y==0) gornjicosak=true;
	if(y==3) donjicosak=true;
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(lijevicosak && gornjicosak){
				for(int i=x; i<x+1; i++){
			}
			if(desnicosak) mat[i][3]=0;
			if(gornjicosak) mat[0][j]=0;
			if(donjicosak) mat[3][j]=0;
			
		}
	}
	return mat;
}

int main ()
{
	std::vector<std::vector<int>> mine {{0,0}, {0,2}, {1,3}};
	auto tabla(KreirajIgru(5,mine));
	IspisiTablu(tabla,5);
	return 0;
}
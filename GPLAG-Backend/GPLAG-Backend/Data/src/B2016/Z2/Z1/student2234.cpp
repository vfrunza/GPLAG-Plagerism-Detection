/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include<iostream>
#include<stdexcept>
#include<vector>
enum class Polje {Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina};
typedef std::vector<std::vector<Polje>>Tabla;
typedef std::vector<std::vector<int>>Matrica;
Tabla KreirajTablu(int n,const std::vector<std::vector<int>>&mine){
	Tabla ploca(n,std::vector<Polje>(n,Polje::Prazno));
	ploca.resize(n);
	for(int i(0);i<n;i++){
		ploca[i].resize(n);
	}
	for(int i(0);i<mine.size();i++){
		for(int j(0);j<mine[i].size();j++){
			if(mine[j].size()!=2)throw std::domain_error("Ilegalan format zadavanja mina");
				if(mine[i][j]<0 || mine[i][j]>n)throw std::domain_error("Ilegalne pozicije mina");
				ploca[mine[i][0]][mine[j][0]]=Polje::Mina;
		}
	}	
	return ploca;
}
Matrica PrikaziOkolinu(int x,int y){
	Matrica rezultat(3,std::vector<int>(3));
	for(int i(x-1);i<x+2;i++){
		if(i<0){ i++; continue; }
		for(int j(y-1);j<y+2;j++){
			if(j<0){j++;continue; }
			
		}
	}
}
void BlokirajPolje(Tabla &ploca,int x,int y){
	if(x<0 || x>ploca.size() || y<0 || y<ploca[0].size()) throw std::domain_error("Polje (x,y) ne postoji");
}
int main ()
{
	return 0;
}
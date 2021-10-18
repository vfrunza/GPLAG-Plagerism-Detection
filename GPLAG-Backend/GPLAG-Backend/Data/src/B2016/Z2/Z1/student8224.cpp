/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>

enum class Polje {
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	Tabla nova(n);
	for(auto x: nova) {
		x.resize(n);
		for(auto i: x) i=Prazno;
	}
	for(auto x: mine) {
		if(x.size()!=2) throw domain_error("Ilegalan format zadavanja mina");
		for(auto i: x) if(i<0 || i>n) throw domain_error("Ilegalne pozicije mina");
	}
	for(auto x: mine)
		/*for(int i=0; i!=n; i++) 
			for(int j=0; j!=n; j++) 
				if(i=x[0] && j=x[1]) nova[i][j]=Mina;*/
		nova[x[0]][x[1]]=Mina;		
	return nova;	
}

std::vector<std::vector<int>> PrikaziOkolinu ( const Tabla &polja, int x, int y) {
	std::vector<std::vector<int>> okolina(3);
	for(auto x: okolina){
		x.resize(3);
		for(auto i: x) i=0;
	} 
	for(int i=0; i!=n; i++)
		for(int j=0; j!=n; j++) {
			if(x!=0 && x!=n && y!=0 && y!=n)
		}
}

void BlokirajPolje(Tabla &polja int x, int y){
	
}

void DeblokirajPolje(Tabla &polja, int x, int y){
	
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	
}

int main ()
{
	return 0;
}
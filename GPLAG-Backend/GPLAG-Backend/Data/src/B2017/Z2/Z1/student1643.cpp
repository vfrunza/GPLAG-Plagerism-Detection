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

typedef std::vector<std::vector<Polje>> Tabla;

enum class Polje {
	Prazno(0), Posjeceno, Mina(1), BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};

Tabla KreirajIgru (int n, const std::vector<std::vector<int>> &mine){
	for (int i(0); i<mine.size(); i++){
		
	}
	Tabla tabla;
	tabla.size()=n;
	for(int i(0); i<tabla.size(); i++) tabla.at(i).size()=n;
	for (int i(0); i<tabla.size(); i++){
		for (int j(0); j<tabla.size(); j++){
			if (mine.at(i).at(0) == i && mine.at(i).at(1) == j) tabla.at(i).at(j) = Mina;
			else tabla.at(i).at(j) = Prazno;
		}
	}
	return tabla;
}

void BlokirajPolje(Tabla &polja, int x, int y){
	if (polja.at(x).at(y) == Prazno) polja.at(x).at(y)=BlokiranoPrazno;
	if (polja.at(x).at(y) == Posjeceno) polja.at(x).at(y)=BlokiranoPosjeceno;
	if (polja.at(x).at(y) == Mina) polja.at(x).at(y)=BlokiranoMina;
}

void DeblokirajPolje 

int main (){
	
}
	return 0;
}
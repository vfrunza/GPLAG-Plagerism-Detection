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
#include <iomanip>
#include <vector>
#include <stdexcept>
enum class Polje{Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjecno, BlokiranoMina};

typedef std::vector<std::vector<Polje>> Tabla;
Tabla KreirajTablu(int n){
	return Tabla(n, std::vector<Polje>(n, Polje::Prazno));
}
template <typename tip>
void IspisiMatricu(tip m){
	for(auto x: m){
		for(auto x1:x) std::cout<<std::setw(6)<<int(x1);
		std::cout<<std::endl;
	}
	std::cout<<std::endl;
}

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	for(int i=0; i<mine.size();i++) if(mine.at(i).size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
	for(int i=0; i<mine.size(); i++) if(mine[i].at(0)>=n || mine.at(i).at(1)>=n) throw std::domain_error("Ilegalne pozicije mina");
	if(n < 1) throw std::domain_error("Ilegalna velicina");
	Tabla novatabla(KreirajTablu(n));
	for(int i=0; i<mine.size(); i++) novatabla.at(mine.at(i).at(0)).at(mine.at(i).at(1))=Polje::Mina;
	return novatabla;
}

//std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y);
//void BlokirajPolje(Tabla &polja, int x, int y);
//void DeblokirajBolje(Tabla &polja, int x, int y);
//Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer);
//Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y);
/*std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	std::vector<std::vector<int>> okolina(3,std::vector<int> (3,0));
	for(int i=x-1; i<=x+1; i++){
		for(int j=y-1; j<=y+1; j++){
		//	for(int l=i-1; l<i+1; l++){
		//		for(int k=j-1; k<j+1; k++){
					if(polja.at(i).at(j)==Polje::Mina) okolina.at(i-x+1).at(j-y+1)++;
		//		}
		//	}
		}
	}
	return okolina;
}*/
int main ()
{
	try{
	std::vector<std::vector<int>>  mine = {{0,1}, {0,4}, {1,3}, {1,4}, {2,0}, {2,1}, {2,3}};
	auto tabla=KreirajIgru(5,mine);
	IspisiMatricu(tabla);
//	auto okolina=PrikaziOkolinu(tabla,1,1);
//	IspisiMatricu(okolina);
	}catch(std::domain_error Izuzetak){
		std::cout<<"Izuzetak: "<<Izuzetak.what()<<std::endl;
	}
	return 0;
}
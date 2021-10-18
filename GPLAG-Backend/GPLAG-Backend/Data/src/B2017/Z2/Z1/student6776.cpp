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
#include <stdexcept>
#include <vector>

enum class Polje {Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina};

enum class Smjerovi {GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo};

enum class Status {NijeKraj, KrajPoraz, KrajPobjeda};

typedef std::vector<std::vector<Polje>> Tabla;

bool ValidnoPolje(Tabla &polje,int &x,int &y){
	if(x<0 || x>=polje.size() || y<0 || y>=polje.size()) return false;
	return true;
}

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	if(n<1) throw std::domain_error("Ilegalna veličina");
	for(int i(0) ; i < mine.size() ; i++){
		if(mine.at(i).size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
	}
	Tabla Igra(n,std::vector<Polje>(n,Polje::Prazno));
	for(int i(0) ; i<mine.size() ; i++){
		int x(mine.at(i).at(0)),y(mine.at(i).at(1));
		if(!ValidnoPolje(Igra,x,y)) throw std::domain_error("Ilegalne pozicije mina");
		Igra.at(x).at(y)=Polje::Mina;
	}
	return Igra;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	std::vector<std::vector<int>> okolina(3,std::vector<int>(3));
	int KretanjeRed[]{-1,-1,-1,0,0,0,1,1,1};
	int KretanjeKolona[]{-1,0,1,-1,0,1,-1,0,1};
	int k(0);
	for(int i(0) ; i<okolina.size() ; i++){
		for(int j(0) ; j<okolina.at(i).size() ; j++){
			int a(x+KretanjeRed[k]);
			int b(y+KretanjeKolona[k]);
			for(int l(0) ; l<9 ; l++){
				Tabla Igra(polja);
				int poz1(a+KretanjeRed[l]);
				int poz2(b+KretanjeKolona[l]);
				if((ValidnoPolje(Igra,poz1,poz2)) && polja.at(poz1).at(poz2)==Polje::Mina){
					okolina.at(i).at(j)++;
				}
			}
			k++;
		}
		
	}
	return okolina;
}

void BlokirajPolje(Tabla &polja, int x, int y){
	if(!ValidnoPolje(polja,x,y)) throw("Polje (x,y) ne postoji!");
	int broj(int(polja.at(x).at(y)));
	switch (broj){
		case 0:
			polja.at(x).at(y)=Polje::BlokiranoPrazno;
			break;
		case 1:
			polja.at(x).at(y)=Polje::BlokiranoPosjeceno;
			break;
		case 2:
			polja.at(x).at(y)=Polje::BlokiranoMina;
			break;
		default:
			break;
	}
}


void DeblokirajPolje(Tabla &polja, int x, int y){
	if(!ValidnoPolje(polja,x,y)) throw("Polje (x,y) ne postoji!");
	int broj(int(polja.at(x).at(y)));
	switch (broj){
		case 3:
			polja.at(x).at(y)=Polje::Prazno;
			break;
		case 4:
			polja.at(x).at(y)=Polje::Posjeceno;
			break;
		case 5:
			polja.at(x).at(y)=Polje::Mina;
			break;
		default:
			break;
	}
}

int main ()
{
//AT2 (c9) - funkcija Okolina primjer iz postavke
    std::vector<std::vector<int>> mine = {{0,1}, {0,4}, {1,3}, {1,4}, {2,0}, {2,1}, {2,3}} ;
    std::vector<std::vector<Polje>> tabla = KreirajIgru(5, mine);
    std::vector<std::vector<int>> okolina = PrikaziOkolinu(tabla, 1, 1);
    for(int i = 0; i < okolina.size(); i++)
    {
      for(int j = 0; j < okolina[i].size(); j++) std::cout << okolina[i][j] << " ";
      std::cout << std::endl;
    }
	return 0;
}
//enum Polje mjesto(Polje::BlokiranoPosjeceno);
	//std::cout << int(mjesto);
	/*
	Tabla Igra(KreirajIgru(4,{{0,0},{0,2},{1,3}}));
	BlokirajPolje(Igra,0,2);
	for(auto red: Igra){
		for(auto x: red){
			std::cout << int(x) << " ";
		}
		std::cout << std::endl;
	}
	*/
#include <iostream>


enum class Polje {
	Prazno, Posjeceno , Mina ,BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina 
};

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){

   Tabla Ploca=n;
   
   for(int i=0; i<n; i++) {
   	  Ploca.at(i).resize(n, Polje::Prazno);
   } 
   
   for(int i=0; i<mine.size(); i++) {
   	if(mine.at(i).size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
   	if(mine.at(i).at(0)<0|| n<=mine.at(i).at(0) || mine.at(i).at(1)<0 || n<=mine.at(i).at(1)) 
   	             throw std::domain_error("Ilegalne pozicije mina");
   	Ploca.at(mine.at(i).at(0)).at(mine.at(i).at(1)) = Polje::Mina;
   }
   return ploca;
}
   
   
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y) {
	std::vector<std::vector<int>> okolina(3);
	if(x<0 || polja.size()<=x || y<0 || polja.at(x).size()<=y) 
	       throw std::domain_error("Polje("+ std::to_string(x) + "," + std::to_string(y)+ ") ne postoji");
	       
	       for(int i=0; i<=2; i++) {
	       	okolina.at(i+1).resize(3,0);
	       	if(x+i<0 || polja.size()<=x+i) continue;
	       	for(int j=-1; j<=1; j++) {
	       		if(y+j<0 || polja.at(i+1).size()<=y+j) continue;
	       		okolina.at(i+1).at(j+1)=izbrojiMine(polja, x+i,y+j);
	       	}
	       }
	       return okolina;
}

void BlokirajPolje(Tabla &polja, int x, int y);
void DeblokirajPolje(Tabla &polja, int x, int y);
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer);
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y);

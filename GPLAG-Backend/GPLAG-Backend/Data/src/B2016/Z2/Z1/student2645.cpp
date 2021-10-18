#include <iostream>
#include <vector>
#include <cmath>

enum class Polje {
 Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};

typedef std::vector<std::vector<int>> Tabla;
Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	std::vector<std::vector<int>>matrica(n,std::vector<int>(0));
	for (int i = 0; i < n; i++) {
	   for (int j = 0; j < n; j++) {
	       if (matrica[i][j]==mine[i][j]) {
	           
	       }
	       
	   }
	}
	return matrica;
}
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y);
    void BlokirajPolje(Tabla &polja, int x, int y);
    void DeblokirajPolje(Tabla &polja, int x, int y);
    //Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer);
    //Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y);
    std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y);
int main ()
{
	
 
	return 0;
}
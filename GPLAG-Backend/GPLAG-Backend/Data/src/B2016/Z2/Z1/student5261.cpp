/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

enum class Polje{
	Prazno, Posjeceno, Mina, BlokiranoPosjeceno, BlokiranoPrazno, BlokiranoMina
};
enum class Smjerovi{
	GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};
enum class Status{
	NijeKraj, KrajPoraz, KrajPobjeda
};
enum class KodoviGresaka{
	PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};
enum class Komande{
	PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	
}
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	
}
void BlokirajPolje(Tabla &polja, int x, int y){
	
}
void DeblokirajPolje(Tabla &polja, int x, int y){
	
}
Status Idi(Tabla &polja,  int &x, int &y, Smjerovi smjer){
	
}
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	
}
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	
}
int main ()
{
	std::cout<<"Unesite broj polja: ";
	int BrojPolja;
	std::cin>>BrojPolja;
	Tabla Matrica(BrojPolja, std::vector<Polje>(BrojPolja));
	try{
		KreirajIgru( BrojPolja)
	}
	
	return 0;
}
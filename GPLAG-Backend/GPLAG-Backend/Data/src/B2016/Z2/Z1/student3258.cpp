/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
 #include <iostream>
 #include <vector>
 #include <stdexcept>
 
 
 using std::cin;
 using std::cout;
 using std::endl;
 using std::vector;

enum class Polje
{
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};

enum class Smjerovi
{
	GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, LIjevo
};

enum class Status
{
	NijeKraj, KrajPoraz, KrajPobjeda	
};

typedef vector<vector<Polje>> Tabla;



int main ()
{
	
	
	return 0;
}
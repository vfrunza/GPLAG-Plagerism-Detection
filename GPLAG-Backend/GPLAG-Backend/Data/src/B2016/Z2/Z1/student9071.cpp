/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>

typedef std::vector<std::vector<int>> Polje;
typedef std::vector<std::vector<int>> Tabla;

enum class Polje
{
	Prazno, Posjeceno, Mina, Blokirano Prazno, BlokiranoPosjeceno, BlokiranoMina
};

Tabla KreirajIgru(int n, const std::vector<std::vector<int>>&mine)
{
	Polje Prazno = 0;
	Polje Mina = 1;
	for (int i(0); i<n; i++)
	{
		for (int j(0); j<n; j++)
		{
			if (n<1) throw std::domain_error ("Ilegalan format zadavanja mina");
			if (mine[i][j] > n) throw std::domain_error ("Ilegalne pozicije mina");
			mine[i][j] = Prazno;
			mine[0][0] = Mina;
			mine[0][2] = Mina;
			mine[1][3] = Mina;
		}
	}
	for (int i(0); i<n; i++)
	{
		for (int j(0); j<n; j++)
		{
			std::cout << mine[i][j];
		}
	}
}
std::vector<std::vector<int>>PrikaziOkolinu(const Tabla &polja,int x, int y)
{
	
}
void BlokirajPolje(Tabla &polja,int x,int y);
void DeblokirajPolje(Tabla &polja,int x,int y);
Status Idi(Tabla &polja, int &x,int &y, Smjerovi smjer);
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y);
std::vector<std::vector<int>>PrikaziOkolinu const Tabla &polja, int x, int y);

int main ()
{
	int n;
	std::cout << "Unesite broj polja: ";
	std::cin >> n;
	std::cout << "Unesite pozicije mina: ";
	return 0;
}
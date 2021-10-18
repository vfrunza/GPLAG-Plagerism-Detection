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
#include <string>
#include <vector>

#include <stdexcept>

// KONSTANTE
const int noTypeOfField{3};

// ENUMI
enum class Polje {
	Prazno = 0, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};

enum class Smjerovi {
	GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};

enum class Status {
	NijeKraj, KrajPoraz, KrajPobjeda
};

// TYPEDEFOVI
typedef std::vector<std::vector<Polje>> Tabla;

// PROTOTIPI
// Pomocne funkcije
int moving(int, int);
std::string fieldNotValidString(int, int);
bool isNotValid(const Tabla&, int, int);
int numOfMines(const Tabla&, int, int);

Tabla KreirajIgru(int, const std::vector<std::vector<int>>&);
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla&, int, int);
void BlokirajPolje(Tabla&, int, int);
void DeblokirajPolje(Tabla&, int, int);
Status Idi(Tabla&, int&, int&, Smjerovi);
Status Idi(Tabla&, int&, int&, int, int);

int main ()
{
	int x = 0, y = 0;
	Tabla t = KreirajIgru(3, {{0,2}, {1,0}, {1,2}, {2,1}, {2,2}});
	Idi(t, x, y, Smjerovi::Desno);
	auto b = Idi(t, x, y, Smjerovi::Dolje);
	
	std::cout << int(b) << std::endl;
	std::cout << x << "," << y << std::endl;
	
	return 0;
}

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine)
{
	if (n <= 0)
		throw std::domain_error("Ilegalna velicina");
	
	Tabla polja(n, std::vector<Polje>(n, Polje::Prazno));
	
	for (auto mina : mine)
	{
		if (mina.size() != 2)
			throw std::domain_error("Ilegalan format zadavanja mina");
			
		if (mina.at(0) < 0 || mina.at(0) >= n || mina.at(1) < 0 || mina.at(1) >= n)
			throw std::domain_error("Ilegalne pozicije mina");
			
		polja.at(mina.at(0)).at(mina.at(1)) = Polje::Mina;
	}
	
	return polja;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y)
{
	if (isNotValid(polja, x, y))
		throw std::domain_error(fieldNotValidString(x, y));
	
	std::vector<std::vector<int>> res(3, std::vector<int>(3));
	
	for(int i{-1}; i <= 1; i++)
		for (int j{-1}; j <= 1; j++)
			res[i + 1][j + 1] = numOfMines(polja, x + i, y + j);
	
	return res;
}

void BlokirajPolje(Tabla& polja, int x, int y)
{
	if (isNotValid(polja, x, y))
		throw std::domain_error(fieldNotValidString(x, y));
		
	if (static_cast<int>(polja[x][y]) < noTypeOfField)
		polja[x][y] = static_cast<Polje>(static_cast<int>(polja[x][y]) + noTypeOfField);
}

void DeblokirajPolje(Tabla& polja, int x, int y)
{
	if (isNotValid(polja, x, y))
		throw std::domain_error(fieldNotValidString(x, y));
		
	if (static_cast<int>(polja[x][y]) >= noTypeOfField)
		polja[x][y] = static_cast<Polje>(static_cast<int>(polja[x][y]) - noTypeOfField);
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y)
{
	if (isNotValid(polja, novi_x, novi_y))
		throw std::out_of_range("Izlazak van igrace table");
	
	if (static_cast<int>(polja[novi_x][novi_y]) >= noTypeOfField)
		throw std::logic_error("Blokirano polje");
	
	polja[x][y] = Polje::Posjeceno;
	x = novi_x;
	y = novi_y;
	
	if (polja[x][y] == Polje::Mina)
	{
		polja = std::move(KreirajIgru(polja.size(), {}));
		return Status::KrajPoraz;
	}
	
	for (int i = 0; i < polja.size(); i++)
		for (int j = 0; j < polja[i].size(); j++)
			if ((polja[i][j] == Polje::Prazno || polja[i][j] == Polje::BlokiranoPrazno) && i != novi_x && j != novi_y)
				return Status::NijeKraj;
	
	return Status::KrajPobjeda;
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer)
{
	return Idi(polja, x, y, moving(x, static_cast<int>(smjer)), moving(y, static_cast<int>(smjer) + 2));
}

int moving(int pos, int dir)
{
	if (dir % 4 == 3)
		return pos;
		
	return pos + ((dir / 4) % 2 == 0 ? -1 : 1);
}

bool isNotValid(const Tabla &polja, int x, int y)
{
	return x < 0 || x >= polja.size() || y < 0 || y >= polja[0].size();
}

std::string fieldNotValidString(int x, int y)
{
	return "Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji";
}

int numOfMines(const Tabla &polja, int x, int y)
{
	int sum{0};
	
	for (int i{0}; i < 8; i++)
	{
		int new_x{moving(x, i)};
		int new_y{moving(y, i + 2)};
		sum += !isNotValid(polja, new_x, new_y) &&
			(polja[new_x][new_y] == Polje::Mina || polja[new_x][new_y] == Polje::BlokiranoMina);
	}
	
	return sum;
}
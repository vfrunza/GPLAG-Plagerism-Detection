#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>

const int X_COORINDATE(0);
const int Y_COORDINATE(1);

enum class Polje         { Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina                     };
enum class Status        { NijeKraj, KrajPoraz, KrajPobjeda                                                                };
enum class Komande       { PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru };
enum class Smjerovi      { GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo                      };
enum class KodoviGresaka { PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar                      };

typedef std::vector<std::string>        ListOfStrings;
typedef std::vector<std::vector<int>>   IntMatrix;
typedef std::vector<std::vector<Polje>> Tabla;

const std::vector<Polje> fields          { Prazno, Posjeceno, Mina };

const ListOfStrings direction_parameters { "DoL"  , "DoD" , "GL"   ,  "GD"   , "Do"  , "G"    , "D"   , "L"     };
const IntMatrix offsets                  { {-1, 1}, {1, 1}, {-1, -1}, {1, -1}, {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

using namespace Polje;
using namespace Status;
using namespace Komande;
using namespace Smjerovi;
using namespace KodoviGresaka;

bool isOutOfBounds(int n, int x, int y)
{
	return ((x < 0 || x >= n) || (y < 0 || y >= n));
}

Tabla KreirajIgru(int n, const IntMatrix &mine)
{
	if (n <= 0) throw std::domain_error("Ilegalna velicina\n");
	
	for (int nth_mine(0); nth_mine < mine.size(); nth_mine++)
		if (mine.at(nth_mine).size() != 2) 
			throw std::domain_error("Ilegalan format zadavanja mina\n");
		else if (isOutOfBounds(n, mine.at(nth_mine).at(X_COORINDATE), mine.at(nth_mine).at(Y_COORDINATE)))
			throw std::domain_error("Ilegalne pozicije mina\n");
	
	Tabla field(n, std::vector<Polje>(n, Prazno));
	for (int nth_mine(0); nth_mine < mine.size(); nth_mine++)
		field.at(mine.at(nth_mine).at(Y_COORDINATE)).at(mine.at(nth_mine).at(X_COORINDATE)) = Mina;
		
	return field;
}

int countMines(const Tabla &polja, int x, int y, int radius)
{
	int n_mines(0);
	for (int y_prime(y - radius); y_prime <= y + radius; y_prime++)
		for (int x_prime(x - radius); x_prime <= x + radius; x_prime++)
			if (isOutOfBounds(polja.size(), x_prime, y_prime) || (x_prime == x && y_prime == y))
				;
			else if (polja.at(y_prime).at(x_prime) == Mina)
				n_mines++;
				
	return n_mines;
}

IntMatrix PrikaziOkolinu(const Tabla &polja, int x, int y)
{
	if (isOutOfBounds(polja.size(), x, y)) throw std::domain_error("Polje (x, y) ne postoji");
	
	const int radius(1);
	IntMatrix surroundings(radius, std::vector<int>(radius));
	for (int y_prime(y - radius), surroundings_y(0); y_prime <= y + radius; y_prime++, surroundings_y++)
		for (int x_prime(x - radius), surroundings_x(0); x_prime <= x + radius; x_prime++, surroundings_x++)
			if (isOutOfBounds(polja.size(), x_prime, y_prime))
				surroundings.at(surroundings_y).at(surroundings_x) = 0;
			else
				surroundings.at(surroundings_y).at(surroundings_x) = countMines(polja, x_prime, y_prime, radius);
}

void BlokirajPolje(Tabla &polja, int x, int y)
{
	if (isOutOfBounds(polja.size(), x, y)) throw std::domain_error("Polje (x, y) ne postoji");
	
	for (int i(0); i < fields.size(); i++)
		if (polja.at(y).at(y) == fields.at(i)) { polja.at(y).at(x) = fields.at(i) + fields.size(); break; }
}

void DeblokirajPolje(Tabla &polja, int x, int y)
{
	if (isOutOfBounds(polja.size(), x, y)) throw std::domain_error("Polje (x, y) ne postoji");
	
	for (int i(0); i < fields.size(); i++)
		if (polja.at(y).at(y) == fields.at(i)) { polja.at(y).at(x) = fields.at(i) - fields.size(); break; }
}

bool isVictory(Tabla &polja, int x, int y)
{
	for (int y_prime(0); y_prime < polja.size(); y_prime++)
		for (int x_prime(0); x_prime < polja.size(); x_prime++)
			if (polja.at(y_prime).at(x_prime) == Prazno && (y_prime != y && x_prime != x)) return false;

	return true;
}

Status updateStatus(Tabla &polja, int x, int y)
{
	if (polja.at(y).at(x) == Mina)
	{
		for (int y_prime(0); y_prime < polja.size(); y_prime++)
			for (int x_prime(0); x_prime < polja.size(); x_prime++)
				polja.at(y_prime).at(x_prime) = Prazno;
				
		return KrajPoraz;
	}
	else if (isVictory(polja, x, y))
		return KrajPobjeda;
	
	return NijeKraj;
}

void checkMove(Tabla &polja, int x, int y)
{
	if (isOutOfBounds(polja.size(), x, y))
		throw std::out_of_range("Izlazak van igrace table");
	for (int i(0); i < fields.size(); i++))
		if (polja.at(y).at(x) == fields.at(i) + fields.size())
			throw std::logic_error("Blokirano polje");
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer)
{
	int x_prime(x), y_prime(y);
	for (int nth_direction; nth_direction < directions.size(); nth_direction++)
		if (smjer == directions.at(nth_direction))
		{
			x_prime += offsets.at(nth_direction).at(X_COORINDATE);
			y_prime += offsets.at(nth_direction).at(Y_COORINDATE);
			break;
		}
	
	checkMove(polja, x_prime, y_prime);
	x = x_prime;
	y = y_prime;
	return updateStatus(polja, x, y);
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y)
{
	checkMove(polja, novi_x, novi_y);
	x = novi_x;
	y = novi_y;
	return updateStatus(polja, x, y);
}

void PrijaviGresku(KodoviGresaka &greska)
{
	switch (greska)
	{
		case PogresnaKomanda    : std::cout << "Nerazumljiva komanda!\n"                     ; break;
		case NedostajeParametar : std::cout << "Komanda trazi parametar koji nije naveden!\n"; break;
		case NeispravanParametar: std::cout << "Parametar komande nije ispravan!\n"          ; break;
		case SuvisanParametar   : std::cout << "Zadan je suvisan parametar nakon komande!\n" ; break;
	}
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska)
{
	std::string input_line;
	std::getline(std::cin, input_line);
	
	// Parse the input...
	
	// I do not write poetry,
	// I only speak my mind.
	// And the only thing on it right now
	// Is the fact that I wanna cry.
}

void printCurrentPosition(Status current_status, Tabla &polja, int x, int y)
{
	std::cout << "Tekuca pozicija igraca je (" << x << ", " << y << ")\n";
	if      (current_status == KrajPobjeda)    { std::cout << "Bravo, obisli ste sva sigurna polja\n"; ZavrsiIgru(); }
	else if (current_status == KrajPoraz  )    { std::cout << "Nagazili ste na minu\n"               ; ZavrsiIgru(); }
}

{
void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Gore, int p_x = 0, int p_y = 0)
	switch (komanda)
	{
		case KreirajIgru:
			// TODO...
		
		case ZavrsiIgru:
			for (int i(0); i < polja.size(); i++)
				for (int j(0); j < polja.size(); j++)
					polja.at(i).at(j) = Prazno;
			throw std::runtime_error("Igra zavrsena\n");
		
		case PrikaziOkolinu:
			IntMatrix surroundings(PrikaziOkolinu(polja, x, y));
			for (int i(0); i < surroundings.size(); i++)
			{
				for (int j(0); j < surroundings.size(); j++)
					std::cout << surroundings.at(i).at(j) << " ";
				std::cout << std::endl;
			}
			break;		
		
		case PomjeriJednoMjesto: Status current_status(Idi(polja, x, y, p_smjer )); printCurrentPosition(current_status, polja, x, y); break;
		case PomjeriDalje      : Status current_status(Idi(polja, x, y, p_x, p_y)); printCurrentPosition(current_status, polja, x, y); break;
		case Blokiraj          : BlokirajPolje(polja, x, y)                                                                          ; break;
		case Deblokiraj        : DeblokirajPolje(polja, x, y)                                                                        ; break;
		
	}
}

int main (void)
{
	// TODO...
	
	return 0;
}
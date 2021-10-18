#include <iostream>
#include <vector>
#include <stdexcept>
#include <sstream>
#include <string>
using std::vector;
using std::string;
using std::cin;

enum class Polje
{
    Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};
typedef vector<vector<Polje>> Tabla;
enum class Smjerovi
{
    GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};
enum class Status
{
    NijeKraj, KrajPoraz, KrajPobjeda
};
enum class KodoviGresaka
{
    PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};
enum class Komande
{
    PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};
template <typename T> string int_str(T x)
{
	std::ostringstream s; s << x; return s.str();
}
Tabla KreirajIgru(int n, const vector<vector<int>> &mine)
{
	for (const vector<int> &v : mine)
		if (v.size() != 2) throw std::domain_error("Ilegalan format zadavanja mina");
	if (n <= 0) throw std::domain_error("Ilegalna velicina");
	for (const vector<int> &v : mine)
		if (v.at(0) < 0 || v.at(1) < 0 || v.at(0) >= n || v.at(1) >= n) throw std::domain_error("Ilegalne pozicije mina");
	Tabla t(n, vector<Polje>(n, Polje::Prazno));
	for (const vector<int> &v : mine)
		t.at(v.at(0)).at(v.at(1)) = Polje::Mina;
	return t;
}
vector<vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y)
{
	if (x < 0 || y < 0 || x >= polja.size() || y >= polja.at(0).size())
		throw std::domain_error("Polje (" + int_str(x) + ',' + int_str(y) + ") ne postoji");
	vector<vector<int>> mat(3, vector<int>(3));
	for (int i(0); i < 3; i++)
		for (int j(0); j < 3; j++)
			for (int k(x+i-2); k <= x+i; k++)
				for (int l(y+j-2); l <= y+j; l++)
					if ((k != x+i-1 || l != y+j-1) && 0 <= k && k < polja.size()
					&& 0 <= l && l < polja.at(k).size() && polja.at(k).at(l) == Polje::Mina) mat.at(i).at(j)++;
	return mat;
}
void BlokirajPolje(Tabla &polja, int x, int y)
{
	if (x < 0 || y < 0 || x >= polja.size() || y >= polja.at(0).size())
		throw std::domain_error("Polje (" + int_str(x) + ',' + int_str(y) + ") ne postoji");
	if (int(polja.at(x).at(y)) < 3) polja.at(x).at(y) = Polje(int(polja.at(x).at(y))+3);
}
void DeblokirajPolje(Tabla &polja, int x, int y)
{
	if (x < 0 || y < 0 || x >= polja.size() || y >= polja.at(0).size())
		throw std::domain_error("Polje (" + int_str(x) + ',' + int_str(y) + ") ne postoji");
	if (int(polja.at(x).at(y)) >= 3) polja.at(x).at(y) = Polje(int(polja.at(x).at(y))-3);
}
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y)
{
	if (novi_x < 0 || novi_y < 0 || novi_x >= polja.size() || novi_y >= polja.at(0).size())
		throw std::out_of_range("Izlazak van igrace table");
	if (int(polja.at(novi_x).at(novi_y)) >= 3) throw std::logic_error("Blokirano polje");
	polja.at(x).at(y) = Polje::Posjeceno;
	if (polja.at(x = novi_x).at(y = novi_y) == Polje::Mina)
	{
		polja = Tabla(polja.size(), vector<Polje>(polja.at(0).size(), Polje::Prazno));
		return Status::KrajPoraz;
	}
	for (const auto &v : polja)
		for (const Polje &q : v)
			if (q == Polje::Prazno && (&polja.at(x).at(y) != &q)) return Status::NijeKraj;
	return Status::KrajPobjeda;
}
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer)
{
	int _y[] {-1, 0, 1, 1, 1, 0, -1, -1};
	return Idi(polja, x, y, x + ((int(smjer)+1) % 4 != 0) * (int(smjer) < 4 ? -1 : 1), y + _y[int(smjer)]);
}
void PrijaviGresku(KodoviGresaka kod)
{
	char ispisi[4][42]{"Nerazumljiva komanda", "Komanda trazi parametar koji nije naveden",
        "Zadan je suvisan parametar nakon komande", "Parametar komande nije ispravan"};
	std::cout << ispisi[int(kod)] << "!\n";
}
bool ukloni() {	return cin.get() || true; }
bool procitaj(char c) { return cin.peek() == c && ukloni(); }
bool cifra(char c) { return '0' <= c && c <= '9'; }
bool ocisti()
{
	cin.clear();
	cin.ignore(10000, '\n');
	return false;
}
bool ucitaj_sa_razmakom(char c)
{
	while (procitaj(' '));
	return cin.peek() == c;
}
bool unos_koord(int &x, int &y)
{
	int c(cin.peek()), a, b;
	if (c == '\n') cin.get();
	if (!ucitaj_sa_razmakom('(')) return ocisti();
	cin.get();
	while ((c = cin.peek()) == ' ') cin.get();
	if (!cifra(c) || !(cin >> a) || !ucitaj_sa_razmakom(',')) return ocisti();
	cin.get();
	while ((c = cin.peek()) == ' ') cin.get();
	if (!cifra(c) || !(cin >> b) || !ucitaj_sa_razmakom(')')) return ocisti();
	cin.get();
	if (!ucitaj_sa_razmakom('\n')) return ocisti();
	x = a; y = b;
	return !ocisti();
}
bool samo_razmak()
{
	if (cin.peek() != ' ' && cin.peek() != '\n') return false;
	while (procitaj(' ')); 
	return cin.peek() == '\n';
}
bool ucitaj_broj(int &x)
{
	int y;
	if (cifra(cin.peek()) && cin >> y && (cin.peek() == '\n' || cin.peek() == ' ')) x = y;
	else return false;
	return true;
}
bool vrati_gresku(int gr, KodoviGresaka &greska)
{
	greska = KodoviGresaka(gr);
	return ocisti();
}
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska)
{
	int a, b, c;
	if (cin.peek() == '\n') return vrati_gresku(0, greska);
	if ((c = cin.get()) == ' ' && cin.peek() != '\n') c = cin.get();
	if (c == 'K' || c == 'Z')
		if (!samo_razmak()) return vrati_gresku(2, greska);
		else komanda = c == 'K' ? Komande::KreirajIgru : Komande::ZavrsiIgru;
	else if (c == 'B' || c == 'D' || (c == 'P' && procitaj('>')))
		if (samo_razmak()) return vrati_gresku(1, greska);
		else if (ucitaj_broj(a) && (samo_razmak() || cifra(cin.peek())) && ucitaj_broj(b) && samo_razmak())
		{
			komanda = c == 'B' ? Komande::Blokiraj : (c == 'D' ? Komande::Deblokiraj : Komande::PomjeriDalje);
			x = a; y = b;
		}
		else return vrati_gresku(3, greska);
	else if (c == 'P')
		if (procitaj('O'))
			if (!samo_razmak()) return vrati_gresku(2, greska);
			else komanda = Komande::PrikaziOkolinu;
		else if (procitaj('1'))
		{
			if (samo_razmak()) return vrati_gresku(1, greska);
			string s;
			cin >> s;
			string komande[]{"GL", "G", "GD", "D", "DoD", "Do", "DoL", "L"};
			if (samo_razmak())
				for (int i(0); i < 8; i++)
					if (s == komande[i])
					{
						smjer = Smjerovi(i);
						komanda = Komande::PomjeriJednoMjesto;
						return !ocisti();
					}
			return vrati_gresku(3, greska);
		}
		else return vrati_gresku(0, greska);
	else return vrati_gresku(0, greska);
	return !ocisti();
}
void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0)
{
	try
	{
		Status st(Status::NijeKraj);
		if (int(komanda) < 2)
		{
			st = komanda == Komande::PomjeriDalje ? Idi(polja, x, y, p_x, p_y) : Idi(polja, x, y, p_smjer);
			std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")\n";
			if (st == Status::KrajPobjeda) std::cout << "Bravo, obisli ste sva sigurna polja\n";
			else if (st == Status::KrajPoraz) std::cout << "Nagazili ste na minu\n";
		}
		if (st != Status::NijeKraj || komanda == Komande::ZavrsiIgru)
		{
			if (!polja.empty()) polja = Tabla(polja.size(), vector<Polje>(polja.at(0).size(), Polje::Prazno));
			throw std::runtime_error("Igra zavrsena");
		}
		switch (komanda)
		{
			case Komande::Blokiraj:
				BlokirajPolje(polja, p_x, p_y); break;
			case Komande::Deblokiraj:
				DeblokirajPolje(polja, p_x, p_y); break;
			case Komande::PrikaziOkolinu:
				for (const vector<int> &v : PrikaziOkolinu(polja, x, y))
				{
					for (int x : v) std::cout << x << ' ';
					std::cout << std::endl;
				}
				break;
			case Komande::KreirajIgru:
			{
				int n, _x(0), _y(0);
				std::cout << "Unesite broj polja: ";
				while (!((cifra(cin.peek()) || procitaj(' ')) && ucitaj_broj(n) && samo_razmak() && n > 0)) 
				{
					std::cout << "Greska, unesite ponovo!\nUnesite broj polja: ";
					ocisti();
				}
				ocisti();
				std::cout << "Unesite pozicije mina: ";
				vector<vector<int>> mine;
				while (cin.peek() != '.')
					if (!unos_koord(_x, _y) || _x < 0 || _y < 0 || _x >= n || _y >= n || (_x == 0 && _y == 0))
						std::cout << "Greska, unesite ponovo!\n";
					else mine.push_back({_x, _y});
				polja = KreirajIgru(n, mine);
				ocisti();
			}
			default: break;
		}
	}
	catch (std::runtime_error e) { throw; }
	catch (const std::exception &e) { std::cout << e.what() << '\n'; }
}
int main()
{
	try
	{
		Komande kom;
		Smjerovi smjer;
		Tabla tabla;
		int x(0), y(0), _x(0), _y(0);
		KodoviGresaka greska;
		for (;;)
			try
			{
				std::cout << "Unesite komandu: ";
				if (UnosKomande(kom, smjer, _x, _y, greska)) IzvrsiKomandu(kom, tabla, x, y, smjer, _x, _y);
				else PrijaviGresku(greska);
			}
			catch (std::logic_error e) { std::cout << e.what() << std::endl; }
			catch (...) { throw; }
	}
	catch (...) { std::cout << "Dovidjenja!"; }
	return 0;
}
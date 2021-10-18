/*B 16/17, Zadaća 2, Zadatak 1

	NAPOMENA: i javni ATo-vi su dio postavke

	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba

*/
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

enum class Komande
{
    PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};

enum class KodoviGresaka
{
    PogresnaKomanda, NedostajeParmetar, SuvisanParametar, NeispravanParametar
};

enum class Status
{
    NijeKraj, KrajPoraz, KrajPobjeda
};

enum class Smjerovi
{
    GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};

enum class Polje
{
    Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};

using std::cout;
using std::cin;
using std::endl;
using std::string;
typedef std::vector<std::vector<Polje>> Tabla;
typedef std::vector<std::vector<int>> Matrica;
typedef std::vector<int> Vektor;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine)
{
	for(int i = 0; i < mine.size() - 1; i++) {
		if(mine.at(i).size() != mine.at(i + 1).size())
			throw std::domain_error ("Ilegalan format zadavanje mina");
		for(int j = 0; j < mine.at(0).size(); j++) {
			if(mine.at(i).at(j) > n)
				throw std::domain_error("Ilegalne pozicije mina");
		}
	}

	Tabla polja(n, std::vector<Polje> (n, Polje::Prazno));

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			for(int k = 0; k < mine.size(); k++) {
				for(int l = 0; l < mine.at(0).size() - 1; l++) {
					if(i == mine.at(k).at(l)) {
						if(j == mine.at(k).at(l + 1)) {
							polja.at(i).at(j) = Polje::Mina;
							break;
						}
					} else break;
				}
			}
		}
	}

	return polja;
}

Matrica PrikaziOkolinu (const Tabla &polja, int x, int y)
{
	if(x >= polja.size() || y >= polja[0].size() || x < 0 || y < 0)
		throw std::domain_error("Polje (x,y) ne postoji");

	Matrica mat;
	Vektor temp;
	for(int i = x - 1; i <= x + 1; i++) {
		for(int j = y - 1; j <= y + 1; j++) {
			int br(0);
			for(int k = i - 1; k <= i + 1; k++) {
				for(int l = j - 1; l <= j + 1; l++) {
					if(k == i && l == j) continue;
					if(k < 0 || k >= polja.size() || l < 0 || l >= polja[0].size() || polja[k][l] == Polje::Prazno )
						continue;
					else br += 1;
				}
			}
			temp.push_back(br);
			br = 0;
		}
		mat.push_back(temp);
		temp.clear();
	}
	return mat;
}

void BlokirajPolje(Tabla &polja, int x, int y)
{
	if(x >= polja.size() || x < 0 || y >= polja[0].size() || y < 0)
		throw std::domain_error ("Polje (x,y) ne postoji");

	for(int i = 0; i < polja.size(); i++) {
		for(int j = 0; j < polja[0].size(); j++) {
			if(i == x && j == y) {
				if(polja[i][j] == Polje::Prazno) polja[i][j] = Polje::BlokiranoPrazno;
				if(polja[i][j] == Polje::Mina) polja[i][j] = Polje::BlokiranoMina;
				if(polja[i][j] == Polje::Posjeceno) polja[i][j] = Polje::BlokiranoPosjeceno;
			}
		}
	}
}

void DeblokirajPolje(Tabla &polja, int x, int y)
{
	if(x >= polja.size() || x < 0 || y >= polja[0].size() || y < 0)
		throw std::domain_error ("Polje (x,y) ne postoji");

	for(int i = 0; i < polja.size(); i++) {
		for(int j = 0; j < polja[0].size(); j++) {
			if(i == x && j == y) {
				if(polja[i][j] == Polje::BlokiranoPrazno) polja[i][j] = Polje::Prazno;
				if(polja[i][i] == Polje::BlokiranoPosjeceno) polja[i][j] = Polje::Posjeceno;
				if(polja[i][j] == Polje::BlokiranoMina) polja[i][j] = Polje::Mina;
			}
		}
	}
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer)
{
	int i(x), j(y);
	if(smjer == Smjerovi::GoreLijevo) {
		if(i - 1 < 0 || j - 1 < 0) throw std::out_of_range ("Izlazak van igrace table");
		else {
			if(polja[i - 1][j - 1] == Polje::BlokiranoPrazno || polja[i - 1][j - 1] == Polje::BlokiranoMina || polja[i - 1][j - 1] == Polje::BlokiranoPosjeceno)
				throw std::logic_error("Blokirano polje");
			if(polja[i - 1][j - 1] == Polje::Mina) return Status::KrajPoraz;
			polja[i][j] = Polje::Posjeceno;
			x = x - 1;
			y = y - 1;
		}
	}
	if(smjer == Smjerovi::Gore) {
		if(i - 1 < 0) throw std::out_of_range ("Izlazak van igrace table");
		else {
			if(polja[i - 1][j] == Polje::BlokiranoPrazno || polja[i - 1][j] == Polje::BlokiranoMina || polja[i - 1][j] == Polje::BlokiranoPosjeceno)
				throw std::logic_error("Blokirano polje");
			if(polja[i - 1][j] == Polje::Mina) return Status::KrajPoraz;
			polja[i][j] = Polje::Posjeceno;
			x = x - 1;
		}
	}
	if(smjer == Smjerovi::GoreDesno) {
		if(i - 1 < 0 || j + 1 == polja[0].size()) throw std::out_of_range ("Izlazak van igrace table");
		else {
			if(polja[i - 1][j + 1] == Polje::BlokiranoPrazno || polja[i - 1][j + 1] == Polje::BlokiranoMina || polja[i - 1][j + 1] == Polje::BlokiranoPosjeceno)
				throw std::logic_error("Blokirano polje");
			if(polja[i - 1][j + 1] == Polje::Mina) return Status::KrajPoraz;
			polja[i][j] = Polje::Posjeceno;
			x = x - 1;
			y = y + 1;
		}
	}
	if(smjer == Smjerovi::Desno) {
		if(j + 1 == polja[0].size()) throw std::out_of_range ("Izlazak van igrace table");
		else {
			if(polja[i][j + 1] == Polje::BlokiranoPrazno || polja[i][j + 1] == Polje::BlokiranoMina || polja[i][j + 1] == Polje::BlokiranoPosjeceno)
				throw std::logic_error("Blokirano polje");
			if(polja[i][j + 1] == Polje::Mina) return Status::KrajPoraz;
			polja[i][j] = Polje::Posjeceno;
			y = y + 1;
		}
	}
	if(smjer == Smjerovi::DoljeDesno) {
		if(i + 1 == polja.size() || j + 1 == polja[0].size()) throw std::out_of_range ("Izlazak van igrace table");
		else {
			if(polja[i + 1][j + 1] == Polje::BlokiranoPrazno || polja[i + 1][j + 1] == Polje::BlokiranoMina || polja[i + 1][j + 1] == Polje::BlokiranoPosjeceno)
				throw std::logic_error("Blokirano polje");
			if(polja[i + 1][j + 1] == Polje::Mina) return Status::KrajPoraz;
			polja[i][j] = Polje::Posjeceno;
			x = x + 1;
			y = y + 1;
		}
	}
	if(smjer == Smjerovi::Dolje) {
		if(i + 1 == polja.size()) throw std::out_of_range ("Izlazak van igrace table");
		else {
			if(polja[i + 1][j] == Polje::BlokiranoPrazno || polja[i + 1][j] == Polje::BlokiranoMina || polja[i + 1][j] == Polje::BlokiranoPosjeceno)
				throw std::logic_error("Blokirano polje");
			if(polja[i + 1][j] == Polje::Mina) return Status::KrajPoraz;
			polja[i][j] = Polje::Posjeceno;
			x = x + 1;
		}
	}
	if(smjer == Smjerovi::DoljeLijevo) {
		if(i + 1 == polja.size() || j - 1 < 0) throw std::out_of_range ("Izlazak van igrace table");
		else {
			if(polja[i + 1][j - 1] == Polje::BlokiranoPrazno || polja[i + 1][j - 1] == Polje::BlokiranoMina || polja[i + 1][j - 1] == Polje::BlokiranoPosjeceno)
				throw std::logic_error("Blokirano polje");
			if(polja[i + 1][j - 1] == Polje::Mina) return Status::KrajPoraz;
			polja[i][j] = Polje::Posjeceno;
			x = x + 1;
			y = y - 1;
		}
	}
	if(smjer == Smjerovi::Lijevo) {
		if(j - 1 < 0) throw std::out_of_range ("Izlazak van igrace table");
		else {
			if(polja[i][j - 1] == Polje::BlokiranoPrazno || polja[i][j - 1] == Polje::BlokiranoMina || polja[i][j - 1] == Polje::BlokiranoPosjeceno)
				throw std::logic_error("Blokirano polje");
			if(polja[i][j - 1] == Polje::Mina) return Status::KrajPoraz;
			polja[i][j] = Polje::Posjeceno;
			y = y - 1;
		}
	}
	bool prazno = false;
	for(int i = 0; i < polja.size(); i++) {
		for(int j = 0; j < polja[0].size(); j++)
			if(polja[i][j] == Polje::Prazno) prazno = true;
	}
	if(prazno == false) return Status::KrajPobjeda;

	return Status::NijeKraj;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y)
{
	if(x < 0 || x > polja.size() || y < 0 || y > polja[0].size())
		throw std::out_of_range ("Izlazak van igrace table");
	if(novi_x < 0 || novi_x > polja.size() || y < 0 || y > polja[0].size())
		throw std::out_of_range ("Izlazak van igrace table");
	if(polja[novi_x][novi_y] == Polje::BlokiranoPrazno || polja[novi_x][novi_y] == Polje::BlokiranoMina || polja[novi_x][novi_x] == Polje::BlokiranoPosjeceno)
		throw std::logic_error ("Blokirano polje");
	if(polja[novi_x][novi_y] == Polje::Mina) return Status::KrajPoraz;

	x = novi_x;
	y = novi_y;

	bool prazno = false;
	for(int i = 0; i < polja.size(); i++) {
		for(int j = 0; j < polja[0].size(); j++)
			if(polja[i][j] == Polje::Prazno) prazno = true;
	}
	if(prazno == false) return Status::KrajPobjeda;

	return Status::NijeKraj;
}

void PrijaviGresku(KodoviGresaka greska)
{
	if(greska == KodoviGresaka::PogresnaKomanda)
		cout << "Nerazumljiva komanda!";
	if(greska == KodoviGresaka::NedostajeParmetar)
		cout << "Komanda trazi parametar koji nije naveden!";
	if(greska == KodoviGresaka::NeispravanParametar)
		cout << "Parametar komande nije ispravan!";
	if(greska == KodoviGresaka::SuvisanParametar)
		cout << "Zadan je suvisan parametar nakon komande!";
}

/*bool UnosKomande (Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &kod_greska)
{
	string s;
	getline(cin, s);

	for(int i = 0; i < s.length(); i++) {
		if(s[i] == ' ') i++;

		if(s[i] == 'P' && s[i + 1] == '1') {
			komanda = Komande::PomjeriJednoMjesto;
			i += 2;
			while(s[i] == ' ') i++;

			if(s[i] == 'G') {
				if(s[i + 1] == 'L') {
					i += 2;
					while(s[i] == ' ') i++;
					if(s[i] != ' ' || s[i] != s.length())
						kod_greska = KodoviGresaka::SuvisanParametar;
					else smjer = Smjerovi::GoreLijevo;
				} else if(s[i +1] == 'D') {
					i += 2;
					while(s[i] == ' ') i++;
					if(s[i] != ' ' || s[i] != s.length())
						kod_greska = KodoviGresaka::SuvisanParametar;
					else smjer = Smjerovi::GoreDesno;
				} else if(s[i + 1] == ' ' || s[i + 1] == s.length()) {
					i++;
					while(s[i] == ' ') i++;
					if(s[i] != ' ' || s[i] != s.length())
						kod_greska = KodoviGresaka::SuvisanParametar;
					else smjer = Smjerovi::Gore;
				}
			}

			if(s[i] == 'L') {
				i++;
				while(s[i] == ' ') i++;
				if(s[i] != ' ' || s[i] != s.length())
					kod_greska = KodoviGresaka::SuvisanParametar;
				else smjer = Smjerovi::Lijevo;
			}

			if(s[i] == 'D') {
				if(s[i + 1] == 'o') {
					i += 2;

					if(s[i + 1] == 'D') {
						while(s[i] == ' ') i++;
						if(s[i] != ' ' || s[i] != s.length())
							kod_greska = KodoviGresaka::SuvisanParametar;
						else smjer = Smjerovi::DoljeDesno;
					}

					else if(s[i + 1] == 'L') {
						while(s[i] == ' ') i++;
						if(s[i] != ' ' || s[i] != s.length())
							kod_greska = KodoviGresaka::SuvisanParametar;
						else smjer = Smjerovi::DoljeLijevo;
					} else {
						while(s[i] == ' ') i++;
						if(s[i] != ' ' || s[i] != s.length())
							kod_greska = KodoviGresaka::SuvisanParametar;
						else smjer = Smjerovi::Dolje;
					}
				} else {
					while(s[i] == ' ') i++;
					if(s[i] != ' ' || s[i] != s.length())
						kod_greska = KodoviGresaka::SuvisanParametar;
					else smjer = Smjerovi::Desno;

				}
			}
			
		//	else if(s[i + 1] == '>')
		}
		
	}
}
*/
int main ()
{
	try {
		int n;
		cout << "Unesite broj polja: ";
		cin >> n;

	} catch(std::domain_error e) {
		cout << e.what();
	} catch(std::out_of_range e){
		cout << e.what();
	} catch(std::logic_error e){
		cout << e.what();
	}
	return 0;
}
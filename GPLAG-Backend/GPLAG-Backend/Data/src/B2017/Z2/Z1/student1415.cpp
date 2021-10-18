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
#include <vector>
#include <stdexcept>
#include <string>

enum class Polje
{
    Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};

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

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru (int n, const std::vector<std::vector<int>> &mine)
{

	if(n <= 0) throw std::domain_error("Ilegalna veličina");											// Ispravnost matrica?

	for(int i = 0; i < mine.size(); i++) {
		if(mine.at(i).size() != 2) throw std::domain_error("Ilegalan format zadavanja mina");

		if (mine.at(i).at(0) >= n || mine.at(i).at(1) >= n || mine.at(i).at(0) < 0 || mine.at(i).at(1) < 0)
			throw std::domain_error("Ilegalne pozicije mina");
	}

	Tabla Ploca (n, std::vector<Polje> (n, Polje::Prazno));

	for(int i = 0; i < Ploca.size(); i++) {
		for(int j = 0; j < Ploca.at(i).size(); j++) {

			for(int k = 0; k < mine.size(); k++) {
				if(i == mine.at(k).at(0) && j == mine.at(k).at(1))
					Ploca.at(i).at(j) = Polje::Mina;
			}
		}
	}

	return Ploca;
}

std::vector<std::vector<int>> PrikaziOkolinu (const Tabla &polja, int x, int y)
{

	if(x >= polja.size() || y >= polja.at(0).size() || x < 0 || y < 0) {
		std::string prvi(std::to_string(x)), drugi(std::to_string(y));
		throw std::domain_error("Polje ("  + prvi + ", " + drugi + ") ne postoji");
	}

	std::vector<std::vector<int>> Okolina (3, std::vector<int> (3));

	for (int i = x - 1; i < x + 2 ; i++) {
		if(i < 0 || i >= polja.size())
			continue;

		for(int j = y - 1; j < y + 2; j++) {

			if(j < 0 || j >= polja.at(i).size())
				continue;


			int BrojMina(0);

			for(int k = i - 1; k < i + 2; k++) {
				if(k < 0 || k >= polja.size())

					continue;

				int l = j -1;
				for(; l < j + 2; l++) {

					if(l < 0 || l >= polja.at(i).size())
						continue;

					if(i == k && j == l)
						continue;


					if(polja.at(k).at(l) == Polje::Mina) BrojMina++;
				}

			}
			Okolina.at(i).at(j) = BrojMina;

		}
	}


	return Okolina;
}

void BlokirajPolje (Tabla &polja, int x, int y)
{
	if(x >= polja.size() || y >= polja.size() || x < 0 || y < 0) {

		std::string prvi (std::to_string(x)), drugi (std::to_string(y));
		throw std::domain_error("Polje (" + prvi + ", " + drugi + ") ne postoji");
	}

	if(polja.at(x).at(y) == Polje::Prazno) polja.at(x).at(y) = Polje::BlokiranoPrazno;
	if(polja.at(x).at(y) == Polje::Posjeceno) polja.at(x).at(y) = Polje::BlokiranoPosjeceno;
	if(polja.at(x).at(y) == Polje::Mina) polja.at(x).at(y) = Polje::BlokiranoMina;
}

void DeblokirajPolje(Tabla &polja, int x, int y)
{
	if(x >= polja.size() || y >= polja.size() || x < 0 || y < 0) {
		std::string prvi(std::to_string(x)), drugi(std::to_string(y));
		throw std::domain_error("Polje (" + prvi + ", " + drugi + ") ne postoji");
	}

	if(polja.at(x).at(y) == Polje::BlokiranoPosjeceno) polja.at(x).at(y) = Polje::Posjeceno;
	if(polja.at(x).at(y) == Polje::BlokiranoPrazno) polja.at(x).at(y) = Polje::Prazno;
	if(polja.at(x).at(y) == Polje::BlokiranoMina) polja.at(x).at(y) = Polje::Mina;

}

Status Idi (Tabla &polja, int &x, int &y, Smjerovi smjer)
{
	polja.at(x).at(y) = Polje::Posjeceno;

	if(smjer >= Smjerovi::GoreLijevo && smjer <= Smjerovi::GoreDesno) x--;
	if(smjer >= Smjerovi::DoljeDesno && smjer <= Smjerovi::DoljeLijevo) x++;
	if(smjer >= Smjerovi::GoreDesno && smjer <= Smjerovi::DoljeDesno) y++;
	if((smjer >= Smjerovi::DoljeLijevo && smjer <= Smjerovi::Lijevo) || smjer == Smjerovi::GoreLijevo) y--;

	if(x < 0 || x >= polja.size() || y < 0 || y >= polja.size())
		throw std::out_of_range ("Izlazak van igrace table");

	if(polja.at(x).at(y) == Polje::BlokiranoPrazno || polja.at(x).at(y) == Polje::BlokiranoMina
	        || polja.at(x).at(y) == Polje::BlokiranoPosjeceno) throw std::logic_error("Blokirano polje");

	if(polja.at(x).at(y) == Polje::Mina) {
		for(int i = 0; i < polja.size(); i++) {
			for(int j = 0; j < polja.size(); j++)
				polja.at(i).at(j) = Polje::Prazno;
		}
		return Status::KrajPoraz;
	}

	for(int i = 0; i < polja.size(); i++)
		for(int j = 0; j < polja.size(); j++)
			if(polja.at(i).at(j) == Polje::Prazno) return Status::NijeKraj;

	return Status::KrajPobjeda;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y)
{
	if (novi_x < 0 || novi_x >= polja.size() || novi_y < 0 || novi_y >= polja.size())
		throw std::out_of_range("Izlazak van igrace table");

	x = novi_x;
	y = novi_y;
	if(polja.at(x).at(y) >= Polje::BlokiranoPrazno && polja.at(x).at(y) <= Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");

	if(polja.at(x).at(y) == Polje::Mina) {
		for(int i = 0; i < polja.size(); i++) {
			for(int j = 0; j < polja.size(); j++)
				polja.at(i).at(j) = Polje::Prazno;
		}
		return Status::KrajPoraz;
	}

	for(int i = 0; i < polja.size(); i++)
		for(int j = 0; j < polja.size(); j++)
			if(polja.at(i).at(j) == Polje::Prazno) return Status::NijeKraj;

	return Status::KrajPobjeda;
}

void PrijaviGresku (KodoviGresaka vrsta)
{
	if(vrsta == KodoviGresaka::PogresnaKomanda) std::cout << "Nerazumljiva komanda!" << std::endl;
	else if (vrsta == KodoviGresaka::NedostajeParametar) std::cout << "Komanda trazi parametar koji nije naveden!"<<std::endl;
	else if (vrsta == KodoviGresaka::NeispravanParametar) std::cout << "Parametar komande nije ispravan!"<< std::endl;
	else std::cout << "Zadan je suvisan parametar nakon komande!"<< std::endl;
}

void ZavrsiIgru(Tabla &polja)
{
	for(int i = 0; i < polja.size(); i++) {
		for(int j = 0; j < polja.at(i).size(); j++) {
			polja.at(i).at(j) = Polje::Prazno;
		}
	}
	throw std::runtime_error("Igra zavrsena");
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska)
{
	std::cout<< "Unesite komandu: ";
	std::string unos;
	std::getline(std::cin, unos);

	std::vector<std::string> DozvoljeneKomande {{"P1"}, {"P>"}, {"B"}, {"D"}, {"PO"}, {"Z"}, {"K"}};
	std::vector<std::string> DozvoljeniSmjerovi {{"GL"}, {"G"}, {"GD"}, {"D"}, {"DoD"}, {"Do"}, {"DoL"}, {"L"}};

	for(int i = 0; i < unos.size(); i++) {

		if(unos.at(i) == ' ') continue;

		for(int j = 0; j < DozvoljeneKomande.size(); j++) {

			if(unos.at(i) == DozvoljeneKomande.at(j).at(0)) {

				for(int k = 0; i + k < unos.size(); k++) {
					if(k >= DozvoljeneKomande.at(j).size()) break;
					if(unos.at(k + i) != DozvoljeneKomande.at(j).at(k)) break;

					if(DozvoljeneKomande.at(j).size() - 1 == k && unos.at(k + i) == DozvoljeneKomande.at(j).at(k) &&
					        (i == k || unos.at(i - k - 1 == ' ')) && (i + k + 1 == unos.size() || unos.at(i + k + 1) == ' ')) {

						if(j > 3) {

							if(i + k + 1 >= unos.size()) {
								komanda = Komande(j);
								return true;
							}

							for(int p = i + k + 1; p < unos.size(); p++)
								if(unos.at(p) != ' ') {
									greska = KodoviGresaka::SuvisanParametar;
									return false;
								}
							komanda = Komande(j);
							return true;

						}

						else if(j == 0) {

							if((i + k + 1) >= unos.size()) {
								greska = KodoviGresaka::NedostajeParametar;
								return false;
							}

							for(int s = i + k + 1; s < unos.size(); s++) {
								if(unos.at(s) == ' ') continue;

								for(int r = 0; r < DozvoljeniSmjerovi.size(); r++) {

									if(unos.at(s) == DozvoljeniSmjerovi.at(r).at(0)) {

										for(int a = 0; a < unos.size(); a++) {
											if(DozvoljeniSmjerovi.at(r).size() <= a) break;
											if(unos.at(s + a) != DozvoljeniSmjerovi.at(r).at(a)) break;

											if(DozvoljeniSmjerovi.at(r).size() - 1 == a && DozvoljeniSmjerovi.at(r).at(a) == unos.at(s + a) &&
											        (unos.at(s - 1) == ' ') && (s + a == unos.size() - 1 || unos.at(s + a + 1) == ' ')) {
												if(s + a + 1 == unos.size()) {
													smjer = Smjerovi(r);
													komanda = Komande(j);
													return true;
												}

												for(int b = s + a + 1; b < unos.size(); b++)
													if(unos.at(b) != ' ') {
														greska = KodoviGresaka::NeispravanParametar;
														return false;
													}

												smjer = Smjerovi(r);
												komanda = Komande(j);
												return true;
											}
										}
									}

								}
								if(unos.at(s)!= ' ') break;
							}

							greska = KodoviGresaka::NeispravanParametar;
							return false;
						}

						else {
							if(i + k + 1 > unos.size()) {
								greska = KodoviGresaka::NedostajeParametar;
								return false;
							}

							std::string temp1, temp2;

							for(int c = i + k + 1; c < unos.size(); c++) {
								if(unos.at(c) == ' ') continue;

								if(unos.at(c) < '0' || unos.at(c) > '9') {
									greska = KodoviGresaka::NeispravanParametar;
									return false;
								}

								if(temp1.size() == 0) {
									while(c < unos.size() && unos.at(c) >= '0' && unos.at(c) <= '9') {
										temp1.push_back(unos.at(c));
										c++;
									}
								}
								if(unos.at(c) != ' ') {
									greska= KodoviGresaka::NeispravanParametar;
									return false;
								}
								while(unos.at(c) == ' ') {
									if(unos.at(c) != ' ' && (unos.at(c) < '0' || unos.at(c) > '9')) {
										greska = KodoviGresaka::NeispravanParametar;
										return false;
									}
									c++;
								}

								if(c >= unos.size() && temp2.size() == 0) {
									greska = KodoviGresaka::NeispravanParametar;
									return false;
								}

								if(unos.at(c) == ' ') continue;

								if(temp2.size() == 0) {

									while(c < unos.size() && unos.at(c) >= '0' && unos.at(c) <= '9') {
										temp2.push_back(unos.at(c));
										c++;
									}
								}


								if(temp1.size() != 0 && temp2.size() != 0) {
									if (c == unos.size()) {
										x = std::stoi(temp1);
										y = std::stoi(temp2);
										komanda = Komande(j);
										return true;
									}

									for(int e = c; e < unos.size(); e++) {
										if(unos.at(e) == ' ') continue;
										if(unos.at(e) != ' ') {
											greska = KodoviGresaka::NeispravanParametar;
											return false;
										}
									}
									x = std::stoi(temp1);
									y = std::stoi(temp2);
									komanda = Komande(j);
									return true;

								}

							}

						}

					}

				}

			}
		}

		greska = KodoviGresaka::PogresnaKomanda;
		return false;

	}
	return false;
}

bool TancnostUnosa (std::string trenutni, int &x, int &y)
{
	for(int i = 0; i < trenutni.length(); i++) {
		if(trenutni.at(i) == ' ') continue;

		if(trenutni.at(i) == '(') {

			for(int j = i + 1; j < trenutni.length(); j++) {

				if(trenutni.at(j) == ' ') continue;
				if(trenutni.at(j) < '0' || trenutni.at(j) > '9') return false;

				std::string temp1, temp2;
				while(j < trenutni.length() &&  trenutni.at(j) >= '0' && trenutni.at(j) <= '9') {
					temp1.push_back(trenutni.at(j));
					j++;
				}

				if(j >= trenutni.size()) return false;
				while(j < trenutni.length() && trenutni.at(j) == ' ')
					j++;

				if(j >= trenutni.length()) return false;
				if (trenutni.at(j) != ',') return false;
				j++;
				if(j >= trenutni.length()) return false;

				while(j < trenutni.length() && trenutni.at(j) == ' ')j++;
				if(j >= trenutni.length()) return false;

				if(trenutni.at(j) <'0' || trenutni.at(j) > '9') return false;

				while(j < trenutni.length() && trenutni.at(j) >= '0' && trenutni.at(j) <= '9') {
					temp2.push_back(trenutni.at(j));
					j++;
				}
				if(j >= trenutni.length()) return false;
				while( j < trenutni.length() && trenutni.at(j) == ' ' ) j++;

				if(j >= trenutni.length()) return false;
				if(trenutni.at(j) != ')') return false;
				j++;
				if(j == trenutni.length()) {

					x = std::stoi(temp1);
					y = std::stoi(temp2);
					return true;
				}

				while(j < trenutni.length()) {
					if(trenutni.at(j) != ' ') return false;
					j++;
				}
				x = std::stoi(temp1);
				y = std::stoi(temp2);

				return true;

			}
		}
		return false;
	}

	return false;
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0 )
{

	try {

		if(komanda == Komande(6)) {
			int n;
			for(;;) {
				std::cout << "Unesite broj polja: ";
				std::cin >> n;
				if(std::cin && std::cin.peek() == '\n') break;
				std::cout << "Greska, unesite ponovo!" << std::endl;
				std::cin.clear();
				std::cin.ignore(10000, '\n');
			}

			std::cout << "Unesite pozicije mina: ";

			std::string privremeni;
			std::getline(std::cin, privremeni);
			std::vector<std::vector<int>> Mine;

			for(;;) {

				std::getline(std::cin, privremeni);
				if(privremeni == ".") break;
				int mina_x , mina_y ;

				if(TancnostUnosa(privremeni, mina_x, mina_y)) {

					if(mina_x >= n || mina_y >= n || (mina_x == 0 && mina_y == 0) ) {
						std::cout << "Greska, unesite ponovo!" << std::endl;
						continue;
					}

					std::vector<int> TrenutnaPozicija {{mina_x}, {mina_y}};
					Mine.push_back(TrenutnaPozicija);
					continue;

				}


				std::cout << "Greska, unesite ponovo!"<< std::endl;
			}
			polja = (KreirajIgru(n,Mine));
		}


		Status status;

		if(komanda == Komande(0)) {

			status = (Idi(polja, x, y, p_smjer));
			std::cout << "Tekuca pozicija igraca je (" << x << "," << y <<")" << std::endl;

			if(status == Status::KrajPoraz) {
				std::cout<< "Nagazili ste na minu"<< std::endl;
				ZavrsiIgru(polja);
			}
			if(status == Status::KrajPobjeda) {
				std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
				ZavrsiIgru(polja);
			}

		} else if (komanda == Komande(1)) {

			status = (Idi(polja, x, y, p_x, p_y));

			if(status == Status::KrajPoraz) {
				std::cout<< "Nagazili ste na minu"<< std::endl;
				ZavrsiIgru(polja);
			}
			if(status == Status::KrajPobjeda) {
				std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
				ZavrsiIgru(polja);
			}
			std::cout << "Tekuca pozicija igraca je (" << x << "," << y <<")" << std::endl;
		}

		else if(komanda == Komande(2)) BlokirajPolje(polja, p_x, p_y);

		else if(komanda == Komande(3)) DeblokirajPolje(polja, p_x, p_y);

		else if(komanda == Komande(4)) {

			auto matrica_mina (PrikaziOkolinu(polja, x, y));
			for(int i = 0; i < matrica_mina.size(); i++) {
				for (int j = 0; j < matrica_mina.at(i).size(); j++) {
					std::cout << matrica_mina.at(i).at(j) << " ";
				}
				std::cout << std::endl;
			}

		} else if(komanda == Komande(5)) ZavrsiIgru(polja);


	} catch(std::domain_error e) {
		std::cout << e.what() << std::endl;
		throw;
	} catch (std::runtime_error e) {
		if(komanda == Komande(5)) throw;
		std::cout << e.what() << std::endl;
		throw;
	} catch(std::logic_error e) {

		std::cout << e.what() << std::endl;
	}
}


int main ()
{
	Tabla igraca_ploca;
	Komande komanda;
	int x(0), y(0), p_x, p_y;
	Smjerovi smjer;
	KodoviGresaka greska;
	int brojac (0);

	try {
		for(;;) {
			if(UnosKomande(komanda, smjer, p_x, p_y, greska)) {
				if(brojac == 0 && komanda != Komande::KreirajIgru) {
					std::cout << "Greska, unesite ponovo!" << std::endl;
					continue;
				}

				IzvrsiKomandu(komanda, igraca_ploca, x, y, smjer, p_x, p_y);

			} else {
				PrijaviGresku(greska);
			}
			brojac++;
		}
	} catch(...) {
		std::cout << "Dovidjenja!";
		return 0;
	}

	return 0;
}

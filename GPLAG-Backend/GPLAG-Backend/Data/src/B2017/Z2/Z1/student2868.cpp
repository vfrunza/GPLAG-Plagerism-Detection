#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <deque>
#include <cmath>
#include <complex>

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

bool PoljeNijeValidno(int x, int y, int vel)
{
	return (x<0 || y<0 || x>=vel || y>=vel);
}

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine)
{
	if (n<=0)
		throw std::domain_error("Ilegalan velicina");
	Tabla rez(n, std::vector<Polje>(n, Polje::Prazno));
	for (int i = 0; i < mine.size(); i++) {
		if (mine.at(i).size()!=2)
			throw std::domain_error("Ilegalan format zadavanja mina");
		if ((mine.at(i).at(0)<0) || (mine.at(i).at(1)<0) || (mine.at(i).at(0))>=n || (mine.at(i).at(1)>=n))
			throw std::domain_error("Ilegalne pozicije mina");
		rez.at(mine.at(i).at(0)).at(mine.at(i).at(1))=Polje::Mina;
	}
	return rez;
}

int OkolnaSumaMina(const Tabla &polja, int x, int y)
{
	int suma(0);
	for (int i = x-1; i <= x+1; i++) {
		for (int j = y-1; j <= y+1; j++) {
			if (PoljeNijeValidno(i,j,polja.size()) || (i==x && j==y))
				continue;
			if (polja.at(i).at(j)==Polje::Mina)
				suma++;
		}
	}
	return suma;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y)
{
	std::string greska("Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji");
	if (PoljeNijeValidno(x,y,polja.size()))
		throw std::domain_error(greska);
	std::vector<std::vector<int>> rez(3, std::vector<int>(3));
	int i(0),j(0);
	for (int k = x-1; k <= x+1; k++) {
		for (int g = y-1; g <= y+1; g++) {
			rez.at(i).at(j++)=OkolnaSumaMina(polja, k, g);
			if (j==3) {
				i++;
				if (i==3)
					return rez;
				j=0;
			}
		}
	}

	return rez;
}

void BlokirajPolje(Tabla &polja, int x, int y)
{
	std::string greska("Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji");
	if (PoljeNijeValidno(x,y,polja.size()))
		throw std::domain_error(greska);
	if (polja.at(x).at(y)==Polje::Mina)
		polja.at(x).at(y)=Polje::BlokiranoMina;
	else if (polja.at(x).at(y)==Polje::Posjeceno)
		polja.at(x).at(y)=Polje::BlokiranoPosjeceno;
	else if (polja.at(x).at(y)==Polje::Prazno)
		polja.at(x).at(y)=Polje::BlokiranoPrazno;
}

void DeblokirajPolje(Tabla &polja, int x, int y)
{
	std::string greska("Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji");
	if (PoljeNijeValidno(x,y,polja.size()))
		throw std::domain_error(greska);
	if (polja.at(x).at(y)==Polje::BlokiranoMina)
		polja.at(x).at(y)=Polje::Mina;
	else if (polja.at(x).at(y)==Polje::BlokiranoPosjeceno)
		polja.at(x).at(y)=Polje::Posjeceno;
	else if (polja.at(x).at(y)==Polje::BlokiranoPrazno)
		polja.at(x).at(y)=Polje::Prazno;
}

bool JelKraj(const Tabla &polja, const int &x, const int &y)
{
	for (int i = 0; i < polja.size(); i++) {
		for (int j = 0; j < polja.size(); j++) {
			if (i==x && j==y)
				continue;
			if (polja.at(i).at(j)==Polje::Prazno)
				return false;
		}
	}
	return true;
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer)
{
	int px(x), py(y);
	if (smjer==Smjerovi::GoreLijevo) {
		px--;
		py--;
	} else if (smjer==Smjerovi::Gore) {
		px--;
	} else if (smjer==Smjerovi::GoreDesno) {
		py++;
		px--;
	} else if (smjer==Smjerovi::Desno) {
		py++;
	} else if (smjer==Smjerovi::DoljeDesno) {
		px++;
		py++;
	} else if (smjer==Smjerovi::Dolje) {
		px++;
	} else if (smjer==Smjerovi::DoljeLijevo) {
		py--;
		px++;
	} else if (smjer==Smjerovi::Lijevo) {
		py--;
	}
	if (PoljeNijeValidno(px,py,polja.size()))
		throw std::out_of_range("Izlazak van igrace table");
	if (polja.at(px).at(py)==Polje::BlokiranoPosjeceno || polja.at(px).at(py)==Polje::BlokiranoPrazno || polja.at(px).at(py)==Polje::BlokiranoMina)
		throw std::logic_error("Blokirano polje");
	polja.at(x).at(y)=Polje::Posjeceno;
	x=px;
	y=py;
	if (polja.at(x).at(y)==Polje::Mina)
		return Status::KrajPoraz;
	if (JelKraj(polja,x,y))
		return Status::KrajPobjeda;
	return Status::NijeKraj;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y)
{
	if (PoljeNijeValidno(novi_x,novi_y,polja.size()))
		throw std::out_of_range("Izlazak van igrace table");
	if (polja.at(novi_x).at(novi_y)==Polje::BlokiranoPosjeceno || polja.at(novi_x).at(novi_y)==Polje::BlokiranoPrazno || polja.at(novi_x).at(novi_y)==Polje::BlokiranoMina)
		throw std::logic_error("Blokirano polje");
	polja.at(x).at(y)=Polje::Posjeceno;
	x=novi_x;
	y=novi_y;
	if (polja.at(x).at(y)==Polje::Mina)
		return Status::KrajPoraz;
	if (JelKraj(polja,x,y))
		return Status::KrajPobjeda;
	return Status::NijeKraj;
}

void PrijaviGresku(KodoviGresaka greska)
{
	if (greska==KodoviGresaka::PogresnaKomanda)
		std::cout << "Nerazumljiva komanda!" << std::endl;
	else if (greska==KodoviGresaka::NedostajeParametar)
		std::cout << "Komanda trazi parametar koji nije naveden!" << std::endl;
	else if (greska==KodoviGresaka::NeispravanParametar)
		std::cout << "Parametar komande nije ispravan!" << std::endl;
	else if (greska==KodoviGresaka::SuvisanParametar)
		std::cout << "Zadan je suvisan parametar nakon komande!" << std::endl;
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska)
{
	std::string unos;
	std::getline(std::cin, unos);
	bool pocetak(true), kraj(false);
	for (int i = 0; i < unos.length(); i++) {
		if ((pocetak && unos.at(i)==' ')||(kraj && unos.at(i)==' '))
			continue;
		pocetak=false;
		if (unos.at(i)=='P' && i+1 < unos.length() && unos.at(i+1)=='1') {
			for (int j = i+2; j < unos.length(); j++) {
				if (unos.at(j)==' ')
					continue;
				if (unos.at(j)=='G' && j+1<unos.length() && unos.at(j+1)=='L') {
					for (int k = j+2; k < unos.length(); k++) {
						if (unos.at(k)!=' ') {
							greska=KodoviGresaka::SuvisanParametar;
							return false;
						}
					}
					komanda=Komande::PomjeriJednoMjesto;
					smjer=Smjerovi::GoreLijevo;
					return true;
				} else if (unos.at(j)=='G' && j+1<unos.length() && unos.at(j+1)=='D') {
					for (int k = j+2; k < unos.length(); k++) {
						if (unos.at(k)!=' ') {
							greska=KodoviGresaka::SuvisanParametar;
							return false;
						}
					}
					komanda=Komande::PomjeriJednoMjesto;
					smjer=Smjerovi::GoreDesno;
					return true;
				} else if (unos.at(j)=='G') {
					for (int k = j+1; k < unos.length(); k++) {
						if (unos.at(k)!=' ') {
							greska=KodoviGresaka::SuvisanParametar;
							return false;
						}
					}
					komanda=Komande::PomjeriJednoMjesto;
					smjer=Smjerovi::Gore;
					return true;
				} else if (unos.at(j)=='D' && j+1<unos.length() && unos.at(j+1)=='o' && j+2<unos.length() && unos.at(j+2)=='D') {
					for (int k = j+3; k < unos.length(); k++) {
						if (unos.at(k)!=' ') {
							greska=KodoviGresaka::SuvisanParametar;
							return false;
						}
					}
					komanda=Komande::PomjeriJednoMjesto;
					smjer=Smjerovi::DoljeDesno;
					return true;
				} else if (unos.at(j)=='D' && j+1<unos.length() && unos.at(j+1)=='o' && j+2<unos.length() && unos.at(j+2)=='L') {
					for (int k = j+3; k < unos.length(); k++) {
						if (unos.at(k)!=' ') {
							greska=KodoviGresaka::SuvisanParametar;
							return false;
						}
					}
					komanda=Komande::PomjeriJednoMjesto;
					smjer=Smjerovi::DoljeLijevo;
					return true;
				} else if (unos.at(j)=='D' && j+1<unos.length() && unos.at(j+1)=='o') {
					for (int k = j+2; k < unos.length(); k++) {
						if (unos.at(k)!=' ') {
							greska=KodoviGresaka::SuvisanParametar;
							return false;
						}
					}
					komanda=Komande::PomjeriJednoMjesto;
					smjer=Smjerovi::Dolje;
					return true;
				} else if (unos.at(j)=='D') {
					for (int k = j+1; k < unos.length(); k++) {
						if (unos.at(k)!=' ') {
							greska=KodoviGresaka::SuvisanParametar;
							return false;
						}
					}
					komanda=Komande::PomjeriJednoMjesto;
					smjer=Smjerovi::Desno;
					return true;
				} else if (unos.at(j)=='L') {
					for (int k = j+1; k < unos.length(); k++) {
						if (unos.at(k)!=' ') {
							greska=KodoviGresaka::SuvisanParametar;
							return false;
						}
					}
					komanda=Komande::PomjeriJednoMjesto;
					smjer=Smjerovi::Lijevo;
					return true;
				} else {
					greska=KodoviGresaka::NeispravanParametar;
					return false;
				}
			}
			greska=KodoviGresaka::NedostajeParametar;
			return false;
		} else if (unos.at(i)=='P' && i+1 < unos.length() && unos.at(i+1)=='O') {
			for (int k = i+2; k < unos.length(); k++) {
				if (unos.at(k)!=' ') {
					greska=KodoviGresaka::SuvisanParametar;
					return false;
				}
			}
			komanda=Komande::PrikaziOkolinu;
			return true;
		} else if ((unos.at(i)=='P' && i+1 < unos.length() && unos.at(i+1)=='>')||(unos.at(i)=='B')||(unos.at(i)=='D')) {
			int k(i+1);
			if (unos.at(i)=='P' && i+1 < unos.length() && unos.at(i+1)=='>')
				k=i+2;
			for (; k < unos.length(); k++) {
				if (unos.at(k)!=' ' && !(unos.at(k)>='0' && unos.at(k)<='9')) {
					greska=KodoviGresaka::NeispravanParametar;
					return false;
				}
			}
			if ((unos.at(i)=='P' && i+1 < unos.length() && unos.at(i+1)=='>')&&(k==i+2)) {
				greska=KodoviGresaka::NedostajeParametar;
				return false;
			} else if (k==i+1) {
				greska=KodoviGresaka::NedostajeParametar;
				return false;
			}
			k=i+1;
			if (unos.at(i)=='P' && i+1 < unos.length() && unos.at(i+1)=='>')
				k=i+2;
			bool drugi_put(false);
			int xbroj(0), ybroj(0);
			for (; k < unos.length(); k++) {
				if (unos.at(k)>='0' && unos.at(k)<='9' && !(unos.at(k-1)>='0' && unos.at(k-1)<='9')) {
					if (!drugi_put) {
						std::deque<int> pomocni;
						int j(k);
						for (; j < unos.length(); j++) {
							if (unos.at(j)>='0' && unos.at(j)<='9')
								pomocni.push_front(unos.at(j)-'0');
							else
								break;
						}
						bool okey(false);
						for (; j < unos.length(); j++) {
							if (unos.at(j)==' ')
								continue;
							if (unos.at(j)>='0' && unos.at(j)<='9') {
								okey=true;
								break;
							}
						}
						if (!okey) {
							greska=KodoviGresaka::NeispravanParametar;
							return false;
						}

						for (j = 0; j < pomocni.size(); j++)
							xbroj+=pomocni.at(j)*pow(10,j);
						drugi_put=true;
					} else {
						std::deque<int> pomocni;
						int j(k);
						for (; j < unos.length(); j++) {
							if (unos.at(j)>='0' && unos.at(j)<='9')
								pomocni.push_front(unos.at(j)-'0');
							else
								break;
						}
						bool okey(true);
						for (; j < unos.length(); j++) {
							if (unos.at(j)==' ')
								continue;
							okey=false;
							break;
						}
						if (!okey) {
							greska=KodoviGresaka::SuvisanParametar;
							return false;
						}
						for (j = 0; j < pomocni.size(); j++)
							ybroj+=pomocni.at(j)*pow(10,j);
					}
				}
			}
			x=xbroj;
			y=ybroj;
			if (unos.at(i)=='P' && i+1 < unos.length() && unos.at(i+1)=='>')
				komanda=Komande::PomjeriDalje;
			else if(unos.at(i)=='B')
				komanda=Komande::Blokiraj;
			else if(unos.at(i)=='D')
				komanda=Komande::Deblokiraj;
			return true;
		} else if (unos.at(i)=='Z') {
			for (int j = i+1; j < unos.length(); j++) {
				if (unos.at(j)!=' ') {
					greska=KodoviGresaka::SuvisanParametar;
					return false;
				}
			}
			komanda=Komande::ZavrsiIgru;
			return true;
		} else if (unos.at(i)=='K') {
			for (int j = i+1; j < unos.length(); j++) {
				if (unos.at(j)!=' ') {
					greska=KodoviGresaka::SuvisanParametar;
					return false;
				}
			}
			komanda=Komande::KreirajIgru;
			return true;
		} else {
			greska=KodoviGresaka::PogresnaKomanda;
			return false;
		}
	}
	return true;
}

void Zavrsi(Tabla &polja)
{
	for (int i = 0; i < polja.size(); i++) {
		for (int j = 0; j < polja.at(i).size(); j++)
			polja.at(i).at(j)=Polje::Prazno;
	}
	throw std::runtime_error("Igra zavrsena");
}

void IzvrsiKomandu (Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0)
{
	if (komanda==Komande::PomjeriJednoMjesto) {
		Status s;
		try {
			s=Idi(polja, x, y, p_smjer);
		} catch (const std::exception &error) {
			std::cout << error.what() << std::endl;
			return;
		}
		if (s==Status::KrajPobjeda) {
			std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
			Zavrsi(polja);
		} else if (s==Status::KrajPoraz) {
			std::cout << "Nagazili ste minu" << std::endl;
			Zavrsi(polja);
		}
		std::cout << "Tekuca pozicija igraca je " << "("<< x << "," << y << ")" << std::endl;
	} else if (komanda==Komande::PomjeriDalje) {
		Status s;
		try {
			s=Idi(polja, x, y, p_x, p_y);
		} catch (const std::exception &error) {
			std::cout << error.what() << std::endl;
			return;
		}
		if (s==Status::KrajPobjeda) {
			std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
			Zavrsi(polja);
		} else if (s==Status::KrajPoraz) {
			std::cout << "Nagazili ste minu" << std::endl;
			Zavrsi(polja);
		}
		std::cout << "Tekuca pozicija igraca je " << "("<< x << "," << y << ")" << std::endl;
	} else if (komanda==Komande::Blokiraj) {
		try {
			BlokirajPolje(polja, p_x, p_y);
		} catch (const std::exception &error) {
			std::cout << error.what() << std::endl;
			return;
		}
	} else if (komanda==Komande::Deblokiraj) {
		try {
			DeblokirajPolje(polja, p_x, p_y);
		} catch (const std::exception &error) {
			std::cout << error.what() << std::endl;
			return;
		}
	} else if (komanda==Komande::PrikaziOkolinu) {
		std::vector<std::vector<int>> matrica;
		try {
			matrica=PrikaziOkolinu(polja, x, y);
		} catch (const std::exception &error) {
			std::cout << error.what() << std::endl;
			return;
		}
		for (int i = 0; i < matrica.size(); i++) {
			for (int j = 0; j < matrica.at(i).size(); j++)
				std::cout << matrica.at(i).at(j) << " ";
			std::cout << std::endl;
		}
	} else if (komanda==Komande::ZavrsiIgru) {
		Zavrsi(polja);
	} else if (komanda==Komande::KreirajIgru) {
		int n;
		bool ponovi;
		do {
			ponovi=false;
			std::cout << "Unesite broj polja: ";
			std::cin >> n;
			if (n<=0 || !std::cin || std::cin.peek()!='\n') {
				std::cin.clear();
				std::cin.ignore(10000,'\n');
				std::cout << "Greska, unesite ponovo!" << std::endl;
				ponovi=true;
			}
		} while(ponovi);
		polja.resize(n);
		for (int i = 0; i < polja.size(); i++)
			polja.at(i).resize(n);
		std::vector<std::vector<int>> mine;
		int i(0);
		std::cout << "Unesite pozicije mina: ";
		do {
			std::complex<int> komplunos;
			std::cin >> komplunos;
			std::cin.clear();
			if (std::cin.peek()=='.') {
				std::cin.ignore(10000,'\n');
				break;
			}
			if (!std::cin || (std::cin.peek()!='\n' && std::cin.peek()!='.' && std::cin.peek()!=' ') || PoljeNijeValidno(real(komplunos), imag(komplunos), polja.size())) {
				std::cin.ignore(10000,'\n');
				std::cout << "Greska, unesite ponovo!" << std::endl;
				continue;
			}
			mine.resize(i+1);
			mine.at(i).push_back(real(komplunos));
			mine.at(i).push_back(imag(komplunos));
			i++;
		} while (true);
		x=0;
		y=0;
		polja=KreirajIgru(n, mine);
	}
}


int main ()
{
	Tabla polja;
	Komande kom;
	Smjerovi smj;
	KodoviGresaka gres;
	int x(0), y(0);
	int novi_x(0), novi_y(0);
	do {
		std::cout << "Unesite komandu: ";
		if (UnosKomande(kom, smj, novi_x,novi_y,gres)==false)
			PrijaviGresku(gres);
		else {
			try {
				IzvrsiKomandu(kom, polja, x, y, smj, novi_x, novi_y);
			} catch (...) {
				std::cout << "Dovidjenja!";
				return 0;
			}
		}
	} while(true);

	return 0;
}
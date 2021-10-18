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
#include <sstream>

template <typename T> std::string PretvoriUString(T x) {
 std::ostringstream s; s << x; return s.str();
}

enum class Polje { Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina };
enum class Smjerovi { GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo };
enum class Status { NijeKraj, KrajPoraz, KrajPobjeda };
enum class KodoviGresaka { PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar };
enum class Komande { PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru };

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru (int n, const std::vector<std::vector<int>> &mine) {
	Tabla polja;
	
	if (n<=0) throw std::domain_error("Ilegalna velicina");
	
	for (int i=0; i<mine.size(); i++) {
		if (mine.at(i).size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
		if (mine.at(i).at(0)>=n || mine.at(i).at(0)<0 || mine.at(i).at(1)>=n || mine.at(i).at(1)<0) throw std::domain_error("Ilegalne pozicije mina");
	}
	
	
	polja.resize(n);
	for (int i=0; i<n; i++) polja.at(i).resize(n);
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			polja.at(i).at(j)=Polje::Prazno;
		}
	}
	for (int i=0; i<mine.size(); i++) polja.at(mine.at(i).at(0)).at(mine.at(i).at(1))=Polje::Mina;
	
	return polja;
}

int BrojMina (const Tabla &polja, int x, int y) {
	int brojac(0);
	
	for (int i=0; i<polja.size(); i++) {
		for (int j=0; j<polja.size(); j++) {
			
			if (std::abs(x-i)<=1 && std::abs(y-j)<=1 && polja.at(i).at(j)==Polje::Mina && (x!=i || y!=j)) brojac++;
			
		}
	}
	return brojac;
}

std::vector<std::vector<int>> PrikaziOkolinu (const Tabla &polja, int x, int y) {
	
	if (x<0 || x>=polja.size() || y<0 || y>=polja.size()) throw std::domain_error("Polje (" + PretvoriUString(x) + "," + PretvoriUString(y) + ") ne postoji");
	
	std::vector<std::vector<int>> okolina;
	okolina.resize(3); 
	for (int i=0; i<3; i++) okolina.at(i).resize(3);
	
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			okolina.at(i).at(j)=BrojMina(polja, x-1+i, y-1+j);
		}
	}
	return okolina;
}

void BlokirajPolje (Tabla &polja, int x, int y) {
	if (x<0 || x>=polja.size() || y<0 || y>=polja.size()) throw std::domain_error("Polje (" + PretvoriUString(x) + "," + PretvoriUString(y) + ") ne postoji");
	
	if (polja.at(x).at(y)==Polje::Prazno) polja.at(x).at(y)=Polje::BlokiranoPrazno;
	else if (polja.at(x).at(y)==Polje::Mina) polja.at(x).at(y)=Polje::BlokiranoMina;
	else if (polja.at(x).at(y)==Polje::Posjeceno) polja.at(x).at(y)=Polje::BlokiranoPosjeceno;
	
	return;
}

void DeblokirajPolje (Tabla &polja, int x, int y) {
	if (x<0 || x>=polja.size() || y<0 || y>=polja.size()) throw std::domain_error("Polje (" + PretvoriUString(x) + "," + PretvoriUString(y) + ") ne postoji");
	
	if (polja.at(x).at(y)==Polje::BlokiranoPrazno) polja.at(x).at(y)=Polje::Prazno;
	else if (polja.at(x).at(y)==Polje::BlokiranoMina) polja.at(x).at(y)=Polje::Mina;
	else if (polja.at(x).at(y)==Polje::BlokiranoPosjeceno) polja.at(x).at(y)=Polje::Posjeceno;
	
	return;
	
}

void Ocisti (Tabla &polja) {
	for (int i=0; i<polja.size(); i++) {
		for (int j=0; j<polja.size(); j++) {
			polja.at(i).at(j)=Polje::Prazno;
		}
	}
}

bool SvaPosjecena (Tabla &polja, int x, int y) {
	for (int i=0; i<polja.size(); i++) {
		for (int j=0; j<polja.size(); j++) {
			if (i!=x && j!=y && polja.at(i).at(j)==Polje::Prazno) return false;
		}
	}
	return true;
}

Status Idi (Tabla &polja, int &x, int &y, Smjerovi smjer) {
	
	polja.at(x).at(y)=Polje::Posjeceno;
	int temp_x(x), temp_y(y);
	
	if (smjer==Smjerovi::GoreLijevo) { temp_x--; temp_y--; }
	else if (smjer==Smjerovi::Gore) temp_x--;
	else if (smjer==Smjerovi::GoreDesno) { temp_x--; temp_y++; }
	else if (smjer==Smjerovi::Desno) temp_y++;
	else if (smjer==Smjerovi::DoljeDesno) { temp_x++; temp_y++; }
	else if (smjer==Smjerovi::Dolje) temp_x++;
	else if (smjer==Smjerovi::DoljeLijevo) { temp_x++; temp_y--; }
	else if (smjer==Smjerovi::Lijevo) temp_y--;
	
	if (temp_x<0 || temp_x>=polja.size() || temp_y<0 || temp_y>=polja.size()) throw std::out_of_range("Izlazak van igrace table");
	if (polja.at(temp_x).at(temp_y)==Polje::BlokiranoMina || polja.at(temp_x).at(temp_y)==Polje::BlokiranoPrazno || polja.at(temp_x).at(temp_y)==Polje::BlokiranoPosjeceno) throw std::logic_error("Blokirano polje");
	if (polja.at(temp_x).at(temp_y)==Polje::Mina) {
		Ocisti(polja);
		return Status::KrajPoraz;
	}
	x=temp_x; y=temp_y;
	
	if (SvaPosjecena(polja, x, y)) return Status::KrajPobjeda;
	
	return Status::NijeKraj;
}
Status Idi (Tabla &polja, int &x, int &y, int novi_x, int novi_y) {
	
	polja.at(x).at(y)=Polje::Posjeceno;
	
	if (novi_x<0 || novi_x>=polja.size() || novi_y<0 || novi_y>=polja.size()) throw std::out_of_range("Izlazak van igrace table");
	if (polja.at(novi_x).at(novi_y)==Polje::BlokiranoMina || polja.at(novi_x).at(novi_y)==Polje::BlokiranoPrazno || polja.at(novi_x).at(novi_y)==Polje::BlokiranoPosjeceno) throw std::logic_error("Blokirano polje");
	
	x=novi_x; y=novi_y;
	
	if (polja.at(x).at(y)==Polje::Mina) {
		Ocisti(polja);
		return Status::KrajPoraz;
	}
	
	if (SvaPosjecena(polja, x, y)) return Status::KrajPobjeda;
	
	return Status::NijeKraj;
}

void PrijaviGresku (KodoviGresaka greska) {
	if (greska==KodoviGresaka::PogresnaKomanda) std::cout << "Nerazumljiva komanda!" << std::endl;
	else if (greska==KodoviGresaka::NedostajeParametar) std::cout << "Komanda trazi parametar koji nije naveden!" << std::endl;
	else if (greska==KodoviGresaka::NeispravanParametar) std::cout << "Parametar komande nije ispravan!" << std::endl;
	else if (greska==KodoviGresaka::SuvisanParametar) std::cout << "Zadan je suvisan parametar nakon komande!" << std::endl;
}


bool UnosKomande (Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska) {
	
	std::string s;
	std::getline(std::cin, s);
	
	for (int i=0; i<s.length(); i++) {
		if (s.at(i)==' ') {
			s.erase(s.begin()+i);
			i--;
		}
	}
	if (s.length()==1) {
		if (s.at(0)=='Z') komanda=Komande::ZavrsiIgru;
		else if (s.at(0)=='K') komanda=Komande::KreirajIgru;
		else if (s.at(0)=='B') {
			komanda=Komande::Blokiraj;
			greska=KodoviGresaka::NedostajeParametar;
			return false;
		}
		else if (s.at(0)=='D') {
			komanda=Komande::Deblokiraj;
			greska=KodoviGresaka::NedostajeParametar;
			return false;
		}
		else {
			greska=KodoviGresaka::PogresnaKomanda;
			return false;
		}
	}
	else if (s.length()>=2) {
		if (s.at(0)=='P' && s.at(1)=='1') {
			
			komanda=Komande::PomjeriJednoMjesto;
			
			if (s=="P1G") smjer=Smjerovi::Gore;
			else if (s=="P1GD") smjer=Smjerovi::GoreDesno;
			else if (s=="P1GL") smjer=Smjerovi::GoreLijevo;
			else if (s=="P1L") smjer=Smjerovi::Lijevo;
			else if (s=="P1D") smjer=Smjerovi::Desno;
			else if (s=="P1Do") smjer=Smjerovi::Dolje;
			else if (s=="P1DoD") smjer=Smjerovi::DoljeDesno;
			else if (s=="P1DoL") smjer=Smjerovi::DoljeLijevo;
			else if (s.length()==2) {
				greska=KodoviGresaka::NedostajeParametar;
				return false;
			}
			else if (s.substr(0, 3)=="P1G" || s.substr(0, 3)=="P1D" || s.substr(0, 4)=="P1GD" || s.substr(0, 4)=="P1GL" || s.substr(0, 3)=="P1L" || s.substr(0, 4)=="P1Do" || s.substr(0, 5)=="P1DoD" || s.substr(0,5)=="P1DoL") {
				greska=KodoviGresaka::SuvisanParametar;
				return false;
			}
			else {
				greska=KodoviGresaka::NeispravanParametar;
				return false;
			}
		}
		else if (s.at(0)=='P' && s.at(1)=='>') {
			komanda=Komande::PomjeriDalje;
			
			if (s.length()>2) {
				if (s.at(2)<'0' || s.at(2)>'9') {
					greska=KodoviGresaka::NeispravanParametar;
					return false;
				}
			}
			if (s.length()==2 || s.length()==3) {
				greska=KodoviGresaka::NedostajeParametar;
				return false;
			}
			else if (s.length()>4) {
				greska=KodoviGresaka::SuvisanParametar;
				return false;
			}
			else if (!((s.at(2)>='0' && s.at(2)<='9') && (s.at(3)>='0' && s.at(3)<='9'))) {
				greska=KodoviGresaka::NeispravanParametar;
				return false;
			}
			else {
				x=s.at(2)-'0'; y=s.at(3)-'0';
			}
		}
		else if (s.at(0)=='B') {
			komanda=Komande::Blokiraj;
			
			if (s.length()==2) {
				if (!(s.at(1)>='0' && s.at(1)<='9')) greska=KodoviGresaka::NeispravanParametar;
				else greska=KodoviGresaka::NedostajeParametar;
				return false;
			}
			if (!((s.at(1)>='0' && s.at(1)<='9') && (s.at(2)>='0' && s.at(2)<='9'))) {
				greska=KodoviGresaka::NeispravanParametar;
				return false;
			}
			else if (s.length()>3) {
				greska=KodoviGresaka::SuvisanParametar;
				return false;
			}
			else {
				x=s.at(1)-'0'; y=s.at(2)-'0';
			}
		}
		else if (s.at(0)=='D') {
			komanda=Komande::Deblokiraj;
			
			if (s.length()==2) {
				if (!(s.at(1)>='0' && s.at(1)<='9')) greska=KodoviGresaka::NeispravanParametar;
				else greska=KodoviGresaka::NedostajeParametar;
				return false;
			}
			
			if (!((s.at(1)>='0' && s.at(1)<='9') && (s.at(2)>='0' && s.at(2)<='9'))) {
				greska=KodoviGresaka::NeispravanParametar;
				return false;
			}
			else if (s.length()>3) {
				greska=KodoviGresaka::SuvisanParametar;
				return false;
			}
			else {
				x=s.at(1)-'0'; y=s.at(2)-'0';
			}
		}
		else if (s.at(0)=='P' && s.at(1)=='O') {
			komanda=Komande::PrikaziOkolinu;
			if (s.length()>2) {
				greska=KodoviGresaka::SuvisanParametar;
				return false;
			}
		}
		else if (s.at(0)=='Z') {
			komanda=Komande::ZavrsiIgru;
			greska=KodoviGresaka::SuvisanParametar;
			return false;
		}
		else if (s.at(0)=='K') {
			komanda=Komande::KreirajIgru;
			greska=KodoviGresaka::SuvisanParametar;
			return false;
		}
		else {
			greska=KodoviGresaka::PogresnaKomanda;
			return false;
		}
	}
	return true;
}


void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer=Smjerovi::Gore, int p_x=0, int p_y=0) {
	
	try {
	if (komanda==Komande::PomjeriJednoMjesto) {
		Status status(Idi(polja, x, y, p_smjer));
		std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")" << std::endl;
		if (status==Status::KrajPoraz) {
			std::cout << "Nagazili ste na minu" << std::endl;
			komanda=Komande::ZavrsiIgru;
			Ocisti(polja);
			throw std::runtime_error("Igra zavrsena");
		}
		else if (status==Status::KrajPobjeda) {
			std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
			komanda=Komande::ZavrsiIgru;
			Ocisti(polja);
			throw std::runtime_error("Igra zavrsena");
		}
	}
	else if (komanda==Komande::PomjeriDalje) {
		Status status(Idi(polja, p_x, p_y, x, y));
		std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")" << std::endl;
		if (status==Status::KrajPoraz) {
			std::cout << "Nagazili ste na minu" << std::endl;
			komanda=Komande::ZavrsiIgru;
			Ocisti(polja);
			throw std::runtime_error("Igra zavrsena");
		}
		else if (status==Status::KrajPobjeda) {
			std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
			komanda=Komande::ZavrsiIgru;
			Ocisti(polja);
			throw std::runtime_error("Igra zavrsena");
		}
	}
	else if (komanda==Komande::Blokiraj) {
		BlokirajPolje(polja, x, y);
	}
	else if (komanda==Komande::Deblokiraj) {
		DeblokirajPolje(polja, x, y);
	}
	else if (komanda==Komande::PrikaziOkolinu) {
		auto matrica(PrikaziOkolinu(polja, x, y));
		for (int i=0; i<3; i++) {
			for (int j=0; j<3; j++) {
				std::cout << matrica.at(i).at(j) << " ";
			}
			std::cout << std::endl;
		}
	}
	else if (komanda==Komande::ZavrsiIgru) {
		Ocisti(polja);
		throw std::runtime_error("Igra zavrsena");
	}
	else if (komanda==Komande::KreirajIgru) {
		
		std::vector<std::vector<int>> mine;
		int n;
		
		std::cout << "Unesite broj polja: ";
		while (std::cin >> n, !std::cin || n<=0 || std::cin.peek()!='\n') {
			std::cout << "Greska, unesite ponovo!" << std::endl;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "Unesite broj polja: ";
		}
		std::cin.ignore(10000, '\n');
		std::cout << "Unesite pozicije mina: ";
		char znak;
		int prvi, drugi;
		while (std::cin >> znak, znak!='.') {
			
			if (znak!='(') std::cout << "Greska, unesite ponovo!" << std::endl;
			else if (std::cin >> prvi >> znak, prvi<0 || prvi>=n || !std::cin || znak!=',') std::cout << "Greska, unesite ponovo!" << std::endl;
			else if (std::cin >> drugi >> znak, drugi<0 || drugi>=n || !std::cin || znak!=')') std::cout << "Greska, unesite ponovo!" << std::endl;
			else mine.push_back({prvi, drugi});
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
		
		polja=KreirajIgru(n, mine);
		std::cin.clear();
		std::cin.ignore(10000, '\n');
	}
	}
	catch(std::runtime_error) {
		throw;
	}
	catch (std::exception &izuzetak) {
		std::cout <<  izuzetak.what() << std::endl;
	}
	return;
}

int main ()
{
	Tabla polja;
	Komande komanda;
	KodoviGresaka greska;
	Smjerovi smjer;
	int x(0), y(0), poc_x(0), poc_y(0);
	try {
	for (;;) {
		std::cout << "Unesite komandu: ";
		if (UnosKomande(komanda, smjer, x, y, greska)) {
			IzvrsiKomandu(komanda, polja, x, y, smjer, poc_x, poc_y);
		}
		else PrijaviGresku(greska);
	} 
	} catch(...) { 
		std::cout << "Dovidjenja!";
	}
	return 0;
}
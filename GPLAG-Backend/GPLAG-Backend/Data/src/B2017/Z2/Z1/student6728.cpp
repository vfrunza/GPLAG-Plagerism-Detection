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
#include <string>
#include <stdexcept>

enum class Polje {
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};

enum class Smjerovi {
	GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};

enum class Status {
	NijeKraj, KrajPoraz, KrajPobjeda
};

enum class KodoviGresaka {
	PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};

enum class Komande {
	PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};

typedef std::vector<std::vector<Polje>> Tabla;
typedef std::vector<std::vector<int>> Matrica;
typedef std::string String;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine) {
	
	if (n<=0) throw std::domain_error ("Ilegalna velicina");
	
	for (int i=0; i<mine.size(); i++) {
		if (mine.at(i).size()!=2) throw std::domain_error ("Ilegalan format zadavanja mina"); // redoslijed provjer??
		for (int j=0; j<mine.at(i).size(); j++)
			if (mine.at(i).at(j)<0 || mine.at(i).at(j)>=n) throw std::domain_error ("Ilegalne pozicije mina");
	}
	
	Tabla t(n, std::vector<Polje>(n, Polje::Prazno));
	
	for (int i=0; i<mine.size(); i++)
		t.at(mine.at(i).at(0)).at(mine.at(i).at(1))=Polje::Mina;
	
	return t;
}


std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y) {
	
	if (x<0 || x>=polja.size() || y<0 || y>=polja.size()) throw std::domain_error ("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	
	Matrica m(3, std::vector<int>(3, 0));
	
	
	
	return m;
}

void BlokirajPolje(Tabla &polja, int x, int y) {
	
	if (x<0 || x>=polja.size() || y<0 || y>=polja.size()) throw std::domain_error ("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");

	if (polja.at(x).at(y)==Polje::Prazno) polja.at(x).at(y)=Polje::BlokiranoPrazno;		
	else if (polja.at(x).at(y)==Polje::Posjeceno) polja.at(x).at(y)=Polje::BlokiranoPosjeceno;
	else if (polja.at(x).at(y)==Polje::Mina) polja.at(x).at(y)=Polje::BlokiranoMina;
}

void DeblokirajPolje(Tabla &polja, int x, int y) {
	
	if (x<0 || x>=polja.size() || y<0 || y>=polja.size()) throw std::domain_error ("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	
	if (polja.at(x).at(y)==Polje::BlokiranoPrazno) polja.at(x).at(y)=Polje::Prazno;
	else if (polja.at(x).at(y)==Polje::BlokiranoPosjeceno) polja.at(x).at(y)=Polje::Posjeceno;
	else if (polja.at(x).at(y)==Polje::BlokiranoMina) polja.at(x).at(y)=Polje::Mina;
}


Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer) {
	
	polja.at(x).at(y)=Polje::Posjeceno;
	
	int novi_x=x, novi_y=y;
	
	if (smjer==Smjerovi::GoreLijevo) {novi_x=x-1; novi_y=y-1;}
	else if (smjer==Smjerovi::Gore) {novi_x=x-1; novi_y=y;}
	else if (smjer==Smjerovi::GoreDesno) {novi_x=x-1; novi_y=y+1;}
	else if (smjer==Smjerovi::Desno) {novi_y=y+1; novi_x=x;}
	else if (smjer==Smjerovi::DoljeDesno) {novi_x=x+1; novi_y=y+1;}
	else if (smjer==Smjerovi::Dolje) {novi_x=x+1; novi_y=y;}
	else if (smjer==Smjerovi::DoljeLijevo) {novi_x=x+1; novi_y=y-1;}
	else if (smjer==Smjerovi::Lijevo) {novi_y=y-1; novi_x=x;}
	
	if (novi_x<0 || novi_x>=polja.size() || novi_y<0 || novi_y>=polja.size()) throw std::out_of_range ("Izlazak van igrace table");
	if (polja.at(novi_x).at(novi_y)==Polje::BlokiranoPosjeceno || polja.at(novi_x).at(novi_y)==Polje::BlokiranoPrazno || polja.at(novi_x).at(novi_y)==Polje::BlokiranoMina) 
		throw std::logic_error ("Blokirano polje");
		
	x=novi_x; y=novi_y;
	
	Status status(Status::NijeKraj);
	
	if (polja.at(x).at(y)==Polje::Mina) {
		status=Status::KrajPoraz;
		for (int i=0; i<polja.size(); i++)
			for (int j=0; j<polja.at(i).size(); j++)
				polja.at(i).at(j)=Polje::Prazno;
		return status;
	}
	
	// provjera pobjede
	bool pobjeda(1);
	for (int i=0; i<polja.size(); i++)
		for (int j=0; j<polja.at(i).size(); j++)
			if (polja.at(i).at(j)==Polje::Prazno) { // treba li porvjeravati i posjeceno?!?
				pobjeda=0;
				break;
			}

	if (pobjeda==1) status=Status::KrajPobjeda;
	
	return status;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y) {
	
	polja.at(x).at(y)=Polje::Posjeceno;
	
	if (novi_x<0 || novi_x>=polja.size() || novi_y<0 || novi_y>=polja.size()) throw std::out_of_range ("Izlazak van igrace table");
	if (polja.at(novi_x).at(novi_y)==Polje::BlokiranoPosjeceno || polja.at(novi_x).at(novi_y)==Polje::BlokiranoPrazno || polja.at(novi_x).at(novi_y)==Polje::BlokiranoMina) 
		throw std::logic_error ("Blokirano polje");
	
	x=novi_x; y=novi_y;
	
	Status status(Status::NijeKraj);
	
	if (polja.at(x).at(y)==Polje::Mina) {
		status=Status::KrajPoraz;
		for (int i=0; i<polja.size(); i++)
			for (int j=0; j<polja.at(i).size(); j++)
				polja.at(i).at(j)=Polje::Prazno;
		return status;
	}
	
	// provjera pobjede
	bool pobjeda(1);
	for (int i=0; i<polja.size(); i++)
		for (int j=0; j<polja.at(i).size(); j++)
			if (polja.at(i).at(j)==Polje::Prazno) { // treba li porvjeravati i posjeceno?!?
				pobjeda=0;
				break;
			}

	if (pobjeda==1) status=Status::KrajPobjeda;
	
	return status;
}

void PrijaviGresku (KodoviGresaka kod) {
	
	if (kod==KodoviGresaka::PogresnaKomanda) std::cout << "Nerazumljiva komanda!" << std::endl;
	else if (kod==KodoviGresaka::NedostajeParametar) std::cout << "Komanda trazi parametar koji nije naveden!" << std::endl;
	else if (kod==KodoviGresaka::NeispravanParametar) std::cout << "Parametar komande nije ispravan!" << std::endl;
	else if (kod==KodoviGresaka::SuvisanParametar) std::cout << "Zadan je suvisan parametar nakon komande!" << std::endl;
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska) {
	
	String ime;
	std::getline(std::cin, ime);
	
	// uklanjanje razmaka
	for (int i=0; i<ime.length(); i++)
		if (ime.at(i)==' ') {
			ime.erase(std::begin(ime)+i);
			i--;
		}
	
	if (ime.length()==0 || (ime.at(0)!='P' && ime.at(0)!='B' && ime.at(0)!='D' && ime.at(0)!='Z' && ime.at(0)!='K')) {
		greska=KodoviGresaka::PogresnaKomanda;
		return false;
	}
	if (ime.length()>0) {
		if (ime.at(0)=='Z') {
			if (ime.length()==1) {komanda=Komande::ZavrsiIgru; return true;}
			else {greska=KodoviGresaka::SuvisanParametar; return false;}
		}
		if (ime.at(0)=='K') {
			if (ime.length()==1) {komanda=Komande::KreirajIgru; return true;}
			else {greska=KodoviGresaka::SuvisanParametar; return false;}
		}
		if (ime.length()>=2) {
			if (ime.at(0)=='P' && ime.at(1)=='O') {
				if (ime.length()==2) {komanda=Komande::PrikaziOkolinu; return true;}
				else {greska=KodoviGresaka::SuvisanParametar; return false;}
			}
			if (ime.at(0)=='P' && ime.at(1)=='1') {
				if (ime.length()==2) {greska=KodoviGresaka::NedostajeParametar; return false;}
				if (ime.length()>5) {greska=KodoviGresaka::NeispravanParametar; return false;}
				if (ime.length()<=5) {
					if (ime.length()==3) {
						if (ime.at(2)=='G') {komanda=Komande::PomjeriJednoMjesto; smjer=Smjerovi::Gore; return true;}
						if (ime.at(2)=='D') {komanda=Komande::PomjeriJednoMjesto; smjer=Smjerovi::Desno; return true;}
						if (ime.at(2)=='L') {komanda=Komande::PomjeriJednoMjesto; smjer=Smjerovi::Lijevo; return true;}
						greska=KodoviGresaka::NeispravanParametar;
						return false;
					}
					if (ime.length()==4) {
						if (ime.at(2)=='G' && ime.at(3)=='L') {komanda=Komande::PomjeriJednoMjesto; smjer=Smjerovi::GoreLijevo; return true;}
						if (ime.at(2)=='G' && ime.at(3)=='D') {komanda=Komande::PomjeriJednoMjesto; smjer=Smjerovi::GoreDesno; return true;}
						if (ime.at(2)=='D' && ime.at(3)=='o') {komanda=Komande::PomjeriJednoMjesto; smjer=Smjerovi::Dolje; return true;}
						greska=KodoviGresaka::NeispravanParametar;
						return false;
					}
					if (ime.length()==5) {
						if (ime.at(2)=='D' && ime.at(3)=='o' && ime.at(4)=='D') {komanda=Komande::PomjeriJednoMjesto; smjer=Smjerovi::DoljeDesno; return true;}
						if (ime.at(2)=='D' && ime.at(3)=='o' && ime.at(4)=='L') {komanda=Komande::PomjeriJednoMjesto; smjer=Smjerovi::DoljeLijevo; return true;}
						greska=KodoviGresaka::NeispravanParametar;
						return false;
					}
				}
			}
			if (ime.at(0)=='P' && ime.at(1)=='>') {
				if (ime.length()==2) {greska=KodoviGresaka::NedostajeParametar; return false;}
				if (ime.length()>4) {greska=KodoviGresaka::NeispravanParametar; return false;}
				if (ime.length()==4) {
					if ((ime.at(2)>='0' && ime.at(2)<='9') && (ime.at(3)>='0' && ime.at(3)<='9')) {komanda=Komande::PomjeriDalje; x=ime.at(2)-48; y=ime.at(3)-48; return true;}
					greska=KodoviGresaka::NeispravanParametar;
					return false;
				}
			}
		}
		if (ime.length()>=1) {
			if (ime.at(0)=='B') {
				if (ime.length()==1) {greska=KodoviGresaka::NedostajeParametar; return false;}
				if (ime.length()>3) {greska=KodoviGresaka::SuvisanParametar; return false;}
				if (ime.length()==3) {
					if ((ime.at(1)>='0' && ime.at(1)<='9') && (ime.at(2)>='0' && ime.at(2)<='9')) {komanda=Komande::Blokiraj; x=ime.at(1)-48; y=ime.at(2)-48; return true;}
					greska=KodoviGresaka::NeispravanParametar;
					return false;
				}
			}
			if (ime.at(0)=='D') {
				if (ime.length()==1) {greska=KodoviGresaka::NedostajeParametar; return false;}
				if (ime.length()>3) {greska=KodoviGresaka::SuvisanParametar; return false;}
				if (ime.length()==3) {
					if ((ime.at(1)>='0' && ime.at(1)<='9') && (ime.at(2)>='0' && ime.at(2)<='9')) {komanda=Komande::Deblokiraj; x=ime.at(1)-48; y=ime.at(2)-48; return true;}
					greska=KodoviGresaka::NeispravanParametar;
					return false;
				}
			}
		}
		greska=KodoviGresaka::PogresnaKomanda;
		return false;
	}
	
	return false;
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0) {
	
	
}





int main ()
{
    while (true) {
      Komande komanda;
      Smjerovi smjer = Smjerovi::GoreDesno;
      int x = 0, y = 0;
      KodoviGresaka greska = KodoviGresaka::SuvisanParametar;
      UnosKomande(komanda, smjer, x, y, greska);
      if(komanda == Komande::ZavrsiIgru) break;
      std::cout << "Unesena komanda: " << int(komanda);
      std::cout << ", (x,y) = (" << x << "," << y <<")";
      if(smjer != Smjerovi::GoreDesno) std::cout << " azuriran smjer na " << int(smjer);
      std::cout  << std::endl;
    }
	return 0;
}
#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

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
    PogresnaKomanda, NedostajeParmetar, SuvisanParametar, NeispravanParametar
};

typedef vector<vector<Polje>> Tabla;

Status TrenutniStatus(Tabla t, int x, int y) {
	if(t.at(x).at(y) == Polje::Mina)
		return Status::KrajPoraz;
		
	for(int i=0; i<t.size(); i++) 
		for(int j=0; j<t.size(); j++) 
			if(i != x && j != y && t.at(i).at(j) != Polje::Posjeceno && t.at(i).at(j) != Polje::Mina)
				return Status::NijeKraj;
		
	return Status::KrajPobjeda;
}	

bool BlokiranoPolje(Tabla t, int x, int y) {
	if(t.at(x).at(y) == Polje::BlokiranoPrazno || t.at(x).at(y) == Polje::BlokiranoPosjeceno || t.at(x).at(y) == Polje::BlokiranoMina)
		return true;
		
	return false;
}

Tabla KreirajIgru(int n, const vector<vector<int>> &mine) {
	if(n <= 0)
		throw domain_error("Ilegalna velicina");
		
	for(int i=0; i<mine.size(); i++) {
		if(mine.at(i).size() != 2)
			throw domain_error("Ilegalan format zadavanja mina");
		if(mine.at(i).at(0) >= n || mine.at(i).at(0) < 0 || mine.at(i).at(1) >= n || mine.at(i).at(1) < 0)
			throw domain_error("Ilegalne pozicije mina");
	}
		
	Tabla t(n);
	
	for(int i=0; i<n; i++)
		t.at(i).resize(n);
		
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			t.at(i).at(j) = Polje::Prazno;
	
	for(int i=0; i<mine.size(); i++) {
		t.at(mine.at(i).at(0)).at(mine.at(i).at(1)) = Polje::Mina;
	}
	
	return t;
}

void IspisiTablu(Tabla t){
	for(int i=0; i<t.size(); i++) {
		for(int j=0; j<t.at(0).size(); j++) {
			if(t.at(i).at(j) == Polje::Prazno)
				cout << "0 ";
			else
				cout << "1 ";
		}
		
		cout << endl;
	}
}

std::vector<vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y);

void BlokirajPolje(Tabla &polja, int x, int y) {
	if(x < 0 || x >= polja.size() || y < 0 || y >= polja.size())
		throw domain_error("Polje (x,y) ne postoji");
		
	if(polja.at(x).at(y) == Polje::Prazno)
		polja.at(x).at(y) == Polje::BlokiranoPrazno;
	else if(polja.at(x).at(y) == Polje::Mina)
		polja.at(x).at(y) == Polje::BlokiranoMina;
	else if(polja.at(x).at(y) == Polje::Posjeceno)
		polja.at(x).at(y) == Polje::BlokiranoPosjeceno;
}

void DeblokirajPolje(Tabla &polja, int x, int y) {
	if(x < 0 || x >= polja.size() || y < 0 || y >= polja.size())
		throw domain_error("Polje (x,y) ne postoji");
		
	if(polja.at(x).at(y) == Polje::BlokiranoPrazno)
		polja.at(x).at(y) == Polje::Prazno;
	else if(polja.at(x).at(y) == Polje::BlokiranoMina)
		polja.at(x).at(y) == Polje::Mina;
	else if(polja.at(x).at(y) == Polje::BlokiranoPosjeceno)
		polja.at(x).at(y) == Polje::Posjeceno;
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer) {
	if(((smjer == Smjerovi::Gore || smjer == Smjerovi::GoreDesno || smjer == Smjerovi::GoreLijevo) && y == 0) ||
		((smjer == Smjerovi::Dolje || smjer == Smjerovi::DoljeDesno || smjer == Smjerovi::DoljeLijevo) && y == polja.size() - 1) ||
		((smjer == Smjerovi::Lijevo || smjer == Smjerovi::GoreLijevo || smjer == Smjerovi::DoljeLijevo) && x == 0) ||
		((smjer == Smjerovi::Desno || smjer == Smjerovi::GoreDesno || smjer == Smjerovi::DoljeDesno) && x == polja.size() - 1))
			throw out_of_range("Izlazak van igrace table");
			
	if((smjer == Smjerovi::Gore && BlokiranoPolje(polja, x, y - 1)) ||
		(smjer == Smjerovi::Dolje && BlokiranoPolje(polja, x, y + 1)) ||
		(smjer == Smjerovi::Lijevo && BlokiranoPolje(polja, x - 1, y)) ||
		(smjer == Smjerovi::Desno && BlokiranoPolje(polja, x + 1, y)) ||
		(smjer == Smjerovi::GoreLijevo && BlokiranoPolje(polja, x - 1, y - 1)) ||
		(smjer == Smjerovi::GoreDesno && BlokiranoPolje(polja, x + 1, y - 1)) ||
		(smjer == Smjerovi::DoljeLijevo && BlokiranoPolje(polja, x - 1, y + 1)) ||
		(smjer == Smjerovi::DoljeDesno && BlokiranoPolje(polja, x + 1, y + 1)))
			throw logic_error("Blokirano polje");
			
	polja.at(x).at(y) = Polje::Posjeceno;
			
	switch(smjer) {
		case Smjerovi::Gore:
			y--;
			break;
		case Smjerovi::Dolje:
			y++;
			break;
		case Smjerovi::Lijevo:
			x--;
			break;
		case Smjerovi::Desno:
			x++;
			break;
		case Smjerovi::GoreLijevo:
			y--;
			x--;
			break;
		case Smjerovi::GoreDesno:
			y--;
			x++;
			break;
		case Smjerovi::DoljeLijevo:
			y++;
			x--;
			break;
		case Smjerovi::DoljeDesno:
			y++;
			x++;
	}
			
	Status trenutniStatus = TrenutniStatus(polja, x, y);
	
	if(trenutniStatus == Status::KrajPoraz) 
		for(int i=0; i<polja.size(); i++) 
			for(int j=0; j<polja.size(); j++)
				polja.at(i).at(j) = Polje::Prazno;
	
	return trenutniStatus;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y) {
	if(novi_x < 0 || novi_x >= polja.size() || novi_y < 0 || novi_y >= polja.size())
		throw out_of_range("Izlazak van igrace table");
		
	if(BlokiranoPolje(polja, novi_x, novi_y))
		throw logic_error("Blokirano polje");
		
		
	polja.at(x).at(y) = Polje::Posjeceno;
	
	x = novi_x;
	y = novi_y;
		
	Status trenutniStatus = TrenutniStatus(polja, x, y);
	
	if(trenutniStatus == Status::KrajPoraz) 
		for(int i=0; i<polja.size(); i++) 
			for(int j=0; j<polja.size(); j++)
				polja.at(i).at(j) = Polje::Prazno;
	
	return trenutniStatus;
}

int main ()
{
	vector<vector<int>> mine = {{0,0}, {0,2}, {1,3}};
	Tabla t = KreirajIgru(4,mine);
	IspisiTablu(t);
}
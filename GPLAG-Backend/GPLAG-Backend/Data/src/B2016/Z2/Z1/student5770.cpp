#include <vector>
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>

template <typename T> std::string PretvoriUString(T x){  
  std::ostringstream s; s << x; 
  return s.str();
}

enum class Polje {Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina};

enum class Smjerovi {GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo};

enum class Status {NijeKraj, KrajPoraz, KrajPobjeda};

enum class KodoviGresaka {PogresnaKomanda, NedostajeParmetar, SuvisanParametar, NeispravanParametar};

enum class Komande {PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru};

typedef std::vector<std::vector<Polje>> Tabla;

void IspisiTablu(Tabla igra){
	for(int i = 0; i < igra.size(); i++){
		for(int j = 0; j < igra.size(); j++){
			std::cout << static_cast<int>(igra[i][j]) << " ";
		}
		std::cout << std::endl;
	}
}

int BrojMina(const Tabla &polja, int x, int y){
	int rezultat(0);
	for(int i = 0; i < polja.size(); i++){
		for(int j = 0; j < polja[0].size(); j++){
			if(i==x-1 && j==y-1 && polja[i][j]==Polje::Mina) rezultat++;
			else if(i==x-1 && j==y && polja[i][j]==Polje::Mina) rezultat++;
			else if(i==x-1 && j==y+1 && polja[i][j]==Polje::Mina) rezultat++;
			else if(i==x && j==y-1 && polja[i][j]==Polje::Mina) rezultat++; 
			else if(i==x && j==y+1 && polja[i][j]==Polje::Mina) rezultat++; 
			else if(i==x+1 && j==y-1 && polja[i][j]==Polje::Mina) rezultat++; 
			else if(i==x+1 && j==y && polja[i][j]==Polje::Mina) rezultat++; 
			else if(i==x+1 && j==y+1 && polja[i][j]==Polje::Mina) rezultat++; 
		}
	}
	return rezultat;
}

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	bool format(true),pozicije(true);
	for(int i = 0; i < mine.size(); i++){
		if(mine[i].size() != 2){
			format = false;
			break;
		}
	}
	for(int i = 0; i < mine.size(); i++){
		if(mine[i][0] > n-1 || mine[i][0] < 0 || mine[i][1] > n-1 || mine[i][1] < 0){
			pozicije = false;
			break;
		}
	}
	if(!format) throw std::domain_error("Ilegalan format zadavanja mina");
	if(!pozicije) throw std::domain_error("Ilegalne pozicije mina");
	Tabla igra(n, std::vector<Polje> (n,Polje::Prazno));
	for(int i = 0; i < mine.size(); i++){
		igra[mine[i][0]][mine[i][1]] = Polje::Mina;
	}
	return igra;
}

void BlokirajPolje(Tabla &polja, int x, int y){
	bool uslov(true);
	if(x < 0 || x >= polja.size() || y < 0 || y >= polja[0].size()) uslov = false;
	if(!uslov) throw std::domain_error(("Polje (" + PretvoriUString(x) + "," + PretvoriUString(y) + ") ne postoji"));
	if(polja[x][y] == Polje::Prazno) polja[x][y] = Polje::BlokiranoPrazno;
	else if(polja[x][y] == Polje::Posjeceno) polja[x][y] = Polje::BlokiranoPosjeceno;
	else if(polja[x][y] == Polje::Mina) polja[x][y] = Polje::BlokiranoMina;
}

void DeblokirajPolje(Tabla &polja, int x, int y){
	bool uslov(true);
	if(x < 0 || x >= polja.size() || y < 0 || y >= polja[0].size()) uslov = false;
	if(!uslov) throw std::domain_error(("Polje (" + PretvoriUString(x) + "," + PretvoriUString(y) + ") ne postoji"));
	if(polja[x][y] == Polje::BlokiranoPrazno) polja[x][y] = Polje::Prazno;
	else if(polja[x][y] == Polje::BlokiranoPosjeceno) polja[x][y] = Polje::Posjeceno;
	else if(polja[x][y] == Polje::BlokiranoMina) polja[x][y] = Polje::Mina;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	bool uslov(true);
	if(x < 0 || x >= polja.size() || y < 0 || y >= polja[0].size()) uslov = false;
	if(!uslov) throw std::domain_error(("Polje (" + PretvoriUString(x) + "," + PretvoriUString(y) + ") ne postoji"));
	std::vector<std::vector<int>> okolina(3,std::vector<int> (3));
	for(int i = 0; i < polja.size(); i++){
		for(int j = 0; j < polja[0].size(); j++){
			if(i==x-1 && j==y-1) okolina[0][0]=BrojMina(polja,i,j);
			else if(i==x-1 && j==y) okolina[0][1]=BrojMina(polja,i,j);
			else if(i==x-1 && j==y+1) okolina[0][2]=BrojMina(polja,i,j);
			else if(i==x && j==y-1) okolina[1][0]=BrojMina(polja,i,j);
			else if(i==x && j==y) okolina[1][1]=BrojMina(polja,i,j);
			else if(i==x && j==y+1) okolina[1][2]=BrojMina(polja,i,j);
			else if(i==x+1 && j==y-1) okolina[2][0]=BrojMina(polja,i,j);
			else if(i==x+1 && j==y) okolina[2][1]=BrojMina(polja,i,j);
			else if(i==x+1 && j==y+1) okolina[2][2]=BrojMina(polja,i,j);
		}
	}
	return okolina;
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	int n(0),m(0);
	if(smjer == Smjerovi::GoreLijevo || smjer == Smjerovi::GoreDesno || smjer == Smjerovi::Gore) n = -1;
	if(smjer == Smjerovi::DoljeLijevo || smjer == Smjerovi::DoljeDesno || smjer == Smjerovi::Dolje) n = 1;
	if(smjer == Smjerovi::GoreLijevo || smjer == Smjerovi::DoljeLijevo || smjer == Smjerovi::Lijevo) m = -1;
	if(smjer == Smjerovi::GoreDesno || smjer == Smjerovi::DoljeDesno || smjer == Smjerovi::Desno) m = 1;
	if(x+n >= polja.size() || x+n < 0 || y+m >= polja[0].size() || y+m < 0){
		throw std::out_of_range("Izlazak van igrace table");
	}
	if(static_cast<int>(polja[x+n][y+m]) > 2) throw std::logic_error("Blokirano polje");
	x+=n;
	y+=m;
	if(polja[x][y] == Polje::Mina){
		for(int i = 0; i < polja.size(); i++){
			for(int j = 0; j < polja[0].size(); j++){
				polja[i][j] = Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
	else polja[x][y] = Polje::Posjeceno;
	bool pobjeda(true);
	for(int i = 0; i < polja.size(); i++){
		for(int j = 0; j < polja[0].size(); j++){
			if(polja[i][j] == Polje::Prazno){
				pobjeda = false;
				break;
			}
		}
	}
	if(pobjeda) return Status::KrajPobjeda;
	else return Status::NijeKraj;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	if(novi_x >= polja.size() || novi_x < 0 || novi_y >= polja[0].size() || novi_y < 0){
		throw std::out_of_range("Izlazak van igrace table");
	}
	if(static_cast<int>(polja[novi_x][novi_y]) > 2) throw std::logic_error("Blokirano polje");
	x = novi_x;
	y = novi_y;
	if(polja[x][y] == Polje::Mina){
		for(int i = 0; i < polja.size(); i++){
			for(int j = 0; j < polja[0].size(); j++){
				polja[i][j] = Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
	else polja[x][y] = Polje::Posjeceno;
	bool pobjeda(true);
	for(int i = 0; i < polja.size(); i++){
		for(int j = 0; j < polja[0].size(); j++){
			if(polja[i][j] == Polje::Prazno){
				pobjeda = false;
				break;
			}
		}
	}
	if(pobjeda) return Status::KrajPobjeda;
	else return Status::NijeKraj;
}

void PrijaviGresku(KodoviGresaka kod){
	if(kod == KodoviGresaka::PogresnaKomanda) std::cout << "Nerazumljiva komanda! ";
	else if(kod == KodoviGresaka::NedostajeParmetar) std::cout << "Komanda trazi parametar koji nije naveden!";
	else if(kod == KodoviGresaka::SuvisanParametar) std::cout << "Zadan je suvisan parametar nakon komande!";
	else if(kod == KodoviGresaka::NeispravanParametar) std::cout << "Parametar komande nije ispravan!";
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	char znak, x;
	znak = std::cin.get();
	x = std::cin.peek();
	if(znak == 'P'){
		if(x == '1') komanda = Komande::PomjeriJednoMjesto;
		else if(x == '>') komanda = Komande::PomjeriDalje;
		else if(x == 'O') komanda = Komande::PrikaziOkolinu;
	}
	
}

int main ()
{
	std::vector<std::vector<int>> test{{0,1},{0,4},{1,3},{1,4},{2,0},{2,1},{2,3}};
	try{
		Tabla igrica = KreirajIgru(5,test);
		std::vector<std::vector<int>> okolina = PrikaziOkolinu(igrica,1,1);
		for(int i = 0; i < okolina.size(); i++){
			for(int j = 0; j < okolina[0].size(); j++){
				std::cout << okolina[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
	catch(const std::exception &izuzetak){
		std::cout << izuzetak.what() << std::endl;
	}
	return 0;
}
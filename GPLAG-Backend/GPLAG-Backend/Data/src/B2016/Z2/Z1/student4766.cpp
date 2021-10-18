#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <complex>
#include <cstring>

enum class KodoviGresaka{
	PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};
enum class Polje{
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};
enum class Smjerovi{
	GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};
enum class Status{
	NijeKraj, KrajPoraz, KrajPobjeda
};
enum class Komande{
	PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine);
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y);
void BlokirajPolje(Tabla &polja, int x, int y);
void DeblokirajPolje(Tabla &polja, int x, int y);
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer);
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y);
int testMine(const std::vector<std::vector<int>> &mine, int n);
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska);
void popuniPrazno(Tabla &polja);
void setStatus(Status &ret, Tabla &polja, int x, int y);
bool jeBroj(char x);
int readNum(std::string &s, int &pos, bool test = true);
void showEnv(std::vector<std::vector<int>> v);
std::vector<std::vector<int>> setUpGame(int &x);

void gameOver(Tabla &polja){
	popuniPrazno(polja); throw std::runtime_error("Igra Zavrsena");
}
void doMove(Status stat, Tabla &polja){
	if(stat == Status::KrajPobjeda){
		std::cout << "Bravo obisli ste sva sigurna polja\n";
		gameOver(polja);
	}
	else if(stat == Status::KrajPoraz){
		std::cout << "Nagazili ste na minu\n";
		gameOver(polja);
	}
}
void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0){
	try{
		switch(komanda){
			case Komande:: PomjeriJednoMjesto: doMove(Idi(polja,x,y,p_smjer), polja); std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")\n"; break;
			case Komande::  PomjeriDalje: doMove(Idi(polja, x, y, p_x, p_y), polja); std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")\n"; break;
			case Komande:: Blokiraj: BlokirajPolje(polja, p_x, p_y); break;
			case Komande:: Deblokiraj: DeblokirajPolje(polja, p_x, p_y); break;
			case Komande:: PrikaziOkolinu: showEnv(PrikaziOkolinu(polja, x, y)); break;
			case Komande:: ZavrsiIgru: gameOver(polja); break;
			case Komande:: KreirajIgru: int n; std::vector<std::vector<int>> v (setUpGame(n)); polja = KreirajIgru(n,v); break;
		}
	}catch(std::logic_error &err){
		if(!strcmp(err.what(), "Igra Zavrsena")) throw;
		std::cout << err.what() << std::endl;
	}
}
bool jeBroj(char x){
	return (x >= '0' && x <= '9');
}
bool nijeRazmak(char x){
	return x != ' ';
}
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	std::vector<std::string> validne{"P1", "P>", "B", "D", "PO", "Z", "K"};
	std::vector<std::string> eww{"GL", "GD", "G", "DoD", "DoL", "Do","D","L"};
	std::vector<Smjerovi> dir{Smjerovi::GoreLijevo, Smjerovi::GoreDesno, Smjerovi::Gore,
	Smjerovi::DoljeDesno, Smjerovi::DoljeLijevo, Smjerovi::Dolje, Smjerovi::Desno, Smjerovi::Lijevo};
	std::vector<Komande> kom{Komande::PomjeriJednoMjesto, Komande::PomjeriDalje, Komande::Blokiraj,
	Komande::Deblokiraj, Komande::PrikaziOkolinu, Komande::ZavrsiIgru, Komande::KreirajIgru};
	std::string read;
	std::getline(std::cin, read);
	bool validKom(false), validPar(true),sviPar(true), prevPar(false);
	for(int i = 0; i < read.length(); i++){
		if(read[i] == ' ' && (i == 0 || i == read.length() -1 || (!nijeRazmak(read[i-1]) || !nijeRazmak(read[i+1]))) ){
			read.erase(read.begin() + i);
			i--;
		}
	}
	int i;
	for(i = 0; i < validne.size(); i++)
		if(read.substr(0, validne[i].size()) == validne[i]){
			validKom = true;
			read = read.substr(validne[i].size(), read.length() -validne[i].size());
			if(read.size() > 0 && read[0] == ' ') read.erase(read.begin());
			break;
		}
	if(validKom && i == 0){
		int j;
		for( j = 0; j < eww.size(); j++)
			if(read.substr(0, eww[j].size()) == eww[j]){
				read = read.substr(eww[j].size(), read.length() - eww[j].size());
				if(read.length() != 0){
					validPar = false;
					//smjer = dir[j];
				}else{
					smjer = dir[j];
				}
				break;
			}
		if(j == eww.size() && read.length()== 0) sviPar = false;
		else if(j == eww.size()) validPar = false;
	}
	else if(validKom && i >= 1 && i <= 3){
		int tmpX(-1), tmpY(-1), pos(0);
		tmpX = readNum(read,pos);
		if(pos < read.length() && read[pos] != ' ')  validPar = false;//pos++
		pos++;
		tmpY = readNum(read,pos);
		if(pos != read.length() && (tmpX < 0 || tmpY < 0 )) validPar = false;
		if(tmpY == -2 && tmpX != -3) sviPar = false;
		if(tmpX == -3 || tmpY == -3) validPar = false;
		if(validPar && sviPar) {
			x = tmpX; y = tmpY;
			read.resize(read.length()-pos);
		}
	}
	if(validKom && i >= 1 && i <= 6){
		if(read.length() != 0) prevPar = true;
	}
	if(!validKom) greska = KodoviGresaka::PogresnaKomanda;
	else if(!sviPar) greska = KodoviGresaka::NedostajeParametar;
	else if(!validPar) greska = KodoviGresaka::NeispravanParametar;
	else if(prevPar) greska = KodoviGresaka::SuvisanParametar;
	
	 if(validKom && sviPar && !prevPar && validPar){
	 	komanda = kom[i];
	 	return true;
	 }
	 return false;
}
int readNum(std::string &s, int &pos, bool test ){
	int ret(0);//vraca -1 za neg brojeve, -3 ako nista ne ucita jer naleti na nesto sto nije razmak, -2 ako nista ne ucita jer fali parametar
	bool uslo = false;
	if(pos < s.length() && s[pos] == '-') return -1;
	while(pos < s.length() && jeBroj(s[pos])){
		uslo = true;
		ret *= 10;
		ret += s[pos++] - '0';
	}
	if(pos >= s.length() && uslo == false) return -2;
	else if(test && pos < s.length() && !jeBroj(s[pos]) && s[pos] != ' ') return -3;
	return ret;
}

bool validPos(int x, int y, const Tabla &polja){
	return !(x >= polja.size() || x < 0 || y >= polja.size() || y < 0);
}
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	if(!validPos(novi_x, novi_y, polja))
		throw std::out_of_range("Izlazak van igrace table");
	if(polja[novi_x][novi_y] == Polje::BlokiranoPosjeceno ||polja[novi_x][novi_y] == Polje::BlokiranoPrazno || polja[novi_x][novi_y] == Polje::BlokiranoMina)
		throw std::logic_error("Blokirano polje");
	polja[x][y] = Polje::Posjeceno;
	x = novi_x;
	y = novi_y;
	Status ret;
	setStatus(ret, polja, x, y);
	return ret;
}
void setStatus(Status &ret, Tabla &polja, int x, int y){
	if(polja[x][y] == Polje::Mina){
		ret = Status::KrajPoraz; popuniPrazno(polja);
	}else{
		ret = Status::NijeKraj;
		for(int i = 0; i < polja.size(); i++)
		for(int j = 0; j < polja.size(); j++){
			if(polja[i][j] == Polje::Prazno && (i != x || j != y))return;
			else if( i + 1 == polja.size() && j + 1 == polja.size())
				ret = Status::KrajPobjeda;
		}
	}
}
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	int vx(0), vy(0);
	switch(smjer){
		case Smjerovi::GoreLijevo: vx = -1; vy= -1; break;
		case Smjerovi::GoreDesno: vx=-1; vy =+1; break;
		case Smjerovi::Gore: vx-= 1; break;
		case Smjerovi::Dolje: vx += 1; break;
		case Smjerovi::DoljeDesno: vx += 1; vy += 1; break;
		case Smjerovi::DoljeLijevo: vx += 1; vy -= 1; break;
		case Smjerovi::Desno: vy+= 1; break;
		case Smjerovi::Lijevo: vy-= 1; break;
	}
	if(!validPos(x+vx,y+vy,polja)) throw std::out_of_range("Izlazak van igrace table");
	if(polja[x+vx][y+vy] == Polje::BlokiranoPosjeceno || polja[x+vx][y+vy] == Polje::BlokiranoPrazno || polja[x+vx][y+vy] == Polje::BlokiranoMina)
		throw std::logic_error("Blokirano polje");
	polja[x][y] = Polje::Posjeceno;
	x += vx; y += vy;
	Status ret;
	setStatus(ret,polja,x,y);
	return ret;
}

void PrijaviGresku(KodoviGresaka err){
	switch(err){
		case KodoviGresaka::PogresnaKomanda: std::cout << "Nerazumljiva komanda!\n"; break;
		case KodoviGresaka::NedostajeParametar: std::cout << "Komanda trazi parametar koji nije naveden!\n"; break;
		case KodoviGresaka::NeispravanParametar: std::cout << "Parametar komande nije ispravan!\n";break;
		case KodoviGresaka::SuvisanParametar: std::cout << "Zadan je suvisan parametar nakon komande!\n"; break;
	}
}
void popuniPrazno(Tabla &polja){
	for(int i = 0; i < polja.size(); i++){
		for(int j = 0; j< polja.size(); j++)
			polja[i][j] = Polje::Prazno;
	}
}
void BlokirajPolje(Tabla &polja, int x, int y){
	if(!validPos(x,y,polja))
	throw std::domain_error("Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji");
	switch(polja[x][y]){
		case Polje::Prazno: polja[x][y] = Polje::BlokiranoPrazno; break;
		case Polje::Posjeceno: polja[x][y] = Polje::BlokiranoPosjeceno; break;
		case Polje::Mina: polja[x][y] = Polje::BlokiranoMina; break;
		default: break;
	}
}
void DeblokirajPolje(Tabla &polja, int x, int y){
	if(!validPos(x,y,polja))
	throw std::domain_error("Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji");
	switch(polja[x][y]){
		case Polje::BlokiranoPrazno: polja[x][y] = Polje::Prazno; break;
		case Polje::BlokiranoPosjeceno: polja[x][y] = Polje::Posjeceno; break;
		case Polje::BlokiranoMina: polja[x][y] = Polje::Mina; break;
		default: break;
	}
}
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	std::vector<std::vector<int>> v(3);
	if(!validPos(x,y,polja))
	throw std::domain_error("Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji");
	for(int i = x-1; i < x+2; i++){
		for(int j = y-1; j < y+2; j++){
			int sum(0);
			for(int k = i-1; k <= i+1; k++){
				for(int l = j -1; l<= j +1; l++){
					if(validPos(k,l,polja) && (k!= i || l != j)){
						if(polja[k][l] == Polje::Mina) sum++;
					}
				}
			}
			v[i-x+1].push_back(sum);
		}
	}
	return v;
}
int testMine(const std::vector<std::vector<int>> &mine, int n){
	//vraca 1 ako ne valja vektor, 2 ako izlazi van opsega, 0 ako je korektan
	for(int i = 0; i < mine.size(); i++){
		if(mine[i].size() != 2) return 1;
		for(int j = 0; j < 2; j++)
			if(mine[i][j] >= n || mine[i][j] < 0) return 2;
	}
	return 0;
}
std::vector<std::vector<int>> setUpGame(int &par){
	std::cout << "Unesite broj polja: "; int n;
	std::complex<double> c(-1,-1);
	std::vector<std::vector<int>> v;
	std::vector<int> tmp;
	std::cin >> n;
	std::cout << "Unesite pozicije mina: ";
	par = n;
	std::cin.ignore(1000, '\n');
	for(;;){
		std::string unos;
		std::getline(std::cin, unos);
		for(int i = 0; i < unos.length(); i++)
			if(unos[i] == ' ') unos.erase(unos.begin() + i--);
		if(unos.size() == 1 && unos[0] == '.') break;
		bool err(false); int pos(0);
		if(pos >= unos.size() || unos[pos] != '(') err = true; pos++;
		int xx(readNum(unos,pos,false));
		if(pos >= unos.size() || unos[pos] != ',') err = true; pos++;
		int yy(readNum(unos,pos,false));
		if(pos != int(unos.size())-1 || unos[pos] != ')' || xx < 0 || yy < 0 || xx >= n || yy >= n || (xx == 0 && yy == 0)) err = true;
		if(!err){
			tmp.resize(0);
			tmp.push_back(xx); tmp.push_back(yy); v.push_back(tmp);
		}else{
			std::cout << "Greska, unesite ponovo!\n";
		}
	}
	return v;
}
Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	switch(testMine(mine, n)){
		case 1: throw std::domain_error("Ilegalan format zadavanja mina"); break;
		case 2: throw std::domain_error("Ilegalne pozicije mina"); break;
		case 0: break;
	}
	Tabla ret(n);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			ret[i].push_back(Polje::Prazno);
	}
	for(unsigned int i = 0; i < mine.size(); i++){
		ret[mine[i][0]][mine[i][1]] = Polje::Mina;
	}
	return ret;
}
void showEnv(std::vector<std::vector<int>> v){
	for(int i = 0; i < 3; i++){
		for(int k = 0; k < 3; k++)
		std::cout << v[i][k] << " ";
		std::cout << std::endl;
	}
}
int main(){
	Komande komanda; Smjerovi smjer; Tabla polja; KodoviGresaka greska;
	int x(0), y(0), p_x(0), p_y(0);
	try{
		for(;;){
			std::cout << "Unesite komandu: ";
			if(UnosKomande(komanda, smjer, p_x,p_y,greska)){
				IzvrsiKomandu(komanda, polja, x, y, smjer, p_x, p_y);
			}
			else{
				PrijaviGresku(greska);
			}
		}
	}catch(std::runtime_error err){
		//std::cout << err.what();
		std::cout << "Dovidjenja!";
	}
	return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <cmath>

using std::vector;
using std::string;

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
	PogresnaKomanda, NedostajeParmetar, NeispravanParametar, SuvisanParametar
};
enum class Komande {
	PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};

typedef vector<vector<Polje>> Tabla;

//Global Var
int s_praznihPolja = 0;
//Oke
void ClearTable(Tabla &polja){
	for(vector<Polje> &red : polja)
		for(Polje &p : red)
			p = Polje::Prazno;
}
//Oke
Tabla KreirajIgru(int n, const vector<vector<int>> &mine){
	//Throw domain_error
	if(n <= 0)
		throw std::domain_error("Ilegalna velicina");

	//Postavi tablu na Prazno
	Tabla newTable(n);
	
	for(vector<Polje> &v : newTable){
		v.resize(n);
		for(Polje &p : v){
			p = Polje::Prazno;
		}
	}
	
	//Postavi mine
	for(vector<int> mina : mine){
		//Moraju biti tacno dvije koord mine
		if(mina.size() != 2)
			throw std::domain_error("Ilegalan format zadavanja mina");
		
		//Koordinate moraju biti unutar table
		if( (mina[0] < 0 || mina[0] >= n) || (mina[1] < 0 || mina[1] >= n) )
			throw std::domain_error("Ilegalne pozicije mina");
		
		//Postavi minu, mozda ne valjaju koord
		newTable[mina[0]][mina[1]] = Polje::Mina;
	}
	
	//Mozda treba -1, zbog pozicije na koju se igrac postavi!
	s_praznihPolja = n*n - mine.size();
	
	return newTable;
}
//Oke
int GetFieldSum(const Tabla &polja, int n, int x, int y){
	int sum = 0;
	
	for(int i = -1; i <= 1; i++){
		for(int j = -1; j <= 1; j++){
			//Ne gledaj trenutni element
			if(i != 0 || j != 0){
				//Ako je polja u tabli
				if(x + j >= 0 && x + j < n && y + i >= 0 && y + i < n){
					//Te ako je mina, prebroj ga
					if(polja[y+i][x+j] == Polje::Mina){
						sum++;
					}
				}
			}
		}
	}
	
	return sum;
}
//Oke
vector<vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	vector<vector<int>> okolina(3, vector<int>(3));
	int n = polja.size();
	
	//Mozda treba zamijeniti x i y u ispisu
	if(x < 0 || x >= n || y < 0 || y >= n)
		throw std::domain_error("Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji");
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			okolina[i][j] = GetFieldSum(polja, polja.size(), x+j-1, y+i-1);
		}
	}
	
	return okolina;
}
//Oke
void BlokirajPolje(Tabla &polja, int x, int y){
	int n = polja.size();
	if(x < 0 || x >= n || y < 0 || y >= n)
		throw std::domain_error("Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji");
	
	switch(polja[x][y]){
		case Polje::Prazno:
			polja[x][y] = Polje::BlokiranoPrazno;
			s_praznihPolja--;
			break;
		case Polje::Posjeceno:
			polja[x][y] = Polje::BlokiranoPosjeceno;
			break;
		case Polje::Mina:
			polja[x][y] = Polje::BlokiranoMina;
			break;
		default:
			break;
	}
}
//Oke
void DeblokirajPolje(Tabla &polja, int x, int y){
	int n = polja.size();
	if(x < 0 || x >= n || y < 0 || y >= n)
		throw std::domain_error("Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji");
	
	switch(polja[x][y]){
		case Polje::BlokiranoPrazno:
			polja[x][y] = Polje::Prazno;
			s_praznihPolja++;
			break;
		case Polje::BlokiranoPosjeceno:
			polja[x][y] = Polje::Posjeceno;
			break;
		case Polje::BlokiranoMina:
			polja[x][y] = Polje::Mina;
			break;
		default:
			break;
	}
}
//Oke, valjda
Status Idi(Tabla &polja, int &y, int &x, Smjerovi smjer){
	int n = polja.size();
	
	double pi = 4 * std::atan(1);
	int dx = std::round(std::sin(-int(smjer) * pi/4 - pi/2 - pi/4));
	int dy = std::round(std::cos(-int(smjer) * pi/4 - pi/2 - pi/4));
	
	if(x+dx < 0 || x+dx >= n || y+dy < 0 || y+dy >= n)
		throw std::out_of_range("Izlazak van igrace table");
	
	//Provjeri jel' polje blokirano
	if(polja[y+dy][x+dx] == Polje::BlokiranoPosjeceno || polja[y+dy][x+dx] == Polje::BlokiranoPrazno || polja[y+dy][x+dx] == Polje::BlokiranoMina)
		throw std::logic_error("Blokirano polje");
	
	//Oznaci polje kao posjeceno
	polja[y][x] = Polje::Posjeceno;
	s_praznihPolja--;
	
	//Pomjeri igraca
	x += dx;
	y += dy;
	
	//Provjeri jel' mina
	if(polja[y][x] == Polje::Mina){
		//Ocisti tablu
		ClearTable(polja);
		
		return Status::KrajPoraz;
	}
	
	if(s_praznihPolja == 0)
		return Status::KrajPobjeda;
	
	
	return Status::NijeKraj;
}
//Oke, valjda
Status Idi(Tabla &polja, int &y, int &x, int novi_y, int novi_x){
	int n = polja.size();
	
	if(novi_x < 0 || novi_x >= n || novi_y < 0 || novi_y >= n)
		throw std::out_of_range("Izlazak van igrace table");
	
	//Provjeri jel' polje blokirano
	if(polja[novi_y][novi_x] == Polje::BlokiranoPosjeceno || polja[novi_y][novi_x] == Polje::BlokiranoPrazno || polja[novi_y][novi_x] == Polje::BlokiranoMina)
		throw std::logic_error("Blokirano polje");
	
	//Oznaci polje kao posjeceno
	polja[y][x] = Polje::Posjeceno;
	s_praznihPolja--;
	
	//Pomjeri igraca
	x = novi_x;
	y = novi_y;
	
	//Provjeri jel' mina
	if(polja[y][x] == Polje::Mina){
		//Ocisti tablu
		ClearTable(polja);
		return Status::KrajPoraz;
	}
	
	if(s_praznihPolja == 0)
		return Status::KrajPobjeda;
	
	
	return Status::NijeKraj;
}
//Oke
void PrijaviGresku(KodoviGresaka kod){
	const char* msgs[4]{
		"Nerazumljiva komanda!",
		"Komanda trazi parametar koji nije naveden!",
		"Parametar komande nije ispravan!",
		"Zadan je suvisan parametar nakon komande!"
	};
	
	for(int i = 0; i < 4; i++){
		if(int(kod) == i){
			std::cout << msgs[i];
			break;
		}
	}
}

bool CheckExcessParams(){
    char next;

	//Ako ima razmaka ili tabova, ukloni ih
	while(next = std::cin.peek(), next == ' ' || next == '\t')
		std::cin.get();
	
	if(std::cin.peek() == '\n'){
		std::cin.get();
		return false;
	}
    
    std::cin.ignore(1024, '\n');
    return true;
}
//Oke
bool InputCoord(int &x, int y, KodoviGresaka &greska){
	int tempx, tempy;
	string cmd;
	char next;
	
	//Unesi koord
	std::cin >> tempx;
	if(next = std::cin.peek(), next != '\n' && next != '\t' && next != ' '){
		greska = KodoviGresaka::NeispravanParametar;
		return false;
	}
	//Ako nije int, neispravan parametar
	if(!std::cin){
		greska = KodoviGresaka::NeispravanParametar;
		std::cin.clear();
		
		std::cin >> cmd;
		//Jel' manjak parametar ili je neispravan?
		if(cmd == "K" || cmd == "Z" || cmd == "PO" || cmd == "B" || cmd == "D" || cmd == "P1" || cmd == "P>")
			greska = KodoviGresaka::NedostajeParmetar;
		
		return false;
	}
	//Unesi koord y
	std::cin >> tempy;
	
	if(next = std::cin.peek(), next != '\n' && next != '\t' && next != ' '){
		greska = KodoviGresaka::NeispravanParametar;
		return false;
	}
	//Ako nije int, neispravan parametar
	if(!std::cin){
		greska = KodoviGresaka::NeispravanParametar;
		std::cin.clear();
		
		std::cin >> cmd;
		//Jel' manjak parametar ili je neispravan?
		if(cmd == "K" || cmd == "Z" || cmd == "PO" || cmd == "B" || cmd == "D" || cmd == "P1" || cmd == "P>")
			greska = KodoviGresaka::NedostajeParmetar;
		
		return false;
	}
	
	if(CheckExcessParams()){
		greska = KodoviGresaka::SuvisanParametar;
		return false;
	}
	
	x = tempx;
	y = tempy;
	return true;
}
//Oke
bool InputDir(Smjerovi &smjer, KodoviGresaka &greska){
	string dir; 
	Smjerovi sm;
	bool input = false;
	const char* possibleDirs[]{
		"GL", "G", "GD", "D", "DoD", "Do", "DoL", "L"
	};
	
	std::cin >> dir;
	
	for(int i = 0; i < 8; i++){
		if(dir == possibleDirs[i]){
			input = true;
			sm = Smjerovi(i);
			break;
		}
	}
	if(!input){
		greska = KodoviGresaka::NeispravanParametar;
		
		//Jel' manjak parametar ili je neispravan?
		if(dir == "K" || dir == "Z" || dir == "PO" || dir == "B" || dir == "D" || dir == "P1" || dir == "P>")
			greska = KodoviGresaka::NedostajeParmetar;
		
		return false;
	}
	
	if(CheckExcessParams()){
		greska = KodoviGresaka::SuvisanParametar;
		return false;
	}
	
	smjer = sm;
	
	return true;
}
//Oke
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	string cmd;
	bool input;
	
	//Unos komande
	std::cin >> cmd;
	
	//Bezparametarske komande
	if(cmd == "PO" || cmd == "K" || cmd == "Z"){
		if(CheckExcessParams()){
			greska = KodoviGresaka::SuvisanParametar;
			return false;
		}
		if(cmd == "PO")
			komanda = Komande::PrikaziOkolinu;
		else if(cmd == "K")
			komanda = Komande::KreirajIgru;
		else
			komanda = Komande::ZavrsiIgru;
	}
	//Koordinatne komande
	else if(cmd == "P>" || cmd == "B" || cmd == "D"){
		input = InputCoord(x, y, greska);
		if(!input)
			return false;
		
		if(cmd == "P>")
			komanda = Komande::PomjeriDalje;
		else if(cmd == "B")
			komanda = Komande::Blokiraj;
		else
			komanda = Komande::Deblokiraj;
	}else if(cmd == "P1"){
		input = InputDir(smjer, greska);
		if(!input)
			return false;
		
		komanda = Komande::PomjeriJednoMjesto;
	}else{
		greska = KodoviGresaka::PogresnaKomanda;
		std::cin.ignore();
		return false;
	}
	
	return true;
}

bool InputInt(int &broj){
	int temp;
	std::cin >> temp;
	
	if(!std::cin){
		std::cin.clear();
		std::cin.ignore(1024, '\n');
		std::cout << "Greska, unesite ponovo!\n";
		return false;
	}
	
	char next;
	if(next = std::cin.peek(), next != '\n' && next != '\t' && next != ' ' && next != ',' && next != ')'){
		std::cin.ignore(1024, '\n');
		std::cout << "Greska, unesite ponovo!\n";
		return false;
	}
	
	broj = temp;
	return true;
}

bool CharBroj(char c){
	return c >= '0' && c <= '9';
}

bool UnosMina(int n, vector<vector<int>> &mine){
	int x, y;
	char c;
	
	std::cin >> c;
	
	if(c == '.')
		return true;
	
	if(c != '('){
		std::cout << "Greska, unesite ponovo!\n";
		std::cin.ignore(1024, '\n');
		return false;
	}
	
	bool intOk = InputInt(x);
	if(intOk){
		if(x >= n){
			std::cout << "Greska, unesite ponovo!\n";
			std::cin.ignore(1024, '\n');
			return false;
		}
	}else{
		std::cout << "Greska, unesite ponovo!\n";
		std::cin.ignore(1024, '\n');
		return false;
	}
		
	std::cin >> c;
	if(c != ','){
		std::cout << "Greska, unesite ponovo!\n";
		std::cin.ignore(1024, '\n');
		return false;
	}
	
	intOk = InputInt(y);
	if(intOk){
		if(y >= n){
			std::cout << "Greska, unesite ponovo!\n";
			std::cin.ignore(1024, '\n');
			return false;
		}
	}else {
		std::cout << "Greska, unesite ponovo!\n";
		std::cin.ignore(1024, '\n');
		return false;
	}
		
	std::cin >> c;
	if(c != ')'){
		std::cout << "Greska, unesite ponovo!\n";
		std::cin.ignore(1024, '\n');
		return false;
	}
	
	mine.push_back({x, y});
	return false;
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0){
	try{
		if(komanda == Komande::KreirajIgru){
			int n;
			std::cout << "Unesite broj polja: ";
			while(!InputInt(n));
			
			std::cout << "Unesite pozicije mina: ";
			vector<vector<int>> mine;
			while(!UnosMina(n, mine));
			
			polja = KreirajIgru(n, mine);
		}
		else if(komanda == Komande::Blokiraj)
			BlokirajPolje(polja, x, y);
		else if(komanda == Komande::Deblokiraj)
			DeblokirajPolje(polja, x, y);
		else if(komanda == Komande::PrikaziOkolinu){
			auto okolina = PrikaziOkolinu(polja, x, y);
			for(vector<int> red : okolina){
				for(int i : red)
					std::cout << i << " ";
				std::cout << std::endl;
			}
		}
	}catch(std::exception &err){
		std::cout << err.what() << std::endl;
		return;
	}
	
	if(komanda == Komande::PomjeriJednoMjesto){
		Status state;
		try{
			state = Idi(polja, x, y, p_smjer);
		}catch(std::exception &err){
			std::cout << err.what() << std::endl;
			return;
		}
		if(state == Status::KrajPobjeda){
			std::cout << "Bravo, obisli ste sva sigurna polja";
			ClearTable(polja);
			throw std::runtime_error("Igra zavrsena");
		}else if(state == Status::KrajPoraz){
			std::cout << "Nagazili ste na minu";
			ClearTable(polja);
			throw std::runtime_error("Igra zavrsena");
		}
		std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")\n";
	}
	else if(komanda == Komande::PomjeriDalje){
		Status state;
		try{
			state = Idi(polja, x, y, p_x, p_y);
		}catch(std::exception &err){
			std::cout << err.what() << std::endl;
			return;
		}
		if(state == Status::KrajPobjeda){
			std::cout << "Bravo, obisli ste sva sigurna polja";
			ClearTable(polja);
			throw std::runtime_error("Igra zavrsena");
		}else if(state == Status::KrajPoraz){
			std::cout << "Nagazili ste na minu";
			ClearTable(polja);
			throw std::runtime_error("Igra zavrsena");
		}
		std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")\n";
	}
	else if(komanda == Komande::ZavrsiIgru){
		ClearTable(polja);
		throw std::runtime_error("Igra zavrsena");
	}
}

int main () {
	Tabla tabla{};
	Komande komanda;
	KodoviGresaka greska;
	int x = 0, y = 0, nx = 0, ny = 0;
	Smjerovi smjer;
	bool input;
	
	while(true){
		try{
			std::cout << "Unesite komandu: ";
			input = UnosKomande(komanda, smjer, nx, ny, greska);
			if(input){
				if(komanda != Komande::PomjeriDalje){
					if(komanda == Komande::Blokiraj || komanda == Komande::Deblokiraj)
						IzvrsiKomandu(komanda, tabla, nx, ny, smjer);
					else
						IzvrsiKomandu(komanda, tabla, x, y, smjer);
				}else
					IzvrsiKomandu(komanda, tabla, x, y, smjer, nx, ny);
				
			}
			else{
				PrijaviGresku(greska);
				std::cout << std::endl;
			}
		}catch(std::runtime_error err){
			//std::cout << err.what();
			std::cout << "Dovidjenja!";
			break;
		}
	}
	
	return 0;
}
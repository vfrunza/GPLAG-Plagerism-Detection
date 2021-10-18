#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <complex>

//Enumeracije
enum class Polje {Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina};

enum class Smjerovi {GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo};

enum class Status {NijeKraj, KrajPoraz, KrajPobjeda};

enum class KodoviGresaka{PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar};

enum class Komande{PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru};

typedef std::vector<std::vector<Polje>> Tabla;

//Funkcije
bool TestSlobode  (Tabla polja){
	for (int i = 0; i < polja.size(); i++) { 
		for (int j = 0; j < polja[i].size(); j++) {
			if (static_cast<int>(polja[i][j]) == 0 || static_cast<int>(polja[i][j]) == 3 || static_cast<int>(polja[i][j]) == 4) return false;
		}
	}
	return true;
}

Tabla KreirajIgru (int n, const std::vector<std::vector<int>> &mine){
	Tabla trenutnaTabla;
	
	trenutnaTabla.resize(n); //Namjesta velicinu redova
	for (int i = 0; i < n; i++) {
		trenutnaTabla[i].resize(n);
	} //Namjesta velicinu kolona
	
	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < n; j++) {
			trenutnaTabla[i][j] = Polje(0);
		}
	}//inicijalizira tablu sa inicijaliziranim vrijednostima 0
	for (int i = 0; i < mine.size(); i++) {
		if (mine[i].size() != 2) {
			throw std::domain_error ("Ilegalan format zadavanja mina");
		}
		else{
			int HorPozicijaMine (mine[i][0]), VerPozicijaMine(mine[i][1]);
			
			if (HorPozicijaMine >= n || VerPozicijaMine >= n) {
				throw std::domain_error ("Ilegalne pozicije mina");
			}
			else{
				trenutnaTabla[HorPozicijaMine][VerPozicijaMine] = Polje(2);
			}
		} 
	} //Postavlja mine

	return trenutnaTabla;
}

std::vector<std::vector<int>> PrikaziOkolinu (const Tabla &polja, int x, int y){

	if (!((x >= 0 && x < polja.size()) && (y >= 0 && y < polja[0].size()))) throw std::domain_error ("Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji"); // Baca izuzetak
	
	
	std::vector<std::vector<int>> Okolina(3, std::vector<int>(3,0));
	int o(0);
	for (int i = x-1; i <= x+1; i++) {
		int p(0);
		for (int j = y-1; j <= y+1; j++) { //Ove dvije petlje dobiju glavnu okolinu
			int brojac(0);
			
			for (int k = i-1; k <= i+1; k++) for (int l = j-1; l <= j+1; l++) if (k >= 0 && k < polja.size() && l >= 0 && l < polja[0].size() && (int)polja[k][l] == 2 && !(k == i && l == j)) brojac++; //PEtlje za podokoline
			
			Okolina[o][p++]=brojac;
		}
		o++;
	}

	return Okolina;
}

void BlokirajPolje(Tabla &polja, int x, int y){
	if (x < 0 || x >= polja.size() || y < 0 || y >= polja[0].size()) {
		throw std::domain_error ("Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji");
	}
	
	if (static_cast<int>(polja[x][y]) >= 3 && static_cast<int>(polja[x][y]) <= 5) return;
	
	else if (static_cast<int>(polja[x][y]) >= 0 && static_cast<int>(polja[x][y]) <= 2) {
		polja[x][y] = Polje(static_cast<int>(static_cast<int>(polja[x][y]) + 3));
	}
	
	
}

void DeblokirajPolje(Tabla &polja, int x, int y){
	if (x < 0 || x >= polja.size() || y < 0 || y >= polja[0].size()) {
		throw std::domain_error ("Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji");
	}
	
	if (static_cast<int>(polja[x][y]) >= 0 && static_cast<int>(polja[x][y]) <= 2) return;
	
	else if (static_cast<int>(polja[x][y]) >= 3 && static_cast<int>(polja[x][y]) <= 5) {
		polja[x][y] = Polje(static_cast<int>(static_cast<int>(polja[x][y]) - 3));
	}
	
	
}


Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	static int pocetniX(0), pocetniY(0); int o(0), p(0);
	
	if (smjer == Smjerovi::Gore){ o = -1; p = 0;}
	else if (smjer == Smjerovi::GoreLijevo){ o = -1; p = -1;}
	else if (smjer == Smjerovi::GoreDesno){ o = -1; p = 1;}
	else if (smjer == Smjerovi::Desno){ o = 0; p = 1;}
	else if (smjer == Smjerovi::DoljeDesno){ o = 1; p = 1;}
	else if (smjer == Smjerovi::Dolje){ o = 1; p = 0;}
	else if (smjer == Smjerovi::DoljeLijevo){ o = 1; p = -1;}
	else if (smjer == Smjerovi::Lijevo){ o = 0; p = -1;}
	
	 //Ako je izasao iz tablice
	if ((pocetniX + o < 0 || pocetniX + o >= polja.size()) || (pocetniY + p < 0) || (pocetniY+p) >= polja[0].size()) throw std::out_of_range ("Izlazak van igrace table");
		
	//Ako blokriano polje
	else if(static_cast<int>(polja[pocetniX+o][pocetniY+p])>= 3 && static_cast<int>(polja[pocetniX+o][pocetniY+p])<= 5)	throw std::logic_error ("Blokirano polje");
		
	//ako stane na minu
	else if(polja[pocetniX+o][pocetniY+p] == Polje::Mina){
		for (int i = 0; i < polja.size(); i++) { 
			for (int j = 0; j < polja[0].size(); j++) {
				polja[i][j] = Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
	//dodati test slobode
	else{
		polja[pocetniX][pocetniY]=Polje(1);
		
		pocetniX = pocetniX+o;
		pocetniY = pocetniY+p;
		x = pocetniX;
		y = pocetniY;
	}
	
	Tabla kopija = polja;
	kopija [pocetniX][pocetniY] = Polje(1);
	if (TestSlobode(kopija)){
		return Status::KrajPobjeda;
	}
		
	
	
	
	return Status::NijeKraj;
} //Works

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	static int prosliX(novi_x),  prosliY(novi_y);
	
	if (x < 0 || x >= polja.size() || y< 0 || y >= polja[0].size()) {
		throw std::out_of_range ("Izlazak van igrace table");
	}
	
	else if(static_cast<int>(polja[x][y])>= 3 && static_cast<int>(polja[x][y])<= 5){
			throw std::logic_error ("Blokirano polje");
	}
	else if (static_cast<int>(polja[x][y])== 2){
		//Sve vratiti na prazno
		for (int i = 0; i < polja.size(); i++) { 
			for (int j = 0; j < polja[0].size(); j++) {
				polja[i][j] = Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
	
	else {
		polja[prosliX][prosliY]=Polje(1);
	
		prosliX = x;
		prosliY = y;
		x = novi_x;
		y = novi_y;
	}
	
	Tabla kopija = polja;
	kopija [x][y] = Polje(1);
	if (TestSlobode(kopija)){
		return Status::KrajPobjeda;
	}
	
	return Status::NijeKraj;
} //Works like a charm :D

void PrijaviGresku (KodoviGresaka x){
	if (static_cast<int> (x) == 0) std::cout << "Nerazumljiva komanda!" << std::endl;
	else if (static_cast<int> (x) == 1) std::cout << "Komanda trazi parametar koji nije naveden!" << std::endl;
	else if (static_cast<int> (x) == 3) std::cout << "Parametar komande nije ispravan!"<< std::endl;
	else if (static_cast<int> (x) == 2) std::cout << "Zadan je suvisan parametar nakon komande!" << std::endl;
} //Works

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	std::string input;

	getline(std::cin, input);
	//var za pelju
	int i(0), o(0);
	bool bioRazmak(true);
	std::vector<int> brojaci(2,0);
	
	while (i < input.length()) {
		if (input[i] == ' ' || input[i] == '\n' || input[i] == '\t') {
			input = input.substr(0, i) + input.substr(i+1, (input.length()-i));
			if (!bioRazmak) o++;
			
			bioRazmak = true;
			continue;
		}
		else if (input[i] >= '0' && input[i] <= '9' && o < 2 && !bioRazmak) brojaci[o]++;
		
		else if (input[i] >= '0' && input[i] <= '9' && o < 2 && bioRazmak) {
			bioRazmak = false;
			brojaci[o]++;
		}
		
		i++;
	} //RADI
	
	if (input.substr(0,2) == "PO") {
		if (input.length() == 2){
			komanda = Komande::PrikaziOkolinu;
			return true;
			//Komanda je uredu
		}
		else if (input.length()>2) {
			//Suvisan parametar
			greska = KodoviGresaka::SuvisanParametar;
			return false;
		}
	} // RADI
	
	else if (input.substr(0,1) == "Z") {
		if (input.length() == 1){
			komanda = Komande::ZavrsiIgru;
			return true;
			//Komanda je uredu
		}
		else if (input.length()>1) {
			//Suvisan parametar
			greska = KodoviGresaka::SuvisanParametar;
			return false;
		}
	} //RADI
	
	else if (input.substr(0,1) == "K") {
		if (input.length() == 1){
			komanda = Komande::KreirajIgru;
			return true;
			//Komanda je uredu
		}
		else if (input.length()>1) {
			//Suvisan parametar
			greska = KodoviGresaka::SuvisanParametar;
			return false;
		}
	} //RADI
	
	else if (input.substr(0,2) == "P1"){
		if (input.length() < 3){
			greska = KodoviGresaka::NedostajeParametar;
			return false;
		}
		else if (input.length() == 3){
			if (input.substr(2,3) == "G") {
				smjer = Smjerovi::Gore;
				komanda = Komande::PomjeriJednoMjesto;
				return true;
			}
			else if (input.substr(2,3) == "L") {
				smjer = Smjerovi::Lijevo;
				komanda = Komande::PomjeriJednoMjesto;
				return true;
			}
			else if (input.substr(2,3) == "D") {
				smjer = Smjerovi::Desno;
				komanda = Komande::PomjeriJednoMjesto;
				return true;
			}
			else{
				greska = KodoviGresaka::NeispravanParametar;
				return false;
			}
		}
		else if (input.length() == 4){
			if (input.substr(2,4) == "GL") {
				komanda = Komande::PomjeriJednoMjesto;
				smjer = Smjerovi::GoreLijevo;
				return true;
			}
			else if (input.substr(2,4) == "GD") {
				smjer = Smjerovi::GoreDesno;
				komanda = Komande::PomjeriJednoMjesto;
				return true;
			}
			else if (input.substr(2,4) == "Do") {
				smjer = Smjerovi::Dolje;
				komanda = Komande::PomjeriJednoMjesto;
				return true;
			}
			else{
				greska = KodoviGresaka::NeispravanParametar;
				return false;
			}
		}
		else if (input.length() == 5){
			if (input.substr(2,5) == "DoL") {
				smjer = Smjerovi::DoljeLijevo;
				komanda = Komande::PomjeriJednoMjesto;
				return true;
			}
			else if (input.substr(2,5) == "DoD") {
				smjer = Smjerovi::DoljeDesno;
				komanda = Komande::PomjeriJednoMjesto;
				return true;
			}
			else{
				greska = KodoviGresaka::NeispravanParametar;
				return false;
			}
		}
		else if (input.length() > 5){
			greska = KodoviGresaka::NeispravanParametar;
			return false;
		}
	} //Radi
	
	else if (input.substr(0,2) == "P>"){
		if (input.length() == 2) {
			greska = KodoviGresaka::NedostajeParametar;
			return false;
		}
		else if (input.length() == (2+brojaci[0]+brojaci[1])){
			x = std::stoi(input.substr(2, brojaci[0]));
			y = std::stoi(input.substr(2+brojaci[0], brojaci[1]));
			komanda = Komande::PomjeriDalje;
			return true;
		}
		else{
			greska = KodoviGresaka::NeispravanParametar;
			return false;
		}
	} //RADI
	
	else if (input.substr(0,1) == "B" || input.substr(0,1) == "D"){
		if (input.length() == 1) {
			greska = KodoviGresaka::NedostajeParametar;
			return false;
		}
		else if (input.length() == (1+brojaci[0]+brojaci[1])){
	
			x = std::stoi(input.substr(1, brojaci[0]));
			y = std::stoi(input.substr(1+brojaci[0], brojaci[1]));
			if (input.substr(0,1) == "B") {
				komanda = Komande::Blokiraj;
			}
			else if (input.substr(0,1) == "D"){
				komanda = Komande::Deblokiraj;
			}
			
			return true;
		}
		else{
			greska = KodoviGresaka::NeispravanParametar;
			return false;
		}
	} //RADI
	else {
		greska = KodoviGresaka::PogresnaKomanda;
		return false;
	}
	
	return true;
} //Radi

void IzvrsiKomandu (Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y=0){
	int kopijaX=x, kopijaY=y;
	
	if (komanda == Komande::PomjeriJednoMjesto || komanda == Komande::PomjeriDalje) {
		Status staJeBilo(Status::NijeKraj);
		if (komanda == Komande::PomjeriJednoMjesto) {
			staJeBilo = Idi(polja, x, y, p_smjer);
		}
		else if (komanda == Komande::PomjeriDalje) {
			staJeBilo = Idi(polja, x, y, p_x, p_y);
		} // RADI
		
		if (staJeBilo == Status::KrajPoraz) {
			std::cout << "Nagazili ste na minu" << std::endl;
			throw std::runtime_error ("Igra zavrsena");
		}
		else if (staJeBilo == Status::KrajPobjeda) {
			std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
			throw std::runtime_error ("Igra zavrsena");
		}
		else if (komanda == Komande::PomjeriJednoMjesto){
			std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")" << std::endl;
		}
		else if (komanda == Komande::PomjeriDalje){
			std::cout << "Tekuca pozicija igraca je (" << kopijaX << "," << kopijaY << ")" << std::endl;
		}
		
	} // OSTALO ZA URADITI
	
	else if (komanda == Komande::ZavrsiIgru) {
		for (int i = 0; i < polja.size(); i++) { 
			for (int j = 0; j < polja.size(); j++) {
				polja[i][j] = Polje(0);
			}
		}
		
		throw std::runtime_error ("Igra zavrsena");
		
	} //Radi
	
	else if (komanda == Komande::PrikaziOkolinu) {
		std::vector<std::vector<int>> Okolina = PrikaziOkolinu(polja, x, y);
		
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				std::cout << Okolina[i][j] << " ";
			}
			std::cout << std::endl;
		}
		
	} //Radi
	
	else if (komanda == Komande::Deblokiraj) {
		DeblokirajPolje(polja, x, y);
	} //Radi
	
	else if (komanda == Komande::Blokiraj) {
		BlokirajPolje(polja, x, y);
	} //Radi
	
	else if (komanda == Komande::KreirajIgru) {
		int n;
		std::cout << "Unesite broj polja: ";
		std::cin >> n;
		
		std::cin.ignore(10000, '\n');
		
		
		std::cout << "Unesite pozicije mina: ";
	
	std::vector<std::vector<int>> mine;
	std::complex<int> z;
	int i(0);
	
	bool izasaoSaTackom(false);
	
	if((std::cin >> std::ws).peek()=='.') {
		izasaoSaTackom = true;
	}
	

	
	while(!izasaoSaTackom){
	
        while (std::cin >> z) {
            mine.resize(i+1);
            if (z.real() < 0 || z.real() >= n || z.imag() < 0 || z.imag() >= n) break;
            
            mine[i].push_back(z.real());
            mine[i].push_back(z.imag());
            i++;
            if((std::cin >> std::ws).peek()=='.'){ izasaoSaTackom = true;break;}
        }
        
        if (!izasaoSaTackom) {
            std::cout << "Greska, unesite ponovo!" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
         }
	}
		std::cin.ignore(10000, '\n');
		polja = KreirajIgru(n, mine);
	} //OVO OSTALO ZA URADITI

}


int main (){
	 int x = 0, y = 0;
    std::vector<std::vector<int>> mine = {{0,2}, {1,0}, {1,1}, {1,2}, {2,0}, {2,1}, {2,2}};
    std::vector<std::vector<Polje>> tabla = KreirajIgru(3, mine);
   try{
     Idi(tabla, x, y, x-1, y);
   }
   catch(std::out_of_range e){
     std::cout << e.what() << std::endl;
   }
   BlokirajPolje(tabla, 0, 1);
   try{
     Idi(tabla, x, y, x, y+1);
   }
   catch(std::logic_error e){
     std::cout << e.what() << std::endl;
   }
	/*
	Komande komanda;
	Smjerovi smjer = Smjerovi::Gore; 
	int x=1, y=0;
	KodoviGresaka greska;
	Tabla polja;
	
	int p_x=0, p_y=0;
	
	
	for(;;){
		std::cout << "Unesite komandu: ";
		if (UnosKomande(komanda, smjer, x, y, greska)) {
			try{
				IzvrsiKomandu( komanda, polja, x, y, smjer, p_x, p_y);
				std::cout << "Tabla izgleda ovako" << std::endl;
				for (int i = 0; i < 5; i++) {
					for (int j = 0; j < 5; j++) {
						std::cout << int(polja[i][j]) << " ";
					}
					std::cout << std::endl;
				}
				
			}
			catch(std::domain_error e){
				std::cout << e.what() << std::endl;
			}
			catch(std::out_of_range e){
				std::cout << e.what() << std::endl;
			}
			catch(std::runtime_error e){
				
				std::cout << "Dovidjenja!" << std::endl;
				return 0;
			}
			catch(std::logic_error e){
				std::cout << e.what() << std::endl;
			}
		}
		else{
			PrijaviGresku(greska);
		}
		
	}
	*/
	return 0;
}
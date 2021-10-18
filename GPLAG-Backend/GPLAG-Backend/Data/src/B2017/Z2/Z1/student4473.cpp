#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <algorithm>
#include <complex>


enum class Polje {
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};

enum class Smjerovi{
	GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};

enum class Status {
	NijeKraj, KrajPoraz, KrajPobjeda
};

enum class KodoviGresaka{
	PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};

enum class Komande {
	PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};


typedef std::vector<std::vector<Polje>> Tabla;
typedef std::vector<std::vector<int>> Matrica;

std::string broj2string (int broj){
	if(broj == 0) return "0";
	std::string pretvoreni ="";
	bool minus = false;
	if(broj < 0)minus = true;
	while(broj){
		pretvoreni +=(broj% 10)+ '0';
		broj /= 10;
		
	}
	if (minus) pretvoreni += "-";
	reverse(std::begin(pretvoreni), std::end(pretvoreni));
	
	return pretvoreni;
}

Tabla KreirajIgru (int n, const std::vector<std::vector<int>> &mine){
	if(mine.size() <= 0 || mine[0].size() <=0) throw std::domain_error ("Ilegalna velicina");
	
	Tabla matrica_tabla(n, std::vector<Polje>(n, Polje::Prazno)) ;
	
	for(int i = 0; i < mine.size(); i++){
		for(int j = 0; j < mine[i].size(); j++){
			if(mine[i].size() != 2) throw std::domain_error ("Ilegalan format zadavanja mina");
			if(mine[i][j] > n || mine[i][j] < 0) throw std::domain_error ("Ilegalne pozicije mina");
		}
		int koordinata_1 = mine[i][0];
		int koordinata_2 = mine[i][1];
		matrica_tabla[koordinata_1][koordinata_2] = Polje::Mina;
	}
	
	//std::vector<std::vector<int>> pretvorena = Pretvori(matrica_tabla);
	return matrica_tabla;
}
bool ValidnaKoordinata(int x, int y, int velicina){
	bool validna = true;
	if(x < 0 || x > velicina - 1 || y < 0 || y > velicina - 1) validna =false;
	
	return validna;
	
}
Matrica PrikaziOkolinu (const Tabla &polja, int x, int y){
	Matrica matrica (3);
	
	if(x > polja.size()- 1 || x < 0 || y > polja.size()- 1 || y < 0) throw std::domain_error ("Polje (" + (std::to_string(x)) + "," + (std::to_string(y)) +") ne postoji");
	int nizX[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
	int nizY[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
	
	for(int i = 0; i < polja.size() ;i++){
		for(int j = 0; j < polja.size(); j++){
			if(i == x && y == j){
				for(int d = 0; d < 9; d++){
					int novo_x = x + nizX[d];
					int novo_y = y + nizY[d];
					int suma = 0;
					for(int k = 0; k < 9; k++){
					
						int pomocno_x = novo_x + nizX[k];
						int pomocno_y = novo_y + nizY[k];
						if(!ValidnaKoordinata(pomocno_x, pomocno_y, polja.size()))continue;
						if (novo_x == pomocno_x && novo_y == pomocno_y)continue;
					
						 else if(polja[pomocno_x][pomocno_y] == Polje::Mina)suma++;
						
						 
					}
				if(d < 3)matrica[0].push_back(suma);
				else if(d >=3 && d <= 5) matrica[1].push_back(suma);
				else matrica[2].push_back(suma);
				}
			}
		}
	}
	return matrica;
}

void BlokirajPolje (Tabla &polja, int x, int y){
	if(x > polja.size() - 1 || x < 0 || y > polja.size() -1 || y < 0) throw std::domain_error ("Polje (" + broj2string(x) + "," + broj2string(y) +") ne postoji");
	
	if(polja[x][y] == Polje::Prazno) polja[x][y] = Polje::BlokiranoPrazno;
	else if (polja[x][y] == Polje::Posjeceno) polja[x][y] = Polje::BlokiranoPosjeceno;
	else if (polja[x][y] == Polje::Mina) polja[x][y] = Polje::BlokiranoMina;	
}
void DeblokirajPolje(Tabla &polja, int x, int y){
	if(x > polja.size() - 1 || x < 0 || y > polja.size() - 1 || y < 0) throw std::domain_error ("Polje (" + broj2string(x) + ","+ broj2string(y) +") ne postoji");
	
	if(polja[x][y] == Polje::BlokiranoPrazno) polja[x][y] = Polje::Prazno;
	else if(polja[x][y] == Polje::BlokiranoPosjeceno)polja[x][y] = Polje::Posjeceno;
	else if (polja[x][y] == Polje::BlokiranoMina)polja[x][y] = Polje::Mina;
	
}

Status Idi (Tabla &polja, int &x, int &y, Smjerovi smjer){
	Status stanje;
	bool mina = false;
	if(smjer == Smjerovi::Gore){
		if(x - 1 < 0) throw std::out_of_range ("Izlazak van igrace table");
		else {
			polja[x][y] = Polje::Posjeceno;
			x = x - 1;
			if(polja[x][y] == Polje::Mina){mina = true; }
			else if(polja[x][y] == Polje::BlokiranoPosjeceno || polja[x][y] == Polje::BlokiranoPrazno || polja[x][y] == Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
			
		}
	}
	else if(smjer == Smjerovi::GoreDesno){
		if(x - 1 < 0 || y + 1 > polja.size()) throw std::out_of_range ("Izlazak van igrace table");
		else {
			polja[x][y] = Polje::Posjeceno;
			x = x - 1;
			y = y + 1;
			if(polja[x][y] == Polje::Mina){mina = true; }
			else if(polja[x][y] == Polje::BlokiranoPosjeceno || polja[x][y] == Polje::BlokiranoPrazno || polja[x][y] == Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		}
	}
	else if(smjer == Smjerovi::GoreLijevo){
		if(x - 1 < 0 || y - 1 < 0) throw std::out_of_range ("Izlazak van igrace table");
		else {
			polja[x][y] = Polje::Posjeceno;
			x = x - 1;
			y = y - 1;
			if(polja[x][y] == Polje::Mina){mina = true; }
			else if(polja[x][y] == Polje::BlokiranoPosjeceno || polja[x][y] == Polje::BlokiranoPrazno || polja[x][y] == Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		}
	}
	else if(smjer == Smjerovi::Dolje){
		if(x + 1 > polja.size() ) throw std::out_of_range ("Izlazak van igrace table");
		else {
			polja[x][y] = Polje::Posjeceno;
			x = x + 1;
			if(polja[x][y] == Polje::Mina){mina = true; }
			else if(polja[x][y] == Polje::BlokiranoPosjeceno || polja[x][y] == Polje::BlokiranoPrazno || polja[x][y] == Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		}
	}
	else if(smjer == Smjerovi::DoljeDesno){
		if(x + 1 > polja.size() || y + 1 > polja.size()) throw std::out_of_range ("Izlazak van igrace table");
		else {
			polja[x][y] = Polje::Posjeceno;
			x = x + 1;
			y = y + 1;
			if(polja[x][y] == Polje::Mina){mina = true; }
			else if(polja[x][y] == Polje::BlokiranoPosjeceno || polja[x][y] == Polje::BlokiranoPrazno || polja[x][y] == Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		}
	}
	else if(smjer == Smjerovi::DoljeLijevo){
		if(x - 1 < 0 || y - 1 < 0) throw std::out_of_range ("Izlazak van igrace table");
		else {
			polja[x][y] = Polje::Posjeceno;
			x = x + 1;
			y = y - 1;
			if(polja[x][y] == Polje::Mina){mina = true; }
			else if(polja[x][y] == Polje::BlokiranoPosjeceno || polja[x][y] == Polje::BlokiranoPrazno || polja[x][y] == Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		}
	}
	else if(smjer == Smjerovi::Desno){
		if( y + 1 > polja.size()) throw std::out_of_range ("Izlazak van igrace table");
		else {
			polja[x][y] = Polje::Posjeceno;
			y = y + 1;
			if(polja[x][y] == Polje::Mina){mina = true;}
			else if(polja[x][y] == Polje::BlokiranoPosjeceno || polja[x][y] == Polje::BlokiranoPrazno || polja[x][y] == Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		}
	}
	else if(smjer == Smjerovi::Lijevo){
		if(y - 1 < 0) throw std::out_of_range ("Izlazak van igrace table");
		else {
			polja[x][y] = Polje::Posjeceno;
			y = y - 1;
			if(polja[x][y] == Polje::Mina){mina = true; }
			else if(polja[x][y] == Polje::BlokiranoPosjeceno || polja[x][y] == Polje::BlokiranoPrazno || polja[x][y] == Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		}
	}
	bool kraj = true;
	
	if(mina){
		for(int i = 0; i < polja.size(); i++){
			for(int j = 0; j < polja.size(); j++){
				polja[i][j] = Polje::Prazno;
			}
		}
		return stanje = Status::KrajPoraz;
	}
	
	else {
		
		for(int i = 0; i < polja.size(); i++){
			for(int j = 0; j < polja.size(); j++){
				if(polja[i][j] == Polje::BlokiranoPosjeceno || polja[i][j] == Polje::BlokiranoMina || polja[i][j] == Polje::BlokiranoPrazno || polja[i][j] == Polje::Posjeceno)kraj =  true;
				else { kraj =false; break;}
			}
		}
	}
	if(kraj) return stanje = Status::KrajPobjeda;
	else return stanje = Status::NijeKraj;
	
}



Status Idi (Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	bool mina = false;
	if(novi_x > polja.size()-1 || novi_x < 0 || novi_y > polja.size()-1 || novi_y < 0) throw std::out_of_range ("Izlazak van igrace table");

	else {
		polja[x][y] = Polje::Posjeceno;
		x = novi_x;
		y = novi_y;
		if(polja[x][y] == Polje::Mina){mina = true; }
		else if(polja[x][y] == Polje::BlokiranoPosjeceno || polja[x][y] == Polje::BlokiranoPrazno || polja[x][y] == Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
	}
	bool kraj = true;
	Status stanje;
	if(mina){
		for(int i = 0; i < polja.size(); i++){
			for(int j = 0; j < polja.size(); j++){
				polja[i][j] = Polje::Prazno;
			}
		}
		return stanje = Status::KrajPoraz;
	}
	else{
		for(int i = 0; i < polja.size(); i++){
			for(int j = 0; j < polja.size(); j++){
				if(polja[i][j] == Polje::BlokiranoPosjeceno || polja[i][j] == Polje::BlokiranoMina || polja[i][j] == Polje::BlokiranoPrazno || polja[i][j] == Polje::Posjeceno)kraj =  true;
				else { kraj =false; break;}
			}
		}
	}
	if(kraj) return stanje = Status::KrajPobjeda;
	else return stanje = Status::NijeKraj;
}
void PrijaviGresku (KodoviGresaka greska){
	if(greska == KodoviGresaka:: PogresnaKomanda) std::cout << "Nerazumljiva komanda!" << std::endl;
	else if(greska == KodoviGresaka::NedostajeParametar) std::cout << "Komanda trazi parametar koji nije naveden!" << std::endl;
	else if(greska == KodoviGresaka::NeispravanParametar) std::cout << "Parametar komande nije ispravan!"<<std:: endl;
	else if(greska == KodoviGresaka::SuvisanParametar)std::cout << "Zadan je suvisan parametar nakon komande!" << std::endl;
}
bool Broj(char s){
	if(s == '1' || s == '2' || s =='3' || s == '4' || s == '5' || s =='6'|| s == '7' || s == '8' || s =='9'|| s =='0')return true;
	else return false;
}
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	
	std::string unos;
	//std::cin.clear();
	//std::cin.ignore(10000, '/n');
	std::getline(std::cin, unos);
	bool dobro_je = true;

	int i = 0;
	//	while(unos[i] == ' ')i++;
		 
		 if(unos[i] == 'P'){
		 	i++;
		 	if(unos[i] == '1'){
		 		i++;
		 		if(unos[i] == 'G'){
		 			i++;
		 			if(unos[i]==' ' || unos[i] == '/n'){
		 				komanda = Komande::PomjeriJednoMjesto;
		 				smjer = Smjerovi::Gore;
		 			}
		 			else if(unos[i]== 'L'){
		 				i++;
		 				if(unos[i]==' ' || unos[i]=='/n'){
		 				komanda = Komande::PomjeriJednoMjesto;
		 				smjer = Smjerovi::GoreLijevo;
		 			}
		 			}
		 			else if(unos[i] == 'D'){
		 				
		 			if(unos[i] ==' ' || unos[i]=='/n'){
		 				komanda = Komande::PomjeriJednoMjesto;
		 				smjer = Smjerovi::GoreLijevo;
		 			}
		 			}
		 			else {
		 				greska = KodoviGresaka::NeispravanParametar;
		 				dobro_je = false;
		 			}
		 		}
		 		else if(unos[i]== 'D'){
		 			i++;
		 			if(unos[i]== ' ' || unos[i]== '/n'){
		 				komanda = Komande::PomjeriJednoMjesto;
		 				smjer = Smjerovi::Desno;
		 			}
		 			else if (unos[i+3]== 'o'){
		 				if(unos[i+4]== ' '){
		 					komanda = Komande::PomjeriJednoMjesto;
		 					smjer = Smjerovi::Dolje;
		 				}
		 				else if(unos[i+4] == 'D'){
		 					komanda = Komande::PomjeriJednoMjesto;
		 					smjer = Smjerovi::DoljeDesno;
		 				}
		 				else if(unos[i+4] =='L'){
		 					komanda = Komande::PomjeriJednoMjesto;
		 					smjer = Smjerovi::DoljeLijevo;
		 				}
						else{
							greska = KodoviGresaka::NeispravanParametar;
							dobro_je = false;
						}
		 			}
		 		}
		 		else if(unos[i+2]=='L'){
		 			if(unos[i+3]==' ' || unos[i+3] =='/n'){
		 				komanda = Komande::PomjeriJednoMjesto;
		 				smjer = Smjerovi::Lijevo;
		 			}
		 			else{
		 				greska = KodoviGresaka::NeispravanParametar;
		 				dobro_je = false;
		 			}
		 		}
		 		else{
		 			greska = KodoviGresaka::NedostajeParametar;
		 			dobro_je = false;
		 		}
		 	}
		 	else if(unos[i + 1]== '>'){
		 		if(unos[i+2] == ' ' || Broj(unos[i+2])){
		 			if(Broj(unos[i+2])){
		 				if(unos[i+3]==' '&& Broj(unos[i+4])){
		 					komanda = Komande::PomjeriDalje;
		 					x = unos[i+2];
		 					y = unos[i+4];
		 				}
		 				else{
		 					greska = KodoviGresaka::NeispravanParametar;
		 					dobro_je = false;
		 				}
		 			}
		 			else{
		 				if(Broj(unos[i+3]) && (unos[i+4] ==' ' || unos[i+4]=='/n')){
		 					if(Broj(unos[i+5])){
		 						x = unos[i+3];
		 						y = unos[i+5];
		 					}
		 					else{
		 						greska = KodoviGresaka::NeispravanParametar;
		 						dobro_je = false;
		 					}
		 				}
		 				else{
		 					greska = KodoviGresaka::NeispravanParametar;
		 					dobro_je = false;
		 				}
		 			}
		 		}
		 	}
		 	else if(unos[i+1] =='O'){
		 		if(unos[i+2] == ' ' || unos[i+2] =='/n'){
		 			komanda = Komande::PrikaziOkolinu;
		 		}
		 		else{
		 			greska = KodoviGresaka::SuvisanParametar;	
		 			dobro_je = false;
		 		}
		 	}
		 	else {
		 		greska = KodoviGresaka::PogresnaKomanda;
		 		dobro_je = false;
		 	}
		 }
	 	else if(unos[i]== 'B'){
	 		if(unos[i+1] == ' ' || Broj(unos[i+1])){
	 			if(Broj(unos[i+1])){
	 				if(unos[i+2]==' '&& Broj(unos[i+3])){
	 					komanda = Komande::Blokiraj;
	 					x = unos[i+1];
	 					y = unos[i+3];
	 				}
	 				else{
	 					greska = KodoviGresaka::NeispravanParametar;	
	 					dobro_je = false;
	 					
	 				}
	 			}
	 			else{
	 				if(Broj(unos[i+2]) && (unos[i+3] ==' ' || unos[i+3] =='/n')){
	 					if(Broj(unos[i+4])){
	 						x = unos[i+2];
	 						y = unos[i+4];
	 					}
	 					else{
	 						greska = KodoviGresaka::NeispravanParametar;
	 						dobro_je = false;
	 					}
	 				}
	 				else{
	 					greska = KodoviGresaka::NeispravanParametar;
	 					dobro_je = false;
	 				}
	 			}
	 		}
	 	}
	 		else if(unos[i]== 'D'){
	 		if(unos[i+1] == ' ' || Broj(unos[i+1])){
	 			if(Broj(unos[i+1])){
	 				if(unos[i+2]==' '&& Broj(unos[i+3])){
	 					komanda = Komande::Deblokiraj;
	 					x = unos[i+1];
	 					y = unos[i+3];
	 				}
	 				else{
	 					greska = KodoviGresaka::NeispravanParametar;
	 					dobro_je = false;
	 				}
	 			}
	 			else{
	 				if(Broj(unos[i+2]) && (unos[i+3] ==' ' || unos[i+3]=='/n')){
	 					if(Broj(unos[i+4])){
	 						x = unos[i+2];
	 						y = unos[i+4];
	 					}
	 					else{
	 						greska = KodoviGresaka::NeispravanParametar;
	 						dobro_je = false;
	 					}
	 				}
	 				else{
	 					greska = KodoviGresaka::NeispravanParametar;
	 					dobro_je = false;
	 				}
	 			}
	 		}
	 	}
	 	else if(unos[i] == 'Z'){
	 		komanda = Komande::ZavrsiIgru;
	 		i++;
	 		if(unos[i] == ' ' || unos[i] == '/n'){
	 			
	 		}
	 		else{
	 		//	greska = KodoviGresaka::SuvisanParametar;
	 			dobro_je = false;
	 		}
	 	}
 		else if(unos[i] == 'K'){
 			komanda = Komande::KreirajIgru;
 			i++;
	 		if(unos[i] == ' ' || unos[i]== '/n'){
	 			
	 		}
	 		else{
	 			greska = KodoviGresaka::SuvisanParametar;
	 			dobro_je = false;
	 		}
		}	
	
	return dobro_je;
}

void IzvrsiKomandu (Komande komanda, Tabla &polja, int &x, int &y, Smjerovi smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0){
	if(komanda == Komande::Blokiraj){
		try{
		BlokirajPolje(polja, x, y);
		}
		catch(std::domain_error izuzetak){
			std::cout << izuzetak.what()<<std::endl;
		}
	}
	else if(komanda == Komande::Deblokiraj){
		try{
		DeblokirajPolje(polja, x, y);
		}
		catch(std::domain_error izuzetak){
			std::cout <<izuzetak.what()<< std::endl;
		}
	}
	else if(komanda == Komande::PomjeriJednoMjesto){
		try{
			Status trenutno = Idi(polja, x, y, smjer);
			if(trenutno == Status:: KrajPobjeda){
				std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
					for(int i = 0; i < polja.size(); i++){
						for(int j = 0; j < polja.size(); j++){
						polja[i][j] = Polje::Prazno;
							}
						}
			}
			else if(trenutno == Status:: KrajPoraz){
				std::cout <<  "Nagazili ste na minu" <<std::endl;
					for(int i = 0; i < polja.size(); i++){
						for(int j = 0; j < polja.size(); j++){
						polja[i][j] = Polje::Prazno;
						}
					}
			}
			else{
				std::cout << "Tekuca pozicija igraca je (" + broj2string(x)+ "," + broj2string(y)+")";
			}
		}
		catch(std::out_of_range preslo){
			std::cout<< preslo.what()<< std::endl;
		}
		catch(std::logic_error nesta){
			std::cout <<nesta.what()<<std::endl;
		}
	}
	else if(komanda == Komande::PomjeriDalje){
		try{
			Status trenutno = Idi(polja, p_x, p_y, x, y );
			if(trenutno == Status:: KrajPobjeda){
				std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
					for(int i = 0; i < polja.size(); i++){
						for(int j = 0; j < polja.size(); j++){
						polja[i][j] = Polje::Prazno;
							}
						}
			}
			else if(trenutno == Status:: KrajPoraz){
				std::cout <<  "Nagazili ste na minu" <<std::endl;
					for(int i = 0; i < polja.size(); i++){
						for(int j = 0; j < polja.size(); j++){
						polja[i][j] = Polje::Prazno;
						}
					}
			}
			else{
				std::cout << "Tekuca pozicija igraca je (" + broj2string(x)+ "," + broj2string(y)+")";
			}
		}
		catch(std::out_of_range preslo){
			std::cout<< preslo.what()<< std::endl;
		}
		catch(std::logic_error nesta){
			std::cout <<nesta.what()<<std::endl;
		}
	}
	else if(komanda == Komande::PrikaziOkolinu){
		try{
			Matrica matrica = PrikaziOkolinu(polja, x, y);
			for(int i = 0; i < matrica.size(); i++){
				for(int j = 0; j < matrica[0].size(); j++){
					if(polja[i][j] == Polje:: Mina)std::cout<<"1"<<std::endl;
					else if(polja[i][j] == Polje::Prazno)std::cout<<"0"<<std::endl;
				}
				std::cout << std::endl;
			}
		}
		catch(std::domain_error izuzetak){
			std::cout<< izuzetak.what()<< std::endl;
		}
	}
	else if(komanda == Komande::ZavrsiIgru){
		for(int i = 0; i < polja.size(); i++){
			for(int j = 0; j < polja[0].size(); j++){
				polja[i][j] = Polje::Prazno;
			}
		}
		throw std::runtime_error ("Igra zavrsena");
	}
	else if(komanda == Komande:: KreirajIgru){
		std::cout <<"Unesite broj polja: ";
		int broj_polja;
		std::cin >> broj_polja;
		Matrica mine;
	
		
		std::cout << "Unesite pozicije mina: ";
		char c, c1, c2;
			for(;;){	
					std::vector<int> pomocni;
				int x;
				int y;
				std::cin>> c1; 
				if(c1=='.')break;
				std::cin>> x;
				std::cin>> c2 ;
				if(c2=='.')break;
				std::cin>> y ;
				std::cin >> c;
				if(c=='.') break;
			
				
					pomocni.push_back(x);
					pomocni.push_back(y);
					mine.push_back(pomocni);
					
				
			}
			try{
				polja = KreirajIgru(broj_polja, mine);
			}
			catch(std::domain_error izuzetak){
				std::cout<<izuzetak.what()<<std::endl;
			}
	}
	
}


int main(){
	try{
		
	for(;;){
		std::cout <<"Unesite komandu: ";
		Komande komanda;
		Smjerovi smjer;
		KodoviGresaka greska;
		int x, y;
		Tabla  tabla;
		UnosKomande(komanda, smjer, x, y, greska);
		if(UnosKomande(komanda, smjer, x, y, greska)){
			IzvrsiKomandu(komanda, tabla,x, y ,smjer);
			
			}
		
		else{
			PrijaviGresku(greska);
		}
	}
		
	}
	catch(std::runtime_error){
		std::cout <<"Dovidjenja";
	}
	return 0;
}
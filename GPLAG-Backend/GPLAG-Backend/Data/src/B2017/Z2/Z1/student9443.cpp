//B 2017/2018, Zadaća 2, Zadatak 1

#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

enum class Polje {
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	if(n <= 0) throw std::domain_error("Ilegalna velicina");
	Tabla vrati(n, std::vector<Polje> (n, Polje::Prazno));
	for(int i=0; i<vrati.size(); i++){
		for(int j=0; j<vrati.at(i).size(); j++){
			for(int k=0; k<mine.size(); k++){
			    if(mine.at(k).size() != 2) throw std::domain_error("Ilegalan format zadavanja mina");
			    if(mine.at(k).at(0) >= n || mine.at(k).at(1) >= n || mine.at(k).at(0) < 0 || mine.at(k).at(1) < 0) throw std::domain_error("Ilegalne pozicije mina");
			    if(mine.at(k).at(0)==i && mine.at(k).at(1)==j)   vrati.at(i).at(j)=Polje::Mina;
			}
		}
	}
	return vrati;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	if(x<0 || y<0 || x>=polja.size() || y>=polja.size()) {
		throw std::domain_error("Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji");
	}
	std::vector<std::vector<int>> vrati(3, std::vector<int> (3, 0));
    for(int i=0; i<polja.size(); i++){
    	for(int j=0; j<polja.at(i).size(); j++){
    		if(i >= x-1 && i <= x+1 && j >= y-1 && j <= y+1){
    			for(int a=i-1; a<=i+1; a++){
    				for(int b=j-1; b<=j+1; b++){
    					if((a != i || b != j ) && a >= 0 && b >= 0 && a < polja.size() && b < polja.at(i).size() && polja.at(a).at(b) == Polje::Mina) vrati.at(i-x+1).at(j-y+1)++;
    				}
    			}
    		}
    	}
    }
    return vrati;
}

void BlokirajPolje(Tabla &polja, int x, int y){
	if(x<0 || y<0 || x>=polja.size() || y>=polja.size()) {
		throw std::domain_error("Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji");
	}
	if(polja.at(x).at(y) == Polje::Prazno) polja.at(x).at(y)=Polje::BlokiranoPrazno;
	else if(polja.at(x).at(y) == Polje::Posjeceno) polja.at(x).at(y)=Polje::BlokiranoPosjeceno;
	else if(polja.at(x).at(y) == Polje::Mina) polja.at(x).at(y)=Polje::BlokiranoMina;
}

void DeblokirajPolje(Tabla &polja, int x, int y){
	if(x<0 || y<0 || x>=polja.size() || y>=polja.size()) {
		throw std::domain_error("Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji");
	}
	if(polja.at(x).at(y) == Polje::BlokiranoPrazno) polja.at(x).at(y)=Polje::Prazno;
	else if(polja.at(x).at(y) == Polje::BlokiranoPosjeceno) polja.at(x).at(y)=Polje::Posjeceno;
	else if(polja.at(x).at(y) == Polje::BlokiranoMina) polja.at(x).at(y)=Polje::Mina;
}

enum class Smjerovi{
	GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};

enum class Status{
	NijeKraj, KrajPoraz, KrajPobjeda
};

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	int i{x}, j{y};
	if(smjer == Smjerovi::GoreLijevo) {
		i--;
		j--;
	}
	else if(smjer == Smjerovi::Gore)  i--;
	else if(smjer == Smjerovi::GoreDesno) {
		i--;
		j++;
	}
	else if(smjer == Smjerovi::Desno) j++;
	else if(smjer == Smjerovi::DoljeDesno) {
		i++;
		j++;
	}
	else if(smjer == Smjerovi::Dolje) i++;
	else if(smjer == Smjerovi::DoljeLijevo) {
		i++;
		j--;
	}
	else if(smjer == Smjerovi::Lijevo) j--;
	
	if(i<0 || j<0 || i>=polja.size() || j>=polja.size()) {
		throw std::out_of_range("Izlazak van igrace tabele");
	}
	if(polja.at(i).at(j) == Polje::BlokiranoPosjeceno || polja.at(i).at(j) == Polje::BlokiranoPrazno || polja.at(i).at(j) == Polje::BlokiranoMina) {
		throw std::logic_error("Blokirano polje");
	}
	x=i;
	y=j;
	if(polja.at(x).at(y) == Polje::Mina) return Status::KrajPoraz;
	if(polja.at(x).at(y) == Polje::Prazno) polja.at(x).at(y)=Polje::Posjeceno;
	for(i=0; i<polja.size(); i++)
	    for(j=0; j<polja.at(i).size(); j++) 
	        if(polja.at(i).at(j) == Polje::Prazno) return Status::NijeKraj;
	return Status::KrajPobjeda;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	if(novi_x<0 || novi_y<0 || novi_x>=polja.size() || novi_y>=polja.size()) {
		throw std::out_of_range("Izlazak van igrace table");
	}
	if(polja.at(novi_x).at(novi_y) == Polje::BlokiranoPosjeceno || polja.at(novi_x).at(novi_y) == Polje::BlokiranoPrazno || polja.at(novi_x).at(novi_y) == Polje::BlokiranoMina) {
		throw std::logic_error("Blokirano polje");
	}
	x=novi_x;
	y=novi_y;
	if(polja.at(x).at(y) == Polje::Mina) return Status::KrajPoraz;
	if(polja.at(x).at(y) == Polje::Prazno) polja.at(x).at(y)=Polje::Posjeceno;
	for(int i=0; i<polja.size(); i++)
	    for(int j=0; j<polja.at(i).size(); j++) 
	        if(polja.at(i).at(j) == Polje::Prazno) return Status::NijeKraj;
	return Status::KrajPobjeda;
}

enum class KodoviGresaka{
	PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};

void PrijaviGresku(KodoviGresaka zaispis){
	if(zaispis == KodoviGresaka::PogresnaKomanda) std::cout << "Nerazumljiva komanda!" << std::endl;
	else if(zaispis == KodoviGresaka::NedostajeParametar) std::cout << "Komanda trazi parametar koji nije naveden!" << std::endl;
	else if(zaispis == KodoviGresaka::NeispravanParametar) std::cout << "Parametar komande nije ispravan!" << std::endl;
	else if(zaispis == KodoviGresaka::SuvisanParametar) std::cout << "Zadan je suvisan parametar nakon komande!" << std::endl;
}

enum class Komande{
	PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	std::string unos;
	std::getline(std::cin, unos);
	for(int i=0; i<unos.size(); i++) {
		if(unos.at(i) != ' '){
			if(unos.at(i) == 'P') {                                             //ako je P
				i++;
				if(i < unos.size()) {
					if(unos.at(i) == '1') {                                       //ako je 1
						i++;
						while(i < unos.size() && unos.at(i) == ' ' )  i++;            //da prodjemo sve razmake ako ih ima
					    	if(i < unos.size() && unos.at(i) == 'G') {                                  //ako je G
								i++;
								while(i < unos.size() && unos.at(i) == ' ' )  i++;
								if(i == unos.size()){                                 // dosao uspjesno do kraja: P1 G
									smjer=Smjerovi::Gore;
									return true;
								}
								if(i < unos.size() && unos.at(i) == 'L') {                             // ako je L
								    i++;
								    while(i < unos.size() && unos.at(i) == ' ' )  i++;
								    if(i == unos.size()) {                            // dosao uspjesno do kraja: P1 GL
								    	smjer=Smjerovi::GoreLijevo;
								    	komanda=Komande::PomjeriJednoMjesto;
							    		return true;
								    }
								    greska=KodoviGresaka::SuvisanParametar;           // ima jos nesta iza parametera
								    return false;
								}
								if(i < unos.size() && unos.at(i) == 'D') {                             // ako je D
								    i++;
									while(i < unos.size() && unos.at(i) == ' ' )  i++;
								    if(i == unos.size()) {                            // dosao uspjesno do kraja: P1 GD
								    	smjer=Smjerovi::GoreDesno;
								    	komanda=Komande::PomjeriJednoMjesto;
							    		return true;
								    }
								    greska=KodoviGresaka::SuvisanParametar;           // ima jos nesta iza parametera
								    return false;
								}
								greska=KodoviGresaka::SuvisanParametar;             // ima iza G nesto nevaljasto
								return false;
							}
							else if(i < unos.size() && unos.at(i) == 'D') {
								i++;
								while(i < unos.size() && unos.at(i) == ' ' )  i++;
								if(i == unos.size()){                                 // dosao uspjesno do kraja: P1 D
									smjer=Smjerovi::Desno;
									komanda=Komande::PomjeriJednoMjesto;
									return true;
								}
								if(unos.at(i) == 'o'){
									i++;
							     	while(i < unos.size() && unos.at(i) == ' ' )  i++;
							    	if(i == unos.size()){                                 // dosao uspjesno do kraja: P1 Do
							     		smjer=Smjerovi::Dolje;
							     		komanda=Komande::PomjeriJednoMjesto;
								    	return true;
						     		}
									if(unos.at(i) == 'D') {
										i++;
										while(i < unos.size() && unos.at(i) == ' ' )  i++;
								        if(i == unos.size()) {                            // dosao uspjesno do kraja: P1 DoD
							   		    	smjer=Smjerovi::DoljeDesno;
							   		    	komanda=Komande::PomjeriJednoMjesto;
							   	    		return true;
							    	    }
						    		    greska=KodoviGresaka::SuvisanParametar;           // ima jos nesta iza parametera
							    	    return false;
								   	}
								   	if(unos.at(i) == 'L') {
								   		i++;
								   		while(i < unos.size() && unos.at(i) == ' ' )  i++;
							     	    if(i == unos.size()) {                            // dosao uspjesno do kraja: P1 DoL
							     	    	smjer=Smjerovi::DoljeLijevo;
							     	    	komanda=Komande::PomjeriJednoMjesto;
							         		return true;
							     	    }
						     		    greska=KodoviGresaka::SuvisanParametar;           // ima jos nesta iza parametera
							    	    return false;
								   	}
								}
								greska=KodoviGresaka::SuvisanParametar;
								return false;
							}
							else if(i < unos.size() && unos.at(i) == 'L'){
								i++;
								while(i < unos.size() && unos.at(i) == ' ' )  i++;
								if(i == unos.size()) {                            // dosao uspjesno do kraja: P1 L
									smjer=Smjerovi::Lijevo;
									komanda=Komande::PomjeriJednoMjesto;
								    return true;
							    }
								greska=KodoviGresaka::SuvisanParametar;           // ima jos nesta iza parametera
								return false;
							}
							if(i == unos.size())  	greska=KodoviGresaka::NedostajeParametar;
						    else greska=KodoviGresaka::NeispravanParametar;
							return false;
					}
					else if(unos.at(i) == '>') {
						i++;
						while(i < unos.size() && unos.at(i) == ' ' )  i++;
						if(i < unos.size() && unos.at(i) >= '0' && unos.at(i) <= '9') {     // ako je i-ti karakter broj
							int a{0};
							while(i < unos.size() && unos.at(i) >= '0' && unos.at(i) <= '9') {        // prvi param a
								a*=10;
								a+= unos.at(i) - '0';
								i++;
							}
							if(i < unos.size() && unos.at(i) == ' ') {
								while(i < unos.size() && unos.at(i) == ' ' )  i++;
								if(i < unos.size() && unos.at(i) >= '0' && unos.at(i) <= '9') {
									int b{0};
									while(i < unos.size() && unos.at(i) >= '0' && unos.at(i) <= '9') {     // drugi param b
							        	b*=10;
					        			b+= unos.at(i) - '0';
			        					i++;
			        				}
			        				while(i < unos.size() && unos.at(i) == ' ' )  i++;
			        				if(i == unos.size()) {
			        					komanda=Komande::PomjeriDalje;                      //P> x y
			        					x=a;
			        					y=b;
			        					return true;
			        				}
			        				greska=KodoviGresaka::SuvisanParametar;
			        				return false;
								}
							}
							if(i == unos.size()) greska=KodoviGresaka::NedostajeParametar;
							else greska=KodoviGresaka::NeispravanParametar;
							return false;
						}
						if(i == unos.size()) greska=KodoviGresaka::NedostajeParametar;
						else greska=KodoviGresaka::NeispravanParametar;
						return false;
					}
					else if(unos.at(i) == 'O') {
						i++;
						while(i < unos.size() && unos.at(i) == ' ' )  i++;
					    if(i == unos.size()) {                            // dosao uspjesno do kraja: PO
					        komanda=Komande::PrikaziOkolinu;
				     	    return true;
			     		}
						greska=KodoviGresaka::SuvisanParametar;           // ima jos nesta iza parametera
						return false;
					}
					greska=KodoviGresaka::NeispravanParametar;
					return false;
				}
				greska=KodoviGresaka::NedostajeParametar;
				return false;
			}
			else if(unos.at(i) == 'B') {
		    	i++;
				while(i < unos.size() && unos.at(i) == ' ' )  i++;
				if(i < unos.size() && unos.at(i) >= '0' && unos.at(i) <= '9') {     // ako je i-ti karakter broj
					int a{0};
					while(i < unos.size() && unos.at(i) >= '0' && unos.at(i) <= '9') {   // prvi param
						a*=10;
						a+= unos.at(i) - '0';
						i++;
					}
					if(i < unos.size() && unos.at(i) == ' ') {
						while(i < unos.size() && unos.at(i) == ' ' )  i++;
						if(i < unos.size() && unos.at(i) >= '0' && unos.at(i) <= '9') {
							int b{0};
							while(i < unos.size() && unos.at(i) >= '0' && unos.at(i) <= '9') {        //drugi param
							    b*=10;
					        	b+= unos.at(i) - '0';
			        			i++;
			        		}
			        		while(i < unos.size() && unos.at(i) == ' ' )  i++;
			       			if(i == unos.size()) {
			       				komanda=Komande::Blokiraj;                                 // B x y
			       				x=a;
			        			y=b;
			   					return true;
		     				}
	        				greska=KodoviGresaka::SuvisanParametar;
	        				return false;
						}
					}
					if(i == unos.size()) greska=KodoviGresaka::NedostajeParametar;
					else greska=KodoviGresaka::NeispravanParametar;
					return false;
				}
				if(i == unos.size()) greska=KodoviGresaka::NedostajeParametar;
				else greska=KodoviGresaka::NeispravanParametar;
				return false;	
			}
			else if(unos.at(i) == 'D') {
				i++;
				while(i < unos.size() && unos.at(i) == ' ' )  i++;
				if(i < unos.size() && unos.at(i) >= '0' && unos.at(i) <= '9') {     // ako je i-ti karakter broj
					int a{0};
					while(i < unos.size() && unos.at(i) >= '0' && unos.at(i) <= '9') {
						a*=10;
						a+= unos.at(i) - '0';
						i++;
					}
					if(i < unos.size() && unos.at(i) == ' ') {
						while(i < unos.size() && unos.at(i) == ' ' )  i++;
						if(i < unos.size() && unos.at(i) >= '0' && unos.at(i) <= '9') {
							int b{0};
							while(i < unos.size() && unos.at(i) >= '0' && unos.at(i) <= '9') {
					        	b*=10;
			        			b+= unos.at(i) - '0';
	        					i++;
	        				}
		       				while(i < unos.size() && unos.at(i) == ' ' )  i++;
		       				if(i == unos.size()) {
		       					komanda=Komande::Deblokiraj;                               // D x y
	        					x=a;
		       					y=b;
		       					return true;
		       				}
		       				greska=KodoviGresaka::SuvisanParametar;
	        				return false;
						}
					}
					if(i == unos.size()) greska=KodoviGresaka::NedostajeParametar;
					else greska=KodoviGresaka::NeispravanParametar;
					return false;
				}
				if(i == unos.size()) greska=KodoviGresaka::NedostajeParametar;
				else greska=KodoviGresaka::NeispravanParametar;
				return false;
			}
			else if(unos.at(i) == 'Z') {
				i++;
				while(i < unos.size() && unos.at(i) == ' ' )  i++;
				if(i == unos.size()) {                            // dosao uspjesno do kraja: Z
					komanda=Komande::ZavrsiIgru;
					return true;
				}
				greska=KodoviGresaka::SuvisanParametar;           // ima jos nesta iza komande
				return false;
			}
			else if(unos.at(i) == 'K') {
				i++;
				while(i < unos.size() && unos.at(i) == ' ' )  i++;
				if(i == unos.size()) {                            // dosao uspjesno do kraja: K
				    komanda=Komande::KreirajIgru;
				    return true;
				}
				greska=KodoviGresaka::SuvisanParametar;           // ima jos nesta iza komande
				return false;
			}
			greska=KodoviGresaka::PogresnaKomanda;
			return false;
		}
	}
	greska=KodoviGresaka::PogresnaKomanda;
    return false;
}

void zavrsi(Tabla &polja) {
	for(int i=0; i<polja.size(); i++){
		for(int j=0; j<polja.at(i).size(); j++) polja.at(i).at(j)=Polje::Prazno;
	}
	throw std::runtime_error("Dovidjenja!");
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0){
	Status status;
	if(komanda == Komande::PomjeriJednoMjesto) {                                                             // Pomjeri Jedno Mjesto
		status=Idi(polja, x, y, p_smjer);
		std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")" << std::endl;
		if(status == Status::KrajPobjeda) {
			std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
			zavrsi(polja);
		}
		else if(status == Status::KrajPoraz) {
			std::cout << "Nagazili ste na minu" << std::endl;
			zavrsi(polja);
		}
	}
	else if(komanda == Komande::PomjeriDalje) {                                                              // Pomjeri Dalje
		status=Idi(polja, x, y, p_x, p_y);
		std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")" << std::endl;
		if(status == Status::KrajPobjeda) {
			std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
			zavrsi(polja);
		}
		else if(status == Status::KrajPoraz) {
			std::cout << "Nagazili ste na minu" << std::endl;
			zavrsi(polja);
		}
	}
	else if(komanda == Komande::Blokiraj) {                                                                  // Blokiraj
		BlokirajPolje(polja, p_x, p_y);
	}
	else if(komanda == Komande::Deblokiraj) {                                                                // Deblokiraj
		DeblokirajPolje(polja, p_x, p_y);
	}
	else if(komanda == Komande::PrikaziOkolinu) {                                                            // Prikazi Okolinu
		auto ispisi = PrikaziOkolinu(polja, x, y);
		for(int i=0; i<3; i++) {
			for(int j=0; j<3; j++) {
				std::cout << ispisi.at(i).at(j);
			}
			std::cout << std::endl;
		}
	}
	else if(komanda == Komande::ZavrsiIgru) zavrsi(polja);                                                   // Zavrsi Igru
	else if(komanda == Komande::KreirajIgru) {                                                               // Kreiraj Igru
	    int n;
	    std::cout << "Unesite broj polja: ";
	    std::cin >> n;
	    while(!std::cin || n<=0) {
	    	std::cout << "Greska, unesite ponovo!" << std::endl << "Unesite broj polja: ";
	    	std::cin.clear();
	    	std::cin.ignore(10000, '\n');
	    	std::cin >> n;
	    }
	    std::cin.ignore(10000, '\n');
	    std::cin.clear();
	    std::cout << "Unesite pozicije mina: ";
	    std::vector<std::vector<int>> mine;
	    bool jel_dosta{false};
	    while(!jel_dosta) {
    	    std::string unos;
        	std::getline(std::cin, unos);
        	for(int i=0; i<unos.size(); i++) {
        		while(i < unos.size() && unos.at(i) == ' ' )  i++;
        		if(unos.at(i) != ' '){
        			if(unos.at(i) == '.') { 
        				jel_dosta=true;
        				break;
        			}
        			else if(unos.at(i) == '(') {  
        				i++;
        				while(i < unos.size() && unos.at(i) == ' ' )  i++;
			         	if(i < unos.size() && unos.at(i) >= '0' && unos.at(i) <= '9') {
				         	int a{0};
				        	while(i < unos.size() && unos.at(i) >= '0' && unos.at(i) <= '9') {
					        	a*=10;
					        	a+= unos.at(i) - '0';
					        	i++;
				        	}
        		     		while(i < unos.size() && unos.at(i) == ' ' )  i++;
        			    	if(i < unos.size() && unos.at(i) == ',') { 
        		    			i++;
        		    			while(i < unos.size() && unos.at(i) == ' ' )  i++;
		                    	if(i < unos.size() && unos.at(i) >= '0' && unos.at(i) <= '9') {
	                    			int b{0};
	                    			while(i < unos.size() && unos.at(i) >= '0' && unos.at(i) <= '9') {
                    					b*=10;
	                    				b+= unos.at(i) - '0';
	                     				i++;
                        			}
        		    	     		while(i < unos.size() && unos.at(i) == ' ' )  i++;
        			         		if(i < unos.size() && unos.at(i) == ')') {
        					      		i++;
        						       	while(i < unos.size() && unos.at(i) == ' ' )  i++;
        						        if(i == unos.size() && (a>0 || b>0) && a<n && b<n){
								            mine.push_back(std::vector<int> {a, b});                                 // Upis u vektor vektora mine
							    	        break;
        						        }
       								}
       							}
        					}
        				}
        			}
        		}
        		std::cout << "Greska, unesite ponovo!" << std::endl;
        		break;
        	}	
	    }
		polja = KreirajIgru(n, mine);
		polja.at(0).at(0)=Polje::Posjeceno;                                                                 // Upis na poziciju (0,0) da je posjecena automatski
	}
}

int main ()
{
	Tabla polja(0, std::vector<Polje> (0));
	Komande komanda;
	Smjerovi smjer;
	int x=0, y=0, novo_x{0}, novo_y{0};
	KodoviGresaka greska;
	for(;;) {
		std::cout << "Unesite komandu: ";
	    while( !UnosKomande(komanda, smjer, novo_x, novo_y, greska) || (polja.size() == 0 && komanda != Komande::KreirajIgru) ) {
	    	PrijaviGresku(greska);
	    	std::cout << "Unesite komandu: ";
	    }
	    try {
	        IzvrsiKomandu(komanda, polja, x, y, smjer, novo_x, novo_y);
	    }
	    catch(std::logic_error izuzetak) {
	    	std::cout << izuzetak.what() << std::endl;
	    	
	    }
	    catch(std::runtime_error izuzetak) {
	    	std::cout << izuzetak.what() << std::endl;
	    	break;
	    }
	    catch(...) {
	    	std::cout << "Nepoznat izuzetak" << std::endl;
	    }
	}
	return 0;
}
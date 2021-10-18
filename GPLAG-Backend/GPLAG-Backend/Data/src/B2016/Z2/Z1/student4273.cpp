/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/

#include <iostream>
#include <vector>
#include <stdexcept> //u njoj su definirani standardni izuzeci
#include <string>
#include <complex>

using std::cin; using std::cout; using std::endl;

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
 PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu,ZavrsiIgru, KreirajIgru
};


typedef std::vector<std::vector<Polje>> Tabla;
typedef std::vector<std::vector<int>> Matrica;

//Funkcije

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine) {
	Tabla pocetna;
	pocetna.resize(n);
	for (int i=0; i<n; i++) { //Kreiramo i inicijaliziramo tablu
		for (int j=0; j<n; j++) {
			pocetna[i].push_back(Polje::Prazno);
		}
	}
	//Provjerimo ispravnost vektora mine, ne smije biti na poziciji (0,0)!
	for (int i=0; i<mine.size(); i++) {
		if (mine[i].size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
		if (mine[i][0]<0 || mine[i][0]>=n || mine[i][1]<0 || mine[i][1]>=n || (mine[i][0]==0 && mine[i][1]==0)) throw std::domain_error("Ilegalne pozicije mina");
	}
	//Ubacimo i mine
	for (int i=0; i<mine.size(); i++) {
		pocetna[mine[i][0]][mine[i][1]]=(Polje::Mina);
	}
	return pocetna;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y) {
	if (x<0 || y<0 || x>=polja.size() || y>=polja.size()) {
		const std::string ispis("Polje (" + std::to_string(x) + ","+ std::to_string(y) + ") ne postoji");
		throw std::domain_error(ispis);
	}
	Matrica mat(3, std::vector<int>(3)); //Matrica 3x3
	int brojac(0); int poc1, poc2, poc3, poc4, kraj1, kraj2, kraj3, kraj4;
	//Brojimo mine u okolini
	if (x==0) poc1=x; //Ako je prvi red
	else poc1=x-1;
	if (x==polja.size()-1) kraj1=x+1; //Ako je zadnji red- iza_kraja
	else kraj1=x+2;
	if (y==0) poc2=y; //Prva kolona
	else poc2=y-1;
	if (y==polja.size()-1) kraj2=y+1; //Zadnja kolona
	else kraj2=y+2;
	
	for (int i=poc1; i<kraj1; i++) {
		for (int j=poc2; j<kraj2; j++) {
			brojac=0;
			//Uslovi za rubove
			if (i==0) poc3=i;
			else poc3=i-1;
			if (i==polja.size()-1) kraj3=i+1;
			else kraj3=i+2;
			if (j==0) poc4=j;
			else poc4=j-1;
			if (j==polja.size()-1) kraj4=j+1;
			else kraj4=j+2;
				
			for (int k=poc3; k<kraj3; k++) {
				for (int l=poc4; l<kraj4; l++) {
					if (polja[k][l]==Polje::Mina || polja[k][l]==Polje::BlokiranoMina) brojac++;
				}
			}
			if (polja[i][j]==Polje::Mina || polja[i][j]==Polje::BlokiranoMina) brojac--;
			mat[i-x+1][j-y+1]=brojac;
		}
	}
	return mat;
}

void BlokirajPolje(Tabla &polja, int x, int y) {
	if (x<0 || y<0 || x>=polja.size() || y>=polja.size()) {
		const std::string ispis("Polje (" + std::to_string(x) + ","+ std::to_string(y) + ") ne postoji");
		throw std::domain_error(ispis);
	}
	//U enumu mozes koristiti i poredak, svi ovi tipovi su > od BlokiranoPrazno, a rezultat je polje -3
	if (polja[x][y]==Polje::Mina) polja[x][y]=Polje::BlokiranoMina;
	else if (polja[x][y]==Polje::Prazno) polja[x][y]=Polje::BlokiranoPrazno;
	else if (polja[x][y]==Polje::Posjeceno) polja[x][y]=Polje::BlokiranoPosjeceno;
}

void DeblokirajPolje(Tabla &polja, int x, int y) {
	if (x<0 || y<0 || x>=polja.size() || y>=polja.size()) {
		const std::string ispis("Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji");
		throw std::domain_error(ispis);
	}
	if (polja[x][y]==Polje::BlokiranoMina) polja[x][y]=Polje::Mina;
	else if (polja[x][y]==Polje::BlokiranoPrazno) polja[x][y]=Polje::Prazno;
	else if (polja[x][y]==Polje::BlokiranoPosjeceno) polja[x][y]=Polje::Posjeceno;
}

bool ProvjeriJeLiBlokirano (Tabla &polja, int x, int y) {
	if (polja[x][y]==Polje::BlokiranoPosjeceno || polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoMina )
	return true;
	return false;
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer) {
	//Provjerimo da li izlazimo iz table
	if (smjer==Smjerovi::Gore) {
		if(x<=0) throw std::out_of_range("Izlazak van igrace table");
		x=x-1; 
	}
	if (smjer==Smjerovi::GoreLijevo) { 
		if(x<=0 || y<=0) throw std::out_of_range("Izlazak van igrace table");
		x=x-1; y=y-1;
	}
	if (smjer==Smjerovi::GoreDesno) {
		if(x<=0 || y>=polja[0].size()-1) throw std::out_of_range("Izlazak van igrace table");
		x=x-1; y=y+1; 
	}
	if (smjer==Smjerovi::Desno) {
		if(y>=polja[0].size()-1) throw std::out_of_range("Izlazak van igrace table");
		y=y+1; 
	} 
	if (smjer==Smjerovi::DoljeDesno) {
		if(y>=polja[0].size()-1 || x>=polja.size()-1) throw std::out_of_range("Izlazak van igrace table");
		x=x+1; y=y+1; 
	}
	if (smjer==Smjerovi::Dolje) {
		if (x>=polja.size()-1) throw std::out_of_range("Izlazak van igrace table");
		x=x+1;
	}
	if (smjer==Smjerovi::DoljeLijevo) {
		if (x>=polja.size() || y<=0) throw std::out_of_range("Izlazak van igrace table");
		x=x+1; y=y-1;
	}
	if (smjer==Smjerovi::Lijevo) {
		if (y<=0) throw std::out_of_range("Izlazak van igrace table");
		y=y-1;
	}
	if (ProvjeriJeLiBlokirano(polja, x, y)) throw std::logic_error("Blokirano polje");
	
	polja.at(x).at(y)=Polje::Posjeceno;
	
	if (polja[x][y]==Polje::Mina) {
		//Očistimo matricu
		for (int i=0; i<polja.size(); i++) {
			for (int j=0; j<polja.size(); j++) {
				polja[i][j]=Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
	//Provjerimo da li je pobjeda
	for (int i=0; i<polja.size(); i++) {
			for (int j=0; j<polja.size(); j++) {
				if (polja[i][j]==Polje::Prazno)
				return Status::NijeKraj;
			}
		}
	return Status::KrajPobjeda;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y) {
	polja.at(x).at(y)=Polje::Posjeceno; 
	//Provjerimo da li izlazimo iz table
	if (novi_x<0 || novi_x>polja.size()-1 || novi_y<0 || novi_y>polja.size()-1) throw std::out_of_range("Izlazak van igrace table");
	if (ProvjeriJeLiBlokirano(polja, novi_x, novi_y)) throw std::logic_error("Blokirano polje");
	
	x=novi_x; y=novi_y;
	
	if (polja[novi_x][novi_y]==Polje::Mina) {
		//Očistimo matricu
		for (int i=0; i<polja.size(); i++) {
			for (int j=0; j<polja.size(); j++) {
				polja[i][j]=Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
	//Provjerimo da li je pobjeda
	for (int i=0; i<polja.size(); i++) {
			for (int j=0; j<polja.size(); j++) {
				if (polja[i][j]==Polje::Prazno)
				return Status::NijeKraj;
			}
		}
	return Status::KrajPobjeda;
}

void PrijaviGresku (KodoviGresaka kod) {
	//Mozes napraviti const char *tekstovi[] koji sadrzi tekst, ispis tekstovi[int(greska)]
	if (kod==KodoviGresaka::PogresnaKomanda)
	cout << "Nerazumljiva komanda!" << endl;
	if (kod==KodoviGresaka::NedostajeParametar)
	cout << "Komanda trazi parametar koji nije naveden!" << endl;
	if (kod==KodoviGresaka::NeispravanParametar)
	cout << "Parametar komande nije ispravan!" << endl;
	if (kod==KodoviGresaka::SuvisanParametar)
	cout << "Zadan je suvisan parametar nakon komande!" << endl;
}


bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska) {
	std::string unos; komanda=Komande();
 	std::getline(cin, unos); //Unijeli smo komandu, sada je moramo prepoznati
 	//cout << "Unos: "<< unos << endl;
 	int i=0; //bool prva(true); 
 	while (i<unos.size()) {
 		if (unos[i]==' ') continue; //Preskacemo prve razmake 
 		else {
 		    //Provjerimo koja je komanda u pitanju
 		    if (unos[i]=='P' && i<unos.size()-1 && unos[i+1]=='1') { //Pomjeri se za jedno mjesto
 		    	i+=2;
 		    	while (i<unos.size() && unos[i]==' ') i++;
 		    	if (i==unos.size()) {
 		    		greska=KodoviGresaka::NedostajeParametar;
 		    		return false;
 		    	}
 		    	//Provjerimo koji smjer je u pitanju
 		    	if (unos[i]=='G' && i<unos.size()-1 && unos[i+1]=='L') {
 		    		i+=2;
 		    		while (i<unos.size() && unos[i]==' ') i++;
 		    		if (i==unos.size()) {
 		    			smjer=Smjerovi::GoreLijevo;
 		    			komanda=Komande::PomjeriJednoMjesto;
 		    			return true;
 		    		}
 		    		greska=KodoviGresaka::SuvisanParametar;
 		    		return false;
 		    	}
 		    	if (unos[i]=='G' && i<unos.size()-1 && unos[i+1]=='D') {
 		    		i+=2;
 		    		while (i<unos.size() && unos[i]==' ') i++;
 		    		if (i==unos.size()) {
 		    			smjer=Smjerovi::GoreDesno;
 		    			komanda=Komande::PomjeriJednoMjesto;
 		    			return true;
 		    		}
 		    		greska=KodoviGresaka::SuvisanParametar;
 		    		return false;
 		    	}
 		    	if (unos[i]=='G') {
 		    		i+=1;
 		    		while (i<unos.size() && unos[i]==' ') i++;
 		    		if (i==unos.size()) {
 		    			smjer=Smjerovi::Gore;
 		    			komanda=Komande::PomjeriJednoMjesto;
 		    			return true;
 		    		}
 		    		greska=KodoviGresaka::SuvisanParametar;
 		    		return false;
 		    	}
 		    	if (unos[i]=='D' && i<unos.size()-1 && unos[i+1]=='o') {
 		    		if ((i+2)<unos.size() && unos[i+2]=='D') {
 		    			i+=3;
 		    			while (i<unos.size() && unos[i]==' ') i++;
 		    			if (i==unos.size()) {
 		    				smjer=Smjerovi::DoljeDesno; 
 		    				komanda=Komande::PomjeriJednoMjesto;
 		    				return true;

 		    			}
 		    			greska=KodoviGresaka::SuvisanParametar;
 		    			return false;
 		    		}
 		    		else if ((i+2)<unos.size() && unos[i+2]=='L') {
 		    			i+=3;
 		    			while (i<unos.size() && unos[i]==' ') i++;
 		    			if (i==unos.size()) {
 		    				smjer=Smjerovi::DoljeLijevo;
 		    				komanda=Komande::PomjeriJednoMjesto;
 		    				return true; 
 		    			}
 		    			greska=KodoviGresaka::SuvisanParametar;
 		    			return false;
 		    		}
 		    		else {
 		    			i+=2;
 		    			while (i<unos.size() && unos[i]==' ') i++;
 		    			if (i==unos.size()) {
 		    				smjer=Smjerovi::Dolje;
 		    				komanda=Komande::PomjeriJednoMjesto;
 		    				return true;
 		    			}
 		    			greska=KodoviGresaka::SuvisanParametar;
 		    			return false;
 		    		}
 		    	}
 		    	if (unos[i]=='D') {
 		    		i+=1;
 		    		while (i<unos.size() && unos[i]==' ') i++;
 		    		if (i==unos.size()) {
 		    			smjer=Smjerovi::Desno;
 		    			komanda=Komande::PomjeriJednoMjesto;
 		    			return true;
 		    		}
 		    		greska=KodoviGresaka::SuvisanParametar;
 		    		return false;
 		    	}
 		    	
 		        if (unos[i]=='L') {
 		    		i+=1;
 		    		while (i<unos.size() && unos[i]==' ') i++;
 		    		if (i==unos.size()) {
 		    			smjer=Smjerovi::Lijevo;
 		    			komanda=Komande::PomjeriJednoMjesto;
 		    			return true;
 		    		}
 		    		greska=KodoviGresaka::SuvisanParametar;
 		    		return false;
 		    	}
 		    	//Ako nije nista od navedenog i nije kraj
 		    	greska=KodoviGresaka::NeispravanParametar;
 		    	return false;
 		    }
 		    if (unos[i]=='P' && i<unos.size()-1 && unos[i+1]=='>') { //Pomjeri se na zadano polje
 		    	i+=2;
 		    	while (i<unos.size() && unos[i]==' ') i++; //Preskacemo razmake na pocetku
 		    	if (i==unos.size()) {
 		    		greska=KodoviGresaka::NedostajeParametar;
 		    		return false;
 		    	}
 		    	x=0;
 		    	while (i<unos.size() && (unos[i]>='0' && unos[i]<='9')) {
 		    		x=x*10+(unos[i]-'0');
 		    		i++;
 		    	}
 		    	if (unos[i] != ' ') {
 		    		greska=KodoviGresaka::NeispravanParametar;
 						return false;
 		    	}
 		    	while (i<unos.size() && unos[i]==' ') i++; //Preskacemo razmake
 				if (i==unos.size()) {
 					greska=KodoviGresaka::NeispravanParametar;
 					return false;
 				}
 				y=0;
 				while (i<unos.size() && (unos[i]>='0' && unos[i]<='9')) {
 					y=y*10+(unos[i]-'0');
 					i++;
 				}
 				while (i<unos.size() && unos[i]==' ') i++; //Pomjeramo na kraj unosa
 				if (i!=unos.size()) {
 					greska=KodoviGresaka::NeispravanParametar;
 					return false;
 				}
 		    	komanda=Komande::PomjeriDalje;
 		    	return true;
 		    }
 		    
 			if (unos[i]=='B' || unos[i]=='D') {
 				if (unos[i]=='B') {
 					i=i+1; //Pomjerimo na sljedeci
 					while (i<unos.size() && unos[i]==' ') i++; //Preskacemo razmake
 					if (i==unos.size()) {
 		    			greska=KodoviGresaka::NedostajeParametar;
 		    			return false;
 		    		}
 					x=0;
 		    		while (i<unos.size() && (unos[i]>='0' && unos[i]<='9')) {
 		    			x=x*10+(unos[i]-'0');
 		    			i++;
 		    		}
 		    		if (unos[i] != ' ') {
 		    			greska=KodoviGresaka::PogresnaKomanda;
 						return false;
 		    		}
 		    		while (i<unos.size() && unos[i]==' ') i++; //Preskacemo razmake
 					if (i==unos.size()) {
 						greska=KodoviGresaka::NedostajeParametar;
 						return false;
 					}
 					y=0;
 					while (i<unos.size() && (unos[i]>='0' && unos[i]<='9')) {
 						y=y*10+(unos[i]-'0');
 						i++;
 					}
 					while (i<unos.size() && unos[i]==' ') i++; //Pomjeramo na kraj unosa
 					if (i!=unos.size()) {
 						greska=KodoviGresaka::PogresnaKomanda;
 						return false;
 					}
 					
 					komanda=Komande::Blokiraj;
 					return true;
 				}
 				//Ako je unos D
 				i++; //Pomjerimo na sljedeci
 				while (i<unos.size() && unos[i]==' ') i++; //Preskacemo razmake
 				if (i==unos.size()) {
 		    		greska=KodoviGresaka::NedostajeParametar;
 		    		return false;
 		    	}
 				x=0;
 		    	while (i<unos.size() && (unos[i]>='0' && unos[i]<='9')) {
 		    		x=x*10+(unos[i]-'0');
 		    		i++;
 		    	}
 		    	if (unos[i] != ' ') {
 		    		greska=KodoviGresaka::PogresnaKomanda;
 					return false;
 		    	}
 		    	while (i<unos.size() && unos[i]==' ') i++; //Preskacemo razmake
 				if (i==unos.size()) {
 					greska=KodoviGresaka::NedostajeParametar;
 					return false;
 				}
 				y=0;
 				while (i<unos.size() && (unos[i]>='0' || unos[i]<='9')) {
 					y=y*10+(unos[i]-'0');
 					i++;
 				}
 				while (i<unos.size() && unos[i]==' ') i++; //Pomjeramo na kraj unosa
 				if (i!=unos.size()) {
 					greska=KodoviGresaka::PogresnaKomanda;
 					return false;
 				}
 				komanda=Komande::Deblokiraj;
 				return true;
 			}
 			
 			if (unos[i]=='Z' || unos[i]=='K') {
 			 	int p(i++);
 			 	//provjerimo da li su samo razmaci do kraja stringa
 			 	while (i<unos.size()) {
 			 		if (unos[i]!=' ') { greska=KodoviGresaka::SuvisanParametar; return false; }
 			 		i++;
 			 	}
 			    if (unos[p]=='Z') {
 			 		komanda=Komande::ZavrsiIgru;
 			 		return true;
 			 	}
 			 	komanda=Komande::KreirajIgru; 
 			 	return true;
 			 }
 			 
 			 if (unos[i]=='P' && i<unos.size()-1 && unos[i+1]=='O') {
 			 	i=i+2;
 			 	while (i<unos.size()) {
 			 		if (unos[i]!=' ') { greska=KodoviGresaka::SuvisanParametar; return false; }
 			 		i++;
 			 	}
 			 	komanda=Komande::PrikaziOkolinu;
 			 	return true;
 			 }
 			 greska=KodoviGresaka::PogresnaKomanda;
 			 return false;
 		}
 		i++;
 	}
 	return false;
 }
 
 void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0) {
 	//Moras hvatati izuzetke!!!
 	if (komanda==Komande::PomjeriJednoMjesto) {
 		try{
 			if (Idi(polja, x, y, p_smjer)==Status::KrajPobjeda) {
 			cout << "Bravo, obisli ste sva sigurna polja" << endl;
 			//Očistimo matricu
 			for (int i=0; i<polja.size(); i++) {
 				for (int j=0; j<polja.size(); j++) {
 					polja[x][y]=Polje::Prazno;
 				}
 			}
 			throw std::runtime_error ("Igra zavrsena");
 			return ;
 			}
 			if (Idi(polja, x, y, p_smjer)==Status::KrajPoraz) {
 				cout << "Nagazili ste na minu" << endl;
 				//Očistimo matricu
 				for (int i=0; i<polja.size(); i++) {
 					for (int j=0; j<polja.size(); j++) {
 						polja[x][y]=Polje::Prazno;
 					}
 				}
 				throw std::runtime_error ("Igra zavrsena");
 				return ;
 				}
 			}
 			catch (std::out_of_range izuzetak) {
 				cout << izuzetak.what() << endl;
 				return;
 			}
 			catch (std:: logic_error izuzetak) {
 				cout << izuzetak.what() << endl;
 				return;
 			}
 		cout << "Tekuca pozicija igraca je (" << x << "," << y <<")" << endl;
 		return;
 	}
 	if (komanda==Komande::PomjeriDalje) {
 		try{
 			if (Idi(polja, x, y, p_x, p_y)==Status::KrajPobjeda) {
 			cout << "Bravo, obisli ste sva sigurna polja" << endl;
 			//Očistimo matricu
 			for (int i=0; i<polja.size(); i++) {
 				for (int j=0; j<polja.size(); j++) {
 					polja[x][y]=Polje::Prazno;
 				}
 			}
 			throw std::runtime_error ("Igra zavrsena");
 			return ;
 			}
 			if (Idi(polja, x, y, p_x, p_y)==Status::KrajPoraz) {
 				cout << "Nagazili ste na minu" << endl;
 				//Očistimo matricu
 				for (int i=0; i<polja.size(); i++) {
 					for (int j=0; j<polja.size(); j++) {
 						polja[x][y]=Polje::Prazno;
 					}
 				}
 				throw std::runtime_error ("Igra zavrsena");
 				return ;
 				}
 			}
 			catch (std::out_of_range izuzetak) {
 				cout << izuzetak.what() << endl;
 				return;
 			}
 			catch (std:: logic_error izuzetak) {
 				cout << izuzetak.what() << endl;
 				return;
 			}
 		cout << "Tekuca pozicija igraca je (" << x << "," << y <<")" << endl;
 		return;
 	}
 	
 	if (komanda==Komande::Blokiraj) {
 		try {
 			BlokirajPolje(polja, x, y);
 		}
 		catch (std::domain_error izuzetak) {
 			cout << izuzetak.what() << endl; 
 		}
 		return;
 	}
 	if (komanda==Komande::Deblokiraj) {
 		try {
 			DeblokirajPolje(polja, x, y);
 		}
 		catch (std::domain_error izuzetak) {
 			cout << izuzetak.what();
 		}	
 		return;
 	}
 	if (komanda==Komande::PrikaziOkolinu) {
 		try {
 			auto mat(PrikaziOkolinu(polja, x, y));
 			for (int i=0; i<mat.size(); i++) {
 				for (int j=0; j<mat[i].size(); j++) {
 					if (j==mat[i].size()-1) { cout << int (mat[i][j]); }
 					else cout << int (mat[i][j]) << " ";
 				}
 				cout << endl;
 			}
 		}
 		catch (std::domain_error izuzetak) {
 			cout << izuzetak.what() << endl;
 		}
 		return;
 	}
 	if (komanda==Komande::ZavrsiIgru) {
 		//Očistimo matricu
 		for (int i=0; i<polja.size(); i++) {
 			for (int j=0; j<polja.size(); j++) {
 				polja[x][y]=Polje::Prazno;
 			}
 		}
 		throw std::runtime_error ("Igra zavrsena");
 		return ;
 	}
 	if (komanda==Komande::KreirajIgru ) { //Bolja verzija od tvoje 1000x
 		int n;
 		cout << "Unesite broj polja: ";
 		cin >> n;
 		std::vector<std::vector<int>> mine;
 		cout << "Unesite pozicije mina: "; 
 		for (;;) {
 			char znak;
 			bool ima_greska(false);
 			int x, y;
 			cin >> znak;
 			if (znak=='.') break;
 			if (znak!='(') ima_greska=true;
 			if (!ima_greska) {
 				cin >> x >> znak;
 				if(!cin || znak !=',') ima_greska = true;
 			}
 			if (!ima_greska) {
 				cin >> y >> znak;
 				if (!cin || znak!=')') ima_greska = true;
 			}
 			if (ima_greska || x<0 || x>=n || y<0 || y>=n) {
 				cin.clear();
 				cin.ignore(1000, '\n');
 				cout << "Greska, unesite ponovo!" << endl;
 			}
 			else mine.push_back({x, y});
 		}
 		polja=KreirajIgru(n, mine);
 	}
 }

int main (){
	try{
		Tabla polja;
		int x_p(0), y_p(0);
    	for (; ;) {
    		Komande komanda;
			Smjerovi smjer;
			KodoviGresaka greska;
			int x, y;
    		cout << "Unesite komandu: ";
    		if (UnosKomande(komanda, smjer, x, y, greska)) {
    			IzvrsiKomandu(komanda, polja, x_p, y_p, smjer, x, y);
    		}
    		else PrijaviGresku(greska);
    		}
    	}
    catch (std:: runtime_error) {
    	cout << "Dovidjenja!" << endl; 
    }
	return 0;
}

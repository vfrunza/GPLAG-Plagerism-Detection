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

enum class Polje {
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};

typedef std::vector<std::vector<Polje>> Tabla;

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

Tabla KreirajIgru(int n, std::vector<std::vector<int>> &mine){

	for(int i(0); i < mine.size()-1; i++){
		if(mine.at(i).size() != mine.at(i+1).size()) throw std::domain_error("Ilegalan format zadavanja mina");
		
	}
	if(n <= 0) throw std::domain_error("Ilegalna velicina");
	
	for(int i(0); i < mine.size(); i++){
		for(int j(0); j < mine.at(i).size(); j++){
			if(mine.at(i).at(j) < 0 || mine.at(i).at(j) > n) throw std::domain_error("Ilegalne pozicije mina");
		}
	}
	
	
	Tabla tablica(n,std::vector<Polje> (n));
	
	for(int i(0); i < n; i++){
		for(int j(0); j < n; j++){
			for(int k(0); k < mine.size(); k++){
				if(i == mine.at(k).at(0) && j == mine.at(k).at(1)){
					Polje mina;
					mina = Polje::Mina;
					tablica.at(i).at(j) = mina;
					break;
				}
				if(i != mine.at(k).at(0) || j != mine.at(k).at(1)){
					Polje prazno;
					prazno = Polje::Prazno;
					tablica.at(i).at(j) = prazno;
				}
					
			}
		}
	
	}

	return tablica;
}

int broji(const Tabla &polja, int x, int y){
	int brojac(0);
	for(int i(x-1); i <= x+1; i++){
		if(i < 0 || i > polja.size()) continue;
		for(int j(y-1); j <= y+1; j++){
			//if(x < 0 || x > polja.size() || y < 0 || y > polja[0].size()) continue;
			if(j < 0 || j > polja[0].size()) continue;
			//if(polja[x][y] == Polje::Mina) ;
			if(polja[i][j] == Polje::Mina){
				brojac++;
				if(i == x && j == y) brojac--;
			}
		}
	}
	return brojac;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	std::vector<std::vector<int>> Matrica(3, std::vector<int> (3));
	int red(0), kolona(0);
	if((x < 0 || x > polja.size()) ||(y < 0 || y > polja.at(0).size())) throw std::domain_error("Polje (x, y) ne postoji");
	
	for(int i(x-1); i <= x+1; i++){
		for(int j(y-1); j <= y+1; j++){
			Matrica[red][kolona] = broji(polja, i, j);
			kolona++;
		}
		kolona = 0;
		red++;
	}
	return Matrica;
}

void BlokirajPolje (Tabla &polja, int x, int y){
	if((x < 0 || x > polja.size()) || (y < 0 || y > polja[0].size())) throw std::domain_error("Polje (x,y) ne postoji");
	if(polja.at(x).at(y) == Polje::BlokiranoPosjeceno || polja.at(x).at(y) == Polje::BlokiranoPrazno || polja.at(x).at(y) == Polje::BlokiranoMina);// break;
	else if(polja.at(x).at(y) == Polje::Prazno) polja.at(x).at(y) = Polje::BlokiranoPrazno;
	else if(polja.at(x).at(y) == Polje::Posjeceno) polja.at(x).at(y) = Polje::BlokiranoPosjeceno;
	else if(polja.at(x).at(y) == Polje::Mina) polja.at(x).at(y) = Polje::BlokiranoMina;
}

void DeblokirajPolje (Tabla &polja, int x, int y){
	if((x < 0 || x > polja.size()) || (y < 0 || y > polja[0].size())) throw std::domain_error("Polje (x,y) ne postoji");
	if(polja.at(x).at(y) == Polje::Posjeceno || polja.at(x).at(y) == Polje::Prazno || polja.at(x).at(y) == Polje::Mina);
	else if(polja.at(x).at(y) == Polje::BlokiranoPrazno) polja.at(x).at(y) = Polje::Prazno;
	else if(polja.at(x).at(y) == Polje::BlokiranoPosjeceno) polja.at(x).at(y) = Polje::Posjeceno;
	else if(polja.at(x).at(y) == Polje::BlokiranoMina) polja.at(x).at(y) = Polje::Mina;
}

void gore(Tabla &tabla, int &x, int &y){
	tabla[x][y] = Polje::Posjeceno;
	x--;
	if(tabla[x][y] == Polje::BlokiranoPosjeceno || tabla[x][y] == Polje::BlokiranoPrazno || tabla[x][y] == Polje::BlokiranoMina)
	throw std::logic_error("Blokirano polje");
}

void dolje(Tabla &tabla, int &x, int &y){
	tabla[x][y] = Polje::Posjeceno;
	x++;
	if(tabla[x][y] == Polje::BlokiranoPosjeceno || tabla[x][y] == Polje::BlokiranoPrazno || tabla[x][y] == Polje::BlokiranoMina)
	throw std::logic_error("Blokirano polje");
}

void gorelijevo(Tabla &tabla, int &x, int &y){
	tabla[x][y] = Polje::Posjeceno;
	x--; y--;
	if(tabla[x][y] == Polje::BlokiranoPosjeceno || tabla[x][y] == Polje::BlokiranoPrazno || tabla[x][y] == Polje::BlokiranoMina)
	throw std::logic_error("Blokirano polje");
}

void goredesno(Tabla &tabla, int &x, int &y){
	tabla[x][y] = Polje::Posjeceno;
	x--; y++;
	if(tabla[x][y] == Polje::BlokiranoPosjeceno || tabla[x][y] == Polje::BlokiranoPrazno || tabla[x][y] == Polje::BlokiranoMina)
	throw std::logic_error("Blokirano polje");
}

void desno(Tabla &tabla, int &x, int &y){
	tabla[x][y] = Polje::Posjeceno;
	y++;
	if(tabla[x][y] == Polje::BlokiranoPosjeceno || tabla[x][y] == Polje::BlokiranoPrazno || tabla[x][y] == Polje::BlokiranoMina)
	throw std::logic_error("Blokirano polje");
}

void lijevo(Tabla &tabla, int &x, int &y){
	tabla[x][y] = Polje::Posjeceno;
	y--;
	if(tabla[x][y] == Polje::BlokiranoPosjeceno || tabla[x][y] == Polje::BlokiranoPrazno || tabla[x][y] == Polje::BlokiranoMina)
	throw std::logic_error("Blokirano polje");
}

void doljelijevo(Tabla &tabla, int &x, int &y){
	tabla[x][y] = Polje::Posjeceno;
	y--; x++;
	if(tabla[x][y] == Polje::BlokiranoPosjeceno || tabla[x][y] == Polje::BlokiranoPrazno || tabla[x][y] == Polje::BlokiranoMina)
	throw std::logic_error("Blokirano polje");
}

void doljedesno(Tabla &tabla, int &x, int &y){
	tabla[x][y] = Polje::Posjeceno;
	y++; x++;
	if(tabla[x][y] == Polje::BlokiranoPosjeceno || tabla[x][y] == Polje::BlokiranoPrazno || tabla[x][y] == Polje::BlokiranoMina)
	throw std::logic_error("Blokirano polje");
}


Status Idi(Tabla &tabla, int &x, int &y, Smjerovi smjer){

	void (*npf[8])(Tabla&,int&,int&) = {gorelijevo, gore, goredesno, desno, doljedesno, dolje, doljelijevo, lijevo};
	int broj;
	for(int i(0); i < 8; i++){
		if(smjer == Smjerovi(i)){
			broj = i;
			break;
		}
	}
	try{
	npf[broj](tabla,x,y);
	}
	catch(std::logic_error){
		throw;
	}
	if(x < 0 || x > tabla.size() || y < 0 || y > tabla[0].size()) throw std::out_of_range("Izlazak van igrace table");
	if(tabla[x][y] == Polje::Mina){
		for(int i(0); i < tabla.size(); i++){
			for(int j(0); j < tabla.at(i).size(); j++){
				tabla[i][j] = Polje::Prazno;
			}
		}
		 return Status::KrajPoraz;
	}
	
	for(int i(0); i < tabla.size(); i++){
		for(int j(0); j < tabla.at(i).size(); j++){
			if(tabla[i][j] == Polje::Posjeceno || tabla[i][j] == Polje::Mina) return Status::KrajPobjeda;
		}
	}
	
	return Status::NijeKraj;
}

Status Idi(Tabla &tabla, int &x, int &y, int NoviX, int NoviY){

	if(NoviX < 0 || NoviX > tabla.size()) throw std::out_of_range("Izlazak van igrace table");
	if(NoviY < 0 || NoviY > tabla[0].size()) throw std::out_of_range("Izlazak van igrace table");
	
	x = NoviX;
	y = NoviY;
	
	if(tabla[x][y] == Polje::BlokiranoPosjeceno || tabla[x][y] == Polje::BlokiranoPrazno || tabla[x][y] == Polje::BlokiranoMina)
	throw std::logic_error("Blokirano polje");
	
	if(tabla[x][y] == Polje::Mina){
		for(int i(0); i < tabla.size(); i++){
			for(int j(0); j < tabla.at(i).size(); j++){
				tabla[i][j] = Polje::Prazno;
			}
		}
		 return Status::KrajPoraz;
	}
	
	for(int i(0); i < tabla.size(); i++){
		for(int j(0); j < tabla.at(i).size(); j++){
			if(tabla[i][j] == Polje::Posjeceno || tabla[i][j] == Polje::Mina) return Status::KrajPobjeda;
		}
	}
	
	return Status::NijeKraj;
	
}

void PrijaviGresku(KodoviGresaka greska){
	std::string NizStringova[4] = {"Nerazumljiva Komanda", "Komanda trazi parametar koji nije naveden!", "Parametar komande nije ispravan!", "Zadan je suvisan parametar nakon komande!"};
	for(int i(0); i < 4; i++){
		if(greska == KodoviGresaka(i)){
			 std::cout<<NizStringova[i];
			 break;
		}
	}
}

int BROJACRIJECI(std::string s){
	int razmak(1), BrojRijeci(0);
	for(int i(0); i < s.length(); i++){
		if(s.at(i) == ' '){
			razmak = 1;
		}
		else if(razmak){
			BrojRijeci++;
			razmak = 0;
		}
	}
	return BrojRijeci;
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	std::string komand;
	std::cout<<"Unesite komandu: "<<std::endl;
	std::getline(std::cin,komand);
	int Rijeci(BROJACRIJECI(komand));
	if(Rijeci == 0 || Rijeci){
		greska = KodoviGresaka::PogresnaKomanda;
		return false;
	}
	//std::string ValidneKomande[7] = {"P1","P>","B","D","PO","Z","K"};
	
	/*if(Rijeci > 3){
		greska = KodoviGresaka::SuvisanParametar;
		return false;
	}*/
	std::string pomocni;
	std::string pomocnadruga;
	std::string pomocnatreca;
	int razmak(1), BrojRijeci(0),brojac_komandi(0),indexKomande(0),brojac_parametra(0);
	std::string ValidneKomande[7] = {"P1","P>","B","D","PO","Z","K"};
	for(int i(0); i < komand.length(); i++){
		if(komand.at(i) == ' '){
			razmak = 1;
		}
		else if(razmak){
			BrojRijeci++;
			razmak = 0;
			if(BrojRijeci == 1){
				for(int j(i); komand[j] != ' ' && j < komand.length(); j++){
					pomocni.push_back(komand[j]);
				}
				for(int k(0); k < 7; k++){
					if(pomocni == ValidneKomande[k]){
					 	indexKomande = k;
					 	break;
					}
					brojac_komandi++;
				}
				if(brojac_komandi == 7){
					greska = KodoviGresaka::PogresnaKomanda;
					return false;
				}
				for(int p(4); p <= 6; p++){
					if(pomocni == ValidneKomande[p] && Rijeci > 1){
						greska = KodoviGresaka::SuvisanParametar;
						return false;
					}
				}
				if(pomocni == ValidneKomande[0] && Rijeci > 2){
					greska = KodoviGresaka::SuvisanParametar;
					return false;
				}
				for(int q(1); q <= 3; q++){
					if(pomocni == ValidneKomande[q] && (Rijeci > 3)){
						greska = KodoviGresaka::SuvisanParametar;
						return false;
					}
					if(pomocni == ValidneKomande[q] && Rijeci < 3){
						greska = KodoviGresaka::NedostajeParametar;
						return false;
					}
				}
			}
			if(BrojRijeci == 2){
				/*for(int i(4); i <= 6; i++){
					if(komanda == ValidneKomande[i]) greska = KodoviGresaka::SuvisanParametar;
				}*/
				//std::string pomocnadruga;
				for(int j(i); komand[j] != ' ' && j < komand.length(); j++){
					pomocnadruga.push_back(komand[j]);
				}
				if(pomocni != ValidneKomande[0]){
					for(int j(0); j < pomocnadruga.length(); j++){
						if(pomocnadruga[j] < '0' || pomocnadruga[j] > '9'){
							greska = KodoviGresaka::SuvisanParametar;
							return false;
						}
					}
					x = std::stoi(pomocnadruga);
				}
				if(pomocni == ValidneKomande[0]){
					std::string ValidniParametar[8] = {"GL","G","GD","D","DoD","Do","DoL","L"};
					for(int j(0); j < 8; j++){
						if(pomocnadruga == ValidniParametar[j]){
							smjer = Smjerovi(j);
							break;
						}
						brojac_parametra++;
					}
					if(brojac_parametra == 8){
						greska = KodoviGresaka::SuvisanParametar;
						return false;
					}
				}
				
			}
			if(BrojRijeci == 3){
				for(int j(i); komand[j] != ' ' && j < komand.length(); j++){
					pomocnatreca.push_back(komand[j]);
				}
				for(int j(0); j < pomocnatreca.length(); j++){
					if(pomocnatreca[j] < '0' || pomocnatreca[j] > '9'){
						greska = KodoviGresaka::SuvisanParametar;
						return false;
					}
				}
				y = std::stoi(pomocnatreca);
			}
		}
	}
		/*for(int i(0); i < 7; i++){
			if(pomocni == ValidneKomande[i]){
				komanda = Komande(i);
				break;
			}
		}*/
		komanda = Komande(indexKomande);
		
		return true;
}

void IzvrsiKomandu(Komande komanda,Tabla &polja, int &x, int &y,Smjerovi p_smjer = Smjerovi::Gore,int p_x = 0, int p_y = 0){
	double BrojPolja(0);
	if(komanda == Komande(0)){
		try{
		Status RezIdi(Idi(polja,x,y,p_smjer));
		if(RezIdi == Status::NijeKraj) std::cout<<"Tekuca pozicija igraca je ("<<x<<", "<<y<<")"<<std::endl;
		else if(RezIdi == Status::KrajPoraz) std::cout<<"Nagazili ste na minu"<<std::endl;
		else if(RezIdi == Status::KrajPobjeda) std::cout<<"Bravo, obisli ste sva sigurna polja"<<std::endl;
		}
		catch(std::out_of_range izuzetak){
			std::cout<<izuzetak.what();
		}
		catch(std::logic_error izuzetak){
			std::cout<<izuzetak.what();
		}
	}
	if(komanda == Komande(1)){
		try{
		Status RezIdi(Idi(polja,x,y,p_x,p_y));
		if(RezIdi == Status::NijeKraj) std::cout<<"Tekuca pozicija igraca je ("<<x<<", "<<y<<")"<<std::endl;
		else if(RezIdi == Status::KrajPoraz){
			 std::cout<<"Nagazili ste na minu"<<std::endl;
			 komanda = Komande(5);
		}
		else if(RezIdi == Status::KrajPobjeda){
			std::cout<<"Bravo, obisli ste sva sigurna polja"<<std::endl;
			komanda = Komande(5);
		}
		}
		catch(std::out_of_range izuzetak){
			std::cout<<izuzetak.what();
		}
		catch(std::logic_error izuzetak){
			std::cout<<izuzetak.what();
		}
	}
	
	if(komanda == Komande(2)){
		try{
			BlokirajPolje(polja,x,y);
		}
		catch(std::domain_error izuzetak){
			std::cout<<izuzetak.what();
		}
	}
	if(komanda == Komande(3)){
		try{
			DeblokirajPolje(polja,x,y);
		}
		catch(std::domain_error izuzetak){
			std::cout<<izuzetak.what();
		}
	}
	if(komanda == Komande(4)){
		try{
		std::vector<std::vector<int>> matrica(PrikaziOkolinu(polja,x,y));
		for(int i(0); i < matrica.size(); i++){
			for(int j(0); j < matrica[0].size(); j++){
				std::cout<<matrica.at(i).at(j)<<" ";
			}
			std::cout<<std::endl;
		}
		}
		catch(std::domain_error izuzetak){
			std::cout<<izuzetak.what();
		}
	}
	
	if(komanda == Komande(5)){
		for(int i(0); i < polja.size(); i++){
			for(int j(0); j < polja[0].size(); j++){
				polja[i][j] = Polje::Prazno;
			}
		}
		throw std::runtime_error("Igra zavrsena");
	}
	
	if(komanda == Komande(6)){
		do{
		std::cout<<"Unesite broj polja: ";
		std::cin>>BrojPolja;
		if(BrojPolja <= 0 || BrojPolja != (int)BrojPolja || std::cin){
			std::cout<<"Greska, unesite ponovo!"<<std::endl;
		}
		}
		while(BrojPolja <= 0 || BrojPolja != (int)BrojPolja || std::cin);
	}
	
	
	
}

int main ()
{
	/*int broj;
	std::cout<<"Unesi broj: ";
	std::cin>>broj;
	std::vector<std::vector<int>> v{{0,0},{0,2},{1,3}};
	try{
	Tabla tabe(KreirajIgru(broj, v));
	try{
	BlokirajPolje(tabe,0,0);
	DeblokirajPolje(tabe,0,0);
	}
	catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what();
		return 0;
	}
	for(int i(0); i < tabe.size(); i++){
		for(int j(0); j < tabe.at(i).size(); j++){
			std::cout<<(int)tabe.at(i).at(j);//<<" ";
		}
		std::cout<<std::endl;
	}
	}
	catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what();
	}*/
	/*Komande komanda;
	Sm
	if(UnosKomande)*/
	return 0;
}
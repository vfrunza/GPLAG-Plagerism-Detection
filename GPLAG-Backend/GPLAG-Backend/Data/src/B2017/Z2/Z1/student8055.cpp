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
#include <sstream>
#include <algorithm> 

bool domen (char x){
	if (x == ' '|| x=='0'|| x=='1'|| x=='2'|| x=='3'|| x=='4'|| x=='5'|| x=='6'|| x=='7'|| x=='8'|| x=='9')return true; 
	return false; 
}

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

enum class Komande {
PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};

typedef std::vector<std::vector<Polje>> Tabla;

bool domen (int v, int x, int y) {
	return x>=0 && y>=0 && x<v && y<v  ;
}
bool f (std::string &rijec, int &x, int &y, KodoviGresaka &greska, int c){
		if (rijec.size()==2){
			greska = KodoviGresaka::NedostajeParmetar; 
			return false; 
		}
	 	rijec.erase(rijec.begin()+c);
	 	while (rijec.at(0)==' ') rijec.erase(rijec.begin());
	 	for (int i=0; i<rijec.size(); i++) 
	 		if (!domen (rijec.at(i))) {
	 			greska = KodoviGresaka::NeispravanParametar;
	 			return false;
	 		}
	 	std::string parametar1, parametar2; 
	 	int k(0);
	 	while (k<rijec.size() && k!=' ')parametar1+=rijec.at(k);
	 	while (k<rijec.size() && k==' ') k++;
	 	while (k<rijec.size()) k++; 
	 	if (parametar1.size()==0 || parametar2.size()==0)
	 		{
	 			greska = KodoviGresaka::NedostajeParmetar;
	 			return false;
	 		}
	 	x = std::stoi (parametar1);
	 	y = std::stoi (parametar2); 
	return true; 	
}

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	if (n<=0) throw std::domain_error("Ilegalna veličina"); 
	Tabla tabla(n, std::vector<Polje>(n, Polje::Prazno)); 
	for (auto x : mine){
		if (x.size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
	  	int i(x.at(0));
		int j(x.at(1)); 
		if (!domen(n, i, j)) throw std::domain_error("Ilegalne pozicije mina"); 
		tabla.at(i).at(j) = Polje::Mina; 
	}
	return tabla; 
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	if (!domen(polja.size(), x, y)) throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	std::vector<std::vector<int>> v (3, std::vector<int>(3)); 
	for (int i=-1; i<=1; i++){
		for (int j=-1; j<=1; j++){
			int counter(0); 
			for (int k=-1; k<=1; k++){ 
				for (int h=-1; h<=1; h++) {
					if (k==0 && h==0) continue;  //da ne brojimo samo polje
					if (domen (polja.size(), x+i+k, y+j+h) &&  polja.at(x+i+k).at(y+j+h) == Polje::Mina) counter++;
				}
			}
		v.at(i+1).at(j+1) = counter;
		}
	}
return v; 
}
void BlokirajPolje(Tabla &polja, int x, int y){
	if (!domen(polja.size(), x, y)) throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	if (polja.at(x).at(y) == Polje::Prazno) polja.at(x).at(y) = Polje::BlokiranoPrazno;
	if (polja.at(x).at(y) == Polje::Posjeceno) polja.at(x).at(y) = Polje::BlokiranoPosjeceno;
	if (polja.at(x).at(y) == Polje::Mina) polja.at(x).at(y) = Polje::BlokiranoMina; 
}
void DeblokirajPolje( Tabla &polja, int x, int y) {
	if (!domen(polja.size(), x, y)) throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	if (polja.at(x).at(y) == Polje::BlokiranoPrazno) polja.at(x).at(y) = Polje::Prazno;
	if (polja.at(x).at(y) == Polje::BlokiranoPosjeceno) polja.at(x).at(y) = Polje::Posjeceno;
	if (polja.at(x).at(y) == Polje::BlokiranoMina) polja.at(x).at(y) = Polje::Mina; 
}

Status Idi(Tabla &polja, int &x, int&y, Smjerovi smjer){
	
	polja.at(x).at(y)=Polje::Posjeceno;
	if (smjer == Smjerovi::Desno) y++;
	if (smjer == Smjerovi::Lijevo) y--;
	if (smjer == Smjerovi::Gore) x--;
	if (smjer == Smjerovi::Dolje) x++;
	if (smjer == Smjerovi::GoreDesno) {
		x--; 
		y++;
	}
	if (smjer == Smjerovi::GoreLijevo){
		x--;
		y--;
	}
	if (smjer == Smjerovi::DoljeDesno){
		x++;
		y++;
	}
	if (smjer == Smjerovi::DoljeLijevo) {
		x++; 
		y--;
	}
	if (!domen(polja.size(), x, y)) throw std::out_of_range ("Izlazak van igrace table");
	if (polja.at(x).at(y)==Polje::BlokiranoPosjeceno || polja.at(x).at(y)==Polje::BlokiranoPrazno || polja.at(x).at(y)==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
	if (polja.at(x).at(y)==Polje::Mina) {
		for (int i=0; i<polja.size(); i++)
			for (int j=0; j<polja.size(); j++)
				polja.at(i).at(j) = Polje::Prazno;
		return Status::KrajPoraz;
	}
	for (auto x : polja) {
		for (auto y : x) {
			if (y!=Polje::Mina && y!=Polje::Posjeceno) 	return Status::NijeKraj;
		}
	}
	
	return Status::KrajPobjeda; 
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y) {
	polja.at(x).at(y)=Polje::Posjeceno;
	x = novi_x; 
	y = novi_y; 
	if (!domen(polja.size(), x, y)) throw std::out_of_range ("Izlazak van igrace table");
	if (polja.at(x).at(y)==Polje::BlokiranoPosjeceno || polja.at(x).at(y)==Polje::BlokiranoPrazno || polja.at(x).at(y)==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
	if (polja.at(x).at(y)==Polje::Mina) {
		for (int i=0; i<polja.size(); i++)
			for (int j=0; j<polja.size(); j++)
				polja.at(i).at(j) = Polje::Prazno;
		return Status::KrajPoraz;
	}
	for (auto x : polja) {
		for (auto y : x) {
			if (y!=Polje::Mina && y!=Polje::Posjeceno) 	return Status::NijeKraj;
		}
	}
	
	return Status::KrajPobjeda; 
}

void PrijaviGresku (KodoviGresaka k ) {
		
		if (KodoviGresaka::PogresnaKomanda == k) std::cout<<"Nerazumljiva komanda!"; 
		if (KodoviGresaka::NedostajeParmetar == k) std::cout<<"Komanda trazi parametar koji nije naveden!";
		if (KodoviGresaka::SuvisanParametar == k) std::cout<<"Parametar komande nije ispravan!"; 
		if (KodoviGresaka::NeispravanParametar == k) std::cout<<"Zadan je suvisan parametar nakon komande!";
}
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	std::string rijec;
	std::getline (std::cin, rijec);
	while (rijec.at(0)==' ') rijec.erase(rijec.begin()); 
	while (rijec.at(rijec.size()-1) == ' ') rijec.erase (rijec.end()-1); //brisanje suvisnih razmaka ako ih ima   
	std::vector<std::string> v { "P1", "P>", "B","D","PO", "Z", "K" };
	auto  iterator1 = std::find(std::begin(v), std::end(v), rijec.substr(0, 1));
	iterator1 = std::find(std::begin(v), std::end(v), rijec.substr(0, 2)); 
		std::string y1;
		if (iterator1!=std::end(v)){
			 y1 = *iterator1;
		}
		else if (iterator1==std::end(v) ) {
		greska = KodoviGresaka::PogresnaKomanda; 
		return false; 
	}
	if (y1 == "P1"){
		if (rijec.size()==2) {
			greska = KodoviGresaka::NedostajeParmetar; 
			return false; 
		}
		komanda = Komande::PomjeriJednoMjesto;
		rijec.erase(rijec.begin()+1); 
		while (rijec.at(0)==' ') rijec.erase(rijec.begin()); 
		std::vector<std::string> v1 {"GL", "G", "GD", "D", "DoD", "Do", "DoL","L"}; 
			auto iterator2 = std::find(std::begin(v1), std::end(v1), rijec);
			if (iterator2!=std::end(v1) ) 
			{
				smjer = Smjerovi(iterator2 - std::begin(v1)+1); 
			}
			else if (iterator2==std::end(v1) ) {
			greska = KodoviGresaka::NeispravanParametar;
			return false;
			}
	}
	if (y1 == "P>"){
		if (! f(rijec, x, y, greska, 1) ) return false;
		komanda = Komande::PomjeriDalje;
	}
	if (y1 == "B") {
		if (! f(rijec, x, y, greska, 0)) return false; 
		komanda = Komande::Blokiraj;
	}
	if (y1 == "D") {
		if (! f(rijec, x, y, greska, 0)) return false; 
		komanda = Komande::Deblokiraj;
	}
	if (y1 == "Z" ) {
		if (rijec.size()!=1) {
			greska = KodoviGresaka::SuvisanParametar;
			return false; 
		}
		komanda = Komande::ZavrsiIgru;
	}
		if (y1 == "K" ) {
		if (rijec.size()!=1) {
			greska = KodoviGresaka::SuvisanParametar;
			return false; 
		}
		komanda = Komande::KreirajIgru;
	}
	if (y1 == "Z") {
		if (rijec.size()!=1) {
			greska = KodoviGresaka::SuvisanParametar;
			return false; 
		}
		komanda = Komande::ZavrsiIgru;
	}
	if (y1 == "PO") {
		if (rijec.size()!=2) {
			greska = KodoviGresaka::SuvisanParametar;
			return false; 
		}
		komanda = Komande::PrikaziOkolinu;
	}
	return true; 
}
void IzvrsiKomandu (Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x =0, int p_y=0){
	
}






int main ()
{
	//AT2 (c9) - funkcija Okolina primjer iz postavke
    std::vector<std::vector<int>> mine = {{0,1}, {0,4}, {1,3}, {1,4}, {2,0}, {2,1}, {2,3}} ;
    std::vector<std::vector<Polje>> tabla = KreirajIgru(5, mine);
    std::vector<std::vector<int>> okolina = PrikaziOkolinu(tabla, 1, 1);
    for(int i = 0; i < okolina.size(); i++)
    {
      for(int j = 0; j < okolina[i].size(); j++) std::cout << okolina[i][j] << " ";
      std::cout << std::endl;
    }
	
	
	
	return 0;
}
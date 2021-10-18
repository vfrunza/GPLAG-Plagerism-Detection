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

enum class Polje    { Prazno,Posjeceno,Mina,BlokiranoPrazno,BlokiranoPosjeceno,BlokiranoMina };
enum class Smjerovi { GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo };
enum class Status   { NijeKraj, KrajPoraz, KrajPobjeda };
enum class KodoviGresaka { PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar };

enum class Komande { PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru };


typedef std::vector< std::vector<Polje>> Tabla;

// test za matricu mina
bool Test(std::vector<std::vector<int>> mat){
	for(int i(0);i<mat.size();i++)
		if(mat.at(i).size()!=2)return true;
	return false;	
}

// radi ispravno
Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	
	// provjera formata mina
	if(Test(mine))throw std::domain_error("Ilegalan format zadavanja mina");
	
	// kreiranje inicijalne table
	std::vector<std::vector<Polje>> tabla(n,std::vector<Polje>(n,Polje::Prazno));
	
	// kreiranje mina na mapi
	for(int i(0);i<mine.size();i++)
		tabla.at(mine.at(i).at(0)).at(mine.at(i).at(1)) = Polje::Mina;
	
	return tabla;
}
// RADIIIIIIIIIII F JEAAHH
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	
	if(x<0 || x>=polja.size() || y<0 || y>=polja.size() ){
		std::cout<<"Polje ("<<x<<","<<y<<") ne postoji";
		throw std::domain_error("");
		
	}
	std::vector<std::vector<int>> komsije;
	// locirati sva okolna polja(ukupno 9)
	for(int xoff(-1); xoff <= 1; xoff++){
		std::vector<int> pom2;
		for(int yoff(-1); yoff <= 1; yoff++){
			
			int i(x+xoff), j(x+yoff);
			// susjedna celija pokupi broj mina okolo sebe i trpa se u vektor
			if(i >= 0 && j >= 0 && i < polja.size() && j < polja.size()){
				int mine(0);
				// svaki susjed ima 9 novih susjeda i broji mine u svom komsiluku
				for(int xoff1(-1);xoff1<=1;xoff1++){
					for(int yoff1(-1);yoff1<=1;yoff1++){
						
						int i1(i+xoff1), j1(j+yoff1);
						// if radi testiranja indexa
						if(i1 >= 0 && j1 >= 0 && i1 < polja.size() && j1 < polja.size() )
							if(polja.at(i1).at(j1)==Polje::Mina)mine++;
					}
				}
				if( polja.at(i).at(j)==Polje::Mina)mine--;
				// prebrojao je mine i salje informaciju u vektor
				pom2.push_back(mine);
			}
			
		}
		// kad tri komsije prikupe informacije saljemo informacje vektora u matricu i praznimo vektor
		komsije.push_back(pom2);
	}
	// kad smo prikupili informacije o minama saljemo ih deminerima
	return komsije;
}
void BlokirajPolje(Tabla &polja, int x, int y){
	
	if(x<0 || y<0 || y>=polja.size() || x>=polja.size()){
		std::cout<<"Polje ("<<x<<","<<y<<") ne postoji";
		throw std::domain_error("");
	}
	
	if(polja.at(x).at(y)==Polje::Prazno)
		polja.at(x).at(y)=Polje::BlokiranoPrazno;
	else if(polja.at(x).at(y)==Polje::Mina)
		polja.at(x).at(y)=Polje::BlokiranoMina;
	else if(polja.at(x).at(y)==Polje::Posjeceno)
		polja.at(x).at(y)=Polje::BlokiranoPosjeceno;
}

void DeblokirajPolje(Tabla &polja, int x, int y){
	if(x<0 || y<0 || y>=polja.size() || x>=polja.size()){
		std::cout<<"Polje ("<<x<<","<<y<<") ne postoji";
		throw std::domain_error("");
	}
	
	if(polja.at(x).at(y)==Polje::BlokiranoPrazno)
		polja.at(x).at(y)=Polje::Prazno;
	else if(polja.at(x).at(y)==Polje::BlokiranoPosjeceno)
		polja.at(x).at(y)=Polje::Posjeceno;
	else if(polja.at(x).at(y)==Polje::BlokiranoMina)
		polja.at(x).at(y)=Polje::Mina;
}
bool Blokirano(Polje p){
	return(p == Polje::BlokiranoPosjeceno || p == Polje::BlokiranoPrazno || p == Polje::BlokiranoMina);
}
bool NemaPraznih(const Tabla &tabla){
	for(int i(0);i<tabla.size();i++){
		for(int j(0);j<tabla.size();j++){
			if(tabla.at(i).at(j)==Polje::Prazno)return false;
		}
	}
	return true;
}
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	int x1(x),y1(y);
	if(smjer == Smjerovi::Gore)  x1--;
	else if(smjer == Smjerovi::Dolje) x1++;
	else if(smjer == Smjerovi::Desno) y1++;
	else if(smjer == Smjerovi::Lijevo) y1--;
	else if(smjer == Smjerovi::GoreDesno ) { x1--; y1++;}
	else if(smjer == Smjerovi::GoreLijevo ){ x1--; y1--;}
	else if(smjer == Smjerovi::DoljeDesno ){ x1++; y1++;}
	else if(smjer == Smjerovi::DoljeLijevo){ x1++; y1--;}
	
	if(x1<0 || y1<0 || x1>=polja.size() || y1 >= polja.size()){
		
		throw std::out_of_range("Izlazak izvan igrace table");
	}
	else if( Blokirano( polja.at(x1).at(y1) ) ){
		throw std::logic_error("Blokirano polje");
	}	
	else {
		polja.at(x).at(y) = Polje::Posjeceno;
		x = x1; y = y1;
	}
	
	if( polja.at(x).at(y) == Polje::Mina ){
		for(int i(0);i<polja.size();i++)
			for(int j(0);j<polja.size();j++)
				polja.at(i).at(j) = Polje::Prazno;
		return Status::KrajPoraz;
	} 
	else if( NemaPraznih(polja))return Status::KrajPobjeda;
	else return Status::NijeKraj;
}
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	
	if(novi_x<0 || novi_x>=polja.size() || novi_y<0 || novi_y>=polja.size())
		throw std::out_of_range("Izlazak izvan igrace table");
	else if(Blokirano( polja.at(novi_x).at(novi_y) ) )
		throw std::logic_error("Blokirano polje");
	else{
		polja.at(x).at(y) = Polje::Posjeceno;
		x = novi_x; y = novi_y;
	}
	if( polja.at(x).at(y) == Polje::Mina ){
		
		for(int i(0);i<polja.size();i++)
			for(int j(0);j<polja.size();j++)
				polja.at(i).at(j) = Polje::Prazno;
		return Status::KrajPoraz;
		
	}
	else if( NemaPraznih(polja))return Status::KrajPobjeda;
	else return Status::NijeKraj;
}

void PrijaviGresku(KodoviGresaka g){
	if(g==KodoviGresaka::PogresnaKomanda)std::cout<<"Nerazumljiva komanda";
	else if(g==KodoviGresaka::NedostajeParametar)std::cout<<"Komanda trazi parametar koji nije naveden";
	else if(g==KodoviGresaka::NeispravanParametar)std::cout<<"Parametar komande nije ispravan";
	else if(g==KodoviGresaka::SuvisanParametar)std::cout<<"Zadan je suvisan parametar nakon komande";
}
bool UnosKomande(Komande &komande, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	
	return false;
}
int main ()
{
	
	return 0;
}
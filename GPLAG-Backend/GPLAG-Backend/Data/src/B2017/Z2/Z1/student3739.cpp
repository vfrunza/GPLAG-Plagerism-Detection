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
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina };
typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru (int n, const std::vector<std::vector<int>> &mine){
	Tabla igra;
	igra.resize(n);
	for(int i=0; i<n; i++){ 
		igra.at(i).resize(n);
	}
	
	for(int i=0; i<mine.size(); i++) {
		for(int j=0; j<mine.at(i).size(); j++) {
			if(mine.at(i).size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
			if(mine.at(i).at(j)>=n) throw std::domain_error("Ilegalne pozicije mina");
			else if(j==1) {
				igra.at(mine.at(i).at(0)).at(mine.at(i).at(1))=Polje::Mina;
			}
		}
	}
	return igra;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y) {
	for(int i=0; i<polja.size(); i++) {
		if(y>=polja.size()) throw std::domain_error ("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
		if(x>=polja[i].size()) throw std::domain_error ("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	}
	std::vector<std::vector<int>>pomocna;
	std::vector<std::vector<int>> vracamo;
	pomocna.resize(polja.size());
	for(int i=0; i<polja.size(); i++) pomocna.at(i).resize(polja.at(i).size());
	
	for(int i=0; i<polja.size(); i++) {
		for (int j=0; j<polja.at(i).size(); j++) {
			if(polja.at(i).at(j)==Polje::Mina) pomocna.at(i).at(j)=1;
		}
	}
	vracamo.resize(3);
	for(int i=0; i<3; i++) vracamo.at(i).resize(3);
	for(int i=-1; i<2; i++) {
		for(int j=-1; j<2; j++) {
			for(int m=-1; m<2; m++) {
				for(int n=-1; n<2; n++) {
					if(m==0 && n==0) {continue;}
					if(m+y+i<0 || n+x+j<0 || n+x+j>=pomocna.at(0).size() || m+y+i>=pomocna.size()) {continue;}
					vracamo[i+1][j+1]+=pomocna[m+y+i][n+x+j];
					
				}
			}
		}
	}
	return vracamo;
}
void DeblokirajPolje(Tabla &polja, int x, int y) {
	if(x>=polja.at(0).size() || y>=polja.size()) throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	if(polja.at(x).at(y)==Polje::BlokiranoPrazno) polja.at(x).at(y)=Polje::Prazno;
	else if(polja.at(x).at(y)==Polje::BlokiranoMina) polja.at(x).at(y)=Polje::Mina;
	else if(polja.at(x).at(y)==Polje::BlokiranoPosjeceno) polja.at(x).at(y)=Polje::Posjeceno;
}
void BlokirajPolje(Tabla &polja, int x, int y) {
	if(x>=polja.at(0).size() || y>=polja.size()) throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	if(polja.at(x).at(y)==Polje::Prazno) polja.at(x).at(y)=Polje::BlokiranoPrazno;
	else if(polja.at(x).at(y)==Polje::Mina) polja.at(x).at(y)=Polje::BlokiranoMina;
	else if(polja.at(x).at(y)==Polje::Posjeceno) polja.at(x).at(y)=Polje::BlokiranoPosjeceno;
}

enum class Smjerovi { GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo };
enum class Status { NijeKraj, KrajPoraz, KrajPobjeda};

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer) {
	int pocetnix(x), pocetniy(y);
	if(smjer==Smjerovi::GoreLijevo) {
		polja.at(x).at(y)=Polje::Posjeceno; x--; y--;
	}
	else if(smjer==Smjerovi::Gore) {
		polja.at(x).at(y)=Polje::Posjeceno; x--;
	}
	else if(smjer==Smjerovi::GoreDesno) {
		polja.at(x).at(y)=Polje::Posjeceno; x--;y++;
	}
	else if(smjer==Smjerovi::Desno) {
		polja.at(x).at(y)=Polje::Posjeceno; y++;
	}
	else if(smjer==Smjerovi::DoljeDesno) {
		polja.at(x).at(y)=Polje::Posjeceno; x++; y++;
	}
	else if(smjer==Smjerovi::Dolje) {
		polja.at(x).at(y)=Polje::Posjeceno; x++;
	}
	else if(smjer==Smjerovi::DoljeLijevo) {
		polja.at(x).at(y)=Polje::Posjeceno; x++;y--;
	}
	else if(smjer==Smjerovi::Lijevo) {
		polja.at(x).at(y)=Polje::Posjeceno; y--;
	}
	if(x<0 || y<0 ) {
		x=pocetnix;
		y=pocetniy;
		throw std::out_of_range ("Izlazak van igrace table");
	}
	if(x>=polja.size() || y>=polja.size()) {
		x=pocetnix;
		y=pocetniy;
		throw std::out_of_range("Izlazak van igrace table");
	}
	if(polja.at(x).at(y)==Polje::BlokiranoMina) {
		x=pocetnix;
		y=pocetniy;
		throw std::out_of_range ("Blokirano polje");
	}
	if(polja.at(x).at(y)==Polje::BlokiranoPosjeceno) {
		x=pocetnix;
		y=pocetniy;
		throw std::out_of_range("Blokirano polje");
	}
	if(polja.at(x).at(y)==Polje::BlokiranoPrazno){
		x=pocetnix;
		y=pocetniy;
		throw std::out_of_range("Blokirano polje");
	}
		if(polja.at(x).at(y)==Polje::Mina){
			for(int i=0; i<polja.size(); i++) {
				for(int j=0; j<polja.at(i).size(); j++) {
					polja.at(i).at(j)=Polje::Prazno;
				}
			}
			return Status::KrajPoraz;
		}
		if(polja.at(x).at(y)==Polje::Prazno) {
			bool minica(true);
			for(int i=0; i<polja.size(); i++){
				for(int j=0; j<polja.at(i).size(); j++) {
					if(polja.at(i).at(j)==Polje::Prazno) minica=false;
				}
			}
			if(minica) return Status::KrajPobjeda;
		}
		return Status::NijeKraj;
	}
enum class KodoviGresaka {
	PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar };
void PrijaviGresku(KodoviGresaka greska) {
	if(greska==KodoviGresaka::PogresnaKomanda) std::cout<<"Nerazumljiva komanda!\n";
	if(greska==KodoviGresaka::NedostajeParametar) std::cout<<"Komanda trazi parametar koji nije naveden!\n";
	if(greska==KodoviGresaka::SuvisanParametar) std::cout<<"Zadan je suvisan parametar nakon komande!\n";
	if(greska==KodoviGresaka::NeispravanParametar) std::cout<<"Parametar komande nije ispravan!\n";
}
enum class Komande {
	PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};
	


int main ()
{
	try{
	Komande komande;
	Smjerovi smjer;
	KodoviGresaka greska;
	Tabla tabla;
	int x(0), y(0);
//	while(true) {
//		std::cout<<"Unesite komandu: ";
		
//	}
	}
	catch(std::domain_error neispravno) {
		std::cout<<neispravno.what();
	}
	catch(std::out_of_range izvanopsega) {
		std::cout<<izvanopsega.what();
	}
	std::cout<<"Dovidjenja!";
	return 0;
}
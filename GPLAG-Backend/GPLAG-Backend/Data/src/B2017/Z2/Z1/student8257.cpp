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

using std::vector;

enum class Komande {
	PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu,
	ZavrsiIgru, KreirajIgru
};

enum class KodoviGresaka {
	PogresnaKomanda, NedostajeParmetar, SuvisanParametar, NeispravanParametar
};
enum class Status {
	NijeKraj, KrajPoraz, KrajPobjeda
};

enum class Smjerovi {
	GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};

enum class Polje {
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};
typedef vector<vector<Polje>> Tabla;

Tabla KreirajIgru(int n,const vector<vector<int>> &mine) {
	if(n<=0) throw std::domain_error("Ilegalna velicina");  // Provjera ispravnosti
	for(vector<int> koord : mine) {
		if(koord.size() != 2) throw std::domain_error("Ilegalan format zadavanja mina");
		for(int koordinata : koord)
			if(koordinata >= n || koordinata < 0 ) throw std::domain_error("Ilegalne pozicije mina");
	} // !!
	Tabla novaTabla(n,vector<Polje>(n,Polje::Prazno)); // Kreiranje table
	for(vector<int> koord : mine)
		novaTabla.at(koord.at(0)).at(koord.at(1)) = Polje::Mina;
	return novaTabla;
}
int brojMinaUOkolini(const Tabla &polja , int x , int y) {
		int brojMina = 0;
		for(int i=x-1;i<x+1;i++) {
			for(int j=y-1;j<y+1;j++) {
				if(i<0 || j<0 || i==j)
					continue;
				if(polja.at(i).at(j) == Polje::Mina)
					brojMina++;
			}
		}
		return brojMina;
}

vector<vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y) {
	if(x<0 || y<0 || x>=polja.size() || y >= polja.size())
			throw std::domain_error("Polje (x,y) ne postoji");
	vector<vector<int>> okolina(3);
	int red=0;
	for(int i=x-1;i<x+1;i++) {
		for(int j=y-1;j<y+1;j++) {
			okolina.at(red).push_back(brojMinaUOkolini(polja,i,j);
		}
	}
	return okolina;
}
void BlokirajPolje(Tabla &polja ,int x ,int y) {
	if(x<0 || y<0 || x>=polja.size() || y >= polja.size())
			throw std::domain_error("Polje (x,y) ne postoji");
	if(int(polja.at(x).at(y))>2) return ;
	polja.at(x).at(y) = Polje(int(polja.at(x).at(y))+3);
	/*if(polja.at(x).at(y)==Polje::Prazno)
		polja.at(x).at(y)=Polje::BlokiranoPrazno;
	else if(polja.at(x).at(y)==Polje::Posjeceno)
		polja.at(x).at(y)=Polje::BlokiranoPosjeceno;
	else if(polja.at(x).at(y)==Polje::Mina)
		polja.at(x).at(y)=Polje::BlokiranoMina;*/
}
void DeblokirajPolje(Tabla &polja , int x , int y) {
	if(x<0 || y<0 || x>=polja.size() || y >= polja.size())
			throw std::domain_error("Polje (x,y) ne postoji");
	if(int(polja.at(x).at(y))<=2) return ;
	polja.at(x).at(y) = Polje(int(polja.at(x).at(y))-3);
}
Status statusTable(const Tabla &polja,int x, int y) {
	if(polja.at(x).at(y) == Polje::Mina)
		return Status::KrajPoraz;
	for(vector<Polje> red : Tabla)
		for(Polje polje : red)
			if(polje==Polje::Prazno) return Status::NijeKraj;
	return Status::KrajPobjeda;
}
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer) {
	polja.at(x).at(y) = Polje::Posjeceno;
	if(smjer == Smjerovi::GoreLijevo)   x-- , y--;
	if(smjer == Smjerovi::Gore)         x--;
	if(smjer == Smjerovi::GoreDesno)    x-- , y++;
	if(smjer == Smjerovi::Desno)  	     	  y++;
	if(smjer == Smjerovi::DoljeDesno)   x++ , y++;
	if(smjer == Smjerovi::Dolje)        x++;
	if(smjer == Smjerovi::DoljeLijevo)  x++ , y--;
	if(smjer == Smjerovi::Lijevo)       	  y--:
	if(x<0 || y<0 || x>polja.size() || y>polja.size())
		throw std::out_of_range("Izlazak van igrace table");
	if(int(polja.at(x).at(y))>2) 
		throw std::logic_eror("Blokirano polje");
	return statusTable(polja);
}
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y) {
	polja.at(x).at(y) = Polje::Posjeceno;
	x = novi_x; 
	y = novi_y;
	if(x<0 || y<0 || x>polja.size() || y>polja.size())
		throw std::out_of_range("Izlazak van igrace table");
	if(int(polja.at(x).at(y))>2) 
		throw std::logic_eror("Blokirano polje");
	return statusTable(polja);
}
void PrijaviGresku(KodoviGresaka greska) {
	if(greska==KodoviGresaka::PogresnaKomanda) std::cout<<"Nerazumljiva komanda!";
	if(greska==KodoviGresaka::NedostajeParmetar) std::cout<<"Komanda trazi parametar koji nije naveden!";
	if(greska==KodoviGresaka::NeispravanParametar) std::cout<<"Parametar komande nije ispravan!";
	if(greska==KodoviGresaka::SuvisanParametar) std::cout<<"Zadan je suvisan parametar nakon komande!";
}
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y,KodoviGresaka &greska) {
	string unos;
	std::getline(std::cin,unos);
}














int main ()
{
	return 0;
}
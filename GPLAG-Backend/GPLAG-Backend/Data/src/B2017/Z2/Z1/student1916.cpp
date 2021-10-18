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

enum class Polje
{
    Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n, std::vector<std::vector<int>> mine)
{
	int brojac(0);
	for(int i(0); i<mine.size(); i++) if(mine.at(i).size()==2) brojac++;
	if(brojac==0) throw std::domain_error("Ilegalan format zadavanja mina");
	for(int i(0); i<mine.size(); i++)
		if(mine.at(i).size()==2 && (mine.at(i).at(0)<0 || mine.at(i).at(0)>=n || mine.at(i).at(1)<0 || mine.at(i).at(1)>=n))
			throw std::domain_error("Ilegalne pozicije mina");
	if(n<=0) throw std::domain_error("Ilegalna veličina");
	try {
		Tabla poc(n, std::vector<Polje> (n, Polje::Prazno));
		for(int k(0); k<mine.size(); k++)
			if(mine.at(k).size()==2 && !(mine.at(k).at(0)==0 && mine.at(k).at(1)==0)) {
				poc.at(mine.at(k).at(0)).at(mine.at(k).at(1))=Polje::Mina;
			}
		return poc;
	} catch(std::bad_alloc) {
		throw;
	}
}

std::vector<std::vector<int>> PrikaziOkolinu(Tabla tabla, int x, int y)
{
	if(x<0 || x>=tabla.size() || y<0 || y>=tabla.at(0).size()) throw std::domain_error("Polje (x,y) ne postoji");
	std::vector<std::vector<int>> br_mina(3, std::vector<int> (3, 0));
	for(int i(x-1); i<=x+1; i++) {
		for(int j(y-1); j<=y+1; j++) {
			if(i>=0 && i<tabla.size() && j>=0 && j<tabla.size()) {
				int suma(0);
				for(int i1(i-1); i1<=i+1; i1++) {
					for(int j1(j-1); j1<=j+1; j1++)
						if(i1>=0 && i1<tabla.size() && j1>=0 && j1<tabla.size() && 
						tabla.at(i1).at(j1)==Polje::Mina && !(i1==x && j1==y) && !(i1==i && j1==j)) suma++;
				}
				br_mina.at(i-x+1).at(j-y+1)=suma;
			}
		}
	}
	return br_mina;
}

void BlokirajPolje(Tabla &tabla, int x, int y){
	if(x<0 || x>=tabla.size() || y<0 || y>=tabla.at(0).size()) throw std::domain_error("Polje (x,y) ne postoji");
	if(tabla.at(x).at(y)==Polje::Prazno) tabla.at(x).at(y)=Polje::BlokiranoPrazno;
	else if(tabla.at(x).at(y)==Polje::Mina) tabla.at(x).at(y)=Polje::BlokiranoMina;
	else if(tabla.at(x).at(y)==Polje::Posjeceno) tabla.at(x).at(y)=Polje::BlokiranoPosjeceno;
}

void DeblokirajPolje(Tabla &tabla, int x, int y){
	if(x<0 || x>=tabla.size() || y<0 || y>=tabla.at(0).size()) throw std::domain_error("Polje (x,y) ne postoji");
	if(tabla.at(x).at(y)==Polje::BlokiranoPrazno) tabla.at(x).at(y)=Polje::Prazno;
	else if(tabla.at(x).at(y)==Polje::BlokiranoMina) tabla.at(x).at(y)=Polje::Mina;
	else if(tabla.at(x).at(y)==Polje::BlokiranoPosjeceno) tabla.at(x).at(y)=Polje::Posjeceno;
}

enum class Smjerovi {
 GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};

void Idi(Tabla &tabla, int &x, int &y, Smjerovi smjer){
	if(smjer==Smjerovi::GoreLijevo){x--; y--; }
	else if(smjer==Smjerovi::Gore) x--;
	else if(smjer==Smjerovi::GoreDesno) {x--; y++; }
	else if(smjer==Smjerovi::Desno) y++;
	else if(smjer==Smjerovi::DoljeDesno) {x++; y++; }
	else if(smjer==Smjerovi::Dolje) x++;
	else if(smjer==Smjerovi::DoljeLijevo) {x++; y--; }
	else y--;
	tabla.at(x).at(y)=Polje::Posjeceno;
}

enum class Status {
 NijeKraj, KrajPoraz, KrajPobjeda
};

Status Idi(Tabla &tabla, int &x, int &y, int x1, int y1){
	if(x1<0 || x1>=tabla.size() || y1<0 || y1>=tabla.at(0).size()) throw std::out_of_range("Izlazak van igrace table");
	if(tabla.at(x1).at(y1)==Polje::BlokiranoMina || tabla.at(x1).at(y1)==Polje::BlokiranoPosjeceno || tabla.at(x1).at(y1)==Polje::BlokiranoPrazno)
		throw std::logic_error("Blokirano polje");
	x=x1; y=y1;
	if(tabla.at(x1).at(y1)==Polje::Mina){
		tabla=std::vector<std::vector<Polje>> (tabla.size(), std::vector<Polje> (tabla.size(), Polje::Prazno));
		return Status::KrajPoraz;
	}
	if(tabla.at(x1).at(y1)==Polje::Prazno){
		int brojac(0);
		for(int i(0); i<tabla.size(); i++){
			for(int j(0); j<tabla.size(); j++){
				if(!(i==x1 && j==y1) && tabla.at(i).at(j)==Polje::Prazno) brojac++; 
			}
		}
		if(brojac==0) return Status::KrajPobjeda;
	}
	return Status::NijeKraj;
}

enum class KodoviGresaka {
 PogresnaKomanda, NedostajeParmetar, SuvisanParametar, NeispravanParametar
};

void PrijaviGresku(KodoviGresaka a){
	if(a==KodoviGresaka::PogresnaKomanda) std::cout << "Nerazumljiva komanda!";
	else if(a==KodoviGresaka::NedostajeParmetar) std::cout << "Komanda trazi parametar koji nije naveden!";
	else if(a==KodoviGresaka::SuvisanParametar) std::cout << "Zadan je suvisan parametar nakon komande!";
	else std::cout << "Parametar komande nije ispravan!";
}

enum class Komande {
 PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};
/*
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	std::string a;
	std::getline(std::cin, a);
	for(int i(0); i<a.size()-1; i++){
		bool jeste(true);
		if(a.at(i)=='P' && a.at(i+1)=='1'){
			for(int j(0); j<i; j++) if(a.(j)!=' ') jeste=false;
			for(int j(i+2); j<a.size(); j++)
				if(!(a.at(j)=='G' || a.at(j)=='o' || a.at(j)=='L' || a.at(j)=='D' || a.at(j)==' ')) jeste=false;
			if(jeste){
				for(int j(i+2); j<a.size(); j++){
					std::string b;
					if(a.at(j)=='G' || a.at(j)=='L' || a.at(j)=='D' || a.at(j)==' '){
						while(a.at(j)=='G' || a.at(j)=='L' || a.at(j)=='D' || a.at(j)=='o'){
							b.push_back(a.at(j));
							j++;
						}
						for(int k(j); k<a.size(); k++) if(a.at(k)!=' ') jeste=false;
						break;
					}
					if(jeste){
						if(b==std::string ("GL")) {smjer=Smjerovi::GoreLijevo; return true;}
						else if(b==std::string ("G")) {smjer=Smjerovi::Gore; return true;}
						else if(b==std::string ("GD")) {smjer=Smjerovi::GoreDesno; return true;}
						else if(b==std::string ("D")) {smjer=Smjerovi::Desno; return true;}
						else if(b==std::string ("DoD")) {smjer=Smjerovi::DoljeDesno; return true;}
						else if(b==std::string ("Do")) {smjer=Smjerovi::Dolje; return true;}
						else if(b==std::string ("DoL")) {smjer=Smjerovi::DoljeLijevo; return true;}
						else return false;
					}
					else return false;
				}
			}
			else return false;
		}
/*		else  if(a.at(i)=='P' && a.at(i+1)=='>'){
			for(int j(0); j<i; j++) if(a.(j)!=' ') jeste=false;
			for(int j(i+2); j<a.size(); j++)
				if(!((a.at(j)>='0' && a.at(j)<='9') || a.at(j)==' ')) jeste=false;
			if(jeste){
				
			}
		}
	} 
	return true;
}
*/
int main ()
{
	return 0;
}





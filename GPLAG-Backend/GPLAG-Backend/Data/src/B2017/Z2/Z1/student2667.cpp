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
enum class Polje {Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina};
enum class Smjerovi { GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo};
enum class Status { NijeKraj, KrajPoraz, KrajPobjeda};
enum class KodoviGresaka { PogresnaKomanda, NedostajeParmetar, SuvisanParametar, NeispravanParametar};
enum class Komande { PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru};
typedef std::vector<std::vector<Polje>> Tabla;
Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine);
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y);
void BlokirajPolje(Tabla &polja, int x, int y);
void DeblokirajPolje(Tabla &polja, int x, int y);
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer);
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y);
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska);
void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0);

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine) {
	Tabla t(n);
	for(int i=0; i<t.size(); i++) {
		t.at(i).resize(n);
	}
	for(int i=0; i<t.size(); i++) {
		for(int j=0; j<t.at(i).size(); j++) {
			t.at(i).at(j)=Polje::Prazno;
		}
	}
	for(int i=0; i<mine.size(); i++) {
		for(int j=0; j<mine.at(i).size(); j++) {
			if(mine.at(i).size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
			int pozicija(mine.at(i).at(j));
			if(pozicija<0 || pozicija>=n) throw std::domain_error("Ilegalne pozicije mina");
		}
	}
	for(int i=0; i<mine.size(); i++) {
		for(int j=0; j<mine.at(i).size(); j++) {
			t.at(mine.at(i).at(0)).at(mine.at(i).at(1))=Polje::Mina;
		}
	}
	return t;
}

void BlokirajPolje(Tabla &polja, int x, int y) {
	std::string s("Polje "); s+=x+'0'; s+=","; s+=y+'0'; s+=")";
	if(x<0 || x>=polja.size() || y<0 || y>=polja.size()) throw std::domain_error(s);
	if(polja.at(x).at(y)==Polje::Prazno) polja.at(x).at(y)=Polje::BlokiranoPrazno;
	if(polja.at(x).at(y)==Polje::Posjeceno) polja.at(x).at(y)=Polje::BlokiranoPosjeceno;
	if(polja.at(x).at(y)==Polje::Mina) polja.at(x).at(y)=Polje::BlokiranoMina;
}

void DeblokirajPolje(Tabla &polja, int x, int y) {
	std::string s("Polje "); s+=x+'0'; s+=","; s+=y+'0'; s+=")";
	if(x<0 || x>=polja.size() || y<0 || y>=polja.size()) throw std::domain_error(s);
	if(polja.at(x).at(y)==Polje::BlokiranoPrazno) polja.at(x).at(y)=Polje::Prazno;
	if(polja.at(x).at(y)==Polje::BlokiranoPosjeceno) polja.at(x).at(y)=Polje::Posjeceno;
	if(polja.at(x).at(y)==Polje::BlokiranoMina) polja.at(x).at(y)=Polje::Mina;
}
int main ()
{
	return 0;
}
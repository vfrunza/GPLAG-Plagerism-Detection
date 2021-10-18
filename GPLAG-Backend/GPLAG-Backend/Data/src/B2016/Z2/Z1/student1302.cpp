#include <iostream>
#include <vector>
 /* TREBAJU MI FUNKCIJE 
 
Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine); ----------------------------------uradjeno
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y);
void BlokirajPolje(Tabla &polja, int x, int y); ------------------------------------------uradjeno fali domain error
void DeblokirajPolje(Tabla &polja, int x, int y);------------------------------------------uradjeno fali domain error
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer);
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y);
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y);
void PrijaviGresku (KodoviGresaka kod_greske) -----------------------------------uradjeno


*/
enum class Polje 
 { Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina};
enum class Smjerovi
 { GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo};
enum class Status 
 {NijeKraj, KrajPoraz, KrajPoraz};
enum class KodoviGresaka
 {PogresnaKomanda, NedostajeParametar, Suvisanparametar, NeispravanParametar};
enum class Komande 
 {PomjeriJednoDesno, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru};
 
typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajTablu(int broj_redova) {
 return Tabla(broj_redova, std::vector<Polje>(broj_redova));
}

Tabla PostaviNaPrazno (int n, Tabla t) {
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            t[i][j] = Polje::Prazno;
        }
    }
    return t;
}
Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	int zamine, zamine1;
	Tabla kreirana = KreirajIgru(n);
	Tabla postavljena = PostaviNaPrazno(n, kreirana);
	
	for(int i = 0; i<mine.size(); ++i){
		if(mine.size()!=2)
			throw std::domain_error("Ilegalan format zadavanja mina");
	}
	
	if(mine.size()==0 || mine.size()<n) 
		throw std::domain_error ("Ilegalne pozicije mina");
	
	for(int i=0; i<mine.size(); ++i) {
		zamine = mine[i][0];
		zamine1 = mine[i][1];
		postavljena = [zamine][zamine1];
	}
	return postavljena;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	std::vector<std::vector<int>> matrica (3, std::vector<int>(3));
	return matrica;
}
void BlokirajPolje(Tabla &polja, int x, int y){ //FALI DOMAIN ERROR DA SE BACI
	if(x<0 || x>polja.size() || y<0 || y>polja.size()) throw 
	if(polja[y][x] == Polje::Prazno) tabla[y][x] == Polje::BlokiranoPrazno;
	if(polja[y][x] == Polje::Posjeceno) tabla[y][x] == Polje::BlokiranoPosjeceno;
	if(polja[y][x] == Polje::Mina) tabla[y][x] == Polje::BlokiranoMina;
}
void DeblokirajPolje(Tabla &polja, int x, int y){//FALI DOMAIN ERROR DA SE BACI
	if(polja[y][x] == Polje::BlokiranoPrazno) tabla[y][x] == Polje::Prazno;
	if(polja[y][x] == Polje::BlokiranoPosjeceno) tabla[y][x] == Polje::Posjeceno;
	if(polja[y][x] == Polje::BlokiranoMina) tabla[y][x] == Polje::Mina;
}
void PrijaviGresku(KodoviGresaka kod_greske){
	if(kod_greske == KodoviGresaka::PogresnaKomanda) { std::cout<<"Nerazumljiva komanda!"; }
	if(kod_greske == KodoviGresaka::NedostajeParametar) { std::cout<<"Komanda trazi parametar koji nije naveden!"; }
	if(kod_greske == KodoviGresaka::Suvisanparametar) { std::cout<<"Zadan je suvisan parametar nakon komande!"; }
	if(kod_greske == KodoviGresaka::NeispravanParametar) { std::cout<<"Parametar komande nije ispravan!"; }
}
bool UnosKomande (Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	
}
int main (){
    //Tabla kreiraj;
    std::cout<<"Unesite velicinu table (n): ";
    int n;
    std::cin >> n;
    //kreiraj = 
    
	return 0;
}
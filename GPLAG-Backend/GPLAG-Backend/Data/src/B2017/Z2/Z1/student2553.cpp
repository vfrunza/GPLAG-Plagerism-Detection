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
#include <string>
#include <algorithm>

enum class Polje { Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina }; 
enum class Smjerovi { GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo };
enum class Status { NijeKraj, KrajPoraz, KrajPobjeda };
enum class KodoviGresaka { PogresnaKomanda, NedostajeParmetar, SuvisanParametar, NeispravanParametar }; 
enum class Komande { PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru }; 
 
 
typedef std::vector<std::vector<Polje>> Tabla; 

using std::cout;
using std::cin;
using std::endl;


Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	
	Tabla Minesweeper(n);
	
	for(int i=0;i<Minesweeper.size();i++)
		Minesweeper.at(i).resize(n);

	for(int i=0;i<mine.size();i++)
			Minesweeper.at(mine.at(i).at(0)).at(mine.at(i).at(1)) = Polje::Mina;
		
	return Minesweeper;
	
}

int Suma_okoline(const Tabla &polja, int x, int y){
	
	int suma(0);
	
	for(int i=x-1;i<=x+1;i++){
		for(int j=y-1;j<=y+1;j++){
			if(i!=-1 && i!=-2 && i!=polja.size() && i!=polja.size()+1 && j!=-1 && j!=-2  && j!=polja.size() && j!=polja.size()+1){ // u okolini table nema mina
				if( (i!=x || j!=y) && polja.at(i).at(j)==Polje::Mina) suma++;
			}
		}
	}

	
	return suma;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	
	std::vector<std::vector<int>> Okolina(3);
	
	for(int i=0;i<3;i++) Okolina.at(i).resize(3);
	
	int suma (0);
	int k(0),l(0);
	
	
	for(int i=x-1;i<=x+1;i++){
		for(int j=y-1;j<=y+1;j++){
				suma=Suma_okoline(polja,i,j);
				Okolina.at(k).at(l)=suma;
			l++;
		}
	l=0;	
	k++;
	}
	
	return Okolina;
}

void BlokirajPolje(Tabla &polja, int x, int y){
	
		if (polja.at(x).at(y)==Polje::Prazno) polja.at(x).at(y)=Polje::BlokiranoPrazno;
		if (polja.at(x).at(y)==Polje::Posjeceno) polja.at(x).at(y)=Polje::BlokiranoPosjeceno;
		if (polja.at(x).at(y)==Polje::Mina) polja.at(x).at(y)=Polje::BlokiranoMina;
}

void DeblokirajPolje(Tabla &polja, int x, int y){

		if (polja.at(x).at(y)==Polje::BlokiranoPrazno) polja.at(x).at(y)=Polje::Prazno;
		if (polja.at(x).at(y)==Polje::BlokiranoPosjeceno) polja.at(x).at(y)=Polje::Posjeceno;
		if (polja.at(x).at(y)==Polje::BlokiranoMina) polja.at(x).at(y)=Polje::Mina;
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	
	polja.at(x).at(y)=Polje::Posjeceno;
	if(smjer==Smjerovi::GoreLijevo) {x--; y--;}
	if(smjer==Smjerovi::Gore) {x--;}
	if(smjer==Smjerovi::GoreDesno) {x--; y++;}
	if(smjer==Smjerovi::Desno) {y++;}
	if(smjer==Smjerovi::DoljeDesno) {x++; y++;}
	if(smjer==Smjerovi::Dolje) {x++;}
	if(smjer==Smjerovi::DoljeLijevo) {x++; y--;}
	if(smjer==Smjerovi::Lijevo) {y--;}
	
	int n(polja.size());
	
	if(polja.at(x).at(y)==Polje::Mina) {
	polja.resize(0);
	polja.resize(n);
	for(int i=0;i<n;i++)
	polja.at(i).resize(n);
	return Status::KrajPoraz;
	}
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(polja.at(i).at(j)==Polje::Prazno || polja.at(i).at(j)==Polje::BlokiranoPrazno || polja.at(i).at(j)==Polje::BlokiranoPosjeceno || polja.at(i).at(j)==Polje::BlokiranoMina)
			return Status::NijeKraj;
		
		return Status::KrajPobjeda;
	
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	
	polja.at(x).at(y)=Polje::Posjeceno;

	x=novi_x;
	y=novi_y;
	
	int n(polja.size());
	
	if(polja.at(x).at(y)==Polje::Mina) {
	polja.resize(0);
	polja.resize(n);
	for(int i=0;i<n;i++)
	polja.at(i).resize(n);
	return Status::KrajPoraz;
	}
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(polja.at(i).at(j)==Polje::Prazno || polja.at(i).at(j)==Polje::BlokiranoPrazno || polja.at(i).at(j)==Polje::BlokiranoPosjeceno || polja.at(i).at(j)==Polje::BlokiranoMina)
			return Status::NijeKraj;
		
		return Status::KrajPobjeda;
}

void PrijaviGresku(KodoviGresaka greska){
	if(greska==KodoviGresaka::PogresnaKomanda) cout<<"Nerazumljiva komanda!"<<endl;
	if(greska==KodoviGresaka::NedostajeParmetar) cout<<"Komanda trazi parametar koji nije naveden!"<<endl;
	if(greska==KodoviGresaka::NeispravanParametar) cout<<"Parametar komande nije ispravan!"<<endl;
	if(greska==KodoviGresaka::SuvisanParametar) cout<<"Zadan je suvisan parametar nakon komande!"<<endl;
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	
	return true;
	
}

int main ()
{

   
	return 0;
}
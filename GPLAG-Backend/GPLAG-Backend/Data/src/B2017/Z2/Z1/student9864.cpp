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
#include<vector>
#include<stdexcept>

enum class Polje{
	Prazno, Posjeceno , Mina, BlokiranoPrazno,BlokiranoPosjeceno,BlokiranoMina
	
};
enum class Smjerovi {
	GoreLijevo ,Gore,GoreDesno,Desno,DoljeDesno,Dolje,DoljeLijevo,Lijevo
};

enum class Status {
	NijeKraj, KrajPoraz,KrajPobjeda
}; 
enum class KodoviGresaka {
	PogresnaKomanda, NedostajeParametar,SuvisanParametar,NeispravanParametar
};
enum class Komande{
	PomjeriJednoMjesto, PomjeriDalje, Blokiraj,Deblokiraj,PrikaziOkolinu,ZavrsiIgru,KreirajIgru
};
	
 
 typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n,const std::vector<std::vector<int>> &mine){
	Tabla KreiranaTabla(n,std::vector<Polje>(n,Prazno));
	if(n<=0) 
	  throw std::domain_error ("Ilegalna velicina");
	//prolazim kroz poslani vektor vektora ako broj elemenata vektora nije 2 da bacim izuzetak
	for(int i(0);i<mine.size();i++){
	  if(mine[i].size()!=2) 
	      throw std::domain_error ("Ilegalan format zadavanja mina");
	 for(int i(0);i<mine.size();i++){
	 	for(int j(0);j<mine[i].size();j++){
	 		if(i<=0 || j<=0 || i>=n-1 || j>= n-1)
	 	throw std::domain_error ("Ilegalne pozicije mina");
	}
	 }
for(int i(0);i<mine.size();i++){
	for(int j(0);j<mine[i].size();j++){
		
				
	}
}
return KreiranaTabla;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja,int x,int y)
{
	std::vector<std::vector<int>> rezultat(3,std::vector<int> (3));
	int brojacmina;
	for(int i=0)
	
}

void BlokirajPolje(Tabla &polja,int x,int y){
	if (Tabla[x][y]==BlokiranoPrazno) Tabla[x][y]==Prazno;
	else if(Tabla[x][y]==BlokiranoPosjeceno) Tabla[x][y]==Posjeceno;
	else if(Tabla[x][y]==BlokiranoMina) Tabla[x][y]==Mina;
}
void DeblokirajPolje(Tabla &polja,int x,int y){
}
StatusIdi(Tabla &polja,int &x,int &y,Smjerovi smjer){
}
StatusIdi(Tabla &polja,int &x,int &y,int novi_x,int novi_y){
}
void PrijaviGresku(KodoviGresaka greska){
	if(greska==PogresnaKomanda) 
	   std::cout<<"Nerazumljiva komanda!";
	if(greska==NedostajeParametar)
	   std::cout<<"Komanda trazi parametar koji nije naveden!";
	if(greska==NeispravanParametar)
	   std::cout<<"Parametar komande nije ispravan!";
	if(greska==SuvisanParametar)
	   std::cout<<"Zadan je suvisan parametar nakon komande!";
}
bool UnosKomande(Komande &komande,Smjerovi &smjer,int &x,int &y,KodoviGresaka &greska){
	
}



int main ()
{
	return 0;
}
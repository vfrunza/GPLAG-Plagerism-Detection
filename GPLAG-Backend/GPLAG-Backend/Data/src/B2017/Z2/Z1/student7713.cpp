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


enum class Polje
{
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
 PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu,
 ZavrsiIgru, KreirajIgru
};
typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine)
{
	Tabla t(n,std::vector<Polje> (n,Polje(0)));
	for(int i=0; i<mine.size(); i++)
			t.at(mine.at(i).at(0)).at(mine.at(i).at(1))=Polje(2);

	return t;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y)
{
	std::vector<std::vector<int>> m(3,std::vector<int> (3,0));
	Tabla prosirena(polja.size()+1,std::vector<Polje>(polja.size()+1));
	for(int i=0; i<prosirena.size(); i++) {
		if(i==0 || i==prosirena.size()-1) continue;
		for(int j=0; j<prosirena.size(); j++) {
			if(j==0 || j==prosirena.size()-1) continue;
			prosirena.at(i).at(j)=polja.at(i-1).at(j-1);
		}
	}
	int k(0),l(0);
			for(int i=x; i<=x+2; i++){
				for(int j=y; j<=y+2; j++){
					for(int p=i-1; p<=i+1; p++)
						for(int q=j-1; q<=j+1;q++) {
							if(p==i && q==j) continue;
							if(prosirena.at(p).at(q)==Polje(2)) m.at(k).at(l)++;
						}  l++;} k++; l=0; }
	return m;
}
void BlokirajPolje(Tabla &polja, int x, int y) {
		if(polja.at(x).at(y)==Polje(0)) polja.at(x).at(y)=Polje(3);
		else if(polja.at(x).at(y)==Polje(1)) polja.at(x).at(y)=Polje(4);
		else if(polja.at(x).at(y)==Polje(2)) polja.at(x).at(y)=Polje(5);
}
void DeblokirajPolje(Tabla &polja, int x, int y){
		if(polja.at(x).at(y)==Polje(3)) polja.at(x).at(y)=Polje(0);
		else if(polja.at(x).at(y)==Polje(4)) polja.at(x).at(y)=Polje(1);
		else if(polja.at(x).at(y)==Polje(5)) polja.at(x).at(y)=Polje(2);
}
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	int p(x),q(y);
	if(smjer==Smjerovi(0)) { x-=1; y-=1; }
	else if(smjer==Smjerovi(1))  x-=1;
	else if(smjer==Smjerovi(2)) { x-=1; y+=1; }
	else if(smjer==Smjerovi(3)) y+=1;
	else if(smjer==Smjerovi(4)) { x+=1; y+=1; }
	else if(smjer==Smjerovi(5)) x+=1;
	else if(smjer==Smjerovi(6)) { x+=1; y-=1; }
	else if(smjer==Smjerovi(7))  y-=1;
	
	if(polja.at(x).at(y)==Polje(2)) return Status(1);
	polja.at(p).at(q)=Polje(1);
	bool T(false);
	for(int i=0;i<polja.size();i++){
	for(int j=0;j<polja.size();j++)
	if(polja.at(i).at(j)==Polje(0)) { T=true; break; }
	if(T) return Status(0);
	}
	return Status(2);
}
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	
	int p(x),q(y);
	
	x=novi_x;
	y=novi_y;
	
	if(polja.at(x).at(y)==Polje(2)) return Status(1);
	polja.at(p).at(q)=Polje(1);
	bool T(false);
	for(int i=0;i<polja.size();i++){
	for(int j=0;j<polja.size();j++)
	if(polja.at(i).at(j)==Polje(0)) { T=true; break; }
	if(T) return Status(0);
	}
	return Status(2);
}
//bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y,
 //KodoviGresaka &greska);
 void PrijaviGresku(KodoviGresaka &greska) {
 	if(greska==KodoviGresaka(0)) std::cout<<"Nerazumljiva komanda!"<<std::endl;
 	else if(greska==KodoviGresaka(1)) std::cout<<"Komanda trazi parametar koji nije naveden!"<<std::endl;
 	else if(greska==KodoviGresaka(2)) std::cout<<"Parametar komande nije ispravan!"<<std::endl;
 	else if(greska==KodoviGresaka(3)) std::cout<<"Zadan je suvisan parametar nakon komande!"<<std::endl;
  }
  
int main ()
{
	return 0;
}
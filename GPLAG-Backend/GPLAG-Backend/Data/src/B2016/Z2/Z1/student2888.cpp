/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
using namespace std;
typedef vector<vector<int>> Cijeli;
enum class Polje{Prazno,Posjeceno,Mina,BlokiranoPrazno,BlokiranoPosjeceno,BlokiranoMina};
typedef vector<vector<Polje>> Tabla;
Tabla KreirajIgru(int n,const Cijeli &mine){
	Tabla TABLICA(n);
	for(int i=0;i<n;i++)  TABLICA[i].resize(n);
	for(int i=0;i<mine.size();i++)
	for(int j=0;j<mine[i].size();j++)
	if(mine[i][j]<0 || mine[i][j]>=n) throw domain_error("Ilegalne pozicije mina");
	for(int i=0;i<mine.size();i++)
	if(mine[i].size()!=2) throw domain_error("Ilegalan format zadavanja mina");
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++) TABLICA[i][j]=Polje::Prazno;
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	for(int k=0;k<mine.size();k++)
	if(j==mine[k][1] && i==mine[k][0]) TABLICA[i][j]=Polje::Mina;
	return TABLICA;
}
void BlokirajPolje(Tabla &polja,int x,int y){
	if(x>=polja.size() || y>=polja.size()){
		string s1(to_string(x));
		string s2(to_string(y));
		throw domain_error("Polje ("+s1+","+s2+") ne postoji");
	}
	if(polja[x][y]==Polje::Posjeceno)
	polja[x][y]=Polje::BlokiranoPosjeceno;
	else if(polja[x][y]==Polje::Prazno)
	polja[x][y]=Polje::BlokiranoPrazno;
	else if(polja[x][y]==Polje::Mina)
	polja[x][y]=Polje::BlokiranoMina;
}
void DeblokirajPolje(Tabla &polja,int x,int y){
	if(x>=polja.size() || y>=polja.size()){
		string s1(to_string(x));
		string s2(to_string(y));
		throw domain_error("Polje ("+s1+","+s2+") ne postoji");
	}
	if(polja[x][y]==Polje::BlokiranoPosjeceno)
	polja[x][y]=Polje::Posjeceno;
	else if(polja[x][y]==Polje::BlokiranoPrazno)
	polja[x][y]=Polje::Prazno;
	else if(polja[x][y]==Polje::BlokiranoMina)
	polja[x][y]=Polje::Mina;
}
enum class Status {NijeKraj, KrajPoraz, KrajPobjeda};
Status StanjeNaPolju(Tabla polja){
	Status STANJE(Status::KrajPobjeda);
	for(int i=0;i<polja.size();i++)
	for(int j=0;j<polja[i].size();j++)
	if(polja[i][j]==Polje::BlokiranoPrazno || polja[i][j]==Polje::Prazno){
		STANJE=Status::NijeKraj;
		return STANJE;
	}
	return STANJE;
}
enum class Smjerovi {GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo};
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	polja[x][y]=Polje::Posjeceno;
	Status STANJE(StanjeNaPolju(polja));
	if(smjer==Smjerovi::Gore) x--;
	else if(smjer==Smjerovi::Dolje) x++;
	else if(smjer==Smjerovi::Lijevo) y--;
	else if(smjer==Smjerovi::Desno) y++;
	else if(smjer==Smjerovi::GoreLijevo){ x--; y--; }
	else if(smjer==Smjerovi::DoljeLijevo){ x++; y--; }
	else if(smjer==Smjerovi::GoreDesno){ x--; y++; }
	else if(smjer==Smjerovi::DoljeDesno){ x++; y++; }
	if(x<0 || y<0) throw out_of_range("Izlazak van igrace table");
	if(x>=polja.size() || y>=polja.size()) throw out_of_range("Izlazak van igrace table");
	if(polja[x][y]==Polje::BlokiranoPosjeceno || polja[x][y]==Polje::BlokiranoMina || polja[x][y]==Polje::BlokiranoPrazno) throw logic_error("Blokirano polje");
	if(polja[x][y]==Polje::Mina) STANJE=Status::KrajPoraz;
	return STANJE;
}
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	polja[x][y]=Polje::Posjeceno;
	Status STANJE(StanjeNaPolju(polja));
	x=novi_x;
	y=novi_y;
	if(x<0 || y<0) throw out_of_range("Izlazak van igrace table");
	if(x>=polja.size() || y>=polja.size()) throw out_of_range("Izlazak van igrace table");
	if(polja[x][y]==Polje::BlokiranoPosjeceno || polja[x][y]==Polje::BlokiranoMina || polja[x][y]==Polje::BlokiranoPrazno) throw logic_error("Blokirano polje");
	if(polja[x][y]==Polje::Mina) STANJE=Status::KrajPoraz;
	return STANJE;
}
int main ()
{
	return 0;
}
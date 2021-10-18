/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include<iostream>
#include<vector>
#include <string>
#include <stdexcept>
using namespace std;
enum class Polje {
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};
enum class Smjerovi {
	GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje,  DoljeLijevo, Lijevo
};
enum class Status {
	NijeKraj, KrajPoraz, KrajPobjeda 
};
enum class KodoviGresaka {
	PogresnaKomanda, NedestajeParametar, SuvisanParametar, NeispravanParametar
};

typedef vector<vector<Polje>> Tabla;



Tabla KreirajIgru(int n, const vector<vector<int>> &mine){//funkcija 1

Tabla igra(n);

for(int i(0);i<n;i++)
igra[i].resize(n);

for(int i(0);i<mine.size();i++){
	if(mine[i].size()!=2) throw domain_error ("Ilegalan format zadavanja mina");
}

for(int i(0);i<mine.size();i++)
	for(int j(0);j<mine[i].size();j++){
		if(mine[i][j]>=n) throw domain_error ("Ilegalna pozicija mina");
	}
for(int i(0);i<n;i++)
for(int j(0);j<n;j++){
	igra[i][j]=Polje::Prazno;
}

for(int i(0);i<n;i++){
	for(int j(0);j<n;j++){
		for(int l(0);l<mine.size();l++){
			if(i==mine[l][0] && j==mine[l][1])
			igra[i][j]=Polje::Mina;
		}
	}
}
return igra;
}



void BlokirajPolje(Tabla &polja, int x,int y){//funkcija 3
if(x>= polja.size() || y>= polja.size()){
	string x1=to_string(x);
	string y1=to_string(y);
	string greska = "Polje ("+x1+","+y1+") ne postoji";
	throw domain_error (greska);
	
}
if(polja[x][y]==Polje::Prazno) polja[x][y]=Polje::BlokiranoPrazno;
else if(polja[x][y]==Polje::Mina) polja[x][y]=Polje::BlokiranoMina;
else if(polja[x][y]==Polje::Posjeceno) polja[x][y]=Polje::BlokiranoPosjeceno;

}

void DeblokirajPolje(Tabla &polja, int x,int y){//funkcija 4
if(x>= polja.size() || y>= polja.size()){
	string x1=to_string(x);
	string y1=to_string(y);
	string greska = "Polje ("+x1+","+y1+") ne postoji";
	throw domain_error (greska);
	
}
if(polja[x][y]==Polje::BlokiranoPrazno) polja[x][y]=Polje::Prazno;
else if(polja[x][y]==Polje::BlokiranoMina) polja[x][y]=Polje::Mina;
else if(polja[x][y]==Polje::BlokiranoPosjeceno) polja[x][y]=Polje::Posjeceno;

}
Status ProvjeraStatusa(Tabla polja){
	Status provjeri=Status::KrajPobjeda;
	for(int i(0);i<polja.size();i++){
		for(int j(0);j<polja[i].size();j++){
			if(polja[i][j]==Polje::Prazno || polja[i][j]==Polje::BlokiranoPrazno){
				provjeri=Status::NijeKraj;
				return provjeri;
			}
		}
	}
	return provjeri;
}

Status Idi(Tabla &polja, int &x, int y, Smjerovi smjer){//funkcija 5

polja[x][y]=Polje::Posjeceno;
Status provjeri=ProvjeraStatusa(polja);

if(smjer==Smjerovi::GoreLijevo){
	x--;
	y--;
}
else if(smjer==Smjerovi::GoreDesno){
	x--;
	y++;
}
else if(smjer==Smjerovi::Gore){
	x--;
}
else if(smjer==Smjerovi::Desno){
	y++;
}
else if(smjer==Smjerovi::Lijevo){
	y--;
}
else if(smjer==Smjerovi::DoljeDesno){
	x++;
	y++;
}
else if(smjer==Smjerovi::DoljeLijevo){
	x++;
	y--;
}
else if(smjer==Smjerovi::Dolje){
	x++;
}
if(x<0 || y<0 || x>=polja.size() || y>=polja.size()) throw out_of_range ("Izlazak van igrace table");
if(polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoMina || polja[x][y]==Polje::BlokiranoPosjeceno) throw logic_error ("Blokirano polje");
if(polja[x][y]==Polje::Mina) provjeri=Status::KrajPoraz;
return provjeri;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	polja[x][y]=Polje::Posjeceno;
	Status status=ProvjeraStatusa(polja);
	x=novi_x;
	y=novi_y;
	if(x<0 || y<0 || x>=polja.size() || y>=polja.size()) throw out_of_range ("Izlazak van igrace table");
    if(polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoMina || polja[x][y]==Polje::BlokiranoPosjeceno) throw logic_error ("Blokirano polje");

	return status;
}
void PrijaviGresku(KodoviGresaka greska) {
	if(greska==KodoviGresaka::PogresnaKomanda) cout<< "Nerazumljiva komanda!" << endl;
	else if(greska==KodoviGresaka::SuvisanParametar) cout<< "Zadan je suvisan parametar nakon komande!"<< endl;
    else if(greska==KodoviGresaka::NedestajeParametar) cout <<"Komanda trazi parametar koji nije naveden!"<<endl;
	else if(greska==KodoviGresaka::NeispravanParametar) cout<<"Parametar komande nije ispravan!";
}



int main ()
{
	return 0;
}
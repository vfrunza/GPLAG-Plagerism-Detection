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
#include<cmath>
using namespace std;

enum class Polje
{
    Prazno,Posjeceno,Mina,BlokiranoPrazno,BlokiranoPosjeceno,BlokiranoMina
};

enum class Smjerovi
{
    GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};

enum class Status
{
    NijeKraj, KrajPoraz, KrajPobjeda
};

typedef vector<vector<bool>>Logicka;
typedef vector<vector<Polje>>Tabla;

Tabla KreirajIgru(int n,const vector<vector<int>>&mine)
{
	if(n<0){
		throw domain_error("Ilegalna velicina");
	}
	Tabla tabla(n,vector<Polje>(n,Polje::Prazno));
	for(int i=0; i<mine.size(); i++) {
		if(mine[i].size()!=2)
			throw domain_error("Ilegalan format zadavanja mina");
	}
	for(int i=0;i<mine.size();i++){
		for(int j=0;j<mine[i].size();j++){
			if((mine[i][j]>=tabla.size()) || mine[i][j]<0) throw domain_error("Ilegalne pozicije mina");
		}
	}
	for(int i=0; i<mine.size(); i++) {
		tabla[mine[i][0]][mine[i][1]]=Polje::Mina;
	}
	return tabla;
}

Logicka Izdvoji(const Tabla &polja,int x, int y)
{
	Logicka m(5,vector<bool>(5));
	for(int i=-2; i<=2; i++) {
		for(int j=-2; j<=2; j++) {
			if(polja[x+i][y+j]==Polje::Mina) m[i+2][j+2]=bool(polja[x+i][y+j]);
			else m[i+2][j+2]=0;
		}
	}
	return m;
}
int JeLiMina(Logicka mat,int x,int y)
{
	int br_mina(0);
	for(int i=0; i<mat.size(); i++) {
		for(int j=0; j<mat[i].size(); j++) {
			if(mat[x+i][y+j]==true)
				br_mina++;
		}
	}
	return br_mina;
}


vector<vector<int>>PrikaziOkolinu(const Tabla &polja,int x,int y)
{
	if(x<0 || x>=polja.size() || y<0 || y>=polja.size()) throw domain_error("Polje ("+to_string(x)+","+to_string(y)+") ne postoji");
	vector<vector<int>>m(3,vector<int>(3));
	Logicka l=Izdvoji(polja,x,y);
	for(int i=0; i<m.size(); i++) {
		for(int j=0; j<m[i].size(); j++) {
			m[i][j]=JeLiMina(l,x,y);
		}
	}
	return m;
}

void BlokirajPolje(Tabla &polja,int x,int y)
{
	if(x>=polja.size() || x<0 || y>=polja.size() || y<0) {
		throw domain_error("Polje(" + to_string(x) + "," + to_string(y) + ") ne postoji");
	}
	if(polja[x][y]==Polje::Prazno) polja[x][y]=Polje::BlokiranoPrazno;
	else if(polja[x][y]==Polje::Mina) polja[x][y]=Polje::BlokiranoMina;
	else if(polja[x][y]==Polje::Posjeceno) polja[x][y]=Polje::BlokiranoPosjeceno;
}

void DeblokirajPolje(Tabla &polja,int x,int y)
{
	if(x>=polja.size() || x<0 || y>=polja.size() || y<0) {
		throw domain_error("Polje(x,y) ne postoji");
	}
	if(polja[x][y]==Polje::BlokiranoPrazno) polja[x][y]=Polje::Prazno;
	else if(polja[x][y]==Polje::BlokiranoMina) polja[x][y]=Polje::Mina;
	else if(polja[x][y]==Polje::BlokiranoPosjeceno) polja[x][y]=Polje::Posjeceno;
}

Status Idi(Tabla &polja,int &x,int &y,Smjerovi smjer)
{
	int i1(x),j1(y);
	if(smjer==Smjerovi::GoreLijevo) {
		i1--;
		j1--;
	} else if(smjer==Smjerovi::GoreDesno) {
		i1--;
		j1++;
	} else if(smjer==Smjerovi::DoljeLijevo) {
		i1++;
		j1--;
	} else if(smjer==Smjerovi::DoljeDesno) {
		i1++;
		j1++;
	} else if(smjer==Smjerovi::Desno) {
		j1++;
	} else if(smjer==Smjerovi::Lijevo) {
		j1--;
	} else if(smjer==Smjerovi::Gore) {
		i1--;
	} else if(smjer==Smjerovi::Dolje) {
		i1++;
	}
	if(i1<0 || i1>=polja.size() || j1<0 || j1>=polja.size()) {
		throw out_of_range("Izlazak van igrace table");
	}
	if(polja[i1][j1]==Polje::BlokiranoPosjeceno || polja[i1][j1]==Polje::BlokiranoPrazno || polja[i1][j1]==Polje::BlokiranoMina) {
		throw logic_error("Blokirano polje");
	}
	polja[x][y]=Polje::Posjeceno;
	x=i1; 
	y=j1;
		
	if(polja[x][y]==Polje::Mina){
		for(int i=0;i<polja.size();i++){
			for(int j=0;j<polja[i].size();j++){
				polja[i][j]=Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
	else{
		bool prazna(false);
		for(int i=0;i<polja.size();i++){
			for(int j=0;j<polja[i].size();j++){
				if(i==x && j==y) continue;
				else if(polja[i][j]==Polje::Prazno){
					prazna=true;
					break;
				}
			}
			if(prazna) break;
		}
		if(!prazna) return Status::KrajPobjeda;
	}
	return Status::NijeKraj;
}



Status Idi(Tabla &polja, int &x,int &y,int slj_x,int slj_y)
{
	if(slj_x<0 || slj_x>=polja.size() || slj_y<0 || slj_y>=polja.size())  throw out_of_range("Izlazak van igrace table");
	if(polja[slj_x][slj_y]==Polje::BlokiranoPosjeceno || polja[slj_x][slj_y]==Polje::BlokiranoPrazno || polja[slj_x][slj_y]==Polje::BlokiranoMina)
		throw logic_error("Blokirano polje");
		
	polja[x][y]=Polje::Posjeceno;
	x=slj_x; 
	y=slj_y;
		
	if(polja[x][y]==Polje::Mina){
		for(int i=0;i<polja.size();i++){
			for(int j=0;j<polja[i].size();j++){
				polja[i][j]=Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
	else{
		bool prazna(false);
		for(int i=0;i<polja.size();i++){
			for(int j=0;j<polja[i].size();j++){
				if(i==x && j==y) continue;
				else if(polja[i][j]==Polje::Prazno){
					prazna=true;
					break;
				}
			}
			if(prazna) break;
		}
		if(!prazna) return Status::KrajPobjeda;
	}
	return Status::NijeKraj;
}

int main ()
{
	int n;
	cout<<"Unesite broj polja: ";
	cin>>n;

	return 0;
}
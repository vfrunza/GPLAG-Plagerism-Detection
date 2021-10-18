/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iomanip>
#include <iostream>
#include <vector>
#include <stdexcept>

using std::cout;
using std::cin;

enum class Polje {
 Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};
enum class Smjerovi {
 GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};
enum class Status {
 NijeKraj, KrajPoraz, KrajPobjeda
};

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	Tabla tabla(n, std::vector<Polje> (n,Prazno));
	for(int i=0;i<mine.size();i++){
		if(mine[i].size()!=2)throw std::domain_error("Ilegalan nacin zadavanja mina");
		if(mine[i][0] >= n || mine[i][1] >= n)throw std::domain_error("Ilegalne pozicije mina");
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
				if(j == mine[i][0] && k = mine[i][1])
					tabla[j][k] = Mina;
	}
	return tabla;
}
/*
void BlokirajPolje(Tabla &polja, int x, int y){
	if(x >= polja.size() || y >= polja.size())throw std::domain_error("Polje (x,y) ne postoji");
	for(int i=0;i<polja.size();i++){
		for(int j=0;j<polja[i].size;j++){
			if(i==x && j==y && polja[i][j]==Prazno)polja[i][j]==BlokiranoPrazno;
			if(i==x && j==y && polja[i][j]==Posjeceno)polja[i][j]==BlokiranoPosjeceno;
			if(i==x && j==y && polja[i][j]==Mina)polja[i][j]==BlokiranoMina;
		}
	}
}

void DeblokirajPolje(Tabla &polja, int x, int y){
	if(x >= polja.size() || y >= polja.size())throw std::domain_error("Polje (x,y) ne postoji");
	for(int i=0;i<polja.size();i++){
		for(int j=0;j<polja[i].size;j++){
			if(i==x && j==y && polja[i][j]==BlokiranoPrazno)polja[i][j]==Prazno;
			if(i==x && j==y && polja[i][j]==BlokiranoPosjeceno)polja[i][j]==Posjeceno;
			if(i==x && j==y && polja[i][j]==BlokiranoMina)polja[i][j]==Mina;
		}
	}
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	if(y==0 && (smijer==Lijevo || smijer==DoljeLijevo || smijer==GoreLijevo) ||
	|| y==polja.size()-1 && (smijer==Desno || smijer==DoljeDesno || smijer==GoreDesno) ||
	|| x==0 && (smijer==Gore || smijer==GoreDesno || smijer==GoreLijevo) ||
	|| x==polja.size()-1 && (smijer==Dolje || smijer==DoljeDesno || smijer==DoljeLijevo))
					throw std::out_of_range("Izlazak van igrace table");
	
		 if(smijer = Gore)		 {r= 1;k= 0}
	else if(smijer = Dolje)		 {r=-1;k= 0}
	else if(smijer = Lijevo)	 {r= 0;k=-1}
	else if(smijer = Desno)		 {r= 0;k= 1}
	else if(smijer = GoreDesno)	 {r= 1;k= 1}
	else if(smijer = GoreLijevo) {r= 1;k=-1}
	else if(smijer = DoljeDesno) {r=-1;k= 1}
	else if(smijer = DoljeLijevo){r=-1;k=-1}
	
	if(polje[x+r][y+k]==BlokiranoPrazno || polje[x+r][y+k]==BlokiranoPosjeceno || polje[x+r][y+k]==BlokiranoMina )
				throw std::logic_error("Blokirano polje");
	if(polje[x+r][y+k]==Mina){
		for(int i=0;i<polja.size();i++)
			for(int j=0;j<polja.size();j++)
				polje[i][j]=Prazno;
		return KrajPoraz;
	}
	
	Status status(KrajPobjeda);
	for(int i=0;i<polja.size();i++)
			for(int j=0;j<polja.size();j++)
				if(polja[i][j]!=Posjeceno)
					status=NijeKraj;
	
	x+=r;
	y+=k;
	return status;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	if(novi_x >= polja.size() || novi_y >= polja.size())
			throw std::out_of_range("Izlazak van igrace table");
			
	if(polje[novi_x][novi_y]==BlokiranoPrazno || polje[novi_x][novi_y]==BlokiranoPosjeceno || polje[novi_x][novi_y]==BlokiranoMina )
				throw std::logic_error("Blokirano polje");
	if(polje[novi_x][novi_y]==Mina){
		for(int i=0;i<polja.size();i++)
			for(int j=0;j<polja.size();j++)
				polje[i][j]=Prazno;
		return KrajPoraz;
	}
	
	Status status(KrajPobjeda);
	for(int i=0;i<polja.size();i++)
			for(int j=0;j<polja.size();j++)
				if(polja[i][j]!=Posjeceno)
					status=NijeKraj;
	
	x=novi_x;
	y=novi_y;
	return status;
}
*/
int main ()
{
	return 0;
}
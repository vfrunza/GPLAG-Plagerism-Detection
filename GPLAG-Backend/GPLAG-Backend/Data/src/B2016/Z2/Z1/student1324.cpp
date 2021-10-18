/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
enum class Smjerovi{ GoreLijevo , Gore , GoreDesno , Desno , DoljeDesno , Dolje , DoljeLijevo , Lijevo };
enum class Status { NijeKraj , KrajPoraz , KrajPobjeda};
enum class Polje { Prazno,Posjeceno,Mina,BlokiranoPrazno,BlokiranoPosjeceno,BlokiranoMina };
typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n,const std::vector<std::vector<int>> &mine){
	Tabla Igra(n,std::vector<Polje>(n,Polje::Prazno));
	for(int i=0;i<mine.size();i++)if(mine[i].size()>2)throw std::domain_error("Ilegalan format zadavanja mina");
	
	for(int i=0;i<mine.size();i++)if(mine[i][0]>=n || mine[i][1]>=n)throw std::domain_error("Ilegalne pozicije mina");
	
	for(int i=0;i<mine.size();i++){
		Igra[ mine[i][0] ][ mine[i][1] ]=Polje::Mina;
	}
	return Igra;
}
std::vector<std::vector<int>> PrikaziOkolinu (const Tabla &polja,int x,int y){
	if(x<0 || y<0 || x>=polja.size() || y>=polja.size())throw std::domain_error("Polje (x,y) ne postoji");
	std::vector<std::vector<int>> v(3,std::vector<int>(3));
    int i(0),j(0);
    for(int novi_x=x-1;novi_x<=x+1;novi_x++){ 
    	j=0;
    	for(int novi_y=y-1; novi_y<=y+1; novi_y++){
            if(novi_y>=0 && novi_x>=0 && novi_y<polja.size() && novi_x<polja.size()){
    	        int br(0);
    	        for(int a=novi_x-1;a<=novi_x+1;a++){
    		        for(int b=novi_y-1;b<=novi_y+1;b++){
    			        if(a>=0 && a<polja.size() && b>=0 && b<polja.size()) if(polja[a][b]==Polje::Mina) br++;
    		        }
    	        }
    	        if(polja[novi_x][novi_y]==Polje::Mina)br=br-1;
    	        v[i][j]=br;
            }
            j++;
    	}
    	i++;
    }
	return v;
	
}
void BlokirajPolje(Tabla &polja,int x,int y){
	if(x<0 || y<0 || x>=polja.size() || y>=polja.size())throw std::domain_error("Polje (x,y) ne postoji");
	if(polja[x][y]==Polje::Mina) polja[x][y]=Polje::BlokiranoMina;
	if(polja[x][y]==Polje::Prazno) polja[x][y]=Polje::BlokiranoPrazno;
    if(polja[x][y]==Polje::Posjeceno) polja[x][y]=Polje::BlokiranoPosjeceno;
}
void DeblokirajPolje(Tabla &polja, int x,int y){
	if(x<0 || y<0 || x>=polja.size() || y>=polja.size())throw std::domain_error("Polje (x,y) ne postoji");
	if(polja[x][y]==Polje::BlokiranoMina) polja[x][y]=Polje::Mina;
	if(polja[x][y]==Polje::BlokiranoPrazno) polja[x][y]=Polje::Prazno;
    if(polja[x][y]==Polje::BlokiranoPosjeceno) polja[x][y]=Polje::Posjeceno;
}

Status Idi(Tabla &polja,int &x, int &y, Smjerovi smjer){
	if (smjer==Smjerovi::GoreLijevo){ x=x-1; y=y-1;}
	if (smjer==Smjerovi::Gore) x=x-1;
	if (smjer==Smjerovi::GoreDesno){ x=x-1; y=y+1;}
	if (smjer==Smjerovi::Lijevo) y=y-1;
	if (smjer==Smjerovi::Desno) y=y+1;
	if (smjer==Smjerovi::DoljeDesno){ x=x+1; y=y+1;}
	if (smjer==Smjerovi::DoljeLijevo){ x=x+1; y=y-1;}
	if (smjer==Smjerovi::Dolje)x=x+1;
}
Status Idi(Tabla &polja,int &x, int &y,int novi_x,int novi_y){
	if(novi_x<0 || novi_y<0 || novi_x>=polja.size() || novi_y>=polja.size())throw std::out_of_range("Izlazak van igrace table");
	if(1){
		x=novi_x;
		y=novi_y;
	}
}

int main ()
{
	std::vector<std::vector<int>> mine = {{0,1}, {0,4}, {1,3}, {1,4}, {2,0}, {2,1}, {2,3}} ;
	std::vector<std::vector<Polje>> tabla = KreirajIgru(5, mine);
	std::vector<std::vector<int>> okolina = PrikaziOkolinu(tabla, 1, 1);
	for(int i = 0; i < okolina.size(); i++)
	{
	  for(int j = 0; j < okolina[i].size(); j++) std::cout << okolina[i][j] << " ";
	  std::cout << std::endl;
	}
	
	return 0;
}
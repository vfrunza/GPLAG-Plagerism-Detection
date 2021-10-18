/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <vector>

enum class Polje{
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina};
	
enum class Smjerovi{
	GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo};
	
enum class Status{
	NijeKraj,KrajPoraz, KrajPobjeda};

enum class KodoviGresaka{
	PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar};

enum class Komande{
	PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru};

typedef std::vector<std::vector<Polje>> Tabla;
	
	
Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
		Tabla igra;

		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==mine[i][0] && j==mine[i][1]){
					igra[i][j]=Polje::Mina;
				}
				else igra[i][j]=Polje::Prazno;
			}
		}
	return igra;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
    	std::vector<std::vector<int>> okolina(3,std::vector<int>(3));
   
    	int brojac=0;
    	for(int i=x-1;i<=x+1;i++){
    		for(int j=y-1;j<=y+1;j++){
    	
    			if(i>0 && j>0 && int(polja[x-1][y-1])==1) brojac++;
    			if(i>0 && j>0 && int(polja[x-1][y])==1) brojac++;
    			if(i>0 && j>0 && int(polja[x-1][y+1])==1) brojac++;
    			if(i>0 && j>0 && int(polja[x][y-1])==1) brojac++;
    			if(i>0 && j>0 && int(polja[x][y])==1) brojac++; //provjeri jel se pika ova
    			if(i>0 && j>0 && int(polja[x][y+1])==1) brojac++;
    			if(i>0 && j>0 && int(polja[x+1][y-1])==1) brojac++;
    			if(i>0 && j>0 && int(polja[x+1][y])==1) brojac++;
    			if(i>0 && j>0 && int(polja[x+1][y+1])==1) brojac++;
    		}
    		okolina[i].push_back(brojac);
    	}
    	return okolina;
}
    
/*void BlokirajPolje(Tabla &polja, int x, int y){
    	for(int i=0;i<polja.size();i++){
    		for(int j=0;j<polja[0].size();j++){
    			if(x==polja[i] && y==polja[j] && Tabla==Polje::Prazno) Tabla==Polje::BlokiranoPrazno;
    			else if(x==polja[i] && y==polja[j] && Tabla==Polje::Posjeceno) Tabla==Polje::BlokiranoPosjeceno;
    			else if(x==polja[i] && y==polja[j] && Tabla==Polje::Mina) Tabla==Polje::BlokiranoMina;
    		}
    	}
}
    */
  //  void DeblokirajPolje(Tabla &polja, int x, int y);
    
  //  Status Idi (Tabla &polja, int &x, int &y, Smjerovi smjer);
    
 //   Status Idi (Tabla &polja, int &x, int &y, int novi_x, int novi_y);
    
 //   std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y);

int main ()
{
	int n;
	std::cout<<"Unesite broj polja: ";
	std::cin>>n;
	std::cout<<"Unesite pozicije mina: ";

    std::vector<std::vector<int>>mine;
	
	for(int i=0;i<n;i++){
			std::cout<<"(";
		std::cin>>mine[i][0];
		std::cout<<",";
		
		std::cin>>mine[i][1];
		std::cout<<")\n";
	}
	
//	KreirajIgru(n,mine);
	
	return 0;
}
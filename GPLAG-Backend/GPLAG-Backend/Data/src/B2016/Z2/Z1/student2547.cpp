/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>

enum class Polje{
		Prazno,Prosjecno,Mina,BlokiranoPrazno,BlokiranoProsjecno,BlokiranoMina
};

typedef std::vector<std::vector<Polje>> Tabla;

/*... IMPLEMENTIRATI OVE FUNKCIJE............
Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine);
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y);
void BlokirajPolje(Tabla &polja, int x, int y);
void DeblokirajPolje(Tabla &polja, int x, int y);
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer);
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y);
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y);

*/
	
Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	//...DEKLARACIJA..
	Tabla t = {};
	
	//..NAPRAVI MATRICU...INICIJALIZIRAJ NA PRAZNO
	for(int i (0); i < n; i++){
		t.push_back(std::vector<Polje> ());
		for(int j (0); j < n;j++){
			t[i].push_back(Polje(0));
		}
	}
	
	//..POSTAVI MINE NA ODGOVARAJUCU POZICIJU....
	for(int i (0); i < mine.size() ; i++){
		
		if(mine[i][0] >= t.size()) throw std::domain_error("Ilegalne pozicije mina!\n");
		if(mine[i][1] >= t[mine[i][0]]. size() ) throw std::domain_error("Ilegalne pozicije mina!\n");
		
		
		t[mine[i][0]][mine[i][1]] = Polje(1);
	}
	
	//... test ISPISI
	for(int i (0); i < t.size();i++){
		for(int j (0); j < t[i].size();j++){
			std::cout<< int(t[i][j])<<" ";
		}
		std::cout<<std::endl;
	}
	
	return t;
}	
	
	

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	
	//...NAPRAVI MATRICU
	std::vector<std::vector<int>> okolina = { {0,0,0}, {0,0,0}, {0,0,0} };
	
	int i = x, j = y;
	while(true){
		if(i - 1 > 0 ){
			if(j - 1 > 0){
				for(int k (i - 1), l (j - 1); k < i + 2; k++ , l++){
					//.... OKOLINA 9
					if(){
						
						
					}
				}
			}
		}
	}
	
	
	
	
	
	return;
}	
	
int main ()
{
	//...TEST
	std::cout<<"Unesi:\n";
	int n;
	std::cin >>n;
	try{
		
	std::vector<std::vector<int>> mine = { {0,0} , {0,2} , {1,3} };
	Tabla TAB = KreirajIgru(n,mine);
	
	}catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what();
	}
	return 0;
}
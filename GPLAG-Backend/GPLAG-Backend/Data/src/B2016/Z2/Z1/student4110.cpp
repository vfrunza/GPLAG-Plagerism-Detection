/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>

enum class Polje { Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoProsjeceno, BlokiranoMina };

typedef std::vector<std::vector<Polje>> Tabla;



Tabla KreirajIgru (int n, const std::vector<std::vector<int> &mine)
{
	//Treba dodati Try Catcheve za ovu funkciju

	Tabla T(n, std::vector<Polje>(n,Prazno));
	
	//Potrebno promijeniti vrijednost svakog polja iz Prazno u Mina za svaku poziciju zadanu u matrici 'mine'
	int x,y;
	for(int i=0;i<mine.size();i++)
	 {
	  for(int j=0;j<2;j++)
	   {
	   	 if(j==0) x=mine[i][j];
	   	 else if(j==1) y=mine[i][j];
	     Tabla[x][y]=Mina;
	   }
	 	
	 }
	
  return T;
 	
}

std::vector<std::vector<int>>PrikaziOkolinu(const Tabla &polje, int x, int y)
{
	std::vector<std::vector<int> Okolina(3,std::vector<int>(3));
	
	
	 
	polje[x-1][y-1]
	polje[x-1][y]
	polje[x-1][y+1]
	polje[x][y-1]
	polje[x][y]
	polje[x][y+1]
	polje[x+1][y-1]
	polje[x+1][y]
	polje[x+1][j+1]
	
}

int main ()
{
	int br_polja;
	std::cout<<"Unesite broj polja: ";
	std::cin>>br_polja;
	std::cout<<"Unesite pozicije mina: ";
	
	
	
	return 0;
}
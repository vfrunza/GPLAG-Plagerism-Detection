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
#include <iomanip>
#include <vector>
#include <stdexcept>

enum class Komande {
 PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu,
 ZavrsiIgru, KreirajIgru
};

auto KeirajIgru(int a,std::vector<std::vector<int>>mine){

int c=mine.size();
std::vector<std::vector<int>>tabla(10, std::vector<int>(10));
for(int i=0;i<a;i++) {
	for(int j=0;j<a;j++) {
		for(int p=0;p<c;p++){
			for(int z=0;z<2;z++) {
				for(int r=0;r<2;r++) {
				
					if(i==mine[p][z] && j==mine[p][r])tabla[i][j]=1;
					else tabla[i][j]=0;
				}
				
			}
		}
	}
}

return tabla;
}







int main ()
{
	int br_polja;
	char k;
	std::cout<<"Unesite komandu: ";

	std::cout<<"Unesite broj polja: ";
 while(!(std::cin>>br_polja) || std::cin.peek()!='\n'){
 	std::cin.clear();
        std::cin.ignore(1000, '\n');
 	std::cout<<"Pogresan unos";
 }
 std::cout<<"Unesite poziciju mina: ";
 std::vector<std::vector<int>>mina(10, std::vector<int>(10));
 for(int i=0;i<br_polja;i++) {
 	for(int j=0;j<2;j++) {
 		std::cin>>mina[i][j];
 	}
 }
 int a;
 std::cout<<"Unesite broj elemenata table: ";
 std::cin>>a;
 	std::cin.clear();
        std::cin.ignore(1000, '\n');
 auto P(KeirajIgru(a, mina));
 for(int i=0;i<a;i++) {
 	for(int j=0;j<a;j++) {
 		std::cout<<std::setw(4)<<P[i][j];
 	}
 	std::cout<<std::endl;
 }
 
 
 
	return 0;
}
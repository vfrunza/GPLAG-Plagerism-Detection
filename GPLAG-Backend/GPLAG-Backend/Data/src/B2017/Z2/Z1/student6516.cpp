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
enum class Polje {
 Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};
typedef std::vector<std::vector<Polje>> Tabla;
Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){

Tabla mat;
mat(n,std::vector<Polje>(n,Polje::Prazno));
for(int i=0;i<mine.size();i++){
	mat[mine[i][0]][mine[i][1]]=Polje::Prazno;
}
return mat;

}


	



int main ()
{
	return 0;
}
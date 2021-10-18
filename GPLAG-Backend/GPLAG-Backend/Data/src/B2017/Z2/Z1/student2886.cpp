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
#include <stdexcept>

enum class Polje {
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};
typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru (int n, std::vector<std::vector<int>> mine){
	if (n<=0) throw std::domain_error("Ilegalna velicina");
	bool istina(1);
	bool dobarbroj(1);
	for (int i=0; i<mine.size(); i++){
		for (int j=0; j<mine.at(0).size(); j++){
			if (mine.at(i).size()!=2) istina=0;
			if (mine.at(i).at(j)>=n) dobarbroj=0;
		}
	}
	
	if (!istina) throw std::domain_error("Ilegalan format zadavanja mina");
	if (!dobarbroj) throw std::domain_error ("Ilegalne pozicije mina");
	 
	 Tabla a(n, std::vector<Polje>n);
	
return a;	
}


int main ()
{
	try{
		
	}
	catch (std::domain_error a){
		std::cout << a.what() << std::endl;
	}
	return 0;
}
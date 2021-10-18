/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <new>
#include <stdexcept>
#include <vector>
#include <string>

	int PotencijalniKrivci(char **&n, std::vector<std::string>v){
		int **niz_pok;
		try{
			niz_pok = new char*[v.size()];
			int brojac(0);
			try{
				while(brojac < v.size())
				niz_pok[brojac++] = new char [v[i].size()+1];
			}
		catch(...){
			for(int i=0; i<brojac; i++)
				delete[] niz_pok[i];
			delete[] niz_pok;
			throw std::bad_alloc();
			}
		}
		catch(...){
			throw;
		}
		n = niz_pok;
		return brojac;
	}
	
	OdbaciOptuzbu(**&n, int vel, std::string s){
		for(int i=0; i<vel; i++){
			
		}
	}
int main ()
{
	return 0;
}
/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <vector>
#include <string>
int PotencijalniKrivci(char **&pok,std::vector<std::string> vektor_stringova) {
	int broj_alociranih(0);
	int velicina=vektor_stringova.size();
	try{
		pok=new char*[velicina];
		for(int i=0;i<velicina;i++) {
			pok[i]=nullptr;
		}
		for(int i=0;i<velicina;i++) {
			try{
				std::string s=vektor_stringova[i];
				int duzina=s.length()+1;
				pok[i]=new char[duzina];
			}
			catch(...) {
				delete[] pok[i];
			}
		}
	}
	catch(...) {
		throw;
	}
	return broj_alociranih;
}
int main ()
{
	return 0;
}
/*B 2017/2018, Zadaća 2, Zadatak 3
	
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
#include<algorithm>

template<typename tip>

tip **AlocirajFragmentirano(const std::vector<tip> &prim,int koliko_puta){
	if(prim.size()<=0)throw std::domain_error("Izuzetak:Neispravan vektor!");
	if(koliko_puta<=0)throw std::domain_error("Neispravan broj ponavljanja");
	int **pok=nullptr;
	try{
		pok=new int*[koliko_puta*prim.size()];
		for(int i=0;i<koliko_puta;i++){
			for(int j=i*prim.size();j<i*prim.size()+prim.size();j++){
				if(prim[j-i*prim.size()]<=0){
					delete []pok;
					throw std::domain_error("Izuzetak:Neispravan vektor!");
				}
				else pok[i*prim.size()+j]=new int[prim[j-i*prim.size()]];
			}
		}
	}
	catch(...){
		for(int a=0;a<koliko_puta;a++){
			for(int b=0+a*prim.size();b<(a+1)*prim.size();b++){
				delete[]pok[b];
			}
		}
		delete[] pok;
		throw;
	}
	return pok;
}
/*template<typename tip>
tip **AlocirajKontinualno(const std::vector<tip>&prim,int koliko_puta){
	int mak=*max_element(prim.begin(),prim.end());
	if(prim.size()<=0)throw std::domain_error("Izuzetak:Neispravan vektor!");
	tip** pok2=nullptr;
	try{
		pok2=new int*[prim.size()*koliko_puta];
		pok2[0]=new int[prim.size()*koliko_puta*max];
		int temp=1;
		for(int i=0;i<koliko_puta;i++){
			for(int j=0;j<prim.size();j++){
				if(prim[j]<=0){
					delete []pok2[0];
					delete []pok2;
					throw std::domain_error("Izuzetak:Neispravan vektor!");
				}
			}
		}
	}
}
*/
int main ()
{
	return 0;
}
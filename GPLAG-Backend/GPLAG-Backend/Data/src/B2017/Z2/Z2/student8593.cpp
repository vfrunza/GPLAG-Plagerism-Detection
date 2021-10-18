/*B 2017/2018, Zadaća 2, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include<stdexcept>
#include<type_traits>
template<typename Tip,typename SmjerKretanja>

Tip PjescaniSat(Tip kont,SmjerKretanja Smjer){
	for(int i(0);i<kont.size();i++){
		for(int j(0);j<kont.at(0).size();j++){
			for(int k(0);k<kont.at(0).size();k++){
				if(kont.at(i).size()!=kont.size()|| kont.at(i).at(j).size()!=kont.size()) throw std::domain_error("3D matrica nema oblik kocke");
			}
		}
	}
	if(kont.size()%2!=1) throw std::length_error();
	Tip rezultat;
	if(smjer==SmjerKretanja::GoreDolje){
		for(int i(0);i<kont.size();i++){
		
		typename std::remove_reference<decltype(kont.at(0))>type matrica;
		rezultat.push_back(matrica);
		for(int j(0);j<kont.at(i).size();j++){
			typename std::remove_reference<decltype(kont.at(0).at(0))>::type red;
			rezultat.push_back(red);
			
			if(j<kont.at(i.size()/2)){
				int brojZauzetih(kont.at(i).size()-2*j);
				int pocetniIndeks(brojZauzetih/2);
				int krajnjiIndeks(kont.at(i).size()-pocetniIndeks-1);
				
			}
			else{
				int poslijepolovine(j-kont.at(i).size()/2);
				int brojZauzeti(kont.at(i).size()-2*posljednji);
			}
			for(int k(pocetniIndeks);k<krajnjiIndeks;k++){
				rezultat.at(i).at(j).push_back(kont.at(i).at(j).at(k));}
				
		}
	}
}

int main ()
{
	return 0;
}
/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/

#include <iostream>
#include <stdexcept>
#include <cmath>
#include <iterator>
#include <algorithm>
#include <set>
#include <vector>

template <typename NekiTip1 , typename NekiTip2>

NekiTip1 UvrnutiPresjek ( NekiTip1 pok1 , NekiTip1 pok2 , NekiTip2 novi_pok1 , NekiTip2 novi_pok2){
	int suma1;
	int suma2;
	int cifra;
	std::vector<NekiTip1> pomocni1;
	std::vector<NekiTip2> pomocni2;
	for(NekiTip1 i = pok1 ; i != pok2 ; i++){
		suma1= 0;
		for( NekiTip1 j = i ; j != pok2 ; j++){
			cifra = j%10;
			j/=10;
		}
		suma1+=cifra;
		pomocni1.push_back(suma1);
	}
	
	for(NekiTip2 i = novi_pok1 ; i != novi_pok2; i++){
		suma2 = 0 ; 
		for(NekiTip2 j = i ; j != novi_pok2; j++){
			cifra = j % 10;
			j/=10;
		}
		suma2+=cifra;
		pomocni2.push_back(suma2);
	}
		
		std::set<NekiTip1> skup_parova;
	
	for( int i = 0 ; i < pomocni1.size(); i++){
		for( int j = 0 ; j < pomocni2.size(); j++){
			for (NekiTip1 k = pok1; k != pok2 ; k++){
				for( NekiTip2 z = novi_pok1 ; z != novi_pok2 ; z++){
					if( pomocni1.at(i) = pomocni2.at(j)) {
						skup_parova.insert(pok1);
						skup_parova.insert(novi_pok1);
					} else {
						k++;
						z++;
					}
				}
			}
		}
	}
	
	
	return skup_parova;
	
	
}

int main ()
{
	int n ;
	std::cout<<"Unesite broj elemenata: ";
	std::cin>>n;
	std::cout<<"Unesite elemente: ";
	std::set<int> skup1;
	for( int i = 0 ; i < n ; i++){
		int x ; 
		skup1.insert(x);
	}
	
	std::set<int> skup2;
	for(int i = 0 ; i < n ; i++){
		int x ; 
		skup2.insert(x);
	}
	
	std::set<int> skup(UvrnutiPresjek(std::begin(skup1),std::end(skup1),std::begin(skup2),std::end(skup2)));
	std::cout<<"Elementi skupa su: ";
	for(int i = 0 ; i < skup.size(); skup++){
		std::cout<<skup<<" ";
	}
	
	
	return 0;
}
/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <type_traits>
#include <iomanip>

int SumaCifara (int n){
	int suma(0);
	while(n){
		suma+= n%10;
		n/=10;
	}
	return suma;
}

template <typename Tip1, typename Tip2, typename TipF, typename TipFParam>
	auto UvrnutiPresjek (Tip1 b1, Tip1 b1_end, Tip2 b2, Tip2 b2_end, TipF fun(TipFParam)) -> typename std::remove_reference<decltype(*b1)>::type**{
		std::vector<std::vector<Tip1>> Matrica;
		while(b1 < b1_end){
			while(b2 < b2_end){
				if(fun(*b1) == fun(*b2)){
					
				}
				b2++;
			}
			b1++;
		}
		return Matrica;
	}

int main ()
{
	std::vector<int> b1{15, 16, 17, 12, 13, 14};
	std::vector<int> b2{31, 51, 91, 71, 21, 31, 51, 23, 24, 22};
	std::vector<std::vector<int>> Matrica(UvrnutiPresjek(b1.begin(), b1.end(), b2.begin(), b2.end(), SumaCifara));
	for(int i=0; i<Matrica.size(); i++){
		for(int j=0; j<Matrica.at(i).size(); j++){
			std::cout << std::setw(6)<<Matrica.at(i).at(j);
		}
		std::cout << std::endl;
	}
	return 0;
}
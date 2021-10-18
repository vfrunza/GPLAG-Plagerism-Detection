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

template <typename NekiTip>
	bool DaLiJePeriodicna(std::vector<NekiTip> &v, int &osnovni_period){
		for(int i=0; i<v.size(); i++){
			for(int j=i+1; j<v.size(); j++){
				if(v[i]==v[j]){
					i++;
					j++;
					while(j<v.size()){
						
					}
				}
			}
		}
	}
	
template <typename NekiTip>
	DopuniPeriodicno(){
		
	}

template<typename NekiTip>
	DopuniNePeriodicno(){
		
	}

template <typename NekiTip>
	void AlocirajFragmentirano(const std::vector<NekiTip> &v, int &koliko_puta){
	
	int osnovni_period;
	if(DaLiJePeriodicna(v, osnovni_period))DopuniPeriodicno(v, koliko_puta);
	else DopuniNePeriodicno(v, koliko_puta);
	
	}
template <typename NekiTip>
	void AlocirajKontinualno(const std::vector<NekiTip> &v, int &koliko_puta){
		
	int osnovni_period;
	
	}

int main ()
{
	int n;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	return 0;
}
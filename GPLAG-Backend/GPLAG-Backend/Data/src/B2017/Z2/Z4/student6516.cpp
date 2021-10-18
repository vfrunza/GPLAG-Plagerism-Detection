/*B 2017/2018, Zadaća 2, Zadatak 4

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>
int prosti(int x)
{
	int brojac=0;
	for(int j=2; j<10; j++) {
		if(x<=0) return brojac;
		if(x==j) continue;
		else if(x%j==0) brojac++;
	}
	return brojac;
}

template <typename NekiTip1, typename NekiTip2, typename NekiTip3>
auto SortirajPodrucjeVrijednosti(NekiTip1 poc1,NekiTip1 kraj1, NekiTip2 poc2, NekiTip3 poc3,NekiTip3 fun(NekiTip1,NekiTip2),bool prost(int,int))->typename std::remove_reference<decltype(*poc3)>::type {
	int duzina=0;
  
	std::sort(poc1,kraj1,prost);
	int br=std::distance(poc1,kraj1);
	std::sort(poc2,poc2+br,prost);
	for(int i=0; i<br; i++) {

		for(int j=0; j<br; j++) {
			if(fun(*(poc1+i),*(poc2+i))==*(poc3+j)) {
				duzina++;
			}
		}

	}

	if(duzina!=br) {
		throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
		
	} else {
		for(int i=0; i<br; i++) {
			int jeste=0;
			for(int j=0; j<br; j++) {
				if(fun(*(poc1+i),*(poc2+i))==*(poc3+j)) {
					auto temp=*(poc3+i);
					*(poc3+i)=*(poc3+j);
					*(poc3+j)=temp;

				}
			}

		}
	}

}

int main ()
{
	std::cout<<"Unesite broj elemenata: ";
	int n;
	std::cin >>n;
	std::cout <<"Unesite elemente prvog vektora: ";
	int element;
	std::vector<int> v1;
	std::vector<int> v2;
	std::vector<int> v3;
	for(int i=0; i<n; i++) {
		std::cin>>element;
		int bio=0;
		bool isti=true;
		for(int j=0;j<i;j++){
			if(v1[j]==element){
				bio=1;
				isti=false;
			}
		}
		if(isti)v1.push_back(element);
		i=i-bio;
	}
	std::cout <<"Unesite elemente drugog vektora: ";
	for(int i=0; i<n; i++) {
		std::cin>>element;
		int bio=0;
		bool isti=true;
		for(int j=0;j<i;j++){
			if(v2[j]==element){
				bio=1;
				isti=false;
			}
		}
		if(isti)v2.push_back(element);
		i=i-bio;
	}
	std::cout <<"Unesite elemente treceg vektora: ";
	for(int i=0; i<n; i++) {
		std::cin>>element;
		int bio=0;
		bool isti=true;
		for(int j=0;j<i;j++){
			if(v3[j]==element){
				bio=1;
				isti=false;
			}
		}
		if(isti)v3.push_back(element);
		i=i-bio;
	}

	try {
		auto poc=SortirajPodrucjeVrijednosti(v1.begin(),v1.end(),v2.begin(),v3.begin(),[](int x,int y) {return -2*x+y;},[](int x,int y){if(x>y && prosti(x)==prosti(y)) return true;
	else if(prosti(x)>prosti(y)) return true;
	return false;
});
		std::cout <<std::endl<<"Nakon sortiranja podrucja vrijednosti imamo sljedece trojke:"<<std::endl;
		for(int i=0; i<n; i++) {
			std::cout <<"f("<<v1[i]<<", "<<v2[i]<<") = "<<v3[i]<<std::endl;
		}

	} catch(std::logic_error izuzetak) {
		std::cout <<std::endl<<"Izuzetak: "<<izuzetak.what();
		return 0;
	}
m	return 0;
}
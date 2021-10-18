#include <iostream>
#include<vector>
#include<deque>
#include<string>
#include<cmath>
#include<algorithm>
#include<functional>
#include<type_traits>
#include<set>
bool DaLiJeProst(int broj)
{
	if(broj<=1) return false;
	for(int i(2); i<=std::sqrt(broj); i++) {
		if(broj%i==0) return false;
	}
	return true;
}
int BrojProstihFaktora(int broj)
{
	int brojac(0);
	while(broj!=1) {
		for(int i(2); i<=broj; i++) {
			if(broj%i==0) {
				if(DaLiJeProst(i)) {
					brojac++;
					broj/=i;
				}
			}
		}
	}
	return brojac;
}
template<typename Tip1, typename Tip2, typename Tip3, typename Fun1, typename Fun2>
void SortirajPodrucjeVrijednosti (Tip1 p1, Tip1 p2, Tip2 p3, Tip3 p4, Fun1 f, Fun2 kriterij)
{
	auto poc1(p1),kraj1(p2);
	int vel(kraj1-poc1);
	auto poc2(p3);
	std::sort(poc1,kraj1,kriterij);
	std::sort(poc2,poc2+vel,kriterij);
	int pozicija(0);
	std::transform(p1,p2,p3,p4,[f, p4,vel,&pozicija] (typename std::remove_reference<decltype(*p1)>::type x, typename std::remove_reference<decltype(*p1)>::type y) {
		auto rez (f(x,y));
		auto ima(std::find(p4,p4+vel,rez));
		if(ima!=(p4+vel)) {
			*(p4+pozicija)=rez;
			pozicija++;
		} else throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
	});

}
int main ()
{
	try {
		int brojelemenata;
		std::cout<<"Unesite broj elemenata: ";
		std::cin>>brojelemenata;
		std::vector<int> v1(brojelemenata);
		std::vector<int> v2(brojelemenata);
		std::cout<<"Unesite elemente prvog vektora: ";
		for(int i(0); i<v1.size(); i++) std::cin>>v1.at(i);
		std::cout<<"Unesite elemente drugog vektora: ";
		for(int i(0); i<v2.size(); i++) std::cin>>v2.at(i);
		std::vector<int> rezultat(brojelemenata);
		SortirajPodrucjeVrijednosti(v1.begin(),v1.end(),v2.begin(),rezultat.begin(),[](int x, int y) {
			return -2*x+y;
		}, [](int x, int y) {
			return BrojProstihFaktora(x)>BrojProstihFaktora(y);
		});
		std::cout<<"Sortirani: ";
		for(auto x: rezultat) std::cout<<x<<" ";
	}
	catch(std::logic_error izuz) {
		std::cout<<izuz.what()<<std::endl;
	}
	return 0;
}
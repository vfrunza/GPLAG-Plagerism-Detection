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
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <type_traits>
#include <cmath>
bool Prost(int x)
{
	if(x<=1) return false;
	for(int i(2);i<std::sqrt(x);i++)
	{
		if(x%i==0) return false;
	}
	return true;
}
bool ProstiFaktor(int broj,int broj2)
{
	int novi=broj,novi2=broj2;
	if(broj<0) {
		broj*=-1;
	}
	if(broj2<0) {
		broj2*=-1;
	}
	int brojac1(0);
		for(int i(1);i<broj;i++){
			if(broj%i==0){
					broj/=i;
				 if(Prost(i)){
					brojac1++;
				}
				i=1;
			}
		}
	int brojac2(0);
		for(int i(1);i<broj2;i++){
			if(broj2%i==0){
					broj2/=i;
				  if(Prost(i)){
					brojac2++;
				}
				i=1;
			} 
		}
		if(novi<0||novi2<0){
			if(brojac1==brojac2&&novi>novi2) return true;
		}
		if(novi>=0&&novi2>=0){
		if(brojac1==brojac2&&novi>novi2) return true;
		}
		if(brojac1>brojac2) return true;
	return false;
}
int fun(int x,int y){
	return x*(-2)+y;
}
template <typename Tip1,typename Tip2,typename Tip3>
void SortirajPodrucjeVrijednosti(Tip1 prvi_prvog, Tip1 zadnji_prvog, Tip2 prvi_drugog, Tip3 prvi_treceg ,auto f(typename std::remove_reference<decltype(*prvi_prvog)>::type,typename std::remove_reference<decltype(*prvi_drugog)>::type)-> typename std::remove_reference<decltype(*prvi_treceg)>::type , bool ProstiFaktor(typename std::remove_reference<decltype(*prvi_prvog)>::type,typename std::remove_reference<decltype(*prvi_drugog)>::type))

{
	
	int brojac(0),pozicija(0);
	try{
    typename std::remove_reference<decltype(*prvi_treceg)>::type pom,pom2; 
	while(prvi_prvog!=zadnji_prvog)
	{
		brojac++;
		prvi_prvog++;

	}
	prvi_prvog-=brojac;
	std::sort(prvi_prvog,zadnji_prvog,ProstiFaktor);
	std::sort(prvi_drugog,prvi_drugog+brojac,ProstiFaktor);
	int pom_brojac(0),i(0);
	while(prvi_prvog!=zadnji_prvog)
	{
		i=0;
		pom_brojac=0;
		pom=f(*prvi_prvog,*prvi_drugog);
		while(i!=brojac)
		{
		if(pom==*(prvi_treceg+i))
		{
			pom_brojac++;
			pom2=*(prvi_treceg+i);
			break;
		}
		i++;
		}
		if(pom_brojac==0) throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
		*(prvi_treceg+i)=*(prvi_treceg+pozicija);
		*(prvi_treceg+pozicija)=pom2;
		prvi_drugog++;
		prvi_prvog++;
		pozicija++;
	}
	}
	catch(std::logic_error)
	{
		throw;
	}
}

int main ()
{
	try{
	int n(0),unos,pom(0);
	std::cout<<"Unesite broj elemenata: ";
	std::cin>>n;
	std::vector<int> v1;
	std::cout<<"Unesite elemente prvog vektora: ";
	while(1)
	 {
	 	if(v1.size()==n) break;
	 	std::cin>>unos;
	 	pom=0;
	 	for(int j(0);j<v1.size();j++)
	 	{
	 		if(v1.at(j)==unos) pom++;
	 	}
	 	if(pom>=1) continue;
	 	v1.push_back(unos);
	 }
	std::vector<int> v2;
	std::cout<<"Unesite elemente drugog vektora: ";
	while(1)
	 {
	 	if(v2.size()==n) break;
	 	std::cin>>unos;
	 	pom=0;
	 	for(int j(0);j<v2.size();j++)
	 	{
	 		if(v2.at(j)==unos) pom++;
	 	}
	 	if(pom>=1) continue;
	 	v2.push_back(unos);
	 	
	 }
	std::vector<int> v3;
	std::cout<<"Unesite elemente treceg vektora: ";
	while(1)
	 {
	 	if(v3.size()==n) break;
	 	std::cin>>unos;
	 	pom=0;
	 	for(int j(0);j<v3.size();j++)
	 	{
	 		if(v3.at(j)==unos) pom++;
	 	}
	 	if(pom>=1) continue;
	 	v3.push_back(unos);
	 }
    std::cout<<std::endl;
    SortirajPodrucjeVrijednosti(v1.begin(),v1.end(),v2.begin(),v3.begin(),fun,ProstiFaktor);
    std::cout<<"Nakon sortiranja podrucja vrijednosti imamo sljedece trojke: "<<std::endl; 
    for(int i(0);i<n;i++)
    {
    	std::cout<<"f("<<v1.at(i)<<", "<<v2.at(i)<<") = "<<v3.at(i)<<std::endl;
    }
	}
	catch(std::logic_error e)
	{
		std::cout<<"Izuzetak: "<<e.what();
	}
	return 0;
}
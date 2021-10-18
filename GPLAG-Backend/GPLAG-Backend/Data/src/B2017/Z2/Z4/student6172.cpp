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
#include <type_traits>
#include <vector>
#include <cmath>
typedef std::vector<int>Vektor;
template< typename Itertip1,typename Itertip2,typename Itertip3>
bool prost(int x){
	for(int i=2;i<x;i++){
		if(x%i==0) return false;
	}
	return true;
}
int brprostih(int a){
	int br(0);
	for(int i=2;i<a;i++){
		bool b(prost(i));
		if(b){
			if(a%i==0) br++;
		}
		
	}
	return br;
}
bool brojprostihfaktora(int x,int y){
	if(brprostih(x)==brprostih(y)) return x>y;
	return brprostih(x)>brprostih(y);
}
void SortirajPodrucjeVrijednosti(Itertip1 poc1,Itertip2 izakraja1,Itertip2 poc2,Itertip3 poc3,
                                 decltype(*poc3+*poc3) f(decltype(*poc1+*poc1),decltype(*poc1+*poc1)),bool fkrit(decltype(*poc1+*poc1),decltype(*poc1+*poc1)))
{
	int brel(izakraja1-poc1);
	std::sort(poc1,izakraja1,fkrit);
	std::sort(poc2,poc2+brel,fkrit);
	int poz(0);//pozicija na koju ubacujemo element n u treci blok
	while(poc1!=izakraja1) {
		auto n(f(*poc1,*poc2));
		decltype(*poc3+*poc3) pompok;
		pompok=find(poc3,poc3+brel,n);
		if(pompok==poc3+brel) throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
		std::swap(*pompok,*(poz+poc3));
		poz++;
		poc1++;
		poc2++;

	}
}

int main ()
{
	std::cout<<"Unesite broj elemenata: ";
	int n;
	std::cin>>n;
	Vektor v1(n);
	int x;
	std::cout<<"Unesite elemente prvog vektora: ";
	for(int i=0; i<n; i++) {
		std::cin>>x;
		bool postoji(false);
		for(int j=0; j<v1.end()-v1.begin(); j++) {
			if(v1.at(j)==x) postoji=true;
		}
		if(!postoji)	v1.at(i)=x;
		else i--;
	}
	std::cout<<"Unesite elemente drugog vektora: ";
	Vektor v2(n);
	for(int i=0; i<n; i++) {
		std::cin>>x;
		bool postoji(false);
		for(int j=0; j<v2.end()-v2.begin(); j++) {
			if(v2.at(j)==x) postoji=true;
		}
		if(!postoji)	v2.at(i)=x;
		else i--;
	}
	std::cout<<"Unesite elemente treceg vektora: ";
	Vektor v3(n);
	for(int i=0; i<n; i++) {
		std::cin>>x;
		bool postoji(false);
		for(int j=0; j<v3.end()-v3.begin(); j++) {
			if(v3.at(j)==x) postoji=true;
		}
		if(!postoji)	v3.at(i)=x;
		else i--;
	}
	SortirajPodrucjeVrijednosti(v1.begin(),v1.end(),v2.begin(),v3.begin(),
	[](int x,int y){return -2*x+y;},brojprostihfaktora);
	std::cout<<"Nakon sortiranja podrucja vrijednosti imamo sljedece trojke: ";
	return 0;
}
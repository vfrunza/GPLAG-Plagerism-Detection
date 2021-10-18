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
#include <stdexcept>
#include <vector> 
#include <cmath>

bool prost(int a){
	
	if(a<=1 || (a%2==0 && a!=2)) return false;
	for(int i=2;i<=sqrt(a);i++){
		if(a%i==0) return false;
	}
	return true;
}


int broj_prostih_faktora(int a){
	int brojac(0);
	for(int i=2;i<=a;i++){
	if(a%i==0 && prost(i)) {
		brojac++;
		
		a/=i;
		i=1;
	}
	}
	return brojac;
	
}

bool faktori (int a, int b){
	int x(broj_prostih_faktora(a)),y(broj_prostih_faktora(b));
	if(x!=y) return x>y;
	return a>b;
}

template <typename Tip1, typename Tip2, typename Tip3>
void SortirajPodrucjeVrijednosti(Tip1 p1, Tip1 p2, Tip2 p3, Tip3 p4, typename std::remove_reference<decltype(*p4)>::type f1(typename std::remove_reference<decltype(*p1)>::type, 
typename std::remove_reference<decltype(*p1)>::type), bool f2(typename std::remove_reference<decltype(*p1)>::type,typename  std::remove_reference<decltype(*p1)>::type) ){
int duzina(p2-p1);
	
	std::sort(p1,p2,f2);
	std::sort(p3, p3+duzina,f2);
for(int i=0;i<duzina;i++){
	Tip3 pokazivac(std::find(p4,p4+duzina, f1(p1[i],p3[i])));
	if(pokazivac==p4+duzina) throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
	typename std::remove_reference<decltype(*p4)>::type pomocna(*pokazivac);
	*pokazivac=p4[i];
	p4[i]=pomocna;

	
}	
	
	
}

void unos(std::vector<int>&v,int n){
	int i=0,broj;
	while(i<n){
		std::cin>>broj;
		if(std::find(v.begin(),v.end(), broj)==v.end()){
			i++;
			v.push_back(broj);
		}
	}
	
}	
int funkcija(int x, int y){
	return -2*x+y;
}
	
	

int main ()
{ int n;
try{
	std::vector<int> v1,v2,v3;
std::cout<<"Unesite broj elemenata: ";
std::cin>>n;


std::cout<<"Unesite elemente prvog vektora: ";

unos(v1,n);

std::cout<<"Unesite elemente drugog vektora: ";
unos(v2,n);
std::cout<<"Unesite elemente treceg vektora: ";
unos(v3,n);
std::cout<<std::endl;

	SortirajPodrucjeVrijednosti(v1.begin(),v1.end(),v2.begin(),v3.begin(),funkcija, faktori);
	std::cout<<"Nakon sortiranja podrucja vrijednosti imamo sljedece trojke: "<<std::endl;
	for(int i=0;i<n;i++) std::cout<<"f("<<v1[i]<<", "<<v2[i]<<") = "<<v3[i]<<std::endl;
} 	
catch(std::logic_error izuzetak){
	std::cout<<"Izuzetak: "<<izuzetak.what();
}
catch(std::bad_alloc){};
	return 0;
}
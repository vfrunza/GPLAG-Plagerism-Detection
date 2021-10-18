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
#include <type_traits>
#include <cmath>
#include <stdexcept>

bool PostojiUVektoru(std::vector<int> v, int n) {
	for(int i=0; i<v.size(); i++) if(v[i]==n) return true;
	return false;
}

template <typename tip>
bool nepostoji(tip poc, tip kraj, typename std::remove_reference<decltype(poc[0])>::type n) {
	while(poc!=kraj) {
		if(*poc==n) return false;
		poc++;
	}
	return true;
}

template <typename tip>
bool prost(tip n) {
	for(int i=2; i<=std::sqrt(n); i++)
		if(n%i==0) return false;
	return true;
}

template <typename tip1>
bool ff2(tip1 a, tip1 b) {
	int x(std::fabs(a)), y(std::fabs(b)), sumax(0), sumay(0);
	for(int i=2; i<=x; i++) {
		while(x%i==0) {
			if(prost(i)) sumax++;
			x/=i;
		}
		if(i>x || x==1) break;
	}
	for(int i=2; i<=y; i++) {
		while(y%i==0) {
			if(prost(i)) sumay++;
			y/=i;
		}
		if(i>y || y==1) break;
	}
	if(a==0 || a==1 || a==-1) sumax=1;
	if(b==0 || b==1 || b==-1) sumay=1;
	if(sumax==sumay) return a>b;
	else return sumax>sumay;
}

int f1(int x, int y) {
	return -2*x+y;
}

template <typename tip1, typename tip2, typename tip3>
void SortirajPodrucjeVrijednosti(tip1 poc1, tip1 kraj, tip2 poc2, tip3 poc3, 
typename std::remove_reference<decltype(poc3[0])>::type f(typename std::remove_reference<decltype(poc1[0])>::type, typename std::remove_reference<decltype(poc2[0])>::type), 
bool f2(typename std::remove_reference<decltype(poc1[0])>::type, typename std::remove_reference<decltype(poc2[0])>::type)) 
{
	int duz(kraj-poc1);
	typename std::remove_reference<decltype(poc3[0])>::type pom;
	std::sort(poc1, kraj, f2);
	std::sort(poc2, poc2+duz, f2);
	for(int i=0; i<duz; i++) {
		pom=f(poc1[i], poc2[i]);
		if(nepostoji(poc3, poc3+duz, pom)) throw std::logic_error ("Vrijednost koja odgovara nekom od parova nije nadjena");
		auto pok(std::find(poc3+i, poc3+duz, pom));
		std::rotate(poc3+i, pok, poc3+duz);
	}
}

int main ()
{
	int n, pom;
	std::cout<<"Unesite broj elemenata: ";
	std::cin>>n;
	try{
		std::vector<int> v1, v2, v3;
		std::cout<<"Unesite elemente prvog vektora: ";
		int br=0;
		while(br<n) {
			std::cin>>pom;
			if(PostojiUVektoru(v1, pom)) continue;
			v1.push_back(pom);
			br++;
		}
		std::cout<<"Unesite elemente drugog vektora: ";
		br=0;
		while(br<n) {
			std::cin>>pom;
			if(PostojiUVektoru(v2, pom)) continue;
			v2.push_back(pom);
			br++;
		}
		std::cout<<"Unesite elemente treceg vektora: ";
		br=0;
		while(br<n) {
			std::cin>>pom;
			if(PostojiUVektoru(v3, pom)) continue;
			v3.push_back(pom);
			br++;
		}
		std::cout<<std::endl;
		SortirajPodrucjeVrijednosti(v1.begin(), v1.end(), v2.begin(), v3.begin(), f1, ff2);
		std::cout<<"Nakon sortiranja podrucja vrijednosti imamo sljedece trojke: "<<std::endl;
		for(int i=0; i<n; i++) {
			std::cout<<"f("<<v1[i]<<", "<<v2[i]<<") = "<<v3[i]<<std::endl;
		}
	}
	catch(std::bad_alloc) {
		std::cout<<"Izuzetak: Nema dovoljno memorije!"<<std::endl;
	}
	catch(std::logic_error izuz) {
		std::cout<<"Izuzetak: "<<izuz.what()<<std::endl;
	}
	catch(...) {
		std::cout<<"Izuzetak: Neocekivan izuzetak!"<<std::endl;
	}
	return 0;
}
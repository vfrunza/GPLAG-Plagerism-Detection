/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <iomanip>
#include <cmath>

bool DaLiJeProst(int a) {
	for(int i(2); i<=std::sqrt(a); i++) 
		if(a%i==0) return false;
	return true;
}
int SumaCifara(long long int a) {
	int suma(0);
	a=std::abs(a);
	do {
		suma+=a%10;
		a/=10;
	} while (a!=0);
	return suma;
}
int BrojProstihFaktora(long long int a){
	int brojac(0);
	a=std::abs(a);
	for(int i(2); i<=a; i++) {
		if(a%i==0 && DaLiJeProst(i)) {brojac++; a/=i; i--;}
	}
	return brojac;
}
int SumaDjelilaca(long long int a){
	int suma(0);
	a=std::abs(a);
	for(int i(1); i<=a; i++) 
		if(a%i==0) suma+=i;
	return suma;
}
int BrojSavrsenihDjelilaca(long long int a){
	int brojac(0);
	a=std::abs(a);
	for(int i(2); i<=a; i++) {
		if(a%i==0) {
			int suma(0);
			for(int j(1); j<=i/2; j++)
				if(i%j==0) suma+=j;
			if(suma==i) brojac++;
		}
	}
	return brojac;
}
template <typename iter_tip1, typename iter_tip2, typename tip1, typename tip2>
auto UvrnutiPresjek(iter_tip1 pocetak1, iter_tip1 iza_kraja1, iter_tip2 pocetak2, iter_tip2 iza_kraja2, tip1 f(tip2))->std::vector<std::vector<decltype(*pocetak1+0)>> {
	std::vector<std::vector<decltype(*pocetak1+0)>> matrica(1, std::vector<decltype(*pocetak1+0)> (3));
	int k(0);
	for(auto i=pocetak1; i!=iza_kraja1; i++) {
		for(auto j=pocetak2; j!=iza_kraja2; j++) 
			if(f(*i)==f(*j)) {
				matrica[k][0]=*i;
				matrica[k][1]=*j;
				matrica[k][2]=f(*i);
				k++;
				matrica.resize(k+1);
				matrica[k].resize(3);
			}
	}
	matrica.resize(k);
	std::sort(matrica.begin(), matrica.end(), [] (const std::vector<decltype(*pocetak1+0)> &v1, const std::vector<decltype(*pocetak1+0)> &v2)->bool {
												 if(v1[2]!=v2[2]) return v1[2]<v2[2];
												 if(v1[0]!=v2[0]) return v1[0]<v2[0];
												 return v1[1]<v2[1]; });
	return matrica;											 
}
template <typename iter_tip1, typename iter_tip2>
auto UvrnutiPresjek(iter_tip1 pocetak1, iter_tip1 iza_kraja1, iter_tip2 pocetak2, iter_tip2 iza_kraja2)->std::vector<std::vector<decltype(*pocetak1+0)>> {
	std::vector<std::vector<decltype(*pocetak1+0)>> matrica(1, std::vector<decltype(*pocetak1+0)> (3,0));
	int k(0);
	for(auto i=pocetak1; i!=iza_kraja1; i++) {
		for(auto j=pocetak2; j!=iza_kraja2; j++)
			if(*i==*j) {
				matrica[k][0]=*i;
				k++;
				matrica.resize(k+1);
				matrica[k].resize(3);
			}
	}
	matrica.resize(k);
	std::sort(matrica.begin(), matrica.end(), [] (const std::vector<decltype(*pocetak1+0)> &v1, const std::vector<decltype(*pocetak1+0)> &v2) {return v1[0]<v2[0];});
	return matrica;
}
template <typename iter_tip1, typename iter_tip2, typename tip1, typename tip2>
auto UvrnutaRazlika(iter_tip1 pocetak1, iter_tip1 iza_kraja1, iter_tip2 pocetak2, iter_tip2 iza_kraja2, tip1 f(tip2))->std::vector<std::vector<decltype(*pocetak1+0)>> {
	std::vector<std::vector<decltype(*pocetak1+0)>> matrica(1, std::vector<decltype(*pocetak1+0)> (2));
	int k(0);
	for(auto i=pocetak1; i!=iza_kraja1; i++) {
		bool ulazak(false);
		for(auto j=pocetak2; j!=iza_kraja2; j++) 
			if(f(*i)==f(*j)) {ulazak=true; break;}
		if(!ulazak) {
			matrica[k][0]=*i;
			matrica[k][1]=f(*i);
			k++;
			matrica.resize(k+1);
			matrica[k].resize(2);
		}
	}
	for(auto i=pocetak2; i!=iza_kraja2; i++) {
		bool ulazak(false);
		for(auto j=pocetak1; j!=iza_kraja1; j++) 
			if(f(*i)==f(*j)) {ulazak=true; break;}
		if(!ulazak) {
			matrica[k][0]=*i;
			matrica[k][1]=f(*i);
			k++;
			matrica.resize(k+1);
			matrica[k].resize(2);
		}
	}
	matrica.resize(k);
	std::sort(matrica.begin(), matrica.end(), [] (const std::vector<decltype(*pocetak1+0)> &v1, const std::vector<decltype(*pocetak1+0)> &v2)->bool {
												 if(v1[0]!=v2[0]) return v1[0]>v2[0];
												 return v1[1]>v2[1]; });
	return matrica;
}
template <typename iter_tip1, typename iter_tip2>
auto UvrnutaRazlika(iter_tip1 pocetak1, iter_tip1 iza_kraja1, iter_tip2 pocetak2, iter_tip2 iza_kraja2)->std::vector<std::vector<decltype(*pocetak1+0)>> {
	std::vector<std::vector<decltype(*pocetak1+0)>> matrica(1, std::vector<decltype(*pocetak1+0)> (2,0));
	int k(0);
	for(auto i=pocetak1; i!=iza_kraja1; i++) {
		bool ulazak(false);
		for(auto j=pocetak2; j!=iza_kraja2; j++)
			if(*i==*j) {ulazak=true; break;}
		if(!ulazak) {
			matrica[k][0]=*i;
			k++;
			matrica.resize(k+1);
			matrica[k].resize(2);
		}
	}
	for(auto i=pocetak2; i!=iza_kraja2; i++) {
		bool ulazak(false);
		for(auto j=pocetak1; j!=iza_kraja1; j++)
			if(*i==*j) {ulazak=true; break;}
		if(!ulazak) {
			matrica[k][0]=*i;
			k++;
			matrica.resize(k+1);
			matrica[k].resize(2);
		}
	}
	matrica.resize(k);
	std::sort(matrica.begin(), matrica.end(), [] (const std::vector<decltype(*pocetak1+0)> &v1, const std::vector<decltype(*pocetak1+0)> &v2) {return v1[0]>v2[0];});
	return matrica;
}
int main ()
{
	int n,pom;
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	std::cin>>n;
	std::deque<int> d1,d2;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	for(int i(0); i<n; i++) {
		std::cin>>pom;
		bool prekid(false);
		for(int j(0); j<d1.size(); j++)
			if(pom==d1[j]) {prekid=true; i--; break;}
		if(!prekid) d1.push_back(pom);
	}
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	std::cin>>n;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	for(int i(0); i<n; i++) {
		std::cin>>pom;
		bool prekid(false);
		for(int j(0); j<d2.size(); j++)
			if(pom==d2[j]) {prekid=true; i--; break;}
		if(!prekid) d2.push_back(pom);
	}
	std::vector<std::vector<int>> m1=UvrnutiPresjek(d1.begin(), d1.end(), d2.begin(), d2.end(), SumaCifara), m2=UvrnutaRazlika(d1.begin(), d1.end(), d2.begin(), d2.end(), BrojProstihFaktora);
	std::cout<<"Uvrnuti presjek kontejnera: \n";
	for(std::vector<int> &red : m1) {
		for(int &x : red)
			std::cout<<std::setw(6)<<x<<" ";
		std::cout<<std::endl;
	}
	std::cout<<"Uvrnuta razlika kontejnera: \n";
	for(std::vector<int> &red : m2) {
		for(int &x : red) 
			std::cout<<std::setw(6)<<x<<" ";
		std::cout<<std::endl;
	}
	std::cout<<"Dovidjenja!";
	return 0;
}
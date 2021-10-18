/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <deque>
#include <type_traits>
#include <cmath>
int SumaDjelilaca(long long int x) {
	int suma(0);
	for(int i=1;i<=x;i++) {
		if(x%i==0) suma+=i;
	}
	return suma;
}
int BrojProstihFaktora(long long int x) {
	int broj_prostih(0);
	bool prost;
	for(int i=2;i<x;i++) {
		prost=true;
		for(int j=2;j<=std::sqrt(i);j++) {
			if(i%j==0) prost=false;
		}
		if(prost==true && x%i==0) {
			broj_prostih++;
		}
	}
	return broj_prostih;
}
int BrojSavrsenihDjelilaca(int x) {
	int suma;
	int broj_savrsenih(0);
	for(int i=2;i<=x;i++) {
		if(x%i==0) {
			suma=0;
			for(int j=1;j<i;j++) {
				if(i%j==0) suma+=j;
			}
			if(suma==i) broj_savrsenih++;
		}
	}
	return broj_savrsenih;
}
template <typename tip1,typename tip2,typename tip3>
std::vector<std::vector<long long int>> UvrnutiPresjek(tip1 p1,tip1 p2, tip2 p3, tip2 p4,tip3 fun){
	int n(0);
	tip1 q1=p1;
	tip2 q3=p3;
	while(q1!=p2 && q3!=p4) {
		if(fun(*q1)==fun(*q3)) {
			n++;
		}
		q1++;
		q3++;
	}
	std::vector<std::vector<long long int>> matrica(n,std::vector<long long int> (3));
	int red(0);
	while(p1!=p2 && p3!=p4) {
		if(fun(*p1)==fun(*p3)) {
			matrica[red][0]=*p1;
			matrica[red][1]=*p3;
			matrica[red][2]=fun(*p1);
			red++;
		}
		p1++;
		p3++;
	}
	return matrica;
}
template <typename tip1, typename tip2,typename tip3,typename tip4> 
auto UvrnutaRazlika(tip1 p1,tip1 p2,tip2 p3,tip2 p4,tip4 fun(tip3))->std::vector<std::vector<typename std::remove_reference<decltype(*p1+*p3)>::type>>{
	std::vector<std::vector<typename std::remove_reference<decltype(*p1+*p3)>::type>> matrica;
	return matrica;
}
int main ()
{
	int n1,n2;
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	std::cin>>n1;
	std::deque<long long int> dek1(n1);
	std::cout<<"Unesite elemente prvog kontejnera: ";
	for(int i=0;i<n1;i++) {
		long long int broj;
		std::cin>>broj;
		dek1.push_back(broj);
	}
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	std::cin>>n2;
	std::deque<long long int> dek2;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	for(int i=0;i<n2;i++) {
		long long int broj;
  		std::cin>>broj;
  		dek2.push_back(broj);
	}
	std::cout<<"Uvrnuti presjek kontejnera: ";
	auto matrica1=UvrnutiPresjek(dek1.begin(),dek1.end(),dek2.begin(),dek2.end(),SumaDjelilaca);
	for(int i=0;i<matrica1.size();i++) {
		for(int j=0;j<matrica1[i].size();j++) {
			std::cout<<matrica1[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Uvrnuta razlika kontejnera: ";
	auto matrica2=UvrnutaRazlika(dek1.begin(),dek1.end(),dek2.begin(),dek2.end(),SumaDjelilaca);
	for(int i=0;i<matrica2.size();i++) {
		for(int j=0;j<matrica2[i].size();j++) {
			std::cout<<matrica2[i][j];
		}
		std::cout<<std::endl;
	}
	std::cout<<"Dovidjenja!";
	return 0;
}
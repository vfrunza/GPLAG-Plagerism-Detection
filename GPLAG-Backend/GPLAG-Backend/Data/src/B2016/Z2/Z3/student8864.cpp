/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <cmath>
#include <iomanip>
bool Prost(int n){
	for(int i=2;i<n;i++) if(n%i==0) return false;
	return true;
}
bool Savrsen(int n){
	int suma(0);
	for(int i=1;i<n;i++){
		if(n%i==0) suma+=i;
	}
	if(suma==n) return true;
	return false;
}
int SumaDjelilaca(long long int n){
	int suma(0);
	for(int i=1;i<=abs(n);i++) if(n%i==0) suma+=i;
	return suma;
}
int SumaCifara(long long int n){
	int suma(0);
	while (n!=0){
		suma+=abs(n%10);
		n/=10;
	}
	return suma;
}
int BrojProstihFaktora(long long int n){
	int brojac(0);
	for(int i=2;i<=n;i++){
		if(n%i==0 && Prost(i)){
			brojac++;
			n/=i;
			i=1;
		}
	}
	return brojac;
}
int BrojSavrsenihDjelilaca(long long int n){
	int brojac(0);
	for(int i=2;i<=n;i++){
		if(n%i==0 && Savrsen(i)){
			brojac++;
			n/=i;
			i=1;
		}
	}
	return brojac;
}
template <typename itip1,typename itip2>
auto UvrnutiPresjek(itip1 p1,itip1 p2,itip2 p3,itip2 p4)->std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>{
	std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type >> matrica;
	itip1 temp;
	while(p1!=p2){
		temp=p3;
		while(temp!=p4){
			if(*p1==*temp){
				matrica.resize(matrica.size()+1);
				matrica[matrica.size()-1].push_back(*p1);
				matrica[matrica.size()-1].push_back(0);
				matrica[matrica.size()-1].push_back(0);
				temp=p4-1;
			}
			temp++;
		}
		p1++;
	}
	return matrica;
}
template <typename itip1,typename itip2,typename ptip1,typename ptip2>
auto UvrnutiPresjek (itip1 p1,itip1 p2, itip2 p3, itip2 p4, ptip1 funkcija(ptip2))->std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>{
	std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type >> matrica;
	while(p1!=p2){
		auto pom1(p3);
		while(pom1!=p4){
			if(funkcija(*p1)==funkcija(*pom1)){
				matrica.resize(matrica.size()+1);
				matrica[matrica.size()-1].push_back(*p1);
				matrica[matrica.size()-1].push_back(*pom1);
				matrica[matrica.size()-1].push_back(funkcija(*p1));
			}
			pom1++;
		}
		p1++;
	}
	std::sort(matrica.begin(),matrica.end(),[](std::vector<typename std::remove_reference<decltype(*p1)>::type> a,std::vector<typename std::remove_reference<decltype(*p1)>::type> b){if(a[2]<b[2]) return true;
	else if(a[2]>b[2]) return false;
	else if(a[0]<b[0]) return true;
	else if(a[0]>b[0]) return false;
	else if(a[1]<b[1]) return true;
	else if(a[1]>b[1]) return false;
	return true;});
	return matrica;
}
template<typename itip1,typename itip2>
auto UvrnutaRazlika (itip1 p1,itip1 p2, itip2 p3,itip2 p4)->std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>{
	std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> matrica;
	auto pom1(p1);
	bool ubaci;
	while(pom1!=p2){
		ubaci=true;
		auto pom3(p3);
		while(pom3!=p4){
			if(*pom1==*pom3) ubaci=false;
			pom3++;
		}
		if(ubaci){
			matrica.resize(matrica.size()+1);
			matrica[matrica.size()-1].push_back(*pom1);
			matrica[matrica.size()-1].push_back(0);
		}
		pom1++;
	}
	while(p3!=p4){
		pom1=p1;
		ubaci=true;
		while(pom1!=p2){
			if(*pom1==*p3) ubaci=false;
			pom1++;
		}
		if(ubaci){
			matrica.resize(matrica.size()+1);
			matrica[matrica.size()-1].push_back(*p3);
			matrica[matrica.size()-1].push_back(0);
		}
		p3++;
	}
	std::sort(matrica.begin(),matrica.end(),[](std::vector<typename std::remove_reference<decltype(*p1)>::type>a,std::vector<typename std::remove_reference<decltype(*p1)>::type>b){
		if(a[0]>b[0]) return true;
		return false;
	});
	return matrica;
}
template <typename itip1,typename itip2,typename ptip1,typename ptip2>
auto UvrnutaRazlika (itip1 p1,itip2 p2,itip2 p3,itip2 p4,ptip1 funkcija(ptip2))->std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>{
	std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> matrica;
	auto pom1(p1);
	bool ubaci;
	while(pom1!=p2){
		ubaci=true;
		auto pom3(p3);
		while(pom3!=p4){
			if(funkcija(*pom1)==funkcija(*pom3)) ubaci=false;
			pom3++;
		}
		if(ubaci){
			matrica.resize(matrica.size()+1);
			matrica[matrica.size()-1].push_back(*pom1);
			matrica[matrica.size()-1].push_back(funkcija(*pom1));
		}
		pom1++;
	}
	while(p3!=p4){
		ubaci=true;
		pom1=p1;
		while(pom1!=p2){
			if(funkcija(*p3)==funkcija(*pom1)) ubaci=false;
			pom1++;
		}
		if(ubaci){
			matrica.resize(matrica.size()+1);
			matrica[matrica.size()-1].push_back(*p3);
			matrica[matrica.size()-1].push_back(funkcija(*p3));
		}
		p3++;
	}
	std::sort(matrica.begin(),matrica.end(),[](std::vector<typename std::remove_reference<decltype(*p1)>::type> a,std::vector<typename std::remove_reference<decltype(*p1)>::type> b){
		if (a[0]>b[0]) return true;
		if (a[0]<b[0]) return false;
		if(a[1]>b[1]) return true;
		return false;
	});
	return matrica;
}
int main (){
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	int s1,s2;
	std::cin>>s1;
	if(s1<0){
		std::cout<<"broj elemenata ne moze biti negativan!";
		return 0;
	}	
	std::cout<<"Unesite elemente prvog kontejnera: ";
	std::deque<int> d1;
	int temp;
	bool ubaci;
	for(int i=0;i<s1;i++){
		ubaci=true;
		std::cin>>temp;
		for(int j=0;j<d1.size();j++){
			if (temp==d1[j]) ubaci=false;
		}
		if(ubaci) d1.push_back(temp);
		else i--;
	}
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	std::cin>>s2;
	if(s2<0){
		std::cout<<"Broj elemenata ne moze biti negativan!";
		return 0;
	}
	std::deque<int> d2;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	for(int i=0;i<s2;i++){
		ubaci=true;
		std::cin>>temp;
		for(int j=0;j<d2.size();j++){
			if(temp==d2[j]) ubaci=false;
		}
		if(ubaci) d2.push_back(temp);
		else i--;
	}
	std::cout<<"Uvrnuti presjek kontejnera:\n";
	auto a(UvrnutiPresjek(d1.begin(),d1.end(),d2.begin(),d2.end(),SumaCifara));
	for(int i=0;i<a.size();i++){
		for(int j=0;j<3;j++){
			std::cout<<std::setw(6)<<a[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Uvrnuta razlika kontejnera:\n";
	auto b(UvrnutaRazlika(d1.begin(),d1.end(),d2.begin(),d2.end(),BrojProstihFaktora));
	for(int i=0;i<b.size();i++){
		for(int j=0;j<2;j++){
			std::cout<<std::setw(6)<<b[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Dovidjenja!";
	return 0;
}
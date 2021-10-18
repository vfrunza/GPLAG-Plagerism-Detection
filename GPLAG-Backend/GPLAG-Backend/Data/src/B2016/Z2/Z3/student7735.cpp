#include <iostream>
#include <vector> 
#include <stdexcept>
#include <deque>
#include <limits>
#include <iomanip>
#include <cmath>
#include <string>
#include<type_traits>
#include <algorithm>
#include <iterator>

template <typename Tip1, typename Tip2, typename Tip3,typename Tip4>
auto UvrnutiPresjek(Tip1 pocetak1,Tip1 iza_kraja1,Tip2 pocetak2,Tip2 iza_kraja2,Tip4 f(Tip3)) -> std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>>{
	std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>> mat;
	int i=0;
	Tip2 pocetak22;
	while(pocetak1!=iza_kraja1){
			pocetak22=pocetak2;
		while(pocetak22!=iza_kraja2){
			if(f(*pocetak1)==f(*pocetak22)){
				 mat.resize(mat.size()+1);
				 mat[i].push_back(*pocetak1);
				 mat[i].push_back(*pocetak22);
				 mat[i].push_back(f(*pocetak1));
				 i++;
			}
			pocetak22++;
		}
	pocetak1++;
	}
	std::sort(mat.begin(),mat.end(),[](std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>a,
			std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>b){
				if(a[2]<b[2])return  true;
				else if(a[2]>b[2])return false;
				else if(a[2]==b[2] && a[0]<b[0])return true;
				else if(a[2]==b[2] && a[0]>b[0])return false;
				else if(a[1]<b[1])return true;
				else if(a[1]>b[1])return false;
				else if(a[0]<b[0])return true;
				else return false;});
return mat;
}

template <typename Tip1, typename Tip2>
auto UvrnutiPresjek(Tip1 pocetak1,Tip1 iza_kraja1,Tip2 pocetak2,Tip2 iza_kraja2) -> std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>>{
	std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>> mat;
	int i=0;
	Tip2 pocetak22;
	while(pocetak1!=iza_kraja1){
			pocetak22=pocetak2;
		while(pocetak22!=iza_kraja2){
			if(*pocetak1==*pocetak22){
				 mat.resize(mat.size()+1);
				 mat[i].push_back(*pocetak1);
				 mat[i].push_back(0);
				 mat[i].push_back(0);
				 i++;
			}
			pocetak22++;
		}
	pocetak1++;
	}
	std::sort(mat.begin(),mat.end());
return mat;
}

template <typename Tip1, typename Tip2, typename Tip3,typename Tip4>
auto UvrnutaRazlika(Tip1 pocetak1,Tip1 iza_kraja1,Tip2 pocetak2,Tip2 iza_kraja2,Tip4 f(Tip3)) -> std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>>{
	std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>> mat;
	int br=0;
	Tip1 kopija1=pocetak1;
	Tip2 kopija=pocetak2;
	int i(0);
	while(pocetak1!=iza_kraja1){
		pocetak2=kopija;
		br=0;
		while(pocetak2!=iza_kraja2){
			if(f(*pocetak1)==f(*pocetak2)){br++;
				}
		pocetak2++;
	}
	if(br==0){
		mat.resize(mat.size()+1);
		mat[i].push_back(*pocetak1);
		mat[i].push_back(f(*pocetak1));
		i++;
		}
	pocetak1++;
	}
	pocetak2=kopija;
	while(pocetak2!=iza_kraja2){
		pocetak1=kopija1;
		br=0;
		while(pocetak1!=iza_kraja1){
			if(f(*pocetak2)==f(*pocetak1))br++;
			pocetak1++;
		}
		if(br==0){
			mat.resize(mat.size()+1);
			mat[i].push_back(*pocetak2);
			mat[i].push_back(f(*pocetak2));
			i++;
		}
		pocetak2++;
	}
	
	std::sort(mat.begin(),mat.end(),[](std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>a,
			std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>b){
				if(a[0]>b[0]) return true;
				else if(a[0]<b[0]) return false;
				else if(a[1]>b[1]) return true;
				else return false;
				
			});
return mat;
}

template <typename Tip1, typename Tip2>
auto UvrnutaRazlika(Tip1 pocetak1,Tip1 iza_kraja1,Tip2 pocetak2,Tip2 iza_kraja2) -> std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>>{
	std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>> mat;
	int br=0;
	Tip1 kopija1=pocetak1;
	Tip2 kopija=pocetak2;
	int i(0);
	while(pocetak1!=iza_kraja1){
		pocetak2=kopija;
		br=0;
		while(pocetak2!=iza_kraja2){
			if(*pocetak1==*pocetak2){br++;
				}
		pocetak2++;
	}
	if(br==0){
		mat.resize(mat.size()+1);
		mat[i].push_back(*pocetak1);
		mat[i].push_back(0);
		i++;
		}
	pocetak1++;
	}
	pocetak2=kopija;
	while(pocetak2!=iza_kraja2){
		pocetak1=kopija1;
		br=0;
		while(pocetak1!=iza_kraja1){
			if(*pocetak2==*pocetak1)br++;
			pocetak1++;
		}
		if(br==0){
			mat.resize(mat.size()+1);
			mat[i].push_back(*pocetak2);
			mat[i].push_back(0);
			i++;
		}
		pocetak2++;
	}
	
	std::sort(mat.begin(),mat.end(),[](std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>a,
			std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>b){
				return a[0]>b[0];
			});
return mat;
}
	
int SumaCifara(long long int t){
	int suma=0;
	int d;
	while(t!=0){
		d=t%10;
		suma=suma+d;
		t=t/10;
	}
	return suma;
}
bool DaLijeprost(long long int broj){
	for(int i=2;i<=std::sqrt(broj);i++){
		if(broj%i==0) return false;
	}
	return true;
}
int BrojProstihFaktora(long long int n){
	int brojac=0;
	int k=n%2;
	if(k==0){
	while(k==0){
		brojac++;
		n=n/2;
		k=n%2;
	}}
	for(int i=3;i<=n;i++){
		int m=n%i;
		if(m==0){
		while(m==0){
			brojac++;
			n=n/i;
			m=n%i;
		}
		while(DaLijeprost(i)==false && i<n)i++;
	i--;
		}
	}
	return brojac;
}
int DaLiJeSavrsen(long long int n){
	int s=0;
	for(int i=1;i<n;i++){
		if(n%i==0)s=s+i;
	}
	if(n==s)return true;
	return false;
}
int BrojSavrsenihDjelilaca(long long int n){
	int br=0;
	for(int i=1;i<=n;i++){
		if(n%i==0){
			if (DaLiJeSavrsen(i))br++;
		}
	}
	return br;
}
int SumaDjelilaca(long long int n){
	int suma=0;
	if(n<0)(n=abs(n));
	for(int i=1;i<=n;i++){
		if(n%i==0)suma=suma+i;
	}
	return suma;
}

int main ()
{
	int n,m;
	int broj;
	std::deque<int> v{};
	std::deque<int> f{};
	std::cout << "Unesite broj elemenata prvog kontejnera: ";
	std::cin >> n;
	std::cout << "Unesite elemente prvog kontejnera: ";
	int indeks;
	for(int i=0;i<n;i++){
		std::cin >> broj;
		indeks=i;
		auto it=v.begin();
		while(it!=v.end()){
			if (broj==*it){
				i--;
				break;
			}
				it++;
		}
	if(indeks==i)v.push_back(broj);
	}
	std::cout << "Unesite broj elemenata drugog kontejnera: ";
	std::cin >> m;
	std::cout << "Unesite elemente drugog kontejnera: " ;
	int indeks1;
	for(int i=0;i<m;i++){
		std::cin >> broj;
		indeks1=i;
		auto it1=f.begin();
		while(it1!=f.end()){
			if(broj==*it1){
				i--;
				break;}
			it1++;
		}
	if(indeks1==i)f.push_back(broj);
	}
	std::vector<std::vector<int>> mat;
	std::cout << "Uvrnuti presjek kontejnera: " << std::endl;
	mat=UvrnutiPresjek(v.begin(),v.end(),f.begin(),f.end(),SumaCifara);
	for(int i=0;i<mat.size();i++){
		for(int j=0;j<mat[0].size();j++){
			std::cout <<std::setw(6)<< mat[i][j]<<" ";
		}
		
		std::cout << std::endl;
	}
	mat.resize(0);
	mat=UvrnutaRazlika(v.begin(),v.end(),f.begin(),f.end(),BrojProstihFaktora);
	std::cout << "Uvrnuta razlika kontejnera:" << std::endl;
	for(int i=0;i<mat.size();i++){
		for(int j=0;j<mat[0].size();j++){
			std::cout <<std::setw(6)<< mat[i][j] <<" ";
		}
		std::cout<< std::endl;
	}
	std::cout << "Dovidjenja!";
	return 0;
}


#include <iostream>
#include <stdexcept>
#include <new>
#include <cmath>
#include <limits>
#include <deque>
#include <vector>
#include <algorithm>
#include <type_traits>
#include <iomanip>

int SumaDjelilaca(long long int n){
	int brojac=0;
	for(int i=1; i<=std::abs(n); i++){
		if(n%i==0)
			brojac+=i;
	}
	return brojac;
}
bool DaLiJeProst(int a){
	if (a<=1) return false;
	for(int i=2; i<=std::sqrt(a); i++){
		if(a%i==0) return false;
	}
	return true;
}
int BrojProstihFaktora(long long int n){
	int brojac=0;
	for(int i=2; i<=std::abs(n); i++){
		if(DaLiJeProst(i))
		    while(n%i==0){
				brojac++;
				n/=i;
		}
	}
	return brojac;
}
int BrojSavrsenihDjelilaca(long long int n){
	if(n<0) n=-n;
	int brojac=0;
	int suma=0;
	for(int i=1; i<=n; i++){
		if(n%i==0){
			for(int j=1; j<i;j++){
				if(i%j==0)
					suma+=j;
			}
			if(suma==i)
			 	brojac++;
		}
		suma=0;
	}
	return brojac;
}
int beze (int n){
	int b=0;
	while(n!=0){
		b+=n%10;
		n/=10;
	}
	return b;
}
template <typename Tip1,typename Tip2,typename Tip3,typename Tip4>
	auto UvrnutiPresjek(Tip1 a, Tip1 b, Tip2 p, Tip2 q, Tip3 f(Tip4)) -> typename std::vector<std::vector<typename std::remove_reference<decltype(*p)>::type>>{
		typename std::vector<std::vector<typename std::remove_reference<decltype(*p)>::type>> matrica;
		bool nema_para(true);
		int n=0;
		Tip2 temp;
		while(a!=b){
			temp=p;
			while(temp!=q){
				if(f(*a)==f(*temp)){
					for(int i=0; i<matrica.size(); i++){
						if(matrica[i][0]==*a && matrica[i][1]==*temp){
							nema_para=false;
							break;
						}
					}
					if(nema_para){
						matrica.push_back(std::vector<typename std::remove_reference<decltype(*p)>::type>(3));
						matrica[n][0]=*a;
						matrica[n][1]=*temp;
						matrica[n][2]=f(*a);
						n++;
					}
					nema_para=true;
				}
				temp++;	
			}
			a++;
		}
		std::sort(matrica.begin(), matrica.end(), [](std::vector<typename std::remove_reference<decltype(*p)>::type> a, std::vector<typename std::remove_reference<decltype(*p)>::type> b)->bool{
			if(a[2]==b[2])
			{
				if(a[0]==b[0])
					return a[1]<b[1];
				return	a[0]<b[0];
			}		
			return	a[2]<b[2];
			});
		return matrica;	
	}
template <typename Tip1,typename Tip2>
	auto UvrnutiPresjek(Tip1 a, Tip1 b, Tip2 p, Tip2 q) -> typename std::vector<std::vector<typename std::remove_reference<decltype(*p)>::type>>{
		typename std::vector<std::vector<typename std::remove_reference<decltype(*p)>::type>> matrica;
		bool nema_para(true);
		Tip2 temp;
		int n=0;
		while(a!=b){
			temp=p;
			while(temp!=q){
				if(*a==*temp){
					for(int i=0; i<matrica.size(); i++){
						if(matrica[i][0]==*a){
							nema_para=false;
							break;
						}
					}
					if(nema_para){
						matrica.push_back(std::vector<typename std::remove_reference<decltype(*p)>::type>(3));
						matrica[n][0]=*a;
						matrica[n][1]=0;
						matrica[n][2]=0;
						n++;
					}
					nema_para=true;
				}
				temp++;	
			}
			a++;
		}
		std::sort(matrica.begin(), matrica.end(), [](std::vector<typename std::remove_reference<decltype(*p)>::type> a, std::vector<typename std::remove_reference<decltype(*p)>::type> b)->bool{
			return a[0]<b[0];});
		return matrica;
	}
template <typename Tip1,typename Tip2,typename Tip3,typename Tip4>
	auto UvrnutaRazlika(Tip1 a, Tip1 b, Tip2 p, Tip2 q, Tip3 f(Tip4)) -> typename std::vector<std::vector<typename std::remove_reference<decltype(*p)>::type>>{
		typename std::vector<std::vector<typename std::remove_reference<decltype(*p)>::type>> matrica;
		int n=0;
		int br=0;
		Tip1 temp1=a;
		Tip2 temp2;
		while(temp1!=b){
			temp2=p;
			while (temp2!=q) {
				if(f(*temp1)==f(*temp2))
					br++;
				temp2++;
			}
			if(br==0){
				matrica.push_back(std::vector<typename std::remove_reference<decltype(*p)>::type>(2));
				matrica[n][0]=*temp1;
				matrica[n][1]=f(*temp1);
				n++;
			}
			br=0;
			temp1++;
		}
		br=0;
		while(p!=q){
			temp2=a;
			while (temp2!=b) {
				if(f(*p)==f(*temp2))
					br++;
				temp2++;
			}
			if(br==0){
				matrica.push_back(std::vector<typename std::remove_reference<decltype(*p)>::type>(2));
				matrica[n][0]=*p;
				matrica[n][1]=f(*p);
				n++;
			}
			br=0;
			p++;
		}
		std::sort(matrica.begin(), matrica.end(), [](std::vector<typename std::remove_reference<decltype(*p)>::type> a, std::vector<typename std::remove_reference<decltype(*p)>::type> b)->bool{
			if( a[0]==b[0])
				if(a[1]==a[1])
					return a[1]>b[1];
			return a[0]>b[0]; 		
			
		});
		
		return matrica;
	}
template<typename Tip1, typename Tip2>
	auto UvrnutaRazlika(Tip1 a, Tip1 b, Tip2 p, Tip2 q) ->typename std::vector<std::vector<typename std::remove_reference<decltype(*p)>::type>>{
		typename std::vector<std::vector<typename std::remove_reference<decltype(*p)>::type>> matrica;
		int n=0;
		int br=0;
		Tip1 temp1 =a;
		Tip2 temp2;
		while (temp1!=b) {
			temp2=p;
			while (temp2!=q) {
				if(*temp1==*temp2)
					br++;
				temp2++;	
			}
			if(br==0){
				matrica.push_back(std::vector<typename std::remove_reference<decltype(*p)>::type>(2));
				matrica[n][0]=*temp1;
				matrica[n][1]=0;
				n++;
				
			}
			br=0;
			temp1++;
		}
		br=0;
		while(p!=q){
			temp2=a;
			while (temp2!=b) {
				if(*p==*temp2)
					br++;
				temp2++;
			}
			if(br==0){
				matrica.push_back(std::vector<typename std::remove_reference<decltype(*p)>::type>(2));
				matrica[n][0]=*p;
				matrica[n][1]=0;
				n++;
			}
			br=0;
			p++;
		}
		std::sort(matrica.begin(), matrica.end(), [](std::vector<typename std::remove_reference<decltype(*p)>::type> a, std::vector<typename std::remove_reference<decltype(*p)>::type> b){return a>b;});
		return matrica;
		
	}
int main (){
	std::cout << "Unesite broj elemenata prvog kontejnera: ";
	int n,pomocni; bool ima_vec(false);
	std::cin >> n;
	std::deque<int>d1(n);
	std::cout << "Unesite elemente prvog kontejnera: ";
	for(int i=0;i<n;i++){
		std::cin >> pomocni;
		for(int k=0; k<i;k++)
			if(pomocni==d1[k]){
				ima_vec=true;
				break;
			}
		if(ima_vec){
			i--;
			ima_vec=false;
			continue;
		}
		d1[i]=pomocni;
	}
	
	std::cout << "Unesite broj elemenata drugog kontejnera: ";
	std::cin >> n;
	std::deque<int>d2(n);
	std::cout << "Unesite elemente drugog kontejnera: ";
	for(int i=0;i<n;i++){
		std::cin >> pomocni;
		for(int k=0; k<i;k++)
			if(pomocni==d2[k]){
				ima_vec=true;
				break;
			}
		if(ima_vec){
			i--;
			ima_vec=false;
			continue;
		}
		d2[i]=pomocni;
	}
	
	std::cout <<"Uvrnuti presjek kontejnera:" << std::endl;
	std::vector<std::vector<int>> mat=UvrnutiPresjek(d1.begin(),d1.end(),d2.begin(),d2.end(),beze);
	for(int i=0; i<mat.size(); i++){
		for(int j= 0; j<mat[i].size(); j++){
			std::cout.width(6);
			std::cout<< mat[i][j]<<" ";}
		std::cout<< std::endl;	
	}
	
	std::cout << "Uvrnuta razlika kontejnera:" << std::endl;
	mat=UvrnutaRazlika(d1.begin(),d1.end(),d2.begin(),d2.end(),BrojProstihFaktora);
	for(int i=0; i<mat.size(); i++){
		for(int j= 0; j<mat[i].size(); j++){
			std::cout.width(6);
			std::cout<< mat[i][j]<<" ";}
		std::cout << std::endl;	
	}
	std::cout << "Dovidjenja!";
	return 0;
}

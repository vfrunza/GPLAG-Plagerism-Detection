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

bool DaLiJeProst(long long int x){
	if(x<0) x=-x;
	if(x==1) return false;
	if(x==2) return true;
	for(int i=2; i<sqrt(x); i++){
		if(x%i==0) return false;
	}
	return true;
}
int SumaDjelilaca(long long int x); 
bool DaLiJeSavrsen(long long int x){
	if(x<0) x=-x;
	if(x==(SumaDjelilaca(x)-x))return true;
	return false;
}

int SumaDjelilaca(long long int x){
	if(x<0) x=-x;
	int suma(0);
	for(int i=1; i<=x; i++){
		if(x%i==0) suma+=i;
	}
	return suma;
}

int BrojProstihFaktora(long long int x){
	if(x<0) x=-x;
	int broj(0);
	if(x==1) return 1;
	for(int i=2; i<=x; i++){
		if(x%i==0){
			if(DaLiJeProst(i)) broj++;
			x/=i;
			i=1;
		}
	}
	return broj;
}

int BrojSavrsenihDjelilaca(long long int x){
	if(x<0) x=-x;
	if(x==1) return 0;
	int broj(0);
	for(int i=1; i<=x; i++){
		if(x%i==0){
			if(DaLiJeSavrsen(i)) broj++;
		}
	}
	return broj;
	
}

int SumaCifara(long long int x){
	if(x<0) x=-x;
	int suma(0);
	if(x<10) return x;
	while(x!=0){
		suma+=x%10;
		x/=10;
	}
	return suma;
}
template <typename tip>
tip fun (tip x){
		return x;
	}
	
template <typename NekiTip1, typename NekiTip2, typename tip, typename tipu>
auto UvrnutiPresjek(NekiTip1 pocetak1, NekiTip1 iza_kraja1, NekiTip2 pocetak2, NekiTip2 iza_kraja2, tip f(tipu))->std::vector<std::vector<decltype(*pocetak2+*pocetak2)>>{
		int vel(0);
		NekiTip1 poc1(pocetak1);
		NekiTip2 poc2(pocetak2);
		while(poc1 != iza_kraja1){
			poc2=pocetak2;
			while(poc2 != iza_kraja2){
				if(f(*poc1)==f(*poc2)) vel++;
				poc2++;
			}
			poc1++;
		}
		std::vector<std::vector<decltype(*pocetak2+*pocetak2)>> matrica(vel, std::vector<decltype(*pocetak2+*pocetak2)>(3,0));
		poc1=pocetak1;
		poc2=pocetak2;
		int i(0);
		while(poc1 != iza_kraja1 && i<vel){
			poc2=pocetak2;
			while(poc2 != iza_kraja2){
				if(f(*poc1)==f(*poc2)) {
					matrica[i][0]=*poc1;
					matrica[i][1]=*poc2;
					matrica[i][2]=f(*poc1);
					i++;
				}
				poc2++;
			}
			poc1++;
		}
		std::sort(matrica.begin(), matrica.end(), [] (std::vector<decltype(*pocetak2+*pocetak2)> v1, std::vector<decltype(*pocetak2+*pocetak2)> v2)->bool{
			if(v1[2]<v2[2]) return true;
			else if(v1[2]>v2[2]) return false;
			else{
				if(v1[0]<v2[0]) return true;
				else if(v1[0]>v2[0]) return false;
				else{
					if(v1[1]<v2[1]) return true;
					return false;
				}
			}
		});
		
		return matrica;
	}
	
template <typename NekiTip1, typename NekiTip2>
	auto UvrnutiPresjek(NekiTip1 pocetak1, NekiTip1 iza_kraja1, NekiTip2 pocetak2, NekiTip2 iza_kraja2)->std::vector<std::vector<decltype(*pocetak2+*pocetak2)>>{
		std::vector<std::vector<decltype(*pocetak2+*pocetak2)>> matrica(UvrnutiPresjek(pocetak1, iza_kraja1, pocetak2, iza_kraja2, fun<decltype(*pocetak1+*pocetak1)>));
		for(int i=0; i<matrica.size(); i++){
			matrica[i][1]=0;
			matrica[i][2]=0;
		}
		return matrica;
	}

template <typename NekiTip1, typename NekiTip2, typename tip, typename tipu>
auto UvrnutaRazlika(NekiTip1 pocetak1, NekiTip1 iza_kraja1, NekiTip2 pocetak2, NekiTip2 iza_kraja2, tip f(tipu)) -> std::vector<std::vector<decltype(*pocetak2+*pocetak2)>>{
	NekiTip1 poc1(pocetak1);
	NekiTip2 poc2(pocetak2);
	std::vector<std::vector<decltype(*pocetak2+*pocetak2)>> m1;
    m1=UvrnutiPresjek(pocetak1, iza_kraja1, pocetak2, iza_kraja2, f);
	std::vector<std::vector<decltype(*pocetak2+*pocetak2)>> m(0);
	bool istina(false);
	int j(0);
	while(poc1!=iza_kraja1){
		istina=false;
		for(int i=0; i<m1.size(); i++){
			if(*poc1==m1[i][0]) istina=true;
		}
		if(!istina){
			m.resize(j+1);
			m[j].push_back(*poc1);
			m[j].push_back(f(*poc1));
			j++;
		}
		poc1++;
	}
	while(poc2!=iza_kraja2){
		istina=false;
		for(int i=0; i<m1.size(); i++){
			if(*poc2==m1[i][1]) istina=true;
		}
		if(!istina){
			m.resize(j+1);
			m[j].push_back(*poc2);
			m[j].push_back(f(*poc2));
			j++;
		}
		poc2++;
	}
	std::sort(m.begin(), m.end(), [](std::vector<decltype(*pocetak2+*pocetak2)> v1, std::vector<decltype(*pocetak2+*pocetak2)> v2) -> bool{
		if(v1[0]>v2[0]) return true;
		else if(v1[0]<v2[0]) return false;
		else{
			if(v1[1]>v2[1]) return true;
		}
		return false;
	});
	
	return m;
}

template <typename NekiTip1, typename NekiTip2>
auto UvrnutaRazlika(NekiTip1 pocetak1, NekiTip1 iza_kraja1, NekiTip2 pocetak2, NekiTip2 iza_kraja2)->std::vector<std::vector<decltype(*pocetak1+*pocetak1)>>{
	std::vector<std::vector<decltype(*pocetak1+*pocetak1)>> m(UvrnutaRazlika(pocetak1, iza_kraja1, pocetak2, iza_kraja2, fun<decltype(*pocetak1+*pocetak1)>));
	for(int i=0; i<m.size(); i++) m[i][1]=0;
	return m;
}
	

int main ()
{
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	int n1;
	std::cin>>n1;
	std::deque<int> dek1(n1);
	std::cout<<"Unesite elemente prvog kontejnera: ";
	bool istina(false);
	for(int i=0; i<n1; i++){
		istina=false;
		int a; 
		std::cin>>a;
		for(int j=0; j<i; j++) {
			if(a==dek1[j]){
				istina=true;
				break;
			}
		}
		if(istina){
			i--;
			continue;
		}
		dek1[i]=a;
	}
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	int n2;
	std::cin>>n2;
	std::deque<int> dek2(n2);
	std::cout<<"Unesite elemente drugog kontejnera: ";
	for(int i=0; i<n2; i++){
		istina=false;
		int a;
		std::cin>>a;
		for(int j=0; j<i; j++){
			if(a==dek2[j]){
				istina=true;
			}
		}
		if(istina){
			i--;
			continue;
		}
		dek2[i]=a;
	}
	/*for(int x:dek1) std::cout<<x<<" ";
	std::cout<<std::endl;
	for(int x:dek2) std::cout<<x<<" ";
	std::cout<<std::endl;*/
	std::cout<<"Uvrnuti presjek kontejnera: "<<std::endl;
	std::vector<std::vector<int>> matrica(UvrnutiPresjek(dek1.begin(), dek1.end(), dek2.begin(), dek2.end(), SumaCifara));
	for(auto x: matrica){
		for(auto y:x){
			std::cout<<std::right<<std::setw(6)<<y<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Uvrnuta razlika kontejnera: "<<std::endl;
	std::vector<std::vector<int>> m2(UvrnutaRazlika(dek1.begin(), dek1.end(), dek2.begin(), dek2.end(), BrojProstihFaktora));
	for(auto x : m2){
		for(auto y : x){
			std::cout<<std::right<<std::setw(6)<<y<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Dovidjenja!";
	return 0;
}
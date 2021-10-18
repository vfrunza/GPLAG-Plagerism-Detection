/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <deque>
#include <type_traits>
#include <stdexcept>
#include <algorithm>
#include <iomanip>

int t(int x){ //Ne treba mi ovo
	return x*x;
}
int SumaCifara(int n){
	n=std::abs(n);
	int p{0};
	while(n!=0){
		p+=n%10;
		n/=10;
	}
	return p;
}
int SumaDjelilaca(long long int n){
	int suma{0};
	for(int i=1; i<=n; i++)
		if(n%i==0)
			suma+=i;
	return suma;
}
bool Prost(int n){
	if(n<=1)
		return false;
	for(int i=2; i<n; i++)
		if(n%i==0)
			return false;
	return true;
}
int BrojProstihFaktora(long long int n){
	int suma{0};
	for(int i=1; i<=n; i++)
		if(Prost(i) && n%i==0){
			suma++; n/=i;i=1;}
	return suma;
}
template<typename tip>
	std::vector<int> Pretvori(tip p, tip k){
		std::vector<int> v;
		while(p!=k)
			v.push_back(*p++);
		return v;
	}

template <typename tip1, typename tip2, typename tip3>
	std::vector<std::vector<int>> UvrnutiPresjek(tip1 pocetak1, tip1 kraj1, tip2 pocetak2, tip2 kraj2, tip3 f=t){
		std::vector<int> v1=Pretvori(pocetak1,kraj1);
		std::vector<int> v2=Pretvori(pocetak2,kraj2);
		std::vector<std::vector<int>> a;
		if(f==t){
			for(int i=0; i<v1.size(); i++)
				for(int j=0; j<v2.size(); j++)
					if(v1[i]==v2[j]){
						std::vector<int> v;
						v.push_back(v1[i]);
						v.push_back(v2[j]);
						v.push_back(0);
						a.push_back(v);
					}
		}
		else{
			for(int i=0; i<v1.size(); i++)
				for(int j=0; j<v2.size(); j++)
					if(f(v1[i])==f(v2[j])){
						std::vector<int> v;
						v.push_back(v1[i]);
						v.push_back(v2[j]);
						v.push_back(f(v1[i]));
						a.push_back(v);
					}
		}
		std::sort(a.begin(),a.end(),[](std::vector<int> x, std::vector<int> y)->bool{if(x[2]!=y[2])return x[2]<y[2];if(x[0]!=y[0])return x[0]<y[0];return x[1]<y[1];});
		
		return a;
	}
template <typename o>
	bool Ima(o p, int n){
		for(int i=0; i<p.size(); i++)
			if(n==p[i])
				return true;
		return false;
	}

template <typename tip1, typename tip2, typename tip3>
	std::vector<std::vector<int>> UvrnutaRazlika(tip1 pocetak1, tip1 kraj1, tip2 pocetak2, tip2 kraj2, tip3 f=t){
		std::vector<int> v1=Pretvori(pocetak1,kraj1);
		std::vector<int> v2=Pretvori(pocetak2,kraj2);
		std::vector<std::vector<int>> a;
		for(int i=0; i<v1.size(); i++){
			bool prekidac{true};
			for(int j=0; j<v2.size(); j++)
				if(f(v1[i])==f(v2[j]))
					prekidac=false;
			if(prekidac){
				std::vector<int> t;
				t.push_back(v1[i]);
				t.push_back(f(v1[i]));
				a.push_back(t);
			}
		}
		for(int i=0; i<v2.size(); i++){
			bool prekidac{true};
			for(int j=0; j<v1.size(); j++)
				if(f(v2[i])==f(v1[j]))
					prekidac=false;
			if(prekidac){
				std::vector<int> t;
				t.push_back(v2[i]);
				t.push_back(f(v2[i]));
				a.push_back(t);
			}
		}
		std::sort(a.begin(),a.end(),[](std::vector<int> x, std::vector<int> y)->bool{if(x[0]!=y[0])return x[0]>y[0];return x[1]>y[1];});
				
		
		return a;
	}

bool SavrsenBroj(int n){
	int suma{0};
	for(int i=1; i<n; i++)
		if(n%i==0)
			suma+=i;
	if(suma==n)
		return true;
	return false;
}

int BrojSavrsenihDjelilaca(long long int n){
	int brojac{0};
	for(int i=1; i<n; i++)
		if(SavrsenBroj(i) && n%i==0)
			brojac++;
	return brojac;
}


int main ()
{
	int n,m;
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	std::cin>>n;
	std::vector<int> a;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	for(int i=0; i<n; i++){
		std::cin>>m;
		if(Ima(a,m)){
			i--;continue;
		}
		a.push_back(m);
	}
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	std::cin>>n;
	std::deque<int> b;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	for(int i=0; i<n; i++){
		std::cin>>m;
		if(Ima(b,m)){
			i--;continue;
		}
		b.push_back(m);
	}
	std::cout<<"Uvrnuti presjek kontejnera:\n";
	std::vector<std::vector<int>> r=UvrnutiPresjek(a.begin(), a.end(), b.begin(), b.end(),SumaCifara);
	for(int i=0; i<r.size(); i++){
		for(int j=0; j<r[i].size(); j++)
			std::cout<<std::setw(6)<<r[i][j];
		std::cout<<"\n";}
	r=UvrnutaRazlika(a.begin(), a.end(), b.begin(), b.end(),SumaCifara);
	std::cout<<"Uvrnuta razlika kontejnera:\n";
	for(int i=0; i<r.size(); i++){
		for(int j=0; j<r[i].size(); j++)
			std::cout<<std::setw(6)<<r[i][j];
		std::cout<<"\n";	
	}
	std::cout<<"Dovidjenja!";
	return 0;
}
/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.bagg
	
*/
#include <iostream>
#include <vector> 
#include <algorithm>
#include <type_traits>
#include <deque>
#include <cmath>
#include <iomanip>

template<typename tip>
	int dajvel(tip a, tip b){
		int rjes=0;
		while(a!=b){
			a++;
			rjes++;
		}
		return rjes;
	}

template<typename itepok1, typename itepok2, typename tipfije, typename tipparam>
	auto UvrnutiPresjek(itepok1 poc1, itepok1 kraj1, itepok2 poc2, itepok2 kraj2, tipfije f(tipparam))->std::vector<std::vector<typename std::remove_reference<decltype(*poc1)>::type>>{
		std::vector<std::vector<typename std::remove_reference<decltype(*poc1)>::type>> v;
		int n=dajvel(poc1, kraj1);
		int m=dajvel(poc2, kraj2);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(f(poc1[i])==f(poc2[j])){
					bool ima=false;
					for(auto k:v){
						if(k[0]==poc1[i] && k[1]==poc2[j]){
							ima=true;
							break;
						}
					}
					if(ima==false){
						v.push_back(std::vector<typename std::remove_reference<decltype(*poc1)>::type> {poc1[i], poc2[j], f(poc1[i])});
					}
				}
			}
		}
		std::sort(v.begin(), v.end(), [](std::vector<typename std::remove_reference<decltype(*poc1)>::type> a, std::vector<typename std::remove_reference<decltype(*poc1)>::type> b){
			if(a[2]<b[2])return true; else
			if(a[2]==b[2]){
				if(a[0]<b[0])return true; else 
				if(a[0]==b[0]){
					if(a[1]<b[1])return true;
				}
			}
			return false;
		});
		return v;
	}

template<typename itepok1, typename itepok2>
	auto UvrnutiPresjek(itepok1 poc1, itepok1 kraj1, itepok2 poc2, itepok2 kraj2)->std::vector<std::vector<typename std::remove_reference<decltype(*poc1)>::type>>{
		std::vector<std::vector<typename std::remove_reference<decltype(*poc1)>::type>> v;
		int n=dajvel(poc1, kraj1);
		int m=dajvel(poc2, kraj2);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(poc1[i]==poc2[j]){
					bool ima=false;
					for(auto k:v){
						if(k[0]==poc1[i]){
							ima=true;
							break;
						}
					}
					if(ima==false){
						v.push_back(std::vector<typename std::remove_reference<decltype(*poc1)>::type> {poc1[i], 0, 0});
					}
				}
			}
		}
		std::sort(v.begin(), v.end(), [](std::vector<typename std::remove_reference<decltype(*poc1)>::type> a, std::vector<typename std::remove_reference<decltype(*poc1)>::type> b){
			return a[0]<b[0];
		});
		return v;
	}

template<typename itepok1, typename itepok2, typename tipfije, typename tipparam>
	auto UvrnutaRazlika(itepok1 poc1, itepok1 kraj1, itepok2 poc2, itepok2 kraj2, tipfije f(tipparam))->std::vector<std::vector<typename std::remove_reference<decltype(*poc1)>::type>>{
		std::vector<std::vector<typename std::remove_reference<decltype(*poc1)>::type>> v;
		int n=dajvel(poc1, kraj1);
		int m=dajvel(poc2, kraj2);
		for(int i=0;i<n;i++){
			bool ima=false;
			for(int j=0;j<m;j++){
				if(f(poc1[i])==f(poc2[j])){
					ima=true;
					break;
				}
			}
			for(auto k:v){
				if(poc1[i]==k[0]){
					ima=true;
					break;
				}
			}
			if(ima==false){
				v.push_back(std::vector<typename std::remove_reference<decltype(*poc1)>::type> {poc1[i], f(poc1[i])});
			}
		}
		for(int i=0;i<m;i++){
			bool ima=false;
			for(int j=0;j<n;j++){
				if(f(poc2[i])==f(poc1[j])){
					ima=true;
					break;
				}
			}
			for(auto k:v){
				if(poc2[i]==k[0]){
					ima=true;
					break;
				}
			}
			if(ima==false){
				v.push_back(std::vector<typename std::remove_reference<decltype(*poc1)>::type> {poc2[i], f(poc2[i])});
			}
		}
		std::sort(v.begin(), v.end(), [](std::vector<typename std::remove_reference<decltype(*poc1)>::type> a, std::vector<typename std::remove_reference<decltype(*poc1)>::type> b){
			return a[0]>b[0];
		});
		return v;
	}

template<typename itepok1, typename itepok2>
	auto UvrnutaRazlika(itepok1 poc1, itepok1 kraj1, itepok2 poc2, itepok2 kraj2)->std::vector<std::vector<typename std::remove_reference<decltype(*poc1)>::type>>{
		std::vector<std::vector<typename std::remove_reference<decltype(*poc1)>::type>> v;
		int n=dajvel(poc1, kraj1);
		int m=dajvel(poc2, kraj2);
		for(int i=0;i<n;i++){
			bool ima=false;
			for(int j=0;j<m;j++){
				if(poc1[i]==poc2[j]){
					ima=true;
					break;
				}
			}
			for(auto k:v){
				if(poc1[i]==k[0]){
					ima=true;
					break;
				}
			}
			if(ima==false){
				v.push_back(std::vector<typename std::remove_reference<decltype(*poc1)>::type> {poc1[i], 0});
			}
		}
		for(int i=0;i<m;i++){
			bool ima=false;
			for(int j=0;j<n;j++){
				if(poc2[i]==poc1[j]){
					ima=true;
					break;
				}
			}
			for(auto k:v){
				if(poc2[i]==k[0]){
					ima=true;
					break;
				}
			}
			if(ima==false){
				v.push_back(std::vector<typename std::remove_reference<decltype(*poc1)>::type> {poc2[i], 0});
			}
		}
		std::sort(v.begin(), v.end(), [](std::vector<typename std::remove_reference<decltype(*poc1)>::type> a, std::vector<typename std::remove_reference<decltype(*poc1)>::type> b){
			return a[0]>b[0];
		});
		return v;
	}


int sumacifara(long long int a){
	int suma=0;
	while(a){
		suma+=std::abs(a%10);
		a/=10;
	}
	return suma;
}

int SumaDjelilaca(long long int g){
	if(g<0)g=-g;
	if(g==0)return 0;
	if(g==1)return 1;
	long long int suma=g+1;
	long long int a=std::sqrt(g);
	for(long long int i=2;i<=a;i++){
		if(g%i==0){
			suma+=i;
			suma+=g/i;
		}
	}
	if(a*a==g)suma-=a;
	return suma;
}

bool daljeprost(long long int a){
	if(a==2 || a==3)return true;
	if(a<5)return false;
	if(a%6!=1 && a%6!=5)return false;
	long long int g=std::sqrt(a);
	for(long long int i=3;i<=g;i+=2){
		if(a%i==0)return false;
	}
	return true;
}

int BrojProstihFaktora(long long int g){
	if(g<0)g=-g;
	int prosti=0;
	for(long long int i=2;i<g;i++){
		if(daljeprost(i)){
			while(g%i==0){
				g/=i;
				prosti++;
			}
		}
	}
	if(daljeprost(g))prosti++;
	return prosti;
}

bool jelsavrsen(long long int g){
	if(SumaDjelilaca(g)-g==g)return true;
	return false;
}

int BrojSavrsenihDjelilaca(long long int g){
	if(g<0)g=-g;
	int savrseni=0;
	long long int a=std::sqrt(g);
	for(long long int i=2;i<a;i++){
		if(g%i==0){
			if(jelsavrsen(i))savrseni++;
			if(jelsavrsen(g/i))savrseni++;
		}
	}
	if(jelsavrsen(a))savrseni++;
	if(jelsavrsen(g))savrseni++;
	return savrseni;
}

int main ()
{
	long long int najm=std::numeric_limits<long long int>::min();
	std::cout<<najm<<" "<<sumacifara(najm);
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	int n;
	std::cin>>n;
	std::deque<int> d1;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	while(d1.size()!=n){
		int g;
		std::cin>>g;
		bool ima=false;
		for(auto j:d1){
			if(g==j){
				ima=true;
				break;
			}
		}
		if(ima==false){
			d1.push_back(g);
		}
	}
	int m;
	//radi reda
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	std::cin>>m;
	std::deque<int> d2;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	while(d2.size()!=m){
		int g;
		std::cin>>g;
		bool ima=false;
		for(auto j:d2){
			if(g==j){
				ima=true;
				break;
			}
		}
		if(ima==false){
			d2.push_back(g);
		}
	}
	
	std::vector<std::vector<int> > v;
	v=UvrnutiPresjek(d1.begin(), d1.end(), d2.begin(), d2.end(), sumacifara);
	std::cout<<"Uvrnuti presjek kontejnera:\n";
	for(auto i:v){
		for(auto j:i){
			std::cout<<std::setw(6)<<std::right<<j<<" ";
		}
		std::cout<<" \n";
	}
	v=UvrnutaRazlika(d1.begin(), d1.end(), d2.begin(), d2.end(), BrojProstihFaktora);
	std::cout<<"Uvrnuta razlika kontejnera:\n";
	for(auto i:v){
		for(auto j:i){
			std::cout<<std::setw(6)<<std::right<<j<<" ";
		}
		std::cout<<" \n";
	}
	std::cout<<"Dovidjenja!";
	return 0;
}
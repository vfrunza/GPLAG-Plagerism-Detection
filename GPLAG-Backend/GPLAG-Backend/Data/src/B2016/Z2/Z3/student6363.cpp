/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
//popraviti u UvrnutiPesijek lamdba funkciju da radi kad se funkcija ne proslijedi

#include<iostream>
#include<vector> 
#include <algorithm>
#include<cmath>
#include <deque>
#include<iomanip>
bool flag(false);
template <typename nesto = int, typename nesto2 = long long int>
nesto Default(nesto2 x){ flag = true; return x;}

template<typename nesto = int, typename nesto2 = long long int>
nesto SumaCifara(nesto2 n){
	int suma(0);
	unsigned long long int temp;
	if(n<0) temp = n*(-1);
	else  temp = n;
	while(temp>(unsigned long long int)0){
		suma+=temp%10;
		temp/=10;
	}
	return suma;
}

bool DaLiJeSavrsen(long long int n){
	int suma(0);
	for(int i(1); i<n; i++){
		if(n%i==0) suma+=i;
	}
	if(suma == n) return true;
	return false;
}
bool DaLiJeProst(long long int n){
	if(n<=1) return false;
	for(int i(2); i<=int(std::sqrt(n)); i++)
		if(n%i == 0) return false;
	
	return true;	
}
template<typename nesto = int, typename nesto2 = long long int>
nesto SumaDjelilaca(nesto2 n){
	int broj(0);
	unsigned long long int temp;
	if(n<0) temp=n*(-1);
	else temp=n;
	for(unsigned int i(1); i<=temp; i++){
		if(temp%i==0) broj+=i;
	}
	return broj;
}

template<typename nesto = int, typename nesto2 = long long int>
nesto BrojProstihFaktora(nesto2 n){
	unsigned long long int temp;
	int broj(0);
	if(n<0) temp=n*(-1);
	else temp=n;
	for(unsigned long long int i(2);i<=temp && temp>(unsigned long long int) 1; i++){
		if(DaLiJeProst(i)){
			if(temp%i == 0){ temp/=i; broj++; i=1;}
		}
	}
	return broj;
}

template<typename nesto = int, typename nesto2 = long long int>
nesto BrojSavrsenihDjelilaca(nesto2 n){
	unsigned long long int temp;
	if(n<0) temp = n*(-1);
	else temp = n;
	int broj(0);
	for(unsigned long long int i(1);i<=temp; i++ ){
		if(temp%i == 0){ 
			if(DaLiJeSavrsen(i)) broj++;
		}
	}
	return broj;
}

template<typename Itpok1, typename Itpok2>
auto UvrnutiPresjek(Itpok1 poc1, Itpok2 kraj1, Itpok2 poc2, Itpok2 kraj2, decltype(*poc1 + *poc1) (*F)(decltype(*poc2 + *poc2)) = Default) -> std::vector<std::vector<decltype(*poc1 + *poc1)> >{  
	Itpok1 temp1(poc1);
	std::vector<std::vector<decltype (*poc1 + *poc1)>> n;
	int i(0);
	const double E(1e-10);
	for(;temp1!=kraj1;temp1++){
		Itpok2 temp2(poc2);
		decltype(*poc1 + *poc1) N{F(*temp1)};
		if(!flag){
			for(;temp2!=kraj2 ;temp2++){
				if(std::fabs(N - F(*temp2))<=E){
					n.resize(i+1);
					n[i].push_back(*temp1);
					n[i].push_back(*temp2);
					n[i].push_back(N);
					i++;
				}
			}
		}
		else{
			for(;temp2 != kraj2 ; temp2++){
				if(std::fabs(N - F(*temp2))<=E){
				n.resize(i+1);
				n[i].push_back(N);
				n[i].push_back(0);
				n[i].push_back(0);
				i++;
				}
			}
		}
	}

	sort(n.begin(), n.end(), [](std::vector<decltype(*poc1 + *poc1)> x, std::vector<decltype(*poc1 + *poc1)> y)-> bool{const double E(1e-10); if(std::fabs(x[2]-y[2])<=E){ if(std::fabs(x[0] - y[0])<=E){ return x[1] < y[1];} else return x[0]<y[0];} else return x[2]< y[2];});
	flag = false;
	return n;
}

template<typename Itpok1, typename Itpok2>
auto UvrnutaRazlika(Itpok1 poc1, Itpok1 kraj1, Itpok2 poc2, Itpok2 kraj2, decltype(*poc1 + *poc1) (*F)(decltype(*poc2 + *poc2)) = Default) -> std::vector<std::vector<decltype(*poc1 + *poc1)>>{
	Itpok1 temp1(poc1);
	std::vector<std::vector<decltype(*poc1 + *poc1)>> n;
	int i(0);
	const double E(1e-10);
	
	while(temp1!=kraj1){
		Itpok2 temp2(poc2);
		bool ima_li(false);
		decltype(*poc1 + *poc1) N{F(*temp1)};
		while(temp2!=kraj2){
			if(std::fabs(N-F(*temp2))<=E) {ima_li = true; break;}
			temp2++;
		}
		if(!ima_li){
			
			n.resize(i+1);
			n[i].push_back(*temp1);
			if(flag) n[i].push_back(0);
			else n[i].push_back(N);
			i++;
		}
		
		temp1++;
	}
	Itpok2 temp2(poc2);
	while(temp2!=kraj2){
		Itpok1 temp1(poc1);
		bool ima_li(false);
		decltype(*poc1 + *poc1) N{F(*temp2)};
		while(temp1!=kraj1){
			if(std::fabs(N-F(*temp1))<=E){ima_li = true; break;}
			temp1++;
		}
		if(!ima_li){
			n.resize(i+1);
			n[i].push_back(*temp2);
			if(flag) n[i].push_back(0);
			else n[i].push_back(N);
			i++;
		}
		temp2++;
	}
	
	sort(n.begin(), n.end(), [](std::vector<decltype(*poc1 + *poc1)> x, std::vector<decltype(*poc1 + *poc1)> y)->bool{double E(1e-10); if(std::fabs(x[0]-y[0])<=E) return x[1]>y[1];else return x[0]>y[0];});
	flag = false;
	return n;
	
}

int main ()
{
	
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	int n;
	std::cin>>n;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	std::deque<int> D1, D2;
	for(int i(0); i<n;i++){
		bool isit(false);
		int d;
		std::cin>>d;
		
		for(int j(0); j<i; j++){
			if(D1[j] == d){isit = true; break;}
		}
		if(!isit) D1.push_back(d);
		else i--;
	}
	std::cout << "Unesite broj elemenata drugog kontejnera: ";
	std::cin>>n;
	std::cout << "Unesite elemente drugog kontejnera: ";
	for(int i(0);i<n; i++){
		bool isit(false);
		int d;
		std::cin>>d;
		
		for(int j(0); j<i; j++){
			if(D2[j] == d){isit = true; break;}
		}
		if(!isit) D2.push_back(d);
		else i--;
	}
	auto UP = UvrnutiPresjek(D1.begin(), D1.end(), D2.begin(), D2.end(), SumaCifara);
	auto UR = UvrnutaRazlika(D1.begin(), D1.end(), D2.begin(), D2.end(), BrojProstihFaktora);
	
	std::cout << "Uvrnuti presjek kontejnera:" << std::endl;
	for(auto x : UP){
		for (auto y : x) std::cout << std::setw(6) <<y<<" ";
		std::cout<<std::endl;
	}
	std::cout << "Uvrnuta razlika kontejnera:" << std::endl;
	for(auto x: UR){
		for(auto y: x) std::cout << std::setw(6) <<y<<" ";
		std::cout<<std::endl;
	}
	
	std::cout << "Dovidjenja!";
	
	
	return 0;
}
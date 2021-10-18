#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <cmath>
#include <iomanip>

int Default(long long int b){
	return int(b);
}
int SumaCifara(long long int n){
	int suma(0);
	while(n/10!=0){ suma=suma+(n%10); n/=10;}
	return suma+n;
}
int BrojProstihFaktora(long long int n){
	int umnoz(1), brojac(0);
	int broj(n);
	for(int i=2; i<=broj; i++){
		if(broj%i==0){
			umnoz*=i; brojac++;
			broj/=i; i--;
		}
		if(umnoz==n)break;
	}
	return brojac;
}
int SumaDjelilaca(long long int n){
	int sumadjel(0);
	for(int i=1; i<=abs(n); i++){
		if(abs(n)%i==0) sumadjel+=i;
	}
	return sumadjel;
}
int BrojSavrsenihDjelilaca(long long int n){
	int broj(0);
	for(int i=1; i<=n; i++){
		if(n%i==0){
			int suma(0);
			for(int j=1; j<i; j++)
				if(i%j==0) suma+=j;
		if(suma==i) broj++;
		}
	}
	return broj;
}

template <typename PokIt1, typename PokIt2, typename FunTip, typename FunPar>
auto UvrnutiPresjek(PokIt1 poc1, PokIt1 kr1, PokIt2 poc2, PokIt2 kr2, FunTip f(FunPar))-> std::vector<std::vector<typename std::remove_reference<decltype(*poc1+*poc2)>::type>>{
	std::vector<std::vector<typename std::remove_reference<decltype(*poc1+*poc2)>::type>> vrati;
	int res(1);
	auto ppoc1=poc1;
	while(ppoc1!=kr1){
		auto pompoc2(poc2);
		while(pompoc2!=kr2){
			if(f(*ppoc1)==f(*pompoc2)){
				vrati.resize(res);
				vrati[res-1].push_back(*ppoc1);
				vrati[res-1].push_back(*pompoc2);
				vrati[res-1].push_back(f(*ppoc1));
				res++;
			}
			pompoc2++;
		}
		ppoc1++;
	}
	
	//sortiranje
	std::sort(std::begin(vrati), std::end(vrati), [](std::vector<decltype(*poc1+*poc2)> a, std::vector<decltype(*poc1+*poc2)> b){
		if(a[2]<b[2]) return true;
		else if(a[2]==b[2]){
			if(a[0]<b[0]) return true;
			else if(a[0]==b[0]){
				if(a[1]<b[1]) return true;
			}
		}
		return false;
	});
	return vrati;
}
template <typename PokIt1, typename PokIt2>
auto UvrnutiPresjek(PokIt1 poc1, PokIt1 kr1, PokIt2 poc2, PokIt2 kr2)-> std::vector<std::vector<typename std::remove_reference<decltype(*poc1+*poc2)>::type>>{
	std::vector<std::vector<typename std::remove_reference<decltype(*poc1+*poc2)>::type>> vrati;
	int res(1);
	auto ppoc1=poc1;
	while(ppoc1!=kr1){
		auto pompoc2(poc2);
		while(pompoc2!=kr2){
			if(Default(*ppoc1)==Default(*pompoc2)){
				vrati.resize(res);
				vrati[res-1].push_back(*ppoc1);
				vrati[res-1].push_back(0);
				vrati[res-1].push_back(0);
				res++;
			}
			pompoc2++;
		}
		ppoc1++;
	}

	//sortiranje
	std::sort(std::begin(vrati), std::end(vrati), [](std::vector<decltype(*poc1+*poc2)> a, std::vector<decltype(*poc1+*poc2)> b){
		if(a[2]<b[2]) return true;
		else if(a[2]==b[2]){
			if(a[0]<b[0]) return true;
			else if(a[0]==b[0]){
				if(a[1]<b[1]) return true;
			}
		}
		return false;
	});
	return vrati;
}


template <typename PokIt1, typename PokIt2, typename FunTip, typename FunPar>
auto UvrnutaRazlika(PokIt1 poc1, PokIt1 kr1, PokIt2 poc2, PokIt2 kr2, FunTip f(FunPar))-> std::vector<std::vector<typename std::remove_reference<decltype(*poc1+*poc2)>::type>>{
	std::vector<std::vector<typename std::remove_reference<decltype(*poc1+*poc2)>::type>> vrati;
	int res(1);
	auto pompoc1=poc1;
	while(pompoc1!=kr1){
		auto pompoc2(poc2);
		bool checker(false);
		while(pompoc2!=kr2){
			if(f(*pompoc1)==f(*pompoc2)){checker=true; break;}
			pompoc2++;
		}
		if(!checker){
				vrati.resize(res);
				vrati[res-1].push_back(*pompoc1);
				vrati[res-1].push_back(f(*pompoc1));
				res++;
		}
		pompoc1++;
	}
	
	auto pompoc2=poc2;
	while(pompoc2!=kr2){
		auto pompoc1(poc1);
		bool checker(false);
		while(pompoc1!=kr1){
			if(f(*pompoc2)==f(*pompoc1)){checker=true; break;}
			pompoc1++;
		}
		if(!checker){
				vrati.resize(res);
				vrati[res-1].push_back(*pompoc2);
				vrati[res-1].push_back(f(*pompoc2));
				res++;
		}
		pompoc2++;
	}
	
	//sortiranje
	std::sort(std::begin(vrati), std::end(vrati), [](std::vector<decltype(*poc1+*poc2)> a, std::vector<decltype(*poc1+*poc2)> b){
		if(a[0]>b[0]) return true;
		else if(a[0]==b[0]){
			if(a[1]>b[1]) return true;
		}
		return false;
	});
	return vrati;
}
template <typename PokIt1, typename PokIt2>
auto UvrnutaRazlika(PokIt1 poc1, PokIt1 kr1, PokIt2 poc2, PokIt2 kr2)-> std::vector<std::vector<typename std::remove_reference<decltype(*poc1+*poc2)>::type>>{
	std::vector<std::vector<typename std::remove_reference<decltype(*poc1+*poc2)>::type>> vrati;
	int res(1);
	auto pompoc1=poc1;
	while(pompoc1!=kr1){
		auto pompoc2(poc2);
		bool checker(false);
		while(pompoc2!=kr2){
			if(Default(*pompoc1)==Default(*pompoc2)){checker=true; break;}
			pompoc2++;
		}
		if(!checker){
				vrati.resize(res);
				vrati[res-1].push_back(*pompoc1);
				vrati[res-1].push_back(0);
				res++;
		}
		pompoc1++;
	}
	
	auto pompoc2=poc2;
	while(pompoc2!=kr2){
		auto pompoc1(poc1);
		bool checker(false);
		while(pompoc1!=kr1){
			if(Default(*pompoc2)==Default(*pompoc1)){checker=true; break;}
			pompoc1++;
		}
		if(!checker){
				vrati.resize(res);
				vrati[res-1].push_back(*pompoc2);
				vrati[res-1].push_back(0);
				res++;
		}
		pompoc2++;
	}
	
	//sortiranje
	std::sort(std::begin(vrati), std::end(vrati), [](std::vector<decltype(*poc1+*poc2)> a, std::vector<decltype(*poc1+*poc2)> b){
		if(a[0]>b[0]) return true;
		else if(a[0]==b[0]){
			if(a[1]>b[1]) return true;
		}
		return false;
	});
	return vrati;
}

int main (){
	std::deque<int>kont1, kont2;
	int unos;
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	int n1;
	std::cin>>n1;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	for(int i=0; i<n1; i++){
		std::cin>>unos;
		bool bio(false);
		for(int j=0; j<kont1.size(); j++){
			if(unos==kont1[j]){bio=true; i--; break;}
		}
		if(!bio) kont1.push_back(unos);
	}
	
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	int n2;
	std::cin>>n2;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	for(int i=0; i<n2; i++){
		std::cin>>unos;
		bool bio(false);
		for(int j=0; j<kont2.size(); j++){
			if(unos==kont2[j]){bio=true; i--; break;}
		}
		if(!bio) kont2.push_back(unos);
	}
	
	auto kancer=UvrnutiPresjek(std::begin(kont1), std::end(kont1), std::begin(kont2), std::end(kont2), SumaCifara);
	std::cout<<"Uvrnuti presjek kontejnera: "<<std::endl;
	for(int i=0; i<kancer.size(); i++){
		for(int j=0; j<3; j++){
			std::cout<<std::right<<std::setw(6)<<kancer[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	auto kensr=UvrnutaRazlika(std::begin(kont1), std::end(kont1), std::begin(kont2), std::end(kont2), BrojProstihFaktora);
	std::cout<<"Uvrnuta razlika kontejnera: "<<std::endl;
	for(int i=0; i<kensr.size(); i++){
		for(int j=0; j<2; j++){
			std::cout<<std::right<<std::setw(6)<<kensr[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Dovidjenja!";
	return 0;
}
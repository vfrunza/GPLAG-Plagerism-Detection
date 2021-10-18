/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <algorithm>
#include <vector> 
#include <type_traits>
#include <iomanip>
#include <cmath>
#include <deque> 

template <typename tip1, typename tip2>
	auto UvrnutaRazlika (tip1 a, tip1 b, tip2 c, tip2 d  ) -> typename std::vector< typename std::vector< typename std::remove_reference<decltype(*a)>::type>>
		{ 
	int ks (d-c);
	typedef	 typename std::remove_reference<decltype(*a)>::type keno1; 
	 int ks1 (b-a); 
	 std::vector<keno1> f1;
	 std::vector<std::vector<keno1>> f2;
	while (a != b){
		bool istina (1);
		while (c != d){
			
		if (*a== *c ){
		istina = 0;
		} 
		c++; 
	}
	c = c - ks;
	if (istina == 1) { f1.push_back(*a); f1.push_back(0); f2.push_back(f1);  	
				int velicina (f1.size());
				for (int n=0; n<velicina; n++){
					f1.erase(f1.begin());
				} }
	a++;
	}
	a = a - ks1;
		
		 ks = b-a;
	while (c != d){
		bool istina (1);
		while (a != b){
			
		if (*c== *a ){
		istina = 0;
		} 
		a++; 
	}
	a = a - ks;
	if (istina == 1) { f1.push_back(*c); f1.push_back(0); f2.push_back(f1); int velicina (f1.size());
				for (int n=0; n<velicina; n++){
					f1.erase(f1.begin());
				}   }
	c++;
	}
	std::sort (std::begin(f2), std::end(f2), [](std::vector<keno1> p1, std::vector<keno1> p2) {if (p1[0] == p2[0]) { return p1[1]>p2[1];} return p1[0]>p2[0];} );
	return f2;
	
	
	}




bool pitanje (int x){
	int S(0);
	 for (int i=1; i<x; i++){
            if (x%i==0) S+=i;
        }
     if (S == x) return 1; else return 0;
}



int SumaDjelilaca (long long int n){
	int S(0);
	if (n<0) n = -n;
	for (int i=1; i<=n; i++){
 	if (n%i==0) S = S + i;
	 }
	 return S;
}


int BrojSavrsenihDjelilaca (long long int x){
	int broj(0);
	for (int i=1; i<=x; i++){
 	if ((x%i==0) && (pitanje(i)==1)) broj++;}
 	return broj;
}

 int fun (int x) 
 {
 	int S(0); 
 while (x!=0){
 S=S+x%10;
 x=x/10; }
 return S; }
 int BrojProstihFaktora (int x) 
 {
 int broj(0);
 int y(x);
 for (int i =2; i<=y; i++){
 	if (x%i==0){ broj++; 	x = x/i; i--; }
 	
 }
 return broj;
 }
//int fun1 (int x) { return x; }
template <typename tip1, typename tip2, typename tip3, typename tip4>
	auto UvrnutaRazlika (tip1 a, tip1 b, tip2 c, tip2 d, tip3 (*f) (tip4)  ) -> typename std::vector< typename std::vector< typename std::remove_reference<decltype(*a)>::type>>
	{
	int ks (d-c);
	typedef	 typename std::remove_reference<decltype(*a)>::type keno1; 
	 int ks1 (b-a); 
	 std::vector<keno1> f1;
	 std::vector<std::vector<keno1>> f2;
	while (a != b){
		bool istina (1);
		while (c != d){
			
		if (f(*a)== f(*c) ){
		istina = 0;
		} 
		c++; 
	}
	c = c - ks;
	if (istina == 1) { f1.push_back(*a); f1.push_back(f(*a)); f2.push_back(f1);  	
				int velicina (f1.size());
				for (int n=0; n<velicina; n++){
					f1.erase(f1.begin());
				} }
	a++;
	}
	a = a - ks1;
		
		 ks = b-a;
	while (c != d){
		bool istina (1);
		while (a != b){
			
		if (f(*c)== f(*a) ){
		istina = 0;
		} 
		a++; 
	}
	a = a - ks;
	if (istina == 1) { f1.push_back(*c); f1.push_back(f(*c)); f2.push_back(f1); int velicina (f1.size());
				for (int n=0; n<velicina; n++){
					f1.erase(f1.begin());
				}   }
	c++;
	}
	std::sort (std::begin(f2), std::end(f2), [](std::vector<keno1> p1, std::vector<keno1> p2) {if (p1[0] == p2[0]) { return p1[1]>p2[1];} return p1[0]>p2[0];} );
	return f2;
	}
template <typename tip1, typename tip2>
	auto UvrnutiPresjek (tip1 a, tip1 b, tip2 c, tip2 d  ) -> typename std::vector< typename std::vector< typename std::remove_reference<decltype(*a)>::type>>
		{ 
	int ks (d-c);
	typedef	 typename std::remove_reference<decltype(*a)>::type keno1; 
	 
	 std::vector<keno1> f1;
	 std::vector<std::vector<keno1>> f2;
	while (a != b){
		
		while (c != d){
			
		if (*a== *c ){
		//	std::cout<<"vrijednosti su"<<f(*a)<<" i" << f(*c)<< std::endl;
			f1.push_back(*a);
			f1.push_back(0);
			f1.push_back(0);
			f2.push_back(f1);
			int velicina (f1.size());
				for (int n=0; n<velicina; n++){
					f1.erase(f1.begin());
				}
		//	std::cout<<"KENOIO"<<std::endl;
		/*	for (std::vector<int> red : f2)
			{
		for (int broj : red)
			std::cout << broj << " ";
		std::cout << std::endl;
	}*/
		} 
		c++; 
	}
	c = c - ks;
	
	a++;
	}

	std::sort (std::begin(f2), std::end(f2), [](std::vector<keno1> p1, std::vector<keno1> p2) {if (p1[2] == p2[2]) {if (p1[0] == p2[0]) {  return p1[1]<p2[1];} return p1[0]<p2[0];} return p1[2] < p2[2]; } );
	return f2;
	}


template <typename tip1, typename tip2, typename tip3, typename tip4>
	auto UvrnutiPresjek (tip1 a, tip1 b, tip2 c, tip2 d, tip3 (*f) (tip4)  ) -> typename std::vector< typename std::vector< typename std::remove_reference<decltype(*a)>::type>>
	
	
	{
	int ks (d-c);
	typedef	 typename std::remove_reference<decltype(*a)>::type keno1; 
	 
	 std::vector<keno1> f1;
	 std::vector<std::vector<keno1>> f2;
	while (a != b){
		
		while (c != d){
			
		if (f(*a)== f(*c) ){
		//	std::cout<<"vrijednosti su"<<f(*a)<<" i" << f(*c)<< std::endl;
			f1.push_back(*a);
			f1.push_back(*c);
			f1.push_back(f(*a));
			f2.push_back(f1);
			int velicina (f1.size());
				for (int n=0; n<velicina; n++){
					f1.erase(f1.begin());
				}
		//	std::cout<<"KENOIO"<<std::endl;
		/*	for (std::vector<int> red : f2)
			{
		for (int broj : red)
			std::cout << broj << " ";
		std::cout << std::endl;
	}*/
		} 
		c++; 
	}
	c = c - ks;
	
	a++;
	}

	std::sort (std::begin(f2), std::end(f2), [](std::vector<keno1> p1, std::vector<keno1> p2) {if (p1[2] == p2[2]) {if (p1[0] == p2[0]) {  return p1[1]<p2[1];} return p1[0]<p2[0];} return p1[2] < p2[2]; } );
	return f2;
	}

int main ()
{
	
	int x,a;
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	std::cin>>x;
	//std::cin.ignore (1000, '\n');
	std::vector<int> prvi;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	for (; ;) {
		std::cin>>a;
		int adding (1);
		for (int element : prvi ){
			if (element == a) adding=0;
		}
		if (adding) prvi.push_back(a);
		if (prvi.size() == x) break;
	}
//	std::cin.ignore (1000,'\n');
	int y;
//	std::cin.ignore (1000, '\n');
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	std::cin>>y;
//	std::cin.ignore (1000, '\n');
	std::vector<int> drugi;
	std::cout<<"Unesite elemente drugog kontejnera: "; 
	for (; ;) {
		std::cin>>a;
		int adding (1);
		for (int element : drugi ){
			if (element == a) adding=0;
		}
		if (adding) drugi.push_back(a);
		if (drugi.size() == y) break;
	}
	 try {std::vector<std::vector<int>> keno = UvrnutiPresjek (std::begin(prvi), std::end(prvi), std::begin(drugi), std::end(drugi), fun ) ;
	 std::vector<std::vector<int>> mesi = UvrnutaRazlika (std::begin(prvi), std::end(prvi), std::begin(drugi), std::end(drugi), BrojProstihFaktora ) ;
	 
	std::cout<<"Uvrnuti presjek kontejnera:"<<std::endl;
	int dr(0);
	for (std::vector<int> red : keno)
	{		dr = 0; 
			for (int broj : red){
			std::cout<<std::setw(6) << broj<<" ";     }
			std::cout << std::endl;
	}
		std::cout<<"Uvrnuta razlika kontejnera:"<<std::endl;
	for (std::vector<int> red : mesi)
	{	dr = 0; 
		for (int broj : red) {
			std::cout<<std::setw(6) << broj<<" ";   	}
			std::cout << std::endl;
	}
	std::cout<<"Dovidjenja!";
	 }
	 catch (...){}
	return 0;
}
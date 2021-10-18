#include <iostream>
#include <algorithm>
#include <vector>
#include <type_traits>
#include <iomanip>
#include <deque>

bool DaLiJeProst(int broj){
	int brojac(0);
	for(int i=1; i<=broj/2; i++){
		if(broj%i==0) brojac++;
	}
	if(brojac==1) return true;
	return false;
}

int SumaDjelilaca(long long int n){
	int suma(0);
	if(n<0) n=-1*n;
	for(long long int i=1; i<=n/2; i++){ if(n%i==0) suma+=i; }
	suma+=n;
	return suma;
}

int BrojProstihFaktora(long long int n){
	int brojac(0);
	long long int broj(n);
	for(int i=2; i<=n/2; i++){
		if(broj%i==0){
			if(DaLiJeProst(i)){
				brojac++;
				broj/=i;
                i--;
			}
		}
	}
	if(DaLiJeProst(n)) brojac++;
	return brojac;
}

int BrojSavrsenihDjelilaca(long long int n){
	int brojac(0);
	if(n<0) n=-1*n;
	for(long long int i=2; i<=n/2; i++){
		if(n%i==0){
			long long int suma(0);
			for(long long int j=1; j<=i/2; j++){ if(i%j==0) suma+=j; }
			if(suma==i) brojac++;
		}
	}
	long long int suma(0);
	for(long long int i=1; i<=n/2; i++){ if(n%i==0) suma+=i; }
	if(suma==n) brojac++;
	return brojac;
}

/*bool FunkcijaKriterija(std::vector<Tip1> v1,std::vector<Tip1> v2){
	if(v1[2]>v2[2]) return false;
	else if(v1[2]==v2[2]){
		if(v1[0]>v2[0]) return false;
		else if(v1[0]==v2[0]){
			if(v1[1]>v2[1]) return false;
			else if(v1[1]==v2[1]) return true;
		}
	}
	return true;
}*/

template <typename Tip1, typename Tip2, typename Tip3, typename Tip4>
auto UvrnutiPresjek(Tip1 pocetak1, Tip1 iza_kraj1, Tip2 pocetak2, Tip2 iza_kraj2, Tip3 f(Tip4)) -> std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>>{
	std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>> mat;
	int brojac(0);
	Tip2 temp=pocetak2;
	while(pocetak1 != iza_kraj1){
		pocetak2=temp;
	    while(pocetak2 != iza_kraj2){
	        if(f(*pocetak1)==f(*pocetak2)){
	        	mat.resize(brojac+1);
	        	mat[brojac].push_back(*pocetak1);
	        	mat[brojac].push_back(*pocetak2);
	        	mat[brojac].push_back(f(*pocetak1));
	        	brojac++;
	        }
	        pocetak2++;
	    }
	    pocetak1++;
	}
	std::sort(mat.begin(), mat.end(), [](std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> v1,std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> v2){
	if(v1[2]>v2[2]) return false;
	else if(v1[2]==v2[2]){
		if(v1[0]>v2[0]) return false;
		else if(v1[0]==v2[0]){
			if(v1[1]>v2[1]) return false;
			else if(v1[1]==v2[1]) return true;
		}
	}
	return true;
});
	return mat;
}

template <typename Tip1, typename Tip2>
auto UvrnutiPresjek(Tip1 pocetak1, Tip1 iza_kraj1, Tip2 pocetak2, Tip2 iza_kraj2) -> std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>>{
	std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>> mat;
	Tip2 temp(pocetak2);
	int brojac(0);
	while(pocetak1 != iza_kraj1){
		pocetak2=temp;
		while(pocetak2 != iza_kraj2){
			if(*pocetak1==*pocetak2){
				mat.resize(brojac+1);
				mat[brojac].push_back(*pocetak1);
				mat[brojac].push_back(0);
				mat[brojac].push_back(0);
				brojac++;
			}
			pocetak2++;
		}
		pocetak1++;
	}
	return mat;
}

template <typename Tip1, typename Tip2, typename Tip3, typename Tip4>
auto UvrnutaRazlika(Tip1 pocetak1, Tip1 iza_kraj1, Tip2 pocetak2, Tip2 iza_kraj2, Tip3 f(Tip4)) -> std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>>{
	std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>> mat;
	int brojac(0);
	Tip2 temp(pocetak2);
	Tip1 temp1(pocetak1);
	while(pocetak1 != iza_kraj1){
		pocetak2=temp;
		bool razlika(true);
		while(pocetak2 != iza_kraj2){
			if(f(*pocetak1)==f(*pocetak2)){
				razlika=false;
				break;
			}
			pocetak2++;
		}
		if(razlika){
			mat.resize(brojac+1);
			mat[brojac].push_back(*pocetak1);
			mat[brojac].push_back(f(*pocetak1));
			brojac++;
		}
		pocetak1++;
	}
	pocetak2=temp;
	while(pocetak2 != iza_kraj2){
		pocetak1=temp1;
		bool razlika(true);
		while(pocetak1 != iza_kraj1){
			if(f(*pocetak2)==f(*pocetak1)){
				razlika=false;
				break;
			}
			pocetak1++;
		}
		if(razlika){
			mat.resize(brojac+1);
			mat[brojac].push_back(*pocetak2);
			mat[brojac].push_back(f(*pocetak2));
			brojac++;
		}
		pocetak2++;
	}
	std::sort(mat.begin(),mat.end(), [](std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> v1,std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> v2){
	if(v1[0]<v2[0]) return false;
	else if(v1[0]==v2[0]){
		if(v1[1]<v2[1]) return false;
		else if(v1[1]==v2[1]) return true;
	}
	return true;
});
	return mat;
}

template <typename Tip1, typename Tip2>
auto UvrnutaRazlika(Tip1 pocetak1, Tip1 iza_kraj1, Tip2 pocetak2, Tip2 iza_kraj2) -> std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>>{
	std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>> mat;
	int brojac(0);
	Tip2 temp(pocetak2);
	Tip1 temp1(pocetak1);
	while(pocetak1!=iza_kraj1){
		pocetak2=temp;
		bool razlika(true);
		while(pocetak2!=iza_kraj2){
			if(*pocetak1==*pocetak2){
				razlika=false;
				break;
			}
			pocetak2++;
		}
		if(razlika){
			mat.resize(brojac+1);
			mat[brojac].push_back(*pocetak1);
			mat[brojac].push_back(0);
			brojac++;
		}
		pocetak1++;
	}
	pocetak2=temp;
	while(pocetak2!=iza_kraj2){
		pocetak1=temp1;
		bool razlika(true);
		while(pocetak1!=iza_kraj1){
			if(*pocetak2==*pocetak1){
				razlika=false;
				break;
			}
			pocetak1++;
		}
		if(razlika){
			mat.resize(brojac+1);
			mat[brojac].push_back(*pocetak2);
			mat[brojac].push_back(0);
			brojac++;
		}
		pocetak2++;
	}
	std::sort(mat.begin(),mat.end(),[](std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> v1,std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> v2){
	if(v1[0]<v2[0]) return false;
	else if(v1[0]==v2[0]) return true;
	return true;
});
	return mat;
}

/*bool f(std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> v1,std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> v2){
	if(v1[0]>v2[0]) return false;
	else if(v1[0]==v2[0]) return true;
	}
	return true;
}*/

int sumaCifara(long long int n){
	int suma=0;
	while(n!=0){
		suma+=n%10;
		n/=10;
	}
	return suma;
}

template <typename Tip>
void Ispisi(std::vector<std::vector<Tip>> mat){
	for(int i=0; i<mat.size(); i++){
		for(int j=0; j<mat[i].size(); j++) std::cout << std::setw(6) << mat[i][j] << " ";
		std::cout<< std::endl;
	}
}

int main ()
{
	int brel1, brel2;
	std::deque<long long int> d1, d2;
	std::cout << "Unesite broj elemenata prvog kontejnera: " ;
	std::cin >> brel1;
	std::cout << "Unesite elemente prvog kontejnera: " ;
	for(int i=0; i<brel1; i++){ 
		long long int x;
		std::cin >> x;
		bool postoji(false);
		for(auto it=d1.begin(); it<d1.end(); it++){
			if(*it==x) postoji=true;
		}
		if(postoji) i--;
		else d1.push_back(x);
	}
	
	std::cout << "Unesite broj elemenata drugog kontejnera: " ;
	std::cin >> brel2;
	std::cout << "Unesite elemente drugog kontejnera: " ;
	for(int i=0; i<brel2; i++){ 
		long long int x;
		std::cin >> x;
		bool postoji(false);
		for(auto it=d2.begin(); it<d2.end(); it++){
			if(*it==x) postoji=true;
		}
		if(postoji) i--;
		else d2.push_back(x);
	}
	std::cout << "Uvrnuti presjek kontejnera:" << std::endl;
	auto rezultat1=UvrnutiPresjek(d1.begin(),d1.end(),d2.begin(),d2.end(),sumaCifara); Ispisi(rezultat1);
	std::cout << "Uvrnuta razlika kontejnera:" << std::endl;
	auto rezultat2=UvrnutaRazlika(d1.begin(),d1.end(),d2.begin(),d2.end(),BrojProstihFaktora); Ispisi(rezultat2);
	std::cout << "Dovidjenja!" ;
	
	
	/*std::vector<long long int> v1{15,16,17,12,13,14};
	std::vector<long long int> v2{31,51,91,71,21,23,24,22};
	std::cout << "Uvrnuti presjek kontejnera: " << std::endl;
	auto rezultat1=UvrnutiPresjek(v1.begin(),v1.end(),v2.begin(),v2.end(),sumaCifara); Ispisi(rezultat1);
	std::cout << "Uvrnuta razlika kontejnera: " << std::endl;
	auto rezultat2=UvrnutaRazlika(v1.begin(),v1.end(),v2.begin(),v2.end(),sumaCifara); Ispisi(rezultat2);
	//auto rezultat3=UvrnutiPresjek(v1.begin(),v1.end(),v2.begin(),v2.end()); Ispisi(rezultat3);*/
	return 0;
}
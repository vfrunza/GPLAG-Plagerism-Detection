#include <iostream>
#include <iomanip>
#include <deque>
#include <algorithm>
#include <type_traits>
#include <vector>
#include <cmath>

int SumaCifara(long long int broj){
	int suma{};
	while(broj){
		suma+=fabs(broj%10);
		broj/=10;
	}
	return suma;
}
int SumaDjelilaca(long long int broj){
	long long int suma{};
	for(long long int i=1;i<=fabs(broj/2);i++)
		if(broj%i==0)
			suma+=i;
	return suma+=fabs(broj);
}
int prosti_faktor(int broj){
	int prosti{2};
	while(1){
		if(broj%prosti==0) return prosti;
		prosti++;
		if(prosti>broj) break;
	}
	return 1;
}
int BrojProstihFaktora(long long int broj){
	int prosti, broj_pros{};
	while(1){
		prosti=prosti_faktor(broj);
		if(prosti==1)	break;
		broj_pros++;
		broj/=prosti;
	}
	return broj_pros;
}
int BrojSavrsenihDjelilaca(long long int broj){
	int broj_s{};
	for(long long int i=1;i<=fabs(broj/2);i++)
		if(broj%i==0)
			if(SumaDjelilaca(i)-i==i)
				broj_s++;
	if(SumaDjelilaca(broj)-abs(broj)==broj)
		broj_s++;
	return broj_s;
}

template<typename tip1, typename tip2, typename funk>
	auto UvrnutiPresjek(tip1 skup1_p, tip1 skup1_k, tip2 skup2_p, tip2 skup2_k, funk f)->std::vector<std::vector<typename std::remove_reference<decltype(skup1_p[0])>::type>>{
		std::vector<std::vector<typename std::remove_reference<decltype(skup1_p[0])>::type>> matrica;
		std::vector<typename std::remove_reference<decltype(skup1_p[0])>::type> presjek;
		auto temp=skup1_p;
		while(skup1_p!=skup1_k){
			for(auto pocetak=skup2_p;pocetak!=skup2_k;pocetak++)
				if(f(*skup1_p)==f(*pocetak)){
					presjek.resize(0);
					presjek.push_back(*skup1_p); presjek.push_back(*pocetak); presjek.push_back(f(*skup1_p));
					matrica.push_back(presjek);
				}
			skup1_p++;
		}
		skup1_p=temp;
		sort(std::begin(matrica), std::end(matrica), [](decltype(presjek) element1, decltype(presjek) element2)->bool{if(element1[2]==element2[2]){if(element1[0]==element2[0]){return element1[1]<element2[1];}else{return element1[0]<element2[0];}}else{return element1[2]<element2[2];}});
		return matrica;
	}

template<typename tip1, typename tip2, typename funk >
	auto UvrnutaRazlika(tip1 skup1_p, tip1 skup1_k, tip2 skup2_p, tip2 skup2_k, funk f)->std::vector<std::vector<typename std::remove_reference<decltype(skup1_p[0])>::type>>{
		std::vector<std::vector<typename std::remove_reference<decltype(skup1_p[0])>::type>> matrica;
		std::vector<typename std::remove_reference<decltype(skup1_p[0])>::type> presjek;
		
		auto temp=skup1_p;
		while(temp!=skup1_k){
			bool jednakost(false);
			for(auto pocetak=skup2_p; pocetak!=skup2_k;pocetak++)
				if(f(*temp)==f(*pocetak))
					jednakost=true;
			if(jednakost==false){
				presjek.resize(0);
				presjek.push_back(*temp); presjek.push_back(f(*temp));
				matrica.push_back(presjek);
			}
			temp++;		
		}
		
		while(skup2_p!=skup2_k){
			bool jednakost(false);
			for(auto pocetak=skup1_p; pocetak!=skup1_k;pocetak++)
				if(f(*skup2_p)==f(*pocetak))
					jednakost=true;
			if(jednakost==false){
				presjek.resize(0);
				presjek.push_back(*skup2_p); presjek.push_back(f(*skup2_p));
				matrica.push_back(presjek);
			}
			skup2_p++;		
		}

		sort(std::begin(matrica), std::end(matrica), [](decltype(presjek) element1, decltype(presjek) element2)->bool{if(element1[0]==element2[0]){return element1[1]<element2[1];}else{return element1[0]>element2[0];}});
		return matrica;
		
	}
	
template<typename tip1, typename tip2>
	auto UvrnutiPresjek(tip1 skup1_p, tip1 skup1_k, tip2 skup2_p, tip2 skup2_k)->std::vector<std::vector<typename std::remove_reference<decltype(skup1_p[0])>::type>>{
		std::vector<std::vector<typename std::remove_reference<decltype(skup1_p[0])>::type>> matrica;
		std::vector<typename std::remove_reference<decltype(skup1_p[0])>::type> presjek;
		auto temp=skup1_p;
		while(skup1_p!=skup1_k){
			for(auto pocetak=skup2_p;pocetak!=skup2_k;pocetak++)
				if(*skup1_p==*pocetak){
					presjek.resize(0);
					presjek.push_back(*skup1_p); presjek.push_back(0); presjek.push_back(0);
					matrica.push_back(presjek);
				}
			skup1_p++;
		}
		skup1_p=temp;
		sort(std::begin(matrica),std::end(matrica), [](decltype(presjek) element1, decltype(presjek) element2)->bool{if(element1[2]==element2[2]){if(element1[0]==element2[0]){return element1[1]<element2[1];}else{return element1[0]<element2[0];}}else{return element1[2]<element2[2];}});
		return matrica;
	}
	
template<typename tip1, typename tip2>
	auto UvrnutaRazlika(tip1 skup1_p, tip1 skup1_k, tip2 skup2_p, tip2 skup2_k)->std::vector<std::vector<typename std::remove_reference<decltype(skup1_p[0])>::type>>{
		std::vector<std::vector<typename std::remove_reference<decltype(skup1_p[0])>::type>> matrica;
		std::vector<typename std::remove_reference<decltype(skup1_p[0])>::type> presjek;
		
		auto temp=skup1_p;
		while(temp!=skup1_k){
			bool jednakost(false);
			for(auto pocetak=skup2_p; pocetak!=skup2_k;pocetak++)
				if(*temp==*pocetak)
					jednakost=true;
			if(jednakost==false){
				presjek.resize(0);
				presjek.push_back(*temp); presjek.push_back(0);
				matrica.push_back(presjek);
			}
			temp++;		
		}
		
		while(skup2_p!=skup2_k){
			bool jednakost(false);
			for(auto pocetak=skup1_p; pocetak!=skup1_k;pocetak++)
				if(*skup2_p==*pocetak)
					jednakost=true;
			if(jednakost==false){
				presjek.resize(0);
				presjek.push_back(*skup2_p); presjek.push_back(0);
				matrica.push_back(presjek);
			}
			skup2_p++;		
		}

		sort(std::begin(matrica), std::end(matrica), [](decltype(presjek) element1, decltype(presjek) element2)->bool{if(element1[0]==element2[0]){return element1[1]<element2[1];}else{return element1[0]>element2[0];}});
		return matrica;	
	}

void Unos(std::deque<int> &deq, int br_el){
	for(int i=0;i<br_el;){
		int broj;
		std::cin>>broj;
		if(find(deq.begin(), deq.end(), broj)==deq.end()){
			deq.push_back(broj); i++;
		}
	}

}

int main (){

	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	int br_el1, br_el2;
	std::cin>>br_el1;
	std::deque<int> deq1,deq2;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	Unos(deq1,br_el1);
	
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	std::cin>>br_el2;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	Unos(deq2,br_el2);
	
	std::cout<<"Uvrnuti presjek kontejnera:\n";
	for(auto red: UvrnutiPresjek(deq1.begin(), deq1.end(), deq2.begin(), deq2.end(), SumaCifara)){
		for(auto element: red)
			std::cout<<std::fixed<<std::setw(6)<<element<<" ";
		std::cout<<std::endl;
	}
	
	std::cout<<"Uvrnuta razlika kontejnera:\n";
	for(auto red: UvrnutaRazlika(deq1.begin(), deq1.end(), deq2.begin(), deq2.end(), BrojProstihFaktora)){
		for(auto element: red)
			std::cout<<std::fixed<<std::setw(6)<<element<<" ";
		std::cout<<std::endl;
	}
	
	std::cout<<"Dovidjenja!";
	return 0;
}
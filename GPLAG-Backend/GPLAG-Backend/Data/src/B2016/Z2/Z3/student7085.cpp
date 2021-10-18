#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <iomanip>


int SumaDjelilaca(long long int broj){
	int suma(0);
	if(broj<0)broj=-broj;
		for(int i=1;i<=broj;i++){
			if(broj%i==0) suma+=i;
		}
	return suma;
}

int SumaCifara(long long int broj){
	int suma(0);
	while(broj!=0){
	    suma+=broj%10;
		broj/=10;
	}
	return suma;
}

bool DaliJeProst(int n){
	for(int i=2;i<n;i++)
	if(n%i==0) return false;
	return true;
}
int BrojProstihFaktora( long long int broj){
	int brojac(0);
	for(int i=2;i<=broj; i++){
		if(broj%i==0)
			if(DaliJeProst(i))
			{
				while(broj%i==0) {broj/=i; brojac++;}
	        }
	}
	return brojac;
}


int SavrsenBroj(int n){
	int suma(0);
	for(int i=1;i<n;i++){
	   if(n%i==0)
	   suma+=i;
	}
	return suma;
}
int BrojSavrsenihDjelilaca(long long int n){
	int brojac(0);
	for(int i=1;i<=n;i++){
		if(n%i==0 && i==SavrsenBroj(i)) brojac++;
	}
	return brojac;
}



template < typename tip1,typename tip2>
auto UvrnutiPresjek( tip1 p1, tip1 p2, tip2 p3, tip2 p4 ) ->typename std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>
{
		std::vector<std::vector<decltype(*p1+*p1)>> mat ; 
		tip2 pom3=p3;
		while(p1!=p2){
			while(p3!=p4){
			    if(*p1==*p3){
			     std::vector<decltype(*p1+*p1)>v={*p1,0,0} ;
			     mat.push_back(v);
			    }
			    p3++;
			}
			p1++;
			p3=pom3;
		}
		sort(mat.begin(),mat.end(),[](std::vector<decltype(*p1+*p1)> jedan , std::vector<decltype(*p1+*p1)> drugi){ 
		if(jedan[0]==drugi[0] && jedan[2] == drugi[2])return jedan[1] < drugi[1];
		if(jedan[2] == drugi[2])return jedan[0] < drugi[0];
		return jedan[2]<drugi[2] ;});
		return mat;
	}

template <typename tip3, typename tip1,typename tip2,typename tip4>
auto UvrnutiPresjek( tip1 p1, tip1 p2, tip2 p3, tip2 p4, tip3 f(tip4) ) -> std::vector<std::vector<tip3>>
{
	std::vector<std::vector<tip3>> mat ; 
	while(p1!=p2){
		tip2 k=p3;
				
		while(k!=p4){
			if(f(*p1) == f(*k)){
				std::vector<tip3>v {*p1,*k,f(*p1)} ;
				mat.push_back(v);
			}
			k++;
		}
		p1++;
	}
	sort(mat.begin(),mat.end(),[](std::vector<tip3> jedan , std::vector<tip3> drugi){ 
		if(jedan[0]==drugi[0] && jedan[2] == drugi[2])return jedan[1] < drugi[1];
		if(jedan[2] == drugi[2])return jedan[0] < drugi[0];
		return jedan[2]<drugi[2] ;});

	return mat;
}
template < typename tip1,typename tip2>
auto UvrnutaRazlika( tip1 p1, tip1 p2, tip2 p3, tip2 p4) ->typename std::vector<std::vector<decltype(*p1+*p1)>>
{
   std::vector<std::vector<decltype(*p1+*p1)>> mat1 ; 
    tip1 pom1=p1;
    while(pom1!=p2){
    	bool pret(false);
    	tip2 pom3=p3;
    	while (pom3!=p4) {
    		if(*pom1==*pom3){
    		pret=true;
    		break;
    		}
    		pom3++;
    	}
    	if(!pret){
    		std::vector<decltype(*p1+*p1)> v1={*pom1,0} ;
    		mat1.push_back(v1);
    	}
    	pom1++;
    }
    tip1 poom1=p1;
    while(p3!=p4){
    	bool pret(false);
    	poom1=p1;
    	while (poom1!=p2) {
    		if(*p3==*poom1){
    		pret=true;
    		break;
    		}
    		poom1++;
    	}
    	if(!pret){
    		std::vector<decltype(*p1+*p1)> v1={*p3,0} ;
    		mat1.push_back(v1);
    	}
    	p3++;
    	
    }
    	sort(mat1.begin(),mat1.end(),[](std::vector<decltype(*p1+*p1)> jedan , std::vector<decltype(*p1+*p1)> drugi){ 
		if(jedan[0] == drugi[0])return jedan[1] > drugi[1];
		return jedan[0] > drugi[0];
		});
	
	return mat1;
} 


template <typename tip3, typename tip1,typename tip2, typename tip4>
auto UvrnutaRazlika( tip1 p1, tip1 p2, tip2 p3, tip2 p4, tip3 f(tip4)) ->std::vector<std::vector<tip3>>
{
    std::vector<std::vector<tip3>> mat1 ; 
    tip1 pom1=p1;
    while(pom1!=p2){
    	bool pret(false);
    	tip2 pom3=p3;
    	while (pom3!=p4) {
    		if(f(*pom1)==f(*pom3)){
    		pret=true;
    		break;
    		}
    		pom3++;
    	}
    	if(!pret){
    		std::vector<tip3> v1={*pom1,f(*pom1)} ;
    		mat1.push_back(v1);
    	}
    	pom1++;
    }
    tip1 poom1=p1;
    while(p3!=p4){
    	bool pret(false);
    	poom1=p1;
    	while (poom1!=p2) {
    		if(f(*p3)==f(*poom1)){
    		pret=true;
    		break;
    		}
    		poom1++;
    	}
    	if(!pret){
    		std::vector<tip3> v1={*p3,f(*p3)} ;
    		mat1.push_back(v1);
    	}
    	p3++;
    	
    }
    	sort(mat1.begin(),mat1.end(),[](std::vector<tip3> jedan , std::vector<tip3> drugi){ 
		if(jedan[0] == drugi[0])return jedan[1] > drugi[1];
		return jedan[0] > drugi[0];
		});
	
	return mat1;
}


int main ()
{
	int broj_elemenata, broj_elemenata2;
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	std::cin>> broj_elemenata;
	std::deque<int> dek(broj_elemenata);
	std::cout<<"Unesite elemente prvog kontejnera: ";
	for(int i = 0; i < dek.size(); i++){
		int elem;
		std::cin>>elem;
		auto it = std::find(dek.begin(),dek.end(),elem);
		if(it == dek.end())dek[i] = elem;
		else i--;
	}
	
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	std::cin>> broj_elemenata2;
	
	std::deque<int> dek2(broj_elemenata2);
	std::cout<<"Unesite elemente drugog kontejnera: ";
		for(int i = 0; i < dek2.size(); i++){
		int elem;
		std::cin>>elem;
		auto it = std::find(dek2.begin(),dek2.end(),elem);
		if(it == dek2.end())dek2[i] = elem;
		else i--;
	}
	
	
	std::cout<<"Uvrnuti presjek kontejnera: "<<std::endl;
	auto matrica=UvrnutiPresjek(dek.begin(),dek.end(), dek2.begin(),dek2.end(),SumaCifara);
	for(int i=0;i<matrica.size();i++){
	for(int j=0;j<matrica[i].size();j++){
		std::cout<<std::setw(6)<<matrica[i][j]<<" ";
	}
	std::cout<<std::endl;
	}
	
	std::cout<<"Uvrnuta razlika kontejnera: "<<std::endl;
	auto kontejner=UvrnutaRazlika(dek.begin(),dek.end(), dek2.begin(),dek2.end(),BrojProstihFaktora);
    for(int i=0;i<kontejner.size();i++){
	for(int j=0;j<kontejner[i].size();j++){
		std::cout<<std::setw(6)<<kontejner[i][j]<<" ";
	}
	std::cout<<std::endl;
	}
	
	std::cout<<"Dovidjenja!";

	return 0;
}

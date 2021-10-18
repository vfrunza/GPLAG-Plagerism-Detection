
/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <deque>
#include <type_traits>


template <typename PokTip1, typename PokTip2, typename Tip1, typename Tip2>
std::vector<std::vector<Tip1>> UvrnutiPresjek(PokTip1 p1, PokTip1 p2, PokTip2 p3, PokTip2 p4, Tip2 f(Tip1) ){
	std::vector<std::vector<Tip1>> Matrica;
	int brojac(0);
	PokTip1 pok1(p1), pok2(p2);
	while(pok1!=pok2){
		PokTip2 pok3(p3);
		while(pok3!=p4){
			if(f(*pok1)==f(*pok3)){
				Matrica.resize(Matrica.size()+1);
				Matrica[Matrica.size()-1].resize(3);
				Matrica[brojac][0] = *pok1;
				Matrica[brojac][1] = *pok3;
				Matrica[brojac][2] = f(*pok1);
				brojac++;
			}
		pok3++;
		}
	pok1++;
	}



return Matrica;
}

template<typename poktip1, typename poktip2>
auto UvrnutiPresjek(poktip1 p1, poktip1 p2, poktip2 p3, poktip2 p4)->typename std::remove_reference<std::vector<std::vector<decltype(*p1)>>>::type{
	typename std::remove_reference<std::vector<std::vector<decltype(*p1)>>>::type Matrica;
	int brojac(0);
	poktip1 pok1(p1);
	while(pok1!=p2){
		poktip2 pok3(p3);
		while(pok3!=p4){
			if(*pok1==*pok3){
				Matrica.resize(Matrica.size()+1);
				Matrica[Matrica.size()-1].resize(3);
				Matrica[brojac][0] = *pok1;
				Matrica[brojac][1] = 0;
				Matrica[brojac][2] = 0;
				brojac++;
			}
			pok3++;
		}
		pok1++;
	}
	return Matrica;
}


template <typename poktip1, typename poktip2, typename tip1, typename tip2>
std::vector<std::vector<tip1>> UvrnutaRazlika (poktip1 p1, poktip1 p2, poktip2 p3, poktip2 p4, tip2 f(tip1)){
	std::vector<std::vector<tip1>> Matrica;
	int brojac(0);
	poktip1 pok1(p1);
	poktip2 pok3(p3);
	while(pok1!=p2) {
       pok3 = p3;
       while (pok3!=p4) {
       	  if(f(*pok1)==f(*pok3))
       	    break;
       	  pok3++;
       }
       if(pok3==p4){
       	Matrica.resize(Matrica.size()+1);
       	Matrica[Matrica.size()-1].resize(2);
       	Matrica[brojac][0] = *pok1;
       	Matrica[brojac][1] = f(*pok1);
       	brojac++;
       }
       pok1++;
	}
	pok1 = p1;
	pok3 = p3;
	while(pok3!=p4){
		pok1 = p1;
		while (pok1!=p2) {
			if(f(*pok3)==f(*pok1))
			  break;
			pok1++;
		}
	    if(pok1==p2){
	    	Matrica.resize(Matrica.size()+1);
	    	Matrica[Matrica.size()-1].resize(2);
	    	Matrica[brojac][0] = *pok3;
	    	Matrica[brojac][1] = f(*pok3);
	    	brojac++;
	    }
	 pok3++;  
	}
return Matrica;
}

template <typename poktip1, typename poktip2>
auto UvrnutaRazlika(poktip1 p1, poktip1 p2, poktip2 p3, poktip2 p4)-> typename std::remove_reference<std::vector<std::vector<decltype(*p1)>>>::type {
	typename std::remove_reference<std::vector<std::vector<decltype(*p1)>>>::type Matrica;
	poktip1 pok1(p1);
	poktip2 pok3(p3);
	int brojac(0);
	while(pok1!=p2){
		pok3 = p3;
		while(pok3!=p4){
			if(*pok1==*pok3)
			  break;
			pok3++;
		}
		if(pok3==p4){
			Matrica.resize(Matrica.size() + 1);
			Matrica[Matrica.size() - 1].resize(2);
			Matrica[brojac][0] = *pok1;
			Matrica[brojac][1] = 0;
			brojac++;
		}
		pok1++;
	}
	pok1 = p1;
	pok3 = p3;
	while(pok3!=p4){
		pok1 = p1;
		while (pok1!=p2) {
			if(*pok3==*pok1)
			  break;
			pok1++;
		}
		if(pok1==p2){
			Matrica.resize(Matrica.size() + 1);
			Matrica[Matrica.size() - 1].resize(2);
			Matrica[brojac][0] = *pok3;
			Matrica[brojac][1] = 0;
			brojac++;
		}
	pok3++;
	}
	return Matrica;
}

int SumaDjelilaca (long long int n){
	int suma(0);
	for(int i=1; i<=n; i++){
		if(n%i==0)
		  suma+=i;
	}
return suma;
}

int SumaCifara(long long int n){
	int suma(0);
	while(n!=0){
		suma+=std::abs(n%10);
		n/=10;
	}
return suma;
}


int BrojProstihFaktora (long long int n){
	int brojac(0);
	long long int a(n);
	//while(a!=0){
		for(int k=2; k<=n; k++){
			bool z(true);
			for(int i=2; i<k; i++){
				if(k%i==0){
					z = false;
					break;
				}
			}
		if(a%k==0 && z){
			while(a%k==0){
				brojac++;
				a/=k;
			}
		}
		}
//	}
return brojac;
}

int BrojSavrsenihDjelilaca (long long int n){
	int brojac(0);
	//long long int a(n);
	for(int k=2; k<=n; k++){
		if(n%k==0){
			int suma(0);
			for(int l=2; l<k; l++){
				if(k%l==0)
				  suma+=l;
			}
		if(suma==k)
		   brojac++;
		}
	}
return brojac;	
}




int main ()
{
	
	int n,m;
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	std::cin>>n;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	std::deque<int> dek1(n) ;
	for(int i=0; i<n; i++)
	  std::cin>>dek1[i];
	std::cin.clear();
	std::cin.ignore(10000, '\n');
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	std::cin>>m;

	std::cout<<"Unesite elemente drugog kontejnera: ";
	std::deque<int> dek2(m);
	for(int i=0; i<m; i++)
	  std::cin>>dek2[i];
	auto mat1(UvrnutiPresjek(dek1.begin(), dek1.end(), dek2.begin(), dek2.end(), SumaCifara));
   // auto mat1(UvrnutiPresjek(dek1.begin(), dek1.end(), dek2.begin(), dek2.end() ));
	std::cout<<"Uvrnuti presjek kontejnera: "<<std::endl;
	for(int i=0; i<mat1.size(); i++){
		for(int j=0; j<mat1[i].size(); j++)
		  std::cout<<mat1[i][j]<<" ";
		  
		std::cout<<std::endl;
	}
	auto mat2(UvrnutaRazlika(dek1.begin(), dek1.end(), dek2.begin(), dek2.end(), SumaCifara ));
	std::cout<<"Uvrnuta razlika kontejnera: \n";
	for(int i=0; i<mat2.size(); i++){
		for(int j=0; j<mat2[i].size(); j++){
			std::cout<<mat2[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	return 0;
}
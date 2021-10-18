/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <type_traits>

//fja za provjeru razl elemenata



int Suma(int broj){
	int suma(0);
	while(broj!=0){
		suma+=(broj%10);
		broj/=10;
	}
return suma;
}

int SumaDjelilaca(long long int broj){
	int suma(0);
	for (int i=1; i<=broj; i++){
		if(broj%i==0) suma+=i;
	}
	return suma;
}
 //fja za provjeru da li je djel prost
 bool Prost(int broj){
 	int i(2);
 	while(i!=broj){
 		if(broj%i==0) break;
 	}
 	return i==broj;
 }
 
 
int BrojProstihFaktora(long long int broj){
	int brojac(0);
	while(broj!=1){
		for(int i=2; i<=broj; i++){
			if(broj%i==0 && Prost(i)) {
				broj=broj/i;
				brojac++;
			}
		}	
	}
return brojac;
}

bool SavrsenDjelilac(int broj){
	int suma(0);

	for(int i=1; i<broj; i++){
		    if(broj==1) break; 
			if(broj%i==0 ){
			broj/=i;
			suma+=i;
			}
	}
	return suma==broj;
}

int BrojSavrsenihDjelilaca (long long int broj){
	int brojac(1);
	while(broj!=1){
		for(int i=2; i<=broj; i++){
			if(broj%i==0 &&  SavrsenDjelilac(i)){
				brojac++;
				broj/=i;
				break;
			} 
		}
	}
	return brojac;
}	
	


template <typename tip_kont1, typename tip_kont2, typename tip_fje, typename tip_param>
auto UvrnutiPresjek(tip_kont1 poc1, tip_kont1 kraj1, tip_kont2 poc2, tip_kont2 kraj2, tip_fje f(tip_param)) -> std::vector<std::vector<typename std::remove_reference<decltype(*poc1)>::type>>{
	
	
	//matrica
 	int brojacredova(0);
	std::vector<std::vector<typename std::remove_reference<decltype(*poc1)>::type>> matrica;
	for(auto i=poc1; i!=kraj1; i++ ){
		std::vector<typename std::remove_reference<decltype(*poc1)>::type> vektor;
		for(auto j=poc2; j!=kraj2; j++){
			int x=f(*i);
			int y=f(*j);
			if(x==y){
				brojacredova++;
				vektor.push_back(*i);
				vektor.push_back(*j);
				vektor.push_back(f(*i));
				matrica.resize(brojacredova);
				for(int k=0; k<3; k++){
					matrica[brojacredova-1][k]=vektor[k];
				}
			}
		}
	}
	
	//sortiranje
	sort (matrica.begin(), matrica.end(), [](std::vector<typename std::remove_reference<decltype(*poc1)>::type> x, std::vector<typename std::remove_reference<decltype(*poc1)>::type> y){ 
		if(x[2]!=y[2]) return x[2]>y[2];
		else if(x[1]!=x[2]) return x[1]>y[1];
		return  x[0]>y[0]; 
		}
		
	);
	
	return matrica;
	
}



//fja za provjeru ima li par u dr kont
template <typename tip_elem, typename tip_kont, typename tip_fje, typename tip_param>
bool Jedinstven(tip_elem i, tip_kont poc, tip_kont kraj, tip_fje f(tip_param)){
	while(poc!=kraj){
		if(f(i)!=f(*poc)) poc++;
	}
	if (poc==kraj) return 1;
	return 0;
}

template <typename tip_kont1, typename tip_kont2, typename tip_fje, typename tip_param>
auto UvrnutaRazlika (tip_kont1 poc1, tip_kont1 kraj1, tip_kont2 poc2, tip_kont2 kraj2, tip_fje f(tip_param)) -> std::vector<std::vector<typename std::remove_reference<decltype(*poc1)>::type>>{
	 
	 std::vector<std::vector<typename std::remove_reference<decltype(*poc1)>::type>> matrica;
	 int n(0);
	 
	 for(auto i=poc1; i!=kraj1; i++){
	  if(Jedinstven(*i,poc2, kraj2, f)){
	 		n++;
	 		matrica.resize(n);
	 		matrica[n]. resize(2);
	 		matrica[n-1].push_back(*i);
	 		matrica[n-1].push_back(f(*i));
	 	}
	 }
	 
	 for( auto i=poc2; i!=kraj2; i++){
	 	if(Jedinstven(*i, poc1, kraj1, f)){
	 		n++;
	 		matrica.resize(n);
	 		matrica[n].resize(2);
	 		matrica[n-1].push_back(*i);
	 		matrica[n-1].push_back(f(*i));
	 	}
	 }
	
	//sortiranje

	
	sort(matrica.begin(), matrica.begin()+n, [](std::vector<typename std::remove_reference<decltype(*poc1)>::type> x, std::vector<typename std::remove_reference<decltype(*poc1)>::type> y){
		if(x[0]!=y[0]) return x[0]<y[0];
		else return x[1]<y[1];
		}
	);
	
	return matrica;

}


int main (){
	int br1;
	
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	std::cin>>br1;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	std::vector<int>v1;
	int i(0);
	while(i<br1){
		int broj;
		std::cin>>broj;
		bool razliciti(1);
	     for(int k=0; k<i; k++){
	     	if(broj==v1[k]) {
				razliciti=0;
				break;
			}
	     }
		if(razliciti){
			v1.push_back(broj);
			i++;
		}
	}
	
	 int br2;
	std::cout<<"Unesite broj elemenata drguog kontejnera: ";
	std::cin>>br2;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	std::vector<int>v2;
	int j(0);
	while(j<br2){
	   int broj;
		std::cin>>broj;
		bool razliciti(1);
	     for(int k=0; k<j; k++){
	     	if(broj==v2[k]) {
				razliciti=0;
				break;
			}	
	     }	
	
		if(razliciti){
			v2.push_back(broj);
			j++;
		}
	}
	auto m(UvrnutiPresjek(v1.begin(), v1.begin()+br1, v2.begin(), v2.begin()+br2, Suma));
	auto m1(UvrnutaRazlika(v1.begin(), v1.begin()+br1, v2.begin(), v2.begin()+br2, Suma));
	 
	std::cout<<"Uvrnuti presjek kontejnera: "<<std::endl;
	for(int i=0; i<m.size(); i++){
		for(int j=0; j<3; j++){
			std::cout<<m[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	
	std::cout<<"Uvrnuta razlika kontejnera: "<<std::endl;
		for(int i=0; i<m1.size(); i++){
		for(int j=0; j<3; j++){
			std::cout<<m1[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	
	
	return 0;
}
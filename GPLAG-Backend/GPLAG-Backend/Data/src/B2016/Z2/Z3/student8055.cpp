/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <iterator>
#include <utility>
#include <type_traits>
#include <algorithm>
#include <iomanip>


int SumaCifara(long long int a) {
    int suma(0);
    while(a != 0){
        suma+=a%10;
        a/=10;
    }
    return suma;
}
int SumaDjelilaca(long long int a) {
    int suma(0);
    for(int i(1); i <= a; i++) {
        if(a%i == 0) suma+=i;
    }
    return suma;
}

bool JelProst(long long int a){
	for(int i=2; i<a; i++){
		if(a%i==0) return false;
	}
	return true;
}

int BrojProstihFaktora(long long int a){
	int suma(0);
	for(int i=2;i<=a; i++){
        while(a%i == 0){
            if(JelProst(i)){
                suma++;
				a/=i;
            }
        }
    }
	return suma;
}

int BrojSavrsenihDjelilaca(long long int a){
    int counter(0), devider_sum(0),devider;
    bool perfect(false);
    for(int i(2); i <= a; i++){
        if(a%i == 0){
            perfect=false;
            devider = i;
            devider_sum = 0;
            for(int j(1); j < devider; j++) {
                if(devider%j == 0) devider_sum+=j;
            }
            if(devider == devider_sum) perfect=true;
            if(perfect) counter++;
            
        }
    }
    return counter;
}

template <typename IterTip1, typename IterTip2, typename NekiTip1, typename NekiTip2> 
auto UvrnutiPresjek(IterTip1 pocetak_1, IterTip1 kraj_1, IterTip2 pocetak_2, IterTip2 kraj_2, NekiTip2 f(NekiTip1)) -> std::vector<std::vector<decltype(*pocetak_2 + *pocetak_1)>>{
	std::vector<std::vector<decltype(*pocetak_2 + *pocetak_1)>> Mat(0);
	while(pocetak_1 != kraj_1){
		IterTip2 poc_2=pocetak_2;
		while(poc_2 != kraj_2){
			if (f(*pocetak_1) == f(*poc_2)){
				Mat.resize(Mat.size()+1);
				Mat[Mat.size() - 1].push_back(*pocetak_1);
				Mat[Mat.size() - 1].push_back(*poc_2);
				Mat[Mat.size() - 1].push_back(f(*pocetak_1));
			}
			poc_2++;
		}
		pocetak_1++;
	}
	std::sort(Mat.begin(), Mat.end(), [] (std::vector<decltype(*pocetak_2 + *pocetak_1)> v1, std::vector<decltype(*pocetak_2 + *pocetak_1)> v2){
		if(v1[2] == v2[2]){
			if(v1[0] == v2[0]){
				return v1[1] < v2[1];
			}else return v1[0] < v2[0];
		}else return v1[2] < v2[2];
	});
	
	return Mat;
}

template <typename IterTip1, typename IterTip2> 
auto UvrnutiPresjek(IterTip1 pocetak_1, IterTip1 kraj_1, IterTip2 pocetak_2, IterTip2 kraj_2) -> std::vector<std::vector<decltype(*pocetak_2 + *pocetak_1)>>{
	std::vector<std::vector<decltype(*pocetak_2 + *pocetak_1)>> Mat(0);
	while(pocetak_1 != kraj_1){
		IterTip2 poc_2=pocetak_2;
		while(poc_2 != kraj_2){
			if (*pocetak_1 == *poc_2){
				Mat.resize(Mat.size()+1);
				Mat[Mat.size() - 1].push_back(*pocetak_1);
				Mat[Mat.size() - 1].push_back(0);
				Mat[Mat.size() - 1].push_back(0);
			}
			poc_2++;
		}
		pocetak_1++;
	}
	std::sort(Mat.begin(), Mat.end(), [] (std::vector<decltype(*pocetak_2 + *pocetak_1)> v1, std::vector<decltype(*pocetak_2 + *pocetak_1)> v2){
		if(v1[2] == v2[2]){
			if(v1[0] == v2[0]){
				return v1[1] < v2[1];
			}else return v1[0] < v2[0];
		}else return v1[2] < v2[2];
	});
	
	return Mat;
}


template <typename IterTip1, typename IterTip2, typename NekiTip1, typename NekiTip2> 
auto UvrnutaRazlika(IterTip1 pocetak_1, IterTip1 kraj_1, IterTip2 pocetak_2, IterTip2 kraj_2, NekiTip2 f(NekiTip1)) -> std::vector<std::vector<decltype(*pocetak_2 + *pocetak_1)>>{
	std::vector<std::vector<decltype(*pocetak_2 + *pocetak_1)>> Mat(0);
	auto poc_1 =pocetak_1;
	auto poc_2 =pocetak_2;
	auto kr_1 =kraj_1;
	auto kr_2 =kraj_2;
	bool a(true);
	while(pocetak_1 != kraj_1){
		poc_2=pocetak_2;
		a=true;
		while(poc_2 != kraj_2){
			if(f(*pocetak_1) == f(*poc_2)){
				a=false;
				break;
			}
			poc_2++;
		}
		if(a){
			Mat.resize(Mat.size()+1);
			Mat[Mat.size() - 1].push_back(*pocetak_1);
			Mat[Mat.size() - 1].push_back(f(*pocetak_1));
		}
		pocetak_1++;
	}
	pocetak_1 = poc_1;
	while(pocetak_2 != kraj_2){
		poc_1=pocetak_1;
		a=true;
		while(poc_1 != kraj_1){
			if(f(*pocetak_2) == f(*poc_1)){
				a=false;
				break;
			}
			poc_1++;
		}
		if(a){
			Mat.resize(Mat.size()+1);
			Mat[Mat.size() - 1].push_back(*pocetak_2);
			Mat[Mat.size() - 1].push_back(f(*pocetak_2));
		}
		pocetak_2++;
	}
	
	std::sort(Mat.begin(), Mat.end(), [] (std::vector<decltype(*pocetak_2 + *pocetak_1)> v1, std::vector<decltype(*pocetak_2 + *pocetak_1)> v2){
		if(v1[0] == v2[0]){
			return v1[1] > v2[1];
		}else return v1[0] > v2[0];
		
	});
	
	return Mat;
}
	
template <typename IterTip1, typename IterTip2> 
auto UvrnutaRazlika(IterTip1 pocetak_1, IterTip1 kraj_1, IterTip2 pocetak_2, IterTip2 kraj_2) -> std::vector<std::vector<decltype(*pocetak_2 + *pocetak_1)>>{
	std::vector<std::vector<decltype(*pocetak_2 + *pocetak_1)>> Mat(0);
	auto poc_1 =pocetak_1;
	auto poc_2 =pocetak_2;
	auto kr_1 =kraj_1;
	auto kr_2 =kraj_2;
	bool a(true);
	while(pocetak_1 != kraj_1){
		poc_2=pocetak_2;
		a=true;
		while(poc_2 != kraj_2){
			if(*pocetak_1 == *poc_2){
				a=false;
				break;
			}
			poc_2++;
		}
		if(a){
			Mat.resize(Mat.size()+1);
			Mat[Mat.size() - 1].push_back(*pocetak_1);
			Mat[Mat.size() - 1].push_back(0);
		}
		pocetak_1++;
	}
	pocetak_1 = poc_1;
	while(pocetak_2 != kraj_2){
		poc_1=pocetak_1;
		a=true;
		while(poc_1 != kraj_1){
			if(*pocetak_2 == *poc_1){
				a=false;
				break;
			}
			poc_1++;
		}
		if(a){
			Mat.resize(Mat.size()+1);
			Mat[Mat.size() - 1].push_back(*pocetak_2);
			Mat[Mat.size() - 1].push_back(0);
		}
		pocetak_2++;
	}
	
	std::sort(Mat.begin(), Mat.end(), [] (std::vector<decltype(*pocetak_2 + *pocetak_1)> v1, std::vector<decltype(*pocetak_2 + *pocetak_1)> v2){
		if(v1[0] == v2[0]){
			return v1[1] > v2[1];
		}else return v1[0] > v2[0];
		
	});
	
	return Mat;
}
	

int main ()
{
	std::deque<int> v1, v2;
	int v1_size, v2_size, tmp;
	bool a;
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	std::cin>>v1_size;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	for(int i(0); i<v1_size; i++){
		std::cin>>tmp;
		a=false;
		for(int j(0); j<v1.size(); j++){
			if(tmp == v1[j]){
				a=true;
				break;
			}
		}
		if(a){
			i--;
		}
		else{
			v1.push_back(tmp);
		}
	}
	
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	std::cin>>v2_size;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	for(int i(0); i<v2_size; i++){
		std::cin>>tmp;
		a=false;
		for(int j(0); j<v2.size(); j++){
			if(tmp == v2[j]){
				a=true;
				break;
			}
		}
		if(a){
			i--;
		}
		else{
			v2.push_back(tmp);
		}
	}
	
	std::cout<<"Uvrnuti presjek kontejnera:\n";
	auto mat = UvrnutiPresjek(v1.begin(), v1.end(), v2.begin(), v2.end(), SumaCifara);
	for(auto red : mat){
		for(auto element : red){
			std::cout<<std::setw(6)<<element<<" ";
		}
		std::cout<<"\n";
	}
	std::cout<<"Uvrnuta razlika kontejnera:\n";
	mat = UvrnutaRazlika(v1.begin(), v1.end(), v2.begin(), v2.end(), BrojProstihFaktora);
	for(auto red : mat){
		for(auto element : red){
			std::cout<<std::setw(6)<<element<<" ";
		}
		std::cout<<"\n";
	}
	std::cout<<"Dovidjenja!";
	
	return 0;
}
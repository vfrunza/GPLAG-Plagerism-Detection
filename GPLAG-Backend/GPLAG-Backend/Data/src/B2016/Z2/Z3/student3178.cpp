#include <algorithm>
#include <iostream>
#include <iterator>
#include <type_traits>
#include <deque>
#include <vector>
#include <iomanip>
#include <cmath>

int SumaCifara(long long int broj){
	int pomocna{0};
	int suma{0};
	broj=std::fabs(broj);
	while( broj != 0){
		pomocna=broj%10;
		suma+=pomocna;
		broj=broj/10;
	}
	return suma;
}

int SumaDjelilaca(long long int broj){
	int suma{0};
	broj=std::fabs(broj);
		for(int i{1}; i<=broj; i++){
			if(broj%i == 0) 
			suma += i;
			}

	return suma;
}

bool DaLiJeProst(int x){
	for(int i{2}; i<x; i++){
		if( x%i == 0) return false;}
		return true;
}

int BrojProstihFaktora(long long int broj){
	int br_prostih_fak{0};
	broj=std::fabs(broj);
	for(int i=2; i<=broj; i++){
		if(broj%i == 0){
		   if(DaLiJeProst(i)) br_prostih_fak++;
		   broj /= i;
		   i = 1;}
	}
	return br_prostih_fak;
	}	

bool JeLiSavrsen(int x){
	int suma_djel{0};
	for(int i{1}; i<x; i++){
		if(x%i == 0){
			suma_djel+=i;
			}
	}
return suma_djel == x;	
}

int BrojSavrsenihDjelilaca(long long int broj){
	int broj_savrsenih{0};
broj=std::fabs(broj);
		for(int i{1}; i<=broj; i++){
			if(broj%i == 0) {
			if(JeLiSavrsen(i))  {
			broj_savrsenih++;
			broj /=i;
			i=1;}}
			}
			
	return broj_savrsenih;
	}	
template<typename T1, typename T2>
auto UvrnutiPresjek(T1 poc1, T1 kraj1, T2 poc2, T2 kraj2) -> std::vector<std::vector<decltype(*poc1 + *poc2)>>{
	std::vector<std::vector<decltype(*poc1 + *poc2)>> fr;
	
	while(poc1 != kraj1){
		auto i2(poc2);
		while(i2 != kraj2){
			std::vector<decltype(*poc1 + *poc2)> tmp;
			if(*poc1 == *i2){
				tmp.push_back(*poc1);
				tmp.push_back(0);
				tmp.push_back(0);
			}
			if(tmp.size() > 0)
				fr.push_back(tmp);
			i2++;
		}
		poc1++;
	}
	sort(fr.begin(), fr.end(), [](std::vector<decltype(*poc1 + *poc1)> x, std::vector<decltype(*poc1 + *poc1)> y){
		if(x[2] != y[2]) return x[2] < y[2];
		
	if(x[0] != y[0]) return x[0] < y[0];
	
	if(x[1] != y[1]) return x[1] < y[1];
	return true;
});
return fr;
}	

template<typename T1, typename T2, typename F1, typename F2>
auto UvrnutiPresjek(T1 poc1, T1 kraj1, T2 poc2, T2 kraj2, F2 fun(F1)) -> std::vector<std::vector<decltype(*poc1 + *poc2)>>{
	std::vector<std::vector<decltype(*poc1 + *poc2)>> fr;
	
	while(poc1 != kraj1){
		auto i2(poc2);
		while(i2 != kraj2){
			std::vector<decltype(*poc1 + *poc2)> tmp;
			if(fun(*poc1) == fun(*i2)){
				tmp.push_back(*poc1);
				tmp.push_back(*i2);
				tmp.push_back(fun(*poc1));
			}
			if(tmp.size() > 0)
				fr.push_back(tmp);
			i2++;
		}
		poc1++;
	}
	sort(fr.begin(), fr.end(), [](std::vector<decltype(*poc1 + *poc1)> x, std::vector<decltype(*poc1 + *poc1)> y){
		if(x[2] != y[2]) return x[2] < y[2];
		
	if(x[0] != y[0]) return x[0] < y[0];
	
	if(x[1] != y[1]) return x[1] < y[1];
	return true;
});
return fr;
}

template<typename T1, typename T2>
void ZaUvrnutuRazliku(T1 poc1, const T1& kraj1, const T2& poc2, T2& kraj2, std::vector<std::vector<decltype(*poc1 + *poc2)>>&v){
while(poc1 != kraj1){
		auto i2(poc2);
		bool flag=true;
		while(i2 != kraj2){
			if(*poc1 == *i2){
				flag=false;
				break;
			}
			i2++;
		}
		if(flag){
				std::vector<decltype(*poc1 + *poc2)> tmp{*poc1, 0};
					v.push_back(tmp);
		}
			poc1++;
			}
}			
	
template<typename T1, typename T2>
auto UvrnutaRazlika(T1 poc1, T1 kraj1, T2 poc2, T2 kraj2) -> std::vector<std::vector<decltype(*poc1 + *poc2)>>{
	std::vector<std::vector<decltype(*poc1 + *poc2)>> fr;
	
	ZaUvrnutuRazliku(poc1,kraj1,poc2,kraj2,fr);
	ZaUvrnutuRazliku(poc2,kraj2,poc1,kraj1,fr);
	
	sort(fr.begin(), fr.end(), [](std::vector<decltype(*poc1 + *poc1)> x, std::vector<decltype(*poc1 + *poc1)> y){
		if(x[0] != y[0]) return x[0] > y[0];
return x[1] >= y[1];
});

return fr;
}

	
template<typename T1, typename T2, typename F1, typename F2>
void ZaUvrnutuRazliku(T1 poc1, const T1& kraj1, const T2& poc2, T2& kraj2, F2 fun(F1), std::vector<std::vector<decltype(*poc1 + *poc2)>>&v){

while(poc1 != kraj1){
		auto i2(poc2);
		bool flag=true;
		while(i2 != kraj2){
			if(fun(*poc1) == fun(*i2)){
				flag=false;
				break;
			}
			i2++;
		}
		if(flag){
				std::vector<decltype(*poc1 + *poc2)> tmp{*poc1, fun(*poc1)};
					v.push_back(tmp);
		}
			poc1++;
			}
}
			
	
template<typename T1, typename T2, typename F1, typename F2>
auto UvrnutaRazlika(T1 poc1, T1 kraj1, T2 poc2, T2 kraj2, F2 fun(F1)) -> std::vector<std::vector<decltype(*poc1 + *poc2)>>{
	std::vector<std::vector<decltype(*poc1 + *poc2)>> fr;
	
	ZaUvrnutuRazliku(poc1,kraj1,poc2,kraj2,fun,fr);
	ZaUvrnutuRazliku(poc2,kraj2,poc1,kraj1,fun,fr);
	
	sort(fr.begin(), fr.end(), [](std::vector<decltype(*poc1 + *poc1)> x, std::vector<decltype(*poc1 + *poc1)> y){
		if(x[0] != y[0]) return x[0] > y[0];
return x[1] >= y[1];
});

return fr;
}

/*
template<typename T1, typename T2>
auto UvrnutaRazlika(T1 poc1, T1 kraj1, T2 poc2, T2 kraj2) -> std::vector<std::vector<decltype(*poc1 + *poc2)>>{
	std::vector<std::vector<decltype(*poc1 + *poc2)>> fr;
	
	ZaUvrnutuRazliku(poc1,kraj1,poc2,kraj2,fun,fr);
	ZaUvrnutuRazliku(poc2,kraj2,poc1,kraj1,fun,fr);
	
	sort(fr.begin(), fr.end(), [](std::vector<decltype(*poc1 + *poc1)> x, std::vector<decltype(*poc1 + *poc1)> y){
		if(x[0] != y[0]) return x[0] > y[0];

return x[1] >= y[1];

});
return fr;
}
*/


void Unos(std::deque<int> &d, std::string s){
	int n;
	std::cout<< "Unesite broj elemenata " << s <<" kontejnera: ";
	std::cin >> n;
	std::cout<< "Unesite elemente " << s <<" kontejnera: ";
	while(n>0){
		int element;
		std::cin >> element;
		bool flag = 1;
		for(int i=0; i<d.size(); i++)
			if(d.at(i) == element){
				flag = 0;
				break;
			}
		
		if(flag){
			d.push_back(element);
			n--;
		}	
	}
	
}

int main ()
{
	std::deque<int> dek1;
	std::deque<int> dek2;

	Unos(dek1,"prvog");
	Unos(dek2,"drugog");


		auto it1(std::begin(dek1)); //ili dek1.begin()
		auto it2(std::end(dek1));
		
	    auto it3(std::begin(dek2));
		auto it4(std::end(dek2));


	std::vector<std::vector<int>> temp;
//	std::vector<std::vector<int>> temp_;
std::cout << "Uvrnuti presjek kontejnera:" << std::endl;
/*temp_ = (UvrnutiPresjek(it1,it2,it3,it4));
for( std::vector<int> k : temp_) {
      for (int t : k) std::cout << std::setw(6) << t << " " ;
      std::cout << std::endl;
	}*/
temp = (UvrnutiPresjek(it1,it2,it3,it4,SumaCifara));
for( std::vector<int> k : temp) {
      for (int t : k) std::cout << std::setw(6) << t << " " ;
      std::cout << std::endl;
	}

 std::vector<std::vector<int>> temp1;
// std::vector<std::vector<int>> temp1_;
std::cout << "Uvrnuta razlika kontejnera:" << std::endl;
/*temp1_ = (UvrnutaRazlika(it1,it2,it3,it4));
for( std::vector<int> k1 : temp1_) {
      for (int t1 : k1) std::cout << std::setw(6) << t1 <<" ";
      std::cout << std::endl;
	}*/
temp1 = (UvrnutaRazlika(it1,it2,it3,it4,BrojProstihFaktora));

for( std::vector<int> k1 : temp1) {
      for (int t1 : k1) std::cout << std::setw(6) << t1 <<" ";
      std::cout << std::endl;
	}

std::cout << "Dovidjenja!";

	return 0;
}
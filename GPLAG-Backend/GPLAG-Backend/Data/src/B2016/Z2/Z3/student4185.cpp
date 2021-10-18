/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/


#include <iostream>
#include <vector>
#include <string>
#include <type_traits>
#include <algorithm>
template <typename tip1, typename tip2, typename tip3, typename tip4>

auto UvrnutiPresjek(tip1 poc1, tip1 end1, tip2 poc2, tip2 end2, tip3 f(tip4)) -> std :: vector<std :: vector<typename std :: remove_reference<decltype(*poc1)> :: type>>{

std::vector<std::vector<typename std :: remove_reference<decltype(*poc1)>::type >> novo(10, std::vector<typename std::remove_reference<decltype(*poc1)>::type>(3));
int brojac=0;
tip1 pomocni1=poc1;
while(pomocni1!=end1){
	tip2 pomocni2=poc2;
	while (pomocni2!=end2) {
		if (f(*pomocni1)==f(*pomocni2)) {
			brojac++;	
			pomocni2++;
		}
	}
	pomocni1++;
}
novo.resize(brojac);
int i=0;
while(poc1!=end1){
    tip2 pomoc=poc2;
	while(poc2!=end2){
		if (f(*poc1)==f(*poc2)) {
			novo[i].push_back(*poc1);
			novo[i].push_back(*poc2);
			novo[i].push_back(f(*poc2));
		}
		i++;
		poc2++;
	}
	poc2=pomoc;
	poc1++;
}
std :: sort (novo.begin(),novo.end(),[](std::vector<typename std :: remove_reference<decltype(novo[1][1])>> v1,std::vector<typename std :: remove_reference<decltype(novo[1][1])>> v2 )
{if (v1[3]==v2[3]) {
	if (v1[1]==v2[1]) {
	return v1[2]<v2[2];
	}
	return v1[1]<v1[1];
}
return v1[3]<v2[3];
});

return novo;
}

int suma(int a){
	int sum=0;
	while(a!=0){
	sum = sum+ (a%10);
	a=a/10;
	}
	return sum;
}
int main ()
{
	std::vector<int>vec ;
	std::vector<int>vec2 ;
	std::cout << "Unesite broj elemenata prvog kontejnera: ";
	int n; 
	std :: cin>>n;
	std::cout << "Unesite elemente prvog kontejnera: " ;
	for (int i = 0; i < n; i++) {
		int el;
		std::cin >> el;
		vec.push_back(el);
		}
		int a=n;
	std::cout << "Unesite broj elemenata drugog kontejnera: ";
	std::cin >> n;
	std::cout << "Unesite elemente drugog kontejnera:";
	for(int i=0; i<n; i++){
		int el;
		std::cin >> el;
		vec2.push_back(el);
	}
	std::cout << std::endl;
	
	UvrnutiPresjek(std :: begin(vec),std :: end(vec),std :: begin(vec2),std :: end(vec2),suma);
	return 0;
}







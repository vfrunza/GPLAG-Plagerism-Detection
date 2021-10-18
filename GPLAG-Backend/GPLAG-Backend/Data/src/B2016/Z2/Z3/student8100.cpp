/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>

int SumaDjelilaca(long long int x){
	int suma(0);
	for(long long int i(1); i<=abs(x); i++)
		if(abs(x%i)==0) suma+=i; 
	return suma;
}

bool jelprost(long long int x){
	if(x<=3) return true;
	else if(x%2==0 || x%3==0) return false;
	int i=5;
	while(i*i<=x){
		if(x%i == 0 || x%(i+2) == 0) return false;
		i+=6;
	}
	return true;
}

int BrojProstihFaktora(long long int x){
	int brojac(0);
	auto temp = abs(x);
	for(long long int i(2); i<=abs(x); i++){
		if(temp%i==0)
			while(temp%i==0){
				brojac++;
				temp/=i;
			}
	}
	return brojac;
}

int BrojSavrsenihDjelilaca(long long int x){
	int brojac(0);
	for(long long int i(2); i<=x; i++){
		if(abs(x%i)==0){
			long long int suma(0);
			for(int j(1); j<i; j++)
				if(abs(i%j)==0) suma+=j;
			if(suma==i) brojac++;
		}
	}
	return brojac;
}

template <typename tip1, typename tip2>
auto UvrnutiPresjek(tip1 pocetak1, tip1 kraj1, tip2 pocetak2, tip2 kraj2) -> std::vector<std::vector<decltype(*pocetak1+*pocetak1)>> {
	int brojac(0);
	for(auto i(pocetak1); i!=kraj1; i++){
		for(auto j(pocetak2); j!=kraj2; j++){
			if(*i==*j) brojac++;
		}
	}
	std::vector<std::vector<decltype(*pocetak1+*pocetak1)>> matrica;
	matrica.resize(brojac);
	int brojac2(0);
	for(auto i(pocetak1); i!=kraj1; i++){
		for(auto j(pocetak2); j!=kraj2; j++){
			if(*i==*j){
				matrica[brojac2].push_back(*i);
				matrica[brojac2].push_back(0);
				matrica[brojac2].push_back(0);
				brojac2++;
			}
		}
	}
	std::sort(matrica.begin(), matrica.end(), [](const std::vector<decltype(*pocetak1+*pocetak1)> &a, const std::vector<decltype(*pocetak1+*pocetak1)> &b){
		if(a[2]==b[2]){
			if(a[0]==b[0]) return a[1]<b[1];
			return a[0]<b[0];
		}
		return  (a[2]<b[2]);});
	return matrica;
}

template <typename tip1, typename tip2, typename tip3>
auto UvrnutiPresjek(tip1 pocetak1, tip1 kraj1, tip2 pocetak2, tip2 kraj2, tip3 f) -> std::vector<std::vector<decltype(*pocetak1+*pocetak1)>> {
	int brojac(0);
	for(auto i(pocetak1); i!=kraj1; i++){
		for(auto j(pocetak2); j!=kraj2; j++){
			if(f(*i)==f(*j)) brojac++;
		}
	}
	std::vector<std::vector<decltype(*pocetak1+*pocetak1)>> matrica;
	matrica.resize(brojac);
	int brojac2(0);
	for(auto i(pocetak1); i!=kraj1; i++){
		for(auto j(pocetak2); j!=kraj2; j++){
			if(f(*i)==f(*j)){
				matrica[brojac2].push_back(*i);
				matrica[brojac2].push_back(*j);
				matrica[brojac2].push_back(f(*i));
				brojac2++;
			}
		}
	}
	std::sort(matrica.begin(), matrica.end(), [](const std::vector<decltype(*pocetak1+*pocetak1)> &a, const std::vector<decltype(*pocetak1+*pocetak1)> &b){
		if(a[2]==b[2]){
			if(a[0]==b[0]) return a[1]<b[1];
			return a[0]<b[0];
		}
		return  (a[2]<b[2]);});
	return matrica;
}

template <typename tip1, typename tip2>
auto UvrnutaRazlika(tip1 pocetak1, tip1 kraj1, tip2 pocetak2, tip2 kraj2) -> std::vector<std::vector<decltype(*pocetak1+*pocetak1)>>{
	int brojac(0);
	std::vector<decltype(*pocetak1+*pocetak1)> pom;
	tip1 pocetak1_pomocni1(pocetak1);
	tip2 pocetak2_pomocni1(pocetak2);
	bool valja(true);
	for(auto i(pocetak1); i != kraj1; i++){
		for(auto j(pocetak2); j != kraj2; j++)
			if(*i == *j) valja = false;
		if(valja) pom.push_back(*i);
		valja = true;
	}
	for(auto i(pocetak2); i != kraj2; i++){
		for(auto j(pocetak1); j != kraj1; j++)
			if(*i == *j) valja = false;
		if(valja) pom.push_back(*i);
		valja = true;
	}
	std::vector<std::vector<decltype(*pocetak1+*pocetak1)>> matrica;
	pocetak1=pocetak1_pomocni1;
	pocetak2=pocetak2_pomocni1;
	matrica.resize(int(pom.size()));
	std::sort(pom.begin(), pom.end());
	for(auto i(pom.begin()); i!=pom.end(); i++)
		if(std::count(pocetak1, kraj1, *i) != 0){
			matrica[brojac].push_back(*i);
			matrica[brojac].push_back(0);
			brojac++;
		}
	for(auto i(pom.begin()); i!=pom.end(); i++)
		if(std::count(pocetak2, kraj2, *i) != 0){
			matrica[brojac].push_back(*i);
			matrica[brojac].push_back(0);
			brojac++;
		}
	std::sort(matrica.begin(), matrica.end(), [](const std::vector<decltype(*pocetak1+*pocetak1)> &a, const std::vector<decltype(*pocetak1+*pocetak1)> &b){return a[0]>b[0];});
	return matrica;
}

template <typename tip1, typename tip2, typename tip3>
auto UvrnutaRazlika(tip1 pocetak1, tip1 kraj1, tip2 pocetak2, tip2 kraj2, tip3 f) -> std::vector<std::vector<decltype(*pocetak1+*pocetak1)>>{
	int brojac(0);
	std::vector<decltype(*pocetak1+*pocetak1)> pom;
	tip1 pocetak1_pomocni1(pocetak1);
	tip2 pocetak2_pomocni1(pocetak2);
	bool valja(true);
	for(auto i(pocetak1); i != kraj1; i++){
		for(auto j(pocetak2); j != kraj2; j++)
			if(f(*i) == f(*j)) valja = false;
		if(valja) pom.push_back(*i);
		valja = true;
	}
	for(auto i(pocetak2); i != kraj2; i++){
		for(auto j(pocetak1); j != kraj1; j++)
			if(f(*i) == f(*j)) valja = false;
		if(valja) pom.push_back(*i);
		valja = true;
	}
	std::vector<std::vector<decltype(*pocetak1+*pocetak1)>> matrica;
	pocetak1=pocetak1_pomocni1;
	pocetak2=pocetak2_pomocni1;
	matrica.resize(int(pom.size()));
	std::sort(pom.begin(), pom.end());
	for(auto i(pom.begin()); i!=pom.end(); i++){
		if(std::count(pocetak1, kraj1, *i) != 0){
			matrica[brojac].push_back(*i);
			matrica[brojac].push_back(f(*i));
			brojac++;
		}
	}
	for(auto i(pom.begin()); i!=pom.end(); i++){
		if(std::count(pocetak2, kraj2, *i) != 0){
			matrica[brojac].push_back(*i);
			matrica[brojac].push_back(f(*i));
			brojac++;
		}
	}
	std::sort(matrica.begin(), matrica.end(), [](const std::vector<decltype(*pocetak1+*pocetak1)> &a, const std::vector<decltype(*pocetak1+*pocetak1)> &b){return a[0]>b[0];});
	return matrica;
}


int main (){
	std::vector<int> niz1;
	std::vector<int> niz2;
	int n1, n2;
	bool valja(true);
	std::cout << "Unesite broj elemenata prvog kontejnera: ";
	std::cin >> n1;
	std::cout << "Unesite elemente prvog kontejnera: ";
	for(int i(0); i<n1; i++){
		int temp;
		std::cin >> temp;
		for(int j(0); j<int(niz1.size()); j++)
			if(niz1[j]==temp){
				valja=false;
				i--;
			}
		if(valja) niz1.push_back(temp);
		valja=true;
	}
	std::cout << "Unesite broj elemenata drugog kontejnera: ";
	std::cin >> n2;
	std::cout << "Unesite elemente drugog kontejnera: ";
	for(int i(0); i<n2; i++){
		int temp;
		std::cin >> temp;
		for(int j(0); j<int(niz2.size()); j++)
			if(niz2[j]==temp){ 
				valja=false;
				i--;
			}
		if(valja) niz2.push_back(temp);
		valja=true;
	}
	std::vector<std::vector<int>> mat1 = UvrnutiPresjek(niz1.begin(), niz1.end(), niz2.begin(), niz2.end(), [](int x){int suma(0); do{suma+=abs(x%10); x/=10;}while(x!=0); return suma;});
	auto mat2 = UvrnutaRazlika(niz1.begin(), niz1.end(), niz2.begin(), niz2.end(), BrojProstihFaktora);
	std::cout << "Uvrnuti presjek kontejnera:" << std::endl;
	for(int i(0); i<mat1.size(); i++){
		for(int j(0); j<3; j++)
			std::cout << std::setw(6) << mat1[i][j] << " ";
		std::cout << std::endl;
	}
	std::cout << "Uvrnuta razlika kontejnera:" << std::endl;
	for(int i(0); i<mat2.size(); i++){
		for(int j(0); j<2; j++)
			std::cout << std::setw(6) << mat2[i][j] << " ";
		std::cout << std::endl;
	}
	std::cout << "Dovidjenja!";
	return 0;
}
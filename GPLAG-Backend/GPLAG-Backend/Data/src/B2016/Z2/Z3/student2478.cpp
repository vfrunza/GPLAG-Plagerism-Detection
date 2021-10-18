#include <iostream>
#include <deque> 
#include <algorithm>
#include <vector>
#include <iostream>
#include <iomanip>


template <typename NekiTip>
int Suma(NekiTip x){
	
	int cifra, suma(0);
	while(x != 0){
		cifra = x % 10;
		suma +=cifra;
		x /= 10;
	}
	return suma;
}

template <typename NekiTip>
bool Provjeri(NekiTip vektor, int broj){
	
	for(int i(0); i < vektor.size(); i++){
		if(vektor[i] == broj)return false;
	}
	return true;
}

int SumaDjelilaca(long long int broj){
	
	int suma(0);
	for(int i(1); i <= broj; i++){
		if(broj % i == 0)suma+=i;
	}
	return suma;
}

bool Prost_je(long long int broj){
	
	for(int i(2); i <= broj; i++){
		if(broj % i == 0 && broj != i)return false;
	}
	return true;
}
int BrojProstihFaktora(long long int broj){
	
	int brojac(0);
	for(int i(2); i <= broj; i++){
		if((broj % i == 0) && Prost_je(i)){
			brojac++;
			broj /= i;
			i--;
		}
		if(broj == 0)break;
		}
	return brojac;	
	}
	
bool Savsen(long long int broj){
	
	int suma(1);
	for(int i(2); i < broj; i++){
		if(broj % i == 0)suma+=i;
	}
	if(suma == broj)return true;
	return false;
}

int BrojSavrsenihDjelilaca(long long int broj){
	
	int brojac(0);
	
	for(int i(2); i <= broj; i++){
		if((broj % i == 0) && Savsen(i))brojac++;
	}
	return brojac;
	
}


template <typename Tip1, typename Tip2>
auto UvrnutiPresjek(Tip1 poc1, Tip1 kraj1, Tip2 poc2, Tip2 kraj2)->typename std::vector<std::vector<typename std::remove_reference<decltype(*poc1)>::type>>{
typedef typename std::remove_reference<decltype(*poc1)>::type NoviTip;
std::vector<std::vector<NoviTip>> Matrica;
int brojac(0);
while (poc1 != kraj1){
	poc2 -= brojac;
	brojac=0;
	while(poc2 != kraj2){
		if(*poc1 == *poc2){
			Matrica.push_back({*poc1, 0, 0});
		}
		poc2++;
		brojac++;
	}
	poc1++;
}

std::sort(Matrica.begin(), Matrica.end(), [](const std::vector<decltype(*poc1 + *poc1)> &x, const std::vector<decltype(*poc1 + *poc1)> &y){
	if(x[0] == y[0])return false;
	return x[0] < y[0];
});

return Matrica;	
}
template <typename Tip1, typename Tip2, typename Tip3>
auto UvrnutiPresjek(Tip1 poc1, Tip1 kraj1, Tip2 poc2, Tip2 kraj2, Tip3 fun)->typename std::vector<std::vector<typename std::remove_reference<decltype(*poc1)>::type>>{
typedef typename std::remove_reference<decltype(*poc1)>::type NoviTip;
std::vector<std::vector<NoviTip>> Matrica;
int brojac(0);
while (poc1 != kraj1){
	poc2 -= brojac;
	brojac=0;
	while(poc2 != kraj2){
		if(fun(*poc1) == fun(*poc2)){
			Matrica.push_back({*poc1, *poc2, fun(*poc1)});
		}
		poc2++;
		brojac++;
	}
	poc1++;
}

std::sort(Matrica.begin(), Matrica.end(), [](const std::vector<decltype(*poc1 + *poc1)> &x, const std::vector<decltype(*poc1 + *poc1)> &y){
	if(x[2] == y[2]){
		if(x[0] == y[0]){
			if(x[1] == y[1])return false;
			else return x[1] < y[1];
		}
		return x[0] < y[0];
	}
	return x[2] < y[2];
});

return Matrica;	
}

template <typename Tip1, typename Tip2>
auto UvrnutaRazlika(Tip1 poc1, Tip1 kraj1, Tip2 poc2, Tip2 kraj2)-> typename std::vector<std::vector<typename std::remove_reference<decltype(*poc1)>::type>>{
	
	std::vector<std::vector<typename std::remove_reference<decltype(*poc1)>::type>> Matrica;
	int velicinap(kraj1 - poc1);
	int velicinad(kraj2 - poc2);
	int PozitivnaNula(0);
	bool ubaci(true);
	for(int i(0); i < velicinap; i++){
		ubaci = true;
		for(int j(0); j < velicinad; j++){
			if(poc1[i] == poc2[j]){
				ubaci = false;
				break;
			}
			
		}
		if(ubaci) Matrica.push_back({poc1[i], PozitivnaNula});
	}
	
	for(int i(0); i < velicinad; i++){
		ubaci = true;
		for(int j(0); j < velicinap; j++){
			if(poc2[i] == poc1[j]){
				ubaci = false;
				break;
			}
		}
		if(ubaci) Matrica.push_back({poc2[i], PozitivnaNula});
	}
	
	std::sort(Matrica.begin(), Matrica.end(), [](const std::vector<decltype(*poc1 + *poc1)> &x, const std::vector<decltype(*poc1 + *poc1)> &y){
			if(x[0] == y[0])return false;
		
		return x[0] > y[0];
	});
	
	return Matrica;
}

template <typename Tip1, typename Tip2, typename Tip3>
auto UvrnutaRazlika(Tip1 poc1, Tip1 kraj1, Tip2 poc2, Tip2 kraj2, Tip3 fun)-> typename std::vector<std::vector<typename std::remove_reference<decltype(*poc1)>::type>>{
	
	std::vector<std::vector<typename std::remove_reference<decltype(*poc1)>::type>> Matrica;
	int velicinap(kraj1 - poc1);
	int velicinad(kraj2 - poc2);
	bool ubaci(true);
	for(int i(0); i < velicinap; i++){
		ubaci = true;
		for(int j(0); j < velicinad; j++){
			if((fun(poc1[i]) == fun(poc2[j]))){
				ubaci = false;
				break;
			}
			
		}
		if(ubaci) Matrica.push_back({poc1[i], fun(poc1[i])});
	}
	
	for(int i(0); i < velicinad; i++){
		ubaci = true;
		for(int j(0); j < velicinap; j++){
			if((fun(poc2[i]) == fun(poc1[j]))){
				ubaci = false;
				break;
			}
		}
		if(ubaci) Matrica.push_back({poc2[i], fun(poc2[i])});
	}
	
	std::sort(Matrica.begin(), Matrica.end(), [](const std::vector<decltype(*poc1 + *poc1)> &x, const std::vector<decltype(*poc1 + *poc1)> &y){
			if(x[0] == y[0]){
				if(x[1] == y[1])
				return false;
				else return  x[1] > y[1];
		}
		
		return x[0] > y[0];
	});
	
	return Matrica;
}

int main (){
	
	std::cout << "Unesite broj elemenata prvog kontejnera: ";
	int broj_p;
	std::cin >> broj_p;
	
	std::cout << "Unesite elemente prvog kontejnera: ";
	int element;
	std::deque<int> prvi;
	for(int i(0); i < broj_p; i++){
		std::cin >> element;
		if(Provjeri(prvi, element))
		prvi.push_back(element);
		else i--;
	}
	
	std::cout << "Unesite broj elemenata drugog kontejnera: ";
	int broj_d;
	std::cin >> broj_d;
	
	std::deque<int> drugi;
	std::cout << "Unesite elemente drugog kontejnera: ";
	for(int i(0); i < broj_d; i++){
		std::cin >> element;
		if(Provjeri(drugi, element))
		drugi.push_back(element);
		else i--;
	}
	std::cout << "Uvrnuti presjek kontejnera:" << std::endl;
	auto Matrica(UvrnutiPresjek(prvi.begin(), prvi.end(), drugi.begin(), drugi.end(),Suma<long long>));
	
	for(int i(0); i < Matrica.size(); i++){
		for(int j(0); j < Matrica[i].size(); j++){
			std::cout << std::setw(6) << Matrica[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "Uvrnuta razlika kontejnera:" << std::endl;
	
	auto Matrica2(UvrnutaRazlika(prvi.begin(), prvi.end(), drugi.begin(), drugi.end(), BrojProstihFaktora));
	
	for(int i(0); i < Matrica2.size(); i++){
		for(int j(0); j < Matrica2[i].size(); j++){
			std::cout << std::setw(6) << Matrica2[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "Dovidjenja!";
	return 0;
}
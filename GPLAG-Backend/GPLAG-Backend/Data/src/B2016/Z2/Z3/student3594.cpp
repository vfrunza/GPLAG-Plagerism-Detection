#include <iostream>
#include <deque>
#include <iomanip>
#include <vector>
#include <algorithm>

int SumaDjelilaca (long long int x){
	int suma(0);
	x = abs(x);
	for(int i=1; i<=x; i++){
		if(x%i == 0)
			suma += i;
	}
	return suma;
}

int SumaCifara (long long int x){
	int suma(0);
	int temp;
	while(x != 0){
		temp = x % 10;
		suma += temp;
		x = x / 10;
	}
	return suma;
}

bool Prost(int x){
	
	for(int i=2; i<x; i++){
		if(x % i == 0) return false;
	}
	return true;
}

int BrojProstihFaktora (long long int x){
	int suma(0);
	
	
	for(int i=2; i<=x; i++){
		while(x%i == 0){
			if(Prost(i)){
				suma++;
				x /= i;
			}
		}
	}
	return suma;
}

int BrojSavrsenihDjelilaca(long long int x){
	int brojac(0), suma_djelilaca(0), djelilac;
	bool savrsen(false);
	
	for(int i=2; i <= x; i++){
		if(x % i == 0){
			savrsen = false;
			djelilac = i;
			suma_djelilaca = 0;
			for(int j=1; j<djelilac; j++){
				if(djelilac%j == 0) suma_djelilaca+=j;
			}
			if(djelilac == suma_djelilaca) savrsen = true;
			if(savrsen == true) brojac++;
		}
	}
	return brojac;
}

template <typename tip1, typename tip2, typename tip3, typename tip4>
auto UvrnutiPresjek(tip1 IterTip1, tip1 IterTip2, tip2 IterTip3, tip2 IterTip4, tip3 f(tip4)) -> std::vector<std::vector<decltype(*IterTip1 + 0)>> {
	
	std::vector<decltype(*IterTip1 + 0)> temp1, temp2, temp3;
	std::vector<std::vector<decltype(*IterTip1 + 0)>> rez;
	
	while(IterTip1 != IterTip2){
		temp1.push_back(*IterTip1);
		IterTip1++;
	}
	
	while(IterTip3 != IterTip4){
		temp2.push_back(*IterTip3);
		IterTip3++;
	}
	
	for(int i=0; i<temp1.size(); i++){
		for(int j=0; j<temp2.size(); j++){
			if(f(temp1[i]) == f(temp2[j])){
				temp3.push_back(temp1[i]);
				temp3.push_back(temp2[j]);
				temp3.push_back(f(temp1[i]));
				rez.push_back(temp3);
				temp3.clear();
			}
		}
	}
	
	std::sort(rez.begin(), rez.end(), [] (std::vector<decltype(*IterTip1+0)> vek1, std::vector<decltype(*IterTip1+0)> vek2) {
		
		if(vek1[2] == vek2[2]){
			if(vek1[0] == vek2[0]){
				return vek1[1] < vek2[1];
			}
			else return vek1[0] < vek2[0];
		}
		else return vek1[2] < vek2[2];
	});
	
	return rez;
}

template <typename tip1, typename tip2>
auto UvrnutiPresjek(tip1 IterTip1, tip1 IterTip2, tip2 IterTip3, tip2 IterTip4) -> std::vector<std::vector<decltype(*IterTip1 + 0)>> {
	
	std::vector<decltype(*IterTip1 + 0)> temp1, temp2, temp3;
	std::vector<std::vector<decltype(*IterTip1 + 0)>> rez;
	
	while(IterTip1 != IterTip2){
		temp1.push_back(*IterTip1);
		IterTip1++;
	}
	
	while(IterTip3 != IterTip4){
		temp2.push_back(*IterTip3);
		IterTip3++;
	}
	
	for(int i=0; i<temp1.size(); i++){
		for(int j=0; j<temp2.size(); j++){
			if(temp1[i] == temp2[j]){
				temp3.push_back(temp1[i]);
				temp3.push_back(0);
				temp3.push_back(0);
				rez.push_back(temp3);
				temp3.clear();
			}
		}
	}
	
	std::sort(rez.begin(), rez.end(), [] (std::vector<decltype(*IterTip1+0)> vek1, std::vector<decltype(*IterTip1+0)> vek2) {
		
		if(vek1[2] == vek2[2]){
			if(vek1[0] == vek2[0]){
				return vek1[1] < vek2[1];
			}
			else return vek1[0] < vek2[0];
		}
		else return vek1[2] < vek2[2];
	});
	
	return rez;
}


template <typename tip1, typename tip2, typename tip3, typename tip4>
auto UvrnutaRazlika(tip1 IterTip1, tip1 IterTip2, tip2 IterTip3, tip2 IterTip4, tip3 f(tip4)) -> std::vector<std::vector<decltype(*IterTip1 + 0)>>{
	
	std::vector<decltype(*IterTip1 + 0)> temp1, temp2, temp3;
	std::vector<std::vector<decltype(*IterTip1 + 0)>> rez;
	
	while(IterTip1 != IterTip2){
		temp1.push_back(*IterTip1);
		IterTip1++;
	}
	
	while(IterTip3 != IterTip4){
		temp2.push_back(*IterTip3);
		IterTip3++;
	}
	
	bool razlika = true;
	
	for(int i=0; i<temp1.size(); i++){
		razlika = true;
		for(int j=0; j<temp2.size(); j++){
			if(f(temp1[i]) == f(temp2[j])){
				razlika = false;
				break;
			}
		}
		if(razlika){
		temp3.push_back(temp1[i]);
		temp3.push_back(f(temp1[i]));
		rez.push_back(temp3);
		temp3.clear();
		}
	}
	
	for(int i=0; i<temp2.size(); i++){
		razlika = true;
		for(int j=0; j<temp1.size(); j++){
			if(f(temp2[i]) == f(temp1[j])){
				razlika = false;
				break;
			}
		}
		if(razlika){
		temp3.push_back(temp2[i]);
		temp3.push_back(f(temp2[i]));
		rez.push_back(temp3);
		temp3.clear();
		}
	}
	
	
	std::sort(rez.begin(), rez.end(), [] (std::vector<decltype(*IterTip1+0)> vek1, std::vector<decltype(*IterTip1+0)> vek2){
		if(vek1[0] == vek2[0]){
			return vek1[1] > vek2[1];
		} 
		else return vek1[0] > vek2[0];
	});
	
	return rez;
	
}

template <typename tip1, typename tip2>
auto UvrnutaRazlika(tip1 IterTip1, tip1 IterTip2, tip2 IterTip3, tip2 IterTip4) -> std::vector<std::vector<decltype(*IterTip1 + 0)>>{
	
	std::vector<decltype(*IterTip1 + 0)> temp1, temp2, temp3;
	std::vector<std::vector<decltype(*IterTip1 + 0)>> rez;
	
	while(IterTip1 != IterTip2){
		temp1.push_back(*IterTip1);
		IterTip1++;
	}
	
	while(IterTip3 != IterTip4){
		temp2.push_back(*IterTip3);
		IterTip3++;
	}
	
	bool razlika = true;
	for(int i=0; i<temp1.size(); i++){
		razlika = true;
		for(int j=0; j<temp2.size(); j++){
			if(temp1[i] == temp2[j]){
				razlika = false;
				break;
			}
		}
		
		if(razlika){
		temp3.push_back(temp1[i]);
		temp3.push_back(0);
		rez.push_back(temp3);
		temp3.clear();
		}
	}
	
	for(int i=0; i<temp2.size(); i++){
		razlika = true;
		for(int j=0; j<temp1.size(); j++){
			if(temp2[i] == temp1[j]){
				razlika = false;
				break;
			}
		}
		
		if(razlika){
		temp3.push_back(temp2[i]);
		temp3.push_back(0);
		rez.push_back(temp3);
		temp3.clear();
		}
	}
	
	std::sort(rez.begin(), rez.end(), [] (std::vector<decltype(*IterTip1+0)> vek1, std::vector<decltype(*IterTip1+0)> vek2){
		if(vek1[0] == vek2[0]){
			return vek1[1] > vek2[1];
		} 
		else return vek1[0] > vek2[0];
	});
	
	return rez;
	
}


bool ImaLiGa(std::deque<int> dek, int x){
	
	bool temp = false;
	
	for(int i=0; i<dek.size(); i++){
		if(x == dek[i])
			temp = true;
	}
	return temp;
}

int main (){	

	std::cout << "Unesite broj elemenata prvog kontejnera: ";
	int n1;
	std::cin >> n1;
	std::cout << "Unesite elemente prvog kontejnera: ";
	int element1;
	std::deque<int> prvi;
	
	for(int i=0; i<n1; i++){
		std::cin >> element1;
		if(ImaLiGa(prvi, element1) == true)
			i--;
		else prvi.push_back(element1);;
	}
	
	std::cout << "Unesite broj elemenata drugog kontejnera: ";
	int n2;
	std::cin >> n2;
	std::cout << "Unesite elemente drugog kontejnera: ";
	int element2;
	
	std::deque<int> drugi;
	for(int i=0; i<n2; i++){
		std::cin >> element2;
		if(ImaLiGa(drugi, element2) == true)
			i--;
		else drugi.push_back(element2);;
	}
	
	std::cout << "Uvrnuti presjek kontejnera: " << std::endl;
	std::vector<std::vector<int>> mat1;
	mat1 = UvrnutiPresjek(prvi.begin(), prvi.end(), drugi.begin(), drugi.end(), SumaCifara);
	
	for(int i=0; i<mat1.size(); i++){
		for(int j=0; j<mat1[i].size(); j++){
			std::cout << std::setw(6) << mat1[i][j] << " ";
		}
		std::cout << std::endl;
	}
	
	
	std::cout << "Uvrnuta razlika kontejnera: " << std::endl;
	std::vector<std::vector<int>> mat2;
	mat2 = UvrnutaRazlika(prvi.begin(), prvi.end(), drugi.begin(), drugi.end(), BrojProstihFaktora);
	
	for(int i=0; i<mat2.size(); i++){
		for(int j=0; j<mat2[i].size(); j++){
			std::cout << std::setw(6) << mat2[i][j] << " ";
		}
		std::cout << std::endl;
	}
	
	std::cout << "Dovidjenja!";
	
	
	
	return 0;
}
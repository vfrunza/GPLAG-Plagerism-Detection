#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using std::vector;

template <typename iter1, typename iter2, typename iter3, typename type1, typename type2>
void SortirajPodrucjeVrijednosti(iter1 b11, iter1 b12, iter2 b2, iter3 b3, type2 f(type1, type1), bool crit(type1, type1)){
	//Velicina container-a
	int size = b12 - b11;
	
	//Sortiraj 1. block
	sort(b11, b12, crit);
	//Sortiraj 2. block
	sort(b2, b2+size, crit);
	
	for(int i = 0; i < size; i++){
		// std::cout << *(b11+i) << " - " << *(b2+i) << std::endl;
		iter3 it3 = std::find(b3, b3+size, f(*(b11+i), *(b2+i)) );
		if(it3 == b3+size)
			throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
		
		//Nadjen broj, zamijeni vrijednosti iter/pok
		std::swap(*(b3+i), *it3);
	}
}

int Func(int x, int y){
	return -2 * x + y;
}

bool ProstBroj(int n){
	//Nula, negativni?
	for(int i = 2; i <= std::sqrt(n); i++){
		if(n % i == 0)
			return false;
	}
	
	return true;
}

int BrojProstihFaktora(int n){
	if(n < 2) return 0;
	
	int pFakt = 0;
	for(int i = 2; i <= n; i++){
		if(n % i == 0){
			if(ProstBroj(i))
				pFakt++;
			n /= i;
			i--;
		}
	}
	
	return pFakt;
}

bool SortCrit(int a, int b){
	int pFakt1 = BrojProstihFaktora(a);
	int pFakt2 = BrojProstihFaktora(b);
	
	if(pFakt1 == pFakt2)
		return a >= b;
	
	return pFakt1 > pFakt2;
}

void UnesiElemente(vector<int> &vec, int n){
	int temp;

	for(int i = 0; i < n; i++){
		std::cin >> temp;
		bool found = false;
		for(int j = 0; j < i; j++){
			if(temp == vec[j]){
				found = true;
				break;
			}
		}
		if(!found)
			vec.push_back(temp);
		else
			i--;
	}
}

int main () {
	int n;
	vector<int> s1, s2, s3;
	
	std::cout << "Unesite broj elemenata: ";
	std::cin >> n;
	
	std::cout << "Unesite elemente prvog vektora: ";
	UnesiElemente(s1, n);
	std::cout << "Unesite elemente drugog vektora: ";
	UnesiElemente(s2, n);
	std::cout << "Unesite elemente treceg vektora: ";
	UnesiElemente(s3, n);
	
	std::cout << std::endl;
	
	//Glavni poziv
	try{
		SortirajPodrucjeVrijednosti(s1.begin(), s1.end(), s2.begin(), s3.begin(), Func, SortCrit);
	}catch(std::logic_error err){
		std::cout << "Izuzetak: " << err.what();
		return 0;
	}
	
	std::cout << "Nakon sortiranja podrucja vrijednosti imamo sljedece trojke:\n";
	for(int i = 0; i < n; i++)
		std::cout << "f(" << s1[i] << ", " << s2[i] << ") = " << s3[i] << std::endl;
	
	return 0;
}
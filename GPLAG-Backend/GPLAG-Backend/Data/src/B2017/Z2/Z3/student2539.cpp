#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
int **AlocirajFragmentirano(const std::vector<T> &v, int &koliko_puta){
	for(auto x : v) if(x <= 0) throw std::domain_error("Neispravan vektor!");
	bool periodican{true},produzi{false},izadji{false};
	int period{0},broj{1},dodaj{0},indeks{0};
	for(int i = 1; i < v.size(); i++){
		if(v.at(i) == v.at(0)){
			for(;;){
				if(izadji) break;
				for(int j = 0; j < i; j++){
					if(broj*i+j >= v.size()) {
						izadji = true;
						broj--;
						break;
					}
					if(v.at(j) != v.at(broj*i+j)){
						periodican = false;
						break;
					}
				}
				broj++;
			}
			if(periodican) {
				period = i;
				break;
			}
		}
	}
	if((period * broj) - v.size() != 0){
		dodaj = period - (v.size() - (period * broj));
	}
	if(dodaj != 0) produzi = true;
	int **pok(new int*[period*(broj+produzi)]);
	for(int i = 0; i < period*broj; i++){
		pok[i] = new int[v.at(i)];
	}
	if(produzi){
		for(int i = 0; i < period; i++){
			pok[i + period * broj] = new int[v.at(i)];
		}	
	}
	int br{0};
	for(int i = 0; i < period*(broj+produzi); i++){
		for(int j = 0; j < v.at(br); j++){
			pok[i][j] = v.at(br) - j;
		}
		br++;
		if(br >= period) br = 0;
		std::cout << std::endl;
	}
	br = 0;
	for(int i = 0; i < period*(broj+produzi); i++){
		for(int j = 0; j < v.at(br); j++){
			std::cout << pok[i][j] << " ";
		}
		br++;
		if(br >= period) br = 0;
		std::cout << std::endl;
	}
}

int main (){
	std::vector<int> v{1,2,3,4,1,2,3,4,1,2};
	int a{5};
	AlocirajFragmentirano(v,a);
}
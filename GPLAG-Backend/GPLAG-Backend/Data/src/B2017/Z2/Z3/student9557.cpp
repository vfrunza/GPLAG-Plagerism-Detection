/*B 2017/2018, Zadaća 2, Zadatak 3

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <new>
#include <vector>
#include <algorithm>
/*
template<typename TipEl>
	void UnistiMatricu(TipEl **mat, int broj_redova){
		if(!mat) return;
		for(int i=0; i<broj_redova; i++){
			delete[] mat.at(i);
		}
		delete[] mat;
	}

template <typename TipEl>
	TipEl **StvoriMatricu(int broj_redova, int broj_kolona){
		TipEl **mat(new TipEl*[broj_redova]{});
		try {
			for(int i=0; i<broj_redova; i++){
				mat[i]=new TipEl[broj_kolona];
			}
		}
		catch (...) {
			UnistiMatricu(mat, broj_redova);
			throw;
		}
		return mat;
	}
*/
template<typename tip>
bool DaLiJePeriodican(const std::vector<tip>&v, int T)
{
	if(T<1 || T>=v.size()) return false;
	for(int i=0; i<v.size()-T; i++) {
		if((v[i]-v[i+T])!=0) return false;
	}
	return true;
}
/*
template<typename tip>
int OsnovniPeriod(const std::vector<tip>&v){
	for(int i=1; i<v.size(); i++){
		if(DaLiJePeriodican(v, i)) return i;
	}
	return 0;
}
*/
template <typename tip>
tip *AlocirajFragmentirano(std::vector<tip> &v, int &koliko_puta) //koliko puta
{
	int period;
	for(int i=0; i<v.size(); i++) {
		if(DaLiJePeriodican(v, i)) period=i;
	}
	int k=0;
	int vel1;
	while((v.size()+k)%3!=0) {
		vel1=v.size()+k;
		k++;
	}
	vel1++;
	v.resize(vel1);
	for(int i=v.size()-1; i<vel1; i++) {
		int dodaj=i%3+1;
		v.push_back(v[dodaj]);
	}
	int brojac_perioda=0;
	for(int i=0; i<v.size(); i++) {
		if(v[i]=v[0]) brojac_perioda++;
	}
	koliko_puta=brojac_perioda;

	int brojac_uspjelihal=0;
	tip **mat=nullptr;
	try {
		mat=new tip*[v.size()];
		for(int i=0; i<v.size(); i++) {
			mat[i]=new tip[v[i]];
			brojac_uspjelihal++;
		}
		for(int i=0; i<mat.size(); i++) {
			for(int j=0; j<mat[i].size(); j++) {
				auto najveci=std::max_element(mat, mat+mat[i].size());
				if(j==mat[i].size()-1) mat[i][j]=*najveci;
				else mat[i][j]=j;
			}
		}
		return mat[0];
		for(int i=0; i<mat.size(); i++) {
			delete[] mat[i];
			delete[] mat;
		}
	} catch(...) {
		for(int i=0; i<brojac_uspjelihal; i++) {
			delete[] mat[i];
			delete[] mat;
		}
	}
}
int main ()
{
	int n;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	std::vector<int> v(n);
	std::cout << "Unesite elemente vektora: ";
	int element;
	int i=0;
	while(v.size()!=n){
		std::cin >> element;
		v[i]=element;
		i++;
	}
	int odaberi;
	std::cout << "Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
	std::cin >> odaberi;
	
	std::cout << "Dinamicki alocirana matrica: " << std::endl;
	int koliko_puta;
	int *mat=AlocirajFragmentirano(v, koliko_puta);
	for(int i=0; i<koliko_puta; i++){
			std::cout << mat[i] << " ";
		}
		std::cout << std::endl;

	return 0;
}
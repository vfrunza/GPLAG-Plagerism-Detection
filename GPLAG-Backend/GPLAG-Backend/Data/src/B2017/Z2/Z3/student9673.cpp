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
#include <stdexcept>
#include <vector>
#include <iomanip>


template <typename tip>
bool TestPerioda(const std::vector<tip> &v,int p){
	 for(int i(0);i<v.size();i++){
	 	for(int j(i); j<v.size();j+=p) {
	 		if(v.at(i) != v.at(j)) return false;
	 	}
	 }
	 return true;
}

template<typename tip>
int Period(const std::vector<tip> &v){
	int n=v.size()-1;
	for(int i=n;i>=1;i--){
		if(TestPerioda(v,i))
		return i;
	}
	return 0;
}

template<typename tip>
int Najveci(const std::vector<tip> &v){
	int max(0);
	for(int i(0); i < v.size(); i++) {
		if(v.at(i) > max) max = v.at(i);
	}
	return max;
}

template<typename tip>
int Najmanji(const std::vector<tip> &v){
	int min(v[0]);
	for(int i(1);i<v.size();i++){
	if(v.at(i)<min) min=v.at(i);	
	}
	return min;
}


template <typename tip>
int **AlocirajKontinualno (const std::vector<tip> &v,int &koliko_puta){
	if(v.size()==0) throw("Prazan vektor!");
	for(int i(0);i<v.size();i++){
		if(v.at(i) <=0 ) throw std::domain_error("Neispravan vektor!");
	}
	int period=Period(v);
	int produzenje=0;
	if(period!=0){
		int modul=v.size()%period;
		produzenje= period-modul;
		if(produzenje==period) produzenje = 0;
		koliko_puta=(v.size()+produzenje)/period;
	}
	else{
		koliko_puta=2;
		period=v.size();
		produzenje=v.size();
	}
	
	int suma=0;
	for(int i(0);i<period;i++)
	  suma+=v.at(i);
	try{
		int **mat=new int*[v.size()+produzenje]{};
		try{
			mat[0]= new int[suma*koliko_puta];
			for(int i(1);i<v.size()+produzenje;i++){
				mat[i]=mat[i-1]+v[i%period];
			}
			int min = Najmanji(v);
			for(int i(0); i<v.size()+produzenje;i++) {
				for(int j(v.at(i % period)-1); j >= 0;j--) {
					
					if(j == v.at(i % period)-1) mat[i][j] = min;
					
					else mat[i][j] = mat[i][j + 1] + 1;
					
				}
			}
			return mat;
		}
		catch(...){
			
				delete[] mat[0];
				mat[0] = nullptr;
		
			delete[] mat;
			mat = nullptr;
			throw;
		}
	}
	catch(...){
		throw;
	}
}
		
	

template <typename tip>
int **AlocirajFragmentirano (const std::vector<tip> &v,int &koliko_puta) {
	if(v.size() == 0) throw ("Prazan vektor!");
	for(int i(0); i < v.size(); i++) {
		if(v.at(i) <= 0) throw std::domain_error("Neispravan vektor!");
	}
	int period=Period(v);
	int produzenje=0;
	if(period!=0){
		int modul = v.size() % period;
		produzenje = period - modul;
		if(produzenje == period) produzenje = 0;
		koliko_puta = (v.size() + produzenje) / period;
	}
	else {
		koliko_puta = 2;
		period = v.size();
		produzenje = v.size();
	}
	try{ 
		int **mat=new int*[v.size()+produzenje]{}; // period * koliko_puta
		try{
			for(int i(0);i<v.size()+produzenje;i++){
				mat[i]=new int[v[i%period]];
			}
			int max = Najveci(v);
			for(int i(0); i<v.size()+produzenje;i++) {
				for(int j(v.at(i % period) - 1); j >= 0;j--) {
					if(j == v.at(i % period) - 1) mat[i][j] = max;
					else mat[i][j] = mat[i][j + 1] - 1;
				}
			}
			return mat;
		}
		catch(...){
			for(int i(0); i<v.size()+produzenje;i++) {
				delete[] mat[i];
				mat[i] = nullptr;
			}
			delete[] mat;
			mat = nullptr;
			throw;
		}
	}
	catch(...){
		throw;
	}
}


int main () {
	try {
		std::cout<<"Unesite broj elemenata vektora: ";
		int n;
		std::cin>>n;
		std::cout<<"Unesite elemente vektora: ";
		std::vector<int>v;
		for(int i(0); i < n; i++) {
			int x;
			std::cin>>x;
			v.push_back(x);
		}
		std::cout<<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
		int a;
		std::cin >> a;
		int koliko_puta;
		int **matrica = nullptr;
		if(a == 1) {
			matrica = AlocirajFragmentirano(v, koliko_puta);
		}
		else if(a == 0) {
			matrica = AlocirajKontinualno(v, koliko_puta);
			
		}
		int period = Period(v);
		int produzenje = 0;
		if(period != 0) {
			int modul = v.size() % period;
			produzenje = period - modul;
			if(produzenje == period) produzenje = 0;
		}
		else {
			period = v.size();
			produzenje = v.size();
		}
		std::cout << "Dinamicki alocirana matrica: " << std::endl;
		for(int i(0); i < v.size()+produzenje; i++) {
			for(int j(0); j < v.at(i % period); j++) {
				std::cout << std::left << std::setw(3) << matrica[i][j];
			}
			std::cout << std::endl;
		}
		if(a==1){
		for(int i(0); i < v.size()+produzenje; i++) {
			delete[] matrica[i];
		}
		delete[] matrica;
	}
	
	if(a==0){
		delete [] matrica[0];
		delete [] matrica;
	}
	}
	catch(std::domain_error e) {
		std::cout << "Izuzetak: " << e.what();
	}
	catch(const char *e) {
		std::cout << "Izuzetak: " << e;
	}
	catch(...) {
		// alokacija
		std::cout << "alokacija";
	}
	return 0;
}
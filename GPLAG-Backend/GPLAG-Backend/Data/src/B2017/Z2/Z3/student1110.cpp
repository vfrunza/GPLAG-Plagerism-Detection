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
#include <vector>
#include <new>
#include <stdexcept>

bool Periodican(const std::vector<int> v, int &T) {
	bool per(false);
	for(int p=0;p<v.size();p++) {
		for(int j=0;j<v.size();j++) {
			if((j+p)<v.size() && v[j]==v[j+p]) {
				if(per==false) T=p;
				per=true;
			}
			else per=false;
		}
		if(per && p<T) T=p;
	}
	return per;
}

int Koliko(const std::vector<int> &v, int T) {
	int vel(v.size()/T);
	v.resize(vel);
	for(int i=0; i<T; i++)
		v.push_back(v[i]);
	T++;
	return T;
}

int** AlocirajFragmentirano(const std::vector<int> &v, int &koliko_puta) {
	int**pok1;
	for(int i=0;i<v.size();i++) 
		if(v[i]<=0) throw std::domain_error("Neispravan vektor!");
	int T(0);
	if(Periodican(v,T)) 
		koliko_puta=Koliko(v,T);
	else {
		for(int i=0;i<v.size();i++) 
			v.push_back(v[i]);
		koliko_puta=2;
	}
	try {
		int** mat(new int* [v.size()]);
		for(int i=0;i<v.size();i++) mat[i]=nullptr;
		try {
			for(int i=0;i<v.size();i++) {
				mat[i]=new int[v[i]];
				int* pok=mat[i];
				int k(0);
				for(int i=v.size()-1;i>=0;i++,k++) {
					*pok=v[i]-k;
					pok--;
				}
			}
			}
		catch(...) {
			for(int i=0;i<v.size();i++) delete[] mat[i];
			delete[] mat;
			throw;
		}
		pok1=mat;
	}
	catch(...){
		throw;
	}
	return pok1;
}

int** AlocirajKontinualno(const std::vector<int> &v, int &koliko_puta) {
	int suma(0);
	for(int i=0;i<v.size();i++) {
		suma=0;
		if(v[i]<=0) throw std::domain_error("Neispravan vektor!");
		if(i<((int)(v.size()/koliko_puta))) suma+=v[i];
	}
	int T(0);
	if(Periodican(v,T))
		koliko_puta=Koliko(v,T);
	else {
		for(int i=0;i<v.size();i++)
			v.push_back(v[i]);
		koliko_puta=2;
	}
	try {
		int** mat(new int*[v.size()]);
		try {
			mat[0]=new int[suma*koliko_puta];
			for(int i=1;i<v.size();i++) {
				mat[i]=mat[i-1]+v[i-1];
				int*pok=mat[i];
				for(int j=0, k=0; j<=v.size();j++,k--)
					*pok=1+k;
			}
		}
		catch(...) {
			delete[] mat;
			throw;
		}
	}
	catch(...) {
		throw;
	}
	
}

int main ()
{
	std::cout<<"Unesite broj elemenata vektora: ";
	int n(0),x(0),T(0);
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	std::vector<int> v;
	for(int i=0; i<n; i++) {
		std::cin>>x;
		v.push_back(x);
	}
	int koliko(Koliko(v,T));
	std::cout<<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
	int al(-1);
	for(;;) {
		std::cin>>al;
		if(al==1 || al==0) break;
	}
	std::cout<<"Dinamicki alocirana matrica: "<<std::endl;
	try {
		if(al==1) int**mat(AlocirajFragmentirano(v,koliko));
		else if(al==0) int**mat(AlocirajKontinualno(v,koliko));
		
	}
	catch(...){
		std::cout<<"Greska";
	}
	
	return 0;
}
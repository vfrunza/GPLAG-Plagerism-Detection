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
#include <memory>
#include <new>
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include <limits>

template<typename tip>
bool TestPerioda (std::vector<tip> z, int p){
	if(p>=1 && p<z.size()){
		for(int i(0); i<z.size()-p; i++){
				if(z.at(i)!=z.at(p+i)) return false;
			}
	return true;
	}
	else return false;
}
template<typename tip>
int OdrediOsnovniPeriod (std::vector<tip> z){
	int osnovni_period(std::numeric_limits<int>::max());
	for(int i(1); i<z.size(); i++){
		if(TestPerioda(z,i)){
			int period=i;
			if(period<osnovni_period) osnovni_period=period;
		}
	}
	if(osnovni_period==std::numeric_limits<int>::max()) return 0;
	else
	return osnovni_period;
}

template<typename tip>
int** AlocirajFragmentirano(const std::vector<tip> &vek, int &koliko_puta){
	if(vek.size()==0) throw std::logic_error("Prazan vektor!");
		for(int i(0); i<vek.size(); i++){
				if(vek.at(i)<=0){
					throw std::domain_error("Neispravan vektor!");
				}
		}
	bool Periodican(false);
	for(int i(1); i<vek.size(); i++){
		if(TestPerioda(vek,i)) Periodican=true;
	}
	if(Periodican==true){
		int T(OdrediOsnovniPeriod(vek));
		int produzenje=vek.size();
		while(produzenje%T!=0) produzenje++;
		koliko_puta=int(produzenje/T);
		try{
		int**pok=new int*[koliko_puta*T]{};
		try{
			int t(1);
			for(int i(0); i<koliko_puta*T; i++){
					pok[i]=new int[vek.at(t-1)];
					if(t<T) t++;
					else t=1;
				}
			int max(0);
			for(int i(0); i<vek.size(); i++)
				if(vek.at(i)>max) max=vek.at(i);
			t=1;	
			for(int i(0); i<koliko_puta*T; i++){
				int brojac(0);
				for(int j(vek.at(t-1)-1); j>=0; j--){
					pok[i][j]=max-brojac;
					brojac++;
				}
				if(t<T) t++;
				else t=1;
			}
			return pok;
		}catch(std::bad_alloc){
			for(int i(0); i<koliko_puta*T; i++) delete[] pok[i];
			delete[] pok;
			throw;
		}
		}catch(...){
			throw;
		}
	}
	else{
		int T(vek.size());
		koliko_puta=2;
		try{
			int**pok=new int*[T*koliko_puta]{};
			try{
			int t(1);
			for(int i(0); i<koliko_puta*T; i++){
					pok[i]=new int[vek.at(t-1)];
					if(t<T) t++;
					else t=1;
				}
			int max(0);
			for(int i(0); i<vek.size(); i++)
				if(vek.at(i)>max) max=vek.at(i);
			t=1;	
			for(int i(0); i<koliko_puta*T; i++){
				int brojac(0);
				for(int j(vek.at(t-1)-1); j>=0; j--){
					pok[i][j]=max-brojac;
					brojac++;
				}
				if(t<T) t++;
				else t=1;
			}
			return pok;
		}catch(std::bad_alloc){
			for(int i(0); i<koliko_puta*T; i++) delete[] pok[i];
			delete[] pok;
			throw;
		}
		}catch(...){
			throw;
		}
	}
}
template<typename tip>
int** AlocirajKontinualno(const std::vector<tip> &vek, int &koliko_puta){
	if(vek.size()==0) throw std::logic_error("Prazan vektor!");
		for(int i(0); i<vek.size(); i++){
				if(vek.at(i)<=0){
					throw std::domain_error("Neispravan vektor!");
				}
		}
	bool Periodican(false);
	for(int i(1); i<vek.size(); i++){
		if(TestPerioda(vek,i)) Periodican=true;
	}
	if(Periodican){
		int T(OdrediOsnovniPeriod(vek));
		int produzenje=vek.size();
		while(produzenje%T!=0) produzenje++;
		koliko_puta=int(produzenje/T);
		try{
		int**pok=new int*[koliko_puta*T]{};
		try{
			int brojelemenata(0);
			int t(1);
			for(int i(0); i<koliko_puta*T; i++){
					brojelemenata=brojelemenata+vek.at(t-1);
					if(t<T) t++;
					else t=1;
				}
			pok[0]=new int[brojelemenata];
			t=1;
			for(int i(1); i<koliko_puta*T; i++){
				pok[i]=pok[i-1]+vek.at(t-1);
				if(t<T) t++;
				else t=1;
			}
			t=1;	
			for(int i(0); i<koliko_puta*T; i++){
				int brojac(1);
				for(int j(vek.at(t-1)-1); j>=0; j--){
					pok[i][j]=brojac;
					brojac++;
				}
				if(t<T) t++;
				else t=1;
			}
			return pok;
		}catch(...){
			delete[] pok;
			throw;
		}
		}catch(...){
			throw;
		}
	}
	else{
		int T(vek.size());
		koliko_puta=2;
		try{
			int**pok=new int*[T*koliko_puta]{};
			try{
			int brojelemenata(0);
			int t(1);
			for(int i(0); i<koliko_puta*T; i++){
					brojelemenata=brojelemenata+vek.at(t-1);
					if(t<T) t++;
					else t=1;
				}
			pok[0]=new int[brojelemenata];
			t=1;
			for(int i(1); i<koliko_puta*T; i++){
				pok[i]=pok[i-1]+vek.at(t-1);
				if(t<T) t++;
				else t=1;
			}
			t=1;	
			for(int i(0); i<koliko_puta*T; i++){
				int brojac(1);
				for(int j(vek.at(t-1)-1); j>=0; j--){
					pok[i][j]=brojac;
					brojac++;
				}
				if(t<T) t++;
				else t=1;
			}
			return pok;
		}catch(...){
			delete[] pok;
			throw;
		}
		}catch(...){
			throw;
		}
	}
}
int main ()
{
	try{
		int n,fragmentacija;
		std::cout<<"Unesite broj elemenata vektora: ";
		std::cin>>n;
		std::vector<int> vektor(n);
		std::cout<<"Unesite elemente vektora: ";
		for(int i(0); i<n; i++){
			std::cin>>vektor.at(i);
		}
		std::cout<<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
		std::cin>>fragmentacija;
		if(fragmentacija){
			int koliko(0);
			int Period(OdrediOsnovniPeriod(vektor));
			int t(1);
			if(Period!=0){
			int** pok=AlocirajFragmentirano(vektor,koliko);
			std::cout<<"Dinamicki alocirana matrica: \n";
			for(int i(0); i<koliko*Period; i++){
				for(int j(0); j<vektor.at(t-1); j++){
					std::cout<<pok[i][j]<<"  ";
				}
				if(t<Period) t++;
				else t=1;
				std::cout<<"\n";
			}
			for(int i(0); i<koliko*Period; i++) delete[] pok[i];
			delete[] pok;
		}
		else{
			Period=vektor.size();
			int t(1);
			int** pok=AlocirajFragmentirano(vektor,koliko);
			std::cout<<"Dinamicki alocirana matrica: \n";
			for(int i(0); i<koliko*Period; i++){
				for(int j(0); j<vektor.at(t-1); j++){
					std::cout<<pok[i][j]<<"  ";
				}
				if(t<Period) t++;
				else t=1;
				std::cout<<"\n";
			}
			for(int i(0); i<koliko*Period; i++) delete[] pok[i];
			delete[] pok;
		}
		}
		else{
			int koliko(0);
			int Period(OdrediOsnovniPeriod(vektor));
			int t(1);
			if(Period!=0){
			int** pok=AlocirajKontinualno(vektor,koliko);
			std::cout<<"Dinamicki alocirana matrica: \n";
			for(int i(0); i<koliko*Period; i++){
				for(int j(0); j<vektor.at(t-1); j++){
					std::cout<<pok[i][j]<<"  ";
				}
				if(t<Period) t++;
				else t=1;
				std::cout<<"\n";
			}
			delete[] pok[0];
			delete[] pok;
		}
		else{
			Period=vektor.size();
			int t(1);
			int** pok=AlocirajKontinualno(vektor,koliko);
			std::cout<<"Dinamicki alocirana matrica: \n";
			for(int i(0); i<koliko*Period; i++){
				for(int j(0); j<vektor.at(t-1); j++){
					std::cout<<pok[i][j]<<"  ";
				}
				if(t<Period) t++;
				else t=1;
				std::cout<<"\n";
			}
			delete[] pok[0];
			delete[] pok;
		}
		}	
	}catch(std::logic_error logicki){
		std::cout<<"Izuzetak: "<<logicki.what();
	}catch(std::domain_error domena){
		std::cout<<"Izuzetak: "<<domena.what();
	}catch(...){
		std::cout<<"Izuzetak: Neuspjela alokacija";
	}
	return 0;
}
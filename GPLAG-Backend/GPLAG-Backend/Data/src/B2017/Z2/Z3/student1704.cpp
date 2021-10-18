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
#include <stdexcept>
#include <iomanip>

template <typename NekiTip>
int ** AlocirajFragmentirano(const std::vector<NekiTip> &v, int &koliko_puta) {

int **a;
	if(v.size()==0) throw("Izuzetak: Prazan vektor!");

	bool nije_period(false);
	int period(0);
	for(int i=0; i<v.size(); i++) {
		for(int j=0; j<v.size(); j++) {
			if(j+i<v.size()) {
				if(v.at(j)!=v.at(j+i)) nije_period =true;
			}
		}
		if(!nije_period && period==0) period=i; 
		nije_period=false;
	}
	
	if(period!=0) {
		if(v.size()%period!=0) koliko_puta=int(v.size()/period)+1;
		else koliko_puta=v.size()/period;
	}
	else {
		koliko_puta=2;
		period=v.size();
	}
	
	
	try {
		a = new int* [koliko_puta*period];
	}
	catch(...) {
		throw;
	}
	
	try {
		for(int i=0; i<koliko_puta*period; i++) a[i]=nullptr;
		int k=0; 
		for(int i=0; i<koliko_puta*period; i++) {
			if(v.at(k)<=0) throw std::domain_error("Izuzetak: Neispravan vektor!");
			a[i]=new int [v.at(k)];
			k++;
			if(k==period) k=0;
		}
		
		int m=period-1;
		int n=0;
		
		for(int i=0; i<period*koliko_puta; i++) {
			for(int j=v[n]-1; j>=0; j--) {
				a[i][j]=v[m];
				m--;
				if(m<0) j=-1;
			
			}
			m=period-1;
			n++;
			if(n==period) n=0;
		}
	}
	catch(...) {
		for(int i=0; i<period*koliko_puta; i++) delete [] a[i];
		delete [] a;
		throw;
	}
	return a;
}

template <typename Tip>
int **AlocirajKontinualno(const std::vector<Tip> &v, int &koliko_puta) {
	int **a;
	if(v.size()==0) throw("Izuzetak: Prazan vektor!");
	
	bool nije_period(false);
	int period(0);
	for(int i=0; i<v.size(); i++) {
		for(int j=0; j<v.size(); j++) {
			if(j+i<v.size()) {
				if(v.at(j)!=v.at(j+i)) nije_period=true;
			}
		}
		if(!nije_period && period==0) period=i;
		nije_period=false;
	}
	
	if(period!=0) {
		if(v.size()%period!=0) koliko_puta=int(v.size()/period)+1;
		else koliko_puta=v.size()/period;
	}
	else {
		koliko_puta=2;
		period=v.size();
	}
	

		try{
			a=new int* [koliko_puta*period];
		}
		catch(...) {
			throw;
		}
	
	
	try {
		int broj(0);
		int k=0;
		for(int i=0; i<period*koliko_puta; i++) {
			if(v.at(i)<=0) throw std::domain_error("Izuzetak: Neispravan vektor!");
			broj+=v.at(k);
			k++;
			if(k==period) k=0;
		}
	
		a[0]=new int [broj];
		
		k=0;
		for(int i=1; i<koliko_puta*period; i++) {
			a[i]=a[i-1]+v.at(k);
			k++;
			if(k==period) k=0;
		}
		
	    int m=0;
		int n=0;
		
		for(int i=0; i<period*koliko_puta; i++) {
			for(int j=v[n]-1; j>=0; j--) {
				a[i][j]=v[m];
				m++;
				if(m==period) j=-1;
			}
			m=0;
			n++;
			if(n==period) n=0;
		}
		
	}
	catch(...) {
		delete [] a;
		throw;
	}
	
	return a;
	
	}



int main ()
{
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::vector<int> v;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i<n; i++) {
		int broj;
		std::cin>>broj;
		v.push_back(broj);
	}
	
	bool nije_period(false);
	int period(0);
	for(int i=0; i<v.size(); i++) {
		for(int j=0; j<v.size(); j++) {
			if(j+i<v.size()) {
				if(v.at(j)!=v.at(j+i)) nije_period=true;
			}
		}
		if(!nije_period && period==0) period=i;
		nije_period=false;
	}
	if(period==0) period=v.size();
	
	
	int alloc;
	std::cout<<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
	std::cin>>alloc;
	int koliko_puta;
	
	if(alloc) {
		try {
		int** a=AlocirajFragmentirano(v,koliko_puta);
		std::cout<<"Dinamicki alocirana matrica:"<<std::endl;
		int k=0;
		for(int i=0; i<period*koliko_puta; i++) {
			for(int j=0; j<v[k]; j++) {
				std::cout<<std::left<<std::setw(3)<<a[i][j];
			}
			k++;
			if(k==period) k=0;
			std::cout<<std::endl;
		}
		for(int i=0; i<koliko_puta*period; i++) delete [] a[i];
		delete [] a;
		}
	
	catch(const char poruka[]) {
		std::cout<<poruka;
	}
	catch(std::domain_error poruka) {
		std::cout<<poruka.what();
	}
	catch(...) {
		std::cout<<"Alokacija nije uspjela!";
	}
	}
	
	else {
		try {
			int ** a=AlocirajKontinualno(v,koliko_puta);
			std::cout<<"Dinamicki alocirana matrica:"<<std::endl;
			int k=0;
			for(int i=0; i<period*koliko_puta; i++) {
				for(int j=0; j<v[k]; j++) {
					std::cout<<std::left<<std::setw(3)<<a[i][j];
				}
				k++;
				if(k==period) k=0;
				std::cout<<std::endl;
			}
			delete [] a[0];
			delete [] a;
		}
		catch(const char poruka[]) {
			std::cout<<poruka;
		}
		catch(std::domain_error poruka) {
			std::cout<<poruka.what();
		}
		catch(...) {
			std::cout<<"Alokacija nije uspjela!";
		}
	}
	
	return 0;
}
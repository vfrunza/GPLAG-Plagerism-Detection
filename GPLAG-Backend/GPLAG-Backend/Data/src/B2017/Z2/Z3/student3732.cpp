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
#include <type_traits>
#include <stdexcept>
#include <iomanip>
#include <new>

template<typename TIP>
bool TestPerioda(std::vector<TIP> v1,int p,int broj_elem){
	bool period = true;
	if(p==0 || p>=broj_elem) period = false; 
	else {
	for(int i=0;i<broj_elem-p;i++){
		if(v1[i+p]!=v1[i]) {
			period=false;
			break;
		}
	}
	}
	return period;
} 
 template<typename VEK>
int KojiPeriod(std::vector<VEK> v2,int br_elem){
	int i;
	for(i=1;i<br_elem;i++){
		if(TestPerioda(v2,i,br_elem)) return i;
	}
	return 0;
}
template<typename tip5>
auto NadjiSumu(const std::vector<tip5> &v3,int p)-> typename std::remove_reference<decltype(v3[0])>::type{
	auto suma=v3[0];
	for(int i=1;i<p;i++) suma+=v3[i];
	return suma;
}

template<typename tip1>

int **AlocirajKontinualno(const std::vector<tip1> &v1,int &koliko_puta){
	
	if(v1.size()==0) throw std::range_error("Prazan vektor!");
	for(int i=0;i<v1.size();i++){
		if(v1[i]<=0) throw std::domain_error("Neispravan vektor!");
	}
	
	int period=KojiPeriod(v1,v1.size());
	if(period!=0) koliko_puta=(v1.size()+v1.size()%period)/period;
	else if(period==0){koliko_puta=2; period=v1.size();}
	int **a=nullptr;
	int k(1);
	try{
		a=new int *[period*koliko_puta]{};
	  try{
	  	int suma=NadjiSumu(v1,period);
	  	suma*=koliko_puta;
	  	a[0]=new int [suma];
	  	int br(0);
	  	while(br<koliko_puta){
	  	for(int i=0;i<period;i++) {a[k]=a[k-1]+v1[i]; if(k==period*koliko_puta-1)break;  k++; }
	  	br++;
	  	}
	  	k=0;
	  	br=0;
	  	while(br<koliko_puta){
	  	for(int i=0;i<period;i++){
	  		for(int j=0;j<v1[i];j++){
	  			a[k][j]=v1[i]-j;
	  		}
	  		k++;
	  	}
	  	br++;
	  	}
	  	
	  }
	  catch(...){
	  	delete[] a[0];
	  	delete[] a;
	  }
	}
	  catch(...){
	  	throw std::bad_alloc();
	  }
	  return a;
}
template<typename tip4>
auto NadjiMax(const std::vector<tip4> &v1)->typename std::remove_reference<decltype(v1[0])>::type{
	auto max=v1[0];
	for(int i=0;i<v1.size();i++){
		if(max<=v1[i]) max=v1[i]; 
	}
	return max;
}
 
 template<typename tip>
 int **AlocirajFragmentirano(const std::vector<tip> &v,int &koliko_puta){ 
    std::vector<int> v3;
    if(v.size()==0) throw std::range_error("Prazan vektor!");
    for(int i=0;i<v.size();i++) {
    	if(v[i]<=0) throw std::domain_error("Neispravan vektor!");
    }
  int period=KojiPeriod(v,v.size());
  if(period!=0) koliko_puta=(v.size()+v.size()%period)/period;
   else if(period==0) {koliko_puta=2; period=v.size();}
    int **p=nullptr;
    int k=0,br(0);
    auto max=NadjiMax(v);
    try{
    p=new int *[period*koliko_puta]{};
    try{
          while(br<koliko_puta){
            for(int i=0;i<period;i++) {p[k]=new int [v[i]]; k++;}
            	br++;
            }
            br=0;
            k=0;
            while(br<koliko_puta){
       for(int i=0;i<period;i++){
    	for(int j=0;j<v[i];j++){
    		p[k][j]=max-v[i]+1+j;
    	}
    	k++;
       }
       br++;
       }
    }
    catch(...){
    	for(int i=0;i<period*koliko_puta;i++) delete[] p[i];
    	delete[] p;
    	throw;
    }
    }
    catch(...){
    	delete[] p;
    	throw std::bad_alloc();
    }
   return p;
}

int main ()
{
	std::vector<int> v;
	int kolko(0);
	std::cout<<"Unesite broj elemenata vektora: ";
	int n(0);
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	int broj;
	try{
	for(int i=0;i<n;i++){
		std::cin>>broj;
		v.push_back(broj);
	}
	}
	catch(...){
		std::cout<<"Nedostatak memorije: ";
	}
	std::cout<<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
	int m(0);
	std::cin>>m;
	int periodica=KojiPeriod(v,v.size());
	int **pok;
	if(m==1){
	try{
		try{ 
			try{
	pok=AlocirajFragmentirano(v,kolko);
	if(kolko==2 && periodica==0) periodica=v.size();
	std::cout<<"Dinamicki alocirana matrica: "<<std::endl;
	int odakle(0);
	int k(0);
	while(odakle<kolko){
	for(int i=0;i<periodica;i++){
		for(int j=0;j<v[i];j++){
			std::cout<<std::left<<std::setw(3)<<pok[k][j];
		}
		std::cout<<std::endl;
		k++;
	}
	odakle++;
	}
	for(int i=0;i<periodica*kolko;i++) delete[] pok[i];
	delete[] pok;
	}
	catch(std::domain_error izuzetak){
		std::cout<<"Izuzetak: "<<izuzetak.what();
		return 0;
	}
	}
	catch(std::range_error izuzetak){
		std::cout<<"Izuzetak: "<<izuzetak.what();
		return 0;
	}
	}
	catch(std::bad_alloc){
		std::cout<<"Nedovoljno memorije: ";
	}
	}
	else if(m==0){
	try{ 
		try{ 
			try{
			int z(0),br(0);
		pok=AlocirajKontinualno(v,kolko);
		std::cout<<"Dinamicki alocirana matrica: "<<std::endl;
		periodica=KojiPeriod(v,v.size());
		if(kolko==2 && periodica==0) periodica=v.size();
		while(br<kolko){
		for(int i=0;i<periodica;i++){
			for(int j=0;j<v[i];j++){
				std::cout<<std::left<<std::setw(3)<<pok[z][j];
			}
			std::cout<<std::endl;
			z++;
		}
		br++;
		}
		delete[] pok[0];
		delete[] pok;
	}
	catch(std::domain_error izuzetak){
		std::cout<<"Izuzetak: "<<izuzetak.what();
		return 0;
	}
	}
	catch(std::range_error izuzetak){
		std::cout<<"Izuzetak: "<<izuzetak.what();
		return 0;
	}
	}
	catch(std::bad_alloc){
		std::cout<<"Nedovoljno memorije";
	}
	}
	
	return 0;
}
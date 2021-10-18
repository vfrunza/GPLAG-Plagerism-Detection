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
#include <iomanip>
#include <stdexcept>


int OdrediOsnovniPeriod(std::vector<int> v){
	int t(1);
	for(int i=0; i<static_cast<int> (v.size())-t; i++)
	if(v.at(i)!=v.at(i+t)){
		t++;
		i=-1;
	}
	return t!=static_cast<int> (v.size()) ? t:0;
}
template <typename tip>
int  **AlocirajFragmentirano(const std::vector<tip> &v, int &koliko_puta){
	for(int i=0; i<v.size(); i++) if(v.at(i)<=0) throw std::domain_error("Neispravan vektor!");
	if(v.size()==0) throw std::domain_error("Prazan vektor!");
	int br_redova(0);
	int duzina(0);
	int period(0);
	 if(v.size()!=OdrediOsnovniPeriod(v) && OdrediOsnovniPeriod(v)!=0){
	 	duzina=v.size();
	 	while(duzina>=OdrediOsnovniPeriod(v)){
	 		duzina-=OdrediOsnovniPeriod(v);
	 		koliko_puta++;
	 	} 
	 	if(duzina!=0)koliko_puta++;
	 	br_redova=koliko_puta*OdrediOsnovniPeriod(v);
	 	period=OdrediOsnovniPeriod(v);

	 }
	 if(OdrediOsnovniPeriod(v)==0){
	 	duzina=0;
	 	koliko_puta=2;
	 	br_redova=v.size()*koliko_puta;
	 	period=v.size();

	 }
	 
     try{
     	int** p=new int* [br_redova];
     	for(int i=0; i<br_redova; i++)
     	p[i]=nullptr;
     	try {
     		int j(duzina);
     		for(int i=0; i<br_redova; i++){
     			if(i>=v.size() && j<period){
     			p[i]=new int[v[j]];
     			j++;
     			} 
     			else p[i]=new int[v[i]];
     		}
     		
     	}catch(std::bad_alloc){
     		for(int i=0; i<br_redova; i++)
     		delete[] p[i];
     		delete[] p;
     		throw;
     	}
     	//nesto radi matrica
     	int j(duzina);
     	for(int i=0; i<br_redova; i++){
     		if(i>=v.size() && j<period){
     			for(int k=v[j]-1; k>=0; k--) p[i][k]=period-v[j]+k+1;
     			j++;
     			} 
     			else for(int k=v[i]-1; k>=0; k--) p[i][k]=period-v[i]+k+1;
     	}
     	return p;
     }catch(std::bad_alloc){
     	throw;
     }
}
template <typename tip>
int  **AlocirajKontinualno(const std::vector<tip> &v, int &koliko_puta){
	for(int i=0; i<v.size(); i++) if(v.at(i)<=0) throw std::domain_error("Neispravan vektor!");
	if(v.size()==0) throw std::domain_error("Prazan vektor!");
	int br_redova(0);
	int duzina(0);
	int period(0);
	 if(v.size()!=OdrediOsnovniPeriod(v) && OdrediOsnovniPeriod(v)!=0){
	 	duzina=v.size();
	 	while(duzina>=OdrediOsnovniPeriod(v)){
	 		duzina-=OdrediOsnovniPeriod(v);
	 		koliko_puta++;
	 	} 
	 	if(duzina!=0)koliko_puta++;
	 	br_redova=koliko_puta*OdrediOsnovniPeriod(v);
	 	period=OdrediOsnovniPeriod(v);

	 }
	 if(OdrediOsnovniPeriod(v)==0){
	 	duzina=0;
	 	koliko_puta=2;
	 	br_redova=v.size()*koliko_puta;
	 	period=v.size();

	 }
	 
     try{
     	int** p=new int* [br_redova];
     	try {
     		int brojac(0);
     		int j=duzina;
     		for(int i=0; i<br_redova; i++){
     			if(i>=v.size() && j<period){
     			brojac+=v[j];
     			j++;
     			} 
     			else brojac+=v[i];
     		}
     		p[0]=new int[brojac];
     		j=duzina;
     		for(int i=1; i<br_redova; i++){
     			if(i>= v.size() && j<period){
     		    if(j!=0)p[i]=p[i-1]+v[j-1];
     		    else p[i]=p[i-1]+v[i-1];
     			j++;
     			} 
     			else p[i]=p[i-1]+v[i-1];
     		}
     		
     	}catch(std::bad_alloc){
     		delete[] p;
     		throw;
     	}
     	//nesto radi matrica
     	int j(duzina);
     	for(int i=0; i<br_redova; i++){
     		if(i>=v.size() && j<period){
     			for(int k=v[j]-1; k>=0; k--) p[i][k]=v[j]-k;
     			j++;
     			} 
     			else for(int k=v[i]-1; k>=0; k--) p[i][k]=v[i]-k;
     	}
     	return p;
     }catch(std::bad_alloc){
     	throw;
     }
}
std::vector<int> ProsireniVektor(std::vector<int> v){
	if(v.size()!=OdrediOsnovniPeriod(v) && OdrediOsnovniPeriod(v)!=0){
        int duzina(v.size());
        while(duzina>=OdrediOsnovniPeriod(v)) duzina-=OdrediOsnovniPeriod(v);
        if(duzina!=0) for(int i=duzina; i<OdrediOsnovniPeriod(v); i++) v.push_back(v.at(i));
    }
    if(OdrediOsnovniPeriod(v)==0){
        int duzina(v.size());
        for(int i=0; i<duzina; i++) v.push_back(v.at(i));
    }
   
    return v;
}
int main ()
{
	try{
	int koliko_puta(0);
	std::cout<<"Unesite broj elemenata vektora: ";
	int n(0);
	std::cin>>n;
	std::vector<int> v(n);
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i<n; i++) std::cin>>v.at(i);
	
	std::cout<<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
	int f;
	std::cin>>f;
	//if(v.size()==0) throw std::domain_error("Prazan vektor!");
	if(f==0){ 
	auto m=AlocirajKontinualno(v, koliko_puta);
	auto v1=ProsireniVektor(v);
	std::cout<<"Dinamicki alocirana matrica: ";
	std::cout<<std::endl;
	for(int i=0; i<v1.size(); i++){
		for(int j=0; j<v1.at(i); j++){
			std::cout<<std::left<<m[i][j]<<std::setw(3);
		}
		std::cout<<std::endl;
	}
       delete[] m[0];
	delete[] m;
	}
	if(f==1){ 
	auto m=AlocirajFragmentirano(v, koliko_puta);
	auto v1=ProsireniVektor(v);
	std::cout<<"Dinamicki alocirana matrica: ";
	std::cout<<std::endl;
	for(int i=0; i<v1.size(); i++){
		for(int j=0; j<v1.at(i); j++){
			std::cout<<std::left<<m[i][j]<<std::setw(3);
		}
		std::cout<<std::endl;
	}
     	for(int i=0; i<v1.size(); i++) delete[] m[i];
	delete[] m;
	}
	}catch(std::domain_error Izuzetak){
		std::cout<<"Izuzetak: "<<Izuzetak.what()<<std::endl;
	
	}catch(std::bad_alloc){
		std::cout<<"Izuzetak: Nedovoljno memorije!"<<std::endl;
	}
	return 0;
}
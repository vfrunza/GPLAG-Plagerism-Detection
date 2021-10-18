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
#include <algorithm>
template<typename tip>
   int TestPerioda(std::vector<tip> v, int p){
   	if(p<1 || p>=v.size()) return 0;
   	for(int i=0; i<v.size(); i++){
   		if(v[i]!=v[i+p]) return 0;
   	}
   	return 1;
   }
template<typename tip>
   int OdrediOsnovniPeriod(std::vector<tip> v){
   	for(int i=0; i<v.size(); i++){
   		if(TestPerioda(v,i)) return i;
   	}
   	return 0;
   }
template<typename tip>
 tip **AlocirajFragmentirano(std::vector<tip> &v, int &koliko_puta){
  	if(v.size()==0) throw("Prazan vektor!");
  	int m=v.size();
  	for(int i=0; i<v.size(); i++){
  		if(v[i]<=0) throw std::domain_error ("Neispravan vektor!");
  	}
  	int period(OdrediOsnovniPeriod(v));
  	if(period>0){
  		int pom(v.size());
  		for(;;){
  			if(pom%period==0) break;
  			pom++;
  		}
  		koliko_puta=(v.size()/period)+1;
  		int ostatak(pom%(koliko_puta-1));
  		for(int i=(period-ostatak); i<period; i++) v.push_back(v[i]);
  	}
  	else {
  	    for(int i=0; i<m; i++) v.push_back(v[i]);
  		koliko_puta=2;
  	}
  	int **pok(nullptr);
  	try{
  		pok=new int*[m*koliko_puta];
  		for(int i=0; i<m*koliko_puta; i++){
  			pok[i]=nullptr;
  		}
  		try{
  		    for(int i=0; i<koliko_puta; i++){
  		       for(int j=i*m; j<(i+1)*m; j++) pok[i*m+j]=new int[v[j-i*m]];
  		    }
  		}catch(...){
  		    throw;
  		}
  	}
  	catch(std::bad_alloc){
  	    for(int i=0; i<v.size(); i++) delete[] pok[i];
  	    delete[] pok;
  	    throw;
  	} catch(...){
  	    throw;
  	}
  	return pok;
  }
template<typename tip>
 tip **AlocirajKontiualno(std::vector<tip> &v, int &koliko_puta){
  	if(v.size()==0) throw("Prazan vektor!");
  	int m=v.size();
  	for(int i=0; i<v.size(); i++) if(v[i]<=0) throw std::domain_error("Neispravan vektor!");
  	int period(OdrediOsnovniPeriod(v));
  	//prosirenje
  	if(period>0){
  	    int pom(v.size());
  	    for(;;){
  	        if(pom%period==0) break;
  	        pom++;
  	    }
  	    koliko_puta=(v.size()/period)+1;
  	    int ostatak(pom%(koliko_puta-1));
  	    for(int i=(period-ostatak); i<period; i++) v.push_back(v[i]);
  	} else{
  	    for(int i=0; i<m; i++) v.push_back(v[i]);
  	    koliko_puta=2;
  	}
  	int **pok(nullptr);
  	int vel=*max_element(v.begin(),v.end());
  	try{
  	    pok=new int*[m*koliko_puta];
  	    pok[0]=new int[v.size()*vel];
  	    int pom(1);
  	    for(int i=0; i<koliko_puta; i++){
  	        pok[pom]=pok[pom-1]+v[i];
  	        pom++;
  	    }
  	}
  	catch(...){
  	    delete[] pok[0];
  	    delete[] pok;
  	    throw;
  	}
  	return pok;
  }
int main ()
{
    std::cout<<"Unesite broj elemenata vektora: ";
    int n;
    std::cin>>n;
    std::cout<<"Unesite elemente vektora: ";
    std::vector<int> v;
    for(int i=0; i<n; i++){
        int pom;
        std::cin>>pom;
        v.push_back(pom);
    }
    int f;
    std::cout<<"Odaberite alokaciju: 1 - framentirana, 0 - kontinualna: ";
    std::cin>>f;
    if(f!=0 || f!=1) std::cout << "Pogresan odabir!" << std::endl;
    else {
        try{
        int **pok(nullptr);
        int koliko_puta;
        if(f==0) pok=AlocirajKontiualno(v,koliko_puta);
        else pok=AlocirajFragmentirano(v,koliko_puta);
        std::cout<<"Dinamicki alocirana matrica: "<<std::endl;
        
            if(f){
                for(int i=0; i<v.size(); i++) delete [] pok[i];
                delete[] pok;
            } else{
                delete[] pok[0];
                delete[] pok;
            }
            
        }catch(std::domain_error izuzetak){
            std::cout << izuzetak.what() << std::endl;
        }
        catch(...){
            std::cout << "Prazan vektor!" << std::endl;
        }
    }
	return 0;
}
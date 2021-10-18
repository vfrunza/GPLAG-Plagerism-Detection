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
#include <algorithm>
 
template <typename TipV>
TipV **AlocirajFragmentirano(const std::vector<TipV> &v, int koliko_puta) {
    if(v.size()==0) throw ("Prazan vektor!");
    if(koliko_puta <=0) throw std::domain_error("Neispravan broj ponavljanja!");
    int **pok1=nullptr;
    try{
        pok1=new int*[koliko_puta*v.size()];
        for(int i(0);i<koliko_puta*v.size();i++)
            pok1[i]=nullptr;
        try{
                for(int i =0;i<koliko_puta;i++) {
                for(int j = i*v.size();j< i*v.size()+v.size();j++) {
                    if(v[j-i*v.size()]<=0) {
                        delete [] pok1;
                        throw std::domain_error("Neispravan vektor!");
                    }
                    else    pok1[i*v.size()+j] = new int[v[j-i*v.size()]];
                }
            }
        }
        catch(...){
            for(int x(0);x<koliko_puta;x++){
                for(int i(0+x*v.size());i<(x+1)*v.size();i++){
                    delete[] pok1[i];
                }
            }
            delete[] pok1;
            throw;
        }
    }
    catch(...){
       
        throw;
    }
    return pok1;
}
template<typename TipV>
TipV **AlocirajKontinualno(const std::vector<TipV> &v, int koliko_puta) {
    int max = *max_element(v.begin(),v.end());
    if(koliko_puta<=0) throw std::domain_error("Neispravan broj ponavljanja.");
    TipV **pok1(nullptr);
   try{
           
        pok1 = new int*[v.size()*koliko_puta];
        pok1[0] = new int[v.size()*koliko_puta*max];
        int temp(1);
        for(int j(0);j<koliko_puta;j++){
            for(int i = 0; i<v.size();i++)
            {
                if(v[i] <=0) {
                    delete [] pok1[0];
                    delete [] pok1;
                    throw std::domain_error("Neispravan vektor!.");
                }
                pok1[temp] = pok1[temp-1] + v[i];
                temp++;
            }
        }
   }
   catch(...){
        delete[] pok1[0];
            delete[] pok1;
            throw;
   }
    return pok1;
}
template <typename TipV>
TipV **KreirajPoUvrnutomPravilu(std::vector<TipV>&v, int koliko_puta, bool fragmentirano){
        if(v.size()==0) throw "Prazan vektor!";
        int p=0;
        int i=0;
        for(int i=1;i<v.size();i++) {
            if(v[0]==v[i]) p=i;
        }
        i=0;
        while(i+p<v.size()) {
            if(v[i]!=v[i+p]) {
                p++;
                i=-1;
            }
            i++;
        }
        if(p!=0) v.resize(p);
        else {
            int maksimalni(v[0]);
            for (int i=1;i<v.size();i++) {
                if(v[i]>maksimalni) maksimalni=v[i];
            }
            for(int i=0;i<v.size();i++) {
                v[i]=maksimalni+1-v[i];
            }
        }
        if(fragmentirano==true) {
            return AlocirajFragmentirano(v,koliko_puta);
        }
        if(fragmentirano==false) {
            return AlocirajKontinualno(v,koliko_puta);
        }
}
int main() {
 try {
     int elementi;
     std::cout<<"Unesite broj elemenata vektora: ";
     std::cin>>elementi;
     std::vector<int>v (elementi);
     std::cout<<"Unesite elemente vektora: ";
     for(int i=0;i<elementi;i++) {
        std::cin>>v[i];
     }
     int n;
     std::cout<<"Unesite broj ponavljanja: ";
     std::cin>>n;
     std::cout<<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
        bool f;
        std::cin>>f;
     int **pok=nullptr;
       
            pok=KreirajPoUvrnutomPravilu(v,n,f);
       
        std::cout<<"Dinamicki alocirana matrica: "<<std::endl;
      if(f!=0){
            for(int i(0);i<v.size()*n;i++)
                delete[] pok[i];
            delete[] pok;
        }
        else {
            delete[] pok[0];
            delete[] pok;
        }
 }
 catch(std::domain_error e) {
     std::cout<<e.what()<<std::endl;
 }
 
    return 0;
}
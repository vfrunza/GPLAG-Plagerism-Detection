/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include <vector> 
#include <list>
#include <set>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <memory>


struct Dijete {
    std::string ime;
    std::shared_ptr<Dijete> sljedeci;
};
std::vector<std::set<std::string>> Razvrstavanje(const std::vector<std::string> &v, int timovi){
    int broj_djece = v.size();
   if(broj_djece < timovi || timovi<1) throw std::logic_error("Razvrstavanje nemoguce");
    std::shared_ptr<Dijete> pocetak; 
    std::shared_ptr<Dijete>trenutni; 
    std::shared_ptr<Dijete> prethodni;
    for(int i = 0; i<v.size(); i++){
       
        std::shared_ptr<Dijete> novo = std::make_shared<Dijete>();
        novo->ime = v[i];
        
        if(i==0) {
            
            pocetak = novo;
            trenutni = novo;
            
        }
        else {
           
            trenutni->sljedeci = novo;
            trenutni = trenutni->sljedeci;
        }
        
        if(i==v.size()-1) {
            prethodni = trenutni;
            trenutni->sljedeci = pocetak;
        }
    }
    
    trenutni = pocetak;
   
    auto stanje(broj_djece);
    
    int zavrseno_timova = 0;
    
    std::vector<std::set<std::string>> raspodijeljeni_timovi;
    int slova (0);
    int br_timova_sa_vise_djece =0;
    
    if(broj_djece%timovi!=0)
        br_timova_sa_vise_djece = broj_djece%timovi;
    
    while(zavrseno_timova < timovi){
        std::set<std::string> tim;
        int broj_djece_u_timu = broj_djece/timovi;
        if(br_timova_sa_vise_djece > 0) {
            broj_djece_u_timu+=1; 
            br_timova_sa_vise_djece--;
            
        }
        
        while (broj_djece_u_timu > 0) {
            
             
            while(slova > 0) {
                
                prethodni = prethodni->sljedeci;
                trenutni = trenutni->sljedeci;
                slova--;
            }
            
            std::string s = trenutni->ime;
            //std::cout<<s;
            tim.insert(s);
            
            for(int i = 0; i<s.length(); i++){
                if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) slova++;
            }
            slova -=1;
            
            
           
            prethodni->sljedeci = trenutni->sljedeci;
            if(trenutni == pocetak) pocetak=pocetak->sljedeci;
            //trenutni->sljedeci = nullptr;
            //delete trenutni;
            stanje--;
            if(stanje!=0) trenutni = prethodni->sljedeci;
            broj_djece_u_timu--;
            //std::cout<<"Broj djece u timu nakon dodavanja je  "<< broj_djece_u_timu <<std::endl;
        }
        
        raspodijeljeni_timovi.push_back(tim);
        zavrseno_timova++;
    }
    pocetak->sljedeci = nullptr;
        prethodni->sljedeci = nullptr;
        trenutni->sljedeci = nullptr;
    return raspodijeljeni_timovi;
    
}


int main ()
{
    try {
       int broj_djece;
       std::cout<< "Unesite broj djece: ";
       std::cin>>broj_djece;
       std::cout<<"Unesite imena djece: " <<std::endl;
       std::cin.clear();
       std::cin.ignore(1000,'\n');
       std::vector<std::string> v;
       
       while(broj_djece>0){
           std::string s;
           std::getline(std::cin, s);
           v.push_back(s);
           broj_djece--;
       }
       std::cout<< "Unesite broj timova: ";
       int broj_timova; 
       std::cin>>broj_timova;
       std::vector<std::set<std::string>> vektor = Razvrstavanje(v,broj_timova);
       for(int i = 0; i< vektor.size(); i++){
           int j(0);
           std::cout<< "Tim " << i+1 << ": ";
           for(auto x : vektor[i]){
               if(j==vektor[i].size()-1) std::cout << x;
               else std::cout << x << ", ";
               j++;
           } 
           std::cout<<std::endl;
       }
    }
    catch(std::logic_error e){
        std::cout<<"Izuzetak: "<< e.what();
    }
	return 0;
}
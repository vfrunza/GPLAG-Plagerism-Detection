/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector> 
#include <list>
#include <set>
#include <string>
#include <stdexcept>
#include <algorithm>

std::vector<std::set<std::string>> Razvrstavanje(const std::vector<std::string> &v, int timovi){
    std::list<std::string> l;
    std::copy(v.begin(), v.end(),std::back_inserter(l));
    int broj_djece = v.size();
    if(broj_djece < timovi || timovi<1) throw std::logic_error("Razvrstavanje nemoguce");
    int zavrseno_timova = 0;
    //auto pocetak = l.begin(); 
    auto kraj = --l.end();
    auto trenutni = l.begin();
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
        //std::cout<<"Broj djece u timu je "<< broj_djece_u_timu <<std::endl;
        while (broj_djece_u_timu > 0) {
            
             
            while(slova > 0) {
                //std::cout<<"Broj slova je " << slova << " a ono na sta pokazuje trenutni je " << *trenutni<< std::endl; 
                if(trenutni == kraj) trenutni = l.begin();
                else trenutni++;
                slova--;
            }
            
            std::string s = *trenutni;
            //std::cout<<"Treba dodati sada "<< s<< std::endl;
            tim.insert(s);
            
            for(int i = 0; i<s.length(); i++){
                if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) slova++;
            }
            slova -=1;
            
            
            if(trenutni == kraj ){
                kraj--;
                 trenutni = l.erase(trenutni);
                 trenutni = l.begin();
            }
            else {
                trenutni = l.erase(trenutni);
            }
           
           
            
            broj_djece_u_timu--;
            //std::cout<<"Broj djece u timu nakon dodavanja je  "<< broj_djece_u_timu <<std::endl;
        }
     
        raspodijeljeni_timovi.push_back(tim);
        zavrseno_timova++;
    }
    
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
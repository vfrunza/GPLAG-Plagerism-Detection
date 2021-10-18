/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <vector>
#include <stdexcept>
#include <set>

int broj_koraka(std::string s){
    int slovo (0);
    int i = 0;
    while  ( i < s.length() ){
        
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) slovo++;
    //    while( s[i] == ' ' || !( (s[i] >= 'a' && s[i] <= 'z') || (s[i]>= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9') )) continue;
        
        i++;
    }
   return slovo;
}

std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> imena, int br_timova){
    
    if(br_timova < 1 || br_timova > imena.size())
        throw std::logic_error("Izuzetak: Razvrstavanje nemoguce\n");
  
    //... SVA IMENA IZ VEKTORA ISKOPIRATI U LISTU
    std::list<std::string> lista{};
    
   for(int i (0); i < imena.size(); i++){
       lista.insert(lista.end(), imena[i]);
   }


    
    //...KOLIKO TIM IMA CLANOVA
    /*   int n = imena.size(), k = br_timova, vel_tim,broj_timova;
        if(n % k != 0) { broj_timova = n % k; vel_tim = int(n / k) + 1;  std::cout <<broj_timova << " | " << vel_tim <<std::endl;}
        else{ broj_timova = k - (n % k); vel_tim = int(n /k);   std::cout <<broj_timova << " | " << vel_tim <<std::endl;}
    */
    
   
    //...U TIMOVE RAZVRSTATI DJECU
  std::vector<std::set<std::string>> timovi{};
 //std::list<std::string> prazna = std::list<std::string>();
  
    auto it = lista.begin();
    //it++;
    int n = imena.size(), k = br_timova;
    int p = 0;
    
    for(int i=0; i<k; i++) {
        timovi.push_back(std::set<std::string>());
    }
    
    while(p< n%k) {
        while(timovi[p].size() < ((n/k)+1)) {
            timovi[p].insert(*it);
            int b = broj_koraka(*it);
            int l =0;
            it = lista.erase(it);
            while(l<b-1) {
                if(it == lista.end()) { it = lista.begin(); it++; }
                else it++;
                l++;
            }
            if(it == lista.end()) it = lista.begin();
        }
        p++;
    }
    
    while(p < k) {
        while(timovi[p].size() < (n/k)) {
            timovi[p].insert(*it);
            int b = broj_koraka(*it);
            int l = 0;
            it = lista.erase(it);
            while(l < b-1) {
                if(it == lista.end()) { it = lista.begin(); it++;}
                else it++;
                l++;
            }
            if(it == lista.end()) it = lista.begin();
            
        }
        p++;
    }
    /*
        //...OVDJE CE UZETI PRVO DIJETE I STAVITI GA U TIM
        if(it == lista.begin()){  
            
             timovi.push_back(std::set<std::string>());
                timovi[0].insert(*it);
            
        }
    
     
    //..POMJERI ZA BROJ SLOVA
    int pomjeri_za_broj = broj_koraka(*it);
    
  
    
     //...IZBRISI UBACENO DIJETE IZ LISTE
     
     
     it = lista.erase(it);
    //  for(auto x: lista) std::cout<<x<< "|";  std::cout<<std::endl;
    while(*it != " "){ 
        
        while(pomjeri_za_broj - 1) { 
            if( it == lista.end()) { it = lista.begin(); }
            else it++;
            
        }
        
        
    //PROVJERA NA KOJEM JE DJETETU U LISTI

    std::cout<< *it <<"| ";
    //....UBACI SLJEDECE DIJETE NA MJESTO U PRVOM TIMU ILI U SLJEDECI TIM
   
     for(int i (0); i < broj_timova; i++){
         
        if(i == 0){
            for(int j (1); j < vel_tim;j++){
                timovi[i].insert(*it);
            }
        }else{
        
           timovi.push_back(std::set<std::string>());
            for(int j (0); j <vel_tim; j++ ){
                    timovi[i].insert(*it);
                   
                }
            }
            
            
     }
     
   // if(it == lista.end()  && it != prazna.begin() ) it = lista.begin();
  //  else break;
    }    
    
*/

   /*...ispis 
 
    for(int i (0); i < timovi.size();i++){
        std::cout<<"Tim "<< i + 1 << ": ";
        int j(0);
        for(auto skup : timovi[i])  {
            std::cout<<skup<< ((j!=(timovi[i].size()-1)) ? ", " : "");
            j++;
        }
        std::cout<<std::endl;
    }
    
    */
    return timovi;
}
int main ()
{
   
    
    //..BROJ_TIMOVA
    std::cout<<"Unesite broj djece: ";
    int broj_djece;
    std::cin >> broj_djece;
    
    std::cin.clear();
    std::cin.ignore(10000,'\n');
    
    std::string s;
    std::vector<std::string>imena;
    std::cout<<"Unesite imena djece: ";
    
    
    for(int i (0); i < broj_djece ; i++){
         std::getline(std::cin,s);
         imena.push_back(s);
       
    }
    
   
    std::cout<<"\nUnesite broj timova: ";
    int broj_timova;
    std::cin >> broj_timova ; 
    /*
    for(int i (0); i < imena.size();i++){
        std::cout<<imena[i]<<"| ";
        
    }
    */
    
    try{
       
       std::vector<std::set<std::string>> t =  Razvrstavanje(imena,broj_timova);
       
    for(int i (0); i < t.size();i++){
        std::cout<<"Tim "<< i + 1 << ": ";
        int j(0);
        for(auto skup : t[i])  {
            std::cout<<skup<< ((j!=(t[i].size()-1)) ? ", " : "");
            j++;
        }
        std::cout<<std::endl;
    }
    
    }catch(std::logic_error izuzetak){
        std::cout<<izuzetak.what()<<std::endl;
    }
	return 0;
	
	
	
	
	
	
}
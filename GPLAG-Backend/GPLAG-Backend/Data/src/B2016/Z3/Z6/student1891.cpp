/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>
#include <memory>




struct Dijete{
    std::string ime;
    std::shared_ptr<Dijete> sljedeci,prethodni;
};

    std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> v,int n){
    std::shared_ptr<Dijete> pocetak,prethodni;
    std::vector<std::set<std::string>>v1;
    int broj=0,broj_timova=v.size();
    if(n>broj_timova || n<1) throw std::logic_error("Izuzetak: Razvrstavanje nemoguce");
    int hasan=broj_timova%n;
    int e=0,radi=v.size();
    v1.resize(n);
   
    std::string pomocni;
    
    int velicina=v.size();
    
    while(broj!=velicina){
        std::shared_ptr<Dijete> novi{ new Dijete};
        novi->ime=v[broj];
        novi->sljedeci=nullptr;
        if(!pocetak) pocetak=novi;
        else prethodni->sljedeci=novi;
        prethodni=novi;
        broj++;
    }
    prethodni->sljedeci=pocetak;
    
    
    std::shared_ptr<Dijete> dodatni2,dodatni;
    
    dodatni=prethodni;
    dodatni2=pocetak;
    
        for(int i=0;i<hasan;i++){
       for(int k=0;k<(int(broj_timova/n)+1);k++) {
           pomocni="";
           pomocni=pocetak->ime;
           v1[e].insert(pomocni);
           
           pocetak=pocetak->sljedeci;
           
           radi--;
           dodatni->sljedeci=pocetak;
            
           int brojac=0,brojilo=0;
           for(int i=0;i<pomocni.length();i++){
               if((pomocni[i]>='0' && pomocni[i]<='9') || (pomocni[i]>='a' && pomocni[i]<='z') || (pomocni[i]>='A' && pomocni[i]<='Z'))
                brojilo++;
               
           }
            while(brojac<brojilo-1){
                dodatni=dodatni->sljedeci;
               pocetak=pocetak->sljedeci; 
               brojac++;
            }
           
           
       }e++;
    }
    
    
    
    for(int i=0;i<n-hasan;i++){  
     for(int k=0;k<int(broj_timova/n);k++){       
        
           pomocni="";
           pomocni=pocetak->ime;
           v1[e].insert(pomocni);
           
           
           pocetak=pocetak->sljedeci;
          
           dodatni->sljedeci=pocetak;
            
            radi--;
            
            
            
           int brojac=0,brojilo=0;
           for(int i=0;i<pomocni.length();i++){
               if((pomocni[i]>='0' && pomocni[i]<='9') || (pomocni[i]>='A' && pomocni[i]<='Z') || (pomocni[i]>='a' && pomocni[i]<='z'))
               brojilo++;
           }
            while(brojac<brojilo-1){
                dodatni=dodatni->sljedeci;
                pocetak=pocetak->sljedeci;
                brojac++;
            }
            
     
     }
     e++;
        
                                                                                                                                
                                                                                       
        
    }dodatni=dodatni2;                        
    pocetak=dodatni2; 
    for(int i=0;i<velicina;i++){
        pocetak=pocetak->sljedeci;
         dodatni->sljedeci=nullptr;
         dodatni->sljedeci=pocetak;
    }
        prethodni->sljedeci=nullptr;
       pocetak->sljedeci=nullptr;
       dodatni2->sljedeci=nullptr;
       dodatni->sljedeci=nullptr;
    return v1;
}
                                                                                                                                                                                                                                                                           

int main ()
{
    std::vector<std::set<std::string>> v;
    int k=1,n,broj;
    std::string s;
    std::vector<std::string>v1;
    std::cout<<"Unesite broj djece: ";
    std::cin>>broj;
    std::cin.clear();
    std::cin.ignore(10000,'\n');
    std::cout<<"Unesite imena djece: ";
    
    for(int i=0;i<broj;i++){
        s="";
        std::getline(std::cin,s);
        v1.push_back(s);
    }std::cout<<std::endl;
   std::cout<<"Unesite broj timova: ";
   std::cin>>n;
    try{
        v=Razvrstavanje(v1,n);
   
    
    for(int i=0;i<v.size();i++){
        auto it=v[i].begin();
        std::cout<<"Tim "<<k<<": ";
        while(it!=v[i].end()){
            std::cout<<*it++;
            if(it==v[i].end()) break;
            std::cout<<", ";
        }std::cout<<std::endl;
        k++;
    }}
    catch(std::logic_error izuzetak){
        std::cout<<izuzetak.what();
    }
  
	
	return 0;
}                                                                                                                                                                                          
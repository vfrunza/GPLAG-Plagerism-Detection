/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include<set>
#include<vector>
#include<iterator>
#include<stdexcept>
#include<string>
#include<cmath>


struct Dijete{
    std::string ime;
    Dijete *sljedeci;
};


int VelicinaImena (std::string s){
    int brojac(0);
    for(int i=0;i<s.size();i++){
        if((s[i]>='0' && s[i]<='9') || (s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z')){
            brojac++;
        }
    }
    return brojac;
}


std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> v, int br_timova){
    
    if(br_timova<1 || br_timova>v.size())
    throw std::logic_error ("Razvrstavanje nemoguce");
    
    std::vector<int> br_clanova(br_timova,std::abs(v.size()/br_timova));
    
    int mod(v.size()%br_timova);
    
    for(int i=0;i<br_timova;i++){
        if(i<mod){
            br_clanova[i]++;
        }
    }
    
    std::vector<std::set<std::string>> vec(br_timova);
    
    
    Dijete *pocetak(nullptr),*prethodni(nullptr);
   
    for(int i=0;i<v.size();i++){
        Dijete *novi(new Dijete);
        novi->ime=v[i];
        novi->sljedeci=nullptr;
        
        if(!pocetak) pocetak=novi;
        else prethodni->sljedeci=novi;
        prethodni=novi;
    }
    
    prethodni->sljedeci=pocetak;
    
 
   
    Dijete *p(pocetak);
    Dijete *q(prethodni);
    
    
    int vel(VelicinaImena(pocetak->ime)-1);
    
    for(int i=0;i<br_timova;i++){
        for(int j=0;j<br_clanova[i];j++){

            vec[i].insert(p->ime);

              auto z=p;
              
              z=z->sljedeci;
              q->sljedeci=z;
        
             delete p;
             
             p=z;
             
             if(i==br_timova-1 && j==br_clanova[br_timova-1]-1) continue;
            
            for(int k=0;k<vel;k++){
        
                p=p->sljedeci;
                q=q->sljedeci;
              // std::cout<<"{"<<q->ime<<"} ";
              
            }
 
        vel=VelicinaImena(p->ime)-1;
  
     }
        
   }
    
   return vec; 

}


int main ()
{
    
 
    
    try{
        
    std::cout<<"Unesite broj djece: ";
    int n;
    std::cin>>n;
    std::cin.clear();
    std::cin.ignore(100000,'\n');
    std::vector<std::string> s;
    std::cout<<"Unesite imena djece: ";
    for(int i=0;i<n;i++){
        std::string a;
        std::getline(std::cin,a);
        s.push_back(a);
    }
    std::cout<<"\nUnesite broj timova: ";
    int br;
    std::cin>>br;

    
    
   auto v(Razvrstavanje(s,br));
   
    
   for(int i=0;i<v.size();i++){
       std::cout<<"Tim "<<i+1<<": ";
        
         auto p(v[i].end());
          p--;
     
       
      for(auto it=v[i].begin();it!=v[i].end();it++){
          std::cout<<*it;
          if(it!=p)
          std::cout<<", ";
      }
      std::cout<<std::endl;
       
   }
    }
    catch(std::logic_error e){
        std::cout<<"Izuzetak: "<<e.what();
    }
   
    
	return 0;
}
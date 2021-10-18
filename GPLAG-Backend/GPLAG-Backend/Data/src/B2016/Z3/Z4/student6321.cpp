/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include<string>
#include<set>
#include<vector>
#include<list>
#include<stdexcept>
#include<cmath>


int VelicinaImena(std::string s){
    
    int brojac(0);
    for(int i=0;i<s.size();i++){
        if((s[i]>='0' && s[i]<='9') || (s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z')){
            
            brojac++;
        }
    }
    return brojac;
}

void Pomjeri(std::list<std::string>::iterator &it,std::list<std::string> &l, int br){

         for(int k=0;k<br;k++){

              if(it==l.end()) {

                it=l.begin();
  
            }
            
            it++;
    
        }
        if(it==l.end()) {
                
                it=l.begin();
        }
    
}

std::vector<std::set<std::string>>  Razvrstavanje (std::vector<std::string> v,int br_timova){
    
    if(br_timova<1 || br_timova>v.size())
    throw std::logic_error ("Razvrstavanje nemoguce");
    
    
    std::vector<int> br_clanova(br_timova,std::abs(v.size()/br_timova));
    
    int mod(v.size()%br_timova);
    
    for(int i=0;i<br_timova;i++){
        if(i<mod){
            br_clanova[i]++;
        }
        
    }
    
    
    
    std::list<std::string> l;
    for(int i=0;i<v.size();i++){
        l.push_back(v[i]);
    }


   
   std::vector<std::set<std::string>> p(br_timova);
 
      auto it(l.begin());
   
     for(int j=0;j<br_timova;j++)
     {
          for(int i=0;i<br_clanova[j];i++)
         {
   
             p[j].insert(*it);
      
             int br1(VelicinaImena(*it));
 
             it=l.erase(it);
 
             Pomjeri(it,l,br1-1);
   
         }
     }
    
    return p;
    
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

    for(int i=0;i<br;i++){
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
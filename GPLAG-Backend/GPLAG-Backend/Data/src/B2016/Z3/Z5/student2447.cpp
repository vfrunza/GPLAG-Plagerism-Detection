#include <list>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <set>
#include <iterator>

struct Dijete{
    std::string ime;
    Dijete *sljedeci;
};


std::vector<std::set<std::string>>Razvrstavanje(std::vector<std::string> v,int broj_timova){
   
    if(broj_timova>v.size() || broj_timova<=0) throw std::logic_error("Razvrstavanje nemoguce");
   
    std::list<std::string> lista;
    
    for(int i=0;i<v.size();i++){
        lista.push_back(v[i]);
    }
    
    int broj_clanova_kod_prvih;
    int broj_clanova_kod_ostalih;
    int broj_prvih;
    
    broj_clanova_kod_prvih = int (v.size()/broj_timova)+1;
    broj_clanova_kod_ostalih = int (v.size()/broj_timova);
    broj_prvih=(v.size())%broj_timova;
    
    std::vector<std::set<std::string>>imena_timova;


    std::list<std::string>::iterator it1(lista.begin());
    std::set<std::string>skup;
    
    
        
        for(int i=0;i<broj_timova;i++){
           // int velicina=(*it1).length();
           int velicina(0);
           for(int i=0;i<(*it1).length();i++){
               if(((*it1)[i]>='A' && (*it1)[i]<='Z') || ((*it1)[i]>='a' && (*it1)[i]<='z') || ((*it1)[i]>='0' && (*it1)[i]<='9'))
               velicina++;
           }
           
           
           if((i<broj_prvih && std::distance(skup.begin(),skup.end())<broj_clanova_kod_prvih)){
               skup.insert(*it1);
              
               if(std::distance(skup.begin(),skup.end())==broj_clanova_kod_prvih){
                   imena_timova.push_back(skup);
                   skup.erase(skup.begin(),skup.end());
               }
             else i--;
             
             
           }
           
           else if((i>=broj_prvih && std::distance(skup.begin(),skup.end())<broj_clanova_kod_ostalih)){
               skup.insert(*it1);
              
               if(std::distance(skup.begin(),skup.end())==broj_clanova_kod_ostalih){
                   
                   imena_timova.push_back(skup);
                   skup.erase(skup.begin(),skup.end());
               }
             else i--;
               
               
               
           }
        
           
        it1=lista.erase(it1);
        it1--;
        if(lista.size()==0) break;
        for(int i=0;i<velicina;i++)  if(++it1==lista.end()) it1=lista.begin();
        }  
    
   return imena_timova;
}


int main ()
{
    
    int n,x;
    std::string s;
    std::vector<std::string> vs;
    std::cout<<"Unesite broj djece: ";
    std::cin>>n;
    std::cin.ignore(10000, '\n');
    std::cin.clear();
    
    std::cout<<"Unesite imena djece: ";
    for(int i=0;i<n;i++){
        std::getline(std::cin,s);
        vs.push_back(s);
    }
    
    std::cout<<"\nUnesite broj timova: ";
    std::cin>>x;
  
   try{ 
    
    std::vector<std::set<std::string>> broj;
    broj=Razvrstavanje(vs,x);
    
   for(int i=0;i<broj.size();i++){
        std::cout<<"Tim "<<i+1<<": ";
       for(auto it=broj[i].begin();it!=broj[i].end();it++){
         
          if(std::distance(it, broj[i].end())==1) std::cout<<*it;
          else std::cout<<*it<<", ";
       }
       std::cout<<std::endl;
   }
    
   }
   catch(...){
       std::cout<<"Izuzetak: Razvrstavanje nemoguce";
   }
    
	return 0;
}
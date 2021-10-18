/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <set>
#include <memory>
#include <tuple>
#include <map>
#include <vector>
#include <stdexcept>
#include <algorithm>
typedef std::map<std::string, std::vector<std:: string>> Knjiga;  

std::vector<std::pair<std::string,int>> VratiRijeciSaIsteStranice (std::string s1) {
    std::transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    auto it(s1.begin());
    std::vector<std::pair<std::string,int>> SveRijeciSaIsteStranice ;
    int brojac{0};
    while(it!=s1.end()) {
        std::string CijelaRijec;
        
        while (!((*it>='a' && *it<='z')|| (*it>='A' && *it<='Z'))){
            
        if(it != s1.end()) it++; 
        brojac++;
        }
        while((*it>='a' && *it<='z')|| (*it>='A' && *it<='Z')){
        
        CijelaRijec+=*it++ ;
        brojac++;
        }
        SveRijeciSaIsteStranice.push_back(std::make_pair(CijelaRijec,brojac - CijelaRijec.length()));
    }
        return SveRijeciSaIsteStranice ;
}






std::map<std::string,std::set<std::tuple<std::string,int,int>>> KreirajIndeksPojmova(Knjiga book) {
    
    
    std::map<std::string,std::set<std::tuple<std::string ,int ,int >>> OvoSeVracaIzFunkcije;
    
    for(auto it(book.begin());it!=book.end();it++) {
        
        auto vec(it->second);
        for(int j{0};j<vec.size();j++) {
            
        auto VektorParova(VratiRijeciSaIsteStranice(vec[j]));    
        
        for(int k {0};k<VektorParova.size();k++) {
            //pomocni iterator
            
            auto par(VektorParova[k]);
            std::string pom (par.first);
            auto trazilica(OvoSeVracaIzFunkcije.find(pom));
            std::tuple<std::string ,int ,int > t(std::make_tuple(it->first,j+1,(par.second)));
            if (trazilica==OvoSeVracaIzFunkcije.end() ) {
                std::set<std::tuple<std::string ,int ,int >> pomocni{t};
                OvoSeVracaIzFunkcije.insert(std::make_pair(pom,pomocni));

            }
            else {
                
                (trazilica->second).insert(t);
                
            }
            
        }
        }
        
    }
    return OvoSeVracaIzFunkcije;
}

std::set<std::tuple<std::string,int,int>>PretraziIndeksPojmova(std::string k,std::map<std::string,std::set<std::tuple<std::string,int,int>>> tuzno){
    
    auto it(tuzno.find(k));
    if(it==tuzno.end()) 
    throw std::logic_error("Unesena rijec nije nadjena!\n") ;
    
    return it->second;
    
    
}

void IspisiIndeksPojmova(std::map<std::string,std::set<std::tuple<std::string,int,int>>> tuznije){
     for(auto it(tuznije.begin());it!=tuznije.end();it++) {
        std::cout<<(it->first)<<": ";
        for(auto iter(it->second.begin());iter!=(it->second.end());iter++) {
         auto pom(iter);   
        std::tuple<std::string, int, int> pomocna(*iter);
       if(++pom!=(it->second.end())) std::cout<<std::get<0>(pomocna)<<"/"<<std::get<1>(pomocna)<<"/"<<std::get<2>(pomocna)<<", ";
        else
        std::cout<<std::get<0>(pomocna)<<"/"<<std::get<1>(pomocna)<<"/"<<std::get<2>(pomocna);
    }
        std::cout<<std::endl ;
    }
    
}
int main ()
{
    std::string n;
    Knjiga knjiga ;
    do{
        std::string k;
        std::vector<std::string> vec ;
        
        int brojac{1} ;
         std::cout<<"Unesite naziv poglavlja: ";
         std::getline(std::cin,n);
         
         if(n!=".") do{
         std::cout<<"Unesite sadrzaj stranice "<<brojac++<<": " ;
         std::getline(std::cin,k);
          if(k!=".") vec.push_back(k);
         }while(k!=".");
             
             
           if(n!=".")  knjiga.insert(std::make_pair(n,vec));
    } while(n!=".");
    
    
   auto mapaludila( KreirajIndeksPojmova(knjiga)) ;
  
  std::cout<<"\nKreirani indeks pojmova: \n";
  IspisiIndeksPojmova(mapaludila);
   
   std::string novi;
   do {
       
       std::cout<<"Unesite rijec: ";
       
       std::getline(std::cin,novi);
       if(novi!= ".")try{
       auto skup(PretraziIndeksPojmova(novi,mapaludila));
       if(novi!=".") for(auto iter(skup.begin());iter!=skup.end();iter++) {
            
        std::tuple<std::string, int, int> pomocna(*iter);
        std::cout<<std::get<0>(pomocna)<<"/"<<std::get<1>(pomocna)<<"/"<<std::get<2>(pomocna)<<" ";
    }
        std::cout<<std::endl ;
       }
       catch(std::logic_error l)
       {
           std::cout<<l.what();
       }
   } while (novi!=".");
   
    
	return 0;
}

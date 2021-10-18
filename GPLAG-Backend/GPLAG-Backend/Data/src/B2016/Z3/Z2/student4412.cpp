/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <stdexcept>

std::set<int> PretraziIndeksPojmova(std::string trazena_rijec, std::map<std::string, std::set<int>> mapa){
    
    auto i = mapa.begin();
    for(int j=0; j<mapa.size(); j++ ){
        if(i->first == trazena_rijec) return i->second;
        i++;
    }
    throw std::logic_error("Unesena rijec nije nadjena!");
        
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> mapa){
    auto i = mapa.begin();
    for(int j=0; j<mapa.size(); j++){
        std::cout<<i->first <<": ";
        int k(0);
        for(auto broj : i->second) {
            
            if(k==(i->second).size()-1) std::cout<<broj;
            else std::cout<<broj <<",";
            k++;
        }
        std::cout<<std::endl;
        i++;
    }
}
bool DaLiImaVecUMapi(const std::string &s, const std::map<std::string, std::set<int>> &mapa){
    
    auto i = mapa.begin();
    for(int j=0; j<mapa.size(); j++){
        if(i->first == s) return true;
        i++;
    }
    return false;
}
std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string s){
    
    std::map<std::string, std::set<int>> mapa; 
    for(int i=0; i< s.size();i++)
        if(s[i]>='A' && s[i]<='Z') s[i]=s[i]+'a'-'A';
    
    for(int i = 0; i<s.size(); i++){
        if(((s[i]>='A' && s[i]<='Z')
            || (s[i]>='a' && s[i]<='z')
            || (s[i]>='0' && s[i]<='9')) && (i==0 || !((s[i-1]>='A' && s[i-1]<='Z')
                                                        || (s[i-1]>='a' && s[i-1]<='z')
                                                        || (s[i-1]>='0' && s[i-1]<='9'))) ){
                
                std::string nadjena_rijec;
                while(i<s.size() && ((s[i]>='A' && s[i]<='Z')
                        || (s[i]>='a' && s[i]<='z')
                        || (s[i]>='0' && s[i]<='9')))
                             {
                            
                            nadjena_rijec+=s[i];
                            i++;
                        }
              
                std::set<int> skup_mjesta;
                for(int j=0; j<s.size(); j++){
                    if(s[j]==nadjena_rijec[0]){
                        int zapamti_pocetak=j;
                        int k = 0;
                        while(s[j]==nadjena_rijec[k] && j<s.size() && k<nadjena_rijec.size()){
                            j++;
                            k++;
                        }
                        
                        
                        if(k==nadjena_rijec.size() && !((s[j]>='A' && s[j]<='Z')
                        || (s[j]>='a' && s[j]<='z')
                        || (s[j]>='0' && s[j]<='9')) && (zapamti_pocetak==0 || !((s[zapamti_pocetak-1]>='A' && s[zapamti_pocetak-1]<='Z')
                                                                            || (s[zapamti_pocetak-1]>='a' && s[zapamti_pocetak-1]<='z')
                                                                            || (s[zapamti_pocetak-1]>='0' && s[zapamti_pocetak-1]<='9')))){
                            skup_mjesta.insert(zapamti_pocetak);
                       
                        }
                    }
                }
             
                if(DaLiImaVecUMapi(nadjena_rijec, mapa) == false){
                    mapa.insert(std::pair<std::string,std::set<int>>(nadjena_rijec,skup_mjesta));
                   
                }
                
                
            } 
            
    }
    return mapa;
}


int main ()
{
   std::string s; 
   std::cout<<"Unesite tekst: "; 
   std::getline(std::cin, s);
   auto mapa = KreirajIndeksPojmova(s);
   IspisiIndeksPojmova(mapa);
   for(;;){
       std::string rijec;
       std::cout<<"Unesite rijec: ";
       std::getline(std::cin, rijec);
       if(rijec ==".") break;
       try{
           std::set<int> skup = PretraziIndeksPojmova(rijec,mapa);
           for(auto element_skupa : skup) std::cout<<element_skupa << " ";
           std::cout<<std::endl;
       }
       catch(std::logic_error e){
           std::cout<<e.what()<<std::endl;
       }
   }
   
	return 0;
}
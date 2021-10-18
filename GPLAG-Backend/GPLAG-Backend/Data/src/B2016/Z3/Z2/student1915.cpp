/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <vector>
#include <set>
#include <stdexcept>
std::map<std::string,std::set <int>>KreirajIndeksPojmova(std::string s){
      
      std::map<std::string , std::set <int>>novi;
    
    for(int i=0;i<s.size();i++){
          std::string rijec;
          int br(0);
          while(s[i]!=' ' && s[i]!='\0'){
                rijec+=s[i];
                i++;
                br++;
          }
          i-=br;
        novi[rijec].insert(i);
        // novi[rijec]=i;
         // novi.insert(std::make_pair(rijec,i));
        
          i+=br;
       
         
    }
  return novi;  
}
std::set<int>PretraziIndeksPojmova(std::string s, std::map<std::string, std::set<int> >mapa){
     
     std::set<int>vek;
     
  
          std::map<std::string,std::set<int>>::iterator it(mapa.begin());
     
          it=mapa.find(s);
          if(!mapa.count(s))std::logic_error ("Unesena rijec nije nadjena!");
          else
          vek= it->second;
          
     
   
     
 return vek;    
}
int main ()
{
      std::string s;
      std::cout<<"Unesite tekst: ";
      std::getline(std::cin,s);
      std::map<std::string,std::set<int>>mapa;  
      mapa=KreirajIndeksPojmova(s);
      for(auto it=mapa.begin();it!=mapa.end();it++){
            std::cout<< it->first <<": ";
           
           for(auto x:it->second){
                std::cout<<x<<" ";
           }
          
           
           
          
           std::cout<<std::endl;
      }
      return 0;
            
        /*    if(itt.size()!=0){
                 std::cout<<itt.get(0)->second;
                 for(int i=1;i<itt.size();i++)
                 std::cout<<","<<itt.get(i)->second;
            }
            */
            
         
         
      }
/*      try{
      std::string rijec;
      while(1){
      std::cout<<"Unesite rijec: ";
      std::getline(std::cin,rijec);
      if(std::getline(std::cin,rijec)=='.')break;
      
      
    
      std::set<int>vek;
      vek=PretraziIndeksPojmova(s,mapa);
      for(auto itt: vek){
           std::cout<<itt;
      }
      }
      }
      catch(std::logic_error izuzetak){
           std::cout<<izuzetak.what();
           
      }
      */
//	return 0;
//}
/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stdexcept>
bool NijeSlovo(char c) {
   //Ako je tacka broj i sl.
   if(c>='a' && c<='z') return true;
   return false;
}
std::map<std::string,std::set<int>> KreirajIndeksPojmova(std::string s) {
   for(int i(0);i<s.length();i++) {
      if(s[i]>='A' && s[i]<='Z') {
         s[i]+='a'-'A';
      }
   }
   std::map<std::string, std::set<int>>  Mapa;
   
   for(int i(0);i<s.length();i++) {
       if(s[i]==' ') i++;
       std::string pomoc;
       int j(i);
       while(s[i]!=' ' && s[i]!=s.length()) {
          pomoc+=s[i];
          i++;
       }
       
       if(!Mapa.count(pomoc)) {
          std::set<int> pozicija{j};
          Mapa[pomoc]=pozicija;
       }
       //ako ima da ubaci poziciju;
       else {
          auto it(Mapa.find(pomoc));
          it->second.insert(j);
       }
   }
   return Mapa;
}
std::set<int> PretraziIndeksPojmova(std::string rijec, std::map<std::string, std::set<int>>  Mapa) {
   if(Mapa.count(rijec)) return Mapa[rijec];
   else throw std::logic_error ("Pojam nije nadjen");
}
void IspisiIndeksPojmova(const std::map<std::string, std::set<int>> & Mapa) {
    for(auto it=Mapa.begin();it!=Mapa.end(); it++) {
        std::cout<<it->first<<": ";
        int brojac(it->second.size());
        for(auto x : it->second) {
            if(brojac!=1) std::cout<<x<<",";
            else
            std::cout<<x;
            brojac--;
        }
        std::cout<<std::endl;
    }
}
int main ()
{
   std::cout<<"Unesite tekst: ";
   std::string s;
   std::getline(std::cin, s);
   auto  Mapa1(KreirajIndeksPojmova(s));
   IspisiIndeksPojmova(Mapa1);
   for(;;) {
       std::cout<<"Unesite rijec: ";
       std::string rijec;
       std::getline(std::cin, rijec);
       if(rijec==std::string(".")) break;
       try {
        auto nadji(PretraziIndeksPojmova(rijec,Mapa1));
        
        
        for(auto x: nadji) {
            std::cout<<x<<" "; 
            }
        std::cout<<std::endl;
       }
       catch(std::logic_error tekst) {
           std::cout<<"Unesena rijec nije nadjena!";
           std::cout<<std::endl;
           
       }
   }
	return 0;
}












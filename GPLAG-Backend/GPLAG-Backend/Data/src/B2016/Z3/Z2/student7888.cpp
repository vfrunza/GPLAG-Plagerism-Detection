#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>
#include <cctype>

    void PretvoriUMala(std::string &S) {
      for ( int i = 0 ; i < S.size(); i++ ) {
       if ( S[i]>='A' && S[i]<='Z' ) S[i] = S[i]+32;
      }
    }
 std::map<std::string,std::set<int>> KreirajIndeksPojmova(std::string S) {
     std::map<std::string,std::set<int>> Mapa;
     PretvoriUMala(S);
     for ( int i = 0 ; i < S.size(); i++) {
         while(!((S[i]>='a' && S[i]<='z') || (S[i]>='0' && S[i] <='9')) && i < S.size()) i++;
          std::string help;   auto j(i);
         while (((S[i]>='a' && S[i]<='z') || (S[i]>='0' && S[i] <='9')) && i < S.size()) {
          help.push_back(S[i]);
          i++;
         }
          auto it(Mapa.find(help));
          if ( it == Mapa.end())  Mapa[help].insert(j);
           else  it->second.insert(j);
     }
       return Mapa;
 }
  std::set<int> PretraziIndeksPojmova(std::string S,std::map<std::string,std::set<int>> Mapa) {
         std::set<int> skup;
         for ( auto it = Mapa.begin(); it != Mapa.end(); it++) {
          if ( S == it->first )  for (auto it2 = (it->second).begin(); it2 != (it->second).end();it2++) skup.insert(*it2);
        }
         int brojac(0);
         for ( auto it = skup.begin(); it != skup.end(); it++) brojac++;
         if ( brojac == 0 ) throw std::logic_error("Pojam nije nadjen");
         return skup;
  }
  
   void IspisiIndeksPojmova(std::map<std::string,std::set<int>> Mapa) {
 for (auto it1 = Mapa.begin(); it1 != Mapa.end(); it1++ ) {
  std::cout<<it1->first<<": ";
    auto pomocni((it1->second).end());
  pomocni--;
  for ( auto it2 = (it1->second).begin(); it2 != (it1->second).end();it2++) {

   if ( it2 == pomocni ) {
    std::cout<<*it2;
    break;
   }
   std::cout<<*it2<<",";
   
  }
  std::cout<<std::endl;
 }
   }
int main ()
{
 std::cout<<"Unesite tekst: ";
 std::string S;
 std::getline(std::cin,S);
 std::map<std::string,std::set<int>>Mapa{KreirajIndeksPojmova(S)};
 IspisiIndeksPojmova(Mapa);
 for(;;){
  std::cout<<"Unesite rijec: ";
  std::string rijeci;
  std::getline(std::cin,rijeci);
  if (rijeci == ".") break;
  std::set<int> skup;
  try {
  skup = PretraziIndeksPojmova(rijeci,Mapa);
  }
  catch (std::logic_error izuzetak) {
   std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
   continue;
  }
  for ( auto it = skup.begin(); it != skup.end(); it++) std::cout<<*it<<" ";
  std::cout<<std::endl;

 }
 
 
 
	return 0;
}
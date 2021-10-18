/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <cstring>
#include <utility>
#include <algorithm>

int BrojRijeci(std::string s){
    if(s.size()==0)
        return 0;
    int brojac(0);    
    for(int i=0; i<s.size(); i++){
        while(i<s.size() && !((s[i]>='A' && s[i]<='Z') ||  (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')))
            i++;
        if(i==s.size()) break;
        brojac++;
        while(i<s.size() && ((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')))
        i++;    
    }
    return brojac;
}
std::string PretvoriUMale(std::string s){
    for(int i=0; i<s.size(); i++){
        if(s[i]>='A' && s[i]<='Z')
            s[i]+='a'-'A';
}
    return s;
}
std::string Rijec(std::string s, int i){
    std::string x;
    while(i<s.size() && ((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))){
        x.push_back(s[i]);
        i++;
    }
    return x;
}


std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string s){
    s=PretvoriUMale(s);
    std::map<std::string, std::set<int>> mapa;
    for(int i=0; i<s.size(); i++){
        while(i<s.size() && !((s[i]>='A' && s[i]<'Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')))
            i++;
            if(i==s.size()) break;
        std::set<int> skup;
        skup.insert(i);
        std::string a(Rijec(s, i));
            for(int j=i+1; j<s.size(); j++){
                while(!((s[j]>='A' && s[j]<='Z') || (s[j]>='a' && s[j]<='z') || (s[j]>='0' && s[j]<='9')) && j<s.size())
                    j++;
                if(j==s.size()) break;    
                std::string b(Rijec(s, j));
                if(a==b) skup.insert(j);
                while(j<s.size() && ((s[j]>='A' && s[j]<='z') || (s[j]>='a' && s[j]<='z') || (s[j]>='0' && s[j]<='9')))
                    j++;
            }
        mapa.insert(std::make_pair(a, skup));
    while(i<s.size() && ((s[i]>='A' && s[i]<'Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')))
        i++;
    }
    return mapa;
}

std::set<int> PretraziIndeksPojmova(std::string s, std::map<std::string, std::set<int>> mapa){
        auto it(mapa.find(s));
        if(it==mapa.end()) throw std::logic_error ("Pojam nije nadjen");
        else return it->second;
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> mapa){
    for(auto it=mapa.begin(); it!=mapa.end(); it++){
        std::set<int> skup(it->second);
        std::cout << it->first << ": ";
        for(auto x=skup.begin(); x!=skup.end(); x++){
            if(x!=--skup.end())
         std::cout << *x << ",";
         else std::cout << *x;
        }
        std::cout << std::endl;
        }
    }
int main ()
{
    std::cout << "Unesite tekst: ";
    std::string s;
    std::getline(std::cin, s);
   auto mapa(KreirajIndeksPojmova(s));
   IspisiIndeksPojmova(mapa);
   std::string x;
   do{ 
       std::cout << "Unesite rijec: ";
       std::getline(std::cin, x);
       if(x==".") break;
       try{
           std::set<int> skup (PretraziIndeksPojmova(x, mapa));
           for(int x: skup) std::cout << x << " ";
       }
       catch(std::logic_error izuzetak){
           std::cout << "Unesena rijec nije nadjena!";
       } 
       std::cout << std::endl;
      // if((std::cin.peek())=='.') break;
   } while(x!=".");
	return 0;
}
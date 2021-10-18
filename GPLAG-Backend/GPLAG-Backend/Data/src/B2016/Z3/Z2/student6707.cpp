/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stdexcept>
void PretvaraUMalaSlova(std::string &s)
{
    for(int i=0; i<s.length(); i++)
        {
           if(s[i]>=65 && s[i]<=90) s[i]+=32;
        }
}

std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string tekst)
{
    std::map<std::string, std::set<int>> pojmovi;
    
    auto it1=tekst.begin();
    auto it2 =tekst.end();
     
     while(it1<it2)
     {
         while((*it1<48 || (*it1>57 && *it1<65) || (*it1>90 && *it1<97) || *it1>123)) it1++;
         
         auto pomocni=it1;
         while(((*pomocni>47 && *pomocni<58) || (*pomocni>64 && *pomocni<91) || (*pomocni>96 && *pomocni<123)))pomocni++;
         if(pomocni<=it2){
         std::string s=tekst.substr(it1-tekst.begin(), pomocni-it1);
         PretvaraUMalaSlova(s);
         pojmovi[s].insert(it1-tekst.begin());
        it1=pomocni;
         }
     }
    return pojmovi;
    
}
std::set<int> PretraziIndeksPojmova (std::string s,std::map<std::string, std::set<int>> mapa)
{
    std::set<int> skup;
    PretvaraUMalaSlova(s);
    auto it(mapa.find(s));
    if(it == mapa.end()) throw std::logic_error("Unesena rijec nije nadjena!");
    for(auto x=mapa.begin(); x!=mapa.end(); x++)
    {
        if(s==x->first) {
            skup=x->second;
    }
  }
 return skup;
}
void IspisiIndeksPojmova(std::map<std::string, std::set<int>> mapa)
{
    for(auto x=mapa.begin(); x!=mapa.end(); x++)
    {
        std::cout<<x->first<<": ";
      auto skupovi=x->second;
        for(auto it1=skupovi.begin(); it1!=skupovi.end(); it1++) {
            if(it1!=(--(skupovi.end())))
            std::cout << *it1 << ",";
            else std::cout << *it1;
        }
        
        std::cout << std::endl; 

    
       
    }
     std::cout<<std::endl;
}

int main (){
    std::string tekst;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin,tekst);
    auto mapa=KreirajIndeksPojmova(tekst);
    IspisiIndeksPojmova(mapa);
    for(;;)
    {
        std::cout<<"Unesite rijec: ";
        std::string s;
        std::cin>>s;
        
        if(s==".") break;
        try{
           
        auto skup=PretraziIndeksPojmova(s,mapa);
        for(auto x: skup) std::cout<<x<<" ";
        std::cout<<std::endl;
        }
        catch(std::logic_error y)
        {
            std::cout<<y.what()<<std::endl;
        }
    }
	return 0;
}
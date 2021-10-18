/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <utility>
#include <iterator>
#include <stdexcept>
std::map<std::string, std::set<int>> KreirajIndeksPojmova (std::string str) {
    std::map<std::string, std::set<int>> rezultat;
    std::set<int> prazan_skup;
    std::vector<std::string> spisak_rijeci;
    for(int i=0; i<str.size(); i++) {if(str[i]>='A' && str[i]<='Z') str[i]=str[i]+32;
        if(str[i]=='\n' || str[i]<32) {str[i]='\0';
        str.resize(i+1);}
    }
    for(int i=0; i<str.size(); i++) {
        for(int j=str.size()-1; j>=i; j--) {
            std::string rijec;
            for(int k=i; k<=j; k++) {
                rijec.push_back(str[k]);
            } if(i==0 || (str[i-1]<'0' || (str[i-1]>'9' && str[i-1]<'A') || (str[i-1]>'Z' && str[i-1]<'a') || str[i-1]>'z')) {
                if(j==str.size()-1 || (str[j+1]<'0' || (str[j+1]>'9' && str[j+1]<'A') || (str[j+1]>'Z' && str[j+1]<'a') || str[j+1]>'z')) {
                    bool jedinstvena=true;
                    for(int m=0; m<rijec.size(); m++) {
                        if(rijec[m]<'0' || (rijec[m]>'9' && rijec[m]<'A') || (rijec[m]>'Z' && rijec[m]<'a') || rijec[m]>'z') jedinstvena=false;
                    }
                    for(int l=0; l<spisak_rijeci.size(); l++) {
                   if(rijec==spisak_rijeci[l]) jedinstvena=false;
                    }
                    if(jedinstvena) rezultat.insert(std::make_pair(rijec, prazan_skup));}}}}
    for(int i=0; i<str.size(); i++) {
        for(int j=str.size()-1; j>=i; j--) {
            std::string word;
            for(int k=i; k<=j; k++) {word.push_back(str[k]);}
            auto it(rezultat.find(word));
            if(it!=rezultat.end()) it->second.insert(i);
        }
    }
    return rezultat;
}
std::set<int> PretraziIndeksPojmova(std::string rijec, std::map<std::string, std::set<int>> indekspojmova) {
    std::set<int> rezultat;
    auto p(indekspojmova.find(rijec));
    if(p==indekspojmova.end()) throw std::logic_error("Unesena rijec nije nadjena!");
    else rezultat=p->second;
    return rezultat;
}
void IspisiIndeksPojmova(std::map<std::string, std::set<int>> indekspojmova) {
    for(auto it=indekspojmova.begin(); it!=indekspojmova.end(); it++) {
        std::cout<<it->first<<": ";
        auto t((it->second).begin()), v((it->second).end());
        auto zamjena=t;
        for(int i=0; i<std::distance(t, v); i++) {
        if(i!=std::distance(t,v)-1) std::cout<<*zamjena++<<",";
        else std::cout<<*zamjena;
        } std::cout<<std::endl;
    }
}
int main ()
{
   std::string tekst, rijec;
   std::cout<<"Unesite tekst: ";
   std::getline(std::cin, tekst);
   auto a(KreirajIndeksPojmova(tekst));
   IspisiIndeksPojmova(a);
   while(rijec!=".") {
       std::cout<<"Unesite rijec: ";
       std::cin>>rijec;
       if(rijec!=".") {
       try{
          auto b=PretraziIndeksPojmova(rijec, a);
          for(auto x: b) std::cout<<x<<" ";
       }  catch(std::logic_error e) {std::cout<<e.what();}}
       std::cout<<std::endl;
   } return 0;
}
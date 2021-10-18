/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iterator>

std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string s){
    std::map<std::string,std::set<int>> mapa;
    int index;
    std::vector<std::string> vektor_stringova;
    for(int i=0;i<s.length();i++){
        std::string pomocni;
        index=i;
        int brojac(0);
        while(!((s[i]>=' ' && s[i]<='/') ||  s[i]=='\0')){
            brojac++;
            i++;
        }
        if((s[i]>=' ' && s[i]<='/') || s[i]=='\0'){
            vektor_stringova.resize(1);
            pomocni=s.substr(index,brojac);
            int a(0);
            for(int i=0;i<vektor_stringova.size();i++)if(vektor_stringova[i]==pomocni){a=1;
            mapa[pomocni].insert(index);
            break;}
            if(a==0){
                vektor_stringova.push_back(pomocni);
                mapa[pomocni].insert(index);
            }
        }
        pomocni.clear();
    }
    return mapa;
}

std::set<int> PretraziIndeksPojmova(std::string s,std::map<std::string,std::set<int>> mapa){
    std::set<int> skup;
    for(auto it=mapa.begin();it!=mapa.end();it++){
        auto it3(mapa.find(s));
        if(it3==mapa.end())throw std::logic_error("Unesena rijec nije nadjena!");
        else if(it->first == s)
            for(auto it2=it->second.begin();it2!=it->second.end();it2++)skup.insert(*it2);
        }
    
    return skup;
}

void IspisiIndeksPojmova(std::map<std::string,std::set<int>> mapa){
    for(auto it=mapa.begin();it!=mapa.end();it++){
        std::cout << it->first <<": " ;
        int brojac(0);
        for(auto it2=it->second.begin(); it2!=it->second.end();it2++){
            brojac++;
            if(brojac==it->second.size())std::cout << *it2 ;
            else {
                std::cout<<*it2 <<",";
            }
        }
        std::cout<<std::endl;
    }
}
int main ()
{
    std::string s;
    std::cout << "Unesite tekst: ";
    std::getline(std::cin,s);
    std::map<std::string,std::set<int>> mapa;
    mapa=KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(mapa);
    try{
      std::string a;
      for(;;){
      std::cout << "Unesite rijec: ";   
      std::getline(std::cin,a);
      if(a==".")break;
      std::set<int> skup;
      skup=PretraziIndeksPojmova(a,mapa);
      for(auto x: skup)std::cout << x << " ";
      std::cout << std::endl;
      }
      
    }catch(std::logic_error e){
        std::cout << e.what() << std::endl;
        std::cout << "Unesite rijec: ";   
    }
	return 0;
}
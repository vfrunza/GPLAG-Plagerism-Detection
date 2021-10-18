#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <set>
#include <stdexcept>

std::string PretvoriUMala(std::string rijec){
    for(auto &i: rijec){
        if(i>='A' && i<='Z')
            i+=32;
    }
    return rijec;
}

std::map<std::string,std::set<int>> KreirajIndeksPojmova(std::string tekst){
    //razdvoji rijeci
    std::set<std::string> spisak_rijeci;
    for(auto iter=tekst.begin(); iter<tekst.end(); iter++){
        if(*iter==' ' || *iter<'0' || (*iter>'9' && *iter<'A') || (*iter>'Z' && *iter<'a') || *iter>'z'){
        
        } else {
            std::string pomoc;
            while(*iter!=' ' && ((*iter>='0' && *iter<='9') || (*iter>='A' && *iter<='Z') || (*iter>='a' && *iter<='z')) && iter!=tekst.end()){
                pomoc.push_back(*iter);
                iter++;
            }
            pomoc=PretvoriUMala(pomoc);
            spisak_rijeci.insert(pomoc);
        }
    }
    
    std::map<std::string,std::set<int>> vrati;
    //prolazi kroz tekst i mape
    tekst=PretvoriUMala(tekst);
    for(auto izdvojena: spisak_rijeci){
        int i(0);
        std::set<int> pozicija;
        auto iter1(izdvojena.begin());
        auto iter2(tekst.begin());
        while(iter2!=tekst.end()){
            if(iter1!=izdvojena.end() && iter2!=tekst.end() && *iter1==*iter2){
                auto iter1_pomoc(iter1);
                auto iter2_pomoc(iter2);
                while(iter1_pomoc!=izdvojena.end() && iter2_pomoc!=tekst.end() && *iter1_pomoc==*iter2_pomoc){
                    if(iter1_pomoc==izdvojena.end()){
                        pozicija.insert(i);
                        break;
                    } else {
                        iter1_pomoc++;
                        iter2_pomoc++;
                    }
                    if(iter1_pomoc==izdvojena.end())
                        pozicija.insert(i);
                }
            }
            if(iter2==tekst.end()) break;
            else iter2++;
            i++;
        }
        vrati.insert(std::make_pair(izdvojena,pozicija));
    }
    return vrati;
}

std::set<int> PretraziIndeksPojmova(std::string rijec, std::map<std::string,std::set<int>> indeks_pojmova){
    std::set<int> pozicije;
    auto it(indeks_pojmova.find(rijec));
    if(it==indeks_pojmova.end()) 
        throw std::logic_error("Pojam nije nadjen");
    else 
        pozicije=it->second;
    return pozicije;
}

void IspisiIndeksPojmova(std::map<std::string,std::set<int>> indeks_pojmova){
    for(auto el_mape=indeks_pojmova.begin(); el_mape!=indeks_pojmova.end(); el_mape++){
        std::cout << el_mape->first << ": ";
        int za_zarez(0);
        for(auto brojevi: el_mape->second){
            za_zarez++;
            if(za_zarez==el_mape->second.size())
                std::cout << brojevi;
            else 
                std::cout << brojevi <<",";
        }
        std::cout << std::endl;
    }
}

int main ()
{
    std::string tekst;
    std::cout << "Unesite tekst: ";
    std::getline(std::cin,tekst);
    auto indeks_pojmova=KreirajIndeksPojmova(tekst);
    IspisiIndeksPojmova(indeks_pojmova);
    std::string rijec;
    do{
      std::cout << "Unesite rijec: ";
      std::cin >> rijec;
      if(rijec==".")
        break;
      try{
        auto indeks=PretraziIndeksPojmova(rijec,indeks_pojmova);
        for(auto x: indeks)
            std::cout << x << " ";
        std::cout << std::endl;
      } catch(...){
          std::cout << "Unesena rijec nije nadjena!" << std::endl;
      }
    } while(rijec!=".");
	return 0;
}
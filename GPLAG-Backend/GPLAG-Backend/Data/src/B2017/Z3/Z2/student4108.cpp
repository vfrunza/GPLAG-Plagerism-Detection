/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <tuple>
#include <utility>
#include <string>
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>
#include <cctype>
#include <stdexcept>

typedef std::map<std::string, std::vector<std:: string>> Knjiga;

std::string PretvoriUMala(std::string a){
    std::transform(a.begin(), a.end(), a.begin(), ::tolower);
    return a;
}
std::map<std::string, std::set<std::tuple<std::string, int, int>>>  KreirajIndeksPojmova(Knjiga citanka){
    
    std::map<std::string, std::set<std::tuple<std::string, int, int>>> povratna;
    
 
   
    for(auto it=citanka.begin(); it!=citanka.end(); it++){
        for(int i=0; i<it->second.size(); i++){
            for(int j=0; j<it->second[i].size(); j++){
                std::string pomocna;
                bool nadjeno=false;
                while(std::isalpha(it->second[i][j]) || (it->second[i][j]>='0' && it->second[i][j]<='9')){
                    pomocna+=it->second[i][j];
                    j++;
                    nadjeno=true;
                }
                if(nadjeno){
                pomocna=PretvoriUMala(pomocna);
                povratna.insert({pomocna, {/*std::make_tuple("test",0, 0)*/}});
                }
            }
        }
    }
    
    
    
    for(auto it=povratna.begin(); it!=povratna.end(); it++){
        for(auto itNaCitanku=citanka.begin(); itNaCitanku!=citanka.end(); itNaCitanku++){
            for(int i=0; i<itNaCitanku->second.size(); i++){
                for(int j=0; j<itNaCitanku->second[i].size(); j++){
                    std::string pomocna;
                    bool nadjeno=false;
                    while(std::isalpha(itNaCitanku->second[i][j]) || (itNaCitanku->second[i][j]>='0' && itNaCitanku->second[i][j]<='9')){
                        pomocna+=itNaCitanku->second[i][j];
                        j++;
                        nadjeno=true;
                    }
                    if(nadjeno){
                        pomocna=PretvoriUMala(pomocna);
                        if(it->first==pomocna){
                            it->second.insert(std::make_tuple(itNaCitanku->first, i+1, j-pomocna.size() ));
                        }
                    }
                }
            }
        }  
    }
    
    
    return povratna;
}
std::set<std::tuple<std::string, int, int>> PretraziIndeksPojmova(std::string rijec, std::map<std::string, std::set<std::tuple<std::string, int, int> > > pojmovi){
    
    std::set<std::tuple<std::string, int, int>> povratna;
    rijec=PretvoriUMala(rijec);
    
    for(auto it=pojmovi.begin(); it!=pojmovi.end(); it++){
        if(it->first==rijec){
            for(auto it2=it->second.begin(); it2!=it->second.end(); it2++){
                povratna.insert(*it2);
            }
            
        }
    }
    if(povratna.size()) return povratna;
    throw std::logic_error("Pojam nije nadjen");
    
}

void IspisiIndeksPojmova(std::map<std::string, std::set<std::tuple<std::string, int, int>>> pojmovi){
    for(auto it=pojmovi.begin(); it!=pojmovi.end(); it++){
        std::cout<<it->first<<": ";
        for(auto it2=it->second.begin(); it2!=it->second.end(); it2++){
            auto dokle=it->second.end();
            dokle--;
            if(it2==dokle) std::cout<<std::get<0>(*it2)<<"/"<<std::get<1>(*it2)<<"/"<<std::get<2>(*it2);
            else std::cout<<std::get<0>(*it2)<<"/"<<std::get<1>(*it2)<<"/"<<std::get<2>(*it2)<<", ";
        }
        std::cout<<std::endl;
    }
}
int main ()
{
    Knjiga citanka;
    std::map<std::string, std::set<std::tuple<std::string, int, int>>> test;
    int k=1;
    while(true){
    std::cout<<"Unesite naziv poglavlja: ";
    
    std::string unos;
    std::getline(std::cin, unos);
    if(unos==".") break;
    citanka.insert({unos, {}});
    while(true){
        std::cout<<"Unesite sadrzaj stranice "<<k<<": ";
        std::string u;
        std::getline(std::cin, u);
        if(u==".") break;
        k++;
        citanka[unos].push_back(u);
    }
    }
    std::cout<<std::endl;
    std::cout<<"Kreirani indeks pojmova:"<<std::endl;
    
    
    test=KreirajIndeksPojmova(citanka);
    IspisiIndeksPojmova(test);
    std::cout<<std::endl;
    while(true){
        std::cout<<"Unesite rijec: ";
        std::string rijec;
        std::getline(std::cin, rijec);
       
        if(rijec==".") break;
        std::set<std::tuple<std::string, int, int>> gdjeSeNalazi;
        try{
        gdjeSeNalazi=PretraziIndeksPojmova(rijec, test);
        for(auto it=gdjeSeNalazi.begin(); it!=gdjeSeNalazi.end(); it++){
            std::cout<<std::get<0>(*it)<<"/"<<std::get<1>(*it)<<"/"<<std::get<2>(*it)<<" ";
        }
        std::cout<<std::endl;
        }
        catch(std::logic_error e){
            std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
        }
    }
    
    /*std::string naslov = "I";                            
    std::vector<std::string> v{"abc qwe stsda abc abc dhi qwe hrkw dhi"};
    std::string naslov2 = "auto";  
    std::vector<std::string> v2{"neko ide ulicom"};
    Knjiga citanka;
    citanka.insert({naslov, v});
    //citanka.insert({naslov2, v2});
     //Knjiga citanka({std::string("armin"), {std::string("neko"), std::string("ide."), std::string("..ulicom..ad")}});
    std::map<std::string, std::set<std::tuple<std::string, int, int>>> pokusaj=KreirajIndeksPojmova(citanka);
    /*for(auto it=pokusaj.begin(); it!=pokusaj.end(); it++) std::cout<<it->first<<" ";
    std::cout<<std::endl;*/
    /*for(auto it=pokusaj.begin(); it!=pokusaj.end(); it++){
        std::cout<<it->first<<" ";
        for(auto pom =it->second.begin(); pom!=it->second.end(); pom++){
            std::cout<<std::get<0>(*pom)<<" "<<std::get<1>(*pom)<<" "<<std::get<2>(*pom)<<" ";
        }
        std::cout<<std::endl;
    }
    IspisiIndeksPojmova(pokusaj);
    std::map<int, int> mapa;
    mapa.insert({1,2});
    mapa.insert({5,7});
    auto it=mapa.begin();
    it++;
    std::cout<<it->second;*/
    
	return 0;
}

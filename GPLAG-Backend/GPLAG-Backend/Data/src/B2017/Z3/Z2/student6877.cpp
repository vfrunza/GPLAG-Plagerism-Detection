/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <tuple>
#include <stdexcept>
#include <set>

typedef std::map<std::string,std::vector<std::string>> Knjiga;
typedef std::map<std::string, std::set<std::tuple<std::string, int, int>>> IndeksPojmova;

std::string PretvoriUMala(std::string str){
    std::string povratni;
    for(int i(0);i<str.size();i++){
        if(str[i]>='A' && str[i]<='Z') povratni.push_back(str[i]+'a'-'A');
        else povratni.push_back(str[i]);
    }
    return povratni;
}


IndeksPojmova KreirajIndeksPojmova (Knjiga knjiga){
    IndeksPojmova indexpojmova;
    int pozicija(0);
    for(auto it(knjiga.begin());it!=knjiga.end();it++){
        for(int i(0);i<it->second.size();i++){
            pozicija=0;
            for(int j(0);j<it->second[i].size();j++){
                if(it->second[i][j]!=' '){ 
                    std::string pomocni;
                    pozicija=j;
                    std::cout<<std::endl;
                    while(j<it->second[i].size()) {
                        if(!((it->second[i][j]>='a' && it->second[i][j]<='z') || (it->second[i][j]>='A' && it->second[i][j]<='Z') || (it->second[i][j]>='1' && it->second[i][j]<='9' ))) break;
                       
                        j++;
                    }
                    for(int k(pozicija);k<j;k++){ 
                        pomocni.push_back(it->second[i][k]);
                    }
                    auto mala_slova(PretvoriUMala(pomocni));
                    auto pom(std::make_tuple(it->first,i+1,pozicija));
                    indexpojmova[mala_slova].insert(pom);
                }
            }
        }
    }
    return indexpojmova;
}

std::set<std::tuple<std::string,int,int>> PretraziIdneksPojmova(std::string str, IndeksPojmova mapa){
    std::set<std::tuple<std::string,int,int>> SkupPpozicija;
    for(auto it(mapa.begin());it!=mapa.end();it++){
        if(str==it->first) {
            for(auto it1(it->second.begin());it1!=it->second.end();it1++){
                SkupPpozicija.insert(std::make_tuple(std::get<0>(*it1),std::get<1>(*it1),std::get<2>(*it1)));
            }
        }
        
    }
    if(SkupPpozicija.empty()) throw std::logic_error("Unesena rijec nije nadjena!");
    return SkupPpozicija;
}

void IspisiIndeksPojmova(IndeksPojmova indexpojmova){
    for(auto it1(indexpojmova.begin());it1!=indexpojmova.end();it1++){
            std::cout<<it1->first<<": "; 
            for(auto it2(it1->second.begin());it2!=it1->second.end();it2++){
                auto pomit=it1->second.end();
                pomit--;
                std::cout<<std::get<0>(*it2)<<"/"<<std::get<1>(*it2)<<"/"<<std::get<2>(*it2);
                if(it2!=pomit)std::cout<<", ";
            }
           
        std::cout<<std::endl;
    }
}

int main ()
{
    Knjiga knjiga;
    std::vector<std::string> vs;
    while(1){
        std::cout<<"Unesite naziv poglavlja: ";
        std::string naziv_poglavlja;
        std::getline(std::cin, naziv_poglavlja);
        std::cin.clear();
        if(naziv_poglavlja==".") break;
        int brojac_str(1);
        while(1){
            std::cout<<"Unesite sadrzaj stranice "<<brojac_str<<": ";
            std::string sadrzaj_str;
            std::getline(std::cin, sadrzaj_str);
            std::cin.clear();
            if(sadrzaj_str==".") break;
            vs.push_back(sadrzaj_str);
            brojac_str++;
        }
        knjiga[naziv_poglavlja]=vs;
    }
    
    auto a(KreirajIndeksPojmova(knjiga));
    std::cout<<"Kreirani indeks pojmova:"<<std::endl;
    IspisiIndeksPojmova(a);
    
    while(1){
        std::cout<<"Unesite rijec: ";
        std::string rijec;
        std::getline(std::cin,rijec);
        std::cin.clear();
        if(rijec==".") break;
        try {
            auto pov(PretraziIdneksPojmova(rijec,a));
            for(auto it(pov.begin());it!=pov.end();it++)
            std::cout<<std::get<0>(*it)<<"/"<<std::get<1>(*it)<<"/"<<std::get<2>(*it)<<" ";
            std::cout<<std::endl;    
    
        }
        catch (std::logic_error e) {
            std::cout << e.what() << std::endl;
        }
        
    }

	return 0;
}

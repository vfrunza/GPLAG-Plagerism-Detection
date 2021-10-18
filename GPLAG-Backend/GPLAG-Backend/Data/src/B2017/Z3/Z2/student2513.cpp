#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>

typedef std::map<std::string, std::vector<std::string>> Knjiga;

std::map<std::string,std::set<std::tuple<std::string,int,int>>> KreirajIndeksPojmova (Knjiga tekst)
{
    std::map<std::string,std::set<std::tuple<std::string,int,int>>> indeks;

    for (auto it = tekst.begin(); it !=tekst.end(); it++) {
        for (int j = 0; j <it->second.size() ; j++) {
            auto it2=it->second[j].begin();
            while (it2!=it->second[j].end()) {
                std::string s;
                while (it2!=it->second[j].end() && !((*it2>=0 && *it2<=9) or (*it2>='a' and *it2<='z') or (*it2>='A' && *it2 <= 'Z' ))) {
                    it2++;
                }
                auto it3=it2;
                while (it2!=it->second[j].end() && ((*it2>=0 && *it2<=9) or (*it2>='a' and *it2<='z') or (*it2>='A' && *it2 <= 'Z' ))) {
                    s.push_back(char(std::tolower(*it2)));
                    it2++;
                }
                indeks[s].insert(std::make_tuple(it->first,j+1,it3-it->second[j].begin()));
                if(it2!=it->second[j].end()) it2++;
            }
        }
    }
    return indeks;
}

std::set<std::tuple<std::string,int,int>> PretraziIndeksPojmova (std::string rijec, std::map<std::string,std::set<std::tuple<std::string,int,int>>> indeks)
{
    std::set<std::tuple<std::string,int,int>> skup;
    auto it(indeks.begin());
    while (it!=indeks.end()) {
        if (it->first==rijec){ skup=it->second; return skup;}
        it++;
    }
    if(it==indeks.end()) throw std::logic_error ("Unesena rijec nije nadjena!");
    return skup;
}

void IspisiIndeksPojmova (std::map<std::string,std::set<std::tuple<std::string,int,int>>> indeks)
{
    
    auto it(indeks.begin());
    while (it!=indeks.end()) {
        std::cout<<it->first<<": ";
        auto it1=it->second.begin();
        auto it2=it->second.end();
        it2--;
        while(it1!=it2) {
            std::cout<<std::get<0>(*it1)<<"/"<<std::get<1>(*it1)<<"/"<<std::get<2>(*it1)<<", ";
            it1++;
        }
        std::cout<<std::get<0>(*it1)<<"/"<<std::get<1>(*it1)<<"/"<<std::get<2>(*it1);
        std::cout<<std::endl;
        it++;
    }
}

int main ()
{
    Knjiga knjiga;
    std::string naziv_poglavlja;
    do {
        
        std::cout<<"Unesite naziv poglavlja: ";
        std::getline(std::cin,naziv_poglavlja);
        if(naziv_poglavlja==".") break;
        std::string stranica;
        int brojac(0);
        std::vector<std::string> vektor;
        do {
            brojac++;
            std::cout<<"Unesite sadrzaj stranice "<<brojac<<": ";
            std::getline(std::cin,stranica);
            if(stranica==".") break;
            vektor.push_back(stranica);
        } while(stranica!=".");
        knjiga.insert({naziv_poglavlja,vektor});
    } while(naziv_poglavlja!=".");
    auto pojmovi=KreirajIndeksPojmova(knjiga);
    std::cout<<std::endl;
    
    ////////
    std::cout << "Kreirani indeks pojmova:\n";
    
    IspisiIndeksPojmova(pojmovi);
    std::string rijec;
    while(1){
        std::cout<<"Unesite rijec: ";
        std::getline(std::cin,rijec);
        if(rijec==".") break;
        try{
            auto p=PretraziIndeksPojmova(rijec, pojmovi);
            auto it=p.begin();
            while(it!=p.end()){
                std::cout<<std::get<0>(*it)<<"/"<<std::get<1>(*it)<<"/"<<std::get<2>(*it)<<" ";
                it++;
            }
            std::cout<<"\n";
        }
        catch(std::logic_error greska){
            std::cout << greska.what() << std::endl;
        }
    }
    return 0;
}

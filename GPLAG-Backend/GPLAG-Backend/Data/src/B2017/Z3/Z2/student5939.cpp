/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <tuple>
#include <set>

typedef std::map<std::string, std::vector<std::string>> Knjiga;

bool daLiJeSlovo(char a){
    if(a>='a' && a<='z') return true;
    if(a>='A' && a<='Z') return true;
    if(a>='0' && a<='9') return true;
    return false;
}

std::string malaSlova(std::string rec){
    for(int i=0;i<rec.size();i++){
        if(rec[i]>='A' && rec[i]<='Z'){
            rec[i]+=32;
        }
    }
    return rec;
}

std::map<std::string,std::set<std::tuple<std::string,int,int>>> KreirajIndeksPojmova (Knjiga knjiga){
    
    std::map<std::string,std::set<std::tuple<std::string,int,int>>> rez;
    
    auto it=knjiga.begin();
    while(it!=knjiga.end()){//prolazimo kroz mapu knjiga 
    
    std::string oznakaP = it->first;
    std::vector<std::string> poglavlje=it->second;
    
    for(int i=0;i<poglavlje.size();i++){ //petlja uzima stranicu po stranicu
        for(int j=0;j<poglavlje[i].size();j++){
            
            int duzina=0, poc=j;
            while(j<poglavlje[i].size() && daLiJeSlovo(poglavlje[i][j])){
                duzina++;
                j++;
            }
            
            std::string oznaka=poglavlje[i].substr(poc,duzina);
            auto it2=rez.find(malaSlova(oznaka));
            if(it2==rez.end()){
                std::set<std::tuple<std::string,int,int>> skup;
                skup.insert(std::tuple<std::string,int,int>(oznakaP,i+1,poc));
                rez.insert(std::make_pair(malaSlova(oznaka),skup));
            }
            else{
                (it2->second).insert(std::tuple<std::string,int,int>(oznakaP,i+1,poc));
            }
            
        }
        
    }
    
        it++;
    }
    
    return rez;
}

std::set<std::tuple<std::string,int,int>> PretraziIndeksPojmova(std::string oznaka,std::map<std::string,std::set<std::tuple<std::string,int,int>>> mapica){
    auto it(mapica.find(malaSlova(oznaka)));
    if(it==mapica.end()){
        throw std::logic_error("Unesena rijec nije nadjena!");
    }
    else{
        return it->second;
    }
}

void IspisiIndeksPojmova(std::map<std::string,std::set<std::tuple<std::string,int,int>>> mapica){
    
    auto it=mapica.begin();
    while(it!=mapica.end()){
        
        std::cout<<it->first<<": ";
        auto skupic = it->second;
        auto it2=skupic.begin();
        while(it2!=skupic.end()){
            auto pom (it2);
            pom++;
            if (pom == skupic.end()) std::cout << std::get<0>(*it2) << "/" << std::get<1>(*it2) << "/" << std::get<2>(*it2);
            else std::cout<<std::get<0>(*it2)<<"/"<<std::get<1>(*it2)<<"/"<<std::get<2>(*it2)<<", ";
            it2++;
        }
        
        std::cout<<std::endl;
        it++;
    }
}

void IspisiPojmove (std::set<std::tuple<std::string, int, int>> setic) {
    auto it(setic.begin());
    while (it != setic.end()) {
        //auto pom (it);
       // pom++;
        //if (pom == setic.end()) 
        std::cout << std::get<0>(*it) << "/" << std::get<1>(*it) << "/" << std::get<2>(*it) << " ";
        //else std::cout << std::get<0>(*it) << "/" << std::get<1>(*it) << "/" << std::get<2>(*it) << ", ";
        it++;
    }
}

int main ()
{
    
    std::string s1 ("a");
    Knjiga knjiga;
    
    while (s1 != ".") {
        std::vector<std::string> vs;
        std::cout << "Unesite naziv poglavlja: ";
        std::getline (std::cin, s1);
        if (s1 == ".") break;
        int brojac(0);
        std::string s2 ("a");
        while (s2 != ".") {
            std::cout << "Unesite sadrzaj stranice " << brojac+1 << ": ";
            std::getline (std::cin, s2);
            if (s2 == ".") break;
            vs.push_back(s2);
            brojac++;
        }
        knjiga.insert(std::make_pair(s1,vs));
    }
    std::cout << std::endl;
    std::cout << "Kreirani indeks pojmova:";
    std::cout << std::endl;
    auto maps (KreirajIndeksPojmova(knjiga));
    IspisiIndeksPojmova(maps);
    
    std::string sr ("a");
        while (sr != ".") {
            std::cout << "Unesite rijec: ";
            std::getline (std::cin, sr);
            if (sr == ".") break;
            try {
            auto setic (PretraziIndeksPojmova(sr,maps));
            IspisiPojmove(setic);
            std::cout << std::endl;
            }
            catch (std::logic_error l) {
                std::cout << l.what();
                std::cout << std::endl;
            }
        }
    
	return 0;
}

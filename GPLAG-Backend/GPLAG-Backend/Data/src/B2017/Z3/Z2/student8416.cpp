/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <tuple>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <locale>
#include <algorithm>
#include <stdexcept>

typedef std::map<std::string, std::vector<std::string>> Knjiga;
typedef std::map<std::string, std::set<std::tuple<std::string, int, int>>> Povratna;

Povratna KreirajIndeksPojmova(Knjiga indeks){
Povratna krajnji;
    std::string kratkotrajni;
    int p(0);
    for(auto it=indeks.begin(); it!=indeks.end(); it++){
        auto stringovi=it->second; //stringovi su sada vektor stringova
        for(int i=0; i<stringovi.size(); i++){
            std::string hop=stringovi.at(i);  //hop je sad jedan string iz vektora stringova
            std::transform(hop.begin(), hop.end(), hop.begin(), ::tolower);
            for(int j=0; j<hop.size(); j++){
                    while(hop.at(j)<'0' || (hop.at(j)>'9' && hop.at(j)<'a') || hop.at(j)>'z'){if(j!=hop.size()-1) j++; else break;}
                    p=j;
                    while((hop.at(j)>='0' && hop.at(j)<='9') || (hop.at(j)>='a' && hop.at(j)<='z')) {kratkotrajni.push_back(hop.at(j)); if(j==hop.size()-1) break; else j++;}
                    krajnji[kratkotrajni].insert(std::make_tuple(it->first, i+1, p));
                    kratkotrajni.resize(0);
                    if(j==hop.size()-1) break;
            }
        }
    }

    return krajnji;
}

std::set<std::tuple<std::string, int, int>> PretraziIndeksPojmova(std::string s, Povratna mapa){
    try{
    auto it(mapa.find(s));
    if(it==mapa.end()) throw std::logic_error("Unesena rijec nije nadjena!\n");
    else return it->second;
    }catch(std::logic_error e){
        throw;
    }
}

void IspisiIndeksPojmova(Povratna karina){
    for(auto it=karina.begin(); it!=karina.end(); it++){
        auto sett=it->second;
        auto zar=sett.begin();
        std::cout<<it->first<<": ";
        for(auto i=0; i<sett.size(); i++){
            std::cout<<std::get<0>(*zar)<<"/"<<std::get<1>(*zar)<<"/"<<std::get<2>(*zar);
            if(i!=sett.size()-1) std::cout<<", ";
            zar++;
        }
        std::cout<<std::endl;
    }
}
   

int main ()
{
    int n(1);
    
    std::string s;
    std::string poglavlje;
    std::vector<std::string> vektor_stringova;
    Knjiga ovo_saljem;
    for(;;){
        std::cout<<"Unesite naziv poglavlja: ";
        std::getline(std::cin, poglavlje);
        if(poglavlje==".") break;
        for(;;){
            std::cout<<"Unesite sadrzaj stranice "<<n<<": "; n++;
            std::getline(std::cin, s);
            if(s==".") break;
            vektor_stringova.push_back(s);
        }
        ovo_saljem.insert({poglavlje, vektor_stringova});
        n=1;
    }
    
    auto karina=KreirajIndeksPojmova(ovo_saljem);
    std::cout<<"\nKreirani indeks pojmova:"<<std::endl;
    IspisiIndeksPojmova(karina);
    for(;;){
    try{
        std::string op;
        
            std::cout<<"Unesite rijec: ";
            std::getline(std::cin, op);
            if(op==".") break;
    auto k=PretraziIndeksPojmova(op, karina);
    for(auto x:k){
        std::cout<<std::get<0>(x)<<"/"<<std::get<1>(x)<<"/"<<std::get<2>(x)<<" ";
    
    }
   std::cout<<std::endl;
        }
    catch(std::logic_error e){
        std::cout<<e.what();
    }
    }
	return 0;
}

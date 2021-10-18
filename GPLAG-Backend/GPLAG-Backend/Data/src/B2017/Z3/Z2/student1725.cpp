/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <vector>
#include <string>
#include <map> 
typedef std::map<std::string, std::vector<std::string>> Knjiga;
typedef std::map<std::string, std:set<std::tuple<std::string,int,int>>> IndexPojmova;
typedef std::set<std::tuple<std::string,int,int>> SkupPozicija;
IndexPojmova KreirajIndexPojmova(Knjiga A) {
    for(auto it=A.begin(); it!=A.end();it++) {
        for (int i=0; i<(it->first).size();i++) {
            std::string novarijec;
            while((it->first)[i]==' ' && (it->first)[i]!='\n') i++; 
            int pozicija(i);
            while((it->first)[i] != ' ') novarijec.push_back((it->first)[i])
            while((it->first)[i]==' ' && (it->first)[i]!='\n') i++;
        }
    }
}

SkupPozicija PretraziIndeksPojmova(std::string rijec, IndexPojmova IdeksPojmova) {
    auto it(IdeksPojmova.find(rijec));
    if(it==IdeksPojmova.end()) throw std::logic_error("Pojam nije nadjen");
    else return it->second;
}

void IspisiIndeksPojmova(IndexPojmova &IdeksPojmova) {
    for(auto it=IdeksPojmozva.begin(); it!=IndeksPojmova.end(); it++) {
        std::cout<<it->first<<": ";
        for(auto x : it->second) {
            std::cout<<get<0><<"/"<<get<1><<"/"<<get<2><<", ";
        }
        std::cout<<std::endl;
    }
}
int main ()
{
	return 0;
}

/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <vector>
#include <string>

typedef std::map<std::string, std::vector<std::string>> Knjiga;

std::map<std::string, std::tuple<std::string, int, int>> KreirajIndeksPojmova(Knjiga K)
{

    std::map<std::string, std::tuple<std::string, int, int>> Povratna_mapa;
    for(auto it(K.begin()); it!=K.end(); it++) {
        for(int i=0; i<it->second.size(); i++) {
            int index, broj_slova(0);
            for(int j=0; j<it->second[i].size(); j++) {
                broj_slova=0;
                if(!((it->second[i][j]>='A' && it->second[i][j]<='Z') || (it->second[i][j]>='a' && it->second[i][j]<='z')) && !(it->second[i][j]>='0' && it->second[i][j]<='9')) {
                    j++;
                } else {
                    index=j;
                    while((it->second[i][j]>='A' && it->second[i][j]<='Z') || (it->second[i][j]>='a' && it->second[i][j]<='z') || (it->second[i][j]>='0' && it->second[i][j]<='9')) {
                        broj_slova++;
                        j++;
                    }
                    std::string Novi=it->second[i].substr(j,broj_slova);
                    Povratna_mapa.insert({Novi,std::make_tuple(it->first,i+1,index)});
                    j--;
                }
            }
        }
    }
    return Povratna_mapa;
}

int main ()
{
    
    return 0;
}

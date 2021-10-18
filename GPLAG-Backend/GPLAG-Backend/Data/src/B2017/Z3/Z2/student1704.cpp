/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <tuple>
#include <stdexcept>

typedef std::map<std::string, std::vector<std::string>> Knjiga;

std::map<std::string, std::set<std::tuple<std::string, int, int>>> KreirajIndeksPojmova(Knjiga &tekst) {
    std::map<std::string, std::set<std::tuple<std::string, int, int>>> indeks;
    for(auto it=tekst.begin(); it!=tekst.end(); it++) {
        for(int i=0; i<(it->second).size(); i++) {
            for(int j=0; j<(it->second)[i].length(); j++) {
                std::string rijec;
                while(((it->second)[i][j]>='a' && (it->second)[i][j]<='z') || ((it->second)[i][j]>='A' && (it->second)[i][j]<='Z') || ((it->second)[i][j]>='0' && (it->second)[i][j]<='9') && j<(it->second)[i].length()) {
                    char znak;
                    if((it->second)[i][j]>='A' && (it->second)[i][j]<='Z') znak=(it->second)[i][j]+32;
                    else znak=(it->second)[i][j];
                    rijec.push_back(znak);
                    j++;
                }
                if(rijec.length()!=0 ) {
                    std::set<std::tuple<std::string, int, int>> skup;
                    bool ima(false);
                    for(auto it3(indeks.begin()); it3!=indeks.end(); it3++) 
                        if(rijec==it3->first) ima=true;
                        if(!ima){ 
                    for(auto it2(tekst.begin()); it2!=tekst.end(); it2++) {
                        for(int k=0; k<(it2->second).size(); k++) {
                            for(int z=0; z<(it2->second)[k].length(); z++) {
                                std::string temp;
                                while(((it2->second)[k][z]>='a' && (it2->second)[k][z]<='z') || ((it2->second)[k][z]>='A' && (it2->second)[k][z]<='Z') || ((it2->second)[k][z]>='0' && (it2->second)[k][z]<='9') && z<(it2->second)[k].length()) {
                                    char znak2;
                                    if((it2->second)[k][z]>='A' && (it2->second)[k][z]<='Z') znak2=(it2->second)[k][z]+32;
                                    else znak2=(it2->second)[k][z];
                                    temp.push_back(znak2);
                                    z++;
                                }
                                if(temp.length()!=0 && temp==rijec) {
                                   std::tuple<std::string, int, int> t;
                                   t=std::make_tuple(it2->first, k+1, z-temp.length());
                                    skup.insert(t);
                                }
                            }
                        }
                    }
                    indeks.insert({rijec, skup});
                    }
                }
                }
            }
        }
    return indeks;
}

std::set<std::tuple<std::string, int, int>> PretraziIndeksPojmova(std::string pojam, std::map<std::string, std::set<std::tuple<std::string, int, int>>> &mapa) {
    std::string temp;
    char znak;
    for(int i=0; i<pojam.length(); i++) {
        if(pojam[i]>='A' && pojam[i]<='Z') znak=pojam[i]+32;
        else znak=pojam[i];
        temp.push_back(znak);
    }
    auto it(mapa.find(temp));
    if(it==mapa.end()) throw std::logic_error("Unesena rijec nije nadjena!");
    return it->second;
}

void IspisiIndeksPojmova(std::map<std::string, std::set<std::tuple<std::string, int, int>>> &mapa) {
    for(auto it=mapa.begin(); it!=mapa.end(); it++) {
        std::cout<<it->first<<": ";
        for(auto it2((it->second).begin()); it2!=(it->second).end(); it2++) {
            auto pomocni(it2);
            pomocni++;
            if(pomocni!=(it->second).end()) 
            std::cout<<std::get<0>(*it2)<<"/"<<std::get<1>(*it2)<<"/"<<std::get<2>(*it2)<<", ";
            else std::cout<<std::get<0>(*it2)<<"/"<<std::get<1>(*it2)<<"/"<<std::get<2>(*it2);
        }
        std::cout<<std::endl;
    }
}



int main ()
{
    Knjiga tekst;
    for(;;) {
        std::cout<<"Unesite naziv poglavlja: ";
        std::string poglavlje;
        std::getline(std::cin, poglavlje);
        if(poglavlje[0]=='.' && poglavlje.length()==1) break;
        int i(1);
        std::vector<std::string> v;
        while(1) {
            std::cout<<"Unesite sadrzaj stranice "<<i<<": ";
            std::string sadrzaj;
            std::getline(std::cin, sadrzaj);
            if(sadrzaj[0]=='.' && sadrzaj.length()==1) break;
            v.push_back(sadrzaj);
            i++;
        }
        tekst.insert({poglavlje, v});
    }
    auto indeks(KreirajIndeksPojmova(tekst));
    std::cout<<std::endl;
    std::cout<<"Kreirani indeks pojmova:"<<std::endl;
    IspisiIndeksPojmova(indeks);
    
    for(;;) {
        std::string rijec;
        std::cout<<"Unesite rijec: ";
        std::getline(std::cin, rijec);
        if(rijec=="." && rijec.length()==1) break;
        try {
            auto skup(PretraziIndeksPojmova(rijec,indeks));
            for(auto it(skup.begin()); it!=skup.end(); it++) {
            std::cout<<std::get<0>(*it)<<"/"<<std::get<1>(*it)<<"/"<<std::get<2>(*it)<<" ";
            }
            std::cout<<std::endl;
        }
        catch(std::logic_error poruka) {
            std::cout<<poruka.what()<<std::endl;
        }
    }
    
	return 0;
}

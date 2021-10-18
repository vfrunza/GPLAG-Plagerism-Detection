/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <stdexcept>

std::map<std::string, std::set<int>> KreirajIndeksPojmova (std::string tekst)
{
    std::map<std::string, std::set<int>> mapa;
    for (int i=0; i<tekst.length(); i++) {
        if (tekst[i]==' ') continue;
        if (tekst[i]>='A' && tekst[i]<='Z') tekst[i]+=32;
    }
    int duzina(0);
    for (int i=0; i<tekst.length(); i++) {
        if (((tekst[i]>='a' && tekst[i]<='z') || (tekst[i]>='0' && tekst[i]<='9')) && (i==0 || tekst[i-1]<'0' || (tekst[i-1]>'9' && tekst[i-1]<'a') || tekst[i-1]>'z')) {
            duzina=0;
            std::set<int> skup {};
            skup.insert(i);
            int j;
            for (j=i; j<tekst.length(); j++) {
                if ((tekst[j]>='a' && tekst[j]<='z') || (tekst[j]>='0' && tekst[j]<='9')) duzina++;
                else break;
            }
            for (int j=i+duzina; j<tekst.length(); j++) {
                if (tekst.substr(i,duzina)==tekst.substr(j,duzina) && (tekst[j+duzina]<'0' || (tekst[j+duzina]>'9' && tekst[j+duzina]<'a') || tekst[i-1]>'z') &&
                        (tekst[j-1]<'0' || (tekst[j-1]>'9' && tekst[j-1]<'a') || tekst[j-1]>'z'))                skup.insert(j);
            }
            mapa.insert(std::make_pair(tekst.substr(i,duzina), skup));
        }
    }
    return mapa;
}

std::set<int> PretraziIndeksPojmova (std::string tekst, std::map<std::string, std::set<int>> mapa)
{
    if(mapa.count(tekst)==0) throw std::logic_error ("Pojam nije nadjen");
    for (auto it=mapa.begin(); it!=mapa.end(); it++)
        if(it->first==tekst) return it->second;
    return std::set<int> {};
}

void IspisiIndeksPojmova (std::map<std::string, std::set<int>> mapa)
{
    for (auto it=mapa.begin(); it!=mapa.end(); it++) {
        std::cout << it->first << ": ";
        for (auto iter=it->second.begin(); iter!=it->second.end(); iter++) {
            if (iter!=(--it->second.end()))
                std::cout << *iter << ",";
            else std::cout << *iter;
        }
        std::cout << std::endl;
    }
}

int main ()
{
    std::cout << "Unesite tekst: ";
    std::string tekst;
    std::getline(std::cin, tekst);
    std::string pomocni, tacka(".");
    std::map<std::string, std::set<int>> mapa(KreirajIndeksPojmova(tekst));
    IspisiIndeksPojmova(mapa);
    for (;;) {
        std::cout << "Unesite rijec: ";
        std::getline(std::cin, pomocni);
        if (pomocni==tacka)break;
        if(mapa.count(pomocni)==0) std::cout << "Unesena rijec nije nadjena!" << std::endl;
        else {
            for (auto it=mapa.begin(); it!=mapa.end(); it++) {
                if (it->first == pomocni) {
                    for (auto iter=it->second.begin(); iter!=it->second.end(); iter++)
                        std::cout << *iter << " ";
                    std::cout << std::endl;
                }
            }
        }
    }
    return 0;
}
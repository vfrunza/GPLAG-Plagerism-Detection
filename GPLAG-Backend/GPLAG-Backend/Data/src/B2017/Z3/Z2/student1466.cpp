/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <iterator>
#include <tuple>
#include <utility>
#include <set>
typedef std::map<std::string, std::vector<std::string>> Knjiga;
typedef std::map<std::string, std::set<std::tuple<std::string, int,int>>> Index;
Index KreirajIndeksPojmova(Knjiga book)
{
    Index indeks;
    auto it=book.begin();
    while(it!=book.end()) {
        for(int i=0; i<it->second.size(); i++) {
            int j(0);
            auto stranica=it->second.at(i);
            while(j<stranica.length()) {
                std::string rijec;
                if(!(isalnum(stranica.at(j)))) {
                    while(j<stranica.length() && !(isalnum(stranica.at(j)))) {
                        j++;
                    }
                    rijec.resize(0);
                } else if(j<stranica.length() && isalnum(stranica.at(j))) {
                    while(j<stranica.length() && isalnum(stranica.at(j))) {
                        rijec.push_back(std::tolower(stranica.at(j)));
                        j++;
                    }
                    indeks[rijec].insert(std::make_tuple(it->first, i+1, j-rijec.length()));

                }
                j++;
            }
        }
        it++;
    }
    return indeks;
}
std::set<std::tuple<std::string, int, int>> PretraziIndeksPojmova(std::string rijec,Index indeks)
{
    int j(0);
    std::set<std::tuple<std::string, int, int>> a;
    if(rijec=="."){ return a;}
    while(j<rijec.length()) {
        rijec.at(j)=std::tolower(rijec.at(j));
        j++;
    }
    auto it=indeks.find(rijec);
    if(it==indeks.end()) throw std::logic_error("Unesena rijec nije nadjena!");
    else return it->second;
}
void IspisiIndeksPojmova(Index book)
{
    auto it=book.begin();
    while(it!=book.end()) {
        std::cout<<it->first<<": ";
        int i(0);
        for(auto it1=it->second.begin(); i<it->second.size(); it1++) {
            std::cout<<std::get<0>(*it1)<<"/"<<std::get<1>(*it1)<<"/"<<std::get<2>(*it1);
            if(i<it->second.size()-1)
                std::cout << ", ";
            i++;
        }
        std::cout << std::endl;
        it++;
    }
}
int main ()
{
    Knjiga book;
    for(;;) {
        std::cout << "Unesite naziv poglavlja: ";
        std::string chapter;
        std::getline(std::cin, chapter);
        if(chapter==".") break;
        std::vector<std::string> stranice;
        int i(0);
        std::string content;
        do {
            std::cout << "Unesite sadrzaj stranice "<<i+1<<": ";
            std::getline(std::cin, content);
            if(content==".") continue;
            stranice.push_back(content);
            i++;
        } while(content!=".");
        book.insert(std::make_pair(chapter, stranice));
    }
    std::cout << std::endl<<"Kreirani indeks pojmova:"<<std::endl;
    auto indeks=KreirajIndeksPojmova(book);
    IspisiIndeksPojmova(indeks);
    std::string nadji;
    do {
        std::cout << "Unesite rijec: ";
        std::getline(std::cin, nadji);
        try {
            auto skup=PretraziIndeksPojmova(nadji, indeks);
            auto it=skup.begin();
            while(it!=skup.end()) {
                std::cout<<std::get<0>(*it)<<"/"<<std::get<1>(*it)<<"/"<<std::get<2>(*it)<<" ";
                it++;
            }
            std::cout  << std::endl;
        }catch(std::logic_error izuzetak){
            std::cout << izuzetak.what() << std::endl;
        }
    } while(nadji!=".");
    return 0;
}
#include <iostream>
#include <map>
#include <set>
#include <tuple>
#include <vector>
#include <string>
#include <algorithm>

typedef std::map<std::string, std::vector<std::string>> Knjiga;

bool DaLiJeSlovo(char znak){
    return ((znak <= 'Z' && znak >= 'A') || (znak >= 'a' && znak <= 'z') || (znak >= '0' && znak <= '9'));
}

std::vector<std::string> DajRijeci(std::string s){
    std::vector<std::string> rezultat;
    for(int i = 0; i < s.length(); i++){
        if(DaLiJeSlovo(s.at(i))){
            int kraj = i;
            std::string rijec;
            for(;;){
                if(kraj == s.length() || (!DaLiJeSlovo(s.at(kraj)))) break;
                else kraj++;
            }
            rijec = s.substr(i,kraj-i);
            i = kraj;
            rezultat.push_back(rijec);
        }
    }
    return rezultat;
}

std::vector<int> PozicijeURecenici(std::string recenica, std::string rijec){
    std::vector<int> rezultat;
    for(int i = 0; i < recenica.length(); i++){
        if(recenica.at(i) == rijec.at(0)){
            bool jeste = true;
            for(int j = 0; j < rijec.length(); j++){
                if((i+j >= recenica.length()) || (recenica.at(i+j) != rijec.at(j))) {
                    jeste = false;
                    break;
                }
            }
            if(jeste) rezultat.push_back(i);
        }
    }
    return rezultat;
}

std::map<std::string, std::set<std::tuple<std::string, int, int>>> KreirajIndeksPojmova(Knjiga book){
    std::map<std::string, std::set<std::tuple<std::string, int, int>>> indeks;
    std::set<std::string> pogl;
    std::set<int> str;
    for(auto it = book.begin(); it != book.end(); it++){
        for(int i = 0; i < it->second.size(); i++){
            std::string mirza = it->second.at(i);
            std::transform(mirza.begin(),mirza.end(),mirza.begin(),::tolower);
            std::vector<std::string> rijeci = DajRijeci(mirza);
            for(int j = 0; j < rijeci.size(); j++){
                if(!indeks.count(rijeci.at(j))){
                    std::set<std::tuple<std::string, int, int>> x;
                    std::vector<int> pozicije = PozicijeURecenici(mirza,rijeci.at(j));
                    for(auto broj : pozicije){
                         x.insert(std::make_tuple(it->first,i+1,broj));
                    }
                    indeks.insert(std::make_pair(rijeci.at(j),x));
                    
                }
                else if(str.count(i) == 0 || pogl.count(it->first) == 0){
                    auto it1(indeks.find(rijeci.at(j)));
                    std::vector<int> pozicije = PozicijeURecenici(mirza,rijeci.at(j));
                    for(auto broj : pozicije){
                         it1->second.insert(std::make_tuple(it->first,i+1,broj));
                    }
                }
            }
            str.insert(i); 
        }
        pogl.insert(it->first);
    }
    return indeks;
}

std::set<std::tuple<std::string, int, int>> PretraziIndeksPojmova(std::string rijec, std::map<std::string, std::set<std::tuple<std::string, int, int>>> indeks){
    auto it(indeks.find(rijec));
    if(it == indeks.end()) throw std::logic_error("Pojam nije nadjen");
    else return it->second;
}

void IspisiIndeksPojmova(std::map<std::string, std::set<std::tuple<std::string, int, int>>> indeks){
    for(auto it = indeks.begin(); it != indeks.end(); it++){
        std::cout << it->first << ": ";
        auto nesto = it->second;
        int br = 0;
        for(auto it1 = nesto.begin(); it1 != nesto.end(); it1++){
            if(br == nesto.size() - 1) std::cout << std::get<0>(*it1)<< "/" << std::get<1>(*it1)<< "/" << std::get<2>(*it1);
            else std::cout << std::get<0>(*it1)<< "/" << std::get<1>(*it1)<< "/" << std::get<2>(*it1) << ", "; 
            br++;
        }
        std::cout << std::endl;
    }
}

int main ()
{
    Knjiga book;
    for(;;){
        int br(1);
        std::vector<std::string> v;
        std::string pogl,str;
        std::cout << "Unesite naziv poglavlja: ";
        getline(std::cin,pogl);
        if(pogl == ".") break;
        for(;;){
            std::cout << "Unesite sadrzaj stranice " << br++ << ": ";
            getline(std::cin,str);
            if(str == ".") break;
            v.push_back(str);
        }
        book.insert(std::make_pair(pogl,v));
    }
    std::cout << std::endl;
    std::cout << "Kreirani indeks pojmova: " << std::endl;
    auto indeks = KreirajIndeksPojmova(book);
    IspisiIndeksPojmova(indeks);
    for(;;){
        std::string rijec;
        std::cout << "Unesite rijec: ";
        getline(std::cin,rijec);
        if(rijec == ".") break;
        try{
            auto nesto = PretraziIndeksPojmova(rijec,indeks);
            int br = 0;
            for(auto it1 = nesto.begin(); it1 != nesto.end(); it1++){
                if(br == nesto.size() - 1) std::cout << std::get<0>(*it1)<< "/" << std::get<1>(*it1)<< "/" << std::get<2>(*it1);
                else std::cout << std::get<0>(*it1)<< "/" << std::get<1>(*it1)<< "/" << std::get<2>(*it1) << " "; 
                br++;
            }
            std::cout << std::endl;
        }
        catch(std::exception &e){
            std::cout << "Unesena rijec nije nadjena!" << std::endl;
        }
    }
	return 0;
}

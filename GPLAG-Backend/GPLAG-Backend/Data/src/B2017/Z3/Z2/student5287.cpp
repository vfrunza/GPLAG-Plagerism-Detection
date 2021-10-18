/B2017/2018: Zadaca 3, Zadatak 2
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <map>
#include <set>
#include <stdexcept>

using std::string;
using std::vector;
using std::tuple;
using std::map;
using std::multimap;
using std::set;

typedef map<string, vector<string> > Knjiga;
typedef set<tuple<string, int, int> > SetPozicija;
typedef map<string, SetPozicija> Index;

bool Slovo(char c){
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

string ToLower(string s){
    for(char &c : s)
        if(c >= 'A' && c <= 'Z') c += 'a' - 'A';
    
    return s;
}

multimap<string, int> PageParser(const string &stranica){
    multimap<string, int> rijeci;
    int i = 0;
    
    while(i < stranica.size()){
        int j = i;
        
        while(j < stranica.size() && Slovo(stranica[j]))
            j++;
            
        if(j != i){
            //Rijec i pozicija
            rijeci.insert({ToLower(stranica.substr(i,j-i)), i});
        }
        
        i = j + 1;
    }
    
    return rijeci;
}

Index KreirajIndeksPojmova(Knjiga &knjiga){
    Index idx;
    
    //Prodji kroz poglavlja knjige
    for(auto it = knjiga.begin(); it != knjiga.end(); it++){
        //Prodji kroz stranice poglavlja
        for(int i = 0; i < it->second.size(); i++){
            multimap<string, int> rijeci = PageParser(it->second[i]);
            
            for(auto jt = rijeci.begin(); jt != rijeci.end(); jt++){
                //idx[rijec] = tuple<poglavlje, stranica, pozicija>
                idx[jt->first].insert(std::make_tuple(it->first, i+1, jt->second));
            }
        }
    }
    
    return idx;
}

SetPozicija PretraziIndeksPojmova(string rijec, Index &index){
    rijec = ToLower(rijec);
    
    if(index.count(rijec) == 0)
        throw std::logic_error("Pojam nije nadjen");
    
    return index[rijec];
}

void PrintSet(SetPozicija &set, const char* devidor = " "){
    SetPozicija::iterator it = set.begin();
    
    if(it != set.end()){
        std::cout << std::get<0>(*it) << "/" << std::get<1>(*it) << "/" << std::get<2>(*it);
        it++;
    }
    
    for(; it != set.end(); it++)
        std::cout << devidor << std::get<0>(*it) << "/" << std::get<1>(*it) << "/" << std::get<2>(*it);
}

void IspisiIndeksPojmova(Index index){
    for(auto it = index.begin(); it != index.end(); it++){
        std:: cout << it->first << ": ";
        PrintSet(it->second, ", ");
        std::cout << std::endl;
    }
}

int main () {
    string poglavlje, stranica, rijec;
    Knjiga knjiga;
    Index index;
    
    //Unos poglavlja i stranica
    while(true){
        std::cout << "Unesite naziv poglavlja: ";
        std::getline(std::cin, poglavlje);
        if(poglavlje == ".") break;
        
        int i = 1;
        vector<string> stranice;
        while(true){
            std::cout << "Unesite sadrzaj stranice " << i << ": ";
            std::getline(std::cin, stranica);
            if(stranica == ".") break;
            stranice.push_back(stranica);
            i++;
        }
        
        knjiga[poglavlje] = stranice;
    }
    
    std::cout << std::endl;
    
    //Indeksacija
    index = KreirajIndeksPojmova(knjiga);
    
    std::cout << "Kreirani indeks pojmova:" << std::endl;
    IspisiIndeksPojmova(index);
    
    std::cout << std::endl;
    
    //trazenje rijeci
    while(true){
        std::cout << "Unesite rijec: ";
        std::cin >> rijec;
        if(rijec == ".") break;
        
        try{
            SetPozicija setPoz = PretraziIndeksPojmova(rijec, index);
            for(SetPozicija::iterator it = setPoz.begin(); it != setPoz.end(); it++)
                std::cout << std::get<0>(*it) << "/" << std::get<1>(*it) << "/" << std::get<2>(*it) << " ";
        }catch(std::logic_error err){
            std::cout << "Unesena rijec nije nadjena!";
        }
        std::cout << std::endl;
    }
    
	return 0;
}

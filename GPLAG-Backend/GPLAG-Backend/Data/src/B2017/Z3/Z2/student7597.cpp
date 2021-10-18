/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <utility>
#include <set>
#include <tuple>
#include <stdexcept>

using std::map;
using std::string;
using std::vector;
using std::set;
using std::tuple;

typedef map<string,vector<string>> Knjiga;

typedef map<string,set<tuple<string,int,int>>> indeksPojmova;

bool nijeSlovoNiBroj(char x) {
    if((x>='A' && x<='Z') || (x>='a' && x<='z') || (x>='0' && x<='9'))
        return false;
    return true;
}
string ToLower(string s) {
    for(char &x : s) {
        if(x>='A' && x<='Z')
            x+=32;
    }
    return s;
}
 
indeksPojmova KreirajIndeksPojmova(const Knjiga &knjiga) {
    indeksPojmova indeks;
    
    for(auto it=knjiga.begin();it!=knjiga.end();it++) { 
        vector<string> stranice = it->second;             // Stranice jednog poglavlja
        int brStranice=0;                               // Broj trenutne stranice
        for(const string &stranica : stranice) {         // Prolazi kroz svaku stranicu 
            brStranice++;
            int i=0;
            while(i<stranica.size()) {                  // Prolazi kroz stranicu i pronalazi sve pojmove
                int j=i;
                while(j<stranica.size() && nijeSlovoNiBroj(stranica.at(j))) j++; // Sve dok nije slovo ili broj
                i=j;
                if(i==stranica.size()) break;                                       // Dosao do kraja stranice
                while(j<stranica.size() && !nijeSlovoNiBroj(stranica.at(j))) j++; // Prodji kroz rijec do iduceg znaka interpunkcije
                string pojam = stranica.substr(i,j-i);
                if(indeks.count(ToLower(pojam))==0)                                  // Ako ne postoji u indeksu dodaj pojam i njegovu prvu poziciju u knjizi
                    indeks.insert({ToLower(pojam),{std::make_tuple(it->first,brStranice,i)}});
                else                                                             // Ako pojam vec postoji , samo dodaj poziciju na kojoj se nalazi
                    indeks[ToLower(pojam)].insert(std::make_tuple(it->first,brStranice,i));
                i=j;                                                            // Trazi iduci pojam
            }
        }
    }
    return indeks;
}

set<tuple<string,int,int>> PretraziIndeksPojmova(string rijec , indeksPojmova indeks) {
    if(indeks.count(ToLower(rijec))==0)
        throw std::logic_error("Pojam nije nadjen");
    return indeks[ToLower(rijec)];
}

void IspisiIndeksPojmova(indeksPojmova indeks) {
    for(auto it=indeks.begin();it!=indeks.end();it++) {
        std::cout<<it->first<<": ";
        int brojac=0;
        for(const auto &pozicija : it->second) {
            std::cout<<std::get<0>(pozicija)<<"/"<<std::get<1>(pozicija)<<"/"<<std::get<2>(pozicija);
            brojac++;
            if(brojac!=(it->second).size())
                std::cout<<", ";
        }
        std::cout<<std::endl;
    } 
}

int main ()
{
    Knjiga knjiga;
    while(true) {
        std::cout<<"Unesite naziv poglavlja: ";
        string poglavlje;
        if(std::cin.peek()=='.') break;
        std::getline(std::cin,poglavlje);
        int brStranice=1;
        vector<string> stranice(0);
        while(true) {
            std::cout<<"Unesite sadrzaj stranice "<<brStranice<<": ";
            if(std::cin.peek()=='.') {
                std::cin.ignore(10000,'\n'); // OCISTI SPREMNIK ( da ne bi izaslo iz unutrasnje petlje )
                break;
            }
            string stranica;
            std::getline(std::cin,stranica);
            stranice.push_back(stranica);
            brStranice++;
        }
        knjiga.insert({poglavlje,stranice});
    }
    
    indeksPojmova indeks = KreirajIndeksPojmova(knjiga);
    std::cout<<"\nKreirani indeks pojmova:\n";
    IspisiIndeksPojmova(indeks);
    
    std::cout<<std::endl;
    std::cin.ignore(10000,'\n'); // OCISTI SPREMNIK
    while(true) {
        try {
            std::cout<<"Unesite rijec: ";
            if(std::cin.peek()=='.') break;
            string rijec;
            std::getline(std::cin,rijec);
            auto pozicije = PretraziIndeksPojmova(rijec,indeks);
            for(const auto &pozicija : pozicije)
                std::cout<<std::get<0>(pozicija)<<"/"<<std::get<1>(pozicija)<<"/"<<std::get<2>(pozicija)<<" ";
            std::cout<<std::endl;
        }
        catch(std::logic_error e) {
            std::cout<<"Unesena rijec nije nadjena!\n";
        }
    }
	return 0;
}

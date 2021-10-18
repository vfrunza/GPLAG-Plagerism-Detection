#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <stdexcept>
#include <set>
#include <tuple>

using std::cin;
using std::cout;

typedef std::map<std::string, std::vector<std::string>> Knjiga;

void UMalaSlova (std::string &s) {
    for(int i=0; i<s.length(); i++) {
        if(s[i]>='A' && s[i]<='Z') s[i]=s[i]+32;
    }
} 

bool Slovo(char s) {
    return (s>='A' && s<='Z') || (s>='a' && s<='z') || (s>='0' && s<='9');
}

bool BioUIndeksu(std::string pomocni, std::map<std::string, std::set<std::tuple<std::string, int, int>>> Indeks) {
    UMalaSlova(pomocni);
    auto it(Indeks.find(pomocni));
    if(it==Indeks.end()) return false;
    else return true;
}

std::map<std::string, std::set<std::tuple<std::string, int, int>>> KreirajIndeksPojmova(Knjiga knjiga) {
    std::map<std::string, std::set<std::tuple<std::string, int, int>>> Indeks;
    
    for(auto it=knjiga.begin(); it!=knjiga.end(); it++) {
        
        for(int i=0; i<it->second.size(); i++) {
            bool neslovo(true);
            bool pomjerio_se(false);
            for(int j=0; j<it->second.at(i).size(); j++) {
                if(!Slovo(it->second.at(i).at(j))) neslovo=true;
                else if(neslovo==true) {
                    std::string pomocni;
                    int cuvaj(j);
                    while(j<it->second.at(i).size() && Slovo(it->second.at(i).at(j))) {
                        pomocni.insert(pomocni.end(), it->second.at(i).at(j));
                        pomjerio_se=true;
                        j++;
                    }
                    UMalaSlova(pomocni);
                    if(!BioUIndeksu(pomocni, Indeks)) {
                        std::set<std::tuple<std::string, int, int>> pomocni_set;
                        std::tuple<std::string, int, int> ubaci;
                        ubaci=std::make_tuple(it->first, i+1, cuvaj);
                        pomocni_set.insert(ubaci);
                        Indeks[pomocni]=pomocni_set;
                    } else {
                        auto it2(Indeks.find(pomocni));
                        std::tuple<std::string, int, int> ubaci;
                        ubaci=std::make_tuple(it->first, i+1, cuvaj);
                        it2->second.insert(ubaci);
                    }
                    neslovo=false;
                    if(pomjerio_se) j--;
                }
            }
        }
    }
    return Indeks;
}

std::set<std::tuple<std::string, int, int>> PretraziIndeksPojmova(std::string rijec,  std::map<std::string, std::set<std::tuple<std::string, int, int>>> Indeks) {
    UMalaSlova(rijec);
    auto it(Indeks.find(rijec));
    if(it==Indeks.end()) throw std::logic_error("Pojam nije nadjen");
    else return it->second;
}

void IspisiIndeksPojmova(std::map<std::string, std::set<std::tuple<std::string, int, int>>> Indeks) {
    auto it(Indeks.begin());
    while(it!=Indeks.end()) {
        cout<<it->first<<":";
        auto it2(it->second.begin());
        while(it2!=it->second.end()) {
            if(std::distance(it2, it->second.end())==1) {
                cout<<" "<<std::get<0>(*it2)<<"/"<<std::get<1>(*it2)<<"/"<<std::get<2>(*it2);
            } else {
                cout<<" "<<std::get<0>(*it2)<<"/"<<std::get<1>(*it2)<<"/"<<std::get<2>(*it2)<<",";
            }
            it2++;
        }
        cout<<"\n";
        it++;
    }
}

int main ()
{
    Knjiga knjiga;
    std::string pomocni;
    
    for(;;) {
        cout<<"Unesite naziv poglavlja: ";
        std::getline(cin, pomocni);
        if(pomocni==".") break;
        int i(1);
        std::string stranica;
        std::vector<std::string> vektor_stringova;
        for(;;) {
            cout<<"Unesite sadrzaj stranice "<<i<<": ";
            std::getline(cin, stranica);
            if(stranica==".") break;
            vektor_stringova.push_back(stranica);
            i++;
        }
        knjiga[pomocni]=vektor_stringova;
    }
    
    auto indeks(KreirajIndeksPojmova(knjiga));
    
    cout<<"\nKreirani indeks pojmova:\n";
    IspisiIndeksPojmova(indeks);
    
    std::string rijec;
    for(;;) {
        cout<<"Unesite rijec: ";
        std::getline(cin, rijec);
        if(rijec==".") break;
        try {
            auto pojmovi(PretraziIndeksPojmova(rijec, indeks));
            auto it(pojmovi.begin());
            while(it!=pojmovi.end()) {
                cout<<std::get<0>(*it)<<"/"<<std::get<1>(*it)<<"/"<<std::get<2>(*it)<<" ";
                it++;
            }
            cout<<"\n";
        } catch(std::logic_error izuzetak) {
            cout<<"Unesena rijec nije nadjena!\n";
        }
    }
	return 0;
}

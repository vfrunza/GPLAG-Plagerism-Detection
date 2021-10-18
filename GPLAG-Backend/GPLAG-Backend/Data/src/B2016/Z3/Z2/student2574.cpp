#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stdexcept>
#include <utility>
#include <algorithm>

 using std::string;
 using std::set; //Zbog čitljivosti koda :) 
 

set<int> PretraziIndeksPojmova (string rijec, std::map<string, set<int>> index_pojmova) {
    std::transform(rijec.begin(), rijec.end(), rijec.begin(), ::tolower);
    auto iter (index_pojmova.find((rijec)));
    if (iter==index_pojmova.end()) 
        throw std::logic_error ("Pojam nije nadjen\n");
    else 
        return iter->second;
}

std::map<string,set<int>> KreirajIndeksPojmova (string main_s) {
    std::map<string,set<int>> index_pojmova; 
    set<int> index;
    std::transform(main_s.begin(), main_s.end(), main_s.begin(), ::tolower);
    string pomocni;
    for (int i(0); i<main_s.length(); i++) {
        int brojac(i);
        if (main_s[i]!=' ') {
            index.insert(brojac);
            pomocni.clear();
            while (main_s[brojac]!=' ' && brojac!=main_s.length()) {
                pomocni.push_back (main_s[brojac]);
                brojac++;
            }
            if (index_pojmova.count(pomocni)==1) {
                index_pojmova[pomocni].insert(i);
                i=brojac;
                continue;
            }
            else 
                index_pojmova[pomocni].insert(i);
            i=brojac;
        }
    }
    return index_pojmova;
}

void IspisiIndeksPojmova (std::map<string,set<int>> index_pojmova) {
    for(auto it(index_pojmova.begin()); it != index_pojmova.end(); it++) {
        std::cout << it->first<<": ";
        for (set<int>::iterator iter=(it->second).begin(); iter!=(it->second).end(); ++iter) {
                if (iter==(it->second).begin()) 
                    std::cout <<*iter;
                else 
                    std::cout<<","<<*iter;
            }
            std::cout<<std::endl;
    }
}

int main () {
    std::cout<<"Unesite tekst: ";
    string main_string;
    std::getline(std::cin,main_string);
    auto index(KreirajIndeksPojmova(main_string));
    IspisiIndeksPojmova(index);
    for (;;) {
        std::cout<<"Unesite rijec: ";
        string rijec;
        std::getline(std::cin,rijec);
        if (rijec == ".")
            break;
        try {
            auto skup(PretraziIndeksPojmova(rijec,index));
            for (set<int>::iterator it=skup.begin(); it!=skup.end(); ++it)  
                std::cout <<*it<<" ";
            std::cout<<std::endl;
        }
        catch (std::logic_error izuzetak) {
            std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
        }
    }
	return 0;
}
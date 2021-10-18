#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <set>
#include <stdexcept>
#include <vector>

void KorigujString(std::string &s){
    auto pok(s.begin());
    while(pok != s.end()){
        *pok=tolower(*pok);
        if(!((*pok >= 'a' && *pok <='z') || (*pok >='0' && *pok <='9') || *pok == ' ')) *pok = ' ';
        pok++;
    }
}

int Brojac(std::string s){
    int brojac(0);
    KorigujString(s);
    auto pok(s.begin());
    while(pok != s.end()){
        if(*pok == ' '){
            pok++;
            continue;
        }
        std::string pomocni;
        while((*pok >= 'a' && *pok <= 'z') || (*pok >= '0' && *pok <='9')){
            pomocni += *pok;
            pok++;
        }
        if(pomocni.length() != 0) brojac++;
    }
    return brojac;
}

std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string s){
    std::map<std::string, std::set<int>> rez;
    KorigujString(s);
    auto pok(s.begin());
    int pozicija(0);
    std::vector<std::set<int>> setovi;
    setovi.resize(Brojac(s));
    int i(0);
    while(pok != s.end()){
        if(*pok == ' '){
            pozicija++;
            pok++;
            continue;
        }
        std::string pomocni;
        int pravapozicija(pozicija);
        while((*pok >= 'a' && *pok <= 'z') || (*pok >= '0' && *pok <='9')){
            pomocni += *pok;
            pok++;
            pozicija++;
        }
        //std::cout << pravapozicija << ",  ";
        setovi[i].insert(pravapozicija);
        auto it(rez.find(pomocni));
        if(it == rez.end()) {
            rez.insert(std::make_pair(pomocni, setovi[i]));
            //(it->second).insert(pravapozicija);
        }
        else{
            (it->second).insert(pravapozicija);
        }
        i++;
    }
    return rez;
}

std::set<int> PretraziIndeksPojmova(std::string s, std::map<std::string, std::set<int>> mapa){
    std::set<int> rez;
    for(int i=0; i<s.length(); i++) s[i] = tolower(s[i]);
    bool nijenadjen(true);
    for(auto it=mapa.begin(); it!=mapa.end(); it++){ 
        if(it->first==s) nijenadjen=false;
    }
    if(nijenadjen) throw std::logic_error("Pojam nije nadjen");
    else{
        rez = mapa[s];
    }
    return rez;
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> mapa){
    for(auto it=mapa.begin(); it!=mapa.end(); it++){
        std::cout << it->first << ": " ;
        auto it2((it->second).begin());
	    while(it2 != (it->second).end()){
	        if((it->second).size() == 1){ 
	            std::cout << *it2; 
	            break;
	        }
	        std::cout<< *it2 << ",";
	        it2=(it->second).erase(it2);
	    }
	    std::cout << std::endl;
    }
}

void IspisiSet(std::set<int> set){
    for(auto x : set) std::cout << x << " ";
    std::cout << std::endl;
}

int main ()
{
	std::cout << "Unesite tekst: ";
	std::string tekst;
	std::getline(std::cin, tekst);
	auto rezultat(KreirajIndeksPojmova(tekst));
	IspisiIndeksPojmova(rezultat);
	for(;;){
	    std::cout << "Unesite rijec: ";
	    std::string s;
	    std::cin >> std::ws;
	    std::getline(std::cin, s);
	    std::string kraj(".");
	    if(s==kraj) break;
	    try{
	        auto rez2(PretraziIndeksPojmova(s,rezultat));
	        IspisiSet(rez2);
	    }
	    catch(...){
	        std::cout << "Unesena rijec nije nadjena!" << std::endl;
	    }
	}
	return 0;
}
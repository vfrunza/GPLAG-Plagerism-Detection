/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <iterator>
#include <stdexcept>

struct Dijete{
    std::string ime;
    Dijete *sljedeci;
};

int kolikoSlova(const std::string &s){
    int howmuch(0);
    for(int i(0); i < s.length(); i++){
        if((s[i]>47 && s[i]<58) || (s[i]>64 && s[i]<91) || (s[i]>96 && s[i]<123)){
            howmuch++;
        }
    }
    return howmuch;
}

Dijete *NapraviCirkularnuListu(std::vector<std::string> vek){
    Dijete *prvi=nullptr;
    Dijete *tekuci;
    for(int i(0); i<vek.size(); i++){
        
        Dijete *tmp(new Dijete);
        tmp->ime = vek[i];
        tmp->sljedeci = nullptr;
        if(prvi == nullptr) prvi = tmp;
        else tekuci->sljedeci = tmp;
        tekuci = tmp;
    }
    tekuci->sljedeci = prvi;
    return prvi;
}

Dijete *ObrisiCvor(Dijete *tekuci, Dijete *&prvi){
    if(tekuci == tekuci->sljedeci){
        delete tekuci;
        
        return nullptr;
    }
    bool a (prvi==tekuci);
    Dijete *tmp = prvi;
    while(tmp->sljedeci != tekuci){
        tmp = tmp->sljedeci;
    }
    tmp->sljedeci = tekuci->sljedeci;
    tekuci->sljedeci = nullptr;
    delete tekuci;
    tekuci = nullptr;
    if(a) prvi = tmp->sljedeci;
    
    return tmp->sljedeci;
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> vek, int a){
    if(a < 1 || a > vek.size()) throw std::logic_error("Razvrstavanje nemoguce");
    
    Dijete *prviCvor = NapraviCirkularnuListu(vek);
    
    int kolikoChildren(0);
    for(int i(0); i<vek.size(); i++){
        kolikoChildren++;
    }
    
    std::vector<std::set<std::string>> vekSkupova;
    vekSkupova.resize(a);
   
    
    int modulo=kolikoChildren%a;
    
    Dijete *tmp = prviCvor;
    
    for(int i(0); i < vekSkupova.size(); i++){
        int uTimu=int(kolikoChildren/a) + bool(modulo);
                   //std::cout<<uTimu<<" uTimu\n "; 
        while(uTimu != 0){
            vekSkupova[i].insert(tmp->ime);
            int dokle=kolikoSlova(tmp->ime); //std::cout<<tmp->ime<<" "<<dokle<<"ovoliko slova\n";
            
            tmp = ObrisiCvor(tmp, prviCvor);
            
            for(int j(0); j < dokle-1; j++){ 
                if(tmp == nullptr) continue; 
                tmp = tmp->sljedeci;
            }
            
            uTimu--;
        }
        
        if(modulo != 0) modulo--;
    }
    
    
    return vekSkupova;
}


int main (){
    int m,n;
    std::string s;
    std::cout<<"Unesite broj djece: ";
    std::cin>>m;
    std::cout<<"Unesite imena djece: \n";
    
    std::vector<std::string> vek;
    
    std::cin.clear();
    std::cin.ignore(10000,'\n');
    for(int i(0); i<m; i++){
        std::getline(std::cin, s);
        vek.push_back(s);
    }
    std::cout<<"Unesite broj timova: ";
    std::cin>>n;
    std::vector<std::set<std::string>> z;
try{
    z=Razvrstavanje(vek, n);
    for(int i(0); i<z.size(); i++){
        std::cout<<"Tim "<<i+1<<": ";
        for(auto it=z[i].begin(); it != z[i].end(); it++){
            auto it1=it;
            it1++;
            if(it1 != z[i].end()){
                std::cout<<*it<<", ";
            }
            else std::cout<<*it;
        }
        
        std::cout<<"\n";
    }
    
}catch(std::logic_error e){
    std::cout<<"Izuzetak: "<<e.what();
}
	return 0;
}
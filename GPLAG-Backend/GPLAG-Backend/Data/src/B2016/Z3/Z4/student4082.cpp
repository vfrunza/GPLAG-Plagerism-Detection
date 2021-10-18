/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <iterator>
#include <stdexcept>



int kolikoSlova(const std::string &s){
    int howmuch(0);
    for(int i(0); i < s.length(); i++){
        if((s[i]>47 && s[i]<58) || (s[i]>64 && s[i]<91) || (s[i]>96 && s[i]<123)){
            howmuch++;
        }
    }
    return howmuch;
}


std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> vek, int a){
    if(a < 1 || a > vek.size()) throw std::logic_error("Razvrstavanje nemoguce");
    
    std::list<std::string> l;
    int kolikoChildren(0);
    
    for(int i(0); i<vek.size(); i++){
        l.push_back(vek[i]);
        kolikoChildren++;
    }
    
    std::vector<std::set<std::string>> vekSkupova;
    vekSkupova.resize(a);
    
    int modulo=kolikoChildren%a;
    auto it=l.begin();
    
    for(int i(0); i < vekSkupova.size(); i++){
        int uTimu=int(kolikoChildren/a) + bool(modulo);
                   //std::cout<<uTimu<<" uTimu\n "; 
        while(uTimu != 0){
            vekSkupova[i].insert(*it);
            int dokle=kolikoSlova(*it); //std::cout<<dokle<<"ovoliko slova\n";
            it=l.erase(it);
            for(int j(0); j < dokle-1; j++){ // ipak ide dokle-1
                if(it == l.end()) it=l.begin();
                it++;
            }
            if(it == l.end()) it=l.begin();
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
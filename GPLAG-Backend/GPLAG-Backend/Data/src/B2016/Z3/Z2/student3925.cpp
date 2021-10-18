/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stdexcept>


bool dalijebroj (char a){

    if(a>='0' && a<='9') return true;
    return false;
}

bool dalijeslovo (char a){
    if((a>='A' && a<='Z') || (a>='a' && a<='z')) return true;
    return false;
}

std::string pretvoriumala(std::string s){
    for(int i(0);i<s.length();i++){
        if(s[i]>='A' && s[i]<='Z') s[i]+='a'-'A';
    }
    return s;
}
std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string s){
    std::map<std::string, std::set<int>> m;
    
    for(int i(0);i<s.length();i++){
        while(i != s.size() && !dalijebroj(s[i]) && !dalijeslovo(s[i])) i++;
        std::string a;
        int indeks=i;
        while(i!=s.size() && (dalijebroj(s[i]) || dalijeslovo(s[i]))) {
            a.push_back(s[i]);
            i++;
        }
        if(a.size()) m[pretvoriumala(a)].insert(indeks);
    }
    
    return m;
    
}

std::set<int> PretraziIndeksPojmova(std::string s, std::map<std::string, std::set<int>> m){
    auto it (m.find(pretvoriumala(s)));
    if(it==m.end()) throw std::logic_error("Pojam nije nadjen");
    else return it->second;
    
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> m){
    for(auto it=m.begin();it!=m.end();it++){
        std::cout << it->first<<": ";
        bool prvi (true);
        for(auto indeks: it-> second){
            if(prvi) prvi=false;
            else std::cout << ",";
            std::cout << indeks;
        }
        std::cout << std::endl;
    }
}

int main ()
{
    std::string s;
    std::cout << "Unesite tekst: ";
    std::getline(std::cin, s);
    std::map<std::string, std::set<int>> m;
    try{
    m=KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(m);
    std::string a;
    while(1){
        std::cout << "Unesite rijec: ";
        std::cin >> a;
        if(a==".") break;
        auto it(m.find(pretvoriumala(a)));
        if(it==m.end()) std::cout << "Unesena rijec nije nadjena!" << std::endl;
        else{
            bool prvi=true;
             for(auto indeks: it->second){
            if(prvi) prvi=false;
            else std::cout << " ";
            std::cout << indeks;
        }
        std::cout <<  std::endl;
    }
    }
    }
    catch (std::logic_error izuzetak){
        std::cout << izuzetak.what() << std::endl;
    }
    
	return 0;
}